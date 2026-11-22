#include "D2GameTypes.h"

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char unk0x008[0x2];
    unsigned char nFlags0x0A;
    char unk0x00B[0x4A1];
    D2ClientStrc* pServerNext;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern int gbClientListInitialized;                                                                // 0x008846D8
extern D2CriticalSectionStrc gClientListLock;                                                      // 0x008846A8
extern D2ClientStrc* gpClientList[256];                                                            // 0x008842A8

// 0x005377B0
int __cdecl sub_005377B0_CountFlaggedClients()
{
    int nCount = 0;
    if (!gbClientListInitialized)
    {
        return 0;
    }
    EnterCriticalSection(&gClientListLock);
    for (int i = 0; i < 256; ++i)
    {
        for (D2ClientStrc* pClient = gpClientList[i]; pClient; pClient = pClient->pServerNext)
        {
            if (pClient->nFlags0x0A & 0x20)
            {
                ++nCount;
            }
        }
    }
    LeaveCriticalSection(&gClientListLock);
    return nCount;
}
