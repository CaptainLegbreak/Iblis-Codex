#include "D2Launch.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2MultiTypes.h"
#include "D2LevelTxt.h"

#pragma intrinsic(strlen)

struct D2UnitStrc;

struct D2ActiveRoomStrc;

struct D2InventoryStrc;

struct D2DynamicPathStrc;

struct D2StatListStrc;

struct SMSGHANDLER_PARAMS;

struct D2CharSelCacheStrc;

struct D2StatesTxt;

struct D2DataTablesStrc;

struct D2LaunchRequestStrc;

struct D2UnitDropItemsPacketStrc;

struct D2GridCellStrc;

struct D2CelFileStrc;

struct Unicode;

struct D2FuncTable_0077ABF0Strc;

struct D2LaunchCharInfoStrc;

struct D2FuncRecordStrc;

struct D2LaunchCharEntryStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue);
};

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern "C" int __stdcall sub_0043A460_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460

static int gdwGlobal_00779DC4; // 0x00779DC4

extern int gdwGlobal_0070CC08; // 0x0070CC08

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet); // 0x004F9740

int __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0

void __fastcall sub_00439AF0(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0

void __fastcall sub_004FC660_SetValue(D2WinControlStrc* pControl, int nValue); // 0x004FC660

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

int __cdecl sub_0042F6D0(); // 0x0042F6D0

extern D2WinControlStrc* gpControl_007795E0; // 0x007795E0

extern D2WinControlStrc* gpControl_007795E4; // 0x007795E4

extern void** gppSlots_00779988; // 0x00779988

extern int gdwGlobal_0077998C; // 0x0077998C

unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0

char* __fastcall sub_00430B50_GetSlotName(int nIndex); // 0x00430B50

int __cdecl sub_00430A20_FreeSlots(); // 0x00430A20

D2CharSelCacheStrc* gpCharSelCache_00779DE8; // 0x00779DE8

static int gbFlag_00779C6C;             // 0x00779C6C

extern char gszBaseName_00779B68[]; // 0x00779B68

struct D2LaunchRequestStrc
{
    int nData[5];
    unsigned int dwFlags;
};

struct D2UnitDropItemsPacketStrc
{
    char nHeader;
    char bActive;
    char nUnitId[4];
    char nOtherUnitId[4];
};

struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds); // 0x006CC258

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void __cdecl sub_00444E70_FillGameList(); // 0x00444E70

void __fastcall WINMAIN_SendMcpGameListRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId); // 0x0044A590

void __cdecl RECORD_WriteRecordFile(); // 0x00451620

extern "C" D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int nStateId); // 0x00452040

void __cdecl AUTOMAP_SaveAutomapLayer(); // 0x004584C0

void __cdecl AUTOMAP_ResetAutomapCells(); // 0x00458680

void __cdecl AUTOMAP_LoadAutomapLayer(); // 0x00458750

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall UI_DrawLoadingScreen(int nArg); // 0x004565E0

unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall GFX_DrawProgressiveStateOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY); // 0x0046E1B0

void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70

void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648CE0

void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode); // 0x00649190

int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern unsigned short gwRequestId_0070CD60; // 0x0070CD60

extern int gnGlobal_007111CC; // 0x007111CC

extern int gnGlobal_007111D0; // 0x007111D0

extern int gnGlobal_007111D4; // 0x007111D4

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern unsigned short gwSavedRequestId_0077BBDC; // 0x0077BBDC

extern void* gpGlobal_007A0634; // 0x007A0634

extern void* gpAutomapContext_007A5164; // 0x007A5164

extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

extern int gnProgress_007BB3B4; // 0x007BB3B4

void __stdcall sub_00439E60_AddToValue(int nDelta); // 0x00439E60

int __stdcall sub_00439E90_ListKeyDown(SMSGHANDLER_PARAMS* pMsg); // 0x00439E90

static int gnTopRow_00779DC8; // 0x00779DC8

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId); // 0x0042F430

void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __cdecl sub_0043B9A0(); // 0x0043B9A0

