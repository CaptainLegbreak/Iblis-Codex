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
void* __cdecl sub_00446CF0(); // 0x00446CF0
int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0
extern D2WinControlInitStrc gtControlInit_0070D8D0; // 0x0070D8D0
extern D2WinControlInitStrc gtControlInit_0070D900; // 0x0070D900
extern D2WinControlInitStrc gtControlInit_0070D930; // 0x0070D930
extern D2WinControlInitStrc gtControlInit_0070D960; // 0x0070D960
extern D2WinControlInitStrc gtControlInit_0070D990; // 0x0070D990
extern D2WinControlInitStrc gtControlInit_0070D9F0; // 0x0070D9F0
extern D2WinControlInitStrc gtControlInit_0070DA20; // 0x0070DA20
extern D2WinControlInitStrc gtControlInit_0070E110; // 0x0070E110
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern D2WinControlStrc* gpControl_0077BCEC; // 0x0077BCEC
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" size_t __cdecl strlen(const char* szString);
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
extern D2WinControlStrc* gpChatTextBox_0077BD8C; // 0x0077BD8C
extern char gszLastWhisperer_0077B0D0[]; // 0x0077B0D0
static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand); // 0x0043E6E0

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

D2WinControlStrc* gpControl_0077BCDC; // 0x0077BCDC

D2WinControlStrc* gpControl_0077BCE0; // 0x0077BCE0

D2WinControlStrc* gpControl_0077BCE4; // 0x0077BCE4

D2WinControlStrc* gpControl_0077BCE8; // 0x0077BCE8

D2WinControlStrc* gpControl_0077BCF0; // 0x0077BCF0

D2WinControlStrc* gpEditBox_0077BCF4; // 0x0077BCF4

D2WinControlStrc* gpControl_0077BCFC; // 0x0077BCFC

int CHATDLG_ReplyCommand(const char* szText, const char* szCommand); // 0x00442180

// 0x00440FC0
void __cdecl sub_00440FC0_CreateGatewayControls()
{
    gpControl_0077BCDC = CONTROL_Create(&gtControlInit_0070D8D0);

    gpControl_0077BCE0 = CONTROL_Create(&gtControlInit_0070D900);
    D2Win_10044(gpControl_0077BCE0, D2LANG_GetStringFromTblIndex(0x148D));

    gpControl_0077BCE4 = CONTROL_Create(&gtControlInit_0070D930);
    D2Win_10044(gpControl_0077BCE4, D2LANG_GetStringFromTblIndex(0x148E));

    gpControl_0077BCE8 = CONTROL_Create(&gtControlInit_0070D960);
    D2Win_10044(gpControl_0077BCE8, D2LANG_GetStringFromTblIndex(0x148F));

    gpControl_0077BCEC = CONTROL_Create(&gtControlInit_0070DA20);

    gpControl_0077BCF0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_0077BCF0);

    gpEditBox_0077BCF4 = CONTROL_Create(&gtControlInit_0070D990);
    sub_004FDD50_SetMaxLength(gpEditBox_0077BCF4, 0x20);
    sub_004FDAD0_SetKeyCallback(gpEditBox_0077BCF4, sub_0043DBA0_ClearSelection);
    sub_004FDB00_SetEnterCallback(gpEditBox_0077BCF4, CHATDLG_OnEditChange);

    gpControl_0077BCFC = CONTROL_Create(&gtControlInit_0070D9F0);

    const char* szList = gpLaunchFuncs_0077B09C->pfn0x20(gpCharInfo_0077BBD8->wFlags[0] & 0x20);

    if (gpCharInfo_0077BBD8->szRealm0x381[0])
    {
        D2Win_10045(gpControl_0077BCFC, gpCharInfo_0077BBD8->szRealm0x381);
    }

    if (gpCharInfo_0077BBD8->szRealm0x361[0] && strcmp(gpCharInfo_0077BBD8->szRealm0x381, gpCharInfo_0077BBD8->szRealm0x361))
    {
        D2Win_10045(gpControl_0077BCFC, gpCharInfo_0077BBD8->szRealm0x361);
    }

    while (*szList)
    {
        if (!gpCharInfo_0077BBD8->szRealm0x361[0] || strcmp(szList, gpCharInfo_0077BBD8->szRealm0x361))
        {
            D2Win_10045(gpControl_0077BCFC, szList);
        }

        while (*szList)
        {
            ++szList;
        }
        ++szList;
    }

    sub_004FFE10_SetTextA(gpEditBox_0077BCF4, (const char*)sub_00446CF0());
    CONTROL_SetFocusedEditBox(gpEditBox_0077BCF4);
    D2Win_10082(gpEditBox_0077BCF4);
    D2Win_10053(gpControl_0077BCFC, 0);
// build: symbol ?CHARSEL_UpdateOkEnabled@* 0x0043E660
    CHARSEL_UpdateOkEnabled();
}

#include "gen/data/Source/D2Multi/Unknown_00440FC0.inc"

// 0x0043E6E0
static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand)
{
    if (strlen(szText) < strlen(szCommand))
        return -1;

    unsigned int nLength = strlen(szCommand);
    while (nLength--)
    {
        const int nDiff = toupper(*szText) - toupper(*szCommand);
        if (nDiff)
            return nDiff > 0 ? 1 : -1;
        ++szText;
        ++szCommand;
    }
    return 0;
}

// build: context CONSOLE_FindSecondTokenInline
static __forceinline int CONSOLE_FindSecondTokenInline(const char* szText, char* szCopy, const char** ppArg)
{
    strcpy(szCopy, szText);
    char szDelim[2] = " ";
    char* pToken = strtok(szCopy, szDelim);
    int nCount = 0;
    while (pToken)
    {
        if (++nCount == 2)
        {
            *ppArg = szText + (pToken - szCopy);
            return 1;
        }
        pToken = strtok(0, szDelim);
    }
    return 0;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// calling-convention shim (not game code)
int __fastcall sub_00442180_Shim(char* szText)
{
    if (CHATDLG_ReplyCommand(szText, gszCmdR_006D56D4))
        return 1;
    if (CHATDLG_ReplyCommand(szText, gszCmdReply_006D56CC))
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
    if ((*(unsigned short*)gpCharInfo_0077BBD8->wFlags) & 4)
    {
        nFilterA = 4;
        nFilterB = 4;
    }
    if ((*(unsigned short*)gpCharInfo_0077BBD8->wFlags) & 0x20)
    {
        nFilterA |= 8;
        nFilterB |= 8;
    }
    if (!sub_004438E0_HasProgress(*(unsigned short*)gpCharInfo_0077BBD8->wFlags, 0x800, 0xA00))
    {
        if (sub_004438E0_HasProgress(*(unsigned short*)gpCharInfo_0077BBD8->wFlags, 0x400, 0x500))
            nFilterB |= 2;
        else
            nFilterB |= 3;
    }

    const char* p = (const char*)gpLaunchFuncs_0077B09C->pfQueryGames(szName, szPassword, nFilterA, nFilterB);
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
