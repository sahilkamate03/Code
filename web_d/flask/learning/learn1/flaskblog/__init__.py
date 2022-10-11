import bcrypt
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_bcrypt import Bcrypt
from flask_login import LoginManager

app = Flask(__name__)
app.config['SECRET_KEY']= '5f06016b9d07cdc3403f047ed3be1990ab87833e81fd0cc0994c2bd06fa67fe5'
app.config['SQLALCHEMY_DATABASE_URI']='postgres://ztbiaqsouyprfr:549df14281ef82e59ba295a430e0566038eda7bc4c5048303316af6e8976a06f@ec2-44-208-88-195.compute-1.amazonaws.com:5432/d4n21bnuetpv41'

db= SQLAlchemy(app)
bcrypt= Bcrypt(app)

login_manager= LoginManager(app)
login_manager.login_view = 'login' #login is the function name of the route
login_manager.login_message_category = 'info'

from flaskblog import routes