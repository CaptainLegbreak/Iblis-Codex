struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2ItemsTxt;

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
    int nX;
    int nY;
};

struct D2PlayerDataStrc
{
    char unk0x00[0xA0];
    unsigned char nPositionHistoryIndex;
    char unk0xA1[0x03];
    unsigned int dwPositionHistoryTick;
    D2CoordStrc pPositionHistory[20];
    char unk0x148[0x08];
    int bInteract;
    int nInteractAction;
    int nInteractUnitType;
    int nInteractUnitGUID;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct D2CharStatsTxt
{
    char unk0x00[0x42];
    unsigned char nRunDrain;
    char unk0x43[0x81];
};

struct D2ItemsTxtSpeed
{
    char unk0x00[0xD8];
    int dwSpeed;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

struct D2GameStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame);  // 0x00548B00
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00553490
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                       // 0x00553570
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);           // 0x00553990
void __fastcall SUNIT_ResetRecurringModeChangeEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                  // 0x00553F00
int __fastcall SUNIT_UpdateUnitPath(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x00554CA0
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY); // 0x0057F020
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x005C9D90
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);         // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0
D2ItemsTxtSpeed* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                         // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);          // 0x006439F0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648780
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648DC0
void __stdcall D2COMMON_10190_PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nDistance);   // 0x00648E40
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                             // 0x006492A0

// build: context sub_F05_PlrGetUnitX
static __forceinline int sub_F05_PlrGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// build: context sub_F05_PlrGetUnitY
static __forceinline int sub_F05_PlrGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// build: context sub_F05_GetInteractAction
static __forceinline int sub_F05_GetInteractAction(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == 0 ? pPlayer->pPlayerData->nInteractAction : 0;
}

// build: context sub_F05_GetInteractUnitType
static __forceinline int sub_F05_GetInteractUnitType(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == 0 && pPlayer->pPlayerData ? pPlayer->pPlayerData->nInteractUnitType : 0;
}

// build: context sub_F05_GetInteractUnitGUID
static __forceinline int sub_F05_GetInteractUnitGUID(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == 0 ? (pPlayer->pPlayerData ? pPlayer->pPlayerData->nInteractUnitGUID : 0) : 0;
}

// build: context sub_F05_IsInteracting
static __forceinline int sub_F05_IsInteracting(D2UnitStrc* pPlayer)
{
    if (pPlayer)
    {
        switch (pPlayer->dwUnitType)
        {
        case 0:
            if (pPlayer->pPlayerData)
            {
                return pPlayer->pPlayerData->bInteract;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return 0;
        }
    }

    return 0;
}

// build: context sub_F05_SetInteractFlag
static __forceinline void sub_F05_SetInteractFlag(D2UnitStrc* pPlayer, int nFlag)
{
    if (pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->bInteract = nFlag;
    }
}

// build: context sub_F05_GetCharStatsTxtRecord
static __forceinline D2CharStatsTxt* sub_F05_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

static void __stdcall sub_0057F090_StartMovement(D2GameStrc*, D2UnitStrc*, int); // 0x0057F090
// 0x0057F090
static void __stdcall sub_0057F090_StartMovement(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode)
{
    D2_ASSERT(pGame, 0x138);

    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    PATH_ResetToPreviousType(pPath);

    switch (nMode)
    {
    case 3:
        if (STATLIST_UnitGetStatValue(pPlayer, 10, 0))
        {
            break;
        }
    case 2:
    case 6:
        nMode = DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)) != 0 ? 6 : 2;
        break;

    case 19:
        PATH_SetType(pPath, 8);
        D2COMMON_10190_PATH_SetDistance(pPath, 5);
        break;
    }

    D2Common_10142(pPath, pPlayer, 0);
    UNITS_SetUsedSkill(pPlayer, 0);

    if (!PATH_GetNumberOfPathPoints(pPath))
    {
        PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
    }
    else
    {
        SUNIT_SetCombatMode(pGame, pPlayer, nMode);
        D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
        SUNIT_ResetRecurringModeChangeEvent(pGame, pPlayer);
    }
}

// build: context PLRMODE_StartID_WalkRunKnockback
void __fastcall PLRMODE_StartID_WalkRunKnockback(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(pGame, 0x16E);

    if (nMode != 19 || pPlayer->dwAnimMode != nMode)
    {
        PATH_SetTargetUnit(pPlayer->pDynamicPath, pTargetUnit);
        sub_0057F090_StartMovement(pGame, pPlayer, nMode);
    }
}

// 0x0057F1F0
void __fastcall PLRMODE_StartXY_WalkRunKnockback(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(pGame, 0x17C);

    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    sub_0057F090_StartMovement(pGame, pPlayer, nMode);
}

