#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2Txt.h"

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct D2BeltSlotStrc;
struct Unicode;
struct D2TextEntryStrc;
struct D2MonStatsTxt;
struct D2CharStatsTxt;
struct D2DifficultyLevelsTxt;
struct D2CharTextStrc;
struct D2CharFieldStrc;
struct D2HoverBoxStrc;
struct D2ZeroDwordStrc;
struct D2PointsTextStrc;
struct D2SkillsTxt;
struct D2SkillDescTxt;
struct D2UiCelFileStrc;
struct D2SkillIconStateStrc;

#pragma pack(push, 2)
struct D2BeltSlotStrc
{
    int nX;
    int nY;
    int bActive;
    unsigned short wCode;
};

#pragma pack(pop)

extern int gnScreenWidth; // 0x0071146C
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern int gbStatScreenButtonDown; // 0x007C02F4
extern D2BeltSlotStrc gaStatButtons[4]; // 0x00724A48
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
int __cdecl sub_00468830(); // 0x00468830
void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall ROSTERPETS_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
void __stdcall ROSTERPETS_HandleButtonDown(SMSGHANDLER_PARAMS* pMsg); // 0x00467F20
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

#pragma pack(push, 2)
struct D2TextEntryStrc
{
    unsigned short wStringId;
    int nLength;
    int nX;
    int nY;
    int nWidth;
};

#pragma pack(pop)

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern D2TextEntryStrc gaTextEntries[15]; // 0x00724824



#pragma pack(push, 2)
struct D2CharTextStrc
{
    int nX;
    int nY;
    int nX2;
    unsigned short wStringId;
    int nLength;
};

#pragma pack(pop)
struct D2CharFieldStrc
{
    int nX;
    int nY;
    int nX2;
    int nStatId;
};

struct D2ZeroDwordStrc
{
    int nValue;

    D2ZeroDwordStrc() : nValue(0) {}
};

struct D2PointsTextStrc
{
    Unicode w0, w1, w2, w3, w4, w5, w6, w7, w8, w9;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" const char gszFormatLd_006D9BE8[]; // 0x006D9BE8
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
extern unsigned char gnTextColor; // 0x007C02F8
extern void* gpInvCharCel; // 0x007BEF64
extern void* gpSkillPointsCel; // 0x007BEF20
extern void* gpLevelSocketCel; // 0x007C02E0
extern void* gpLevelCel; // 0x007C02DC
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2CharTextStrc gaCharTexts[15]; // 0x00724818
extern D2CharFieldStrc gaCharFields[18]; // 0x00724928
extern D2HoverBoxStrc gaHoverBoxes[2]; // 0x006DA430
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
void* __cdecl GAME_GetBuySellButtonCells(); // 0x00454600
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __cdecl sub_00466DC0(); // 0x00466DC0
int __cdecl UI_GetHoverClassId(); // 0x00466DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
char* __fastcall ROSTER_GetUnitName(D2UnitStrc* pUnit); // 0x0047A210
void __cdecl PANEL_SetBlackColour(); // 0x00499E30
int __stdcall TEXT_GetChanceToHit(int nAttackRating); // 0x004A7340
int __cdecl MONSTER_GetPlayerDefensePercent(); // 0x004A74A0
void __fastcall SKILLDESC_RefreshSkills(D2UnitStrc* pUnit); // 0x004EDA20
int __fastcall sub_004EDA80_CallSkillDescFunc(D2UnitStrc* pUnit, int bLeft); // 0x004EDA80
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
void __stdcall STR_GroupUintDigits(Unicode* pOut, unsigned int nValue, int nSize); // 0x00525350
int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount); // 0x005262A0
Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
Unicode* __fastcall win2Unicode(Unicode* pDest, const char* szSource, int nCount); // 0x00526F20
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30
int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int nArg); // 0x00622720
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall STATES_CheckStateMaskArmRedOnUnit(D2UnitStrc* pUnit); // 0x0063A5F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
static void TEXT_DrawBlockChanceHover(int nX, int nY, int nValue); // 0x004A7180
static void __stdcall sub_004A7AE0_DrawHoverToHit(int nX, int nY, int nLeftChance, int nRightChance); // 0x004A7AE0


