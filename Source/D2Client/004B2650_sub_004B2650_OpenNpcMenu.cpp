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
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    unsigned short wMode;
    char unk0x12[0x4E];
    D2InventoryStrc* pInventory;
};

struct D2ItemsTxt
{
    char unk0x000[0x1A5];
    unsigned char nField1A5;
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

void __cdecl sub_00487C20();                                                                                // 0x00487C20
void __cdecl sub_00487C60();                                                                                // 0x00487C60
void __cdecl sub_00487CA0();                                                                                // 0x00487CA0
int __cdecl sub_00489870();                                                                                 // 0x00489870
void __cdecl sub_0048A630();                                                                                // 0x0048A630
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3);      // 0x00478700
int __fastcall sub_004C1D60(D2UnitStrc* pItem);                                                             // 0x004C1D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

extern int gnGlobal_007C0D3F;                                                                               // 0x007C0D3F
extern int gnGlobal_007C0D5B;                                                                               // 0x007C0D5B
extern int gnGlobal_007C0D7F;                                                                               // 0x007C0D7F
extern int gnGlobal_007C0DB0;                                                                               // 0x007C0DB0
extern D2UnitStrc* gpPlayer_007C0DD4;                                                                       // 0x007C0DD4
extern char gbGlobal_007C0DE0;                                                                              // 0x007C0DE0
extern int gnGlobal_007C0DE5;                                                                               // 0x007C0DE5
extern unsigned long gdwGlobal_007C0DE9;                                                                    // 0x007C0DE9
extern int gnGlobal_007C0DED;                                                                               // 0x007C0DED
extern unsigned long gdwGlobal_007C0DF1;                                                                    // 0x007C0DF1
extern unsigned long gdwGlobal_007C0E48;                                                                    // 0x007C0E48

static __forceinline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
}

static int sub_004B1C80_GetNpcDialogPos(D2CoordStrc* pCoords); // 0x004B1C80

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
            nMode = pUnit->wMode;
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
        sub_00487CA0();
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
