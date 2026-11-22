#include "D2Client.h"
#include "D2ClientGame.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2ItemTypes.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Path.h"
#include "D2Win32Types.h"
#include "D2GameObjs.h"
#include "D2LevelTxt.h"
#include "D2ItemsWorld.h"

struct D2CelFileStrc;

struct Unicode;

struct D2UiControlAStrc;

struct D2UiControlBStrc;

struct D2UiControlCStrc;

struct PairStrc_0045BA70;

struct D2RectStrc;

struct D2SlotStrc;

struct D2SlotOwnerStrc;

struct D2MsgHandlerEntryStrc;

struct D2PanelHotkeysStrc;

struct D2ClientEntryStrc;

struct D2RosterPetStrc;

struct D2CelContextStrc;

struct D2UnitStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2DataTablesStrc;

struct D2ImmunityTextStrc;

extern int gdwGlobal_007A277C; // 0x007A277C

extern int gdwGlobal_007A2784; // 0x007A2784

extern int gdwGlobal_007A2788; // 0x007A2788

extern int gdwGlobal_007A2878; // 0x007A2878

extern int gdwGlobal_007A2880; // 0x007A2880

extern int gdwGlobal_007A288C; // 0x007A288C

extern int gdwGlobal_007A51E0; // 0x007A51E0

extern int gdwGlobal_007113E8; // 0x007113E8

extern int gdwGlobal_007A5150; // 0x007A5150

extern int gdwGlobal_007A520C; // 0x007A520C

extern int gdwGlobal_007A5208; // 0x007A5208

struct PairStrc_0045BA70
{
    int nFirst;
    int nSecond;
};

void __stdcall sub_00625960(void* pArg); // 0x00625960

extern int gdwGlobal_007A6A94; // 0x007A6A94

extern int gdwGlobal_007A6ABC; // 0x007A6ABC

extern int gdwGlobal_007A6AB0; // 0x007A6AB0

extern int gdwGlobal_007A6AAC; // 0x007A6AAC

extern int gdwGlobal_007A6AF0; // 0x007A6AF0

extern int gdwGlobal_007A8918; // 0x007A8918

extern D2CelFileStrc* gpBoxPiecesCel_007A2798; // 0x007A2798

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

struct D2SlotStrc
{
    int unk0x00;
    int nClass;
    int unk0x08;
};

struct D2SlotOwnerStrc
{
    char unk0x00[0x20];
    D2SlotStrc* pSlots;
};

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

void __fastcall CUNIT_ForEachPlayer(void (__fastcall* pfnCallback)(D2UnitStrc*)); // 0x00464950

void __fastcall UI_DrawPartyMemberText(D2UnitStrc* pUnit); // 0x00453330

int __cdecl sub_004B85E0(); // 0x004B85E0

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

struct D2PanelHotkeysStrc
{
    int nIndex26Sec;
    int nIndex16Sec;
    int nIndex26;
    int nIndex16;
    int nIndex29Sec;
    int nIndex29;
    int nIndex2CSec;
    int nIndex2C;
    D2MsgHandlerEntryStrc* f_20;
};

int __cdecl sub_004F59A0(); // 0x004F59A0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl CHAT_InitChatIme(); // 0x0047B090

void __cdecl sub_0047B4D0_Nop(); // 0x0047B4D0

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

void __fastcall TEXT_ToggleKeyConfigPanel(int nArg); // 0x004A5200

void __cdecl UI_RegisterKeyConfigHandlers(); // 0x00454980

void __cdecl TEXT_ResetNpcPanel(); // 0x00491940

void __cdecl sub_004B8920(); // 0x004B8920

void __cdecl sub_0048A680(); // 0x0048A680

void __cdecl INV_LoadStashPanelCels(); // 0x00489E50

void __cdecl INV_LoadCubePanelCel(); // 0x0048A4B0

void TEXT_OpenMessageLogDialog(); // 0x004A0050

void __cdecl PARTY_RebuildRosterUnits(); // 0x0049A640

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[]; // 0x006D5F28

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F58[]; // 0x006D5F58

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FAC[]; // 0x006D5FAC

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FC4[]; // 0x006D5FC4

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FD0[]; // 0x006D5FD0

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5FE8[]; // 0x006D5FE8

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6000[]; // 0x006D6000

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D600C[]; // 0x006D600C

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6030[]; // 0x006D6030

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6084[]; // 0x006D6084

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

extern const D2PanelHotkeysStrc gtPanelHotkeys_006D5F88; // 0x006D5F88

extern const D2PanelHotkeysStrc gtPanelHotkeys_006D618C; // 0x006D618C

extern const D2PanelHotkeysStrc gtPanelHotkeys_006D6234; // 0x006D6234

extern const D2PanelHotkeysStrc gtPanelHotkeys_006D6258; // 0x006D6258

extern const D2PanelHotkeysStrc gtPanelHotkeys_006D627C; // 0x006D627C

extern const D2PanelHotkeysStrc gtPanelHotkeys_006D62A0; // 0x006D62A0

int gnPanelState_007A27E8;                                                                                  // 0x007A27E8

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl GAME_LoadLoadingPalette(); // 0x00454740

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern int gnGlobal_0071146C; // 0x0071146C

extern unsigned long gdwUIVarTick_007A2790; // 0x007A2790

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern int gdwGlobal_007A5238; // 0x007A5238

extern void* gpGlobal_007A523C; // 0x007A523C

extern void* gpGlobal_007A5240; // 0x007A5240

extern void* gpGlobal_007A5244; // 0x007A5244

extern int gnGlobal_007B8D20; // 0x007B8D20

extern int gnGlobal_007B9534; // 0x007B9534

extern int gnGlobal_007B9538; // 0x007B9538

extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

struct D2UiControlAStrc
{
    virtual ~D2UiControlAStrc();
};

struct D2UiControlBStrc
{
    virtual ~D2UiControlBStrc();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual unsigned int GetValue();
};

struct D2UiControlCStrc
{
    virtual ~D2UiControlCStrc();
};

void __cdecl sub_00489880_OpenPanel(); // 0x00489880

void __cdecl sub_004A7A80_OpenPanel0(); // 0x004A7A80

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

extern unsigned int gnDialogAmount_007A2A68; // 0x007A2A68

void __cdecl UI_CloseGoldDialog(); // 0x00453EE0

void __fastcall sub_004B9110_SendGoldRequest(unsigned long nGold); // 0x004B9110

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall sub_004B8100(void* pObj); // 0x004B8100

void __cdecl TEXT_ToggleListDialogUI(); // 0x004A02F0

void __cdecl sub_004B69E0_CloseTrade(); // 0x004B69E0

D2UiControlAStrc* gpGoldControlA_007A27A4; // 0x007A27A4

D2UiControlBStrc* gpGoldControlB_007A27A8; // 0x007A27A8

D2UiControlCStrc* gpGoldControlC_007A27AC; // 0x007A27AC

D2UiControlCStrc* gpGoldControlD_007A27B0; // 0x007A27B0

int gbGoldPanelFlag_007A27B4; // 0x007A27B4

#pragma pack(push, 2)

struct D2ImmunityTextStrc
{
    int nStat;
    unsigned short wString;
    int nColor;
};

