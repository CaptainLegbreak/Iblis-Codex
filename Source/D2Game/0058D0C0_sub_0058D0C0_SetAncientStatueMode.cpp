struct D2BitBufferStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char unk0x000[0xD8];
    unsigned int dwFrameCnt[8];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char unk0x0D[0x07];
    unsigned int dwFlags;
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    char unk0xA0[0x40];
    int nQuestFilter;
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated;
    unsigned char bQualKehkActivated;
    unsigned char unused0x02[0x0A];
    int nActivePortalCount;
    unsigned char unk0x10;
    unsigned char bActivatable;
    unsigned char pad0x12[2];
    int nAncientStatueGUID[3];
    int nAncientMonsterGUID[3];
    unsigned char bAncientMonsterSpawned[3];
    unsigned char pad0x2F;
    int nAncientStatueObjectMode[3];
    unsigned char bAncienStatueRespawned[3];
    unsigned char pad0x3F;
    int nAncientsSpawned;
    int nAncientsAlive;
    unsigned char bAncientsActivated;
    unsigned char unused0x49;
    unsigned char bQuestCompletedBefore;
    unsigned char pad0x4B;
    int nAltarObjectMode;
    int nAltarGUID;
    int nLivingPlayersOnSummit;
    unsigned char bSummitDoorInitialized;
    unsigned char pad0x59[3];
    int nSummitDoorGUID;
    int nSummitDoorObjectMode;
};

struct D2Act5Quest6Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    char unk0x84[0x14];
    unsigned char bLastPortalOpened;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern "C" const char gszA5Q5SourceFile[];
extern "C" const char gszA5Q6SourceFile[];
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer);
void __fastcall sub_00535430(D2GameStrc* pGame, D2UnitStrc* pPlayer);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage);
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate);
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate);
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam);
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp);
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);
int __fastcall ACT5Q6_UnitIterate_CreateLastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty);
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs);
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct);

static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwClassId;
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

static __forceinline int UNITS_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0;
    return pUnit->dwAnimMode;
}

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0058D0C0
static __declspec(noinline) void sub_0058D0C0_SetAncientStatueMode(D2Act5Quest5Strc* pQuestDataEx, D2ObjInitFnStrc* pOp)
{
    D2UnitStrc* pObject = pOp->pObject;
    int nIndex;
    switch (sub_00623C60(pObject))
    {
    case 0x1DA: nIndex = 1; break;
    case 0x1DB: nIndex = 0; break;
    case 0x1DC: nIndex = 2; break;
    default: return;
    }
    UNITS_ChangeAnimMode(pObject, pQuestDataEx->nAncientStatueObjectMode[nIndex]);
}

void __fastcall OBJECTS_InitFunction65_AncientStatue2(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[0] = UNITS_GetUnitId(pOp->pObject);
    sub_0058D0C0_SetAncientStatueMode(pQuestDataEx, pOp);
}

void __fastcall OBJECTS_InitFunction63_AncientStatue3(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[1] = UNITS_GetUnitId(pOp->pObject);
    sub_0058D0C0_SetAncientStatueMode(pQuestDataEx, pOp);
}

void __fastcall OBJECTS_InitFunction64_AncientStatue1(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[2] = UNITS_GetUnitId(pOp->pObject);
    sub_0058D0C0_SetAncientStatueMode(pQuestDataEx, pOp);
}

int __fastcall sub_0058D1E0_OperateAncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
    return 0;
}

int __fastcall sub_0058D200_OperateAncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
    return 0;
}

int __fastcall sub_0058D220_OperateAncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
    return 0;
}

void __fastcall OBJECTS_InitFunction72_AncientsAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return;
    }

    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nAltarGUID = UNITS_GetUnitId(pOp->pObject);
    UNITS_ChangeAnimMode(pOp->pObject, ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nAltarObjectMode);
}

void __fastcall OBJECTS_InitFunction73_AncientsDoor(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return;
    }

    if (((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bQuestCompletedBefore)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, 0);
    }
}

int __fastcall ACT5Q5_UnitIterate_ClosePortals(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, PLAYER_GetUniqueIdFromPlayerData(pUnit));
    if (!pPortal)
    {
        return 0;
    }

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal)) == 0x78)
    {
        sub_00535430(pGame, pUnit);
    }

    return 0;
}

