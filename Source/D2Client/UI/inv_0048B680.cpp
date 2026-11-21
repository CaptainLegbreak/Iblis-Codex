#include "D2Client.h"
#include "D2Structs.h"
#include "D2StormTypes.h"

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    int unk0x10;
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

int __cdecl sub_00468730();                                                                                 // 0x00468730

int __cdecl sub_00468740();                                                                                 // 0x00468740

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20

void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990

int __stdcall sub_0048A790_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom);                    // 0x0048A790

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C

extern int gnGlobal_00721E40;                                                                               // 0x00721E40

extern int gnGlobal_00721E44;                                                                               // 0x00721E44

extern int gnGlobal_00721E48;                                                                               // 0x00721E48

extern int gnGlobal_007A2858;                                                                               // 0x007A2858

extern int gnGlobal_007A285C;                                                                               // 0x007A285C

extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8

extern D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4

extern D2UnitStrc* gdwGlobal_007BCBF8;                                                                      // 0x007BCBF8

extern D2BodyLocRectStrc gaBodyLocRects_007BCD38[11];                                                       // 0x007BCD38

int gnGlobal_007BCEA0;                                                                                      // 0x007BCEA0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

struct D2CelFileStrc* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                          // 0x004520C0

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

int __fastcall sub_00502EF0(int nSize);                                                                     // 0x00502EF0

enum D2C_UIvars
{
    UI_GAME = 0x00,
    UI_INVENTORY = 0x01,
    UI_STATSCREEN = 0x02,
    UI_MINISKILL = 0x03,
    UI_SKILLTREE = 0x04,
    UI_CHATBOX = 0x05,
    UI_NEWSTATS = 0x06,
    UI_NEWSKILLS = 0x07,
    UI_NPCMENU = 0x08,
    UI_ESCMENU = 0x09,
    UI_AUTOMAP = 0x0A,
    UI_CONFIG = 0x0B,
    UI_NPCSHOP = 0x0C,
    UI_HOLDALT = 0x0D,
    UI_ANVIL = 0x0E,
    UI_QUESTSCREEN = 0x0F,
    UI_INISCROLL = 0x10,
    UI_QUESTLOG = 0x11,
    UI_UNKNOWN18 = 0x12,
    UI_HIRICONS = 0x13,
    UI_WAYPOINT = 0x14,
    UI_MINIPANEL = 0x15,
    UI_PARTYSCREEN = 0x16,
    UI_MPTRADE = 0x17,
    UI_MSGLOG = 0x18,
    UI_STASH = 0x19,
    UI_CUBE = 0x1A,
    UI_STEEGSTONE = 0x1B,
    UI_GUILDVAULT = 0x1C,
    UI_UNKNOWN29 = 0x1D,
    UI_UNKNOWN30 = 0x1E,
    UI_BELTROWS = 0x1F,
    UI_UNKNOWN32 = 0x20,
    UI_HELPSCREEN = 0x21,
    UI_HELPBUTTON = 0x22,
    UI_HIREICONS = 0x23,
    UI_MERCINV = 0x24,
    UI_RECIPESCROLL = 0x25
};

enum DrawMode
{
    DRAWMODE_TRANS25,
    DRAWMODE_TRANS50,
    DRAWMODE_TRANS75,
    DRAWMODE_MODULATE,
    DRAWMODE_BURN,
    DRAWMODE_NORMAL,
    DRAWMODE_TRANSHIGHLIGHT,
    DRAWMODE_HIGHLIGHT
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    int unk0x24;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    struct D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int nGamma, DrawMode eDrawMode, unsigned char* pPalette); // 0x004F6480

void __fastcall sub_00502320(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320

extern struct D2CelFileStrc* gpRecipeScrollCel_007BCE8C;                                                  // 0x007BCE8C

extern int gnRecipeScrollColor_007BCEA4;                                                                    // 0x007BCEA4

extern unsigned short gwszRecipeScrollText_007BCEA8[];                                                      // 0x007BCEA8

static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

// 0x0048B680
void __stdcall sub_0048B680_MercPanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    if (!sub_00463990(nPetId, 1))
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    if (!IsCursorInRectInline(0, 0, gnGlobal_0071146C / 2, gnGlobal_00711470 - 0x31))
    {
        return;
    }

    if (IsCursorInRectInline(gnGlobal_007A2858 + 0x110, gnGlobal_007A285C + gnGlobal_00711470 - 0x5F, gnGlobal_007A2858 + 0x130, gnGlobal_007A285C + gnGlobal_00711470 - 0x3F))
    {
        gnGlobal_007BCEA0 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0048BA50
void __stdcall sub_0048BA50_MercPanelHoverMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pPet = sub_00463990(nPetId, 1);
    if (!pPet)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    if (!IsCursorInRectInline(0, 0, gnGlobal_0071146C / 2, gnGlobal_00711470 - 0x31))
    {
        return;
    }

    if (gnGlobal_007BCEA0 && !sub_0048A790_IsCursorInRect(gnGlobal_007A2858 + 0x110, gnGlobal_007A285C + gnGlobal_00711470 - 0x5F, gnGlobal_007A2858 + 0x130, gnGlobal_007A285C + gnGlobal_00711470 - 0x3F))
    {
        gnGlobal_007BCEA0 = 0;
    }

    D2InventoryStrc* pInventory = pPet->pInventory;
    if (!pInventory)
    {
        return;
    }

    sub_00487990_ResetHover();
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects_007BCD38[i].nLeft > 0 && sub_0048A790_IsCursorInRect(gaBodyLocRects_007BCD38[i].nLeft, gaBodyLocRects_007BCD38[i].nTop, gaBodyLocRects_007BCD38[i].nRight, gaBodyLocRects_007BCD38[i].nBottom))
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (pItem)
            {
                gdwGlobal_007BCBE8 = 1;
                if (pItem != gdwGlobal_007BCBF8)
                {
                    gdwGlobal_007BCBF4 = pItem;
                    gnGlobal_00721E3C = (gaBodyLocRects_007BCD38[i].nLeft + gaBodyLocRects_007BCD38[i].nRight) / 2;
                    gnGlobal_00721E44 = gnGlobal_00721E3C;
                    gnGlobal_00721E40 = gaBodyLocRects_007BCD38[i].nTop;
                    gnGlobal_00721E48 = gaBodyLocRects_007BCD38[i].nBottom;
                    gdwGlobal_007BCBF8 = pItem;
                }
            }
        }
    }
}

// 0x0048BC10
void __stdcall sub_0048BC10()
{
    D2CelContextStrc tContext;

    if (!sub_0044DCC0() || !sub_004538D0(UI_RECIPESCROLL))
    {
        return;
    }

    if (!gpRecipeScrollCel_007BCE8C)
    {
        gpRecipeScrollCel_007BCE8C = sub_004520C0_LoadUiCelFile("menu\\recipescroll");
        if (!gpRecipeScrollCel_007BCE8C)
        {
            return;
        }
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpRecipeScrollCel_007BCE8C;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 256, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 256, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, DRAWMODE_NORMAL, 0);

    const int nOldSize = sub_00502EF0(4);
    sub_00502320(gwszRecipeScrollText_007BCEA8, gnGlobal_007A2858 + 80, 130 - gnGlobal_007A285C, gnRecipeScrollColor_007BCEA4, 0);
    sub_00502EF0(nOldSize);
}
