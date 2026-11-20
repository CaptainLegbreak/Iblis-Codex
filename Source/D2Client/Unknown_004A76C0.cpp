#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"

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

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXPos;
    unsigned short nYPos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

#pragma pack(push, 2)
struct D2BeltSlotStrc
{
    int nX;
    int nY;
    int bActive;
    unsigned short wCode;
};

#pragma pack(pop)

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern int gnGlobal_007C02F4; // 0x007C02F4
extern D2BeltSlotStrc gtSlots_00724A48[4]; // 0x00724A48
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
int __cdecl sub_00468830(); // 0x00468830
void __cdecl sub_00453EC0(); // 0x00453EC0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x00467F20
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
void __cdecl sub_0044DA70(); // 0x0044DA70

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
extern D2TextEntryStrc gaTextEntries_00724824[15]; // 0x00724824


struct D2MonStatsTxt
{
    char unk0x00[0x06];
    unsigned short nNameStr;
    char unk0x08[0x1A0];
};

struct D2CharStatsTxt
{
    Unicode wszClassName[16];
    char unk0x20[0xA4];
};




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

enum D2C_StatIds
{
    STAT_STATPTS = 4,
    STAT_HITPOINTS = 6,
    STAT_MAXHP = 7,
    STAT_MANA = 8,
    STAT_MAXMANA = 9,
    STAT_STAMINA = 10,
    STAT_MAXSTAMINA = 11,
    STAT_LEVEL = 12,
    STAT_EXPERIENCE = 13,
    STAT_NEXTEXP = 30,
    STAT_ARMORCLASS = 31,
    STAT_MAGICRESIST = 37,
    STAT_MAXMAGICRESIST = 38,
    STAT_FIRERESIST = 39,
    STAT_MAXFIRERESIST = 40,
    STAT_LIGHTRESIST = 41,
    STAT_MAXLIGHTRESIST = 42,
    STAT_COLDRESIST = 43,
    STAT_MAXCOLDRESIST = 44,
    STAT_POISONRESIST = 45,
    STAT_MAXPOISONRESIST = 46,
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" const char gszFormatLd_006D9BE8[]; // 0x006D9BE8
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
extern unsigned char gnTextColor_007C02F8; // 0x007C02F8
extern void* gpCel_007BEF64; // 0x007BEF64
extern void* gpCel_007BEF20; // 0x007BEF20
extern void* gpGlobal_007C02E0; // 0x007C02E0
extern void* gpGlobal_007C02DC; // 0x007C02DC
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2CharTextStrc gaCharTexts_00724818[15]; // 0x00724818
extern D2CharFieldStrc gaCharFields_00724928[18]; // 0x00724928
extern D2HoverBoxStrc gaHoverBoxes_006DA430[2]; // 0x006DA430
int __cdecl sub_0044DCC0(); // 0x0044DCC0
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit); // 0x00451F60
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
void* __cdecl sub_00454600_GetBuySellButtonCells(); // 0x00454600
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __cdecl sub_00466DC0(); // 0x00466DC0
int __cdecl sub_00466DD0(); // 0x00466DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
char* __fastcall sub_0047A210_GetUnitName(D2UnitStrc* pUnit); // 0x0047A210
void __cdecl sub_00499E30_SetBlackColour(); // 0x00499E30
int __stdcall sub_004A7340_GetPercentA(int nAttackRating); // 0x004A7340
int __cdecl sub_004A74A0_GetPercentB(); // 0x004A74A0
void __fastcall sub_004EDA20_RefreshSkills(D2UnitStrc* pUnit); // 0x004EDA20
int __fastcall sub_004EDA80_CallSkillDescFunc(D2UnitStrc* pUnit, int bLeft); // 0x004EDA80
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __stdcall sub_00525350_FormatUInt(Unicode* pOut, unsigned int nValue, int nSize); // 0x00525350
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
static void sub_004A7180_DrawHoverLevelText(int nX, int nY, int nValue); // 0x004A7180
static void __stdcall sub_004A7AE0_DrawHoverToHit(int nX, int nY, int nLeftChance, int nRightChance); // 0x004A7AE0

