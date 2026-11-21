#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2UnitData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Primitives.h"
#include "D2GameObjs.h"
#include "D2GameClient.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

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
struct D2UnitUpdateEntry
{
    int nFirst;
    int nSecond;
    unsigned char nType;
};
#pragma pack(pop)


void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053CEF0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2PacketSize06Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2PacketSize05Strc
{
    unsigned char nHeader;
    int nValue;
};
#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient); // 0x005392D0

void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData); // 0x00539240

#pragma pack(push, 1)
struct D2GSPacketSrv01
{
    unsigned char nHeader;
    unsigned char nDifficulty;
    unsigned int dwArenaFlags;
    unsigned char nExpansion;
    unsigned char nLadder;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv1A
{
    unsigned char nHeader;
    unsigned char nExperience;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv1B
{
    unsigned char nHeader;
    unsigned short nExperience;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv1C
{
    unsigned char nHeader;
    unsigned int nExperience;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv1D
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned char nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv1E
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned short nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv1F
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned int nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv69
{
    unsigned char nHeader;
    unsigned int unk0x01;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short unk0x08;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv6A
{
    unsigned char nHeader;
    unsigned int nUnitGUID;
    unsigned char unk0x05;
    unsigned char nTargetUnitType;
    unsigned int nTargetUnitGuid;
    unsigned char nDirection;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv6B
{
    unsigned char nHeader;
    unsigned int unk0x01;
    unsigned char unk0x05;
    unsigned short unk0x06;
    unsigned short unk0x08;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned short unk0x0C;
    unsigned short unk0x0E;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv6C
{
    unsigned char nHeader;
    unsigned int unk0x01;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned int unk0x07;
    unsigned char unk0x0B;
    unsigned short unk0x0C;
    unsigned short unk0x0E;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv6D
{
    unsigned char nHeader;
    unsigned int unk0x01;
    unsigned short unk0x05;
    unsigned short unk0x07;
    unsigned char unk0x09;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv67
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char unk0x05;
    short nX;
    short nY;
    char unk0x0A;
    char unk0x0B;
    unsigned char nPathType;
    short nVelocity;
    char unk0x0F;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv68
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char unk0x05;
    short nX;
    short nY;
    char unk0x0A;
    int unk0x0B;
    char unk0x0F;
    char unk0x10;
    unsigned char nPathType;
    short nVelocity;
    char unk0x14;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv9E
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned int dwGUID;
    unsigned char nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv9F
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned int dwGUID;
    unsigned short nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA0
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned int dwGUID;
    unsigned int nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA1
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned int dwGUID;
    unsigned char nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA2
{
    unsigned char nHeader;
    unsigned char nStat;
    unsigned int dwGUID;
    unsigned short nValue;
};
#pragma pack(pop)

unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame); // 0x0053FD40

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall sub_00648A40_GetTargetX(D2DynamicPathStrc* pPath); // 0x00648A40

int __stdcall sub_00648A60_GetTargetY(D2DynamicPathStrc* pPath); // 0x00648A60

unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pPath); // 0x00648EA0

#pragma pack(push, 1)
struct D2GSPacketSrv03Strc
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned int dwGameSeed;
    unsigned short nTownLevelId;
    unsigned int nObjectSeed;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv0C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessage;
    unsigned char nHitClass;
    unsigned char nLife;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv15
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char bReassign;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv07
{
    unsigned char nHeader;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv23
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nPosition;
    unsigned short nSkill;
    unsigned int nOwnerGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv3F
{
    unsigned char nHeader;
    unsigned char nCursor;
    unsigned int dwItemId;
    unsigned short nSkill;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv09
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nClassId;
    unsigned short nPosX;
    unsigned short nPosY;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct PacketA1
{
    unsigned char header,stat;
    int guid;
    unsigned char value;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PacketA2
{
    unsigned char header,stat;
    int guid;
    unsigned short value;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PacketA0
{
    unsigned char header,stat;
    int guid;
    unsigned int value;
};
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvAB
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nLife;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA5
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    unsigned short unk0x06;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5C
{
    unsigned char nHeader;
    unsigned int dwPlayerGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv77
{
    unsigned char nHeader;
    unsigned char nAction;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv78
{
    unsigned char nHeader;
    char szName[16];
    unsigned int dwPlayerGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned short unk0x03;
    unsigned int unk0x05;
    unsigned int unk0x09;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv93Strc
{
    unsigned char nHeader;
    int dwUnitGUID;
    unsigned char nBonus;
    unsigned char nCharClass;
    unsigned char nSkillTab;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv79
{
    unsigned char nHeader;
    unsigned char bOwnGold;
    unsigned int dwGold;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7F
{
    unsigned char nHeader;
    unsigned char bIsPlayer;
    unsigned short nLifePercentage;
    int nUnitGUID;
    unsigned short nLevelId;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv90
{
    unsigned char nHeader;
    int dwGUID;
    int dwPosX;
    int dwPosY;
};
#pragma pack(pop)

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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv47
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned int nUnitGUID;
    unsigned int unk0x07;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv28
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    unsigned char unk0x06;
    unsigned char pData[96];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv29
{
    unsigned char nHeader;
    unsigned char pData[96];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short nSoundEvent;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv4E
{
    unsigned char nHeader;
    unsigned short nMercName;
    int nSeed;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nMonstersToBeKilled;
    unsigned short nStaffTombLevelOffset;
    unsigned short nBarbsToBeRescued;
    unsigned char unk0x09[6];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    unsigned char unk0x001[37];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv52
{
    unsigned char nHeader;
    unsigned char pQuestList[41];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv11
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short unk0x06;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
    unsigned char unk0x06;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv60
{
    unsigned char nHeader;
    unsigned char nFlags;
    unsigned char nLevel;
    int dwUnitGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv61
{
    unsigned char nHeader;
    unsigned char unk0x01;
};
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv75
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned short nPartyId;
    unsigned short nLevel;
    unsigned short nFlags;
    unsigned short unk0x0B;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7B
{
    unsigned char nHeader;
    unsigned char nSlot;
    unsigned short nSkill;
    int nItemGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7E
{
    unsigned char nHeader;
    unsigned int unk0x01;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv82
{
    unsigned char nHeader;
    int dwOwnerGUID;
    char szOwnerName[16];
    int dwPortalGUID0;
    int dwPortalGUID1;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    int dwPlayerGUID;
    int dwCorpseGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv89
{
    unsigned char nHeader;
    unsigned char nEvent;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2PacketInteractStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char unk0x06;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2PacketSrv2AStrc
{
    unsigned char nHeader;
    unsigned char nTransactionType;
    unsigned char nResult;
    unsigned int unk0x03;
    int nUnitGUID;
    int nGold;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv65Strc
{
    unsigned char nHeader;
    unsigned int dwUnitId;
    unsigned short nKillCount;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv74
{
    unsigned char nHeader;
    unsigned char bAssign;
    int nPlayerGUID;
    int nCorpseGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8BStrc
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char bParty;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8F
{
    unsigned char nHeader;
    unsigned int unk0x01[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv98
{
    unsigned char nHeader;
    unsigned int unk0x01;
    unsigned short unk0x05;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv9B
{
    unsigned char nHeader;
    unsigned short unk0x01;
    int unk0x03;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv97
{
    unsigned char nHeader;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA4
{
    unsigned char nHeader;
    short unk0x01;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA7
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA9
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv59
{
    unsigned char nHeader;
    unsigned int dwGUID;
    unsigned char nClass;
    char szName[16];
    short nPosX;
    short nPosY;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv19
{
    unsigned char nHeader;
    unsigned char nGold;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};
#pragma pack(pop)

void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0053DA90

unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00623D60

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0

int __fastcall sub_0053EA50_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags); // 0x0053EA50

#pragma pack(push, 1)
struct D2GSPacketSrv16
{
    unsigned char nHeader;
    unsigned short nSize;
    unsigned char nCount;
    D2UnitUpdateEntry entries[1];
};
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

struct D2PacketTarget3FStrc;

static __declspec(noinline) int __stdcall sub_0053CC40_ShouldSendMinionLifeUpdate(D2UnitStrc*, D2UnitStrc*, int);

static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer); // 0x0053CC90

#pragma pack(push, 1)
struct D2PacketTarget3FStrc
{
    unsigned char nHeader;
    unsigned char nType;
    int nUnitGUID;
    unsigned short nValue;
};
#pragma pack(pop)

static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(D2ClientStrc* pClient, const void* pPacket, int nPacketSize); // 0x0053B280

static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nLifePercentage, int nLevelId);

static int SCMD_ShouldSendLifeUpdate(int nLifePercentage, D2LifeSyncStrc* pLifeSync);

void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId);

void __fastcall D2GAME_SendPacketSize05_6FC3C880(D2ClientStrc* pClient, unsigned char nHeader, int nValue);

struct D2SkillListStrc;

#pragma pack(push, 1)
struct D2SkillPacketEntryStrc
{
    unsigned short nSkill;
    unsigned char nLevel;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv94
{
    unsigned char nHeader;
    unsigned char nCount;
    int nGUID;
};
#pragma pack(pop)

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc*); // 0x006438F0

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc*); // 0x00643910

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*, const char*, int); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

void __fastcall FOG_FreePool(void*, void*, const char*, int, int); // 0x0040B480

extern "C" const char szSCmdCppFile_006D69E4[];                                                             // 0x006D69E4

#pragma pack(push, 1)
struct D2GSPacketSrv5B
{
    unsigned char nHeader;
    unsigned short nPacketLen;
    unsigned int nUnitGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nLevel;
    unsigned short nPartyId;
    unsigned short unk0x1C;
    unsigned short nPartyFlags;
    unsigned short nGuildFlags;
    char szGuildTag[0x100];
};
#pragma pack(pop)

#define offsetof(s, m) ((unsigned int)&(((s*)0)->m))

#define STAT_LEVEL 12

extern "C" unsigned short __fastcall sub_00539110(D2ClientStrc* pClient);                                 // 0x00539110

extern "C" void __fastcall sub_00539130(D2ClientStrc* pClient, unsigned int* pOut);                       // 0x00539130

extern "C" void __fastcall sub_00539150(D2ClientStrc* pClient, char* pDst);                               // 0x00539150

void __fastcall sub_00574F80(D2ClientStrc* pClient, D2UnitStrc* pPlayer);               // 0x00574F80

#pragma pack(push, 1)
union D2GSPacketSrv7F90
{
    D2GSPacketSrv7F packet7F;
    D2GSPacketSrv90 packet90;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char pBitstream[244];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct Packet40
{
    unsigned char header;
    int guid;
    int x;
    int y;
};
#pragma pack(pop)

enum { HEADER = 0x40 };

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define MONMODE_DEATH 0

#define MONMODE_NEUTRAL 1

#define MONMODE_SKILL1 8

#define MONMODE_SKILL2 9

#define MONMODE_DEAD 12

#define MONTYPEFLAG_CHAMPION 4

#define MONTYPEFLAG_UNIQUE 8

#define MONTYPEFLAG_MINION 16

#define MONTYPEFLAG_GHOSTLY 64

#define UNITFLAG_ISMERC 0x200

#define ITEMSTATCOSTFLAGINDEX_SEND_OTHER 0

struct D2GSPacketSrv4D;

struct D2GSPacketSrv8C;

struct D2GSPacketSrv8D;

struct D2GSPacketSrvAC;

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

#pragma pack(push, 1)
struct D2GSPacketSrv4D
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    int unk0x06;
    unsigned char unk0x0A;
    unsigned short unk0x0B;
    unsigned short unk0x0D;
    unsigned short unk0x0F;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    int dwPlayerGUID1;
    int dwPlayerGUID2;
    unsigned short nFlags;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8D
{
    unsigned char nHeader;
    int dwPlayerGUID;
    unsigned short nPartyGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvAC
{
    unsigned char nHeader;
    int dwUnitGUID;
    unsigned short nUnitIndex;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char nLifePct;
    unsigned char nPacketLength;
    unsigned char bitstream[0xF4];
};
#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __fastcall sub_00573AE0_HasComponents(D2UnitStrc* pUnit); // 0x00573AE0

int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20

unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120

unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0

int __fastcall sub_005A0380_HasMonsterFlag(D2UnitStrc* pUnit); // 0x005A0380

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0

int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90

#pragma pack(push, 1)
struct D2GSPacketSrv4C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short wSkill;
    unsigned char nSkillLevel;
    unsigned char nTargetType;
    int dwTargetGUID;
    unsigned short unk0x0E;
};
#pragma pack(pop)

void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9);

void __fastcall D2GAME_PACKETS_SendPacket0xA3_6FC3D730(D2ClientStrc* pClient, unsigned char a2, unsigned short a3, unsigned short a4, int a5, int a6, int a7, int a8, int a9, int a10);

void __fastcall D2GAME_PACKETS_SendPacket0xAB_6FC3D7B0(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife);

void __fastcall D2GAME_PACKETS_SendPacket0xA5_6FC3D7F0(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4);

void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity);

void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket);

void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket);

void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket);

void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID);

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo);

void __fastcall D2GAME_PACKETS_SendPacket0x7A_6FC3E100(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass);

void __fastcall D2GAME_PACKETS_SendPacket0x81_6FC3E160(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName);

#pragma pack(push, 1)
struct D2GSPacketSrv83
{
    unsigned char nHeader;
    char szName[4];
    unsigned short f_5;
    unsigned short wSize;
    unsigned short f_9;
    unsigned char pData[0x190];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv84
{
    unsigned char nHeader;
    unsigned char nArg;
    unsigned char pData[0x190];
};
#pragma pack(pop)

extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);

#pragma intrinsic(strcpy)

#define ITEMACTION_DROPTOGROUND 2

#define ITEMACTION_ONGROUND 3

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

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet01, sizeof(packet01));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId)
{
    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = dwUnitType;
    tPacket.nUnitGUID = dwUnitId;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B400
void __fastcall D2GAME_SendPacketSize05_6FC3C880(D2ClientStrc* pClient, unsigned char nHeader, int nValue)
{
    D2PacketSize05Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet0C, sizeof(packet0C));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet0D, sizeof(packet0D));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
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
    packet68.unk0x14 = PATH_GetMaxDistance(pPath);
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet68, sizeof(packet68));
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
    packet67.unk0x0F = PATH_GetMaxDistance(pPath);
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet67, sizeof(packet67));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet68, sizeof(packet68));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet67, sizeof(packet67));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet6A, sizeof(packet6A));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet69, sizeof(packet69));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet6C, sizeof(packet6C));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet6B, sizeof(packet6B));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet6D, sizeof(packet6D));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet15, sizeof(packet15));
}

// 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv07 packet07;

    packet07.nHeader = 0x07;
    packet07.nX = nTileX;
    packet07.nY = nTileY;
    packet07.nLevelId = nAreaId;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet07, sizeof(packet07));
}

// 0x0053BC90
void __fastcall D2GAME_PACKETS_SendPacket0x08_6FC3D160(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv08 packet08;
    packet08.nHeader = 8;
    packet08.nX = nTileX;
    packet08.nY = nTileY;
    packet08.nLevelId = nAreaId;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet08, sizeof(packet08));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet09, sizeof(packet09));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet51, sizeof(packet51));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
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
            D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1A, sizeof(packet1A));
        }
        else
        {
            D2GSPacketSrv1B packet1B;
            packet1B.nHeader = 0x1B;
            packet1B.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1B, sizeof(packet1B));
        }
    }
    else
    {
        D2GSPacketSrv1C packet1C;
        packet1C.nHeader = 0x1C;
        packet1C.nExperience = nExperience;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1C, sizeof(packet1C));
    }
}

