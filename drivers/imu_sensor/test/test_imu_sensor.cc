#include "imu_sensor/imu_sensor.hh"

int main()
{
    ImuSensor imu;
    auto ego = imu.fetchEgoState();
    std::cout << ego.raw_acc_x << " " << ego.raw_gyro_x << std::endl;
    return 0;
}