struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2DifficultyLevelsTxt
{
    int dwResistPenalty;
};

struct D2MercStatLineStrc
{
    int nLeft;
    int nRight;
    int nY;
    int nMaxWidth;
    int nStatId;
};

struct D2ElemDamageStrc
{
    int nMinStat;
    int f_4;
    int nColor;
};

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40
int __cdecl sub_0044DCC0(); // 0x0044DCC0
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_00479080_GetPetLife(int nUnitId); // 0x00479080
void __stdcall sub_0048A7D0_DrawUnitName(D2UnitStrc* pUnit); // 0x0048A7D0
void __cdecl sub_0048A890_DrawPanelLabels(); // 0x0048A890
void __stdcall sub_0048B0A0(D2UnitStrc* pUnit); // 0x0048B0A0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __stdcall sub_00525FB0_FormatInt(Unicode* pOut, int nValue, int nSize); // 0x00525FB0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit); // 0x006223F0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0
int __stdcall STATES_CheckStateMaskArmBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A550
int __stdcall STATES_CheckStateMaskRFBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A570
int __stdcall STATES_CheckStateMaskRCBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A590
int __stdcall STATES_CheckStateMaskRLBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A5B0
int __stdcall STATES_CheckStateMaskRPBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A5D0
int __stdcall STATES_CheckStateMaskRFRedOnUnit(D2UnitStrc* pUnit); // 0x0063A610
int __stdcall STATES_CheckStateMaskRCRedOnUnit(D2UnitStrc* pUnit); // 0x0063A630
int __stdcall STATES_CheckStateMaskRLRedOnUnit(D2UnitStrc* pUnit); // 0x0063A650
int __stdcall STATES_CheckStateMaskRPRedOnUnit(D2UnitStrc* pUnit); // 0x0063A670
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

extern D2MercStatLineStrc gaMercStatLines_007221A8[12]; // 0x007221A8
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

static void sub_0048A990_DrawMercStats(D2UnitStrc* pUnit); // 0x0048A990

