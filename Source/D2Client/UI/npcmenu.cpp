// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
#include <D2UnitData.h>
#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Primitives.h"
#include "D2DataTbls.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientMenus.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define CHECK(c,line) if(!(c)) { sub_00408A60(&empty,sub_00408090(),line); exit(-1); }

struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2ClientItemSlotStrc;
struct D2MonsterDataStrc;
struct D2ClientPacket7Strc;
struct D2PacketRecord6Strc;
struct D2StringMapStrc;
struct D2ClientStringListStrc;
struct D2PartyRecordStrc;
struct D2ClientObjectStrc;
struct D2NpcRecordStrc;
struct D2NpcQuestHandlerStrc;
struct D2NpcIndexStrc;
struct Unicode;
struct D2NpcMenuSlotStrc;
struct D2NpcMenuEntryStrc;
struct D2NpcPacketStrc;
struct D2ClientValueBlockStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2CoordStrc;
struct D2NpcEntryStrc;
class D2NpcTradeObjStrc;
struct Unit;
struct UnicodeChar;
union D2SeedStrc;

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x46];
    short nStateOverlayLevel[3];
    char unk0x5C[0x14C];
};

struct D2ClientItemSlotStrc
{
    unsigned short wId;
    char unk0x02[0x06];
    int nUnitId;
    char unk0x0C[0x04];
};

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004C70D0_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
void __stdcall sub_0063BD00(D2InventoryStrc* pInventory); // 0x0063BD00
void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory); // 0x0063CB70
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2ClientItemSlotStrc gaItemSlots_007C0C85[10]; // 0x007C0C85

#pragma pack(push, 1)
struct D2ClientPacket7Strc
{
    unsigned char nHeader;
    int dwUnitId;
    unsigned short f_5;
};

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
};

#pragma pack(pop)
struct D2StringMapStrc
{
    unsigned short f_0;
    unsigned short wValue;
    char unk0x04[0x4];
};

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

struct D2PartyRecordStrc
{
    unsigned char nFlag0;
    unsigned char nFlag1;
    char unk0x02[0x14];
};

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern int gnStringMapCount_00725C04; // 0x00725C04
extern D2StringMapStrc gaStringMap_0072739C[]; // 0x0072739C
extern int gnPartyCount_0072554C; // 0x0072554C
extern D2PartyRecordStrc gaParty_00726861[]; // 0x00726861
extern unsigned char gbGlobal_007C0C6A; // 0x007C0C6A
extern void* gpRes_007C0D63; // 0x007C0D63
extern void* gpRes_007C0D67; // 0x007C0D67
extern void* gpRes_007C0D73; // 0x007C0D73
extern void* gpRes_007C0D7B; // 0x007C0D7B
extern D2ClientStringListStrc gtStringList_007C0D9A; // 0x007C0D9A
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_004649D0(UNITFN pfnCallback); // 0x004649D0
void __cdecl sub_00466FE0(); // 0x00466FE0
D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __cdecl sub_00487B70(); // 0x00487B70
D2TextHeaderStrc* __cdecl sub_0049F900(); // 0x0049F900
int __fastcall sub_004AE130(D2UnitStrc* pUnit); // 0x004AE130
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc(); // 0x004B1620
void __cdecl sub_004B23E0_InitPartyPanel(); // 0x004B23E0
void __cdecl sub_004B24A0(); // 0x004B24A0
void __cdecl sub_004B2940(); // 0x004B2940
void __fastcall sub_004B3360(D2UnitStrc* pUnit); // 0x004B3360
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

struct D2ClientObjectStrc
{
    virtual void Destroy(int bFree) = 0;
};

extern D2ClientObjectStrc* gpObject_007C0D83; // 0x007C0D83
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490

struct D2NpcRecordStrc
{
    int unk0x00;
    int nValue04;
    int unk0x08;
    int nValue0C;
};

#pragma pack(push, 1)
struct D2NpcIndexStrc
{
    int nId;
    char unk0x04[0x23];
};

#pragma pack(pop)

extern D2NpcQuestHandlerStrc gaNpcHandlers_007253E0[]; // 0x007253E0
extern D2NpcIndexStrc gaNpcIndex_00726C48[]; // 0x00726C48

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, long* pLeft, long* pTop, long* pRight, long* pBottom); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
const Unicode* __fastcall sub_0049F910_GetTextString(unsigned short nStringId); // 0x0049F910
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370_SetCtrlState(void* pPanel, int nValue); // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8); // 0x004B85F0
int __cdecl sub_004B1DC0(); // 0x004B1DC0
int __cdecl sub_004B5810(); // 0x004B5810
int __cdecl sub_004B5850(); // 0x004B5850
extern D2ViewStrc* gpView_007A0640; // 0x007A0640
extern int gnGlobal_007C0C60; // 0x007C0C60
extern int gnGlobal_007C0C64; // 0x007C0C64
extern D2NpcMenuSlotStrc gaSlots_007C0C85[]; // 0x007C0C85
extern D2ClientDialogStrc* gpDialog_007C0D67; // 0x007C0D67
extern D2NpcEntryStrc gaNpcEntries_00726850[]; // 0x00726850
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
D2UnitStrc* __stdcall sub_Z12_EmitNext(D2UnitStrc* pItem);
void __stdcall sub_Z12_EmitUseItem(D2UnitStrc* pItem);

#pragma pack(push, 1)
struct D2NpcMenuEntryStrc
{
    int nType;
    char unk0x04[2];
    short wStringId;
    short wSlot[3];
    char unk0x0E[4];
    int (__cdecl* pfnHandler)();
    int nSlot[3];
    char unk0x22[5];
};

struct D2NpcPacketStrc
{
    unsigned char nHeader;
    unsigned short wSubId;
};

#pragma pack(pop)

