#include "D2Multi.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"

extern int gnChatLaunchMode; // 0x0077BBE4


#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinTextBoxStrc;

struct Unicode;

struct D2LaunchCharInfoStrc;

struct D2GameListRecordStrc;

struct D2LaunchFuncsStrc;

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

extern D2WinControlInitStrc gtHelpBckgImageInit; // 0x0070E9E0

extern D2WinControlInitStrc gtControlInit_0070EA10; // 0x0070EA10

extern D2WinControlInitStrc gtControlInit_0070EA40; // 0x0070EA40

extern D2WinControlInitStrc gtControlInit_0070EA70; // 0x0070EA70

extern D2WinControlStrc* gpCreateScreenButton; // 0x0077B070

extern D2WinControlStrc* gpChatControl_0077B074; // 0x0077B074

extern D2WinControlStrc* gpJoinScreenButton; // 0x0077B078

extern D2WinControlStrc* gpControlC_0077B07C; // 0x0077B07C

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

#pragma pack(push, 1)

struct D2GameListRecordStrc
{
    char szName[0x10];
    char szDesc[0x22];
    unsigned short wType;
    char unk0x34[2];
    unsigned int f_36;
    char unk0x3A;
};

#pragma pack(pop)

extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

extern D2LaunchCharInfoStrc* gpCharInfo; // 0x0077BBD8

extern D2GameListRecordStrc gtGameList_0077BDC9[]; // 0x0077BDC9

int __fastcall CHATDLG_IsCharOverLimit(const char* szText); // 0x00442B20

void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FB9D0

int __stdcall sub_00443540_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x00443540

void __cdecl sub_00443630_UpdateCreateButton(); // 0x00443630

void __cdecl COMCALLBACK_BuildCreateGamePanel(); // 0x004453B0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

extern D2WinControlStrc* gpLevelDiffLabel; // 0x00798C04

extern D2WinControlStrc* gpControl_00798C08; // 0x00798C08

extern D2WinControlStrc* gpLevelDiffUpButton; // 0x00798C1C

extern D2WinControlStrc* gpLevelDiffDownButton; // 0x00798C20

extern D2WinControlStrc* gpLevelDiffGreyArrows; // 0x00798C24

extern D2WinControlStrc* gpLevelDiffEdit; // 0x00798C3C

extern D2WinControlStrc* gpLevelDiffCheck; // 0x00798C40

extern D2WinControlStrc* gpLevelDiffBoxImage; // 0x00798C44

D2WinControlStrc* gpControl_00798CB0; // 0x00798CB0

D2WinControlStrc* gpControl_00798CB4; // 0x00798CB4

D2WinControlStrc* gpControl_00798CB8; // 0x00798CB8

D2WinControlStrc* gpHelpBckgImage; // 0x00798CBC

int gnValue_00798CC0; // 0x00798CC0

// 0x00444020
int __cdecl sub_00444020_CreateControls()
{
// build: symbol ?CHARSEL_ResetLaunchState@* 0x0043F8C0
    CHARSEL_ResetLaunchState();
// build: symbol ?GAME_IsLaunchExpansion@* 0x0043DB10
    int bExpansion = GAME_IsLaunchExpansion();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gpHelpBckgImage = CONTROL_Create(&gtHelpBckgImageInit);
    gpControl_00798CB0 = CONTROL_Create(&gtControlInit_0070EA10);
    D2Win_10044(gpControl_00798CB0, D2LANG_GetStringFromTblIndex(bExpansion ? 0x14BC : 0x2AE));
    gpControl_00798CB4 = CONTROL_Create(&gtControlInit_0070EA40);
    if (!bExpansion)
    {
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2AF));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B0));
// build: symbol ?gszSpace@* 0x006FFC44
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B1));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B2));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B3));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B4));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B5));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B6));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B7));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B8));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B34));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B9));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BA));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BB));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B35));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BD));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
    }
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BE));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BF));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C0));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C1));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C2));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C3));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C4));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C5));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C6));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C7));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C8));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C9));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CA));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CB));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CC));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CD));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CE));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CF));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D0));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D1));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D2));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x276C));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x276D));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D3));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    if (!bExpansion)
    {
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D4));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B26));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B27));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B28));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2714));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2715));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DA));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B21));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B22));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DB));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DC));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2716));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2717));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DF));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2718));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2719));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E2));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E3));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E4));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E5));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E6));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E7));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E8));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E9));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EA));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271A));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EC));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2ED));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EE));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271B));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F0));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271C));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F2));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F3));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F4));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271D));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271E));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F7));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F8));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F9));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FA));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FB));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FC));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FD));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FE));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FF));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x300));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x301));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271F));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x303));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x304));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x305));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x306));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x307));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B23));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x309));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30A));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30B));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30C));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30D));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30E));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30F));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x310));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x311));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x312));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x313));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    }
    gpControl_00798CB8 = CONTROL_Create(&gtControlInit_0070EA70);
    sub_004FA450_SetActive(gpControl_00798CB8);
    gnValue_00798CC0 = 1;
    D2Win_10053(gpControl_00798CB4, 0);
    return 1;
}

