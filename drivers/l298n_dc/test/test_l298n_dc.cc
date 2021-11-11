#include "l298n_dc/l298n_dc.hh"
#include <wiringPi.h>
#include <signal.h>


bool run= true;

void signal_cb(int num)
{
        run= false;
}

int main()
{
        signal(SIGINT, signal_cb);
        L298n_dc motor_driver(1, 4, 5, 26, 31, 11);
        int16_t speed = 435;
        bool togel = false;
        while (run)
        {
                std::cout << "\r" << "Speed " << speed  << std::endl;
                motor_driver.setSpeed(speed, speed);
                motor_driver.forward();
                delay(100);
                // motor_driver.reverse();
                // delay(3000);
                // motor_driver.clockwiseDiff();
                // delay(3000);
                // motor_driver.antiClockwiseDiff();
                // delay(3000);
                // motor_driver.stop();

                if(1023 == speed || 434 == speed)
                {
                        togel = !togel;
                }
                if(togel)
                {
                        speed--;
                }
                else
                {
                        speed++;
                }

                
        }
        motor_driver.stop();
}