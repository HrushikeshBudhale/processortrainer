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


# try:
ser = serial.Serial(port='com5', baudrate=115200)
print("Connected !!")
time.sleep(3)
ser.read_all()
ser.flush()
ser.write(b"77BF0002,77BF0001,77BF0000,C01F0001,C03F0001,88000800,C0210001,D8410005,7BA2FFFC,641F0004,77BFFFFF,d")
while True:
    time.sleep(0.1)
    if (ser.inWaiting() > 0):
        s = ser.readline().decode()
        createJSON(s)

# except:
#     ser.close()
#     print("Disconnected !!!")
#     print("Port closed")
