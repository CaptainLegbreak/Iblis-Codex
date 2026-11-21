#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ClientGfx.h"
#include "D2Path.h"

struct D2ActiveRoomStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct BitStreamContext;

struct D2OrbSmoothStrc;

struct Unicode;

struct D2HotkeySlotTableStrc;

struct D2TextPanelLineStrc;

struct D2TextPanelStrc;

struct D2UiRectStrc;

struct D2UiRecordStrc;

struct D2Block1;

struct D2UnitStrc;

struct D2CelContextStrc;

struct SMSGHANDLER_PARAMS;

struct D2GfxMotionStrc;

struct D2ItemsTxt;

struct D2OrbSmoothStrc
{
    int nValue;
    int nTick;
    int f_8;
    int nPrevTick;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

unsigned int __cdecl sub_0044DA90(); // 0x0044DA90

int __cdecl sub_004F5140(); // 0x004F5140

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2OrbSmoothStrc gtOrbSmooth_007BEF30[3]; // 0x007BEF30

extern int gnGlobal_007BEFA4; // 0x007BEFA4

extern int gnGlobal_007BEF84; // 0x007BEF84

extern int gnGlobal_007BEF88; // 0x007BEF88

extern int gnGlobal_007BEFDC; // 0x007BEFDC

extern int gnGlobal_007BEFE0; // 0x007BEFE0

extern int gnGlobal_007BEFD0; // 0x007BEFD0

extern int gnGlobal_007BEFD8; // 0x007BEFD8

int __cdecl sub_0044DA30(); // 0x0044DA30

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

struct D2TextPanelLineStrc
{
    unsigned short unk0x00[4];
    Unicode wszText[6][0x400];
    unsigned short unk0x3008[3];
};

struct D2TextPanelStrc
{
    D2TextPanelLineStrc pLines[128];
    int unk0x180700[5];
    int nHeight;
    int unk0x180718[6];
    int nFirstLine;
    int unk0x180734[5];
    unsigned short f_180748;
    unsigned short unk0x18074A[14];
    unsigned char nLineStep[4];
    unsigned char nLineGap[4];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

extern int gnTabSelection_00724CE0; // 0x00724CE0

extern int gnGlobal_00724BEC; // 0x00724BEC

extern unsigned char gbGlobal_007A0522; // 0x007A0522

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

void* gpPanelQuadCel_007BF018; // 0x007BF018

extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300

extern int gnHotkeySkill_007C06C8[16]; // 0x007C06C8

extern int gnHotkeyOwner_007C0768[16]; // 0x007C0768

extern int gbHotkeyLeft_007C07B8[16]; // 0x007C07B8

extern int gbGlobal_007C07FC; // 0x007C07FC

extern int gbGlobal_007C0C38; // 0x007C0C38

int __cdecl sub_0047A560(); // 0x0047A560

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

extern "C" int gnScreenWidth; // 0x0071146C

extern "C" int gnScreenHeight; // 0x00711470

extern "C" int __cdecl sub_00468730_MouseX();

extern "C" int __cdecl sub_00468740_MouseY();

extern "C" U32 __fastcall sub_004538D0_UIState(U32 index);

extern "C" const U16* __fastcall sub_00524A30_LocalizedText(U16 index);

extern "C" void __fastcall sub_00502280_SetTooltip(const U16* text, int x, int y, int color, int mode);

extern "C" void __stdcall sub_00410EB0_WriteBits(BitStreamContext* stream, U32 value, int bitCount);

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C

void __stdcall sub_00660CB0_GetUiRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord); // 0x00660CB0

void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId); // 0x0063C7F0

int __cdecl sub_00468830(); // 0x00468830

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240

void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680

void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

void __fastcall sub_004C21F0_SetState36(D2UnitStrc* pItem); // 0x004C21F0

int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60

int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __cdecl sub_0044DCC0(); // 0x0044DCC0

int __cdecl sub_00463DF0(); // 0x00463DF0

int __cdecl sub_0044BFE0(); // 0x0044BFE0

void __cdecl sub_00453EC0(); // 0x00453EC0

int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90

void __stdcall sub_0065C1F0(int nId, int nGroup, D2Block1* pBlock); // 0x0065C1F0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x0049FF90

void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0

extern int gnUiRecordRow_007A5218; // 0x007A5218

extern int gdwGlobal_007A061C; // 0x007A061C

extern int gnBeltHover_007BEF94; // 0x007BEF94

int gbUiRecordMode_007BEF98;                                                                                // 0x007BEF98

extern int gnBeltRecordMode2_007BEF9C; // 0x007BEF9C

extern D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8

int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300

extern "C" size_t __cdecl strlen(const char* szString);

int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount); // 0x005262A0

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall sub_00478A00(void* pCel); // 0x00478A00

void __cdecl sub_00499E50_DrawPanelQuad(); // 0x00499E50

