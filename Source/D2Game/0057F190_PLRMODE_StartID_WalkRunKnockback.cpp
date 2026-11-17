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
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
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
extern "C" void __stdcall sub_00648B90_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget);        // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648DC0
void __stdcall D2COMMON_10190_PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nDistance);   // 0x00648E40
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                             // 0x006492A0

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

// 0x0057F190
void __fastcall PLRMODE_StartID_WalkRunKnockback(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(pGame, 0x16E);

    const int nCurMode = nMode;
    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    if (nCurMode != 19 || pPlayer->dwAnimMode != nCurMode)
    {
        sub_00648B90_SetPathTarget(pPath, pTargetUnit);
        sub_0057F090_StartMovement(pGame, pPlayer, nCurMode);
    }
}

void __fastcall PLRMODE_StartXY_WalkRunKnockback(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(pGame, 0x17C);

    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    sub_0057F090_StartMovement(pGame, pPlayer, nMode);
}
