#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"

#pragma intrinsic(strcpy)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define CLIENTFLAGEX_PLAYER_UNIT_ALIVE 0x01
#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define CLIENTFLAGEX_ARENA_RELATED 0x04
#define ASSERT(x,line) if(!(x)){sub_00408A60(&data_006CC837,sub_00408090(),line);sub_00681E09(-1);}
#define PREVIEW_VERSION 0x0E
#define STAT_LEVEL 0x0C
#define PREVIEW_COPY_SIZE 0x0B
#define PREVIEW_MAX_LEVEL_INDEX 98
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 0x11
#define CLIENTSAVEFLAG_HARDCORE 0x04
#define CLIENTSAVEFLAG_DEAD 0x08
#define CLIENTSAVEFLAG_INVALID_1 0x01
#define CLIENTSAVEFLAG_INVALID_2 0x02
#define CLIENTSAVEFLAG_INVALID_10 0x10
#define PREVIEW_STRING_LENGTH 0x21

struct D2CorpseStrc;
struct D2SkillListStrc;
struct D2ServerCallbackFunctions;
struct D2DrlgCoordsStrc;
struct D2ObjectControlStrc;
struct D2W11RoomTileRecordStrc;
struct D2W11RoomTileOwnerStrc;
struct D2W11QuestEx5B7230Strc;
struct D2W11QuestEx5BD040Strc;
struct D2StaticPathStrc;
struct D2ClientUnitUpdateStrc;
struct D2ClientUnitUpdateSortStrc;
struct Client;
struct Obj00538650;
struct Pad40_00539070;
struct Obj00539070;
struct Obj00539080;
struct Obj00539110;
struct Obj00539120;
struct Obj00539130;
struct Obj00539140;
struct Obj00539190;
struct Obj005391C0;
struct Obj00539210;
struct Pad40_00539220;
struct Pad400_00539220;
struct Obj00539220;
struct Pad40_00539230;
struct Pad400_00539230;
struct Obj00539230;
struct D2PacketDataStrc;
struct Obj005392D0;
struct Pad40_005392E0;
struct Obj005392E0;
struct Obj00539300;
struct Obj00539310;
struct D2CharacterPreviewRecordStrc;
struct D2CriticalSectionStrc;
struct D2UnitStrc;
struct D2ClientStrc;
struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2ObjectsTxt;
struct D2MapAIStrc;
struct D2QuestDataStrc;
struct D2CoordStrc;
struct Obj00539150;
struct Obj00539170;
union D2PackedClientSaveFlags;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};


#pragma pack(push, 1)
struct D2ClientUnitUpdateStrc
{
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned short nX;
    unsigned short nY;
};

#pragma pack(pop)
union D2PackedClientSaveFlags
{
    unsigned short nPackedValue;
    struct
    {
        unsigned short bInit : 1;
        unsigned short bUnkFlag0x02 : 1;
        unsigned short bHardcore : 1;
        unsigned short bDead : 1;
        unsigned short bUnkFlag0x10 : 1;
        unsigned short bExpansion : 1;
        unsigned short bLadder : 1;
        unsigned short bUnkFlag0x80 : 1;
        unsigned short nProgression : 5;
        unsigned short bWeaponSwitch : 1;
        unsigned short nDONOTUSEBITS : 2;
    };
};

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char unk_08[0x2];
    union
    {
        unsigned short nSaveFlags;
        D2PackedClientSaveFlags tSaveFlags;
    };
    unsigned char nByte0C;
    char szName[16];
    char unk0x01D[0x3];
    int nResult_020;
    char unk0x024[0x64];
    int nValue_088;
    int nValue_08C;
    char unk0x090[0xDC];
    int dwUnitType;
    int dwUnitGUID;
    D2UnitStrc* pPlayer;
    char unk0x178[0x30];
    D2GameStrc* pGame;
    unsigned char bAct;
    unsigned char nByte1AD;
    unsigned char unk_1AE[0x6];
    D2ActiveRoomStrc* hRoom;
    union
    {
        int nEmitterTag;
        D2PacketDataStrc* pPacketDataHead;
    };
    D2PacketDataStrc* pPacketDataTail;
    unsigned char unk_1C0[0xC];
    D2ClientUnitUpdateStrc unitUpdate[55];
    char pad0x3BB;
    unsigned int nUnitUpdateIndex;
    unsigned char unk_3C0[0x14];
    union
    {
        unsigned int dwFlags;
        unsigned char nFlags;
    };
    unsigned char unk_3D8[0x86];
    unsigned short nGuildFlags;
    unsigned int f_460;
    char unk0x464[0x480 - 0x464];
    unsigned char nGuildBgColor;
    unsigned char nGuildFgColor;
    unsigned char f_482;
    unsigned char unk_483[0x1];
    int nIronGolemItemGUID;
    unsigned char unk_488[0x20];
    D2ClientStrc* pNext;
    D2ClientStrc* pServerNext;
    D2ClientStrc* pServerNextByName;
};

struct D2GameStrc
{
    char unk0x00[0x88];
    D2ClientStrc* pClientList;
    unsigned char unk_8C[0x30];
    D2DrlgActStrc* pAct[5];
    char unk0xD0[0x1C];
    int unk0xEC;
    unsigned char unk_F0[0x1000];
    D2ObjectControlStrc* pObjectControl;
    void sub_00546FF0_SendQuestText(const char* szText);                                                    // 0x00546FF0
};

struct D2ServerCallbackFunctions
{
    char unk0x00[0x34];
    int (__stdcall* pfGetValue)();
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString); // 0x004112C0
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
extern D2ClientStrc* gpClientListByName_00883EA8[256]; // 0x00883EA8
extern D2ClientStrc* gpClientList_008842A8[256]; // 0x008842A8
extern D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8
extern int gbClientListInitialized_008846D8; // 0x008846D8
extern D2CriticalSectionStrc gSrvClientListByNameLock_008846C0; // 0x008846C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;

    void sub_0053E2C0_WriteBool(int bValue);
};

