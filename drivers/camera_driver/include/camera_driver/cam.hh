#ifndef DRIVERS_CAMERA_DRIVER_INCLUDE_CAMERA_DRIVER_CAM
#define DRIVERS_CAMERA_DRIVER_INCLUDE_CAMERA_DRIVER_CAM
#include <opencv2/opencv.hpp>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

class Camera : public rclcpp::Node {
 public:
Camera();
~Camera()=default;

 private:
 cv::Mat getImage();
 void timer_callback();
 rclcpp::TimerBase::SharedPtr m_timer;
 cv::VideoCapture m_camera;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr m_cam_pub;
};


#endif   /* DRIVERS_CAMERA_DRIVER_INCLUDE_CAMERA_DRIVER_CAM */
