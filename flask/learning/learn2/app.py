import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# fetch the service account key JSON file contents
cred = credentials.Certificate('day-planner-5165f-firebase-adminsdk-rincw-fa76672773.json')

# initialize the app with a service account, granting admin privilages
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://day-planner-5165f-default-rtdb.firebaseio.com/'
})

# save data
ref = db.reference('/')
user_ref = ref.child('users')
user_ref.set({
    'Sahil' :{
        'data_of_birth' : '3 Jun 1920',
        'full_name' : 'Sahil Kamate'
    },
    'Sahil':{
        'data_of_birth' : '3 Jun 2009',
        'full_name' : 'Kamate'
    }
})

# update data
sahil_ref = user_ref.child('Sahil')
sahil_ref.update({
    'nickname' : 'cool_boy'
})

# read data
handle = db.reference('/users/Sahil')
print(handle.get())

handle.delete()