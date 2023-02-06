from flask_wtf import FlaskForm
from flask_wtf.file import FileField, FileAllowed
from wtforms import StringField, PasswordField, SubmitField, BooleanField, TextAreaField
from wtforms.validators import DataRequired, Length, Email, EqualTo, ValidationError
from flaskblog.model import User
from flask_login import current_user

class RegistrationForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired(), 
        Length(min=2,max=20,message='Hello Length')])
    email = StringField('Email', validators=[DataRequired(), 
        Email()])
    password = PasswordField('Password',validators=[DataRequired(),
        ])
    confirm_password = PasswordField('Confirm Password',validators=[DataRequired(),
        EqualTo('password')])
    submit = SubmitField('Sign Up')

    def validate_username(self,username):
        user = User.query.filter_by(username=username.data).first()

        if user:
            raise ValidationError('That Username is taken.')

    def validate_email(self,email):
        user = User.query.filter_by(email=email.data).first()

        if user:
            raise ValidationError('That Email is taken.')

class LoginForm(FlaskForm):
    email = StringField('Email', validators=[DataRequired(), 
        Email()])
    password = PasswordField('Password',validators=[DataRequired(),
        ])
    remember = BooleanField('Remeber Me')
    submit = SubmitField('Sign In')

class UpdateAccountForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired(), 
        Length(min=2,max=20,message='Hello Length')])
    email = StringField('Email', validators=[DataRequired(), 
        Email()])
    picture = FileField('Update Profile Picture', validators=[FileAllowed(['jpg','png'])])
    submit = SubmitField('Update')

    def validate_username(self,username):
        if current_user.username != username.data:
            user = User.query.filter_by(username=username.data).first()
            if user:
                raise ValidationError('That Username is taken.')

    def validate_email(self,email):
        if current_user.email != email.data:
            user = User.query.filter_by(email=email.data).first()

            if user:
                raise ValidationError('That Email is taken.')

class PostForm(FlaskForm):
    title = StringField('Title', validators=[DataRequired()])
    content = TextAreaField('Content', validators=[DataRequired()])
    submit = SubmitField('Post')