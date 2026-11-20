#include "D2Client.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"

struct D2CellFileStrc;

struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall win2Unicode(Unicode* pDest, const char* szSource, int nCount);           // 0x00526F20
};

struct UnicodeChar : Unicode
{
    void sub_0042F530_ClearUnicode();                                                                      // 0x0042F530
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

void __stdcall sub_00403040_ConstructArray(void* pArray, unsigned int nSize, int nCount, void (UnicodeChar::*pfnConstruct)()); // 0x00403040
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
D2CellFileStrc* __cdecl sub_00454600_GetBuySellButtonCells(); // 0x00454600
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                           // 0x00463DD0
int __cdecl sub_00463DF0();                                                                    // 0x00463DF0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
char* __fastcall sub_0047A210_GetUnitName(D2UnitStrc* pUnit); // 0x0047A210
void __cdecl sub_004835B0_LoadUiRecords();                                                                  // 0x004835B0
void __stdcall sub_00483FF0_DrawUnitInventory(D2UnitStrc* pPlayer);                                             // 0x00483FF0
void __cdecl sub_004845A0_DrawEquippedItems();                                                                                // 0x004845A0
int __cdecl sub_00486AE0_GetPanelX(); // 0x00486AE0
int __stdcall sub_00486B00_GetPanelY();                                                                     // 0x00486B00
void __stdcall sub_00487A10_SelectItemPageTab(unsigned char nTab);                                          // 0x00487A10
void __fastcall sub_00488100(int nArg);                                                                     // 0x00488100
void __cdecl sub_00488400_DrawPanel();                                                                                // 0x00488400
void __cdecl sub_004886C0_DrawButtonHoverText();                                                            // 0x004886C0
void __stdcall sub_0048DD90_DrawItemTooltip(D2UnitStrc* pUnit, int bOther);                                   // 0x0048DD90
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
const Unicode* __cdecl sub_004B9060();                                                                      // 0x004B9060
int __cdecl sub_004B90F0();                                                                                 // 0x004B90F0
int __cdecl sub_004B9100();                                                                                 // 0x004B9100
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nPaletteShift); // 0x004F64B0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);   // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
extern "C" Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                          // 0x005267E0
extern "C" int __fastcall sub_00526800(const Unicode* pString);                                           // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __stdcall sub_00623460(D2UnitStrc* pUnit);                                                            // 0x00623460
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007220B0;                                                                               // 0x007220B0
extern int gnGlobal_007220B4;                                                                               // 0x007220B4
extern int gnGlobal_007220B8;                                                                               // 0x007220B8
extern int gnGlobal_007220BC;                                                                               // 0x007220BC
extern int gnGlobal_007220C0;                                                                               // 0x007220C0
extern int gnGlobal_007220C4;                                                                               // 0x007220C4
extern int gnGlobal_007220C8;                                                                               // 0x007220C8
extern int gnGlobal_007220CC;                                                                               // 0x007220CC
extern int gnGlobal_007220D0;                                                                               // 0x007220D0
extern int gnGlobal_007220D4;                                                                               // 0x007220D4
extern int gnGlobal_007220D8;                                                                               // 0x007220D8
extern int gnGlobal_007220DC;                                                                               // 0x007220DC
extern int gnGlobal_007220E0;                                                                               // 0x007220E0
extern int gnGlobal_007220E4;                                                                               // 0x007220E4
extern int gnGlobal_007220E8;                                                                               // 0x007220E8
extern int gnGlobal_007220EC;                                                                               // 0x007220EC
extern int gnGlobal_007220F0;                                                                               // 0x007220F0
extern int gnGlobal_007220F4;                                                                               // 0x007220F4
extern int gnGlobal_007220F8;                                                                               // 0x007220F8
extern int gnGlobal_007220FC;                                                                               // 0x007220FC
extern int gnGlobal_00722100;                                                                               // 0x00722100
extern int gnGlobal_00722104;                                                                               // 0x00722104
extern int gnGlobal_00722108;                                                                               // 0x00722108
extern int gnGlobal_0072210C;                                                                               // 0x0072210C
int gnGlobal_007A2858;                                                                                      // 0x007A2858
int gnGlobal_007A285C;                                                                                      // 0x007A285C

