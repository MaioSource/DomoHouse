from wtforms import Form
from wtforms import RadioField

class electro(Form):
	luz = RadioField('luz')
	luzPatio = RadioField('luzPatio')
	luzPileta = RadioField('luzPileta')
	luzJardin = RadioField('luzJardin')
	luzCocina = RadioField('luzCocina')
	luzComedor = RadioField('luzComedor')
	luzLiving = RadioField('luzLiving')
	luzLiving2 = RadioField('luzLiving2')
	luzQuincho = RadioField('luzQuincho')
	luzQuincho2 = RadioField('luzQuincho2')
	cortina = RadioField('cortina')