extern int gnState_00779DAC; // 0x00779DAC

extern "C" unsigned int __cdecl strlen(const char* sz);

struct D2LaunchCharEntryStrc
{
    char szName[0x324];
    int nFlags;
    char unk0x328[0x0C];
    int bShared;
    D2CelFileStrc* pCellFile;
    char unk0x33C[0x10];
    D2LaunchCharEntryStrc* pNext;
};

int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag); // 0x005041B0

extern D2LaunchCharEntryStrc* gpCharEntry_00779DC0; // 0x00779DC0

struct D2WinTextBoxStrc;

struct D2WinButtonStrc;

int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0

int __stdcall sub_00439DF0_OnScroll(SMSGHANDLER_PARAMS* pMsg);                                              // 0x00439DF0

int __cdecl sub_0043A2B0_InitRealmScreen();                                                                 // 0x0043A2B0

void __fastcall sub_0043ADB0_UseName(char* szName);                                                         // 0x0043ADB0

void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0

void __fastcall sub_004FB590(int nFont);                                                                    // 0x004FB590

int __fastcall D2Win_10191(D2WinTextBoxStrc* pTextBox, int nMaxSteps);                                      // 0x004FC5E0

int __fastcall D2Win_10194(D2WinTextBoxStrc* pTextBox, D2WinTextBoxStrc* pLinkedTextBox);                   // 0x004FC6A0

int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x004FC6E0

void __fastcall BUTTON_SetStringId(D2WinButtonStrc* pButton, int nStringId);                                // 0x00500BF0

D2WinControlStrc* gpControl_007799F8;                                                                       // 0x007799F8

extern void* gapRowControls_00779A20[];                                                                     // 0x00779A20

extern char gData_00779A40[];                                                                               // 0x00779A40

void* gapRowControlsX_00779B40[8];                                                                          // 0x00779B40

D2WinControlStrc* gpControl_00779C84;                                                                       // 0x00779C84

static int gnSelected_0070CC00;         // 0x0070CC00

static D2WinControlStrc* gpCharSelectText_00779DD4; // 0x00779DD4

static D2WinControlStrc* gpControl_00779DD0;        // 0x00779DD0

static int gnLastValue_00779DCC;        // 0x00779DCC

int __stdcall sub_0043B8E0_OnTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0

int __stdcall sub_0043B940_OnTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940

D2RecordHandlerFn gpfnPrevHandler_007A2764; // 0x007A2764

int gbOverlaysEnabled_007A289C; // 0x007A289C

int gnOverlayStep_007A3138; // 0x007A3138

int gnGlobal_007B0A54; // 0x007B0A54

int gnGlobal_007B0A58; // 0x007B0A58

void __fastcall SCMD_DropUnitItems(D2UnitDropItemsPacketStrc* pPacket); // 0x00462F60

struct D2ListMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
};

int __stdcall sub_00439840(D2ListMsgStrc* pMsg); // 0x00439840

// 0x0042E5B0
char* __cdecl sub_0042E5B0_StrStr(char* szString, const char* szSubString)
{
    return strstr(szString, szSubString);
}

// build: symbol ??0Unicode@@QAE@G@Z 0x0042E600
Unicode::Unicode(unsigned short wValue)
{
    wChar = wValue;
}

// 0x0042FDE0
int __stdcall sub_0042FDE0_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    char c = *pChar;
    switch (c)
    {
    case '"':
    case '#':
    case '%':
    case '*':
    case ',':
    case '/':
    case '<':
    case '>':
    case '?':
    case '\\':
        return 0;
    }
    if (c <= 0x20)
        return 0;
    return c < 0x7F;
}

// 0x0042FE70
int __stdcall sub_0042FE70_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    char c = *pChar;
    switch (c)
    {
    case '"':
    case '#':
    case '%':
    case '*':
    case ',':
    case '/':
    case '<':
    case '>':
    case '?':
    case '\\':
        return 0;
    }
    if (c <= 0x20)
        return 0;
    return c < 0x7F;
}

