#!/usr/bin/env python

# blink wifi led gpio 44 from arduino

import mraa
import serial
import time

GPIO_PIN = 44

myserial = None
ledStatus = 0
myled = None

def led(on):
	if on:
		myled.write(0)
	else:
		myled.write(1)

def setup():
	global myserial
	myserial = serial.Serial("/dev/ttyS0", 57600)

	global myled
	myled = mraa.Gpio(GPIO_PIN)
	myled.dir(mraa.DIR_OUT)
	myled.write(1)

def main():
	while 1:
		data = myserial.readline()
		print("Received: "+ data[:-1])
		if (data[:-1] == "led on"):
			led(True)
		if (data[:-1] == "led off"):
			led(False)
		time.sleep(0.2)

try:
	if __name__ == "__main__":
		setup()
		main()
finally:
	print("\ncleanup")
	myled.write(1)