#pragma pack(push, 2)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};

#pragma pack(pop)

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2UiCelFileStrc gaSkillIconCels[7]; // 0x00724AC0
extern int gnSkillPage; // 0x00724BEC
extern D2UiCelFileStrc gaPanelCels[7]; // 0x00724BF0
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8
extern "C" int gbSkillPointsHighlight; // 0x007C0C3C
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
void __stdcall sub_004A9D70_ClearSkillHotkeys(D2SkillsTxt* pSkillsTxt, int nQuantity); // 0x004A9D70
void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nX, int nArg3, int nArg4, int nArg5); // 0x004AA3A0
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage); // 0x004AAAE0
void __cdecl sub_004AACE0_DrawSkillTreeTexts(); // 0x004AACE0
void __stdcall sub_004AB310_DrawTabHoverText(int nValue); // 0x004AB310
void __cdecl sub_004AB530_DrawTabCel(); // 0x004AB530
void __cdecl sub_004AB630_DrawTabHint(); // 0x004AB630
void __cdecl sub_004AC200_RefreshSkillTree(); // 0x004AC200
void __cdecl sub_004AC4D0_DrawSkillTree(); // 0x004AC4D0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040
void __stdcall sub_K05_EmitUse(int nValue);

// 0x004A76C0
static int sub_004A76C0_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && pMsg->nXpos <= gnScreenWidth / 2 && pMsg->nYpos < gnScreenHeight - 0x2F)
    {
        if (sub_00468830() == 6)
            UI_CancelCursorItemUse();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

void __stdcall sub_004A7720_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (nX >= gnPanelOffsetX + 0x80 && nX <= gnPanelOffsetX + 0xA0 && nY >= gnScreenHeight + gnPanelOffsetY - 0x5C && nY <= gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        gbStatScreenButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (nX >= gnPanelOffsetX && nX <= gnScreenWidth / 2 - 1 && nY >= gnPanelOffsetY && nY <= gnScreenHeight + gnPanelOffsetY - 0x31)
    {
        if (STATLIST_GetUnitBaseStat(sub_00463DD0_GetPlayerUnit(), STAT_STATPTS, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                const int nSlotY = gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight;
                if (nY > nSlotY - 0x1F6 && nY < nSlotY - 0x1E0 && nX > gaStatButtons[i].nX + gnPanelOffsetX && nX < gaStatButtons[i].nX + gnPanelOffsetX + 0x28)
                {
                    gaStatButtons[i].bActive = 1;
                    ROSTERPETS_HandleButtonDown(pMsg);
                    sub_004B9A00(5, 0, 0, 0, 0);
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }
            }
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!sub_004A76C0_ClaimLeftPanelClick(pMsg))
        pMsg->bReturn = 0;
}

void __stdcall sub_004A78C0_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    ROSTERPETS_HandleButtonUp(pMsg);
    gbStatScreenButtonDown = 0;
    if (nX >= gnPanelOffsetX + 0x80 && nX <= gnPanelOffsetX + 0xA0 && nY >= gnScreenHeight + gnPanelOffsetY - 0x5C && nY <= gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        UI_SetUIVar(2, 1, 0);
        return;
    }
    if (nX >= gnPanelOffsetX && nX <= gnScreenWidth / 2 - 1 && nY >= gnPanelOffsetY && nY <= gnScreenHeight + gnPanelOffsetY - 0x31)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                const int nSlotY = gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight;
                gaStatButtons[i].bActive = 0;
                if (nY > nSlotY - 0x1F6 && nY < nSlotY - 0x1E0 && nX > gaStatButtons[i].nX + gnPanelOffsetX && nX < gaStatButtons[i].nX + gnPanelOffsetX + 0x28)
                {
                    int nCount = STATLIST_UnitGetStatValue(pPlayer, STAT_STATPTS, 0);
                    if (GetKeyState(0x10) < 0)
                        nCount = 1;
                    else if (!nCount)
                        break;
                    do
                    {
                        const int nStack = nCount < 0x20 ? nCount : 0x20;
                        nCount -= nStack;
                        sub_004785B0_SendPacket3(0x3A, ((unsigned char)(nStack - 1) << 8) | gaStatButtons[i].wCode);
                    }
                    while (nCount);
                    break;
                }
            }
        }
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!sub_004A76C0_ClaimLeftPanelClick(pMsg))
        pMsg->bReturn = 0;
}

