#include "D2ItemTypes.h"
#include "D2StatIds.h"
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

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

unsigned short __fastcall NPCMENU_GetFreeStringId(unsigned short wStringId); // 0x004B1830

int __cdecl sub_004B5BC0_SelectNpcEntry(); // 0x004B5BC0

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

int __fastcall sub_004B8580(D2ClientDialogStrc* pDialog); // 0x004B8580

D2TextHeaderStrc* __cdecl DLIGHTMAP_GetTextHeader(); // 0x0049F900

extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall NPCMENU_NpcMessageCallback(void* pContext, int nArg, int nValue); // 0x004B18C0

char gbNpcMessageShown; // 0x007C0C69

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

void __fastcall VIEW_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

const Unicode* __fastcall TEXT_GetTextString(unsigned short nStringId); // 0x0049F910

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0

void __fastcall sub_004B8370(void* pPanel, int nValue); // 0x004B8370

void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8); // 0x004B85F0

int __cdecl sub_004B1DC0(); // 0x004B1DC0

int __cdecl NPCMENU_CloseSubMenuToMain(); // 0x004B5810

int __cdecl sub_004B5850(); // 0x004B5850

extern D2ViewStrc* gpClientView; // 0x007A0640

extern int gnHireMercIndex; // 0x007C0C60

extern int gnHireMercNpcId; // 0x007C0C64

extern D2NpcMenuSlotStrc gaSlots_007C0C85[]; // 0x007C0C85

extern D2ClientDialogStrc* gpNpcWaitDialog; // 0x007C0D67

struct D2NpcMonListPacketStrc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short nMonIds[12];
};

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall NPCMENU_RemoveInventoryClientUnits(D2UnitStrc* pUnit); // 0x004B3790

void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840

void __cdecl CUNIT_ClearTextPanel();                                                                     // 0x004A1730

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70

void __cdecl NPCMENU_BuildNpcMenu();                                                                        // 0x004B4830

int __cdecl sub_004B5C60_Handler();                                                                         // 0x004B5C60

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern D2ClientDialogStrc* gpNpcSubMenuDialog;                                                               // 0x007C0D63

extern "C" int gnNpcSoundActive;                                                                   // 0x007C0DB4

extern "C" int gnNpcSoundHandle;                                                                   // 0x007C0DB8

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

void __cdecl GAME_ResetMouseState();                                                                                // 0x0044DA40

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490

void __fastcall CUNIT_TurnTowardPlayer(D2UnitStrc* pUnit);                                                 // 0x00464420

void __fastcall CUNIT_PlayerFaceUnit(D2UnitStrc* pUnit);                                             // 0x004644E0

void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback);                                                           // 0x00464990

void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0

void __cdecl INV_ResetHover();                                                                     // 0x00487990

D2UnitStrc* __cdecl NPCMENU_GetInteractNpc();                                                          // 0x004B1620

int __cdecl NPCMENU_ResurrectMercWait();                                                               // 0x004B1DD0

void __cdecl NPCMENU_ResetHandlers();                                                                  // 0x004B2250

void __fastcall NPCMENU_ClearInteractOverlay(D2UnitStrc* pUnit);                                          // 0x004B2390

extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __fastcall NPCMENU_EndNpcInteraction(int nValue);                                                                   // 0x004B3C20

void __cdecl sub_004B3DE0_CloseNpc();                                                                       // 0x004B3DE0

void __cdecl NPCMENU_OpenGreetingDialog();                                                             // 0x004B4DB0

void __stdcall sub_004B4FD0(D2UnitStrc* pUnit);

int __cdecl NPCMENU_InitHireHandler();                                                                     // 0x004B6410

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit);                                            // 0x004CB190

int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

short __stdcall TEXT_GetStringIdOfMenuType1Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661440

extern D2NpcQuestHandlerStrc gaNpcHandlers[];                                                      // 0x007253E0

extern D2NpcIndexStrc gaNpcIndex[];                                                                // 0x00726C48

extern char gabNpcMenuState[];                                                                            // 0x007C0C68

extern D2ClientStringListStrc gtStringList;                                                        // 0x007C0D9A

extern int gbGambleShop;                                                                              // 0x007C0DB0

extern int gnNpcMenuValue;                                                                               // 0x007C0DD0

union D2SeedStrc;

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3); // 0x004786D0

void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry);

extern D2UnitStrc* gpNpcPlayerUnit; // 0x007C0DD4

extern unsigned short gwGlobal_007C0DD8; // 0x007C0DD8

void __fastcall GAME_SetExitApplication(int nValue); // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __cdecl GAME_RequestExit(); // 0x0044D520

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

int __cdecl CURSOR_GetCursorItem(); // 0x004680A0

void __cdecl INV_SendLeaveGame(); // 0x00477EE0

void __cdecl INV_EnterNpcMenuState(); // 0x0048A630

void __cdecl NPCMENU_FreeDialogs(); // 0x004B2110

void __cdecl NPCMENU_CloseWaitDialog(); // 0x004B2900

