#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

#define QUEST_A5Q5_ANCIENTS 35
#define STAT_LEVEL 12

struct D2ModeChangeStrc;
struct D2Act5Quest5Strc;
struct D2ObjOperateFnStrc;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2ObjInitFnStrc;
struct D2Act5Quest6Strc;
struct D2GameStrc;
struct D2CoordStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2DataTablesStrc;
struct D2ObjectsTxt;
struct D2QuestArgStrc;




struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
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
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    char unk0xA0[0x40];
    int eFilter;
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

struct D2DataTablesStrc
{
    char unk0x000[0xB36];
    unsigned short wAncientSuperUniqueIds[3];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2); // 0x005544B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex); // 0x00545C30
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall ACT5Q5_UnitIterate_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D510

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    D2UnitStrc* hPlayer;
    void* pObjectregion;
    int nObjectIdx;
};

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
int __fastcall ACT5Q5_UnitIterate_ClosePortals(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D2C0

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};


struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act5Quest6Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    char unk0x84[0x14];
    unsigned char bLastPortalOpened;
};

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern "C" const char gszA5Q5SourceFile[];
extern "C" const char gszA5Q6SourceFile[];
int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer); // 0x005353F0
void __fastcall sub_00535430(D2GameStrc* pGame, D2UnitStrc* pPlayer);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058BE20
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp); // 0x0059D9D0
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId); // 0x00544190
int __fastcall ACT5Q6_UnitIterate_CreateLastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D7D0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570880
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel); // 0x00611800
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

// 0x0058BEC0
static bool sub_0058BEC0_RemoveAncientMonster(D2GameStrc* pGame, int nAncientMonsterGUID)
{
    D2UnitStrc* pAncientMonster = SUNIT_GetServerUnit(pGame, 1, nAncientMonsterGUID);
    if (!pAncientMonster)
    {
        return false;
    }

    if (STATES_CheckState(pAncientMonster, 0x36))
    {
        sub_6FCBDE90(pAncientMonster, 0);
    }

    if (UNITS_GetRoom(pAncientMonster))
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pAncientMonster, 0x0C, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pAncientMonster), 1, nAncientMonsterGUID);
        UNITS_FreeCollisionPath(pAncientMonster);
        UNITROOM_RemoveUnitFromRoom(pAncientMonster);
    }

    return true;
}

// 0x0058C000
static void __stdcall ACT5Q5_DeactivateAncientMonsters(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2Act5Quest5Strc* pQuestDataEx)
{
    for (int i = 0; i < 0x03; ++i)
    {
        if (pQuestDataEx->bAncientMonsterSpawned[i])
        {
            if (sub_0058BEC0_RemoveAncientMonster(pGame, pQuestDataEx->nAncientMonsterGUID[i]))
            {
                --pQuestDataEx->nAncientsSpawned;
                --pQuestDataEx->nAncientsAlive;
            }
            else
            {
                SUNITINACTIVE_DeleteSingleListNode(pGame, 1, i + 0x21C, 0x04);
            }

            pQuestDataEx->bAncientMonsterSpawned[i] = 0;
        }
    }

    pQuestDataEx->bAncientsActivated = 0;

    for (int i = 0; i < 0x03; ++i)
    {
        pQuestDataEx->bAncienStatueRespawned[i] = 0;
        D2UnitStrc* pAncientStatue = SUNIT_GetServerUnit(pQuestData->pGame, 0x02, pQuestDataEx->nAncientStatueGUID[i]);
        if (pAncientStatue)
        {
            UNITS_ChangeAnimMode(pAncientStatue, 0);
        }
        pQuestDataEx->nAncientStatueObjectMode[i] = 0;
    }

    pQuestDataEx->nAltarObjectMode = 0;
    D2UnitStrc* pAltar = SUNIT_GetServerUnit(pGame, 0x02, pQuestDataEx->nAltarGUID);
    if (pAltar)
    {
        UNITS_ChangeAnimMode(pAltar, 0);
    }
}