// 0x00430120
int __stdcall sub_00430120_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        CONTROL_SetVisible(gpControl_007795E0, 1);
    else
        CONTROL_SetVisible(gpControl_007795E0, 0);
    return 1;
}

// 0x00430160
int __stdcall sub_00430160_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        CONTROL_SetVisible(gpControl_007795E4, 1);
    else
        CONTROL_SetVisible(gpControl_007795E4, 0);
    return 1;
}

// 0x004303E0
bool __stdcall sub_004303E0_IsLineBreak(Unicode wc)
{
    if (wc.wChar == 13 || wc.wChar == 10)
        return true;
    return false;
}

// 0x00430840
int __stdcall sub_00430840(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004307A0(pMsg->lParam, 1, 0xFAA, 0x140B);
    return 1;
}

// 0x00430870
int __stdcall sub_00430870(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004307A0(pMsg->lParam, 0, 0xFAB, 0x1408);
    return 1;
}

// 0x00430920
int __stdcall sub_00430920(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004307A0(pMsg->lParam, 2, 0xFA9, 0x1409);
    return 1;
}

// 0x00430950
int __stdcall sub_00430950(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004307A0(pMsg->lParam, 4, 0xFA7, 0x140A);
    return 1;
}

// 0x00430980
int __stdcall sub_00430980(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004307A0(pMsg->lParam, 3, 0xFA8, 0x140C);
    return 1;
}

// 0x004309C0
int __stdcall sub_004309C0_AddToSlots(void* pEntry)
{
    D2_ASSERT(gppSlots_00779988, 4383);
    for (int i = 0; i < gdwGlobal_0077998C; i++)
    {
        if (!gppSlots_00779988[i])
        {
            gppSlots_00779988[i] = pEntry;
            return 1;
        }
    }
    return 0;
}

// 0x00430B00
int __cdecl sub_00430B00_CompareNames(const void* pEntry1, const void* pEntry2)
{
    return strcmp(**(const char* const* const*)pEntry1, **(const char* const* const*)pEntry2);
}

// 0x004379D0
int __fastcall sub_004379D0_GetBit20(int nValue)
{
    return nValue & 0x20;
}

// 0x004379E0
unsigned int __fastcall sub_004379E0_GetBits8(unsigned int nValue)
{
    return (nValue >> 8) & 0x1F;
}

// 0x004379F0
void __cdecl sub_004379F0_Forward()
{
    sub_00434060();
}

// 0x00437A00
static inline char* sub_00437A00_GetSlotNameChecked(int nIndex)
{
// build: symbol ?GAME_GetSlotNameCount@* 0x00430B40
    if (nIndex < GAME_GetSlotNameCount())
        return sub_00430B50_GetSlotName(nIndex);
    return 0;
}

// 0x00437A60
int __cdecl sub_00437A60_FreeSlots()
{
    return sub_00430A20_FreeSlots();
}

// 0x00437A70
void* __fastcall sub_00437A70_CharSelCacheFind(const char* szKey)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    const int nTick = GetTickCount();
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

int __fastcall sub_M110_Emit_00437A00(int nIndex)
{
    return sub_00437A00_GetSlotNameChecked(nIndex + 1) != 0;
}

// 0x00437AB0
void __fastcall sub_00437AB0_CharSelCacheStore(const char* szKey, const void* pData, unsigned int nSize)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash)
        {
            SMemFree(pEntry->pData, ".\\Src\\CharSel.cpp", 0xF1, 0);
            pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xF2, 0);
            memcpy(pEntry->pData, pData, nSize);
            pEntry->dwExpireTick = GetTickCount() + 300000;
            return;
        }
    }
    D2CharSelCacheStrc* pEntry = (D2CharSelCacheStrc*)SMemAlloc(sizeof(D2CharSelCacheStrc), ".\\Src\\CharSel.cpp", 0xFA, 0);
    pEntry->dwHash = dwHash;
    pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xFC, 0);
    memcpy(pEntry->pData, pData, nSize);
    pEntry->dwExpireTick = GetTickCount() + 300000;
    pEntry->pNext = gpCharSelCache_00779DE8;
    gpCharSelCache_00779DE8 = pEntry;
}

