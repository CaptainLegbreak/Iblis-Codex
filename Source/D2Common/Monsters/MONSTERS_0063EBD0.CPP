#include "D2Common.h"
#define UNIT_MONSTER 1
struct D2MonsterDataStrc;
struct D2ItemsTxt;
struct D2MonStatsTxt;
struct D2DifficultyStatStrc;
struct D2SeedStrc;
struct D2CoordStrc;
struct D2StaticPathStrc;

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    unsigned char unk_08[0xC];
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x8];
    D2SeedStrc pSeed;
    char unk0x28[4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2ItemsTxt
{
    unsigned char pad00[0x12F];
    unsigned char nLightRadius;
};

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    unsigned char unk_04[0x48];
    unsigned char nSpecial;
    char unk_4D[0x5D];
    short nLevel;
    unsigned char unk_AC[0xFC];
};

struct D2DifficultyStatStrc { int stat; int numerator1; int denominator1; int numerator2; int denominator2; };

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int monsterId); // 0x00451F80
int __fastcall DATATBLS_ApplyRatio(int value, int numerator, int denominator); // 0x00483360
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* unit, int stat, int layer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* unit, int stat, int value, int layer); // 0x00627260
extern const D2DifficultyStatStrc gaDifficultyStats_006EA9F0[3]; // 0x006EA9F0

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nTargetX;
    int nTargetY;
    D2CoordStrc tGameCoords;
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nChainSteps); // 0x0054DA60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pChainId, int* pMissileOffset); // 0x006510C0

// 0x0063EBD0
unsigned char __stdcall sub_0063EBD0_GetLightRadius(D2UnitStrc* pMonster)
{
    if (pMonster && (!pMonster ? 6 : pMonster->dwUnitType) == 1)
    {
        unsigned char nMaxLightRadius = 0;
        unsigned char* pComponents = pMonster && pMonster->dwUnitType == 1 && pMonster->pMonsterData ? pMonster->pMonsterData->nComponent : 0;
        if (!pComponents)
            return 0;
        for (int i = 0; i < 16; ++i)
        {
            unsigned int nCode = D2Common_11069(pMonster, i, pComponents[i]);
            if (nCode && nCode != ' til' && nCode != ' dem' && nCode != ' yvh')
            {
                int nItemId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(nCode, &nItemId);
                if (pItemsTxtRecord && pItemsTxtRecord->nLightRadius > nMaxLightRadius)
                    nMaxLightRadius = pItemsTxtRecord->nLightRadius;
            }
        }
        return nMaxLightRadius;
    }
    return 0;
}

// 0x0063EEF0
void __stdcall sub_0063EEF0_AdjustMonsterStats(D2UnitStrc* unit, int mode, unsigned char difficulty)
{
    if (mode || !difficulty)
        return;
    const int nType = unit ? unit->dwUnitType : 6;
    if (nType != 1)
        return;
    D2MonStatsTxt* record = DATATBLS_GetMonStatsTxtRecord(unit->dwClassId);
    if (!record || record->nSpecial == 1)
        return;
    const D2DifficultyStatStrc* p = gaDifficultyStats_006EA9F0;
    for (int i = 0; i < 3; ++i, ++p)
    {
        int value = STATLIST_UnitGetStatValue(unit, p->stat, 0);
        int numerator;
        int denominator;
        if (difficulty == 1)
        {
            numerator = p->numerator1;
            denominator = p->denominator1;
        }
        else
        {
            numerator = p->numerator2;
            denominator = p->denominator2;
        }
        STATLIST_SetUnitStat(unit, p->stat, DATATBLS_ApplyRatio(value, numerator, denominator), 0);
    }
    STATLIST_SetUnitStat(unit, 12, record->nLevel + 25 * difficulty, 0);
}

#include "gen/data/Source/D2Common/Monsters/MONSTERS_0063EBD0.inc"

__forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

__forceinline int MONSTERS_GetBaseIdFromMonsterIdInline(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }

    return pMonStatsTxtRecord->nBaseId;
}

__forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }

    return nMonsterId;
}

__forceinline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

__forceinline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0063EFA0
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc* pMonster, int* pMonsterId, int* pX, int* pY, int* pSpawnMode, int nChainSteps, int (__fastcall* pfnGetClassId)(D2UnitStrc*))
{
    int nChainId;
    D2DynamicPathStrc* pPath;
    D2SeedStrc* pSeed;
    int nBaseId = -1;

    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        nBaseId = MONSTERS_GetBaseIdFromMonsterIdInline(pMonster->dwClassId);
    }

    switch (MONSTERS_ValidateMonsterIdInline(nBaseId))
    {
    case 206:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(15), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 3;
        *pSpawnMode = 1;
        return;

    case 228:
        *pMonsterId = D2Common_11063(UNITS_GetRoom(pMonster), MONSTERS_ValidateMonsterIdInline(96));
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 2;
        *pSpawnMode = 1;
        return;

    case 267:
        *pMonsterId = MONSTERS_ValidateMonsterIdInline(6);
        pPath = pMonster->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pPath);
        *pSpawnMode = 8;
        return;

    case 284:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(68), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster) + 8;
        *pY = CLIENTS_GetUnitY(pMonster);
        *pSpawnMode = 8;
        return;

    case 321:
        if (pMonster && pMonster->dwClassId == 711)
        {
            *pMonsterId = MONSTERS_ValidateMonsterIdInline(712);
        }
        else
        {
            *pMonsterId = MONSTERS_ValidateMonsterIdInline(19);
        }
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster);
        *pSpawnMode = 1;
        return;

    case 298:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(301), nChainId);
        pPath = pMonster->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pPath);
        *pSpawnMode = 1;
        return;

    case 334:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(114), nChainId);
        *pX = UNITS_GetXPositionInline(pMonster) - 2;
        *pY = UNITS_GetYPositionInline(pMonster) - 2;
        *pSpawnMode = 1;
        return;

    case 484:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(453), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 3;
        *pSpawnMode = 1;
        return;

    case 526:
    case 528:
        if (pfnGetClassId)
        {
            *pMonsterId = pfnGetClassId(pMonster);
        }
        else
        {
            *pMonsterId = MONSTERS_ValidateMonsterIdInline(0);
            D2_ASSERT(pfnGetClassId, 508);
        }
        *pX = CLIENTS_GetUnitX(pMonster) + 2;
        *pY = CLIENTS_GetUnitY(pMonster) + 2;
        *pSpawnMode = 1;
        return;

    case 537:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(540), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 2;
        *pSpawnMode = 1;
        STATES_ToggleState(pMonster, 146, 1);
        return;

    case 544:
        pSeed = &pMonster->pSeed;
        if (*pMonsterId != MONSTERS_ValidateMonsterIdInline(570))
        {
            *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(562), SEED_RollLimitedRandomNumber(pSeed, 2) + nChainSteps);
            *pX = CLIENTS_GetUnitX(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
            *pY = CLIENTS_GetUnitY(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
            *pSpawnMode = 4;
            return;
        }

        *pX = CLIENTS_GetUnitX(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
        *pY = CLIENTS_GetUnitY(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
        *pSpawnMode = 1;
        return;

    default:
        *pMonsterId = MONSTERS_ValidateMonsterIdInline(0);
        *pX = 0;
        *pY = 0;
        *pSpawnMode = 1;
        return;
    }
}
