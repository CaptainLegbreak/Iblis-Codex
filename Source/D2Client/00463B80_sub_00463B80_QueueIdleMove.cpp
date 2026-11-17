struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x0C];
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x00[0x08];
    unsigned char nFlags[8];
};

struct D2LevelsTxt
{
    char unk0x00[0x02];
    unsigned char nAct;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define PLRMODE_DEATH 0
#define PLRMODE_NEUTRAL 1
#define PLRMODE_TOWNNEUTRAL 5
#define PLRMODE_DEAD 17
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12
#define SKILLSFLAGINDEX_PERIODIC 6

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, void* pTarget, int nArg);          // 0x00461250
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
D2ActiveRoomStrc* __fastcall sub_00465420_FindRoomAt(int nX, int nY);                                       // 0x00465420
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                           // 0x00644140
void __cdecl sub_004DBFE0_StopSkill();                                                                      // 0x004DBFE0
void __stdcall sub_0061ACD0_SetRoomPos(D2ActiveRoomStrc* pRoom, int nX, int nY, int bChanged);              // 0x0061ACD0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall sub_0061DBE0(int nLevelId);                                           // 0x0061DBE0
void __stdcall sub_004F5190_SetTownMode(int bTown);                                                         // 0x004F5190
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
void __fastcall sub_004FB480_SetActA(unsigned char nAct);                                                   // 0x004FB480
void __stdcall sub_00600C00_SetActB(int nAct);                                                              // 0x00600C00
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20
void __cdecl sub_00459140_Refresh();                                                                        // 0x00459140
void __fastcall sub_00472C20_PlayerMoved(int nArg);                                                         // 0x00472C20

// 0x00463B80
static void sub_00463B80_QueueIdleMove(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nMode = pUnit->dwAnimMode;
        if (UNITS_GetRoom(pUnit))
        {
            switch (nMode)
            {
            case PLRMODE_NEUTRAL:
            case PLRMODE_TOWNNEUTRAL:
                sub_00461250_QueueMove(7, pUnit, 0, 1);
                break;
            }
        }
    }
}

// 0x004654C0
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int bFlag)
{
    D2UnitStrc* pPlayer = gpPlayerUnit_007A6A70;
    if (pUnit == pPlayer)
    {
        sub_00466FE0();
    }
    D2ActiveRoomStrc* pRoom = sub_00465420_FindRoomAt(nX, nY);
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2_ASSERT(pDynamicPath, 0x166);
    if (nX && nY)
    {
        D2_ASSERT(pRoom, 0x168);
    }
    if (pUnit->dwFlags & 0x10000)
    {
        return;
    }
    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == PLRMODE_DEATH || nMode == PLRMODE_DEAD)
        {
            return;
        }
        break;
    case UNIT_MONSTER:
        if (nMode == MONMODE_DEATH || nMode == MONMODE_DEAD)
        {
            return;
        }
        break;
    }
    if (pUnit == pPlayer)
    {
        D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pUnit);
        if (pOldRoom)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
            D2SkillsTxt* pSkillsTxtRecord;
            if (pSkill && (pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill)) != 0 && (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks_006CE268[SKILLSFLAGINDEX_PERIODIC & 7]))
            {
                bFlag = 0;
            }
            else if (bFlag)
            {
                D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x17D);
                sub_004DBFE0_StopSkill();
            }
        }
        if (pRoom)
        {
            sub_0061ACD0_SetRoomPos(pRoom, nX, nY, pOldRoom != pRoom);
            sub_004F5190_SetTownMode(!sub_0061DBE0(DUNGEON_GetLevelIdFromRoom(pRoom)));
            if (pOldRoom)
            {
                D2LevelsTxt* pOldLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pOldRoom));
                D2LevelsTxt* pNewLevel = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (pOldLevel->nAct != pNewLevel->nAct)
                {
                    sub_004FB480_SetActA(pNewLevel->nAct);
                    sub_00600C00_SetActB(pNewLevel->nAct);
                }
            }
        }
    }
    if (!sub_00650BE0_PlaceUnit(pDynamicPath, pUnit, pRoom, nX, nY))
    {
        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
        COLLISION_GetFreeCoordinates(pRoom, &tCoord, nUnitSize, 0x1C09, 1);
        D2_ASSERT(D2Common_10231(pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY), 0x1A9);
    }
    sub_00459140_Refresh();
    if (pUnit == pPlayer)
    {
        sub_00472C20_PlayerMoved(bFlag);
    }
    sub_00463B80_QueueIdleMove(pUnit);
}
