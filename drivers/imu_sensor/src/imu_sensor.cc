#include "imu_sensor/imu_sensor.hh"
#include <math.h>


ImuSensor::ImuSensor()
{
    //Power on the device
    dev_.addConfig("MPU6050_PWR_MGMT_1", 0x6B, 0);
    //Disable master mode.
    dev_.addConfig("MPU9250_USER_CTRL", 0x6A,0x00);
    // enable bypass.
    dev_.addConfig("MPU9250_BYPASS_ADDR", 0x37, 0x02);
    // // power down mag
    // dev_.addConfig("MPU9250_MAGN_MEAS_MODE_WAIT", 0x0A, 0x00);
    // // switch mag to 100khz
    // dev_.addConfig("MPU9250_MAGN_MEAS_MODE2_WAIT", 0x0A, 0x16);
    // 0x00 AFS_SEL 00 Full Scale Range ± 2g
    // 0x08 AFS_SEL 01 Full Scale Range ± 4g
    // 0x10 AFS_SEL 02 Full Scale Range ± 8g
    // 0x18 AFS_SEL 03 Full Scale Range ± 16g
    dev_.addConfig("ACCEL_CONFIG", 0x1C, 0x00); 
    dev_.addConfig("GYRO_CONFIG", 0x1B, 0x00); // +- 250 deg/s
    // dev_.addConfig("MPU9250_DLPF_CONFIG", 0x1A, 0x02);

    dev_.addConfig("ACCEL_CONFIG", 0x1C);
    dev_.addRequest("MPU6050_ACCEL_XOUT_H", 0x3B);
    dev_.addRequest("MPU6050_ACCEL_XOUT_L", 0x3C);
    dev_.addRequest("MPU6050_ACCEL_YOUT_H", 0x3D);
    dev_.addRequest("MPU6050_ACCEL_YOUT_L", 0x3E);
    dev_.addRequest("MPU6050_ACCEL_ZOUT_H", 0x3F);
    dev_.addRequest("MPU6050_ACCEL_ZOUT_L", 0x40);

    dev_.addConfig("GYRO_CONFIG", 0x1B);
    dev_.addRequest("MPU6050_GYRO_XOUT_H", 0x43);
    dev_.addRequest("MPU6050_GYRO_XOUT_L", 0x44);
    dev_.addRequest("MPU6050_GYRO_YOUT_H", 0x45);
    dev_.addRequest("MPU6050_GYRO_YOUT_L", 0x46);
    dev_.addRequest("MPU6050_GYRO_ZOUT_H", 0x47);
    dev_.addRequest("MPU6050_GYRO_ZOUT_L", 0x48);

    // dev_.addConfig("MPU9250_DLPF_CONFIG", 0x1A);
    // dev_.addRequest("MPU9250_MAG_XOUT_H", 0x04);
    // dev_.addRequest("MPU9250_MAG_XOUT_L", 0x03);
    // dev_.addRequest("MPU9250_MAG_YOUT_H", 0x06);
    // dev_.addRequest("MPU9250_MAG_YOUT_L", 0x05);
    // dev_.addRequest("MPU9250_MAG_ZOUT_H", 0x08);
    // dev_.addRequest("MPU9250_MAG_ZOUT_L", 0x07);

    dev_.addRequest("MPU6050_TEMP_H", 0x41);
    dev_.addRequest("MPU6050_TEMP_L", 0x42);
    i2c_chan_.setI2cDevice(&dev_);
    i2c_chan_.configure();
    readConfigurationAcc();
    readConfigurationGyro();
    // readConfigurationDLPF();
    calibrateDevice();
}

ImuSensor::~ImuSensor()
{
}

bool ImuSensor::calibrateDevice()
{
    std::cout << "Calibrating ...." << std::endl;
    bool sucess = false;
    for (size_t i = 0; i < CALIB_REPS; i++)
    {
        i2c_chan_.receive();
        acc_off_set[0] += getXAcc();
        acc_off_set[1] += getYAcc();
        acc_off_set[2] += getZAcc();

        gyro_off_set[0] += getXGyro();
        gyro_off_set[1] += getYGyro();
        gyro_off_set[2] += getZGyro();
    }
    acc_off_set[0] /= CALIB_REPS;
    acc_off_set[1] /= CALIB_REPS;
    acc_off_set[2] /= CALIB_REPS;
    // acc_off_set[2] += G;
    gyro_off_set[0] /= CALIB_REPS;
    gyro_off_set[1] /= CALIB_REPS;
    gyro_off_set[2] /= CALIB_REPS;

    for(auto i: acc_off_set)
    {
        std::cout << "Acc : " << i << std::endl;
    }
        for(auto i: gyro_off_set)
    {
        std::cout << "Gyro : " << i << std::endl;
    }
    sucess = true;
    return sucess;
}

int16_t ImuSensor::combine(int16_t lsb, int16_t msb)
{
    int16_t res = (lsb | (msb << 8));
    return res;
}

double ImuSensor::getXAcc()
{
        int16_t resh = dev_.getResponse("MPU6050_ACCEL_XOUT_H");
        // std::cout << "MPU6050_ACCEL_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_ACCEL_XOUT_L");
        // std::cout << "MPU6050_ACCEL_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		double access_x =  (result/VAL_PER_G);
        return access_x;
}

