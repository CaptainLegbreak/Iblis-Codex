enum D2ControlTypes
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

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct tagPOINT
{
    long x;
    long y;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct tagTRACKMOUSEEVENT
{
    unsigned long cbSize;
    unsigned long dwFlags;
    void* hwndTrack;
    unsigned long dwHoverTime;
};

struct D2CellFileStrc;
struct D2WinEditBoxStrc;
struct D2ArchiveHandleStrc;

struct D2WinControlStrc
{
    int nType;
    D2CellFileStrc* pCellFile;
    unsigned int dwFlags;
    char unk0x0C[0x30];
    D2WinControlStrc* pNext;
};

struct D2WinTextBoxStrc
{
    D2WinControlStrc controlHeader;
    char unk0x40[0x60];
    int field_A0;
    int field_A4;
};

struct D2WinControlInitStrc
{
    int nType;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int field_14;
    int nStringId;
    D2CellFileStrc** ppCellFile;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

struct D2PaletteTableStrc
{
    void* transPalettes[3];
    void* shadowLightGammaPalettes[49];
    void* standardShiftPalettes[13];
    void* pScreenPalette;
    void* pLuminancePalette;
    void* pDarkBlendPalette;
    void* pDarkenPalette;
    void* pStandardColorsPalette;
    unsigned char* unk0x118;
    unsigned char* unk0x11C;
};

struct D2TransPaletteStrc
{
    unsigned char data[0x10000];
};

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall PtInRect(const tagRECT* pRect, tagPOINT tPoint);           // 0x006CC4B0
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY);                               // 0x006CC4B4
extern "C" __declspec(dllimport) int __stdcall TrackMouseEvent(tagTRACKMOUSEEVENT* pEventTrack);           // 0x006CC520

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
int __cdecl sub_00406D20();                                                                              // 0x00406D20
int __cdecl sub_00407FF0();                                                                                 // 0x00407FF0
void __stdcall WINDOW_SetPaused(int bPaused);                                                               // 0x004F5990
int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                              // 0x004F59B0
void __stdcall sub_004F59F0(int nArg);                                                                      // 0x004F59F0
int __stdcall WINDOW_CheckCutScene();                                                                       // 0x004F5DD0
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
int __stdcall D2GFX_HardwareAcceleratedRenderMode();                                                        // 0x004F6270
void __stdcall D2GFX_SetPaletteTables(D2PaletteTableStrc* pPaletteTables);                                  // 0x004F6410
void __fastcall sub_004FB130_SetActiveState(int bActive);                                                   // 0x004FB130
D2WinControlStrc* __fastcall D2Win_10042_TEXTBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CellFileStrc* pCellFile, int a8, int a9, int a10, int a11); // 0x004FC7A0
void __fastcall sub_004FDCC0(D2WinEditBoxStrc* pEditBox);                                                    // 0x004FDCC0
D2WinControlStrc* __fastcall IMAGE2_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6, int a7, int a8); // 0x004FD6C0
D2WinControlStrc* __fastcall IMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6, int a7); // 0x004FD770
D2WinControlStrc* __fastcall TIMER_Create(int nTimeout, int a2);                                            // 0x004FD9D0
D2WinControlStrc* __fastcall D2Win_10070_EDITBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CellFileStrc* pCellFile, int a8, int a9, int a10, int a11); // 0x005001D0
D2WinControlStrc* __fastcall ANIMIMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10); // 0x00500850
D2WinControlStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10, int a11); // 0x00501290
D2WinControlStrc* __fastcall SMACK_Create(int nX, int nY, int nWidth, int nHeight, int a5);                 // 0x00506B70
D2WinControlStrc* __fastcall LIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6);          // 0x005075E0
D2WinControlStrc* __fastcall ACCOUNTLIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6);   // 0x00507CA0
D2WinControlStrc* __fastcall PROGRESSBAR_Create(int nX, int nY, int nWidth, int nHeight);                  // 0x00507E50
D2WinControlStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6); // 0x005084F0
void __fastcall D2SOUND_10034(int nArg);                                                                    // 0x005148F0
void __fastcall D2SOUND_10065();                                                                            // 0x00514960
int __cdecl sub_00514CF0();                                                                                 // 0x00514CF0
void __fastcall D2SOUND_10049(int nState);                                                                  // 0x00514D00
int __cdecl sub_00514D80();                                                                                 // 0x00514D80
void __fastcall D2SOUND_10070(int nArg);                                                                    // 0x00514D90
int __cdecl sub_00515060();                                                                                 // 0x00515060
D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