struct D2SkillsTxt
{
    short nSkillId;
    unsigned short unk0x02;
    unsigned char nFlags[8];
    char unk0x0C[0x188];
    short wSkillDesc;
    char unk0x196[0xA6];
};


#pragma pack(push, 2)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};

#pragma pack(pop)

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2UiCelFileStrc gaSkillIconCels_00724AC0[7]; // 0x00724AC0
extern int gnGlobal_00724BEC; // 0x00724BEC
extern D2UiCelFileStrc gaPanelCels_00724BF0[7]; // 0x00724BF0
extern int gnHotkeySkill_007C06C8[16]; // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16]; // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16]; // 0x007C07B8
extern "C" int gnValue_007C0C3C; // 0x007C0C3C
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
void __stdcall sub_004A9D70_ClearSkillHotkeys(D2SkillsTxt* pSkillsTxt, int nQuantity); // 0x004A9D70
void __fastcall sub_004AA3A0_BuildSkillRows(D2UnitStrc* pUnit, int nX, int nArg3, int nArg4, int nArg5); // 0x004AA3A0
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage); // 0x004AAAE0
void __cdecl sub_004AACE0_DrawSkillTreeTexts(); // 0x004AACE0
void __stdcall sub_004AB310_DrawTabHoverText(int nValue); // 0x004AB310
void __cdecl sub_004AB530_DrawTabCel(); // 0x004AB530
void __cdecl sub_004AB630_DrawTabHint(); // 0x004AB630
void __cdecl sub_004AC200_RefreshSkillTree(); // 0x004AC200
void __cdecl sub_004AC4D0_DrawSkillTree(); // 0x004AC4D0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040
void __stdcall sub_K05_EmitUse(int nValue);

