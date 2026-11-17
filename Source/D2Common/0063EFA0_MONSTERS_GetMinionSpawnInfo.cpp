struct D2ActiveRoomStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

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

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char unk0x04[0x1A8 - 4];
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

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_MONSTER 1

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