// 0x0053BE40
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short wStat, unsigned int nValue)
{
    D2_ASSERT(wStat < 0xFF, 971);

    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = (unsigned char)wStat;
        packet1D.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1D, sizeof(packet1D));
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = (unsigned char)wStat;
        packet1E.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1E, sizeof(packet1E));
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = (unsigned char)wStat;
        packet1F.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1F, sizeof(packet1F));
    }
}

// 0x0053BEE0
void __fastcall D2GAME_PACKETS_SendPacket0x9E_9F_A0_6FC3D520(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short wStat, unsigned int nValue)
{
    D2_ASSERT(wStat < 0xFF, 1013);

    const int bFitsWord = nValue < 0xFFFF;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv9E packet9E;
        packet9E.nHeader = 0x9E;
        packet9E.nStat = (unsigned char)wStat;
        packet9E.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9E.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet9E, sizeof(packet9E));
    }
    else if (bFitsWord)
    {
        D2GSPacketSrv9F packet9F;
        packet9F.nHeader = 0x9F;
        packet9F.nStat = (unsigned char)wStat;
        packet9F.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9F.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet9F, sizeof(packet9F));
    }
    else
    {
        D2GSPacketSrvA0 packetA0;
        packetA0.nHeader = 0xA0;
        packetA0.nStat = (unsigned char)wStat;
        packetA0.dwGUID = SCMD_GetUnitGUID(pUnit);
        packetA0.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetA0, sizeof(packetA0));
    }
}

