#include <iostream>



class L298n_dc
{
private:
    /* data */
    size_t enA_;
    size_t in1_;
    size_t in2_;
    size_t enB_;
    size_t in3_;
    size_t in4_;
    size_t speed;
public:
    L298n_dc(size_t enA, size_t in1, size_t in2, size_t enB, size_t in3, size_t in4);
    ~L298n_dc();
    void setSpeed(int speedA, int speedB);
    void forward();
    void reverse();
    void clockwiseDiff();
    void antiClockwiseDiff();
    void stop();
};