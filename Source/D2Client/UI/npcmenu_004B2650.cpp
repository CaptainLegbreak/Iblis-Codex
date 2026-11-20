#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientMenus.h"
#include "D2Win32Types.h"

struct D2BitBufferStrc;
struct D2GameStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2NpcMenuSlotStrc;
struct D2StoredMsgPacketStrc;
struct D2StoredMsgStrc;

#pragma pack(push, 2)

#pragma pack(pop)
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
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, long* pLeft, long* pTop, long* pRight, long* pBottom); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_0049F900(); // 0x0049F900
const Unicode* __fastcall sub_0049F910_GetTextString(unsigned short nStringId); // 0x0049F910
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
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
extern D2NpcEntryStrc gaNpcEntries_00726850[]; // 0x00726850
void __cdecl sub_00487C20(); // 0x00487C20
void __cdecl sub_00487C60(); // 0x00487C60
int __cdecl sub_00487CA0_SetNpcState6(); // 0x00487CA0
int __cdecl sub_00489870(); // 0x00489870
void __cdecl sub_0048A630(); // 0x0048A630
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
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
D2UnitStrc* __cdecl sub_004B1620_GetInteractNpc(); // 0x004B1620
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
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

static __forceinline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
}

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
