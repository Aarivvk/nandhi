#include "camera_driver/cam.hh"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Camera>());
  rclcpp::shutdown();
  return 0;
}