#pragma pack(pop)

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360

int __fastcall UI_GetHoverRect(D2RectStrc* pRect); // 0x00454880

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5, int nArg6); // 0x005022F0

int __fastcall AUTOMAP_GetHoverMonsterName(D2UnitStrc* pUnit, int nArg); // 0x00452580

void __fastcall GAME_SetHoverLine(const Unicode* pText, int nColor); // 0x00452520

int __fastcall NPCMENU_GetInteractNpcId(int* pLow); // 0x004B3230

int __cdecl TEXT_IsTextBoxOpen(); // 0x004A0000

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const D2ImmunityTextStrc gaImmunityTexts_006D6418[6]; // 0x006D6418

extern Unicode gwszText_007A2A78[]; // 0x007A2A78

extern int gnHoverTextState_007A2C78; // 0x007A2C78

extern Unicode gwszHoverName_007A2F38[]; // 0x007A2F38

int gdwGlobal_007A2780; // 0x007A2780

int gdwGlobal_007A2868; // 0x007A2868

int gdwGlobal_007A8914; // 0x007A8914

int gdwGlobal_007A891C; // 0x007A891C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char gszFmtInt_006D6454[]; // 0x006D6454

extern "C" const char gszUiCpp_006D6458[]; // 0x006D6458

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC

int __cdecl CHAT_IsNumberDisplayEnabled(); // 0x0047A980

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __fastcall sub_00479B80_GetRecordValue(D2StoredUnitRecordStrc* pRecord); // 0x00479B80

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

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

extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0

const Unicode* __fastcall UI_GetLevelName(int nLevelId); // 0x00453E70

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30

void __fastcall sub_00454AD0_DrawUnitHoverName(D2UnitStrc* pUnit);                                          // 0x00454AD0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070

void __fastcall VIEW_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY);                           // 0x004760C0

D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40

int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20

int __fastcall sub_00479150_FindRosterIndex(int nUnitId);                                                   // 0x00479150

const char* __fastcall ROSTER_GetPortalOwnerName(int nUnitId);                                              // 0x0047A290

int __stdcall INV_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0

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

void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName);        // 0x0063E810

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640

extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0

extern Unicode gxGlobal_007A2C80[80];                                                                       // 0x007A2C80

extern int gdwGlobal_007A2D20;                                                                              // 0x007A2D20

extern int gdwGlobal_007A2D24;                                                                              // 0x007A2D24

extern int gdwGlobal_007A2D28;                                                                              // 0x007A2D28

extern unsigned short gwszText_007A2D30[];                                                                  // 0x007A2D30

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6024[];                                                    // 0x006D6024

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D60C0[];                                                    // 0x006D60C0

struct D2Block0xA0Strc;

struct D2Block0xA0Strc
{
    unsigned short wData[0x50];
};

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

void __fastcall PLAYER_SetPanelSlide(int nMode); // 0x0045AEA0

void __cdecl sub_00466FE0(); // 0x00466FE0

void __cdecl CHAT_CloseChatInput(); // 0x0047B2E0

void __cdecl sub_0047B4E0(); // 0x0047B4E0

void __cdecl INV_ResetHover(); // 0x00487990

void __cdecl sub_00489EE0(); // 0x00489EE0

void __cdecl sub_0048A500(); // 0x0048A500

void __cdecl sub_00494FC0(); // 0x00494FC0

void __cdecl PARTY_FreeRosterUnits(); // 0x0049A020

void __cdecl sub_0049CF50_SendWaypointClose(); // 0x0049CF50

void __cdecl sub_0049FF00(); // 0x0049FF00

void __cdecl TEXT_CloseMessageLogDialog(); // 0x004A01A0

void __cdecl TEXT_ResetQuestButton(); // 0x004A28D0

extern "C" void __cdecl TEXT_ResetQuestButtonState(); // 0x004A3000

void __cdecl sub_004ABF10_ClearSkillStates(); // 0x004ABF10

void __cdecl NPCMENU_CloseByState(); // 0x004B3F10

void __fastcall sub_004B8940_CloseWait(int bReopen); // 0x004B8940

void __cdecl GAME_TickKeepAlive(); // 0x0044CD70

void __cdecl GAME_LoadLoadingScreen(); // 0x00456550

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __cdecl sub_00478150(); // 0x00478150

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __cdecl sub_0044DA70(); // 0x0044DA70

struct D2UIVarRecordStrc
{
    char unk0x00[0x54];
    int nCloseKind;
    unsigned char unk_58[0x2C];
    int nDrawCloseKind;
};

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __fastcall NPCMENU_EndNpcInteraction(int nValue); // 0x004B3C20

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10

void __fastcall UI_DrawUnitHover(D2UnitStrc* pUnit); // 0x00454F30

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __fastcall TEXT_UpdateTexts(D2ViewStrc* pView); // 0x004A0E70

void __cdecl sub_0047E3D0_DrawOptions(); // 0x0047E3D0

void __cdecl TEXT_DrawKeyConfigPanel(); // 0x004A5270

void __cdecl UI_DrawPetHover(); // 0x00452D20

void __cdecl PANEL_DrawDurabilityIcons(); // 0x00497FE0

void __cdecl PANEL_DrawQuantityWarningIcons(); // 0x00497E00

void __cdecl PLAYER_DrawAutomap(); // 0x0045AD60

void __cdecl GAME_DrawLevelLoadingScreen(); // 0x00455510

void __cdecl HIREABLES_UpdateHirelingPanel(); // 0x00493340

void __cdecl sub_00494020_DrawPetIcons(); // 0x00494020

void __cdecl sub_004929F0_DrawMercPanel(); // 0x004929F0

void __stdcall INV_DrawRecipeScroll(); // 0x0048BC10

void __cdecl sub_004A34F0_DrawQuestPage(); // 0x004A34F0

void __cdecl sub_0048EDF0_DrawInventoryPanel(); // 0x0048EDF0

void __cdecl sub_004B8730_DrawDialogHover(); // 0x004B8730

void __cdecl sub_00453470_DrawProgressiveStates(); // 0x00453470

void __cdecl sub_004AC690_DrawSkillPanel(); // 0x004AC690

void __cdecl sub_004A7D00_DrawCharStats(); // 0x004A7D00

void __cdecl PANEL_DrawPartyPanel(); // 0x0049C3D0

void __cdecl TEXT_DispatchTextData(); // 0x0049FF10

void __cdecl sub_0049C9C0_DrawWaypointPanel(); // 0x0049C9C0

void __cdecl HIREABLES_LoadHelpCels(); // 0x00494320

void __cdecl sub_00494EB0(); // 0x00494EB0

void __cdecl PANEL_DrawControlPanel(); // 0x00499450

void __cdecl sub_004AA7E0_ResetSkillIcons(); // 0x004AA7E0

void __cdecl PANEL_SetBeltExpandedMode(); // 0x00498E90

void __cdecl TEXT_UpdateLevelUpButtons(); // 0x004A64C0

void __cdecl VIEW_DrawHelpButtons(); // 0x00495180

void __cdecl TEXT_DrawStatButton(); // 0x004A6B30

void __cdecl sub_004A6A70_DrawLeftPanelButton(); // 0x004A6A70

