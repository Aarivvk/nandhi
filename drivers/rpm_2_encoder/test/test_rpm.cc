#include "rpm/rpm.hh"
#include <iostream>
#include <wiringPi.h>

void callback(int way)
{
   static int pos = 0;

   pos += way;

   std::cout << "pos=" << pos << std::endl;
}

int main(void)
{
   RotaryDecoder dec(10, 6, callback);
   delay(30000);
   dec.re_cancel();
  return 0;
}
