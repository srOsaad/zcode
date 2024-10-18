#include <windows.h>
#include <iostream>

bool valid(int x){
    if (x>64 && x<91)return true;
    switch(x){
        case 187:case 189:case 219:case 221:case 186:case 222:case 191:case 19:case 188:
        return true;
        default:
        return false;
    }
};

bool run=0;
HHOOK g_hHook = nullptr;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            if(pKeyStruct->vkCode == 192) run = !run;
            else if(run && valid(pKeyStruct->vkCode)){
                std::cout << "Blocked key 'A'"<<pKeyStruct->vkCode << std::endl;
                return 1; // Returning 1 from the hook procedure blocks the key
            }
        }
    }

    return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}


int main() {
    std::cout<<"running";
    // Install the hook
    g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(nullptr), 0);

    if (g_hHook == nullptr) {
        std::cerr << "Failed to install hook." << std::endl;
        return 1;
    }

    // Message loop to keep the application running
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Uninstall the hook before exiting
    UnhookWindowsHookEx(g_hHook);

    return 0;
}
