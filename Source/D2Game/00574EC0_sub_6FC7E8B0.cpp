struct D2GameStrc;
struct D2UnitStrc;

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
    char unk0x08[0x0C];
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nPetMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBF0];
    int nPetTypeTxtRecordCount;
};

#define UNIT_MONSTER 1

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

static __forceinline D2PetListStrc* sub_00574EC0_GetPetList(D2PlayerDataStrc* pPlayerData, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
        if (pPlayerPets)
        {
            return &pPlayerPets->pPetList[nPetType];
        }
    }
    return 0;
}

// 0x00574EC0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PetListStrc* pPetList = sub_00574EC0_GetPetList(pPlayerData, nPetType);
        if (pPetList)
        {
            D2PetDataStrc* pPetData;
            for (pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (a4 || !(pPetData->nFlags & 1))
                {
                    break;
                }
            }

            if (pPetData)
            {
                return SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
            }
        }
    }

    return 0;
}
