import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

cred = credentials.Certificate('day-planner-5165f-firebase-adminsdk-rincw-fa76672773.json')
firebase_admin.initialize_app(cred)

db = firestore.client()

db.collection('person').add({'name':'john','age': 34})