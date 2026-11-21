#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2Path.h"
#include "D2ClientTypes.h"
#include "D2Win32Types.h"
#include "D2GameObjs.h"
#include "D2LevelTxt.h"
#include "D2CelContext.h"
#include "D2ItemsWorld.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct UnicodeChar;

struct UnicodeChar
{
    unsigned short wChar;

    UnicodeChar();                                                                                          // 0x0042F530
    UnicodeChar(unsigned short ch) : wChar(ch)
    {
    }
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char gszFmtInt_006D6454[]; // 0x006D6454

extern "C" const char gszUiCpp_006D6458[]; // 0x006D6458

Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0

const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60

void __fastcall sub_0048C060_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC

int __cdecl sub_0047A980_IsNumberDisplayEnabled(); // 0x0047A980

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __fastcall sub_00479B80_GetRecordValue(D2StoredUnitRecordStrc* pRecord); // 0x00479B80

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    unsigned int nWidth;
    unsigned int nHeight;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

extern "C" unsigned int __cdecl strlen(const char* szString);

int __cdecl sub_0045AE90();                                                                         // 0x0045AE90

extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0

extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0

const Unicode* __fastcall sub_00453E70_GetLevelName(int nLevelId); // 0x00453E70

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

void __fastcall sub_00454AD0_DrawUnitHoverName(D2UnitStrc* pUnit);                                          // 0x00454AD0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070

void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY);                           // 0x004760C0

D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20

int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150

const char* __fastcall sub_0047A290_GetOwnerName(int nUnitId);                                              // 0x0047A290

int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230

int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0

int __cdecl sub_004A0000();                                                                                 // 0x004A0000

void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5, int nArg6); // 0x005022F0

const Unicode* __fastcall D2LANG_GetStringByReferenceString(const char* szKey);                                       // 0x00524E20

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords);                       // 0x00620900

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);        // 0x0063E810

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640

extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0

extern unsigned short gwszText_007A2A78[];                                                                  // 0x007A2A78

extern Unicode gxGlobal_007A2C80[80];                                                                       // 0x007A2C80

extern int gdwGlobal_007A2D20;                                                                              // 0x007A2D20

extern int gdwGlobal_007A2D24;                                                                              // 0x007A2D24

extern int gdwGlobal_007A2D28;                                                                              // 0x007A2D28

extern unsigned short gwszText_007A2D30[];                                                                  // 0x007A2D30

extern Unicode gwszHoverName_007A2F38[];                                                                    // 0x007A2F38

int __cdecl sub_004F59A0();                                                                                // 0x004F59A0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6024[];                                                    // 0x006D6024

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6084[];                                                    // 0x006D6084

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D60C0[];                                                    // 0x006D60C0

int gnPanelState_007A27E8;                                                                                  // 0x007A27E8

struct D2CelFileStrc;

struct D2MsgHandlerEntryStrc;

struct D2Block0xA0Strc;

struct D2Block0xA0Strc
{
    unsigned short wData[0x50];
};

void __cdecl sub_00453AE0(); // 0x00453AE0

void __cdecl sub_00453EE0_ClosePanel(); // 0x00453EE0

void __fastcall sub_0045AEA0_SetPanelSlide(int nMode); // 0x0045AEA0

void __cdecl sub_00466FE0(); // 0x00466FE0

void __cdecl sub_0047B2E0_CloseChatInput(); // 0x0047B2E0

void __cdecl sub_0047B4E0(); // 0x0047B4E0

void __cdecl sub_00487990_ResetHover(); // 0x00487990

void __cdecl sub_00489EE0(); // 0x00489EE0

void __cdecl sub_0048A500(); // 0x0048A500

void __cdecl sub_00494FC0(); // 0x00494FC0

void __cdecl sub_0049A020_FreeRosterUnits(); // 0x0049A020

void __cdecl sub_0049CF50_SendWaypointClose(); // 0x0049CF50

void __cdecl sub_0049FF00(); // 0x0049FF00

void __cdecl sub_004A01A0_CloseListBoxDialog(); // 0x004A01A0

void __cdecl sub_004A28D0_ResetButton(); // 0x004A28D0

extern "C" void __cdecl sub_004A3000_ResetFlag(); // 0x004A3000

void __fastcall sub_004A5200(int nArg); // 0x004A5200

void __cdecl sub_004ABF10_ClearSkillStates(); // 0x004ABF10

void __cdecl sub_004B3F10_CloseByState(); // 0x004B3F10

void __fastcall sub_004B8940_CloseWait(int bReopen); // 0x004B8940

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[]; // 0x006D5F28

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F58[]; // 0x006D5F58

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FAC[]; // 0x006D5FAC

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FC4[]; // 0x006D5FC4

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FD0[]; // 0x006D5FD0

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FE8[]; // 0x006D5FE8

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6000[]; // 0x006D6000

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D600C[]; // 0x006D600C

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6030[]; // 0x006D6030

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D615C[]; // 0x006D615C

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D61B0[]; // 0x006D61B0

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D61C8[]; // 0x006D61C8

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6204[]; // 0x006D6204

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D621C[]; // 0x006D621C

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D62C4[]; // 0x006D62C4

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6300[]; // 0x006D6300

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6318[]; // 0x006D6318

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D633C[]; // 0x006D633C

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6360[]; // 0x006D6360

extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F878[]; // 0x0070F878

extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F8D8[]; // 0x0070F8D8

extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F930[]; // 0x0070F930

extern D2MsgHandlerEntryStrc gtPanelHandlers_0070F9D0[]; // 0x0070F9D0

extern D2MsgHandlerEntryStrc gtPanelHandlers_0070FA30[]; // 0x0070FA30

extern D2MsgHandlerEntryStrc gtPanelHandlers_0070FA84[]; // 0x0070FA84

extern int gnPanelFlag_007A2864; // 0x007A2864

int __cdecl sub_0044DB30(); // 0x0044DB30

void __cdecl sub_0044CD70_TickTimer(); // 0x0044CD70

void __cdecl sub_00456550_LoadLoadingScreen(); // 0x00456550

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __cdecl sub_00478150(); // 0x00478150

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __cdecl sub_0044DA40(); // 0x0044DA40

void __cdecl sub_0044DA70(); // 0x0044DA70

struct D2UIVarRecordStrc
{
    char unk0x00[0x54];
    int nCloseKind;
    unsigned char unk_58[0x2C];
    int nDrawCloseKind;
};

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __cdecl sub_0044DCC0(); // 0x0044DCC0

void __fastcall sub_004B3C20(int nValue); // 0x004B3C20

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10

void __fastcall sub_00454F30_DrawUnitHover(D2UnitStrc* pUnit); // 0x00454F30

int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __fastcall sub_004B8100(void* pObj); // 0x004B8100

void __fastcall sub_004A0E70_UpdateTexts(D2ViewStrc* pView); // 0x004A0E70

void __fastcall sub_00453330_DrawPartyMemberText(D2UnitStrc* pUnit); // 0x00453330

void __fastcall sub_00464950(void (__fastcall* pfnCallback)(D2UnitStrc*)); // 0x00464950

void __cdecl sub_0047E3D0_DrawOptions(); // 0x0047E3D0

void __cdecl sub_004A5270(); // 0x004A5270

void __cdecl sub_00452D20_DrawPetHover(); // 0x00452D20

void __cdecl sub_00497FE0_DrawDurabilityIcons(); // 0x00497FE0

void __cdecl sub_00497E00(); // 0x00497E00

void __cdecl sub_0045AD60(); // 0x0045AD60

void __cdecl sub_00455510_DrawLevelLoadingScreen(); // 0x00455510

void __cdecl sub_00493340_UpdateHirelingPanel(); // 0x00493340

void __cdecl sub_00494020_DrawPetIcons(); // 0x00494020

void __cdecl sub_004929F0_DrawMercPanel(); // 0x004929F0

void __stdcall sub_0048BC10(); // 0x0048BC10

void __cdecl sub_004A34F0_DrawQuestPage(); // 0x004A34F0

void __cdecl sub_0048EDF0_DrawInventoryPanel(); // 0x0048EDF0

void __cdecl sub_004B8730_DrawDialogHover(); // 0x004B8730

void __cdecl sub_00453470_DrawProgressiveStates(); // 0x00453470

void __cdecl sub_004AC690_DrawSkillPanel(); // 0x004AC690

void __cdecl sub_004A7D00_DrawCharStats(); // 0x004A7D00

void __cdecl sub_0049C3D0_DrawPartyPanel(); // 0x0049C3D0

void __cdecl sub_0049FF10_DispatchTextData(); // 0x0049FF10

void __cdecl sub_0049C9C0_DrawWaypointPanel(); // 0x0049C9C0

void __cdecl sub_00494320_LoadHelpCels(); // 0x00494320

void __cdecl sub_00494EB0(); // 0x00494EB0

void __cdecl sub_00499450_DrawControlPanel(); // 0x00499450

void __cdecl sub_004AA7E0_ResetSkillIcons(); // 0x004AA7E0

void __cdecl sub_00498E90_SetRecordMode(); // 0x00498E90

void __cdecl sub_004A64C0_UpdateStatButtons(); // 0x004A64C0

void __cdecl sub_00495180_DrawButtons(); // 0x00495180

void __cdecl sub_004A6B30_DrawLeftPanelButtons(); // 0x004A6B30

void __cdecl sub_004A6A70_DrawLeftPanelButton(); // 0x004A6A70

void __cdecl sub_004A6E60_DrawRightPanelButtons(); // 0x004A6E60

void __cdecl sub_004A6DA0_DrawRightPanelButton(); // 0x004A6DA0

void __cdecl sub_004A2A80_DrawButton(); // 0x004A2A80

void __cdecl sub_00498120(); // 0x00498120

void __cdecl sub_0047F710_UpdateSlotBar(); // 0x0047F710

void __cdecl sub_0047B720_DrawChatPanel(); // 0x0047B720

void __cdecl sub_004966C0_DrawHelpScreen(); // 0x004966C0

void __cdecl sub_004C0810_DrawUnitNames(); // 0x004C0810

void __cdecl sub_004B4380_UpdateNpcInteract(); // 0x004B4380

void __cdecl sub_004C01E0_DrawPanelUnit(); // 0x004C01E0

void __cdecl sub_00496B10(); // 0x00496B10

void __stdcall D2Win_10124(); // 0x00503000

void __cdecl sub_00454A70_DrawHoverText(); // 0x00454A70

void __cdecl sub_00453060(); // 0x00453060

void __cdecl sub_004554B0_DrawHoverName(); // 0x004554B0