// 0x00437C90
void __cdecl sub_00437C90_ScrollNameControl()
{
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl_007799E8, -1, 4);
}

// 0x00437F30
void __fastcall sub_00437F30_CopyBaseName(const char* szName)
{
    char* pDest = gszBaseName_00779B68;
    while (*szName && *szName != '.')
        *pDest++ = *szName++;
    *pDest = 0;
}

// 0x00438060
void __cdecl sub_00438060_FreeCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->bShared)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x00438F40
int __fastcall sub_00438F40_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}

// 0x00439B80
int __stdcall sub_00439B80(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439AF0(pMsg, 0);
    return 1;
}

// 0x00439BA0
int __stdcall sub_00439BA0(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439AF0(pMsg, 1);
    return 1;
}

// 0x00439BC0
int __stdcall sub_00439BC0(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439AF0(pMsg, 2);
    return 1;
}

// 0x00439E60
void __stdcall sub_00439E60_AddToValue(int nDelta)
{
    sub_004FC660_SetValue(gpControl_00779C84, sub_004FC620_GetValue(gpControl_00779C84) + nDelta);
}

// 0x00439E90
int __stdcall sub_00439E90_ListKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->uMessage != 0x102)
    {
    switch (pMsg->wParam)
    {
    case 0x28:
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
        {
            gnSelected_0070CC00 += 2;
            if (gnSelected_0070CC00 > gdwGlobal_00779DC4 - 1)
            {
                gnSelected_0070CC00 -= 2;
            }
            else if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00;
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                if (gnSelected_0070CC00 % 2 == 0)
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 2;
                }
                else
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
                }
                sub_00439E60_AddToValue(1);
            }
        }
        break;

    case 0x26:
        if (gnSelected_0070CC00 > 0)
        {
            gnSelected_0070CC00 -= 2;
            if (gnSelected_0070CC00 < 0)
            {
                gnSelected_0070CC00 += 2;
            }
            else if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                if (gnSelected_0070CC00 % 2 != 0)
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - 1;
                }
                else
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00;
                }
                sub_00439E60_AddToValue(-1);
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 2;
            }
        }
        break;

    case 0x27:
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1 && gnSelected_0070CC00 % 2 == 0)
        {
            gnSelected_0070CC00 += 1;
            if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00;
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
        }
        break;

    case 0x25:
        if (gnSelected_0070CC00 > 0 && gnSelected_0070CC00 % 2 != 0)
        {
            gnSelected_0070CC00 -= 1;
            if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00;
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
        }
        break;

    case 0x24:
        gnTopRow_00779DC8 = 0;
        gnSelected_0070CC00 = 0;
        break;

    case 0x23:
        if (gdwGlobal_00779DC4 > gnVisibleRows_0070CC0C)
        {
            gnTopRow_00779DC8 = gdwGlobal_00779DC4 - gnVisibleRows_0070CC0C;
        }
        gnSelected_0070CC00 = gdwGlobal_00779DC4 - 1;
        break;
    }

    sub_00438560_Refresh();
    sub_00439210_Redraw();
    return 1;
    }

    return 0;
}

