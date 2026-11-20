#include "D2Win.h"

#define D2WIN_SCROLLBAR 5
#define D2WIN_BUTTON 6
struct D2WinControlStrc;
struct D2WinButtonStrc;
struct JPEG_CORE_PROPERTIES;

struct JPEG_CORE_PROPERTIES
{
    int UseJPEGPROPERTIES;
    unsigned char* DIBBytes;
    int DIBWidth;
    int DIBHeight;
    int DIBPadBytes;
    int DIBChannels;
    int DIBColor;
    int DIBSubsampling;
    const char* JPGFile;
    unsigned char* JPGBytes;
    int JPGSizeBytes;
    int JPGWidth;
    int JPGHeight;
    int JPGChannels;
    int JPGColor;
    int JPGSubsampling;
    int JPGThumbWidth;
    int JPGThumbHeight;
    int cconversion_reqd;
    int upsampling_reqd;
    int jquality;
    int unk0x54[0x137B];
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall ijlInit(JPEG_CORE_PROPERTIES* pProps); // 0x006CC5E0
extern "C" __declspec(dllimport) int __stdcall ijlWrite(JPEG_CORE_PROPERTIES* pProps, int nMode); // 0x006CC5E4
extern "C" __declspec(dllimport) int __stdcall ijlFree(JPEG_CORE_PROPERTIES* pProps); // 0x006CC5E8
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern int gnScreenshotIndex_0072DC40; // 0x0072DC40
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight); // 0x004F59B0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer); // 0x004F6250

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

struct D2WinControlStrc
{
    int eType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    D2WinControlFn pfDraw;
    D2WinControlFn pfInitialize;
    D2WinMsgHandler pfHandleMouseDown;
    D2WinMsgHandler pfHandleMouseUp;
    D2WinMsgHandler pfHandleCharInput;
    D2WinMsgHandler pfHandleVirtualKeyInput;
    D2WinMsgHandler field_34;
    D2WinControlFn pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2WinControlStrc* gpControlList_6F8FE24C; // 0x007D55BC
extern void* dword_6F8FE260; // 0x007D55D0
extern D2WinControlStrc* dword_6F8FE264; // 0x007D55D4
void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg); // 0x004F9BF0
int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* pButton, int nMouseWheelIncrement); // 0x00500B50
void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg); // 0x00500AB0
int __fastcall sub_6F8AF240(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3); // 0x00508030
int __stdcall POPUP_IsActive(); // 0x005085C0
extern int gnMouseX_007D55A4; // 0x007D55A4
extern int gnMouseY_007D55A8; // 0x007D55A8

unsigned long gdwLastScreenshotTick_007D5600; // 0x007D5600

// 0x004F9FB0
static void __stdcall sub_004F9FB0_WriteScreenshotJpeg(unsigned char* pData, const char* szFile, int nWidth, int nHeight)
{
    char szName[256];
    JPEG_CORE_PROPERTIES tProps;
    while (1)
    {
        sprintf(szName, "Screenshot%03d.jpg", gnScreenshotIndex_0072DC40);
        ++gnScreenshotIndex_0072DC40;
        void* hFile = sub_00406960_CreateFile(szFile ? szFile : szName, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile == (void*)-1)
        {
            break;
        }

        sub_004069A0_CloseFile(hFile);
        if (szFile)
        {
            return;
        }
    }

    memset(&tProps, 0, sizeof(tProps));
    ijlInit(&tProps);
    tProps.DIBWidth = nWidth;
    tProps.DIBHeight = nHeight;
    tProps.DIBBytes = pData;
    tProps.DIBColor = 1;
    tProps.DIBPadBytes = ((nWidth * 3 + 3) & ~3) - nWidth * 3;
    if (szFile)
    {
        tProps.JPGFile = szFile;
    }
    else
    {
        tProps.JPGFile = szName;
    }
    tProps.JPGWidth = nWidth;
    tProps.JPGHeight = nHeight;
    tProps.jquality = 100;
    ijlWrite(&tProps, 8);
    ijlFree(&tProps);
}

