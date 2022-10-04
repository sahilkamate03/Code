import firebase_admin
from firebase_admin import credentials
# from firebase_admin import auth
from firebase_admin import firestore
# import pyrebase

# import json
hell = {
  "type": "service_account",
  "project_id": "day-planner-5165f",
  "private_key_id": "83e4ce0e84a5ea2c2a40f9101a00edd16a4edcaa",
  "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDBYrwzBdpoTR4k\nkQ63nojx31S9mGTywbsZip2x2BeBjM2Bb/HL/UdYkW2ZDkefuo9gNLbNUQi2holB\nwkTWwMKXUty7Oq1lIhpl7kghIS87Q9by2txQAbuMDKS4+hXLG+36gJ0vbRJkyeX0\nPSQxrRuyrbo/IcG3jbDEsdpNOYa7UJ3nQFqSjiuuWlvRNfFADQa40AcxJrKNybo8\ndVjEhlFJuuqbfFaXTYGJaUIHvbKuc9Ro0s/WyIoGydcGcjItPCOkBRPuVnnb0JTJ\nSBFs2oDv4e4EE1jYHk3/X0heQpwTn/pCl7u4Zn6VY+YcZsRi8syBFS3pX045+DLi\nqoe6y4sdAgMBAAECggEAIP7luZbwEwfFctvFNRM5rns6jDbqUnk3oT4Ddgq2yAXs\nMn+VNAb9G2GE366ODfTY7cNQxWtkHzCJTs0EzdeJ3CPpQZDbcPwGoQmtCOoOkwAa\nNsmc+ZGyHE0z9dPF0CftzOYQ67yifMvuDmQ4PrmYlj4KHyd1VAo69PSbmL2N/XuR\nkofmdhUliFH4ER07L9BIQv8bW70+/iwJfwkLLcOXqeGzZTX+DA9tADFisVW2V9OE\na5YsWLCBYRVNy6+fS2CAaykF9y0Iqrw+snxshbxWoJxcM5LI5YqMNcClWF8AEu0P\naTXFoChfht0iEox+FZ/LrSf9m+Oo2E338CbhqppkiQKBgQD0X65KD/Ju8PCADTN/\n0cLhsD5yS2loxKth+vFL33ZIwZ8ypZEL8O1vQhk2f8L3oHCSGy75LuAVSxe2czIU\nco7GC3ovVtKR6owFXXF5NOFyRZkTkxPeKMZZYMClKiztNC81QPwMclNrNlnCfjwy\nZQgoSa6QEX6QXdN+7s0EKe1MewKBgQDKlg02Dn/QwutiLI8wKMAAPI1oJK8TxO2i\nUO8Y9ttAxW7LWpMqvAuFz2KpEhy2cNN/IU3CQrKELFF+pYh7+8rP2CeZW5oSKgYe\nWrAcFYVMFzyzboC6Rt5NiGSZYa53kBBslW4bSfdtUOv9QT/wT+zmrblt5/dYEwY/\nmlTLpdZvRwKBgENrlmlGhwtGnAOoILo2A/9CIahk19sYz3PDyQi2ySp/iM1vUloq\nCUe1w8D+dKre78/PgiErZpVZV1x14a40gOFwzy/6UzQAssrUIfdfuIdPXlFBNa0I\nMNj90Yh/308+I3wcxq0kaZFduFvpefApYZvD4E5NFU79I9mURqnMa3S7AoGBALPZ\nvuTMvoBRa7L+qCgzJTGQkGFyn9PHMsi1XW8mSMQaAyCZyqlXxEsJMCe1IrR9OeZV\nZLkfiWh6B+eNgbvAb+9RkOY/Qmr5z/DGxi5IlMxWnNcXNUUqgVUHz3e0FrWiulIL\n33JumjD8dGWjteXcrw6kEEkYdKhGS3fPxZP+KH8lAoGALCVvlpS7rfrOZPz5Bzrv\n1ou38dBHSH+bNxz3bqNNAf7PB1mjt9zxbisqPyZgyX+GYsb4WUy6/yU0C9qpDkE1\noRtgW65cayqPWQVx6BZ6OyEFCjDu6zDoRA/EZkAbk1zszbftpUBndpsUFavxM+AN\nzV0h8JpI75uo+Y6muyThqq8=\n-----END PRIVATE KEY-----\n",
  "client_email": "firebase-adminsdk-rincw@day-planner-5165f.iam.gserviceaccount.com",
  "client_id": "101312543958252486473",
  "auth_uri": "https://accounts.google.com/o/oauth2/auth",
  "token_uri": "https://oauth2.googleapis.com/token",
  "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs",
  "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/firebase-adminsdk-rincw%40day-planner-5165f.iam.gserviceaccount.com"
}

cred = credentials.Certificate(hell)
firebase_admin.initialize_app(cred)

# config
# firebaseConfig = {
#     "apiKey": "AIzaSyAUBaH94HsV0b0BgKprPZ6uwcr4IT2De78",
#     "authDomain": "day-planner-5165f.firebaseapp.com",
#     "databaseURL": "https://day-planner-5165f-default-rtdb.firebaseio.com",
#     "projectId": "day-planner-5165f",
#     "storageBucket": "day-planner-5165f.appspot.com",
#     "messagingSenderId": "957874282773",
#     "appId": "1:957874282773:web:93bbb3ac3802131130091c",
#     "measurementId": "G-BZHRXN4120"
# }

