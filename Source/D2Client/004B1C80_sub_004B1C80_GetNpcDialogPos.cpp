struct Unicode
{
    unsigned short wChar;
};

struct D2ViewStrc;
struct D2InventoryStrc;
struct D2ClientDialogStrc;
struct D2TextHeaderStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
};

struct D2NpcMenuSlotStrc
{
    unsigned short wId;
    char unk0x02[0x0E];
};

#pragma pack(push, 2)
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

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                       // 0x00620900
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY);                           // 0x004760C0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
D2TextHeaderStrc* __cdecl sub_0049F900();                                                                   // 0x0049F900
const Unicode* __fastcall sub_0049F910_GetString(unsigned short nStringId);                                 // 0x0049F910
int __stdcall TEXT_GetMenuType2NodeCount(D2TextHeaderStrc* pTextHeader);                                    // 0x00661390
short __stdcall TEXT_GetStringIdOfMenuType2Node(D2TextHeaderStrc* pTextHeader, int nNodeId);               // 0x006613C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                 // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                             // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                            // 0x0063DFA0
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);                                                         // 0x00628590
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue);                                                     // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8);                                                                   // 0x004B85F0
int __cdecl sub_004B1A80();                                                                                 // 0x004B1A80
int __cdecl sub_004B1B80();                                                                                 // 0x004B1B80
int __cdecl sub_004B1C00();                                                                                 // 0x004B1C00
int __cdecl sub_004B1DC0();                                                                                 // 0x004B1DC0
int __cdecl sub_004B4010();                                                                                 // 0x004B4010
int __cdecl sub_004B4070();                                                                                 // 0x004B4070
int __cdecl sub_004B41C0();                                                                                 // 0x004B41C0
int __cdecl sub_004B41E0();                                                                                 // 0x004B41E0
int __cdecl sub_004B4290();                                                                                 // 0x004B4290
int __cdecl sub_004B5810();                                                                                 // 0x004B5810
int __cdecl sub_004B5850();                                                                                 // 0x004B5850

extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
extern int gnGlobal_007C0C60;                                                                               // 0x007C0C60
extern int gnGlobal_007C0C64;                                                                               // 0x007C0C64
extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern int gnGlobal_007C0C81;                                                                               // 0x007C0C81
extern D2NpcMenuSlotStrc gaSlots_007C0C85[];                                                                // 0x007C0C85
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern int gdwGlobal_007C0D2D;                                                                              // 0x007C0D2D
extern int gnGlobal_007C0D31;                                                                               // 0x007C0D31
extern unsigned long gdwGlobal_007C0D53;                                                                    // 0x007C0D53
extern int gnGlobal_007C0D57;                                                                               // 0x007C0D57
extern D2ClientDialogStrc* gpDialog_007C0D67;                                                               // 0x007C0D67
extern D2ClientDialogStrc* gpDialog_007C0D6B;                                                               // 0x007C0D6B
extern D2ClientDialogStrc* gpDialog_007C0D6F;                                                               // 0x007C0D6F
extern D2ClientDialogStrc* gpDialog_007C0D73;                                                               // 0x007C0D73
extern D2ClientDialogStrc* gpDialog_007C0D77;                                                               // 0x007C0D77
extern D2NpcTradeObjStrc* gpTradeObj_007C0D83;                                                              // 0x007C0D83
extern int gnGlobal_007C0D96;                                                                               // 0x007C0D96
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850

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
    sub_004786A0_SendIntInt(0x36, gnGlobal_007C0C64, gaSlots_007C0C85[gnGlobal_007C0C60].wId);

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
        sub_004B85F0_AddTextLine(gpDialog_007C0D6F, sub_0049F910_GetString(nStringId), 0xF, 0, 0, 1, sub_004B1A80, 1);
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
