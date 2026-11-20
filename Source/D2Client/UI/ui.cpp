#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"

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

int __cdecl sub_0044DB30(); // 0x0044DB30


void __fastcall sub_00464950(void (__fastcall* pfnCallback)(D2UnitStrc*)); // 0x00464950
void __fastcall sub_00453330_DrawPartyMemberText(D2UnitStrc* pUnit); // 0x00453330
int __cdecl sub_004B85E0(); // 0x004B85E0
int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0


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
void __cdecl sub_0047B090_InitChatIme(); // 0x0047B090
void __cdecl sub_0047B4D0_Nop(); // 0x0047B4D0
void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
void __fastcall sub_004A5200(int nArg); // 0x004A5200
void __cdecl sub_00454980(); // 0x00454980
void __cdecl sub_00491940_ResetNpcPanel(); // 0x00491940
void __cdecl sub_004B8920(); // 0x004B8920
void __cdecl sub_0048A680(); // 0x0048A680
void __cdecl sub_00489E50_LoadStashPanelCels(); // 0x00489E50
void __cdecl sub_0048A4B0_LoadCubePanelCel(); // 0x0048A4B0
void sub_004A0050_OpenListBoxDialog(); // 0x004A0050
void __cdecl sub_0049A640(); // 0x0049A640
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
extern int gnPanelState_007A27E8; // 0x007A27E8


struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int unk0x10[5];
    D2ClientEntryStrc tEntry;
    D2RosterPetStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __cdecl sub_00454740_LoadLoadingPalette(); // 0x00454740
void __fastcall sub_00478A00(void* pCel); // 0x00478A00

void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
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
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
extern unsigned int gnDialogAmount_007A2A68; // 0x007A2A68
void __cdecl sub_00453EE0_ClosePanel(); // 0x00453EE0
void __fastcall sub_004B9110_SendGoldRequest(unsigned long nGold); // 0x004B9110
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004B8100(void* pObj); // 0x004B8100
void __cdecl sub_004A02F0_ToggleListDialogUI(); // 0x004A02F0
void __cdecl sub_004B69E0_CloseTrade(); // 0x004B69E0
extern D2UiControlAStrc* gpGoldControlA_007A27A4; // 0x007A27A4
extern D2UiControlBStrc* gpGoldControlB_007A27A8; // 0x007A27A8
extern D2UiControlCStrc* gpGoldControlC_007A27AC; // 0x007A27AC
extern D2UiControlCStrc* gpGoldControlD_007A27B0; // 0x007A27B0
extern int gbGoldPanelFlag_007A27B4; // 0x007A27B4




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
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __fastcall sub_004AE360_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360
int __fastcall sub_00454880_GetHoverRect(D2RectStrc* pRect); // 0x00454880
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5, int nArg6); // 0x005022F0
int __fastcall sub_00452580_GetHoverMonsterName(D2UnitStrc* pUnit, int nArg); // 0x00452580
void __fastcall sub_00452520_SetHoverLine(const Unicode* pText, int nColor); // 0x00452520
int __fastcall sub_004B3230_GetTickPair(int* pLow); // 0x004B3230
int __cdecl sub_004A0000(); // 0x004A0000
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const D2ImmunityTextStrc gaImmunityTexts_006D6418[6]; // 0x006D6418
extern Unicode gwszText_007A2A78[]; // 0x007A2A78
extern int gnHoverTextState_007A2C78; // 0x007A2C78
extern Unicode gwszHoverName_007A2F38[]; // 0x007A2F38

int gdwGlobal_007A2780; // 0x007A2780

int gdwGlobal_007A2868; // 0x007A2868

int gdwGlobal_007A5210; // 0x007A5210

int gdwGlobal_007A8914; // 0x007A8914

int gdwGlobal_007A891C; // 0x007A891C

// 0x00451910
int __cdecl sub_00451910()
{
    return gdwGlobal_007A277C;
}

// 0x00451960
int __cdecl sub_00451960()
{
    return gdwGlobal_007A2780;
}

// 0x00451980
int __cdecl sub_00451980()
{
    return gdwGlobal_007A2784;
}

// 0x00451990
int __cdecl sub_00451990()
{
    return gdwGlobal_007A2788;
}

// 0x004526C0
static void sub_004526C0_BuildImmunityText(D2UnitStrc* pUnit)
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
            sub_004521C0_PrefixLevelText((Unicode*)wszItem, gaImmunityTexts_006D6418[n].nColor);
            sub_00526700((Unicode*)wszText, (Unicode*)wszItem);
        }
    }
    sub_005267E0(gwszText_007A2A78, (Unicode*)wszText);
    gnHoverTextState_007A2C78 = 4;
}