// 0x0053BFD0
void __fastcall sub_0053BFD0(D2ClientStrc* client,D2UnitStrc* unit,unsigned short stat,unsigned int base,unsigned int full) {
 if(stat>=0xFF) {sub_00408A60(text_006CC837,sub_00408090(),1069);sub_00681E09(-1);}
 full-=base;
 const int fitsWord=full<0xFFFF;
 if(full<0xFF) {
  PacketA1 packet;packet.header=0xA1;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket_6FC3C710(client, &packet, sizeof(packet));
 } else if(fitsWord) {
  PacketA2 packet;packet.header=0xA2;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket_6FC3C710(client, &packet, sizeof(packet));
 } else {
  PacketA0 packet;packet.header=0xA0;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=base;
  D2GAME_PACKETS_SendPacket_6FC3C710(client, &packet, sizeof(packet));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetA3, sizeof(packetA3));
}

// 0x0053C150
void __fastcall D2GAME_PACKETS_SendPacket0xAB_6FC3D7B0(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife)
{
    D2GSPacketSrvAB packetAB = {};

    packetAB.nHeader = 0xAB;
    packetAB.nUnitType = nUnitType;
    packetAB.dwUnitGUID = dwUnitId;
    packetAB.nLife = nUnitLife;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetAB, sizeof(packetAB));
}

// 0x0053C190
void __fastcall D2GAME_PACKETS_SendPacket0xA5_6FC3D7F0(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4)
{
    D2GSPacketSrvA5 packetA5 = {};

    packetA5.nHeader = 0xA5;
    packetA5.unk0x01 = a2;
    packetA5.unk0x02 = a3;
    packetA5.unk0x06 = a4;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetA5, sizeof(packetA5));
}

// 0x0053C1D0
void __fastcall sub_6FC3D830(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short wStat, int nValue)
{
    D2_ASSERT(wStat < 0xFF, 0x4B8);
    D2GSPacketSrv20Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.dwUnitGUID = nUnitGUID;
    tPacket.nStat = wStat;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, packet, BITMANIP_GetSize(&bitBuffer));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, packet, BITMANIP_GetSize(&bitBuffer));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, packet, BITMANIP_GetSize(&bitBuffer));
}

// build: context sub_GetUnitType
static __forceinline int sub_GetUnitType(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    return nUnitType;
}

// 0x0053C4A0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove)
{
    if (!pUnit)
    {
        return;
    }

    if (!pClient && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (!pOwner)
        {
            return;
        }

        pClient = UnitGetClient(pOwner, ".\\GAME\\SCmd.cpp", 1298);
    }

    if (pClient)
    {
        D2GSPacketSrv21 packet21;
        packet21.nHeader = 0x21;
        packet21.nUnitType = sub_GetUnitType(pUnit);
        packet21.bRemove = bRemove;
        packet21.nUnitGUID = pUnit->dwUnitId;
        packet21.nSkillId = nSkillId;
        packet21.nSkillLevel = nSkillLevel;
        packet21.nBonusSkillLevel = (unsigned char)SKILLS_GetBonusSkillLevelFromSkillId(pUnit, nSkillId);
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet21, sizeof(packet21));
    }
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet22, sizeof(packet22));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053C5D0
void __fastcall sub_0053C5D0(D2ClientStrc* pClient, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 0x55A);
    D2SkillListStrc* hSkillInfo = hUnit->pSkills;
    D2_ASSERT(hSkillInfo, 0x55D);
    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(hSkillInfo);
    int nCount = 0;
    while (pSkill)
    {
        pSkill = SKILLS_GetNextSkill(pSkill);
        ++nCount;
    }
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    int nSize = 6 + 3 * nCount;
    D2GSPacketSrv94* pPacket = (D2GSPacketSrv94*)sub_0040B430(pGame->pMemoryPool, nSize, ".\\GAME\\SCmd.cpp", 0x568, 0);
    D2SkillPacketEntryStrc* pEntry = (D2SkillPacketEntryStrc*)(pPacket + 1);
    pPacket->nHeader = 0x94;
    D2_ASSERT(nCount < 256, 0x56E);
    pPacket->nCount = nCount;
    pPacket->nGUID = !hUnit ? -1 : hUnit->dwUnitId;
    for (pSkill = SKILLS_GetFirstSkillFromSkillList(hSkillInfo); pSkill;)
    {
        pEntry->nLevel = SKILLS_GetSkillLevel(hUnit, pSkill, 0);
        pEntry->nSkill = SKILLS_GetSkillIdFromSkill(pSkill, ".\\GAME\\SCmd.cpp", 0x576);
        pSkill = SKILLS_GetNextSkill(pSkill);
        ++pEntry;
    }
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, nSize);
    FOG_FreePool(pGame->pMemoryPool, pPacket, ".\\GAME\\SCmd.cpp", 0x57E, 0);
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053C730
extern "C" void __stdcall sub_0053C730(unsigned arg0,unsigned arg1,unsigned arg2) {}

