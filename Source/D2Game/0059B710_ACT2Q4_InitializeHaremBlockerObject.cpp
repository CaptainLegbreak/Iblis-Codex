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
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
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
    int nPlayerCloseToHaremBlockerGUID;
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

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

#define UNIT_OBJECT 2
#define OBJECT_EUNUCH_HAREM_BLOCKER 318
#define OBJMODE_NEUTRAL 0
#define UNITFLAG_ISRESURRECT_ISINIT 0x03000000

// 0x0059B710
void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);
    if (pQuestDataEx->bPalaceOpen || pQuestDataEx->bHaremBlockerInitialized)
    {
        return;
    }

    pQuestDataEx->nHaremBlockerObjectMode = OBJMODE_NEUTRAL;
    pQuestDataEx->pHaremBlockerCoords.nX = pCoord.nX - 2;
    pQuestDataEx->pHaremBlockerCoords.nY = pCoord.nY - 1;

    D2UnitStrc* pHaremBlocker = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_EUNUCH_HAREM_BLOCKER, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY, pQuestData->pGame, UNITS_GetRoom(pUnit), 1, 0, 0);

    if (!pHaremBlocker)
    {
        pQuestDataEx->pHaremBlockerCoords.nY = pCoord.nY;
        pHaremBlocker = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_EUNUCH_HAREM_BLOCKER, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY, pQuestData->pGame, UNITS_GetRoom(pUnit), 1, 0, 0);
    }

    if (!pHaremBlocker)
    {
        return;
    }

    pHaremBlocker->dwFlags |= UNITFLAG_ISRESURRECT_ISINIT;
    pQuestDataEx->bHaremBlockerInitialized = 1;
    pQuestDataEx->nHaremBlockerGUID = !pHaremBlocker ? -1 : pHaremBlocker->dwUnitId;
}
