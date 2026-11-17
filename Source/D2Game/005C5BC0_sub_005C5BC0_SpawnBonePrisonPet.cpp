struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2PathRecordStrc;
struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2PathRecordStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
};
struct D2CoordStrc
{
    int nX;
    int nY;
};
struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};
struct D2SkillsTxt
{
    char unk0x000[0xBE];
    unsigned char nPetType;
    char unk0x0BF[0x01];
    unsigned int dwPetMax;
    char unk0x0C4[0x178];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x4C];
    int nPetTypeTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int gnBonePrisonOffsetX_006E304C[12];                                                          // 0x006E304C
extern const int gnBonePrisonOffsetY_006E307C[12];                                                          // 0x006E307C
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg);            // 0x0056D940
int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                 // 0x0061AB00
void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850
void __fastcall sub_6FC40280(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4);                          // 0x005B1990
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                         // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                  // 0x00451F50
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);        // 0x0058F100
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                      // 0x00621CE0
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2);                                     // 0x0064FDC0
void __stdcall sub_006488A0_SetDirection(D2PathRecordStrc* pPath, int nDirection);                                 // 0x006488A0
int __stdcall sub_006488C0_PathGetX(D2PathRecordStrc* pPath);                                                      // 0x006488C0
int __stdcall sub_00648900_PathGetY(D2PathRecordStrc* pPath);                                                      // 0x00648900

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? sub_00648900_PathGetY(pUnit->pDynamicPath) : 0;
}

// 0x005C5BC0
static D2UnitStrc* __stdcall sub_005C5BC0_SpawnBonePrisonPet(D2GameStrc* pGame, int nSkillId, D2UnitStrc* pUnit, int nX, int nY, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (DUNGEON_IsRoomInTown(D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY)))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.dwFlags = 9;
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = nX;
    summonArg.pPosition.nY = nY;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 15, 0);
    sub_6FC40280(pGame, pPet, 0, 9);
    return pPet;
}

// build: context SKILLS_SrvDo062_BonePrison
int __fastcall SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pOwner = 0;
    for (int i = 0; i < 12; ++i)
    {
        D2UnitStrc* pPet = sub_005C5BC0_SpawnBonePrisonPet(pGame, nSkillId, pUnit, nTargetX + gnBonePrisonOffsetX_006E304C[i], nTargetY + gnBonePrisonOffsetY_006E307C[i], nSkillLevel);
        if (pPet)
        {
            if (!pOwner)
            {
                pOwner = pPet;
                AIGENERAL_SetOwnerData(pGame, pPet, sub_00451F50_GetUnitGUID(pUnit), sub_0044BE50_GetUnitTypeOrInvalid(pUnit), 0, 1);
            }
            else
            {
                AIGENERAL_SetOwnerData(pGame, pPet, pOwner->dwUnitId, pOwner->dwUnitType, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pOwner, pPet);
            }

            UNITS_StoreOwner(pPet, pUnit);
            sub_006488A0_SetDirection(pPet->pDynamicPath, PATH_ComputeDirection(UNITS_GetXPositionInline(pPet), UNITS_GetYPositionInline(pPet), nTargetX, nTargetY));
        }
    }

    return 1;
}

#include "gen/data/Source/D2Game/005C5BC0_sub_005C5BC0_SpawnBonePrisonPet.inc"
