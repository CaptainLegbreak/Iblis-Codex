struct D2UnitStrc;
struct D2PetDataStrc;

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
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBF0];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

// 0x00574810
int __fastcall sub_00574810_GetPetMaxFromPetType(D2UnitStrc* pPlayer, int nPetType)
{
    int nMax = 0;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData && pPlayerData->pPlayerPets && nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        D2PetListStrc* pPetList = &pPlayerData->pPlayerPets->pPetList[nPetType];
        if (pPetList)
        {
            nMax = pPetList->nMax;
        }
    }
    return nMax;
}
