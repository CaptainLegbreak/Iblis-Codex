#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientMenus.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2Primitives.h"
#include "D2Txt.h"

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct D2NpcMenuSlotStrc;

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

unsigned short __fastcall sub_004B1830_GetFreeStringId(unsigned short wStringId); // 0x004B1830

int __cdecl sub_004B5BC0_SelectNpcEntry(); // 0x004B5BC0

void __fastcall sub_004B8020(void* pRes); // 0x004B8020

int __fastcall sub_004B8580(D2ClientDialogStrc* pDialog); // 0x004B8580

D2TextHeaderStrc* __cdecl sub_0049F900(); // 0x0049F900

extern D2NpcEntryStrc gaNpcEntries_00726850[]; // 0x00726850

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue); // 0x004B18C0

char gbGlobal_007C0C69; // 0x007C0C69

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, long* pLeft, long* pTop, long* pRight, long* pBottom); // 0x00476070

void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

const Unicode* __fastcall sub_0049F910_GetTextString(unsigned short nStringId); // 0x0049F910

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0

void __fastcall sub_004B8370(void* pPanel, int nValue); // 0x004B8370

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

struct D2NpcMonListPacketStrc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short nMonIds[12];
};

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall sub_004B3790_RemoveInventoryClientUnits(D2UnitStrc* pUnit); // 0x004B3790

void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840

void __cdecl sub_004A1730_ClearPanel();                                                                     // 0x004A1730

void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70

void __cdecl sub_004B4830_Rebuild();                                                                        // 0x004B4830

int __cdecl sub_004B5C60_Handler();                                                                         // 0x004B5C60

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern D2ClientDialogStrc* gpDialog_007C0D63;                                                               // 0x007C0D63

extern "C" int gnNpcSoundActive_007C0DB4;                                                                   // 0x007C0DB4

extern "C" int gnNpcSoundHandle_007C0DB8;                                                                   // 0x007C0DB8

extern int (__cdecl* gpfnGlobal_00726E0B)();                                                                // 0x00726E0B

extern short gwGlobal_00726DFF;                                                                             // 0x00726DFF

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

#pragma pack(push, 1)

struct D2NpcIndexStrc
{
    int nId;
    int nCount;
    unsigned short awIds[5];
    int (__cdecl* apfHandlers[5])();
    char bEnabled;
};

#pragma pack(pop)

typedef char check_size_npcindex[(sizeof(D2NpcIndexStrc) == 0x27) ? 1 : -1];

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

void __cdecl sub_0044DA40();                                                                                // 0x0044DA40

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300

int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490

void __fastcall sub_00464420_TurnTowardPlayer(D2UnitStrc* pUnit);                                                 // 0x00464420

void __fastcall sub_004644E0_PlayerFaceUnit(D2UnitStrc* pUnit);                                             // 0x004644E0

void __fastcall sub_00464990(UNITFN pfnCallback);                                                           // 0x00464990

void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0

void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990

D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc();                                                          // 0x004B1620

int __cdecl sub_004B1DD0_OpenTimedDialog62();                                                               // 0x004B1DD0

void __cdecl sub_004B2250_ResetHandlers();                                                                  // 0x004B2250

void __fastcall sub_004B2390_CheckMonStatsFlag(D2UnitStrc* pUnit);                                          // 0x004B2390

extern "C" void __fastcall sub_004B3830_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20

void __cdecl sub_004B3DE0_CloseNpc();                                                                       // 0x004B3DE0

void __cdecl sub_004B4DB0_OpenGreetingDialog();                                                             // 0x004B4DB0

void __stdcall sub_004B4FD0(D2UnitStrc* pUnit);

int __cdecl sub_004B6410_InitHandler();                                                                     // 0x004B6410

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

void __fastcall sub_004CB190_ReleaseSkillSfx(D2UnitStrc* pUnit);                                            // 0x004CB190

int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

short __stdcall sub_00661440(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661440

extern D2NpcQuestHandlerStrc gaNpcHandlers_007253E0[];                                                      // 0x007253E0

extern D2NpcIndexStrc gaNpcIndex_00726C48[];                                                                // 0x00726C48

extern char gaGlobal_007C0C68[];                                                                            // 0x007C0C68

extern D2ClientStringListStrc gtStringList_007C0D9A;                                                        // 0x007C0D9A

extern int gdwGlobal_007C0DB0;                                                                              // 0x007C0DB0

extern int gnGlobal_007C0DD0;                                                                               // 0x007C0DD0

union D2SeedStrc;

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3); // 0x004786D0

void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry);

extern D2UnitStrc* gpUnit_007C0DD4; // 0x007C0DD4

extern unsigned short gwGlobal_007C0DD8; // 0x007C0DD8

void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880

void __fastcall sub_0044C860_SetValue(int nValue); // 0x0044C860

void __cdecl sub_0044D520(); // 0x0044D520

int __cdecl sub_0044DB30(); // 0x0044DB30

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __cdecl sub_00463DF0(); // 0x00463DF0

int __cdecl sub_004680A0(); // 0x004680A0

void __cdecl sub_00477EE0_SendPacket69(); // 0x00477EE0

void __cdecl sub_0048A630_EnterState1(); // 0x0048A630

void __cdecl sub_004B2110_FreeResources(); // 0x004B2110

void __cdecl sub_004B2900_CloseDialog(); // 0x004B2900

void __fastcall sub_004B8100(void* pObj);

