struct D2UnitStrc;

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
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
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBF0];
    int nPetTypeTxtRecordCount;
};

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

// build: context PLAYERPETS_GetPetListFromPetType
static __forceinline D2PetListStrc* PLAYERPETS_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

static __declspec(noinline) int PLAYERPETS_GetFirstPetGUID(D2UnitStrc* pPlayer, int nPetType);

// 0x005747B0
static int PLAYERPETS_GetFirstPetGUID(D2UnitStrc* pPlayer, int nPetType)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), 0x171);
        exit(-1);
    }

    if (!pPlayerData->pPlayerPets)
    {
        return -1;
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerData->pPlayerPets, nPetType);
    if (!pPetList)
    {
        return -1;
    }

    if (!pPetList->pPetData)
    {
        return -1;
    }

    return pPetList->pPetData->nUnitGUID;
}

// build: context sub_005747B0_Shim

// calling-convention shim (not game code)
int __fastcall sub_005747B0_Shim(D2UnitStrc* pPlayer, int nPetType)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    return PLAYERPETS_GetFirstPetGUID(pPlayer, nPetType) + (int)pPlayerData + nPetType;
}
