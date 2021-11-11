#ifndef DRIVERS_RPM_SINGLE_DECODER_INCLUDE_RPM_SINGLE_DECODER_RPM_SINGLE
#define DRIVERS_RPM_SINGLE_DECODER_INCLUDE_RPM_SINGLE_DECODER_RPM_SINGLE

#include <iostream>
#include <wiringPi.h>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class RMPSingle
{
private:
    /* data */
    uint8_t num_slots{};
    static RMPSingle* myself;
    double rpm{0};
    TimePoint prev_time{};
    std::chrono::duration<double> dt_time_last{};

    static void pulse();
    void calculateRPM();

public:
    RMPSingle(size_t pin, size_t nslots);
    ~RMPSingle();
    double getRPM();
};


#endif /* DRIVERS_RPM_SINGLE_DECODER_INCLUDE_RPM_SINGLE_DECODER_RPM_SINGLE */
