#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
while(1)
  {
    char cmd[100];
    sprintf(cmd, "raspistill -t 1 -o /home/pi/www/img/%d.jpg -w 1920 -h 1080", time(0));
    system(cmd);
    printf(cmd);
    printf("\n");
    sleep(60);
  }
}
