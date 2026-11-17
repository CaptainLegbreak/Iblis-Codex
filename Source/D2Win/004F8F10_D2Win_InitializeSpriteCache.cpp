struct D2CellFileStrc;

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2WinControlStrc
{
    int nType;
    D2CellFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    int (__fastcall* pfDraw)(D2WinControlStrc*);
    int (__fastcall* pfInitialize)(D2WinControlStrc*);
    void* unk0x24[6];
    D2WinControlStrc* pNext;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CellFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect);                 // 0x006CC4BC

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void* __cdecl sub_004F59A0();                                                                              // 0x004F59A0
int __stdcall WINDOW_GetDimensions(long* pWidth, long* pHeight);                                            // 0x004F59B0
int __stdcall WINDOW_Create(int bWindowed, int nResolution);                                                // 0x004F5610
int __stdcall WINDOW_Resize(int nResolution, int bForceResize);                                             // 0x004F5AA0
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
void __stdcall WINDOW_EndCutScene(int nResolution);                                                         // 0x004F6080
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);    // 0x004F60F0
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340
void __stdcall D2GFX_ClearScreen(int bPartial);                                                             // 0x004F63B0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_004F9250_AppendToDeadList(D2WinControlStrc* pControl);                                   // 0x004F9250
void __cdecl sub_004F9290_FreeDeadControls();                                                               // 0x004F9290
void __cdecl sub_004F97E0_PaintCursor();                                                                     // 0x004F97E0
void __cdecl sub_004F9870_DrawFontCaches();                                                                 // 0x004F9870
void __fastcall sub_004FB130_SetActiveState(int bActive);                                                   // 0x004FB130
void __stdcall D2CMP_InitSpriteCache(int a1, int nCacheSize, int nCacheCount, int a4);                      // 0x005FFD40
void __stdcall sub_005FFE30_FreeTileCache(int bFree);                                                       // 0x005FFE30

extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
tagRECT gSavedWindowRect_007D5580;                                                                          // 0x007D5580
int gnCursorFrame;                                                                                          // 0x007D55A0
extern void* ghMainWindow_6F8FE23C;                                                                         // 0x007D55AC
D2CellFileStrc* gpBackgroundCellFile;                                                                       // 0x007D55B0
extern int gbWindowed_6F8FE244;                                                                             // 0x007D55B4
int gnResolution_6F8FE248;                                                                                  // 0x007D55B8
D2WinControlStrc* gpControlList_6F8FE24C;                                                                   // 0x007D55BC
extern D2WinControlStrc* dword_6F8FE250;                                                                    // 0x007D55C0
extern int dword_6F8FE254;                                                                                  // 0x007D55C4
extern D2WinControlStrc* gpEditBox_6F8FE258;                                                                // 0x007D55C8
D2WinControlStrc* dword_6F8FE25C;                                                                           // 0x007D55CC
void* dword_6F8FE260;                                                                                       // 0x007D55D0
extern D2WinControlStrc* dword_6F8FE264;                                                                    // 0x007D55D4
void* gpfWndProc_6F8FE268;                                                                                  // 0x007D55D8
extern int dword_6F8FE26C;                                                                                  // 0x007D55DC
int dword_6F8FE278;                                                                                         // 0x007D55E8
extern int (__cdecl* dword_6F8FE27C)();                                                                     // 0x007D55EC

// 0x004F8F10
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution)
{
    dword_6F8FE26C = 1;

    if (!WINDOW_Create(bWindowed, nResolution))
    {
        return 0;
    }

    D2CMP_InitSpriteCache(0, 0x800000, 0x7D000, 0);
    ghMainWindow_6F8FE23C = sub_004F59A0();
    gpBackgroundCellFile = 0;
    gpControlList_6F8FE24C = 0;
    dword_6F8FE250 = 0;
    dword_6F8FE254 = 0;
    dword_6F8FE25C = 0;
    dword_6F8FE260 = 0;
    gpEditBox_6F8FE258 = 0;
    gpfWndProc_6F8FE268 = 0;
    dword_6F8FE264 = 0;
    dword_6F8FE278 = 0;
    gnCursorFrame = 0;
    dword_6F8FE27C = 0;
    gnResolution_6F8FE248 = nResolution;
    gbWindowed_6F8FE244 = bWindowed;
    return 1;
}

