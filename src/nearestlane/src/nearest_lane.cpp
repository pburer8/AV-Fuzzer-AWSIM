#include <fstream>
#include <iostream>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "autoware_map_msgs/msg/lanelet_map_bin.hpp"

#include <lanelet2_core/LaneletMap.h>
#include <lanelet2_io/Io.h>
#include <sstream>
#include <lanelet2_io/io_handlers/Serialize.h>

class LaneletSubscriber : public rclcpp::Node
{
    public:
        LaneletSubscriber() : Node("lanelet_subscriber")
        {
            subscription_ = this->create_subscription<autoware_map_msgs::msg::LaneletMapBin>(
                "/map/vector_map",
                10,
                std::bind(&LaneletSubscriber::lane_callback, this, std::placeholders::_1));
            RCLCPP_INFO(this->get_logger(), "Subscribed to /map/vector_map");
        }
    private:
        void lane_callback(const autoware_map_msgs::msg::LaneletMapBin::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "Received LaneletMapBin with %lu bytes", msg->data.size());

            std::ofstream outputFile("map.bin", std::ios::binary);

            outputFile.write(reinterpret_cast<const char*>(msg->data.data()), msg->data.size());
            outputFile.close();

            

        }

    rclcpp::Subscription<autoware_map_msgs::msg::LaneletMapBin>::SharedPtr subscription_;
    
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LaneletSubscriber>());
  rclcpp::shutdown();
  return 0;
}