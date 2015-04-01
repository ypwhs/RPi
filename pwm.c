#include <stdio.h>
#include <wiringPi.h>
int main()
{
    setup();
    printf("主线程开始\n");
    pwmWrite(1,100);
}