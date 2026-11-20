#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

struct D2SeedStrc;
struct D2MonsterDataStrc;
struct D2MissilesTxt;


void __fastcall QUESTSFX_Bloodraven(D2GameStrc*, D2UnitStrc*); // 0x005DFD90
void __fastcall QUESTSFX_SpawnMephistoDeathControlMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFDB0
void __fastcall QUESTSFX_Andariel(D2GameStrc*, D2UnitStrc*); // 0x005DFE00
void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFE20
void __fastcall QUESTSFX_Izual(D2GameStrc*, D2UnitStrc*); // 0x005E0020
void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc*, D2UnitStrc*); // 0x005E0040
void __fastcall sub_005E0060_QuestsFxEmpty(D2GameStrc*, D2UnitStrc*); // 0x005E0060
void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc*, D2UnitStrc*); // 0x005E0070


struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned short nFlags;
};

struct D2MissilesTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
    char unk0x08[0x1A4 - 0x08];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall sub_6FD11420(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel, int a6, int a7, int nX, int nY, int a10); // 0x0056ECB0
int __fastcall sub_005A0180_CheckMonsterFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

// 0x005A3250
void __fastcall MONSTERUNIQUE_QuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    switch (!pUnit ? -1 : (unsigned int)pUnit->dwClassId)
    {
    case 156:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Andariel(pGame, pUnit);
        break;
    case 229:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnRadamentDeathMissile(pGame, pUnit);
        break;
    case 242:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnMephistoDeathControlMissile(pGame, pUnit);
        break;
    case 256:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Izual(pGame, pUnit);
        break;
    case 267:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Bloodraven(pGame, pUnit);
        break;
    case 540:
    case 541:
    case 542:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) sub_005E0060_QuestsFxEmpty(pGame, pUnit);
        break;
    case 479:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_ShenkTheOverseer(pGame, pUnit);
        break;
    case 704:
    case 705:
    case 709:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_UberPrimeEvil(pGame, pUnit);
        break;
    }
}

static __forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static int sub_005A3610_IsWideMissile(int nMissileId)
{
    if (nMissileId < 0x3F)
    {
        return 0;
    }
    if (nMissileId > 0x42)
    {
        return 0;
    }
    return 1;
}

// 0x005A3610
void __fastcall sub_005A3610_SpawnSideMissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, int nArg)
{
    if (!nArg || !pMissile || pMissile->dwUnitType != 3)
    {
        return;
    }

    const int nMissileId = pMissile->dwClassId;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_005A0180_CheckMonsterFlag(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pOwner);
    int nY;
    if (!pTarget)
    {
        nArg = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nArg = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 0x53454953);
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDeltaX = CLIENTS_GetUnitX(pOwner) - nArg;
    int nDeltaY = CLIENTS_GetUnitY(pOwner) - nY;
    if (nDeltaX < 0)
    {
        nDeltaX = -1;
    }
    else if (nDeltaX > 0)
    {
        nDeltaX = 1;
    }

    if (nDeltaY < 0)
    {
        nDeltaY = -1;
    }
    else if (nDeltaY > 0)
    {
        nDeltaY = 1;
    }

    if (sub_005A3610_IsWideMissile(nMissileId))
    {
        nDeltaY = 0;
        nDeltaX = 0;
    }

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nFlags |= 0x80;
        }
    }

    sub_6FD11420(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg - nDeltaY, nY + nDeltaX, 0);
    sub_6FD11420(pGame, nMissileId, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), 0, 0, nArg + nDeltaY, nY - nDeltaX, 0);

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nFlags &= ~0x80;
        }
    }
}