// 0x004A7AA0
void __cdecl sub_004A7AA0_InitTextEntryLengths()
{
    for (unsigned int i = 0; i < sizeof(gaTextEntries) / sizeof(gaTextEntries[0]); ++i)
    {
        gaTextEntries[i].nLength = sub_00526800(D2LANG_GetStringFromTblIndex(gaTextEntries[i].wStringId));
    }
}

#include "gen/data/Source/D2Client/Unknown_004A76C0.inc"
struct D2SkillStrc;
struct D2UnitStrc;

int gbStatScreenButtonDown; // 0x007C02F4

static inline D2MonStatsTxt* sub_MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline D2CharStatsTxt* sub_CharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x004A7080
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor)
{
    int nSpan = nRight - nLeft + 1;
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    if (nWidth < nSpan)
    {
        nLeft += (nSpan - nWidth) >> 1;
    }

    D2Win_10117_DrawText(wszText, nLeft, nY, nColor, 0);
}

// build: symbol ?TEXT_GetWeaponBlock@* 0x004A70C0
static int TEXT_GetWeaponBlock(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    int i = 0;
    const int nCount = STATLIST_CopyStats(pUnit, STAT_PASSIVE_WEAPONBLOCK, aStats, 0x20);
    int nBest = 0;
    for (; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0 || ((pLeftItem && ITEMSIsA(pLeftItem, nItemType)) || (pRightItem && ITEMSIsA(pRightItem, nItemType))) && nValue > nBest)
        {
            nBest = nValue;
        }
    }

    return nBest;
}

static void TEXT_DrawBlockChanceHover(int nX, int nY, int nValue)
{
    if (nValue < 5)
    {
        nValue = 5;
    }
    else if (nValue > 0x5F)
    {
        nValue = 0x5F;
    }

    int anText[0x40];
    for (int k = 0; k < 0x40; ++k)
    {
        anText[k] = 0;
    }

    if (nX < gnPanelOffsetX + 0xAD || nX > gnPanelOffsetX + 0x137
        || nY < gnScreenHeight + gnPanelOffsetY - 0x11E || nY > gnScreenHeight + gnPanelOffsetY - 0x10B)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    int nLevel = UNITS_GetBlockRate(pPlayer, GAME_IsExpansion());
    if (nLevel <= 0)
    {
        nLevel = TEXT_GetWeaponBlock(pPlayer);
        if (nLevel > 0)
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pPlayer, pPlayer->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass != 0x0D)
            {
                nLevel = 0;
            }
        }
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(UI_GetHoverClassId());
    D2_ASSERT(pMonStatsTxtRecord, 0x15C);

    Unicode* wszText = (Unicode*)anText;
    if (nLevel)
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2779), nLevel, nValue, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }
    else
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2778), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }

    D2Win_10132(wszText, gnPanelOffsetX + 0x8B, gnScreenHeight + gnPanelOffsetY - 0x13B, gnTextColor, 2, 0);
}

