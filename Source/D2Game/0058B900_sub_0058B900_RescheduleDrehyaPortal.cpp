#define QUEST_A5Q4_NIHLATHAK 0x22
#define EVENTTYPE_QUESTFN 7

struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    unsigned int dwGameFrame;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2Act5Quest4Strc
{
    char unk0x00[0x87];
    unsigned char bNeedsToOpenPortal;
    unsigned char bPortalCreated;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x0058B900
void __fastcall sub_0058B900_RescheduleDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (pQuestData && ((D2Act5Quest4Strc*)pQuestData->pQuestDataEx)->bNeedsToOpenPortal)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_QUESTFN, pGame->dwGameFrame + 12, 0, 0);
    }
}