void __cdecl sub_0049C270_DrawPartyRows(); // 0x0049C270

void __cdecl sub_0049A510_DrawPartyButtons(); // 0x0049A510

void __cdecl sub_0049A950_DrawPanelCel(); // 0x0049A950

void __cdecl sub_0049ABD0_DrawRosterHoverHints(); // 0x0049ABD0

void __cdecl sub_0049B330_DrawRosterButtonHints(); // 0x0049B330

void __cdecl sub_0049A9B0_RefreshRosterIndices(); // 0x0049A9B0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

extern int gdwGlobal_007BEFA8; // 0x007BEFA8

extern int gdwGlobal_007BEFAC; // 0x007BEFAC

extern void* gpCelFile_007BF020; // 0x007BF020

extern unsigned char gbGlobal_007BF034; // 0x007BF034

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nArg, int nMode); // 0x00621050

void __fastcall sub_004CBDE0_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0

unsigned char gabBeltHotkey_007BEFB0[1]; // 0x007BEFB0

static void __stdcall sub_00498870_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY);

static void __stdcall sub_00498A90_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift);

static int __stdcall sub_00498A20_CheckState(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2ItemsTxt* pState);

unsigned char gnTextColorRed_007BEFBA; // 0x007BEFBA

unsigned char gnTextColorA_007BEFBB; // 0x007BEFBB

unsigned char gnTextColorB_007BEFE4; // 0x007BEFE4

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

void __fastcall sub_00496BE0_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg); // 0x00496BE0


unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0

const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB);                                          // 0x0046A530

int __fastcall sub_0046EE80_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);  // 0x006280A0

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem);                                                              // 0x00628C20

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

extern D2CelFileStrc* gpCellFile_007BEF10;                                                                  // 0x007BEF10

unsigned char gabBeltColors_007BEF6C[4];                                                                    // 0x007BEF6C

int gbGlobal_007BEFA0;                                                                                      // 0x007BEFA0

void __cdecl sub_004972B0_InitBeltColors(); // 0x004972B0

static void __stdcall sub_004978D0_DrawBeltBoxFrame(int nBox, int nColor); // 0x004978D0

static void __cdecl sub_00497920_DrawCursorBeltBox(D2InventoryStrc* pInventory); // 0x00497920

void* gpBorderFrameCel_007BEF18; // 0x007BEF18

int gnLevelTimer_007BEFEC; // 0x007BEFEC

int gnLevelId_007BEFF0; // 0x007BEFF0

void* gpCelFile_007BF01C; // 0x007BF01C

void* gpCelFile_007BF024; // 0x007BF024

void* gpCelFile_007BF028; // 0x007BF028

void __cdecl sub_0049A580_DrawPlayerName(); // 0x0049A580

static int ORB_AbsValue(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x00496CF0
void __cdecl sub_00496CF0_ValidateActiveSkills()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    D2SkillStrc* pSkill = UNITS_GetLeftSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillLevel(pPlayer, pSkill, 1) <= 0)
    {
        SKILLS_RemoveSkill(pPlayer, SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\panel.cpp", 0x289), ".\\UI\\panel.cpp", 0x289);
        SKILLS_SetLeftActiveSkill(pPlayer, SKILL_ATTACK, -1);
        pSkill = UNITS_GetLeftSkill(pPlayer);
    }
    sub_00496BE0_DrawSkillInfo(pPlayer, pSkill, 0x75, gnGlobal_00711470, 1);
    pSkill = UNITS_GetRightSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillLevel(pPlayer, pSkill, 1) <= 0)
    {
        SKILLS_RemoveSkill(pPlayer, SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\panel.cpp", 0x294), ".\\UI\\panel.cpp", 0x294);
        SKILLS_SetRightActiveSkill(pPlayer, SKILL_ATTACK, -1);
        pSkill = UNITS_GetRightSkill(pPlayer);
    }
    sub_00496BE0_DrawSkillInfo(pPlayer, pSkill, gnGlobal_0071146C - 0xA5, gnGlobal_00711470, 0);
}

