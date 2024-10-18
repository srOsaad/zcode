#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>  // For Sleep function
#include "MyKey.h"

bool valid(int x){
    if (x>64 && x<91)return true;
    switch(x){
        case 187:case 189:case 219:case 221:case 186:case 222:case 191:case 19:case 188:
        return true;
        default:
        return false;
    }
};

MyKey performon;

bool run=0;
HHOOK g_hHook = nullptr;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            if(pKeyStruct->vkCode == 192) { run = !run; std::cout<<(run ? "\nstarted\n" : "\npaused\n"); return 1;}
            else if(run && valid(pKeyStruct->vkCode)){
                performon.pressNext();
                if(!performon.isNextAvailable()) PostQuitMessage(0);
                return 1;
            }
        }
    }
    return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

int main() {

    g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(nullptr), 0);

    if (g_hHook == nullptr) {
        std::cerr << "Failed to install hook." << std::endl;
        return 1;
    }

    std::cout<<"\nToggle start and pause = '`'. (Only 1 file)\n\n"
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
            
            performon.setFile(fileName);
            std::cout<<"Started\n";
            std::cout<<"Has data: "<<std::boolalpha<<performon.isNextAvailable()<<'\n';

            MSG msg;
            while (GetMessage(&msg, nullptr, 0, 0) != 0) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            UnhookWindowsHookEx(g_hHook);
        }
    }
    return 0;
}