// 0x0053C740
void __stdcall sub_0053C740(int nUnused1)
{
}

// 0x0053C750
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket)
{
    int nMessageLength = 0;
    if (strlen(pPacket->szMessage) >= 256)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x5BA);
        exit(-1);
    }
    if (pPacket->szMessage[255])
        pPacket->szMessage[255] = 0;
    D2GSPacketSrv26 packet;
    packet.nHeader = pPacket->nHeader;
    packet.nMessageType = pPacket->nMessageType;
    packet.nLang = pPacket->nLang;
    packet.nUnitType = pPacket->nUnitType;
    packet.dwUnitGUID = pPacket->dwUnitGUID;
    packet.nMessageColor = pPacket->nMessageColor;
    packet.nNameColor = pPacket->nNameColor;
    char* pText = packet.szName + SStrCopy(packet.szName, pPacket->szName, 16) + 1;
    nMessageLength = SStrCopy(pText, pPacket->szMessage, 256);
    nMessageLength += pText - (char*)&packet + 1;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, nMessageLength);
}

// 0x0053C850
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket)
{
    D2_ASSERT(strlen(pPacket->szText) < 16, 1498);

    D2GSPacketSrv5A packet5A = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet5A, sizeof(packet5A));
}

// 0x0053C8D0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket)
{
    D2GSPacketSrv27 packet27 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet27, sizeof(packet27));
}

// 0x0053C900
void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket)
{
    D2GSPacketSrv53 packet53 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet53, sizeof(packet53));
}

// 0x0053C930
void __fastcall sub_0053C930_SendPacketSize03(D2ClientStrc* pClient, const void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, 3);
}

// 0x0053C940
void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc* pClient1, D2UnitStrc* pPlayer, D2ClientStrc* pClient2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2GSPacketSrv5B packet5B;
    memset(&packet5B, 0, sizeof(packet5B));

    packet5B.nHeader = 0x5B;
    packet5B.nUnitGUID = SCMD_GetUnitGUID(pPlayer);
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    packet5B.nClass = nClass;
    packet5B.nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    packet5B.nPartyId = SUNIT_GetPartyId(pPlayer);
    packet5B.unk0x1C = 0;
    packet5B.nPartyFlags = 0;
    packet5B.nGuildFlags = sub_00539110(pClient2);

    SStrCopy(packet5B.szName, pPlayerData->szName, 0x7FFFFFFF);

    sub_00539130(pClient2, (unsigned int*)packet5B.szGuildTag);

    const int nLength = strlen(packet5B.szGuildTag) + 1;

    char* szString = &packet5B.szGuildTag[nLength];
    sub_00539150(pClient2, szString);

    const int nPacketLen = strlen(szString) + 1 + (szString - packet5B.szGuildTag) + offsetof(D2GSPacketSrv5B, szGuildTag);
    packet5B.nPacketLen = nPacketLen;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient1, &packet5B, nPacketLen);

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        sub_00574F80(pClient1, pPlayer);
    }
}

// 0x0053CA90
void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID)
{
    D2GSPacketSrv5C packet5C;
    packet5C.nHeader = 0x5C;
    packet5C.dwPlayerGUID = nUnitGUID;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet5C, sizeof(packet5C));
}

// 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo)
{
    D2GSPacketSrv77 packet77;
    packet77.nHeader = 0x77;
    packet77.nAction = nUiNo;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet77, sizeof(packet77));
}

// 0x0053CAD0
void __fastcall sub_0053CAD0_SendPacket0x78(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket)
{
    D2GSPacketSrv78 packet78 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet78, sizeof(packet78));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet7A, sizeof(packet7A));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet81, sizeof(packet81));
}

// 0x0053CBE0
void __fastcall D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(D2ClientStrc* pClient, int nGold, char bOwnGold)
{
    D2GSPacketSrv79 packet79;
    packet79.nHeader = 0x79;
    packet79.bOwnGold = bOwnGold;
    packet79.dwGold = nGold;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet79, sizeof(packet79));
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

// 0x0053CC40
static int __stdcall sub_0053CC40_ShouldSendMinionLifeUpdate(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nLifePercentage)
{
    if (AIGENERAL_GetMinionOwner(pUnit) != pPlayer)
    {
        return 0;
    }
    const int bTest = !pUnit || pUnit->dwUnitType != UNIT_MONSTER;
    if (!bTest)
    {
        pUnit = (D2UnitStrc*)pUnit->pMonsterData;
    }
    if (bTest)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = pUnit ? (D2LifeSyncStrc*)((D2MonsterDataStrc*)pUnit)->abLifeSync : 0;
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

// 0x0053CC90
static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    if (!pGame)
    {
        return 0;
    }
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pPlayer);
    if (nPartyId == 0xFFFF || nPartyId != PARTY_GetPartyIdForUnitOwner(pGame, pUnit))
    {
        return 0;
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = pPlayerData->pPartyLifeList;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    int bFound = 0;
    while (!bFound)
    {
        if (!pLifeSync)
        {
            pLifeSync = (D2LifeSyncStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2LifeSyncStrc), ".\\GAME\\SCmd.cpp", 0x6FA, 0);
            if (!pLifeSync)
            {
                return 0;
            }
            *pLifeSync = D2LifeSyncStrc();
            pLifeSync->pNext = pPlayerData->pPartyLifeList;
            pPlayerData->pPartyLifeList = pLifeSync;
            pLifeSync->nUnitGUID = nUnitGUID;
            bFound = 1;
        }
        else if (nUnitGUID == pLifeSync->nUnitGUID)
        {
            bFound = 1;
        }
        else
        {
            pLifeSync = pLifeSync->pNext;
        }
    }

    if (pLifeSync->nLevelId != nLevelId)
    {
        pLifeSync->nLifePercentage = nLifePercentage;
        pLifeSync->nLevelId = nLevelId;
        return 1;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

// 0x0053CD80
static int __stdcall sub_0053CD80_ShouldSendLifeUpdate(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nLifePercentage, int nLevelId)
{
    D2_ASSERT(pPlayer, 0x712);
    D2_ASSERT(pUnit, 0x713);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SCMD_ShouldSendPartyLifeUpdate(pUnit, nLifePercentage, nLevelId, pPlayer);

    case UNIT_MONSTER:
        return sub_0053CC40_ShouldSendMinionLifeUpdate(pUnit, pPlayer, nLifePercentage);

    default:
        return 0;
    }
}

