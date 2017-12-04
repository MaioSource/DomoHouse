# -*- coding: utf-8 -*-
from flask import request, redirect, render_template, url_for, json, flash, Flask
from app import app #Comentar para srv. prod.
import datetime
import forms
import arduino

###VARIABLES
###LUCES
estadoLuzHabitacion1=False
estadoLuzHabitacion2=False
estadoLuzHabitacion3=False
estadoLuzCocina=False
estadoLuzComedor=False
estadoLuzLiving=False
estadoLuzLiving2=False
estadoLuzQuincho=False
estadoLuzQuincho2=False
estadoLuzPileta=False
estadoLuzJardin=False
estadoLuzPatio=False
estadoLuzGeneral=False
###OTROS
estadoTelevisionGeneral=False
###CORTINAS
estadoCortinaHabitacion1=False
estadoCortinaHabitacion2=False
estadoCortinaHabitacion3=False

@app.route('/', methods=['GET' , 'POST'])
@app.route('/Inicio', methods=['GET' , 'POST'])
def Inicio():
	electroForm=forms.electro(request.form)
	luz=electroForm.luz.data
	luzPileta=electroForm.luzPileta.data
	luzPatio=electroForm.luzPatio.data
	luzJardin=electroForm.luzJardin.data
	luzCocina=electroForm.luzCocina.data
	luzComedor=electroForm.luzComedor.data
	luzLiving=electroForm.luzLiving.data
	luzLiving2=electroForm.luzLiving2.data
	luzQuincho=electroForm.luzQuincho.data
	luzQuincho2=electroForm.luzQuincho2.data
	global estadoLuzGeneral
	if (luz=="on"):
		estadoLuzGeneral=True
		arduino.send("luz", True, "General")
	elif(luz=="off"):
		estadoLuzGeneral=False
		arduino.send("luz", False, "General")

	global estadoLuzPileta
	if (luzPileta=="on"):
		estadoLuzPileta=True
		arduino.send("luz", True, "Pileta")
	elif(luzPileta=="off"):
		estadoLuzPileta=False
		arduino.send("luz", False, "Pileta")

	global estadoLuzPatio
	if (luzPatio=="on"):
		estadoLuzPatio=True
		arduino.send("luz", True, "Patio")
	elif(luzPatio=="off"):
		estadoLuzPatio=False
		arduino.send("luz", False, "Patio")

	global estadoLuzJardin
	if (luzJardin=="on"):
		estadoLuzJardin=True
		arduino.send("luz", True, "Jardin")
	elif(luzJardin=="off"):
		estadoLuzJardin=False
		arduino.send("luz", False, "Jardin")

	global estadoLuzCocina
	if (luzCocina=="on"):
		estadoLuzCocina=True
		arduino.send("luz", True, "Cocina")
	elif(luzCocina=="off"):
		estadoLuzCocina=False
		arduino.send("luz", False, "Cocina")

	global estadoLuzComedor
	if (luzComedor=="on"):
		estadoLuzComedor=True
		arduino.send("luz", True, "Comedor")
	elif(luzComedor=="off"):
		estadoLuzComedor=False
		arduino.send("luz", False, "Comedor")

	global estadoLuzLiving
	if (luzLiving=="on"):
		estadoLuzLiving=True
		arduino.send("luz", True, "Living")
	elif(luzLiving=="off"):
		estadoLuzLiving=False
		arduino.send("luz", False, "Living")

	global estadoLuzLiving2
	if (luzLiving2=="on"):
		estadoLuzLiving2=True
		arduino.send("luz", True, "Living2")
	elif(luzLiving2=="off"):
		estadoLuzLiving2=False
		arduino.send("luz", False, "Living2")

	global estadoLuzQuincho
	if (luzQuincho=="on"):
		estadoLuzQuincho=True
		arduino.send("luz", True, "Quincho")
	elif(luzQuincho=="off"):
		estadoLuzQuincho=False
		arduino.send("luz", False, "Quincho")

	global estadoLuzQuincho2
	if (luzQuincho2=="on"):
		estadoLuzQuincho2=True
		arduino.send("luz", True, "Quincho2")
	elif(luzQuincho2=="off"):
		estadoLuzQuincho2=False
		arduino.send("luz", False, "Quincho2")

	return render_template('index.html', estadoLuz=estadoLuzGeneral, estadoLuzPatio=estadoLuzPatio, estadoLuzJardin=estadoLuzJardin, 
				estadoLuzPileta=estadoLuzPileta, estadoLuzCocina=estadoLuzCocina, estadoLuzComedor=estadoLuzComedor,
				estadoLuzLiving=estadoLuzLiving, estadoLuzLiving2=estadoLuzLiving2, estadoLuzQuincho=estadoLuzQuincho,
				estadoLuzQuincho2=estadoLuzQuincho2)
	#return render_template('index.html')

