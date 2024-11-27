#include "key_to_twist/key_to_twist.hh"
#include "geometry_msgs/msg/twist.hpp"

#include <algorithm>
#include <chrono>
#include <cmath> // For tan function
#include <iostream>
#include <memory>
#include <mutex>
#include <signal.h>
#include <stdio.h>
#include <thread>

using namespace std::chrono_literals;

bool terminate{false};

void terminate_sig(int s) { terminate = true; }

KeyEventManager::KeyEventManager() : Node("keyboard_event_listner") {
  system("stty raw");
  system("stty -echo");
  m_key_thread_ptr = std::make_unique<std::thread>(&KeyEventManager::run, this);
}

KeyEventManager::~KeyEventManager() {
  m_key_thread_ptr->join();
  system("stty cooked");
  system("stty echo");
}

KEY KeyEventManager::get_key() {
  std::lock_guard<std::mutex> guard(m_key_mutex);
  auto ret = m_key;
  m_key = KEY::None;
  return ret;
}

void KeyEventManager::setKey(char key) {
  std::lock_guard<std::mutex> guard(m_key_mutex);
  switch (key) {
  case 'q':
    m_key = KEY::Stop;
    break;
  case 'w':
    m_key = KEY::Up;
    break;
  case 'a':
    m_key = KEY::Left;
    break;
  case 'd':
    m_key = KEY::Right;
    break;
  case 's':
    m_key = KEY::Down;
    break;
  default:
    // std::cerr << "Unknown key recived: " << key << std::endl;
    m_key = KEY::Stop;
    terminate = true;
    break;
  }
}

void KeyEventManager::read_key_press() {
  char key{};
  key = getchar();
  setKey(key);
}

void KeyEventManager::run() {
  while (!terminate) {
    read_key_press();
    std::this_thread::sleep_for(40ms);
  }
}

TwistPublisher::TwistPublisher(/* args */) : Node("key_to_twist") {
  m_publisher =
      this->create_publisher<geometry_msgs::msg::Twist>("/nandhi/cmd_vel", 10);
  m_timer = this->create_wall_timer(
      150ms, std::bind(&TwistPublisher::timer_callback, this));
}

void TwistPublisher::timer_callback() {
  std::lock_guard<std::mutex> guard(m_msg_mutex);
  m_publisher->publish(m_message);
}

void TwistPublisher::SetData(double linear, double angular) {
  std::lock_guard<std::mutex> guard(m_msg_mutex);
  m_message.linear.x = linear;
  m_message.angular.z = angular;
}

void print_info() {
  std::cout << "q --> stop" << std::endl;
  std::cout << "w --> forward" << std::endl;
  std::cout << "s --> backword" << std::endl;
  std::cout << "a --> left" << std::endl;
  std::cout << "d --> right" << std::endl;
  std::cout << "Any thing else programe terminates" << std::endl;
}

int main(int argc, char *argv[]) {
  print_info();

  signal(SIGINT, terminate_sig);
  rclcpp::init(argc, argv);
  KEY key{KEY::Stop};

  // Min pulse length out of 4096
  // Max pulse length out of 4096
  constexpr int speed_inc = 5;
  constexpr int steering_inc = 5;

  constexpr double range = 100;

  constexpr double max_linear_velocity = 13.89; // m/s
  constexpr double max_angular_velocity = 47.9; // rad/s

  double speed{}, steering{};

  rclcpp::executors::MultiThreadedExecutor executor;

  auto twist_publisher = std::make_shared<TwistPublisher>();
  auto key_man = std::make_shared<KeyEventManager>();

  executor.add_node(twist_publisher);
  executor.add_node(key_man);

  executor.spin_once();

  while (!terminate) {
    
    key = key_man->get_key();
    
    switch (key) {
    case KEY::Up:
      speed = std::min(speed + speed_inc, range);
      break;
    case KEY::Down:
      speed = std::max(speed - speed_inc, -1 * range);
      break;
    case KEY::Left:
      steering = std::min(steering + steering_inc, range);
      break;
    case KEY::Right:
      steering = std::max(steering - steering_inc, -1 * range);
      break;
    case KEY::None:
      break;
    case KEY::Stop:
    default:
      speed = 0;
      steering = 0;
      break;
    }

    double acceleration = ((speed/range) * max_linear_velocity);
    double angular = (steering / range) * max_angular_velocity;

    twist_publisher->SetData(acceleration, angular);

    std::cout << "\rspeed " << speed << " acceleration " << acceleration
              << " angular " << angular << " steering " << steering << " range "
              << range << " max_linear_velocity " << max_linear_velocity << std::flush;

    executor.spin_once();
    std::this_thread::sleep_for(std::chrono::milliseconds(40));
  }

  rclcpp::shutdown();

  return 0;
}
