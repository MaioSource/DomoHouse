import serial
import habitacionTranslator

arduinoEn = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

def send(dispositivo, estado, habitacion):
	if (dispositivo=="luz"):
		if estado:
			arduinoEn.write("LuzOnn-" + str(habitacionTranslator.translate(habitacion)) + "/")
		elif ~estado:
			arduinoEn.write("LuzOff-" + str(habitacionTranslator.translate(habitacion)) + "/")
	elif(dispositivo=="cortina"):
		if estado:
			arduinoEn.write("CortinaUp-" + str(habitacionTranslator.translate(habitacion)) + "/")
		elif ~estado:
			arduinoEn.write("CortinaDown-" + str(habitacionTranslator.translate(habitacion)) + "/")
'''
def send(dispositivo, estado, habitacion):
	if (dispositivo=="luz"):
		if estado:
			print("LuzOn - " + str(habitacionTranslator.translate(habitacion)))
		elif ~estado:
			print("LuzOff - " + str(habitacionTranslator.translate(habitacion)))
	elif(dispositivo=="cortina"):
		if estado:
			print("CortinaUp - " + str(habitacionTranslator.translate(habitacion)))
		elif ~estado:
			print("CortinaDown - " + str(habitacionTranslator.translate(habitacion)))
		'''