@app.route('/Habitacion1', methods=['GET' , 'POST'])
def Habitacion1():
	electroForm=forms.electro(request.form)
	luz=electroForm.luz.data
	cortina=electroForm.cortina.data

	global estadoLuzHabitacion1
	if (luz=="on"):
		estadoLuzHabitacion1=True
		arduino.send("luz", True, "Habitacion1")
	elif(luz=="off"):
		estadoLuzHabitacion1=False
		arduino.send("luz", False, "Habitacion1")

	global estadoCortinaHabitacion1
	if (cortina=="up"):
		estadoCortinaHabitacion1=True
		arduino.send("cortina", True, "Habitacion1")
	elif (cortina=="down"):
		estadoCortinaHabitacion1=False
		arduino.send("cortina", False, "Habitacion1")

	return render_template('habitacion1.html', estadoLuz=estadoLuzHabitacion1, estadoCortina=estadoCortinaHabitacion1)

@app.route('/Habitacion2', methods=['GET' , 'POST'])
def Habitacion2():
	electroForm=forms.electro(request.form)
	luz=electroForm.luz.data
	cortina=electroForm.cortina.data

	global estadoLuzHabitacion2
	if (luz=="on"):
		estadoLuzHabitacion2=True
		arduino.send("luz", True, "Habitacion2")
	elif(luz=="off"):
		estadoLuzHabitacion2=False
		arduino.send("luz", False, "Habitacion2")

	global estadoCortinaHabitacion2
	if (cortina=="up"):
		estadoCortinaHabitacion2=True
		arduino.send("cortina", True, "Habitacion2")
	elif (cortina=="down"):
		estadoCortinaHabitacion2=False
		arduino.send("cortina", False, "Habitacion2")

	return render_template('habitacion2.html', estadoLuz=estadoLuzHabitacion2, estadoCortina=estadoCortinaHabitacion2)

@app.route('/Habitacion3', methods=['GET' , 'POST'])
def Habitacion3():
	electroForm=forms.electro(request.form)
	luz=electroForm.luz.data
	cortina=electroForm.cortina.data

	global estadoLuzHabitacion3
	if (luz=="on"):
		estadoLuzHabitacion3=True
		arduino.send("luz", True, "Habitacion3")
	elif(luz=="off"):
		estadoLuzHabitacion3=False
		arduino.send("luz", False, "Habitacion3")

	global estadoCortinaHabitacion3
	if (cortina=="up"):
		estadoCortinaHabitacion3=True
		arduino.send("cortina", True, "Habitacion3")
	elif (cortina=="down"):
		estadoCortinaHabitacion3=False
		arduino.send("cortina", False, "Habitacion3")

	return render_template('habitacion3.html', estadoLuz=estadoLuzHabitacion3, estadoCortina=estadoCortinaHabitacion3)

@app.route('/Manager', methods=['GET' , 'POST'])
def Manager():
	return render_template('manager.html')



