struct D2InventoryStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2UnitStrc
{
    char unk0x00[0xC];
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x12[2];
};

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId);                                                // 0x00479120
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc);                                     // 0x0062ED50
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
extern D2BodyLocRectStrc gaBodyLocRects_007BCD38[11];                                                       // 0x007BCD38
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern unsigned char gbGlobal_007BCAD8;                                                                     // 0x007BCAD8
extern unsigned char gbGlobal_007BCAD9;                                                                     // 0x007BCAD9
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                        // 0x00478F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __stdcall sub_00467FA0(SMSGHANDLER_PARAMS* pMsg);                                                      // 0x00467FA0
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                            // 0x00420290
void __fastcall sub_004C21F0(D2UnitStrc* pItem);                                                            // 0x004C21F0
int __fastcall sub_004C1D60(D2UnitStrc* pItem);                                                             // 0x004C1D60
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                           // 0x004785B0
void __fastcall sub_004CBDE0_PetCommand(int nPetId, char bFlag, int nSkill);                                // 0x004CBDE0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007BCEA0;                                                                               // 0x007BCEA0
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4

// build: symbol ?sub_0048B290@@YGHPAUD2UnitStrc@@0PAH@Z 0x0048B290
static int __stdcall sub_0048B290(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pbSlotMatch)
{
    *pbSlotMatch = 0;
    if (!sub_0044DCC0())
        return 0;
    int bResult = 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x302C, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x302F, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemTypeId(pItem, 3) || ITEMS_CheckItemTypeId(pItem, 0x25))
    {
        bResult = 1;
        *pbSlotMatch = bResult;
    }
    switch (sub_00479120_GetHirelingClassId(!pUnit ? -1 : pUnit->dwUnitId))
    {
    case 0x10F:
        if (ITEMS_CheckItemTypeId(pItem, 0x1B))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x152:
        if (ITEMS_CheckItemTypeId(pItem, 0x21) || ITEMS_CheckItemTypeId(pItem, 0x22))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x167:
        if (ITEMS_CheckItemTypeId(pItem, 2))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x230:
        if (ITEMS_CheckItemTypeId(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x231:
        if (ITEMS_CheckItemTypeId(pItem, 0x1E))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMS_CheckItemTypeId(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    }
    if (bResult && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        bResult = 0;
    return bResult;
}

static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

static __forceinline void DrawBodyLocRectInline(D2BodyLocRectStrc* pRect, int nColor)
{
    const int nX = pRect->nLeft;
    const int nY = pRect->nTop;
    if (nX >= 0 && nX < gnAutomapWidth_007A5220 && nY >= 0 && nY < gnAutomapHeight_007A521C)
        sub_0046EFD0_DrawFramedBox(nX, nY, pRect->nWidth, pRect->nHeight, nColor, 0);
}

void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit)
{
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    if (!pCursorItem)
        return;
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects_007BCD38[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects_007BCD38[i].nLeft, gaBodyLocRects_007BCD38[i].nTop, gaBodyLocRects_007BCD38[i].nRight, gaBodyLocRects_007BCD38[i].nBottom))
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            int bMatch;
            if (ITEMS_CheckBodyLocation(pCursorItem, i) && sub_0048B290(pUnit, pCursorItem, &bMatch) && ITEMS_CheckRequirements(pCursorItem, pUnit, 0, 0, 0, 0))
                DrawBodyLocRectInline(&gaBodyLocRects_007BCD38[i], gbGlobal_007BCAD9);
            else
                DrawBodyLocRectInline(&gaBodyLocRects_007BCD38[i], gbGlobal_007BCAD8);
        }
    }
}

static __forceinline int INV_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x0048B7C0
void __stdcall sub_0048B7C0_HandleMercInvClick(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
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
    sub_00467FA0(pMsg);
    gnGlobal_007BCEA0 = 0;
    if (!IsCursorInRectInline(0, 0, gnGlobal_0071146C / 2, gnGlobal_00711470 - 0x31))
    {
        return;
    }

    if (IsCursorInRectInline(gnGlobal_007A2858 + 0x110, gnGlobal_007A285C + gnGlobal_00711470 - 0x5F, gnGlobal_007A2858 + 0x130, gnGlobal_007A285C + gnGlobal_00711470 - 0x3F))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00455F20(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects_007BCD38[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects_007BCD38[i].nLeft, gaBodyLocRects_007BCD38[i].nTop, gaBodyLocRects_007BCD38[i].nRight, gaBodyLocRects_007BCD38[i].nBottom))
        {
            if (pCursorItem)
            {
                int bSlotMatch = 0;
                if (ITEMS_CheckBodyLocation(pCursorItem, i) && ITEMS_CheckRequirements(pCursorItem, pPet, 0, 0, 0, 0) && sub_0048B290(pPet, pCursorItem, &bSlotMatch))
                {
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    sub_004785B0_SendPacket3(0x61, 0);
                }
                else if (ITEMS_CheckBodyLocation(pCursorItem, i) && sub_0048B290(pPet, pCursorItem, &bSlotMatch) && bSlotMatch)
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x56);
                }
                else
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x55);
                }

                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }

            if (pPet->pInventory)
            {
                D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPet->pInventory, i);
                if (pItem)
                {
                    sub_004C21F0(pItem);
                    sub_004785B0_SendPacket3(0x61, i);
                    gdwGlobal_007BCBE4 = 0;
                    gdwGlobal_007BCBE8 = 0;
                    gdwGlobal_007BCBF4 = 0;
                }
            }
        }
    }

    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}