void __fastcall sub_004B8100(void* pObj);

int gbWaitSoundPlayed; // 0x007C0DBC

int gbWaitSoundScheduled; // 0x007C0DC0

unsigned long gdwWaitSoundTick; // 0x007C0DC4

struct D2BitBufferStrc;

struct D2GameStrc;

struct D2StoredMsgPacketStrc;

struct D2StoredMsgStrc;


void __cdecl sub_00487C20(); // 0x00487C20

void __cdecl sub_00487C60(); // 0x00487C60

int __cdecl VIEW_SetNpcMenuMode(); // 0x00487CA0

int __cdecl sub_00489870(); // 0x00489870

void __cdecl sub_0048A630(); // 0x0048A630

void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700

int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

extern int gnGlobal_007C0D3F; // 0x007C0D3F

extern int gnGlobal_007C0D5B; // 0x007C0D5B

extern int gnGlobal_007C0DB0; // 0x007C0DB0

extern D2UnitStrc* gpPlayer_007C0DD4; // 0x007C0DD4

extern unsigned long gdwGlobal_007C0DE9; // 0x007C0DE9

extern unsigned long gdwGlobal_007C0DF1; // 0x007C0DF1

extern unsigned long gdwTradeThrottleTick; // 0x007C0E48

static int NPCMENU_GetNpcDialogPos(D2CoordStrc* pCoords); // 0x004B1C80

extern "C" const char gszFormatD[]; // 0x006D57BC

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

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
int __fastcall NPCMENU_NpcMessageCallback(void* pContext, int nArg, int nValue)
{
    if (gbNpcMessageShown == 1)
    {
// build: symbol ?gwNpcLastString@* 0x007C0C7B
        const unsigned short wStringId = NPCMENU_GetFreeStringId(gwNpcLastString);
// build: symbol ?gnInteractNpcId@* 0x007C0D25
// build: symbol ?gbNpcInteracting@* 0x007C0D29
        if (wStringId != 0xFFFF && gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
        {
            gwNpcLastString = wStringId;
            D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
            sub_004A10E0(pNpc, wStringId, 0);
            TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
            return 1;
        }
    }

    gbNpcMessageShown = 0;
    TEXT_SetTextCallback(0, pContext);
    sub_004B5BC0_SelectNpcEntry();
    return 1;
}

// 0x004B1A80
int __cdecl NPCMENU_OnSelectMessage()
{
// build: symbol ?gpNpcMessageDialog@* 0x007C0D6F
    const int nSelected = sub_004B8580(gpNpcMessageDialog);
// build: symbol ?gnNpcEntryIndex@* 0x007C0C81
    const int nFirstLine = gaNpcEntries[gnNpcEntryIndex].bFlag14 ? 2 : 3;
    if (nSelected < nFirstLine)
    {
        return 0;
    }

    if (!gbNpcInteracting || !CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        return 0;
    }

    const int nNodeId = sub_004B8580(gpNpcMessageDialog) - nFirstLine;
    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    D2_ASSERT(pTextHeader, 0x710);
    const unsigned short wStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, nNodeId);
    gwNpcLastString = wStringId;
    D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    sub_004A10E0(pNpc, wStringId, 0);
    gbNpcMessageShown = 1;
    TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
    DIALOG_DestroyDialog(gpNpcMessageDialog);
    gpNpcMessageDialog = 0;
    return 1;
}

// 0x004B1B80
int __cdecl NPCMENU_PlayIntroMessage()
{
    if (gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
        sub_004A10E0(pNpc, 0xFE, 0);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
        DIALOG_DestroyDialog(gpNpcMessageDialog);
        gpNpcMessageDialog = 0;
    }
    return 1;
}

// 0x004B1C00
int __cdecl NPCMENU_PlayGossipMessage()
{
    if (gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
        sub_004A10E0(pNpc, 0x152, 0);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
        DIALOG_DestroyDialog(gpNpcMessageDialog);
        gpNpcMessageDialog = 0;
    }
    return 1;
}

static inline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
}

// 0x004B6410
int __cdecl NPCMENU_InitHireHandler()
{
    gnGlobal_00726DF9 = 3;
    gpfnGlobal_00726E0B = sub_004B5C60_Handler;
    gwGlobal_00726DFF = 0xD45;
    return 1;
}

