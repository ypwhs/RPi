<?php
echo shell_exec("raspistill -t 1 -o /home/pi/www/a.jpg -w 2592 -h 1944");
echo '<img style="width: 80%" src=a.jpg>';
?>
