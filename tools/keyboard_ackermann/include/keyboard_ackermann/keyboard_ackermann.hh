#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "nandhi_msg_types/msg/ackermann_drive.hpp"

class keyboard_ackermann : public rclcpp::Node
{
private:
  float m_speed{}, m_acceleration{}, m_jerk{};
  rclcpp::TimerBase::SharedPtr m_timer;
  rclcpp::Publisher<nandhi_msg_types::msg::AckermannDrive>::SharedPtr m_publisher;

  void timer_callback();

      public : keyboard_ackermann(/* args */);
  ~keyboard_ackermann();
};

enum class KEY
{
  Up,
  Down,
  Left,
  Right,
  Stop,
  None
};

class KeyEventManager
{
public:
  KeyEventManager();

  ~KeyEventManager();

  KEY get_key();

private:
  std::mutex m_key_mutex{};
  KEY m_key{KEY::None};
  std::unique_ptr<std::thread> m_key_thread_ptr;

  void setKey(char key);

  void read_key_press();

  void run();
};