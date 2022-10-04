from flask import Flask, render_template
from flask_socketio import SocketIO, send

app = Flask(__name__)
socketio = SocketIO(app, cors_allowed_origins="*")


@socketio.on("message")
def sendMessage(message):
    message = 'sahil: ' + message
    print(message)
    send(message, broadcast=True)
    # send() function will emit a message vent by default


@app.route("/")
def message():
    return render_template("chat.html", username = 'sahil')


if __name__ == "__main__":
    app.run(debug=True)