# with open('../config/firebase_config.json', 'r') as f:
#     firebaseConfig = json.load(f)

# print(firebaseConfig)
# firebase = pyrebase.initialize_app(firebaseConfig)
# auth = firebase.auth()
# email= 'sahilkamate03@aitpune.edu.in'
# login = auth.sign_in_with_email_and_password(email,12343356 )
# print(login)
# # -------------------------------------Authentication Starts--------------------------------------

# # create user
# email = input('Enter Email: ')
# pwd = input('Enter Pwd: ')
# user = auth.create_user(email = email , password = pwd)
# print(user.uid)

# # getUser
# email= 'sahilkamate03@gmail.com'
# user = 'sfs'
# try:
#     user = auth.get_user_by_email(email)
# except:
#     print('error email not found')
# else:
#     user = auth.get_user_by_email(email)
# print(user)
# print(user.uid)
# print(auth.generate_sign_in_with_email_link(email, ))

# # -------------------------------------Authentication Ends--------------------------------------

# # -------------------------------------Firestore  Add Data Starts-----------------------------------------

db = firestore.client()
doc_ref = db.collection('connection').document('harshalmukundapatil')
doc = doc_ref.get()
print(doc.to_dict())
# data = {'name':'sahil','age':19, 'in_clg': True}

# # add document with auto ids
# db.collection('people').add(data)

# # set document with known ids
# db.collection('people').document('SahilKamate').set(data)

# # set document with auto ids
# db.collection('people').document().set(data)

# # append data / merging
# db.collection('Alumini').document('surajchavan').set({'add':'Kolkata'}, merge = True)

# # add subcollection with auto ids
# db.collection('people').document('SahilKamate').collection('book').add({'b1':'Rich Dad Poor Dad'})

# # add subcollection with know ids
# db.collection('people').document('SahilKamate').collection('book').document('help_book').set({'b1':'Rich Dad Poor Dad'})

# # -------------------------------------Firestore Add Data Ends-----------------------------------------

# # ------------------------------------Firestor Read Data Starts----------------------------------------

# # read document with known id
# user = 'sahilannasokamate_21185'
# result = db.collection('post').document('sahilannasokamate_2118520220928121435').get().to_dict()
# if user in result['likes']:
#     temp = db.collection('post').document('sahilannasokamate_2118520220928121435').get().to_dict()['likes']
#     print(temp)
#     temp.remove(user)
#     print(temp)
#     db.collection('post').document('sahilannasokamate_2118520220928121435').set({'likes': temp}, merge =True)

# else:
#     print(db.collection('post').document('sahilannasokamate_2118520220928121435').get().to_dict()['likes'])
#     db.collection('post').document('sahilannasokamate_2118520220928121435').set({'likes': ['sahilannasokamate_21185']}, merge = True)

# print(result.to_dict())
# for r in result:
#     print(r.to_dict())
# # get all document in a collection
# docs = db.collection('post').get()
# for doc in docs:
#     # print(doc.to_dict()['username']+str(doc.to_dict()['date_created']).replace(" ", ""))
#     print(bool(doc.to_dict()['comments']))
    


# # quering
# docs = db.collection('post').where('username','==','sahilannasokamate_21185').get()
# for doc in docs:
#     print(doc.to_dict())

# # quering in arrays
# docs = db.collection('people').where('age','array_contains',19).get()
# for doc in docs:
#     print(doc.to_dict())

# # quering in arrays2
# docs = db.collection('people').where('age','in',['18,19,20']).get()
# for doc in docs:
#     print(doc.to_dict())

# # ------------------------------------Firestor Read Data Ends----------------------------------------

# #-------------------------------------Firebase Storage Starts ---------------------------------------



# #-------------------------------------Firebase Storage Ends ---------------------------------------
# firebase = pyrebase.initialize_app(firebaseConfig)
# storage = firebase.storage()

# filename = input('Enter FileName: ')
# cloudFileName = input('Enter Filename for cloud stroage: ')

# storage.child(cloudFileName).put(filename)
# url = storage.child(cloudFileName).get_url(None)
# print(url)

# database listener
# Create an Event for notifying main thread.
# callback_done = threading.Event()

# Create a callback on_snapshot function to capture changes
# def on_snapshot(doc_snapshot, changes, read_time):
#     for doc in doc_snapshot:
#         print(f'Received document snapshot: {doc.id}')
#         for change in changes:
#             if change.type.name == 'ADDED':
#                 print(f'New city: {change.document.id}')
#             elif change.type.name == 'MODIFIED':
#                 print(f'Modified city: {change.document.id}')
#             elif change.type.name == 'REMOVED':
#                 print(f'Removed city: {change.document.id}')
#                 # delete_done.set()
#     # callback_done.set()

# doc_ref = db.collection(u'test').document(u'VnsP3DMDbmp8kXcLYT0u')

# # Watch the document
# while (True):
#     doc_watch = doc_ref.on_snapshot(on_snapshot)