void __cdecl sub_00453B30_DrawStoredUnitNumber(); // 0x00453B30

void __cdecl sub_00453100_DrawDeathScreen(); // 0x00453100

void __cdecl sub_0046C130_DrawCountdown(); // 0x0046C130

D2CelFileStrc* gpLoadingScreen_007A2888; // 0x007A2888

int gnLoadingFrame_007A2A6C; // 0x007A2A6C

int gnValue_007A27B8; // 0x007A27B8

unsigned char gnLoadingBarColor_007A2A70; // 0x007A2A70

unsigned char gnLoadingBoxColor_007A2A71; // 0x007A2A71

int gbMiniPanel_007A2814; // 0x007A2814

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004527D0
void __fastcall sub_004527D0_BuildItemHoverName(D2UnitStrc* pUnit, Unicode* pOut, int nMaxLength)
{
    gnHoverY_0070F858 -= 0x10;
    if (!pUnit)
        return;

    const Unicode* pName = sub_00464A60_GetUnitName(pUnit);
    int nColor = 0;
    switch (ITEMS_GetItemQuality(pUnit))
    {
    case ITEMQUAL_RARE:
        nColor = 9;
        break;
    case ITEMQUAL_CRAFT:
        nColor = 8;
        break;
    case ITEMQUAL_TEMPERED:
        nColor = 10;
        break;
    case ITEMQUAL_MAGIC:
        nColor = 3;
        break;
    case ITEMQUAL_SET:
        nColor = 2;
        break;
    case ITEMQUAL_UNIQUE:
        nColor = 4;
        break;
    default:
        if (ITEMS_CheckItemFlag(pUnit, 0x800, 0x5AA, gszUiCpp_006D6458))
            nColor = 5;
        else if (ITEMS_CheckItemFlag(pUnit, 0x400000, 0x5AE, gszUiCpp_006D6458))
            nColor = 5;
        break;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    if (pItemsTxtRecord->nQuest && pItemsTxtRecord->dwCode != 0x2067656C)
        nColor = 4;

    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    if (dwCode == 0x20686563 || dwCode == 0x20746562 || dwCode == 0x20736574 || dwCode == 0x20646566
        || dwCode == 0x20616F74 || dwCode == 0x206E6864 || dwCode == 0x20796562 || dwCode == 0x2072626D
        || dwCode == 0x20316B70 || dwCode == 0x20326B70 || dwCode == 0x20336B70 || ITEMSIsA(pUnit, 0x4A))
        nColor = 8;

    Unicode wszText[0x80] = { 0 };
    if (ITEMS_GetItemType(pUnit) == 4)
    {
        char szGold[10];
        const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
        Unicode wszGold[10];
        wsprintfA(szGold, gszFmtInt_006D6454, nGold);
        sub_00526F20(wszGold, szGold, 9);
        sub_005267E0(wszText, wszGold);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, pName);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText(wszText, gnHoverX_0070F854, gnHoverY_0070F858, nColor, 1);
            return;
        }

        sub_004521C0_PrefixLevelText(wszText, nColor);
        D2_ASSERT(sub_00526800(wszText) < nMaxLength, 0x5E0);
        sub_005267E0(pOut, wszText);
        return;
    }
    else if (pUnit)
    {
        UnicodeChar wszItem[0x80] = { 0 };
        sub_0048C060_BuildItemName(pUnit, (Unicode*)wszItem, 0x100);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText((Unicode*)wszItem, gnHoverX_0070F854, gnHoverY_0070F858, nColor, 1);
            return;
        }

        sub_004521C0_PrefixLevelText((Unicode*)wszItem, nColor);
        D2_ASSERT(sub_00526800((Unicode*)wszItem) < nMaxLength, 0x5EB);
        sub_005267E0(pOut, (Unicode*)wszItem);
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00453B30
void __cdecl sub_00453B30_DrawStoredUnitNumber()
{
    if (!sub_0047A980_IsNumberDisplayEnabled())
    {
        return;
    }

    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    if (!pUnit)
    {
        return;
    }

    D2StoredUnitRecordStrc* pRecord = sub_00479BB0_FindRecord(pUnit->dwUnitId);
    if (!pRecord)
    {
        return;
    }

    const int nValue = sub_00479B80_GetRecordValue(pRecord);
    char szText[12];
    Unicode wszText[12];
    wsprintfA(szText, gszFormatD_006D57BC, nValue);
    sub_00526F20_ToUnicode(wszText, szText, 12);
    sub_00502320(wszText, 600, 25, 4, 0);
}

// 0x004545C0
void __fastcall sub_004545C0_TogglePanelHandlers(int bRegister)
{
    if (bRegister)
    {
        if (gnPanelState_007A27E8)
        {
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6084, 5);
        }
    }
    else
    {
        if (gnPanelState_007A27E8)
        {
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6084, 5);
        }
    }
}

// 0x00454980
void __cdecl sub_00454980()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D60C0, 13);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6024, 1);
}

// 0x004549C0
int __cdecl sub_004549C0_IsPanelAllocated()
{
    return gpGlobal_007A27A0 != 0;
}

// 0x004549D0
D2Block0xA0Strc* __fastcall sub_004549D0_ClearBlock(D2Block0xA0Strc* pBlock)
{
    for (int i = 0; i < 0x50; ++i)
        pBlock->wData[i] = 0;
    return pBlock;
}

