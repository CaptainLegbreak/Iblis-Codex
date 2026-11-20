#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ITEMACTION_REMOVEFROMCONTAINER 5
#define ITEMACTION_EQUIP 6
#define ITEMACTION_INDIRECTLYSWAPBODYITEM 7
#define ITEMACTION_UNEQUIP 8
#define ITEMACTION_SWAPBODYITEM 9
#define ITEMACTION_AUTOUNEQUIP 0x11
#define ITEMACTION_UNKNOWN0x14 0x14
#define ITEMACTION_WEAPONSWITCH 0x17
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define UNIT_MONSTER 1
#define UNIT_TYPES_COUNT 6
#define UNIT_PLAYER 0
#define ITEMACTION_ADDTOGROUND 0
#define ITEMACTION_GROUNDTOCURSOR 1
#define ITEMACTION_PUTINCONTAINER 4
#define ITEMACTION_ADDQUANTITY 10
#define ITEMACTION_ADDTOSHOP 11
#define ITEMACTION_REMOVEFROMSHOP 12
#define ITEMACTION_SWAPINCONTAINER 13
#define ITEMACTION_PUTINBELT 14
#define ITEMACTION_REMOVEFROMBELT 15
#define ITEMACTION_SWAPINBELT 16
#define ITEMACTION_TOCURSOR 18
#define ITEMACTION_ITEMINSOCKET 19
#define ITEMACTION_UPDATESTATS 21
#define ITEMACTION_UNKNOWN0x16 22
#define IFLAG_DELETED 0x00000008
#define IFLAG_IDENTIFIED 0x00000010
#define IFLAG_QUANTITY 0x00000020
#define STAT_GOLD 14
struct D2GSPacketSrvB0;
struct D2GSPacketSrv06;
struct D2PacketHeaderOnlyStrc;
struct D2PacketSize06Strc;
struct D2PacketSize05Strc;
struct D2PacketDataStrc;
struct D2GSPacketSrv01;
struct D2GSPacketSrv1A;
struct D2GSPacketSrv1B;
struct D2GSPacketSrv1C;
struct D2GSPacketSrv1D;
struct D2GSPacketSrv1E;
struct D2GSPacketSrv1F;
struct D2GSPacketSrv69;
struct D2GSPacketSrv6A;
struct D2GSPacketSrv6B;
struct D2GSPacketSrv6C;
struct D2GSPacketSrv6D;
struct D2GSPacketSrv67;
struct D2GSPacketSrv68;
struct D2GSPacketSrv9E;
struct D2GSPacketSrv9F;
struct D2GSPacketSrvA0;
struct D2GSPacketSrvA1;
struct D2GSPacketSrvA2;
struct D2StaticPathStrc;
struct D2GSPacketSrv03Strc;
struct D2GSPacketSrv0C;
struct D2GSPacketSrv0D;
struct D2GSPacketSrv15;
struct D2GSPacketSrv07;
struct D2GSPacketSrv21;
struct D2GSPacketSrv23;
struct D2GSPacketSrv3F;
struct D2GSPacketSrv57;
struct D2GSPacketSrv99;
struct D2GSPacketSrv9A;
struct D2GSPacketSrv0EStrc;
struct D2GSPacketSrv10Strc;
struct D2GSPacketSrv0FStrc;
struct FieldStrc_005A6220;
struct D2GSPacketSrv08;
struct D2GSPacketSrv09;
struct D2GSPacketSrv51;
struct PacketA1;
struct PacketA2;
struct PacketA0;
struct D2GSPacketSrvA3;
struct D2GSPacketSrvAB;
struct D2GSPacketSrvA5;
struct D2GSPacketSrv22;
struct D2GSPacketSrv5C;
struct D2GSPacketSrv77;
struct D2GSPacketSrv78;
struct D2GSPacketSrv7A;
struct D2GSPacketSrv81;
struct D2PackedGuidStrc;
struct D2MessageStrc;
struct D2GSPacketSrv27;
struct D2GSPacketSrv53;
struct D2GSPacketSrv26;
struct D2GSPacketSrv20Strc;
struct D2GSPacketSrv23Strc;
struct D2GSPacketSrv93Strc;
struct D2GSPacketSrv79;
struct D2GSPacketSrv7F;
struct D2GSPacketSrv90;
struct D2LifeSyncStrc;
struct D2MonsterDataStrc;
struct D2PlayerDataStrc;
struct D2GSPacketSrv3E;
struct D2GSPacketSrv42;
struct D2GSPacketSrv47;
struct D2GSPacketSrv48;
struct D2ObjectDataStrc;
struct D2GSPacketSrv7D;
struct D2GSPacketSrv28;
struct D2GSPacketSrv29;
struct D2GSPacketSrv5D;
struct D2GSPacketSrv2C;
struct D2GSPacketSrv4E;
struct D2GSPacketSrv50;
struct D2GSPacketSrv5E;
struct D2GSPacketSrv52;
struct D2GSPacketSrv11;
struct D2GSPacketSrv58;
struct D2GSPacketSrv60;
struct D2GSPacketSrv61;
struct D2GSPacketSrv73;
struct D2GSPacketSrv75;
struct D2GSPacketSrv7B;
struct D2GSPacketSrv7E;
struct D2GSPacketSrv82;
struct D2GSPacketSrv8E;
struct D2GSPacketSrv89;
struct D2GSPacketSrv8A;
struct D2PacketInteractStrc;
struct D2PacketSrv2AStrc;
struct D2GSPacketSrv65Strc;
struct D2GSPacketSrv74;
struct D2GSPacketSrv8BStrc;
struct D2GSPacketSrv8F;
struct D2GSPacketSrv91;
struct D2GSPacketSrv98;
struct D2GSPacketSrv9B;
struct D2GSPacketSrv97;
struct D2GSPacketSrvA4;
struct D2GSPacketSrvA7;
struct D2GSPacketSrvA9;
struct D2GSPacketSrv59;
struct D2GSPacketSrv19;
struct D2GSPacketSrv9C;
struct D2UnitUpdateEntry;
struct D2GSPacketSrv16;
struct D2GSPacketSrvA6;
struct D2GSPacketSrvAE;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330

#pragma pack(push, 1)
struct D2UnitUpdateEntry { int nFirst; int nSecond; unsigned char nType; };

#pragma pack(pop)
struct D2ClientStrc
{
    char unk0x000[0x1B8];
    D2PacketDataStrc* pPacketDataHead;
    D2PacketDataStrc* pPacketDataTail;
    D2PacketDataStrc* pPacketDataPool;
    unsigned char unk_1C4[0x8];
    D2UnitUpdateEntry entries[54];
    unsigned char pad3B2[10];
    int nCount;
};


void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053CEF0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem); // 0x006282F0

struct D2GSPacketSrvB0
{
    unsigned char nHeader;
};

struct D2GSPacketSrv06
{
    unsigned char nHeader;
};

#pragma pack(push, 1)
struct D2PacketHeaderOnlyStrc
{
    unsigned char nHeader;
};

struct D2PacketSize06Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};

struct D2PacketSize05Strc
{
    unsigned char nHeader;
    int nValue;
};

#pragma pack(pop)
struct D2PacketDataStrc
{
    union
    {
        int nPacketSize;
        int nSize;
    };
    union
    {
        unsigned char packetData[0x200];
        unsigned char data[1];
    };
    D2PacketDataStrc* pNext;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient); // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData); // 0x00539240

#pragma pack(push, 1)
struct D2GSPacketSrv01 { unsigned char nHeader; unsigned char nDifficulty; unsigned int dwArenaFlags; unsigned char nExpansion; unsigned char nLadder; };

struct D2GSPacketSrv1A { unsigned char nHeader; unsigned char nExperience; };

struct D2GSPacketSrv1B { unsigned char nHeader; unsigned short nExperience; };

struct D2GSPacketSrv1C { unsigned char nHeader; unsigned int nExperience; };

struct D2GSPacketSrv1D { unsigned char nHeader; unsigned char nStat; unsigned char nValue; };

struct D2GSPacketSrv1E { unsigned char nHeader; unsigned char nStat; unsigned short nValue; };

struct D2GSPacketSrv1F { unsigned char nHeader; unsigned char nStat; unsigned int nValue; };

struct D2GSPacketSrv69 { unsigned char nHeader; unsigned int unk0x01; unsigned char unk0x05; unsigned short unk0x06; unsigned short unk0x08; unsigned char unk0x0A; unsigned char unk0x0B; };

struct D2GSPacketSrv6A { unsigned char nHeader; unsigned int nUnitGUID; unsigned char unk0x05; unsigned char nTargetUnitType; unsigned int nTargetUnitGuid; unsigned char nDirection; };

struct D2GSPacketSrv6B { unsigned char nHeader; unsigned int unk0x01; unsigned char unk0x05; unsigned short unk0x06; unsigned short unk0x08; unsigned char unk0x0A; unsigned char unk0x0B; unsigned short unk0x0C; unsigned short unk0x0E; };

struct D2GSPacketSrv6C { unsigned char nHeader; unsigned int unk0x01; unsigned char unk0x05; unsigned char unk0x06; unsigned int unk0x07; unsigned char unk0x0B; unsigned short unk0x0C; unsigned short unk0x0E; };

struct D2GSPacketSrv6D { unsigned char nHeader; unsigned int unk0x01; unsigned short unk0x05; unsigned short unk0x07; unsigned char unk0x09; };