int __cdecl sub_0044DB30(); // 0x0044DB30
void __cdecl sub_00487CC0_SelectFirstButton(); // 0x00487CC0
int __cdecl sub_004B2020_OpenTimedDialog34(); // 0x004B2020
extern D2NpcMenuEntryStrc gNpcMenuEntries_00726C4C[]; // 0x00726C4C
extern int gnGlobal_007C0D39; // 0x007C0D39
extern short gwGlobal_007C0D3D; // 0x007C0D3D
extern unsigned char g007C0D89; // 0x007C0D89
int __cdecl sub_004B1DD0_OpenTimedDialog62(); // 0x004B1DD0
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0
extern short gwGlobal_00726E01; // 0x00726E01
extern int gnGlobal_00726E0F; // 0x00726E0F
extern short gwGlobal_00726E4F; // 0x00726E4F
extern int gnGlobal_00726E5D; // 0x00726E5D
extern short gwGlobal_00726E9D; // 0x00726E9D
extern int gnGlobal_00726EAB; // 0x00726EAB
extern short gwGlobal_00726CCB; // 0x00726CCB
extern int gnGlobal_00726CDB; // 0x00726CDB
extern short gwGlobal_007272E1; // 0x007272E1
extern int gnGlobal_007272EF; // 0x007272EF
extern short gwGlobal_00727247; // 0x00727247
extern int gnGlobal_00727257; // 0x00727257
extern short gwGlobal_00727297; // 0x00727297
extern int gnGlobal_007272A9; // 0x007272A9
extern short gwGlobal_00726F87; // 0x00726F87
extern int gnGlobal_00726F95; // 0x00726F95
extern short gwGlobal_00726EC2; // 0x00726EC2
extern int (__cdecl* gpfnGlobal_00726ECE)(); // 0x00726ECE
extern short gwGlobal_00726EE9; // 0x00726EE9
extern int (__cdecl* gpfnGlobal_00726EF5)(); // 0x00726EF5
extern short gwGlobal_00726F10; // 0x00726F10
extern int (__cdecl* gpfnGlobal_00726F1C)(); // 0x00726F1C
extern short gwGlobal_00726F37; // 0x00726F37
extern int (__cdecl* gpfnGlobal_00726F43)(); // 0x00726F43
extern short gwGlobal_0072721C; // 0x0072721C
extern int (__cdecl* gpfnGlobal_00727228)(); // 0x00727228

#pragma pack(push, 1)
struct D2ClientValueBlockStrc
{
    char unk0x00[0x15];
    int anValues[20];
    D2ClientValueBlockStrc();
};

#pragma pack(pop)

void __cdecl sub_004939B0_LoadPopupHireling(); // 0x004939B0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_004B3C20(int nValue); // 0x004B3C20
void __cdecl sub_004B2F50_ShowTradeDialog(); // 0x004B2F50
extern "C" D2UnitStrc* __fastcall sub_00463990_FindClientUnit(int nUnitId, int nUnitType); // 0x00463990
extern "C" void __fastcall sub_004B3790_RemoveInventoryClientUnits(D2UnitStrc* pUnit); // 0x004B3790
extern "C" void __fastcall sub_004BA840(int nHandle); // 0x004BA840
extern "C" int gnNpcSoundActive_007C0DB4; // 0x007C0DB4
extern "C" int gnNpcSoundHandle_007C0DB8; // 0x007C0DB8
extern char gbGlobal_007C0C69; // 0x007C0C69
void __cdecl sub_004B3DE0_CloseNpc(); // 0x004B3DE0
void __cdecl sub_004B3ED0(); // 0x004B3ED0
void __cdecl sub_004B2110_FreeResources(); // 0x004B2110
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300
int __cdecl sub_004C0440_Thunk(); // 0x004C0440
void __cdecl sub_0048A6A0_ResetNpcCursor(); // 0x0048A6A0
void __cdecl sub_004B2110_FreeResources(); // 0x004B2110

struct Unit { char pad[0x60]; void* inventory; };

typedef int (__cdecl* Callback)();
void __cdecl sub_00487D30_SetNpcState7(); // 0x00487D30
int __cdecl sub_004B4CF0_NpcMenuReturn(); // 0x004B4CF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
Unit* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
Unit* __stdcall INVENTORY_GetCursorItem(void*); // 0x0063C1E0
int __cdecl sub_004680A0(); // 0x004680A0
void __fastcall sub_00468070_SetCursorItemState(Unit*); // 0x00468070
extern const char empty; // 0x006CC837
extern int g007C0C6B; // 0x007C0C6B
extern int g007C0D31; // 0x007C0D31
extern int g007C0D3F; // 0x007C0D3F
extern int g007C0D5B; // 0x007C0D5B
extern void* g007C0D67; // 0x007C0D67
extern int g007C0D8E; // 0x007C0D8E
extern int g007C0D96; // 0x007C0D96
extern int g007C0DE1; // 0x007C0DE1
extern int g007C0DE5; // 0x007C0DE5
static int sub_004B2E30_FindNpcIndex(D2NpcRecordStrc* pRecord);

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
void __fastcall sub_0048C060_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength); // 0x004B2AD0
int __cdecl sub_004B2E70_MenuBack(); // 0x004B2E70
int __cdecl sub_004B2F00_MenuClose(); // 0x004B2F00
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
extern Unicode gwszCost_007C0DF5[]; // 0x007C0DF5

typedef char sub_I16_AssertUnitSeed[(int)&((D2UnitStrc*)0)->pSeed == 0x20 ? 1 : -1];

typedef char sub_I16_AssertUnitInventory[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
int __cdecl sub_004B4670_NpcMenuCancelText(); // 0x004B4670
int __cdecl sub_004B46D0_NpcMenuCancelTextB(); // 0x004B46D0
int __cdecl sub_004B4730_NpcMenuTalk(); // 0x004B4730

static int GetUnitPathX(D2UnitStrc* pUnit)
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

static int GetUnitPathY(D2UnitStrc* pUnit)
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

static D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004AD0C0
void __fastcall sub_004AD0C0_StateOverlayBurst(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX + 1, nY + 1, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX + 1, nY - 1, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX - 1, nY + 1, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX - 1, nY - 1, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD1A0
void __fastcall sub_004AD1A0_StateOverlayCross(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nX, nY, 0, 1);
    const int nYPlus = nY + 1;
    const int nXPlus = nX + 1;
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXPlus, nYPlus, 0, 1);
    bFlag = nY - 1;
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXPlus, bFlag, 0, 1);
    const int nXMinus = nX - 1;
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXMinus, nYPlus, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nXMinus, bFlag, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXPlus, nYPlus, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXPlus, bFlag, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXMinus, nYPlus, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x52, nXMinus, bFlag, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD510
void __fastcall sub_004AD510_StateEffect(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag && nState == 0x12)
    {
        return;
    }

    if (nState == 0x2A)
    {
        if (!pUnit || !pUnit->dwAnimMode)
        {
            sub_004C70D0_StartUnitEffect(pUnit, pUnit, 0x5A, -1, 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_NOVA, 0));
        }
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    if (nState == 0x0A)
    {
        sub_004CDBA0_SubmitOwnerRequest(pUnit, 0x9B, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0));
        return;
    }
    if (nState == 0x12)
    {
        sub_004C70D0_StartUnitEffect(pUnit, pUnit, 0xC2, -1, 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_FROSTNOVA, 0));
    }
}

