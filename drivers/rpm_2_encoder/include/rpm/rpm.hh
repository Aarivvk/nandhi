#ifndef DRIVERS_RPM_INCLUDE_RPM_RPM
#define DRIVERS_RPM_INCLUDE_RPM_RPM

typedef void (*RE_decoderCB_t)(int);

class RotaryDecoder
{
   int mygpioA, mygpioB, levA, levB, lastGpio;

   RE_decoderCB_t mycallback;

   void _pulse(int gpio, int level);

   /* Need a static callback to link with C. */
   void _pulseEx(int gpio, int level);

   static void _pulseExA();

   static void _pulseExB();

   static RotaryDecoder *mySelf;


   public:

   RotaryDecoder(int gpioA, int gpioB, RE_decoderCB_t callback);
   /*
      This function establishes a rotary encoder on gpioA and gpioB.

      When the encoder is turned the callback function is called.
   */

   void re_cancel(void);
   /*
      This function releases the resources used by the decoder.
   */
};


#endif /* DRIVERS_RPM_INCLUDE_RPM_RPM */
