#include "D2Win.h"

enum D2WinControlType
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};
struct D2CompositeUnitStrc;

struct D2WinControlStrc
{
    int eType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    void* pfDraw;
    void* pfInitialize;
    void* pfHandleMouseDown;
    void* pfHandleMouseUp;
    void* pfHandleCharInput;
    void* pfHandleVirtualKeyInput;
    void* field_34;
    void* pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

struct D2WinCommandRegisterStrc
{
    int nType;
    int nId;
    void* pCallback;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0
int __fastcall D2Win_10177(unsigned char nAct);                                                             // 0x004FB480
int __fastcall D2Win_10043_TEXTBOX_Destroy(D2WinControlStrc* pControl);                                     // 0x004FC960
int __fastcall sub_004FD0F0(void* pArg);                                                                    // 0x004FD0F0
int __fastcall sub_004FD100(void* pArg);                                                                    // 0x004FD100
int __fastcall sub_004FD820(void* pArg);                                                                    // 0x004FD820
int __fastcall D2Win_10071_EDITBOX_Destroy(D2WinControlStrc* pControl);                                     // 0x004FDAA0
int __fastcall sub_00500300(void* pArg);                                                                    // 0x00500300
int __fastcall BUTTON_Destroy(D2WinControlStrc* pControl);                                                  // 0x00500930
void __cdecl sub_005015F0();                                                                                // 0x005015F0
void __fastcall D2Win_10115_FONT();                                                                         // 0x00502C60
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_00503A50_DrawCompositeShadow(D2CompositeUnitStrc* pCompositeUnit);                                          // 0x00503A50
void __fastcall sub_00503BA0(D2CompositeUnitStrc* pCompositeUnit, int nValue);                              // 0x00503BA0
D2CompositeUnitStrc* __cdecl sub_00505150();                                                                // 0x00505150
D2CompositeUnitStrc* __stdcall D2Win_10148(D2CompositeUnitStrc* pCompositeUnit);                            // 0x00505160
void __stdcall D2Win_10157();                                                                               // 0x00505550
void __fastcall sub_00505810(D2CompositeUnitStrc* pCompositeUnit);                                          // 0x00505810
void __fastcall sub_00505A80(D2CompositeUnitStrc* pCompositeUnit);                                          // 0x00505A80
int __fastcall SMACK_Destroy(D2WinControlStrc* pControl);                                                   // 0x00506A40
void __fastcall WREGISTER_RegisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands); // 0x00506DA0
void __fastcall WREGISTER_UnregisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands); // 0x00506E00
int __fastcall LIST_Destroy(D2WinControlStrc* pControl);                                                    // 0x00506E60
void __stdcall LIST_LoadPentspinCellfile();                                                                 // 0x005070D0
void __stdcall LIST_UnloadPentspinCellfile();                                                               // 0x00507140
int __fastcall ACCOUNTLIST_Destroy(D2WinControlStrc* pControl);                                             // 0x00507AF0
int __fastcall sub_00507DB0(void* pArg);                                                                    // 0x00507DB0
int __fastcall sub_00507EE0(void* pArg);                                                                    // 0x00507EE0
int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2WinCommandRegisterStrc gpCommandRegister_6F8BDE28[0x21];                                          // 0x0072DC48
D2WinControlStrc* dword_6F8FE250;                                                                           // 0x007D55C0
extern void* gpfWndProc_6F8FE268;                                                                           // 0x007D55D8
extern int (__cdecl* dword_6F8FE27C)();                                                                     // 0x007D55EC

// 0x004F8FE0
int __fastcall D2Win_10015()
{
    D2Win_10115_FONT();
    sub_00502EF0(1);
    LIST_LoadPentspinCellfile();
    D2Win_10157();
    gpfWndProc_6F8FE268 = 0;
    WREGISTER_RegisterCommands(sub_004F59A0(), gpCommandRegister_6F8BDE28, 0x21);
    D2Win_10177(0);
    dword_6F8FE27C = 0;
    return 1;
}

// 0x004F9250
int __fastcall sub_004F9250_AppendToDeadList(D2WinControlStrc* pControl)
{
    pControl->pNext = 0;
    if (!dword_6F8FE250)
    {
        dword_6F8FE250 = pControl;
        return 1;
    }

    D2WinControlStrc* pLast = dword_6F8FE250;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pControl;
    return 1;
}