// 0x004ADB20
void __fastcall sub_004ADB20_StateOverlayAtPath(D2UnitStrc* pUnit, int nState, int bFlag)
{
    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }
    sub_004CDBA0_SubmitOwnerRequest(pUnit, 0x2A, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004ADBC0
void __fastcall sub_004ADBC0_StateMonOverlay(D2UnitStrc* pUnit, int nState, int bFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? GetMonStatsTxtRecord(pUnit->dwClassId) : 0;
    const int nLevel = pMonStatsTxtRecord->nStateOverlayLevel[sub_0044DCD0_GetDifficulty()];

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    if (nLevel == 1)
    {
        sub_004CDBA0_SubmitOwnerRequest(pUnit, 0x1AB, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    else if (nLevel >= 2)
    {
        sub_004CDBA0_SubmitOwnerRequest(pUnit, 0x1AC, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    sub_004CDBA0_SubmitOwnerRequest(pUnit, 0x1AA, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

unsigned char g007C0D89; // 0x007C0D89

unsigned char gbFound_007C0DDA; // 0x007C0DDA

// 0x004B1240
void __fastcall sub_004B1240_UsePacket7(D2ClientPacket7Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, 1);
    if (pUnit)
    {
        const unsigned short wClassId = pPacket->f_5;
        const int nClassId = wClassId == 0xFFFF ? -1 : wClassId;
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nMinionSpawnClassId = nClassId;
        }
    }
}

#include "gen/data/Source/D2Client/UI/npcmenu.inc"

void* gpCelFile_007C0DC8; // 0x007C0DC8

void* gpCelFile_007C0DCC; // 0x007C0DCC

// 0x004B1620
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc()
{
    if (gnGlobal_007C0D29)
    {
        return sub_00463990(gnGlobal_007C0D25, 1);
    }
    return 0;
}

// 0x004B1640
static void sub_004B1640_SetNpcInteract(D2NpcRecordStrc* pRecord)
{
    if (pRecord)
    {
        gnGlobal_007C0D29 = 1;
        gnGlobal_007C0D25 = pRecord->nValue0C;
        gdwGlobal_007C0D2D = pRecord->nValue04;
    }
    else
    {
        gnGlobal_007C0D29 = 0;
    }
}

static int CLIENT_IsStringUsed(unsigned short wString)
{
    for (int i = 0; i < gtStringList_007C0D9A.wCount; ++i)
    {
        if (gtStringList_007C0D9A.awStrings[i] == wString)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B1830
unsigned short __fastcall sub_004B1830_GetFreeStringId(unsigned short wStringId)
{
    for (int i = 0; i < gnStringMapCount_00725C04; ++i)
    {
        if (gaStringMap_0072739C[i].f_0 == wStringId)
        {
            return gaStringMap_0072739C[i].wValue;
        }
    }

    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    int nNode = 0;
    unsigned short wNode = sub_00661400(pTextHeader, nNode);
    while (wNode != 0xFFFF)
    {
        if (wNode != wStringId && !CLIENT_IsStringUsed(wNode))
        {
            return wNode;
        }
        ++nNode;
        wNode = sub_00661400(pTextHeader, nNode);
    }
    return 0xFFFF;
}

// 0x004B1980
void __fastcall sub_004B1980_AddUsedString(unsigned short wStringId)
{
    if (gtStringList_007C0D9A.wCount < 9)
    {
        gtStringList_007C0D9A.awStrings[gtStringList_007C0D9A.wCount] = wStringId;
        gtStringList_007C0D9A.wCount++;
    }
}

// 0x004B19A0
static int __stdcall sub_004B19A0_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount)
{
    int nResult = 1;
    for (int i = 0; i < nCount; ++i)
    {
        if (pTable[i].nNpcId == nNpcId)
        {
            if (pTable[i].bSet)
            {
                if (QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
            else
            {
                if (!QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
        }
    }
    return nResult;
}

// 0x004B1A10
static bool sub_004B1A10_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

void __cdecl sub_F03_Emit_004B1640(D2NpcRecordStrc* pRecord)
{
    sub_004B1640_SetNpcInteract(pRecord);
}

int __cdecl sub_F03_Emit_004B19A0(int nNpcId)
{
    return sub_004B19A0_RunNpcQuestHandlers(nNpcId, gpQuestFlags_007C0D43, gaNpcHandlers_007253E0, gnHandlerCount_007253DC);
}

void __cdecl sub_F03_Emit_004B1A10(int nClassId)
{
    if (sub_004B1A10_IsSpecialNpc(nClassId))
        gnGlobal_007C0D29 = 1;
}

int __cdecl sub_F03_Emit_004B2E30(D2NpcRecordStrc* pRecord)
{
    return sub_004B2E30_FindNpcIndex(pRecord);
}

static __forceinline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
}

// build: context sub_004B1C80_GetNpcDialogPos
static int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords)
{
    if (NPC_GetInteractUnit_Inline())
    {
        UNITS_GetClientCoords(NPC_GetInteractUnit_Inline(), pCoords);

        tagRECT tView;
        sub_00476070_GetViewRect(gpView_007A0640, &tView.left, &tView.top, &tView.right, &tView.bottom);

        D2CoordStrc tOffset;
        sub_004760C0_GetViewOffset(gpView_007A0640, &tOffset.nX, &tOffset.nY);

        tagRECT tRect;
        SetRect(&tRect, tOffset.nX, tOffset.nY, tOffset.nX + (tView.right - tView.left), tOffset.nY + (tView.bottom - tView.top));
        pCoords->nX -= tRect.left;
        pCoords->nY = pCoords->nY - tRect.top - 150;
        if (pCoords->nY < 20)
        {
            pCoords->nY = 20;
        }

        return 1;
    }

    return 0;
}

// 0x004B1DD0
int __cdecl sub_004B1DD0_OpenTimedDialog62()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    sub_00478680_SendPacket5(0x62, gnGlobal_007C0D25);
    gnGlobal_007C0C6B = 10;

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D67 = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwGlobal_007C0D53 = GetTickCount() + 60000;
    gnGlobal_007C0D57 = 0;
    sub_004B8370_SetCtrlState(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    return 1;
}

// 0x004B1E80
void __cdecl sub_004B1E80_OpenTimedDialog36()
{
    sub_004786A0_SendDwords2(0x36, gnGlobal_007C0C64, gaSlots_007C0C85[gnGlobal_007C0C60].wId);

    if (gpDialog_007C0D77)
    {
        sub_004B8020(gpDialog_007C0D77);
        delete gpTradeObj_007C0D83;
        gpTradeObj_007C0D83 = 0;
        gpDialog_007C0D77 = 0;
    }

    gnGlobal_007C0C6B = 10;

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D67 = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwGlobal_007C0D53 = GetTickCount() + 60000;
    gnGlobal_007C0D57 = 0;
    sub_004B8370_SetCtrlState(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
}

// 0x004B1F80
static int sub_004B1F80_ItemNeedsRepair(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        return 0;
    if (!sub_0062E660(pItem))
        return 0;
    if (ITEMS_HasDurability(pItem))
    {
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability && STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) < nMaxDurability)
            return 1;
    }
    if (ITEMS_CheckIfStackable(pItem) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        return 1;
    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
        return 1;
    return 0;
}

// 0x004B2020
int __cdecl sub_004B2020_OpenTimedDialog34()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    D2_ASSERT(!gpDialog_007C0D67, 0xA2D);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D67 = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwGlobal_007C0D53 = GetTickCount() + 60000;
    gnGlobal_007C0D57 = 0;
    sub_004B8370_SetCtrlState(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    gnGlobal_007C0C6B = 10;
    gnGlobal_007C0D31 = 4;
    gnGlobal_007C0D96 = 0;
    sub_00478680_SendPacket5(0x34, gnGlobal_007C0D25);
    return 1;
}

// 0x004B2110
void __cdecl sub_004B2110_FreeResources()
{
    if (gpRes_007C0D6F) { sub_004B8020(gpRes_007C0D6F); gpRes_007C0D6F = 0; }
    if (gpRes_007C0D73) { sub_004B8020(gpRes_007C0D73); gpRes_007C0D73 = 0; }
    if (gpRes_007C0D6B) { sub_004B8020(gpRes_007C0D6B); gpRes_007C0D6B = 0; }
    if (gpRes_007C0D7B) { sub_004B8020(gpRes_007C0D7B); gpRes_007C0D7B = 0; }
    if (gpRes_007C0D5F) { sub_004B8020(gpRes_007C0D5F); gpRes_007C0D5F = 0; }
    if (gpRes_007C0D63) { sub_004B8020(gpRes_007C0D63); gpRes_007C0D63 = 0; }
    if (gpRes_007C0D67) { sub_004B8020(gpRes_007C0D67); gpRes_007C0D67 = 0; }
    if (gpRes_007C0D77) { sub_004B8020(gpRes_007C0D77); gpRes_007C0D77 = 0; }
}

void __fastcall sub_Z12_EmitItemNeedsRepair(D2UnitStrc* pItem)
{
    for (; pItem; pItem = sub_Z12_EmitNext(pItem))
        if (sub_004B1F80_ItemNeedsRepair(pItem))
            sub_Z12_EmitUseItem(pItem);
}

// 0x004B21C0
static __forceinline void sub_004B21C0_SetEntryType2(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].nType = 2;
    gNpcMenuEntries_00726C4C[nIndex].wSlot[0] = 0;
    gNpcMenuEntries_00726C4C[nIndex].nSlot[0] = 0;
}

// 0x004B21E0
static __forceinline void sub_004B21E0_SetEntryType3(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].nType = 3;
    gNpcMenuEntries_00726C4C[nIndex].wSlot[1] = 0;
    gNpcMenuEntries_00726C4C[nIndex].nSlot[1] = 0;
}

// 0x004B2200
static __forceinline void sub_004B2200_SetEntryType4(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].nType = 4;
    gNpcMenuEntries_00726C4C[nIndex].wSlot[2] = 0;
    gNpcMenuEntries_00726C4C[nIndex].nSlot[2] = 0;
}

// 0x004B2220
static __forceinline void sub_004B2220_SetEntryHandler(int nIndex)
{
    gNpcMenuEntries_00726C4C[nIndex].wStringId = 0xFB4;
    gNpcMenuEntries_00726C4C[nIndex].pfnHandler = sub_004B2020_OpenTimedDialog34;
    gNpcMenuEntries_00726C4C[nIndex].nType = 3;
}

// 0x004B2250
void __cdecl sub_004B2250_ResetHandlers()
{
    gnGlobal_00726DF9 = 2; gwGlobal_00726E01 = 0; gnGlobal_00726E0F = 0;
    gnGlobal_00726E47 = 2; gwGlobal_00726E4F = 0; gnGlobal_00726E5D = 0;
    gnGlobal_00726E95 = 2; gwGlobal_00726E9D = 0; gnGlobal_00726EAB = 0;
    gnGlobal_00726CC1 = 3; gwGlobal_00726CCB = 0; gnGlobal_00726CDB = 0;
    gnGlobal_007272D9 = 2; gwGlobal_007272E1 = 0; gnGlobal_007272EF = 0;
    if (gpfnGlobal_007272EB == sub_004B1DD0_OpenTimedDialog62)
    {
        gnGlobal_007272D9 = 3;
    }
    gwGlobal_00727247 = 0; gnGlobal_00727257 = 0;
    gwGlobal_00727297 = 0; gnGlobal_007272A9 = 0;
    gnGlobal_00726F7F = 2; gwGlobal_00726F87 = 0; gnGlobal_00726F95 = 0;
    gwGlobal_00726F85 = 0; gpfnGlobal_00726F91 = 0;
    gnGlobal_0072723D = 3;
    gnGlobal_0072728B = 4;
    gwGlobal_00726EC2 = 0xFB4; gpfnGlobal_00726ECE = sub_004B2020_OpenTimedDialog34; gnGlobal_00726EBC = 3;
    gwGlobal_00726EE9 = 0xFB4; gpfnGlobal_00726EF5 = sub_004B2020_OpenTimedDialog34; gnGlobal_00726EE3 = 3;
    gwGlobal_00726F10 = 0xFB4; gpfnGlobal_00726F1C = sub_004B2020_OpenTimedDialog34; gnGlobal_00726F0A = 3;
    gwGlobal_00726F37 = 0xFB4; gpfnGlobal_00726F43 = sub_004B2020_OpenTimedDialog34; gnGlobal_00726F31 = 3;
    gwGlobal_0072721C = 0xFB4; gpfnGlobal_00727228 = sub_004B2020_OpenTimedDialog34; gnGlobal_00727216 = 3;
}

// 0x004B2370
void __fastcall sub_004B2370_SendPacket38(int nArg)
{
    gnGlobal_007C0D96 = 0;
    sub_004786D0_SendDwords3(0x38, 0, gnGlobal_007C0D25, nArg);
}

// 0x004B2390
void __fastcall sub_004B2390_CheckMonStatsFlag(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit->dwClassId);
    int bFlag = 0;
    if (pMonStatsTxtRecord)
    {
        bFlag = pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }
    if (bFlag)
    {
        sub_0046F0C0(pUnit, 0, 0x48);
    }
}

// 0x004B24A0
void __cdecl sub_004B24A0()
{
    QUESTRECORD_FreeRecord(0, gpQuestFlags_007C0D43);
    QUESTRECORD_FreeRecord(0, gpQuestFlags_007C0D47);
    gpQuestFlags_007C0D43 = 0;
    gpQuestFlags_007C0D47 = 0;

    if (gpCelFile_007C0DC8)
    {
        sub_00478A00(gpCelFile_007C0DC8);
        gpCelFile_007C0DC8 = 0;
    }
    if (gpCelFile_007C0DCC)
    {
        sub_00478A00(gpCelFile_007C0DCC);
        gpCelFile_007C0DCC = 0;
    }
    if (gpObject_007C0D83)
    {
        gpObject_007C0D83->Destroy(1);
        gpObject_007C0D83 = 0;
    }
    if (gpRes_007C0D5F) { sub_004B8020(gpRes_007C0D5F); gpRes_007C0D5F = 0; }
    if (gpRes_007C0D63) { sub_004B8020(gpRes_007C0D63); gpRes_007C0D63 = 0; }
    if (gpRes_007C0D67) { sub_004B8020(gpRes_007C0D67); gpRes_007C0D67 = 0; }
    if (gpRes_007C0D6B) { sub_004B8020(gpRes_007C0D6B); gpRes_007C0D6B = 0; }
    if (gpRes_007C0D77) { sub_004B8020(gpRes_007C0D77); gpRes_007C0D77 = 0; }
    if (gpRes_007C0D7B) { sub_004B8020(gpRes_007C0D7B); gpRes_007C0D7B = 0; }
    if (gpRes_007C0D6F) { sub_004B8020(gpRes_007C0D6F); gpRes_007C0D6F = 0; }
    if (gpRes_007C0D73) { sub_004B8020(gpRes_007C0D73); gpRes_007C0D73 = 0; }
}

void __stdcall sub_M129_Emit_004B21C0(int a, int b, int c, int d)
{
    sub_004B21C0_SetEntryType2(a);
    sub_004B21E0_SetEntryType3(b);
    sub_004B2200_SetEntryType4(c);
    sub_004B2220_SetEntryHandler(d);
}

// 0x004B25C0
void __fastcall sub_004B25C0_OnPacketSub3(D2NpcPacketStrc* pPacket)
{
    D2_ASSERT(pPacket, 0xFC6);
    if (pPacket->wSubId == 3 && gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
    {
        gnGlobal_007C0D39 = 1;
        gwGlobal_007C0D3D = pPacket->wSubId;
    }
}

// 0x004B2620
void __fastcall sub_004B2620_CopyQuestBuffer(unsigned char* pBuffer)
{
    QUESTRECORD_CopyBufferToRecord((D2BitBufferStrc*)gpGlobal_007C0D47, pBuffer, 0x60, 0);
}

// 0x004B2640
void __fastcall sub_004B2640(int nUnused)
{
    sub_00487B70();
}

// 0x004B2900
void __cdecl sub_004B2900_CloseDialog()
{
    if (gpRes_007C0D67)
    {
        sub_004B8020(gpRes_007C0D67);
        gpRes_007C0D67 = 0;
    }
    gnGlobal_007C0C6B = 3;
    sub_00487CC0_SelectFirstButton();
    sub_00488F10();
    sub_00466FE0();
}

// 0x004B2940
void __cdecl sub_004B2940()
{
    const unsigned int nTick = GetTickCount();
    if (nTick - gnGlobal_007C0DE9 > 1000)
    {
        gnGlobal_007C0D57 = nTick + 100;
    }
    else
    {
        unsigned int nCount = gnGlobal_007C0DED;
        if (nCount >= 10)
            nCount = 10;
        gnGlobal_007C0D57 = (nCount + 30) * 500 + nTick;
    }
    gnGlobal_007C0D96 = 0;
    gbGlobal_007C0DE0 = 0;
    gnGlobal_007C0DE1 = 0;
    gnGlobal_007C0DE5 = 0;
    if (!sub_0044DB30())
        sub_004B2900_CloseDialog();
}

// 0x004B29E0
void __fastcall sub_004B29E0(int nUnitId)
{
    if (gnGlobal_007C0D96 && g007C0D89 == 1 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A00
void __fastcall sub_004B2A00(int nUnitId)
{
    if (gnGlobal_007C0D96 && g007C0D89 == 1 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A20
void __fastcall sub_004B2A20(int nUnitId)
{
    if (gnGlobal_007C0D96 && g007C0D89 == 1 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A40
void __fastcall sub_004B2A40(int nUnitId)
{
    if (gnGlobal_007C0D96 && g007C0D89 == 0 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A60
void __fastcall sub_004B2A60(int nUnitId)
{
    if (gnGlobal_007C0D96 && g007C0D89 == 0 && nUnitId == gnGlobal_007C0D8E)
    {
        sub_004B2940();
    }
}

// 0x004B2A80
void __fastcall sub_004B2A80_ResetHoverForItem(int nUnitId)
{
    D2UnitStrc* pSelected = sub_00467A10();
    if (pSelected && gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1)
        && pSelected->dwUnitType == UNIT_ITEM && pSelected->dwUnitId == nUnitId)
    {
        sub_00466FE0();
        sub_00487990_ResetHover();
    }
}

// 0x004B2E20
int __cdecl sub_004B2E20_IsQuestActive()
{
    return gnGlobal_007C0C6B != 0;
}

// 0x004B2E30
static int sub_004B2E30_FindNpcIndex(D2NpcRecordStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->nValue04;
    for (int i = 0; i < gnNpcIndexCount_00725A74; ++i)
    {
        if (gaNpcIndex_00726C48[i].nId == nId)
            return i;
    }
    return 0;
}

// 0x004B2F50
void __cdecl sub_004B2F50_ShowTradeDialog()
{
    D2_ASSERT(!gpDialog_007C0D5F, 0x151B);

    gnGlobal_007C0C6B = 4;
    gpDialog_007C0D5F = sub_004B7EB0_CreateDialog(sub_00468730(), sub_00468740(), sub_004B2F00_MenuClose, 0, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370_SetCtrlState(gpDialog_007C0D5F, 1);

    D2UnitStrc* pItem;
    int bService;
    int bShowItem = 1;
    switch (gnGlobal_007C0D31)
    {
    case 1:
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD14), 0x15, 0, 4, 1, 0, 0);
        bService = 0;
        break;

    case 2:
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD13), 0x15, 0, 4, 1, 0, 0);
        bService = 1;
        break;

    case 3:
        bService = 1;
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD17), 0x15, 0, 4, 1, 0, 0);
        break;

    case 4:
        bService = 1;
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD16), 0x15, 0, 4, 1, 0, 0);
        break;

    case 5:
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD18), 0x15, 0, 4, 1, 0, 0);
        bShowItem = 0;
        break;

    default:
        D2_ASSERT(0, 0x1550);
    }

    if (bShowItem)
    {
        pItem = sub_00463990(gnGlobal_007C0DE5, 4);
        if (!pItem)
        {
            return;
        }

        UnicodeChar wszName[0xC0];
        sub_0048C060_BuildItemName(pItem, wszName, 0xBF);
        const int nLength = sub_00526800(wszName);
        int i = 0;
        int bDone = 0;
        while (!bDone)
        {
            if (i >= nLength)
            {
                bDone = 1;
            }
            else if (wszName[i].wChar == '\n')
            {
                wszName[i].wChar = 0;
                bDone = 1;
            }
            else
            {
                ++i;
            }
        }

        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, wszName, 0xF, 0, 4, 1, sub_004B2E70_MenuBack, 0);

        int nCost;
        gwszCost_007C0DF5[0].wChar = 0;
        sub_004B2AD0_GetTradeCostText(pItem, bService, &nCost, gwszCost_007C0DF5, 0x28);

        {
            UnicodeChar wszCost[10];
            char szCost[12];
            wsprintfA(szCost, gszFormatD_006D57BC, nCost);
            sub_00526F20_ToUnicode(wszCost, szCost, 9);
            sub_005267E0(gwszCost_007C0DF5, wszCost);
        }

        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD12), 0xF, 0, 4, 1, sub_004B2E70_MenuBack, 0);
        sub_004B85F0_AddTextLine(gpDialog_007C0D5F, gwszCost_007C0DF5, 0xF, 0, 4, 1, sub_004B2E70_MenuBack, 0);
    }

    sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD10), 0xF, 0, 0, 1, sub_004B2E70_MenuBack, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D5F, D2LANG_GetStringFromTblIndex(0xD11), 0xF, 0, 0, 1, sub_004B2F00_MenuClose, 1);
}

