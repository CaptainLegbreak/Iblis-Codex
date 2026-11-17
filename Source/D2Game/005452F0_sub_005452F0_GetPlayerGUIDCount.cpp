extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2QuestDataStrc;
struct D2QuestInfoStrc;

typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x0000[0x1C];
    void* pMemoryPool;
    char unk0x0020[0x10D4];
    D2QuestInfoStrc* pQuestControl;
};

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
};

struct D2QuestTimerStrc
{
    QUESTUPDATE pfUpdate;
    D2QuestDataStrc* pQuest;
    unsigned int dwTicks;
    unsigned int dwTimeout;
    D2QuestTimerStrc* pNext;
};

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    void* pQuestFlags;
    D2QuestTimerStrc* pTimer;
};

extern int dword_6FD4DC34;                                                                                  // 0x008846DC
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall sub_6FC84C70(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A930
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

// 0x005452F0
int __fastcall sub_005452F0_GetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs)
{
    return pGUIDs->nPlayerCount;
}

// 0x005454E0
void __fastcall sub_005454E0_RemoveItemFromRoom(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
    UNITS_FreeCollisionPath(pItem);
    UNITROOM_RemoveUnitFromRoom(pItem);
    if (pItem)
        pItem->dwFlags &= ~2;
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
}

// 0x00545FA0
void __fastcall sub_00545FA0_RemoveTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfUpdate)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;

    D2_ASSERT(!pQuestControl->bExecuting, 1068);

    D2QuestTimerStrc* pPrev = 0;
    for (D2QuestTimerStrc* pTimer = pQuestControl->pTimer; pTimer; pTimer = pTimer->pNext)
    {
        if (pTimer->pfUpdate == pfUpdate && pTimer->pQuest == pQuest)
        {
            if (!pPrev)
                pQuestControl->pTimer = pTimer->pNext;
            else
                pPrev->pNext = pTimer->pNext;
            FOG_FreeServerMemory(pQuest->pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 1086, 0);
            return;
        }
        pPrev = pTimer;
    }

    if (dword_6FD4DC34)
        sub_6FC84C70(pGame, "Error in timer usage", 4);
}
