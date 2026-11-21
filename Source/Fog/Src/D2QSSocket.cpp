#include "Fog.h"

#define D2_ASSERT(x,line) do { if (!(x)) { sub_00408A60(gszAssert_006CC837, sub_00408090(), line); exit(-1); } } while (0)

struct T006BC290;
struct FSafeSock;
struct sub_006BC780_Strc;

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern const char gszAssert_006CC837[]; // 0x006CC837
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __fastcall sub_006C1F60_InitLockedList(void* pList); // 0x006C1F60
extern const char gszSocketFile_006FC418[]; // 0x006FC418
extern const char gszUnknown_006CCED8[]; // 0x006CCED8

struct T006BC290
{
    char unk_00[8];
    char szName[0x104];
    int nValue;
    char unk_110[8];
    int nState;
    int nZero;
    char unk_120[8];
    char szLabel[0x40];
    char unk_168[8];
    char tList[0x24];
};

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
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_006C1F80(void* pQueue); // 0x006C1F80
static void sub_006BC2C0_SetClosing(sub_006BC780_Strc* pThis);

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

// 0x006BC6A0
T006BC290* __stdcall sub_006BC6A0_AllocSocketRecord(const char* szName, int nValue, const char* szLabel)
{
    D2_ASSERT(szName, 0x242);
    D2_ASSERT(strlen(szName) < 0x103, 0x243);
    T006BC290* pRecord = (T006BC290*)FOG_Alloc(sizeof(T006BC290), gszSocketFile_006FC418, 0x245, 0);
    if (pRecord)
    {
        memset(pRecord, 0, sizeof(T006BC290));
        SStrCopy(pRecord->szName, szName, 0x104);
        if (szLabel)
            SStrCopy(pRecord->szLabel, szLabel, 4);
        else
            SStrCopy(pRecord->szLabel, gszUnknown_006CCED8, 0x40);
        pRecord->nValue = nValue;
        sub_006C1F60_InitLockedList(pRecord->tList);
        pRecord->nState = 2;
        pRecord->nZero = 0;
    }
    return pRecord;
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