extern "C" const char szD2XVideoMpq_006DC788[];                                                             // 0x006DC788
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
extern unsigned int gdwInvBitMasks_006CE2E8[];                                                              // 0x006CE2E8
extern int dword_6F8BDE18;                                                                                  // 0x0072DC3C
extern int dword_6F8BDE20;                                                                                  // 0x0072DC44
int gdwGlobal_007D5590;                                                                                     // 0x007D5590
D2CellFileStrc* gpCursorCellFile;                                                                           // 0x007D5594
extern tagPOINT gMousePosition_6F8FE234;                                                                    // 0x007D55A4
extern D2CellFileStrc* gpBackgroundCellFile;                                                                // 0x007D55B0
int gdwGlobal_007D55B4;                                                                                     // 0x007D55B4
extern D2WinControlStrc* gpControlList_6F8FE24C;                                                            // 0x007D55BC
D2WinEditBoxStrc* gpEditBox_6F8FE258;                                                                       // 0x007D55C8
extern void* dword_6F8FE260;                                                                                // 0x007D55D0
extern D2WinControlStrc* dword_6F8FE264;                                                                    // 0x007D55D4
extern WNDPROC gpfWndProc_6F8FE268;                                                                         // 0x007D55D8
int dword_6F8FE274;                                                                                         // 0x007D55E4
extern int dword_6F8FE278;                                                                                  // 0x007D55E8
int (__cdecl* dword_6F8FE27C)();                                                                            // 0x007D55EC
int gbMouseTracking_007D55F0;                                                                               // 0x007D55F0
int dword_6F8FE284;                                                                                         // 0x007D55F8
int dword_6F8FE288;                                                                                         // 0x007D55FC
extern D2ArchiveHandleStrc* gpD2VideoMPQ;                                                                   // 0x007D5614
extern D2ArchiveHandleStrc* gpD2XVideoMPQ;                                                                  // 0x007D562C
unsigned char gStandardColorsPalette_007D563C[44];                                                          // 0x007D563C
D2Palette256Strc gStandardShiftsPalette_007D5668[13];                                                       // 0x007D5668
unsigned char gbyPaletteMap_007D6368[256];                                                                  // 0x007D6368
unsigned char gScreenPalette_007DE468[65536];                                                               // 0x007DE468
D2TransPaletteStrc gTransPalette_007EE468[3];                                                               // 0x007EE468
unsigned char gDarkenPalette_0081E468[256];                                                                 // 0x0081E468
unsigned char gbyPaletteMap_0081E568[256];                                                                  // 0x0081E568
D2Palette256Strc gShadowsLightGammaPalette_0081EA68[49];                                                    // 0x0081EA68
unsigned char gLuminancePalette_00821B68[65536];                                                            // 0x00821B68
unsigned char gDarkBlendPalette_00831B68[65536];                                                            // 0x00831B68

// 0x004F8FC0
int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc)
{
    gpfWndProc_6F8FE268 = wndProc;
    return 1;
}

// 0x004F9140
int __stdcall BACKGROUND_SetCellFile(D2CellFileStrc* pCellFile)
{
    gpBackgroundCellFile = pCellFile;
    return 1;
}

// 0x004F9160
int __stdcall CURSOR_SetCellFile(D2CellFileStrc* pCellFile)
{
    gpCursorCellFile = pCellFile;
    return 1;
}

// 0x004F9180
void __stdcall sub_004F9180(int (__cdecl* a1)())
{
    dword_6F8FE27C = a1;
}

// 0x004F91A0
int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CellFileStrc* pCellFile)
{
    pControl->pCellFile = pCellFile;
    return 1;
}

// 0x004F91C0
int __stdcall sub_004F91C0(D2WinEditBoxStrc* pEditBox)
{
    if (gpEditBox_6F8FE258)
    {
        if (pEditBox != gpEditBox_6F8FE258)
        {
            sub_004FDCC0(gpEditBox_6F8FE258);
        }

        gpEditBox_6F8FE258 = pEditBox;
        return 1;
    }

    gpEditBox_6F8FE258 = pEditBox;
    return 1;
}

// 0x004F9210
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl)
{
    if (!gpControlList_6F8FE24C)
    {
        gpControlList_6F8FE24C = pControl;
        return 1;
    }

    D2WinControlStrc* pLast = gpControlList_6F8FE24C;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pControl;
    return 1;
}

