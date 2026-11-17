enum D2C_F41AiUtilConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    UNITFLAG_CANBEATTACKED = 4,
    MONTYPEFLAG_UNIQUE_SUPERUNIQUE = 10,
    STATE_UNINTERRUPTABLE = 54,
    STATE_TERROR = 56,
    SKILL_TERROR = 77,
    AISPECIALSTATE_TERROR = 11,
    EVENTTYPE_AITHINK = 2,
};

struct D2ClientStrc;
struct D2StatListStrc;
struct D2MonStatsTxt;
struct D2AiControlStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
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
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x48];
    D2ClientStrc** ppClients;
    char unk0x4C[0x2C];
    unsigned int nNumClients;
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);
typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2VileMotherAiCallbackArgStrc
{
    int nLastInClass;
    int nMaxDistance;
    int nCounter;
};

struct D2PartyCallbackArgStrc
{
    AIUTIL_TargetCallback pfCallback;
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    void* unk0x0C;
};

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource);      // 0x005DC380
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __fastcall UNITS_CanSwitchAI(int nMonsterId);                                                           // 0x00623470
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiSpecialState, int bCheckIfSuperUnique); // 0x005B0DA0
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse);                                               // 0x0056E970
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005DCE10
D2UnitStrc* __fastcall sub_6FCF1E30(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2VileMotherAiCallbackArgStrc* pArg = (D2VileMotherAiCallbackArgStrc*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pTarget->dwClassId != pArg->nLastInClass)
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    if (AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    pArg->nCounter += 1;
    return 0;
}

// 0x005DCEE0
D2UnitStrc* __stdcall sub_005DCEE0_FindPlayerTargetInAdjacentRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        const unsigned int nNumClients = ppRoomList[i]->nNumClients;
        D2ClientStrc** ppClients = ppRoomList[i]->ppClients;
        for (unsigned int j = 0; j < nNumClients; ++j)
        {
            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(ppClients[j], 0);
            if (pPlayer)
            {
                D2UnitStrc* pTarget = pfCallback(pGame, pUnit, pPlayer, pCallbackArg);
                if (pTarget)
                {
                    return pTarget;
                }
            }
        }
    }

    return 0;
}

// 0x005DD020
void __fastcall sub_6FCF20E0(D2UnitStrc* pUnit, void* pArg, void* ppUnit)
{
    D2PartyCallbackArgStrc* pPartyCallbackArg = (D2PartyCallbackArgStrc*)pArg;
    D2UnitStrc** ppResult = (D2UnitStrc**)ppUnit;
    if (*ppResult)
    {
        return;
    }

    D2GameStrc* pGame = pPartyCallbackArg->pGame;
    D2UnitStrc* pOwner = pPartyCallbackArg->pUnit;
    AIUTIL_TargetCallback pfCallback = pPartyCallbackArg->pfCallback;
    void* pCallbackArg = pPartyCallbackArg->unk0x0C;
    D2UnitStrc* pResult = pfCallback(pGame, pOwner, pUnit, pCallbackArg);
    if (pResult)
    {
        *ppResult = pResult;
    }
}

// 0x005DDD00
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nParam1, int nDuration)
{
    if (SUNIT_IsDead(pTarget))
    {
        return;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    if (STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    if (!UNITS_CanSwitchAI(pTarget->dwClassId))
    {
        return;
    }

    if (!sub_00451F30_TestUnitFlag(pTarget, UNITFLAG_CANBEATTACKED) && !SUNIT_IsDead(pTarget))
    {
        return;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE_SUPERUNIQUE))
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (!AITHINK_CanUnitSwitchAi(pTarget, pMonStatsTxtRecord, AISPECIALSTATE_TERROR, 1))
    {
        return;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkillLevel = 1;
    curse.nDuration = nDuration;
    curse.nStat = -1;
    curse.nSkill = SKILL_TERROR;
    curse.nState = STATE_TERROR;
    sub_0056E970(&curse);

    UNITS_SetTargetUnitForDynamicUnit(pTarget, pUnit);

    D2AiControlStrc* pAiControl = (pTarget->dwUnitType == UNIT_MONSTER && pTarget->pMonsterData) ? pTarget->pMonsterData->pAiControl : 0;
    AITHINK_ExecuteAiFn(pGame, pTarget, pAiControl, AISPECIALSTATE_TERROR);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pTarget, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
}
