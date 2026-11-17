struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2AiControlStrc;
struct D2StatListStrc;
struct D2DamageStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
};

struct D2QuestArgStrc;
struct D2QuestDataStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

struct D2QuestDataStrc
{
    char unk0x00[0x18];
    void* pQuestDataEx;
    char unk0x1C[0x84];
    QUESTCALLBACK pfCallback[15];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    unsigned short nNPCNo;
    unsigned short unk0x16;
    unsigned short nMessageIndex;
    unsigned short unk0x1A;
};

struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
};

extern "C" const char gszSkillDruidSourceFile[];                                                            // 0x006E30AC

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);          // 0x0065C360
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350
void __fastcall ACT3Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x005B8020
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                       // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);               // 0x00627260
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall sub_6FD15190(D2UnitStrc* pUnit, int nAiSpecialState);                                        // 0x0056E2F0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4);    // 0x005C0B50
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                    // 0x0056E900
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType);               // 0x0058F090

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005B8060
void __fastcall ACT3Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == 245)
    {
        switch (nMessageIndex)
        {
        case 543:
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 504);
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 2);
            ((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->bInitiallyTalkedToCain = 1;
            pQuestData->pfCallback[2] = ACT3Q2_Callback02_NpcDeactivate;
            break;

        case 545:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 3);
            break;

        case 544:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 6);
            break;

        case 546:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 4);
            break;

        case 547:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 5);
            break;

        case 548:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 7);
            break;

        default:
            return;
        }
    }
}

// 0x005C01D0
int __fastcall SKILLITEM_EventFunc28_HealAfterKill(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, (unsigned int)nSkillId >> 16, nSkillId);
    if (!nValue)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pAttacker);
    int nHitpoints = STATLIST_UnitGetStatValue(pAttacker, 6, 0);
    if (nHitpoints >= nMaxHp)
    {
        return 0;
    }

    nHitpoints += nValue << 8;
    nHitpoints = nHitpoints > 0 ? nHitpoints : 0;
    STATLIST_SetUnitStat(pAttacker, 6, nHitpoints < nMaxHp ? nHitpoints : nMaxHp, 0);
    UNITS_SetOverlay(pAttacker, 151, 0);
    return 1;
}

// 0x005C31F0
int __fastcall sub_005C31F0_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != 0)
    {
        return 0;
    }

    if (!sub_6FD15190(pTarget, 19))
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return sub_00554200(pGame, pUnit, pTarget) != 0;
}

// 0x005C3370
void __fastcall sub_6FD0B250(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (pUnit)
    {
        SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

        const int nType = pUnit ? pUnit->dwUnitType : 6;
        if (nType == 1)
        {
            AITHINK_ExecuteAiFn(SUNIT_GetGameFromUnit(pUnit), pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
        }

        sub_6FD10E50(pUnit, nState, pStatList);
    }
}

// 0x005C3D50
int __fastcall sub_005C3D50_IsValidTerrorTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    const int nType = pTarget ? pTarget->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != 0)
    {
        return 0;
    }

    if (!sub_00554200(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    return sub_6FD15190(pTarget, 11) != 0;
}

// 0x005C6BF0
int __fastcall sub_005C6BF0_GetConvertedMode(D2UnitStrc* pUnit, int nMode)
{
    int nUnitType;
    int nClassId;
    int nNewMode = nMode;

    int nTypeValue;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
        if (nTypeValue == 0)
        {
            return nMode;
        }
    }
    else
    {
        nTypeValue = 6;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nNewMode, gszSkillDruidSourceFile, 156);
    return nNewMode;
}

// 0x005D8510
int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    if (!sub_6FD15190(pUnit, 12))
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int nOwnerGUID;
    int nOwnerType;
    AIGENERAL_GetOwnerData(pUnit, &nOwnerGUID, &nOwnerType);

    if (nOwnerGUID != -1 && nOwnerType == 0)
    {
        return 0;
    }

    return 1;
}