int gnGlobal_007C0DBC; // 0x007C0DBC

int gnGlobal_007C0DC0; // 0x007C0DC0

unsigned long gdwGlobal_007C0DC4; // 0x007C0DC4

struct D2BitBufferStrc;

struct D2GameStrc;

struct D2StoredMsgPacketStrc;

struct D2StoredMsgStrc;


void __cdecl sub_00487C20(); // 0x00487C20

void __cdecl sub_00487C60(); // 0x00487C60

int __cdecl sub_00487CA0_SetNpcState6(); // 0x00487CA0

int __cdecl sub_00489870(); // 0x00489870

void __cdecl sub_0048A630(); // 0x0048A630

void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700

int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

extern int gnGlobal_007C0D3F; // 0x007C0D3F

extern int gnGlobal_007C0D5B; // 0x007C0D5B

extern int gnGlobal_007C0DB0; // 0x007C0DB0

extern D2UnitStrc* gpPlayer_007C0DD4; // 0x007C0DD4

extern unsigned long gdwGlobal_007C0DE9; // 0x007C0DE9

extern unsigned long gdwGlobal_007C0DF1; // 0x007C0DF1

extern unsigned long gdwGlobal_007C0E48; // 0x007C0E48

static int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords); // 0x004B1C80

extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0

unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __stdcall ITEMS_GetAllRepairCosts(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void (__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*)); // 0x0062FE60

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

#pragma pack(push, 1)

struct D2StoredMsgPacketStrc
{
    unsigned char nHeader;
    unsigned short wValue;
    unsigned int dwValue;
};

#pragma pack(pop)

struct D2StoredMsgStrc
{
    unsigned short wValue;
    unsigned short unk0x02;
    unsigned int dwValue;
    int bUsed;
    int unk0x0C;
};

extern D2StoredMsgStrc gaStoredMsgs_007C0C85[10]; // 0x007C0C85

// 0x004B18C0
int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue)
{
    if (gbGlobal_007C0C69 == 1)
    {
        const unsigned short wStringId = sub_004B1830_GetFreeStringId(gwGlobal_007C0C7B);
        if (wStringId != 0xFFFF && gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
        {
            gwGlobal_007C0C7B = wStringId;
            D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
            sub_004A10E0(pNpc, wStringId, 0);
            sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
            return 1;
        }
    }

    gbGlobal_007C0C69 = 0;
    sub_0049E7E0_SetTextCallback(0, pContext);
    sub_004B5BC0_SelectNpcEntry();
    return 1;
}

// 0x004B1A80
int __cdecl sub_004B1A80_OnSelectMessage()
{
    const int nSelected = sub_004B8580(gpDialog_007C0D6F);
    const int nFirstLine = gaNpcEntries_00726850[gnGlobal_007C0C81].bFlag14 ? 2 : 3;
    if (nSelected < nFirstLine)
    {
        return 0;
    }

    if (!gnGlobal_007C0D29 || !sub_00463990(gnGlobal_007C0D25, 1))
    {
        return 0;
    }

    const int nNodeId = sub_004B8580(gpDialog_007C0D6F) - nFirstLine;
    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    D2_ASSERT(pTextHeader, 0x710);
    const unsigned short wStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, nNodeId);
    gwGlobal_007C0C7B = wStringId;
    D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    sub_004A10E0(pNpc, wStringId, 0);
    gbGlobal_007C0C69 = 1;
    sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
    sub_004B8020(gpDialog_007C0D6F);
    gpDialog_007C0D6F = 0;
    return 1;
}

// 0x004B1B80
int __cdecl sub_004B1B80_SendNpcMessageFE()
{
    if (gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
    {
        D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
        sub_004A10E0(pNpc, 0xFE, 0);
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
        sub_004B8020(gpDialog_007C0D6F);
        gpDialog_007C0D6F = 0;
    }
    return 1;
}

// 0x004B1C00
int __cdecl sub_004B1C00_SendNpcMessage152()
{
    if (gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
    {
        D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
        sub_004A10E0(pNpc, 0x152, 0);
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
        sub_004B8020(gpDialog_007C0D6F);
        gpDialog_007C0D6F = 0;
    }
    return 1;
}

static __forceinline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
}

// 0x004B1C80
static __declspec(noinline) int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords)
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
        pCoords->nY += -150 - tRect.top;
        pCoords->nX -= tRect.left;
        if (pCoords->nY < 20)
        {
            pCoords->nY = 20;
        }

        return 1;
    }

    return 0;
}