// 0x00496DD0
static int sub_00496DD0_GetSmoothedOrbValue(int nStatId)
{
    int bCheckDrop = 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
        const int nDiff = ORB_AbsValue(nLast - nValue);

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

// 0x00496F80
void __cdecl sub_00496F80_DrawLifeOrb()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nLife = sub_00496DD0_GetSmoothedOrbValue(6);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    if (!nMaxLife)
        return;

    int nHeight = 80 * nLife / nMaxLife;
    if (nHeight >= 1 && nHeight <= 2)
    {
        D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11)
            nHeight = 2;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpCellFile_007BEF68;
    tContext.nFrame = 0;
    if (STATES_CheckState(sub_00463DD0_GetPlayerUnit(), STATE_HEALTHPOT))
    {
        int nPoison = 80 * STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_HPREGEN, 0) / 100;
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

    tContext.nFrame = STATES_CheckState(sub_00463DD0_GetPlayerUnit(), STATE_POISON) ? 2 : 0;
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

// 0x00497110
void __cdecl sub_00497110_DrawManaOrb()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nMana = sub_00496DD0_GetSmoothedOrbValue(8);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    if (!nMaxMana)
        return;

    if (nMana > nMaxMana)
        nMana = nMaxMana;
    const int nHeight = 80 * nMana / nMaxMana;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCellFile = gpCellFile_007BEF68;
    tContext.nFrame = 1;
    if (STATES_CheckState(sub_00463DD0_GetPlayerUnit(), STATE_MANAPOT))
    {
        int nShield = 80 * STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_MANARECOVERY, 0) / 100;
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

    switch (sub_004F5140())
    {
    case 1:
    case 3:
        sub_004F64E0(&tContext, gnGlobal_0071146C - 0x6F, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
        break;
    default:
        sub_004F64E0(&tContext, gnGlobal_0071146C - 0x6F, gnGlobal_00711470 - 0xD, 0, nHeight, 5);
        break;
    }

    tContext.pCellFile = gpCellFile_007BEF80;
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - 0x6E, gnGlobal_00711470 - 9, -1, 5, 0);
}

// 0x00497440
static __declspec(noinline) int __cdecl sub_00497440_Bounds(int nX,int nY)
{
    int nHalf=gnGlobal_0071146C / 2;
    if (nX >= nHalf + -145 && nX <= nHalf + -128
        && nY >= gnGlobal_00711470 + -28 && nY <= gnGlobal_00711470 + -8)
        return 1;
    return 0;
}

// 0x004975B0
void __cdecl sub_004975B0_DrawStaminaBar()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
    if (nCur > nMax || STATES_CheckState(pPlayer, STATE_SHRINE_STAMINA))
    {
        nCur = nMax;
        nTextColor = 3;
    }

    Unicode wszText[100];
    if (nMouseX >= gnGlobal_0071146C / 2 - 0x7F && nMouseX <= gnGlobal_0071146C / 2 - 0x19
        && nMouseY >= gnGlobal_00711470 - 0x1B && nMouseY <= gnGlobal_00711470 - 9)
    {
        sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1044), nCur, nMax);
        D2Win_10129_DrawFramedText(wszText, gnGlobal_0071146C / 2 - 0x4C, gnGlobal_00711470 - 0x34, nTextColor, 1);
    }
}

// 0x00497780
static __declspec(noinline) int __cdecl sub_00497780_Bounds(int nX,int nY)
{
    int nHalf=gnGlobal_0071146C / 2;
    if (nX >= nHalf + -8 && nX <= nHalf + 5
        && nY >= gnGlobal_00711470 + -39 && nY <= gnGlobal_00711470 + -13)
        return 1;
    return 0;
}

// @ref 0x00499500
void __stdcall sub_00499500_Click(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0_StateBlocked())
    {
        pMsg->bReturn=0;
        return;
    }
    int nY=pMsg->nYpos;
    int nX=pMsg->nXpos;
    if (sub_00498DC0_OverlayHit(pMsg))
    {
        gnGlobal_007BEFA4=1;
        goto handled;
    }
    {
        int nHeight=gnGlobal_00711470;
        if (nY<=nHeight + -48)
        {
            pMsg->bReturn=0;
            return;
        }
        if ((unsigned int)(nX + -117)<=48 && nY<=nHeight)
        {
            gnGlobal_007BEFA4=1;
            gnGlobal_007BEF84=1;
            goto refresh;
        }
        int nWidth=gnGlobal_0071146C;
        if (nX>=nWidth + -165 && nX<=nWidth + -117 && nY<=nHeight)
        {
            gnGlobal_007BEFA4=1;
            gnGlobal_007BEF88=1;
            goto refresh;
        }
        if ((unsigned int)(nX + -30)<=80 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gnGlobal_007BEFDC=!gnGlobal_007BEFDC;
            sub_004150E0_SaveValue("Diablo II","Show HP Text",0,gnGlobal_007BEFDC);
            goto refresh;
        }
        if (nX>=nWidth + -111 && nX<=nWidth + -31 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gnGlobal_007BEFE0=!gnGlobal_007BEFE0;
            sub_004150E0_SaveValue("Diablo II","Show MP Text",0,gnGlobal_007BEFE0);
            goto refresh;
        }
        if (sub_00497780_Bounds(nX,nY)) gnGlobal_007BEFD0=1;
        else if (sub_00497440_Bounds(nX,nY)) gnGlobal_007BEFD8=1;
        else goto refresh;
        gnGlobal_007BEFA4=1;
        sub_004B9A00_Sound(4,0,0,0,0);
    }
refresh:
    gnGlobal_00722358=1;
handled:
    pMsg->bReturn=1;
    pMsg->lResult=0;
    sub_00420290_BreakHandlerChain(pMsg);
}