struct D2ObjectControlStrc
{
    char unk0x0000[0x1048];
    unsigned short wGroupCount[0x61];
    unsigned short wRoomsTried;
    unsigned short wRoomsNoGroup;
};


struct D2W11RoomTileRecordStrc
{
    char unk0x00[0x18];
    int nTileX;
    int nTileY;
    int nArg1;
    int nArg2;
};

struct D2W11RoomTileOwnerStrc
{
    char unk0x00[0x14];
    D2W11RoomTileRecordStrc* pRecord;
};

struct D2MapAIStrc
{
    int nPathNodes;
    void* pPosition;
};


struct D2W11QuestEx5B7230Strc
{
    unsigned char unk0x00;
    unsigned char bNpcSpawned;
    unsigned char unk0x02[0x0A];
    int nNpcGUID;
    unsigned char bMapAIChanged;
    unsigned char unk0x11[0x07];
    D2MapAIStrc* pMapAI;
};

struct D2W11QuestEx5BD040Strc
{
    unsigned char unk0x00[0x20];
    unsigned char bNpcSpawned;
    unsigned char unk0x21[0x03];
    D2MapAIStrc* pMapAI;
    int unk0x28;
    int nNpcGUID;
    unsigned char bMapAIChanged;
};

typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

extern OBJECTPOPULATEFN sgPopulateTable[10]; // 0x00731D00
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall sub_0063E510_InventoryGridQuery(D2UnitStrc* pUnit, unsigned char* pFirst, unsigned char* pSecond); // 0x0063E510
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120
void __fastcall sub_005531E0_FixRoomIfInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005531E0
void __fastcall sub_0053AAA0_UpdateRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget); // 0x0053AAA0
void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom); // 0x0061A110
void __stdcall D2Common_10077(D2ActiveRoomStrc* pOldRoom, D2ActiveRoomStrc* pNewRoom); // 0x0061A9F0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nFlags); // 0x006221E0


struct D2ClientUnitUpdateSortStrc
{
    D2UnitStrc* pUnit;
    unsigned int nDistance;
    int nNextIndex;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall ARENA_SendScoresToClient(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0053FC70

struct Client {char pad[0x1A8];Game* game;char pad1AC[8];Room* room;};

extern const char data_006CC837; // 0x006CC837
__declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09
Unit* __stdcall sub_00537860(Client*,int); // 0x00537860
Room* __fastcall sub_005545C0(Game*,Unit*); // 0x005545C0
void __stdcall sub_00619790(Room*,Room***,unsigned int*); // 0x00619790
void __fastcall sub_00571F90(Game*,Unit*,Client*); // 0x00571F90

struct Obj00538650 { unsigned char bUnknown00[0x0A]; unsigned short wFlags0A; };

struct Pad40_00539070 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00539070 {
    Pad40_00539070 tPad000;
    Pad40_00539070 tPad040;
    unsigned int dwUnknown80;
    unsigned int dwUnknown84;
    unsigned int dwValue88;
};

struct Obj00539080 { unsigned char bUnknown00[0x4A8]; unsigned int dwValue4A8; };

#pragma pack(push, 1)
struct Obj00539110 { unsigned char bUnknown00[0x45E]; unsigned short wValue45E; };

struct Obj00539120 { unsigned char bUnknown00[0x45E]; unsigned short wValue45E; };

#pragma pack(pop)
struct Obj00539130 { unsigned char bUnknown00[0x460]; unsigned int dwValue460; };

struct Obj00539140 { unsigned char bUnknown00[0x460]; unsigned int dwValue460; };

struct Obj00539190 { unsigned char bUnknown00[0x480]; unsigned char b480; unsigned char b481; unsigned char b482; };

struct Obj005391C0 { unsigned char bUnknown00[0x480]; unsigned char b480; unsigned char b481; unsigned char b482; };

struct Obj00539210 { unsigned char bUnknown00[0x508]; unsigned int dwValue508; };

struct Pad40_00539220 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Pad400_00539220 {
    Pad40_00539220 t000;
    Pad40_00539220 t040;
    Pad40_00539220 t080;
    Pad40_00539220 t0C0;
    Pad40_00539220 t100;
    Pad40_00539220 t140;
    Pad40_00539220 t180;
    Pad40_00539220 t1C0;
    Pad40_00539220 t200;
    Pad40_00539220 t240;
    Pad40_00539220 t280;
    Pad40_00539220 t2C0;
    Pad40_00539220 t300;
    Pad40_00539220 t340;
    Pad40_00539220 t380;
    Pad40_00539220 t3C0;
};

struct Obj00539220 {
    Pad400_00539220 tPad000;
    Pad40_00539220 tPad400;
    unsigned int dwUnknown440;
    unsigned int dwUnknown444;
    unsigned int dwUnknown448;
    unsigned int dwUnknown44C;
    unsigned int dwUnknown450;
    unsigned int dwUnknown454;
    unsigned int dwUnknown458;
    unsigned char nValue45C;
};

struct Pad40_00539230 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Pad400_00539230 {
    Pad40_00539230 t000;
    Pad40_00539230 t040;
    Pad40_00539230 t080;
    Pad40_00539230 t0C0;
    Pad40_00539230 t100;
    Pad40_00539230 t140;
    Pad40_00539230 t180;
    Pad40_00539230 t1C0;
    Pad40_00539230 t200;
    Pad40_00539230 t240;
    Pad40_00539230 t280;
    Pad40_00539230 t2C0;
    Pad40_00539230 t300;
    Pad40_00539230 t340;
    Pad40_00539230 t380;
    Pad40_00539230 t3C0;
};

struct Obj00539230 {
    Pad400_00539230 tPad000;
    Pad40_00539230 tPad400;
    unsigned int dwUnknown440;
    unsigned int dwUnknown444;
    unsigned int dwUnknown448;
    unsigned int dwUnknown44C;
    unsigned int dwUnknown450;
    unsigned int dwUnknown454;
    unsigned int dwUnknown458;
    unsigned char nValue45C;
};

struct D2PacketDataStrc
{
    char unk0x000[0x204];
    D2PacketDataStrc* pNext;
};

struct Obj005392D0 { unsigned char bUnknown00[0x1BC]; unsigned int dwValue1BC; };

struct Pad40_005392E0 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj005392E0 {
    Pad40_005392E0 tPad000;
    Pad40_005392E0 tPad040;
    Pad40_005392E0 tPad080;
    Pad40_005392E0 tPad0C0;
    Pad40_005392E0 tPad100;
    Pad40_005392E0 tPad140;
    unsigned int dwUnknown180;
    unsigned int dwUnknown184;
    unsigned int dwUnknown188;
    unsigned int dwUnknown18C;
    unsigned int dwUnknown190;
    unsigned int dwUnknown194;
    unsigned int dwUnknown198;
    unsigned int dwUnknown19C;
    unsigned int dwUnknown1A0;
    unsigned int dwUnknown1A4;
    unsigned int dwUnknown1A8;
    unsigned int dwUnknown1AC;
    unsigned int dwUnknown1B0;
    unsigned int dwUnknown1B4;
    unsigned int dwValue1B8;
};

struct Obj00539300 { unsigned char bUnknown00[0x60]; unsigned int dwValue60; };

struct Obj00539310 { unsigned char bUnknown00[0x68]; unsigned int dwValue68; };


unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom); // 0x005381F0
void __fastcall sub_6FC7BFC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nPlayerGUID, D2CoordStrc* pCoord); // 0x005352C0
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x7E_6FC3F770(D2ClientStrc* pClient, int nUnused); // 0x0053DB70
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate); // 0x00554850
void __fastcall sub_005773D0_UpdateMercForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005773D0
D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short wName, int nSeed, unsigned short wVersion, int nBaseMonster, int bDead); // 0x005774F0
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7);
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int nTileIndex, int* pX, int* pY, int nUnitSize); // 0x0061B060
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00620C10
int __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, unsigned int nUnitId, unsigned int a3); // 0x0063D4E0
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630
extern "C" unsigned short __stdcall sub_0063D650(D2CorpseStrc* pCorpse); // 0x0063D650
extern "C" unsigned int __stdcall sub_0063D670(D2CorpseStrc* pCorpse); // 0x0063D670
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

