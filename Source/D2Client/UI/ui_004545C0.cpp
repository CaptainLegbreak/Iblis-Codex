#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2Structs.h"
#include "D2CelContext.h"

int __cdecl sub_004F59A0();                                                                                // 0x004F59A0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6024[];                                                    // 0x006D6024

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6084[];                                                    // 0x006D6084

extern D2MsgHandlerEntryStrc gtPanelHandlers_006D60C0[];                                                    // 0x006D60C0

int gnPanelState_007A27E8;                                                                                  // 0x007A27E8

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

extern int gaUIVarStates_007A27C0[]; // 0x007A27C0

extern int gnPanelFlag_007A2864; // 0x007A2864

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gnGlobal_00711470; // 0x00711470

extern int gnGlobal_0071146C; // 0x0071146C

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

int __cdecl sub_004A0000(); // 0x004A0000

int __fastcall sub_004B3230_GetTickPair(int* pLow); // 0x004B3230

void __fastcall sub_004B3C20(int nValue); // 0x004B3C20

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

extern unsigned short gwszText_007A2D30[]; // 0x007A2D30

extern unsigned short gwszText_007A2A78[]; // 0x007A2A78

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

int __cdecl sub_0045AE90(); // 0x0045AE90

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
    if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
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
            if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
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

#include "gen/data/Source/D2Client/UI/ui_004545C0.inc"