static inline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x004B2650
void __stdcall sub_004B2650_OpenNpcMenu(int bAlternate, int nFlags)
{
    if (!gbGlobal_007C0DE0)
    {
        sub_00487C20();
        return;
    }

    char nCommand;
    switch (gnGlobal_007C0D31)
    {
    case 1:
        nCommand = 0x32;
        break;
    case 2:
        nCommand = 0x33;
        break;
    case 3:
        nCommand = 0x35;
        sub_004B9A00(0x0F, 0, 0, 0, 0);
        break;
    default:
        gnGlobal_007C0C6B = 3;
        sub_00487C20();
        return;
    }

    unsigned int nMode = 0;
    gnGlobal_007C0D96 = 0;
    D2UnitStrc* pUnit = 0;
    if (sub_00489870())
    {
        if (GetTickCount() - gdwGlobal_007C0E48 < 2000)
        {
            sub_00487C20();
            return;
        }
        gdwGlobal_007C0E48 = GetTickCount();
    }
    else
    {
        pUnit = sub_00463990(gnGlobal_007C0DE5, 4);
        if (pUnit)
        {
            nMode = (unsigned short)pUnit->dwAnimMode;
            if (gnGlobal_007C0D31 == 2)
            {
                D2InventoryStrc* const pInventory = gpPlayer_007C0DD4->pInventory;
                gnGlobal_007C0D3F = INVENTORY_GetCursorItem(pInventory) == pUnit;
            }
        }
        else
        {
            gnGlobal_007C0C6B = 3;
            sub_0048A630();
            gdwGlobal_007C0DE9 = GetTickCount();
            ++gnGlobal_007C0DED;
            gbGlobal_007C0DE0 = 0;
            return;
        }
    }

    if (bAlternate)
    {
        sub_00487CA0_SetNpcState6();
    }
    else
    {
        sub_00487C60();
    }

    gnGlobal_007C0C6B = 5;
    gdwGlobal_007C0DF1 = GetTickCount();
    if (nCommand == 0x32)
    {
        if (gnGlobal_007C0DB0)
            nMode = ((unsigned int)(unsigned short)nMode << 16) | 2;
        else
            nMode = (unsigned int)(unsigned short)nMode << 16;
        if (nFlags & 4)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInl(pUnit));
            if (pItemsTxtRecord && pItemsTxtRecord->nField1A5)
            {
                nMode |= 0x80000000;
            }
        }
        sub_00478700_SendCommand(0x32, gnGlobal_007C0D25, gnGlobal_007C0DE5, nMode, gnGlobal_007C0D7F);
        gnGlobal_007C0D5B = sub_004C1D60(pUnit);
    }
    else if (nCommand == 0x35)
    {
        if (sub_00489870()) { sub_00478700_SendCommand(nCommand, gnGlobal_007C0D25, gnGlobal_007C0DE5, (unsigned short)nMode, 0x80000000); }
        else if (pUnit) { sub_00478700_SendCommand(0x35, gnGlobal_007C0D25, gnGlobal_007C0DE5, (unsigned short)nMode, STATLIST_UnitGetStatValue(pUnit, 0x48, 0)); }
        else { sub_00478700_SendCommand(0x35, gnGlobal_007C0D25, gnGlobal_007C0DE5, (unsigned short)nMode, 0); }
    }
    else { sub_00478700_SendCommand(nCommand, gnGlobal_007C0D25, gnGlobal_007C0DE5, (unsigned short)nMode, gnGlobal_007C0D7F); }

    D2_ASSERT(!gpDialog_007C0D67, 0x11B6);
    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);
    gpDialog_007C0D67 = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwGlobal_007C0D53 = GetTickCount() + 60000;
    gnGlobal_007C0D57 = 0;
    sub_004B8370(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0x0F, 0, 0, 1, 0, 0);
}

static int sub_004B1F80_ItemNeedsRepair(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType(pItem) == 4)
        return 0;
    if (!sub_0062E660(pItem))
        return 0;
    if (ITEMS_HasDurability(pItem))
    {
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability && STATLIST_UnitGetStatValue(pItem, 0x48, 0) < nMaxDurability)
            return 1;
    }
    if (ITEMS_CheckIfStackable(pItem) && STATLIST_UnitGetStatValue(pItem, 0x46, 0) < ITEMS_GetTotalMaxStack(pItem))
        return 1;
    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
        return 1;
    return 0;
}

static __forceinline D2UnitStrc* GetInteractNpc_Inline()
{
    if (!gnGlobal_007C0D29)
        return 0;
    return sub_00463990(gnGlobal_007C0D25, 1);
}

static int GetUnitIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

static int GetClassIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004B2AD0
int __fastcall sub_004B2AD0_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength)
{
    *pCost = 0;
    if (!pItem)
        return 0;
    if (ITEMS_GetItemType(pItem) == 4)
        return 0;
    int nStringId = 0;
    if (bService)
    {
        const unsigned int nClassId = pItem->dwClassId;
        if (!gnGlobal_007C0D29)
            return 0;
        if (!sub_00463990(gnGlobal_007C0D25, 1))
            return 0;
        D2UnitStrc* pNpc = sub_004B1620_GetInteractNpc();
        const unsigned int nNpcClass = !pNpc ? -1 : pNpc->dwClassId;
        DATATBLS_GetItemsTxtRecord(nClassId);
        switch (nNpcClass)
        {
        case 0xF4:
        case 0xF5:
        case 0x109:
            if (ITEMS_CheckItemFlag(pItem, 0x10, 0x999, ".\\UI\\npcmenu.cpp") == 1)
            {
                *(int*)pText = 0;
                return 1;
            }
            *pCost = QUESTRECORD_GetQuestState(gpQuestFlags_007C0D43, 4, 0) ? 0 : 100;
            nStringId = 0xD04;
            break;
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
        {
            if (sub_00489860())
            {
                if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x147B, ".\\UI\\npcmenu.cpp"))
                {
                    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xFB6));
                    sub_004521C0_PrefixLevelText(pText, 1);
                    return 1;
                }
                if (!sub_004B1F80_ItemNeedsRepair(pItem))
                    return 0;
                D2UnitStrc* pVendor = sub_004B1620_GetInteractNpc();
                *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, !pVendor ? -1 : pVendor->dwClassId, 3);
                nStringId = 0xD02;
                break;
            }
        }
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xF6:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
        case 0x202:
        {
            if (!sub_0062A130(pItem))
                return 0;
            D2UnitStrc* pVendor = sub_004B1620_GetInteractNpc();
            *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, !pVendor ? -1 : pVendor->dwClassId, 1);
            nStringId = 0xD03;
            break;
        }
        }
    }
    else
    {
        int nType = 0;
        if (gnGlobal_007C0DB0)
            nType = 2;
        D2UnitStrc* pVendor = GetInteractNpc_Inline();
        const int nVendorId = !pVendor ? -1 : pVendor->dwClassId;
        *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nVendorId, nType);
        nStringId = 0xD01;
    }
    if (!nStringId)
        return 0;
    const Unicode* pString = D2LANG_GetStringFromTblIndex(nStringId);
    if (sub_00526800(pString) + 10 > nMaxLength)
        return 0;
    sub_005267E0(pText, pString);
    Unicode wszCost[20];
    char szCost[20];
    wsprintfA(szCost, gszFormatD_006D57BC, *pCost);
    sub_00526F20_ToUnicode(wszCost, szCost, 19);
    sub_00526700(pText, wszCost);
    return 1;
}

