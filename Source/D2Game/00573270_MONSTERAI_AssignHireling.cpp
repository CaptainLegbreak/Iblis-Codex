struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2HirelingTxt;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x04];
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
    char unk0xC8[0x08];
    int dwNodeIndex;
};

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short wPad;
    unsigned int dwSeed;
};

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int unk0x34[2];
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    int wName;
    int nHirelingId;
};

extern "C" const char gszMonsterAISourceFile[];                                                             // 0x006E1560
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short a2, int a3);   // 0x0053E0E0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignment, int a3);                    // 0x005543B0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int a3);           // 0x005726C0
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMerc, int nLevel); // 0x00572840
D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitGUID, int a4);        // 0x005750E0
void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo); // 0x00575E90
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bGuard, int a6); // 0x0058F030
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int a4); // 0x005A4850
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nVersion, unsigned short nMercName);      // 0x00663750
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pPlayer, unsigned int nSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline void MONSTER_SetComponent(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    if (sub_0044BE50(pUnit) == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nComponent[nComponent] = nValue;
        }
    }
}

// 0x00573270
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nSaveVersion, D2MercDataStrc* pMercData, int bDead)
{
    if (!pPlayer || !pUnit || !pMercData || pPlayer->dwUnitType != 0)
    {
        return;
    }

    pUnit->dwFlags |= 0x4020200;

    SUNIT_SetAlignment(pUnit, 2, 0);

    if (!bDead)
    {
        D2GAME_UpdateSummonAI_6FC401F0(pGame, pUnit, 0, pPlayer->dwNodeIndex);
    }

    D2UnitStrc* pPet = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1);
    if (pPet)
    {
        D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(SUNIT_GetClientFromPlayer(pPlayer, gszMonsterAISourceFile, 0x52), 0xFFFF, 0);

        AIGENERAL_SetOwnerData(pGame, pPet, -1, 1, 0, 0);
        PLAYERPETS_RemovePet(pGame, pPlayer, UNITS_GetUnitId(pPet), 0);
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPet), 1, UNITS_GetUnitId(pPet));
        SUNIT_RemoveUnit(pGame, pPet);
    }

    D2HirelingInitStrc hirelingInit;
    D2PetInfoStrc petInfo;
    petInfo.nSeed = pMercData->dwSeed;
    petInfo.wName = pMercData->nMercName;
    const int nAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, pMercData->nMercName);
    const int nDifficulty = pGame->nDifficulty;
    if (!MONSTERS_HirelingInit(pGame->bExpansion, pPlayer, pMercData->dwSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    petInfo.nHirelingId = hirelingInit.nId;
    PLAYERPETS_AddPetWithInfo(pGame, pPlayer, pUnit, 7, &petInfo);

    pUnit->dwFlags |= 0x80000000;
    AIGENERAL_SetOwnerData(pGame, pUnit, pPlayer->dwUnitId, sub_0044BE50(pPlayer), 0, 0);

    if (nSaveVersion == 0xFFFF)
    {
        const int nLevel = hirelingInit.nLevel;
        const int nHirelingId = (unsigned short)hirelingInit.nId;
        if (!DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, hirelingInit.nLevel))
        {
            return;
        }

        STATLIST_SetUnitStat(pUnit, 13, hirelingInit.nExperience, 0);
        MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pUnit, nLevel);
        MONSTERAI_SendMercStats(pGame, pPlayer, 1);
    }

    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x13, 0);

    MONSTER_SetComponent(pUnit, 0, 0);
    MONSTER_SetComponent(pUnit, 5, 0);
    MONSTER_SetComponent(pUnit, 6, 0);
    MONSTER_SetComponent(pUnit, 7, 0);
    MONSTER_SetComponent(pUnit, 1, 0);
}
