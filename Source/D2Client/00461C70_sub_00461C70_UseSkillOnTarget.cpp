extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2SkillStrc;
struct D2GfxLightStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2PlayerDataStrc
{
    char unk0x000[0x150];
    int nState;
    int nMode;
    int nArg1;
    int nArg2;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    unsigned short nClientFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2PlayerDataStrc* pPlayerData;
        D2MonsterDataStrc* pMonsterData;
    };
    char unk0x18[0x14];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
};

struct D2PlayerCmdStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pPlayer;
    D2UnitStrc* pTarget;
    int nX;
    int nY;
    int nArg;
    int nMode;
    D2SkillStrc* pSkill;
};

struct D2SkillRefStrc
{
    int nSkillId;
    int nOwnerGUID;
};

struct D2SkillsTxt
{
    char unk0x00[0x4];
    unsigned char nFlags[8];
    char unk0x0C[0x8];
    char nAuraTargetState;
    char unk0x15[0x19];
    unsigned short wSrvDoFunc;
    char unk0x30[0x20C];
};

struct D2ClientEntryStrc
{
    int unk0x00[2];
    int nValue;
};

struct D2MonStatsTxt
{
    char unk0x00[0xC];
    unsigned char nFlags[4];
    char unk0x10[0x198];
};

struct D2InventoryStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x114];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

struct D2StringRefStrc
{
    unsigned short nStringId;
    unsigned short unk0x02;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern void* gpDrlgAct_007A0634;                                                                            // 0x007A0634
extern int gnInTown_007A5260;                                                                               // 0x007A5260
extern unsigned int gdwLastTick_007A5268;                                                                   // 0x007A5268
extern int gdwGlobal_007A5264;                                                                              // 0x007A5264
extern int gnStringCount_00711EF0;                                                                          // 0x00711EF0
extern D2StringRefStrc gaStringRefs_00711DDC[];                                                             // 0x00711DDC
extern "C" const char gszPlayerCpp_006D6A34[];                                                              // 0x006D6A34

unsigned int __cdecl sub_0044BEF0();                                                                        // 0x0044BEF0
unsigned int __cdecl sub_0044DA90();                                                                        // 0x0044DA90
unsigned int __cdecl sub_0044DAA0();                                                                        // 0x0044DAA0
unsigned int __cdecl sub_0044DAC0();                                                                        // 0x0044DAC0
void __fastcall sub_0044DAD0(unsigned int nValue);                                                          // 0x0044DAD0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
void __cdecl sub_00453EC0();                                                                                // 0x00453EC0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_0045AFF0(int* pX, int* pY);                                                             // 0x0045AFF0
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit);                                        // 0x0045C470
int __stdcall sub_00461D60_IsPendingMode(int nArg1, int nArg2);                                             // 0x00461D60
int __fastcall sub_00464600(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                            // 0x00464600
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
void __fastcall sub_00467A70(D2UnitStrc* pUnit);                                                            // 0x00467A70
D2UnitStrc* __fastcall sub_00467880_FindSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pX, int* pY, unsigned int dwFlags, int bForce); // 0x00467880
int __cdecl sub_00468830();                                                                                 // 0x00468830
int __fastcall sub_00474080_GetDistance(int nDX, int nDY);                                                  // 0x00474080
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitType, int nUnitId, int nX, int nY);         // 0x00478700
int __cdecl sub_00454970();                                                                                 // 0x00454970
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_00460780_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2);             // 0x00460780
int __fastcall sub_00461AC0_IsInAuraRange(D2SkillStrc* pSkill, D2UnitStrc* pTarget, int* pRange, int* pDistance); // 0x00461AC0
int __fastcall sub_00462930_FilterMessage(D2PlayerCmdStrc* pCmd);                                           // 0x00462930
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00463D90(int nArg);                                                                     // 0x00463D90
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
void __fastcall sub_00464810(D2UnitStrc* pUnit);                                                            // 0x00464810
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags);                // 0x004654C0
void __fastcall sub_00466CB0(D2UnitStrc* pUnit, int nArg);                                                  // 0x00466CB0
void __fastcall sub_00467410_SetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue);            // 0x00467410
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);                                     // 0x0046BF30
void __fastcall sub_0046C700(D2UnitStrc* pUnit);                                                            // 0x0046C700
void __fastcall sub_0046EC10(D2UnitStrc* pUnit);                                                            // 0x0046EC10
void __fastcall sub_0046ECE0_PruneGfxNodes(D2UnitStrc* pUnit);                                              // 0x0046ECE0
void __fastcall sub_0046F020_FillGfxEntries(D2UnitStrc* pUnit, char nValue);                                // 0x0046F020
void __fastcall sub_00473C90_SetGlobal(int nValue);                                                         // 0x00473C90
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20
void __fastcall sub_00480E70_SetState(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall sub_00481030(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);                // 0x00481030
void __fastcall sub_004B3E10(D2UnitStrc* pUnit);                                                            // 0x004B3E10
void __cdecl sub_004C1E30();                                                                                // 0x004C1E30
void __fastcall sub_004C68F0(D2UnitStrc* pUnit);                                                            // 0x004C68F0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId);                          // 0x004CB9C0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                       // 0x004D9FC0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall sub_0061AA40(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AA40
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __stdcall sub_0061ACD0_SetRoomPos(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged);              // 0x0061ACD0
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30
void __stdcall sub_0061AF10(void* pAct, D2ActiveRoomStrc* pNextRoom, D2ActiveRoomStrc* pRoom);              // 0x0061AF10
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __stdcall sub_00620E40_GetClassSpeed(D2UnitStrc* pUnit, int nClassId, int* pSpeed, int* pBase);        // 0x00620E40
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* pPlayer);                                   // 0x00622060
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags);                             // 0x006221E0
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit);                                                // 0x00622230
int __stdcall sub_00622B50_TestInteractCollision(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMask);       // 0x00622B50
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit);                                                    // 0x00622DC0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer);                  // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                                  // 0x00640E90
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject);                        // 0x00623660
int __stdcall sub_006486C0(D2DynamicPathStrc* pDynamicPath);                                                // 0x006486C0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                      // 0x00641530
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2);                                                // 0x00643A00
D2SkillStrc* __fastcall SKILLS_GetSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                   // 0x006439B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                      // 0x00648460
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_00648A40_GetTargetX(D2DynamicPathStrc* pPath);                                            // 0x00648A40
int __stdcall sub_00648A60_GetTargetY(D2DynamicPathStrc* pPath);                                            // 0x00648A60
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath);                              // 0x00648AA0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                          // 0x00649970
void __stdcall D2Common_10228(D2UnitStrc* pUnit);                                                           // 0x00649F50
void __stdcall sub_00649F70(D2UnitStrc* pUnit, int nArg);                                                   // 0x00649F70
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
unsigned short __stdcall COLLISION_CheckMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D870
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
void __cdecl sub_004608C0();                                                                                // 0x004608C0

