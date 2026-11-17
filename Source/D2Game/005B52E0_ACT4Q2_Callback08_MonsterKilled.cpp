struct D2DrlgActStrc;
struct D2BitBufferStrc;
struct D2UnitStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    char unk0x78[0x04];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    char unk0x74[0x34];
    unsigned int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0xD4];
    D2UnitStrc* pRoomNext;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nEventFlag;
    unsigned short unk0x16;
    int unk0x18;
    int unk0x1C;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2Act4Quest2Strc
{
    unsigned char bTalkedToTyrael;
    unsigned char bTimerCreated;
    unsigned char bNeedToSpawnDiablo;
    unsigned char unk0x03;
    unsigned char bNeedToEndGame;
    unsigned char bNeedToWarpPlayers;
    unsigned char bDiabloStartPointInitialized;
    unsigned char pad0x07;
    int nDiabloStartPointObjectGUID;
    unsigned char bSealActivated[5];
    unsigned char bDiabloSpawned;
    unsigned char unused0x12;
    unsigned char bSanctumCleared;
    unsigned char bDiabloKilled;
    unsigned char bClientsSaved;
    unsigned char pad0x16[2];
    unsigned int dwTickCount;
    int nPlayerCount;
    D2UnitStrc* unk0x20;
    D2CoordStrc pSealCoords[3];
    D2ActiveRoomStrc* pRoom;
    int nLastLastPortalObjectMode;
    unsigned char unk0x44;
    unsigned char bPortalToAct5Spawned;
    unsigned char pad0x46[2];
    int nBossesKilled;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    unsigned char bNotIntro;
    char unk0x0A[0x0E];
    void* pQuestDataEx;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks);           // 0x00543F10
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                               // 0x00543640
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                    // 0x0061A180
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);                        // 0x005B4BE0

typedef int(__fastcall* UNITITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuestData, int nPacket, D2UnitStrc* pUnit, UNITITERATEFN pfnCallback, int bCheck); // 0x00544300
void __fastcall sub_00545990(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, D2UnitStrc* pUnit, UNITITERATEFN pfnCallback); // 0x005537D0
int __fastcall ACT4Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);     // 0x005B4970
int __fastcall ACT4Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B49C0
int __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B4DF0
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);        // 0x005B4E40
int __fastcall sub_005B5140(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);                              // 0x005B5140
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pPlayer);                                       // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);             // 0x0065C310

// 0x005B5230
static void __stdcall ACT4Q2_KillAllMonstersInCS(D2GameStrc* pGame, D2Act4Quest2Strc* pQuestDataEx)
{
    if (pQuestDataEx->bSanctumCleared)
    {
        return;
    }

    pQuestDataEx->bSanctumCleared = 1;
    QUESTS_TriggerFX(pGame, 12);

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[3]); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == 108)
        {
            D2UnitStrc* pNext = 0;
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
            {
                pNext = pUnit->pRoomNext;
                if (pUnit->dwUnitType == 1 && pUnit->dwClassId != 243 && !SUNIT_IsDead(pUnit) && STATLIST_GetUnitAlignment(pUnit) == 0)
                {
                    D2ModeChangeStrc modeChange;
                    MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                }
            }
        }
    }
}

#define UNIT_CLASSID_OR_INVALID(pUnit) ((pUnit) ? (pUnit)->dwClassId : -1)

// build: context OBJECTS_OperateFunction52_DiabloSeal
int __fastcall OBJECTS_OperateFunction52_DiabloSeal(D2ObjOperateFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != 0)
    {
        return 0;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 7) + pOp->pGame->dwGameFrame, 0, 0);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;

    switch (UNIT_CLASSID_OR_INVALID(pOp->pObject))
    {
    case 392:
        pQuestDataEx->bSealActivated[0] = 1;
        break;
    case 393:
        pQuestDataEx->bSealActivated[1] = 1;
        break;
    case 394:
        pQuestDataEx->bSealActivated[2] = 1;
        break;
    case 395:
        pQuestDataEx->bSealActivated[3] = 1;
        break;
    case 396:
        pQuestDataEx->bSealActivated[4] = 1;
        break;
    default:
        break;
    }

    for (int nCounter = 0; nCounter < 5; ++nCounter)
    {
        if (!pQuestDataEx->bSealActivated[nCounter])
        {
            return 0;
        }
    }

    if (pQuestDataEx->nBossesKilled != 3)
    {
        return 0;
    }

    ACT4Q2_KillAllMonstersInCS(pOp->pGame, pQuestDataEx);
    if (pQuestDataEx->bTimerCreated)
    {
        return 0;
    }

    pQuestDataEx->dwTickCount = 0;
    pQuestDataEx->bNeedToSpawnDiablo = 1;
    pQuestDataEx->unk0x03 = 0;
    pQuestDataEx->bTimerCreated = 1;
    QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
    return 0;
}

// 0x005B52E0
void __fastcall ACT4Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (UNIT_CLASSID_OR_INVALID(pQuestArg->pTarget) != 243)
    {
        ++pQuestDataEx->nBossesKilled;
        if (pQuestDataEx->nBossesKilled != 3)
        {
            return;
        }

        for (int i = 0; i < 5; ++i)
        {
            if (!pQuestDataEx->bSealActivated[i])
            {
                return;
            }
        }

        ACT4Q2_KillAllMonstersInCS(pQuestData->pGame, pQuestDataEx);
        if (pQuestDataEx->bTimerCreated)
        {
            return;
        }

        pQuestDataEx->dwTickCount = 0;
        pQuestDataEx->bNeedToSpawnDiablo = 1;
        pQuestDataEx->unk0x03 = 0;
        pQuestDataEx->bTimerCreated = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
        return;
    }
    if (!pQuestData->pGame->bExpansion)
    {
        QUESTS_TriggerFX(pQuestData->pGame, 13);
    }

    pQuestDataEx->bDiabloKilled = 1;
    bool bQuestNotDone = false;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    pQuestDataEx->pRoom = pRoom;
    if (pQuestArg->pPlayer)
    {
        if (!((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bTimerCreated)
        {
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToSpawnDiablo = 0;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->unk0x03 = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToEndGame = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToWarpPlayers = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bClientsSaved = 0;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bTimerCreated = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->dwTickCount = GetTickCount();
            QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
        }

        if (!pQuestData->bNotIntro)
        {
            return;
        }

        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0))
        {
            bQuestNotDone = true;
        }
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    pQuestDataEx->nPlayerCount = 0;
    QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q2_UnitIterate_StatusCyclerEx, 1);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, sub_005B5140);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_AttachCompletionSound);
    if (!bQuestNotDone)
    {
        return;
    }

    for (int i = 0; i < pQuestDataEx->nPlayerCount; ++i)
    {
        sub_00545990(pQuestData, pQuestArg, 0x40);
    }
}