static void* gpCellFile_007BCB04;                                                                           // 0x007BCB04
static int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
static unsigned char gnSelectedTab_007BCC04;                                                                // 0x007BCC04
static unsigned long gdwGlobal_007BCC08;                                                                    // 0x007BCC08
static int gnGlobal_007BCC0C;                                                                               // 0x007BCC0C
static int gbQuestTimerActive_007BCC10;                                                                     // 0x007BCC10
static unsigned int gnQuestTimerValue_007BCC14;                                                             // 0x007BCC14
static unsigned long gdwQuestTimerTicks_007BCC18;                                                           // 0x007BCC18
static void* gpHoradricCel_007BCC1C;                                                                        // 0x007BCC1C
static void* gpCellFile_007BCC28;                                                                           // 0x007BCC28
static void* gpCellFile_007BCC2C;                                                                           // 0x007BCC2C
static void* gpCellFile_007BCC30;                                                                           // 0x007BCC30
static void* gpCellFile_007BCC3C;                                                                           // 0x007BCC3C
static int gnGlobal_007BCC4C;                                                                               // 0x007BCC4C

D2InvCompGridStrc gaCompGrids_007BCC58[11];                                                                 // 0x007BCC58
#define gnGlobal_007BCC6C (gaCompGrids_007BCC58[1].rect.nLeft)
#define gnGlobal_007BCC78 (gaCompGrids_007BCC58[1].rect.nBottom)
#define gnGlobal_007BCC80 (gaCompGrids_007BCC58[2].rect.nLeft)
#define gnGlobal_007BCC8C (gaCompGrids_007BCC58[2].rect.nBottom)
#define gnGlobal_007BCC94 (gaCompGrids_007BCC58[3].rect.nLeft)
#define gnGlobal_007BCCA0 (gaCompGrids_007BCC58[3].rect.nBottom)
#define gnGlobal_007BCCA8 (gaCompGrids_007BCC58[4].rect.nLeft)
#define gnGlobal_007BCCB4 (gaCompGrids_007BCC58[4].rect.nBottom)
#define gnGlobal_007BCCBC (gaCompGrids_007BCC58[5].rect.nLeft)
#define gnGlobal_007BCCC8 (gaCompGrids_007BCC58[5].rect.nBottom)
#define gnGlobal_007BCCD0 (gaCompGrids_007BCC58[6].rect.nLeft)
#define gnGlobal_007BCCDC (gaCompGrids_007BCC58[6].rect.nBottom)
#define gnGlobal_007BCCE4 (gaCompGrids_007BCC58[7].rect.nLeft)
#define gnGlobal_007BCCF0 (gaCompGrids_007BCC58[7].rect.nBottom)
#define gnGlobal_007BCCF8 (gaCompGrids_007BCC58[8].rect.nLeft)
#define gnGlobal_007BCD04 (gaCompGrids_007BCC58[8].rect.nBottom)
#define gnGlobal_007BCD0C (gaCompGrids_007BCC58[9].rect.nLeft)
#define gnGlobal_007BCD18 (gaCompGrids_007BCC58[9].rect.nBottom)
#define gnGlobal_007BCD20 (gaCompGrids_007BCC58[10].rect.nLeft)
#define gnGlobal_007BCD2C (gaCompGrids_007BCC58[10].rect.nBottom)
static int gnGlobal_007BCD34;                                                                               // 0x007BCD34
static int gnGlobal_007BCE14;                                                                               // 0x007BCE14
static int gnGlobal_007BCE18;                                                                               // 0x007BCE18
static int gnGlobal_007BCE1C;                                                                               // 0x007BCE1C
static int gnFlag_007BCE28;                                                                                 // 0x007BCE28
static int gnGlobal_007BCE38;                                                                               // 0x007BCE38
static int gnGlobal_007BCE40;                                                                               // 0x007BCE40
static int gnGlobal_007BCE48;                                                                               // 0x007BCE48
static void* gpCelInvArmor_007BCE68;                                                                        // 0x007BCE68
static void* gpCelInvBelt_007BCE6C;                                                                         // 0x007BCE6C
static void* gpCelInvBoots_007BCE70;                                                                        // 0x007BCE70
static void* gpCelInvHelmGlove_007BCE74;                                                                    // 0x007BCE74
static void* gpCelInvRingAmulet_007BCE78;                                                                   // 0x007BCE78
static void* gpCelInvWeapons_007BCE7C;                                                                      // 0x007BCE7C
static void* gpCelInvChar6Tab_007BCE84;                                                                     // 0x007BCE84
static int gbGlobal_007BCE90;                                                                               // 0x007BCE90

