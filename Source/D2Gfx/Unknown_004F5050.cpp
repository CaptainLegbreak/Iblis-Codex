#include "D2Gfx.h"

struct D2GfxSettingsStrc;

extern "C" __declspec(dllimport) int __stdcall UnregisterClassA(const char* lpClassName, void* hInstance);   // 0x006CC4C8
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType); // 0x006CC464
void* ghInstance_007C8CA8;                                                                                  // 0x007C8CA8
const char* gszWindowClassName_007C9158;                                                                    // 0x007C9158
int gbNoWindowCreated_007C9338;                                                                             // 0x007C9338
extern int gnDisplayType;                                                                                   // 0x007C8CB0

// 0x004F5050
int __stdcall D2GFX_Release()
{
    gpGraphicsInterface->pfClose();
    UnregisterClassA(gszWindowClassName_007C9158, ghInstance_007C8CA8);

    if (gbNoWindowCreated_007C9338 != 0)
    {
        char szCaption[256];
        char szText[256];
        sprintf(szCaption, "Diablo II Critical Error");
        switch (gnDisplayType)
        {
        case 1:
            sprintf(szText, "Error 21: A critical error has occurred while initializing windowed mode.");
            break;
        case 3:
            sprintf(szText, "Error 22: A critical error has occurred while initializing DirectDraw.");
            break;
        case 4:
            sprintf(szText, "Error 23: A critical error has occurred while initializing Glide.");
            break;
        case 5:
            sprintf(szText, "Error 24: A critical error has occurred while initializing OpenGL.");
            break;
        case 6:
            sprintf(szText, "Error 25: A critical error has occurred while initializing Direct3D.");
            break;
        }
        MessageBoxA(0, szText, szCaption, 0x30);
    }

    gpGraphicsInterface = 0;
    return 1;
}