// 0x0043A0D0
int __stdcall sub_0043A0D0_ListKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        return sub_00439E90_ListKeyDown(pMsg);

    if (pMsg->uMessage != 0x102)
    {
        switch (pMsg->wParam)
        {
        case 0x28:
            if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
            {
                gnSelected_0070CC00 += 1;
                if (gnSelected_0070CC00 < gnTopRow_00779DC8)
                    gnTopRow_00779DC8 = gnSelected_0070CC00;
                else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
            break;

        case 0x26:
            if (gnSelected_0070CC00 > 0)
            {
                gnSelected_0070CC00 -= 1;
                if (gnSelected_0070CC00 < gnTopRow_00779DC8)
                    gnTopRow_00779DC8 = gnSelected_0070CC00;
                else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
            break;

        case 0x24:
            gnTopRow_00779DC8 = 0;
            gnSelected_0070CC00 = 0;
            break;

        case 0x23:
            if (gdwGlobal_00779DC4 > gnVisibleRows_0070CC0C)
                gnTopRow_00779DC8 = gdwGlobal_00779DC4 - gnVisibleRows_0070CC0C;
            gnSelected_0070CC00 = gdwGlobal_00779DC4 - 1;
            break;
        }

        sub_00438560_Refresh();
        sub_00439210_Redraw();
        return 1;
    }

    return 0;
}

static int sub_00437A20_FindSlotName(const char* szName)
{
    int i = 0;
    char* szSlot;
    while (i < GAME_GetSlotNameCount() && (szSlot = sub_00430B50_GetSlotName(i)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            return 1;
        ++i;
    }
    return 0;
}

// 0x0043A2B0
int __cdecl sub_0043A2B0_InitRealmScreen()
{
    unsigned short nStringId;
    gnState_00779DAC = 0;
    if (gnLaunchMode_007795EC == 1)
    {
        sub_00434060();
        const int nCount = GAME_GetSlotNameCount();
        if (nCount != -1)
        {
            if (nCount != 0)
            {
                D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x7A);
                sub_004FD830(pControl);
                sub_004FDA50(pControl);
                gpControl_00779DD0 = sub_0042F430_CreateControl(0x94);
                gpCharSelectText_00779DD4 = sub_0042F430_CreateControl(0x95);
                sub_0042F430_CreateControl(0x69);
                gpControl_00779D98 = sub_0042F430_CreateControl(0x6B);
                gpControl_00779D8C = sub_0042F430_CreateControl(0x6C);
                sub_004FC9B0_SetText(sub_0042F430_CreateControl(0x6A), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

                if (!SRegLoadString("Diablo II", "Preferred Realm", 0, gData_00779A40, 0x100) || !sub_00437A20_FindSlotName(gData_00779A40))
                {
                    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
                    const int nIndex = pRecord->nIndex;
                    SStrCopy(gData_00779A40, sub_005180E0(pRecord, nIndex), 0x7FFFFFFF);
                    SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
                    if (!sub_00437A20_FindSlotName(gData_00779A40))
                    {
                        const char* szFirst = GAME_GetSlotNameCount() > 0 ? sub_00430B50_GetSlotName(0) : 0;
                        SStrCopy(gData_00779A40, szFirst, 0x7FFFFFFF);
                        SRegSaveString("Diablo II", "Preferred Realm", 0, gData_00779A40);
                    }
                }
            }
            else
            {
                sub_0043B9A0();
                nStringId = 0x14AA;
                goto fail;
            }
        }
        else
        {
            sub_0043B9A0();
            nStringId = 0x14E3;
            goto fail;
        }
    }
    return 1;

fail:
    sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(nStringId), sub_004336C0);
    return 0;
}

// 0x0043A610
void __cdecl sub_0043A610_ShowString()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
    Unicode wEmpty;
    wEmpty.wChar = 0;
    gdwGlobal_0070CC08 = gdwGlobal_00779DC4;
    sub_0043A460_CreateNotice(pTitle, &wEmpty, 2, 0x12);
}

unsigned long gdwLastClick_00779DEC; // 0x00779DEC

// 0x0043A9D0
int __stdcall sub_0043A9D0_ListClick(D2ListMsgStrc* pMsg)
{
    if (!gbFlag_00779C6C)
    {
        const int nPrevious = gnSelected_0070CC00;
        void* hWnd = pMsg->hWnd;
        int nRow;
        for (nRow = 0; nRow < gnVisibleRows_0070CC0C; nRow += 1)
        {
            if (FOG_IsExpansion() && hWnd == gapRowControlsX_00779B40[nRow])
                break;
            if (hWnd == gapRowControls_00779A20[nRow])
                break;
        }
        const int nIndex = gnTopRow_00779DC8 + nRow;
        if (gdwGlobal_00779DC4 < nIndex)
            return 0;
        gnSelected_0070CC00 = nIndex;
        if (gdwGlobal_00779DC4 <= 0)
            gnSelected_0070CC00 = -1;
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
            if (gnSelected_0070CC00 != -1 && gnSelected_0070CC00 == nPrevious && dwTick - gdwLastClick_00779DEC < 500)
                return sub_00439840(pMsg);
            gdwLastClick_00779DEC = dwTick;
        }
        return sub_00439210_Redraw();
    }
    return 1;
}