static int sub_004977C0_IsInButtonRect(int nX, int nY)
{
    return nX >= gnGlobal_0071146C / 2 - 8 && nX <= gnGlobal_0071146C / 2 + 5 && nY >= gnGlobal_00711470 - 39 && nY <= gnGlobal_00711470 - 13;
}

// 0x004977C0
void __cdecl sub_004977C0_DrawStateButton()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpStateButtonCel_007BEF70;
    tContext.nDirection = 0;
    if (sub_004538D0(21))
    {
        if (gbGlobal_007BEFD0 && sub_004977C0_IsInButtonRect(sub_00468730(), sub_00468740()))
        {
            tContext.nFrame = 3;
        }
        else
        {
            tContext.nFrame = 2;
        }
    }
    else
    {
        if (gbGlobal_007BEFD0 && sub_004977C0_IsInButtonRect(sub_00468730(), sub_00468740()))
        {
            tContext.nFrame = 1;
        }
        else
        {
            tContext.nFrame = 0;
        }
    }
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 8, gnGlobal_00711470 - 16, -1, 5, 0);
}

// 0x00497CF0
static void __stdcall sub_00497CF0_DrawDurabilityIcon(int nState, int nQuiverType, int bType, int nBodyLoc)
{
    int nFrame = nState * 11;
    switch (nBodyLoc)
    {
    case 1:
        nFrame += 1;
        break;
    case 3:
        nFrame += 4;
        break;
    case 4:
        if (nQuiverType)
            nFrame += 10;
        else if (bType)
            nFrame += 7;
        else
            nFrame += 6;
        break;
    case 5:
        if (nQuiverType)
            nFrame += 9;
        else if (bType)
            nFrame += 5;
        else
            nFrame += 8;
        break;
    case 8:
        nFrame += 2;
        break;
    case 9:
        nFrame += 3;
        break;
    case 10:
        nFrame += 0;
        break;
    }
    int nOffset = 0;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BEF60;
    tContext.nDirection = 0;
    tContext.nFrame = nFrame;
    if (sub_004538D0(10))
    {
        if (sub_0047A560())
            nOffset = 0x2B;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x3C, nOffset + 0x8C, -1, 1, 0);
    }
    else
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x3C, 0x6E, -1, 1, 0);
}

// 0x00498120
void __cdecl sub_00498120()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
        D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11 && nLife >= 0 && nLife <= 1)
            nLife = 1;

        sub_005269D0(100, wszLifeText, D2LANG_GetStringFromTblIndex(0x1045), nLife, nMaxLife);
        sub_00526700(wszLife, wszLifeText);
        const int nHalfWidth = sub_00501820(wszLife) / 2;
        sub_00502320(wszLife, 0x41 - nHalfWidth, gnGlobal_00711470 - 0x5F, 0, 0);
    }

    if (gdwShowMpText_007BEFE0 || (nMouseX >= gnGlobal_0071146C - 0x6F && nMouseX <= gnGlobal_0071146C - 0x1F
        && nMouseY >= gnGlobal_00711470 - 0x4B && nMouseY <= gnGlobal_00711470 - 0xF))
    {
        const int nMana = sub_00496DD0_GetSmoothedOrbValue(8) >> 8;
        sub_005269D0(100, wszManaText, D2LANG_GetStringFromTblIndex(0x1046), nMana, STATLIST_GetMaxManaFromUnit(pPlayer) >> 8);
        sub_00526700(wszMana, wszManaText);
        const int nHalfWidth = sub_00501820(wszMana) / 2;
        sub_00502320(wszMana, gnGlobal_0071146C - nHalfWidth - 0x50, gnGlobal_00711470 - 0x5F, 0, 0);
    }
}

void __cdecl sub_00497FE0_DrawDurabilityIcons()
{
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    for (int j = 0; j < 7; ++j)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, gnBodyLocs_007223E8[j]);
        if (!pItem || !ITEMS_HasDurability(pItem) || ITEMS_CheckIfStackable(pItem))
            continue;
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (!nMaxDurability)
            continue;
        if (STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) * 100 / nMaxDurability <= 20)
            goto found;
    }
    return;
found:
    for (int i = 0; i < 7; ++i)
    {
        const int nBodyLoc = gnBodyLocs_007223E8[i];
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        int nState = 0;
        int nQuiverType = 0;
        int bType = 0;
        if (pItem)
        {
            if (ITEMS_HasDurability(pItem) && !ITEMS_CheckIfStackable(pItem))
            {
                const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
                bType = ITEMSIsA(pItem, 0x33);
                nQuiverType = ITEMS_GetQuiverType(pItem);
                if (nMaxDurability)
                {
                    const int nPercent = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) * 100 / nMaxDurability;
                    if (nPercent <= 0)
                        nState = 2;
                    else if (nPercent <= 20)
                        nState = 1;
                }
            }
        }
        else if (nBodyLoc == 4 || nBodyLoc == 5)
            continue;
        sub_00497CF0_DrawDurabilityIcon(nState, nQuiverType, bType, nBodyLoc);
    }
}

