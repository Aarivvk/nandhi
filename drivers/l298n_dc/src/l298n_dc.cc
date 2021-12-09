#include "l298n_dc/l298n_dc.hh"
#include <wiringPi.h>

Wheel::Wheel(size_t enable, size_t in1, size_t in2)
    : m_pin_enable(enable), m_pin_in_1(in1), m_pin_in_2(in2) {}

void Wheel::setSpeed(size_t percent) {
  if (0 >= percent) {
    m_speed = 0;
  } else {
    /**
     *  500 is 0%
     *  1023 is 100%
     *  Total range is 523
     */
    if (100 < percent) {
      percent = 100;
    }

    m_speed = ((percent * 523) / 100) + 500;
  }
}

void Wheel::setDirection(DIRECTION d) {
  switch (d) {
  case DIRECTION::STOP:
    m_value_in_1 = LOW;
    m_value_in_2 = LOW;
    break;
  case DIRECTION::FORWARD:
    m_value_in_1 = HIGH;
    m_value_in_2 = LOW;
    break;
  case DIRECTION::REVERSE:
    m_value_in_1 = LOW;
    m_value_in_2 = HIGH;
    break;
  default:
    break;
  }
}

void Wheel::print() {
  std::clog << "PWM pin No " << pin_enable() << " Value " << speed()
            << std::endl;
  std::clog << "In1 pin No " << pin_in_1() << " Value " << value_in_1()
            << std::endl;
  std::clog << "In2 pin No " << pin_in_2() << " Value " << value_in_2()
            << std::endl;
}

L298n_dc::L298n_dc(size_t enA, size_t in1, size_t in2, size_t enB, size_t in3,
                   size_t in4) {
  m_wheels[0] = new Wheel(enA, in1, in2);
  m_wheels[1] = new Wheel(enB, in3, in4);
  if (!wiringpi_init) {
    wiringPiSetup();
    wiringpi_init = true;
    std::clog << "wiring init done " << std::endl;
  } else {
    std::clog << "wiring init already done " << std::endl;
  }
  setGPIO();
}

void L298n_dc::setGPIO() {
  for (auto w : m_wheels) {
    pinMode(w->pin_in_1(), OUTPUT);
    pinMode(w->pin_in_2(), OUTPUT);
    pinMode(w->pin_enable(), PWM_OUTPUT);
  }
}

// speed value of max 1023

void L298n_dc::stopAll() {
  for (auto w : m_wheels) {
    w->setDirection(DIRECTION::STOP);
    w->setSpeed(LOW);
  }
  flush();
}

void L298n_dc::flush() {
  for (auto w : m_wheels) {
    pwmWrite(w->pin_enable(), w->speed());
    delay(1);
    digitalWrite(w->pin_in_1(), w->value_in_1());
    delay(1);
    digitalWrite(w->pin_in_2(), w->value_in_2());
    delay(1);
  }
}