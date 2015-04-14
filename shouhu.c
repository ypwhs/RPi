#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    while(1)
      {
        int pid = 0;
        fscanf(popen("ps -ef|grep a.out |grep -v grep | awk '{print $2}'", "r"), "%d", &pid);
        printf("pid=%d\n",pid);
        if(pid==0){
            printf("restart a.out\n");
            system("cd /root/www;screen ./a.out");
        }
        sleep(1);
    }
}
