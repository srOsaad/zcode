#ifndef MYKEY_H
#define MYKEY_H

#include <vector>
#include <Windows.h>
#include <iostream>
#include <fstream>
#define RIGHT 101
#define DOWN 110
#define UP 111
#define LEFT 1000
#define ENTER 1001

INPUT input[2];
INPUT input1[2];
class MyKey {
private:
    int i;
    int length;
    std::vector<char> array;
    bool nextAvailable;
    void pressChar(char c) {
    std::string h(1, c);
    std::wstring str=s2ws(h);
    
    int len = str.length();
    if (len == 0) return;

    std::vector<INPUT> in(len*2);
    ZeroMemory(&in[0], in.size()*sizeof(INPUT));

    int i = 0, idx = 0;
    while (i < len) {
        WORD ch = (WORD) str[i++];

        if ((ch < 0xD800) || (ch > 0xDFFF)) {
            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = ch;
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx] = in[idx-1];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
        else {
            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = ch;
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx].type = INPUT_KEYBOARD;
            in[idx].ki.wScan = (WORD) str[i++];
            in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
            ++idx;

            in[idx] = in[idx-2];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;

            in[idx] = in[idx-2];
            in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
            ++idx;
        }
    }

    SendInput(in.size(), &in[0], sizeof(INPUT));
}
    void pressKey(int key) {
        input1[0].type = INPUT_KEYBOARD;
        input1[0].ki.wVk = key==ENTER ? VK_RETURN : key==RIGHT ? VK_RIGHT : key==DOWN ? VK_DOWN : key==UP ? VK_UP : key==LEFT ? VK_LEFT : 0;
        input1[0].ki.dwFlags = 0;
        input1[1].type = INPUT_KEYBOARD;
        input1[1].ki.wVk = key==ENTER ? VK_RETURN : key==RIGHT ? VK_RIGHT : key==DOWN ? VK_DOWN : key==UP ? VK_UP : key==LEFT ? VK_LEFT : 0;
        input1[1].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(2, input1, sizeof(INPUT));
    }
    std::wstring s2ws(const std::string& str) {
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        std::wstring wstrTo( size_needed, 0 );
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
        return wstrTo;
    }

public:
    MyKey(){};
    MyKey(std::string fileName) {
        setFile(fileName);
    };
    void setFile(std::string fileName){
        i=0;
        std::ifstream read; read.open(fileName);
        char xx;
        bool foundStarting=false;
        while(read.get(xx)){
            if(!foundStarting && xx!=' ') foundStarting = true;
            if(foundStarting) array.push_back(xx);
            if(xx=='\n') foundStarting = false;
        }
        read.close();
        length=array.size();
        std::cout<<length<<"  len";
        nextAvailable=(i<length);
    }
    void pressNext() {
        if (i < length) {
            if(array[i]=='\n') {
                if(i<array.size()-1 && array[i+1]=='}') {
                    pressKey(DOWN);
                    i++;
                }
                else pressKey(ENTER);
            }
            else if(array[i]=='^') {std::cout<<"UP\n";}//pressKey(UP);
            //else if(array[i]='`') std::cout<<"enter\n";//pressKey(ENTER);
            else if(array[i]='$') {std::cout<<"Down\n";}//pressKey(DOWN);
            else pressChar(array[i]);
            std::cout<<array[i];
            //Sleep(10);
            i++;
            } 
        else {
            nextAvailable = false;
        }
    };
    
    bool isNextAvailable() {
        return nextAvailable;
    };
    void show() {
        for (char x : array) {
            std::cout << x;
        }
    };
};

#endif