struct D2GSPacketSrv67 { unsigned char nHeader; int nUnitGUID; unsigned char unk0x05; short nX; short nY; char unk0x0A; char unk0x0B; unsigned char nPathType; short nVelocity; char unk0x0F; };

struct D2GSPacketSrv68 { unsigned char nHeader; int nUnitGUID; unsigned char unk0x05; short nX; short nY; char unk0x0A; int unk0x0B; char unk0x0F; char unk0x10; unsigned char nPathType; short nVelocity; char unk0x14; };

struct D2GSPacketSrv9E { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned char nValue; };

struct D2GSPacketSrv9F { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned short nValue; };

struct D2GSPacketSrvA0 { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned int nValue; };

struct D2GSPacketSrvA1 { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned char nValue; };

struct D2GSPacketSrvA2 { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned short nValue; };

#pragma pack(pop)


unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame); // 0x0053FD40
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall sub_00648A40_GetTargetX(D2DynamicPathStrc* pPath); // 0x00648A40
int __stdcall sub_00648A60_GetTargetY(D2DynamicPathStrc* pPath); // 0x00648A60
unsigned char __stdcall sub_00648EA0_GetPathByte(D2DynamicPathStrc* pPath); // 0x00648EA0

#pragma pack(push, 1)
struct D2GSPacketSrv03Strc
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned int dwGameSeed;
    unsigned short nTownLevelId;
    unsigned int nObjectSeed;
};

struct D2GSPacketSrv0C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessage;
    unsigned char nHitClass;
    unsigned char nLife;
};

struct D2GSPacketSrv0D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nHitClass;
    unsigned short nX;
    unsigned short nY;
    unsigned char nHitType;
    unsigned char nUnitLifePct;
};

struct D2GSPacketSrv15
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char bReassign;
};

struct D2GSPacketSrv07
{
    unsigned char nHeader;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};

struct D2GSPacketSrv21
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char bRemove;
    unsigned int nUnitGUID;
    unsigned short nSkillId;
    unsigned char nSkillLevel;
    unsigned char nBonusSkillLevel;
    unsigned char unk0x0B;
};

struct D2GSPacketSrv23
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nPosition;
    unsigned short nSkill;
    unsigned int nOwnerGUID;
};

struct D2GSPacketSrv3F
{
    unsigned char nHeader;
    unsigned char nCursor;
    unsigned int dwItemId;
    unsigned short nSkill;
};

struct D2GSPacketSrv57
{
    unsigned char nHeader;
    unsigned int dwUnitGUID;
    unsigned char nUnitType;
    unsigned short nNameSeed;
    unsigned short nUMods01;
    unsigned short nUMods23;
    unsigned short bChampion;
};

struct D2GSPacketSrv99
{
    unsigned char nHeader;
    unsigned char nSourceUnitType;
    unsigned int nSourceUnitGUID;
    unsigned short nSkillId;
    unsigned char nSkillLevel;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned short nItemEffect;
};

struct D2GSPacketSrv9A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int nUnitGUID;
    unsigned int nSkillId;
    unsigned char nSkillLevel;
    unsigned short nX;
    unsigned short nY;
    unsigned short nItemEffect;
};

#pragma pack(pop)

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

#pragma pack(push, 1)
struct D2GSPacketSrv0EStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char a5;
    unsigned char a6;
    int nAnimMode;
};

struct D2GSPacketSrv10Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nFlags;
    unsigned char nTargetType;
    int nTargetGUID;
    short nCurrentPosX;
    short nCurrentPosY;
};

struct D2GSPacketSrv0FStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nFlags;
    short nDestPosX;
    short nDestPosY;
    unsigned char nHitClass;
    short nCurrentPosX;
    short nCurrentPosY;
};

#pragma pack(pop)
struct FieldStrc_005A6220
{
    int unk0x00[4];
    int unk0x10;
};

#pragma pack(push, 1)
struct D2GSPacketSrv08
{
    unsigned char nHeader;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};

struct D2GSPacketSrv09
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nClassId;
    unsigned short nPosX;
    unsigned short nPosY;
};

struct D2GSPacketSrv51
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nObject;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char nObjectParam;
    unsigned char nInteractType;
};

struct PacketA1 {unsigned char header,stat;int guid;unsigned char value;};

struct PacketA2 {unsigned char header,stat;int guid;unsigned short value;};

struct PacketA0 {unsigned char header,stat;int guid;unsigned int value;};

#pragma pack(pop)

extern const char text_006CC837[]; // 0x006CC837
__declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

#pragma pack(push, 1)
struct D2GSPacketSrvA3
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short unk0x02;
    unsigned short unk0x04;
    unsigned char unk0x06;
    unsigned int unk0x07;
    unsigned char unk0x0B;
    unsigned int unk0x0C;
    unsigned int unk0x10;
    unsigned int unk0x14;
};

struct D2GSPacketSrvAB
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nLife;
};

struct D2GSPacketSrvA5
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    unsigned short unk0x06;
};

struct D2GSPacketSrv22
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    int nUnitGUID;
    unsigned short nSkillId;
    unsigned char nQuantity;
    unsigned char unk0x0A;
    unsigned char bIsCorpse;
};

struct D2GSPacketSrv5C
{
    unsigned char nHeader;
    unsigned int dwPlayerGUID;
};

struct D2GSPacketSrv77
{
    unsigned char nHeader;
    unsigned char nAction;
};

struct D2GSPacketSrv78
{
    unsigned char nHeader;
    char szName[16];
    unsigned int dwPlayerGUID;
};

struct D2GSPacketSrv7A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned short unk0x03;
    unsigned int unk0x05;
    unsigned int unk0x09;
};

struct D2GSPacketSrv81
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short unk0x02;
    unsigned int unk0x04;
    unsigned int unk0x08;
    unsigned int unk0x0C;
    unsigned int unk0x10;
};

#pragma pack(pop)

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};

struct D2GSPacketSrv53
{
    unsigned char nHeader;
    unsigned char nCycleIndex;
    unsigned char nCycleIndex1;
    unsigned char nCycleIndex2;
    unsigned char nCycleIndex3;
    unsigned char nTicks;
    unsigned char nTicks1;
    unsigned char nTicks2;
    unsigned char nTicks3;
    unsigned char nEclipse;
};

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned char abParam[4];
    unsigned char nParam;
    char szText[32];
};

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

#pragma pack(push, 1)
struct D2GSPacketSrv20Strc
{
    unsigned char nHeader;
    int dwUnitGUID;
    unsigned char nStat;
    int nValue;
};

#pragma pack(pop)
struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90

#pragma pack(push, 1)
struct D2GSPacketSrv23Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nPosition;
    unsigned short nSkill;
    int nOwnerGUID;
};

struct D2GSPacketSrv93Strc
{
    unsigned char nHeader;
    int dwUnitGUID;
    unsigned char nBonus;
    unsigned char nCharClass;
    unsigned char nSkillTab;
};

struct D2GSPacketSrv79
{
    unsigned char nHeader;
    unsigned char bOwnGold;
    unsigned int dwGold;
};

struct D2GSPacketSrv7F
{
    unsigned char nHeader;
    unsigned char bIsPlayer;
    unsigned short nLifePercentage;
    int nUnitGUID;
    unsigned short nLevelId;
};

struct D2GSPacketSrv90
{
    unsigned char nHeader;
    int dwGUID;
    int dwPosX;
    int dwPosY;
};

#pragma pack(pop)

struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    D2LifeSyncStrc tLifeSync;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    unsigned char unk_10[0x88];
    D2LifeSyncStrc* pPartyLifeList;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

struct D2GSPacketSrv3E
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned char pBuffer[32];
};

void __fastcall sub_0053B0E0_WriteVarLength(D2BitBufferStrc* pBuffer, unsigned int nValue); // 0x0053B0E0

#pragma pack(push, 1)
struct D2GSPacketSrv42
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

struct D2GSPacketSrv47
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned int nUnitGUID;
    unsigned int unk0x07;
};

struct D2GSPacketSrv48
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned int nUnitGUID;
    unsigned int unk0x07;
};

#pragma pack(pop)

void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053EAE0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char InteractType;
};

int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit); // 0x00552B10
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
unsigned short __fastcall PLAYERLIST_GetFlags(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B350

#pragma pack(push, 1)
struct D2GSPacketSrv7D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID1;
    int nUnitGUID2;
    int unk0x0A;
    int unk0x0E;
};

struct D2GSPacketSrv28
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    unsigned char unk0x06;
    unsigned char pData[96];
};

struct D2GSPacketSrv29
{
    unsigned char nHeader;
    unsigned char pData[96];
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short nSoundEvent;
};

struct D2GSPacketSrv4E
{
    unsigned char nHeader;
    unsigned short nMercName;
    int nSeed;
};

struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nMonstersToBeKilled;
    unsigned short nStaffTombLevelOffset;
    unsigned short nBarbsToBeRescued;
    unsigned char unk0x09[6];
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    unsigned char unk0x001[37];
};

struct D2GSPacketSrv52
{
    unsigned char nHeader;
    unsigned char pQuestList[41];
};

struct D2GSPacketSrv11
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short unk0x06;
};

struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
    unsigned char unk0x06;
};

struct D2GSPacketSrv60
{
    unsigned char nHeader;
    unsigned char nFlags;
    unsigned char nLevel;
    int dwUnitGUID;
};

