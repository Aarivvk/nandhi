#include "rpm_single_decoder/rpm_single.hh"
#include <signal.h>


bool run = true;

void signal_cb(int signal)
{
    run = false;
}

int main(void)
{
   signal(SIGINT, signal_cb);
   RMPSingle rpms(6, 20);
auto crmpnc = 0.22;
   while (run)
   {
       auto rpm = rpms.getRPM();
       std::cout << "\rcurent RMP " << rpm << " Speed " << (rpm*crmpnc)/60 ;
       delay(10);
   }
   
  return 0;
}