#pragma pack(push, 1)
struct D2CharacterPreviewRecordStrc
{
    unsigned char pComponents[0x0B];
    unsigned char nClass;
    unsigned char pComponentColors[0x0B];
    unsigned char nLevel;
    unsigned char nClientFlags[2];
    unsigned char nGuildFlags[2];
    unsigned char nGuildBgColor;
    unsigned char nGuildFgColor;
    unsigned char f_1E;
    unsigned int f_1F;
};

#pragma pack(pop)

extern "C" void __stdcall sub_006BBF40(unsigned char* pBuffer, unsigned int nValue); // 0x006BBF40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
void __stdcall sub_0063E510_FillInventoryTables(D2UnitStrc* pUnit, unsigned char* pTableA, unsigned char* pTableB);
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
extern "C" char* __cdecl strcpy(char*, const char*);

struct Obj00539150 { unsigned char bUnknown00[0x464]; char szName464[1]; };

struct Obj00539170 { unsigned char bUnknown00[0x464]; char szName464[1]; };

static void __stdcall sub_00537D10_InsertUnitUpdate(D2UnitStrc* pRoomUnit, int nX, int nY, unsigned int* pMaxDistance, D2ClientStrc* pClient, unsigned int nUpdateSize, D2ClientUnitUpdateSortStrc* pSort);

static int CLIENTS_GetUnitX_Inlined(D2UnitStrc* pUnit);
static int CLIENTS_GetUnitY_Inlined(D2UnitStrc* pUnit);

D2CriticalSectionStrc gSrvClientListByNameLock_008846C0; // 0x008846C0

// 0x005376C0
void __fastcall CLIENTS_Initialize()
{
    InitializeCriticalSection(&gClientListLock_008846A8);

    EnterCriticalSection(&gClientListLock_008846A8);
    for (int i = 0; i < 256; ++i)
    {
        gpClientList_008842A8[i] = 0;
    }
    LeaveCriticalSection(&gClientListLock_008846A8);

    InitializeCriticalSection(&gSrvClientListByNameLock_008846C0);

    EnterCriticalSection(&gSrvClientListByNameLock_008846C0);
    for (int i = 0; i < 256; ++i)
    {
        gpClientListByName_00883EA8[i] = 0;
    }
    LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);

    gbClientListInitialized_008846D8 = 1;
}

D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8

// 0x00537730
void __fastcall CLIENTS_Release()
{
    DeleteCriticalSection(&gClientListLock_008846A8);
    DeleteCriticalSection(&gSrvClientListByNameLock_008846C0);
    gbClientListInitialized_008846D8 = 0;
}

// 0x00537760
D2ClientStrc* __fastcall sub_00537760_GetClientFromId(int nClientId)
{
    EnterCriticalSection(&gClientListLock_008846A8);
    for (D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return pClient;
        }
    }
    LeaveCriticalSection(&gClientListLock_008846A8);
    return 0;
}

