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
void __cdecl sub_006BBBF0_RenderVideoFrame(); // 0x006BBBF0
void __fastcall sub_00515CE0_SetMasterVolume(int nVolume);                                                  // 0x00515CE0

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern int gbRenderPaused_007C9144;                                                                         // 0x007C9144
extern D2DDrawSurfaceStrc* gpSurface_00970E68;                                                         // 0x00970E68
extern unsigned int gnBinkY_00989C08;                                                                  // 0x00989C08
unsigned int gnBinkX_00989C0C;                                                                         // 0x00989C0C
D2BinkStrc* gpBink_00989C10;                                                                           // 0x00989C10
extern unsigned int gnBinkFlags_00989C18;                                                              // 0x00989C18
int gbBinkDone_00989C1C;                                                                               // 0x00989C1C
int gbBinkQuit_00989C20;                                                                               // 0x00989C20
unsigned long gdwBinkAbortTick_00989C24;                                                               // 0x00989C24

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

// 0x006BBCE0
void __fastcall sub_006BBCE0_Run(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbBinkDone_00989C1C = 0;
    if (gpBink_00989C10)
    {
        return;
    }
    if (gbRenderPaused_007C9144)
    {
        return;
    }

    gnBinkFlags_00989C18 = BinkDDSurfaceType(gpSurface_00970E68);
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
    gpBink_00989C10 = BinkOpen(hFile, nFlags);
    if (!gpBink_00989C10)
    {
        CloseHandle(hFile);
LABEL_FAIL:
        if (gpBink_00989C10)
        {
            BinkClose(gpBink_00989C10);
            gpBink_00989C10 = 0;
        }
        return;
    }

    gnBinkX_00989C0C = (gnScreenWidth_007C9138 - gpBink_00989C10->Width) >> 1;
    if (gnBinkX_00989C0C & 3)
    {
        gnBinkX_00989C0C = (gnBinkX_00989C0C | 3) + 1;
    }
    gnBinkY_00989C08 = (gnScreenHeight_007C913C - gpBink_00989C10->Height) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbBinkDone_00989C1C && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused_007C9144)
            {
                break;
            }
            if (bAbort)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbBinkDone_00989C1C = 1;
                    gbBinkQuit_00989C20 = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwBinkAbortTick_00989C24 = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpBink_00989C10))
            {
                sub_006BBBF0_RenderVideoFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpBink_00989C10)
    {
        sub_00515CE0_SetMasterVolume(0);
        BinkClose(gpBink_00989C10);
        CloseHandle(hFile);
        sub_00515CE0_SetMasterVolume(0xFF);
        gpBink_00989C10 = 0;
    }
    if (gbBinkQuit_00989C20)
    {
        exit(-1);
    }
}
