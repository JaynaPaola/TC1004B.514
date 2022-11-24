import firebase_admin
from firebase_admin import firestore
from firebase_admin import credentials
import time
from datetime import datetime
import random
#Application Default credentials are automatically created.
cred = credentials.Certificate('credentials.json')
app = firebase_admin.initialize_app(cred)
db = firestore,client()

while True:
    print("Sending data")
    current_date = datetime.now()
    date = current_date.strftime('%Y-%m-%d')
    hour = current_date.strftime('%H')
    collectionName = u'sensor_Paola_${0}'.format(date)
    encendido = bool(random.getrandbits(1))
    totals_ref = db.collection().document('totals')
    totals_doc = totlas_ref.get()
    totals_data = totlas_doc.to_dict()
    if totals_data == None:
        totals_ref.set({
            u'total_minutos_encendido': 1 if encendido else 0,
        })
    else:
        if encendido:
            totals_ref.update({
                u'totals_minutos_encendido': 1 if encendido else 0,
            })
        else:
            if encendido:
                totals_ref.update({
                    u'total.minutos_encendido': totals_data[u'total_minutos_encendido'] + 1,
                })
    
    hour_ref = db.collection().document(hour)
    hour_doc = hour_ref.get()
    hour_data = hour_doc.to_dict()
    if hour_data == None:
        hour_ref.set({
            u'minutos_encendido': 1 if encendido else 0,
            u'minutos_apagado': if not encendido else 0
        })
    else:
        if encendido:
            hour_ref.update({
                u'minutos_encendido': hour_data[u'minutos_encendidos'] + 1
            })
        else:
            hour_ref.update({
                u'minutos_apagado': hour_data[u'minutos_apagado'] + 1
            })
    time.sleep(10)