// 0x004A76C0
static int sub_004A76C0_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !sub_00498DC0_MouseMoveMsg(pMsg) && pMsg->nXPos <= gnGlobal_0071146C / 2 && pMsg->nYPos < gnGlobal_00711470 - 0x2F)
    {
        if (sub_00468830() == 6)
            sub_00453EC0();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

void __stdcall sub_004A7720_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXPos;
    const int nY = pMsg->nYPos;
    if (nX >= gnGlobal_007A2858 + 0x80 && nX <= gnGlobal_007A2858 + 0xA0 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x5C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        gnGlobal_007C02F4 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (nX >= gnGlobal_007A2858 && nX <= gnGlobal_0071146C / 2 - 1 && nY >= gnGlobal_007A285C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x31)
    {
        if (STATLIST_GetUnitBaseStat(sub_00463DD0_GetPlayerUnit(), 4, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                const int nSlotY = gtSlots_00724A48[i].nY + gnGlobal_007A285C + gnGlobal_00711470;
                if (nY > nSlotY - 0x1F6 && nY < nSlotY - 0x1E0 && nX > gtSlots_00724A48[i].nX + gnGlobal_007A2858 && nX < gtSlots_00724A48[i].nX + gnGlobal_007A2858 + 0x28)
                {
                    gtSlots_00724A48[i].bActive = 1;
                    sub_00467F20_MsgHandler(pMsg);
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
    const int nX = pMsg->nXPos;
    const int nY = pMsg->nYPos;
    sub_00467FA0_MsgHandler(pMsg);
    gnGlobal_007C02F4 = 0;
    if (nX >= gnGlobal_007A2858 + 0x80 && nX <= gnGlobal_007A2858 + 0xA0 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x5C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        sub_00455F20(2, 1, 0);
        return;
    }
    if (nX >= gnGlobal_007A2858 && nX <= gnGlobal_0071146C / 2 - 1 && nY >= gnGlobal_007A285C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x31)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, 4, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                const int nSlotY = gtSlots_00724A48[i].nY + gnGlobal_007A285C + gnGlobal_00711470;
                gtSlots_00724A48[i].bActive = 0;
                if (nY > nSlotY - 0x1F6 && nY < nSlotY - 0x1E0 && nX > gtSlots_00724A48[i].nX + gnGlobal_007A2858 && nX < gtSlots_00724A48[i].nX + gnGlobal_007A2858 + 0x28)
                {
                    int nCount = STATLIST_UnitGetStatValue(pPlayer, 4, 0);
                    if (GetKeyState(0x10) < 0)
                        nCount = 1;
                    else if (!nCount)
                        break;
                    do
                    {
                        const int nStack = nCount < 0x20 ? nCount : 0x20;
                        nCount -= nStack;
                        sub_004785B0_SendPacket3(0x3A, ((unsigned char)(nStack - 1) << 8) | gtSlots_00724A48[i].wCode);
                    }
                    while (nCount);
                    break;
                }
            }
        }
        sub_0044DA70();
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
    for (unsigned int i = 0; i < sizeof(gaTextEntries_00724824) / sizeof(gaTextEntries_00724824[0]); ++i)
    {
        gaTextEntries_00724824[i].nLength = sub_00526800(D2LANG_GetStringFromTblIndex(gaTextEntries_00724824[i].wStringId));
    }
}

#include "gen/data/Source/D2Client/Unknown_004A76C0.inc"
struct D2SkillStrc;
struct D2UnitStrc;

int gnGlobal_007C02F4; // 0x007C02F4

static __forceinline D2MonStatsTxt* sub_MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2CharStatsTxt* sub_CharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x004A7080
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor)
{
    int nSpan = nRight - nLeft + 1;
    int nWidth = sub_00501820(wszText);
    if (nWidth < nSpan)
    {
        nLeft += (nSpan - nWidth) >> 1;
    }

    sub_00502320(wszText, nLeft, nY, nColor, 0);
}

static int sub_004A70C0_GetWieldedTypeStatMax(D2UnitStrc* pUnit)
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
    const int nCount = STATLIST_CopyStats(pUnit, 0x15C, aStats, 0x20);
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

static void sub_004A7180_DrawHoverLevelText(int nX, int nY, int nValue)
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

    if (nX < gnGlobal_007A2858 + 0xAD || nX > gnGlobal_007A2858 + 0x137
        || nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x11E || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x10B)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    int nLevel = UNITS_GetBlockRate(pPlayer, sub_0044DCC0());
    if (nLevel <= 0)
    {
        nLevel = sub_004A70C0_GetWieldedTypeStatMax(pPlayer);
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

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(sub_00466DD0());
    D2_ASSERT(pMonStatsTxtRecord, 0x15C);

    Unicode* wszText = (Unicode*)anText;
    if (nLevel)
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2779), nLevel, nValue, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->nNameStr), nValue);
    }
    else
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2778), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->nNameStr), nValue);
    }

    D2Win_10132(wszText, gnGlobal_007A2858 + 0x8B, gnGlobal_00711470 + gnGlobal_007A285C - 0x13B, gnTextColor_007C02F8, 2, 0);
}

