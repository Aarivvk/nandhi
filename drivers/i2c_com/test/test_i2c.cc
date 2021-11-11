#include "i2c_com/i2c.hh"
#include <signal.h>
#include <vector>

bool run = true;
uint8_t AFS_SEL = 24;
uint8_t FS_SEL = 24;
const std::vector<std::pair<int, int>> ACCEL_RANGE_PER_G_VAL_MAP{{2, 16384}, {4, 8192}, {8, 4096}, {16, 2048}};
const std::vector<std::pair<int, float>> GYRO_RANGE_PER_DEG_VAL_MAP{{250, 131}, {500, 65.5}, {1000, 32.8}, {2000, 16.4}};
int16_t VAL_PER_G = 16384;
float VAL_PER_DEG = 131;
static constexpr double G = 9.81;


void sig_catch(int sig_num)
{
	std::cout << std::endl << "Caught signal " << sig_num << std::endl;
	run = false;
}

inline int16_t combine(int16_t lsb, int16_t msb)
{
    int16_t res = (lsb | (msb << 8));
    return res;
}

double getXAcc(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_ACCEL_XOUT_H");
        // std::cout << "MPU6050_ACCEL_XOUT_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_ACCEL_XOUT_L");
        // std::cout << "MPU6050_ACCEL_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		double access_x = G * (result/VAL_PER_G);
        return access_x;
}

double getYAcc(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_ACCEL_YOUT_H");
        // std::cout << "MPU6050_ACCEL_XOUT_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_ACCEL_YOUT_L");
        // std::cout << "MPU6050_ACCEL_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		double access_y = G * (result/VAL_PER_G);
        return access_y;
}

double getZAcc(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_ACCEL_ZOUT_H");
        // std::cout << "MPU6050_ACCEL_XOUT_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_ACCEL_ZOUT_L");
        // std::cout << "MPU6050_ACCEL_XOUT_L " << resl << std::endl;
        double result = static_cast<double>(combine (resl, resh));
		double access_z = G * (result/VAL_PER_G);
        return access_z;
}

double getXGyro(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_GYRO_XOUT_H");
        // std::cout << "MPU6050_GYRO_XOUT_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_GYRO_XOUT_L");
        // std::cout << "MPU6050_GYRO_XOUT_L " << resl << std::endl;
		double gyro_x = static_cast<double>(combine (resl, resh))/VAL_PER_DEG;
        return gyro_x;
}

double getYGyro(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_GYRO_YOUT_H");
        // std::cout << "MPU6050_GYRO_XOUT_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_GYRO_YOUT_L");
        // std::cout << "MPU6050_GYRO_XOUT_L " << resl << std::endl;
		double gyro_y = static_cast<double>(combine (resl, resh))/VAL_PER_DEG;
        return gyro_y;
}

double getZGyro(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_GYRO_ZOUT_H");
        // std::cout << "MPU6050_GYRO_XOUT_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_GYRO_ZOUT_L");
        // std::cout << "MPU6050_GYRO_XOUT_L " << resl << std::endl;
		double gyro_z = static_cast<double>(combine (resl, resh))/VAL_PER_DEG;;
        return gyro_z;
}

double getTemp(I2cDevice& dev)
{
        int16_t resh = dev.getResponse("MPU6050_TEMP_H");
        // std::cout << "MPU6050_TEMP_H " << resh << std::endl;
        int16_t resl = dev.getResponse("MPU6050_TEMP_L");
        // std::cout << "MPU6050_TEMP_L " << resl << std::endl;
		double temp = combine (resl, resh)/340 + 36.53;
        return temp;
}

int readConfigurationAcc(I2cDevice& dev)
{
  uint8_t res = (dev.getConfig("ACCEL_CONFIG") & AFS_SEL) >> 3;
  VAL_PER_G = ACCEL_RANGE_PER_G_VAL_MAP.at(res).second;
  std::cout << res << " Config ACC " << VAL_PER_G << std::endl;
  return VAL_PER_G;
}

int readConfigurationGyro(I2cDevice& dev)
{
  uint8_t res = (dev.getConfig("GYRO_CONFIG") & FS_SEL) >> 3;
  VAL_PER_DEG = GYRO_RANGE_PER_DEG_VAL_MAP.at(res).second;
  std::cout << res << " Config GYRO " << VAL_PER_DEG << std::endl;
  return VAL_PER_DEG;
}

int main()
{
    signal(SIGINT, sig_catch);

    I2cBus i2c_bus(1);
    I2cDevice dev(0x68);
    dev.addConfig("MPU6050_PWR_MGMT_1", 0x6B, 0);
    dev.addConfig("ACCEL_CONFIG", 0x1C, 0);
    dev.addConfig("GYRO_CONFIG", 0x1B, 0);

    dev.addConfig("ACCEL_CONFIG", 0x1C);
    dev.addRequest("MPU6050_ACCEL_XOUT_H", 0x3B);
    dev.addRequest("MPU6050_ACCEL_XOUT_L", 0x3C);
    dev.addRequest("MPU6050_ACCEL_YOUT_H", 0x3D);
    dev.addRequest("MPU6050_ACCEL_YOUT_L", 0x3E);
    dev.addRequest("MPU6050_ACCEL_ZOUT_H", 0x3F);
    dev.addRequest("MPU6050_ACCEL_ZOUT_L", 0x40);

    dev.addConfig("GYRO_CONFIG", 0x1B);
    dev.addRequest("MPU6050_GYRO_XOUT_H", 0x43);
    dev.addRequest("MPU6050_GYRO_XOUT_L", 0x44);
    dev.addRequest("MPU6050_GYRO_YOUT_H", 0x45);
    dev.addRequest("MPU6050_GYRO_YOUT_L", 0x46);
    dev.addRequest("MPU6050_GYRO_ZOUT_H", 0x47);
    dev.addRequest("MPU6050_GYRO_ZOUT_L", 0x48);

    dev.addRequest("MPU6050_TEMP_H", 0x41);
    dev.addRequest("MPU6050_TEMP_L", 0x42);
    i2c_bus.setI2cDevice(&dev);
    i2c_bus.configure();
    readConfigurationAcc(dev);
    readConfigurationGyro(dev);

    while (run)
    {
        i2c_bus.receive();
        std::cout << std::endl;
		std::cout << "MPU6050_ACCEL_X " << getXAcc(dev) << " MPU6050_ACCEL_Y " << getYAcc(dev) << " MPU6050_ACCEL_Z " << getZAcc(dev) << std::endl;
        std::cout << std::endl;
        std::cout << "MPU6050_GYRO_X " << getXGyro(dev) << " MPU6050_GYRO_Y " << getYGyro(dev) << " MPU6050_GYRO_Z " << getZGyro(dev) << std::endl;
        std::cout << std::endl;
        std::cout << "MPU6050_TEMP " << getTemp(dev) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}