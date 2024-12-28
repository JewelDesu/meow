#include <windows.h>

LRESULT hook_proc(int code, WPARAM wParam, LPARAM lParam)
{
    KBDLLHOOKSTRUCT *vkey = (KBDLLHOOKSTRUCT *) lParam;
    if(wParam == WM_KEYDOWN)
    {
        switch (vkey -> vkCode)
        {
        case VK_RETURN:
            {
                PlaySound("./meow.wav", NULL, SND_SYNC);
            }
            break;
        default:
            {
            }
            break;
        }
    }
    return CallNextHookEx(NULL, code, wParam, lParam);
}

int main ()
{   
    HHOOK hhook = SetWindowsHookExA(
        WH_KEYBOARD_LL,
        hook_proc,
        NULL,
        0
    );

    //loop
    MSG msg;
    while((GetMessage(&msg ,NULL ,0 ,0 )) != 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
