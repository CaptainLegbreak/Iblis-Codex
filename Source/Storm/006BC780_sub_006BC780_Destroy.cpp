typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct FSafeSock
{
    char unk_00[0x0C];
    char cs[0x18];
    int bActive;
    int unk_28;
    int bClosing;
};

struct sub_006BC780_Strc
{
    char unk_000[0x110];
    FSafeSock* pConn;
    char unk_114[0x10];
    int bClosing;
    char unk_128[0x48];
    char pQueue[4];
};

void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock); // 0x0040DBD0
void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_006C1F80(void* pQueue); // 0x006C1F80

static __declspec(noinline) void sub_006BC2C0_SetClosing(sub_006BC780_Strc* pThis);
// 0x006BC2C0
static void sub_006BC2C0_SetClosing(sub_006BC780_Strc* pThis)
{
    if (pThis && pThis->pConn && pThis->pConn->bActive)
    {
        pThis->bClosing = 1;
        EnterCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
        pThis->pConn->bClosing = 1;
        LeaveCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
    }
}

// 0x006BC780
void __stdcall sub_006BC780_Destroy(sub_006BC780_Strc* pThis)
{
    if (pThis)
    {
        sub_006BC2C0_SetClosing(pThis);
        sub_006C1F80(pThis->pQueue);
        if (pThis->pConn && pThis->pConn->bActive)
        {
            FOG_SOCKET_Destroy(pThis->pConn);
            pThis->pConn = 0;
        }
        FOG_Free(pThis, ".\\Src\\D2QSSocket.cpp", 636, 0);
    }
}
