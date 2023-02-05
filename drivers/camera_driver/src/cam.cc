#include "camera_driver/cam.hh"
#include <chrono>

using namespace std::chrono_literals;

Camera::Camera() : Node("cam_pub") {
  // Open the default camera.
  m_camera.open(0);

  // Check if the camera is opened.
  if (!m_camera.isOpened()) {
    throw std::runtime_error("Failed to open the camera");
  }

  // Set the image to be RGB.
  m_camera.set(cv::CAP_PROP_CONVERT_RGB, true);

  // Set the frames per second to 30.
  m_camera.set(cv::CAP_PROP_FPS, 30);

  // Create a publisher
  m_cam_pub = this->create_publisher<sensor_msgs::msg::Image>("cam", 10);
  // make a timer for publishing the
  m_timer =
      this->create_wall_timer(33ms, std::bind(&Camera::timer_callback, this));
  }

  cv::Mat Camera::getImage() {
    cv::Mat image;
    m_camera >> image;
    return image;
  }

  void Camera::timer_callback()
  {
      auto image = getImage();
      auto msg = std::make_unique<sensor_msgs::msg::Image>();
      msg->header.stamp = rclcpp::Time();
      msg->width = image.cols;
      msg->height = image.rows;
      msg->encoding = "bgr8";
      msg->is_bigendian = false;
      msg->step = image.cols * image.elemSize();
      msg->data.resize(image.rows * msg->step);
      std::memcpy(msg->data.data(), image.data, msg->data.size());
      m_cam_pub->publish(std::move(msg));
  }