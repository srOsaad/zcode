#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>  // For Sleep function
#include "MyKey.h"

int main() {
    std::cout<<"F4 manual + F7 auto\n"
    <<"Files: \n";
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