static inline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x004B1C80
static int NPCMENU_GetNpcDialogPos(D2CoordStrc* pCoords)
{
    if (NPC_GetInteractUnit_Inline())
    {
        UNITS_GetClientCoords(NPC_GetInteractUnit_Inline(), pCoords);

        tagRECT tView;
        sub_00476070_GetViewRect(gpClientView, &tView.left, &tView.top, &tView.right, &tView.bottom);

        D2CoordStrc tOffset;
        VIEW_GetViewOffset(gpClientView, &tOffset.nX, &tOffset.nY);

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

// build: symbol ?NPCMENU_ItemNeedsRepair@* 0x004B1F80
static int NPCMENU_ItemNeedsRepair(D2UnitStrc* pItem)
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

static inline D2UnitStrc* GetInteractNpc_Inline()
{
    if (!gbNpcInteracting)
        return 0;
    return CUNIT_FindClientUnit(gnInteractNpcId, 1);
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
// 0x004B2650
void __stdcall NPCMENU_SendTradeRequest(int bAlternate, int nFlags)
{
// build: symbol ?gbTradeClickPending@* 0x007C0DE0
    if (!gbTradeClickPending)
    {
        sub_00487C20();
        return;
    }

    char nCommand;
// build: symbol ?gnNpcTradeMode@* 0x007C0D31
    switch (gnNpcTradeMode)
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
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
        gnNpcMenuState = 3;
        sub_00487C20();
        return;
    }

    unsigned int nMode = 0;
// build: symbol ?gbNpcActionPending@* 0x007C0D96
    gbNpcActionPending = 0;
    D2UnitStrc* pUnit = 0;
    if (sub_00489870())
    {
        if (GetTickCount() - gdwTradeThrottleTick < 2000)
        {
            sub_00487C20();
            return;
        }
        gdwTradeThrottleTick = GetTickCount();
    }
    else
    {
// build: symbol ?gnTradeItemUnitId@* 0x007C0DE5
        pUnit = CUNIT_FindClientUnit(gnTradeItemUnitId, 4);
        if (pUnit)
        {
            nMode = (unsigned short)pUnit->dwAnimMode;
            if (gnNpcTradeMode == 2)
            {
                D2InventoryStrc* const pInventory = gpPlayer_007C0DD4->pInventory;
                gnGlobal_007C0D3F = INVENTORY_GetCursorItem(pInventory) == pUnit;
            }
        }
        else
        {
            gnNpcMenuState = 3;
            sub_0048A630();
            gdwGlobal_007C0DE9 = GetTickCount();
// build: symbol ?gnTradeRequestFailCount@* 0x007C0DED
            ++gnTradeRequestFailCount;
            gbTradeClickPending = 0;
            return;
        }
    }

    if (bAlternate)
    {
        VIEW_SetNpcMenuMode();
    }
    else
    {
        sub_00487C60();
    }

    gnNpcMenuState = 5;
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
// build: symbol ?gnNpcTransactionCost@* 0x007C0D7F
        sub_00478700_SendCommand(0x32, gnInteractNpcId, gnTradeItemUnitId, nMode, gnNpcTransactionCost);
        gnGlobal_007C0D5B = ITEM_GetDropSound(pUnit);
    }
    else if (nCommand == 0x35)
    {
        if (sub_00489870()) { sub_00478700_SendCommand(nCommand, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, 0x80000000); }
        else if (pUnit) { sub_00478700_SendCommand(0x35, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, STATLIST_UnitGetStatValue(pUnit, STAT_DURABILITY, 0)); }
        else { sub_00478700_SendCommand(0x35, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, 0); }
    }
    else { sub_00478700_SendCommand(nCommand, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, gnNpcTransactionCost); }

    D2_ASSERT(!gpNpcWaitDialog, 0x11B6);
    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);
    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
// build: symbol ?gdwNpcRequestTimeout@* 0x007C0D53
    gdwNpcRequestTimeout = GetTickCount() + 60000;
// build: symbol ?gdwNpcTransactionTick@* 0x007C0D57
    gdwNpcTransactionTick = 0;
    sub_004B8370(gpNpcWaitDialog, 0);
    sub_004B85F0_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0x0F, 0, 0, 1, 0, 0);
}

int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

// 0x004B1F60
static inline int MONSTER_IsItemIdentified(D2UnitStrc* pItem)
{
    return ITEMS_CheckItemFlag(pItem, 0x10, 0x999, ".\\UI\\npcmenu.cpp");
}

// 0x004B2AD0
int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength)
{
    *pCost = 0;
    if (!pItem)
        return 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        return 0;
    int nStringId = 0;
    if (bService)
    {
        const unsigned int nClassId = pItem->dwClassId;
        if (!gbNpcInteracting)
            return 0;
        if (!CUNIT_FindClientUnit(gnInteractNpcId, 1))
            return 0;
        D2UnitStrc* pNpc = NPCMENU_GetInteractNpc();
        const unsigned int nNpcClass = !pNpc ? -1 : pNpc->dwClassId;
        DATATBLS_GetItemsTxtRecord(nClassId);
        switch (nNpcClass)
        {
        case 0xF4:
        case 0xF5:
        case 0x109:
            if (MONSTER_IsItemIdentified(pItem) == 1)
            {
                *(int*)pText = 0;
                return 1;
            }
// build: symbol ?gpPlayerQuestFlags@* 0x007C0D43
            *pCost = QUESTRECORD_GetQuestState(gpPlayerQuestFlags, 4, 0) ? 0 : 100;
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
                    INV_PrefixColorCode(pText, 1);
                    return 1;
                }
                if (!NPCMENU_ItemNeedsRepair(pItem))
                    return 0;
                D2UnitStrc* pVendor = NPCMENU_GetInteractNpc();
                *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, !pVendor ? -1 : pVendor->dwClassId, 3);
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
            D2UnitStrc* pVendor = NPCMENU_GetInteractNpc();
            *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, !pVendor ? -1 : pVendor->dwClassId, 1);
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
        *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, nVendorId, nType);
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
    wsprintfA(szCost, gszFormatD, *pCost);
    sub_00526F20_ToUnicode(wszCost, szCost, 19);
    sub_00526700(pText, wszCost);
    return 1;
}

