#include "D2Multi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ModuleInterfaceStrc;
struct D2CelFileStrc;
struct D2WinMsgStrc;
struct SMSGHANDLER_PARAMS;

extern D2ModuleInterfaceStrc gtInterface; // 0x0070CD14
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00
void* __cdecl sub_0044DA90(); // 0x0044DA90
void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMsg;
    unsigned int wParam;
    int lParam;
};

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

void __fastcall CHATDLG_UpdateScroll(int nDelta); // 0x00448BD0
void __cdecl COMCALLBACK_RefreshChatButtons(); // 0x004477A0
int __cdecl GAME_GetWaitHandle(); // 0x00449AC0
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
int __cdecl sub_00449C30(); // 0x00449C30
void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlStrc* gpChannelListBox; // 0x0077BCFC

void* gpInstance; // 0x0077AD68

// 0x0043CBE0
D2ModuleInterfaceStrc* __fastcall sub_0043CBE0_Init(void* hInstance)
{
    gpInstance = hInstance;
    return &gtInterface;
}

#include "gen/data/Source/D2Multi/Unknown_0043CBE0.inc"
#include "D2StormTypes.h"

// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x0042B9D0
void __cdecl sub_0042B9D0_Nop()
{
}

// 0x00650EA0
void __cdecl sub_00650EA0_Nop()
{
}

// 0x0043CC00
const char* __fastcall sub_0043CC00_StrChr(const char* szString, char nChar, int bReverse)
{
    if (bReverse)
        return SStrChrR(szString, nChar);
    return SStrChr(szString, nChar);
}

// 0x0043CC20
int __fastcall sub_0043CC20_TestBit2(int nValue)
{
    return nValue & 4;
}

D2CelFileStrc* gpChatBackground; // 0x0077BC04

D2CelFileStrc* gpWaitingRoomBkgdCelFile; // 0x0077BC08

D2CelFileStrc* gpPopUpLargest2CelFile; // 0x0077BC0C

D2CelFileStrc* gpMediumButtonBlank2CelFile; // 0x0077BC10

D2CelFileStrc* gpBnetCursorOHandCelFile; // 0x0077BC14

D2CelFileStrc* gpCursorLRotateCelFile; // 0x0077BC18

D2CelFileStrc* gpScrollBarCelFile; // 0x0077BC1C

D2CelFileStrc* gpBnetJoinGameScrollBarsCelFile; // 0x0077BC20

D2CelFileStrc* gpCellFile_0077BC24; // 0x0077BC24

D2CelFileStrc* gpChatLeftButtonsCelFile; // 0x0077BC28

D2CelFileStrc* gpChatLeftButtons1CelFile; // 0x0077BC2C

D2CelFileStrc* gpChatLeftButtons2CelFile; // 0x0077BC30

D2CelFileStrc* gpChatRightButtonsCelFile; // 0x0077BC34

D2CelFileStrc* gpChatRightTopButtonsCelFile; // 0x0077BC38

D2CelFileStrc* gpChatArrowsCelFile; // 0x0077BC3C

D2CelFileStrc* gpJoinGameBckgCelFile; // 0x0077BC50

D2CelFileStrc* gpBlankBckg2CelFile; // 0x0077BC54

D2CelFileStrc* gpGemButtonCelFile; // 0x0077BC58

D2CelFileStrc* gpGameButtonBlankCelFile; // 0x0077BC5C

D2CelFileStrc* gpJoinGameClickBoxCelFile; // 0x0077BC60

D2CelFileStrc* gpGreyLevelBoxCelFile; // 0x0077BC64

D2CelFileStrc* gpRadioButtonCelFile; // 0x0077BC68

D2CelFileStrc* gpRadioButtonGreyCelFile; // 0x0077BC6C

D2CelFileStrc* gpBnetPopUpOkCelFile; // 0x0077BC70

D2CelFileStrc* gpBnetCancelButtonBlankCelFileA; // 0x0077BC74

D2CelFileStrc* gpOverallTabCelFile; // 0x0077BC78

D2CelFileStrc* gpAmazonTabCelFile; // 0x0077BC7C

D2CelFileStrc* gpSorceressTabCelFile; // 0x0077BC80

D2CelFileStrc* gpNecromancerTabCelFile; // 0x0077BC84

D2CelFileStrc* gpPaladinTabCelFile; // 0x0077BC88

D2CelFileStrc* gpBarbarianTabCelFile; // 0x0077BC8C

D2CelFileStrc* gpDruidTabCelFile; // 0x0077BC90

D2CelFileStrc* gpAssassinTabCelFile; // 0x0077BC94

D2CelFileStrc* gpSquelchAuraCelFile; // 0x0077BCB8

D2CelFileStrc* gpSelectAuraCelFile; // 0x0077BCBC

D2CelFileStrc* gpNumberArrowsCelFileA; // 0x0077BCC0