// 0x00452E50
void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect)
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

// 0x004535D0
void __cdecl sub_004535D0_DrawPartyTexts()
{
    if (sub_0044DB30())
    {
        sub_00464950(sub_00453330_DrawPartyMemberText);
    }
}

// 0x004535F0
static __forceinline void __stdcall sub_004535F0_SetSlotClass(D2SlotOwnerStrc* pOwner, unsigned short wDefault, int nIndex, int nA, int nB)
{
    if (nIndex == -1)
    {
        return;
    }

    int nValue;
    unsigned short wClass;
    if (sub_00469D90(nA, nB) && (wClass = sub_00469AA0(nA, nB)) != 0xFFFF && wClass <= 0xDF)
    {
        nValue = wClass;
    }
    else
    {
        nValue = wDefault;
    }

    pOwner->pSlots[nIndex].nClass = nValue;
}

int gnPanelFlag_007A2864; // 0x007A2864

static __forceinline void SetHotkey(const D2PanelHotkeysStrc* pDesc, int nIndex, int nKeyFunc, int bSecondary, int nDefault)
{
    if (nIndex == -1)
        return;

    if (sub_00469D90(nKeyFunc, bSecondary))
    {
        const unsigned short nKey = sub_00469AA0(nKeyFunc, bSecondary);
        if (nKey != 0xFFFF && nKey <= 0xDF)
        {
            pDesc->f_20[nIndex].nId = nKey;
            return;
        }
    }

    pDesc->f_20[nIndex].nId = nDefault;
}

// 0x00453640
static void sub_00453640_SetPanelHotkeys(const D2PanelHotkeysStrc* pDesc)
{
    SetHotkey(pDesc, pDesc->nIndex16Sec, 0x16, 0x1, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26Sec, 0x26, 0x1, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29Sec, 0x29, 0x1, 0x4E);
    if (sub_00408F20_HasExpansionMpq())
        SetHotkey(pDesc, pDesc->nIndex2CSec, 0x2C, 0x1, 0x57);
    SetHotkey(pDesc, pDesc->nIndex16, 0x16, 0x0, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26, 0x26, 0x0, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29, 0x29, 0x0, 0x4E);
    if (sub_00408F20_HasExpansionMpq())
        SetHotkey(pDesc, pDesc->nIndex2C, 0x2C, 0x0, 0x57);
}

void __fastcall sub_M117_Emit_004535F0(D2SlotOwnerStrc* pOwner, int nIndex, int nA, int nB)
{
    sub_004535F0_SetSlotClass(pOwner, 0x1234, nIndex, nA, nB);
}

// 0x00453900
int __cdecl sub_00453900_IsActive()
{
    return sub_004B85E0() != 0;
}

// 0x00453AA0
int __cdecl sub_00453AA0()
{
    return gdwGlobal_007A2878;
}

// 0x00453AB0
int __cdecl sub_00453AB0()
{
    return gdwGlobal_007A2880;
}

// 0x00453AC0
void __cdecl sub_00453AC0()
{
    gdwGlobal_0070FA9C = 0;
    gdwUIVarTick_007A2790 = 0;
}

// 0x00453AD0
void __cdecl sub_00453AD0()
{
    gdwGlobal_0070FA9C = 1;
}

D2UiControlAStrc* gpGoldControlA_007A27A4; // 0x007A27A4

D2UiControlBStrc* gpGoldControlB_007A27A8; // 0x007A27A8

D2UiControlCStrc* gpGoldControlC_007A27AC; // 0x007A27AC

D2UiControlCStrc* gpGoldControlD_007A27B0; // 0x007A27B0

int gbGoldPanelFlag_007A27B4; // 0x007A27B4

static __forceinline int IsGoldPanelMode(int nMode)
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

// 0x00453EE0
void __cdecl sub_00453EE0_ClosePanel()
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
        sub_004B8020(gpGlobal_007A27A0);
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

// 0x00453FD0
int __cdecl sub_00453FD0()
{
    return 0;
}

unsigned short gwDialogAmountHigh_007A2A6A; // 0x007A2A6A

int gnDialogMode_007A279C; // 0x007A279C

