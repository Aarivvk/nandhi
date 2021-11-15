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
        L298n_dc motor_driver_front(1, 4, 5, 26, 31, 11);
        L298n_dc motor_driver_back(23, 0, 2, 24, 3, 12);
        int16_t speed = 600;
        bool togel = false;
        while (run)
        {
                std::cout << "\r" << "Speed " << speed  << std::flush;
                // motor_driver_front.setSpeed(speed, speed);
                // motor_driver_front.forward();
                // motor_driver_back.setSpeed(speed, speed);
                // motor_driver_back.forward();
                delay(100);
                // motor_driver_front.reverse();
                // delay(3000);
                // motor_driver_front.clockwiseDiff();
                // delay(3000);
                // motor_driver_front.antiClockwiseDiff();
                // delay(3000);
                // motor_driver_front.stop();

                if(1023 == speed || 434 == speed)
                {
                        togel = !togel;
                }
                if(togel)
                {
                        motor_driver_front.forward();
                        motor_driver_back.forward();
                        speed--;
                }
                else
                {
                        motor_driver_front.reverse();
                        motor_driver_back.reverse();
                        speed++;
                }

                
        }
        motor_driver_front.stop();
        motor_driver_back.stop();
}