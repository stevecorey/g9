import threading
import serial
import time


class serialComm:

    def __init__(self):
        self.serIn = serial.Serial(
            port='/dev/ttyUSB0',
            baudrate=9600,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS,
            timeout=0
        )
        self.serOut = serial.Serial(
            port='/dev/ttyUSB0',
            baudrate=9600,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS,
            timeout=1
        )
        self.incount = 0
        self.outcount = 0
        self.lock = threading.Lock()


def startThread(ser: serialComm):
    t = threading.Thread(target= waitForData,
                         args=(ser,))

def waitForData(ser: serialComm):
    while 1:
        x = ser.serIn.read()
        if(len(x) != 0):
            if (x & 0xc0) == 0x00:
                ser.lock.acquire()
                ser.incount += 1
                ser.lock.release()
            else:
                ser.lock.acquire()
                ser.outcount += 1
                ser.lock.release()


# and needs a sort of lock
def getData(ser: serialComm):
    # called if data available
    ser.lock.aquire()
    x = ser.incount
    ser.incount = 0
    y = ser.outcount
    ser.outcount = 0
    ser.lock.release()
    return x, y

# target is which encoder we are trying to communicate with
# and so should be 0 or 1
# data is the value we have changed that pot to
def writeData(ser: serialComm, target: int, data: int):
    s = byte((target & 1 << 6) + (data & 0xf))
    ser.serOut.write(s)
