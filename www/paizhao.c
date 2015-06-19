#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#define LED 0
int main()
{
while(1)
  {
    char cmd[100];
    sprintf(cmd, "raspistill -t 1 -o /root/www/img/%d.jpg -w 1920 -h 1080", time(0));
    system(cmd);
    printf(cmd);
    printf("\n");
    sleep(60);
  }
}