#define E06_ABS(x) ((x) < 0 ? -(x) : (x))

#define UNIT_GETX(pUnit, outX) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outX = (pUnit)->pStaticPath->nX; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outX = PATH_GetXPosition((pUnit)->pDynamicPath); \
        else \
            outX = 0; \
        break; \
    }

#define UNIT_GETY(pUnit, outY) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outY = (pUnit)->pStaticPath->nY; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outY = PATH_GetYPosition((pUnit)->pDynamicPath); \
        else \
            outY = 0; \
        break; \
    }

#define UNIT_GETX_K5(pUnit, outX) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outX = (pUnit)->pStaticPath->nX; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outX = PATH_GetXPosition((pUnit)->pDynamicPath); \
        else \
            outX = 0; \
        break; \
    }

#define UNIT_GETY_K5(pUnit, outY) \
    switch ((pUnit)->dwUnitType) \
    { \
    case 2: \
    case 4: \
    case 5: \
        outY = (pUnit)->pStaticPath->nY; \
        break; \
    default: \
        if ((pUnit)->pDynamicPath) \
            outY = PATH_GetYPosition((pUnit)->pDynamicPath); \
        else \
            outY = 0; \
        break; \
    }

// 0x00461070
static void __stdcall sub_00461070_RequestSkillString(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(gnStringCount_00711EF0 > nIndex, 0x2CB);
    const unsigned short nStringId = gaStringRefs_00711DDC[nIndex].nStringId;
    if (nStringId)
        sub_004CB9C0_Request(pUnit, nStringId);
}

// 0x004610C0
static int __stdcall sub_004610C0_CheckSkillUse(int* pUseState, D2SkillStrc** ppSkill, D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0())
        return 1;

    if (!ppSkill || !*ppSkill)
        return 0;

    int nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    if (pUseState)
        *pUseState = nUseState;

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(*ppSkill);
    if (!pSkillsTxt)
        return 0;

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4)
        && (pSkillsTxt->nFlags[3] & gdwBitMasks[4]))
    {
        *ppSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0);
        nUseState = sub_004D9FC0_GetSkillUseState(pUnit, *ppSkill);
    }

    if (nUseState == 5 || nUseState == 0)
        return 1;

    sub_00461070_RequestSkillString(pUnit, nUseState);
    return 0;
}

static int sub_00461160_CheckCommandSkill(D2PlayerCmdStrc* pCmd, int* pUseState)
{
    return sub_004610C0_CheckSkillUse(pUseState, &pCmd->pSkill, pCmd->pPlayer);
}