static void __stdcall sub_004A7AE0_DrawHoverToHit(int nX, int nY, int nLeftChance, int nRightChance)
{
    int anText[0x40];
    for (int k = 0; k < 0x40; ++k)
    {
        anText[k] = 0;
    }

    sub_00499E30_SetBlackColour();

    int bLeft = 0;
    int bRight = 0;
    if (nX >= gnGlobal_007A2858 + 0xA2 && nX <= gnGlobal_007A2858 + 0x140
        && nY >= gnGlobal_007A285C + gnGlobal_00711470 - 0x14E && nY <= gnGlobal_007A285C + gnGlobal_00711470 - 0x13B)
    {
        bLeft = 1;
    }
    else if (nX >= gnGlobal_007A2858 + 0xA2 && nX <= gnGlobal_007A2858 + 0x140
        && nY >= gnGlobal_007A285C + gnGlobal_00711470 - 0x134 && nY <= gnGlobal_007A285C + gnGlobal_00711470 - 0x121)
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

    sub_0046EFD0_DrawFramedBox(gaHoverBoxes_006DA430[nIndex].nBoxX + gnGlobal_007A2858, gaHoverBoxes_006DA430[nIndex].nBoxY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, 0x9B, 0x1E, gnTextColor_007C02F8, 2);
    sub_00502320(D2LANG_GetStringFromTblIndex(0x103F), gaHoverBoxes_006DA430[nIndex].nTitleX + gnGlobal_007A2858, gaHoverBoxes_006DA430[nIndex].nTitleY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, 0, 0);

    D2MonStatsTxt* pMonStatsTxtRecord = sub_MonStatsTxtRecord(sub_00466DC0());
    D2_ASSERT(pMonStatsTxtRecord, 0xEC);

    Unicode* wszText = (Unicode*)anText;
    sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2777), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->nNameStr), nChance);
    sub_00502320(wszText, gaHoverBoxes_006DA430[nIndex].nTextX + gnGlobal_007A2858, gaHoverBoxes_006DA430[nIndex].nTextY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, 0, 0);
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
    tCel.pCellFile = gpCel_007BEF64;
    tCel.nDirection = 0;
    tCel.nFrame = 0;
    TEXTURE_CelDraw(&tCel, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tCel.nFrame = 1;
    TEXTURE_CelDraw(&tCel, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tCel.nFrame = 2;
    TEXTURE_CelDraw(&tCel, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
    tCel.nFrame = 3;
    TEXTURE_CelDraw(&tCel, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= gnGlobal_007A2858 + 0x80 && nMouseX <= gnGlobal_007A2858 + 0xA0
        && nMouseY >= gnGlobal_007A285C + gnGlobal_00711470 - 0x5C && nMouseY <= gnGlobal_007A285C + gnGlobal_00711470 - 0x3C)
    {
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_007A2858 + 0x8F, gnGlobal_007A285C + gnGlobal_00711470 - 0x5F, 0, 1);
    }

    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
    {
        tCel.pCellFile = gpCel_007BEF20;
        tCel.nFrame = 0;
        TEXTURE_CelDraw(&tCel, gnGlobal_007A2858 + 3, gnGlobal_00711470 + gnGlobal_007A285C - 0x74, -1, 5, 0);

        D2PointsTextStrc wszPoints;
        sub_00502EF0(6);
        sub_004A7080(gnGlobal_007A2858 + 0xB, gnGlobal_00711470 + gnGlobal_007A285C - 0x7D, gnGlobal_007A2858 + 0x58, D2LANG_GetStringFromTblIndex(0xFEB), 1);
        sub_004A7080(gnGlobal_007A2858 + 0xB, gnGlobal_007A285C + gnGlobal_00711470 - 0x75, gnGlobal_007A2858 + 0x58, D2LANG_GetStringFromTblIndex(0xFEC), 1);

        int anPoints[3];
        wsprintfA((char*)anPoints, "%i", STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0));
        sub_00502EF0(1);
        win2Unicode(&wszPoints.w0, (const char*)anPoints, 9);
        sub_004A7080(gnGlobal_007A2858 + 0x5C, gnGlobal_00711470 + gnGlobal_007A285C - 0x78, gnGlobal_007A2858 + 0x7F, &wszPoints.w0, 0);
    }

    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
    {
        for (int i = 0; i < 4; ++i)
        {
            tCel.pCellFile = gpGlobal_007C02E0;
            const int nX = gtSlots_00724A48[i].nX + gnGlobal_007A2858;
            const int nY = gtSlots_00724A48[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0;
            tCel.nFrame = 0;
            TEXTURE_CelDraw(&tCel, nX + 5, nY + 5, -1, 5, 0);
            tCel.pCellFile = gpGlobal_007C02DC;
            tCel.nFrame = gtSlots_00724A48[i].bActive != 0;
            TEXTURE_CelDraw(&tCel, nX + 8, nY + 1, -1, 5, 0);
        }
    }

    sub_00502EF0(6);
    for (unsigned int i = 0; i < sizeof(gaCharTexts_00724818) / sizeof(gaCharTexts_00724818[0]); ++i)
    {
        D2ZeroDwordStrc aLine[50];
        Unicode* wszLine = (Unicode*)aLine;
        strncpy(wszLine, D2LANG_GetStringFromTblIndex(gaCharTexts_00724818[i].wStringId), 99);
        const int nLeft = gaCharTexts_00724818[i].nX + gnGlobal_007A2858;
        const int nRight = gaCharTexts_00724818[i].nX2 + gnGlobal_007A2858;
        const int nY = gaCharTexts_00724818[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0;
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
                    sub_004A7080(nLeft, nY - 4, nRight, wszLine, 0);
                    sub_004A7080(nLeft, nY + 4, nRight, pSecond, 0);
                    goto NEXT_TEXT;
                }

                break;
            }

            ++pChar;
            ++nPos;
        }

        sub_004A7080(nLeft, nY, nRight, wszLine, 0);
NEXT_TEXT:;
    }

    sub_004EDA20_RefreshSkills(pPlayer);
    sub_00502EF0(0);
    const int nLeftChance = sub_004A7340_GetPercentA(sub_004EDA80_CallSkillDescFunc(pPlayer, 1));
    const int nRightChance = sub_004A7340_GetPercentA(sub_004EDA80_CallSkillDescFunc(pPlayer, 0));
    const int nPercent = sub_004A74A0_GetPercentB();
    sub_004A7AE0_DrawHoverToHit(nMouseX, nMouseY, nLeftChance, nRightChance);
    sub_004A7180_DrawHoverLevelText(nMouseX, nMouseY, nPercent);
    sub_00502EF0(1);

    tCel.pCellFile = sub_00454600_GetBuySellButtonCells();
    tCel.nFrame = (gnGlobal_007C02F4 != 0) + 10;
    TEXTURE_CelDraw(&tCel, gnGlobal_007A2858 + 0x80, gnGlobal_007A285C + gnGlobal_00711470 - 0x3C, -1, 5, 0);

    int anNumber[0x20];
    D2ZeroDwordStrc aText[0x40];
    Unicode* wszText = (Unicode*)aText;
    if (pPlayer && pPlayer->dwUnitType == 0)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_CharStatsTxtRecord(pPlayer->dwClassId);
        sub_004A7080(gnGlobal_007A2858 + 0xC1, gnGlobal_007A285C + gnGlobal_00711470 - 0x1C7, gnGlobal_007A2858 + 0x136, pCharStatsTxtRecord->wszClassName, 0);

        const char* szName = sub_0047A210_GetUnitName(pPlayer);
        const unsigned int nChars = sub_005262A0_Utf8CountChars(szName, strlen(szName)) + 1;
        if (nChars > 11)
        {
            if (nChars >= 14)
            {
                sub_00502EF0(6);
            }
            else
            {
                sub_00502EF0(0);
            }
        }

        win2Unicode(wszText, szName, 0x80);
        sub_004A7080(gnGlobal_007A2858 + 0xD, gnGlobal_00711470 + gnGlobal_007A285C - 0x1C7, gnGlobal_007A2858 + 0xA0, wszText, 0);
        sub_00502EF0(1);
    }

    int nFont;
    for (unsigned int i = 0; i < sizeof(gaCharFields_00724928) / sizeof(gaCharFields_00724928[0]); ++i)
    {
        int bCheckWidth = 0;
        int nValue = STATLIST_UnitGetStatValue(pPlayer, gaCharFields_00724928[i].nStatId, 0);
        const int nBase = STATLIST_GetUnitBaseStat(pPlayer, gaCharFields_00724928[i].nStatId, 0);
        switch (gaCharFields_00724928[i].nStatId)
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
            if (pUnit && pUnit->dwUnitType == 0 && pUnit->dwAnimMode != 0x11 && (unsigned int)nValue <= 1)
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
            D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(sub_0044DCD0_GetDifficulty());
            int nMax = 0;
            switch (gaCharFields_00724928[i].nStatId)
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

            if (sub_0044DCC0())
            {
                nValue += pDifficultyLevelsTxtRecord->dwResistPenalty;
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

            if (pPlayer->pInventory && INVENTORY_GetEquippedShield(pPlayer->pInventory, 0) && STATES_CheckState(pPlayer, 0x65))
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
            const int nClass = sub_00451F60_UnitClassId(pPlayer);
            if (nLevel != DATATBLS_GetMaxLevel(nClass))
            {
                nValue = DATATBLS_GetLevelThreshold(nClass, nLevel);
            }

            sub_00525350_FormatUInt(wszText, nValue, 0x80);
            sub_004A7080(gaCharFields_00724928[i].nX + gnGlobal_007A2858, gaCharFields_00724928[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, gaCharFields_00724928[i].nX2 + gnGlobal_007A2858, wszText, 0);
            nColor = 0;
            continue;
        }
        case STAT_EXPERIENCE:
            sub_00525350_FormatUInt(wszText, nValue, 0x80);
            sub_004A7080(gaCharFields_00724928[i].nX + gnGlobal_007A2858, gaCharFields_00724928[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, gaCharFields_00724928[i].nX2 + gnGlobal_007A2858, wszText, 0);
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
                nNewFont = sub_00502EF0(0);
            }
            else
            {
                D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
                if (nWidth < gaCharFields_00724928[i].nX2 - gaCharFields_00724928[i].nX)
                {
                    goto DRAW_FIELD;
                }

                nNewFont = sub_00502EF0(0);
            }

            nFont = nNewFont;
        }
        else
        {
            nFont = 0xE;
        }

DRAW_FIELD:
        sub_004A7080(gaCharFields_00724928[i].nX + gnGlobal_007A2858, gaCharFields_00724928[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, gaCharFields_00724928[i].nX2 + gnGlobal_007A2858, wszText, nColor);
        nColor = 0;
        if (nFont != 0xE)
        {
            sub_00502EF0(nFont);
        }
    }
}

