#include "Storm.h"
#include "D2DDrawTypes.h"
#include "D2GfxTypes.h"

struct D2CriticalSectionStrc;
struct ConnectionHandlerView;
struct D2Socket006BC030Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink); // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink); // 0x006CC5C4
extern D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134
extern D2DDSurfaceStrc* gpSurface_00970E68; // 0x00970E68
extern unsigned int gnBinkX_00989C0C; // 0x00989C0C
extern D2BinkStrc* gpBink_00989C10; // 0x00989C10
extern int gbBinkDone_00989C1C; // 0x00989C1C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg); // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg); // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) D2BinkStrc* __stdcall BinkOpen(void* hFile, unsigned int nFlags); // 0x006CC5B8
extern "C" __declspec(dllimport) int __stdcall BinkWait(D2BinkStrc* pBink); // 0x006CC5C8
extern "C" __declspec(dllimport) void __stdcall BinkClose(D2BinkStrc* pBink); // 0x006CC5CC
extern "C" __declspec(dllimport) unsigned int __stdcall BinkDDSurfaceType(D2DDSurfaceStrc* pSurface); // 0x006CC5D0
extern "C" __declspec(dllimport) int __stdcall BinkSetSoundSystem(void* pfOpen, unsigned long nParam); // 0x006CC5D4
extern "C" __declspec(dllimport) void* __stdcall BinkOpenDirectSound(unsigned long nParam); // 0x006CC5D8
int __cdecl sub_00406D20(); // 0x00406D20
int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
void __cdecl sub_006BBBF0_RenderVideoFrame(); // 0x006BBBF0
void __fastcall D2SOUND_SetMasterVolume(int nVolume); // 0x00515CE0
extern int gnRenderHeight; // 0x007C913C
extern unsigned int gnBinkY_00989C08; // 0x00989C08
extern unsigned int gnBinkFlags_00989C18; // 0x00989C18

typedef int (__fastcall* PacketHandler)(const unsigned char* data,unsigned int size,int context);

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_callback_width[sizeof(PacketHandler)==4?1:-1];

struct ConnectionHandlerView
{
    char retained[0x168];
    PacketHandler callback;
    int context;
};

typedef char check_callback[OFFSET(ConnectionHandlerView,callback)==0x168?1:-1];

typedef char check_context[OFFSET(ConnectionHandlerView,context)==0x16c?1:-1];

typedef char check_partial_view[sizeof(ConnectionHandlerView)==0x170?1:-1];

int __stdcall sub_006B017A_Send(int nSocket, const void* pBuffer, int nLength, int nFlags); // 0x006B017A
int __stdcall sub_006B0168_GetLastError(); // 0x006B0168

struct D2Socket006BC030Strc
{
    unsigned char unk_00[8];
    int nSocket;
    D2CriticalSectionStrc tLock;
    unsigned char unk_24[8];
    int bClosed;
    int nState;
    int nLastError;
};

unsigned int gnBinkY_00989C08; // 0x00989C08

unsigned int gnBinkFlags_00989C18; // 0x00989C18

// 0x006BBBF0
void __cdecl sub_006BBBF0_RenderVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    D2DDSurfaceDesc2Strc ddsd = { sizeof(D2DDSurfaceDesc2Strc) };
    BinkDoFrame(gpBink_00989C10);
    D2_ASSERT(gpRenderCriticalSection, 0x3D);
    EnterCriticalSection(gpRenderCriticalSection);
    if (gpSurface_00970E68->lpVtbl->Lock(gpSurface_00970E68, 0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpBink_00989C10, ddsd.lpSurface, ddsd.lPitch, gpBink_00989C10->nHeight, gnBinkX_00989C0C, gnBinkY_00989C08, gnBinkFlags_00989C18);
        gpSurface_00970E68->lpVtbl->Unlock(gpSurface_00970E68, 0);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
    if (gpBink_00989C10->nFrameNum == gpBink_00989C10->nFrames)
    {
        gbBinkDone_00989C1C = 1;
        return;
    }
    BinkNextFrame(gpBink_00989C10);
}

unsigned int gnBinkX_00989C0C; // 0x00989C0C

D2BinkStrc* gpBink_00989C10; // 0x00989C10

int gbBinkDone_00989C1C; // 0x00989C1C

int gbBinkQuit_00989C20; // 0x00989C20

unsigned long gdwBinkAbortTick_00989C24; // 0x00989C24

// 0x006BBCE0
void __fastcall sub_006BBCE0_Run(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbBinkDone_00989C1C = 0;
    if (gpBink_00989C10)
    {
        return;
    }
// build: symbol ?gbRenderPaused@* 0x007C9144
    if (gbRenderPaused)
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

// build: symbol ?gnRenderWidth@* 0x007C9138
    gnBinkX_00989C0C = (gnRenderWidth - gpBink_00989C10->nWidth) >> 1;
    if (gnBinkX_00989C0C & 3)
    {
        gnBinkX_00989C0C = (gnBinkX_00989C0C | 3) + 1;
    }
    gnBinkY_00989C08 = (gnRenderHeight - gpBink_00989C10->nHeight) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbBinkDone_00989C1C && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused)
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
        D2SOUND_SetMasterVolume(0);
        BinkClose(gpBink_00989C10);
        CloseHandle(hFile);
        D2SOUND_SetMasterVolume(0xFF);
        gpBink_00989C10 = 0;
    }
    if (gbBinkQuit_00989C20)
    {
        exit(-1);
    }
}

// 0x006BBF20
extern "C" __declspec(dllexport) int __stdcall sub_006BBF20(const unsigned char* pBuffer) {
    return ((*(pBuffer + 1) & 0x7F) << 7) + (*pBuffer & 0x7F);
}

// 0x006BBF40
extern "C" __declspec(dllexport) void __stdcall sub_006BBF40(unsigned char* pBuffer, unsigned int nValue) {
    *pBuffer = (unsigned char)(nValue | 0x80);
    *(pBuffer + 1) = (unsigned char)((nValue >> 7) | 0x80);
}

// 0x006BC010
extern "C" void __stdcall sub_006BC010_SetHandler(ConnectionHandlerView* connection,PacketHandler callback,int context)
{
    if (connection)
    {
        connection->callback = callback;
        connection->context = context;
    }
}

// 0x006BC030
int __fastcall sub_006BC030_Send(D2Socket006BC030Strc* pSocket, const void* pBuffer, int nLength)
{
    if (!pSocket || pSocket->bClosed)
    {
        return -1;
    }
    EnterCriticalSection(&pSocket->tLock);
    int nResult;
    const int nSent = sub_006B017A_Send(pSocket->nSocket, pBuffer, nLength, 0);
    if (nSent == -1)
    {
        const int nError = sub_006B0168_GetLastError();
        pSocket->nLastError = nError;
        if (nError == 0x2733)
        {
            nResult = 0;
        }
        else
        {
            pSocket->nState = 4;
            return -1;
        }
    }
    else
    {
        nResult = nSent;
    }
    LeaveCriticalSection(&pSocket->tLock);
    return nResult;
}