struct D2GSPacketSrv61
{
    unsigned char nHeader;
    unsigned char unk0x01;
};

struct D2GSPacketSrv73
{
    unsigned char nHeader;
    int unk0x01;
    unsigned short nMissileId;
    int nX;
    int nY;
    int nFirstX;
    int nFirstY;
    unsigned short nCurrentFrame;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nLevel;
    unsigned char nPierce;
};

struct D2GSPacketSrv75
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned short nPartyId;
    unsigned short nLevel;
    unsigned short nFlags;
    unsigned short unk0x0B;
};

struct D2GSPacketSrv7B
{
    unsigned char nHeader;
    unsigned char nSlot;
    unsigned short nSkill;
    int nItemGUID;
};

struct D2GSPacketSrv7E
{
    unsigned char nHeader;
    unsigned int unk0x01;
};

struct D2GSPacketSrv82
{
    unsigned char nHeader;
    int dwOwnerGUID;
    char szOwnerName[16];
    int dwPortalGUID0;
    int dwPortalGUID1;
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    int dwPlayerGUID;
    int dwCorpseGUID;
};

struct D2GSPacketSrv89
{
    unsigned char nHeader;
    unsigned char nEvent;
};

struct D2GSPacketSrv8A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
};

struct D2PacketInteractStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char unk0x06;
};

struct D2PacketSrv2AStrc
{
    unsigned char nHeader;
    unsigned char nTransactionType;
    unsigned char nResult;
    unsigned int unk0x03;
    int nUnitGUID;
    int nGold;
};

struct D2GSPacketSrv65Strc
{
    unsigned char nHeader;
    unsigned int dwUnitId;
    unsigned short nKillCount;
};

struct D2GSPacketSrv74
{
    unsigned char nHeader;
    unsigned char bAssign;
    int nPlayerGUID;
    int nCorpseGUID;
};

struct D2GSPacketSrv8BStrc
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char bParty;
};

struct D2GSPacketSrv8F
{
    unsigned char nHeader;
    unsigned int unk0x01[8];
};

#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv98 { unsigned char nHeader; unsigned int unk0x01; unsigned short unk0x05; };

struct D2GSPacketSrv9B { unsigned char nHeader; unsigned short unk0x01; int unk0x03; };

struct D2GSPacketSrv97 { unsigned char nHeader; };

struct D2GSPacketSrvA4 { unsigned char nHeader; short unk0x01; };

struct D2GSPacketSrvA7 { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nState; };

struct D2GSPacketSrvA9 { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nState; };

struct D2GSPacketSrv59 { unsigned char nHeader; unsigned int dwGUID; unsigned char nClass; char szName[16]; short nPosX; short nPosY; };

struct D2GSPacketSrv19 { unsigned char nHeader; unsigned char nGold; };

struct D2GSPacketSrv9C { unsigned char nHeader; unsigned char nAction; unsigned char nPacketSize; unsigned char nComponent; int nItemId; unsigned char pBitstream[244]; };

#pragma pack(pop)

void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0053DA90
unsigned char __stdcall sub_00623D60_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00623D60
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __fastcall sub_0053EA50_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags); // 0x0053EA50

#pragma pack(push, 1)
struct D2GSPacketSrv16 { unsigned char nHeader; unsigned short nSize; unsigned char nCount; D2UnitUpdateEntry entries[1]; };

#pragma pack(pop)

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc*); // 0x005392E0

struct D2GSPacketSrvA6
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned short nPacketSize;
    short wArg;
    unsigned char data[0x1000];
};

#pragma pack(push, 1)
struct D2GSPacketSrvAE
{
    unsigned char nHeader;
    unsigned short nSize;
    unsigned char data[0x1FD];
};

#pragma pack(pop)

// 0x0053B220
void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId)
{
    D2GSPacketSrvB0 packetB0;
    packetB0.nHeader = 0xB0;
    sub_0052B330(0, nClientId, &packetB0, sizeof(packetB0));
}

// 0x0053B240
void __fastcall sub_6FC3C6B0(int nClientId)
{
    D2GSPacketSrv06 packet06;
    packet06.nHeader = 0x06;
    sub_0052B330(1, nClientId, &packet06, sizeof(packet06));
}

// 0x0053B260
void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nErrorCode)
{
    unsigned int packetB4[2];
    *(unsigned char*)packetB4 = 0xB4;
    *(unsigned int*)((unsigned char*)packetB4 + 1) = nErrorCode;
    sub_0052B330(0, nClientId, packetB4, 5);
}

// 0x0053D010
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2050) == pClient, 2050);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pPlayer, pItem, ITEMACTION_REMOVEFROMCONTAINER, dwCmdFlag, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

// 0x0053D090
void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_EQUIP, dwFlags, 0);
}

// 0x0053D0B0
void __fastcall D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem_6FC3EA70(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_INDIRECTLYSWAPBODYITEM, dwFlags, 0);
}

// 0x0053D0D0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unequip_6FC3EA90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNEQUIP, dwFlags, 0);
}

// 0x0053D0F0
void __fastcall D2GAME_SendP0x9D_ItemAction_SwapBodyItem_6FC3EAB0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_SWAPBODYITEM, dwFlags, 0);
}

// 0x0053D110
void __fastcall D2GAME_SendP0x9D_ItemAction_WeaponSwitch_6FC3EAD0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_WEAPONSWITCH, dwFlags, 0);
}

// 0x0053D2C0
void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_AUTOUNEQUIP, dwFlags, 0);
}

// 0x0053D350
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x14, dwFlags, 0);
}

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void* pPacket, int nPacketSize, D2ClientStrc* pClient)
{
    int nSize = 0;
    if (!pClient)
    {
        return;
    }

    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetTail(pClient);
    if (pPacketData)
    {
        nSize = pPacketData->nPacketSize;
    }

    if (nPacketSize + nSize > 0x200 || !pPacketData)
    {
        pPacketData = pClient->pPacketDataPool;
        nSize = 0;
        if (pPacketData)
        {
            pClient->pPacketDataPool = pPacketData->pNext;
        }
        else
        {
            pPacketData = (D2PacketDataStrc*)sub_0040B430(0, sizeof(D2PacketDataStrc), ".\\GAME\\SCmd.cpp", 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

// 0x0053B320
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader)
{
    D2PacketHeaderOnlyStrc tPacket;
    tPacket.nHeader = nHeader;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId)
{
    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = dwUnitType;
    tPacket.nUnitGUID = dwUnitId;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B400
void __fastcall D2GAME_SendPacketSize05_6FC3C880(D2ClientStrc* pClient, unsigned char nHeader, int nValue)
{
    D2PacketSize05Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0053B340
void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame)
{
    D2GSPacketSrv01 packet01;

    packet01.nHeader = nHeader;
    packet01.dwArenaFlags = ARENA_GetFlags(pGame);
    packet01.nDifficulty = pGame->nDifficulty;
    packet01.nExpansion = pGame->bExpansion != 0;
    packet01.nLadder = pGame->dwGameType != 0;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet01, sizeof(packet01), pClient);
}

// 0x0053B5F0
void __fastcall D2GAME_PACKETS_SendPacket0x68_6FC3CA90(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, char a5, int a6, char a7)
{
    D2GSPacketSrv68 packet68 = {};

    packet68.nHeader = nHeader;
    packet68.nUnitGUID = nUnitGUID;
    packet68.unk0x05 = a4;
    packet68.unk0x0A = a5;
    packet68.unk0x0B = a6;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;

    packet68.nX = CLIENTS_GetUnitXInline(pMonster);
    packet68.nY = CLIENTS_GetUnitYInline(pMonster);
    packet68.unk0x0F = a7;
    packet68.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet68.nPathType >= 5)
    {
        if (packet68.nPathType > 6)
        {
            if (packet68.nPathType == 8)
            {
                packet68.nPathType = 11;
            }
        }
        else
        {
            packet68.nPathType = 2;
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet68.nVelocity = nVelocity;
    packet68.unk0x14 = sub_00648EA0_GetPathByte(pPath);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet68, sizeof(packet68), pClient);
}

// 0x0053B710
void __fastcall D2GAME_PACKETS_SendPacket0x67_6FC3CBC0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, short nX, short nY, char a7)
{
    D2GSPacketSrv67 packet67 = {};

    packet67.nHeader = nHeader;
    packet67.nUnitGUID = nUnitGUID;
    packet67.unk0x05 = a4;
    packet67.nX = nX;
    packet67.nY = nY;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet67.unk0x0A = a7;
    packet67.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet67.nPathType >= 5)
    {
        if (packet67.nPathType > 6)
        {
            if (packet67.nPathType == 8)
            {
                packet67.nPathType = 11;
            }
        }
        else
        {
            packet67.nPathType = 1;
            packet67.nX = sub_00648A40_GetTargetX(pPath);
            packet67.nY = sub_00648A60_GetTargetY(pPath);
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet67.nVelocity = nVelocity;
    packet67.unk0x0F = sub_00648EA0_GetPathByte(pPath);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet67, sizeof(packet67), pClient);
}

// 0x0053B7F0
void __fastcall D2GAME_PACKETS_SendPacket0x68_6FC3CCB0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, char a5, int a6, char a7, char a8, char a9)
{
    D2GSPacketSrv68 packet68 = {};

    packet68.nHeader = nHeader;
    packet68.nUnitGUID = nUnitGUID;
    packet68.unk0x05 = a4;
    packet68.unk0x0A = a5;
    packet68.unk0x0B = a6;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet68.nX = CLIENTS_GetUnitXInline(pMonster);
    packet68.nY = CLIENTS_GetUnitYInline(pMonster);
    packet68.unk0x0F = a7;
    packet68.unk0x10 = a9;
    packet68.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet68.nPathType == 8)
    {
        packet68.nPathType = 11;
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet68.nVelocity = nVelocity;
    packet68.unk0x14 = a8;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet68, sizeof(packet68), pClient);
}