unsigned char gbGlobal_007A0522; // 0x007A0522

D2SkillIconStateStrc gtSkillIconState_007C0300; // 0x007C0300

int ganIconValues_007C0728[16]; // 0x007C0728

unsigned short gawIconValues_007C07A8[8]; // 0x007C07A8

void* gpSkillIconCel_007C07F8; // 0x007C07F8

int gbGlobal_007C07FC; // 0x007C07FC

int gnGlobal_007C0C40; // 0x007C0C40

int gnGlobal_007C0C44; // 0x007C0C44

int gnGlobal_007C0C4C; // 0x007C0C4C

unsigned char gbColor_007C0C50; // 0x007C0C50

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

// 0x004A8A30
void __cdecl sub_004A8A30_InitSkillIcons()
{
    gpSkillIconCel_007C07F8 = sub_004520C0_LoadUiCelFile("Spells\\Skillicon");
    gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels_00724AC0[gbGlobal_007A0522].szPath);

    int i;
    for (i = 0; i < 16; ++i)
    {
        ganIconValues_007C0728[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gnHotkeyOwner_007C0768[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gbHotkeyLeft_007C07B8[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gnHotkeySkill_007C06C8[i] = -1;
    }

    memset(&gtSkillIconState_007C0300, 0, 0x3C5);
    for (i = 0; i < 60; ++i)
    {
        gtSkillIconState_007C0300.anValues[i] = -1;
    }
    for (i = 0; i < 8; ++i)
    {
        gawIconValues_007C07A8[i] = 0;
    }
}

// 0x004A8C00
void __cdecl sub_004A8C00_FreeSkillIcons()
{
    if (gpSkillIconCel_007C07F8)
    {
        sub_00478A00(gpSkillIconCel_007C07F8);
        gpSkillIconCel_007C07F8 = 0;
    }

    if (gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile)
    {
        sub_00478A00(gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile);
        gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile = 0;
    }

    for (int i = 0; i < 7; ++i)
    {
        if (gaSkillIconCels_00724AC0[i].pCelFile)
        {
            sub_00478A00(gaSkillIconCels_00724AC0[i].pCelFile);
            gaSkillIconCels_00724AC0[i].pCelFile = 0;
        }
    }
}

// 0x004A8C80
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt)
{
    if (!pSkillsTxt)
    {
        return gaSkillIconCels_00724AC0[gbGlobal_007A0522].pCelFile;
    }

    int nClass = pSkillsTxt->nSkillId;
    nClass = SKILLS_GetClassIdFromSkillId(nClass);
    if (nClass >= 0 && nClass <= 6)
    {
        if (!gaSkillIconCels_00724AC0[nClass].pCelFile)
        {
            gaSkillIconCels_00724AC0[nClass].pCelFile = sub_004520C0_LoadUiCelFile(gaSkillIconCels_00724AC0[nClass].szPath);
        }
        return gaSkillIconCels_00724AC0[nClass].pCelFile;
    }

    return gpSkillIconCel_007C07F8;
}

// 0x004A8CE0
void __fastcall sub_004A8CE0_SetValue(int nValue)
{
    gbGlobal_007C07FC = nValue;
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
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
        D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
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
    memset(&gtSkillIconState_007C0300, 0, 0x3C5);
    for (int i = 0; i < 60; ++i)
    {
        gtSkillIconState_007C0300.anValues[i] = -1;
    }

    if (gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
    if (!gbGlobal_007C07FC)
    {
        gtSkillIconState_007C0300.bFlag = 0;
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnGlobal_0071146C - 0x80, 0, 0, 0);
    }
    if (gbGlobal_007C07FC)
    {
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
    }
    if (!gbGlobal_007C07FC)
    {
        sub_004AA3A0_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnGlobal_0071146C - 0x80, 0, 1, 0);
    }
}

