import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(17 , GPIO.OUT)
num = int(input("Enter a number"))
if num == 1:
	GPIO.ouput(17 , GPIO.high)
	time.sleep(1)
	while(true):
		num1 = int(input())
			if num1==0:
				GPIO.output(17 , GPIO.high)
				break;
GPIO.cleanup()