static void __stdcall sub_00452AF0_GetPartyText(D2UnitStrc* pUnit, Unicode* pDst, int nMaxLength, int* pValue, int* pFlag)
{
    const char* szName = sub_0047A210_GetPartyName(pUnit);
    if (pUnit && pUnit->dwAnimMode == 0x11)
    {
        *pValue = 0;
        unsigned short wszName[0x80];
        for (int i = 0; i < 0x80; i++)
            wszName[i] = 0;
        sub_00526F20_ToUnicode((Unicode*)wszName, szName, 0x80);
        sub_005272B0_FormatText(pDst, (Unicode*)wszName, D2LANG_GetStringFromTblIndex(0x90B), nMaxLength, STRTABLE_GetLanguage());
        *pFlag = 1;
        return;
    }
    *pValue = sub_0047A6B0_GetLifeValue(!pUnit ? -1 : pUnit->dwUnitId) * 128 / 100;
    *pFlag = 0;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_0047A070_IsPartyRelation(!pPlayer ? -1 : pPlayer->dwUnitId, nUnitId))
    {
        *pFlag = 1;
    }
    sub_00526F20_ToUnicode(pDst, szName, 0x80);
}

static void __stdcall sub_00452BE0_ShowUnitHoverName(D2UnitStrc* pUnit, int bSet)
{
    int nValues[2];
    if (sub_004B3230_GetTickPair(&nValues[0]))
    {
        return;
    }
    nValues[1] = sub_004525F0_GetHoverTextY(pUnit);
    const int nY = gnHoverY_0070F858 - 0x48;
    const int nX = gnHoverX_0070F854;
    const Unicode* pName = sub_00464A60_GetUnitName(pUnit);
    if (bSet)
    {
        gxGlobal_007A2C80[0].wChar = 0;
        if (pName)
        {
            sub_005267E0(gxGlobal_007A2C80, pName);
            gdwGlobal_007A2D24 = nY;
            gdwGlobal_007A2D20 = nX;
            gdwGlobal_007A2D28 = nValues[1];
        }
    }
    else
    {
        D2Win_10130_DrawFramedTextEx(pName, nX, nY, 0, 1, nValues[1]);
    }
}

static int __stdcall sub_00452C70_GetRosterText(D2UnitStrc* pUnit, Unicode* pDst, int* pValue, int* pFlag)
{
    const int nIndex = sub_00479150_FindRosterIndex(!pUnit ? -1 : pUnit->dwUnitId);
    if (nIndex == -1)
    {
        return 0;
    }
    if (!pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 0x0C)
    {
        return 1;
    }
    const char* szName = sub_0047A1F0(nIndex);
    if (!szName)
    {
        return 0;
    }
    sub_00526320_ToUnicode(pDst, szName, 0x80);
    *pValue = sub_0047A6B0_GetLifeValue(nIndex) * 128 / 100;
    *pFlag = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_0047A070_IsPartyRelation(!pPlayer ? -1 : pPlayer->dwUnitId, nIndex))
    {
        *pFlag = 1;
    }
    return 1;
}

static __forceinline int SetHoverPositionFromUnit(D2UnitStrc* pUnit)
{
    if (sub_004F51D0_IsPerspective())
    {
        const int nPrecisionX = UNITS_GetPrecisionX(pUnit);
        const int nPrecisionY = UNITS_GetPrecisionY(pUnit);
        if (!sub_004F66E0_IsPrecisionOnScreen(nPrecisionX, nPrecisionY))
        {
            return 0;
        }
        int nX;
        int nY;
        sub_004F6760_PrecisionToScreen(nPrecisionX, nPrecisionY, 0, &nX, &nY);
        switch (sub_0045AE90())
        {
        case 1:
            nX -= gnGlobal_0071146C / 4;
            break;
        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
        gnHoverX_0070F854 = nX;
        gnHoverY_0070F858 = nY + 0x10;
    }
    else
    {
        gnHoverX_0070F854 = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0();
        gnHoverY_0070F858 = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset();
    }
    return 1;
}

void __cdecl sub_00452D20_DrawPetHover()
{
    if (sub_0045AE90() == 3)
    {
        return;
    }
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        return;
    }
    if (sub_00478E40_FindEntry(nPetId)->nValue != 1)
    {
        return;
    }
    D2UnitStrc* pPet = sub_00463990(nPetId, 1);
    if (!pPet)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pPet))
    {
        return;
    }
    sub_00452BE0_ShowUnitHoverName(pPet, 1);
}

