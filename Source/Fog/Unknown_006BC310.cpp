typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BC310_Conn
{
    int bOpen;
    int unk_04;
    int hSocket;
    char cs[0x18];
};

struct sub_006BC310_Strc
{
    char unk_000[0x110];
    sub_006BC310_Conn* pConn;
};

int __fastcall sub_0040D880(unsigned int s); // 0x0040D880

static __declspec(noinline) void sub_006BC310_CloseSocket(sub_006BC310_Strc* pThis);
// 0x006BC310
static void sub_006BC310_CloseSocket(sub_006BC310_Strc* pThis)
{
    if (pThis && pThis->pConn && pThis->pConn->bOpen && pThis->pConn->hSocket)
    {
        EnterCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
        sub_0040D880(pThis->pConn->hSocket);
        pThis->pConn->hSocket = -1;
        pThis->pConn->bOpen = 0;
        LeaveCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
    }
}

// calling-convention shim (not game code)
int __stdcall sub_006BC310_Shim(sub_006BC310_Strc* pThis)
{
    sub_006BC310_CloseSocket(pThis);
    return (int)pThis->pConn;
}
