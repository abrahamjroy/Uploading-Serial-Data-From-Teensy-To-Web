# Run this Python script on your terminal to get them dope readings
import serial
import sys
import bottle
@bottle.route('/arduino/')
def getArduino():
	ser = serial.Serial('/dev/ttyACM0',9600)#Change this according to your device location
	a = ser.readline()
	d = {}
	d['val']=a
	return d

@bottle.route('/')
def index():
	return open('index.html','r')
bottle.run()
