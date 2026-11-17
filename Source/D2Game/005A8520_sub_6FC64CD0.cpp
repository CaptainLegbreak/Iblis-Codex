struct D2DynamicPathStrc;
struct D2SkillStrc;

enum D2C_Q05MonsterConstants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONMODE_GETHIT = 3,
    EVENTTYPE_AITHINK = 2,
    MONSTER_SANDLEAPER1 = 78,
    STATE_STUNNED = 21,
};

struct D2GameStrc
{
    char pad0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char pad0x30[0x80];
    int dwLastHitClass;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nFlag;
    unsigned char unk0x16;
    unsigned char unk0x17;
    int unk0x18;
    int unk0x1C;
};

struct D2MonStatsTxt
{
    short nId;
    short nBaseId;
    char pad0x04[0x1A4];
};

struct D2DataTablesStrc
{
    char pad0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char pad0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648DC0
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int nMonsterId, int nMode);                              // 0x0046C140
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline_Q05(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int MONSTERMODE_GetBaseIdInline_Q05(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline_Q05(nClassId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nClassId;
}

// 0x005A8520
void __fastcall sub_6FC64CD0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    PATH_ResetToPreviousType(pUnit->pDynamicPath);

    const int nClassId = pUnit->dwClassId;
    if (!sub_0046C140_CheckMonStats2ModeFlag(nClassId, MONMODE_GETHIT))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    int bSandLeaper = 0;
    if (nUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERMODE_GetBaseIdInline_Q05(nClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_SANDLEAPER1)
        {
            bSandLeaper = 1;
        }
    }

    if (!bSandLeaper)
    {
        UNITS_SetUsedSkill(pUnit, 0);

        D2ModeChangeStrc modeChange = {};
        modeChange.nMode = MONMODE_GETHIT;
        modeChange.pUnit = pUnit;
        modeChange.nFlag = 100;
        pUnit->dwLastHitClass = 160;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
        return;
    }

    int nFrame;
    if (STATES_CheckState(pUnit, STATE_STUNNED))
    {
        nFrame = pGame->dwGameFrame + 45;
    }
    else
    {
        nFrame = pGame->dwGameFrame + 15;
    }
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrame, 0, 0);
}
