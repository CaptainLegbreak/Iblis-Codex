#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"

#define UNIT_MONSTER 1
struct D2MissilesTxt;
struct D2GSPacketSrv73;
struct D2MonUModTxt;
struct D2MonsterDataStrc;
struct D2MonStatsTxt;
struct Data005A0120;
struct Unit005A0120;
struct Data005A0180;
struct Unit005A0180;
struct Data004AC780;
struct Unit004AC780;
struct Data005A01E0;
struct Unit005A01E0;
struct Data005A0200;
struct Unit005A0200;
union D2SeedStrc;

struct D2MissilesTxt { int unk00; unsigned int dwMissileFlags; char unk08[0x19C]; };

#pragma pack(push, 1)
struct D2GSPacketSrv73 { unsigned char nHeader; int unk01; unsigned short nMissileId; int nX; int nY; int nFirstX; int nFirstY; unsigned short nCurrentFrame; unsigned char nUnitType; int nUnitGUID; unsigned char nLevel; unsigned char nPierce; };

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gnMissileFlag_006CE27C; // 0x006CE27C

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __stdcall sub_0064A3E0_GetMissileId(D2UnitStrc*); // 0x0064A3E0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __fastcall D2GAME_PACKETS_SendPacket0x73(D2ClientStrc*, D2GSPacketSrv73*); // 0x0053DA10

struct D2MonStatsTxt
{
    char unk0x00[0x1C];
    short wMonType;
    char unk0x1E[0x18A];
};

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

struct Data005A0120 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwField1C;
};

struct Unit005A0120 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0120* pData;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall sub_005A00F0_GetMonUModConstant(int nIndex); // 0x005A00F0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct Data005A0180 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned short wUnknown14;
    unsigned short wFlags16;
};

struct Unit005A0180 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0180* pData;
};

#pragma pack(push, 1)
struct Data004AC780 { unsigned char bUnknown00[0x14]; unsigned short wValue14; };

#pragma pack(pop)
struct Unit004AC780 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC780* pData;
};

struct Data005A01E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned short wUnknown24;
    short sValue26;
};

struct Unit005A01E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A01E0* pData;
};

#pragma pack(push, 1)
struct Data005A0200 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };

#pragma pack(pop)
struct Unit005A0200 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0200* pData;
};
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

inline D2MissilesTxt* GetMissilesTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}

// 0x005A0030
int __fastcall sub_005A0030_GetMonLvlTxtRecordCount()
{
    return sgptDataTables->nMonLvlTxtRecordCount;
}

// 0x005A0040
D2MonUModTxt* __fastcall MONSTERUNIQUE_GetMonUModTxtRecord(int nUMod)
{
    if (nUMod >= sgptDataTables->nMonUModTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMonUModTxt[nUMod];
}

// 0x005A0060
int __fastcall sub_005A0060_GetMonUModTxtRecordCount()
{
    return sgptDataTables->nMonUModTxtRecordCount;
}

static inline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005A0220
static inline int sub_005A0220_GetMonsterField18(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }

    return pMonsterData->dwDurielFlag;
}

// 0x005A0240
static inline void sub_005A0240_SetMonsterField18(D2UnitStrc* pUnit, int nValue)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->dwDurielFlag = nValue;
    }
}

int __fastcall sub_M117_Emit_005A0220(D2UnitStrc* pUnit, int nValue)
{
    sub_005A0240_SetMonsterField18(pUnit, nValue);
    return sub_005A0220_GetMonsterField18(pUnit);
}

static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005A0070
int __fastcall sub_005A0070_MONSTERUNIQUE_CheckMonType(D2UnitStrc* pUnit, int nMonType)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType >= 0 && pMonStatsTxtRecord->wMonType < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType >= 0 && nMonType < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return gdwBitMasks[pMonStatsTxtRecord->wMonType & 31] & sgptDataTables->pMonTypeNest[(pMonStatsTxtRecord->wMonType >> 5) + nMonType * sgptDataTables->nMonTypeIndex];
    }

    return 0;
}

