#include <rpm_single_decoder/rpm_single.hh>

RMPSingle *RMPSingle::myself;

RMPSingle::RMPSingle(size_t pin, size_t nslots)
{

    num_slots = nslots;
    myself = this;

    wiringPiSetup();

    pinMode(pin, INPUT);

    wiringPiISR(pin, INT_EDGE_FALLING, &RMPSingle::pulse);
}

RMPSingle::~RMPSingle()
{
}

void RMPSingle::pulse()
{
    myself->count++;
    if ((myself->count % myself->num_slots) == 0)
    {
        myself->calculateRPM();
        myself->count = 0;
    }
}

void RMPSingle::calculateRPM()
{
    auto now_time = Clock::now();
    std::chrono::duration<double> dt_time = now_time - prev_time;
    // rpm = (count / (num_slots * (dt_time.count() / 60)));
    rpm = (1*60)/dt_time.count();
    prev_time = now_time;
    dt_time_last = dt_time;
}

double RMPSingle::getRPM()
{
    std::chrono::duration<double> dt_time_now = Clock::now() - prev_time;
    return rpm;
}