// 0x00498310
void __cdecl sub_00498310_UpdateLevelTimer()
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (gnLevelId_007BEFF0 != nLevelId)
        {
            gnLevelId_007BEFF0 = nLevelId;
            gnLevelTimer_007BEFEC = 0x3C;
        }
    }
}

// 0x00498340
extern "C" void __cdecl sub_00498340_UpdateTooltip()
{
    const int mouseX = sub_00468730_MouseX();
    const int mouseY = sub_00468740_MouseY();
    if (mouseX >= gnScreenWidth / 2 - 8 && mouseX <= gnScreenWidth / 2 + 5
        && mouseY >= gnScreenHeight - 39 && mouseY <= gnScreenHeight - 13)
    {
        if (sub_004538D0_UIState(21))
            sub_00502280_SetTooltip(sub_00524A30_LocalizedText(4168), gnScreenWidth / 2 - 1, gnScreenHeight - 39, 0, 1);
        else
            sub_00502280_SetTooltip(sub_00524A30_LocalizedText(4167), gnScreenWidth / 2 - 1, gnScreenHeight - 39, 0, 1);
    }
}

// 0x00498630
void __cdecl sub_00498630_DrawBorderFrameLeft()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (!gpBorderFrameCel_007BEF18)
    {
        gpBorderFrameCel_007BEF18 = sub_004520C0_LoadUiCelFile("Panel\\800BorderFrame");
    }
    tContext.pCellFile = gpBorderFrameCel_007BEF18;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 253, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 256, 63, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0, 484, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0, 553, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 256, 553, -1, 5, 0);
}

// 0x00498700
void __cdecl sub_00498700_DrawBorderFrameRight()
{
    if (!gpBorderFrameCel_007BEF18)
    {
        gpBorderFrameCel_007BEF18 = sub_004520C0_LoadUiCelFile("Panel\\800BorderFrame");
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpBorderFrameCel_007BEF18;
    tContext.nDirection = 0;
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 400, 63, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 544, 253, -1, 5, 0);
    tContext.nFrame = 7;
    sub_004F6480(&tContext, 713, 484, -1, 5, 0);
    tContext.nFrame = 8;
    sub_004F6480(&tContext, 544, 553, -1, 5, 0);
    tContext.nFrame = 9;
    sub_004F6480(&tContext, 400, 553, -1, 5, 0);
}

extern "C" void __fastcall sub_0053B0E0_WriteVariableValue(BitStreamContext* stream, U32 value)
{
    if (value < 256u)
    {
        sub_00410EB0_WriteBits(stream, 0, 1);
        sub_00410EB0_WriteBits(stream, value, 8);
    }
    else
    {
        sub_00410EB0_WriteBits(stream, 1, 1);
        if (value < 65536u)
        {
            sub_00410EB0_WriteBits(stream, 0, 1);
            sub_00410EB0_WriteBits(stream, value, 16);
        }
        else
        {
            sub_00410EB0_WriteBits(stream, 1, 1);
            sub_00410EB0_WriteBits(stream, value, 32);
        }
    }
}

// 0x004987E0
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
                sub_004786A0_SendDwords2(0x25, pCursorItem->dwUnitId, !pBeltItem ? -1 : pBeltItem->dwUnitId);
                sub_004C21F0_SetState36(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            sub_004786A0_SendDwords2(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
            sub_004C21F0_SetState36(pCursorItem);
        }
        sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
        return;
    }

    if (pBeltItem && !pCursorItem && !sub_004C2240(pBeltItem))
    {
        sub_00478680_SendPacket5(0x24, pBeltItem->dwUnitId);
        sub_004C21F0_SetState36(pBeltItem);
    }
}

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
    sub_004C21F0_SetState36(pItem);
    if (bShift)
    {
        const int nPetId = sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0);
        if (nPetId != -1)
        {
            if (ITEMSIsA(pItem, 0x4C) || ITEMSIsA(pItem, 0x51) || ITEMSIsA(pItem, 0x50))
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

// 0x00498C00
void __stdcall sub_00498C00_CloseOnSpace(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00456300_CloseUIVars(1, 0);
}

void __stdcall sub_A11_Emit_00498870(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
    if (pState->nUnique == 1 || pState->nQuest == 1)
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

// 0x00498C10
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

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00498A90_UseBeltSlot(nSlot, pPlayer, pPlayer->pInventory, GetKeyState(0x10) & 0x8000);
}

// 0x00498C50
void __cdecl sub_00498C50_BeltHotkey0()
{
    sub_00498C10_BeltHotkey(0);
}

// 0x00498C90
void __cdecl sub_00498C90_BeltHotkey1()
{
    sub_00498C10_BeltHotkey(1);
}

// 0x00498CD0
void __cdecl sub_00498CD0_BeltHotkey2()
{
    sub_00498C10_BeltHotkey(2);
}

// 0x00498D10
void __cdecl sub_00498D10_BeltHotkey3()
{
    sub_00498C10_BeltHotkey(3);
}

// 0x00498D90
void __fastcall sub_00498D90_SetUiRecordIndex(int nIndex)
{
    if (nIndex >= 0)
    {
        gnUiRecordIndex_00722354 = nIndex;
        return;
    }
    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xB07);
    exit(-1);
}