// build: context sub_004B3870_HandleTradeClick
int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll)
{
    D2UnitStrc* pNpc = GetInteractNpc_Inline();
    if (!pNpc)
        return 0;
    const int nNpcClass = pNpc->dwClassId;
    if (bRepairAll)
    {
        switch (nNpcClass)
        {
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            break;
        default:
            return 0;
        }
        if (!sub_00489870())
            return 1;
        gnGlobal_007C0D7F = ITEMS_GetAllRepairCosts(0, pPlayer, nNpcClass, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, 0);
        gnGlobal_007C0D31 = 3;
        gbGlobal_007C0DE0 = 1;
        gnGlobal_007C0DE5 = 0;
        sub_00467A70_RefreshHoverUnit(0);
        gnGlobal_007C0D4B = nX;
        gnGlobal_007C0D4F = nY;
        sub_004B2650(1, nArg);
        return 1;
    }
    if (ITEMS_GetItemType(pItem) == 4)
        return 0;
    if (bCheckTick && GetTickCount() - gnGlobal_007C0DF1 < 0x1F4)
        return 0;
    gnGlobal_007C0D4B = nX;
    gnGlobal_007C0D4F = nY;
    if (nMode == 1)
    {
        switch (nNpcClass)
        {
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            if (sub_00489860())
            {
                if (!sub_004B1F80_ItemNeedsRepair(pItem))
                    return 0;
                gnGlobal_007C0D31 = 3;
                gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, 3);
                break;
            }
            gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, 1);
            if (!sub_0062A130(pItem))
                return 0;
            gnGlobal_007C0D31 = 2;
            break;
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
        case 0x202:
            gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, 1);
            if (!sub_0062A130(pItem))
                return 0;
            gnGlobal_007C0D31 = 2;
            break;
        case 0xF4:
        case 0xF5:
        case 0xF6:
        case 0x109:
        case 0x208:
            if (ITEMS_CheckItemFlag(pItem, 0x10, 0x999, ".\\UI\\npcmenu.cpp") == 1)
                return 0;
            gnGlobal_007C0D31 = 4;
            break;
        default:
            return 0;
        }
    }
    else
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
            return 0;
        gnGlobal_007C0D31 = 1;
        int nType = 0;
        if (gnGlobal_007C0DB0)
            nType = 2;
        gnGlobal_007C0D7F = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, sub_0044DCD0_GetDifficulty(), gpQuestFlags_007C0D43, nNpcClass, nType);
    }
    gbGlobal_007C0DE0 = 1;
    gnGlobal_007C0DE5 = GetUnitIdOrNone(pItem);
    gnGlobal_007C0DE1 = GetClassIdOrNone(pItem);
    sub_00467A70_RefreshHoverUnit(0);
    if ((gnGlobal_007C0D31 == 2 && bCheckTick) || (gnGlobal_007C0D31 == 1 && bCheckTick))
    {
        sub_004B2650(1, nArg);
        return 1;
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    gnGlobal_007C0C6B = 4;
    sub_004B2F50();
    return 1;
}

// 0x004B3240
void __fastcall sub_004B3240_StoreMessage(const D2StoredMsgPacketStrc* pPacket)
{
    if (!pPacket)
    {
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (!gaStoredMsgs_007C0C85[i].bUsed)
        {
            D2StoredMsgStrc* pEntry = &gaStoredMsgs_007C0C85[i];
            pEntry->wValue = pPacket->wValue;
            pEntry->dwValue = pPacket->dwValue;
            pEntry->bUsed = 1;
            return;
        }
    }
}

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
    sub_004B8370(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    return 1;
}

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
    sub_004B8370(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
}

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
    sub_004B8370(gpDialog_007C0D67, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D67, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    gnGlobal_007C0C6B = 10;
    gnGlobal_007C0D31 = 4;
    gnGlobal_007C0D96 = 0;
    sub_00478680_SendPacket5(0x34, gnGlobal_007C0D25);
    return 1;
}