// 0x004F9060
void __stdcall D2Win_10004(int nResolution)
{
    gnResolution_6F8FE248 = nResolution;

    if (nResolution == 1)
    {
        sub_005FFE30_FreeTileCache(1);
    }

    WINDOW_EndCutScene(nResolution);

    if (nResolution == 1)
    {
        D2CMP_InitSpriteCache(0, 0x800000, 0x7D000, 0);
    }
}

// 0x004F90A0
int __stdcall sub_004F90A0_SwitchResolution(int nResolution)
{
    if (!gnResolution_6F8FE248 && !gSavedWindowRect_007D5580.right)
    {
        void* hWnd = sub_004F59A0();
        WINDOW_GetDimensions(&gSavedWindowRect_007D5580.right, &gSavedWindowRect_007D5580.bottom);
        GetWindowRect(hWnd, &gSavedWindowRect_007D5580);
    }

    gnResolution_6F8FE248 = nResolution;
    sub_005FFE30_FreeTileCache(1);
    if (!WINDOW_Resize(nResolution, 0))
    {
        sub_00410610_WriteLogLine("Failed to resize window... this is fatal!");
        exit(-1);
    }

    sub_004FB130_SetActiveState(0);
    D2CMP_InitSpriteCache(0, 0x800000, 0x7D000, 0);
    return 1;
}

// 0x004F9310
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl)
{
    if (dword_6F8FE25C == pControl)
    {
        dword_6F8FE25C = 0;
    }

    if (gpEditBox_6F8FE258 == pControl)
    {
        gpEditBox_6F8FE258 = 0;
    }

    if (dword_6F8FE264 == pControl)
    {
        dword_6F8FE264 = 0;
        dword_6F8FE278 = 0;
    }

    if (dword_6F8FE260 == pControl)
    {
        dword_6F8FE260 = 0;
    }

    D2WinControlStrc* pPrevious = gpControlList_6F8FE24C;
    if (!pPrevious)
    {
        return 0;
    }

    if (pPrevious == pControl)
    {
        gpControlList_6F8FE24C = pControl->pNext;
        sub_004F9250_AppendToDeadList(pControl);
        return 1;
    }

    for (D2WinControlStrc* pCurrent = pPrevious->pNext; pCurrent; pCurrent = pCurrent->pNext)
    {
        if (pCurrent == pControl)
        {
            pPrevious->pNext = pCurrent->pNext;
            sub_004F9250_AppendToDeadList(pControl);
            return 1;
        }

        pPrevious = pCurrent;
    }

    return 1;
}

// 0x004F98E0
void __stdcall sub_004F98E0()
{
    if (WINDOW_GetState())
    {
        return;
    }

    for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
    {
        if (i->pfInitialize)
        {
            i->pfInitialize(i);
        }
    }

    if (gpfWndProc_6F8FE268)
    {
        return;
    }

    long nScreenWidth;
    long nScreenHeight;
    WINDOW_GetDimensions(&nScreenWidth, &nScreenHeight);

    if (D2GFX_StartDraw(0, 0, 0, 0))
    {
        D2GFX_ClearScreen(0);

        if (gpBackgroundCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpBackgroundCellFile;
            tContext.unk0x40 = 0;
            tContext.nFrame = 0;

            for (int y = 256; y < 768; y += 256)
            {
                for (int x = 0; x < 1024; x += 256)
                {
                    sub_004F6480(&tContext, x, y, -1, 5, 0);
                    ++tContext.nFrame;
                }
            }

            for (int x = 0; x < 1024; x += 256)
            {
                sub_004F6480(&tContext, x, nScreenHeight - 1, -1, 5, 0);
                ++tContext.nFrame;
            }
        }

        for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
        {
            if (i->pfDraw && !(i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        sub_004F9870_DrawFontCaches();

        if (dword_6F8FE278)
        {
            D2GFX_DrawBoxAlpha(0, 0, nScreenWidth, nScreenHeight, 0, 127);
        }

        for (D2WinControlStrc* i = gpControlList_6F8FE24C; i; i = i->pNext)
        {
            if (i->pfDraw && (i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        sub_004F97E0_PaintCursor();
        D2GFX_EndScene();
    }

    sub_004F9290_FreeDeadControls();
}
