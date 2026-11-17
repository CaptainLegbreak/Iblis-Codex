struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2UnitStrc { int dwUnitType; };
struct D2SkillsTxt
{
    char unk0x000[4];
    unsigned char nFlags[8];
    char unk0x00C[0x20];
    short wSrvStartFunc;
    char unk0x02E[0x161];
    unsigned char nLineOfSight;
    char unk0x190[0xAC];
};
struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};
typedef char SkillsRecordSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];
typedef int (__fastcall* SkillStartFunc)(D2GameStrc*, D2UnitStrc*, int, int);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern SkillStartFunc gpSkillStartHandlers_00732140[]; // 0x00732140
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit); // 0x0056C160
int __fastcall sub_0056BFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056BFE0
void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nMode, int nX, int nY, int a7); // 0x005809D0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nCollisionMask); // 0x00645950
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x0056F640
int __fastcall sub_0056F640_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bSkipMana)
{
    if (!pGame || !pUnit || !UNITS_GetRoom(pUnit))
        return 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    if (!bSkipMana && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
        return 0;
    if (!(pSkillsTxtRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 0)
                sub_6FC817D0(pGame, pUnit, 0, 5, 0, 0, 1);
            return 0;
        }
    }
    int nX;
    int nY;
    if (pSkillsTxtRecord->nLineOfSight && D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1: nCollisionMask = 4; break;
        case 2: nCollisionMask = 0x1C09; break;
        case 3: nCollisionMask = 0x180; break;
        case 4: nCollisionMask = 0x804; break;
        case 5: nCollisionMask = 0x805; break;
        default: return 0;
        }
        if (!D2Common_11026(nX, nY, pUnit, nCollisionMask))
            return 0;
    }
    if (pSkillsTxtRecord->wSrvStartFunc < 0 || pSkillsTxtRecord->wSrvStartFunc >= 91)
        return 0;
    SkillStartFunc pStart = gpSkillStartHandlers_00732140[pSkillsTxtRecord->wSrvStartFunc];
    int nResult;
    if (!pStart)
    {
        nResult = 1;
    }
    else
    {
        nResult = pStart(pGame, pUnit, nSkillId, nSkillLevel);
        if (nResult && !(pSkillsTxtRecord->nFlags[4] & gdwBitMasks[5]) && !bSkipMana)
            sub_0056BFE0(pGame, pUnit, nSkillId, nSkillLevel);
    }
    if (nResult && (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[6]))
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 8, 0);
    return nResult;
}

#include "gen/data/Source/D2Game/0056F640_sub_0056F640_StartSkill.inc"