void __cdecl TEXT_DrawSkillButton(); // 0x004A6E60

void __cdecl sub_004A6DA0_DrawRightPanelButton(); // 0x004A6DA0

void __cdecl TEXT_DrawQuestButton(); // 0x004A2A80

void __cdecl PANEL_DrawLifeManaText(); // 0x00498120

void __cdecl sub_0047F710_UpdateSlotBar(); // 0x0047F710

void __cdecl sub_0047B720_DrawChatPanel(); // 0x0047B720

void __cdecl sub_004966C0_DrawHelpScreen(); // 0x004966C0

void __cdecl sub_004C0810_DrawUnitNames(); // 0x004C0810

void __cdecl NPCMENU_UpdateNpcInteract(); // 0x004B4380

void __cdecl ITEM_DrawPanelUnit(); // 0x004C01E0

void __cdecl WARDENCLIENT_DrawHostileIcon(); // 0x00496B10

void __stdcall D2Win_10124(); // 0x00503000

void __cdecl sub_00454A70_DrawHoverText(); // 0x00454A70

void __cdecl GAME_DrawPopUpText(); // 0x00453060

void __cdecl sub_004554B0_DrawHoverName(); // 0x004554B0

void __cdecl UI_DrawStoredUnitNumber(); // 0x00453B30

void __cdecl UI_DrawDeathScreen(); // 0x00453100

void __cdecl sub_0046C130_DrawCountdown(); // 0x0046C130

D2CelFileStrc* gpLoadingScreen_007A2888; // 0x007A2888

int gnLoadingFrame_007A2A6C; // 0x007A2A6C

int gnValue_007A27B8; // 0x007A27B8

unsigned char gnLoadingBarColor_007A2A70; // 0x007A2A70

unsigned char gnLoadingBoxColor_007A2A71; // 0x007A2A71

int gbMiniPanel_007A2814; // 0x007A2814

int gnPanelFlag_007A2864; // 0x007A2864

unsigned short gwDialogAmountHigh_007A2A6A; // 0x007A2A6A

int gnDialogMode_007A279C; // 0x007A279C

int __cdecl GAME_IsHardcore();                                                                      // 0x0044B850

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType);                             // 0x004788B0

void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nA, int nB, int nC);  // 0x00502680

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...);                  // 0x005269D0

int gbDeathScreenShown_007A2890;                                                                            // 0x007A2890

D2CelFileStrc* gpYouDiedHardcoreCel_007A2894;                                                              // 0x007A2894

D2CelFileStrc* gpYouDiedInstCel_007A2898;                                                                  // 0x007A2898

extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220

static void __stdcall UI_GetPlayerHoverName(D2UnitStrc* pUnit, Unicode* pDst, int nMaxLength, int* pValue, int* pFlag);

static void __stdcall UI_ShowUnitHoverName(D2UnitStrc* pUnit, int bSet);

static int __stdcall UI_GetRosterHoverName(D2UnitStrc* pUnit, Unicode* pDst, int* pValue, int* pFlag);

static __forceinline int SetHoverPositionFromUnit(D2UnitStrc* pUnit);

int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

int __fastcall sub_00479080_GetPetLife(int nUnitId); // 0x00479080

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x00451910
int __cdecl UI_IsRecordingEnabled()
{
    return gdwGlobal_007A277C;
}

// 0x00451960
int __cdecl UI_IsRecordHandlerInstalled()
{
    return gdwGlobal_007A2780;
}

// 0x00451980
int __cdecl UI_IsPlaybackEnabled()
{
    return gdwGlobal_007A2784;
}

// 0x00451990
int __cdecl UI_IsReplayActive()
{
    return gdwGlobal_007A2788;
}

// 0x004525F0
int __fastcall UI_GetMonsterLifeFraction(D2UnitStrc* pUnit)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 1 && !CUNIT_IsDeadOrDying(pUnit))
    {
        int bPaired;
        if ((!pUnit ? 0 : (pUnit->dwFlags >> 2) & 1) && sub_00465C60_CheckUnitPair(sub_00463DD0_GetPlayerUnit(), pUnit))
        {
            bPaired = 1;
        }
        else
        {
            bPaired = 0;
        }

        const int nLife = sub_00479080_GetPetLife(pUnit->dwUnitId);
        int nResult;
        if (!bPaired && nLife > 0)
        {
            nResult = D2_MIN(D2_MAX((nLife << 7) / 100, 2), 0x80);
        }
        else
        {
            const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (!nMaxLife)
            {
                nResult = 0x80;
            }
            else
            {
                const int nCurrentLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
                nResult = D2_MIN(D2_MAX((nCurrentLife << 7) / nMaxLife, 2), 0x80);
            }
        }
        return nResult;
    }
    return 0;
}

// 0x004526C0
static void UI_BuildImmunityText(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0x2C0 && pUnit->dwClassId <= 0x2C5)
    {
        return;
    }
    const Unicode* pNewLine = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pComma = D2LANG_GetStringFromTblIndex(0xF0C);
    unsigned short wszText[0x100];
    for (int i = 0; i < 0x100; i++)
        wszText[i] = 0;
    wszText[0] = 0;
    for (int n = 0; n < 6; n++)
    {
        if (STATLIST_UnitGetStatValue(pUnit, gaImmunityTexts_006D6418[n].nStat, 0) >= 100)
        {
            unsigned short wszItem[0x100];
            for (int i = 0; i < 0x100; i++)
                wszItem[i] = 0;
            if (wszText[0])
            {
                sub_00526700((Unicode*)wszText, pComma);
                sub_00526700((Unicode*)wszText, pNewLine);
            }
            sub_005267E0((Unicode*)wszItem, D2LANG_GetStringFromTblIndex(gaImmunityTexts_006D6418[n].wString));
            INV_PrefixColorCode((Unicode*)wszItem, gaImmunityTexts_006D6418[n].nColor);
            sub_00526700((Unicode*)wszText, (Unicode*)wszItem);
        }
    }
    sub_005267E0(gwszText_007A2A78, (Unicode*)wszText);
    gnHoverTextState_007A2C78 = 4;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004527D0
void __fastcall UI_BuildItemHoverName(D2UnitStrc* pUnit, Unicode* pOut, int nMaxLength)
{
    gnHoverY_0070F858 -= 0x10;
    if (!pUnit)
        return;

    const Unicode* pName = CUNIT_GetUnitName(pUnit);
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
    if (ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
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

        INV_PrefixColorCode(wszText, nColor);
        D2_ASSERT(sub_00526800(wszText) < nMaxLength, 0x5E0);
        sub_005267E0(pOut, wszText);
        return;
    }
    else if (pUnit)
    {
        Unicode wszItem[0x80] = { 0 };
        INV_BuildItemName(pUnit, (Unicode*)wszItem, 0x100);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText((Unicode*)wszItem, gnHoverX_0070F854, gnHoverY_0070F858, nColor, 1);
            return;
        }

        INV_PrefixColorCode((Unicode*)wszItem, nColor);
        D2_ASSERT(sub_00526800((Unicode*)wszItem) < nMaxLength, 0x5EB);
        sub_005267E0(pOut, (Unicode*)wszItem);
    }
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00452AF0
static void __stdcall UI_GetPlayerHoverName(D2UnitStrc* pUnit, Unicode* pDst, int nMaxLength, int* pValue, int* pFlag)
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