static __forceinline int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00454080
int __cdecl sub_00454080_ConfirmGoldDialog()
{
    sub_00453EE0_ClosePanel();
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

// 0x00454140
int __cdecl sub_00454140_ClosePanelCallback()
{
    sub_00453EE0_ClosePanel();
    return 1;
}

// 0x00454570
void __cdecl sub_00454570_ClearGoldPanel()
{
    gpGlobal_007A27A0 = 0;
    gpGoldControlA_007A27A4 = 0;
    gpGoldControlB_007A27A8 = 0;
    gpGoldControlD_007A27B0 = 0;
    gpGoldControlC_007A27AC = 0;
    gbGoldPanelFlag_007A27B4 = 0;
}

// 0x004545A0
void __cdecl sub_004545A0_ClosePanel()
{
    sub_00453EE0_ClosePanel();
}

// 0x004545B0
void __cdecl sub_004545B0_UpdateGoldPanel()
{
    if (gpGlobal_007A27A0)
        sub_004B8100(gpGlobal_007A27A0);
}

// 0x004547A0
int __cdecl sub_004547A0()
{
    return gdwGlobal_007A288C;
}

// 0x00454840
int __cdecl sub_00454840()
{
    return gdwGlobal_007A2868;
}

// 0x004549B0
void __cdecl sub_004549B0_ToggleListDialog()
{
    sub_004A02F0_ToggleListDialogUI();
    sub_004B69E0_CloseTrade();
}

// 0x00455720
void __fastcall sub_00455720_SetPanelHandlers(int nPanel)
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
        sub_0047B090_InitChatIme();
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
        sub_004A5200(0x1);
        sub_00454980();
        return;
    case 0xC:
        sub_0046AA20(0x2, 0x1);
        sub_00491940_ResetNpcPanel();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D5F88);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F878, 0x8);
        return;
    case 0xF:
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D618C);
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
        sub_0049A640();
        return;
    case 0x17:
        sub_0046AA20(0, 0x1);
        sub_004B8920();
        sub_0048A680();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D6234);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F930, 0xD);
        return;
    case 0x19:
        sub_0046AA20(0x2, 0x1);
        sub_00489E50_LoadStashPanelCels();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D6258);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070F9D0, 0x8);
        return;
    case 0x1A:
        sub_0046AA20(0x2, 0x1);
        sub_0048A4B0_LoadCubePanelCel();
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D627C);
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_0070FA30, 0x7);
        return;
    case 0x18:
        sub_004A0050_OpenListBoxDialog();
        return;
    case 0x1F:
        sub_00453640_SetPanelHotkeys(&gtPanelHotkeys_006D62A0);
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

// 0x00457510
void __stdcall sub_00457510(int nUnused1)
{
}

// 0x00457740
int __cdecl sub_00457740()
{
    return gdwGlobal_007113E0;
}

// 0x00457770
int __cdecl sub_00457770()
{
    return gdwGlobal_007A51E0;
}

// 0x004577B0
int __cdecl sub_004577B0()
{
    return gdwGlobal_007113E4;
}

// 0x004577E0
int __cdecl sub_004577E0()
{
    return gdwGlobal_007113E8;
}

// 0x0045A710
int __cdecl sub_0045A710()
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

// 0x0045AE90
int __cdecl sub_0045AE90()
{
    return gdwGlobal_007A5210;
}

// 0x0045AFA0
int __cdecl sub_0045AFA0()
{
    return gdwGlobal_007A520C;
}

// 0x0045AFB0
int __cdecl sub_0045AFB0()
{
    return gdwGlobal_007A5208;
}

// 0x0045BA70
void __fastcall sub_0045BA70(PairStrc_0045BA70* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0045F7A0
void __stdcall sub_0045F7A0(int nUnused1, int nUnused2)
{
}

// 0x0045FBC0
void __stdcall sub_0045FBC0_DrawCelPair(int bFirst)
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
void __cdecl sub_0045FD80_DrawCenteredString()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_007A2858 + 0x110, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x170, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    sub_00502EF0(nOldFont);
}

// 0x0045FFC0
void __cdecl sub_0045FFC0_DrawCenteredStrings()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xBE - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
    unsigned short nString = 0x1432;
    if (gdwGlobal_007A5238)
        nString = 0x5578;
    sub_004A7080(gnGlobal_0071146C / 2 - 0x84, 0xCD - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1C4, D2LANG_GetStringFromTblIndex(nString), 0);
    sub_00502EF0(nOldFont);
}