// 0x0048A990
static void sub_0048A990_DrawMercStats(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    const int nOldFont = sub_00502EF0(0);
    for (unsigned int i = 0; i < 12; ++i)
    {
        int nColor = 0;
        Unicode wszText[0x80];
        char szText[0x80];
        for (int k = 0; k < 0x80; k++)
            wszText[k].wChar = 0;
        int nValue = STATLIST_UnitGetStatValue(pUnit, gaMercStatLines_007221A8[i].nStatId, 0);
        const int nBase = STATLIST_GetUnitBaseStat(pUnit, gaMercStatLines_007221A8[i].nStatId, 0);
        if (nValue > nBase)
        {
            nColor = 3;
        }
        else if (nValue < nBase)
        {
            nColor = 1;
        }

        const int nLeft = gaMercStatLines_007221A8[i].nLeft + gnGlobal_007A2858;
        const int nRight = gaMercStatLines_007221A8[i].nRight + gnGlobal_007A2858;
        int nY = gaMercStatLines_007221A8[i].nY - gnGlobal_007A285C - 2;

        switch (gaMercStatLines_007221A8[i].nStatId)
        {
        case 6:
        {
            const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
            int nLife = sub_00479080_GetPetLife(sub_00451F50_GetUnitGUID(pUnit)) * nMaxLife / 100;
            if (!sub_00464820_IsDeadOrDying(pUnit) && nLife < 0)
            {
                nLife = 1;
            }
            SStrPrintf(szText, 0x80, "%d / %d", nLife, nMaxLife);
            sub_00526320_ToUnicode(wszText, szText, 0x80);
            if ((STATLIST_GetUnitBaseStat(pUnit, 7, 0) >> 8) < nMaxLife)
            {
                nColor = 3;
            }
            break;
        }
        case 0x15:
        {
            D2UnitStrc* pWeapon = 0;
            int nFlat = 0;
            int nPercent = STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
            const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
            const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
            if (nMinPercent + nPercent > 0)
            {
                nColor = 3;
            }
            else if (nMinPercent + nPercent < 0)
            {
                nColor = 1;
            }

            if (pUnit->pInventory)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, 4);
            }

            int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, 0x16, 0);
            if (pWeapon)
            {
                if (ITEMS_CheckWeaponIfTwoHanded(pWeapon))
                {
                    nValue -= STATLIST_UnitGetStatValue(pWeapon, 0x15, 0);
                    nMaxDamage -= STATLIST_UnitGetStatValue(pWeapon, 0x16, 0);
                    nValue += STATLIST_UnitGetStatValue(pUnit, 0x17, 0);
                    nMaxDamage += STATLIST_UnitGetStatValue(pUnit, 0x18, 0);
                }

                nFlat = ITEMS_GetStrengthBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFlat / 100;
                }

                nFlat = ITEMS_GetDexBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFlat / 100;
                }

                nPercent += SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, 0, 1);
                nFlat = STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, 0x6F, 0);
            }
            else
            {
                if (sub_00451F60_UnitClassId(pUnit) == 0x10F)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 2, 0);
                }
                else
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, 0, 0);
                }
            }

            if (nPercent <= -90)
            {
                nPercent = -90;
            }

            int nMin = (nMinPercent + nPercent + 100) * nValue / 100 + nFlat;
            int nMax = (nMaxPercent + nPercent + 100) * nMaxDamage / 100 + nFlat;

            const D2ElemDamageStrc aElem[4] =
            {
                { 0x30, 0x31, 1 },
                { 0x32, 0x33, 9 },
                { 0x34, 0x35, 3 },
                { 0x36, 0x37, 3 },
            };
            for (int k = 0; k < 4; ++k)
            {
                nValue = STATLIST_UnitGetStatValue(pUnit, aElem[k].nMinStat, 0);
                const int nElemMax = STATLIST_UnitGetStatValue(pUnit, aElem[k].f_4, 0);
                if (nValue || nElemMax)
                {
                    nColor = aElem[k].nColor;
                }
                nMin += nValue;
                nMax += nElemMax;
            }

            nValue = STATLIST_UnitGetStatValue(pUnit, 0x39, 0);
            nFlat = STATLIST_UnitGetStatValue(pUnit, 0x3A, 0);
            if (nValue || nFlat)
            {
                int nLength = STATLIST_UnitGetStatValue(pUnit, 0x65, 0);
                if (nLength <= 0)
                {
                    int nCount = STATLIST_UnitGetStatValue(pUnit, 0x146, 0);
                    if (nCount < 1)
                    {
                        nCount = 1;
                    }
                    nLength = STATLIST_UnitGetStatValue(pUnit, 0x3B, 0) / nCount;
                }
                nMin += (nLength * nValue) >> 8;
                nColor = 2;
                nMax += (nLength * nFlat) >> 8;
            }

            SStrPrintf(szText, 0x80, "%d-%d", nMin, nMax);
            sub_00526320_ToUnicode(wszText, szText, 0x80);
            break;
        }
        case 0x1F:
        {
            const int nDefense = UNITS_GetDefense(pUnit);
            if (STATES_CheckStateMaskArmBlueOnUnit(pUnit))
            {
                nColor = 3;
            }
            sub_00525FB0_FormatInt(wszText, nDefense, 0x80);
            break;
        }
        case 0x27:
        case 0x29:
        case 0x2B:
        case 0x2D:
        {
            D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(sub_0044DCD0_GetDifficulty());
            int nMaxResist = 0;
            switch (gaMercStatLines_007221A8[i].nStatId)
            {
            case 0x27:
                if (STATES_CheckStateMaskRFBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRFRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x28, 0);
                break;
            case 0x29:
                if (STATES_CheckStateMaskRLBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRLRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x2A, 0);
                break;
            case 0x2B:
                if (STATES_CheckStateMaskRCBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRCRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x2C, 0);
                break;
            case 0x2D:
                if (STATES_CheckStateMaskRPBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRPRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, 0x2E, 0);
                break;
            }

            if (sub_0044DCC0())
            {
                nValue += pDifficulty->dwResistPenalty;
            }
            else
            {
                switch (sub_0044DCD0_GetDifficulty())
                {
                case 1:
                    nValue -= 20;
                    break;
                case 2:
                    nValue -= 50;
                    break;
                }
            }

            nMaxResist = D2_MIN(nMaxResist + 75, 95);
            nValue = D2_MIN(D2_MAX(nValue, -100), nMaxResist);
            if (nValue >= nMaxResist)
            {
                nValue = nMaxResist;
                nColor = 4;
            }
            else if (nValue < 0)
            {
                nColor = 1;
            }
            sub_00525FB0_FormatInt(wszText, nValue, 0x80);
            break;
        }
        default:
            sub_00525FB0_FormatInt(wszText, nValue, 0x80);
            break;
        }

        sub_00502EF0(0);
        int nWidth = 0;
        int nHeight = 0;
        D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
        if (gaMercStatLines_007221A8[i].nMaxWidth && nWidth > gaMercStatLines_007221A8[i].nMaxWidth)
        {
            sub_00502EF0(6);
            ++nY;
        }

        if (!gaMercStatLines_007221A8[i].nLeft)
        {
            sub_00502320(wszText, nRight - sub_00501820(wszText), nY, nColor, 0);
        }
        else if (!gaMercStatLines_007221A8[i].nRight)
        {
            sub_00502320(wszText, nLeft, nY, nColor, 0);
        }
        else
        {
            sub_004A7080(nLeft, nY, nRight, wszText, nColor);
        }
    }
    sub_00502EF0(nOldFont);
}

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

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY);                             // 0x0046EE80
void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY);            // 0x00483E40
void __stdcall sub_0048B0A0(D2UnitStrc* pUnit);                                                             // 0x0048B0A0
void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit);                                    // 0x0048B3F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem);                                             // 0x0062BC20
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2InventoryGridInfoStrc gInventoryGrid_007BCBC0;                                                            // 0x007BCBC0
extern D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4
extern D2BodyLocRectStrc gaBodyLocRects_007BCD38[11];                                                       // 0x007BCD38