// 0x00452BE0
static void __stdcall UI_ShowUnitHoverName(D2UnitStrc* pUnit, int bSet)
{
    int nValues[2];
    if (NPCMENU_GetInteractNpcId(&nValues[0]))
    {
        return;
    }
    nValues[1] = sub_004525F0_GetHoverTextY(pUnit);
    const int nY = gnHoverY_0070F858 - 0x48;
    const int nX = gnHoverX_0070F854;
    const Unicode* pName = CUNIT_GetUnitName(pUnit);
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

// 0x00452C70
static int __stdcall UI_GetRosterHoverName(D2UnitStrc* pUnit, Unicode* pDst, int* pValue, int* pFlag)
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

// 0x00452D20
void __cdecl UI_DrawPetHover()
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
    D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
    if (!pPet)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pPet))
    {
        return;
    }
    UI_ShowUnitHoverName(pPet, 1);
}

// 0x00452E50
void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect)
{
    int nWidth = pRect->nRight - pRect->nLeft;
    int nLeft = pRect->nLeft;
    int nRight = nLeft + nWidth + 1;
    int nHeight = pRect->nBottom - pRect->nTop;
    int nTop = pRect->nTop;
    int nBottom = nTop + nHeight + 1;
    D2CelContextStrc context;
    int nPiece = 0;
    memset(&context, 0, sizeof(context));
    context.pCellFile = gpBoxPiecesCel_007A2798;
    context.nDirection = 0;

    const int nRightCorner = nRight - 12;
    const int nHorizontalStart = nLeft + 12;
    for (int nX = nHorizontalStart; nX < nRightCorner - 1; nX += 12)
    {
        context.nFrame = ++nPiece % 6 + 2;
        sub_004F6480(&context, nX, nTop + 12, -1, 5, 0);
    }
    for (int nX = nHorizontalStart + 1; nX < nRightCorner - 1; nX += 12)
    {
        context.nFrame = ++nPiece % 6 + 16;
        sub_004F6480(&context, nX, nBottom + 10, -1, 5, 0);
    }
    const int nVerticalStart = nTop + 12;
    for (int nY = nVerticalStart + 10; nY < nBottom - 1; nY += 12)
    {
        context.nFrame = ++nPiece % 3 + 10;
        sub_004F6480(&context, nLeft - 4, nY, -1, 5, 0);
    }
    for (int nY = nVerticalStart + 12; nY < nBottom - 1; nY += 12)
    {
        context.nFrame = ++nPiece % 3 + 13;
        sub_004F6480(&context, nRight - 7, nY, -1, 5, 0);
    }
    context.nFrame = 0;
    sub_004F6480(&context, nLeft, nVerticalStart, -1, 5, 0);
    context.nFrame = 1;
    sub_004F6480(&context, nRightCorner, nVerticalStart, -1, 5, 0);
    context.nFrame = 8;
    sub_004F6480(&context, nLeft, nBottom + 1, -1, 5, 0);
    context.nFrame = 9;
    sub_004F6480(&context, nRightCorner, nBottom + 1, -1, 5, 0);
}

// 0x00453100
void __cdecl UI_DrawDeathScreen()
{
    char szPath[0x104];
    char szLanguage[4];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    if (CUNIT_IsDeadOrDying(pPlayer))
    {
        int nY = gnGlobal_00711470 / 2 - 0x5E;
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
        STRTABLE_GetLanguageInfoField(szLanguage, 0);
        if (!gpYouDiedHardcoreCel_007A2894)
        {
            sprintf(szPath, "%s\\UI\\%s\\youdiedhardcore", szDataLocal_006D41A8, szLanguage);
            gpYouDiedHardcoreCel_007A2894 = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
        if (gpYouDiedHardcoreCel_007A2894)
            D2Win_10134_DrawCellFile(gpYouDiedHardcoreCel_007A2894, gnGlobal_0071146C / 2, nY, 1, 5, 1);

        nY += 0x30;
        gbDeathScreenShown_007A2890 = 1;
        if (!gpYouDiedInstCel_007A2898)
        {
            sprintf(szPath, "%s\\UI\\%s\\youdiedinst", szDataLocal_006D41A8, szLanguage);
            gpYouDiedInstCel_007A2898 = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
        if (gpYouDiedInstCel_007A2898)
            D2Win_10134_DrawCellFile(gpYouDiedInstCel_007A2898, gnGlobal_0071146C / 2, nY, 1, 5, 1);

        Unicode wszText[0x100];
        if (GAME_IsHardcore())
        {
            sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x13E8));
        }
        else
        {
            if (!STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDLOST, 0))
                goto second_text;
            sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x13E6), STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDLOST, 0));
        }
        nY += 0x30;
        sub_00502EF0(2);
        {
            const int nWidth = D2Win_10121_GetTextWidth(wszText);
            const int nX = gnAutomapWidth_007A5220 / 2 - nWidth / 2;
            D2Win_10117_DrawText(wszText, nX, nY, 1, 1);
        }

second_text:
        if (GAME_GetDifficulty() > 0 && !GAME_IsHardcore())
        {
            sub_00502EF0(2);
            const int nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0x13E7));
            const int nX = gnAutomapWidth_007A5220 / 2 - nWidth / 2;
            nY += 0x30;
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x13E7), nX, nY, 1, 1);
        }
    }
    else
    {
        gbDeathScreenShown_007A2890 = 0;
    }
}

// 0x00453330
void __fastcall UI_DrawPartyMemberText(D2UnitStrc* pUnit)
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
    VIEW_GetViewOffset(gpView_007A0640, &nOffsetX, &nOffsetY);
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
    UI_GetPlayerHoverName(pUnit, wszName, 0x80, &nPercent, &bFlag);
}

// 0x004535D0
void __cdecl UI_DrawPartyTexts()
{
    if (GAME_GetConnectionType())
    {
        CUNIT_ForEachPlayer(UI_DrawPartyMemberText);
    }
}

// 0x004535F0
static inline void __stdcall UI_SetSlotClass(D2SlotOwnerStrc* pOwner, unsigned short wDefault, int nIndex, int nA, int nB)
{
    if (nIndex == -1)
    {
        return;
    }

    int nValue;
    unsigned short wClass;
    if (CUNIT_HasHotkeyBinding(nA, nB) && (wClass = CUNIT_GetHotkeyBinding(nA, nB)) != 0xFFFF && wClass <= 0xDF)
    {
        nValue = wClass;
    }
    else
    {
        nValue = wDefault;
    }

    pOwner->pSlots[nIndex].nClass = nValue;
}

static inline void SetHotkey(const D2PanelHotkeysStrc* pDesc, int nIndex, int nKeyFunc, int bSecondary, int nDefault)
{
    if (nIndex == -1)
        return;

    if (CUNIT_HasHotkeyBinding(nKeyFunc, bSecondary))
    {
        const unsigned short nKey = CUNIT_GetHotkeyBinding(nKeyFunc, bSecondary);
        if (nKey != 0xFFFF && nKey <= 0xDF)
        {
            pDesc->f_20[nIndex].nId = nKey;
            return;
        }
    }

    pDesc->f_20[nIndex].nId = nDefault;
}

