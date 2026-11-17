#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2OrbSmoothStrc;
struct D2UiRectStrc;
struct D2UiRecordStrc;
struct D2Block1;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int dwAnimMode;
    unsigned char unk_14[0x4C];
    D2InventoryStrc* pInventory;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2OrbSmoothStrc
{
    int nValue;
    int nTick;
    int f_8;
    int nPrevTick;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2OrbSmoothStrc gtOrbSmooth_007BEF30[3]; // 0x007BEF30
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
unsigned int __cdecl sub_0044DA90(); // 0x0044DA90
int __cdecl sub_004F5140(); // 0x004F5140
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

struct D2ItemsTxt
{
    char unk0x000[0x11D];
    unsigned char bFlag0x11D;
    char unk0x11E[0x0B];
    unsigned char bFlag0x129;
    unsigned char bFlag0x12A;
};

struct D2UiRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2UiRecordStrc
{
    int unk0x00;
    unsigned char nBoxes;
    unsigned char unk0x05;
    unsigned short unk0x06;
    D2UiRectStrc aRects[16];
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nX;
    unsigned short nY;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bUseResult;
    int lResult;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord); // 0x00660CB0
void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0
int __cdecl sub_00468830(); // 0x00468830
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0
void __fastcall sub_004C21F0(D2UnitStrc* pItem); // 0x004C21F0
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __cdecl sub_0044DA30(); // 0x0044DA30
int __cdecl sub_00463DF0(); // 0x00463DF0
int __cdecl sub_0044BFE0(); // 0x0044BFE0
void __cdecl sub_00453EC0(); // 0x00453EC0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050

struct D2Block1 { int n[6]; };

void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x0049FF90
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, int nId); // 0x004CB9C0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
extern int gnUiRecordRow_007A5218; // 0x007A5218
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gnBeltHover_007BEF94; // 0x007BEF94
extern int gbUiRecordMode_007BEF98; // 0x007BEF98
extern int gnBeltRecordMode2_007BEF9C; // 0x007BEF9C
extern D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8
extern unsigned char gabBeltHotkey_007BEFB0[]; // 0x007BEFB0

unsigned char gnTextColorRed_007BEFBA; // 0x007BEFBA

unsigned char gnTextColorA_007BEFBB; // 0x007BEFBB

unsigned char gnTextColorB_007BEFE4; // 0x007BEFE4

// build: symbol ?sub_00496DD0_GetSmoothedOrbValue@@YAHH@Z 0x00496DD0
static int sub_00496DD0_GetSmoothedOrbValue(int nStatId)
{
    int bCheckDrop = 1;
    D2UnitStrc* pPlayer = sub_00463DD0();
    int nValue = STATLIST_UnitGetStatValue(pPlayer, nStatId, 0);
    int nIndex;
    int nMax = 0;
    switch (nStatId)
    {
    case 6:
        nMax = STATLIST_GetMaxLifeFromUnit(pPlayer);
        nIndex = 0;
        bCheckDrop = 0;
        break;
    case 8:
        nMax = STATLIST_GetMaxManaFromUnit(pPlayer);
        nIndex = 1;
        break;
    case 10:
        nMax = STATLIST_GetMaxStaminaFromUnit(pPlayer);
        nIndex = 2;
        break;
    }

    if (!nMax)
        return 0;

    if (sub_0044DA90() <= 1)
    {
        gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
        gtOrbSmooth_007BEF30[nIndex].nValue = nValue;
    }

    if (!bCheckDrop && nValue < gtOrbSmooth_007BEF30[nIndex].nValue)
    {
        gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
        gtOrbSmooth_007BEF30[nIndex].nValue = nValue;
        const unsigned int nTick = sub_0044DA90();
        gtOrbSmooth_007BEF30[nIndex].nTick = nTick;
        gtOrbSmooth_007BEF30[nIndex].nPrevTick = nTick;
    }

    const int nLast = gtOrbSmooth_007BEF30[nIndex].nValue;
    if (nLast != nValue)
    {
        int nDiff = nLast - nValue;
        if (nDiff < 0)
            nDiff = -nDiff;

        if (nDiff >= nMax / 8)
        {
            gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
            gtOrbSmooth_007BEF30[nIndex].nPrevTick = sub_0044DA90();
        }
        else
        {
            gtOrbSmooth_007BEF30[nIndex].nPrevTick = gtOrbSmooth_007BEF30[nIndex].nTick;
            if (nValue == nMax)
                gtOrbSmooth_007BEF30[nIndex].f_8 = nValue;
            else
                gtOrbSmooth_007BEF30[nIndex].f_8 = nLast;
        }
        gtOrbSmooth_007BEF30[nIndex].nValue = nValue;
        gtOrbSmooth_007BEF30[nIndex].nTick = sub_0044DA90();
    }

    const int nStart = gtOrbSmooth_007BEF30[nIndex].nTick;
    const int nElapsed = sub_0044DA90() - nStart;
    int nDuration = nStart - gtOrbSmooth_007BEF30[nIndex].nPrevTick;
    if (nDuration < 7)
        nDuration = 7;
    else if (nDuration > 15)
        nDuration = 15;

    if (nValue > 0 && nElapsed < nDuration)
    {
        const int nFrom = gtOrbSmooth_007BEF30[nIndex].f_8;
        const int nDelta = gtOrbSmooth_007BEF30[nIndex].nValue - nFrom;
        if (nDelta)
        {
            nValue = (int)((double)(nElapsed + 1) / nDuration * nDelta) + nFrom;
        }
    }

    if (nValue < 0)
        nValue = 0;
    else if (nValue > nMax)
        nValue = nMax;
    return nValue;
}

