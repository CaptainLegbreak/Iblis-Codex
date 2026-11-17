struct D2BinkStrc
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Frames;
    unsigned int f_C;
};

struct tagPOINT
{
    long x;
    long y;
};

struct tagMSG
{
    void* hwnd;
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    tagPOINT pt;
};

struct D2DDrawSurfaceStrc;

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg);                       // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg);                        // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) D2BinkStrc* __stdcall BinkOpen(void* hFile, unsigned int nFlags);          // 0x006CC5B8
extern "C" __declspec(dllimport) int __stdcall BinkWait(D2BinkStrc* pBink);                                 // 0x006CC5C8
extern "C" __declspec(dllimport) void __stdcall BinkClose(D2BinkStrc* pBink);                               // 0x006CC5CC
extern "C" __declspec(dllimport) unsigned int __stdcall BinkDDSurfaceType(D2DDrawSurfaceStrc* pSurface);    // 0x006CC5D0
extern "C" __declspec(dllimport) int __stdcall BinkSetSoundSystem(void* pfOpen, unsigned long nParam);      // 0x006CC5D4
extern "C" __declspec(dllimport) void* __stdcall BinkOpenDirectSound(unsigned long nParam);                 // 0x006CC5D8

int __cdecl sub_00406D20();                                                                              // 0x00406D20
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);         // 0x004192F0
void __cdecl sub_0050FD10_GlideDrawVideoFrame();                                                            // 0x0050FD10
void __cdecl sub_005136F0_BlitBinkFrame();                                                                       // 0x005136F0
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern unsigned int gnGlideBinkY_00880C04;                                                                  // 0x00880C04
unsigned int gnGlideBinkX_00880C08;                                                                         // 0x00880C08
D2BinkStrc* gpGlideBink_00880C0C;                                                                           // 0x00880C0C
extern unsigned int gnGlideBinkFlags_00880C14;                                                              // 0x00880C14
int gbGlideBinkDone_00880C18;                                                                               // 0x00880C18
unsigned long gdwGlideBinkAbortTick_00880C1C;                                                               // 0x00880C1C
extern D2DDrawSurfaceStrc* gpDDrawSurface_00881278;                                                         // 0x00881278
extern unsigned int gnDDrawBinkY_008816B8;                                                                  // 0x008816B8
unsigned int gnDDrawBinkX_008816BC;                                                                         // 0x008816BC
D2BinkStrc* gpDDrawBink_008816C0;                                                                           // 0x008816C0
extern unsigned int gnDDrawBinkFlags_008816C8;                                                              // 0x008816C8
int gbDDrawBinkDone_008816CC;                                                                               // 0x008816CC
int gbDDrawBinkQuit_008816D0;                                                                               // 0x008816D0
unsigned long gdwDDrawBinkAbortTick_008816D4;                                                               // 0x008816D4

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

// 0x0050FDF0
void __fastcall sub_0050FDF0_GlidePlayVideoFile(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbGlideBinkDone_00880C18 = 0;
    if (gpGlideBink_00880C0C)
    {
        return;
    }
    if (gbRenderPaused_007C9144)
    {
        return;
    }

    gnGlideBinkFlags_00880C14 = 2;
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
    if (sub_00406D20())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto LABEL_FAIL;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpGlideBink_00880C0C = BinkOpen(hFile, nFlags);
    if (!gpGlideBink_00880C0C)
    {
        CloseHandle(hFile);
LABEL_FAIL:
        if (gpGlideBink_00880C0C)
        {
            BinkClose(gpGlideBink_00880C0C);
            gpGlideBink_00880C0C = 0;
        }
        return;
    }

    gnGlideBinkX_00880C08 = (gnScreenWidth_007C9138 - gpGlideBink_00880C0C->Width) >> 1;
    if (gnGlideBinkX_00880C08 & 3)
    {
        gnGlideBinkX_00880C08 = (gnGlideBinkX_00880C08 | 3) + 1;
    }
    gnGlideBinkY_00880C04 = (gnScreenHeight_007C913C - gpGlideBink_00880C0C->Height) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbGlideBinkDone_00880C18 && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused_007C9144)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }
            if (bAbort)
            {
                break;
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbGlideBinkDone_00880C18 = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwGlideBinkAbortTick_00880C1C = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpGlideBink_00880C0C))
            {
                sub_0050FD10_GlideDrawVideoFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpGlideBink_00880C0C)
    {
        sub_00515CE0_SetMasterVolume(0);
        BinkClose(gpGlideBink_00880C0C);
        CloseHandle(hFile);
        sub_00515CE0_SetMasterVolume(0xFF);
        gpGlideBink_00880C0C = 0;
    }
}

// 0x005137E0
void __fastcall sub_005137E0_PlayBinkMovie(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbDDrawBinkDone_008816CC = 0;
    if (gpDDrawBink_008816C0)
    {
        return;
    }
    if (gbRenderPaused_007C9144)
    {
        return;
    }

    gnDDrawBinkFlags_008816C8 = BinkDDSurfaceType(gpDDrawSurface_00881278);
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
    if (sub_00406D20())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto LABEL_FAIL;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpDDrawBink_008816C0 = BinkOpen(hFile, nFlags);
    if (!gpDDrawBink_008816C0)
    {
        CloseHandle(hFile);
LABEL_FAIL:
        if (gpDDrawBink_008816C0)
        {
            BinkClose(gpDDrawBink_008816C0);
            gpDDrawBink_008816C0 = 0;
        }
        return;
    }

    gnDDrawBinkX_008816BC = (gnScreenWidth_007C9138 - gpDDrawBink_008816C0->Width) >> 1;
    if (gnDDrawBinkX_008816BC & 3)
    {
        gnDDrawBinkX_008816BC = (gnDDrawBinkX_008816BC | 3) + 1;
    }
    gnDDrawBinkY_008816B8 = (gnScreenHeight_007C913C - gpDDrawBink_008816C0->Height) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbDDrawBinkDone_008816CC && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused_007C9144)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }
            if (bAbort)
            {
                break;
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbDDrawBinkDone_008816CC = 1;
                    gbDDrawBinkQuit_008816D0 = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwDDrawBinkAbortTick_008816D4 = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpDDrawBink_008816C0))
            {
                sub_005136F0_BlitBinkFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpDDrawBink_008816C0)
    {
        sub_00515CE0_SetMasterVolume(0);
        BinkClose(gpDDrawBink_008816C0);
        CloseHandle(hFile);
        sub_00515CE0_SetMasterVolume(0xFF);
        gpDDrawBink_008816C0 = 0;
    }
    if (gbDDrawBinkQuit_008816D0)
    {
        exit(-1);
    }
}
