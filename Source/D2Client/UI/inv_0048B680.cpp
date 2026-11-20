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
