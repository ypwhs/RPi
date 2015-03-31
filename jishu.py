import RPi.GPIO as GPIO
from time import sleep
from threading import Thread

GPIO.setmode(GPIO.BCM)
DIO = 4
SCK = 3
RCK = 2
table = [0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e]


def write(pinNumber, state):
    GPIO.setup(pinNumber, GPIO.OUT)
    GPIO.output(pinNumber, bool(state))


def destroy():
    write(18, 0)
    print "stop"


def blink(pinNumber):
    write(pinNumber, 1)
    write(pinNumber, 0)


def shiftOut(indata):
    for i in range(8):
        write(DIO, indata & (1 << (7 - i)))
        blink(SCK)


def xianshi(numbers):
    numbers = numbers[::-1]
    for i in range(len(numbers)):
        num = int(numbers[i])
        shiftOut(1 << (7 - i))
        shiftOut(table[num])
        blink(RCK)
        sleep(0.002)

mynumber = '0'


def loop():
    i = 1      
    global mynumber
    while True:
        mynumber = str(i)
        i += 1
        sleep(0.1)
        if i % 10 == 0:
            write(18, 1)
            sleep(0.0001)
            write(18, 0)


def displayThread():
    while True:
        xianshi(mynumber)


if __name__ == '__main__':
    t = Thread(target=displayThread)
    t.setDaemon(True)
    t.start()
    try:
        loop()
    except KeyboardInterrupt:
        global mynumber
        mynumber = '0'
        sleep(0.02)
        destroy()

