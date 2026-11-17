struct D2GameStrc;
struct D2ObjectControlStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xE4];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
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
    unsigned int dwFlags;
    void* pQuestDataEx;
};

struct D2Act2Quest4Strc
{
    char unk0x00[0x42];
    unsigned short nPortalModeInSanctuary;
    unsigned short nPortalModeInCellar;
};

#define QUEST_A2Q4_HORAZONTOME 11
#define LEVEL_PALACECELLARLEV3 54
#define LEVEL_ARCANESANCTUARY 74
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define UNIT_TILE 5

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile);                // 0x005550B0

// 0x0059BAF0
void __fastcall ACT2Q4_SetPortalMode(D2GameStrc* pGame, int nLevelId)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        if (!pQuestDataEx->nPortalModeInCellar)
        {
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPERATING;
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPENED;
        }
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        if (!pQuestDataEx->nPortalModeInSanctuary)
        {
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPERATING;
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPENED;
        }
    }
}

// 0x0059D9D0
void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp)
{
    for (D2UnitStrc* i = UNITS_GetRoom(pOp->pObject)->pUnitFirst; i; i = i->pRoomNext)
    {
        if (i->dwUnitType == UNIT_TILE)
        {
            SUNIT_WarpPlayer(pOp->pGame, pOp->pPlayer, i);
        }
    }
}
