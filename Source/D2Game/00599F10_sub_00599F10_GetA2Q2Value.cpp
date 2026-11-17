struct D2GameStrc;

struct D2Act2Quest2Strc
{
    int unused0x00[5];
    int nItemDropCount;
    int nBaseStaffs;
    int nCubedStaffs;
    int nHoradricCubes;
    int nAmulets;
    unsigned char bBaseStaffDropped;
    unsigned char bCubeDropped;
    unsigned char bStaffCubed;
    unsigned char bStaffMissingDetected;
    int nPlayerGUID;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    unsigned char nActNo;
    bool bNotIntro;
    bool bActive;
    unsigned char fLastState;
    unsigned char fState;
    char nInitNo;
    unsigned short dw0E;
    int nSeqId;
    unsigned int dwFlags;
    void* pQuestDataEx;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nQuest); // 0x00543640

// 0x00599F10
void __fastcall sub_00599F10_GetA2Q2Value(D2GameStrc* pGame, int* pnValue, unsigned char* pbFlag)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 9);
    if (pQuestData)
    {
        *pnValue = ((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nHoradricCubes;
        *pbFlag = ((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->bCubeDropped;
    }
    *pnValue = 0;
    *pbFlag = 1;
}