void __cdecl sub_00496F80_DrawLifeOrb()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nLife = sub_00496DD0_GetSmoothedOrbValue(6);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    if (!nMaxLife)
        return;

    int nHeight = 80 * nLife / nMaxLife;
    if (nHeight >= 1 && nHeight <= 2)
    {
        D2UnitStrc* pUnit = sub_00463DD0();
        if (pUnit && pUnit->dwUnitType == 0 && pUnit->dwAnimMode != 0x11)
            nHeight = 2;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpCellFile_007BEF68;
    tContext.nFrame = 0;
    if (STATES_CheckState(sub_00463DD0(), 0x64))
    {
        int nPoison = 80 * STATLIST_UnitGetStatValue(sub_00463DD0(), 0x4A, 0) / 100;
        if (nPoison > 80)
            nPoison = 80;
        if (nPoison > nHeight)
        {
            if (sub_004F5140() == 6)
                sub_004F64E0(&tContext, 0x1C, gnGlobal_00711470 - 0xD, nHeight, nPoison - nHeight, 0);
            else
                sub_004F64E0(&tContext, 0x1D, gnGlobal_00711470 - 0xD, nHeight, nPoison - nHeight, 0);
        }
    }

    tContext.nFrame = STATES_CheckState(sub_00463DD0(), 2) ? 2 : 0;
    if (nHeight)
    {
        switch (sub_004F5140())
        {
        case 1:
        case 3:
            sub_004F64E0(&tContext, 0x1D, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
            break;
        default:
            sub_004F64E0(&tContext, 0x1D, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
            break;
        }
    }

    tContext.pCellFile = gpCellFile_007BEF80;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x1C, gnGlobal_00711470 - 5, -1, 5, 0);
}

void __cdecl sub_00497110_DrawManaOrb()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    int nMana = sub_00496DD0_GetSmoothedOrbValue(8);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    if (!nMaxMana)
        return;

    if (nMana > nMaxMana)
        nMana = nMaxMana;
    const int nHeight = 80 * nMana / nMaxMana;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpCellFile_007BEF68;
    tContext.nFrame = 1;
    if (STATES_CheckState(sub_00463DD0(), 0x6A))
    {
        int nShield = 80 * STATLIST_UnitGetStatValue(sub_00463DD0(), 0x1A, 0) / 100;
        if (nShield > 80)
            nShield = 80;
        if (nShield > nHeight)
        {
            if (sub_004F5140() == 6)
                sub_004F64E0(&tContext, gnGlobal_0071146C - 0x70, gnGlobal_00711470 - 0xD, nHeight, nShield - nHeight, 0);
            else
                sub_004F64E0(&tContext, gnGlobal_0071146C - 0x6F, gnGlobal_00711470 - 0xD, nHeight, nShield - nHeight, 0);
        }
    }

    int nX;
    switch (sub_004F5140())
    {
    case 1:
    case 3:
        nX = gnGlobal_0071146C - 0x6F;
        break;
    default:
        nX = gnGlobal_0071146C - 0x6F;
        break;
    }
    sub_004F64E0(&tContext, nX, gnGlobal_00711470 - 0xD, 0, nHeight, 5);

    tContext.pCellFile = gpCellFile_007BEF80;
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - 0x6E, gnGlobal_00711470 - 9, -1, 5, 0);
}