double ImuSensor::getYAcc()
{
        int16_t resh = dev_.getResponse("MPU6050_ACCEL_YOUT_H");
        // std::cout << "MPU6050_ACCEL_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_ACCEL_YOUT_L");
        // std::cout << "MPU6050_ACCEL_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		double access_y = (result/VAL_PER_G);
        return access_y;
}

double ImuSensor::getZAcc()
{
        int16_t resh = dev_.getResponse("MPU6050_ACCEL_ZOUT_H");
        // std::cout << "MPU6050_ACCEL_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_ACCEL_ZOUT_L");
        // std::cout << "MPU6050_ACCEL_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		double access_z = (result/VAL_PER_G);
        return access_z;
}

double ImuSensor::getXGyro()
{
        int16_t resh = dev_.getResponse("MPU6050_GYRO_XOUT_H");
        // std::cout << "MPU6050_GYRO_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_GYRO_XOUT_L");
        // std::cout << "MPU6050_GYRO_XOUT_L " << resl << std::endl;
		double gyro_x = static_cast<double>(combine (resl, resh))/VAL_PER_DEG;
        return gyro_x;
}

double ImuSensor::getYGyro()
{
        int16_t resh = dev_.getResponse("MPU6050_GYRO_YOUT_H");
        // std::cout << "MPU6050_GYRO_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_GYRO_YOUT_L");
        // std::cout << "MPU6050_GYRO_XOUT_L " << resl << std::endl;
		double gyro_y = static_cast<double>(combine (resl, resh))/VAL_PER_DEG;
        return gyro_y;
}

double ImuSensor::getZGyro()
{
        int16_t resh = dev_.getResponse("MPU6050_GYRO_ZOUT_H");
        // std::cout << "MPU6050_GYRO_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_GYRO_ZOUT_L");
        // std::cout << "MPU6050_GYRO_XOUT_L " << resl << std::endl;
		double gyro_z = static_cast<double>(combine (resl, resh))/VAL_PER_DEG;;
        return gyro_z;
}

double ImuSensor::getXMag()
{
        int16_t resh = dev_.getResponse("MPU9250_MAG_XOUT_H");
        std::cout << "MPU9250_MAG_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU9250_MAG_XOUT_L");
        std::cout << "MPU9250_MAG_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		result = result * (4912/32760);
        return result;
}

double ImuSensor::getYMag()
{
        int16_t resh = dev_.getResponse("MPU9250_MAG_YOUT_H");
        std::cout << "MPU9250_MAG_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU9250_MAG_YOUT_L");
        std::cout << "MPU9250_MAG_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		result = result * (4912/32760);
        return result;
}

double ImuSensor::getZMag()
{
        int16_t resh = dev_.getResponse("MPU9250_MAG_ZOUT_H");
        std::cout << "MPU9250_MAG_XOUT_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU9250_MAG_ZOUT_L");
        std::cout << "MPU9250_MAG_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		result = result * (4912/32760);
        return result;
}

double ImuSensor::getTemp()
{
        int16_t resh = dev_.getResponse("MPU6050_TEMP_H");
        // std::cout << "MPU6050_TEMP_H " << resh << std::endl;
        int16_t resl = dev_.getResponse("MPU6050_TEMP_L");
        // std::cout << "MPU6050_TEMP_L " << resl << std::endl;
		double temp = combine (resl, resh)/340 + 36.53;
        return temp;
}

int ImuSensor::readConfigurationAcc()
{
  uint8_t res = (dev_.getConfig("ACCEL_CONFIG") & AFS_SEL) >> 3;
  VAL_PER_G = ACCEL_RANGE_PER_G_VAL_MAP.at(res).second;
  std::cout << res << " Config ACC " << VAL_PER_G << std::endl;
  return VAL_PER_G;
}

int ImuSensor::readConfigurationGyro()
{
  uint8_t res = (dev_.getConfig("GYRO_CONFIG") & FS_SEL) >> 3;
  VAL_PER_DEG = GYRO_RANGE_PER_DEG_VAL_MAP.at(res).second;
  std::cout << res << " Config GYRO " << VAL_PER_DEG << std::endl;
  return VAL_PER_DEG;
}

int ImuSensor::readConfigurationDLPF()
{
  uint8_t res = (dev_.getConfig("GYRO_CONFIG") & DLPF_CONFIG_MASK);
  DLPF_RANGE = DLPF_RANGES.at(res);
  std::cout << res << " Config DLPF " << DLPF_RANGE << std::endl;
  return DLPF_RANGE;
}

RawImuSensorData ImuSensor::fetchEgoState()
{
    RawImuSensorData data;
    i2c_chan_.receive();
    data.raw_acc_x = getXAcc() - acc_off_set[0];
    data.raw_acc_y = getYAcc() - acc_off_set[1];
    data.raw_acc_z = getZAcc() - acc_off_set[2];

    data.raw_gyro_x = getXGyro() - gyro_off_set[0];
    data.raw_gyro_y = getYGyro() - gyro_off_set[1];
    data.raw_gyro_z = getZGyro() - gyro_off_set[2];

    // data.raw_mag_x = getXMag();
    // data.raw_mag_y = getYMag();
    // data.raw_mag_z = getZMag();

    data.temp = getTemp();

    return data;

}