static void __stdcall sub_004A7AE0_DrawHoverToHit(int nX, int nY, int nLeftChance, int nRightChance)
{
    int anText[0x40];
    for (int k = 0; k < 0x40; ++k)
    {
        anText[k] = 0;
    }

    PANEL_SetBlackColour();

    int bLeft = 0;
    int bRight = 0;
    if (nX >= gnPanelOffsetX + 0xA2 && nX <= gnPanelOffsetX + 0x140
        && nY >= gnPanelOffsetY + gnScreenHeight - 0x14E && nY <= gnPanelOffsetY + gnScreenHeight - 0x13B)
    {
        bLeft = 1;
    }
    else if (nX >= gnPanelOffsetX + 0xA2 && nX <= gnPanelOffsetX + 0x140
        && nY >= gnPanelOffsetY + gnScreenHeight - 0x134 && nY <= gnPanelOffsetY + gnScreenHeight - 0x121)
    {
        bRight = 1;
    }

    if (!nLeftChance)
    {
        bLeft = 0;
    }

    if (!nRightChance)
    {
        bRight = 0;
    }

    int nIndex;
    int nChance;
    if (bLeft)
    {
        nIndex = 0;
        nChance = nLeftChance;
    }
    else if (bRight)
    {
        nIndex = 1;
        nChance = nRightChance;
    }
    else
    {
        return;
    }

    if (nChance < 5)
    {
        nChance = 5;
    }
    else if (nChance > 0x5F)
    {
        nChance = 0x5F;
    }

    AUTOMAP_DrawFramedBox(gaHoverBoxes[nIndex].nBoxX + gnPanelOffsetX, gaHoverBoxes[nIndex].nBoxY + gnPanelOffsetY + gnScreenHeight - 0x1E0, 0x9B, 0x1E, gnTextColor, 2);
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x103F), gaHoverBoxes[nIndex].nTitleX + gnPanelOffsetX, gaHoverBoxes[nIndex].nTitleY + gnPanelOffsetY + gnScreenHeight - 0x1E0, 0, 0);

    D2MonStatsTxt* pMonStatsTxtRecord = sub_MonStatsTxtRecord(sub_00466DC0());
    D2_ASSERT(pMonStatsTxtRecord, 0xEC);

    Unicode* wszText = (Unicode*)anText;
    sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2777), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nChance);
    D2Win_10117_DrawText(wszText, gaHoverBoxes[nIndex].nTextX + gnPanelOffsetX, gaHoverBoxes[nIndex].nTextY + gnPanelOffsetY + gnScreenHeight - 0x1E0, 0, 0);
}