#include "gen/data/Source/D2Multi/Unknown_00444020.inc"

int gnGameCount; // 0x00798CCC

static inline int sub_00444E70_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

static inline char* sub_00444E70_NextString(char* p)
{
    D2_ASSERT(p, 0xAD);
    while (*p)
        ++p;
    return p + 1;
}

// 0x00444E70
void __cdecl sub_00444E70_FillGameList()
{
    int nFlags = 0;
    int nDifficulties = 0;
    if ((*(unsigned short*)gpCharInfo->wFlags) & 4)
    {
        nFlags = 4;
        nDifficulties = 4;
    }
    if ((*(unsigned short*)gpCharInfo->wFlags) & 0x20)
    {
        nFlags |= 8;
        nDifficulties |= 8;
    }
    if (!sub_00444E70_HasProgress(*(unsigned short*)gpCharInfo->wFlags, 0x800, 0xA00))
    {
        if (sub_00444E70_HasProgress(*(unsigned short*)gpCharInfo->wFlags, 0x400, 0x500))
            nDifficulties |= 2;
        else
            nDifficulties |= 3;
    }

    char* p = (char*)gpLaunchFuncs->pfQueryGames(0, 0, nFlags, nDifficulties);
    if (p)
    {
        gnGameCount = *(int*)p;
        p += 4;
        int i = 0;
        while (i < gnGameCount)
        {
            p += 0xC;
            gtGameList_0077BDC9[i].wType = 1;
            gtGameList_0077BDC9[i].f_36 = *(unsigned int*)p;
            p += 0x14;
            strcpy(gtGameList_0077BDC9[i].szName, p);
// build: symbol ?gpGameList@* 0x00798BC0
            if (gpGameList)
                sub_004FCF80_SetTextA(gpGameList, p);
            p = sub_00444E70_NextString(p);
            p = sub_00444E70_NextString(p);
            if (CHATDLG_IsCharOverLimit(p))
            {
                --gnGameCount;
            }
            else
            {
                strcpy(gtGameList_0077BDC9[i].szDesc, p + 1);
                ++i;
            }
            p = sub_00444E70_NextString(p);
        }
    }

// build: symbol ?CHARSEL_FillGameListControl@* 0x00442C20
    CHARSEL_FillGameListControl();
}

struct D2LaunchRequestStrc
{
    int nData[5];
    unsigned int dwFlags;
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall WINMAIN_SendMcpGameListRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId); // 0x0044A590
extern unsigned short gwRequestId; // 0x0070CD60
extern unsigned short gwSavedRequestId; // 0x0077BBDC

// 0x00445020
void __cdecl CHARSEL_RequestGameList()
{
// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
    gnChatLaunchMode = 3;
    gnValue_00798CCC = 0;
// build: symbol ?gpCharInfo@* 0x0077BBD8
    if (gpCharInfo->nType0x35E == 2)
    {
        D2LaunchRequestStrc tRequest;
        memset(&tRequest, 0, sizeof(tRequest));
        if (gpCharInfo->wFlags[0] & 4)
            tRequest.dwFlags |= 0x800;
        while (++gwRequestId == 0)
        {
        }
        WINMAIN_SendMcpGameListRequest(&tRequest, gwRequestId);
        gwSavedRequestId = gwRequestId;
    }
    else
    {
        sub_00444E70_FillGameList();
    }
}

// 0x004450A0
int __stdcall sub_004450A0_JoinNameKey(D2WinControlStrc* pControl, int nArg, const char* pChar)
{
    D2Win_10050_TEXTBOX_SetLine((D2WinTextBoxStrc*)gpGameList, -1);
    return sub_00443540_IsNameChar(pControl, nArg, pChar);
}

// 0x004450C0
int __stdcall sub_004450C0_JoinNameEnter(int nArg)
{
// build: symbol ?CHARSEL_UpdateJoinButtonState@* 0x004437E0
    CHARSEL_UpdateJoinButtonState();
    return 1;
}

// 0x00445530
int __stdcall sub_00445530_ResetBuildPanel(int nArg)
{
    CHARSEL_ResetLaunchState();
    COMCALLBACK_BuildCreateGamePanel();
    return 1;
}

// 0x004456A0
int __stdcall sub_004456A0_OnEnter(int nArg)
{
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x004456B0
int __stdcall sub_004456B0_OnEnter(int nArg)
{
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x004456C0
int __stdcall sub_004456C0_OnEnter(int nArg)
{
    sub_00443630_UpdateCreateButton();
    return 1;
}

// 0x004451C0
void __cdecl sub_004451C0_UpdateLevelControls()
{
    if (sub_00500960_IsPressed(gpLevelDiffCheck))
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 0);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 0);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 1);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 1);
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpLevelDiffEdit, 1);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 1);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 1);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 4, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 4, 0, 0);
    }
    else
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 1);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 0);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 0);
        CONTROL_SetEnabled(gpLevelDiffEdit, 0);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 0);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 0);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
    }
    sub_00443630_UpdateCreateButton();
}
