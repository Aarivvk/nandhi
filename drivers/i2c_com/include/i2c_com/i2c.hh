#ifndef NANDHI_DRIVERS_I2C_COM_INCLUDE_I2C_COM_I2C
#define NANDHI_DRIVERS_I2C_COM_INCLUDE_I2C_COM_I2C
extern "C"
{
#include <errno.h>
#include <fcntl.h>
#include <i2c/smbus.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdint.h>
}

#include <string>
#include <iostream>
#include <vector>

using RegValue = std::pair<uint8_t, int>;
using SigNameRV = std::pair<std::string, RegValue>;

using RequestResponse = std::vector<SigNameRV>;

class I2cDevice
{
private:
    uint8_t addr{}; /* The I2C device address ex. 0x68 for MPU6050, 0x40 for PCA9685*/
    RequestResponse reg_map_read{};
    RequestResponse reg_map_write{};
    RequestResponse reg_map_config_write{};
    RequestResponse reg_map_config_read{};

public:
    I2cDevice(uint8_t dev_addr);
    ~I2cDevice();
    uint8_t getAddress();
    RequestResponse* getRegMapRequest();
    RequestResponse* getRegMapCommand();
    RequestResponse* getRegMapConfigWrite();
    RequestResponse* getRegMapConfigRead();
    void addConfig(std::string sig_name, uint8_t req, uint8_t val);
    void addConfig(std::string sig_name, uint8_t req);
    void addRequest(std::string, uint8_t reg);
    void addCommand(std::string, uint8_t reg, int val);
    int getResponse(std::string sig_name);
    int getConfig(std::string sig_name);

};

class I2cBus
{
private:
    /* data */
    std::string file_name_{};
    int file_discriptor_;
    I2cDevice *curent_device;

public:
    I2cBus(uint8_t chanel_num);
    ~I2cBus();

    int setI2cDevice(I2cDevice* device);
    int configure();
    int send();
    int receive();
};

#endif /* NANDHI_DRIVERS_I2C_COM_INCLUDE_I2C_COM_I2C */