// 0x00453640
static void UI_SetPanelHotkeys(const D2PanelHotkeysStrc* pDesc)
{
    SetHotkey(pDesc, pDesc->nIndex16Sec, 0x16, 0x1, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26Sec, 0x26, 0x1, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29Sec, 0x29, 0x1, 0x4E);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        SetHotkey(pDesc, pDesc->nIndex2CSec, 0x2C, 0x1, 0x57);
    SetHotkey(pDesc, pDesc->nIndex16, 0x16, 0x0, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26, 0x26, 0x0, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29, 0x29, 0x0, 0x4E);
    if (FOG_IsExpansion())
        SetHotkey(pDesc, pDesc->nIndex2C, 0x2C, 0x0, 0x57);
}

void __fastcall sub_M117_Emit_004535F0(D2SlotOwnerStrc* pOwner, int nIndex, int nA, int nB)
{
    UI_SetSlotClass(pOwner, 0x1234, nIndex, nA, nB);
}

// 0x00453900
int __cdecl UI_IsDialogOpen()
{
    return sub_004B85E0() != 0;
}

// 0x00453B30
void __cdecl UI_DrawStoredUnitNumber()
{
    if (!CHAT_IsNumberDisplayEnabled())
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
    D2Win_10117_DrawText(wszText, 600, 25, 4, 0);
}

// 0x00453FD0
int __cdecl UI_GoldSpinnerDefaultCallback()
{
    return 0;
}

// 0x00453AA0
int __cdecl UI_GetPentspinCel()
{
    return gdwGlobal_007A2878;
}

// 0x00453AB0
int __cdecl UI_GetFocusCel()
{
    return gdwGlobal_007A2880;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00453AC0
void __cdecl UI_DisableUIVarDelay()
{
    gdwGlobal_0070FA9C = 0;
    gdwUIVarTick_007A2790 = 0;
}

static inline int IsGoldPanelMode(int nMode)
{
    if (nMode <= 0)
    {
        return 0;
    }

    if (nMode > 4)
    {
        return 0;
    }

    return 1;
}

// 0x00453AD0
void __cdecl UI_EnableUIVarDelay()
{
    gdwGlobal_0070FA9C = 1;
}

// 0x00454140
int __cdecl UI_CancelGoldDialog()
{
    UI_CloseGoldDialog();
    return 1;
}

static inline int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00454080
int __cdecl UI_ConfirmGoldDialog()
{
    UI_CloseGoldDialog();
    if (!gnDialogAmount_007A2A68)
    {
        if (gnDialogMode_007A279C == 2)
            sub_004B9110_SendGoldRequest(gnDialogAmount_007A2A68);
        return 1;
    }
    switch (gnDialogMode_007A279C)
    {
    case 0:
    case 1:
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nId = GetUnitId(pPlayer);
        sub_004786A0_SendDwords2(0x50, nId, gnDialogAmount_007A2A68);
        return 1;
    }
    case 2:
        sub_004B9110_SendGoldRequest(gnDialogAmount_007A2A68);
        break;
    case 4:
        sub_00478600_SendShorts(0x4F, 0x13, gwDialogAmountHigh_007A2A6A, gnDialogAmount_007A2A68);
        break;
    case 3:
        sub_00478600_SendShorts(0x4F, 0x14, gwDialogAmountHigh_007A2A6A, gnDialogAmount_007A2A68);
        break;
    default:
        return 1;
    }
    sub_004B9A00(0xDD, 0, 0, 0, 0);
    return 1;
}

// 0x00454570
void __cdecl UI_ClearGoldPanel()
{
    gpGlobal_007A27A0 = 0;
    gpGoldControlA_007A27A4 = 0;
    gpGoldControlB_007A27A8 = 0;
    gpGoldControlD_007A27B0 = 0;
    gpGoldControlC_007A27AC = 0;
    gbGoldPanelFlag_007A27B4 = 0;
}

// 0x004545A0
void __cdecl UI_CloseGoldPanel()
{
    UI_CloseGoldDialog();
}

// 0x004545B0
void __cdecl UI_DrawGoldPanel()
{
    if (gpGlobal_007A27A0)
        sub_004B8100(gpGlobal_007A27A0);
}

// 0x004545C0
void __fastcall UI_TogglePanelHandlers(int bRegister)
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

// 0x00454650
void* __fastcall UI_ReadWholeFile(const char* szName, unsigned long* pSize)
{
    unsigned long nRead;
    char szPath[0x104];
    strcpy(szPath, szName);
    strcat(szPath, D2CMPGetGfxFileExtension(0));
    void* hFile = CreateFileA(szName, 0x80000000, 0, 0, 3, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return 0;
    }

    *pSize = GetFileSize(hFile, 0);
    void* pBuffer = FOG_Alloc(*pSize, ".\\UI\\ui.cpp", 0x18AD, 0);
    memset(pBuffer, 0, *pSize);
    ReadFile(hFile, pBuffer, *pSize, &nRead, 0);
    CloseHandle(hFile);
    return pBuffer;
}

// 0x004547A0
int __cdecl UI_GetLoadingAct()
{
    return gdwGlobal_007A288C;
}

// 0x00454840
int __cdecl UI_IsLoadingScreenActive()
{
    return gdwGlobal_007A2868;
}

// 0x00454980
void __cdecl UI_RegisterKeyConfigHandlers()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D60C0, 13);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6024, 1);
}

// 0x004549B0
void __cdecl UI_ToggleListDialog()
{
    TEXT_ToggleListDialogUI();
    sub_004B69E0_CloseTrade();
}

// 0x00457510
void __stdcall sub_00457510(int nUnused1)
{
}

// 0x00457740
int __cdecl UI_GetAutomapCenters()
{
    return gdwGlobal_007113E0;
}

// 0x00457770
int __cdecl UI_GetAutomapLeft()
{
    return gdwGlobal_007A51E0;
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
        gnHoverX_0070F854 = UNITS_GetClientCoordX(pUnit) - PLAYER_GetScreenOffsetX();
        gnHoverY_0070F858 = UNITS_GetClientCoordY(pUnit) - PLAYER_GetScreenOffsetY();
    }
    return 1;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00454F30