// 0x004F9290
int __stdcall CONTROL_FreeDeadList()
{
    if (gnWinCallbackDepth_007D55C4 > 0)
    {
        return 1;
    }

    while (dword_6F8FE250)
    {
        if (dword_6F8FE250->dwFlags & gdwBitMasks[0])
        {
            break;
        }

        D2WinControlStrc* pNext = dword_6F8FE250->pNext;
        FOG_Free(dword_6F8FE250, ".\\Src\\D2WinMain.cpp", 0x25A, 0);
        dword_6F8FE250 = pNext;
    }

    while (dword_6F8FE250)
    {
        if (dword_6F8FE250->dwFlags & gdwBitMasks[1])
        {
            break;
        }

        D2WinControlStrc* pNext = dword_6F8FE250->pNext;
        FOG_Free(dword_6F8FE250, ".\\Src\\D2WinMain.cpp", 0x263, 0);
        dword_6F8FE250 = pNext;
    }

    return 1;
}

// 0x004F95C0
int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl)
{
    if (!ppControl)
    {
        return 0;
    }

    D2WinControlStrc* pControl = *ppControl;
    if (!pControl)
    {
        return 0;
    }

    int nResult;
    switch (pControl->eType)
    {
    case D2WIN_TEXTBOX:
        nResult = D2Win_10043_TEXTBOX_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_EDITBOX:
        nResult = D2Win_10071_EDITBOX_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_IMAGE:
        nResult = sub_004FD0F0(pControl);
        *ppControl = 0;
        break;

    case D2WIN_IMAGE2:
        nResult = sub_004FD100(pControl);
        *ppControl = 0;
        break;

    case D2WIN_ANIMIMAGE:
        nResult = sub_00500300(pControl);
        *ppControl = 0;
        break;

    case D2WIN_SCROLLBAR:
        nResult = sub_00507EE0(pControl);
        *ppControl = 0;
        break;

    case D2WIN_BUTTON:
        nResult = BUTTON_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_LIST:
        nResult = LIST_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_TIMER:
        nResult = sub_004FD820(pControl);
        *ppControl = 0;
        break;

    case D2WIN_SMACK:
        nResult = SMACK_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_PROGRESSBAR:
        nResult = sub_00507DB0(pControl);
        *ppControl = 0;
        break;

    case D2WIN_ACCOUNTLIST:
        nResult = ACCOUNTLIST_Destroy(pControl);
        *ppControl = 0;
        break;

    default:
        nResult = 0;
        *ppControl = 0;
        break;
    }

    return nResult;
}

// 0x004F9710
int __fastcall sub_004F9710(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x33F);

    return pControl->dwFlags & gdwBitMasks[0];
}

// 0x004F9740
void __fastcall sub_004F9740(D2WinControlStrc* pControl, int bSet)
{
    D2_ASSERT(pControl, 0x34C);

    if (bSet)
    {
        pControl->dwFlags |= gdwBitMasks[2];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[2];
    }
}

// 0x004F9870
void __cdecl sub_004F9870_DrawFontCaches()
{
    for (D2CompositeUnitStrc* p = sub_00505150(); p; p = D2Win_10148(p))
    {
        sub_00503A50_DrawCompositeShadow(p);
    }

    for (D2CompositeUnitStrc* p = sub_00505150(); p; p = D2Win_10148(p))
    {
        sub_00503BA0(p, -1);
    }

    for (D2CompositeUnitStrc* p = sub_00505150(); p; p = D2Win_10148(p))
    {
        sub_00505810(p);
        sub_00505A80(p);
    }
}

// 0x004FA550
int __fastcall D2Win_10016()
{
    gnWinCallbackDepth_007D55C4 = 0;
    CONTROL_FreeDeadList();
    LIST_UnloadPentspinCellfile();
    sub_005015F0();
    WREGISTER_UnregisterCommands(sub_004F59A0(), gpCommandRegister_6F8BDE28, 0x21);
    return 1;
}

// 0x004FAAE0
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile)
{
    CelFileFreeHardware(pCellFile);
    if (pCellFile)
    {
        FOG_Free(pCellFile, ".\\Src\\D2WinArchive.cpp", 0x5C, 0);
    }
}

#include "gen/data/Source/D2Win/Src/D2WinMain_004F8FE0.inc"
