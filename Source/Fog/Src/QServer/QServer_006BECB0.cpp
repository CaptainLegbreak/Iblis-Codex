#include "Fog.h"

struct sub_006BECB0_Entry;

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BECB0_Entry
{
    char unk_000[0x7A];
    unsigned short nPort;
};

sub_006BECB0_Entry* __fastcall sub_006BEC00_FindLocked(int nKey1, int nKey2, CRITICAL_SECTION** ppLock); // 0x006BEC00

struct D2Connection006C03A0Strc
{
    unsigned char unk_00[0x0C];
    int bClosing;
};

typedef int (__fastcall* SERVERHANDLER)(D2Server006C03A0Strc* pServer, int a, int b);

struct D2Server006C03A0Strc
{
    int bQueued;
    unsigned char unk_004[0x868];
    int nMode;
    unsigned char unk_870[0xBCC - 0x870];
    SERVERHANDLER pfnHandler;
};

D2Connection006C03A0Strc* __fastcall sub_006BE540_Find(D2Server006C03A0Strc* pServer, unsigned int nKey); // 0x006BE540
int __fastcall sub_006C3410_Send(D2Server006C03A0Strc* pServer, D2Connection006C03A0Strc* pConnection, int a, int b); // 0x006C3410
static int sub_006C0140_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b); // 0x006C0140

// 0x006BECB0
unsigned short __stdcall sub_006BECB0_GetPort(int nKey1, int nKey2)
{
    CRITICAL_SECTION* pLock = 0;
    sub_006BECB0_Entry* pEntry = sub_006BEC00_FindLocked(nKey1, nKey2, &pLock);
    unsigned short nPort = 0;
    if (pEntry)
        nPort = sub_006B019E(pEntry->nPort);
    if (pLock)
        LeaveCriticalSection(pLock);
    return nPort;
}

// 0x006C0140
static int sub_006C0140_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b)
{
    if (!pServer)
    {
        return 0;
    }
    D2Connection006C03A0Strc* pConnection = sub_006BE540_Find(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bQueued)
    {
        return sub_006C2C70_Queue(pServer, pConnection, a, b);
    }
    return sub_006C3410_Send(pServer, pConnection, a, b);
}

// calling-convention shim (not game code)
int __stdcall sub_CallSite_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b)
{
    return sub_006C0140_SendToKey(pServer, nKey, a, b);
}

// 0x006C03A0
int __stdcall sub_006C03A0_SendToKey(D2Server006C03A0Strc* pServer, unsigned int nKey, int a, int b)
{
    if (!pServer)
    {
        return 0;
    }
    if ((pServer->nMode == 1 || pServer->nMode == 2) && pServer->pfnHandler)
    {
        return pServer->pfnHandler(pServer, a, b);
    }
    D2Connection006C03A0Strc* pConnection = sub_006BE540_Find(pServer, nKey);
    if (!pConnection || pConnection->bClosing)
    {
        return 0;
    }
    if (pServer->bQueued)
    {
        return sub_006C2C70_Queue(pServer, pConnection, a, b);
    }
    return sub_006C3410_Send(pServer, pConnection, a, b);
}
