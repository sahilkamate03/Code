import firebase_admin
from firebase_admin import credentials
from firebase_admin import auth
from firebase_admin import firestore

cred = credentials.Certificate('admin_config.json')
firebase_admin.initialize_app(cred)