void __fastcall sub_00453330_DrawPartyMemberText(D2UnitStrc* pUnit)
{
    const int nBorder = sub_0045AE90();
    if (nBorder == 3)
    {
        return;
    }
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        return;
    }
    D2RectStrc tView;
    sub_00476070_GetViewRect(gpView_007A0640, &tView.nLeft, &tView.nTop, &tView.nRight, &tView.nBottom);
    int nOffsetX;
    int nOffsetY;
    sub_004760C0_GetViewOffset(gpView_007A0640, &nOffsetX, &nOffsetY);
    tagRECT tRect;
    SetRect(&tRect, nOffsetX, nOffsetY, tView.nRight - tView.nLeft + nOffsetX, tView.nBottom - tView.nTop + nOffsetY);
    D2CoordStrc tCoords;
    UNITS_GetClientCoords(pUnit, &tCoords);
    tCoords.nY = tCoords.nY - tRect.top - 0x46;
    tCoords.nX -= tRect.left;
    switch (nBorder)
    {
    case 1:
        tCoords.nX -= gnGlobal_0071146C / 4;
        if (tCoords.nX > gnGlobal_0071146C / 2)
        {
            return;
        }
        break;
    case 2:
        tCoords.nX += gnGlobal_0071146C / 4;
        if (tCoords.nX < gnGlobal_0071146C / 2)
        {
            return;
        }
        break;
    }
    if (tCoords.nY <= 0 || tCoords.nY >= gnGlobal_0071146C || tCoords.nX <= -0x32 || tCoords.nX >= gnGlobal_00711470 + 0x32)
    {
        return;
    }
    Unicode wszName[0x80];
    int nPercent;
    int bFlag;
    sub_00452AF0_GetPartyText(pUnit, wszName, 0x80, &nPercent, &bFlag);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00454F30
void __fastcall sub_00454F30_DrawUnitHover(D2UnitStrc* pUnit)
{
    if (sub_0045AE90() == 3)
    {
        return;
    }
    if (!pUnit)
    {
        return;
    }
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 5 && sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0_GetPlayerUnit()) > 100)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pUnit))
    {
        return;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    {
        Unicode wszName[0x80];
        int nPercent;
        int bFlag;
        sub_00452AF0_GetPartyText(pUnit, wszName, 0x80, &nPercent, &bFlag);
        D2Win_10130_DrawFramedTextEx(wszName, gnHoverX_0070F854, gnHoverY_0070F858 - 0x48, bFlag, 1, nPercent);
        return;
    }
    case UNIT_ITEM:
        if (gaUIVarStates_007A27C0[13])
        {
            return;
        }
        sub_004527D0(pUnit, 0, 0);
        return;
    case UNIT_MONSTER:
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId != 0x1A1 && nClassId != 0x1A2)
        {
            if (!sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                if (nClassId == 0x164)
                {
                    int bFlag = 3;
                    Unicode wszName[0x80];
                    int nPercent = 0;
                    if (sub_00452C70_GetRosterText(pUnit, wszName, &nPercent, &bFlag))
                    {
                        if (bFlag == 3)
                        {
                            return;
                        }
                        D2Win_10130_DrawFramedTextEx(wszName, gnHoverX_0070F854, gnHoverY_0070F858 - 0x48, bFlag, 1, nPercent);
                        return;
                    }
                }
                sub_00454AD0_DrawUnitHoverName(pUnit);
                return;
            }
            sub_00452BE0_ShowUnitHoverName(pUnit, 0);
        }
        else
        {
            D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pRecord)
            {
                MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pRecord->wNameStr));
                sub_00452BE0_ShowUnitHoverName(pUnit, 0);
            }
        }
        gwszText_007A2D30[0] = 0;
        gwszText_007A2A78[0] = 0;
        gwszHoverName_007A2F38[0].wChar = 0;
        return;
    }
    case UNIT_OBJECT:
    {
        Unicode wszUnused[0x80];
        Unicode wszLine[0x100];
        Unicode wszText[0x80] = { 0 };
        int nLow;
        if (sub_004B3230_GetTickPair(&nLow))
        {
            return;
        }
        if (sub_004A0000() == 1)
        {
            return;
        }
        const Unicode* pName = sub_00464A60_GetUnitName(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nOffset = sub_00622270_GetHoverOffset(pUnit);
        const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord((unsigned short)nClassId)->nSubClass;
        if (nFlags & 4)
        {
            Unicode wszOwner[0x80];
            sub_005267E0(wszText, sub_00453E70_GetLevelName(pUnit->pObjectData->InteractType));
            if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1)
            {
                char szOwner[0x80];
                const char* szName = sub_0047A290_GetOwnerName(pUnit->dwUnitId);
                if (szName)
                {
                    sprintf(szOwner, " (%s) ", szName);
                    sub_00526F20_ToUnicode(wszOwner, szOwner, 0x80);
                    sub_00526700(wszText, wszOwner);
                }
                else if (strlen(sub_004BDFD0_GetObjectText(pUnit)))
                {
                    sprintf(szOwner, " (%s) ", sub_004BDFD0_GetObjectText(pUnit));
                    sub_00526F20_ToUnicode(wszOwner, szOwner, 0x80);
                    sub_00526700(wszText, wszOwner);
                }
            }
            D2Win_10129_DrawFramedText(wszText, gnHoverX_0070F854, gnHoverY_0070F858 + nOffset, 0, 1);
            return;
        }
        if (nFlags & 0x80)
        {
            return;
        }
        if (nFlags & 0x40)
        {
            const Unicode* pObjectName = sub_00464A60_GetUnitName(pUnit);
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom)
            {
                return;
            }
            D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
            sub_005267E0(wszLine, pObjectName);
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszLine, D2LANG_GetStringByReferenceString(pLevelsTxt->szLevelName));
            D2Win_10129_DrawFramedText(wszLine, gnHoverX_0070F854, gnHoverY_0070F858 + nOffset, 0, 1);
            return;
        }
        D2Win_10129_DrawFramedText(pName, gnHoverX_0070F854, gnHoverY_0070F858 + nOffset, 0, 1);
        return;
    }
    case UNIT_TILE:
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nLevelId = sub_0061A1D0_GetTileLevelId(pRoom, nClassId);
        D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(nLevelId);
        if (!pLevelsTxt)
        {
            return;
        }
        D2TileRectStrc* pRect = sub_00619620(pRoom, pUnit);
        if (!pRect)
        {
            return;
        }
        const int nX = (pRect->nWidth >> 1) + pRect->nX + gnHoverX_0070F854;
        const int nY = (pRect->nHeight >> 1) + pRect->nY + gnHoverY_0070F858;
        Unicode wszText[0xC8] = { 0 };
        const Unicode* pText = (const Unicode*)pLevelsTxt->wszLevelWarp;
        if (nLevelId == LEVEL_DENOFEVIL)
        {
            if (sub_004B92E0_GetTableByte(0, 1))
            {
                pText = D2LANG_GetStringFromTblIndex(0x13DE);
            }
            else
            {
                pText = D2LANG_GetStringFromTblIndex(0x13DD);
            }
        }
        sub_00526790(wszText, pText, 0xC7);
        D2Win_10129_DrawFramedText(wszText, nX, nY, 0, 1);
        return;
    }
    }
}