// 0x0053CDF0
void __fastcall SCMD_SendUnitLifeAndPositionUpdate(D2ClientStrc* pClient, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 0x72A);

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(hUnit);
    D2GSPacketSrv7F90 tPacket;
    const D2GSPacketSrv7F tZero7F = {};
    tPacket.packet7F = tZero7F;
    tPacket.packet7F.nHeader = 0x7F;

    if (hUnit->dwUnitType == UNIT_PLAYER)
    {
        tPacket.packet7F.bIsPlayer = 1;
    }

    tPacket.packet7F.nUnitGUID = hUnit->dwUnitId;
    tPacket.packet7F.nLifePercentage = nLifePercentage;
    if (nLifePercentage >= 0xFFFF)
    {
        tPacket.packet7F.nLifePercentage = 0xFFFF;
    }

    tPacket.packet7F.nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(hUnit));

    if (sub_0053CD80_ShouldSendLifeUpdate(CLIENTS_GetPlayerFromClient(pClient, 0), hUnit, nLifePercentage, tPacket.packet7F.nLevelId))
    {
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket.packet7F, sizeof(tPacket.packet7F));
    }

    if (tPacket.packet7F.bIsPlayer)
    {
        D2UnitStrc* pClientPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (sub_006416D0_UnitEdgeDistance(pClientPlayer, hUnit) > 50)
        {
            const D2GSPacketSrv90 tZero90 = {};
            tPacket.packet90 = tZero90;
            tPacket.packet90.nHeader = 0x90;
            tPacket.packet90.dwGUID = hUnit->dwUnitId;
            tPacket.packet90.dwPosX = CLIENTS_GetUnitX(hUnit);
            tPacket.packet90.dwPosY = CLIENTS_GetUnitY(hUnit);
            D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket.packet90, sizeof(tPacket.packet90));

        }
    }
}

// 0x0053CEF0
void __fastcall D2GAME_SendPacket0x9D_6FC3E6F0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2GSPacketSrv9D packet;
    packet.nHeader = 0x9D;
    packet.nAction = nAction;
    packet.nComponent = UNITS_GetItemComponentId(pUnit, pItem);
    packet.nItemId = SCMD_GetUnitGUID(pItem);
    int nUnitType = 6;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    packet.nUnitType = nUnitType;
    packet.nUnitId = SCMD_GetUnitGUID(pUnit);
    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);
    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet.pBitstream, sizeof(packet.pBitstream), 0, 0, bGamble) + 13;
    D2_ASSERT(nLength <= 0xFC, 0x7B4);
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);
    packet.nPacketSize = nLength;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, packet.nPacketSize);
    sub_0053EA50_SendSocketedItems(pClient, pItem, dwFlag);
}

// 0x0053D010
void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, unsigned int dwCmdFlag)
{
    D2_ASSERT(UnitGetClient(hUnit, ".\\GAME\\SCmd.cpp", 2050) == hClient, 2050);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
    D2GAME_SendPacket0x9D_6FC3E6F0(hClient, hUnit, pItem, ITEMACTION_REMOVEFROMCONTAINER, dwCmdFlag, 0);
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

static D2LifeSyncStrc* GetMonsterLifeSync(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return (D2LifeSyncStrc*)pUnit->pMonsterData->abLifeSync;
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
    if (sub_0053CD80_ShouldSendLifeUpdate(CLIENTS_GetPlayerFromClient(pClient, 0), pUnit, nLifePercentage, tPacket7F.nLevelId))
    {
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket7F, sizeof(tPacket7F));
    }
    if (tPacket7F.bIsPlayer && sub_006416D0_UnitEdgeDistance(CLIENTS_GetPlayerFromClient(pClient, 0), pUnit) > 50)
    {
        D2GSPacketSrv90 tPacket90 = {};
        tPacket90.nHeader = 0x90;
        tPacket90.dwGUID = pUnit->dwUnitId;
        tPacket90.dwPosX = CLIENTS_GetUnitX(pUnit);
        tPacket90.dwPosY = CLIENTS_GetUnitY(pUnit);
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket90, sizeof(tPacket90));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D220
void __fastcall sub_0053D220_SendTargetPacket(D2ClientStrc* pClient, D2UnitStrc* pUnit,
    unsigned char nType, int bClear, int nUnused, unsigned short nValue)
{
    D2PacketTarget3FStrc packet = {};
    packet.nHeader = 0x3F;
    if (bClear)
    {
        if (!pUnit)
        {
            packet.nType = 0xFF;
            packet.nUnitGUID = 0;
            goto send;
        }
        packet.nType = 0xFF;
    }
    else
    {
        packet.nType = nType;
        if (!pUnit)
            goto send;
    }
    packet.nUnitGUID = pUnit->dwUnitId;
send:
    packet.nValue = nValue;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, sizeof(packet));
}

// 0x0053D270
void __fastcall sub_0053D270(D2ClientStrc* client,D2UnitStrc* unit,int x,int y)
{
    Packet40 packet = {};
    packet.header = HEADER;
    packet.guid = SCMD_GetUnitGUID(unit);
    packet.x = x;
    packet.y = y;
    D2GAME_PACKETS_SendPacket_6FC3C710(client, &packet, sizeof(packet));
}

// 0x0053D2C0
void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_AUTOUNEQUIP, dwFlags, 0);
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet42, sizeof(packet42));
}

// 0x0053D330
void __fastcall sub_0053D330_SendItemAction13(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, 0x13, dwFlag, 0);
}

// 0x0053D350
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x14, dwFlags, 0);
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet47, sizeof(packet47));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet48, sizeof(packet48));
}

// 0x0053D420
void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UPDATESTATS, dwFlags, 0);
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet7D, sizeof(packet7D));
}

// 0x0053D4B0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D_6FC3E6F0(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x16, dwFlags, 0);
}

// 0x0053D4D0
void __fastcall sub_6FC3F060(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9)
{
    D2GSPacketSrv4D packet;

    packet.nHeader = a9 != 0 ? 0x9Au : 0x4Du;
    packet.unk0x01 = a2;
    packet.unk0x02 = a3;
    packet.unk0x0B = a4;
    packet.unk0x0D = a5;
    packet.unk0x06 = a6;
    packet.unk0x0A = a8;
    packet.unk0x0F = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, sizeof(packet));
}

