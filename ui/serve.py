import json
import os
import eventlet
import serial

from flask import Flask, render_template, url_for
from flask_socketio import SocketIO, emit

app = Flask(__name__)
# app.secret_key = os.urandom(24)
app.config['SECRET_KEY'] = os.urandom(24)
socketio = SocketIO(app)

codeUploaded = False


def uploadCode(data):
    pass


def resetBoard():
    pass

# Connect to controller before serving webpage
# @app.before_first_request
# def conncetController():
#     global ser
#     try:
#         ser = serial.Serial(port='com4', baudrate= 115200)
#         print("Controller connected!")
#     except:
#         print("Controller connection failed.")


@app.route('/')
def index():
    return render_template('index.html')


@socketio.on('connect_event')
def init_display(msg):
    global codeUploaded
    codeUploaded = False
    print(msg['data'])


@socketio.on('upload')
def codeUpload(data):
    global codeUploaded
    try:
        uploadCode(data)
        codeUploaded = True
        print('received something:', str(data))
        msg = json.dumps({"program": [123, 234, 345, 456, 567, 678, 789]})
        socketio.emit('uploadStat', msg)
    except:
        socketio.emit('uploadStat', "error")


@socketio.on('reset')
def reset(msg):
    print('Resetting Board !')
    resetBoard()


# Listen to serial event and emit on update if message available
@socketio.on('getUpdate')
def listen(msg):
    global codeUploaded
    if codeUploaded:
        msg = json.dumps(
            {"pc": 3, "reg": {"1": 234, "3": 555}, "mem": {"5": 111}})
        socketio.emit('update', msg)

if __name__ == "__main__":

    # Start server
    socketio.run(app, debug=True)
    # socketio.run(app, debug=True, host='192.168.0.39',port=5000)
