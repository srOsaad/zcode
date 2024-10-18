#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>  // For Sleep function
#include "MyKey.h"

std::wstring StringToWideString(const std::string& narrowString) {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.from_bytes(narrowString);
    }

std::vector<char> getFormattedChar(const std::string& fileName) {
    std::ifstream read; read.open(fileName);
    std::vector<char> chara;
    char xx;
    bool foundStarting=false;
    while(read.get(xx)){
        if(!foundStarting && xx!=' ') foundStarting = true;
        if(foundStarting) chara.push_back(xx);
        if(xx=='\n') foundStarting = false;
    }
    read.close();
    return chara;
}

int main() {
    std::cout<<"Files: \n";
    Sleep(400);
    system("Files.txt");
    int speed;
    std::cout<<"Break per word (msc): ";std::cin>>speed;
    std::ifstream filelist("Files.txt");
    if (filelist.is_open()) {
        std::string fileName;
        while (std::getline(filelist, fileName)) {
            if (!fileName.empty() && fileName.back() == '\n') {
                fileName.pop_back();
            }
           
            MyKey performon(fileName);
            std::cout<<"Started\n";
            std::cout<<"Has data: "<<std::boolalpha<<performon.isNextAvailable()<<'\n';
            bool wantToRunAuto=false;
            while (performon.isNextAvailable()) {
                if(wantToRunAuto) performon.pressNext();
                if(GetAsyncKeyState(VK_F7) & 0x8000){
                    wantToRunAuto=true;
                }
                else if (GetAsyncKeyState(VK_F4) & 0x8000) {
                    if(wantToRunAuto){
                        wantToRunAuto=0;
                        continue;
                    }
                    performon.pressNext();
                }
                Sleep(speed);
            }
            std::cout<<"Completed";
        }
    }
    return 0;
}
