import json
import os
import time

import eventlet
import serial
from flask import Flask, render_template, url_for
from flask_socketio import SocketIO, emit

from assembler import asm

#################################################################

app = Flask(__name__)
app.config['SECRET_KEY'] = os.urandom(24)
socketio = SocketIO(app)
ser = None
codeUploaded = False
A = asm()
exList = []
exfile = []

#################################################################


def tryToConnect():
    global ser
    try:
        ser = serial.Serial(port='com5', baudrate=115200)
        time.sleep(3)
        ser.read_all()
        ser.flush()
        print("Controller connected!")
    except:
        print("Controller connection failed.")


def createJSON(Rstr):
    Rstr = Rstr.split(' ')
    r = Rstr[1].split(':')
    m = Rstr[2].split(':')
    RxData = {'pc': 0, 'reg': {}, 'mem': {}}

    RxData['pc'] = int(Rstr[0])
    if len(r[0]) is not 0:
        RxData['reg'][r[0]] = int(r[1])
    if len(m[0]) is not 0:
        RxData['mem'][m[0]] = int(m[1])

    msg = json.dumps(RxData)
    return msg


def getExList():
    """Returns list of files in 'examples' directory
    """
    global exList, exfile
    # print(os.getcwd())
    os.chdir('examples')
    exfile = os.listdir(os.curdir)
    exList = [item[:-4] for item in exfile]  # removes '.txt' from file name
    return exList


def getData(index):
    global exfile
    with open(exfile[index], 'r') as exFile:
        return exFile.read()

#################################################################


# Connect to controller before serving webpage
@app.before_first_request
def conncetController():
    print("first connection")
    tryToConnect()
    getExList()
    global codeUploaded
    codeUploaded = False


@app.route('/')
def index():
    return render_template('index.html')


@socketio.on('connect_event')
def init_display(msg):
    exDict = {}
    exDict["list"] = exList
    print(exDict)
    exJSON = json.dumps(exDict)
    socketio.emit('listData', exJSON)


@socketio.on('getExData')
def getExData(index):
    print(index)
    data = getData(index)
    socketio.emit('exData', data)


@socketio.on('upload')
def codeUpload(data):
    d = {}
    global ser
    global codeUploaded
    # print("ser is none")
    if ser is not None:
        print("ser is not none")
        if ser.isOpen():
            print("ser is open")
            if codeUploaded:
                ser.write(b'u')
            print("Code is being uploaded")
            codeUploaded = True
            A.setInString(data["message"])
            codeList = A.assemble('hex')
            A.clear()

            for i, inst in enumerate(codeList):
                codeList[i] = inst.rstrip()
                text = codeList[i]+','
                print(text)
                ser.write(text.encode())
            ser.write(b'd')
            print("done upload")
            d["program"] = codeList
            msg = json.dumps(d)
            socketio.emit('uploadStat', msg)


@socketio.on('reset')
def reset(msg):
    global ser
    if ser is not None:
        if ser.isOpen():
            print('Resetting Board !')
            ser.write(b"r")


@socketio.on('eval')
def evaluate(msg):
    global ser
    if ser is not None:
        if ser.isOpen():
            print('Evaluate next')
            ser.write(b"e")

# Listen to serial event and emit on "update", if message available
@socketio.on('getUpdate')
def listen(msg):
    global ser
    global codeUploaded
    if ser is not None:
        if codeUploaded and ser.isOpen() and (ser.inWaiting() > 0):
            s = ser.readline().decode()
            # msg = json.dumps({"pc": 3, "reg": {"1": 234}, "mem": {}})
            msg = createJSON(s)
            socketio.emit('update', msg)


if __name__ == "__main__":
    # Start server
    socketio.run(app, debug=True)
    # socketio.run(app, debug=True, host='127.0.0.23', port=5000)
