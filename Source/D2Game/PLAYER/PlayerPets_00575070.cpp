#include "D2Game.h"

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
    unsigned char petInfo[0x0C];
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};

struct D2PlayerDataStrc
{
    unsigned char unk_00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};

struct D2DataTablesStrc
{
    unsigned char unk_000[0xBF0];
    int nPetTypeTxtRecordCount;
};
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

static __forceinline D2PetListStrc* PLAYERPETS_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType < 0 || nPetType >= sgptDataTable->nPetTypeTxtRecordCount)
    {
        return 0;
    }
    return &pPlayerPets->pPetList[nPetType];
}

// 0x00575070
int __fastcall sub_00575070_HasPetOfType7(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerData->pPlayerPets)
    {
        return 0;
    }

    SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlayerPets.cpp", 0x66E);
    D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, 7);
    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID))
        {
            return 1;
        }
    }
    return 0;
}