// 0x00498E80
void __cdecl sub_00498E80_ClearPair()
{
    gdwGlobal_007BEFA8 = 0;
    gdwGlobal_007BEFAC = 0;
}

// 0x00498E90
void __cdecl sub_00498E90_SetRecordMode()
{
    gbUiRecordMode_007BEF98 = 1;
}

void __cdecl sub_004972B0_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

static void __stdcall sub_004978D0_DrawBeltBoxFrame(int nBox, int nColor)
{
    sub_004972B0_InitBeltColors();
    if (nColor == 2)
        return;

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
    sub_0046EFD0_DrawFramedBox(tRect.nLeft, tRect.nTop, 0x1D, 0x1D, gabBeltColors_007BEF6C[nColor], 0);
}

static void __cdecl sub_00497920_DrawCursorBeltBox(D2InventoryStrc* pInventory)
{
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (!pItem || !gnBeltHover_007BEF94)
        return;

    D2UiRecordStrc tRecord;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    if (gnBeltBox_0072235C < 0 || gnBeltBox_0072235C >= tRecord.nBoxes)
        return;

    if (!INVENTORY_GetItemFromBeltSlot(pInventory, gnBeltBox_0072235C) && ITEMS_CheckIfBeltable(pItem))
    {
        sub_004978D0_DrawBeltBoxFrame(gnBeltBox_0072235C, 1);
        return;
    }

    int nResult;
    if (sub_0063C830_CanPlaceInBelt(pInventory, pItem, gnBeltBox_0072235C, &nResult))
    {
        sub_004978D0_DrawBeltBoxFrame(gnBeltBox_0072235C, 3);
        return;
    }

    sub_004978D0_DrawBeltBoxFrame(gnBeltBox_0072235C, 0);
}

// 0x00499040
void __cdecl sub_00499040_DrawBelt()
{
    sub_00502EF0(1);
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, 8);
    if (pBelt)
    {
        if (ITEMS_GetItemType(pBelt) == 0x13)
        {
            const int nBeltType = UNITS_GetBeltType(pBelt);
            if (nBeltType >= 0)
            {
                gnUiRecordIndex_00722354 = nBeltType;
            }
            else
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xB07);
                exit(-1);
            }
        }
    }
    else
    {
        gnUiRecordIndex_00722354 = 2;
    }

    if (!sub_004538D0(0x1F) && !gnBeltRecordMode2_007BEF9C)
        gbUiRecordMode_007BEF98 = 0;

    if (sub_004538D0(9))
        gbUiRecordMode_007BEF98 = 0;

    gbGlobal_007BEFA0 = 0;
    if (gbUiRecordMode_007BEF98)
    {
        unsigned char abShow[3];
        abShow[0] = 1;
        abShow[1] = 1;
        abShow[2] = 1;
        switch (gnUiRecordIndex_00722354)
        {
        case 2:
            abShow[0] = 0;
            abShow[1] = 0;
            abShow[2] = 0;
            gbGlobal_007BEFA0 = 0;
            break;
        case 1:
        case 4:
            abShow[1] = 0;
            abShow[2] = 0;
            gbGlobal_007BEFA0 = 1;
            break;
        case 0:
        case 5:
            abShow[2] = 0;
            gbGlobal_007BEFA0 = 1;
            break;
        case 3:
        default:
            gbGlobal_007BEFA0 = 1;
            break;
        }

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        tContext.pCellFile = gpCellFile_007BEF10;
        int nOffset = 0;
        unsigned char* pShow = abShow;
        for (int i = 0; i < 3; ++i)
        {
            if (*pShow)
                sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x15, gnGlobal_00711470 - nOffset - 0x29, -1, 5, 0);

            ++pShow;
            nOffset += 0x20;
        }
    }

    D2UiRecordStrc tRecord;
    sub_00660CB0_GetUiRecord(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRecord);
    for (int nSlot = 0; nSlot < tRecord.nBoxes; ++nSlot)
    {
        if (nSlot > 3 && !gbGlobal_007BEFA0)
            break;

        D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nSlot);
        if (!pItem)
            continue;

        int nBox;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nBox = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
                nBox = PATH_GetXPosition(pItem->pDynamicPath);
            else
                nBox = 0;
            break;
        }

        if (!ITEMS_CheckItemFlag(pItem, 4, 0x5D5, ".\\UI\\panel.cpp") && ITEMS_CheckIfUseable(pItem) && !sub_004C2240(pItem))
        {
            if (pItem == gpBeltItemA_007BEFA8 && gnBeltHover_007BEF94)
                sub_004978D0_DrawBeltBoxFrame(nBox, 1);
            else
                sub_004978D0_DrawBeltBoxFrame(nBox, 2);
        }
        else
        {
            sub_004978D0_DrawBeltBoxFrame(nBox, 0);
        }

        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex_00722354, gnUiRecordRow_007A5218, &tRect, nBox);
        sub_0046EE80_DrawItemCel(pItem, tRect.nLeft, tRect.nTop);
        if (nSlot < sizeof(gaBeltKeys_00722404) / sizeof(gaBeltKeys_00722404[0]) && ITEMS_CheckIfUseable(pItem))
        {
            Unicode wszKey[100];
            for (int i = 0; i < 100; ++i)
            {
                wszKey[i].wChar = 0;
            }

            if (sub_00469AA0(gaBeltKeys_00722404[nSlot], 1) != 0xFFFF || sub_00469AA0(gaBeltKeys_00722404[nSlot], 0) != 0xFFFF)
            {
                sub_005267E0(wszKey, sub_0046A530_GetKeyName(gaBeltKeys_00722404[nSlot], 1));
                const int nLength = sub_00526800(wszKey);
                if (sub_00501820(wszKey) > 0x1C)
                {
                    Unicode* pEnd = &wszKey[nLength];
                    do
                    {
                        pEnd->wChar = 0;
                        --pEnd;
                    }
                    while (sub_00501820(wszKey) > 0x1C);
                }
                sub_00502320(wszKey, tRect.nLeft + 2, tRect.nBottom - 2, 4, 0);
            }
        }
    }

    if (gnUiRecordIndex_00722354 == 2 || sub_004538D0(0x1F) || gbUiRecordMode_007BEF98)
        sub_00497920_DrawCursorBeltBox(pInventory);
}

