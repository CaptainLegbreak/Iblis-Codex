struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;

struct D2PetDataStrc
{
    unsigned char nFlags;
    char unk0x01[0x03];
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

struct D2PetTypeTxt
{
    unsigned int dwHcIdx;
    unsigned char nPetFlags[4];
    char unk0x08[0xD8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBE8];
    D2PetTypeTxt* pPetTypeTxt;
    char unk0xBEC[0x04];
    int nPetTypeTxtRecordCount;
};

#define UNIT_MONSTER 1
#define PETTYPE_HIREABLE 7

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" const char gszPlayerPetsSourceFile[];                                                            // 0x006E15D8

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
void __fastcall sub_6FC7D260(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4);                 // 0x005750E0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053CDF0

inline D2PetListStrc* PLAYERPETS_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

// 0x00575590
static void __stdcall sub_00575590_RemoveDeadPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2PlayerPetStrc* pPlayerPets)
{
    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList && nPetType != PETTYPE_HIREABLE)
        {
            D2PetDataStrc* pPetData = pPetList->pPetData;
            while (pPetData)
            {
                D2PetDataStrc* pNext = pPetData->pNext;
                D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
                if (!pPet || SUNIT_IsDead(pPet))
                {
                    sub_6FC7D260(pGame, pPlayer, pPetData->nUnitGUID, 0);
                }
                pPetData = pNext;
            }
        }
    }
}

// 0x00575630
void __fastcall sub_6FC7E640(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pPlayer)->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    sub_00575590_RemoveDeadPets(pGame, pPlayer, pPlayerPets);

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, gszPlayerPetsSourceFile, 1411);
    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
            if (pPetTypeTxtRecord && pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[2])
            {
                for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
                {
                    if (!(pPetData->nFlags & 1))
                    {
                        D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
                        if (pPet)
                        {
                            sub_6FC3E200(pClient, pPet);
                        }
                    }
                }
            }
        }
    }
}
