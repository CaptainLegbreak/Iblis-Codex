#include "D2Net.h"

#include "D2GameServer.h"

struct D2NetPacketRecStrc;

struct D2NetLockStrc;

struct D2Net52BE10Strc;

struct D2ServerCallbackFunctions;

extern int gnConnectionMode; // 0x00882D10

struct D2NetLockStrc
{
    D2CriticalSectionStrc tLock;

    void Lock(int nUnused);
    void Unlock(int nUnused);
};

struct D2Net52BE10Strc
{
    char unk0x00[0xD0];
    char aData[4];
};

typedef const char* (__stdcall* FnLoadComplete)();

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern char gszEmptyLoadComplete[]; // 0x006E0498

extern int gnGamesGUIDs[1024]; // 0x00882D38

extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50

extern int gbD2ServerCallbackFunctionsInitialized; // 0x00883D54

// 0x0052B7E0
int __fastcall NET_IsLocalConnection()
{
    if (gnConnectionMode == 1)
    {
        return 1;
    }
    return gnConnectionMode == 2;
}

// 0x0052B810
void __fastcall NET_SetConnectionMode(int nConnectionMode)
{
    gnConnectionMode = nConnectionMode;
}

// 0x0052B820
int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize)
{
    int nResult;

    EnterCriticalSection(pCriticalSection);

    D2NetPacketRecStrc* pPacket = *ppPacketList;
    if (pPacket && (gnConnectionMode != 2 || GetTickCount() - pPacket->dwTickCount >= 500))
    {
        memcpy(pBuffer, pPacket, nBufferSize < MAX_MSG_SIZE ? nBufferSize : MAX_MSG_SIZE);
        nResult = pPacket->nPacketSize;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, ".\\SRC\\D2Net.cpp", 0x46, 0);
    }
    else
    {
        nResult = -1;
    }

    LeaveCriticalSection(pCriticalSection);
    return nResult;
}

// 0x0052B8F0
void __cdecl sub_0052B8F0_Nop()
{
}

int gnConnectionMode; // 0x00882D10

// 0x0052B900
void __cdecl sub_0052B900_Nop()
{
}

// 0x0052BDD0
bool __stdcall sub_0052BDD0_AlwaysTrue(int nUnused)
{
    return true;
}

// 0x0052BDE0
void D2NetLockStrc::Lock(int nUnused)
{
    EnterCriticalSection(&tLock);
}

// 0x0052BDF0
void D2NetLockStrc::Unlock(int nUnused)
{
    LeaveCriticalSection(&tLock);
}

// 0x0052BE00
unsigned int __fastcall sub_0052BE00_GetBits12(unsigned int nValue)
{
    return (nValue >> 12) & 7;
}

// 0x0052BE10
char* __fastcall sub_0052BE10_GetField0D0(D2Net52BE10Strc* pRecord)
{
    return pRecord->aData;
}

// 0x0052BE40
void __stdcall NET_DefaultLeaveGame(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
}

// 0x0052BE60
void __stdcall NET_DefaultSaveDatabaseCharacter(int a1, int a2, int a3, int a4)
{
}

// 0x0052BE70
void __cdecl NET_DefaultServerLogMessage()
{
}

// 0x0052BE80
void __stdcall NET_DefaultEnterGame(int a1, int a2, int a3)
{
}

// 0x0052BE90
int __stdcall NET_DefaultFindPlayerToken(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 0;
}

// 0x0052BED0
void __stdcall NET_DefaultUpdateCharacterLadder(int a1, int a2, int a3, int a4, int a5)
{
}

// 0x0052BFE0
int __fastcall GAME_GetGamesCount()
{
    int nResult = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] != 0 && gnGamesGUIDs[i] != -1)
        {
            ++nResult;
        }
    }
    return nResult;
}

// 0x0052B8B0
int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList)
{
    EnterCriticalSection(pCriticalSection);

    while (*ppPacketList)
    {
        D2NetPacketRecStrc* pPacket = *ppPacketList;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, ".\\SRC\\D2Net.cpp", 0x5D, 0);
    }

    LeaveCriticalSection(pCriticalSection);
    return 1;
}

// 0x0052B800
int __fastcall NET_IsSimulatedLagConnection()
{
    return gnConnectionMode == 2;
}