// 0x004FA0C0
void __fastcall sub_004FA0C0_SaveScreenshot(const char* szFile)
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick_007D5600 < 1000 && !szFile)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions(&nWidth, &nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        sub_004F9FB0_WriteScreenshotJpeg(pBuffer, szFile, nWidth, nHeight);
    }

    gdwLastScreenshotTick_007D5600 = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

// 0x004FA7A0
void __stdcall D2Win_10168_WINMAIN_CreateScreenshot()
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick_007D5600 < 1000)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions(&nWidth, &nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        sub_004F9FB0_WriteScreenshotJpeg(pBuffer, 0, nWidth, nHeight);
    }

    gdwLastScreenshotTick_007D5600 = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

#include "gen/data/Source/D2Win/Src/D2WinMain_004F9FB0.inc"

// 0x004FA200
static D2WinControlStrc* __stdcall sub_004FA200_PickScrollBar(D2WinControlStrc* first, D2WinControlStrc* second)
{
    if (!first) return second;
    if (!second) return first;
    int mouseX = gnMouseX_007D55A4;
    int mouseY = gnMouseY_007D55A8;
    int dx1, dy1, dx2, dy2;
    if (mouseX < first->nImageX)
        dx1 = mouseX - first->nImageX;
    else if (mouseX > first->nWidth + first->nImageX)
        dx1 = mouseX - first->nWidth - first->nImageX;
    else
        dx1 = 0;
    if (mouseY < first->nImageY - first->nHeight)
        dy1 = first->nHeight - first->nImageY + mouseY;
    else if (mouseY > first->nImageY)
        dy1 = mouseY - first->nImageY;
    else
        dy1 = 0;

    if (mouseX < second->nImageX)
        dx2 = mouseX - second->nImageX;
    else if (mouseX > second->nWidth + second->nImageX)
        dx2 = mouseX - second->nWidth - second->nImageX;
    else
        dx2 = 0;
    if (mouseY < second->nImageY - second->nHeight)
        dy2 = second->nHeight - second->nImageY + mouseY;
    else if (mouseY > second->nImageY)
        dy2 = mouseY - second->nImageY;
    else
        dy2 = 0;
    int alignedFirst = dy1 == 0 && dx1 <= 0;
    int alignedSecond = dy2 == 0 && dx2 <= 0;
    if (alignedFirst && !alignedSecond)
        return first;
    if (!alignedFirst && alignedSecond)
        return second;
    if (alignedFirst && alignedSecond)
    {
        if (dx1 > dx2)
            return first;
        return second;
    }
    if (dy1 * dy1 + dx1 * dx1 < dy2 * dy2 + dx2 * dx2)
        return first;
    return second;
}

// build: context D2Win_COMMANDS_MouseWheel_6F8AE220
void __stdcall D2Win_COMMANDS_MouseWheel_6F8AE220(SMSGHANDLER_PARAMS* pMsg)
{
    const int nIncrement = (int)(short)(pMsg->wParam >> 16) / 120;

    if (POPUP_IsActive())
    {
        return;
    }

    D2WinControlStrc* pScrollBar = 0;
    D2WinControlStrc* pFirst = dword_6F8FE264 ? dword_6F8FE264 : gpControlList_6F8FE24C;
    if (pFirst)
    {
        D2WinControlStrc* pControl = pFirst;
        do
        {
            if (pControl->eType == D2WIN_SCROLLBAR && pControl->dwFlags & gdwBitMasks[2] && pControl->dwFlags & gdwBitMasks[0] && SCROLLBAR_GetMaxSteps((D2WinScrollBarStrc*)pControl) > 0)
            {
                pScrollBar = sub_004FA200_PickScrollBar(pScrollBar, pControl);
            }

            pControl = pControl->pNext;
        }
        while (pControl);

        if (pScrollBar && sub_6F8AF240(pMsg, (D2WinScrollBarStrc*)pScrollBar, nIncrement))
        {
            goto done;
        }
    }

    for (D2WinControlStrc* i = pFirst; i; i = i->pNext)
    {
        if (i->eType == D2WIN_BUTTON && BUTTON_OnMouseWheelScrolled((D2WinButtonStrc*)i, nIncrement))
        {
            break;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}
