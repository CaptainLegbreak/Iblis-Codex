#include "Fog.h"
#include "D2QServer.h"

#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
const char* __stdcall sub_006B013E_FormatAddress(unsigned int nAddress); // 0x006B013E
void __cdecl sub_00410660_LogWritePrefixed(const char* szCategory, const char* szFormat, ...); // 0x00410660
void __stdcall sub_006C0770_BanClient(int nClient, const char* szFile, int nLine); // 0x006C0770
extern const char gszHack_006FC4A8[]; // 0x006FC4A8

// 0x006C0800
int __fastcall sub_006C0800_BanByAddress(D2QueueServerStrc* pServer, unsigned int* pAddress, const char* szFile, int nLine)
{
    unsigned int nAddress = *pAddress;
    unsigned int nBucket = pServer->nMask & nAddress;
    EnterCriticalSection(&pServer->tAddressLock);
    D2QClientStrc* pNode = pServer->ppAddressBuckets[nBucket];
    while (pNode && pNode->nAddress != nAddress)
        pNode = pNode->pNextByAddress;
    LeaveCriticalSection(&pServer->tAddressLock);
    if (pNode && !pServer->sub_006BF660_CheckAddress(pNode->nAddress))
    {
        sub_00410660_LogWritePrefixed(gszHack_006FC4A8, "[HACKLIST]  Client %d at %s banned via QSBanByAddr()", pNode->iId, sub_006B013E_FormatAddress(*pAddress));
        sub_006C0770_BanClient(pNode->iId, gszServerFile_006FC460, 0x584);
    }
    return 1;
}
