#include "l298n_dc/l298n_dc.hh"
#include <wiringPi.h>

L298n_dc::L298n_dc(size_t enA, size_t in1, size_t in2, size_t enB, size_t in3, size_t in4):
enA_{enA}, in1_{in1}, in2_{in2}, enB_{enB}, in3_{in3}, in4_{in4}
{

    wiringPiSetup();

    pinMode(in1_, OUTPUT);
    pinMode(in2_, OUTPUT);
    pinMode(enA_, PWM_OUTPUT);

    pinMode(in3_, OUTPUT);
    pinMode(in4_, OUTPUT);
    pinMode(enB_, PWM_OUTPUT);
    
}

L298n_dc::~L298n_dc()
{
}

// speed value of max 1023
void L298n_dc::setSpeed(int speedA, int speedB)
{
    pwmWrite(enA_, speedA);
    pwmWrite(enB_, speedB);

}
void L298n_dc::forward()
{
    digitalWrite(in1_, LOW);
    digitalWrite(in2_, HIGH);
    
    digitalWrite(in3_, LOW);
    digitalWrite(in4_, HIGH);

}
void L298n_dc::reverse()
{
    digitalWrite(in1_, HIGH);
    digitalWrite(in2_, LOW);
    
    digitalWrite(in3_, HIGH);
    digitalWrite(in4_, LOW);

}
void L298n_dc::clockwiseDiff()
{
    digitalWrite(in1_, LOW);
    digitalWrite(in2_, HIGH);
    
    digitalWrite(in3_, HIGH);
    digitalWrite(in4_, LOW);
}
void L298n_dc::antiClockwiseDiff()
{
    digitalWrite(in1_, HIGH);
    digitalWrite(in2_, LOW);

    digitalWrite(in3_, LOW);
    digitalWrite(in4_, HIGH);
}
void L298n_dc::stop()
{
    digitalWrite(in1_, LOW);
    digitalWrite(in2_, LOW);

    digitalWrite(in3_, LOW);
    digitalWrite(in4_, LOW);
    
    pwmWrite(enA_, LOW);
    pwmWrite(enB_, LOW);
}