// 0x004975B0
void __cdecl sub_004975B0_DrawStaminaBar()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nStamina = sub_00496DD0_GetSmoothedOrbValue(10);
    int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pPlayer);
    if (!gnTextColorRed_007BEFBA)
    {
        gnTextColorRed_007BEFBA = D2Win_10034_MixRGB(0xFF, 0, 0);
        gnTextColorA_007BEFBB = D2Win_10034_MixRGB(0xF4, 0xC0, 0x4C);
        gnTextColorB_007BEFE4 = D2Win_10034_MixRGB(0, 0, 0xFF);
    }

    int nColor = gnTextColorA_007BEFBB;
    if (nMaxStamina + 5 < nStamina || STATES_CheckStateMaskOnUnit(pPlayer, 0x18))
    {
        nMaxStamina = nStamina;
        nColor = gnTextColorB_007BEFE4;
    }

    int nWidth;
    if (nMaxStamina <= 0)
        nWidth = 0;
    else
        nWidth = 102 * nStamina / nMaxStamina;
    if (nWidth < 25)
        nColor = gnTextColorRed_007BEFBA;

    sub_0046EFD0_DrawFramedBox(gnGlobal_0071146C / 2 - 0x7F, gnGlobal_00711470 - 0x1B, nWidth, 0x12, nColor, 2);

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    int nCur = sub_00496DD0_GetSmoothedOrbValue(10) / 256;
    const int nMax = STATLIST_GetMaxStaminaFromUnit(pPlayer) / 256;
    int nTextColor = 0;
    if (nCur > nMax || STATES_CheckState(pPlayer, 0x88))
    {
        nCur = nMax;
        nTextColor = 3;
    }

    Unicode wszText[100];
    if (nMouseX >= gnGlobal_0071146C / 2 - 0x7F && nMouseX <= gnGlobal_0071146C / 2 - 0x19
        && nMouseY >= gnGlobal_00711470 - 0x1B && nMouseY <= gnGlobal_00711470 - 9)
    {
        sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1044), nCur, nMax);
        sub_00502280_SetPopUpText(wszText, gnGlobal_0071146C / 2 - 0x4C, gnGlobal_00711470 - 0x34, nTextColor, 1);
    }
}

// build: context sub_00498120
void __cdecl sub_00498120()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    Unicode wszLife[100];
    Unicode wszMana[100];
    Unicode wszLifeText[100];
    Unicode wszManaText[100];

    if (gdwShowHpText_007BEFDC || (nMouseX >= 0x1E && nMouseX <= 0x1E + 0x50
        && nMouseY >= gnGlobal_00711470 - 0x4B && nMouseY <= gnGlobal_00711470 - 0xF))
    {
        int nLife = sub_00496DD0_GetSmoothedOrbValue(6) >> 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer) >> 8;
        D2UnitStrc* pUnit = sub_00463DD0();
        if (pUnit && pUnit->dwUnitType == 0 && pUnit->dwAnimMode != 0x11 && nLife >= 0 && nLife <= 1)
            nLife = 1;

        sub_005269D0(100, wszLifeText, D2LANG_GetStringFromTblIndex(0x1045), nLife, nMaxLife);
        sub_00526700(wszLife, wszLifeText);
        const int nTextWidth = sub_00501820(wszLife);
        sub_00502320(wszLife, 0x41 - nTextWidth / 2, gnGlobal_00711470 - 0x5F, 0, 0);
    }

    if (gdwShowMpText_007BEFE0 || (nMouseX >= gnGlobal_0071146C - 0x6F && nMouseX <= gnGlobal_0071146C - 0x1F
        && nMouseY >= gnGlobal_00711470 - 0x4B && nMouseY <= gnGlobal_00711470 - 0xF))
    {
        const int nMana = sub_00496DD0_GetSmoothedOrbValue(8) >> 8;
        sub_005269D0(100, wszManaText, D2LANG_GetStringFromTblIndex(0x1046), nMana, STATLIST_GetMaxManaFromUnit(pPlayer) >> 8);
        sub_00526700(wszMana, wszManaText);
        const int nTextWidth = sub_00501820(wszMana);
        sub_00502320(wszMana, gnGlobal_0071146C - nTextWidth / 2 - 0x50, gnGlobal_00711470 - 0x5F, 0, 0);
    }
}

