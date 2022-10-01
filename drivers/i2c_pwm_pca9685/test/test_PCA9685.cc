#include"i2c_pwm_pca9685/i2c_pwm.hh"
#include <iostream>
#include <chrono>
#include <thread>
#include <signal.h>

bool terminate{false};

void terminate_sig(int s)
{
    std::cout << "\nCaught signal " << s  << std::endl;
    terminate = true;
}


int main()
{
    signal (SIGINT,terminate_sig);

    PCA9685 pca = PCA9685(8, 0x40);

    int servo_min = 250;  // Min pulse length out of 4096
    int servo_mid = 340;
    int servo_max = 450;  // Max pulse length out of 4096
    pca.setPWMFreq(55);

    int i{1};
    int value{servo_min};
    bool togle{true};

    pca.setPWM(1, servo_mid);
    pca.setPWM(0, servo_mid);
    
    while (!terminate)
    {
        pca.setPWM(0, value);
        pca.setPWM(1, value);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(togle)
        {
            std::cout << " value " << value << std::endl;
            value++;
        }
        else
        {
            std::cout << " value " << value << std::endl;
            value--;
        }
        if(value == servo_max || value == servo_min)
        {
            togle = !togle;
            std::cout << "Togled " << togle << std::endl;
        }
        
    }
    
    pca.setPWM(1, servo_mid);
    pca.setPWM(0, servo_mid);

    return 0;
}