// 0x0053B910
void __fastcall D2GAME_PACKETS_SendPacket0x67_6FC3CDE0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, short nX, short nY, char a7, char a8, char a9)
{
    D2GSPacketSrv67 packet67 = {};

    packet67.nHeader = nHeader;
    packet67.nUnitGUID = nUnitGUID;
    packet67.unk0x05 = a4;
    packet67.nX = nX;
    packet67.nY = nY;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet67.unk0x0A = a7;
    packet67.unk0x0B = a9;
    packet67.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet67.nPathType >= 5)
    {
        if (packet67.nPathType > 6)
        {
            if (packet67.nPathType == 8)
            {
                packet67.nPathType = 11;
            }
        }
        else
        {
            packet67.nPathType = 1;
            packet67.nX = sub_00648A40_GetTargetX(pPath);
            packet67.nY = sub_00648A60_GetTargetY(pPath);
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet67.nVelocity = nVelocity;
    packet67.unk0x0F = a8;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet67, sizeof(packet67), pClient);
}

// 0x0053B9F0
void __fastcall D2GAME_PACKETS_SendPacket0x6A_6FC3CEE0(D2ClientStrc* pClient, char a2, int nUnitGUID, char a4, char a5, int a6, char nDirection)
{
    D2GSPacketSrv6A packet6A = {};

    packet6A.nHeader = a2;
    packet6A.nUnitGUID = nUnitGUID;
    packet6A.unk0x05 = a4;
    packet6A.nTargetUnitType = a5;
    packet6A.nTargetUnitGuid = a6;
    packet6A.nDirection = nDirection;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6A, sizeof(packet6A), pClient);
}

// 0x0053BA40
void __fastcall D2GAME_PACKETS_SendPacket0x69_6FC3CF30(D2ClientStrc* pClient, char a2, int a3, char a4, short a5, short a6, char a7, char a8)
{
    D2GSPacketSrv69 packet69 = {};

    packet69.nHeader = a2;
    packet69.unk0x01 = a3;
    packet69.unk0x05 = a4;
    packet69.unk0x06 = a5;
    packet69.unk0x08 = a6;
    packet69.unk0x0A = a7;
    packet69.unk0x0B = a8;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet69, sizeof(packet69), pClient);
}

// 0x0053BAA0
void __fastcall D2GAME_PACKETS_SendPacket0x6C_6FC3CF90(D2ClientStrc* pClient, char a2, int a3, char a4, char a5, int a6, char a7, short a8, short a9)
{
    D2GSPacketSrv6C packet6C = {};

    packet6C.nHeader = a2;
    packet6C.unk0x01 = a3;
    packet6C.unk0x05 = a4;
    packet6C.unk0x06 = a5;
    packet6C.unk0x07 = a6;
    packet6C.unk0x0B = a7;
    packet6C.unk0x0C = a8;
    packet6C.unk0x0E = a9;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6C, sizeof(packet6C), pClient);
}

// 0x0053BB00
void __fastcall D2GAME_PACKETS_SendPacket0x6B_6FC3D000(D2ClientStrc* pClient, char a2, int a3, char a4, short a5, short a6, char a7, char a8, short a9, short a10)
{
    D2GSPacketSrv6B packet6B = {};

    packet6B.nHeader = a2;
    packet6B.unk0x01 = a3;
    packet6B.unk0x05 = a4;
    packet6B.unk0x06 = a5;
    packet6B.unk0x08 = a6;
    packet6B.unk0x0A = a7;
    packet6B.unk0x0B = a8;
    packet6B.unk0x0C = a9;
    packet6B.unk0x0E = a10;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6B, sizeof(packet6B), pClient);
}

// 0x0053BB70
void __fastcall D2GAME_PACKETS_SendPacket0x6D_6FC3D080(D2ClientStrc* pClient, unsigned int dwUnitId, unsigned short nX, unsigned short nY, unsigned char nUnitLife)
{
    D2GSPacketSrv6D packet6D = {};

    packet6D.nHeader = 0x6D;
    packet6D.unk0x01 = dwUnitId;
    packet6D.unk0x05 = nX;
    packet6D.unk0x07 = nY;
    packet6D.unk0x09 = nUnitLife;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6D, sizeof(packet6D), pClient);
}

// 0x0053BDD0
void __fastcall D2GAME_PACKETS_SendPacket0x1A_B_C_6FC3D410(D2ClientStrc* pClient, int nExperience, int a3)
{
    const int nDiff = nExperience - a3;

    if (nDiff >= 0 && nDiff < 0xFFFF)
    {
        if (nDiff < 0xFF)
        {
            D2GSPacketSrv1A packet1A;
            packet1A.nHeader = 0x1A;
            packet1A.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket_6FC3C710(&packet1A, sizeof(packet1A), pClient);
        }
        else
        {
            D2GSPacketSrv1B packet1B;
            packet1B.nHeader = 0x1B;
            packet1B.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket_6FC3C710(&packet1B, sizeof(packet1B), pClient);
        }
    }
    else
    {
        D2GSPacketSrv1C packet1C;
        packet1C.nHeader = 0x1C;
        packet1C.nExperience = nExperience;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1C, sizeof(packet1C), pClient);
    }
}

// 0x0053BE40
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue)
{
    D2_ASSERT(nStatId < 0xFF, 971);

    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = (unsigned char)nStatId;
        packet1D.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1D, sizeof(packet1D), pClient);
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = (unsigned char)nStatId;
        packet1E.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1E, sizeof(packet1E), pClient);
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = (unsigned char)nStatId;
        packet1F.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1F, sizeof(packet1F), pClient);
    }
}

// 0x0053BEE0
void __fastcall D2GAME_PACKETS_SendPacket0x9E_9F_A0_6FC3D520(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nStatId, unsigned int nValue)
{
    D2_ASSERT(nStatId < 0xFF, 1013);

    const int bFitsWord = nValue < 0xFFFF;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv9E packet9E;
        packet9E.nHeader = 0x9E;
        packet9E.nStat = (unsigned char)nStatId;
        packet9E.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9E.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet9E, sizeof(packet9E), pClient);
    }
    else if (bFitsWord)
    {
        D2GSPacketSrv9F packet9F;
        packet9F.nHeader = 0x9F;
        packet9F.nStat = (unsigned char)nStatId;
        packet9F.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9F.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet9F, sizeof(packet9F), pClient);
    }
    else
    {
        D2GSPacketSrvA0 packetA0;
        packetA0.nHeader = 0xA0;
        packetA0.nStat = (unsigned char)nStatId;
        packetA0.dwGUID = SCMD_GetUnitGUID(pUnit);
        packetA0.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packetA0, sizeof(packetA0), pClient);
    }
}

// 0x0053B390
void __fastcall D2GAME_PACKETS_SendPacket0x03_6FC3C810(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId)
{
    D2GSPacketSrv03Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nAct = nAct;
    tPacket.dwGameSeed = dwInitSeed;
    tPacket.nObjectSeed = dwObjSeed;
    tPacket.nTownLevelId = nTownLevelId;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B430
void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct)
{
    D2GSPacketSrv0C packet0C;

    packet0C.nHeader = nHeader;
    packet0C.nUnitType = nUnitType;
    packet0C.dwUnitGUID = nUnitGUID;
    packet0C.nMessage = a5;
    packet0C.nHitClass = nHitClass;
    packet0C.nLife = nLifePct;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet0C, sizeof(packet0C), pClient);
}

// 0x0053B4B0
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife)
{
    D2GSPacketSrv0D packet0D;

    packet0D.nHeader = nPacketId;
    packet0D.nUnitType = nUnitType;
    packet0D.dwUnitGUID = nUnitId;
    packet0D.nHitClass = nHitClass;
    packet0D.nX = nX;
    packet0D.nY = nY;
    packet0D.nHitType = nHitType;
    packet0D.nUnitLifePct = nLife;

    D2_ASSERT(nUnitType < 6, 0x136);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet0D, sizeof(packet0D), pClient);
}

// 0x0053BC10
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7)
{
    D2GSPacketSrv15 packet15;

    packet15.nHeader = nHeader;
    packet15.nUnitType = nUnitType;
    packet15.dwUnitGUID = nUnitGUID;
    packet15.nPosX = nPosX;
    packet15.nPosY = nPosY;
    packet15.bReassign = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet15, sizeof(packet15), pClient);
}

// 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv07 packet07;

    packet07.nHeader = 0x07;
    packet07.nX = nTileX;
    packet07.nY = nTileY;
    packet07.nLevelId = nAreaId;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet07, sizeof(packet07), pClient);
}

