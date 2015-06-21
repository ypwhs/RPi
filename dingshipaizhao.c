#include <stdio.h>
#include <time.h>
int main()
{
	while(1){
		system("raspistill -t 1 -o /var/www/b.jpg -w 640 -h 480");
		system("curl  -F \"file=@/var/www/b.jpg\" \"http://l.ypw.hk/upload2.php\"");
		sleep(60);
	}
}