// 0x005377A0
void __fastcall sub_005377A0_UnlockClientList(int nClientId)
{
    LeaveCriticalSection(&gClientListLock_008846A8);
}

static D2ClientStrc* __fastcall CLIENTS_GetClientFromClientListWithId(D2ClientStrc* pClientList, int nClientId)
{
    for (D2ClientStrc* pClient = pClientList; pClient != 0; pClient = pClient->pNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return pClient;
        }
    }

    return 0;
}

// 0x00537810
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* ptGame, int nClientId)
{
    D2_ASSERT(ptGame, 0xE9);
    return CLIENTS_GetClientFromClientListWithId(ptGame->pClientList, nClientId);
}

// 0x00537860
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* ptClient, int bIgnoreDeath)
{
    D2_ASSERT(ptClient, 251);

    if (ptClient->dwFlags & CLIENTFLAGEX_PLAYER_UNIT_ALIVE)
    {
        return ptClient->pPlayer;
    }

    if (bIgnoreDeath)
    {
        return ptClient->pPlayer;
    }

    if (!ptClient->pPlayer)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(ptClient->pGame, ptClient->dwUnitType, ptClient->dwUnitGUID);
    if (!pPlayer)
    {
        ptClient->pPlayer = 0;
    }

    return pPlayer;
}

// 0x005378E0
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* ptClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(ptClient, 0x114);

    if (pUnit)
    {
        ptClient->dwUnitType = pUnit->dwUnitType;
        ptClient->dwUnitGUID = pUnit->dwUnitId;
        ptClient->pPlayer = pUnit;
    }
    else
    {
        ptClient->pPlayer = 0;
    }
}

// 0x005379A0
void __fastcall sub_005379A0_ResetClient(D2ClientStrc* pClient)
{
    pClient->nValue_08C = 0;
    pClient->nValue_088 = 0;
    if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfGetValue)
    {
        pClient->nResult_020 = gpD2EventCallbackTable_6FD45830->pfGetValue();
    }
}

// 0x005379D0
int __fastcall sub_005379D0_QueryGridFirst(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pGrid, unsigned int nSize)
{
    unsigned char abOther[16];
    D2_ASSERT(nSize >= 16 && pUnit, 0x3D4);
    memset(pGrid, 0xFF, 16);
    return sub_0063E510_InventoryGridQuery(pUnit, pGrid, abOther);
}

// 0x00537A40
int __fastcall sub_00537A40_QueryGridSecond(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pGrid, unsigned int nSize)
{
    unsigned char abOther[16];
    D2_ASSERT(nSize >= 16 && pUnit, 0x3DF);
    memset(pGrid, 0xFF, 16);
    return sub_0063E510_InventoryGridQuery(pUnit, abOther, pGrid);
}

// 0x00537AB0
static __forceinline void sub_00537AB0_ChangeClientRooms(D2ActiveRoomStrc* pNewRoom, D2ActiveRoomStrc* pOldRoom)
{
    DUNGEON_ChangeClientRoom(pOldRoom, pNewRoom);
    D2Common_10077(pOldRoom, pNewRoom);
}

void __fastcall sub_M124_Emit_00537AB0(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom)
{
    if (pClient->hRoom != pRoom)
    {
        sub_00537AB0_ChangeClientRooms(pRoom, pClient->hRoom);
        pClient->hRoom = pRoom;
    }
}

// 0x00537B00
static __forceinline void sub_00537B00_UpdatePlayerPortalFlags(D2ClientStrc* pClient)
{
    D2ActiveRoomStrc* pRoom = pClient->hRoom;
    if (pRoom && pClient->pPlayer)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nFlags = UNITS_GetPlayerPortalFlags(pClient->pPlayer);
        nFlags |= DUNGEON_GetPortalFlagFromLevelId(nLevelId);
        UNITS_SetPlayerPortalFlags(pClient->pPlayer, nFlags);
    }
}

// 0x00537D10
static void __stdcall sub_00537D10_InsertUnitUpdate(D2UnitStrc* pRoomUnit, int nX, int nY, unsigned int* pMaxDistance, D2ClientStrc* pClient, unsigned int nUpdateSize, D2ClientUnitUpdateSortStrc* pSort)
{
    const int nType = pRoomUnit ? pRoomUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        return;
    }
    const int nDeltaX = nX - CLIENTS_GetUnitX_Inlined(pRoomUnit);
    const int nAbsX = nDeltaX < 0 ? -nDeltaX : nDeltaX;
    const int nDeltaY = nY - CLIENTS_GetUnitY_Inlined(pRoomUnit);
    const int nAbsY = nDeltaY < 0 ? -nDeltaY : nDeltaY;
    const unsigned int nDistance = nAbsY + nAbsX;
    if (pClient->nUnitUpdateIndex >= nUpdateSize && nDistance >= *pMaxDistance)
    {
        return;
    }
    int nPrevIndex = 0;
    while (pSort[nPrevIndex].nNextIndex)
    {
        if (nDistance <= pSort[pSort[nPrevIndex].nNextIndex].nDistance)
        {
            break;
        }
        nPrevIndex = pSort[nPrevIndex].nNextIndex;
    }
    int nNewIndex;
    if (pClient->nUnitUpdateIndex == nUpdateSize)
    {
        int nLastIndex = 0;
        int* const pHead = &pSort[0].nNextIndex;
        if (pSort[pSort[0].nNextIndex].nNextIndex)
        {
            int* p = pHead;
            do
            {
                nLastIndex = *p;
                p = &pSort[nLastIndex].nNextIndex;
            } while (pSort[pSort[nLastIndex].nNextIndex].nNextIndex);
        }
        D2ClientUnitUpdateSortStrc* pLast = &pSort[nLastIndex];
        nNewIndex = pLast->nNextIndex;
        if (pClient->nUnitUpdateIndex && nDistance >= pSort[nNewIndex].nDistance)
        {
            return;
        }
        if (pClient->nUnitUpdateIndex == 1)
        {
            *pMaxDistance = nDistance;
        }
        else
        {
            *pMaxDistance = pLast->nDistance;
        }
        pLast->nNextIndex = 0;
    }
    else
    {
        nNewIndex = pClient->nUnitUpdateIndex;
        pClient->nUnitUpdateIndex = nNewIndex + 1;
    }
    if (!nPrevIndex && nDistance < pSort[0].nDistance)
    {
        if (pClient->nUnitUpdateIndex - 1 != 0)
        {
            pSort[nNewIndex].nNextIndex = pSort[0].nNextIndex;
            pSort[nNewIndex].pUnit = pSort[0].pUnit;
            pSort[nNewIndex].nDistance = pSort[0].nDistance;
        }
        pSort[0].nNextIndex = nNewIndex;
        nNewIndex = 0;
    }
    else
    {
        pSort[nNewIndex].nNextIndex = pSort[nPrevIndex].nNextIndex;
        pSort[nPrevIndex].nNextIndex = nNewIndex;
    }
    pSort[nNewIndex].nDistance = nDistance;
    pSort[nNewIndex].pUnit = pRoomUnit;
    if (nDistance > *pMaxDistance)
    {
        *pMaxDistance = nDistance;
    }
}

