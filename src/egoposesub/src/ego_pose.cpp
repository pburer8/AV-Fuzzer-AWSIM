#include <memory>
#include <fstream>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"


class PoseSubscriber : public rclcpp::Node
{
public:
  PoseSubscriber()
  : Node("pose_subscriber")
  {

    subscription_ =this->create_subscription<geometry_msgs::msg::PoseStamped>("localization/pose_estimator/pose", 10, std::bind(&PoseSubscriber::pose_callback, this, std::placeholders::_1));
    
    std::ofstream init_file("ego_pose.yaml", std::ios::out | std::ios::trunc);

    if (!init_file.is_open()) {
      RCLCPP_ERROR(this->get_logger(), "Failed to create ego_pose.yaml in current directory.");
      rclcpp::shutdown();
      return;
    }
    init_file << "# Ego pose data written by pose_estimator_subscriber\nposes:\n";
    init_file.close();
    
    RCLCPP_INFO(this->get_logger(), "Initialized ego_pose.yaml in current directory.");
  }

private:
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_;

  void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) const
  {
    std::ofstream out_file("ego_pose.yaml", std::ios::out | std::ios::trunc);
    if (!out_file.is_open()) {
      RCLCPP_ERROR(this->get_logger(), "Failed to open ego_pose.yaml for writing.");
      return;
    }

    out_file << "  - timestamp: " << msg->header.stamp.sec << "." << msg->header.stamp.nanosec << "\n"
             << "    frame_id: \"" << msg->header.frame_id << "\"\n"
             << "    position:\n"
             << "      x: " << msg->pose.position.x << "\n"
             << "      y: " << msg->pose.position.y << "\n"
             << "      z: " << msg->pose.position.z << "\n"
             << "    orientation:\n"
             << "      x: " << msg->pose.orientation.x << "\n"
             << "      y: " << msg->pose.orientation.y << "\n"
             << "      z: " << msg->pose.orientation.z << "\n"
             << "      w: " << msg->pose.orientation.w << "\n";


    out_file.close();
    RCLCPP_INFO(this->get_logger(), "Pose written to ego_pose.yaml");
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PoseSubscriber>());
  rclcpp::shutdown();
  return 0;
}