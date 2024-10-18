#include <windows.h>
#include <iostream>

HHOOK g_hHook = nullptr;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            // Block the input of the letter 'A'
            if (pKeyStruct->vkCode == 'A') {
                std::cout << "Blocked key 'A'" << std::endl;
                return 1; // Returning 1 from the hook procedure blocks the key
            }
            else if(pKeyStruct->vkCode == 'B'){std::cout<<"works\n"; PostQuitMessage(0);}
        }
    }

    return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

int main() {
    std::cerr<<"Started!\n";
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
