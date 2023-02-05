#include "i2c_com/i2c.hh"
#include <chrono>
#include <thread>
#include <algorithm>


I2cDevice::I2cDevice(uint8_t dev_addr):addr{dev_addr}
{

}

I2cDevice::~I2cDevice()
{

}

void I2cDevice::addConfig(std::string sig_name, uint8_t req, uint8_t val)
{
    RegValue p(req, val);
    reg_map_config_write.push_back(SigNameRV(sig_name, p));
}

void I2cDevice::addConfig(std::string sig_name, uint8_t req)
{
    std::pair<uint8_t, int> p;
    p.first = req;
    reg_map_config_read.push_back(SigNameRV(sig_name, p));
}

void I2cDevice::addRequest(std::string sig_name, uint8_t reg)
{
    std::pair<uint8_t, int> p;
    p.first = reg;
    reg_map_read.push_back(SigNameRV(sig_name, p));
}

void I2cDevice::addCommand(std::string sig_name, uint8_t reg, int val)
{
    std::pair<uint8_t, int> p{reg, val};
    reg_map_write.push_back(SigNameRV(sig_name, p));
}

int I2cDevice::getResponse(std::string sig_name)
{
    int result = -1;
    auto it = std::find_if( reg_map_read.begin(), reg_map_read.end(), 
                    [&sig_name](const SigNameRV& x) 
                    { 
                        return x.first.compare(sig_name) == 0;
                    }
    );
    if(reg_map_read.end() != it)
    {
        result = it->second.second;
    }
    else
    {
        std::cout << "Invalid Request " << std::endl;
    }
    return result;
}

int I2cDevice::getConfig(std::string sig_name)
{
    int result = -1;
    auto it = std::find_if( reg_map_config_read.begin(), reg_map_config_read.end(), 
                [&sig_name](const SigNameRV& x) 
                { 
                    bool result = x.first.compare(sig_name)==0;
                    return result;
                }
    );
    if(reg_map_config_read.end() != it)
    {
        result = it->second.second;
    }
    else
    {
        std::cout << "Invalid Config Request " << std::endl;
    }
    return result;
}

uint8_t I2cDevice::getAddress()
{
    return addr;
}

RequestResponse* I2cDevice::getRegMapRequest()
{
    return &reg_map_read;
}

RequestResponse* I2cDevice::getRegMapCommand()
{
    return &reg_map_write;
}

RequestResponse* I2cDevice::getRegMapConfigWrite()
{
    return &reg_map_config_write;
}

RequestResponse* I2cDevice::getRegMapConfigRead()
{
    return &reg_map_config_read;
}

I2cBus::I2cBus(uint8_t chanel_num)
{
    file_name_ = "/dev/i2c-" + std::to_string(chanel_num);
    file_discriptor_ = open(file_name_.c_str(), O_RDWR);
    if (file_discriptor_ < 0)
    {
        /* ERROR HANDLING; you can check errno to see what went wrong */
        std::cout << "ERROR: Unable to access I2C bus " << std::endl;
        exit(1);
    }
}

I2cBus::~I2cBus()
{
    close(file_discriptor_);
}

int I2cBus::setI2cDevice(I2cDevice *device)
{
    int ret = 0;

    if (nullptr != device)
    {
        curent_device = device;
        if (ioctl(file_discriptor_, I2C_SLAVE, curent_device->getAddress()) < 0)
        {
            /* ERROR HANDLING; you can check errno to see what went wrong */
            std::cout << "ERROR: Unable to access the device address " << curent_device->getAddress() << std::endl;
            ret = -1;
        }
        else
        {
            ret = 0;
        }
    }
    else
    {
        std::cout << "ERROR: Invalid device !!" << std::endl;
        ret = -1;
    }

    return ret;
}

int I2cBus::configure()
{
    int ret = 0;
    for (auto &config : *(curent_device->getRegMapConfigWrite()))
    {
        std::cout << "Config name : " << config.first << " Reg : " << std::to_string(config.second.first) << " value : " << std::to_string(config.second.second) << std::endl;
        auto res = i2c_smbus_write_byte_data(file_discriptor_, config.second.first, config.second.second);
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        if (config.first.find("WAIT") != std::string::npos)
        {
            std::cout << "Configuration wait 100ms" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        
        if(0 > res) ret = -1;
    }
    for (auto &config : *(curent_device->getRegMapConfigRead()))
    {
        config.second.second = i2c_smbus_read_byte_data(file_discriptor_, config.second.first);
        std::cout << "Read Config name : " << config.first << " Reg : " << std::to_string(config.second.first) << " value : " << std::to_string(config.second.second) << std::endl;
        if(0 > config.second.second) ret = -1;
    }
    
    return ret;
}

int I2cBus::receive()
{
    int ret = 0;
    for (auto& request : *curent_device->getRegMapRequest())
    {
        request.second.second = i2c_smbus_read_byte_data(file_discriptor_, request.second.first);
        // std::cout << request.first << " " << std::to_string(request.second.first) << " " << std::to_string(request.second.second) << std::endl;
        if (0 > request.second.second)
        {
            // std::cerr << "I2C device " << curent_device->getAddress() << "did not respond!!" << std::endl;
            ret = -1;
        } 
        
    }

    return ret;
}

int I2cBus::send()
{
    int ret = 0;
    for (auto& command : *curent_device->getRegMapCommand())
    {
        auto res = i2c_smbus_write_byte_data(file_discriptor_, command.second.first, command.second.second);
        // std::cout << command.first << " " << std::to_string(command.second.first) << " " << std::to_string(command.second.second) << std::endl;
        if (0 > ret) ret = -1;
    }

    return ret;
}