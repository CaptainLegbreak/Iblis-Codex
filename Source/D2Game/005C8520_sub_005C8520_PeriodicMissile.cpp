struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2StatListStrc;
struct D2SeedStrc { unsigned int nLowSeed, nHighSeed; };
struct D2UnitStrc { int pad[8]; D2SeedStrc pSeed; };
struct D2GameStrc { char pad[0xA8]; unsigned int dwGameFrame; };
struct D2SkillsTxt { char pad0[4]; unsigned char nFlags[4]; char pad8[0x5C]; unsigned int dwAuraRangeCalc; char pad68[0x18]; short nAuraState; char pad82[0x1BA]; };
struct D2DataTablesStrc { char pad0[0xC4]; int nStatesTxtRecordCount; char padC8[0xAD0]; D2SkillsTxt* pSkillsTxt; void* pLinker; int nSkillsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall sub_004EFC80_FourthSkillParam(int nSkillId); // 0x004EFC80
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nFrame, int nCustomId, int nCustomParam); // 0x005417D0
D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTarget, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
int __stdcall sub_00645950_CheckTarget(int nX, int nY, D2UnitStrc* pUnit, int nMask); // 0x00645950
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
static __forceinline D2SkillsTxt* GetRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static __forceinline int DeleteEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 5, nSkillId);
    return 0;
}
// 0x005C8520
int __fastcall sub_005C8520_PeriodicMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pRecord = GetRecord(nSkillId);
    if (!pRecord || nSkillLevel <= 0 || pRecord->nAuraState < 0 || pRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!STATES_CheckState(pUnit, pRecord->nAuraState))
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!(pRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            D2StatListStrc* pList = STATLIST_GetStatListFromUnitAndState(pUnit, pRecord->nAuraState);
            if (pList)
            {
                D2Common_10474(pUnit, pList);
                STATLIST_FreeStatList(pList);
            }
            STATES_ToggleState(pUnit, pRecord->nAuraState, 0);
            return DeleteEvent(pGame, pUnit, nSkillId);
        }
    }
    int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSkill || !pSeed) return DeleteEvent(pGame, pUnit, nSkillId);
    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRange <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    int nFrame = sub_004EFC80_FourthSkillParam(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 5, nSkillId);
    EVENT_SetEvent(pGame, pUnit, 5, nFrame, nSkillId, nSkillLevel);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
    SEED_InitLowSeed(pSeed, SKILLS_GetParam1(pSkill));
    SKILLS_SetParam1(pSkill, SEED_RollLimitedRandomNumber(pSeed, 1000000));
    UNITS_GetXPosition(pUnit);
    CLIENTS_GetUnitY(pUnit);
    int nX, nY;
    int i = 0;
    for (; i < 5; ++i)
    {
        int nMax = 2 * nRange + 1;
        nX = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nX += UNITS_GetXPosition(pUnit);
        nY = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nY += CLIENTS_GetUnitY(pUnit);
        if (sub_00645950_CheckTarget(nX, nY, pUnit, 0x805))
        {
            pRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);
            if (pRoom && !COLLISION_CheckMask(pRoom, nX, nY, 1)) break;
        }
    }
    if (i >= 5) return 0;
    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
    sub_6FCC6300(pUnit, 0, nSkillId, nSkillLevel, nX, nY, 0);
    return 1;
}