int __fastcall OBJECTS_OperateFunction65_AncientsAltar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (pQuestData)
    {
        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
        {
            return 0;
        }

        if (!pQuestData->bNotIntro)
        {
            if (pQuestDataEx->nActivePortalCount > 0)
            {
                SUNIT_IterateUnitsOfType(pOp->pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
            }

            QUESTS_SendScrollMessage(pOp->pPlayer, pOp->pObject, 20002);
        }
        else if (pQuestData->fState < 4)
        {
            if (pQuestDataEx->nActivePortalCount > 0)
            {
                SUNIT_IterateUnitsOfType(pOp->pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
            }

            QUESTS_SendScrollMessage(pOp->pPlayer, pOp->pObject, 20002);

            if (pQuestData->fState < 2)
            {
                QUESTS_StateDebug(pQuestData, 2, gszA5Q5SourceFile, 1439);
            }

            if (pQuestData->fLastState != 3)
            {
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            }
        }

        if (!pOp->pObject || pOp->pObject->dwAnimMode == 0)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 1);
            pQuestDataEx->nAltarObjectMode = 2;
        }
    }

    return 0;
}

int __fastcall OBJECTS_OperateFunction66_AncientsDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (pQuestData)
    {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->nQuestFilter, 1))
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }

        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pQuestData->bNotIntro && !pQuestDataEx->bAncientsDefeated || pQuestDataEx->bAncientsActivated && !pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            return 0;
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        switch (UNITS_GetAnimMode(pOp->pObject))
        {
        case 0:
            UNITS_ChangeAnimMode(pOp->pObject, 1);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->pObject), 0);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
            break;

        case 2:
            D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->pObject), 1);
            return 0;
        }
    }

    return 0;
}

int __fastcall ACT5Q5_UnitIterate_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 0x11)
    {
        return 0;
    }

    ++((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, 0x23)->pQuestDataEx)->nLivingPlayersOnSummit;
    return 0;
}

int __fastcall OBJECTS_OperateFunction69_InvisibleAncient(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x27, 0))
    {
        pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->pPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x27, 4))
        {
            QUESTS_SendScrollMessage(pOp->pPlayer, pOp->pObject, 20169);
        }
    }
    return 0;
}

// build: context OBJECTS_InitFunction76_SummitDoor
void __fastcall OBJECTS_InitFunction76_SummitDoor(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->bSummitDoorInitialized = 1;
    pQuestDataEx->nSummitDoorGUID = UNITS_GetUnitId(pOp->pObject);
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nSummitDoorObjectMode);
    if (!pQuestDataEx->bAncientsDefeated && pQuestDataEx->nSummitDoorObjectMode != 2)
    {
        pQuestDataEx->nSummitDoorObjectMode = 2;
        UNITS_ChangeAnimMode(pOp->pObject, 1);
    }
}

int __fastcall OBJECTS_OperateFunction71_SummitDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    switch (UNITS_GetAnimMode(pOp->pObject))
    {
    case 0:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 1);
            pQuestDataEx->nSummitDoorObjectMode = 2;
            return 0;
        }

        D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
        return 0;

    case 2:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
        }
        else if (pQuestDataEx->bAncientsActivated)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 0);
            pQuestDataEx->nSummitDoorObjectMode = 0;
        }

    case 1:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->pPlayer, 19, pOp->pPlayer);
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
        else
        {
            pQuestDataEx->nSummitDoorObjectMode = 0;
            UNITS_ChangeAnimMode(pOp->pObject, 0);
        }
        return 0;
    }

    return 0;
}

int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 40, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 40, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 40, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 40, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 36);
    }
    return 0;
}

void __fastcall ACT5Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 0x209 && !pQuestDataEx->bLastPortalOpened)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, pQuestArg->pPlayer, ACT5Q6_UnitIterate_CreateLastPortal);
        pQuestDataEx->bLastPortalOpened = 1;
    }
}

void __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 40, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 40, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 40, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 40, 13);
    CLIENTS_UpdateCharacterProgression(SUNIT_GetClientFromPlayer(pUnit, gszA5Q6SourceFile, 384), 5, pGame->nDifficulty);
}

void __fastcall ACT5Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
}

// build: context ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers
int __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 40, 13))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q6_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

int __fastcall ACT5Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 40, 0) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 40, 14);
    QUESTS_SendLogUpdateEx(pUnit, 36, 0);
    return 0;
}