// 0x004F93C0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit)
{
    D2CellFileStrc* pCellFile = pControlInit->ppCellFile ? *pControlInit->ppCellFile : 0;

    switch (pControlInit->nType)
    {
    case D2WIN_TEXTBOX:
        return D2Win_10042_TEXTBOX_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->field_14, pControlInit->nStringId, pCellFile, pControlInit->field_20, pControlInit->field_2C, pControlInit->field_28, pControlInit->field_24);

    case D2WIN_EDITBOX:
        return D2Win_10070_EDITBOX_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->field_14, pControlInit->nStringId, pCellFile, pControlInit->field_24, pControlInit->field_20, pControlInit->field_2C, pControlInit->field_28);

    case D2WIN_IMAGE:
        return IMAGE2_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->field_20, pControlInit->field_24, pControlInit->field_28);

    case D2WIN_ANIMIMAGE:
        return ANIMIMAGE_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->field_14, pControlInit->field_20, pControlInit->field_24, pControlInit->nStringId, pControlInit->field_28);

    case D2WIN_IMAGE2:
        return IMAGE_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->field_14, pControlInit->nStringId);

    case D2WIN_SCROLLBAR:
        return SCROLLBAR_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->field_20);

    case D2WIN_BUTTON:
        return BUTTON_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->field_20, pControlInit->field_14, pControlInit->field_24, pControlInit->field_2C, pControlInit->nStringId, pControlInit->field_28);

    case D2WIN_LIST:
        return LIST_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->field_24, pControlInit->field_28);

    case D2WIN_TIMER:
        return TIMER_Create(pControlInit->nX, pControlInit->field_20);

    case D2WIN_SMACK:
        return SMACK_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->field_20);

    case D2WIN_PROGRESSBAR:
        return PROGRESSBAR_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight);

    case D2WIN_ACCOUNTLIST:
        return ACCOUNTLIST_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->field_2C, pControlInit->field_28);

    default:
        break;
    }

    return 0;
}

// 0x004F97B0
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect)
{
    return PtInRect(pRect, gMousePosition_6F8FE234);
}

// 0x004F9C80
void __stdcall D2Win_COMMANDS_Control_6F8ADBE0(SMSGHANDLER_PARAMS* pMsg)
{
    dword_6F8FE274 = 1;
    sub_00420290_HandleMsg(pMsg);
}

// 0x004F9CA0
void __stdcall D2Win_COMMANDS_Control_6F8ADBF0(SMSGHANDLER_PARAMS* pMsg)
{
    dword_6F8FE274 = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x004F9F20
void __stdcall D2Win_COMMANDS_ActivateApp_6F8ADC40(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nActive = pMsg->wParam;
    dword_6F8BDE20 = nActive != 0;
    if (nActive)
    {
        if (!sub_00407FF0())
        {
            WINDOW_SetPaused(0);
            sub_004FB130_SetActiveState(1);
        }

        D2SOUND_10049(dword_6F8FE284);
        dword_6F8FE288 = 0;
    }
    else
    {
        if (!dword_6F8FE288)
        {
            dword_6F8FE284 = sub_00514CF0();
        }

        dword_6F8FE288 = 1;
        if (gdwGlobal_007D55B4 != 1)
        {
            WINDOW_SetPaused(1);
        }
    }

    if (WINDOW_CheckCutScene())
    {
        WINDOW_GetState();
    }

    pMsg->bReturn = 0;
}

// 0x004FA160
void __stdcall sub_004FA160(SMSGHANDLER_PARAMS* pMsg)
{
    if (!dword_6F8FE274 || !sub_00515060())
    {
        return;
    }

    if (sub_00514D80())
    {
        D2SOUND_10065();
        D2SOUND_10070(0);
    }
    else
    {
        D2SOUND_10034(1);
        D2SOUND_10070(1);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004FA410
void __stdcall D2Win_10029(int a1)
{
    dword_6F8BDE18 = a1;
}

// 0x004FA420
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet)
{
    if (bSet)
    {
        pControl->dwFlags |= gdwBitMasks_006CE268[3];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks_006CE2E8[3];
    }
}

// 0x004FA450
void __stdcall sub_004FA450(void* a1)
{
    dword_6F8FE260 = a1;
}

// 0x004FA470
int __stdcall D2Win_10033(D2WinControlStrc* a1, int a2)
{
    dword_6F8FE264 = a1;
    dword_6F8FE278 = a2;
    return 1;
}

// 0x004FA4C0
void __stdcall sub_004FA4C0_HideCursorMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        dword_6F8BDE18 = 0;
        sub_004F59F0(0);
    }
    else
    {
        dword_6F8BDE18 = 0;
    }
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x004FA4F0
void __stdcall sub_004FA4F0_MouseLeaveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gbMouseTracking_007D55F0 = 0;
    if (gdwGlobal_007D5590 != 4)
    {
        dword_6F8BDE18 = 0;
    }
    sub_004F59F0(0);
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x004FA6B0
void __stdcall D2Win_COMMANDS_MouseMove_6F8AD670(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gbMouseTracking_007D55F0)
    {
        tagTRACKMOUSEEVENT tEventTrack;
        tEventTrack.cbSize = sizeof(tEventTrack);
        tEventTrack.dwFlags = 2;
        tEventTrack.hwndTrack = pMsg->hWnd;
        tEventTrack.dwHoverTime = 0;
        TrackMouseEvent(&tEventTrack);
        gbMouseTracking_007D55F0 = 1;
    }

    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    dword_6F8BDE18 = 1;
    sub_004F59F0(1);

    int nScreenWidth;
    int nScreenHeight;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);
    --nScreenWidth;
    --nScreenHeight;

    if (D2GFX_HardwareAcceleratedRenderMode())
    {
        int bSetCursorPos = 0;
        if (nX > nScreenWidth)
        {
            nX = nScreenWidth;
            bSetCursorPos = 1;
        }

        if (nY > nScreenHeight)
        {
            nY = nScreenHeight;
            bSetCursorPos = 1;
        }

        if (bSetCursorPos)
        {
            SetCursorPos(nX, nY);
        }
    }

    gMousePosition_6F8FE234.x = nX;
    gMousePosition_6F8FE234.y = nY;
}

