struct D2SkillStrc;
struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define COLLISION_PATTERN_SMALL_UNIT_PRESENCE 1

// 0x004D9260
void __fastcall sub_004D9260_StateClearCollision(D2UnitStrc* pUnit, int nState)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 759) != 167)
    {
        return;
    }

    int nX = SKILLS_GetParam2(pSkill);
    int nY = SKILLS_GetParam3(pSkill);
    if (!nX && !nY)
    {
        return;
    }

    SKILLS_SetParam2(pSkill, 0);
    SKILLS_SetParam3(pSkill, 0);
    if (D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY))
    {
        D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
        COLLISION_ResetMaskWithPattern(pRoom, nX, nY, COLLISION_PATTERN_SMALL_UNIT_PRESENCE, 0x100);
    }
}
