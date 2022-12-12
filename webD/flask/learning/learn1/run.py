# app will be loaded from __init__ file
# flaskblog has now become a module as it has __init__ file
from flaskblog import app

if __name__ == "__main__":
    app.run(debug=True,port=8080) # we are using debug because all the changes get implemented when we do small changes in our code without closing the server 