void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if ((pUnit && pUnit->dwAnimMode == 0x04) || pQuestDataEx->nAncientsSpawned >= 0x03)
    {
        return;
    }

    const int nObjectId = !pUnit ? -1 : pUnit->dwClassId;

    D2UnitStrc* pAncient;
    D2CoordStrc tCoord;
    int nIndex = 0;
    int nMonsterId = 0;
    switch (nObjectId)
    {
    case 0x1DA:
        nIndex = 1;
        nMonsterId = sgptDataTables->wAncientSuperUniqueIds[2];
        break;

    case 0x1DB:
        nIndex = 0;
        nMonsterId = sgptDataTables->wAncientSuperUniqueIds[0];
        break;

    case 0x1DC:
        nIndex = 0x02;
        nMonsterId = sgptDataTables->wAncientSuperUniqueIds[1];
        break;

    default:
        return;
    }

    if (pQuestDataEx->nActivePortalCount > 0)
    {
        ACT5Q5_DeactivateAncientMonsters(pQuestData->pGame, pQuestData, pQuestDataEx);
        return;
    }

    UNITS_GetCoords(pUnit, &tCoord);
    pAncient = QUESTS_SpawnMonster(pQuestData->pGame, pUnit, &tCoord, 0x02, nMonsterId);
    if (!pAncient)
    {
        EVENT_SetEvent(pQuestData->pGame, pUnit, 0x07, pQuestData->pGame->dwGameFrame + 0x0A, 0, 0);
        return;
    }

    if (!pUnit || pUnit->dwAnimMode != 0x04)
    {
        UNITS_ChangeAnimMode(pUnit, 0x04);
        pQuestDataEx->nAncientStatueObjectMode[nIndex] = 0x04;
    }

    pQuestDataEx->bAncientMonsterSpawned[pQuestDataEx->nAncientsSpawned] = 1;
    pQuestDataEx->nAncientMonsterGUID[pQuestDataEx->nAncientsSpawned] = pAncient ? pAncient->dwUnitId : -1;

    ++pQuestDataEx->nAncientsSpawned;
    ++pQuestDataEx->nAncientsAlive;

    pQuestDataEx->bAncientsActivated = 1;
}

// 0x0058CF00
void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bAncientsDefeated)
    {
        return;
    }

    ++((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount;
    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 0;
    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->unk0x10 = 0;
    ACT5Q5_DeactivateAncientMonsters(pGame, pQuestData, (D2Act5Quest5Strc*)pQuestData->pQuestDataEx);
}

// 0x0058CFB0
int __fastcall ACT5Q5_GetPortalCount(D2GameStrc* pGame)
{
    return ((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS)->pQuestDataEx)->nActivePortalCount;
}

// 0x0058CFD0
void __cdecl sub_0058CFD0_Nop()
{
}

// 0x0058CFE0
int __fastcall ACT5Q5_IsActivatable(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);

    return pQuestData && ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable;
}

// 0x0058D000
int __fastcall sub_0058D000_AreAncientsDefeated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (pQuestData)
    {
        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive)
        {
            return 1;
        }
    }
    return 0;
}

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

// 0x0058D110
void __fastcall OBJECTS_InitFunction65_AncientStatue2(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[0] = UNITS_GetUnitId(pOp->pObject);
    sub_0058D0C0_SetAncientStatueMode(pQuestDataEx, pOp);
}

// 0x0058D150
void __fastcall OBJECTS_InitFunction63_AncientStatue3(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[1] = UNITS_GetUnitId(pOp->pObject);
    sub_0058D0C0_SetAncientStatueMode(pQuestDataEx, pOp);
}

// 0x0058D190
void __fastcall OBJECTS_InitFunction64_AncientStatue1(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[2] = UNITS_GetUnitId(pOp->pObject);
    sub_0058D0C0_SetAncientStatueMode(pQuestDataEx, pOp);
}

// 0x0058D1D0
static __forceinline void sub_0058D1D0_PlayStatueSound(D2ObjOperateFnStrc* pOp)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
}

// 0x0058D1E0
int __fastcall sub_0058D1E0_OperateAncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    return 0;
}

// 0x0058D200
int __fastcall sub_0058D200_OperateAncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    return 0;
}

// 0x0058D220
int __fastcall sub_0058D220_OperateAncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    return 0;
}

// 0x0058D240
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

// 0x0058D280
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

// 0x0058D2C0
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

void __stdcall sub_M114_Emit_0058D1D0(D2ObjOperateFnStrc* pOp)
{
    sub_0058D1D0_PlayStatueSound(pOp);
}

// 0x0058D300
void __fastcall sub_0058D300_ClosePortals(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
}

// 0x0058D310
int __fastcall OBJECTS_OperateFunction65_AncientsAltar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (pQuestData)
    {
        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pOp->hObject && pOp->hObject->dwAnimMode != 0)
        {
            return 0;
        }

        if (!pQuestData->bNotIntro)
        {
            if (pQuestDataEx->nActivePortalCount > 0)
            {
                SUNIT_IterateUnitsOfType(pOp->pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
            }

            QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20002);
        }
        else if (pQuestData->fState < 4)
        {
            if (pQuestDataEx->nActivePortalCount > 0)
            {
                SUNIT_IterateUnitsOfType(pOp->pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
            }

            QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20002);

            if (pQuestData->fState < 2)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 1439);
            }

            if (pQuestData->fLastState != 3)
            {
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            }
        }

        if (!pOp->hObject || pOp->hObject->dwAnimMode == 0)
        {
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            pQuestDataEx->nAltarObjectMode = 2;
        }
    }

    return 0;
}

