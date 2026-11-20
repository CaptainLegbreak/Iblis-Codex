#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2NpcMenuSlotStrc;

#pragma pack(push, 1)
struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0D];
    char bSelected;
    char bFlag;
    char unk0x13;
    char bFlag14;
    char bRefreshed;
};

#pragma pack(pop)


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
extern char gbGlobal_007C0C69; // 0x007C0C69

struct Unicode
{
    unsigned short wChar;
};


struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
};

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
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
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

char gbGlobal_007C0C69; // 0x007C0C69

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
