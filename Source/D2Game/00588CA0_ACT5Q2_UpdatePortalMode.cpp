#define nullptr 0
typedef int (__stdcall* FARPROC)();

struct D2BitBufferStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x6D - 0x20];
    unsigned char nDifficulty;
    char unk0x6E[0xA8 - 0x6E];
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
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xC4 - 0x14];
    unsigned int dwFlags;
    char unk0xC8[0xE8 - 0xC8];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
    void* pObjectregion;
    void* pObjectTxt;
    int nX;
    int nY;
};

struct D2QuestGUIDStrc
{
    int nPlayerGUIDs[32];
    unsigned short nGUIDCount;
    unsigned short unk0x82;
};

struct D2Act5Quest2Strc
{
    D2QuestGUIDStrc tPlayerGUIDs;
    unsigned char bQualKehkActivated;
    char unk0x85[0xA8 - 0x85];
    int nKilledWussies;
    int nFreedWussies;
    int nWussieGUIDs[3][5];
    int nPortalGUIDs[3];
    unsigned char bPortalSpawned[3];
    unsigned char pad0xFB;
    int nPortalUpdateInvocations[3];
    unsigned char unk0x108[3];
    unsigned char bChangeToSpecialObjectMode[3];
    unsigned char unk0x10E[6];
    int unk0x114[3];
    int nFreedWussieUnitGUIDs[15];
    int nWussiesInRangeToDoor;
};

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

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
    D2QuestGUIDStrc tPlayerGUIDs;
    QUESTCALLBACK pfCallback[15];
    void* pNPCMessages;
    int nQuestFilter;
    int unk0xE4;
    QUESTSTATUSFILTER pfStatusFilter;
    QUESTACTIVEFILTER pfActiveFilter;
    QUESTSEQFILTER pfSeqFilter;
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame;
    int nEvent;
    D2UnitStrc* pTarget;
    D2UnitStrc* pPlayer;
    unsigned int unk0x10;
    int nOldLevel;
    int nNewLevel;
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __fastcall sub_005417D0_DirectDated(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0

// 0x00588CA0
void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pPortal)
{
    const int nUnitGUID = !pPortal ? -1 : pPortal->dwUnitId;
    int nCounter = 0;
    do
    {
        if (nUnitGUID == ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nPortalGUIDs[nCounter])
        {
            goto found;
        }
        ++nCounter;
    }
    while (nCounter < 3);
    return;

found:
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    switch (!pPortal ? 0 : pPortal->dwAnimMode)
    {
    case 1:
        UNITS_ChangeAnimMode(pPortal, 2);
        break;

    case 2:
        if (pQuestDataEx->unk0x108[nCounter] == 1)
        {
            ++pQuestDataEx->nPortalUpdateInvocations[nCounter];
        }
        if (pQuestDataEx->nPortalUpdateInvocations[nCounter] > 5)
        {
            pQuestDataEx->bChangeToSpecialObjectMode[nCounter] = 1;
        }
        if (pQuestDataEx->bChangeToSpecialObjectMode[nCounter])
        {
            UNITS_ChangeAnimMode(pPortal, 3);
        }
        break;

    case 3:
        UNITS_ChangeAnimMode(pPortal, 4);
        break;
    }

    sub_005417D0_DirectDated(pQuestData->pGame, pPortal, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
}