void __fastcall UI_DrawUnitHover(D2UnitStrc* pUnit)
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
        UI_GetPlayerHoverName(pUnit, wszName, 0x80, &nPercent, &bFlag);
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
                    if (UI_GetRosterHoverName(pUnit, wszName, &nPercent, &bFlag))
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
            UI_ShowUnitHoverName(pUnit, 0);
        }
        else
        {
            D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pRecord)
            {
                MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pRecord->wNameStr));
                UI_ShowUnitHoverName(pUnit, 0);
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
        if (NPCMENU_GetInteractNpcId(&nLow))
        {
            return;
        }
        if (TEXT_IsTextBoxOpen() == 1)
        {
            return;
        }
        const Unicode* pName = CUNIT_GetUnitName(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nOffset = sub_00622270_GetHoverOffset(pUnit);
        const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord((unsigned short)nClassId)->nSubClass;
        if (nFlags & 4)
        {
            Unicode wszOwner[0x80];
            sub_005267E0(wszText, UI_GetLevelName(pUnit->pObjectData->InteractType));
            if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1)
            {
                char szOwner[0x80];
                const char* szName = ROSTER_GetPortalOwnerName(pUnit->dwUnitId);
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
            const Unicode* pObjectName = CUNIT_GetUnitName(pUnit);
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
            if (INV_GetTableByte(0, 1))
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

// 0x00455720
void __fastcall UI_SetPanelHandlers(int nPanel)
{
    switch (nPanel)
    {
    case 0xA:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        gnPanelFlag_007A2864 = 0x1;
        return;
    case 0x0:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5F28, 0x4);
        return;
    case 0x3:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FC4, 0x1);
        return;
    case 0x4:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FAC, 0x2);
        return;
    case 0x2:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FD0, 0x2);
        return;
    case 0x1:
        sub_00487B30();
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5F58, 0x4);
        return;
    case 0x5:
        CHAT_InitChatIme();
        sub_0046AA20(0, 0x1);
        if (gnPanelState_007A27E8)
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6084, 0x5);
        sub_0047B4D0_Nop();
        return;
    case 0x6:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5FE8, 0x2);
        return;
    case 0x13:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6000, 0x1);
        return;
    case 0x7:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D600C, 0x2);
        return;
    case 0x9:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6030, 0x7);
        sub_00467A70_RefreshHoverUnit(0);
        return;
    case 0xB:
        TEXT_ToggleKeyConfigPanel(0x1);
        UI_RegisterKeyConfigHandlers();
        return;
    case 0xC:
        sub_0046AA20(0x2, 0x1);
        TEXT_ResetNpcPanel();
        UI_SetPanelHotkeys(&gtPanelHotkeys_006D5F88);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F878, 0x8);
        return;
    case 0xF:
        UI_SetPanelHotkeys(&gtPanelHotkeys_006D618C);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F8D8, 0x7);
        return;
    case 0x11:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D615C, 0x4);
        return;
    case 0x10:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D61B0, 0x2);
        return;
    case 0x14:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D61C8, 0x5);
        return;
    case 0x15:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6204, 0x2);
        return;
    case 0x16:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D621C, 0x2);
        PARTY_RebuildRosterUnits();
        return;
    case 0x17:
        sub_0046AA20(0, 0x1);
        sub_004B8920();
        sub_0048A680();
        UI_SetPanelHotkeys(&gtPanelHotkeys_006D6234);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F930, 0xD);
        return;
    case 0x19:
        sub_0046AA20(0x2, 0x1);
        INV_LoadStashPanelCels();
        UI_SetPanelHotkeys(&gtPanelHotkeys_006D6258);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F9D0, 0x8);
        return;
    case 0x1A:
        sub_0046AA20(0x2, 0x1);
        INV_LoadCubePanelCel();
        UI_SetPanelHotkeys(&gtPanelHotkeys_006D627C);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070FA30, 0x7);
        return;
    case 0x18:
        TEXT_OpenMessageLogDialog();
        return;
    case 0x1F:
        UI_SetPanelHotkeys(&gtPanelHotkeys_006D62A0);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070FA84, 0x2);
        return;
    case 0x21:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D62C4, 0x5);
        return;
    case 0x22:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6300, 0x2);
        return;
    case 0x23:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6318, 0x3);
        return;
    case 0x24:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D633C, 0x3);
        return;
    case 0x25:
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6360, 0x2);
        return;
    }
}

// 0x00455AE0
void __fastcall UI_ClearPanelHandlers(int nPanel)
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
        UI_StartUIVarDelay();
        sub_004ABF10_ClearSkillStates();
        return;
    case 0x2:
        UI_CloseGoldDialog();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5FD0, 0x2);
    case 0x12:
        UI_StartUIVarDelay();
        return;
    case 0x1:
        UI_CloseGoldDialog();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F58, 0x4);
        UI_StartUIVarDelay();
        return;
    case 0x5:
        CHAT_CloseChatInput();
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
        UI_StartUIVarDelay();
        NPCMENU_CloseByState();
        return;
    case 0x9:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6030, 0x7);
        sub_00466FE0();
        return;
    case 0xB:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6024, 0x1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D60C0, 0xD);
        TEXT_ToggleKeyConfigPanel(0);
        return;
    case 0xC:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F878, 0x8);
        NPCMENU_CloseByState();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0xF:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F8D8, 0x7);
        TEXT_ResetQuestButton();
        UI_StartUIVarDelay();
        return;
    case 0x11:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D615C, 0x4);
        TEXT_ResetQuestButtonState();
        return;
    case 0x10:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D61B0, 0x2);
        sub_0049FF00();
        UI_StartUIVarDelay();
        return;
    case 0x14:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D61C8, 0x5);
        sub_0049CF50_SendWaypointClose();
        UI_StartUIVarDelay();
        return;
    case 0x15:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6204, 0x2);
        return;
    case 0x16:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D621C, 0x2);
        PARTY_FreeRosterUnits();
        UI_StartUIVarDelay();
        return;
    case 0x17:
        if (sub_004B9180())
            return;
        PLAYER_SetPanelSlide(0);
        UI_CloseGoldDialog();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F930, 0xD);
        UI_StartUIVarDelay();
        sub_004B8940_CloseWait(0);
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x19:
        UI_CloseGoldDialog();
        PLAYER_SetPanelSlide(0);
        sub_00489EE0();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070F9D0, 0x8);
        UI_StartUIVarDelay();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x1A:
        PLAYER_SetPanelSlide(0);
        sub_0048A500();
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_0070FA30, 0x7);
        UI_StartUIVarDelay();
        sub_0046AA20(0x1, 0x1);
        return;
    case 0x18:
        TEXT_CloseMessageLogDialog();
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
        INV_ResetHover();
        return;
    case 0x25:
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6360, 0x2);
        return;
    }
}

// 0x00453EE0
void __cdecl UI_CloseGoldDialog()
{
    if (gbGoldPanelFlag_007A27B4)
    {
        sub_0046AA20(1, 1);
        gbGoldPanelFlag_007A27B4 = 0;
    }

    if (gpGoldControlB_007A27A8)
    {
        gnGoldPanelValue_007A2A68 = gpGoldControlB_007A27A8->GetValue();
    }

    if (gpGlobal_007A27A0)
    {
        DIALOG_DestroyDialog(gpGlobal_007A27A0);
        gpGlobal_007A27A0 = 0;
    }

    if (gpGoldControlA_007A27A4)
    {
        delete gpGoldControlA_007A27A4;
        gpGoldControlA_007A27A4 = 0;
    }

    if (gpGoldControlB_007A27A8)
    {
        delete gpGoldControlB_007A27A8;
        gpGoldControlB_007A27A8 = 0;
    }

    if (gpGoldControlC_007A27AC)
    {
        delete gpGoldControlC_007A27AC;
        gpGoldControlC_007A27AC = 0;
    }

    if (gpGoldControlD_007A27B0)
    {
        delete gpGoldControlD_007A27B0;
        gpGoldControlD_007A27B0 = 0;
    }

    if (gnGoldPanelMode_007A279C != 0)
    {
        if (IsGoldPanelMode(gnGoldPanelMode_007A279C))
        {
            sub_00489880_OpenPanel();
        }
    }
    else
    {
        sub_004A7A80_OpenPanel0();
    }
}