void __stdcall sub_004B5890_OpenNpcPanel(int nStringIndex, int nEntryIndex)
{
    D2_ASSERT(!gpDialog_007C0D6F, 0x76F);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D6F = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B5810, sub_004B4010, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370(gpDialog_007C0D6F, 1);
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
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

void __stdcall sub_004B5AD0_OpenConfirmDialog(int nStringIndex)
{
    D2_ASSERT(!gpDialog_007C0D73, 0x7D7);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    sub_004B1C80_GetNpcDialogPos(&tCoords);

    gpDialog_007C0D73 = sub_004B7EB0_CreateDialog(tCoords.nX, tCoords.nY, sub_004B5850, sub_004B4070, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370(gpDialog_007C0D73, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D73, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0D73, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B4290, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0D73, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B5850, 1);
}

// 0x004B34A0
int __cdecl sub_004B34A0()
{
    if (gpDialog_007C0D5F || gpDialog_007C0D63 || gpDialog_007C0D67 || gpDialog_007C0D6B || gpDialog_007C0D6F
        || gpDialog_007C0D73 || gpDialog_007C0D77 || gpDialog_007C0D7B)
    {
        return 1;
    }

    return 0;
}

// 0x004B3510
void __fastcall sub_004B3510(D2NpcMonListPacketStrc* pPacket)
{
    for (int i = 0; i < 12; ++i)
    {
        if (pPacket->nMonIds[i] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            for (int j = 0; j < gnNpcEntryCount_0072554C; ++j)
            {
                if (gaNpcEntries_00726850[j].nId == pPacket->nMonIds[i])
                {
                    gaNpcEntries_00726850[j].bFlag = 1;
                }
            }
        }
    }
}

// 0x004B3C20
void __fastcall sub_004B3C20(int nValue)
{
    if (sub_00463DD0_GetPlayerUnit())
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
    }

    D2UnitStrc* pNpc = sub_00463990(nValue, 1);
    if (pNpc)
    {
        sub_004B3790_RemoveInventoryClientUnits(pNpc);
    }

    if (gnNpcSoundActive_007C0DB4)
    {
        sub_004BA840(gnNpcSoundHandle_007C0DB8);
    }

    gnNpcSoundActive_007C0DB4 = 0;
    gnNpcSoundHandle_007C0DB8 = 0;

    D2UnitStrc* pUnit = sub_00463990(nValue, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }

    sub_004786A0_SendDwords2(0x30, 1, nValue);
    sub_004A1730_ClearPanel();
    gnGlobal_007C0D29 = 0;
    sub_00455F20(8, 1, 0);

    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nClientFlags &= ~1;
        }

        sub_00480E70_SetUnitMode(pUnit, 1);
    }
}

// 0x004B3D40
int __cdecl sub_004B3D40_NpcMenuTradeB()
{
    if (gpDialog_007C0D6B)
    {
        sub_004B8020(gpDialog_007C0D6B);
        gpDialog_007C0D6B = 0;
    }

    D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0D25, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        sub_004B3C20(gnGlobal_007C0D25);
        return 1;
    }

    gnGlobal_007C0C6B = 3;
    gdwGlobal_007C0DB0 = 1;
    sub_00455F20(0xC, 0, 0);
    sub_004786D0_SendDwords3(0x38, 2, gnGlobal_007C0D25, 0);
    gpUnit_007C0DD4 = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B3E10
void __fastcall sub_004B3E10_RefreshNpcEntries(D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return;

    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
    {
        if (gaNpcEntries_00726850[i].bSelected == 1)
        {
            gaNpcEntries_00726850[i].bSelected = 0;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0xFAB);
            sub_004B1680(&gaNpcEntries_00726850[i]);
        }
        gaNpcEntries_00726850[i].bRefreshed = 1;
    }

    if (!(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        return;

    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
    gnGlobal_007C0D29 = 0;
}

// 0x004B4380
void __cdecl sub_004B4380_UpdateNpcInteract()
{
    D2UnitStrc* pNpc;
    if (sub_00463DF0() || (NPC_GET_INTERACT_UNIT() && (pNpc = NPC_GET_INTERACT_UNIT()) != 0 && pNpc->dwAnimMode == 12) || !NPC_GET_INTERACT_UNIT())
    {
        sub_004B2110_FreeResources();
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }

    if (gpDialog_007C0D6F)
    {
        sub_004B8100(gpDialog_007C0D6F);
        return;
    }

    if (gpDialog_007C0D73)
    {
        sub_004B8100(gpDialog_007C0D73);
        return;
    }

    if (gpDialog_007C0D6B)
    {
        sub_0044DA40();
        sub_004B8100(gpDialog_007C0D6B);
        return;
    }

    if (gpDialog_007C0D63)
    {
        sub_004B8100(gpDialog_007C0D63);
        return;
    }

    if (gpDialog_007C0D67)
    {
        D2UnitStrc* pInteract;
        if (sub_004B1620_GetInteractNpc() && (pInteract = sub_004B1620_GetInteractNpc()) != 0 && pInteract->dwClassId == 0x202 && !gnGlobal_007C0DBC)
        {
            if (!gnGlobal_007C0DC0)
            {
                gnGlobal_007C0DC0 = 1;
                gdwGlobal_007C0DC4 = (ITEMS_RollLimitedRandomNumber(&sub_00463DD0_GetPlayerUnit()->pSeed, 30) + 120) * 1000 + GetTickCount();
            }

            if (gdwGlobal_007C0DC4 > GetTickCount())
            {
                gnGlobal_007C0DBC = 1;
                sub_004B9A00(0x11D0, 0, 0, 0, 0);
            }
        }

        if (sub_0044DB30() && gnGlobal_007C0D57 && gnGlobal_007C0D57 < GetTickCount())
        {
            sub_004B2900_CloseDialog();
            return;
        }

        if (gdwGlobal_007C0D53 < GetTickCount())
        {
            sub_00477EE0_SendPacket69();
            sub_0044B880_SetValue(0);
            sub_0044C860_SetValue(1);
            sub_0044D520();
        }
        return;
    }

    if (gpDialog_007C0D5F)
    {
        if (!INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory) && !sub_004680A0())
        {
            sub_004B8100(gpDialog_007C0D5F);
            return;
        }

        gnGlobal_007C0C6B = 3;
        sub_0048A630_EnterState1();
        gnGlobal_007C0DE9 = GetTickCount();
        gnGlobal_007C0DED += 1;
        sub_004B8020(gpDialog_007C0D5F);
        gpDialog_007C0D5F = 0;
        return;
    }

    if (gpDialog_007C0D77)
    {
        sub_004B8100(gpDialog_007C0D77);
        return;
    }

    if (gpDialog_007C0D7B)
    {
        sub_004B8100(gpDialog_007C0D7B);
    }
}

