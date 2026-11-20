#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2QuestExtraStrc;


struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
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
    unsigned char nActNo;
    unsigned char bNotIntro;
    unsigned char bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    D2QuestExtraStrc* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
    void* pCallback[16];
    int eFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q6SourceFile[]; // 0x006E2F7C
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
int __fastcall sub_005BC020_UpdatePlayerQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC020
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC210
void __fastcall ACT3Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC370
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

struct D2QuestExtraStrc { char unk00[0xC]; int nState; int nMode; };

struct D2ActiveRoomStrc { char unk00[0x74]; D2UnitStrc* pUnitFirst; };

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned int __stdcall D2Common_10399(D2UnitStrc*, D2UnitStrc*); // 0x00641530
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc*); // 0x00623830
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0

// build: context ACT3Q6_CycleStatusFromLastState
static __forceinline int ACT3Q6_CycleStatusFromLastState(D2QuestDataStrc* pQuestData)
{
    int bResult = 0;
    if (pQuestData->fLastState == 2)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        bResult = 1;
    }
    else if (pQuestData->fLastState == 0)
    {
        pQuestData->bStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        bResult = 1;
    }
    return bResult;
}

// 0x005BC3C0
void __fastcall ACT3Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == 75)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState > 1 && pQuestData->fState <= 3)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
            {
                return;
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 11) == 1)
            {
                return;
            }

            if (pQuestData->fLastState < 3)
            {
                pQuestData->bStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 0);
            }

            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 364);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 368);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, sub_005BC020_UpdatePlayerQuestFlags);
        }
    }

    if (nNewLevel >= 98 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
        pQuestData->pCallback[2] = ACT3Q6_Callback02_NpcDeactivate;
    }

    if (nNewLevel == 100)
    {
        int bUpdate = ACT3Q6_CycleStatusFromLastState(pQuestData);

        if (pQuestData->fState == 1)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 400);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 404);
            }
            bUpdate = 1;
        }

        if (bUpdate)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, sub_005BC020_UpdatePlayerQuestFlags);
        }
    }
    else if (nNewLevel == 102)
    {
        if (pQuestData->fLastState != 4)
        {
            pQuestData->bStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        }

        if (pQuestData->fState != 4 && pQuestData->fState != 5)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 426);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 430);
            }
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, sub_005BC020_UpdatePlayerQuestFlags);
    }
}

static __forceinline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : 6;
}

// 0x005BCAC0
void __fastcall sub_005BCAC0_UpdateQuestObject(D2QuestDataStrc* pQuest, D2UnitStrc* pObject)
{
    D2QuestExtraStrc* pEx = pQuest->pQuestDataEx;
    if (pEx->nState == 2)
    {
        const int nMode = !pObject ? 0 : pObject->dwAnimMode;
        if (nMode == 2) return;
        for (D2UnitStrc* pUnit = UNITS_GetRoom(pObject)->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            if (UNITS_GetUnitTypeInline(pUnit) == 0 && D2Common_10399(pUnit, pObject) < 18)
            {
                if (nMode == 0)
                {
                    pEx->nMode = 2;
                    UNITS_ChangeAnimMode(pObject, 1);
                }
                else if (nMode == 1)
                {
                    pEx->nMode = 2;
                    UNITS_ChangeAnimMode(pObject, 2);
                    UNITS_FreeCollisionPath(pObject);
                }
                EVENT_SetEvent(pQuest->pGame, pObject, 7, pQuest->pGame->dwGameFrame + 24, 0, 0);
                return;
            }
        }
    }
    EVENT_SetEvent(pQuest->pGame, pObject, 7, pQuest->pGame->dwGameFrame + 24, 0, 0);
}
