struct D2QuestDataStrc
{
    int nQuestNo;
    char unk0x04[0xF0];
    D2QuestDataStrc* pPrev;
};

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
};

struct D2GameStrc
{
    char unk0x00[0x10F4];
    D2QuestInfoStrc* pQuestControl;
};

struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
};

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall sub_00594060_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00594060

static __forceinline D2QuestDataStrc* QUESTS_FindQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x00544990
void __fastcall sub_00544990_ObjInitCainGibbet(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_FindQuestData(pOp->pGame, 4);
    if (pQuestData)
    {
        sub_00594060_InitCainGibbet(pQuestData, pOp);
        return;
    }

    if (!pOp->pObject || pOp->pObject->dwAnimMode != 2)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}