static int __stdcall sub_004987E0_GetBeltBoxAt(int nY, int nX)
{
    D2UiRecordStrc tRecord;
    int nResult = -1;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    for (int i = 0; i < tRecord.nBoxes; ++i)
    {
        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, i);
        if (nX >= tRect.nLeft && nX <= tRect.nRight && nY >= tRect.nTop && nY <= tRect.nBottom)
        {
            nResult = i;
            break;
        }
    }
    return nResult;
}

// 0x00498870
static void __stdcall sub_00498870_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY)
{
    const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
    if (nBox == -1)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    if (sub_00468830() == 6)
    {
        return;
    }

    if (pCursorItem && ITEMS_CheckIfBeltable(pCursorItem))
    {
        const int bBusy = sub_004C2240(pCursorItem);
        if (pBeltItem)
        {
            if (!bBusy)
            {
                sub_004786A0_SendIntInt(0x25, pCursorItem->dwUnitId, !pBeltItem ? -1 : pBeltItem->dwUnitId);
                sub_004C21F0(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            sub_004786A0_SendIntInt(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
            sub_004C21F0(pCursorItem);
        }
        sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
        return;
    }

    if (pBeltItem && !pCursorItem && !sub_004C2240(pBeltItem))
    {
        sub_00478680_SendPacket5(0x24, pBeltItem->dwUnitId);
        sub_004C21F0(pBeltItem);
    }
}

void __stdcall sub_A11_Emit_00498870(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nX;
    const int nY = pMsg->nY;
    D2UnitStrc* pPlayer = sub_00463DD0();
    sub_00498870_ClickBeltBox(pPlayer->pInventory, nX, nY);
}

static void sub_00498930_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY)
{
    const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
    if (nBox < 0)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (sub_00468830() == 6 || sub_00468830() == 8)
    {
        return;
    }

    if (pCursorItem)
    {
        gnBeltBox_0072235C = nBox;
        gnBeltHover_007BEF94 = 1;
        gpBeltItemB_007BEFAC = 0;
        gpBeltItemA_007BEFA8 = 0;
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    gnBeltBox_0072235C = nBox;
    if (!pItem)
    {
        gnBeltHover_007BEF94 = 0;
        gpBeltItemB_007BEFAC = 0;
        gpBeltItemA_007BEFA8 = 0;
        return;
    }

    gnBeltHover_007BEF94 = 1;
    if (pItem == gpBeltItemB_007BEFAC)
    {
        return;
    }

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, CLIENTS_GetUnitX(pItem));
    gpBeltItemA_007BEFA8 = pItem;
    gpBeltItemB_007BEFAC = pItem;
    gnBeltRectX_00722360 = tRect.nLeft + 0xE;
    gnBeltRectY_00722364 = tRect.nTop;
}

static int __stdcall sub_00498A20_CheckState(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2ItemsTxt* pState)
{
    D2_ASSERT(pState, 0xA3D);
    if (pState->bFlag0x129 == 1 || pState->bFlag0x12A == 1)
    {
        sub_0049FF90_Close(pItem, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    sub_004CB9C0_Request(pPlayer, 0x14);
    return 0;
}

// 0x00498A90
static void __stdcall sub_00498A90_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift)
{
    if (!sub_0044DCC0())
    {
        bShift = 0;
    }

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return;
    }

    if (sub_004538D0(9))
    {
        return;
    }

    D2Block1 tBlock1;
    const int nClass = UNITS_GetInventoryRecordId(pPlayer, 0, sub_0044DCC0());
    sub_0065C1F0(nClass, gnUiRecordRow_007A5218, &tBlock1);
    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nSlot);
    if (!pItem)
    {
        return;
    }

    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nClassId);
    D2_ASSERT(pItemsTxt, 0xA64);
    if (sub_00498A20_CheckState(pPlayer, pItem, pItemsTxt) != 1)
    {
        return;
    }

    if (sub_004C2240(pItem))
    {
        return;
    }

    sub_004786D0_SendDwords3(0x26, pItem->dwUnitId, bShift, 0);
    sub_004C21F0(pItem);
    if (bShift)
    {
        const int nPetId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
        if (nPetId != -1)
        {
            if (ITEMS_CheckItemTypeId(pItem, 0x4C) || ITEMS_CheckItemTypeId(pItem, 0x51) || ITEMS_CheckItemTypeId(pItem, 0x50))
            {
                sub_004CBDE0_PlayEventSound(nPetId, 1, 0x54);
            }
            else
            {
                sub_004CBDE0_PlayEventSound(nPetId, 1, 0x55);
            }
            gnBeltHover_007BEF94 = 0;
            return;
        }

        sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
        gnBeltHover_007BEF94 = 0;
        return;
    }

    sub_004B9A00(sub_004C1E20_GetItemUseSound(pItem), 0, 0, 0, 0);
    gnBeltHover_007BEF94 = 0;
}

