#include "D2Game.h"
#include "D2Structs.h"

#define STATE_PLAYERBODY 7
struct D2PlayerListStrc;
struct D2PlayerDataStrc;


struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x38];
    D2PlayerListStrc* pPlayerList;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PLAYERLIST_IterateCallback_FreePlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B1E0

// 0x0055B110
static __declspec(noinline) D2PlayerListStrc* sub_0055B110(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
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

// 0x0055B140
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    if (pPlayer1 == pPlayer2 || STATES_CheckState(pPlayer2, STATE_PLAYERBODY) || STATES_CheckState(pPlayer1, STATE_PLAYERBODY))
    {
        return;
    }

    if (sub_0055B110(pPlayer1, pPlayer2))
    {
        return;
    }

    D2PlayerListStrc* pPlayerList = (D2PlayerListStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlayerListStrc), ".\\UNIT\\PlayerList.cpp", 109, 0);
    memset(pPlayerList, 0, sizeof(D2PlayerListStrc));

    pPlayerList->nUnitGUID = !pPlayer2 ? -1 : pPlayer2->dwUnitId;
    pPlayerList->field_8 = 0;
    pPlayerList->field_C = SUNIT_GetPartyId(pPlayer2) != -1;
    pPlayerList->pNext = pPlayerData->pPlayerList;
    pPlayerData->pPlayerList = pPlayerList;
}

// 0x0055B780
void __fastcall sub_0055B780_FreePlayerListCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    PLAYERLIST_IterateCallback_FreePlayerList(pGame, pPlayer, pArg);
}
