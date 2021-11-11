#ifndef NANDHI_DRIVERS_IMU_SENSOR_INCLUDE_IMU_SENSOR_IMU_SENSOR
#define NANDHI_DRIVERS_IMU_SENSOR_INCLUDE_IMU_SENSOR_IMU_SENSOR
#include "i2c_com/i2c.hh"
#include <array>
#include <vector>
#include "nandhi_msg_types/msg/imu_sensor.hpp"

using RawImuSensorData = nandhi_msg_types::msg::ImuSensor;

class ImuSensor
{
private:
    /* data */
    I2cDevice dev_{0x68};
    I2cBus i2c_chan_{1};

    int16_t VAL_PER_G = 16384;
    float VAL_PER_DEG = 131;
    int DLPF_RANGE{260};


    static constexpr double G = 9.81;
    const uint8_t AFS_SEL = 24;
    const uint8_t FS_SEL = 24;
    const uint8_t DLPF_CONFIG_MASK = 7;
    const std::vector<std::pair<int, int>> ACCEL_RANGE_PER_G_VAL_MAP{{2, 16384}, {4, 8192}, {8, 4096}, {16, 2048}};
    const std::vector<std::pair<int, float>> GYRO_RANGE_PER_DEG_VAL_MAP{{250, 131}, {500, 65.5}, {1000, 32.8}, {2000, 16.4}};
    const std::array<int, 7> DLPF_RANGES{260, 184, 94, 44, 21, 10, 5};
    
    const size_t CALIB_REPS = 1000;
    std::array<double, 3> acc_off_set{};
    std::array<double, 3> gyro_off_set{};
    //functions
    int16_t combine(int16_t lsb, int16_t msb);

    int readConfigurationAcc();
    int readConfigurationGyro();
    int readConfigurationDLPF();

    bool calibrateDevice();

    
    double getXAcc();
    double getYAcc();
    double getZAcc();

    double getXGyro();
    double getYGyro();
    double getZGyro();

    double getXMag();
    double getYMag();
    double getZMag();

    double getTemp();
public:
    ImuSensor();
    ~ImuSensor();
    RawImuSensorData fetchEgoState();
    
};


#endif /* NANDHI_DRIVERS_IMU_SENSOR_INCLUDE_IMU_SENSOR_IMU_SENSOR */
