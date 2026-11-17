struct D2DynamicPathStrc;

struct D2MonStatsTxt
{
    char unk0x000[0x4F];
    unsigned char nAIdel[3];
    char unk0x052[0x153];
    unsigned char nSplGetModeChart;
    char unk0x1A6[0x02];
};

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x06];
    int dwGameType;
    char unk0x78[0x30];
    int dwGameFrame;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
};

struct D2AiParamStrc;

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

struct D2MonModeCallbackTableStrc
{
    void* pfnCallbacks[4];
};

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);
typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const D2MonModeCallbackTableStrc gMonModeCallbacks[];                                                // 0x006E2260
extern const D2MonModeCallbackTableStrc gDiablo_Skill4_Callbacks;                                           // 0x006E2360
extern const D2MonModeCallbackTableStrc gDiablo_Skill3_Callbacks;                                           // 0x006E2370
extern const D2MonModeCallbackTableStrc gTrappedSoul_Attack_Callbacks;                                      // 0x006E2380
extern const D2MonModeCallbackTableStrc gTrappedSoul_Skill_Callbacks;                                       // 0x006E2390
extern const D2MonModeCallbackTableStrc gShadowMasterWarrior_Skill4_Callbacks;                              // 0x006E23A0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                   // 0x005407A0
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg); // 0x005A5C70
void __fastcall sub_6FC7B460(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg);                          // 0x005A5CB0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                       // 0x00553570
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent);                       // 0x005415A0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005A5650
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0x80;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nMaxHp > 0 && nHitpoints < nMaxHp)
    {
        return (nHitpoints << 7) / nMaxHp;
    }

    return 0x80;
}

// build: context PARTYSCREEN_PlayerLeftParty
void __fastcall PARTYSCREEN_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PARTY_IteratePartyMembers(pGame, SUNIT_GetPartyId(pPlayer1), PARTYSCREEN_PartyIterate_PlayerLeftParty, pPlayer1);
    PARTY_LeaveParty(pGame, pPlayer1);
}

// 0x005A5FF0
void __fastcall PARTYSCREEN_RefreshPartyRelationsAfterLeave(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    SUNIT_IterateLivingPlayers(pGame, sub_6FC7B460, pPlayer);
}

// 0x005A64D0
void __fastcall D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam)
{
    FOG_FreeServerMemory(pGame->pMemoryPool, pAiParam, ".\\MONSTER\\MonsterMode.cpp", 327, 0);
}

// 0x005A73E0
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, 1);

    if (EVENT_GetEventFrame(pGame, pUnit, 2) <= pGame->dwGameFrame)
    {
        if (STATES_CheckState(pUnit, 21))
        {
            EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 45, 0, 0);
            return 1;
        }

        if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStatsTxtRecord)
            {
                int nAiDelay;
                if (!pGame->nGameType && !pGame->dwGameType)
                {
                    nAiDelay = pMonStatsTxtRecord->nAIdel[0];
                }
                else
                {
                    nAiDelay = pMonStatsTxtRecord->nAIdel[pGame->nDifficulty];
                }

                if (nAiDelay <= 0)
                {
                    nAiDelay = 15;
                }

                EVENT_SetEvent(pGame, pUnit, 2, nAiDelay + pGame->dwGameFrame, 0, 0);
            }
        }
    }

    return 1;
}

// 0x005A78A0
const D2MonModeCallbackTableStrc* __fastcall MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (nMode < 0 || nMode >= 16)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nSplGetModeChart)
    {
        switch (nClassId)
        {
        case 403:
            if (nMode == 4)
            {
                return &gTrappedSoul_Attack_Callbacks;
            }

            if (nMode == 5)
            {
                return &gTrappedSoul_Attack_Callbacks;
            }

            if (nMode == 9)
            {
                return &gTrappedSoul_Skill_Callbacks;
            }

            if (nMode == 8)
            {
                return &gTrappedSoul_Skill_Callbacks;
            }
            break;

        case 417:
        case 418:
            if (nMode == 11)
            {
                return &gShadowMasterWarrior_Skill4_Callbacks;
            }
            break;

        case 243:
        case 333:
        case 705:
            if (nMode == 11)
            {
                return &gDiablo_Skill4_Callbacks;
            }

            if (nMode == 10)
            {
                return &gDiablo_Skill3_Callbacks;
            }
            break;

        case 543:
            if (nMode == 10)
            {
                return &gMonModeCallbacks[7];
            }
            break;

        case 544:
        case 570:
        case 709:
            if (nMode == 10)
            {
                return &gMonModeCallbacks[7];
            }
            break;

        default:
            break;
        }
    }

    return &gMonModeCallbacks[nMode];
}

#include "gen/data/Source/D2Game/005A5650_MONSTERMODE_GetHpPercent128.inc"
