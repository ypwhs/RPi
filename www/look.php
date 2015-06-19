<?php
echo shell_exec("raspistill -t 1 -o /home/pi/www/a.jpg -w 1920 -h 1080");
echo '<img style="width: 80%" src=a.jpg>';
?>
