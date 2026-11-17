struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2ClientStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;
struct D2MapAIStrc;
struct D2TextHeaderStrc;
struct D2QuestInfoStrc;
struct D2ObjectControlStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x4C];
    unsigned int dwLastHitClass;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x10D0];
    D2ObjectControlStrc* pObjectControl;
    D2QuestInfoStrc* pQuestControl;
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
};

typedef void (__fastcall* QUESTUPDATE)(D2QuestDataStrc* pQuest);

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
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2LevelsTxt
{
    char unk0x00[0x30];
    unsigned char nQuest;
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom;
    int nX;
    int nY;
    D2ObjectRoomCoordStrc* pNext;
};

struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
    int nShrines;
    int nWells;
    int nTrapMonsterId;
    D2CoordStrc wellCoordinates[4];
    D2CoordStrc shrineCoordinates[10];
};

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
    char unk0x1048[0xC8];
    D2ObjectRoomCoordStrc* pObjectRoomCoord;
};

struct D2MonsterRegionStrc
{
    char unk0x000[0x2C8];
    unsigned int dwUniqueCount;
    unsigned int dwMonSpawnCount;
    char unk0x2D0[0x08];
    unsigned char nQuest;
};

struct D2GSPacketSrv29
{
    unsigned char nHeader;
    unsigned char pData[96];
};

struct D2PackedGuidStrc
{
    unsigned short f_0;
    unsigned short f_2;
};

struct D2MessageStrc
{
    unsigned char nMenu;
    unsigned char pad0x01;
    unsigned short nStringId;
};

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x00681CE0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern "C" const char gszQuestsSourceFile[];                                                                // 0x006E0BE4
extern "C" const char gszObjRgnSourceFile[];                                                                // 0x006E0C40
extern "C" const char gszPlrMsgSourceFile[];                                                                // 0x006E1050
int dword_6FD4DC34;                                                                                         // 0x008846DC
extern const D2UnkPlrMsgStrc stru_6FD30708[];                                                               // 0x007319E8
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall sub_6FC84C70(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A930
void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestFlags, unsigned char* pBuffer, int nBufferSize, int nUnused); // 0x0065C560
void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket);   // 0x0053D700
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00593CB0
void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x0059D6A0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket);   // 0x0053C8D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket);                              // 0x0053D710
int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x0059DB20
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit);                          // 0x005BBFA0
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel);        // 0x0058D090
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0058E640
int __stdcall DATATBLS_MapSuperUniqueId(int nType, int nSuperUnique);                                       // 0x00659B80
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600
void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi);        // 0x0058AD80
void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi);     // 0x0058AE10
void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi);        // 0x00587950
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall MONSTER_CheckSummonerFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00573540
int __fastcall MONSTER_GetLevelId(D2UnitStrc* pUnit);                                                       // 0x00573520
void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId);                                        // 0x00573500
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue); // 0x0053BE40
void __fastcall sub_6FC3D830(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue); // 0x0053C1D0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD50

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define STRCOLOR_DARK_GOLD 4
#define LEVEL_DURIELSLAIR 73
#define LEVEL_DURANCEOFHATELEV1 100
#define LEVEL_GLACIALCAVESLEV1 118
#define LEVEL_ROCKYSUMMIT 120
#define LEVEL_THEWORLDSTONEKEEPLEV1 128
#define LEVEL_THEWORLDSTONECHAMBER 132
#define OBJECT_DREHYA_START_IN_TOWN 459
#define OBJECT_NIHLATHAK_START_IN_TOWN 461
#define OBJECT_LARZUK_STANDARD 543
#define OBJRGN_WELL_DISTANCE 100
#define OBJRGN_SHRINE_DISTANCE 50
#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_NEUTRAL 1
#define UNIT_ALIGNMENT_GOOD 2
#define UNIT_ALIGNMENT_UNASSIGNED 4
#define MONTYPEFLAG_OTHER 1
#define IMODE_STORED 0
#define IMODE_EQUIP 1
#define IMODE_INBELT 2
#define IMODE_ONCURSOR 4

// 0x00544350
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine)
{
    char szMsg[128];
    pQuestData->fState = nState;
    wsprintfA(szMsg, "changing state to %d\n", nState);
    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pQuestData->pGame, szMsg, STRCOLOR_DARK_GOLD);
    }
}

// 0x00545CD0
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return;
    }

    const unsigned char nQuestId = DATATBLS_GetLevelsTxtRecord(nLevelId)->nQuest;
    if (!nQuestId)
    {
        return;
    }

    if (bDebug)
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 0)
        {
            return;
        }
    }
    else
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 1)
        {
            return;
        }
    }

    if (dword_6FD4DC34)
    {
        sub_6FC84C70(pGame, "Error attaching to unit", STRCOLOR_DARK_GOLD);
    }
}