// 0x004565E0
void __fastcall UI_DrawLoadingScreen(int bAdvanceFrame)
{
    if (!WINDOW_GetState())
    {
        D2GFX_ClearScreen(0);
    }

    const int nLoadState = GAME_GetConnectionType();
    GAME_TickKeepAlive();

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
        GAME_LoadLoadingScreen();
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
    GAME_ResetMouseState();
    sub_0044DA70();

    if (bAdvanceFrame)
    {
        ++gnLoadingFrame_007A2A6C;
    }
}

// 0x004567F0
void __cdecl UI_ToggleMiniPanel()
{
    unsigned long dwValue;
    if (SRegLoadValue("Diablo II", "Mini Panel", 1, &dwValue) && dwValue)
        return;
    const int bWasOn = gbMiniPanel_007A2814;
    if (FOG_IsExpansion())
        GAME_IsExpansion();
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    if (!gbMiniPanel_007A2814)
    {
        if (TEXT_IsTextBoxOpen())
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
                    if (NPCMENU_GetInteractNpcId(&nLow))
                        NPCMENU_EndNpcInteraction(nLow);
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
    if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
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
void __fastcall UI_DrawUIPanels(D2ViewStrc* pView)
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
        TEXT_DrawKeyConfigPanel();
    UI_DrawUnitHover(sub_00467A10());
    if (gaUIVarStates_007A27C0[35])
        UI_DrawPetHover();
    if (!gaUIVarStates_007A27C0[1] && !gaUIVarStates_007A27C0[12] && !gaUIVarStates_007A27C0[14])
    {
        PANEL_DrawDurabilityIcons();
        PANEL_DrawQuantityWarningIcons();
    }
    if (gaUIVarStates_007A27C0[10] && sub_0045AE90() != 3)
        PLAYER_DrawAutomap();
    GAME_DrawLevelLoadingScreen();
    HIREABLES_UpdateHirelingPanel();
    if (gaUIVarStates_007A27C0[19])
        sub_00494020_DrawPetIcons();
    if (gaUIVarStates_007A27C0[36])
        sub_004929F0_DrawMercPanel();
    if (gaUIVarStates_007A27C0[37])
        INV_DrawRecipeScroll();
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
        PANEL_DrawPartyPanel();
    if (gpGlobal_007A27A0)
        sub_004B8100(gpGlobal_007A27A0);
    if (gaUIVarStates_007A27C0[16])
        TEXT_DispatchTextData();
    if (gaUIVarStates_007A27C0[20])
        sub_0049C9C0_DrawWaypointPanel();
    if (gaUIVarStates_007A27C0[33])
    {
        HIREABLES_LoadHelpCels();
        sub_00494EB0();
    }
    PANEL_DrawControlPanel();
    if (gaUIVarStates_007A27C0[3])
        sub_004AA7E0_ResetSkillIcons();
    if (gaUIVarStates_007A27C0[31])
        PANEL_SetBeltExpandedMode();
    TEXT_UpdateLevelUpButtons();
    if (gaUIVarStates_007A27C0[34])
        VIEW_DrawHelpButtons();
    if (gaUIVarStates_007A27C0[6])
        TEXT_DrawStatButton();
    else
        sub_004A6A70_DrawLeftPanelButton();
    if (gaUIVarStates_007A27C0[7])
        TEXT_DrawSkillButton();
    else
        sub_004A6DA0_DrawRightPanelButton();
    if (gaUIVarStates_007A27C0[17])
        TEXT_DrawQuestButton();
    PANEL_DrawLifeManaText();
    if (gaUIVarStates_007A27C0[21])
        sub_0047F710_UpdateSlotBar();
    if (gaUIVarStates_007A27C0[5])
        sub_0047B720_DrawChatPanel();
    if (gaUIVarStates_007A27C0[33])
    {
        UI_CloseUIVars(0, 0);
        const int bWasOn = gaUIVarStates_007A27C0[33];
        if (FOG_IsExpansion())
            GAME_IsExpansion();
        D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
        if (!gaUIVarStates_007A27C0[33])
        {
            if (TEXT_IsTextBoxOpen())
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
                        if (NPCMENU_GetInteractNpcId(&nLow))
                            NPCMENU_EndNpcInteraction(nLow);
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
            if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
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
        if (GAME_GetConnectionType())
            CUNIT_ForEachPlayer(UI_DrawPartyMemberText);
    }
    if (gaUIVarStates_007A27C0[8])
        NPCMENU_UpdateNpcInteract();
    if (gaUIVarStates_007A27C0[14])
        ITEM_DrawPanelUnit();
    WARDENCLIENT_DrawHostileIcon();
    TEXT_UpdateTexts(pView);
    D2Win_10124();
    sub_00454A70_DrawHoverText();
    GAME_DrawPopUpText();
    sub_004554B0_DrawHoverName();
    UI_DrawStoredUnitNumber();
    UI_DrawDeathScreen();
    sub_0046C130_DrawCountdown();
}

// 0x004577B0
int __cdecl UI_GetAutomapParty()
{
    return gdwGlobal_007113E4;
}

// 0x004577E0
int __cdecl UI_GetAutomapPartyNames()
{
    return gdwGlobal_007113E8;
}

// 0x0045A710
int __cdecl UI_GetAutomapMode()
{
    return gdwGlobal_007A5150;
}

// 0x0045AE60
int __cdecl sub_0045AE60()
{
    return gdwGlobal_00711428;
}

// 0x0045AE80
int __cdecl sub_0045AE80()
{
    return gdwGlobal_0071142C;
}

// 0x0045AFA0
int __cdecl UI_GetAutomapOffsetX()
{
    return gdwGlobal_007A520C;
}

// 0x0045AFB0
int __cdecl UI_GetAutomapOffsetY()
{
    return gdwGlobal_007A5208;
}

// 0x0045BA70
void __fastcall UI_ClearPair(PairStrc_0045BA70* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0045F7A0
void __stdcall sub_0045F7A0(int nUnused1, int nUnused2)
{
}

// 0x0045FBC0
void __stdcall UI_DrawCelPair(int bFirst)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (bFirst)
        tContext.pCellFile = gpGlobal_007A523C;
    else
        tContext.pCellFile = gpGlobal_007A5244;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0xBC, 0x148 - gnGlobal_007A285C, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x1BC, 0x148 - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0045FD80
void __cdecl UI_DrawCenteredString()
{
    const int nOldFont = sub_00502EF0(1);
    TEXT_DrawCenteredText(gnGlobal_007A2858 + 0x110, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x170, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    sub_00502EF0(nOldFont);
}

// 0x0045FFC0
void __cdecl UI_DrawCenteredStrings()
{
    const int nOldFont = sub_00502EF0(1);
    TEXT_DrawCenteredText(gnGlobal_0071146C / 2 - 0x84, 0xBE - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
    unsigned short nString = 0x1432;
    if (gdwGlobal_007A5238)
        nString = 0x5578;
    TEXT_DrawCenteredText(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(nString), 0);
    sub_00502EF0(nOldFont);
}

// 0x004600F0
void __cdecl UI_DrawCenteredStringPair()
{
    const int nOldFont = sub_00502EF0(1);
    TEXT_DrawCenteredText(gnGlobal_007A2858 + 0xCE, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x12E, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    TEXT_DrawCenteredText(gnGlobal_007A2858 + 0x152, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1B2, D2LANG_GetStringFromTblIndex(0x13EF), 0);
    sub_00502EF0(nOldFont);
}

// 0x00460430
void __cdecl UI_FreeCels()
{
    if (gpGlobal_007A523C)
    {
        ARCHIVE_FreeClientCellFile(gpGlobal_007A523C);
        gpGlobal_007A523C = 0;
    }
    if (gpGlobal_007A5244)
    {
        ARCHIVE_FreeClientCellFile(gpGlobal_007A5244);
        gpGlobal_007A5244 = 0;
    }
    if (gpGlobal_007A5240)
    {
        ARCHIVE_FreeClientCellFile(gpGlobal_007A5240);
        gpGlobal_007A5240 = 0;
    }
    GAME_LoadLoadingPalette();
}

// 0x004549C0
int __cdecl UI_IsGoldPanelOpen()
{
    return gpGlobal_007A27A0 != 0;
}

// 0x004549D0
D2Block0xA0Strc* __fastcall UI_ClearTextBlock(D2Block0xA0Strc* pBlock)
{
    for (int i = 0; i < 0x50; ++i)
        pBlock->wData[i] = 0;
    return pBlock;
}

// 0x00463D80
void __fastcall UI_FreeUnitModStats(void* pArg)
{
    sub_00625960(pArg);
}

// 0x00466DD0
int __cdecl UI_GetHoverClassId()
{
    return gdwGlobal_00711F94;
}

// 0x00467400
int __cdecl UI_HasSelectedUnit()
{
    return gdwGlobal_007A6A94;
}

// 0x00468030
int __cdecl UI_GetCursorFrame()
{
    return gdwGlobal_007A6AE0;
}

// 0x004680A0
int __cdecl sub_004680A0()
{
    return gdwGlobal_007A6ABC;
}

// 0x00468830
int __cdecl sub_00468830()
{
    return gdwGlobal_007A6AF0;
}

// 0x0046BC70
int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit)
{
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    gnTimerUnitId_007129D4 = nUnitId;
    return nUnitId;
}

// 0x0046F980
int __cdecl UI_GetGfxMemory()
{
    return gdwGlobal_007A8914;
}

// 0x0046F990
int __cdecl UI_GetCofMemoryUsed()
{
    return gdwGlobal_007A8918;
}

// 0x0046F9A0
int __cdecl UI_GetCofMemoryLimit()
{
    return gdwGlobal_007A891C;
}

// 0x00476AF0
void __cdecl UI_ClearGlobals()
{
    gnGlobal_007B9534 = 0;
    gnGlobal_007B9538 = 0;
    gnGlobal_007B8D20 = 0;
}

void __fastcall sub_00454AD0_DrawUnitHoverName(D2UnitStrc* pUnit)
{
    const int nOld = sub_00502EF0(1);
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    int bDead = 0;
    unsigned short wszText[0x800];
    for (int i = 0; i < 0x800; i++)
        wszText[i] = 0;
    if (!(gdwMask_006CE26C & pMonStatsTxt->nMonStatsFlags[1]) && (gdwTitleMaskB_006CE284 & pMonStatsTxt->nMonStatsFlags[1]) && pMonStatsTxt->wNameStr)
    {
        D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (pMonStats2Txt)
        {
            gnHoverY_0070F858 -= pMonStats2Txt->nPixHeight;
        }
        sub_005267E0((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, CUNIT_GetUnitName(pUnit));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        if (pUnit && pUnit->dwAnimMode == 12)
        {
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
            {
                return;
            }
            bDead = 1;
            if (!STRTABLE_GetLanguage())
            {
                sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0x90B));
            }
            else
            {
                Unicode wszParen[2];
                char szParen[] = "(";
                sub_00526F20_ToUnicode(wszParen, szParen, 2);
                sub_00526700((Unicode*)wszText, wszParen);
                sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0x90B));
                strcpy(szParen, ")");
                sub_00526F20_ToUnicode(wszParen, szParen, 2);
                sub_00526700((Unicode*)wszText, wszParen);
            }
            sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        }
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        const int nY = sub_004525F0_GetHoverTextY(pUnit);
        int nColor = 0;
        if (MONSTER_IsUniqueMonster(pUnit))
        {
            nColor = 4;
        }
        if (sub_004AE320_IsMonsterFlag4(pUnit))
        {
            nColor = 3;
        }
        if (bDead)
        {
            nColor = 1;
        }
        if (nClassId == 0xF3 || nClassId == 0x14D || nClassId == 0xF2 || nClassId == 0xD3 || nClassId == 0x220
            || nClassId == 0x23A || nClassId == 0xE5 || nClassId == 0x2C4 || nClassId == 0x2C3 || nClassId == 0x2C2
            || nClassId == 0x2C1 || nClassId == 0x2C5 || nClassId == 0x2C0)
        {
            nColor = 4;
        }
        D2RectStrc tRect;
        if (UI_GetHoverRect(&tRect))
        {
            const int nWidth = D2Win_10121_GetTextWidth((Unicode*)wszText);
            D2Win_10130_DrawFramedTextEx((Unicode*)wszText, ((tRect.nLeft + tRect.nRight) >> 1) - (nWidth >> 1), 0x20, nColor, 0, nY);
            if (bDead)
            {
                gwszHoverName_007A2F38[0].wChar = 0;
            }
            else
            {
                D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
                unsigned short nTypeString = 0;
                if (MONSTERS_IsDemon(pUnit))
                {
                    nTypeString = 0x275E;
                }
                else if (MONSTERS_IsUndead(pUnit))
                {
                    nTypeString = 0x275D;
                }
                if (!AUTOMAP_GetHoverMonsterName(pUnit, nTypeString))
                {
                    if (nTypeString)
                    {
                        Unicode wszLine[0x200];
                        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nTypeString));
                        sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9B));
                        if (pRecord->wDescStr != 0x1506)
                        {
                            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(pRecord->wDescStr));
                        }
                        GAME_SetHoverLine(wszLine, nColor);
                    }
                    else if (pRecord->wDescStr != 0x1506)
                    {
                        GAME_SetHoverLine(D2LANG_GetStringFromTblIndex(pRecord->wDescStr), nColor);
                    }
                }
                UI_BuildImmunityText(pUnit);
            }
        }
    }
    else
    {
        gwszHoverName_007A2F38[0].wChar = 0;
        if (!NPCMENU_GetInteractNpcId(&bDead) && !TEXT_IsTextBoxOpen())
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
            if (pMonStats2Txt)
            {
                gnHoverY_0070F858 -= pMonStats2Txt->nPixHeight;
            }
            D2Win_10129_DrawFramedText(CUNIT_GetUnitName(pUnit), gnHoverX_0070F854, gnHoverY_0070F858, 0, 1);
        }
    }
    sub_00502EF0(nOld);
}

#include "gen/data/Source/D2Client/UI/ui.inc"
