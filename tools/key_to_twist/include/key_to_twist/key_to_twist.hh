#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"


class TwistPublisher : public rclcpp::Node
{
  public:
  TwistPublisher();
  ~TwistPublisher() = default;
  void SetData(double linear, double angular);


  private:
  std::mutex m_msg_mutex{};
  rclcpp::TimerBase::SharedPtr m_timer;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_publisher;
  geometry_msgs::msg::Twist m_message{};
  void timer_callback();
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

class KeyEventManager : public rclcpp::Node
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