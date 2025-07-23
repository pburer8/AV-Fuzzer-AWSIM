#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"


class PoseSubscriber : public rclcpp::Node
{
public:
  PoseSubscriber()
  : Node("pose_subscriber")
  {

    subscription_ =
      this->create_subscription<geometry_msgs::msg::PoseStamped>("localization/pose_estimator/pose", 10, std::bind(&PoseSubscriber::pose_callback, this, std::placeholders::_1));
  }

private:
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_;

  void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) const
  {
    const auto & pos = msg->pose.position;
    const auto & orient = msg->pose.orientation;

    RCLCPP_INFO(this->get_logger(),
      "Pose Received:\n"
      "Position -> x: %.3f, y: %.3f, z: %.3f\n"
      "Orientation -> x: %.3f, y: %.3f, z: %.3f, w: %.3f",
      pos.x, pos.y, pos.z,
      orient.x, orient.y, orient.z, orient.w);
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PoseSubscriber>());
  rclcpp::shutdown();
  return 0;
}