void __fastcall sub_M468_Emit_00537B00(D2ClientStrc* pClient, D2ActiveRoomStrc* pRoom)
{
    pClient->hRoom = pRoom;
    pClient->nEmitterTag = 0x2D7;
    sub_00537B00_UpdatePlayerPortalFlags(pClient);
}

static int CLIENTS_GetUnitX_Inlined(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int CLIENTS_GetUnitY_Inlined(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00537EE0
static void __stdcall CLIENTS_SetUnitsUpdateList(D2ClientStrc* pClient, D2ClientUnitUpdateSortStrc* pSort)
{
    D2ClientUnitUpdateSortStrc* pCurrent = pSort;
    pClient->nUnitUpdateIndex = 0;
    do
    {
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nUnitType = !pCurrent->pUnit ? UNIT_INVALID : pCurrent->pUnit->dwUnitType;
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nUnitGUID = !pCurrent->pUnit ? -1 : pCurrent->pUnit->dwUnitId;
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nX = CLIENTS_GetUnitX_Inlined(pCurrent->pUnit);
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nY = CLIENTS_GetUnitY_Inlined(pCurrent->pUnit);
        ++pClient->nUnitUpdateIndex;
        pCurrent = &pSort[pCurrent->nNextIndex];
    }
    while (pCurrent->nNextIndex);
}

// 0x00537FD0
void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* ptClient, unsigned int nUpdateSize)
{
    D2_ASSERT(ptClient->hRoom, 0x70B);
    D2ActiveRoomStrc** pAdjacentRoomsList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(ptClient->hRoom, &pAdjacentRoomsList, &nNumRooms);
    D2_ASSERT(pAdjacentRoomsList, 0x70D);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(ptClient, 0);
    if (!pPlayer)
    {
        return;
    }
    const int nPlayerX = CLIENTS_GetUnitX(pPlayer);
    const int nPlayerY = CLIENTS_GetUnitY(pPlayer);
    unsigned int nCurrentMaxDistance = 0;
    D2ClientUnitUpdateSortStrc tUnitUpdatesSort[55];
    ptClient->nUnitUpdateIndex = 0;
    tUnitUpdatesSort[0].nNextIndex = 0;
    tUnitUpdatesSort[0].nDistance = 0;
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pRoomUnit = pAdjacentRoomsList[i]->pUnitFirst; pRoomUnit; pRoomUnit = pRoomUnit->ptRoomNext)
        {
            sub_00537D10_InsertUnitUpdate(pRoomUnit, nPlayerX, nPlayerY, &nCurrentMaxDistance, ptClient, nUpdateSize, tUnitUpdatesSort);
        }
    }
    CLIENTS_SetUnitsUpdateList(ptClient, tUnitUpdatesSort);
}

// 0x005383B0
unsigned char __fastcall sub_005383B0(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x816);
    return pClient->nByte1AD;
}

// 0x005383E0
void __fastcall sub_005383E0(D2ClientStrc* pClient, unsigned char nValue)
{
    D2_ASSERT(pClient, 0x822);
    pClient->nByte1AD = nValue;
}

// 0x00538410
void __fastcall sub_00538410(Client* client,Unit* unit)
{
 Game* game=client->game;
 if(unit==sub_00537860(client,0)) return;
 Room* unitRoom=sub_005545C0(game,unit);
 if(!unitRoom) return;
 Room* clientRoom=client->room;
 ASSERT(clientRoom,2107);
 Room** list;
 unsigned int count;
 sub_00619790(clientRoom,&list,&count);
 unsigned int i=0;
 for(;i<count;++i) {
  Room* room=list[i];
  ASSERT(room,2112);
  if(unitRoom==room) break;
 }
 if(i>=count) sub_00571F90(game,unit,client);
}

// 0x005385E0
void __cdecl sub_005385E0()
{
}

// 0x00538650
extern "C" __declspec(dllexport) void __fastcall sub_00538650(Obj00538650* pObj, unsigned short wMask, int bSet) {
    if (bSet) {
        pObj->wFlags0A |= wMask;
    } else {
        pObj->wFlags0A &= ~wMask;
    }
}

// 0x00538670
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag)
{
    return pClient->nSaveFlags & nFlag;
}