// 0x0043AE30
void __cdecl sub_0043AE30_InitCharList()
{
    sub_0042F480_Reset();
    sub_0042F2E0_ReadPaletteFiles(gapszSkyPalette_006D3A08[0], gapszSkyPalette_006D3A08[1]);
    gdwGlobal_00779DA4 = 1;
    gdwGlobal_00779DC4 = 0;
    gnTopRow_00779DC8 = 0;
    gnSelected_0070CC00 = 0;
    gbFlag_00779C6C = 0;
    gpCharSelectText_00779DD4 = 0;
    gpControl_00779DD0 = 0;
    gnLastValue_00779DCC = 0;
    gpLaunchRecord_007795D4->nByte210 = 0;
    sub_0042F430_CreateControl(0xA1);
    gpControl_00779C68 = sub_0042F430_CreateControl(0xA2);
    gpControl_007799F8 = sub_0042F430_CreateControl(0xA3);
    gpControl_00779D90 = sub_0042F430_CreateControl(0xA4);
    gpControl_00779C80 = sub_0042F430_CreateControl(0xA5);
    gpControl_007799F4 = sub_0042F430_CreateControl(0xA6);
    gpControl_00779B60 = sub_0042F430_CreateControl(0x9C);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779D90, 0x5524);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779C80, 0x58CA);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_007799F4, 0x5524);
    gpControl_00779C84 = sub_0042F430_CreateControl(0xA7);
    D2Win_10194((D2WinTextBoxStrc*)gpControl_00779C84, 0);
    D2Win_10195((D2WinTextBoxStrc*)gpControl_00779C84, (void(__stdcall*)(SMSGHANDLER_PARAMS*))sub_00439DF0_OnScroll);
    memset(gapRowControls_00779A20, 0, 8 * sizeof(void*));
    gnVisibleRows_0070CC0C = 8;
    for (int i = 0; i < gnVisibleRows_0070CC0C; ++i)
    {
        if (FOG_IsExpansion())
        {
            gapRowControlsX_00779B40[i] = sub_0042F430_CreateControl(i + 0x8C);
            D2Win_10045((D2WinControlStrc*)gapRowControlsX_00779B40[i], gszSpace_006FFC44);
        }
        sub_004FB590(1);
        gapRowControls_00779A20[i] = sub_0042F430_CreateControl(i + 0x84);
        sub_004FB590(0);
        ganRowValues_007799FC[i] = i / 2 * 0x5D + 0xB2;
    }
    gpControl_00779D94 = sub_0042F430_CreateControl(0x96);
    if (sub_0043A2B0_InitRealmScreen())
    {
        CONTROL_SetEnabled(gpControl_007799F8, 0);
        sub_0043ADB0_UseName(gData_00779A40);
        const int nExtra = gdwGlobal_00779DC4 - gnVisibleRows_0070CC0C;
        if (nExtra > 0)
            D2Win_10191((D2WinTextBoxStrc*)gpControl_00779C84, nExtra / 2 + (nExtra % 2 != 0));
        if (sub_00514D80())
// build: symbol ?D2SOUND_10034@* 0x005148F0
            D2SOUND_10034(1);
        CONTROL_SetEnabled(gpControl_007799F8, 1);
    }
}