// 0x004B3230
int __fastcall sub_004B3230_GetTickPair(int* pLow)
{
    *pLow = gnGlobal_007C0D25;
    return gnGlobal_007C0D29;
}

// 0x004B3290
void __cdecl sub_004B3290_ResetSlots()
{
    for (int i = 0; i < 10; ++i)
    {
        gaItemSlots_007C0C85[i].nUnitId = 0;
    }
}

// 0x004B32F0
void __cdecl sub_004B32F0()
{
    gwGlobal_00725494 = 0xFFFF;
    sub_004B24A0();
    sub_004B23E0_InitPartyPanel();
    gbGlobal_007C0C6A = 0;
    for (int i = 0; i < gnPartyCount_0072554C; ++i)
    {
        gaParty_00726861[i].nFlag0 = 0;
        gaParty_00726861[i].nFlag1 = 0;
    }
}

// 0x004B3330
void __cdecl sub_004B3330_Empty()
{
}

// 0x004B3340
void __fastcall sub_004B3340_OnUiPacket2(unsigned short nArg)
{
    for (int i = 0; i < 10; ++i)
    {
        if (gaItemSlots_007C0C85[i].wId == nArg)
            break;
    }
    sub_004939B0_LoadPopupHireling();
}

// 0x004B3380
void __fastcall sub_004B3380(D2PacketRecord6Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwClassId == 0x216)
    {
        if (sub_004AE130(pUnit) != -1)
        {
            sub_004B9A00(0x11FB, pUnit, 0, 0, 0);
        }
        else
        {
            sub_004B9A00(0x11FF, pUnit, 0, 0, 0);
        }
        return;
    }

    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    if (pUnit == pNpc)
    {
        return;
    }

    sub_00470390(pUnit, 0x48, 3, 0, 0, 0, 0, 0);
    if (pUnit->dwClassId != 0x14B || sub_004B1620_GetInteractNpc() || !gpQuestFlags_007C0D43)
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, 12, 8) || QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, 12, 1))
    {
        return;
    }

    gbFound_007C0DDA = 0;
    sub_004649D0(sub_004B3360);
    if (!gbFound_007C0DDA)
    {
        sub_004B9A00(0xF8F, pUnit, 0, 0, 0);
    }
}