// 0x004B5C20
int __cdecl sub_004B5C20_ClosePanel77()
{
    if (gpDialog_007C0D77)
    {
        sub_004B8020(gpDialog_007C0D77);
        delete gpTradeObj_007C0D83;
        gpTradeObj_007C0D83 = 0;
        gpDialog_007C0D77 = 0;
    }

    sub_004B4830_Rebuild();
    return 1;
}

// 0x004B6410
int __cdecl sub_004B6410_InitHandler()
{
    gnGlobal_00726DF9 = 3;
    gpfnGlobal_00726E0B = sub_004B5C60_Handler;
    gwGlobal_00726DFF = 0xD45;
    return 1;
}

static __declspec(noinline) void sub_004B1640_SetNpcInteract(D2UnitStrc* pRecord)
{
    if (pRecord)
    {
        gnGlobal_007C0D29 = 1;
        gnGlobal_007C0D25 = pRecord->dwUnitId;
        gdwGlobal_007C0D2D = pRecord->dwClassId;
    }
    else
    {
        gnGlobal_007C0D29 = 0;
    }
}

void __fastcall sub_004B1980_AddUsedString(unsigned short wStringId)
{
    if (gtStringList_007C0D9A.wCount < 9)
    {
        gtStringList_007C0D9A.awStrings[gtStringList_007C0D9A.wCount] = wStringId;
        gtStringList_007C0D9A.wCount++;
    }
}

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

static __declspec(noinline) bool sub_004B1A10_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

static __declspec(noinline) int sub_004B2E30_FindNpcIndex(D2UnitStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->dwClassId;
    for (int i = 0; i < gnNpcIndexCount_00725A74; ++i)
    {
        if (gaNpcIndex_00726C48[i].nId == nId)
            return i;
    }
    return 0;
}

static int __stdcall sub_004B6440_ToggleNpcHandler(int bAdd, int nIndex)
{
    if (!sub_00408F20_HasExpansionMpq() || !sub_0044DCC0())
    {
        return 0;
    }

    if (bAdd)
    {
        const int nCount = gaNpcIndex_00726C48[nIndex].nCount;
        for (int i = 0; i < nCount; ++i)
        {
            if (gaNpcIndex_00726C48[nIndex].apfHandlers[i] == sub_004B1DD0_OpenTimedDialog62)
            {
                return 1;
            }
        }

        for (int i = 0; i < nCount; ++i)
        {
            if (gaNpcIndex_00726C48[nIndex].apfHandlers[i] == sub_004B5C60_Handler)
            {
                for (int j = nCount - 1; j >= i; --j)
                {
                    gaNpcIndex_00726C48[nIndex].apfHandlers[j + 1] = gaNpcIndex_00726C48[nIndex].apfHandlers[j];
                    gaNpcIndex_00726C48[nIndex].awIds[j + 1] = gaNpcIndex_00726C48[nIndex].awIds[j];
                }
                ++gaNpcIndex_00726C48[nIndex].nCount;
                gaNpcIndex_00726C48[nIndex].apfHandlers[i] = sub_004B1DD0_OpenTimedDialog62;
                gaNpcIndex_00726C48[nIndex].awIds[i] = 0x1507;
                return 1;
            }
        }

        const int nPos = nCount - 1;
        for (int j = nCount - 1; j >= nPos; --j)
        {
            gaNpcIndex_00726C48[nIndex].apfHandlers[j + 1] = gaNpcIndex_00726C48[nIndex].apfHandlers[j];
            gaNpcIndex_00726C48[nIndex].awIds[j + 1] = gaNpcIndex_00726C48[nIndex].awIds[j];
        }
        ++gaNpcIndex_00726C48[nIndex].nCount;
        gaNpcIndex_00726C48[nIndex].apfHandlers[nPos] = sub_004B1DD0_OpenTimedDialog62;
        gaNpcIndex_00726C48[nIndex].awIds[nPos] = 0x1507;
        return 1;
    }

    const int nCount = gaNpcIndex_00726C48[nIndex].nCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (gaNpcIndex_00726C48[nIndex].apfHandlers[i] == sub_004B1DD0_OpenTimedDialog62)
        {
            for (int j = i; j < gaNpcIndex_00726C48[nIndex].nCount - 1; ++j)
            {
                gaNpcIndex_00726C48[nIndex].apfHandlers[j] = gaNpcIndex_00726C48[nIndex].apfHandlers[j + 1];
                gaNpcIndex_00726C48[nIndex].awIds[j] = gaNpcIndex_00726C48[nIndex].awIds[j + 1];
            }
            --gaNpcIndex_00726C48[nIndex].nCount;
            return 1;
        }
    }
    return 1;
}