static void sub_00498C10_BeltHotkey(int nSlot)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        return;
    }

    if (gabBeltHotkey_007BEFB0[nSlot] != 1)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    sub_00498A90_UseBeltSlot(nSlot, pPlayer, pPlayer->pInventory, GetKeyState(0x10) & 0x8000);
}

void __cdecl sub_00498C50_BeltHotkey0()
{
    sub_00498C10_BeltHotkey(0);
}

void __cdecl sub_00498C90_BeltHotkey1()
{
    sub_00498C10_BeltHotkey(1);
}

void __cdecl sub_00498CD0_BeltHotkey2()
{
    sub_00498C10_BeltHotkey(2);
}

void __cdecl sub_00498D10_BeltHotkey3()
{
    sub_00498C10_BeltHotkey(3);
}

void __stdcall sub_00499BB0_BeltMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gdwGlobal_007A061C || sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nY = pMsg->nY;
    const int nX = pMsg->nX;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (sub_0044BFE0())
    {
        return;
    }

    if (gbUiRecordMode_007BEF98)
    {
        if (sub_00498DC0_MouseMoveMsg(pMsg))
        {
            if (sub_004538D0(0x1F))
            {
                pMsg->bUseResult = 1;
                pMsg->lResult = 0;
            }
            sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
            return;
        }

        if (!sub_004538D0(0x1F))
        {
            pMsg->bUseResult = 0;
            gbUiRecordMode_007BEF98 = 0;
            gnBeltRecordMode2_007BEF9C = 0;
            gnBeltHover_007BEF94 = 0;
            return;
        }

        pMsg->bUseResult = 0;
        gnBeltRecordMode2_007BEF9C = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (nX < gnGlobal_0071146C / 2 + 0x17 || nX > gnGlobal_0071146C / 2 + 0x91 || nY < gnGlobal_00711470 - 0x27 || nY > gnGlobal_00711470 - 0xA)
    {
        pMsg->bUseResult = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (!sub_00453A90_GetUIVarUnchecked(9))
    {
        gbUiRecordMode_007BEF98 = 1;
        gnBeltRecordMode2_007BEF9C = 1;
        sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
    }
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
}

void __stdcall sub_00499D10_BeltClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bUseResult = 0;
        return;
    }

    const int nX = pMsg->nX;
    const int nY = pMsg->nY;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (sub_00498DC0_MouseMoveMsg(pMsg))
    {
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        if (sub_00468830() == 6)
        {
            sub_00453EC0();
        }
        else if (sub_00468830() == 8)
        {
            sub_00478680_SendPacket5(0x4C, -1);
        }

        const int nBox = sub_004987E0_GetBeltBoxAt(nY, nX);
        if (nBox < 0)
        {
            pMsg->bUseResult = 0;
            return;
        }

        sub_00498A90_UseBeltSlot(nBox, pPlayer, pPlayer->pInventory, (pMsg->wParam >> 2) & 1);
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    pMsg->bUseResult = 0;
    gnBeltHover_007BEF94 = 0;
}
