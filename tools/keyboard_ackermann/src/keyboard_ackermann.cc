#include "keyboard_ackermann/keyboard_ackermann.hh"
#include "nandhi_msg_types/msg/ackermann_drive.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <memory>
#include <signal.h>
#include <stdio.h>

using namespace std::chrono_literals;

bool terminate{false};

void terminate_sig(int s)
{
    std::cout << "\nCaught signal " << s << std::endl;
    terminate = true;
}

KeyEventManager::KeyEventManager() : Node("keyboard_event_listner")
{
    system("stty raw");
    system("stty -echo");
    m_key_thread_ptr = std::make_unique<std::thread>(&KeyEventManager::run, this);
}

KeyEventManager::~KeyEventManager()
{
    m_key_thread_ptr->join();
    system("stty cooked");
    system("stty echo");
}

KEY KeyEventManager::get_key()
{
    std::lock_guard<std::mutex> guard(m_key_mutex);
    auto ret = m_key;
    m_key = KEY::None;
    return ret;
}

void KeyEventManager::setKey(char key)
{
    std::lock_guard<std::mutex> guard(m_key_mutex);
    switch (key)
    {
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

void KeyEventManager::read_key_press()
{
    char key{};
    key = getchar();
    setKey(key);
}

void KeyEventManager::run()
{
    while (!terminate)
    {
        read_key_press();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}

keyboard_ackermann::keyboard_ackermann(/* args */) : Node("keyboard_ackermann_cmd")
{
    m_publisher = this->create_publisher<nandhi_msg_types::msg::AckermannDrive>("/ackermann_cmd", 10);
    m_timer = this->create_wall_timer(
        50ms, std::bind(&keyboard_ackermann::timer_callback, this));
}

keyboard_ackermann::~keyboard_ackermann()
{
}

void keyboard_ackermann::timer_callback()
{
    std::lock_guard<std::mutex> guard(m_msg_mutex);
    m_publisher->publish(m_message);
}

void keyboard_ackermann::set_msg(nandhi_msg_types::msg::AckermannDrive msg)
{
    std::lock_guard<std::mutex> guard(m_msg_mutex);
    m_message = msg;
}

int main(int argc, char *argv[])
{
    std::cout << "start main " << std::endl;
    signal(SIGINT, terminate_sig);
    rclcpp::init(argc, argv);
    KEY key{KEY::Stop};

    constexpr int servo_min = 250; // Min pulse length out of 4096
    constexpr int servo_mid = 340;
    constexpr int servo_max = 450; // Max pulse length out of 4096
    constexpr int speed_inc = 5;
    constexpr int steering_inc = 5;

    int speed{servo_mid}, steering{servo_mid};

    rclcpp::executors::MultiThreadedExecutor executor;
    auto ros2_ackerman_pub = std::make_shared<keyboard_ackermann>();
    auto key_man = std::make_shared<KeyEventManager>();
    executor.add_node(ros2_ackerman_pub);
    executor.add_node(key_man);
    executor.spin_once();

    while (!terminate)
    {
        key = key_man->get_key();
        switch (key)
        {
        case KEY::Up:
            if (servo_max > speed)
                speed = speed + speed_inc;
            else
                speed = servo_max;
            break;
        case KEY::Down:
            if (servo_min < speed)
                speed = speed - speed_inc;
            else
                speed = servo_min;
            break;
        case KEY::Left:
            if (servo_max > steering)
                steering = steering + steering_inc;
            else
                steering = servo_max;
            break;
        case KEY::Right:
            if (servo_min < steering)
                steering = steering - steering_inc;
            else
                steering = servo_min;
            break;
        case KEY::None:
            break;
        case KEY::Stop:
        default:
            speed = servo_mid;
            steering = servo_mid;
            break;
        }

        nandhi_msg_types::msg::AckermannDrive msg{};
        msg.speed = speed;
        msg.steering_angle = steering;
        ros2_ackerman_pub->set_msg(msg);

        executor.spin_once();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }

    rclcpp::shutdown();
    std::cout << "Program terminated!!" << std::endl;
    return 0;
}
