        doc_ref =   db_fire.collection('connection').document(username)
        doc = doc_ref.get()

        if doc.exists:
            data = db_fire.collection('connection').document(username).get().to_dict()['pending']
            data.append(username)
            db_fire.collection('connection').document(username).set({'pending': data},merge = True)

        else:
            db_fire.collection('connection').document(username).set({'pending': [current_user.username]})

        user = User.query.filter_by(username=username).first()
        role = user.role