// 0x0053D530
void __fastcall sub_0053D530(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned char nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9)
{
    D2UnitStrc* pUnit = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID);
    if (!pUnit)
    {
        D2GSPacketSrv4C packet4C;

        packet4C.nHeader = a9 != 0 ? 0x99u : 0x4Cu;
        packet4C.nUnitType = a2;
        packet4C.dwUnitGUID = a3;
        packet4C.nTargetType = nUnitType;
        packet4C.dwTargetGUID = nUnitGUID;
        packet4C.wSkill = a6;
        packet4C.nSkillLevel = a8;
        packet4C.unk0x0E = a7;

        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet4C, sizeof(packet4C));
        return;
    }

    D2ActiveRoomStrc* pClientRoom = UNITS_GetRoom(CLIENTS_GetPlayerFromClient(pClient, 0));
    if (pClientRoom)
    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        for (int i = 0; i < nNumRooms; ++i)
        {
            if (pRoom == ppRoomList[i])
            {
                D2GSPacketSrv4C packet4C;

                packet4C.nHeader = a9 != 0 ? 0x99u : 0x4Cu;
                packet4C.nUnitType = a2;
                packet4C.dwUnitGUID = a3;
                packet4C.nTargetType = nUnitType;
                packet4C.dwTargetGUID = nUnitGUID;
                packet4C.wSkill = a6;
                packet4C.nSkillLevel = a8;
                packet4C.unk0x0E = a7;

                D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet4C, sizeof(packet4C));
                return;
            }
        }
    }

    sub_6FC3F060(pClient, a2, a3, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), a6, a7, a8, a9);
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet28, sizeof(packet28));
}

// 0x0053D6D0
void __fastcall sub_6FC3F340(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5)
{
    D2PacketInteractStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitId;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D700
void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053D710
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket)
{
    D2GSPacketSrv5D packet5D = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet5D, sizeof(packet5D));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D780
void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket)
{
    D2GSPacketSrv2C packet2C = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet2C, sizeof(packet2C));
}

// 0x0053D7B0
void __fastcall D2GAME_SendPacket0x4E_6FC3F410(D2ClientStrc* pClient, D2GSPacketSrv4E* pPacket)
{
    D2GSPacketSrv4E packet4E = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet4E, sizeof(packet4E));
}

// 0x0053D7E0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket)
{
    D2GSPacketSrv50 packet50 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet50, sizeof(packet50));
}

// 0x0053D830
void __fastcall sub_0053D830_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053D840
void __fastcall sub_0053D840(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053D850
void __fastcall D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay)
{
    D2GSPacketSrv11 packet11;

    packet11.nHeader = 0x11;
    packet11.nUnitType = nUnitType;
    packet11.dwUnitGUID = nUnitGUID;
    packet11.unk0x06 = nOverlay;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet11, sizeof(packet11));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet57, sizeof(packet57));
}

// 0x0053D8D0
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket)
{
    D2GSPacketSrv58 packet58 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet58, sizeof(packet58));
}

// 0x0053D900
void __fastcall sub_6FC3F550(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv60 packet60;

    packet60.nHeader = 0x60;
    packet60.nFlags = UNITS_GetObjectPortalFlags(pUnit);
    packet60.nLevel = pUnit->pObjectData->InteractType;
    packet60.dwUnitGUID = pUnit->dwUnitId;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet60, sizeof(packet60));
}

// 0x0053D940
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue)
{
    D2GSPacketSrv61 packet61;

    packet61.nHeader = 0x61;
    packet61.unk0x01 = nValue;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet61, sizeof(packet61));
}

// 0x0053D960
void __fastcall sub_0053D960_SendPacket0x78(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket)
{
    D2GSPacketSrv78 packet78 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet78, sizeof(packet78));
}

// 0x0053D9C0
void __fastcall D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(D2ClientStrc* pClient, unsigned int dwPlayerId, unsigned short nCount)
{
    D2GSPacketSrv65Strc tPacket;
    tPacket.nHeader = 0x65;
    tPacket.dwUnitId = dwPlayerId;
    tPacket.nKillCount = nCount;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D9F0
void __cdecl sub_0053D9F0_AssertFalse()
{
    D2_ASSERT(0, 0xAB4);
}

// 0x0053DA10
void __fastcall sub_6FC3F610(D2ClientStrc* pClient, D2GSPacketSrv73* pPacket)
{
    D2GSPacketSrv73 packet73 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet73, sizeof(packet73));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet74, sizeof(packet74));
}

// 0x0053DA90
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    D2ClientStrc* pClient = UnitGetClient(pLocalPlayer, ".\\GAME\\SCmd.cpp", 0xAFA);

    D2GSPacketSrv75 packet75 = {};

    packet75.nHeader = 0x75u;
    const int nUnitGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;
    packet75.nUnitGUID = nUnitGUID;
    packet75.nLevel = STATLIST_UnitGetStatValue(pOtherPlayer, 0xC, 0);
    packet75.nPartyId = SUNIT_GetPartyId(pOtherPlayer);
    packet75.nFlags = PLAYERLIST_GetFlags(pLocalPlayer, pOtherPlayer);
    packet75.unk0x0B = sub_6FCBA9D0(pLocalPlayer, pOtherPlayer);

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet75, sizeof(packet75));
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

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet7B, sizeof(packet7B));
}

// 0x0053DB70
void __fastcall D2GAME_PACKETS_SendPacket0x7E_6FC3F770(D2ClientStrc* pClient)
{
    D2GSPacketSrv7E packet7E;

    packet7E.nHeader = 0x7E;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet7E, sizeof(packet7E));
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

            D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet82, sizeof(packet82));
        }
    }
}

// 0x0053DC20
void __fastcall sub_0053DC20_SendPacket0x83(D2ClientStrc* pClient, const char* szName, unsigned short wSize, unsigned short wArg1, unsigned short wArg2, const void* pData)
{
    D2GSPacketSrv83 packet;
    packet.nHeader = 0x83;
    strcpy(packet.szName, szName);
    packet.f_5 = wArg1;
    packet.wSize = wSize;
    packet.f_9 = wArg2;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, wSize + 0x0B);
}

// 0x0053DCC0
void __fastcall sub_0053DCC0_SendPacket0x84(D2ClientStrc* pClient, unsigned char nArg, unsigned short wSize, const void* pData)
{
    D2GSPacketSrv84 packet;
    packet.nHeader = 0x84;
    packet.nArg = nArg;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, wSize + 2);
}

// 0x0053DD20
void __fastcall sub_0053DD20_SendPacket0x88(D2ClientStrc* pClient, const char* szName, unsigned short wSize, unsigned short wArg1, unsigned short wArg2, const void* pData)
{
    D2GSPacketSrv83 packet;
    packet.nHeader = 0x88;
    strcpy(packet.szName, szName);
    packet.f_5 = wArg1;
    packet.wSize = wSize;
    packet.f_9 = wArg2;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, wSize + 0x0B);
}

// 0x0053DDC0
void __fastcall D2GAME_PACKETS_SendPacket0x8B_6FC3F810(D2ClientStrc* pClient, int nUnitGUID, unsigned char nPartyState)
{
    D2GSPacketSrv8BStrc tPacket;
    tPacket.nHeader = 0x8B;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.bParty = nPartyState;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053DDF0
void __fastcall sub_0053DDF0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBAE), pPacket, sizeof(D2GSPacketSrv8C));
}