// 0x004FAD10
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion)
{
    if (sub_00406D20())
    {
        pfShowMessage = 0;
    }

    if (bExpansion)
    {
        gpD2XVideoMPQ = sub_00517332_LoadMpqFile(szD2XVideoMpq_006DC788, hFile, pfShowMessage, 1000);
        if (!gpD2XVideoMPQ)
        {
            return 0;
        }
    }
    else
    {
        gpD2VideoMPQ = sub_00517332_LoadMpqFile("d2video.mpq", hFile, pfShowMessage, 1000);
        if (!gpD2VideoMPQ)
        {
            return 0;
        }
    }

    return 1;
}

// 0x004FB010
void __cdecl sub_004FB010_SetPaletteTables()
{
    D2PaletteTableStrc tPaletteTable;

    for (int i = 0; i < 3; ++i)
    {
        tPaletteTable.transPalettes[i] = &gTransPalette_007EE468[i];
    }

    for (int i = 0; i < 49; ++i)
    {
        tPaletteTable.shadowLightGammaPalettes[i] = &gShadowsLightGammaPalette_0081EA68[i];
    }

    for (int i = 0; i < 13; ++i)
    {
        tPaletteTable.standardShiftPalettes[i] = &gStandardShiftsPalette_007D5668[i];
    }

    tPaletteTable.pScreenPalette = gScreenPalette_007DE468;
    tPaletteTable.pLuminancePalette = gLuminancePalette_00821B68;
    tPaletteTable.pDarkBlendPalette = gDarkBlendPalette_00831B68;
    tPaletteTable.pDarkenPalette = gDarkenPalette_0081E468;
    tPaletteTable.pStandardColorsPalette = gStandardColorsPalette_007D563C;
    tPaletteTable.unk0x118 = gbyPaletteMap_007D6368;
    tPaletteTable.unk0x11C = gbyPaletteMap_0081E568;
    D2GFX_SetPaletteTables(&tPaletteTable);
}

// 0x004FB740
int __fastcall D2Win_10062(D2WinTextBoxStrc* pTextBox, int a2, int a3)
{
    D2_ASSERT(pTextBox, 0xFA);
    D2_ASSERT(pTextBox->controlHeader.nType == D2WIN_TEXTBOX, 0xFB);

    pTextBox->field_A0 = a2;
    pTextBox->field_A4 = a3;
    return 1;
}

#include "gen/data/Source/D2Win/004F8FC0_D2Win_10014_SetWndProc.inc"
