#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);            // 0x0065C310
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
bool __fastcall sub_0059AC80_ACT2Q3_IsAltarDestroyed(D2QuestDataStrc* pQuest);                              // 0x0059AC80

// 0x0059DFD0
int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bPortalIsOpening == 1)
    {
        int nX;
        int nY;
        D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[1], LEVEL_LUTGHOLEIN, 12, &nX, &nY, 3);
        if (pRoom)
        {
            sub_6FC385A0(pGame, pRoom);
            pRoom = COLLISION_GetFreeCoordinatesEx(pRoom, pCoord, 3, 0xBE11, 7);
            if (pRoom)
            {
                pCoord->nX = nX;
                pCoord->nY = nY;
                *ppRoom = pRoom;
                return 1;
            }
        }
    }

    return 0;
}
