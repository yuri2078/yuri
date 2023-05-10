import sys
import importlib
import time
reload(sys)
sys.setdefaultencoding('utf8')
from pyzbar.pyzbar import decode
from PIL import Image
while True :
    decocdeQR = decode(Image.open("./image.jpg"))
    if decocdeQR :
        print(decocdeQR[0].data)
    else :
        time.sleep(0.5)