void __stdcall sub_00499BB0_BeltMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gdwGlobal_007A061C || sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
            }
            sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
            return;
        }

        if (!sub_004538D0(0x1F))
        {
            pMsg->bReturn = 0;
            gbUiRecordMode_007BEF98 = 0;
            gnBeltRecordMode2_007BEF9C = 0;
            gnBeltHover_007BEF94 = 0;
            return;
        }

        pMsg->bReturn = 0;
        gnBeltRecordMode2_007BEF9C = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (nX < gnGlobal_0071146C / 2 + 0x17 || nX > gnGlobal_0071146C / 2 + 0x91 || nY < gnGlobal_00711470 - 0x27 || nY > gnGlobal_00711470 - 0xA)
    {
        pMsg->bReturn = 0;
        gnBeltHover_007BEF94 = 0;
        return;
    }

    if (!sub_00453A90_GetUIVarUnchecked(9))
    {
        gbUiRecordMode_007BEF98 = 1;
        gnBeltRecordMode2_007BEF9C = 1;
        sub_00498930_HoverBeltBox(nX, pPlayer->pInventory, nY);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x00499D10
void __stdcall sub_00499D10_BeltClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30() || sub_00463DF0())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_00498DC0_MouseMoveMsg(pMsg))
    {
        pMsg->bReturn = 1;
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
            pMsg->bReturn = 0;
            return;
        }

        sub_00498A90_UseBeltSlot(nBox, pPlayer, pPlayer->pInventory, (pMsg->wParam >> 2) & 1);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
    gnBeltHover_007BEF94 = 0;
}

// 0x00499E10
void __cdecl sub_00499E10_SetRedColour()
{
    gbGlobal_007BF034 = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00499E30
void __cdecl sub_00499E30_SetBlackColour()
{
    gbGlobal_007BF034 = D2Win_10034_MixRGB(0, 0, 0);
}

// 0x0049C0A0
void __cdecl sub_0049C0A0_LoadPartyCels()
{
    gpPanelQuadCel_007BF018 = sub_004520C0_LoadUiCelFile("Menu\\party");
    gpCelFile_007BF01C = sub_004520C0_LoadUiCelFile("Menu\\partybuttons");
    gpCelFile_007BF020 = sub_004520C0_LoadUiCelFile("Menu\\partyboxes");
    gpCelFile_007BF024 = sub_004520C0_LoadUiCelFile("Panel\\inv_goldbtn");
    gpCelFile_007BF028 = sub_004520C0_LoadUiCelFile("Menu\\partybar");
}

// 0x0049C0F0
void __cdecl sub_0049C0F0_FreePartyCels()
{
    if (gpPanelQuadCel_007BF018)
    {
        sub_00478A00(gpPanelQuadCel_007BF018);
        gpPanelQuadCel_007BF018 = 0;
    }
    if (gpCelFile_007BF01C)
    {
        sub_00478A00(gpCelFile_007BF01C);
        gpCelFile_007BF01C = 0;
    }
    if (gpCelFile_007BF020)
    {
        sub_00478A00(gpCelFile_007BF020);
        gpCelFile_007BF020 = 0;
    }
    if (gpCelFile_007BF024)
    {
        sub_00478A00(gpCelFile_007BF024);
        gpCelFile_007BF024 = 0;
    }
    if (gpCelFile_007BF028)
    {
        sub_00478A00(gpCelFile_007BF028);
        gpCelFile_007BF028 = 0;
    }
}

// 0x0049C3D0
void __cdecl sub_0049C3D0_DrawPartyPanel()
{
    sub_00499E50_DrawPanelQuad();
    sub_0049A580_DrawPlayerName();
    sub_0049C270_DrawPartyRows();
    sub_0049A510_DrawPartyButtons();
    sub_0049A950_DrawPanelCel();
    sub_0049ABD0_DrawRosterHoverHints();
    sub_0049B330_DrawRosterButtonHints();
    sub_0049A9B0_RefreshRosterIndices();
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= gnGlobal_007A2858 + 0x116 && nX <= gnGlobal_007A2858 + 0x136 && nY >= 0x185 - gnGlobal_007A285C && nY <= 0x1A5 - gnGlobal_007A285C)
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x102F), gnGlobal_007A2858 + 0x125, 0x182 - gnGlobal_007A285C, 0, 1);
}