// 0x0053D880
void __fastcall sub_6FC3F4D0(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7)
{
    D2GSPacketSrv57 packet57;

    packet57.nHeader = 0x57;
    packet57.dwUnitGUID = a2;
    packet57.nUnitType = a3;
    packet57.nNameSeed = a4;
    packet57.nUMods01 = a5;
    packet57.nUMods23 = a6;
    packet57.bChampion = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet57, sizeof(packet57), pClient);
}

// 0x0053B470
void __fastcall D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char a6, int nAnimMode)
{
    D2GSPacketSrv0EStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.a5 = a5;
    tPacket.a6 = a6;
    tPacket.nAnimMode = nAnimMode;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B520
void __fastcall D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(D2ClientStrc* pClient, char nHeader, char a3, int a4, char a5, int a6, int a7, short a8, short a9)
{
    D2GSPacketSrv10Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = a3;
    tPacket.nUnitGUID = a4;
    tPacket.nFlags = a5;
    tPacket.nTargetType = a6;
    tPacket.nTargetGUID = a7;
    tPacket.nCurrentPosX = a8;
    tPacket.nCurrentPosY = a9;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053B570
void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10)
{
    D2GSPacketSrv0FStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = bTOU;
    tPacket.nUnitGUID = a4;
    tPacket.nFlags = a5;
    tPacket.nDestPosX = a6;
    tPacket.nDestPosY = a7;
    tPacket.nHitClass = a8;
    tPacket.nCurrentPosX = a9;
    tPacket.nCurrentPosY = a10;
    D2_ASSERT(bTOU < UNIT_TYPES_COUNT, 0x166);
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053BBC0
void __stdcall sub_0053BBC0(int nUnused1, int nUnused2)
{
}

// 0x0053BBD0
void __stdcall sub_0053BBD0(int nUnused1, int nUnused2)
{
}

// 0x0053BBE0
void __stdcall sub_0053BBE0(int nUnused1, int nUnused2)
{
}

// 0x0053BBF0
void __stdcall sub_0053BBF0(int nUnused1, int nUnused2)
{
}

// 0x0053BC00
void __stdcall sub_0053BC00(int nUnused1, int nUnused2)
{
}

// 0x0053C740
void __stdcall sub_0053C740(int nUnused1)
{
}

// 0x0053FDF0
int __cdecl sub_0053FDF0()
{
    return 0;
}

// 0x0054B920
int __stdcall sub_0054B920(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054C360
int __stdcall sub_0054C360(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054C370
int __stdcall sub_0054C370(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054D740
int __stdcall sub_0054D740(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0055D930
void __stdcall sub_0055D930(int nUnused1)
{
}

// 0x0055E9A0
int __stdcall sub_0055E9A0(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0055F4F0
void __stdcall sub_0055F4F0(int nUnused1)
{
}

// 0x00568DB0
int __cdecl sub_00568DB0()
{
    return 0;
}

// 0x00570680
int __cdecl sub_00570680()
{
    return 5;
}

// 0x00570690
void __stdcall sub_00570690(int nUnused1)
{
}

// 0x005991B0
void __stdcall sub_005991B0(int nUnused1)
{
}

// 0x0059B6C0
void __stdcall sub_0059B6C0(int nUnused1, int nUnused2)
{
}

// 0x0059B6D0
void __stdcall sub_0059B6D0(int nUnused1, int nUnused2)
{
}

// 0x0059C3B0
void __stdcall sub_0059C3B0(int nUnused1)
{
}

// 0x005A0110
int __cdecl sub_005A0110()
{
    return 0;
}

// 0x005A6220
int __fastcall sub_005A6220(FieldStrc_005A6220* pObject)
{
    return pObject->unk0x10;
}

// 0x0053BC90
void __fastcall D2GAME_PACKETS_SendPacket0x08_6FC3D160(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv08 packet08;
    packet08.nHeader = 8;
    packet08.nX = nTileX;
    packet08.nY = nTileY;
    packet08.nLevelId = nAreaId;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet08, sizeof(packet08), pClient);
}

// 0x0053BCD0
void __fastcall D2GAME_PACKETS_SendPacket0x09_6FC3D1A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, unsigned int nUnitGUID, unsigned char nClassId, unsigned short nPosX, unsigned short nPosY)
{
    D2GSPacketSrv09 packet09;
    packet09.nHeader = nHeader;
    packet09.nUnitType = nUnitType;
    packet09.dwUnitGUID = nUnitGUID;
    packet09.nClassId = nClassId;
    packet09.nPosX = nPosX;
    packet09.nPosY = nPosY;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet09, sizeof(packet09), pClient);
}

// 0x0053BD10
void __fastcall D2GAME_PACKETS_SendPacket0x51_6FC3D300(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nObjectId, unsigned short nX, unsigned short nY, unsigned char nAnimMode, unsigned char nInteractType)
{
    D2_ASSERT(SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID), 0x341);

    D2GSPacketSrv51 packet51;
    packet51.nHeader = nHeader;
    packet51.nUnitType = nUnitType;
    packet51.dwUnitGUID = nUnitGUID;
    packet51.nObject = nObjectId;
    packet51.nPosX = nX;
    packet51.nPosY = nY;
    packet51.nObjectParam = nAnimMode;
    packet51.nInteractType = nInteractType;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet51, sizeof(packet51), pClient);
}

// 0x0053BDA0
void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID)
{
    if (nUnitType == 3)
    {
        return;
    }

    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053BFD0
void __fastcall sub_0053BFD0(D2ClientStrc* client,D2UnitStrc* unit,unsigned short stat,unsigned int base,unsigned int full) {
 if(stat>=0xFF) {sub_00408A60(text_006CC837,sub_00408090(),1069);sub_00681E09(-1);}
 full-=base;
 const int fitsWord=full<0xFFFF;
 if(full<0xFF) {
  PacketA1 packet;packet.header=0xA1;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket_6FC3C710(&packet,sizeof(packet),client);
 } else if(fitsWord) {
  PacketA2 packet;packet.header=0xA2;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket_6FC3C710(&packet,sizeof(packet),client);
 } else {
  PacketA0 packet;packet.header=0xA0;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=base;
  D2GAME_PACKETS_SendPacket_6FC3C710(&packet,sizeof(packet),client);
 }
}

// 0x0053C0E0
void __fastcall D2GAME_PACKETS_SendPacket0xA3_6FC3D730(D2ClientStrc* pClient, unsigned char a2, unsigned short a3, unsigned short a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    D2GSPacketSrvA3 packetA3 = {};

    packetA3.nHeader = 0xA3;
    packetA3.unk0x01 = a2;
    packetA3.unk0x02 = a3;
    packetA3.unk0x04 = a4;
    packetA3.unk0x06 = a5;
    packetA3.unk0x07 = a6;
    packetA3.unk0x0B = a7;
    packetA3.unk0x0C = a8;
    packetA3.unk0x10 = a9;
    packetA3.unk0x14 = a10;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA3, sizeof(packetA3), pClient);
}

// 0x0053C150
void __fastcall D2GAME_PACKETS_SendPacket0xAB_6FC3D7B0(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife)
{
    D2GSPacketSrvAB packetAB = {};

    packetAB.nHeader = 0xAB;
    packetAB.nUnitType = nUnitType;
    packetAB.dwUnitGUID = dwUnitId;
    packetAB.nLife = nUnitLife;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetAB, sizeof(packetAB), pClient);
}

// 0x0053C190
void __fastcall D2GAME_PACKETS_SendPacket0xA5_6FC3D7F0(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4)
{
    D2GSPacketSrvA5 packetA5 = {};

    packetA5.nHeader = 0xA5;
    packetA5.unk0x01 = a2;
    packetA5.unk0x02 = a3;
    packetA5.unk0x06 = a4;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA5, sizeof(packetA5), pClient);
}

// 0x0053C520
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity)
{
    D2GSPacketSrv22 packet22;

    packet22.nHeader = 0x22;
    packet22.nUnitType = nUnitType;
    packet22.nUnitGUID = nUnitGUID;
    packet22.nSkillId = nSkillId;
    packet22.nQuantity = nQuantity;

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID);
    packet22.bIsCorpse = pUnit && STATES_CheckState(pUnit, 7);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet22, sizeof(packet22), pClient);
}

// 0x0053C850
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket)
{
    D2_ASSERT(strlen(pPacket->szText) < 16, 1498);

    D2GSPacketSrv5A packet5A = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5A, sizeof(packet5A), pClient);
}

// 0x0053C8D0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket)
{
    D2GSPacketSrv27 packet27 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet27, sizeof(packet27), pClient);
}

// 0x0053C900
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket)
{
    D2GSPacketSrv53 packet53 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet53, sizeof(packet53), pClient);
}

// 0x0053CA90
void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID)
{
    D2GSPacketSrv5C packet5C;
    packet5C.nHeader = 0x5C;
    packet5C.dwPlayerGUID = nUnitGUID;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5C, sizeof(packet5C), pClient);
}

// 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo)
{
    D2GSPacketSrv77 packet77;
    packet77.nHeader = 0x77;
    packet77.nAction = nUiNo;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet77, sizeof(packet77), pClient);
}

// 0x0053CAD0
void __fastcall sub_0053CAD0_SendPacket0x78(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket)
{
    D2GSPacketSrv78 packet78 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet78, sizeof(packet78), pClient);
}

