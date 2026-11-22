#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2EventTimer.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2DataTbls.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2NpcRecordStrc;

struct D2ItemCacheStrc;

struct D2UnitProxyStrc;

struct M08EmitRecStrc;

struct D2NpcGambleStrc;

struct D2NpcVendorChainStrc;

struct D2NpcEventStrc;

struct D2NpcControlStrc;

struct D2NpcTradeStrc;

struct Pad40_00536B40;

struct Pad400_00536B40;

struct Obj00536B40;

struct D2ItemsTxt;

struct D2EventTimerSlabListStrc;

struct D2EventTimerQueueStrc;

struct D2QuestGUIDStrc;

struct D2RegurgitatorAiCallbackArgStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitProxyStrc gUnitProxyItemCache_00883D78[17]; // 0x00883D78

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct M08EmitRecStrc
{
    int nKind;
    char bFlagA;
    char bFlagB;
    char unk0x06[2];
    D2UnitProxyStrc tProxy;
};

struct D2NpcVendorChainStrc
{
    int dwGUID;
    int unk0x04;
    D2NpcVendorChainStrc* pNext;
};

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int field_4;
    int field_8;
    int field_C;
    D2NpcEventStrc* pNext;
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char bTrader;
    int unk0x04;
    unsigned int dwTick;
};

struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
    D2SeedStrc pSeed;
    int nNpcCount;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0

D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80

int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70

void __fastcall SUNITNPC_RemoveStoreItem(D2UnitStrc*,D2UnitStrc*,D2GameStrc*,int); // 0x005766D0

int __fastcall D2GAME_PlaceItem_6FC44410(const char*,int,D2GameStrc*,D2UnitStrc*,int,int,int,int,int,D2InventoryStrc*); // 0x00560200

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250

void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280

void __fastcall SUNITNPC_SetItemTradeFlags(D2UnitStrc*,D2UnitStrc*,D2GameStrc*,int,int); // 0x005762C0

int __fastcall sub_00579030(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00579030

void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480

struct Pad40_00536B40 {
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

struct Pad400_00536B40 {
    Pad40_00536B40 t000;
    Pad40_00536B40 t040;
    Pad40_00536B40 t080;
    Pad40_00536B40 t0C0;
    Pad40_00536B40 t100;
    Pad40_00536B40 t140;
    Pad40_00536B40 t180;
    Pad40_00536B40 t1C0;
    Pad40_00536B40 t200;
    Pad40_00536B40 t240;
    Pad40_00536B40 t280;
    Pad40_00536B40 t2C0;
    Pad40_00536B40 t300;
    Pad40_00536B40 t340;
    Pad40_00536B40 t380;
    Pad40_00536B40 t3C0;
};

struct Obj00536B40 {
    Pad400_00536B40 tPad0000;
    Pad400_00536B40 tPad0400;
    Pad400_00536B40 tPad0800;
    Pad400_00536B40 tPad0C00;
    Pad400_00536B40 tPad1000;
    Pad400_00536B40 tPad1400;
    Pad400_00536B40 tPad1800;
    Pad40_00536B40 tPad1C00;
    Pad40_00536B40 tPad1C40;
    Pad40_00536B40 tPad1C80;
    Pad40_00536B40 tPad1CC0;
    unsigned int dwUnknown1D00;
    unsigned int dwUnknown1D04;
    unsigned int dwUnknown1D08;
    unsigned int dwUnknown1D0C;
    unsigned int dwUnknown1D10;
    unsigned int dwUnknown1D14;
    unsigned int dwUnknown1D18;
    unsigned int dwUnknown1D1C;
    unsigned int dwUnknown1D20;
    unsigned int dwValue1D24;
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

unsigned char gbUnitProxyItemCacheInitialized_00883E88[17]; // 0x00883E88

struct D2RegurgitatorAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
};

enum
{
    MAX_NPC_INVENTORY = 17,
    UNIT_ALIGNMENT_EVIL = 0,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISMERC = 0x00000200,
    MONSTATS2FLAGINDEX_SOFT = 12,
};

int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0

extern const int gnDifficultyBonus_006E21F4[]; // 0x006E21F4

#define MAX_NPC_INVENTORY 17

extern "C" const char szSUnitProxyCppFile[];                                                                // 0x006E0A30

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

static void SUNITPROXY_InitializeItemCache(D2GameStrc* pGame, D2UnitProxyStrc* pUnitProxy, int nNpcInventoryId);

struct D2NpcConfigStrc
{
    int nClassId;
    unsigned char bTrader;
    unsigned char nAct;
    unsigned char unknown06;
    unsigned char unknown07;
};

struct D2NpcConfigTableStrc
{
    int nCount;
    D2NpcConfigStrc entries[64];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2NpcConfigTableStrc gNpcConfig; // 0x00731184

extern int gnItemCode_00883E9C; // 0x00883E9C

extern int gnItemCode_00883EA0; // 0x00883EA0

void __fastcall SEED_InitSeed(D2SeedStrc*); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc*,unsigned int); // 0x00650E40

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

#define UNIT_MONSTER 1

#define NPCREC_FIELD(type, cursor, offset) (*(type*)((cursor) + (offset) - 0x2C))

extern "C" const char szSUnitProxyCppFile_006E0A30[]; // 0x006E0A30

static void __stdcall SUNITPROXY_RemoveInventoryItems(D2GameStrc* pGame, D2InventoryStrc* pInventory);

static void __stdcall SUNITPROXY_ClearNpcRecordData(D2NpcRecordStrc* pNpcRecord, D2GameStrc* pGame);

void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc); // 0x00536D10

void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer);

void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame);

void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc);

// 0x00537AC0
void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame)
{
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pCurrent = pClient;
        pClient = pClient->pNext;
        FOG_FreePool(pGame->pMemoryPool, pCurrent, ".\\GAME\\Clients.cpp", 0x617, 0);
    }
}
