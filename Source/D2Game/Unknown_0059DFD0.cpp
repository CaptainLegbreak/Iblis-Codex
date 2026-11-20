#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"


struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2Act2Quest6Strc
{
    char unk0x00[0x3C];
    unsigned char bPortalIsOpening;
};

struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
    int nBaseStaffs;
    int nCubedStaffs;
    int nHoradricCubes;
    int nAmulets;
    unsigned char bHoradricScrollDropped;
    unsigned char bCubeDropped;
};

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
        D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[1], 40, 12, &nX, &nY, 3);
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

// 0x0059E630
bool __fastcall ACT2Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 7, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 10, 0) || QUESTRECORD_GetQuestState(pFlags, 10, 1))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, 14, 0))
        {
            *pStatus = QUESTRECORD_GetQuestState(pFlags, 10, 10) ? 5 : 6;
            return true;
        }

        *pStatus = QUESTRECORD_GetQuestState(pFlags, 10, 13) ? 13 : 11;
        return true;
    }

    *pStatus = 0;

    D2UnitStrc* pHoradricScroll = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1rt');
    D2UnitStrc* pBaseStaff = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' fsm');
    D2UnitStrc* pBox = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' xob');
    D2UnitStrc* pAmulet = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' piv');
    D2UnitStrc* pCubedStaff = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' tsh');
    const int bLeaveTown = QUESTRECORD_GetQuestState(pFlags, 10, 3);

    if (pBaseStaff && pBox && pAmulet)
    {
        if (QUESTRECORD_GetQuestState(pFlags, 10, 6))
        {
            *pStatus = 3;
        }
        else
        {
            *pStatus = bLeaveTown ? 2 : 4;
        }

        return true;
    }

    if (pCubedStaff)
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 10, 10) ? 5 : 6;
        return true;
    }

    if (pHoradricScroll && !QUESTRECORD_GetQuestState(pFlags, 10, 3))
    {
        *pStatus = 1;
        return true;
    }

    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuest->pQuestDataEx;
    if (pQuestDataEx->bCubeDropped && !pQuestDataEx->nHoradricCubes || !pQuestDataEx->nAmulets && sub_0059AC80_ACT2Q3_IsAltarDestroyed(pQuest) || pQuestDataEx->bHoradricScrollDropped && !pQuestDataEx->nBaseStaffs)
    {
        *pStatus = 9;
    }

    if (bLeaveTown)
    {
        *pStatus = 2;
        return true;
    }

    if (pAmulet || pBaseStaff || pBox)
    {
        *pStatus = 4;
    }

    return true;
}