// 0x004B3470
int __cdecl sub_004B3470_IsNpcQuestActive()
{
    if (gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1) && gnGlobal_007C0C6B == 1)
    {
        return 1;
    }
    return 0;
}

// 0x004B3560
D2ClientValueBlockStrc::D2ClientValueBlockStrc()
{
    for (int i = 0; i < 20; ++i)
        anValues[i] = 0;
}

// 0x004B3610
void __cdecl sub_004B3610_CloseTradeDialog()
{
    if (gpDialog_007C0D77)
    {
        sub_004B8020(gpDialog_007C0D77);
        delete gpTradeObj_007C0D83;
        gpTradeObj_007C0D83 = 0;
        gpDialog_007C0D77 = 0;
    }

    gnGlobal_007C0D31 = 5;
    sub_004B2F50_ShowTradeDialog();
}

// 0x004B3790
void __fastcall sub_004B3790_RemoveInventoryClientUnits(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 10; ++i)
    {
        gaItemSlots_007C0C85[i].nUnitId = 0;
    }

    if (!pUnit)
    {
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pItemUnit = INVENTORY_UnitIsItem(pItem);
        if (pItemUnit)
        {
            const int nUnitType = pItemUnit ? pItemUnit->dwUnitType : UNIT_INVALID;
            const int nUnitId = pItemUnit ? pItemUnit->dwUnitId : -1;
            sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
        }
    }
    INVENTORY_RemoveInventoryItems(pInventory);
    sub_0063BD00(pInventory);
}