// 0x00445020
void __cdecl sub_00445020_SendLaunchRequest()
{
    gnLaunchMode_0077BBE4 = 3;
    gnValue_00798CCC = 0;
    if (gpCharInfo_0077BBD8->nType0x35E == 2)
    {
        D2LaunchRequestStrc tRequest;
        memset(&tRequest, 0, sizeof(tRequest));
        if (gpCharInfo_0077BBD8->wFlags[0] & 4)
            tRequest.dwFlags |= 0x800;
        while (++gwRequestId_0070CD60 == 0)
        {
        }
        WINMAIN_SendMcpGameListRequest(&tRequest, gwRequestId_0070CD60);
        gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
    }
    else
    {
        sub_00444E70_FillGameList();
    }
}

// 0x00451920
void __stdcall sub_00451920_RecordHandler(int nArg1, int nArg2, int nArg3)
{
    RECORD_WriteRecordFile();
    if (gpfnPrevHandler_007A2764)
        gpfnPrevHandler_007A2764(nArg1, nArg2, nArg3);
}

// 0x00453470
void __cdecl sub_00453470_DrawProgressiveStates()
{
    if (!gpGlobal_007A0634)
        return;
    if (!sub_00463DE0_GetPlayerUnit())
        return;
    if (!UNITS_GetRoom(sub_00463DE0_GetPlayerUnit()))
        return;
    if (!gbOverlaysEnabled_007A289C)
        return;
    int nY = gnGlobal_00711470 - gnGlobal_007111D4;
    int nX = gnGlobal_0071146C - gnGlobal_007111D0;
    if (D2GFX_GetResolutionMode() == 2)
        nY = gnGlobal_00711470 - gnGlobal_007111CC;
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        const int nState = sgptDataTables->pProgressiveStates[i];
        if (!STATES_CheckState(pUnit, nState))
            continue;
        if (!STATLIST_GetStatListFromUnitAndState(pUnit, nState))
            continue;
        D2StatesTxt* pStatesTxtRecord = sub_00452040_GetStatesTxtRecord(nState);
        if (!pStatesTxtRecord)
            continue;
        if (!(pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[4]))
            continue;
        if (pStatesTxtRecord->wPrgOverlay <= 0 || pStatesTxtRecord->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount)
            continue;
        if (pStatesTxtRecord->wStat < 0 || pStatesTxtRecord->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
            continue;
        const int nCharges = STATLIST_UnitGetStatValue(pUnit, pStatesTxtRecord->wStat, 0);
        if (nCharges < 1 || nCharges > 3)
            continue;
        GFX_DrawProgressiveStateOverlays(pUnit, pStatesTxtRecord->wPrgOverlay + nCharges - 1, nX, nY);
        nX -= gnOverlayStep_007A3138;
    }
}

// 0x00458CD0
void __stdcall sub_00458CD0_SetAutomapContext(void* pContext)
{
    AUTOMAP_SaveAutomapLayer();
    AUTOMAP_ResetAutomapCells();
    gpAutomapContext_007A5164 = pContext;
    AUTOMAP_LoadAutomapLayer();
}

// 0x004756D0
void __cdecl sub_004756D0_ScanGridCollision()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    for (int nY = 0; nY < 0x30; ++nY)
    {
        for (int nX = 0; nX < 0x30; ++nX)
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, gnGlobal_007B0A54 + nX, gnGlobal_007B0A58 + nY);
            if (!pRoom)
                pRoom = UNITS_GetRoom(pPlayer);
            if (COLLISION_CheckMask(pRoom, gnGlobal_007B0A54 + nX, gnGlobal_007B0A58 + nY, 0x22))
                gtGridCells_007B0E68[nY * 0x30 + nX].nFlag = 1;
        }
    }
}

// 0x00478160
void __fastcall sub_00478160_ShowProgressSteps(int nDone, int nTotal)
{
    const int nDivisor = nTotal * 8;
    int nPosition = nDone * 8;
    for (int i = 0; i < 8; ++i)
    {
        if (nDivisor == 0)
            gnProgress_007BB3B4 = 0;
        else
            gnProgress_007BB3B4 = (nPosition * 0x100) / nDivisor;
        UI_DrawLoadingScreen(0);
        Sleep(250);
        ++nPosition;
    }
}

#include "gen/data/Source/D2Launch/Src/CharSel.inc"
