#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"

struct D2QuestDataStrc { char unk_00[0x18]; void* pQuestDataEx; };
struct D2MapAIStrc { int unk_00; int nCount; };
struct D2Act5Quest3Strc
{
    char unk_00[0x84];
    int unk_84;
    char unk_88[9];
    unsigned char bDrehyaSpawned;
    char unk_92[2];
    int nDrehyaGUID;
    char unk_98[0x49];
    unsigned char bTownObjectInitialized;
    char unk_E2[2];
    int nTownObjectGUID;
    int nTownX;
    int nTownY;
    char unk_F0[0x14];
    D2MapAIStrc* pMapAI;
    int unk_108;
    unsigned char bMapAIChanged;
};
struct D2Act5Quest4Strc { char unk_00[0x87]; unsigned char bObjectEvent; };
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc*, int); // 0x00543640
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc*); // 0x00589160
D2UnitStrc* __fastcall sub_005459A0_SpawnMonsterNear(D2GameStrc*, int, int, D2ActiveRoomStrc*, int, int); // 0x005459A0
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc*); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc**, D2MapAIStrc*); // 0x00666120
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0

// 0x0058EAC0
void __fastcall sub_0058EAC0_InitDrehyaTownObject(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (pQuestData)
    {
        D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nTownObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        pQuestDataEx->bTownObjectInitialized = 1;
        pQuestDataEx->nTownX = pOp->nX;
        pQuestDataEx->nTownY = pOp->nY;
        switch (pQuestDataEx->unk_84)
        {
        case 2:
            ACT5Q3_SeqCallback(pQuestData);
            if (!pQuestDataEx->bDrehyaSpawned)
            {
                D2UnitStrc* pDrehya = sub_005459A0_SpawnMonsterNear(pOp->pGame, pOp->nX, pOp->nY, pOp->pRoom, 1, 512);
                if (pDrehya)
                {
                    pQuestDataEx->nDrehyaGUID = !pDrehya ? -1 : pDrehya->dwUnitId;
                    pQuestDataEx->bDrehyaSpawned = 1;
                    D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pDrehya);
                    if (pQuestDataEx->pMapAI && pQuestDataEx->pMapAI->nCount && !pQuestDataEx->bMapAIChanged)
                    {
                        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pMapAI, pMapAI);
                        pQuestDataEx->bMapAIChanged = 1;
                    }
                }
            }
            break;
        }
    }
    D2UnitStrc* pObject = pOp->pObject;
    D2GameStrc* pGame = pOp->pGame;
    D2QuestDataStrc* pOtherQuest = QUESTS_GetQuestData(pGame, 34);
    if (pOtherQuest && ((D2Act5Quest4Strc*)pOtherQuest->pQuestDataEx)->bObjectEvent)
        EVENT_SetEvent(pGame, pObject, 7, pGame->dwGameFrame + 12, 0, 0);
}