static void __stdcall sub_004B66B0_OpenNpcInteract(D2UnitStrc* pUnit, int bReopen)
{
    sub_0044DA40();
    if (!pUnit)
    {
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gnGlobal_007C0C6B = 1;
    gnGlobal_007C0D31 = 0;
    gnGlobal_007C0C73 = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), 0xE, 0);
    sub_00456300_CloseUIVars(0, 0);

    if (!bReopen)
    {
        if (pUnit == (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        {
            return;
        }
        if (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0)
        {
            sub_004B3DE0_CloseNpc();
            return;
        }
    }
    else
    {
        gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
    }

    gnGlobal_007C0D29 = 1;
    gnGlobal_007C0D25 = pUnit->dwUnitId;
    gdwGlobal_007C0D2D = pUnit->dwClassId;
    pUnit->dwFlags &= ~2;

    const int nNpcId = pUnit->dwClassId;
    sub_004B19A0_RunNpcQuestHandlers(nNpcId, gpQuestFlags_007C0D43, gaNpcHandlers_007253E0, gnHandlerCount_007253DC);

    if (gnNpcSoundActive_007C0DB4)
    {
        if (gnNpcSoundHandle_007C0DB8)
        {
            sub_004BA840(gnNpcSoundHandle_007C0DB8);
            gnNpcSoundHandle_007C0DB8 = 0;
        }
        gnNpcSoundActive_007C0DB4 = 0;
    }

    switch (pUnit->dwClassId)
    {
    case 0x96:
        if (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), 0xC, 0) >= 8)
        {
            sub_004B6410_InitHandler();
        }
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0xB);
        break;

    case 0xC6:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 8);
        break;

    case 0xFC:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0x18);
        break;

    case 0x16F:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0x15);
        break;

    case 0x203:
        sub_004B6440_ToggleNpcHandler(gwGlobal_00725494 != 0xFFFF, 0x2B);
        break;
    }

    if (!sub_00455F20(8, 0, 0))
    {
        gnGlobal_007C0C6B = 0;
        pUnit->dwFlags |= 2;
        sub_004786A0_SendDwords2(0x30, 1, pUnit->dwUnitId);
        gnGlobal_007C0D29 = 0;
        sub_004B3830_ClearNpcInventoryAndSound(pUnit->dwUnitId);
        return;
    }

    sub_004B4830_Rebuild();
    if (bReopen)
    {
        return;
    }

    int nType = 0;
    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
    {
        if (gaNpcEntries_00726850[i].nId == nNpcId)
        {
            if (gaNpcEntries_00726850[i].bFlag == 1)
            {
                gaNpcEntries_00726850[i].bFlag = 0;
                nType = 2;
            }
            if (gaNpcEntries_00726850[i].bRefreshed != 1)
            {
                return;
            }
            gaNpcEntries_00726850[i].bRefreshed = 0;
            break;
        }
    }

    const int nSound = sub_004E0590_PickNpcSound(pUnit, nType);
    if (!nSound)
    {
        return;
    }

    sub_004CB190_ReleaseSkillSfx(pUnit);
    gnNpcSoundHandle_007C0DB8 = sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
    if (nType == 2)
    {
        sub_004785B0_SendPacket3(0x4D, nNpcId);
        gnNpcSoundActive_007C0DB4 = 1;
        return;
    }
    gnNpcSoundHandle_007C0DB8 = 0;
}

// 0x004B6980
void __fastcall sub_004B6980_SetNpcMenuState(unsigned short wValue, int nValue)
{
    gwGlobal_00725494 = wValue;
    gnGlobal_007C0DD0 = nValue;
    if (wValue == 0xFFFF)
    {
        sub_004B6440_ToggleNpcHandler(0, 0xB);
        sub_004B6440_ToggleNpcHandler(0, 8);
        sub_004B6440_ToggleNpcHandler(0, 0x18);
        sub_004B6440_ToggleNpcHandler(0, 0x15);
        sub_004B6440_ToggleNpcHandler(0, 0x2B);
    }
}