D2CelFileStrc* gpNumberArrowsCelFileB; // 0x0077BCC4

D2CelFileStrc* gpNumberArrowsCelFileC; // 0x0077BCC8

D2CelFileStrc* gpNumberArrowsCelFileD; // 0x0077BCCC

D2CelFileStrc* gpNumberGreyArrowsCelFile; // 0x0077BCD0

D2CelFileStrc* gpCreateJoinBckgCelFile; // 0x0077BCD4

D2CelFileStrc* gpOkayButtonCelFile; // 0x0077BCD8

D2CelFileStrc* gpCreateGameBckgCelFile; // 0x0077BD0C

D2CelFileStrc* gpCreateGameButtonCelFile; // 0x0077BD10

D2CelFileStrc* gpBnetWideButtonBlankCelFile; // 0x0077BD18

D2CelFileStrc* gpBnetCancelButtonBlankCelFileB; // 0x0077BD2C

D2CelFileStrc* gpYesNoButtonBlankCelFile; // 0x0077BD30

D2CelFileStrc* gpLadderChoiceExpCelFile; // 0x0077BD34

D2CelFileStrc* gpHardcoreLadderBckgCelFile; // 0x0077BD38

D2CelFileStrc* gpPlayerProfileBckgCelFileA; // 0x0077BD3C

D2CelFileStrc* gpPlayerProfileBckgCelFileB; // 0x0077BD40

D2CelFileStrc* gpHelpBckgCelFile; // 0x0077BD44

D2CelFileStrc* gpD2LogoBlackBnetCelFile; // 0x0077BD48

D2CelFileStrc* gpD2LogoBnetCelFile; // 0x0077BD4C

