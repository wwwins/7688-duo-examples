#!/usr/bin/env python

# blink led 13

import serial
import time

myserial = None
ledStatus = 0

def led():
	global ledStatus
	if ledStatus:
		ledStatus = 0
		myserial.write("on\n")
	else:
		ledStatus = 1
		myserial.write("off\n")

def setup():
	global myserial
	myserial = serial.Serial("/dev/ttyS0", 57600)

def main():
	while 1:
		data = myserial.readline()
		print("Received: "+ data[:-1])
		time.sleep(0.5)

if __name__ == "__main__":
	setup()
	main()