// 0x004B3830
extern "C" void __fastcall sub_004B3830_ClearNpcInventoryAndSound(int nUnitId)
{
    D2UnitStrc* pUnit = sub_00463990_FindClientUnit(nUnitId, 1);
    if (pUnit)
    {
        sub_004B3790_RemoveInventoryClientUnits(pUnit);
    }
    if (gnNpcSoundActive_007C0DB4)
    {
        sub_004BA840(gnNpcSoundHandle_007C0DB8);
    }
    gnNpcSoundActive_007C0DB4 = 0;
    gnNpcSoundHandle_007C0DB8 = 0;
}

// 0x004B3D10
void __fastcall sub_004B3D10_CancelAndFlag(int nUnitId)
{
    sub_004B3C20(nUnitId);
    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }
}

// 0x004B3DE0
void __cdecl sub_004B3DE0_CloseNpc()
{
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B3ED0
void __cdecl sub_004B3ED0()
{
    sub_00455F20(12, 1, 0);
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B3F10
void __cdecl sub_004B3F10_CloseByState()
{
    if (gnGlobal_007C0C6B == 1)
    {
        gbGlobal_007C0C69 = 0;
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }
    else if (gnGlobal_007C0C6B >= 3 && gnGlobal_007C0C6B <= 6)
    {
        sub_004B3ED0();
        sub_0048A6A0_ClearHover();
    }
    else if (gnGlobal_007C0C6B == 7)
    {
        sub_004C0440();
    }
    else if (gbGlobal_007C0C69)
    {
        gbGlobal_007C0C69 = 0;
        sub_004B3DE0_CloseNpc();
    }

    sub_004B2110_FreeResources();
    gnGlobal_007C0C6B = 0;
}

// 0x004B3FB0
void __cdecl sub_004B3FB0_CloseNpc2()
{
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B3FE0
void __cdecl sub_004B3FE0()
{
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B4070
int __cdecl sub_004B4070_ClosePanel73()
{
    if (gbGlobal_007C0C69)
    {
        return 0;
    }

    if (gpDialog_007C0D73)
    {
        sub_004B8020(gpDialog_007C0D73);
        gpDialog_007C0D73 = 0;
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }

    return 1;
}

static __forceinline unsigned int NPCDLG_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004B4DB0
void __cdecl sub_004B4DB0_OpenGreetingDialog()
{
    if (!NPC_GetInteractUnit_Inline())
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    D2_ASSERT(!gpDialog_007C0D7B, 0xD69);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D7B = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B4670_NpcMenuCancelText, sub_004B46D0_NpcMenuCancelTextB, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370_SetCtrlState(gpDialog_007C0D7B, 1);

    Unicode wszName[80];
    for (int i = 0; i < 80; ++i)
    {
        wszName[i].wChar = 0;
    }

    sub_005267E0(wszName, sub_00464A60_GetUnitName(NPC_GetInteractUnit_Inline()));
    const int nLength = sub_00526800(wszName);
    for (int i = 0; i < nLength; ++i)
    {
        const unsigned short wChar = wszName[i].wChar;
        wszName[i].wChar = wChar < 0x100 ? gaCaseTable_00730778[wChar] : wChar;
    }

    sub_004B85F0_AddTextLine(gpDialog_007C0D7B, wszName, 0x15, 0, 4, 1, 0, 0);
    gnGlobal_007C0C6B = 1;

    unsigned short aStrings[5];
    int nStrings = 0;
    aStrings[nStrings++] = 0xD3A;
    aStrings[nStrings++] = 0xD3B;
    aStrings[nStrings++] = 0xD3C;
    aStrings[nStrings++] = 0xD3D;
    aStrings[nStrings++] = 0xD3E;
    D2UnitStrc* pPlayer = sub_00463DD0();
    const unsigned int nRoll = NPCDLG_RollSeed_Inline(&pPlayer->pSeed) % nStrings;
    sub_004B85F0_AddTextLine(gpDialog_007C0D7B, D2LANG_GetStringFromTblIndex(aStrings[nRoll]), 0xF, 0, 0, 1, sub_004B4730_NpcMenuTalk, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D7B, D2LANG_GetStringFromTblIndex(0x102E), 0xF, 0, 0, 1, sub_004B4670_NpcMenuCancelText, 1);
    sub_004B82F0_Select(gpDialog_007C0D7B, 1);
}

// 0x004B5320
void __fastcall sub_004B5320_OnUnitRemoved(unsigned char nUnitType, int nUnitId)
{
    D2UnitStrc* pUnit = 0;
    if (nUnitType < 6)
    {
        pUnit = sub_00463990(nUnitId, nUnitType);
    }

    switch (nUnitType)
    {
    case 1:
        if (pUnit)
        {
            pUnit->dwFlags |= 2;
        }

        if (gnGlobal_007C0C6B == 1)
        {
            gbGlobal_007C0C69 = 0;
            sub_004B3DE0_CloseNpc();
        }
        else if (gnGlobal_007C0C6B >= 3 && gnGlobal_007C0C6B <= 6)
        {
            sub_004B3ED0();
            sub_0048A6A0_ResetNpcCursor();
        }
        else if (gnGlobal_007C0C6B == 7)
        {
            sub_004C0440_Thunk();
        }
        else if (gbGlobal_007C0C69)
        {
            gbGlobal_007C0C69 = 0;
            sub_004B3DE0_CloseNpc();
        }

        sub_004B2110_FreeResources();
        gnGlobal_007C0C6B = 0;
        break;

    case 2:
    case 4:
    case 6:
        sub_00456300_CloseUIVars(1, 0);
        break;
    }
}

unsigned char g007C0DE0; // 0x007C0DE0

// 0x004B53F0
void __cdecl sub_004B53F0()
{
 void* inv=sub_00463DD0_GetPlayerUnit()->inventory;
 if(g007C0D89<=6) {
  switch(g007C0D89) {
   case 0:
    sub_004B9A00(g007C0D5B,0,0,0,0); g007C0D5B=0;
    if(!sub_00463990(g007C0D8E,4)) { g007C0D96=1; return; }
    break;
   case 1:
    sub_004B9A00(0xdd,0,0,0,0);
    if(sub_00463990(g007C0D8E,4)) { g007C0D96=1; return; }
    break;
   case 5: sub_004939B0_LoadPopupHireling(); break;
  }
  g007C0D96=0;
  if(g007C0D67) { sub_004B8020(g007C0D67);g007C0D67=0; }
  sub_00466FE0(); g007C0DE0=0;g007C0DE1=0;g007C0DE5=0;g007C0C6B=3;
  sub_00487CC0_SelectFirstButton();sub_00488F10();return;
 }
 if(g007C0D67) {sub_004B8020(g007C0D67);g007C0D67=0;}
 int text;
 switch(g007C0D89) {
 case 15:text=0xd23;break;
 case 16:text=0xd1d;break;
 case 12:text=0xd22;break;
 case 10:text=0xd1c;break;
 case 11:text=0xd20;break;
 case 7:case 8:text=0xd1e;break;
 default:text=0xd21;break;
 }
 if(g007C0C6B==5) {
 g007C0C6B=6;sub_00487D30_SetNpcState7();
 CHECK(!gpRes_007C0D63,0x1399);
 if(g007C0D31==2) {
  Unit* item=INVENTORY_GetCursorItem(inv);
  if(g007C0D3F==1 && item && !sub_004680A0()) sub_00468070_SetCursorItemState(item);
 }
 gpRes_007C0D63=sub_004B7EB0_CreateDialog(sub_00468730(),sub_00468740(),sub_004B4CF0_NpcMenuReturn,0,0,1,1,0,0,0,1);
 sub_004B8370_SetCtrlState(gpRes_007C0D63,1);
 sub_004B85F0_AddTextLine(gpRes_007C0D63,D2LANG_GetStringFromTblIndex(text),0x15,0,1,1,0,0);
 sub_004B85F0_AddTextLine(gpRes_007C0D63,D2LANG_GetStringFromTblIndex(0xd4b),0xf,0,0,1,sub_004B4CF0_NpcMenuReturn,1);
 } else { sub_00408A60(&empty,sub_00408090(),0x13ad);exit(-1); }
}

// 0x004B5890
void __stdcall sub_004B5890_OpenNpcPanel(int nStringIndex, int nEntryIndex)
{
    D2_ASSERT(!gpDialog_007C0D6F, 0x76F);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D6F = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B5810, sub_004B4010, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370_SetCtrlState(gpDialog_007C0D6F, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);

    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    if (!pTextHeader)
    {
        sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B5810, 1);
        return;
    }

    const int nCount = TEXT_GetMenuType2NodeCount(pTextHeader);
    gnGlobal_007C0C81 = nEntryIndex;
    if (!gaNpcEntries_00726850[nEntryIndex].bFlag14)
    {
        sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(0xD47), 0xF, 0, 0, 1, sub_004B41E0, 1);
    }

    sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(0xD43), 0xF, 0, 0, 1, sub_004B41C0, 1);

    for (int i = 0; i < nCount; ++i)
    {
        const unsigned short nStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, i);
        sub_004B85F0_AddTextLine(gpDialog_007C0D6F, sub_0049F910_GetTextString(nStringId), 0xF, 0, 0, 1, sub_004B1A80, 1);
    }

    if (gdwGlobal_007C0D2D == 0xC9)
    {
        sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(0xD40), 0xF, 0, 0, 1, sub_004B1B80, 1);
    }

    if (gdwGlobal_007C0D2D == 0x109 || gdwGlobal_007C0D2D == 0xF4 || gdwGlobal_007C0D2D == 0xF5 || gdwGlobal_007C0D2D == 0x208 || gdwGlobal_007C0D2D == 0xF6)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && pPlayer->pInventory)
        {
            for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pItem);
                if (pCheck && ITEMS_GetBaseCode(pCheck) == 0x20786F62)
                {
                    sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(0x8B7), 0xF, 0, 0, 1, sub_004B1C00, 1);
                    break;
                }
            }
        }
    }

    sub_004B85F0_AddTextLine(gpDialog_007C0D6F, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B5810, 1);
}

// 0x004B5AD0
void __stdcall sub_004B5AD0_OpenConfirmDialog(int nStringIndex)
{
    D2_ASSERT(!gpDialog_007C0D73, 0x7D7);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D73 = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B5850, sub_004B4070, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370_SetCtrlState(gpDialog_007C0D73, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D73, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D73, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B4290, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D73, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B5850, 1);
}