// 0x0053CB30
void __fastcall D2GAME_PACKETS_SendPacket0x7A_6FC3E100(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass)
{
    D2GSPacketSrv7A packet7A = {};

    packet7A.nHeader = 0x7A;
    packet7A.unk0x01 = a2;
    packet7A.unk0x02 = nPetType;
    packet7A.unk0x03 = nPetClass;
    packet7A.unk0x09 = nPetGUID;
    packet7A.unk0x05 = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7A, sizeof(packet7A), pClient);
}

// 0x0053CB80
void __fastcall D2GAME_PACKETS_SendPacket0x81_6FC3E160(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName)
{
    D2GSPacketSrv81 packet81 = {};

    packet81.nHeader = 0x81;
    packet81.unk0x01 = nPetType;
    packet81.unk0x08 = nPetGUID;
    packet81.unk0x04 = nUnitGUID;
    packet81.unk0x02 = nPetClass;
    packet81.unk0x0C = nSeed;
    packet81.unk0x10 = nName;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet81, sizeof(packet81), pClient);
}

// 0x0053C1D0
void __fastcall sub_6FC3D830(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue)
{
    D2_ASSERT(nStatId < 0xFF, 0x4B8);
    D2GSPacketSrv20Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.dwUnitGUID = nUnitGUID;
    tPacket.nStat = nStatId;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053C230
void __fastcall SCMD_SendVitalsAndPotionPrediction(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned char nPotionLifePercent, unsigned char nPotionManaPercent, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[15];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x18, 8);
    BITMANIP_Write(&bitBuffer, nHitpoints, 15);
    BITMANIP_Write(&bitBuffer, nMana, 15);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPotionLifePercent, 7);
    BITMANIP_Write(&bitBuffer, nPotionManaPercent, 7);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket_6FC3C710(packet, BITMANIP_GetSize(&bitBuffer), pClient);
}

// 0x0053C320
void __fastcall SCMD_SendVitals(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[13];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x95, 8);
    BITMANIP_Write(&bitBuffer, nHitpoints, 15);
    BITMANIP_Write(&bitBuffer, nMana, 15);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket_6FC3C710(packet, BITMANIP_GetSize(&bitBuffer), pClient);
}

// 0x0053C3F0
void __fastcall D2GAME_PACKETS_SendPacket0x96_WalkVerify_6FC3DA90(D2ClientStrc* pClient, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[9];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x96, 8);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket_6FC3C710(packet, BITMANIP_GetSize(&bitBuffer), pClient);
}

// 0x0053C590
void __fastcall D2GAME_PACKETS_SendPacket0x23_6FC3DC60(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char a4, unsigned short a5, int a6)
{
    D2GSPacketSrv23Strc tPacket;
    tPacket.nPosition = a4;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nSkill = a5;
    tPacket.nHeader = 0x23;
    tPacket.nOwnerGUID = a6;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053C6F0
void __fastcall sub_0053C6F0_SendPacket0x93(D2ClientStrc* pClient, int nUnitGUID, unsigned char nBonus, unsigned char nCharClass, int bSkillTab, unsigned char nSkillTab)
{
    D2GSPacketSrv93Strc tPacket;
    tPacket.nHeader = 0x93;
    tPacket.dwUnitGUID = nUnitGUID;
    tPacket.nBonus = nBonus;
    tPacket.nCharClass = nCharClass;
    if (bSkillTab)
    {
        tPacket.nSkillTab = nSkillTab;
    }
    else
    {
        tPacket.nSkillTab = 4;
    }
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053C730
extern "C" void __stdcall sub_0053C730(unsigned arg0,unsigned arg1,unsigned arg2) {}

// 0x0053C930
void __fastcall sub_0053C930_SendPacketSize03(D2ClientStrc* pClient, const void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, 3, pClient);
}

// 0x0053CBE0
void __fastcall D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(D2ClientStrc* pClient, int nGold, char bOwnGold)
{
    D2GSPacketSrv79 packet79;
    packet79.nHeader = 0x79;
    packet79.bOwnGold = bOwnGold;
    packet79.dwGold = nGold;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet79, sizeof(packet79), pClient);
}

// 0x0053CC10
static int SCMD_ShouldSendLifeUpdate(int nLifePercentage, D2LifeSyncStrc* pLifeSync)
{
    int nDiff = nLifePercentage - pLifeSync->nLifePercentage;
    if (nDiff)
    {
        if (nDiff < 0)
        {
            nDiff = -nDiff;
        }
        if (nDiff > 8)
        {
            pLifeSync->nUpdateCount = 0;
            pLifeSync->nLifePercentage = nLifePercentage;
            return 1;
        }
        if (++pLifeSync->nUpdateCount > 6)
        {
            pLifeSync->nUpdateCount = 0;
            pLifeSync->nLifePercentage = nLifePercentage;
            return 1;
        }
    }
    return 0;
}

static D2LifeSyncStrc* GetMonsterLifeSync(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return &pUnit->pMonsterData->tLifeSync;
    }
    return 0;
}

static int __stdcall sub_0053CC40_ShouldSendMinionLifeUpdate(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nLifePercentage)
{
    if (AIGENERAL_GetMinionOwner(pUnit) != pPlayer)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = GetMonsterLifeSync(pUnit);
    if (!pLifeSync)
    {
        return 0;
    }
    if (pLifeSync->nLifePercentage == nLifePercentage)
    {
        return 0;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    if (!pGame)
    {
        return 0;
    }
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pPlayer);
    if (nPartyId == 0xFFFF || PARTY_GetPartyIdForUnitOwner(pGame, pUnit) != nPartyId)
    {
        return 0;
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    D2LifeSyncStrc* pLifeSync = pPlayerData->pPartyLifeList;
    while (pLifeSync)
    {
        if (pLifeSync->nUnitGUID == nUnitGUID)
        {
            goto found;
        }
        pLifeSync = pLifeSync->pNext;
    }
    pLifeSync = (D2LifeSyncStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2LifeSyncStrc), ".\\GAME\\SCmd.cpp", 0x6FA, 0);
    if (!pLifeSync)
    {
        return 0;
    }
    *pLifeSync = D2LifeSyncStrc();
    pLifeSync->pNext = pPlayerData->pPartyLifeList;
    pPlayerData->pPartyLifeList = pLifeSync;
    pLifeSync->nUnitGUID = nUnitGUID;
found:
    if (pLifeSync->nLevelId != nLevelId)
    {
        pLifeSync->nLifePercentage = nLifePercentage;
        pLifeSync->nLevelId = nLevelId;
        return 1;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, int nLifePercentage, D2UnitStrc* pUnit, int nLevelId)
{
    D2_ASSERT(pPlayer, 0x712);
    D2_ASSERT(pUnit, 0x713);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SCMD_ShouldSendPartyLifeUpdate(pUnit, nLifePercentage, nLevelId, pPlayer);
    case UNIT_MONSTER:
        return sub_0053CC40_ShouldSendMinionLifeUpdate(pUnit, pPlayer, nLifePercentage);
    }
    return 0;
}

void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x72A);
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    D2GSPacketSrv7F tPacket7F = {};
    tPacket7F.nHeader = 0x7F;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        tPacket7F.bIsPlayer = 1;
    }
    tPacket7F.nUnitGUID = pUnit->dwUnitId;
    tPacket7F.nLifePercentage = nLifePercentage;
    if (nLifePercentage >= 0xFFFF)
    {
        tPacket7F.nLifePercentage = 0xFFFF;
    }
    tPacket7F.nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (sub_0053CD80_ShouldSendLifeUpdate(CLIENTS_GetPlayerFromClient(pClient, 0), nLifePercentage, pUnit, tPacket7F.nLevelId))
    {
        D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket7F, sizeof(tPacket7F), pClient);
    }
    if (tPacket7F.bIsPlayer && sub_006416D0_UnitEdgeDistance(CLIENTS_GetPlayerFromClient(pClient, 0), pUnit) > 50)
    {
        D2GSPacketSrv90 tPacket90 = {};
        tPacket90.nHeader = 0x90;
        tPacket90.dwGUID = pUnit->dwUnitId;
        tPacket90.dwPosX = CLIENTS_GetUnitX(pUnit);
        tPacket90.dwPosY = CLIENTS_GetUnitY(pUnit);
        D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket90, sizeof(tPacket90), pClient);
    }
}

// 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6)
{
    D2BitBufferStrc tBitBuffer;
    D2GSPacketSrv3E tPacket = {};

    tPacket.nHeader = 0x3E;
    BITMANIP_Initialize(&tBitBuffer, tPacket.pBuffer, sizeof(tPacket.pBuffer));
    sub_0053B0E0_WriteVarLength(&tBitBuffer, !pItem ? -1 : pItem->dwUnitId);
    BITMANIP_Write(&tBitBuffer, a3 != 0, 1);
    BITMANIP_Write(&tBitBuffer, nStatId, 9);
    sub_0053B0E0_WriteVarLength(&tBitBuffer, nValue);
    if (a6 < 0x100)
    {
        BITMANIP_Write(&tBitBuffer, 0, 1);
        BITMANIP_Write(&tBitBuffer, a6, 8);
    }
    else
    {
        BITMANIP_Write(&tBitBuffer, 1, 1);
        BITMANIP_Write(&tBitBuffer, a6, 16);
    }
    tPacket.nSize = BITMANIP_GetSize(&tBitBuffer) + 2;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

static inline int SCMD_GetUnitTypeOr6(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 6;
    return pUnit->dwUnitType;
}

// 0x0053D2E0
void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv42 packet42 = {};

    packet42.nHeader = 0x42u;
    int nUnitType;
    if (!pUnit)
        nUnitType = 6;
    else
        nUnitType = pUnit->dwUnitType;
    packet42.nUnitType = nUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet42.dwUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet42, sizeof(packet42), pClient);
}