struct D2UnitStrc;

// 0x00455AE0
void __fastcall sub_00455AE0_ClearPanelHandlers(int nPanel)
{
    switch (nPanel)
    {
    case 0xA:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        gnPanelFlag_007A2864 = 0x0;
        return;
    case 0x0:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F28, 0x4);
        return;
    case 0x3:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FC4, 0x1);
        return;
    case 0x4:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FAC, 0x2);
        sub_00453AE0();
        sub_004ABF10_ClearSkillStates();
        return;
    case 0x2:
        sub_00453EE0_ClosePanel();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FD0, 0x2);
    case 0x12:
        sub_00453AE0();
        return;
    case 0x1:
        sub_00453EE0_ClosePanel();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F58, 0x4);
        sub_00453AE0();
        return;
    case 0x5:
        sub_0047B2E0_CloseChatInput();
        sub_0047B4E0();
        if (!gaUIVarStates_007A27C0[0xC] && !gaUIVarStates_007A27C0[0x17] && !gaUIVarStates_007A27C0[0x19]
            && !gaUIVarStates_007A27C0[0x1A] && !gaUIVarStates_007A27C0[0x1B] && !gaUIVarStates_007A27C0[0x1C]
            && !gaUIVarStates_007A27C0[0x1D] && !gaUIVarStates_007A27C0[0x1E] && !gaUIVarStates_007A27C0[0x20])
            sub_0046AA20(0x1, 0x1);
        if (gaUIVarStates_007A27C0[0xA])
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        return;
    case 0x6:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FE8, 0x2);
        return;
    case 0x13:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6000, 0x1);
        return;
    case 0x7:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D600C, 0x2);
        return;
    case 0x8:
    case 0xE:
        sub_00453AE0();
        sub_004B3F10_CloseByState();
        return;
    case 0x9:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6030, 0x7);
        sub_00466FE0();
        return;
    case 0xB:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6024, 0x1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D60C0, 0xD);
        sub_004A5200(0);
        return;
    case 0xC:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F878, 0x8);
        sub_004B3F10_CloseByState();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0xF:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F8D8, 0x7);
        sub_004A28D0_ResetButton();
        sub_00453AE0();
        return;
    case 0x11:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D615C, 0x4);
        sub_004A3000_ResetFlag();
        return;
    case 0x10:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D61B0, 0x2);
        sub_0049FF00();
        sub_00453AE0();
        return;
    case 0x14:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D61C8, 0x5);
        sub_0049CF50_SendWaypointClose();
        sub_00453AE0();
        return;
    case 0x15:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6204, 0x2);
        return;
    case 0x16:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D621C, 0x2);
        sub_0049A020_FreeRosterUnits();
        sub_00453AE0();
        return;
    case 0x17:
        if (sub_004B9180())
            return;
        sub_0045AEA0_SetPanelSlide(0);
        sub_00453EE0_ClosePanel();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F930, 0xD);
        sub_00453AE0();
        sub_004B8940_CloseWait(0);
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x19:
        sub_00453EE0_ClosePanel();
        sub_0045AEA0_SetPanelSlide(0);
        sub_00489EE0();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F9D0, 0x8);
        sub_00453AE0();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x1A:
        sub_0045AEA0_SetPanelSlide(0);
        sub_0048A500();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070FA30, 0x7);
        sub_00453AE0();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x18:
        sub_004A01A0_CloseListBoxDialog();
        return;
    case 0x1F:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070FA84, 0x2);
        return;
    case 0x21:
        sub_00494FC0();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D62C4, 0x5);
        return;
    case 0x22:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6300, 0x2);
        return;
    case 0x23:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6318, 0x3);
        return;
    case 0x24:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D633C, 0x3);
        sub_00487990_ResetHover();
        return;
    case 0x25:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6360, 0x2);
        return;
    }
}

