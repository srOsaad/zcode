import keyboard
import time

while True:
    if keyboard.read_key() == "f2":
        print("F2 pressed")
    elif keyboard.read_key() == "esc":
        break
    else:
        print(keyboard.read_key())