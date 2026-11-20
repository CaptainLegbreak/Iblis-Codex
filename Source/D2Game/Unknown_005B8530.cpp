#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};
struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
    unsigned char pad0x02[2];
    int nSewerStairsObjectGUID;
    int nSewerStairsObjectMode;
};
struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* hObject;
    int unk0x08[2];
    int nObjectIdx;
};
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId); // 0x00552F60
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char nEffect); // 0x00545760

// 0x005B8530
int __fastcall sub_005B8530_OperateSewerLever(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->hObject;
    if (!pObject || !pObject->dwAnimMode)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 16);
        if (pQuestData)
        {
            D2Act3Quest2Strc* pQuestDataEx = static_cast<D2Act3Quest2Strc*>(pQuestData->pQuestDataEx);
            if (pQuestDataEx->bSewerStairsInitialized != 1)
            {
                return 0;
            }

            if (SUNIT_GetServerUnit(pOp->pGame, 2, pQuestDataEx->nSewerStairsObjectGUID))
            {
                UNITS_ChangeAnimMode(pOp->hObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
                EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
                pQuestDataEx->nSewerStairsObjectMode = 2;
                EVENT_SetEvent(pOp->pGame, pOp->hObject, 7, pOp->pGame->dwGameFrame + 30, 0, 0);
                QUESTS_TriggerFX(pQuestData->pGame, 9);
            }
        }
    }

    return 0;
}