// 0x004A7D00
void __cdecl sub_004A7D00_DrawCharStats()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nColor = 0;
    int nWidth;
    D2CelContextStrc tCel;
    int nHeight;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = gpInvCharCel;
    tCel.nDirection = 0;
    tCel.nFrame = 0;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tCel.nFrame = 1;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tCel.nFrame = 2;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    tCel.nFrame = 3;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= gnPanelOffsetX + 0x80 && nMouseX <= gnPanelOffsetX + 0xA0
        && nMouseY >= gnPanelOffsetY + gnScreenHeight - 0x5C && nMouseY <= gnPanelOffsetY + gnScreenHeight - 0x3C)
    {
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnPanelOffsetX + 0x8F, gnPanelOffsetY + gnScreenHeight - 0x5F, 0, 1);
    }

    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
    {
        tCel.pCellFile = gpSkillPointsCel;
        tCel.nFrame = 0;
        TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 3, gnScreenHeight + gnPanelOffsetY - 0x74, -1, 5, 0);

        D2PointsTextStrc wszPoints;
        D2Win_10127_SetFont(6);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xB, gnScreenHeight + gnPanelOffsetY - 0x7D, gnPanelOffsetX + 0x58, D2LANG_GetStringFromTblIndex(0xFEB), 1);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xB, gnPanelOffsetY + gnScreenHeight - 0x75, gnPanelOffsetX + 0x58, D2LANG_GetStringFromTblIndex(0xFEC), 1);

        int anPoints[3];
        wsprintfA((char*)anPoints, "%i", STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0));
        D2Win_10127_SetFont(1);
        win2Unicode(&wszPoints.w0, (const char*)anPoints, 9);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0x5C, gnScreenHeight + gnPanelOffsetY - 0x78, gnPanelOffsetX + 0x7F, &wszPoints.w0, 0);
    }

    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
    {
        for (int i = 0; i < 4; ++i)
        {
            tCel.pCellFile = gpLevelSocketCel;
            const int nX = gaStatButtons[i].nX + gnPanelOffsetX;
            const int nY = gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0;
            tCel.nFrame = 0;
            TEXTURE_CelDraw(&tCel, nX + 5, nY + 5, -1, 5, 0);
            tCel.pCellFile = gpLevelCel;
            tCel.nFrame = gaStatButtons[i].bActive != 0;
            TEXTURE_CelDraw(&tCel, nX + 8, nY + 1, -1, 5, 0);
        }
    }

    D2Win_10127_SetFont(6);
    for (unsigned int i = 0; i < sizeof(gaCharTexts) / sizeof(gaCharTexts[0]); ++i)
    {
        D2ZeroDwordStrc aLine[50];
        Unicode* wszLine = (Unicode*)aLine;
        strncpy(wszLine, D2LANG_GetStringFromTblIndex(gaCharTexts[i].wStringId), 99);
        const int nLeft = gaCharTexts[i].nX + gnPanelOffsetX;
        const int nRight = gaCharTexts[i].nX2 + gnPanelOffsetX;
        const int nY = gaCharTexts[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0;
        wszLine[99].wChar = 0;
        Unicode* pChar = wszLine;
        const int nLength = sub_00526800(wszLine);
        int nPos = 0;
        while (pChar->wChar)
        {
            if (pChar->wChar == '\n')
            {
                wszLine[nPos].wChar = 0;
                if (nPos < nLength)
                {
                    Unicode* pSecond = pChar + 1;
                    TEXT_DrawCenteredText(nLeft, nY - 4, nRight, wszLine, 0);
                    TEXT_DrawCenteredText(nLeft, nY + 4, nRight, pSecond, 0);
                    goto NEXT_TEXT;
                }

                break;
            }

            ++pChar;
            ++nPos;
        }

        TEXT_DrawCenteredText(nLeft, nY, nRight, wszLine, 0);
NEXT_TEXT:;
    }

    SKILLDESC_RefreshSkills(pPlayer);
    D2Win_10127_SetFont(0);
    const int nLeftChance = TEXT_GetChanceToHit(sub_004EDA80_CallSkillDescFunc(pPlayer, 1));
    const int nRightChance = TEXT_GetChanceToHit(sub_004EDA80_CallSkillDescFunc(pPlayer, 0));
    const int nPercent = MONSTER_GetPlayerDefensePercent();
    sub_004A7AE0_DrawHoverToHit(nMouseX, nMouseY, nLeftChance, nRightChance);
    TEXT_DrawBlockChanceHover(nMouseX, nMouseY, nPercent);
    D2Win_10127_SetFont(1);

    tCel.pCellFile = GAME_GetBuySellButtonCells();
    tCel.nFrame = (gbStatScreenButtonDown != 0) + 10;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 0x80, gnPanelOffsetY + gnScreenHeight - 0x3C, -1, 5, 0);

    int anNumber[0x20];
    D2ZeroDwordStrc aText[0x40];
    Unicode* wszText = (Unicode*)aText;
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_CharStatsTxtRecord(pPlayer->dwClassId);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xC1, gnPanelOffsetY + gnScreenHeight - 0x1C7, gnPanelOffsetX + 0x136, (const Unicode*)pCharStatsTxtRecord->wszClassName, 0);

        const char* szName = ROSTER_GetUnitName(pPlayer);
        const unsigned int nChars = sub_005262A0_Utf8CountChars(szName, strlen(szName)) + 1;
        if (nChars > 11)
        {
            if (nChars >= 14)
            {
                D2Win_10127_SetFont(6);
            }
            else
            {
                D2Win_10127_SetFont(0);
            }
        }

        win2Unicode(wszText, szName, 0x80);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xD, gnScreenHeight + gnPanelOffsetY - 0x1C7, gnPanelOffsetX + 0xA0, wszText, 0);
        D2Win_10127_SetFont(1);
    }

    int nFont;
    for (unsigned int i = 0; i < sizeof(gaCharFields) / sizeof(gaCharFields[0]); ++i)
    {
        int bCheckWidth = 0;
        int nValue = STATLIST_UnitGetStatValue(pPlayer, gaCharFields[i].nStatId, 0);
        const int nBase = STATLIST_GetUnitBaseStat(pPlayer, gaCharFields[i].nStatId, 0);
        switch (gaCharFields[i].nStatId)
        {
        case STAT_MAXHP:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_HITPOINTS:
        {
            nValue >>= 8;
            D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11 && (unsigned int)nValue <= 1)
            {
                nValue = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;
        }
        case STAT_MAXMANA:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_MANA:
            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_MAXSTAMINA:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_STAMINA:
            nValue >>= 8;
            wsprintfA((char*)anNumber, gszFormatLd_006D9BE8, nValue);
            bCheckWidth = 1;
            break;

        case STAT_MAGICRESIST:
        case STAT_FIRERESIST:
        case STAT_LIGHTRESIST:
        case STAT_COLDRESIST:
        case STAT_POISONRESIST:
        {
            D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
            int nMax = 0;
            switch (gaCharFields[i].nStatId)
            {
            case STAT_MAGICRESIST:
                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXMAGICRESIST, 0);
                break;

            case STAT_FIRERESIST:
                if (STATES_CheckStateMaskRFBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRFRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXFIRERESIST, 0);
                break;

            case STAT_LIGHTRESIST:
                if (STATES_CheckStateMaskRLBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRLRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXLIGHTRESIST, 0);
                break;

            case STAT_COLDRESIST:
                if (STATES_CheckStateMaskRCBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRCRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXCOLDRESIST, 0);
                break;

            case STAT_POISONRESIST:
                if (STATES_CheckStateMaskRPBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRPRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXPOISONRESIST, 0);
                break;
            }

            if (GAME_IsExpansion())
            {
                nValue += pDifficultyLevelsTxtRecord->dwResistPenalty;
            }
            else
            {
                switch (GAME_GetDifficulty())
                {
                case 1:
                    nValue -= 20;
                    break;

                case 2:
                    nValue -= 50;
                    break;
                }
            }

            nMax += 75;
            nMax = D2_MIN(nMax, 95);
            nValue = D2_MIN(D2_MAX(nValue, -100), nMax);
            if (nValue >= nMax && nColor != 3)
            {
                nColor = 4;
            }
            else if (nValue < 0)
            {
                nColor = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            break;
        }
        case STAT_ARMORCLASS:
            nValue = UNITS_GetDefense(pPlayer);
            if (STATES_CheckStateMaskArmBlueOnUnit(pPlayer))
            {
                nColor = 3;
            }

            if (pPlayer->pInventory && INVENTORY_GetEquippedShield(pPlayer->pInventory, 0) && STATES_CheckState(pPlayer, STATE_HOLYSHIELD))
            {
                nColor = 3;
            }

            if (STATES_CheckStateMaskArmRedOnUnit(pPlayer))
            {
                nColor = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            if (nValue >= 1000 || STRTABLE_GetLanguage() == 6)
            {
                bCheckWidth = 1;
            }
            break;

        case STAT_NEXTEXP:
        {
            const int nLevel = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0);
            const int nClass = GAME_GetUnitClassId(pPlayer);
            if (nLevel != DATATBLS_GetMaxLevel(nClass))
            {
                nValue = DATATBLS_GetLevelThreshold(nClass, nLevel);
            }

            STR_GroupUintDigits(wszText, nValue, 0x80);
            TEXT_DrawCenteredText(gaCharFields[i].nX + gnPanelOffsetX, gaCharFields[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, gaCharFields[i].nX2 + gnPanelOffsetX, wszText, 0);
            nColor = 0;
            continue;
        }
        case STAT_EXPERIENCE:
            STR_GroupUintDigits(wszText, nValue, 0x80);
            TEXT_DrawCenteredText(gaCharFields[i].nX + gnPanelOffsetX, gaCharFields[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, gaCharFields[i].nX2 + gnPanelOffsetX, wszText, 0);
            nColor = 0;
            continue;

        default:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            break;
        }

        win2Unicode(wszText, (const char*)anNumber, 0x80);
        wszText[0x7F].wChar = 0;
        if (bCheckWidth)
        {
            nFont = 0xE;
            int nNewFont;
            if (nValue >= 1000)
            {
                nNewFont = D2Win_10127_SetFont(0);
            }
            else
            {
                D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
                if (nWidth < gaCharFields[i].nX2 - gaCharFields[i].nX)
                {
                    goto DRAW_FIELD;
                }

                nNewFont = D2Win_10127_SetFont(0);
            }

            nFont = nNewFont;
        }
        else
        {
            nFont = 0xE;
        }

DRAW_FIELD:
        TEXT_DrawCenteredText(gaCharFields[i].nX + gnPanelOffsetX, gaCharFields[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, gaCharFields[i].nX2 + gnPanelOffsetX, wszText, nColor);
        nColor = 0;
        if (nFont != 0xE)
        {
            D2Win_10127_SetFont(nFont);
        }
    }
}

unsigned char gnCharClass; // 0x007A0522

D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300

int ganIconValues[16]; // 0x007C0728

unsigned short gawIconValues[8]; // 0x007C07A8

void* gpSkillIconCel; // 0x007C07F8

int gbSkillSelectRight; // 0x007C07FC

int gnGlobal_007C0C40; // 0x007C0C40

int gbInSkillPanelDraw; // 0x007C0C44

int gbSkillPanelDrawn; // 0x007C0C4C

unsigned char gbColor; // 0x007C0C50

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004A89D0
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

// 0x004AA900
int __cdecl sub_004AA900_IsStateOrValue()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer && STATES_CheckState(pPlayer, STATE_UNINTERRUPTABLE))
    {
        return 1;
    }
    return gbSkillPointsHighlight;
}

