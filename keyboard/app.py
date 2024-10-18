import os
import pyautogui
import keyboard
import time

class myKey:
    i=0
    length = 0
    array = []
    nextAvaiable = False
    def __init__(self,array):
        self.array = array
        self.length = len(self.array)
        self.nextAvaiable = self.i < self.length

    def pressNext(self):
        if self.i<self.length:
            pyautogui.write(self.array[self.i])
            self.i+=1
        else: self.nextAvaiable = False
    
    def show(self):
        for x in self.array:
            print(x,end='')

def Sleep(msec) :
    time.sleep(msec/1000)

def getFormatedChar(file) :
    file = open(file , "r")
    arr = []
    for line in file:
        wordFound = False
        newline=""
        for word in line:
            if(wordFound==False and word!=' ') :
                wordFound = True
            if wordFound==True :
                newline+=word
        size = len(newline)-1
        while newline[size] == ' ' or newline[size]=='\n' :
            size-=1
        newline = newline[0:size+1]+"\n"
        for word in newline:
            arr.append(word)
    if arr[len(arr)-1]=='\n' :
        arr.pop(len(arr)-1)
    return arr

def pressNext(arr,index,len) :
    if index<len:
        pyautogui.press(index)
        return True
    return False

def main() :
    filelist = open(os.getcwd()+"/"+"Files.txt" , "r")
    for fileName in filelist:
        if(fileName[len(fileName)-1]=='\n'):
            fileName=fileName[0:len(fileName)-1]
        performon = myKey(getFormatedChar(fileName))

        while(performon.nextAvaiable):
            if keyboard.read_key() == "f2":
                performon.pressNext()
         
main()