// 0x00538680
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty)
{
    int nActsPerDifficulty;
    if (pClient->tSaveFlags.bExpansion)
    {
        nActsPerDifficulty = 5;
    }
    else
    {
        nActsPerDifficulty = 4;
    }

    const int nNewActDifficulty = nAct + nDifficulty * nActsPerDifficulty;
    if (nNewActDifficulty >= pClient->tSaveFlags.nProgression)
    {
        unsigned short* pPackedValue = &pClient->tSaveFlags.nPackedValue;
        *pPackedValue = (*pPackedValue & 0xE0FF) | ((unsigned short)(nDifficulty * nActsPerDifficulty + nAct) << 8);
    }
}

// 0x00538730
int __fastcall sub_00538730(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x989);
    return pClient->nIronGolemItemGUID;
}

// 0x00538860
void __fastcall sub_00538860(D2ClientStrc* pClient, int bSet)
{
    D2_ASSERT(pClient, 0x9F7);
    if (bSet)
    {
        if (!(pClient->dwFlags & CLIENTFLAGEX_ARENA_RELATED))
            ARENA_SendScoresToClient(pClient->pGame, pClient);
        pClient->dwFlags |= CLIENTFLAGEX_ARENA_RELATED;
    }
    else
    {
        pClient->dwFlags &= ~CLIENTFLAGEX_ARENA_RELATED;
    }
}

// 0x005388C0
unsigned int __fastcall sub_6FC33C10(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 0xA05);
    return (ptClient->nFlags >> 2) & 1;
}

// 0x00538900
unsigned char __fastcall sub_00538900(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0xA11);
    return pClient->nByte0C;
}

// 0x00538930
int __fastcall CLIENTS_CheckState(int nClientId, int nExpectedClientState)
{
    if (!gbClientListInitialized_008846D8)
    {
        return 0;
    }

    int bResult = 0;
    EnterCriticalSection(&gClientListLock_008846A8);
    for (D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            bResult = pClient->dwClientState == nExpectedClientState;
            break;
        }
    }
    LeaveCriticalSection(&gClientListLock_008846A8);
    return bResult;
}

// 0x00538BF0
int __fastcall CLIENTS_GetClientIdByName(const char* szName)
{
    int nClientId = 0;
    const int nIndex = FOG_ComputeStringCRC16(szName) & 0xFF;

    EnterCriticalSection(&gSrvClientListByNameLock_008846C0);

    for (D2ClientStrc* pClient = gpClientListByName_00883EA8[nIndex]; pClient; pClient = pClient->pServerNextByName)
    {
        if (nClientId)
        {
            break;
        }

        if (!SStrCmpI(pClient->szName, szName, 16))
        {
            nClientId = pClient->dwClientId;
        }
    }

    LeaveCriticalSection(&gSrvClientListByNameLock_008846C0);
    return nClientId;
}

// 0x00539070
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00539070(Obj00539070* pObj) {
    return pObj->dwValue88;
}

// 0x00539080
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00539080(Obj00539080* pObj) {
    return pObj->dwValue4A8;
}

// 0x00539090
int __fastcall sub_00539090_GetClientState(D2ClientStrc* pClient)
{
    return pClient->dwClientState;
}

// 0x00539110
extern "C" __declspec(dllexport) unsigned short __fastcall sub_00539110(Obj00539110* pObj) {
    return pObj->wValue45E;
}

// 0x00539120
extern "C" __declspec(dllexport) void __fastcall sub_00539120(Obj00539120* pObj, unsigned short wValue) {
    pObj->wValue45E = wValue;
}

// 0x00539130
extern "C" __declspec(dllexport) void __fastcall sub_00539130(Obj00539130* pObj, unsigned int* pOut) {
    *pOut = pObj->dwValue460;
}

// 0x00539140
extern "C" __declspec(dllexport) void __fastcall sub_00539140(Obj00539140* pObj, const unsigned int* pIn) {
    pObj->dwValue460 = *pIn;
}

// 0x00539150
extern "C" __declspec(dllexport) void __fastcall sub_00539150(Obj00539150* pObj, char* pDst) {
    strcpy(pDst, pObj->szName464);
}

// 0x00539170
extern "C" __declspec(dllexport) void __fastcall sub_00539170(Obj00539170* pObj, const char* pSrc) {
    strcpy(pObj->szName464, pSrc);
}

// 0x00539190
extern "C" __declspec(dllexport) void __fastcall sub_00539190(Obj00539190* pObj, unsigned char* p0, unsigned char* p1, unsigned char* p2) {
    *p0 = pObj->b480;
    *p1 = pObj->b481;
    *p2 = pObj->b482;
}

// 0x005391C0
extern "C" __declspec(dllexport) void __fastcall sub_005391C0(Obj005391C0* pObj, unsigned char b0, unsigned char b1, unsigned char b2) {
    pObj->b480 = b0;
    pObj->b481 = b1;
    pObj->b482 = b2;
}

// 0x00539210
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00539210(Obj00539210* pObj) {
    return pObj->dwValue508;
}

// 0x00539220
extern "C" __declspec(dllexport) unsigned char __fastcall sub_00539220(Obj00539220* pObj) {
    return pObj->nValue45C;
}

// 0x00539230
extern "C" __declspec(dllexport) void __fastcall sub_00539230(Obj00539230* pObj, unsigned char nValue) {
    pObj->nValue45C = nValue;
}

// 0x00539240
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData)
{
    pPacketData->pNext = 0;

    if (!pClient->pPacketDataTail)
    {
        pClient->pPacketDataHead = pPacketData;
        pClient->pPacketDataTail = pPacketData;
    }
    else
    {
        pClient->pPacketDataTail->pNext = pPacketData;
        pClient->pPacketDataTail = pPacketData;
    }
}

