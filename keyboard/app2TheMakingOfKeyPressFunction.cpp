#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <codecvt>
#include <locale>
#include <typeinfo>
#include <fstream>

#define RIGHT 101
#define DOWN 110
#define ENTER 111



std::wstring StringToWString(const std::string& str) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(str);
}


INPUT input[2];
INPUT input1[2];

class MyClass {
    private:
    std::vector<char> aa;
    public:
    void nothing(){
    int x;
    for(int i=0;i<aa.size();i++) {
        x=aa[i];
        //std::cout<<x;
        if(x=='\n') {
            if(i<aa.size()-1 && aa[i+1]=='}') {
                pressKey(DOWN);
                //pressKey(RIGHT);
                i++;
            }
            else pressKey(ENTER);
        }

        else pressChar(aa[i]);
        Sleep(30);
    }
}

MyClass(std::string fileName) {
    std::ifstream read; read.open(fileName);
    aa.clear();
    char xx;
    bool foundStarting=false;
    while(read.get(xx)){
        if(!foundStarting && xx!=' ') foundStarting = true;
        if(foundStarting) aa.push_back(xx);
        if(xx=='\n') foundStarting = false;
    }
};


void pressKey(int key) {
    input1[0].type = INPUT_KEYBOARD;
    input1[0].ki.wVk = key==ENTER ? VK_RETURN : key==RIGHT ? VK_RIGHT : key==DOWN ? VK_DOWN : 0;
    input1[0].ki.dwFlags = 0;
    input1[1].type = INPUT_KEYBOARD;
    input1[1].ki.wVk = key==ENTER ? VK_RETURN : key==RIGHT ? VK_RIGHT : key==DOWN ? VK_DOWN : 0;
    input1[1].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(2, input1, sizeof(INPUT));
}
void pressChar(char ch){
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.dwFlags = KEYEVENTF_UNICODE;
    input[0].ki.wScan = ch;
    input[1].ki.dwFlags |= KEYEVENTF_KEYUP;
    SendInput(2, input, sizeof(INPUT));
}
};

int main() {
    std::string msg = "~!@#$%^&*()_+`1234567890-=qwertyuiop[]QWERTYUIOP{}|ASDFGHJKL:asdfghjkl;<>?,./";
    //    std::wstring msg = L"123";
    //or std::string msg = "ABCD - abcd - 1234";

    Sleep(2000);
    //Find a notepad window or another window for send
    //HWND hwnd = FindWindow("visual", 0)#include;
    //if (hwnd) SetForegroundWindow(hwnd);
    //else std::cout << "no window!\n";
std::cout<<"Started\n";
    MyClass myus("app2TheMakingOfKeyPressFunction.cpp");
    myus.nothing();
    std::cout<<"end";
    //SendRightArrowKey();
    //SendDownArrowKey();
   // while(true){ pressChar('a'); Sleep(700);}

    return 0;
}