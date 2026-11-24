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
#include "D2ClientUiRecords.h"
#include "D2ClientStatButton.h"

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
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
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0
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
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
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
int __cdecl SELECT_GetHoverMonClassId(); // 0x00466DC0
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



extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2UiCelFileStrc gaSkillIconCels[7]; // 0x00724AC0
extern int gnSkillPage; // 0x00724BEC
extern D2UiCelFileStrc gaPanelCels[7]; // 0x00724BF0
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8
extern "C" int gbSkillPointsHighlight; // 0x007C0C3C
void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0
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

    D2MonStatsTxt* pMonStatsTxtRecord = sub_MonStatsTxtRecord(SELECT_GetHoverMonClassId());
    D2_ASSERT(pMonStatsTxtRecord, 0xEC);

    Unicode* wszText = (Unicode*)anText;
    sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2777), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nChance);
    D2Win_10117_DrawText(wszText, gaHoverBoxes[nIndex].nTextX + gnPanelOffsetX, gaHoverBoxes[nIndex].nTextY + gnPanelOffsetY + gnScreenHeight - 0x1E0, 0, 0);
}


unsigned char gnCharClass; // 0x007A0522

D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300

int ganIconValues[16]; // 0x007C0728

unsigned short gawIconValues[8]; // 0x007C07A8

void* gpSkillIconCel; // 0x007C07F8

int gbSkillSelectRight; // 0x007C07FC





static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
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
    gpSkillIconCel = GAME_LoadUiCelFile("Spells\\Skillicon");
    gaSkillIconCels[gnCharClass].pCelFile = GAME_LoadUiCelFile(gaSkillIconCels[gnCharClass].szPath);

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











void __fastcall sub_K05_EmitMouseInRect(int nX, int nY)
{
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX, 0x30, nY, 0x30));
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX + 0x30, 0x30, nY, 0x30));
}