int __cdecl NPCMENU_ResurrectMercWait()
{
// build: symbol ?gpNpcMainMenuDialog@* 0x007C0D6B
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    sub_00478680_SendPacket5(0x62, gnInteractNpcId);
    gnNpcMenuState = 10;

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwNpcRequestTimeout = GetTickCount() + 60000;
    gdwNpcTransactionTick = 0;
    sub_004B8370(gpNpcWaitDialog, 0);
    sub_004B85F0_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    return 1;
}

void __cdecl NPCMENU_HireMercWait()
{
    MSG_SendTwoDwords(0x36, gnHireMercNpcId, gaSlots_007C0C85[gnHireMercIndex].wId);

// build: symbol ?gpNpcHireDialog@* 0x007C0D77
    if (gpNpcHireDialog)
    {
        DIALOG_DestroyDialog(gpNpcHireDialog);
// build: symbol ?gpNpcTradeObj@* 0x007C0D83
        delete gpNpcTradeObj;
        gpNpcTradeObj = 0;
        gpNpcHireDialog = 0;
    }

    gnNpcMenuState = 10;

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwNpcRequestTimeout = GetTickCount() + 60000;
    gdwNpcTransactionTick = 0;
    sub_004B8370(gpNpcWaitDialog, 0);
    sub_004B85F0_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
}

int __cdecl NPCMENU_IdentifyItemsWait()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    D2_ASSERT(!gpNpcWaitDialog, 0xA2D);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwNpcRequestTimeout = GetTickCount() + 60000;
    gdwNpcTransactionTick = 0;
    sub_004B8370(gpNpcWaitDialog, 0);
    sub_004B85F0_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    gnNpcMenuState = 10;
    gnNpcTradeMode = 4;
    gbNpcActionPending = 0;
    sub_00478680_SendPacket5(0x34, gnInteractNpcId);
    return 1;
}

void __stdcall NPCMENU_OpenNpcPanel(int nStringIndex, int nEntryIndex)
{
    D2_ASSERT(!gpNpcMessageDialog, 0x76F);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcMessageDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, NPCMENU_CloseSubMenuToMain, sub_004B4010, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370(gpNpcMessageDialog, 1);
    sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);

    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    if (!pTextHeader)
    {
        sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, NPCMENU_CloseSubMenuToMain, 1);
        return;
    }

    const int nCount = TEXT_GetMenuType2NodeCount(pTextHeader);
    gnNpcEntryIndex = nEntryIndex;
    if (!gaNpcEntries[nEntryIndex].bFlag14)
    {
        sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD47), 0xF, 0, 0, 1, sub_004B41E0, 1);
    }

    sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD43), 0xF, 0, 0, 1, sub_004B41C0, 1);

    for (int i = 0; i < nCount; ++i)
    {
        const unsigned short nStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, i);
        sub_004B85F0_AddTextLine(gpNpcMessageDialog, TEXT_GetTextString(nStringId), 0xF, 0, 0, 1, sub_004B1A80, 1);
    }

// build: symbol ?gnInteractNpcClassId@* 0x007C0D2D
    if (gnInteractNpcClassId == 0xC9)
    {
        sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD40), 0xF, 0, 0, 1, sub_004B1B80, 1);
    }

    if (gnInteractNpcClassId == 0x109 || gnInteractNpcClassId == 0xF4 || gnInteractNpcClassId == 0xF5 || gnInteractNpcClassId == 0x208 || gnInteractNpcClassId == 0xF6)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->pInventory)
        {
            for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pItem);
                if (pCheck && ITEMS_GetBaseCode(pCheck) == 0x20786F62)
                {
                    sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0x8B7), 0xF, 0, 0, 1, sub_004B1C00, 1);
                    break;
                }
            }
        }
    }

    sub_004B85F0_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, NPCMENU_CloseSubMenuToMain, 1);
}

void __stdcall NPCMENU_OpenConfirmDialog(int nStringIndex)
{
// build: symbol ?gpNpcConfirmDialog@* 0x007C0D73
    D2_ASSERT(!gpNpcConfirmDialog, 0x7D7);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcConfirmDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B5850, sub_004B4070, 0, 0, 1, 0, 0, 0, 1);
    sub_004B8370(gpNpcConfirmDialog, 1);
    sub_004B85F0_AddTextLine(gpNpcConfirmDialog, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpNpcConfirmDialog, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B4290, 1);
    sub_004B85F0_AddTextLine(gpNpcConfirmDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B5850, 1);
}