// 0x004AA920
void __cdecl sub_004AA920_LoadPanelCel()
{
    char* szPath = gaPanelCels[gnCharClass].szPath;
    D2_ASSERT(szPath, 136);
    gaPanelCels[gnCharClass].pCelFile = sub_004520C0_LoadUiCelFile(szPath);
}

// 0x004AB2F0
void __cdecl sub_004AB2F0_SetBlackColor()
{
    gbColor = D2Win_10034_MixRGB(0, 0, 0);
}

// 0x004AC690
void __cdecl sub_004AC690_DrawSkillPanel()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2Win_10127_SetFont(1);
    gbSkillPanelDrawn = 1;
    sub_004AAAE0_DrawPagedPanel(gaPanelCels[gnCharClass].pCelFile, gnSkillPage);
    sub_004AACE0_DrawSkillTreeTexts();
    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0) > 0)
    {
        gnGlobal_007C0C40 = 1;
        gbInSkillPanelDraw = 1;
        sub_004AC200_RefreshSkillTree();
    }
    else
    {
        gnGlobal_007C0C40 = 0;
        gbInSkillPanelDraw = 0;
        sub_004AC4D0_DrawSkillTree();
    }
    sub_004AB530_DrawTabCel();
    sub_004AB630_DrawTabHint();
    sub_004AB310_DrawTabHoverText(gnSkillPage);
}

