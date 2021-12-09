#include <iostream>
#include <array>


static bool wiringpi_init{false};

enum class DIRECTION
{
    FORWARD,
    REVERSE,
    STOP
};
class Wheel
{
    private:
    size_t m_pin_enable; // PWM Speed control
    size_t m_pin_in_1;
    size_t m_value_in_1;
    size_t m_pin_in_2;
    size_t m_value_in_2;
    size_t m_speed{0};
    
    public:
    Wheel(size_t enable, size_t in1, size_t in2);
    ~Wheel() = default;
    /**
     * @brief Set the Speed in percentage '%'.
     * 
     * @param percent % of the speed from 0 to 100.
     */
    void setSpeed(size_t percent);
    void setDirection(DIRECTION d);
    size_t pin_enable(){return m_pin_enable;};
    size_t pin_in_1(){return m_pin_in_1;};
    size_t pin_in_2(){return m_pin_in_2;};
    size_t speed(){return m_speed;};
    size_t value_in_1(){return m_value_in_1;};
    size_t value_in_2(){return m_value_in_2;};
    void print();
};

class L298n_dc
{
private:
    std::array<Wheel*, 2> m_wheels;
    void setGPIO();

public:
    L298n_dc(size_t enA, size_t in1, size_t in2, size_t enB, size_t in3, size_t in4);
    ~L298n_dc() = default;
    std::array<Wheel*, 2> getWheels(){return m_wheels;};
    void flush();
    void stopAll();
};