// 0x004565E0
void __fastcall sub_004565E0_DrawLoadingScreen(int bAdvanceFrame)
{
    if (!WINDOW_GetState())
    {
        D2GFX_ClearScreen(0);
    }

    const int nLoadState = sub_0044DB30();
    sub_0044CD70_TickTimer();

    if (WINDOW_GetState())
    {
        if (bAdvanceFrame)
        {
            ++gnLoadingFrame_007A2A6C;
        }
        return;
    }

    sub_004FB0D0();
    if (!D2GFX_StartDraw(1, 0, 0, 0))
    {
        if (bAdvanceFrame)
        {
            ++gnLoadingFrame_007A2A6C;
        }
        return;
    }

    if (!gpLoadingScreen_007A2888)
    {
        sub_00456550_LoadLoadingScreen();
        D2_ASSERT(gpLoadingScreen_007A2888, 6594);
    }

    if (nLoadState == 6 || nLoadState == 8 || nLoadState == 7 || nLoadState == 9)
    {
        if (!gnLoadingBarColor_007A2A70)
        {
            gnLoadingBarColor_007A2A70 = D2Win_10034_MixRGB(0x60, 0, 0);
            gnLoadingBoxColor_007A2A71 = D2Win_10034_MixRGB(0xFF, 0xFF, 0);
        }

        if (!gnValue_007A27B8)
        {
            D2GFX_DrawBox(gnGlobal_0071146C / 2 - 0x82, gnGlobal_00711470 / 2 + 0x9E, gnGlobal_0071146C / 2 + 0x82, gnGlobal_00711470 / 2 + 0xB2, gnLoadingBoxColor_007A2A71, 1);
            D2GFX_DrawBox(gnGlobal_0071146C / 2 - 0x80, gnGlobal_00711470 / 2 + 0xA0, gnGlobal_0071146C / 2 + 0x80, gnGlobal_00711470 / 2 + 0xB0, 0, 5);

            const int nWidth = sub_00478150();
            if (nWidth)
            {
                sub_0046EFD0_DrawFramedBox(gnGlobal_0071146C / 2 - 0x80, gnGlobal_00711470 / 2 + 0xA0, nWidth, 0x10, gnLoadingBarColor_007A2A70, 5);
            }
        }
    }

    const int nFrames = CelFileGetCelsPerDirection(gpLoadingScreen_007A2888);
    if (gnLoadingFrame_007A2A6C >= nFrames)
    {
        gnLoadingFrame_007A2A6C = nFrames - 1;
    }

    D2CelContextStrc tContext;
    tContext.pCellFile = gpLoadingScreen_007A2888;
    tContext.nFrame = gnLoadingFrame_007A2A6C;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x80, gnGlobal_00711470 / 2 + 0x80, -1, 5, 0);
    D2GFX_EndScene();
    sub_0044DA40();
    sub_0044DA70();

    if (bAdvanceFrame)
    {
        ++gnLoadingFrame_007A2A6C;
    }
}

// 0x004567F0
void __cdecl sub_004567F0_ToggleMiniPanel()
{
    unsigned long dwValue;
    if (SRegLoadValue("Diablo II", "Mini Panel", 1, &dwValue) && dwValue)
        return;
    const int bWasOn = gbMiniPanel_007A2814;
    if (sub_00408F20_HasExpansionMpq())
        sub_0044DCC0();
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    if (!gbMiniPanel_007A2814)
    {
        if (sub_004A0000())
            return;
        for (int i = 0; i < gnUIVarCount_0070F9CC; ++i)
        {
            if (gaUIVarStates_007A27C0[i] == 1)
            {
                bool bClose = true;
                switch (gpUIVarRecords_00711130[i]->nCloseKind)
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (sub_004B3230_GetTickPair(&nLow))
                        sub_004B3C20(nLow);
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                case 3:
                    bClose = false;
                    break;
                default:
                    return;
                }
                if (!bClose)
                    return;
            }
        }
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !sub_00464820_IsDeadOrDying(pPlayer)))
        gbMiniPanel_007A2814 = gbMiniPanel_007A2814 == 0;
    if (!bWasOn)
    {
        if (gbMiniPanel_007A2814)
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6204, 2);
    }
    else
    {
        if (!gbMiniPanel_007A2814)
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6204, 2);
    }
    sub_00468730();
    sub_00468740();
}

