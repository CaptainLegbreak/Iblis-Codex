#include "D2Launch.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

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
struct D2CellFileStrc;
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
extern int gdwGlobal_00779DC4; // 0x00779DC4
extern int gdwGlobal_0070CC08; // 0x0070CC08

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x10];
    void (__fastcall* pfnSlot10)();
    char unk0x14[0x50];
    int (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    unsigned char unk_6C[0x2C];
    D2FuncRecordStrc* (__cdecl* pfnGetRecord)();
    unsigned char unk_9C[0x4];
    int (__fastcall* pfnSlotA0)(int* pValue);
};

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
void __fastcall sub_004F9740(D2WinControlStrc* pControl, int bSet); // 0x004F9740
int __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
void __fastcall sub_00439AF0(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0
void __fastcall sub_004FC660_SetValue(D2WinControlStrc* pControl, int nValue); // 0x004FC660
int __fastcall sub_004F9190(); // 0x004F9190
int __cdecl sub_0042F6D0(); // 0x0042F6D0
extern D2WinControlStrc* gpControl_007795E0; // 0x007795E0
extern D2WinControlStrc* gpControl_007795E4; // 0x007795E4
extern void** gppSlots_00779988; // 0x00779988
extern int gdwGlobal_0077998C; // 0x0077998C

unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
char* __fastcall sub_00430B50_GetSlotName(int nIndex); // 0x00430B50
int __cdecl sub_00430A20_FreeSlots(); // 0x00430A20
extern D2CharSelCacheStrc* gpCharSelCache_00779DE8; // 0x00779DE8
extern int gbFlag_00779C6C; // 0x00779C6C
extern char gszBaseName_00779B68[]; // 0x00779B68


struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2StatesTxt
{
    unsigned short wState;
    unsigned short wOverlay[4];
    unsigned short wCastOverlay;
    unsigned short wRemoveOverlay;
    short wPrgOverlay;
    unsigned char nStateFlags[4];
    unsigned int dwStateFlagsEx;
    short wStat;
};


struct D2LaunchCharInfoStrc
{
    char unk0x00[0x19];
    char nState[4];
    char wValue[2];
    char szText0x1F[0x18];
    char szText0x37[0x1B8];
    char wFlags[2];
    char unk0x1F1[0x3C];
    char bOnline;
    char unk0x22E[0x17];
    char szText0x245[0x10];
    char unk0x255[0x109];
    char nType0x35E;
};

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
void __fastcall sub_0044A590_SendRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId); // 0x0044A590
void __cdecl sub_00451620_WriteRecordFile(); // 0x00451620
extern "C" D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int nStateId); // 0x00452040
void __cdecl sub_004584C0(); // 0x004584C0
void __cdecl sub_00458680_ResetAutomapCells(); // 0x00458680
void __cdecl sub_00458750(); // 0x00458750
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_004565E0_DrawLoadingScreen(int nArg); // 0x004565E0
unsigned char __stdcall sub_00462EE0_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
void __fastcall sub_00465EE0_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
void __fastcall sub_0046E1B0_DrawUnitOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY); // 0x0046E1B0
void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
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
extern int gnTopRow_00779DC8; // 0x00779DC8

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
    D2CellFileStrc* pCellFile;
    char unk0x33C[0x10];
    D2LaunchCharEntryStrc* pNext;
};
int __stdcall sub_005041B0_Destroy(D2CellFileStrc* pCellFile, int nFlag); // 0x005041B0
extern D2LaunchCharEntryStrc* gpCharEntry_00779DC0; // 0x00779DC0

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
        sub_004F9740(gpControl_007795E0, 1);
    else
        sub_004F9740(gpControl_007795E0, 0);
    return 1;
}

// 0x00430160
int __stdcall sub_00430160_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        sub_004F9740(gpControl_007795E4, 1);
    else
        sub_004F9740(gpControl_007795E4, 0);
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

// build: context sub_0043B8E0_OnTick
int __stdcall sub_0043B8E0_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlot64(&nValue))
        sub_004F9190();
    if (gdwGlobal_0077AC04 || (gpFuncTable_0077ABF0->pfnSlot68() && sub_0042F6D0()))
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
}