// 0x004B4380
void __cdecl NPCMENU_UpdateNpcInteract()
{
    D2UnitStrc* pNpc;
    if (CUNIT_IsPlayerDeadOrMissing() || (NPC_GET_INTERACT_UNIT() && (pNpc = NPC_GET_INTERACT_UNIT()) != 0 && pNpc->dwAnimMode == 12) || !NPC_GET_INTERACT_UNIT())
    {
        NPCMENU_FreeDialogs();
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
    }

    if (gpNpcMessageDialog)
    {
        sub_004B8100(gpNpcMessageDialog);
        return;
    }

    if (gpNpcConfirmDialog)
    {
        sub_004B8100(gpNpcConfirmDialog);
        return;
    }

    if (gpNpcMainMenuDialog)
    {
        GAME_ResetMouseState();
        sub_004B8100(gpNpcMainMenuDialog);
        return;
    }

    if (gpNpcSubMenuDialog)
    {
        sub_004B8100(gpNpcSubMenuDialog);
        return;
    }

    if (gpNpcWaitDialog)
    {
        D2UnitStrc* pInteract;
        if (NPCMENU_GetInteractNpc() && (pInteract = NPCMENU_GetInteractNpc()) != 0 && pInteract->dwClassId == 0x202 && !gbWaitSoundPlayed)
        {
            if (!gbWaitSoundScheduled)
            {
                gbWaitSoundScheduled = 1;
                gdwWaitSoundTick = (ITEMS_RollLimitedRandomNumber(&sub_00463DD0_GetPlayerUnit()->pSeed, 30) + 120) * 1000 + GetTickCount();
            }

            if (gdwWaitSoundTick > GetTickCount())
            {
                gbWaitSoundPlayed = 1;
                sub_004B9A00(0x11D0, 0, 0, 0, 0);
            }
        }

        if (GAME_GetConnectionType() && gdwNpcTransactionTick && gdwNpcTransactionTick < GetTickCount())
        {
            NPCMENU_CloseWaitDialog();
            return;
        }

        if (gdwNpcRequestTimeout < GetTickCount())
        {
            INV_SendLeaveGame();
            GAME_SetExitApplication(0);
            GAME_SetCinematicExit(1);
            GAME_RequestExit();
        }
        return;
    }

// build: symbol ?gpTradeDialog@* 0x007C0D5F
    if (gpTradeDialog)
    {
        if (!INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory) && !CURSOR_GetCursorItem())
        {
            sub_004B8100(gpTradeDialog);
            return;
        }

        gnNpcMenuState = 3;
        INV_EnterNpcMenuState();
// build: symbol ?gdwTradeRequestTick@* 0x007C0DE9
        gdwTradeRequestTick = GetTickCount();
        gnTradeRequestFailCount += 1;
        DIALOG_DestroyDialog(gpTradeDialog);
        gpTradeDialog = 0;
        return;
    }

    if (gpNpcHireDialog)
    {
        sub_004B8100(gpNpcHireDialog);
        return;
    }

// build: symbol ?gpNpcGreetingDialog@* 0x007C0D7B
    if (gpNpcGreetingDialog)
    {
        sub_004B8100(gpNpcGreetingDialog);
    }
}

// 0x004B3E10
void __fastcall NPCMENU_RefreshNpcEntries(D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return;

// build: symbol ?gnNpcEntryCount@* 0x0072554C
    for (int i = 0; i < gnNpcEntryCount; ++i)
    {
        if (gaNpcEntries[i].bSelected == 1)
        {
            gaNpcEntries[i].bSelected = 0;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0xFAB);
            sub_004B1680(&gaNpcEntries[i]);
        }
        gaNpcEntries[i].bRefreshed = 1;
    }

    if (!(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        return;

    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    gbNpcInteracting = 0;
}

// 0x004B34A0
int __cdecl NPCMENU_IsAnyDialogOpen()
{
    if (gpTradeDialog || gpNpcSubMenuDialog || gpNpcWaitDialog || gpNpcMainMenuDialog || gpNpcMessageDialog
        || gpNpcConfirmDialog || gpNpcHireDialog || gpNpcGreetingDialog)
    {
        return 1;
    }

    return 0;
}

// 0x004B3510
void __fastcall NPCMENU_FlagNpcEntries(D2NpcMonListPacketStrc* pPacket)
{
    for (int i = 0; i < 12; ++i)
    {
        if (pPacket->nMonIds[i] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            for (int j = 0; j < gnNpcEntryCount; ++j)
            {
                if (gaNpcEntries[j].nId == pPacket->nMonIds[i])
                {
                    gaNpcEntries[j].bFlag = 1;
                }
            }
        }
    }
}

// 0x004B3C20
void __fastcall NPCMENU_EndNpcInteraction(int nValue)
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

    D2UnitStrc* pNpc = CUNIT_FindClientUnit(nValue, 1);
    if (pNpc)
    {
        NPCMENU_RemoveInventoryClientUnits(pNpc);
    }

    if (gnNpcSoundActive)
    {
        sub_004BA840(gnNpcSoundHandle);
    }

    gnNpcSoundActive = 0;
    gnNpcSoundHandle = 0;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nValue, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }

    MSG_SendTwoDwords(0x30, 1, nValue);
    CUNIT_ClearTextPanel();
    gbNpcInteracting = 0;
    UI_SetUIVar(8, 1, 0);

    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nClientFlags &= ~1;
        }

        UNITMODE_SetUnitMode(pUnit, 1);
    }
}