// build: context sub_00461700_SendCommand
static void __stdcall sub_00461700_SendCommand(int bTarget, D2PlayerCmdStrc* pCmd)
{
    if (sub_00468740() > sub_00454970())
        return;

    if (bTarget == 1)
    {
        D2UnitStrc* pTarget = pCmd->pTarget;
        const int nId = pTarget ? pTarget->dwUnitId : -1;
        const int nType = pTarget ? pTarget->dwUnitType : 6;
        if (pCmd->dwFlags & 1)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(0xA, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(7, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(9, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(6, pCmd->pPlayer, nType, nId, 0);
            }
        }
        if (pCmd->dwFlags & 2)
        {
            if (pCmd->dwFlags & 0x20)
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(0x11, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(0xE, pCmd->pPlayer, nType, nId, 0);
            }
            else
            {
                if (pCmd->dwFlags & 8)
                    sub_00481030(0x10, pCmd->pPlayer, nType, nId, 0);
                else
                    sub_00481030(0xD, pCmd->pPlayer, nType, nId, 0);
            }
        }
        return;
    }

    if (pCmd->dwFlags & 1)
    {
        if (pCmd->dwFlags & 8)
            sub_00481030(8, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            sub_00481030(5, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
    if (pCmd->dwFlags & 2)
    {
        if (pCmd->dwFlags & 8)
            sub_00481030(0xF, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
        else
            sub_00481030(0xC, pCmd->pPlayer, pCmd->nX, pCmd->nY, 0);
    }
}

// 0x00461840
static int __stdcall sub_00461840_WalkTo(int nMode, D2UnitStrc* pUnit, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    if (!D2Common_10142(pPath, pUnit, 0))
        return 0;

    const int nTargetX = sub_00648A40_GetTargetX(pPath);
    const int nTargetY = sub_00648A60_GetTargetY(pPath);
    sub_00481030(nMode, pUnit, nTargetX, nTargetY, 0);
    return 1;
}

// build: context sub_00461B40_ApproachForAura
static int sub_00461B40_ApproachForAura(D2PlayerCmdStrc* pCmd, int nArg1, int nArg2)
{
    int nRange = 0;
    int nDistance = 0;
    D2_ASSERT(pCmd->pTarget, 0x52F);
    D2_ASSERT(pCmd->pPlayer, 0x530);
    if (pCmd->dwFlags & 0x20)
    {
        sub_00461700_SendCommand(1, pCmd);
        return 1;
    }

    if (sub_00461AC0_IsInAuraRange(pCmd->pSkill, pCmd->pTarget, &nRange, &nDistance))
    {
        sub_00461700_SendCommand(1, pCmd);
        return 1;
    }

    if (pCmd->dwFlags & 1)
        sub_00460780_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
    if (pCmd->dwFlags & 2)
        sub_00460780_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);

    const int nDelta = nDistance - nRange;
    D2_ASSERT(nDelta > 0, 0x548);
    D2_ASSERT(nDistance, 0x549);
    const int nPlayerX = CLIENTS_GetUnitX(pCmd->pPlayer);
    nRange = CLIENTS_GetUnitY(pCmd->pPlayer);
    const int nDX = CLIENTS_GetUnitX(pCmd->pTarget) - nPlayerX;
    const int nDY = CLIENTS_GetUnitY(pCmd->pTarget) - nRange;
    const int nNewY = nDY * nDelta / nDistance + nRange;
    sub_00461840_WalkTo(pCmd->nArg, pCmd->pPlayer, nDX * nDelta / nDistance + nPlayerX, nNewY);
    return 1;
}
// 0x00461C70
static void __stdcall sub_00461C70_UseSkillOnTarget(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd)
{
    if (!sub_00461160_CheckCommandSkill(pCmd, 0))
        return;

    const int nResult = D2Common_11016(pCmd->pPlayer, pCmd->pSkill);
    D2UnitStrc* pUnit = sub_00463990(nArg2, nArg1);
    if (!pUnit)
        return;

    if (UNITS_IsInMeleeRange(pCmd->pPlayer, pCmd->pTarget, UNITS_IsInMovingModeEx(pUnit)))
    {
        sub_00461700_SendCommand(1, pCmd);
        return;
    }

    D2SkillStrc* pSkill = pCmd->pSkill;
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (pSkillsTxt && pSkillsTxt->wSrvDoFunc == 0x13)
        {
            sub_00461B40_ApproachForAura(pCmd, nArg1, nArg2);
            return;
        }
    }

    switch (nResult)
    {
    default:
        sub_00461700_SendCommand(1, pCmd);
        return;

    case 1:
    case 4:
        if (!(pCmd->dwFlags & 0x20))
        {
            sub_00481030(pCmd->nMode, pCmd->pPlayer, nArg1, nArg2, 0);
            if (pCmd->dwFlags & 1)
                sub_00460780_SetPlayerMode(6, pCmd->pPlayer, nArg1, nArg2);
            if (pCmd->dwFlags & 2)
                sub_00460780_SetPlayerMode(0xD, pCmd->pPlayer, nArg1, nArg2);
            return;
        }

        sub_00461700_SendCommand(0, pCmd);
        return;
    }
}

void __stdcall sub_E06_Emit_00461C70(int nArg1, int nArg2, D2PlayerCmdStrc* pCmd)
{
    sub_00461C70_UseSkillOnTarget(nArg1, nArg2, pCmd);
    sub_00461C70_UseSkillOnTarget(0, nArg2, pCmd);
}
