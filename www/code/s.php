<?php
$pin = 1;
system("gpio mode $pin OUTPUT");
system("gpio write $pin 1");
system("gpio write $pin 0");
echo "blink~";
?>