// 0x004B3D40
int __cdecl NPCMENU_OpenGambleShop()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnInteractNpcId, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        return 1;
    }

    gnNpcMenuState = 3;
    gbGambleShop = 1;
    UI_SetUIVar(0xC, 0, 0);
    sub_004786D0_SendDwords3(0x38, 2, gnInteractNpcId, 0);
    gpNpcPlayerUnit = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B5C20
int __cdecl NPCMENU_CloseHireDialog()
{
    if (gpNpcHireDialog)
    {
        DIALOG_DestroyDialog(gpNpcHireDialog);
        delete gpNpcTradeObj;
        gpNpcTradeObj = 0;
        gpNpcHireDialog = 0;
    }

    NPCMENU_BuildNpcMenu();
    return 1;
}

// 0x004B3240
void __fastcall NPCMENU_StoreMessage(const D2StoredMsgPacketStrc* pPacket)
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

// build: symbol ?NPCMENU_SetNpcInteract@* 0x004B1640
static void NPCMENU_SetNpcInteract(D2UnitStrc* pRecord)
{
    if (pRecord)
    {
        gbNpcInteracting = 1;
        gnInteractNpcId = pRecord->dwUnitId;
        gnInteractNpcClassId = pRecord->dwClassId;
    }
    else
    {
        gbNpcInteracting = 0;
    }
}

// build: symbol ?NPCMENU_AddUsedString@* 0x004B1980
void __fastcall NPCMENU_AddUsedString(unsigned short wStringId)
{
    if (gtStringList.wCount < 9)
    {
        gtStringList.awStrings[gtStringList.wCount] = wStringId;
        gtStringList.wCount++;
    }
}

// build: symbol ?NPCMENU_RunNpcQuestHandlers@* 0x004B19A0
static int __stdcall NPCMENU_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount)
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

// build: symbol ?NPCMENU_IsSpecialNpc@* 0x004B1A10
static bool NPCMENU_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

// build: symbol ?NPCMENU_FindNpcIndex@* 0x004B2E30
static int NPCMENU_FindNpcIndex(D2UnitStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->dwClassId;
// build: symbol ?gnNpcIndexCount@* 0x00725A74
    for (int i = 0; i < gnNpcIndexCount; ++i)
    {
        if (gaNpcIndex[i].nId == nId)
            return i;
    }
    return 0;
}

static int __stdcall sub_004B6440_ToggleNpcHandler(int bAdd, int nIndex)
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        return 0;
    }

    if (bAdd)
    {
        const int nCount = gaNpcIndex[nIndex].nCount;
        for (int i = 0; i < nCount; ++i)
        {
            if (gaNpcIndex[nIndex].apfHandlers[i] == NPCMENU_ResurrectMercWait)
            {
                return 1;
            }
        }

        for (int i = 0; i < nCount; ++i)
        {
            if (gaNpcIndex[nIndex].apfHandlers[i] == sub_004B5C60_Handler)
            {
                for (int j = nCount - 1; j >= i; --j)
                {
                    gaNpcIndex[nIndex].apfHandlers[j + 1] = gaNpcIndex[nIndex].apfHandlers[j];
                    gaNpcIndex[nIndex].awIds[j + 1] = gaNpcIndex[nIndex].awIds[j];
                }
                ++gaNpcIndex[nIndex].nCount;
                gaNpcIndex[nIndex].apfHandlers[i] = NPCMENU_ResurrectMercWait;
                gaNpcIndex[nIndex].awIds[i] = 0x1507;
                return 1;
            }
        }

        const int nPos = nCount - 1;
        for (int j = nCount - 1; j >= nPos; --j)
        {
            gaNpcIndex[nIndex].apfHandlers[j + 1] = gaNpcIndex[nIndex].apfHandlers[j];
            gaNpcIndex[nIndex].awIds[j + 1] = gaNpcIndex[nIndex].awIds[j];
        }
        ++gaNpcIndex[nIndex].nCount;
        gaNpcIndex[nIndex].apfHandlers[nPos] = NPCMENU_ResurrectMercWait;
        gaNpcIndex[nIndex].awIds[nPos] = 0x1507;
        return 1;
    }

    const int nCount = gaNpcIndex[nIndex].nCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (gaNpcIndex[nIndex].apfHandlers[i] == NPCMENU_ResurrectMercWait)
        {
            for (int j = i; j < gaNpcIndex[nIndex].nCount - 1; ++j)
            {
                gaNpcIndex[nIndex].apfHandlers[j] = gaNpcIndex[nIndex].apfHandlers[j + 1];
                gaNpcIndex[nIndex].awIds[j] = gaNpcIndex[nIndex].awIds[j + 1];
            }
            --gaNpcIndex[nIndex].nCount;
            return 1;
        }
    }
    return 1;
}

