#include "i2c_pwm_pca9685/i2c_pwm.hh"
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <memory>
#include <signal.h>
#include <stdio.h>

bool terminate{false};

void terminate_sig(int s)
{
    std::cout << "\nCaught signal " << s << std::endl;
    terminate = true;
}

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
    KeyEventManager()
    {
        system("stty raw");
        system("stty -echo");
        m_key_thread_ptr = std::make_unique<std::thread>(&KeyEventManager::run, this);
    }

    ~KeyEventManager()
    {
        m_key_thread_ptr->join();
        system("stty cooked");
        system("stty echo");
        std::cout << "KeyEventManager Ended!!" << std::endl;
    }

    KEY get_key()
    {
        std::lock_guard<std::mutex> guard(m_key_mutex);
        auto ret = m_key;
        m_key = KEY::None;
        return ret;
    }

private:
    std::mutex m_key_mutex{};
    KEY m_key{KEY::None};
    std::unique_ptr<std::thread> m_key_thread_ptr;

    void setKey(char key)
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
            std::cerr << "Unknown key recived: " << key << std::endl;
            m_key = KEY::Stop;
            terminate = true;
            break;
        }
    }

    void read_key_press()
    {
        char key{};
        key = getchar();
        setKey(key);
    }

    void run()
    {
        while (!terminate)
        {
            read_key_press();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

int main()
{
    signal(SIGINT, terminate_sig);
    
    KeyEventManager key_man{};
    KEY key{KEY::Stop};

    PCA9685 pca = PCA9685(8, 0x40);
    pca.setPWMFreq(55);

    constexpr int servo_min = 250; // Min pulse length out of 4096
    constexpr int servo_mid = 350;
    constexpr int servo_max = 450; // Max pulse length out of 4096
    constexpr int speed_inc = 10;
    constexpr int steering_inc = 10;

    int speed{servo_mid}, steering{servo_mid};

    pca.setPWM(1, servo_mid);
    pca.setPWM(0, servo_mid);

    while (!terminate)
    {
        key = key_man.get_key();     
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
        pca.setPWM(0, speed);
        pca.setPWM(1, steering);
        // std::cout << " steering " << steering << " speed " << speed << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    pca.setPWM(1, servo_mid);
    pca.setPWM(0, servo_mid);

    std::cout << "Program terminated!!" << std::endl;
    return 0;
}