// 0x0053DE50
void __fastcall D2GAME_PACKETS_SendPacket0x8C_6FC3F8B0(D2UnitStrc* pUnit, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState)
{
    D2GSPacketSrv8C packet8C;

    packet8C.nHeader = 0x8C;
    packet8C.dwPlayerGUID1 = dwPlayerId1;
    packet8C.dwPlayerGUID2 = dwPlayerId2;
    packet8C.nFlags = wRelationState;

    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pUnit, ".\\GAME\\SCmd.cpp", 0xBD0), &packet8C, sizeof(packet8C));
}

// 0x0053DE90
void __fastcall sub_6FC3F930(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBD8), pPacket, sizeof(D2GSPacketSrv8D));
}

// 0x0053DEC0
void __fastcall sub_6FC3F8F0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    SUNIT_IterateLivingPlayers(pGame, sub_6FC3F930, &packet8D);
}

// 0x0053DF00
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pUnit, ".\\GAME\\SCmd.cpp", 0xBF6), &packet8D, sizeof(packet8D));
}

// 0x0053DF50
void __fastcall sub_0053DF50(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBFF), pPacket, 0xA);
}

// 0x0053DFB0
void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc* pClient, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;

    packet8E.nHeader = 0x8E;
    packet8E.dwPlayerGUID = nUnitId;
    packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet8E, sizeof(packet8E));
}

// 0x0053DFE0
void __fastcall sub_0053DFE0_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053DFF0
void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket)
{
    D2GSPacketSrv8A packet8A = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet8A, sizeof(packet8A));
}

// 0x0053E020
void __fastcall D2GAME_PACKETS_SendPacket0x8F_6FC3FA90(D2ClientStrc* pClient)
{
    D2GSPacketSrv8F packet8F = { 0x8F };
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet8F, sizeof(packet8F));
}

// 0x0053E060
void __fastcall sub_0053E060_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket)
{
    D2GSPacketSrv91 packet91 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet91, sizeof(packet91));
}

// 0x0053E0A0
void __fastcall sub_6FC3FAF0(D2ClientStrc* pClient, unsigned int a2, unsigned short a3)
{
    D2GSPacketSrv98 packet98 = {};

    packet98.nHeader = 0x98;
    packet98.unk0x01 = a2;
    packet98.unk0x05 = a3;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet98, sizeof(packet98));
}

// 0x0053E0E0
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3)
{
    D2GSPacketSrv9B packet9B;

    packet9B.nHeader = 0x9B;
    packet9B.unk0x01 = nUnitGUID;
    packet9B.unk0x03 = a3;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet9B, sizeof(packet9B));
}

// 0x0053E110
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc* pClient)
{
    D2GSPacketSrv97 packet97 = {};

    packet97.nHeader = 0x97;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet97, sizeof(packet97));
}

// 0x0053E130
void __fastcall sub_0053E130_SendUnitUpdates(D2ClientStrc* pClient)
{
    int nCount = pClient->nUnitUpdateIndex;
    if (nCount)
    {
        D2PacketDataStrc* pData = CLIENTS_PacketDataList_GetHead(pClient);
        unsigned short nSize = (unsigned short)(sizeof(D2GSPacketSrv16) + sizeof(D2UnitUpdateEntry) * nCount);
        D2GSPacketSrv16* pPacket = (D2GSPacketSrv16*)(pData->packetData + pData->nPacketSize);
        pPacket->nHeader = 0x16;
        pPacket->nCount = (unsigned char)nCount;
        pPacket->nSize = nSize;
        D2UnitUpdateEntry* pOut = pPacket->entries;
        for (int i = 0; i < nCount; ++i)
        {
            *pOut++ = *(D2UnitUpdateEntry*)&pClient->unitUpdate[i];
        }
        pData->nPacketSize += nSize;
    }
}

// 0x0053E1A0
void __fastcall D2GAME_PACKETS_SendPacket0xA4_6FC3FC00(D2ClientStrc* pClient, short a2)
{
    D2GSPacketSrvA4 packetA4;

    packetA4.nHeader = 0xA4;
    packetA4.unk0x01 = a2;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetA4, sizeof(packetA4));
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, nPacketSize);
}

// 0x0053E260
void __fastcall D2GAME_PACKETS_SendPacket0xA7_StateOn_6FC3FC20(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA7 packetA7;

    packetA7.nHeader = 0xA7;
    packetA7.nUnitType = nUnitType;
    packetA7.nUnitId = dwUnitId;
    packetA7.nState = nState;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetA7, sizeof(packetA7));
}

// 0x0053E290
void __fastcall D2GAME_PACKETS_SendPacket0xA9_StateOff_6FC3FC50(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA9 packetA9;

    packetA9.nHeader = 0xA9;
    packetA9.nUnitType = nUnitType;
    packetA9.nUnitId = dwUnitId;
    packetA9.nState = nState;

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetA9, sizeof(packetA9));
}

int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

// build: context Log2Ceil
static __forceinline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : sub_00409000_GetBitWidth(nValue - 1);
}

// build: context sub_0044BE50
static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// build: context sub_00623C60
static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// build: context sub_00451F50
static __forceinline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// build: context UNITS_IsMerc
static __forceinline int UNITS_IsMerc(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// build: context UNITS_HasStoredOwnerInfo
static __forceinline int UNITS_HasStoredOwnerInfo(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 10) & 1;
}

