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
   RMPSingle rpms(6, 10);

   while (run)
   {
       std::cout << "curent RMP " << rpms.getRPM() << std::endl;
       delay(10);
   }
   

   
  return 0;
}