static int sub_00489FB0_IsOverButtonC(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x113 && nX < gnGlobal_007A2858 + 0x13B
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x64 && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        return 1;
    }
    return 0;
}

static int sub_0048A000_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnGlobal_007A2858 + 0x90 && nX < gnGlobal_007A2858 + 0xB8
        && nY > gnGlobal_00711470 + gnGlobal_007A285C - 0xDF && nY < gnGlobal_00711470 + gnGlobal_007A285C - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x0048EDF0
void __cdecl sub_0048EDF0_DrawInventoryPanel()
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    if (gdwGlobal_007BCBF0 == 10)
    {
        return;
    }

    if (gdwGlobal_007BCBF0 >= 1 && gdwGlobal_007BCBF0 <= 9)
    {
        if (GetTickCount() > gdwGlobal_007BCC08)
        {
            gdwGlobal_007BCC08 = 0;
        }
        int nTick;
        if (gnGlobal_007BCC0C == 1 && !gdwGlobal_007BCC08 && sub_004B3230_GetTickPair(&nTick))
        {
            sub_00487A10_SelectItemPageTab(gnSelectedTab_007BCC04);
            gnGlobal_007BCC0C = 0;
        }
        sub_00488400_DrawPanel();
        sub_00488100(2);
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;

    switch (gdwGlobal_007BCBF0)
    {
    case 14:
        if (!sub_0044DA30() && !sub_00463DF0())
        {
            if (gpCellFile_007BCC30)
            {
                tContext.pCellFile = gpCellFile_007BCC30;
                tContext.nFrame = 0;
                TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
                tContext.nFrame = 1;
                TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
                tContext.nFrame = 2;
                TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
                tContext.nFrame = 3;
                TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
            }

            const unsigned char nOldTab = gnSelectedTab_007BCC04;
            if (!gbQuestTimerActive_007BCC10 || gnQuestTimerValue_007BCC14 >= 14)
            {
                gnSelectedTab_007BCC04 = 3;
                sub_00483FF0_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
                gnSelectedTab_007BCC04 = nOldTab;
            }

            tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
            tContext.nFrame = gnGlobal_007BCE40 + 10;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x113, gnGlobal_00711470 + gnGlobal_007A285C - 0x41, -1, 5, 0);

            tContext.pCellFile = gpCellFile_007BCC28;
            tContext.nFrame = gnGlobal_007BCE48;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x90, gnGlobal_00711470 + gnGlobal_007A285C - 0xBC, -1, 5, 0);

            if (gbQuestTimerActive_007BCC10)
            {
                const unsigned long dwTick = GetTickCount();
                if (dwTick - gdwQuestTimerTicks_007BCC18 > 70)
                {
                    gdwQuestTimerTicks_007BCC18 = dwTick;
                    if (++gnQuestTimerValue_007BCC14 >= 30)
                    {
                        gbQuestTimerActive_007BCC10 = 0;
                        if (gpHoradricCel_007BCC1C)
                        {
                            sub_00478A00(gpHoradricCel_007BCC1C);
                            gpHoradricCel_007BCC1C = 0;
                        }
                        goto timer_done;
                    }
                }
                tContext.pCellFile = gpHoradricCel_007BCC1C;
                tContext.nFrame = gnQuestTimerValue_007BCC14;
                TEXTURE_CelDraw(&tContext, gnGlobal_0071146C / 2, gnGlobal_00711470 / 2 - 1, -1, 3, 0);
            }
timer_done:
            sub_00502EF0(1);

            if (sub_00489FB0_IsOverButtonC(nMouseX, nMouseY))
            {
                const Unicode* wszText = D2LANG_GetStringFromTblIndex(0x1030);
                D2Win_10129_DrawFramedText(wszText, gnGlobal_007A2858 - sub_00501820(wszText) / 2 + 0x121, gnGlobal_00711470 + gnGlobal_007A285C - 0x64, 0, 0);
            }
            else if (sub_0048A000_IsOverCubeButton(nMouseX, nMouseY))
            {
                const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xD0D);
                D2Win_10129_DrawFramedText(wszText, gnGlobal_007A2858 - sub_00501820(wszText) / 2 + 0x9E, gnGlobal_00711470 + gnGlobal_007A285C - 0xDF, 0, 0);
            }
        }
        else
        {
            sub_00455F20(0x1A, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x17, 0, 0);
            return;
        }
        break;

    case 12:
    case 13:
    {
        if (gpCellFile_007BCC2C)
        {
            if (sub_0044DCC0())
            {
                tContext.pCellFile = gpCellFile_007BCC3C;
            }
            else
            {
                tContext.pCellFile = gpCellFile_007BCC2C;
            }
            tContext.nFrame = 0;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
            tContext.nFrame = 1;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
            tContext.nFrame = 2;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
            tContext.nFrame = 3;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
        }

        const int nGoldLimit = sub_00623460(sub_00463DD0_GetPlayerUnit());
        int aGoldText[50];
        Unicode* wszGold = (Unicode*)aGoldText;
        sub_00403040_ConstructArray(wszGold, sizeof(Unicode), 100, &UnicodeChar::sub_0042F530_ClearUnicode);
        sub_005269D0(100, wszGold, D2LANG_GetStringFromTblIndex(0xFD3), nGoldLimit);
        if (sub_0044DCC0())
        {
            sub_00502320(wszGold, gnGlobal_007A2858 + 0x4E, gnGlobal_00711470 + gnGlobal_007A285C - 0x19F, 0, 0);
        }
        else
        {
            sub_00502320(wszGold, gnGlobal_007A2858 + 0x4E, gnGlobal_00711470 + gnGlobal_007A285C - 0xDB, 0, 0);
        }

        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        gnSelectedTab_007BCC04 = 4;
        sub_00483FF0_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
        gnSelectedTab_007BCC04 = nOldTab;

        tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
        tContext.nFrame = gnGlobal_007BCE38 + 10;
        const int nButtonX = !sub_0044DCC0() ? gnGlobal_007A2858 + 0x113 : gnGlobal_007A2858 + 0x110;
        TEXTURE_CelDraw(&tContext, nButtonX, sub_00486B00_GetPanelY(), -1, 5, 0);

        sub_00488100(0);
        const int nCursorX = sub_00468730();
        const int nCursorY = sub_00468740();
        const int nLeft = !sub_0044DCC0() ? gnGlobal_007A2858 + 0x113 : gnGlobal_007A2858 + 0x110;
        if (nCursorX >= nLeft && nCursorX <= sub_00486AE0_GetPanelX() + 0x28
            && nCursorY >= sub_00486B00_GetPanelY() - 0x23 && nCursorY <= sub_00486B00_GetPanelY() + 5)
        {
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0x1030);
            D2Win_10129_DrawFramedText(wszText, sub_00486AE0_GetPanelX() - sub_00501820(wszText) / 2 + 12, sub_00486B00_GetPanelY() - 0x23, 0, 0);
        }
        break;
    }
    }

    tContext.pCellFile = gpCellFile_007BEF64;
    tContext.nFrame = 4;
    TEXTURE_CelDraw(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 0x140, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 5;
    TEXTURE_CelDraw(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 0x40, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 6;
    TEXTURE_CelDraw(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 0x140, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
    tContext.nFrame = 7;
    TEXTURE_CelDraw(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 0x40, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);

    sub_004835B0_LoadUiRecords();

    if (gnGlobal_007BCC4C && sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        tContext.pCellFile = gpCelInvChar6Tab_007BCE84;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gnGlobal_00722108, gnGlobal_007BCCC8 + gnGlobal_0072210C, -1, 5, 0);
        tContext.pCellFile = gpCelInvChar6Tab_007BCE84;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gnGlobal_00722100, gnGlobal_007BCCB4 + gnGlobal_00722104, -1, 5, 0);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryStrc* pInventory = pPlayer->pInventory;

    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 3))
    {
        tContext.pCellFile = gpCelInvArmor_007BCE68;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCC94 + gnGlobal_007220B0, gnGlobal_007BCCA0 + gnGlobal_007220B4, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 8))
    {
        tContext.pCellFile = gpCelInvBelt_007BCE6C;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCF8 + gnGlobal_007220B8, gnGlobal_007BCD04 + gnGlobal_007220BC, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 9))
    {
        tContext.pCellFile = gpCelInvBoots_007BCE70;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCD0C + gnGlobal_007220C0, gnGlobal_007BCD18 + gnGlobal_007220C4, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 1))
    {
        tContext.pCellFile = gpCelInvHelmGlove_007BCE74;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCC6C + gnGlobal_007220C8, gnGlobal_007BCC78 + gnGlobal_007220CC, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 10))
    {
        tContext.pCellFile = gpCelInvHelmGlove_007BCE74;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCD20 + gnGlobal_007220D0, gnGlobal_007BCD2C + gnGlobal_007220D4, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 2))
    {
        tContext.pCellFile = gpCelInvRingAmulet_007BCE78;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCC80 + gnGlobal_007220D8, gnGlobal_007BCC8C + gnGlobal_007220DC, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 6))
    {
        tContext.pCellFile = gpCelInvRingAmulet_007BCE78;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCD0 + gnGlobal_007220E8, gnGlobal_007BCCDC + gnGlobal_007220EC, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 7))
    {
        tContext.pCellFile = gpCelInvRingAmulet_007BCE78;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCE4 + gnGlobal_007220E0, gnGlobal_007BCCF0 + gnGlobal_007220E4, -1, 5, 0);
    }

    int nOffsetX = 0;
    int nOffsetY = 0;
    if (sub_0044DCC0() && gnGlobal_007BCC4C)
    {
        nOffsetX = 4;
        nOffsetY = -4;
    }
    const int bRightHand = (int)INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    const int bLeftHand = (int)INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    const int bTwoHanded = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;

    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 5))
    {
        tContext.pCellFile = gpCelInvWeapons_007BCE7C;
        tContext.nFrame = 0;
        if (bRightHand)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gnGlobal_007220F8 + nOffsetX, gnGlobal_007BCCC8 + gnGlobal_007220FC + nOffsetY, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gnGlobal_007220F8 + nOffsetX, gnGlobal_007BCCC8 + gnGlobal_007220FC + nOffsetY, -1, 5, 0);
        }
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 4))
    {
        tContext.pCellFile = gpCelInvWeapons_007BCE7C;
        tContext.nFrame = 0;
        if (bLeftHand)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gnGlobal_007220F0 + nOffsetX, gnGlobal_007BCCB4 + gnGlobal_007220F4 + nOffsetY, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gnGlobal_007220F0 + nOffsetX, gnGlobal_007BCCB4 + gnGlobal_007220F4 + nOffsetY, -1, 5, 0);
        }
    }

    tContext.pCellFile = gpCelInvWeapons_007BCE7C;
    tContext.nFrame = 0;
    if (bRightHand && bLeftHand)
    {
        if (!bTwoHanded)
        {
            if (!INVENTORY_GetItemFromBodyLoc(pInventory, 5))
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gnGlobal_007220F8, gnGlobal_007BCCC8 + gnGlobal_007220FC, -1, 5, 0);
            }
            if (!INVENTORY_GetItemFromBodyLoc(pInventory, 4))
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gnGlobal_007220F0, gnGlobal_007BCCB4 + gnGlobal_007220F4, -1, 5, 0);
            }
        }
    }
    else if (!bRightHand && bLeftHand)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, 5))
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gnGlobal_007220F8, gnGlobal_007BCCC8 + gnGlobal_007220FC, -1, 5, 0);
        }
    }
    else if (bRightHand && !bLeftHand)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, 4))
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gnGlobal_007220F0, gnGlobal_007BCCB4 + gnGlobal_007220F4, -1, 5, 0);
        }
    }

    if (gdwGlobal_007BCBF0 == 11 && gpCellFile_007BCB04)
    {
        tContext.pCellFile = gpCellFile_007BCB04;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
        tContext.nFrame = 2;
        TEXTURE_CelDraw(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
        tContext.nFrame = 3;
        TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);

        tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
        if (gnGlobal_007BCE14)
        {
            tContext.nFrame = 17;
            TEXTURE_CelDrawColor(&tContext, gnGlobal_007A2858 + 0x113, gnGlobal_00711470 + gnGlobal_007A285C - 0x116, -1, 5, 2);
        }
        else
        {
            tContext.nFrame = 16;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x113, gnGlobal_00711470 + gnGlobal_007A285C - 0x116, -1, 5, 0);
        }

        if (gnFlag_007BCE28)
        {
            tContext.nFrame = 16;
            TEXTURE_CelDrawColor(&tContext, gnGlobal_007A2858 + 0xDF, gnGlobal_00711470 + gnGlobal_007A285C - 0x40, -1, 5, 1);
        }
        else if (!gnGlobal_007BCD34 && !gnGlobal_007BCE18)
        {
            tContext.nFrame = 16;
            TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0xDF, gnGlobal_00711470 + gnGlobal_007A285C - 0x40, -1, 5, 0);
        }
        else
        {
            tContext.nFrame = 17;
            TEXTURE_CelDrawColor(&tContext, gnGlobal_007A2858 + 0xDF, gnGlobal_00711470 + gnGlobal_007A285C - 0x40, -1, 5, 2);
        }

        int nFrame = 10;
        if (gnGlobal_007BCE1C == 1)
        {
            nFrame = 11;
        }
        tContext.nFrame = nFrame;
        TEXTURE_CelDraw(&tContext, gnGlobal_007A2858 + 0x113, gnGlobal_00711470 + gnGlobal_007A285C - 0x40, -1, 5, 0);

        const unsigned char nOldTab = gnSelectedTab_007BCC04;
        gnSelectedTab_007BCC04 = 1;
        sub_00483FF0_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
        gnSelectedTab_007BCC04 = 2;
        sub_00483FF0_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
        gnSelectedTab_007BCC04 = nOldTab;
        sub_00502EF0(1);

        int aNameText[12];
        Unicode* wszName = (Unicode*)aNameText;
        sub_00403040_ConstructArray(wszName, sizeof(Unicode), 0x17, &UnicodeChar::sub_0042F530_ClearUnicode);
        D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
        if (pUnit)
        {
            const char* szName = sub_0047A210_GetUnitName(pUnit);
            if (szName)
            {
                Unicode::win2Unicode(wszName, szName, 0x17);
            }
        }

        int aLineText[12];
        Unicode* wszText = (Unicode*)aLineText;
        sub_00403040_ConstructArray(wszText, sizeof(Unicode), 0x17, &UnicodeChar::sub_0042F530_ClearUnicode);
        sub_005267E0(wszText, sub_004B9060());
        int nLength = sub_00526800(wszText);
        while (sub_00501820(wszText) > 0x70)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        sub_00502320(wszText, gnGlobal_007A2858 + 0x19, 0x1B - gnGlobal_007A285C, 0, 0);

        sub_005267E0(wszText, wszName);
        nLength = sub_00526800(wszText);
        while (sub_00501820(wszText) > 0x70)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        sub_00502320(wszText, gnGlobal_007A2858 + 0x19, 0xF2 - gnGlobal_007A285C, 0, 0);

        sub_00502320(D2LANG_GetStringFromTblIndex(0x8A7), gnGlobal_007A2858 - sub_00501820(D2LANG_GetStringFromTblIndex(0x8A7)) / 2 + 0xBB, 0x1B - gnGlobal_007A285C, 0, 0);

        int aNumberText[8];
        Unicode* wszNumber = (Unicode*)aNumberText;
        sub_00403040_ConstructArray(wszNumber, sizeof(Unicode), 0x0F, &UnicodeChar::sub_0042F530_ClearUnicode);
        int aNumber[4];
        char* szNumber = (char*)aNumber;
        SStrPrintf(szNumber, 0x0F, "%d", sub_004B90F0());
        Unicode::win2Unicode(wszNumber, szNumber, 0x0F);
        sub_00502320(wszNumber, gnGlobal_007A2858 - sub_00501820(wszNumber) + 0x124, 0x1B - gnGlobal_007A285C, 0, 0);

        sub_00502320(D2LANG_GetStringFromTblIndex(0x8A7), gnGlobal_007A2858 - sub_00501820(D2LANG_GetStringFromTblIndex(0x8A7)) / 2 + 0xBB, 0xF2 - gnGlobal_007A285C, 0, 0);

        SStrPrintf(szNumber, 0x0F, "%d", sub_004B9100());
        Unicode::win2Unicode(wszNumber, szNumber, 0x0F);
        sub_00502320(wszNumber, gnGlobal_007A2858 - sub_00501820(wszNumber) + 0x124, 0xF2 - gnGlobal_007A285C, 0, 0);
    }

    const unsigned char nOldTab = gnSelectedTab_007BCC04;
    gnSelectedTab_007BCC04 = 0;
    sub_00483FF0_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
    gnSelectedTab_007BCC04 = nOldTab;

    sub_004845A0_DrawEquippedItems();
    if (gdwGlobal_007BCBF0 >= 1 && gdwGlobal_007BCBF0 <= 9)
    {
        sub_004886C0_DrawButtonHoverText();
    }
    sub_00488100(1);

    tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
    tContext.nFrame = (gbGlobal_007BCE90 != 0) + 10;
    TEXTURE_CelDraw(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E, gnGlobal_00711470 + gnGlobal_007A285C - 0x40, -1, 5, 0);

    D2UnitStrc* pPanelUnit = sub_00463DD0_GetPlayerUnit();
    int bOther = 0;
    if (gdwGlobal_007BCBF0 >= 1 && gdwGlobal_007BCBF0 <= 9 && nMouseX < gnGlobal_0071146C / 2)
    {
        int nUnitId;
        if (sub_004B3230_GetTickPair(&nUnitId))
        {
            D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
            if (pUnit)
            {
                pPanelUnit = pUnit;
                bOther = 1;
            }
        }
    }
    sub_0048DD90_DrawItemTooltip(pPanelUnit, bOther);
}

#include "gen/data/Source/D2Client/Unknown_0048EDF0.inc"
struct D2UnitStrc;
