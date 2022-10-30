#include "i2c_pwm_pca9685/i2c_pwm.hh"


//! Constructor takes bus and address arguments
/*!
 \param bus the bus to use in /dev/i2c-%d.
 \param address the device address on bus
 */
PCA9685::PCA9685(int bus, int address) : i2c_bus{bus}, i2c_dev{address}
{
	i2c_bus.setI2cDevice(&i2c_dev);
    i2c_dev.addConfig("MODE1", MODE1, 0x00);  // Normal mode
    i2c_dev.addConfig("MODE2", MODE2, 0x04);  // totem pole (default)
	reset();
	setPWMFreq(1000);
}

PCA9685::~PCA9685() {}


//! Sets PCA9685 mode to 00
void PCA9685::reset() 
{
    i2c_bus.configure();    
}
//! Set the frequency of PWM
/*!
 \param freq desired frequency. 40Hz to 1000Hz using internal 25MHz oscillator.
 */
void PCA9685::setPWMFreq(int freq) {

		uint8_t prescale_val = (CLOCK_FREQ / 4096 / freq)  - 1;
        i2c_dev.getRegMapCommand()->clear();
		i2c_dev.addCommand("MODE1", MODE1, 0x10); //sleep
		i2c_dev.addCommand("PRE_SCALE", PRE_SCALE, prescale_val); // multiplyer for PWM frequency
		i2c_dev.addCommand("MODE1", MODE1, 0x80); //restart
		i2c_dev.addCommand("MODE2", MODE2, 0x04); //totem pole (default)
        i2c_bus.send();
}

//! PWM a single channel
/*!
 \param led channel (0-15) to set PWM value for
 \param value 0-4095 value for PWM
 */
void PCA9685::setPWM(uint8_t led, int value) 
{
	setPWM(led, 0, value);
}

inline int PCA9685::getLEDReg(int reg, int led)
{
    auto result = reg + (LED_MULTIPLYER * led);
    return result;
}

//! PWM a single channel with custom on time
/*!
 \param led The channel that should be updated with the new values (0..15).
 \param on_value The tick (between 0..4095) when the signal should transition from low to high.
 \param off_value The tick (between 0..4095) when the signal should transition from high to low.
 */
void PCA9685::setPWM(uint8_t led, int on_value, int off_value) 
{
        i2c_dev.getRegMapCommand()->clear();
        auto led0_on_l = getLEDReg(LED0_ON_L, led);
		i2c_dev.addCommand("LED0_ON_L"+std::to_string(led0_on_l), led0_on_l, on_value & 0xFF);
        
        auto led0_on_h = getLEDReg(LED0_ON_H, led);
		i2c_dev.addCommand("LED0_ON_H"+std::to_string(led0_on_h), led0_on_h, on_value >> 8);

        auto led0_off_l = getLEDReg(LED0_OFF_L, led);
		i2c_dev.addCommand("LED0_OFF_L"+std::to_string(led0_off_l), led0_off_l, off_value & 0xFF);

        auto led0_off_h = getLEDReg(LED0_OFF_H, led);
		i2c_dev.addCommand("LED0_OFF_H"+std::to_string(led0_off_h), led0_off_h, off_value >> 8);

        i2c_bus.send();
}

//! Get current PWM value
/*!
 \param led channel (1-16) to get PWM value from
 */
int PCA9685::getPWM(uint8_t led){
    i2c_dev.getRegMapRequest()->clear();
	int ledval = 0;
    auto led_off_h = getLEDReg(LED0_OFF_H, led);
    auto sig_name_h = "LED0_OFF_H"+std::to_string(led_off_h);
    i2c_dev.addRequest(sig_name_h, led_off_h);
    
    auto led_off_l = getLEDReg(LED0_OFF_L, led);
    auto sig_name_l = "LED0_OFF_L"+std::to_string(led_off_l);
    i2c_dev.addRequest(sig_name_l, led_off_l);
    
    i2c_bus.receive();
	
    ledval = i2c_dev.getResponse(sig_name_h);
	ledval = ledval & 0xf;
	ledval <<= 8;
	ledval += i2c_dev.getResponse(sig_name_l);
	return ledval;
}