// 0x0043D510
void __cdecl sub_0043D510_FreeCellFiles()
{
    if (gpPopUpLargest2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPopUpLargest2CelFile);
        gpPopUpLargest2CelFile = 0;
    }

    if (gpMediumButtonBlank2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpMediumButtonBlank2CelFile);
        gpMediumButtonBlank2CelFile = 0;
    }

    if (gpChatBackground)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatBackground);
        gpChatBackground = 0;
    }

    if (gpWaitingRoomBkgdCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpWaitingRoomBkgdCelFile);
        gpWaitingRoomBkgdCelFile = 0;
    }

    if (gpBnetCursorOHandCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetCursorOHandCelFile);
        gpBnetCursorOHandCelFile = 0;
    }

    if (gpCursorLRotateCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCursorLRotateCelFile);
        gpCursorLRotateCelFile = 0;
    }

    if (gpScrollBarCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpScrollBarCelFile);
        gpScrollBarCelFile = 0;
    }

    if (gpBnetJoinGameScrollBarsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetJoinGameScrollBarsCelFile);
        gpBnetJoinGameScrollBarsCelFile = 0;
    }

    if (gpChatLeftButtonsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatLeftButtonsCelFile);
        gpChatLeftButtonsCelFile = 0;
    }

    if (gpChatLeftButtons1CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatLeftButtons1CelFile);
        gpChatLeftButtons1CelFile = 0;
    }

    if (gpChatLeftButtons2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatLeftButtons2CelFile);
        gpChatLeftButtons2CelFile = 0;
    }

    if (gpChatRightButtonsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatRightButtonsCelFile);
        gpChatRightButtonsCelFile = 0;
    }

    if (gpChatRightTopButtonsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatRightTopButtonsCelFile);
        gpChatRightTopButtonsCelFile = 0;
    }

    if (gpChatArrowsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatArrowsCelFile);
        gpChatArrowsCelFile = 0;
    }

    if (gpJoinGameBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpJoinGameBckgCelFile);
        gpJoinGameBckgCelFile = 0;
    }

    if (gpGameButtonBlankCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpGameButtonBlankCelFile);
        gpGameButtonBlankCelFile = 0;
    }

    if (gpJoinGameClickBoxCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpJoinGameClickBoxCelFile);
        gpJoinGameClickBoxCelFile = 0;
    }

    if (gpNumberArrowsCelFileA)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileA);
        gpNumberArrowsCelFileA = 0;
    }

    if (gpNumberArrowsCelFileB)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileB);
        gpNumberArrowsCelFileB = 0;
    }

    if (gpNumberArrowsCelFileC)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileC);
        gpNumberArrowsCelFileC = 0;
    }

    if (gpNumberArrowsCelFileD)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileD);
        gpNumberArrowsCelFileD = 0;
    }

    if (gpNumberGreyArrowsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberGreyArrowsCelFile);
        gpNumberGreyArrowsCelFile = 0;
    }

    if (gpGreyLevelBoxCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpGreyLevelBoxCelFile);
        gpGreyLevelBoxCelFile = 0;
    }

    if (gpCreateJoinBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCreateJoinBckgCelFile);
        gpCreateJoinBckgCelFile = 0;
    }

    if (gpOkayButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpOkayButtonCelFile);
        gpOkayButtonCelFile = 0;
    }

    if (gpCreateGameBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCreateGameBckgCelFile);
        gpCreateGameBckgCelFile = 0;
    }

    if (gpCreateGameButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCreateGameButtonCelFile);
        gpCreateGameButtonCelFile = 0;
    }

    if (gpCellFile_0077BC24)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC24);
        gpCellFile_0077BC24 = 0;
    }

    if (gpBnetWideButtonBlankCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetWideButtonBlankCelFile);
        gpBnetWideButtonBlankCelFile = 0;
    }

    if (gpBnetCancelButtonBlankCelFileB)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetCancelButtonBlankCelFileB);
        gpBnetCancelButtonBlankCelFileB = 0;
    }

    if (gpYesNoButtonBlankCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpYesNoButtonBlankCelFile);
        gpYesNoButtonBlankCelFile = 0;
    }

    if (gpD2LogoBlackBnetCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpD2LogoBlackBnetCelFile);
        gpD2LogoBlackBnetCelFile = 0;
    }

    if (gpD2LogoBnetCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpD2LogoBnetCelFile);
        gpD2LogoBnetCelFile = 0;
    }

    if (gpBlankBckg2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBlankBckg2CelFile);
        gpBlankBckg2CelFile = 0;
    }

    if (gpGemButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpGemButtonCelFile);
        gpGemButtonCelFile = 0;
    }

    if (gpLadderChoiceExpCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpLadderChoiceExpCelFile);
        gpLadderChoiceExpCelFile = 0;
    }

    if (gpHardcoreLadderBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpHardcoreLadderBckgCelFile);
        gpHardcoreLadderBckgCelFile = 0;
    }

    if (gpPlayerProfileBckgCelFileA)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPlayerProfileBckgCelFileA);
        gpPlayerProfileBckgCelFileA = 0;
    }

    if (gpHelpBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpHelpBckgCelFile);
        gpHelpBckgCelFile = 0;
    }

    if (gpPlayerProfileBckgCelFileB)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPlayerProfileBckgCelFileB);
        gpPlayerProfileBckgCelFileB = 0;
    }

    if (gpRadioButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpRadioButtonCelFile);
        gpRadioButtonCelFile = 0;
    }

    if (gpRadioButtonGreyCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpRadioButtonGreyCelFile);
        gpRadioButtonCelFile = 0;
    }

    if (gpBnetPopUpOkCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetPopUpOkCelFile);
        gpBnetPopUpOkCelFile = 0;
    }

    if (gpBnetCancelButtonBlankCelFileA)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetCancelButtonBlankCelFileA);
        gpBnetCancelButtonBlankCelFileA = 0;
    }

    if (gpOverallTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpOverallTabCelFile);
        gpOverallTabCelFile = 0;
    }

    if (gpAmazonTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpAmazonTabCelFile);
        gpAmazonTabCelFile = 0;
    }

    if (gpSorceressTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpSorceressTabCelFile);
        gpSorceressTabCelFile = 0;
    }

    if (gpNecromancerTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNecromancerTabCelFile);
        gpNecromancerTabCelFile = 0;
    }

    if (gpPaladinTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPaladinTabCelFile);
        gpPaladinTabCelFile = 0;
    }

    if (gpBarbarianTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBarbarianTabCelFile);
        gpBarbarianTabCelFile = 0;
    }

    if (gpDruidTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpDruidTabCelFile);
        gpDruidTabCelFile = 0;
    }

    if (gpAssassinTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpAssassinTabCelFile);
        gpAssassinTabCelFile = 0;
    }

    if (gpSquelchAuraCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpSquelchAuraCelFile);
        gpSquelchAuraCelFile = 0;
    }

    if (gpSelectAuraCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpSelectAuraCelFile);
        gpSelectAuraCelFile = 0;
    }
}

int gnFlag_0077BD60; // 0x0077BD60

// 0x0043DA00
int __stdcall sub_0043DA00_ScrollPageDown(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(10);
    return 1;
}

// 0x0043DA20
int __stdcall sub_0043DA20_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(-1);
    return 1;
}

// 0x0043DBA0
int __stdcall sub_0043DBA0_ClearSelection(int nArg1, int nArg2, int nArg3)
{
    sub_004FB9D0_Select(gpChannelListBox, -1);
    return 1;
}

// 0x0043DBC0
int __stdcall sub_0043DBC0_OnWaitTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (!WaitForSingleObject((void*)GAME_GetWaitHandle(), 0) || gnFlag_0077BD60)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x0043DBF0
int __stdcall sub_0043DBF0_OnReceiveTick(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00449B70_Receive();
    if (sub_00449C30() || !sub_00449B30_QueryAddress() || gnFlag_0077BD60)
    {
        CHATDLG_SetCharLogonReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}