static void __stdcall sub_004B66B0_OpenNpcInteract(D2UnitStrc* pUnit, int bReopen)
{
    GAME_ResetMouseState();
    if (!pUnit)
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gnNpcMenuState = 1;
    gnNpcTradeMode = 0;
// build: symbol ?gnNpcGoldSnapshot@* 0x007C0C73
    gnNpcGoldSnapshot = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), 0xE, 0);
    UI_CloseUIVars(0, 0);

    if (!bReopen)
    {
        if (pUnit == (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        {
            return;
        }
        if (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0)
        {
            sub_004B3DE0_CloseNpc();
            return;
        }
    }
    else
    {
        gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    }

    gbNpcInteracting = 1;
    gnInteractNpcId = pUnit->dwUnitId;
    gnInteractNpcClassId = pUnit->dwClassId;
    pUnit->dwFlags &= ~2;

    const int nNpcId = pUnit->dwClassId;
// build: symbol ?gnHandlerCount@* 0x007253DC
    NPCMENU_RunNpcQuestHandlers(nNpcId, gpPlayerQuestFlags, gaNpcHandlers, gnHandlerCount);

    if (gnNpcSoundActive)
    {
        if (gnNpcSoundHandle)
        {
            sub_004BA840(gnNpcSoundHandle);
            gnNpcSoundHandle = 0;
        }
        gnNpcSoundActive = 0;
    }

    switch (pUnit->dwClassId)
    {
    case 0x96:
        if (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), 0xC, 0) >= 8)
        {
            NPCMENU_InitHireHandler();
        }
// build: symbol ?gnHirelingName@* 0x00725494
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0xB);
        break;

    case 0xC6:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 8);
        break;

    case 0xFC:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x18);
        break;

    case 0x16F:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x15);
        break;

    case 0x203:
        sub_004B6440_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x2B);
        break;
    }

    if (!UI_SetUIVar(8, 0, 0))
    {
        gnNpcMenuState = 0;
        pUnit->dwFlags |= 2;
        MSG_SendTwoDwords(0x30, 1, pUnit->dwUnitId);
        gbNpcInteracting = 0;
        NPCMENU_ClearNpcInventoryAndSound(pUnit->dwUnitId);
        return;
    }

    NPCMENU_BuildNpcMenu();
    if (bReopen)
    {
        return;
    }

    int nType = 0;
    for (int i = 0; i < gnNpcEntryCount; ++i)
    {
        if (gaNpcEntries[i].nId == nNpcId)
        {
            if (gaNpcEntries[i].bFlag == 1)
            {
                gaNpcEntries[i].bFlag = 0;
                nType = 2;
            }
            if (gaNpcEntries[i].bRefreshed != 1)
            {
                return;
            }
            gaNpcEntries[i].bRefreshed = 0;
            break;
        }
    }

    const int nSound = sub_004E0590_PickNpcSound(pUnit, nType);
    if (!nSound)
    {
        return;
    }

    UNITSND_ReleaseSkillSfx(pUnit);
    gnNpcSoundHandle = sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
    if (nType == 2)
    {
        sub_004785B0_SendPacket3(0x4D, nNpcId);
        gnNpcSoundActive = 1;
        return;
    }
    gnNpcSoundHandle = 0;
}

