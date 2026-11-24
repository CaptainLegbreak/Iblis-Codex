#include "D2BNClient.h"

struct D2CriticalSectionStrc;
struct D2BnStateStrc;
struct FindSignatureTag;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

struct FindSignatureTag
{
    unsigned int dwState[5];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern D2CriticalSectionStrc gtMessageLock; // 0x00882004
extern int ganSlotArrayB[94]; // 0x008822A8

void* gpBnStateArg; // 0x00882000

D2CriticalSectionStrc gtMessageLock; // 0x00882004

int gnBnState; // 0x0088201C

// 0x005201E0
void __cdecl sub_005201E0_InitMessageQueue()
{
// build: symbol ?gpMessageHead@* 0x00882020
    gpMessageHead = 0;
// build: symbol ?gpMessageTail@* 0x00882024
    gpMessageTail = 0;
    gnBnState = 0;
    InitializeCriticalSection(&gtMessageLock);
}

// 0x005205F0
int __fastcall sub_005205F0_GetState(D2BnStateStrc* pState)
{
    EnterCriticalSection(&gtMessageLock);
    pState->nState = gnBnState;
    pState->pArg = gpBnStateArg;
    if (gnBnState == 0x1B)
// build: symbol ?gszEmptyStateText@* 0x00881F80
        pState->pArg = gszEmptyStateText;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x00520200
void __cdecl sub_00520200_DeleteQueueLock()
{
    DeleteCriticalSection(&gtMessageLock);
}

// 0x00520A80
static inline int BNDOWNLOAD_CheckStringBlock(const char* pBuffer, unsigned int nPos, unsigned int nCount, unsigned int nSize)
{
    if (nSize < nPos + nCount)
    {
        return 0;
    }
    if (!nCount)
    {
        return 1;
    }
    if (pBuffer[nSize - 1])
    {
        return 0;
    }
    const unsigned int nEnd = nSize - 1;
    unsigned int nFound = 0;
    for (unsigned int i = nPos; i < nEnd; ++i)
    {
        if (!pBuffer[i])
        {
            ++nFound;
        }
    }
    return nFound == nCount - 1;
}

// 0x00520C30
void __fastcall sub_00520C30_SetSlot(unsigned char nIndex, int nValue)
{
    ganSlotArrayB[nIndex] = nValue;
}

int __fastcall sub_M119_Emit_00520A80(int nPos, int nCount, int nSize)
{
    return BNDOWNLOAD_CheckStringBlock((const char*)nSize, nPos, nCount, nSize + 3);
}