// 0x0053D370
void __fastcall D2GAME_SendPacket0x47_6FC3EEE0(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv47 packet47 = {};

    packet47.nHeader = 0x47;
    int nUnitType;
    if (!pUnit)
        nUnitType = 6;
    else
        nUnitType = pUnit->dwUnitType;
    packet47.nUnitType = nUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet47.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet47, sizeof(packet47), pClient);
}

// 0x0053D3C0
void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient, D2UnitStrc* pUnit, int a3)
{
    D2GSPacketSrv48 packet48 = {};

    packet48.unk0x02 = a3;
    packet48.nHeader = 0x48;
    packet48.nUnitType = SCMD_GetUnitTypeOr6(pUnit);
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet48.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet48, sizeof(packet48), pClient);
}

// 0x0053D330
void __fastcall sub_0053D330_SendItemAction13(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, 0x13, dwFlag, 0);
}

// 0x0053D420
void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UPDATESTATS, dwFlags, 0);
}

// 0x0053D4B0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x16, dwFlags, 0);
}

// 0x0053EA50
int __fastcall sub_0053EA50_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags)
{
    if (ITEMS_CheckIfSocketable(pItem) && !sub_006287A0_TestFlags(nFlags, IFLAG_QUANTITY) && pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            ITEMS_SetOrRemoveFlag(&nFlags, IFLAG_DELETED, 1);
            D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pItem, pSocketed, ITEMACTION_ITEMINSOCKET, nFlags, 0);
        }
        return 1;
    }
    return 0;
}

// 0x0053EC00
void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround_6FC3E850(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDTOGROUND, dwFlag, 0);
}

// 0x0053EC20
void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2002) == pClient, 2002);

    UNITS_SetXForStaticUnit(pItem, 0);
    UNITS_SetYForStaticUnit(pItem, 0);
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_GROUNDTOCURSOR, a4, 0);
}

// 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2031) == pClient, 2031);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_PUTINCONTAINER, a4, 0);
}

// 0x0053EDB0
void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2121) == pClient, 2121);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDQUANTITY, a4, 0);
}

// 0x0053EE10
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2131) == pClient, 2131);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_SWAPINCONTAINER, a4, 0);
}

// 0x0053EE70
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(SUNIT_GetClientFromPlayer(pPlayer, ".\\GAME\\SCmd.cpp", 2140) == pClient, 2140);

    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_PUTINBELT, a4, 0);
}

// 0x0053EED0
void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_REMOVEFROMBELT, dwFlag, 0);
}

// 0x0053EEF0
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInBelt_6FC3EC00(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a3)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_SWAPINBELT, a3, 0);
}

// 0x0053EF10
void __fastcall D2GAME_SendP0x9C_ItemAction_ToCursor_6FC3EEA0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_TOCURSOR, 0, 0);
}

// 0x0053EF30
void __fastcall D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char a3)
{
    switch (a3)
    {
    case 56:
    {
        int bIdentified = 0;
        if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem) && !ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 2498, ".\\GAME\\SCmd.cpp"))
        {
            bIdentified = 1;
        }
        D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDTOSHOP, 0, bIdentified);
        break;
    }
    case 57:
    {
        const unsigned char nPage = ITEMS_GetInvPage(pItem);
        ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
        D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_REMOVEFROMSHOP, 0, 0);
        ITEMS_SetInvPage(pItem, nPage);
        break;
    }
    }
}

// 0x0053D440
void __fastcall sub_6FC3EFC0(D2ClientStrc* pClient, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int a4, int a5)
{
    D2GSPacketSrv7D packet7D = {};

    packet7D.nHeader = 0x7D;
    int nUnitType;
    if (!pUnit1)
        nUnitType = 6;
    else
        nUnitType = pUnit1->dwUnitType;
    packet7D.nUnitType = nUnitType;
    const int nUnitGUID1 = !pUnit1 ? -1 : pUnit1->dwUnitId;
    packet7D.nUnitGUID1 = nUnitGUID1;
    const int nUnitGUID2 = !pUnit2 ? -1 : pUnit2->dwUnitId;
    packet7D.nUnitGUID2 = nUnitGUID2;
    packet7D.unk0x0A = a4;
    packet7D.unk0x0E = a5;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7D, sizeof(packet7D), pClient);
}

// 0x0053D670
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6)
{
    D2GSPacketSrv28 packet28;

    packet28.nHeader = nHeader;
    packet28.unk0x01 = a3;
    packet28.unk0x02 = a4;
    packet28.unk0x06 = a6;

    QUESTRECORD_CopyRecordToBuffer(a5, packet28.pData, 0x60, 0);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet28, sizeof(packet28), pClient);
}

// 0x0053D700
void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053D710
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket)
{
    D2GSPacketSrv5D packet5D = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5D, sizeof(packet5D), pClient);
}

// 0x0053D780
void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket)
{
    D2GSPacketSrv2C packet2C = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet2C, sizeof(packet2C), pClient);
}

// 0x0053D7B0
void __fastcall D2GAME_SendPacket0x4E_6FC3F410(D2ClientStrc* pClient, D2GSPacketSrv4E* pPacket)
{
    D2GSPacketSrv4E packet4E = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet4E, sizeof(packet4E), pClient);
}

// 0x0053D7E0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket)
{
    D2GSPacketSrv50 packet50 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet50, sizeof(packet50), pClient);
}

// 0x0053D830
void __fastcall sub_0053D830_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053D840
void __fastcall sub_0053D840(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053D850
void __fastcall D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay)
{
    D2GSPacketSrv11 packet11;

    packet11.nHeader = 0x11;
    packet11.nUnitType = nUnitType;
    packet11.dwUnitGUID = nUnitGUID;
    packet11.unk0x06 = nOverlay;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet11, sizeof(packet11), pClient);
}

// 0x0053D8D0
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket)
{
    D2GSPacketSrv58 packet58 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet58, sizeof(packet58), pClient);
}

// 0x0053D900
void __fastcall sub_6FC3F550(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv60 packet60;

    packet60.nHeader = 0x60;
    packet60.nFlags = UNITS_GetObjectPortalFlags(pUnit);
    packet60.nLevel = pUnit->pObjectData->InteractType;
    packet60.dwUnitGUID = pUnit->dwUnitId;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet60, sizeof(packet60), pClient);
}

// 0x0053D940
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue)
{
    D2GSPacketSrv61 packet61;

    packet61.nHeader = 0x61;
    packet61.unk0x01 = nValue;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet61, sizeof(packet61), pClient);
}

// 0x0053DA10
void __fastcall sub_6FC3F610(D2ClientStrc* pClient, D2GSPacketSrv73* pPacket)
{
    D2GSPacketSrv73 packet73 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet73, sizeof(packet73), pClient);
}

// 0x0053DA90
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pLocalPlayer, ".\\GAME\\SCmd.cpp", 0xAFA);

    D2GSPacketSrv75 packet75 = {};

    packet75.nHeader = 0x75u;
    const int nUnitGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;
    packet75.nUnitGUID = nUnitGUID;
    packet75.nLevel = STATLIST_UnitGetStatValue(pOtherPlayer, 0xC, 0);
    packet75.nPartyId = SUNIT_GetPartyId(pOtherPlayer);
    packet75.nFlags = PLAYERLIST_GetFlags(pLocalPlayer, pOtherPlayer);
    packet75.unk0x0B = sub_6FCBA9D0(pLocalPlayer, pOtherPlayer);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet75, sizeof(packet75), pClient);
}

// 0x0053DB20
void __fastcall D2GAME_PACKETS_SendPacket0x7B_6FC3F720(D2ClientStrc* pClient, unsigned char nIndex, int nSkill, int nHand, int nItemGUID)
{
    D2GSPacketSrv7B packet7B;

    packet7B.nHeader = 0x7Bu;
    packet7B.nSlot = nIndex;
    packet7B.nSkill = nSkill & 0xFFF;
    packet7B.nItemGUID = nItemGUID;
    if (nHand)
        packet7B.nSkill |= 0x8000;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7B, sizeof(packet7B), pClient);
}

// 0x0053DB70
void __fastcall D2GAME_PACKETS_SendPacket0x7E_6FC3F770(D2ClientStrc* pClient)
{
    D2GSPacketSrv7E packet7E;

    packet7E.nHeader = 0x7E;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7E, sizeof(packet7E), pClient);
}

// 0x0053DB90
void __fastcall D2GAME_PACKETS_SendPacket0x82_6FC3F790(D2GameStrc* pGame, D2ClientStrc* pClient, int nPortalGUID, int nPortalOwnerGUID)
{
    D2GSPacketSrv82 packet82;

    packet82.nHeader = 0x82u;
    D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, nPortalGUID);
    packet82.szOwnerName[0] = 0;
    if (pPortal)
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, OBJECTS_GetUnitIdFromTimerArg(pPortal));
        if (pPlayer)
        {
            SStrCopy(packet82.szOwnerName, UNITS_GetPlayerData(pPlayer)->szName, sizeof(packet82.szOwnerName));

            packet82.dwOwnerGUID = pPlayer->dwUnitId;
            packet82.dwPortalGUID0 = nPortalGUID;
            packet82.dwPortalGUID1 = nPortalOwnerGUID;

            D2GAME_PACKETS_SendPacket_6FC3C710(&packet82, sizeof(packet82), pClient);
        }
    }
}

