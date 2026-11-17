struct D2ActiveRoomStrc;
struct D2StatListStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2UnkNecSkillStrc3
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
    unsigned char nUnitType;
    unsigned char pad0x11;
    unsigned short pad0x12;
    int nUnitGUID;
    int nLength;
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2);                             // 0x00645510
int __stdcall sub_00645680_CanUnitCorpseBeSelected(D2UnitStrc* pUnit);                                      // 0x00645680
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3);                           // 0x005543B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall sub_005B1A90(D2GameStrc* pGame, D2UnitStrc* pUnit);                         // 0x005B1A90
int __fastcall sub_005C31F0_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C31F0
void __fastcall sub_6FC61E30(D2UnitStrc* pUnit, int a2, int a3);                                            // 0x00573090
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005C3070
int __fastcall SKILLS_SrvSt15_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

// 0x005C31C0
int __fastcall SKILLS_SrvSt17_Poison_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return sub_00645680_CanUnitCorpseBeSelected(pTarget);
}

// 0x005C3260
int __fastcall SKILLS_SrvSt18_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x005C3270
int __fastcall SKILLS_SrvSt19_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget));
}

// 0x005C3B00
void __fastcall sub_005C3B00_AttractStateRemove(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FCBDD30(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// 0x005C3B30
int __fastcall sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg)
{
    D2UnkNecSkillStrc3* pParam = (D2UnkNecSkillStrc3*)pArg;
    if (!sub_005C31F0_IsValidAttractTarget(pParam->pGame, pParam->pUnit, pUnit))
    {
        return 0;
    }

    if (pParam->nUnitType == 0)
    {
        sub_6FC61E30(pUnit, 1, pParam->nUnitGUID);
    }
    else
    {
        sub_6FC61E30(pUnit, 2, pParam->nUnitGUID);
    }

    EVENT_SetEvent(pParam->pGame, pUnit, 0x0A, pParam->pGame->dwGameFrame + pParam->nLength, 0, 0);
    return 1;
}

// 0x005C3DB0
void __fastcall sub_6FD0C2B0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FCBDD30(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);
}