// 0x004600F0
void __cdecl sub_004600F0_DrawCenteredStringPair()
{
    const int nOldFont = sub_00502EF0(1);
    sub_004A7080(gnGlobal_007A2858 + 0xCE, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x12E, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    sub_004A7080(gnGlobal_007A2858 + 0x152, 0x136 - gnGlobal_007A285C, gnGlobal_007A2858 + 0x1B2, D2LANG_GetStringFromTblIndex(0x13EF), 0);
    sub_00502EF0(nOldFont);
}

// 0x00460430
void __cdecl sub_00460430_FreeCels()
{
    if (gpGlobal_007A523C)
    {
        sub_00478A00(gpGlobal_007A523C);
        gpGlobal_007A523C = 0;
    }
    if (gpGlobal_007A5244)
    {
        sub_00478A00(gpGlobal_007A5244);
        gpGlobal_007A5244 = 0;
    }
    if (gpGlobal_007A5240)
    {
        sub_00478A00(gpGlobal_007A5240);
        gpGlobal_007A5240 = 0;
    }
    sub_00454740_LoadLoadingPalette();
}

// 0x00463D80
void __fastcall sub_00463D80(void* pArg)
{
    sub_00625960(pArg);
}

// 0x00466DD0
int __cdecl sub_00466DD0()
{
    return gdwGlobal_00711F94;
}

// 0x00467400
int __cdecl sub_00467400()
{
    return gdwGlobal_007A6A94;
}

// 0x00468030
int __cdecl sub_00468030()
{
    return gdwGlobal_007A6AE0;
}

// 0x004680A0
int __cdecl sub_004680A0()
{
    return gdwGlobal_007A6ABC;
}

// 0x00468730
int __cdecl sub_00468730()
{
    return gdwGlobal_007A6AB0;
}

// 0x00468740
int __cdecl sub_00468740()
{
    return gdwGlobal_007A6AAC;
}

// 0x00468830
int __cdecl sub_00468830()
{
    return gdwGlobal_007A6AF0;
}

// 0x0046BC70
int __fastcall sub_0046BC70_SetTimerUnitId(D2UnitStrc* pUnit)
{
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    gnTimerUnitId_007129D4 = nUnitId;
    return nUnitId;
}

// 0x0046F980
int __cdecl sub_0046F980()
{
    return gdwGlobal_007A8914;
}

// 0x0046F990
int __cdecl sub_0046F990()
{
    return gdwGlobal_007A8918;
}

// 0x0046F9A0
int __cdecl sub_0046F9A0()
{
    return gdwGlobal_007A891C;
}

// 0x00476AF0
void __cdecl sub_00476AF0_ClearGlobals()
{
    gnGlobal_007B9534 = 0;
    gnGlobal_007B9538 = 0;
    gnGlobal_007B8D20 = 0;
}

// 0x00478A50
void __cdecl sub_00478A50_FreeRosterPets()
{
    D2RosterPetStrc* pPet = gpRosterPets_007BB5BC;
    while (pPet)
    {
        D2RosterPetStrc* pNext = pPet->pNext;
        FOG_Free(pPet, ".\\GAME\\RosterPets.cpp", 0x2F, 0);
        pPet = pNext;
    }
    gpRosterPets_007BB5BC = 0;
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
        sub_00526700((Unicode*)wszText, sub_00464A60_GetUnitName(pUnit));
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
        if (sub_004AE360_IsUniqueMonster(pUnit))
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
        if (sub_00454880_GetHoverRect(&tRect))
        {
            const int nWidth = sub_00501820((Unicode*)wszText);
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
                if (!sub_00452580_GetHoverMonsterName(pUnit, nTypeString))
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
                        sub_00452520_SetHoverLine(wszLine, nColor);
                    }
                    else if (pRecord->wDescStr != 0x1506)
                    {
                        sub_00452520_SetHoverLine(D2LANG_GetStringFromTblIndex(pRecord->wDescStr), nColor);
                    }
                }
                sub_004526C0_BuildImmunityText(pUnit);
            }
        }
    }
    else
    {
        gwszHoverName_007A2F38[0].wChar = 0;
        if (!sub_004B3230_GetTickPair(&bDead) && !sub_004A0000())
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
            if (pMonStats2Txt)
            {
                gnHoverY_0070F858 -= pMonStats2Txt->nPixHeight;
            }
            D2Win_10129_DrawFramedText(sub_00464A60_GetUnitName(pUnit), gnHoverX_0070F854, gnHoverY_0070F858, 0, 1);
        }
    }
    sub_00502EF0(nOld);
}

#include "gen/data/Source/D2Client/UI/ui.inc"