// 0x00539270
void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pSinglePacketData)
{
    pSinglePacketData->pNext = 0;

    if (!pClient->pPacketDataHead)
    {
        pSinglePacketData->pNext = 0;
        pClient->pPacketDataHead = pSinglePacketData;
    }
    else
    {
        pClient->pPacketDataTail = pSinglePacketData;
        pClient->pPacketDataHead = pSinglePacketData;
    }
}

// 0x005392D0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005392D0(Obj005392D0* pObj) {
    return pObj->dwValue1BC;
}

// 0x005392E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005392E0(Obj005392E0* pObj) {
    return pObj->dwValue1B8;
}

// 0x00539300
extern "C" __declspec(dllexport) void __fastcall sub_00539300(Obj00539300* pObj, unsigned int* pOut) {
    *pOut = pObj->dwValue60;
}

// 0x00539310
extern "C" __declspec(dllexport) void __fastcall sub_00539310(Obj00539310* pObj, unsigned int* pOut) {
    *pOut = pObj->dwValue68;
}

// 0x005394A0
void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nXArg, int nYArg)
{
    if (!pGame || !pPlayer || !pClient)
    {
        return;
    }

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    int nX;
    int nY;
    if (!hRoom)
    {
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromAct(pGame->pAct[nAct]);
        hRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nTownLevelId, 0, &nX, &nY, UNITS_GetUnitSizeX(pPlayer));
        D2_ASSERT(hRoom, 0x1A1);

        D2DrlgCoordsStrc tDrlgCoords;
        DUNGEON_GetRoomCoordinates(hRoom, &tDrlgCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(hRoom), tDrlgCoords.nTileXPos, tDrlgCoords.nTileYPos);
    }
    else
    {
        nX = nXArg;
        nY = nYArg;
    }

    CLIENTS_SetRoomInClient(pClient, hRoom);
    SUNIT_Add(pPlayer, nX, nY, pGame, hRoom, 0);
    pClient->dwFlags &= ~1;
    const int nUnitGUID = pPlayer->dwUnitId;
    const int nUnitType = (pPlayer ? pPlayer->dwUnitType : 6);
    D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, 1);
    D2GAME_PACKETS_SendPacket0x7E_6FC3F770(pClient, pGame->unk0xEC);

    D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory);
    while (pCorpse)
    {
        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
        if (!sub_0063D670(pCorpse))
        {
            const unsigned short wName = sub_0063D650(pCorpse);
            pCorpse = INVENTORY_GetNextCorpse(pCorpse);
            INVENTORY_FreeCorpse(pPlayer->pInventory, nCorpseGUID, 0);
            if (nCorpseGUID && wName)
            {
                D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, wName, nCorpseGUID, 0xFFFF, 0, 0);
            }
        }
        else
        {
            D2UnitStrc* pCorpsePlayer = SUNIT_GetServerUnit(pGame, 0, nCorpseGUID);
            if (pCorpsePlayer)
            {
                const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
                int nCorpseX = 0;
                int nCorpseY = 0;
                D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nTownLevelId, 0, &nCorpseX, &nCorpseY, UNITS_GetUnitSizeX(pCorpsePlayer));
                D2CoordStrc tCoord;
                tCoord.nX = nCorpseX;
                tCoord.nY = nCorpseY;
                sub_6FC7BFC0(pGame, pSpawnRoom, nCorpseGUID, &tCoord);
            }

            pCorpse = INVENTORY_GetNextCorpse(pCorpse);
        }
    }

    sub_005773D0_UpdateMercForOwnerMove(pGame, pPlayer);

    const int nIronGolemItemGUID = pClient->nIronGolemItemGUID;
    if (nIronGolemItemGUID && nIronGolemItemGUID != -1)
    {
        D2UnitStrc* pIronGolemItem = SUNIT_GetServerUnit(pGame, 4, nIronGolemItemGUID);
        if (pIronGolemItem)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, 0x5A);
            if (pSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
                UNITS_SetXForStaticUnit(pIronGolemItem, CLIENTS_GetUnitX(pPlayer));
                UNITS_SetYForStaticUnit(pIronGolemItem, CLIENTS_GetUnitY(pPlayer));
                UNITS_SetTargetUnitForDynamicUnit(pPlayer, pIronGolemItem);
                sub_0056F7F0(pGame, pPlayer, 0x5A, nSkillLevel, 1, 0, 0);
            }
        }

        pClient->nIronGolemItemGUID = -1;
    }
}