static int sub_0057F240_DrainRunStamina(D2UnitStrc*); // 0x0057F240
// 0x0057F240
static int sub_0057F240_DrainRunStamina(D2UnitStrc* pPlayer)
{
    if (!pPlayer)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
    {
        return 1;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = sub_F05_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nStaminaLost = 2 * pCharStatsTxtRecord->nRunDrain;
    if (!pPlayer->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pTorsoArmor = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 3);
    if (pTorsoArmor)
    {
        D2ItemsTxtSpeed* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pTorsoArmor ? -1 : pTorsoArmor->dwClassId);
        if (pItemsTxtRecord)
        {
            int nSpeed = pItemsTxtRecord->dwSpeed;
            nSpeed = nSpeed / 10 + 1;
            nStaminaLost *= nSpeed;
        }
    }

    const int nStaminaDrainPct = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, 154, 0);
    if (nStaminaDrainPct)
    {
        nStaminaLost += nStaminaLost * nStaminaDrainPct / -100;
    }

    if (nStaminaLost < 1)
    {
        nStaminaLost = 1;
    }

    STATLIST_AddUnitStat(pPlayer, 10, -nStaminaLost, 0);

    if (STATLIST_UnitGetStatValue(pPlayer, 10, 0) <= 0)
    {
        STATLIST_SetUnitStat(pPlayer, 10, 0, 0);
        return 0;
    }

    return 1;
}

// 0x00580C20
int __fastcall PLRMODE_UpdateMovement(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventCustomId, int nEventCustomParam)
{
    sub_6FCBC7E0(pGame, pPlayer);

    if (STATES_CheckState(pPlayer, 13))
    {
        SKILLS_CreateBlazeMissile(pGame, pPlayer);
    }

    if (pPlayer && pPlayer->dwAnimMode == 3 && !sub_0057F240_DrainRunStamina(pPlayer))
    {
        sub_0057F090_StartMovement(pGame, pPlayer, 2);
    }

    int nPathResult = SUNIT_UpdateUnitPath(pGame, pPlayer);
    const unsigned int nTickCount = GetTickCount();
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (nTickCount > pPlayerData->dwPositionHistoryTick + 25)
    {
        const unsigned char nHistoryIndex = pPlayerData->nPositionHistoryIndex;
        unsigned char nPreviousIndex;
        if (!nHistoryIndex)
        {
            nPreviousIndex = 19;
        }
        else
        {
            if (nPathResult) nPreviousIndex = nHistoryIndex - 1; else nPreviousIndex = nHistoryIndex - 1;
        }

        const int nPlayerX = sub_F05_PlrGetUnitX(pPlayer);
        const int nPlayerY = sub_F05_PlrGetUnitY(pPlayer);
        const int nPrevX = pPlayerData->pPositionHistory[nPreviousIndex].nX;
        const int nPrevY = pPlayerData->pPositionHistory[nPreviousIndex].nY;
        if (PATH_ComputeSquaredDistance(nPlayerX, nPlayerY, nPrevX, nPrevY) > 45)
        {
            pPlayerData->pPositionHistory[nHistoryIndex].nX = nPlayerX;
            pPlayerData->pPositionHistory[nHistoryIndex].nY = nPlayerY;
            pPlayerData->dwPositionHistoryTick = nTickCount;

            ++pPlayerData->nPositionHistoryIndex;
            if (pPlayerData->nPositionHistoryIndex >= 20)
            {
                pPlayerData->nPositionHistoryIndex = 0;
            }
        }
    }

    if (nPathResult == 2)
    {
        if (sub_F05_IsInteracting(pPlayer))
        {
            int nResult;
            const int nAction = sub_F05_GetInteractAction(pPlayer);
            if (nAction >= 0)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, nAction);
                if (pSkill)
                {
                    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pPlayer, pSkill);
                    D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pPlayer, pSkill, nSkillMode, sub_F05_GetInteractUnitType(pPlayer), sub_F05_GetInteractUnitGUID(pPlayer), 0);
                    nPathResult = 1;
                }
                else
                {
                    PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
                }
                nResult = nPathResult;
            }
            else
            {
                PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
                sub_6FC828D0(pPlayer, sub_F05_GetInteractUnitType(pPlayer), sub_F05_GetInteractUnitGUID(pPlayer), nAction == -2, pGame);
                nResult = *(volatile int*)&nPathResult;
            }

            if (nPathResult) sub_F05_SetInteractFlag(pPlayer, 0); else sub_F05_SetInteractFlag(pPlayer, 0);
            return nResult;
        }

        PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
    }

    return nPathResult;
}
