#include "D2Game.h"
#include "D2Structs.h"


struct D2PlayerDataStrc
{
    char unk0x00[0x38];
    D2PlayerListStrc* pPlayerList;
    char unk0x3C[0x124];
    int dwHostileDelay;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x8B_6FC3F810(D2ClientStrc* pClient, int nUnitGUID, unsigned char nPartyState); // 0x0053DDC0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall PLAYERLIST_IterateCallback_InitializePlayerRelation(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B540
void __fastcall sub_0055B780_FreePlayerListCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B780

static __forceinline D2PlayerListStrc* sub_0055B110(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    const int nUnitGUID = !pPlayer2 ? -1 : pPlayer2->dwUnitId;
    if (pPlayer1 != pPlayer2)
    {
        for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
        {
            if (pPlayerList->nUnitGUID == nUnitGUID)
            {
                return pPlayerList;
            }
        }
    }

    return 0;
}

// 0x0055B350
unsigned short __fastcall PLAYERLIST_GetFlags(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (pPlayer1 != pPlayer2 && pPlayerList)
    {
        return pPlayerList->dwFlags;
    }

    return 0;
}

// 0x0055B3F0
short __fastcall PLAYERLIST_GetPartyState(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2)
    {
        return 1;
    }

    if (pPlayerList)
    {
        return pPlayerList->field_C;
    }

    return 0;
}

// 0x0055B440
void __fastcall PLAYERLIST_SendPartyState(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if ((!pPlayer1 ? -1 : pPlayer1->dwUnitId) != (!pPlayer2 ? -1 : pPlayer2->dwUnitId) && pPlayerList)
    {
        D2GAME_PACKETS_SendPacket0x8B_6FC3F810(SUNIT_GetClientFromPlayer(pPlayer1, ".\\UNIT\\PlayerList.cpp", 0x10B), !pPlayer2 ? -1 : pPlayer2->dwUnitId, pPlayerList->field_C);
    }
}

// 0x0055B620
void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pPlayer, 0x14F);
    SUNIT_IterateLivingPlayers(pGame, PLAYERLIST_IterateCallback_InitializePlayerRelation, pPlayer);
}

// 0x0055B6C0
int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    if (!pPlayer2)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
        if (pPlayerData)
        {
            return pPlayerData->dwHostileDelay;
        }
    }

    D2PlayerListStrc* pPlayerList = sub_0055B110(pPlayer1, pPlayer2);
    if (!pPlayerList)
    {
        return 0;
    }

    return pPlayerList->field_8;
}

// 0x0055B790
void __fastcall PLAYERLIST_FreePlayerLists(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    SUNIT_IterateLivingPlayers(pGame, sub_0055B780_FreePlayerListCallback, pPlayer);

    D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList;
    while (pPlayerList)
    {
        D2PlayerListStrc* pNext = pPlayerList->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerList, ".\\UNIT\\PlayerList.cpp", 0x4E, 0);
        pPlayerList = pNext;
    }

    pPlayerData->pPlayerList = 0;
}
