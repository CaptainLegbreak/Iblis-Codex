#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };
struct D2QuestExStrc { char unk00[3]; unsigned char f_3; unsigned char bSpawning; unsigned char bTimerStarted; };
struct D2QuestDataStrc { char unk00[9]; unsigned char bNotIntro; char unk0A[2]; unsigned char fState; char unk0D[0xB]; D2QuestExStrc* pQuestDataEx; };
struct D2ObjOperateFnStrc { D2GameStrc* pGame; D2UnitStrc* hObject; D2UnitStrc* hPlayer; int unk0C; int nObjectIdx; };
struct D2ObjectsTxt { char unk00[0xDC]; unsigned int dwFrameCnt3; };
typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc*, D2QuestDataStrc*);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc*, QUESTUPDATE, int); // 0x00543F10
bool __fastcall sub_005B9A30_QuestSeqCallback(D2GameStrc*, D2QuestDataStrc*); // 0x005B9A30
void __fastcall SUNIT_AttachSound(D2UnitStrc*, int, D2UnitStrc*); // 0x00553380
inline D2BitBufferStrc* GetPlayerQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}
// 0x005B9B40
int __fastcall sub_005B9B40_OperateQuestObject(D2ObjOperateFnStrc* pOp)
{
    if (pOp->hObject && pOp->hObject->dwAnimMode)
        return 0;
    if (QUESTRECORD_GetQuestState(GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 19, 0)
        || QUESTRECORD_GetQuestState(GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 19, 7)
        || QUESTRECORD_GetQuestState(GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 19, 8))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pOp->pGame, 17);
    if (pQuest && pQuest->bNotIntro)
    {
        if (!pQuest->fState)
            pQuest->fState = 1;
        D2QuestExStrc* pEx = pQuest->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxt->dwFrameCnt3 >> 8), 0, 0);
        pEx->f_3 = 1;
        if (!pEx->bTimerStarted)
        {
            pEx->bTimerStarted = 1;
            QUESTS_CreateTimer(pQuest, sub_005B9A30_QuestSeqCallback, 7);
        }
    }
    return 0;
}