// 0x00539BE0
void __fastcall CLIENTS_FillCharacterPreviewInfo(D2ClientStrc* pClient, char* szInfo)
{
    sub_006BBF40((unsigned char*)szInfo, PREVIEW_VERSION);
    D2CharacterPreviewRecordStrc* pPreview = (D2CharacterPreviewRecordStrc*)(szInfo + 2);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        unsigned char aColors[16];
        unsigned char aComponents[16];
        unsigned char aGfx[16];
        const unsigned char nLevel = (unsigned char)STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
        const unsigned int nClassId = pPlayer->dwClassId;

        memset(aComponents, 0xFF, sizeof(aComponents));
        sub_0063E510_FillInventoryTables(pPlayer, aComponents, aGfx);
        SMemCopy(pPreview->pComponents, aComponents, PREVIEW_COPY_SIZE);
        pPreview->nClass = (unsigned char)nClassId < NUMBER_OF_PLAYERCLASSES ? (unsigned char)nClassId + 1 : 1;

        memset(aColors, 0xFF, sizeof(aColors));
        sub_0063E510_FillInventoryTables(pPlayer, aGfx, aColors);
        for (int i = 0; i < 16; ++i)
        {
            if (!aColors[i])
            {
                aColors[i] = 0xFF;
            }
        }
        SMemCopy(pPreview->pComponentColors, aColors, PREVIEW_COPY_SIZE);

        const unsigned char nLevelIndex = nLevel - 1;
        pPreview->nLevel = nLevelIndex <= PREVIEW_MAX_LEVEL_INDEX ? nLevel : 1;

        const unsigned int nMode = pPlayer->dwAnimMode;
        const unsigned short wSaveFlags = pClient->nSaveFlags;
        unsigned int nFlags = wSaveFlags;
        if ((nMode == PLRMODE_DEAD || nMode == PLRMODE_DEATH) && (wSaveFlags & CLIENTSAVEFLAG_HARDCORE))
        {
            nFlags |= CLIENTSAVEFLAG_DEAD;
        }
        else
        {
            nFlags &= 0xFFF7;
        }
        sub_006BBF40(pPreview->nClientFlags, nFlags);
        sub_006BBF40(pPreview->nGuildFlags, pClient->nGuildFlags);

        unsigned char nBgColor = pClient->nGuildBgColor;
        unsigned char nFgColor = pClient->nGuildFgColor;
        unsigned char nEmblem = pClient->f_482;
        if (!nBgColor)
        {
            nBgColor = 0xFF;
        }
        if (!nFgColor)
        {
            nFgColor = 0xFF;
        }
        if (!nEmblem)
        {
            nEmblem = 0xFF;
        }
        pPreview->nGuildBgColor = nBgColor;
        pPreview->nGuildFgColor = nFgColor;
        pPreview->f_1E = nEmblem;
        pPreview->f_1F = pClient->f_460;

        const int bBadLevel = nLevelIndex > PREVIEW_MAX_LEVEL_INDEX;
        const int bBadClass = (unsigned char)nClassId >= NUMBER_OF_PLAYERCLASSES;
        const int bBadFlags = (nFlags & CLIENTSAVEFLAG_INVALID_1) || (nFlags & CLIENTSAVEFLAG_INVALID_2) || (nFlags & CLIENTSAVEFLAG_INVALID_10);
        const int bBadLength = SStrLen(szInfo) != PREVIEW_STRING_LENGTH;
        if (bBadLevel || bBadClass || bBadFlags || bBadLength)
        {
            *szInfo = 0;
        }
    }
}

inline void W11_InlineFixRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x62);
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        sub_005531E0_FixRoomIfInvalid(pUnit, pClient);
}

// 0x0053A6F0
void __fastcall sub_0053A6F0_FixAdjacentRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x75);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
        W11_InlineFixRoomUnits(ppRoomList[i], pClient);
}

// 0x0053AB10
void __fastcall sub_0053AB10_UpdateAdjacentRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    D2_ASSERT(pRoom, 0x141);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
        sub_0053AAA0_UpdateRoomUnits(pGame, ppRoomList[i], pTarget);
}

// 0x0053E2C0
void D2BitBufferStrc::sub_0053E2C0_WriteBool(int bValue)
{
    BITMANIP_Write(this, bValue != 0, 1);
}

// 0x00547080
void __fastcall sub_00547080_PrintObjectPlacementStats(D2GameStrc* pGame)
{
    char szText[0x80];
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    for (int i = 1; i < 0x61; ++i)
    {
        if (pObjectControl->wGroupCount[i])
        {
            wsprintfA(szText, "Attempted to place group %d %d times\n", i, pObjectControl->wGroupCount[i]);
            pGame->sub_00546FF0_SendQuestText(szText);
        }
    }
    wsprintfA(szText, "%d Rooms where we wanted to place - no group beat the odds\n", pObjectControl->wRoomsNoGroup);
    pGame->sub_00546FF0_SendQuestText(szText);
    wsprintfA(szText, "%d rooms tried to place 1+ group(s); %d rooms w/no objs\n", pObjectControl->wRoomsTried, pObjectControl->wGroupCount[0]);
    pGame->sub_00546FF0_SendQuestText(szText);
}

// 0x00552840
void __fastcall sub_00552840_PopulateObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nObjectId)
{
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
        return;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC7D);
    if (sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xC80);
        sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, gnObjectPopulateDensity_00731BBD, nObjectId, 100);
    }
}

// 0x005536E0
void __fastcall sub_005536E0_StoreRoomTile(D2W11RoomTileOwnerStrc* pOwner, D2ActiveRoomStrc* pRoom, int nArg1, int nArg2)
{
    pOwner->pRecord->nArg1 = nArg1;
    pOwner->pRecord->nArg2 = nArg2;
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    pOwner->pRecord->nTileX = tCoords.nTileXPos;
    pOwner->pRecord->nTileY = tCoords.nTileYPos;
}

// 0x005B7230
void __fastcall sub_005B7230_ChangeQuestMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x0E);
    if (!pQuestData)
        return;
    D2W11QuestEx5B7230Strc* pQuestDataEx = (D2W11QuestEx5B7230Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pMapAI = pMapAI;
    if (!pQuestDataEx->bNpcSpawned)
        return;
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nNpcGUID);
    if (pNpc && pQuestDataEx->pMapAI && pQuestDataEx->pMapAI->pPosition && !pQuestDataEx->bMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pMapAI, AIGENERAL_GetMapAiFromUnit(pNpc));
        pQuestDataEx->bMapAIChanged = 1;
    }
}

// 0x005BD040
void __fastcall sub_005BD040_ChangeQuestMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x14);
    if (!pQuestData)
        return;
    D2W11QuestEx5BD040Strc* pQuestDataEx = (D2W11QuestEx5BD040Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pMapAI = pMapAI;
    if (!pQuestDataEx->bNpcSpawned)
        return;
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nNpcGUID);
    if (pNpc && pQuestDataEx->pMapAI && pQuestDataEx->pMapAI->pPosition && !pQuestDataEx->bMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pMapAI, AIGENERAL_GetMapAiFromUnit(pNpc));
        pQuestDataEx->bMapAIChanged = 1;
    }
}