// build: context sub_0043B940_OnTick
int __stdcall sub_0043B940_OnTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlotA0(&nValue))
        sub_004F9190();
    if (gdwGlobal_0077AC04 || (gpFuncTable_0077ABF0->pfnSlot68() && sub_0042F6D0()))
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        sub_004F9190();
    }
    return 1;
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
static __forceinline char* sub_00437A00_GetSlotNameChecked(int nIndex)
{
    if (nIndex < sub_00430B40())
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

D2CharSelCacheStrc* gpCharSelCache_00779DE8; // 0x00779DE8

D2RecordHandlerFn gpfnPrevHandler_007A2764; // 0x007A2764

int gbOverlaysEnabled_007A289C; // 0x007A289C

int gnOverlayStep_007A3138; // 0x007A3138

int gnGlobal_007B0A54; // 0x007B0A54

int gnGlobal_007B0A58; // 0x007B0A58

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

#include "gen/data/Source/D2Launch/Src/CharSel.inc"

int gdwGlobal_00779DC4; // 0x00779DC4

int gnTopRow_00779DC8; // 0x00779DC8

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
    if (sub_00408F20_HasExpansionMpq())
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

static __declspec(noinline) int sub_00437A20_FindSlotName(const char* szName)
{
    int i = 0;
    char* szSlot;
    while (i < sub_00430B40() && (szSlot = sub_00430B50_GetSlotName(i)) != 0)
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
        const int nCount = sub_00430B40();
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
                        const char* szFirst = sub_00430B40() > 0 ? sub_00430B50_GetSlotName(0) : 0;
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
        sub_0044A590_SendRequest(&tRequest, gwRequestId_0070CD60);
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
    sub_00451620_WriteRecordFile();
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
        sub_0046E1B0_DrawUnitOverlays(pUnit, pStatesTxtRecord->wPrgOverlay + nCharges - 1, nX, nY);
        nX -= gnOverlayStep_007A3138;
    }
}

// 0x00458CD0
void __stdcall sub_00458CD0_SetAutomapContext(void* pContext)
{
    sub_004584C0();
    sub_00458680_ResetAutomapCells();
    gpAutomapContext_007A5164 = pContext;
    sub_00458750();
}

// build: context sub_00462F60_UnitDropItems
void __fastcall sub_00462F60_UnitDropItems(D2UnitDropItemsPacketStrc* pPacket)
{
    if (!pPacket->bActive)
        return;
    D2UnitStrc* pUnit = sub_00463990(*(int*)pPacket->nUnitId, 0);
    if (!pUnit)
        return;
    if (!sub_00464820_IsDeadOrDying(pUnit))
        sub_00480E70_SetUnitMode(pUnit, 0);
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        D2UnitStrc* pOther = sub_00463990(*(int*)pPacket->nOtherUnitId, 0);
        if (!pOther)
            return;
        D2DynamicPathStrc* pPath = pOther->pDynamicPath;
        PATH_SetMoveTestCollisionMask(pPath, 0);
        sub_00649190_SetPathMode(pOther, 5);
        D2_ASSERT(sub_00650BE0_PlaceUnit(pPath, pOther, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)), 0xABA);
        sub_006488A0_SetDirection(pOther->pDynamicPath, PATH_GetDirection(pUnit->pDynamicPath));
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            pItem = INVENTORY_UnitIsItem(pItem);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            sub_0046F280_ClearGfxBytes(pUnit, sub_00462EE0_GetItemComponent(pUnit, pItem));
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xAC8);
            D2_ASSERT(pRemoved == pItem, 0xAC9);
            sub_004C0EC0_UpdateItemLink(pItem, pUnit, 0, 0);
            sub_0063BE30(pInventory, ITEMS_GetBodyLocation(pItem));
            sub_00470610_Refresh(pUnit, 0);
            const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
            const int nUnitId = !pItem ? -1 : pItem->dwUnitId;
            sub_00465EE0_RemoveClientSideUnit(nUnitId, nUnitType);
        }
        pItem = pNext;
    }
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
        sub_004565E0_DrawLoadingScreen(0);
        Sleep(250);
        ++nPosition;
    }
}