// 0x0058D400
int __fastcall OBJECTS_OperateFunction66_AncientsDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (pQuestData)
    {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pQuestData->bNotIntro && !pQuestDataEx->bAncientsDefeated || pQuestDataEx->bAncientsActivated && !pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        switch (UNITS_GetAnimMode(pOp->hObject))
        {
        case 0:
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 0);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
            break;

        case 2:
            D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 1);
            return 0;
        }
    }

    return 0;
}

// 0x0058D510
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

// 0x0058D560
void __fastcall ACT5Q5_OnPlayerDied(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != 0x78)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nActivePortalCount || pQuestDataEx->bAncientsDefeated || !pQuestDataEx->bActivatable)
    {
        return;
    }

    pQuestDataEx->nLivingPlayersOnSummit = 0;
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT5Q5_UnitIterate_CountLivingPlayers);

    if (!pQuestDataEx->nLivingPlayersOnSummit)
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 0;
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->unk0x10 = 0;
        ACT5Q5_DeactivateAncientMonsters(pGame, pQuestData, (D2Act5Quest5Strc*)pQuestData->pQuestDataEx);
    }
}

// 0x0058D5E0
int __fastcall OBJECTS_OperateFunction69_InvisibleAncient(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x27, 0))
    {
        pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x27, 4))
        {
            QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20169);
        }
    }
    return 0;
}

// 0x0058D640
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

// 0x0058D6A0
int __fastcall OBJECTS_OperateFunction71_SummitDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    switch (UNITS_GetAnimMode(pOp->hObject))
    {
    case 0:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            pQuestDataEx->nSummitDoorObjectMode = 2;
            return 0;
        }

        D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
        return 0;

    case 2:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        }
        else if (pQuestDataEx->bAncientsActivated)
        {
            UNITS_ChangeAnimMode(pOp->hObject, 0);
            pQuestDataEx->nSummitDoorObjectMode = 0;
        }

    case 1:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            UNITS_ChangeAnimMode(pOp->hObject, 2);
        }
        else
        {
            pQuestDataEx->nSummitDoorObjectMode = 0;
            UNITS_ChangeAnimMode(pOp->hObject, 0);
        }
        return 0;
    }

    return 0;
}

// 0x0058D770
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

// 0x0058D870
void __fastcall ACT5Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 0x209 && !pQuestDataEx->bLastPortalOpened)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, pQuestArg->pPlayer, ACT5Q6_UnitIterate_CreateLastPortal);
        pQuestDataEx->bLastPortalOpened = 1;
    }
}

// 0x0058DC60
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
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 384), 5, pGame->nDifficulty);
}

// 0x0058DCF0
void __fastcall ACT5Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
}

// 0x0058DD90
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

// 0x0058DDE0
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

static __declspec(noinline)
// 0x0058C5C0
void __stdcall ACT5Q5_RewardPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    int nRewardExp = 1400000;
    switch (pGame->nDifficulty)
    {
    case 1:
        nRewardExp = 20000000;
        break;
    case 2:
        nRewardExp = 40000000;
        break;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    const int nMaxLevel = DATATBLS_GetMaxLevel(nClassId);
    int nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nCurrentLevel >= nMaxLevel)
    {
        return;
    }

    const unsigned int nNextThreshold = DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel + 1);
    const int nDeltaExpThreshold = nNextThreshold - DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel);
    if (nRewardExp > nDeltaExpThreshold)
    {
        nRewardExp = nDeltaExpThreshold;
    }

    do
    {
        if (!nRewardExp)
        {
            break;
        }

        const int nNextExp = STATLIST_GetUnitBaseStat(pUnit, STAT_NEXTEXP, 0);
        const unsigned int nDeltaExp = nNextExp - STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        if ((unsigned int)nRewardExp >= nDeltaExp)
        {
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNextExp, 0);
            STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nDeltaExp, 0);
            PLAYERSTATS_LevelUp(pGame, pUnit);
            nRewardExp -= nDeltaExp;
            nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }
        else
        {
            nRewardExp += STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nRewardExp, 0);
            nRewardExp ^= nRewardExp;
        }
    }
    while (nCurrentLevel < nMaxLevel);
}

void __fastcall sub_Emit_0058C5C0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        ACT5Q5_RewardPlayer(pGame, pUnit);
    }
}