// 0x004A8CF0
static int __stdcall sub_004A8CF0_IsMouseInRect(int nX, int nWidth, int nY, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

// 0x004A8A30
void __cdecl sub_004A8A30_InitSkillIcons()
{
    gpSkillIconCel = sub_004520C0_LoadUiCelFile("Spells\\Skillicon");
    gaSkillIconCels[gnCharClass].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels[gnCharClass].szPath);

    int i;
    for (i = 0; i < 16; ++i)
    {
        ganIconValues[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gaHotkeyOwners[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gaHotkeyLeft[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gaHotkeySkills[i] = -1;
    }

    memset(&gtHotkeySlots, 0, 0x3C5);
    for (i = 0; i < 60; ++i)
    {
        gtHotkeySlots.anValues[i] = -1;
    }
    for (i = 0; i < 8; ++i)
    {
        gawIconValues[i] = 0;
    }
}

// 0x004A8C00
void __cdecl sub_004A8C00_FreeSkillIcons()
{
    if (gpSkillIconCel)
    {
        ARCHIVE_FreeClientCellFile(gpSkillIconCel);
        gpSkillIconCel = 0;
    }

    if (gaSkillIconCels[gnCharClass].pCelFile)
    {
        ARCHIVE_FreeClientCellFile(gaSkillIconCels[gnCharClass].pCelFile);
        gaSkillIconCels[gnCharClass].pCelFile = 0;
    }

    for (int i = 0; i < 7; ++i)
    {
        if (gaSkillIconCels[i].pCelFile)
        {
            ARCHIVE_FreeClientCellFile(gaSkillIconCels[i].pCelFile);
            gaSkillIconCels[i].pCelFile = 0;
        }
    }
}

// 0x004A8C80
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt)
{
    if (!pSkillsTxt)
    {
        return gaSkillIconCels[gnCharClass].pCelFile;
    }

    int nClass = pSkillsTxt->nSkillId;
    nClass = SKILLS_GetClassIdFromSkillId(nClass);
    if (nClass >= 0 && nClass <= 6)
    {
        if (!gaSkillIconCels[nClass].pCelFile)
        {
            gaSkillIconCels[nClass].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels[nClass].szPath);
        }
        return gaSkillIconCels[nClass].pCelFile;
    }

    return gpSkillIconCel;
}

// 0x004A8CE0
void __fastcall sub_004A8CE0_SetValue(int nValue)
{
    gbSkillSelectRight = nValue;
}

// 0x004A8D30
int __fastcall sub_004A8D30_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    const int nState = sub_004D9FC0(pUnit, pSkill);
    if (nState)
    {
        return nState == 6 ? 4 : 1;
    }
    return 0;
}

