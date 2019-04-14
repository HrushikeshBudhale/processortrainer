import json
import serial
import time


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
    print(msg)


try:
    ser = serial.Serial(port='com5', baudrate=115200)
    time.sleep(1)
    ser.read_all()
    ser.flush()

    while True:
        time.sleep(0.1)
        if (ser.inWaiting() > 0):
            s = ser.readline().decode()
            createJSON(s)

except:
    ser.close()
    print("Disconnected !!!")
    print("Port closed")
