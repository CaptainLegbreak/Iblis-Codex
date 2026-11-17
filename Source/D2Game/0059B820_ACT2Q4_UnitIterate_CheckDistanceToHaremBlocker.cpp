struct D2BitBufferStrc;
struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};
struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    int dwGameFrame;
};
struct D2PlayerDataStrc
{
    char unk0x00[0x10];
    D2BitBufferStrc* pQuestData[3];
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    unsigned int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};
struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32];
    unsigned short nPlayerCount;
    unsigned char pad0x82[2];
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
    unsigned char bStatusFlags;
    unsigned char pad0x15[3];
    void* pQuestDataEx;
    D2QuestGUIDStrc tPlayerGUIDs;
};
struct D2Act2Quest4Strc
{
    unsigned char unused0x00[4];
    unsigned char bDrognanActivated;
    unsigned char pad0x05[3];
    D2ActiveRoomStrc* pRoom;
    unsigned char bJerhynStartInitialized;
    unsigned char bJerhynPalaceInitialized;
    unsigned char bPalaceOpen;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char bHaremBlockerInitialized;
    unsigned char unk0x12[8];
    unsigned char bPlayerCloseToHaremBlocker;
    unsigned char pad0x1B;
    unsigned int nPlayerCloseToHaremBlockerGUID;
    D2CoordStrc pHaremBlockerCoords;
    D2CoordStrc pJerhynCoords;
    D2CoordStrc pGuardCoords;
    int nHaremBlockerGUID;
    int nJerhynGUID;
    unsigned short nHaremBlockerObjectMode;
    unsigned short nPortalModeInSanctuary;
    unsigned short nPortalModeInCellar;
    unsigned char bIsHaremBlockerNeutral;
    unsigned char pad0x47;
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY);                          // 0x005DC5C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

#define QUESTSTATEFLAG_A2Q6 14
#define QUEST_A2Q4_HORAZONTOME 11
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1

// 0x0059B820
int __fastcall ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME)->pQuestDataEx;

    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY) > 30)
    {
        return 0;
    }

    pQuestDataEx->bPlayerCloseToHaremBlocker = 1;
    pQuestDataEx->nPlayerCloseToHaremBlockerGUID = !pUnit ? -1 : pUnit->dwUnitId;
    return 1;
}
