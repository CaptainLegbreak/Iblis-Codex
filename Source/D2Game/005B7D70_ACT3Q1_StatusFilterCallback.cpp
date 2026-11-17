struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
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

struct D2Act3Quest1Strc
{
    unsigned char bCanGetReward;
    unsigned char bTomeDropped;
    unsigned char bTomeActive;
    unsigned char unused0x03;
    unsigned char bTomeAcquired;
    unsigned char bPlayerWithTomeDropped;
    unsigned char pad0x06[2];
    int nTomesInGame;
};

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110
void __fastcall ACT3Q1_UnitIterate_CheckForTomeItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);     // 0x005B7D40
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

// 0x005B7D70
bool __fastcall ACT3Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 17, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 17, 13) ? 13 : 11;
        return true;
    }

    *pStatus = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, 0x20626262))
    {
        *pStatus = 2;
        return true;
    }

    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuest->pQuestDataEx;
    unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId != 0xFFFF)
    {
        pQuestDataEx->bTomeAcquired = 0;
        PARTY_IteratePartyMembers(pQuest->pGame, nPartyId, ACT3Q1_UnitIterate_CheckForTomeItem, 0);
        if (pQuestDataEx->bTomeAcquired)
        {
            *pStatus = 2;
            return true;
        }
    }

    if (pQuest->bNotIntro)
    {
        if (pQuest->fState <= 3)
        {
            *pStatus = 1;
            if (pQuestDataEx->bTomeActive == 1 && !pQuestDataEx->nTomesInGame)
            {
                *pStatus = (pQuest->pGame->nGameType != 3) + 8;
                return true;
            }
        }
        else
        {
            *pStatus = 12;
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if (pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == 2 && pQuestDataEx->nTomesInGame)
            {
                *pStatus = 1;
            }
        }
    }

    return true;
}
