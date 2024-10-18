import pyautogui
import time

def Sleep(x):
    time.sleep(x/1000)
def Press(x):
    pyautogui.write(x)

f = open("P:\\code\\keyboard\\hello.cpp" , "r")
Sleep(2000)
for line in f:
    firstWordFound=False
    for word in line:
        if(firstWordFound==False and word!=' '): 
            firstWordFound=True
        if(firstWordFound):
            Press(word)
            Sleep(10)

