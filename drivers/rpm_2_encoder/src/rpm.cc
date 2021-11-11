#include <wiringPi.h>
#include <iostream>

#include "rpm/rpm.hh"

/*

             +---------+         +---------+      0
             |         |         |         |
   A         |         |         |         |
             |         |         |         |
   +---------+         +---------+         +----- 1

       +---------+         +---------+            0
       |         |         |         |
   B   |         |         |         |
       |         |         |         |
   ----+         +---------+         +---------+  1

*/


RotaryDecoder *RotaryDecoder::mySelf;


void RotaryDecoder::_pulse(int gpio, int level)
{
   if (gpio == mygpioA) levA = level; else levB = level;

   if (gpio != lastGpio) /* debounce */
   {
      lastGpio = gpio;

      if ((gpio == mygpioA) && (level == 1))
      {
         if (levB) (mycallback)(1);
      }
      else if ((gpio == mygpioB) && (level == 1))
      {
         if (levA) (mycallback)(-1);
      }
   }
   else
   {
      std::cout << "Not a rotation!! " << mySelf->levB << std::endl;
   }
}

void RotaryDecoder::_pulseEx(int gpio, int level)
{
   /*
      Need a static callback to link with C.
   */

   mySelf->_pulse(gpio, level); /* Call the instance callback. */
}


void RotaryDecoder::_pulseExA()
{
   /*
      Need a static callback to link with C.
   */

   auto val = digitalRead(mySelf->mygpioA);
   mySelf->levA = val;
   std::cout << "Signel from A the decoder " << mySelf->mygpioA << " val " << val << std::endl;
   mySelf->_pulseEx(mySelf->mygpioA, mySelf->levA); /* Call the instance callback. */
}


void RotaryDecoder::_pulseExB()
{
   /*
      Need a static callback to link with C.
   */

   auto val = digitalRead(mySelf->mygpioB);
   mySelf->levB = val;
   std::cout << "Signel from B the decoder " << mySelf->mygpioB << " val " << val << std::endl;
   mySelf->_pulseEx(mySelf->mygpioB, mySelf->levB); /* Call the instance callback. */
}


RotaryDecoder::RotaryDecoder(int gpioA, int gpioB, RE_decoderCB_t callback)
{
   std::cout << "Created the decoder " << gpioA << " " << gpioB << std::endl;
   mygpioA = gpioA;
   mygpioB = gpioB;

   mycallback = callback;

   levA=0;
   levB=0;

   lastGpio = -1;

   mySelf = this;

   wiringPiSetup();

   pinMode(gpioA, INPUT);
   pinMode(gpioB, INPUT);

   /* monitor encoder level changes */
   wiringPiISR(gpioA, INT_EDGE_BOTH, &RotaryDecoder::_pulseExA);
   wiringPiISR(gpioB, INT_EDGE_BOTH, &RotaryDecoder::_pulseExB);
}

void RotaryDecoder::re_cancel(void)
{
   pinMode(mygpioA, INPUT);
   pinMode(mygpioB, INPUT);
}