// 0x004AA900
int __cdecl sub_004AA900_IsStateOrValue()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer && STATES_CheckState(pPlayer, 0x36))
    {
        return 1;
    }
    return gnValue_007C0C3C;
}

// 0x004AA920
void __cdecl sub_004AA920_LoadPanelCel()
{
    char* szPath = gaPanelCels_00724BF0[gbGlobal_007A0522].szPath;
    D2_ASSERT(szPath, 136);
    gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile = sub_004520C0_LoadUiCelFile(szPath);
}

// 0x004AB2F0
void __cdecl sub_004AB2F0_SetBlackColor()
{
    gbColor_007C0C50 = D2Win_10034_MixRGB(0, 0, 0);
}

// 0x004AC690
void __cdecl sub_004AC690_DrawSkillPanel()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    sub_00502EF0(1);
    gnGlobal_007C0C4C = 1;
    sub_004AAAE0_DrawPagedPanel(gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile, gnGlobal_00724BEC);
    sub_004AACE0_DrawSkillTreeTexts();
    if (STATLIST_GetUnitBaseStat(pPlayer, 5, 0) > 0)
    {
        gnGlobal_007C0C40 = 1;
        gnGlobal_007C0C44 = 1;
        sub_004AC200_RefreshSkillTree();
    }
    else
    {
        gnGlobal_007C0C40 = 0;
        gnGlobal_007C0C44 = 0;
        sub_004AC4D0_DrawSkillTree();
    }
    sub_004AB530_DrawTabCel();
    sub_004AB630_DrawTabHint();
    sub_004AB310_DrawTabHoverText(gnGlobal_00724BEC);
}

// 0x004A8CF0
static __declspec(noinline) int __stdcall sub_004A8CF0_IsMouseInRect(int nX, int nWidth, int nY, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

void __fastcall sub_K05_EmitMouseInRect(int nX, int nY)
{
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX, 0x30, nY, 0x30));
    sub_K05_EmitUse(sub_004A8CF0_IsMouseInRect(nX + 0x30, 0x30, nY, 0x30));
}
