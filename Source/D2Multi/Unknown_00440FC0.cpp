#include "D2Multi.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"

struct Unicode;

struct D2LaunchCharInfoStrc;

struct D2LaunchFuncsStrc;

struct D2LaunchGameEntryStrc;

struct D2LaunchGameListStrc;

struct D2LaunchGameRecStrc;

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

int __stdcall sub_0043DBA0_ClearSelection(int nArg1, int nArg2, int nArg3); // 0x0043DBA0

int __stdcall CHATDLG_OnEditChange(void* pMsg); // 0x00440110

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int, int, int)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(void*)); // 0x004FDB00

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80

void* __cdecl GAME_GetChannelName(); // 0x00446CF0

int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

extern D2WinControlInitStrc gtCreateJoinBckgImageInit; // 0x0070D8D0

extern D2WinControlInitStrc gtChannelScreenTitleInit; // 0x0070D900

extern D2WinControlInitStrc gtControlInit_0070D930; // 0x0070D930

extern D2WinControlInitStrc gtControlInit_0070D960; // 0x0070D960

extern D2WinControlInitStrc gtChannelNameEditInit; // 0x0070D990

extern D2WinControlInitStrc gtChannelListInit; // 0x0070D9F0

extern D2WinControlInitStrc gtChannelOkButtonInit; // 0x0070DA20

extern D2WinControlInitStrc gtControlInit_0070E110; // 0x0070E110

extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

extern D2LaunchCharInfoStrc* gpCharInfo; // 0x0077BBD8

extern D2WinControlStrc* gpControl_0077BCEC; // 0x0077BCEC

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" size_t __cdecl strlen(const char* szString);

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140

extern D2WinControlStrc* gpChatTextBox; // 0x0077BD8C

extern char gszLastWhisperer[]; // 0x0077B0D0

int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand); // 0x0043E6E0

struct D2LaunchGameEntryStrc
{
    int nAddress;
    char unk0x04[0x10];
    char szName[1];
};

struct D2LaunchGameListStrc
{
    int nCount;
    char unk0x04[0x0C];
    D2LaunchGameEntryStrc tFirst;
};

const char* __fastcall CHATDLG_SkipString(const char* szText); // 0x00442AE0

int __fastcall CHATDLG_IsCharOverLimit(const char* pChar); // 0x00442B20

D2WinControlStrc* gpCreateJoinBckgImage; // 0x0077BCDC

D2WinControlStrc* gpChannelScreenTitle; // 0x0077BCE0

D2WinControlStrc* gpControl_0077BCE4; // 0x0077BCE4

D2WinControlStrc* gpControl_0077BCE8; // 0x0077BCE8

D2WinControlStrc* gpControl_0077BCF0; // 0x0077BCF0

D2WinControlStrc* gpChannelNameEdit; // 0x0077BCF4

D2WinControlStrc* gpChannelListBox; // 0x0077BCFC

int CHATDLG_ReplyCommand(const char* szText, const char* szCommand); // 0x00442180

#include "gen/data/Source/D2Multi/Unknown_00440FC0.inc"

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// calling-convention shim (not game code)
int __fastcall sub_00442180_Shim(char* szText)
{
// build: symbol ?gszCmdR@* 0x006D56D4
    if (CHATDLG_ReplyCommand(szText, gszCmdR))
        return 1;
// build: symbol ?gszCmdReply@* 0x006D56CC
    if (CHATDLG_ReplyCommand(szText, gszCmdReply))
        return 1;
    return 0;
}

// build: context sub_004438E0_HasProgress
static inline int sub_004438E0_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

// 0x004438E0
int __fastcall sub_004438E0_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord)
{
    int nFilterA = 0;
    int nFilterB = 0;
    if ((*(unsigned short*)gpCharInfo->wFlags) & 4)
    {
        nFilterA = 4;
        nFilterB = 4;
    }
    if ((*(unsigned short*)gpCharInfo->wFlags) & 0x20)
    {
        nFilterA |= 8;
        nFilterB |= 8;
    }
    if (!sub_004438E0_HasProgress(*(unsigned short*)gpCharInfo->wFlags, 0x800, 0xA00))
    {
        if (sub_004438E0_HasProgress(*(unsigned short*)gpCharInfo->wFlags, 0x400, 0x500))
            nFilterB |= 2;
        else
            nFilterB |= 3;
    }

    const char* p = (const char*)gpLaunchFuncs->pfQueryGames(szName, szPassword, nFilterA, nFilterB);
    if (p)
    {
        const int nCount = *(const int*)p;
        if (nCount >= 1)
        {
            p += 0x10;
            *(unsigned short*)pRecord->wValue0x33 = 1;
            *(int*)pRecord->nAddress0x37 = *(const int*)p;
            p += 0x14;
            strcpy(pRecord->szName, p);
            p = CHATDLG_SkipString(p);
            p = CHATDLG_SkipString(p);
            if (!CHATDLG_IsCharOverLimit(p))
            {
                strcpy(pRecord->szDesc, p);
                CHATDLG_SkipString(p);
                return nCount;
            }
        }
    }

    return 0;
}
