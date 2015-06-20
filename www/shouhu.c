#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    while(1)
      {
        int pid = 0;
        fscanf(popen("ps -ef|grep detectHuman |grep -v grep | awk '{print $2}'", "r"), "%d", &pid);
        printf("pid=%d\n",pid);
        if(pid==0){
            printf("restart now\n");
            system("screen /var/www/detectHuman");
        }
        sleep(1);
    }
}