// build: context sub_00499E50_DrawPanelQuad
void __cdecl sub_00499E50_DrawPanelQuad()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpPanelQuadCel_007BF018;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 256, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 256, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
}

// build: context sub_004A9E60_AssignHotkey
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey)
{
    for (int i = 0; i < 60; ++i)
    {
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            if (gnHotkeySkill_007C06C8[nHotkey] != -1)
            {
                sub_004786A0_SendDwords2(0x51, (nHotkey << 16) + 0xFFFF, -1);
            }

            gnHotkeySkill_007C06C8[nHotkey] = gtHotkeySlots_007C0300.nSkill[i];
            if (!gbGlobal_007C07FC)
            {
                gbHotkeyLeft_007C07B8[nHotkey] = 0;
            }
            else
            {
                gbHotkeyLeft_007C07B8[nHotkey] = 1;
            }
            gnHotkeyOwner_007C0768[nHotkey] = gtHotkeySlots_007C0300.f_2D0[i];
            sub_004786A0_SendDwords2(0x51, (nHotkey << 16) + (gbHotkeyLeft_007C07B8[nHotkey] ? 0x8000 : 0) + gnHotkeySkill_007C06C8[nHotkey], gnHotkeyOwner_007C0768[nHotkey]);

            for (int j = 0; j < 16; ++j)
            {
                if (gnHotkeySkill_007C06C8[nHotkey] == gnHotkeySkill_007C06C8[j] && gnHotkeyOwner_007C0768[nHotkey] == gnHotkeyOwner_007C0768[j] && nHotkey != j)
                {
                    gnHotkeySkill_007C06C8[j] = -1;
                    gbHotkeyLeft_007C07B8[j] = -1;
                    gnHotkeyOwner_007C0768[j] = -1;
                    sub_004786A0_SendDwords2(0x51, (j << 16) + 0xFFFF, -1);
                }
            }
        }
    }
}

// build: context sub_004AAAE0_DrawPagedPanel
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 2;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 3;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
}

// build: context sub_004AB530_DrawTabCel
void __cdecl sub_004AB530_DrawTabCel()
{
    int nX = gnTabTable_00724CE4[gbGlobal_007A0522][gnGlobal_00724BEC];
    if (nX == -149)
    {
        gnTabSelection_00724CE0 = 1;
    }
    else if (nX == -220)
    {
        gnTabSelection_00724CE0 = 2;
    }
    else if (nX == -305)
    {
        gnTabSelection_00724CE0 = 3;
    }
    nX += gnGlobal_0071146C - gnGlobal_007A2858;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gbGlobal_007C0C38 != 0) + 10;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nX, gnGlobal_007A285C + gnGlobal_00711470 - 63, -1, 5, 0);
}

// 0x004BE340
int __fastcall sub_004BE340_CountLinesInView(D2TextPanelStrc* pPanel)
{
    const int nLineCount = pPanel->f_180748;
    int nTotal = 0;
    for (int i = 0; i < nLineCount; ++i)
    {
        if (i >= pPanel->nFirstLine && i < nLineCount)
        {
            for (int k = 0; k < 6; ++k)
            {
                if (pPanel->pLines[i].wszText[k][0].wChar)
                {
                    nTotal += *(int*)pPanel->nLineStep;
                }
            }
            nTotal += *(int*)pPanel->nLineGap;
        }

        if (nTotal > pPanel->nHeight - 20)
        {
            i -= pPanel->nFirstLine;
            if (i < 1)
            {
                i = 1;
            }
            return i;
        }
    }

    return nLineCount;
}

#include "gen/data/Source/D2Client/UI/panel.inc"