// 0x005A00F0
int __fastcall sub_005A00F0_GetMonUModConstant(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nMonUModTxtRecordCount)
    {
        D2MonUModTxt* pMonUModTxtRecord = &sgptDataTables->pMonUModTxt[nIndex];
        if (pMonUModTxtRecord)
        {
            return pMonUModTxtRecord->dwConstants;
        }
    }

    return 0;
}

// 0x005A0120
extern "C" __declspec(dllexport) unsigned int* __fastcall sub_005A0120(Unit005A0120* pUnit) {
    Data005A0120* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return &pData->dwField1C;
}

// 0x005A0140
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 5382;
    }
    return pMonsterData->wNameSeed;
}

// 0x005A0D20
static void sub_005A0D20_AddLifePercent(D2UnitStrc* pUnit, int nPercentage)
{
    int nHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nBonus;
    if (nHitpoints > 0x100000)
    {
        if (100 > (nHitpoints >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nPercentage * (nHitpoints / 100);
        }
    }
    else if (nPercentage > 0x10000)
    {
        if (100 > (nPercentage >> 4))
        {
            nBonus = (int)(nHitpoints * (__int64)nPercentage / 100);
        }
        else
        {
            nBonus = nHitpoints * (nPercentage / 100);
        }
    }
    else
    {
        nBonus = nPercentage * nHitpoints / 100;
    }

    nHitpoints += nBonus;
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
}

// 0x005A0160
extern "C" __declspec(dllexport) void __fastcall sub_005A0160(Unit004AC780* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue14 = wValue;
    }
}

// 0x005A0180
extern "C" __declspec(dllexport) int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask) {
    Data005A0180* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags16 & wMask) != 0;
}

// 0x005A01E0
extern "C" __declspec(dllexport) short __fastcall sub_005A01E0(Unit005A01E0* pUnit) {
    Data005A01E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return -1;
    }
    return pData->sValue26;
}

// 0x005A0200
extern "C" __declspec(dllexport) void __fastcall sub_005A0200(Unit005A0200* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->wValue26 = wValue;
    }
}

// 0x005A0260
extern "C" __declspec(dllexport) int __fastcall sub_005A0260(const char* pText) {
    int nLength;
    for (nLength = 0; nLength < 9; nLength++, pText++) {
        if (!*pText) {
            return nLength;
        }
    }
    return 9;
}

// 0x005A03A0
int __fastcall MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonsterDataStrc* pMonsterData = (nType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData || !(pMonsterData->nTypeFlag & MONTYPEFLAG_SUPERUNIQUE))
    {
        return -1;
    }

    return sub_005A01E0((Unit005A01E0*)pUnit);
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005A0CE0
void __fastcall MONSTERUNIQUE_UMod1_RandomName(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && bUnique)
    {
        const unsigned int nRand = SEED_RollRandomNumber(&pUnit->pSeed);
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->wNameSeed = nRand;
        }
    }
}

// 0x005A0DC0
void __fastcall MONSTERUNIQUE_UMod2_HealthBonus(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    const unsigned char nDifficulty = pGame->nDifficulty;
    if (nDifficulty >= 3)
    {
        return;
    }

    if (!bUnique)
    {
        sub_005A0D20_AddLifePercent(pUnit, sub_005A00F0_GetMonUModConstant(nDifficulty + 1));
    }
    else
    {
        int nIndex;
        if (sub_005A0180((Unit005A0180*)pUnit, 4))
        {
            nIndex = nDifficulty + 4;
        }
        else
        {
            nIndex = nDifficulty + 7;
        }
        sub_005A0D20_AddLifePercent(pUnit, sub_005A00F0_GetMonUModConstant(nIndex));
        STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, 0, 0);
    }
}

// 0x005A0E40
void __fastcall sub_005A0E40_IncreaseMonsterLevelAndExperience(D2UnitStrc* pUnit, void* unused, void* context)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nLevel + 3, 0);
        const int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, 5 * nExperience, 0);
    }
}
