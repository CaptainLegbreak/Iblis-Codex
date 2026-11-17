#ifdef MOVED_TEST
#define PREFIX char movedPrefix[4];
#define QUEST_ID 26
#define STATE_A 15
#define STATE_B 4
#define STATE_C 5
#define FALLBACK_MODE 5
#define ITERATE_STATE 4
#else
#define PREFIX
#define QUEST_ID 24
#define STATE_A 13
#define STATE_B 2
#define STATE_C 3
#define FALLBACK_MODE 3
#define ITERATE_STATE 2
#endif
struct D2GameStrc; struct D2UnitStrc; struct D2ActiveRoomStrc;
struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};
struct D2QuestDataStrc
{
    PREFIX
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
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
};
struct D2ObjInitFnStrc
{
    PREFIX
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
};
struct D2Act4Quest3Strc
{
    PREFIX
    unsigned short nHellforgeMode;
    unsigned char bCainActivated;
    char pad0x03[0x0D];
    int nHellforgeHammersInGame;
    char pad0x14[0x08];
    unsigned char bSoulstoneAcquired;
};
typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);        // 0x005B59C0
// 0x005B5A20
void __fastcall sub_005B5A20_InitHellforge(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pOp->pGame, QUEST_ID);
    if (pQuest && pQuest->bNotIntro)
    {
        D2Act4Quest3Strc* pEx = (D2Act4Quest3Strc*)pQuest->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->pObject, pEx->nHellforgeMode);
        if (pQuest->fLastState != STATE_A && pQuest->fLastState != STATE_B && pQuest->fLastState != STATE_C)
        {
            pQuest->bStatusFlags = 0;
            QUESTS_UnitIterate(pQuest, ITERATE_STATE, 0, ACT4Q3_UnitIterate_StatusCyclerEx, true);
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, FALLBACK_MODE);
    }
}
