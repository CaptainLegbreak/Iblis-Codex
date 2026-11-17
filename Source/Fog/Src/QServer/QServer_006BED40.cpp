#include "Fog.h"
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BED40_Entry
{
    char unk_000[0x8A];
    unsigned short nPort;
};

sub_006BED40_Entry* __fastcall sub_006BEC00_FindLocked(int nKey1, int nKey2, CRITICAL_SECTION** ppLock); // 0x006BEC00

// 0x006BED40
unsigned short __stdcall sub_006BED40_GetPort(int nKey1, int nKey2)
{
    CRITICAL_SECTION* pLock = 0;
    sub_006BED40_Entry* pEntry = sub_006BEC00_FindLocked(nKey1, nKey2, &pLock);
    unsigned short nPort = 0;
    if (pEntry)
        nPort = sub_006B019E(pEntry->nPort);
    if (pLock)
        LeaveCriticalSection(pLock);
    return nPort;
}
