#import serial

'''
arduinoEn = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

def send(dispositivo, estado, habitacion):
	if (dispositivo=="luz"):
		if estado:
			arduinoEn.write("LuzOn - " + habitacion)
		elif ~estado:
			arduinoEn.write("LuzOff - " + habitacion)
	elif(dispositivo=="cortina"):
		if estado:
			arduinoEn.write("CortinaUp - " + habitacion)
		elif ~estado:
			arduinoEn.write("CortinaDown - " + habitacion)
'''
def send(dispositivo, estado, habitacion):
	if (dispositivo=="luz"):
		if estado:
			print("LuzOn - " + habitacion)
		elif ~estado:
			print("LuzOff - " + habitacion)
	elif(dispositivo=="cortina"):
		if estado:
			print("CortinaUp - " + habitacion)
		elif ~estado:
			print("CortinaDown - " + habitacion)