#include "l298n_dc/l298n_dc.hh"
#include <signal.h>
#include <vector>
#include <wiringPi.h>

bool run = true;

void signal_cb(int num) { run = false; }

int main() {
  signal(SIGINT, signal_cb);
  L298n_dc motor_driver_right(1, 4, 5, 26, 31, 11);
  L298n_dc motor_driver_left(23, 2, 0, 24, 12, 3);
  auto wlsr = motor_driver_right.getWheels();
  auto wlsl = motor_driver_left.getWheels();

  for (auto w : wlsl) {
    w->setDirection(DIRECTION::FORWARD);
    w->setSpeed(100);
    w->print();
  }
  for (auto w : wlsr) {
    w->setDirection(DIRECTION::FORWARD);
    w->setSpeed(100);
    w->print();
  }
  motor_driver_right.flush();
  motor_driver_left.flush();
  while (run) {
    delay(2000);
  }
  motor_driver_right.stopAll();
  motor_driver_left.stopAll();
}