// 0x0048B540
static void sub_0048B540_DrawEquippedItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem)
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            const int nX = gaBodyLocRects_007BCD38[i].nLeft
                + (gaBodyLocRects_007BCD38[i].nWidth - nWidth * gInventoryGrid_007BCBC0.nGridBoxWidth) / 2;
            const int nY = gaBodyLocRects_007BCD38[i].nTop
                + (gaBodyLocRects_007BCD38[i].nHeight - nHeight * gInventoryGrid_007BCBC0.nGridBoxWidth) / 2;
            sub_0046EE80_DrawCursorItem(pItem, nX, nY);
            if (gdwGlobal_007BCBF4 == pItem && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0
                && ITEMS_CheckItemFlag(pItem, 0x800, 0x30C8, ".\\UI\\inv.cpp"))
            {
                sub_00483E40(pItem, &gInventoryGrid_007BCBC0, nX, nY);
            }
        }
    }
}

struct D2CelFileStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int nDirection;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
D2CelFileStrc* __cdecl sub_00454600_GetBuySellButtonCells();                                               // 0x00454600
void __fastcall sub_00455F20(int nUIState, int eState, int nUnknown);                                 // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int nIndex);                 // 0x00478F20
void __cdecl sub_004835B0_LoadUiRecords();                                                                  // 0x004835B0
void __stdcall sub_0048A7D0_DrawUnitName(D2UnitStrc* pUnit);                                                // 0x0048A7D0
void __cdecl sub_0048A890_DrawPanelLabels();                                                                // 0x0048A890
void __stdcall sub_0048B0A0(D2UnitStrc* pUnit);                                                             // 0x0048B0A0
void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit);                                   // 0x0048B3F0
void __stdcall sub_0048DD90(D2UnitStrc* pUnit, int nArg);                                                   // 0x0048DD90
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int nDrawMode, int nPalette); // 0x004F6480

extern int gnScreenHeight_00711470;                                                                         // 0x00711470
extern int gnPanelX_007A2858;                                                                               // 0x007A2858
extern int gnPanelY_007A285C;                                                                               // 0x007A285C
extern D2CelFileStrc* gpMercPanelCells_007BCE88;                                                            // 0x007BCE88
extern int gbBuySellPressed_007BCEA0;                                                                       // 0x007BCEA0

// 0x004929F0
void __cdecl sub_004929F0_DrawMercPanel()
{
    if (!sub_0044DCC0())
    {
        return;
    }

    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if ((unsigned int)nPetId == 0xFFFFFFFF)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pMerc = sub_00463990(nPetId, 1);
    if (!pMerc)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    sub_004835B0_LoadUiRecords();

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpMercPanelCells_007BCE88;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858, gnScreenHeight_00711470 + gnPanelY_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858 + 0x100, gnScreenHeight_00711470 + gnPanelY_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858, gnScreenHeight_00711470 + gnPanelY_007A285C - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858 + 0x100, gnScreenHeight_00711470 + gnPanelY_007A285C - 0x30, -1, 5, 0);

    tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
    tContext.nFrame = (gbBuySellPressed_007BCEA0 != 0) + 10;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858 + 0x110, gnScreenHeight_00711470 + gnPanelY_007A285C - 0x3F, -1, 5, 0);

    sub_0048A7D0_DrawUnitName(pMerc);
    sub_0048A890_DrawPanelLabels();
    sub_0048A990_DrawMercStats(pMerc);
    sub_0048B0A0(pMerc);
    sub_0048B540_DrawEquippedItems(pMerc);
    sub_0048B3F0_DrawMercEquipHighlights(pMerc);
    sub_0048DD90(pMerc, 0);
}