// build: context CLIENTS_GetUnitX
static __forceinline int CLIENTS_GetUnitXByType(D2UnitStrc* pUnit)
{
    switch (sub_0044BE50(pUnit))
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

// build: context CLIENTS_GetUnitY
static __forceinline int CLIENTS_GetUnitYByType(D2UnitStrc* pUnit)
{
    switch (sub_0044BE50(pUnit))
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: context MONSTER_GetComponents
static __forceinline unsigned char* MONSTER_GetComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

// build: context SKILLS_GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0053E2E0
void __fastcall sub_6FC3FC80(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return;
    }

    D2GSPacketSrvAC packetAC;
    packetAC.nHeader = 0xAC;
    packetAC.dwUnitGUID = pUnit->dwUnitId;
    packetAC.nUnitIndex = sub_00623C60(pUnit);
    packetAC.nPosX = CLIENTS_GetUnitXByType(pUnit);
    packetAC.nPosY = CLIENTS_GetUnitYByType(pUnit);
    packetAC.nLifePct = MONSTERMODE_GetHpPercent128(pUnit);

    D2BitBufferStrc bitBuffer;
    BITMANIP_Initialize(&bitBuffer, packetAC.bitstream, sizeof(packetAC.bitstream));

    if (pUnit->dwAnimMode == MONMODE_SKILL1)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else if (pUnit->dwAnimMode == MONMODE_SKILL2)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, MONMODE_NEUTRAL, 4);
    }

    if (sub_00573AE0_HasComponents(pUnit))
    {
        BITMANIP_Write(&bitBuffer, 1, 1);

        unsigned char* pComponents = MONSTER_GetComponents(pUnit);
        if (pComponents)
        {
            for (int i = 0; i < 16; ++i)
            {
                const unsigned char nComponent = pComponents[i];
                BITMANIP_Write(&bitBuffer, nComponent, Log2Ceil(D2COMMON_11068_GetCompInfo(pUnit, i)));
            }
        }
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }

    if (!sub_005A0380_HasMonsterFlag(pUnit) && !UNITS_IsMerc(pUnit))
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 1, 1);

        const int nChampion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_CHAMPION);
        BITMANIP_Write(&bitBuffer, nChampion != 0, 1);
        const int nUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE);
        BITMANIP_Write(&bitBuffer, nUnique != 0, 1);
        const int nSuperUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_SUPERUNIQUE);
        BITMANIP_Write(&bitBuffer, nSuperUnique != 0, 1);
        const int nMinion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_MINION);
        BITMANIP_Write(&bitBuffer, nMinion != 0, 1);
        const int nGhostly = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_GHOSTLY);
        BITMANIP_Write(&bitBuffer, nGhostly != 0, 1);

        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_SUPERUNIQUE))
        {
            BITMANIP_Write(&bitBuffer, MONSTERUNIQUE_GetBossHcIdx(pUnit), 16);
        }

        const unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
        if (pUMods)
        {
            for (int i = 0; i < 9 && pUMods[i]; ++i)
            {
                BITMANIP_Write(&bitBuffer, pUMods[i], 8);
            }
        }

        BITMANIP_Write(&bitBuffer, 0, 8);

        BITMANIP_Write(&bitBuffer, MONSTERUNIQUE_GetNameSeed(pUnit), 16);

        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && PLAYERPETS_GetPetTypeFromPetGUID(pOwner, packetAC.dwUnitGUID) == PETTYPE_HIREABLE)
        {
            BITMANIP_Write(&bitBuffer, 1, 1);
            BITMANIP_Write(&bitBuffer, sub_00451F50(pOwner), 32);
        }
        else
        {
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
    }

    if (UNITS_HasStoredOwnerInfo(pUnit) && pUnit->dwOwnerType == UNIT_PLAYER)
    {
        BITMANIP_Write(&bitBuffer, 1, 1);
        BITMANIP_Write(&bitBuffer, pUnit->dwOwnerGUID & 0x8FFFFFFF, 31);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }

    int bStatsSent = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40);
    if (pStatList)
    {
        D2StatStrc stats[16];
        const int nStatCount = STATLIST_GetBaseStatsData(pStatList, stats, 16);
        if (nStatCount > 0)
        {
            for (int i = 0; i < nStatCount; ++i)
            {
                const unsigned short nLayer = stats[i].nLayer;
                const int nStat = stats[i].nStat;
                const int nValue = stats[i].nValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(stats[i].nStat);
                if (pItemStatCostTxtRecord)
                {
                    if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SEND_OTHER >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SEND_OTHER & 7] && pItemStatCostTxtRecord->nSendBits > 0)
                    {
                        if (!bStatsSent)
                        {
                            bStatsSent = 1;
                            BITMANIP_Write(&bitBuffer, 1, 1);
                        }

                        BITMANIP_Write(&bitBuffer, nStat, 9);

                        if (pItemStatCostTxtRecord->nSendParamBits)
                        {
                            BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nSendParamBits);
                        }

                        BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nSendBits);
                    }
                }
            }

            if (bStatsSent)
            {
                BITMANIP_Write(&bitBuffer, 511, 9);
                goto Send;
            }
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
        else
        {
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
    }

    BITMANIP_Write(&bitBuffer, 0, 1);

Send:
    const int nPacketSize = BITMANIP_GetSize(&bitBuffer) + 13;
    packetAC.nPacketLength = nPacketSize;
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packetAC, nPacketSize);
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
        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet, nSize + 3);
        return 1;
    }
    D2_ASSERT(nSize <= 0x1FD, 0xE38);
}

// 0x0053E8D0
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, pPacket, nPacketSize);
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
    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet59, sizeof(packet59));

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

        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1D, sizeof(packet1D));
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = nPacketStatId;
        packet1E.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1E, sizeof(packet1E));
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = nPacketStatId;
        packet1F.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet1F, sizeof(packet1F));
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

        D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet19, sizeof(packet19));
    }
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

// 0x0053EAE0
void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2UnitStrc* hUnit = CLIENTS_GetPlayerFromClient(pClient, 0);

    D2_ASSERT(hUnit, 1915);

    D2GSPacketSrv9C packet9C;

    packet9C.nHeader = 0x9C;
    packet9C.nAction = nAction;
    packet9C.nItemId = SCMD_GetUnitGUID(pItem);
    packet9C.nComponent = UNITS_GetItemComponentId(hUnit, pItem);

    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);

    memset(packet9C.pBitstream, 0, sizeof(packet9C.pBitstream));

    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet9C.pBitstream, sizeof(packet9C.pBitstream), 0, 0, bGamble) + 8;

    D2_ASSERT(nLength <= 0xFC, 1932);

    packet9C.nPacketSize = nLength;
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);

    D2GAME_PACKETS_SendPacket_6FC3C710(pClient, &packet9C, packet9C.nPacketSize);

    sub_0053EA50_SendSocketedItems(pClient, pItem, dwFlag);
}

// 0x0053EC00
void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround_6FC3E850(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ADDTOGROUND, dwFlag, 0);
}

// 0x0053EC20
void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2002) == hClient, 2002);

    UNITS_SetXForStaticUnit(pItem, 0);
    UNITS_SetYForStaticUnit(pItem, 0);
    D2GAME_SendPacket0x9C_6FC3E570(hClient, pItem, ITEMACTION_GROUNDTOCURSOR, a4, 0);
}

// 0x0053EC90
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, int a4)
{
    D2_ASSERT(UnitGetClient(hUnit, ".\\GAME\\SCmd.cpp", 2013) == hClient, 2013);
    D2GAME_SendPacket0x9C_6FC3E570(hClient, pItem, ITEMACTION_DROPTOGROUND, a4, 0);
}

// 0x0053ECF0
void __fastcall D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(D2ClientStrc* pClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, int a4)
{
    D2_ASSERT(UnitGetClient(hUnit, ".\\GAME\\SCmd.cpp", 2022) == pClient, 2022);
    D2GAME_SendPacket0x9C_6FC3E570(pClient, pItem, ITEMACTION_ONGROUND, a4, 0);
}

// 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2031) == hClient, 2031);

    D2GAME_SendPacket0x9C_6FC3E570(hClient, pItem, ITEMACTION_PUTINCONTAINER, a4, 0);
}

// 0x0053EDB0
void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2121) == hClient, 2121);

    D2GAME_SendPacket0x9C_6FC3E570(hClient, pItem, ITEMACTION_ADDQUANTITY, a4, 0);
}

// 0x0053EE10
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2131) == hClient, 2131);

    D2GAME_SendPacket0x9C_6FC3E570(hClient, pItem, ITEMACTION_SWAPINCONTAINER, a4, 0);
}

// 0x0053EE70
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2140) == hClient, 2140);

    D2GAME_SendPacket0x9C_6FC3E570(hClient, pItem, ITEMACTION_PUTINBELT, a4, 0);
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

int __cdecl sub_005A0110()
{
    return 0;
}

// 0x005A6220
int __fastcall sub_005A6220(FieldStrc_005A6220* pObject)
{
    return pObject->unk0x10;
}