// 0x00456EE0
void __fastcall sub_00456EE0_DrawUIPanels(D2ViewStrc* pView)
{
    if (gaUIVarStates_007A27C0[18])
        return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        gnGlobal_007A2858 = 0x50;
        gnGlobal_007A285C = -0x3C;
    }
    else
    {
        gnGlobal_007A2858 = 0;
        gnGlobal_007A285C = 0;
    }
    sub_00502280_SetPopUpText(0, 0, 0, 0, 0);
    gwszText_007A2D30[0] = 0;
    gwszText_007A2A78[0] = 0;
    if (gaUIVarStates_007A27C0[9])
        sub_0047E3D0_DrawOptions();
    if (gaUIVarStates_007A27C0[11])
        sub_004A5270();
    sub_00454F30_DrawUnitHover(sub_00467A10());
    if (gaUIVarStates_007A27C0[35])
        sub_00452D20_DrawPetHover();
    if (!gaUIVarStates_007A27C0[1] && !gaUIVarStates_007A27C0[12] && !gaUIVarStates_007A27C0[14])
    {
        sub_00497FE0_DrawDurabilityIcons();
        sub_00497E00();
    }
    if (gaUIVarStates_007A27C0[10] && sub_0045AE90() != 3)
        sub_0045AD60();
    sub_00455510_DrawLevelLoadingScreen();
    sub_00493340_UpdateHirelingPanel();
    if (gaUIVarStates_007A27C0[19])
        sub_00494020_DrawPetIcons();
    if (gaUIVarStates_007A27C0[36])
        sub_004929F0_DrawMercPanel();
    if (gaUIVarStates_007A27C0[37])
        sub_0048BC10();
    if (gaUIVarStates_007A27C0[15])
        sub_004A34F0_DrawQuestPage();
    if (gaUIVarStates_007A27C0[1] || gaUIVarStates_007A27C0[12] || gaUIVarStates_007A27C0[14] || gaUIVarStates_007A27C0[25]
        || gaUIVarStates_007A27C0[26] || gaUIVarStates_007A27C0[28] || gaUIVarStates_007A27C0[29])
        sub_0048EDF0_DrawInventoryPanel();
    if (gaUIVarStates_007A27C0[23])
    {
        sub_004B8730_DrawDialogHover();
        sub_0048EDF0_DrawInventoryPanel();
    }
    sub_00453470_DrawProgressiveStates();
    if (gaUIVarStates_007A27C0[4])
        sub_004AC690_DrawSkillPanel();
    if (gaUIVarStates_007A27C0[2])
        sub_004A7D00_DrawCharStats();
    if (gaUIVarStates_007A27C0[22])
        sub_0049C3D0_DrawPartyPanel();
    if (gpGlobal_007A27A0)
        sub_004B8100(gpGlobal_007A27A0);
    if (gaUIVarStates_007A27C0[16])
        sub_0049FF10_DispatchTextData();
    if (gaUIVarStates_007A27C0[20])
        sub_0049C9C0_DrawWaypointPanel();
    if (gaUIVarStates_007A27C0[33])
    {
        sub_00494320_LoadHelpCels();
        sub_00494EB0();
    }
    sub_00499450_DrawControlPanel();
    if (gaUIVarStates_007A27C0[3])
        sub_004AA7E0_ResetSkillIcons();
    if (gaUIVarStates_007A27C0[31])
        sub_00498E90_SetRecordMode();
    sub_004A64C0_UpdateStatButtons();
    if (gaUIVarStates_007A27C0[34])
        sub_00495180_DrawButtons();
    if (gaUIVarStates_007A27C0[6])
        sub_004A6B30_DrawLeftPanelButtons();
    else
        sub_004A6A70_DrawLeftPanelButton();
    if (gaUIVarStates_007A27C0[7])
        sub_004A6E60_DrawRightPanelButtons();
    else
        sub_004A6DA0_DrawRightPanelButton();
    if (gaUIVarStates_007A27C0[17])
        sub_004A2A80_DrawButton();
    sub_00498120();
    if (gaUIVarStates_007A27C0[21])
        sub_0047F710_UpdateSlotBar();
    if (gaUIVarStates_007A27C0[5])
        sub_0047B720_DrawChatPanel();
    if (gaUIVarStates_007A27C0[33])
    {
        sub_00456300_CloseUIVars(0, 0);
        const int bWasOn = gaUIVarStates_007A27C0[33];
        if (sub_00408F20_HasExpansionMpq())
            sub_0044DCC0();
        D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
        if (!gaUIVarStates_007A27C0[33])
        {
            if (sub_004A0000())
                goto done;
            for (int i = 0; i < gnUIVarCount_0070F9CC; ++i)
            {
                if (gaUIVarStates_007A27C0[i] == 1)
                {
                    bool bClose = true;
                    switch (gpUIVarRecords_00711130[i]->nDrawCloseKind)
                    {
                    case 0:
                        break;
                    case 4:
                    {
                        int nLow;
                        if (sub_004B3230_GetTickPair(&nLow))
                            sub_004B3C20(nLow);
                        break;
                    }
                    case 1:
                        sub_00455F20(i, 1, 0);
                        break;
                    case 2:
                    case 3:
                        bClose = false;
                        break;
                    default:
                        goto done;
                    }
                    if (!bClose)
                        goto done;
                }
            }
        }
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !sub_00464820_IsDeadOrDying(pPlayer)))
                gaUIVarStates_007A27C0[33] = gaUIVarStates_007A27C0[33] == 0;
            if (!bWasOn)
            {
                if (gaUIVarStates_007A27C0[33])
                    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D62C4, 5);
            }
            else
            {
                if (!gaUIVarStates_007A27C0[33])
                {
                    sub_00494FC0();
                    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D62C4, 5);
                }
            }
            sub_00468730();
            sub_00468740();
        }
done:
        sub_004966C0_DrawHelpScreen();
    }
    if (gaUIVarStates_007A27C0[13] && sub_0045AE90() != 3)
    {
        sub_004C0810_DrawUnitNames();
        if (sub_0044DB30())
            sub_00464950(sub_00453330_DrawPartyMemberText);
    }
    if (gaUIVarStates_007A27C0[8])
        sub_004B4380_UpdateNpcInteract();
    if (gaUIVarStates_007A27C0[14])
        sub_004C01E0_DrawPanelUnit();
    sub_00496B10();
    sub_004A0E70_UpdateTexts(pView);
    D2Win_10124();
    sub_00454A70_DrawHoverText();
    sub_00453060();
    sub_004554B0_DrawHoverName();
    sub_00453B30_DrawStoredUnitNumber();
    sub_00453100_DrawDeathScreen();
    sub_0046C130_DrawCountdown();
}

#include "gen/data/Source/D2Client/UI/ui_004527D0.inc"
