struct D2BitBufferStrc;
struct D2ItemDropStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x04];
    int dwUnitId;
    char pad0x10[0xA8];
    unsigned int dwDropItemCode;
    char pad0xBC[0x08];
    unsigned int dwFlags;
};

struct D2GameStrc;

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2QuestDataStrc;
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act3Quest2Strc
{
    char pad0x00[0x1C];
    int nFlailsDropped;
    int nCubedFlails;
    char pad0x24[0x03];
    unsigned char bFlailDropped;
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID;
    unsigned char bOrmusActivated;
    char pad0x05[0x07];
    unsigned char bOrbSmashed;
    unsigned char bFlailDropped;
    unsigned char bCubeDropped;
    char pad0x0F[0x25];
    int nMonstersLeftToKill;
    int nHits;
    int nFlailsMissing;
    int nHoradricCubesMissing;
};

int __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAE20
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005BAF70
int __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB6C0
int __fastcall ACT3Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);    // 0x005BB710
int __fastcall ACT3Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB770
int __fastcall ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB7B0

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

// 0x005BBC00
void __fastcall ACT3Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 913);

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    int i;
    if (UNITS_GetClassIdInline(pQuestArg->pTarget) == 366)
    {
        SetUnitFlagMask(pQuestArg->pTarget, 0x20000);
        return;
    }

    if (!pQuestDataEx->bFlailDropped || !pQuestDataEx->bCubeDropped)
    {
        pQuestDataEx->nFlailsMissing = 0;
        pQuestDataEx->nHoradricCubesMissing = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts);
    }

    if (!pQuestDataEx->bFlailDropped)
    {
        pQuestArg->pTarget->dwDropItemCode = ' 1fq';
        int nFlailsDropped = 0;
        for (i = 0; i < pQuestDataEx->nFlailsMissing; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 7, &nItemLevel, 0, -1, 0))
            {
                ++nFlailsDropped;
            }
        }

        if (nFlailsDropped)
        {
            pQuestDataEx->bFlailDropped = 1;

            D2QuestDataStrc* pQuestData16 = QUESTS_GetQuestData(pQuestData->pGame, 16);
            if (pQuestData16)
            {
                D2Act3Quest2Strc* pQuestDataEx16 = (D2Act3Quest2Strc*)pQuestData16->pQuestDataEx;
                pQuestDataEx16->nFlailsDropped += nFlailsDropped;
                pQuestDataEx16->bFlailDropped = 1;
            }
        }
    }
    else if (!pQuestDataEx->bCubeDropped)
    {
        pQuestDataEx->bCubeDropped = 1;
        pQuestArg->pTarget->dwDropItemCode = ' xob';
        for (i = 0; i < pQuestDataEx->nHoradricCubesMissing; ++i)
        {
            int nItemLevel;
            D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0);
        }
    }

    if (!pQuestData->bNotIntro || pQuestDataEx->nMonstersLeftToKill <= 0)
    {
        return;
    }

    --pQuestDataEx->nMonstersLeftToKill;
    if (pQuestDataEx->nMonstersLeftToKill)
    {
        return;
    }

    pQuestDataEx->nLastKilledMonsterGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
    pQuestData->dwFlags &= 0xFFFFFF00;
    if (pQuestDataEx->bOrbSmashed)
    {
        QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 972);
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q5_UnitIterate_StatusCyclerEx, true);
    }
    else
    {
        QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 977);
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q5_UnitIterate_StatusCyclerEx, true);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateAfterMonsterKill);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_AttachCompletionSound);
    QUESTS_SetGlobalState(pQuestData->pGame, 21, 13);
}