// 0x004B6A30
int __fastcall sub_004B6A30_NpcTextCallback(void* pContext, int nArg, int nValue)
{
    gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(gwGlobal_007C0C77);
    if (gwGlobal_007C0C77 == 0x251)
    {
        sub_004B9A00(0xF1, 0, 0, 0, 0);
    }
    if (gwGlobal_007C0C77 == 0x21A)
    {
        sub_004B9A00(0xED, 0, 0, 0, 0);
    }

    if (gbGlobal_007C0C69 == 1)
    {
        if (gwGlobal_007C0C79 != 0xFFFF && (gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0))
        {
            gwGlobal_007C0C7B = gwGlobal_007C0C79;
            sub_004A10E0(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0, gwGlobal_007C0C7B, 1);
            sub_004B1980_AddUsedString(gwGlobal_007C0C7B);
            sub_0049E7E0_SetTextCallback(sub_004B6A30_NpcTextCallback, 0);
            gwGlobal_007C0C77 = gwGlobal_007C0C7B;
            sub_004786A0_SendDwords2(0x31, gnGlobal_007C0D25, gwGlobal_007C0C7B);
            gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(gwGlobal_007C0C7B);
            return 1;
        }

        gbGlobal_007C0C69 = 0;
        sub_0049E7E0_SetTextCallback(0, 0);
        const int nIndex = sub_004B2E30_FindNpcIndex(gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0);
        if ((!nArg || !nValue) && !sub_004B1A10_IsSpecialNpc(gdwGlobal_007C0D2D) && nIndex >= 0 && sub_004B1620_GetInteractNpc()
            && nIndex < gnNpcIndexCount_00725A74 && gaNpcIndex_00726C48[nIndex].bEnabled)
        {
            gnGlobal_007C0C6B = 1;
            if (sub_004B1620_GetInteractNpc())
            {
                sub_004B66B0_OpenNpcInteract(sub_004B1620_GetInteractNpc(), 1);
                return 1;
            }
            sub_004B3DE0_CloseNpc();
            return 0;
        }

        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return 0;
    }

    gbGlobal_007C0C69 = 0;
    sub_0049E7E0_SetTextCallback(0, pContext);
    gwGlobal_007C0C77 = 0xFFFF;
    sub_004B4DB0_OpenGreetingDialog();
    return 0;
}

void __fastcall sub_004B6DD0_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg)
{
    if (nUnitType == 6)
    {
        QUESTRECORD_CopyBufferToRecord(gpQuestFlags_007C0D43, pBuffer, 0x60, 0);
        return;
    }

    D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
    if (!pUnit)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
        sub_004786A0_SendDwords2(0x30, nArg, nUnitId);
        sub_004B3830_ClearNpcInventoryAndSound(nUnitId);
        return;
    }

    sub_00464990(sub_004B2390_CheckMonStatsFlag);
    pUnit->dwFlags |= 2;
    QUESTRECORD_CopyBufferToRecord(gpQuestFlags_007C0D43, pBuffer, 0x60, 0);
    sub_004B2250_ResetHandlers();
    sub_004786A0_SendDwords2(0x2F, nUnitType, nUnitId);
    sub_0044DA40();

    if (gaGlobal_007C0C68[0])
    {
        gbGlobal_007C0C69 = 1;
        sub_004B1640_SetNpcInteract(pUnit);
        pUnit->dwFlags &= ~2;
        return;
    }

    D2TextHeaderStrc* pTextHeader = sub_0049F900();
    D2_ASSERT(pTextHeader, 0x1060);

    const unsigned short wString = sub_00661400(pTextHeader, 0);
    const int nClassId = pUnit->dwClassId;
    if (sub_00457490_CheckMonStatsFlag(nClassId, 9) && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B
        && nClassId != 0x20F)
    {
        sub_00464420_TurnTowardPlayer(pUnit);
    }

    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        gnGlobal_007C0D29 = 1;
        gnGlobal_007C0D25 = pUnit->dwUnitId;
        gdwGlobal_007C0D2D = pUnit->dwClassId;
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
        return;
    }

    gtStringList_007C0D9A.wCount = 0;
    if (wString != 0xFFFF)
    {
        sub_00456300_CloseUIVars(0, 0);
        gwGlobal_007C0C77 = wString;
        sub_004A10E0(pUnit, wString, 1);
        sub_004B1980_AddUsedString(wString);
        gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(wString);
        sub_004786A0_SendDwords2(0x31, pUnit->dwUnitId, wString);
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B6A30_NpcTextCallback, 0);
        sub_004B1640_SetNpcInteract(pUnit);
    }
    else
    {
        const unsigned short wString2 = sub_00661440(pTextHeader, 0);
        if (pUnit->dwClassId != 0x20F)
        {
            sub_004644E0_PlayerFaceUnit(pUnit);
        }
        if (pUnit->pDynamicPath)
        {
            D2Common_10153(pUnit->pDynamicPath);
        }

        if (wString2 != 0xFFFF)
        {
            sub_00487990_ResetHover();
            sub_00456300_CloseUIVars(0, 0);
            gwGlobal_007C0C77 = wString2;
            gwGlobal_007C0C79 = sub_004B1830_GetFreeStringId(wString2);
            sub_004B4FD0(pUnit);
        }
        else
        {
            const int nClass = pUnit->dwClassId;
            if (sub_00457490_CheckMonStatsFlag(nClass, 9))
            {
                if (sub_004B1A10_IsSpecialNpc(nClass))
                {
                    gnGlobal_007C0D29 = 1;
                    gnGlobal_007C0D25 = pUnit->dwUnitId;
                    gdwGlobal_007C0D2D = pUnit->dwClassId;
                    sub_004B3C20(gnGlobal_007C0D25);
                    sub_00455F20(8, 1, 0);
                    return;
                }
                sub_00487990_ResetHover();
                sub_00456300_CloseUIVars(0, 0);
                sub_004B66B0_OpenNpcInteract(pUnit, 0);
            }
            else
            {
                sub_004B3C20(gnGlobal_007C0D25);
                sub_00455F20(8, 1, 0);
            }
        }
    }
    gdwGlobal_007C0DB0 = 0;
}

struct D2TextHeaderStrc;

#include "gen/data/Source/D2Client/UI/npcmenu_004B2650.inc"