// 0x0053DFB0
void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc* pClient, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;

    packet8E.nHeader = 0x8E;
    packet8E.dwPlayerGUID = nUnitId;
    packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet8E, sizeof(packet8E), pClient);
}

// 0x0053DFE0
void __fastcall sub_0053DFE0_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053DFF0
void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket)
{
    D2GSPacketSrv8A packet8A = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet8A, sizeof(packet8A), pClient);
}

// 0x0053D6D0
void __fastcall sub_6FC3F340(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5)
{
    D2PacketInteractStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitId;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053D740
void __fastcall sub_0053D740_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType)
{
    D2PacketSrv2AStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nResult = nResult;
    tPacket.nGold = nGold;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nTransactionType = nTransactionType;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053D9C0
void __fastcall D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(D2ClientStrc* pClient, unsigned int dwPlayerId, unsigned short nCount)
{
    D2GSPacketSrv65Strc tPacket;
    tPacket.nHeader = 0x65;
    tPacket.dwUnitId = dwPlayerId;
    tPacket.nKillCount = nCount;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053DA40
void __fastcall D2GAME_PACKETS_SendPacket0x74_6FC3F640(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pCorpse, unsigned char bAssign)
{
    D2GSPacketSrv74 packet74;
    packet74.nHeader = 0x74;
    packet74.bAssign = bAssign;
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet74.nPlayerGUID = nPlayerGUID;
    const int nCorpseGUID = !pCorpse ? -1 : pCorpse->dwUnitId;
    packet74.nCorpseGUID = nCorpseGUID;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet74, sizeof(packet74), pClient);
}

// 0x0053DDC0
void __fastcall D2GAME_PACKETS_SendPacket0x8B_6FC3F810(D2ClientStrc* pClient, int nUnitGUID, unsigned char nPartyState)
{
    D2GSPacketSrv8BStrc tPacket;
    tPacket.nHeader = 0x8B;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.bParty = nPartyState;
    D2GAME_PACKETS_SendPacket_6FC3C710(&tPacket, sizeof(tPacket), pClient);
}

// 0x0053E020
void __fastcall D2GAME_PACKETS_SendPacket0x8F_6FC3FA90(D2ClientStrc* pClient)
{
    D2GSPacketSrv8F packet8F = { 0x8F };
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet8F, sizeof(packet8F), pClient);
}

// 0x0053E060
void __fastcall sub_0053E060_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket)
{
    D2GSPacketSrv91 packet91 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet91, sizeof(packet91), pClient);
}

// 0x0053E0A0
void __fastcall sub_6FC3FAF0(D2ClientStrc* pClient, unsigned int a2, unsigned short a3)
{
    D2GSPacketSrv98 packet98 = {};

    packet98.nHeader = 0x98;
    packet98.unk0x01 = a2;
    packet98.unk0x05 = a3;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet98, sizeof(packet98), pClient);
}

// 0x0053E0E0
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3)
{
    D2GSPacketSrv9B packet9B;

    packet9B.nHeader = 0x9B;
    packet9B.unk0x01 = nUnitGUID;
    packet9B.unk0x03 = a3;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet9B, sizeof(packet9B), pClient);
}

// 0x0053E110
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc* pClient)
{
    D2GSPacketSrv97 packet97 = {};

    packet97.nHeader = 0x97;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet97, sizeof(packet97), pClient);
}

// 0x0053E1A0
void __fastcall D2GAME_PACKETS_SendPacket0xA4_6FC3FC00(D2ClientStrc* pClient, short a2)
{
    D2GSPacketSrvA4 packetA4;

    packetA4.nHeader = 0xA4;
    packetA4.unk0x01 = a2;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA4, sizeof(packetA4), pClient);
}

// 0x0053E260
void __fastcall D2GAME_PACKETS_SendPacket0xA7_StateOn_6FC3FC20(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA7 packetA7;

    packetA7.nHeader = 0xA7;
    packetA7.nUnitType = nUnitType;
    packetA7.nUnitId = dwUnitId;
    packetA7.nState = nState;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA7, sizeof(packetA7), pClient);
}

// 0x0053E290
void __fastcall D2GAME_PACKETS_SendPacket0xA9_StateOff_6FC3FC50(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA9 packetA9;

    packetA9.nHeader = 0xA9;
    packetA9.nUnitType = nUnitType;
    packetA9.nUnitId = dwUnitId;
    packetA9.nState = nState;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA9, sizeof(packetA9), pClient);
}

// 0x0053E8D0
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, nPacketSize, pClient);
}

// 0x0053E8F0
void __fastcall sub_6FC3D1F0(D2ClientStrc* pClient, int nUnitGUID, unsigned char nClassId, const char* szName, short nX, short nY)
{
    D2GSPacketSrv59 packet59 = {};

    packet59.nHeader = 0x59;
    packet59.dwGUID = nUnitGUID;
    packet59.nClass = nClassId;
    memset(packet59.szName, 0, sizeof(packet59.szName));
    SStrCopy(packet59.szName, szName, 0x7FFFFFFF);
    packet59.nPosX = nX;
    packet59.nPosY = nY;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet59, sizeof(packet59), pClient);

    D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_PLAYER, nUnitGUID);
    if (pOtherPlayer)
    {
        SCMD_Send0x75_PartyRosterUpdate(pLocalPlayer, pOtherPlayer);
    }
}

static __forceinline void __fastcall SCMD_SendGoldStat(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue)
{
    const unsigned char nPacketStatId = (unsigned char)nStatId;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = nPacketStatId;
        packet1D.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1D, sizeof(packet1D), pClient);
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = nPacketStatId;
        packet1E.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1E, sizeof(packet1E), pClient);
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = nPacketStatId;
        packet1F.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1F, sizeof(packet1F), pClient);
    }
}

// 0x0053E9B0
void __fastcall D2GAME_PACKETS_SendPacket0x19_6FC3D3D0(D2ClientStrc* pClient, int nValue, int a3)
{
    const int nDiff = nValue - a3;
    if (nDiff <= 0 || nDiff >= 0xFF)
    {
        SCMD_SendGoldStat(pClient, STAT_GOLD, nValue);
    }
    else
    {
        D2GSPacketSrv19 packet19;
        packet19.nHeader = 0x19;
        packet19.nGold = nDiff;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet19, sizeof(packet19), pClient);
    }
}

// 0x0053EAE0
void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);

    D2_ASSERT(pPlayer, 1915);

    D2GSPacketSrv9C packet9C;

    packet9C.nHeader = 0x9C;
    packet9C.nAction = nAction;
    packet9C.nItemId = SCMD_GetUnitGUID(pItem);
    packet9C.nComponent = sub_00623D60_GetItemComponent(pPlayer, pItem);

    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);

    memset(packet9C.pBitstream, 0, sizeof(packet9C.pBitstream));

    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet9C.pBitstream, sizeof(packet9C.pBitstream), 0, 0, bGamble) + 8;

    D2_ASSERT(nLength <= 0xFC, 1932);

    packet9C.nPacketSize = nLength;
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet9C, packet9C.nPacketSize, pClient);

    sub_0053EA50_SendSocketedItems(pClient, pItem, dwFlag);
}

// 0x0053E130
void __fastcall sub_0053E130_SendUnitUpdates(D2ClientStrc* pClient)
{
    int nCount = pClient->nCount;
    if (nCount)
    {
        D2PacketDataStrc* pData = CLIENTS_PacketDataList_GetHead(pClient);
        unsigned short nSize = (unsigned short)(sizeof(D2GSPacketSrv16) + sizeof(D2UnitUpdateEntry) * nCount);
        D2GSPacketSrv16* pPacket = (D2GSPacketSrv16*)(pData->data + pData->nSize);
        pPacket->nHeader = 0x16;
        pPacket->nCount = (unsigned char)nCount;
        pPacket->nSize = nSize;
        D2UnitUpdateEntry* pOut = pPacket->entries;
        for (int i = 0; i < nCount; ++i)
        {
            *pOut++ = pClient->entries[i];
        }
        pData->nSize += nSize;
    }
}

// 0x0053E1C0
void __fastcall sub_0053E1C0_SendPacket0xA6(D2ClientStrc* pClient, unsigned char nType, short wArg, int nSize, const void* pData)
{
    D2GSPacketSrvA6 packet;
    packet.nHeader = 0xA6;
    packet.nType = nType;
    packet.wArg = wArg;
    const int nPacketSize = nSize + 6;
    D2_ASSERT(nPacketSize < 0xFFFF, 0xD0D);
    packet.nPacketSize = nPacketSize;
    memcpy(packet.data, pData, nSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet, nPacketSize, pClient);
}

// 0x0053E840
int __fastcall sub_0053E840_SendPacket0xAE(D2ClientStrc* pClient, const void* pData, unsigned int nSize)
{
    D2GSPacketSrvAE packet;
    if (nSize <= 0x1FD)
    {
        packet.nHeader = 0xAE;
        packet.nSize = nSize;
        memcpy(packet.data, pData, nSize);
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet, nSize + 3, pClient);
        return 1;
    }
    D2_ASSERT(nSize <= 0x1FD, 0xE38);
}
