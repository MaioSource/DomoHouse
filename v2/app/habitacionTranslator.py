habitacion = {'Habitacion1': 'HABI1', 'Habitacion2': 'HABI2', 'Habitacion3': 'HABI3',
		'Cocina': 'COCIN', 'Comedor': 'COMED', 'Living': 'LIVI1', 'Living': 'LIVI2',
		'Patio': 'PATIO', 'Jardin': 'JARDI', 'Quincho1': 'QUIN1', 'Quincho2': 'QUIN2',
		'Pileta': 'PILET'}


def translate(n):
	for nLargo, nCorto in habitacion.items():
		if nLargo == n:
        		return str(nCorto)