// 0x004A9A90
int __fastcall sub_004A9A90_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9AE0
int __fastcall sub_004A9AE0_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9B30
int __fastcall sub_004A9B30_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9B80
int __fastcall sub_004A9B80_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9DF0
void __cdecl sub_004A9DF0_UpdateSkillIcons()
{
    D2SkillStrc* pSkill = UNITS_GetStartSkill(sub_00463DD0_GetPlayerUnit());
    D2_ASSERT(pSkill, 1149);

    do
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 36))
        {
            sub_004A9D70_ClearSkillHotkeys(pSkillsTxt, SKILLS_GetQuantity(pSkill));
        }
        pSkill = SKILLS_GetNextSkill(pSkill);
    }
    while (pSkill);
}

// 0x004AA7E0
void __cdecl sub_004AA7E0_ResetSkillIcons()
{
    memset(&gtHotkeySlots, 0, 0x3C5);
    for (int i = 0; i < 60; ++i)
    {
        gtHotkeySlots.anValues[i] = -1;
    }

    if (gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
    if (!gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 0, 0);
    }
    if (gbSkillSelectRight)
    {
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
    }
    if (!gbSkillSelectRight)
    {
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 1, 0);
    }
}

void __fastcall sub_K05_EmitMouseInRect(int nX, int nY)
{
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX, 0x30, nY, 0x30));
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX + 0x30, 0x30, nY, 0x30));
}