// 0x004B6A30
int __fastcall NPCMENU_NpcTextCallback(void* pContext, int nArg, int nValue)
{
// build: symbol ?gwNpcGreetingString@* 0x007C0C77
// build: symbol ?gwNpcMessageString@* 0x007C0C79
    gwNpcMessageString = NPCMENU_GetFreeStringId(gwNpcGreetingString);
    if (gwNpcGreetingString == 0x251)
    {
        sub_004B9A00(0xF1, 0, 0, 0, 0);
    }
    if (gwNpcGreetingString == 0x21A)
    {
        sub_004B9A00(0xED, 0, 0, 0, 0);
    }

    if (gbNpcMessageShown == 1)
    {
        if (gwNpcMessageString != 0xFFFF && (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        {
            gwNpcLastString = gwNpcMessageString;
            sub_004A10E0(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0, gwNpcLastString, 1);
            NPCMENU_AddUsedString(gwNpcLastString);
            TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
            gwNpcGreetingString = gwNpcLastString;
            MSG_SendTwoDwords(0x31, gnInteractNpcId, gwNpcLastString);
            gwNpcMessageString = NPCMENU_GetFreeStringId(gwNpcLastString);
            return 1;
        }

        gbNpcMessageShown = 0;
        TEXT_SetTextCallback(0, 0);
        const int nIndex = NPCMENU_FindNpcIndex(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0);
        if ((!nArg || !nValue) && !NPCMENU_IsSpecialNpc(gnInteractNpcClassId) && nIndex >= 0 && NPCMENU_GetInteractNpc()
            && nIndex < gnNpcIndexCount && gaNpcIndex[nIndex].bEnabled)
        {
            gnNpcMenuState = 1;
            if (NPCMENU_GetInteractNpc())
            {
                sub_004B66B0_OpenNpcInteract(NPCMENU_GetInteractNpc(), 1);
                return 1;
            }
            sub_004B3DE0_CloseNpc();
            return 0;
        }

        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 0;
    }

    gbNpcMessageShown = 0;
    TEXT_SetTextCallback(0, pContext);
    gwNpcGreetingString = 0xFFFF;
    NPCMENU_OpenGreetingDialog();
    return 0;
}

// 0x004B6980
void __fastcall NPCMENU_SetNpcMenuState(unsigned short wValue, int nValue)
{
    gnHirelingName = wValue;
    gnNpcMenuValue = nValue;
    if (wValue == 0xFFFF)
    {
        sub_004B6440_ToggleNpcHandler(0, 0xB);
        sub_004B6440_ToggleNpcHandler(0, 8);
        sub_004B6440_ToggleNpcHandler(0, 0x18);
        sub_004B6440_ToggleNpcHandler(0, 0x15);
        sub_004B6440_ToggleNpcHandler(0, 0x2B);
    }
}

void __fastcall sub_004B6DD0_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg)
{
    if (nUnitType == 6)
    {
        QUESTRECORD_CopyBufferToRecord(gpPlayerQuestFlags, pBuffer, 0x60, 0);
        return;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
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
        MSG_SendTwoDwords(0x30, nArg, nUnitId);
        NPCMENU_ClearNpcInventoryAndSound(nUnitId);
        return;
    }

    CUNIT_ForEachMonster(NPCMENU_ClearInteractOverlay);
    pUnit->dwFlags |= 2;
    QUESTRECORD_CopyBufferToRecord(gpPlayerQuestFlags, pBuffer, 0x60, 0);
    NPCMENU_ResetHandlers();
    MSG_SendTwoDwords(0x2F, nUnitType, nUnitId);
    GAME_ResetMouseState();

    if (gabNpcMenuState[0])
    {
        gbNpcMessageShown = 1;
        NPCMENU_SetNpcInteract(pUnit);
        pUnit->dwFlags &= ~2;
        return;
    }

    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    D2_ASSERT(pTextHeader, 0x1060);

    const unsigned short wString = TEXT_GetStringIdOfMenuType0Node(pTextHeader, 0);
    const int nClassId = pUnit->dwClassId;
    if (MONSTERUNIQUE_CheckMonStatsFlag(nClassId, 9) && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B
        && nClassId != 0x20F)
    {
        CUNIT_TurnTowardPlayer(pUnit);
    }

    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        gbNpcInteracting = 1;
        gnInteractNpcId = pUnit->dwUnitId;
        gnInteractNpcClassId = pUnit->dwClassId;
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gtStringList.wCount = 0;
    if (wString != 0xFFFF)
    {
        UI_CloseUIVars(0, 0);
        gwNpcGreetingString = wString;
        sub_004A10E0(pUnit, wString, 1);
        NPCMENU_AddUsedString(wString);
        gwNpcMessageString = NPCMENU_GetFreeStringId(wString);
        MSG_SendTwoDwords(0x31, pUnit->dwUnitId, wString);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
        NPCMENU_SetNpcInteract(pUnit);
    }
    else
    {
        const unsigned short wString2 = TEXT_GetStringIdOfMenuType1Node(pTextHeader, 0);
        if (pUnit->dwClassId != 0x20F)
        {
            CUNIT_PlayerFaceUnit(pUnit);
        }
        if (pUnit->pDynamicPath)
        {
            D2Common_10153(pUnit->pDynamicPath);
        }

        if (wString2 != 0xFFFF)
        {
            INV_ResetHover();
            UI_CloseUIVars(0, 0);
            gwNpcGreetingString = wString2;
            gwNpcMessageString = NPCMENU_GetFreeStringId(wString2);
            sub_004B4FD0(pUnit);
        }
        else
        {
            const int nClass = pUnit->dwClassId;
            if (MONSTERUNIQUE_CheckMonStatsFlag(nClass, 9))
            {
                if (NPCMENU_IsSpecialNpc(nClass))
                {
                    gbNpcInteracting = 1;
                    gnInteractNpcId = pUnit->dwUnitId;
                    gnInteractNpcClassId = pUnit->dwClassId;
                    NPCMENU_EndNpcInteraction(gnInteractNpcId);
                    UI_SetUIVar(8, 1, 0);
                    return;
                }
                INV_ResetHover();
                UI_CloseUIVars(0, 0);
                sub_004B66B0_OpenNpcInteract(pUnit, 0);
            }
            else
            {
                NPCMENU_EndNpcInteraction(gnInteractNpcId);
                UI_SetUIVar(8, 1, 0);
            }
        }
    }
    gbGambleShop = 0;
}

struct D2TextHeaderStrc;

#include "gen/data/Source/D2Client/UI/npcmenu_004B2650.inc"
