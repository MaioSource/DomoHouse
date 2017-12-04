import commands

def verActivos():
	hostONoOFF={}

	host=open("/home/agus/Escritorio/DomoHouse/Web/app/host.dat","r")
	for i in host:
		if (i=="ON"):
			hostONoOFF["Agus"]= 'ON'
		else:
			hostONoOFF["Agus"]= 'OFF'
		if (i=="ON"):
			hostONoOFF["Caro"]= 'ON'
		else:
			hostONoOFF["Caro"]= 'OFF'
		if (i=="ON"):
			hostONoOFF["Vero"]= 'ON'
		else:
			hostONoOFF["Vero"]= 'OFF'
		if (i=="ON"):
			hostONoOFF["Paco"]= 'ON'
		else:
			hostONoOFF["Paco"]= 'OFF'

	return hostONoOFF
