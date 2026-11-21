typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BC2C0_Conn
{
    char unk_00[0x0C];
    char cs[0x18];
    int bActive;
    int unk_28;
    int bClosing;
};

struct sub_006BC2C0_Strc
{
    char unk_000[0x110];
    sub_006BC2C0_Conn* pConn;
    char unk_114[0x10];
    int bClosing;
};

static void sub_006BC2C0_SetClosing(sub_006BC2C0_Strc* pThis);
// 0x006BC2C0
static void sub_006BC2C0_SetClosing(sub_006BC2C0_Strc* pThis)
{
    if (pThis && pThis->pConn && pThis->pConn->bActive)
    {
        pThis->bClosing = 1;
        EnterCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
        pThis->pConn->bClosing = 1;
        LeaveCriticalSection((CRITICAL_SECTION*)pThis->pConn->cs);
    }
}

// calling-convention shim (not game code)
int __stdcall sub_006BC2C0_Shim(sub_006BC2C0_Strc* pThis)
{
    sub_006BC2C0_SetClosing(pThis);
    return pThis->bClosing;
}
