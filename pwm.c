#include <stdio.h>
#include <wiringPi.h>
int main()
{
    wiringPiSetup();
    pinMode(1, PWM_OUTPUT);
    pwmWrite(1,100);
}