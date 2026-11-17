struct D2GameStrc;
struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;
typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

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
    char tPlayerGUIDs[0x84];
    QUESTCALLBACK pfCallback[15];
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
};

struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized;
    unsigned char bInitiallyTalkedToCain;
    unsigned char pad0x02[2];
    int nSewerStairsObjectGUID;
    int nSewerStairsObjectMode;
    int nItemDropCount;
    int nEyesDropped;
    int nBrainsDropped;
    int nHeartsDropped;
    int nFlailsDropped;
    int nCubedFlails;
    unsigned char bEyeDropped;
    unsigned char bBrainDropped;
    unsigned char bHeartDropped;
    unsigned char bFlailDropped;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110

#define QUEST_A3Q2_KHALIMFLAIL 16

// 0x005B8500
int __fastcall sub_005B8500_IsSewerStairsClosed(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData && pQuestData->bNotIntro)
        return ((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nSewerStairsObjectMode != 2;
    return 0;
}

// 0x005B8750
int __fastcall sub_005B8750_LacksKhalimFlail(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ITEMS_FindQuestItem(pGame, pUnit, ' 2fq') == 0;
}

// 0x005B8B00
void __fastcall sub_005B8B00_AddFlailsDropped(D2GameStrc* pGame, int nCount)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nFlailsDropped += nCount;
        pQuestDataEx->bFlailDropped = 1;
    }
}
