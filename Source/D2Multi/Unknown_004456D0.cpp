#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"

struct D2LaunchResultStrc
{
    int nResult;
};

struct D2LaunchLoginStrc
{
    char szText0x00[0x10];
    char szText0x10[0x10];
    char szText0x20[0x20];
    unsigned int nValue0x40;
    char nValue0x44;
    unsigned char nValue0x45;
    char nValue0x46;
};

extern "C" int __cdecl atoi(const char* szString);
extern "C" size_t __cdecl strlen(const char* szString);

const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __fastcall sub_0043FE40_SetupLogin(D2LaunchLoginStrc* pLogin, const char* szText0x37); // 0x0043FE40
void __fastcall sub_004401C0_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0
void __cdecl sub_00443220_DestroyControls(); // 0x00443220
int __stdcall sub_00443840_CallTable8C(int nUnused); // 0x00443840
int __stdcall sub_00443870_SetCancel(int nArg); // 0x00443870
int __stdcall sub_00443880_PollMcp(int nArg); // 0x00443880
void __cdecl sub_004453B0_BuildPanel(); // 0x004453B0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
extern "C" const char gszMaxPlayer_006D57C0[]; // 0x006D57C0
extern "C" const char gszLvlRest_006D57CC[]; // 0x006D57CC
extern "C" const char gszDiffLevel_006D57DC[]; // 0x006D57DC
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8
extern D2WinControlStrc* gpCreateButton_00798C28; // 0x00798C28
extern D2WinControlStrc* gpCreateName_00798C2C; // 0x00798C2C
extern D2WinControlStrc* gpCreatePassword_00798C30; // 0x00798C30
extern D2WinControlStrc* gpCreateDesc_00798C34; // 0x00798C34
extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C
extern D2WinControlStrc* gpButton_00798C40; // 0x00798C40
extern int gdwGlobal_00798CC4; // 0x00798CC4
extern int gnDiffSelect_00798CD0; // 0x00798CD0

// 0x004456D0
int __stdcall sub_004456D0_SubmitCreateGame(int nArg)
{
    char szName[0x100];
    D2LaunchLoginStrc tLogin;
    char szNumber[8];
    char szDesc[0x200];
    const Unicode* pName;
    const Unicode* pPassword;
    const Unicode* pDesc;

    if (!sub_004F9710_TestFlag(gpCreateButton_00798C28))
        return 0;

    pName = sub_004FDD90_GetEditText(gpCreateName_00798C2C);
    if (pName)
    {
        sub_00526F70(szName, pName, 0xFF);
        if (strlen(szName) < 1)
            return 0;

        pPassword = sub_004FDD90_GetEditText(gpCreatePassword_00798C30);
        pDesc = sub_004FDD90_GetEditText(gpCreateDesc_00798C34);
        if (sub_00449B30_QueryAddress())
        {
            const Unicode* pMaxPlayers = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
            tLogin.nValue0x44 = 1;
            if (sub_00500960_IsPressed(gpButton_00798C40))
            {
                const Unicode* pLevel = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
                sub_00526F70(szNumber, pLevel, 3);
                tLogin.nValue0x45 = atoi(szNumber);
            }
            else
            {
                tLogin.nValue0x45 = -1;
            }
            sub_00526F70(szNumber, pMaxPlayers, 3);
            tLogin.nValue0x46 = atoi(szNumber);
        }

        sub_00526F70(tLogin.szText0x00, pName, 0x10);
        sub_00526F70(tLogin.szText0x10, pPassword, 0x10);
        sub_00526F70(tLogin.szText0x20, pDesc, 0x20);
        tLogin.nValue0x40 = 0;
        sub_00411320_CapitalizeWords(tLogin.szText0x00);
        sub_00411320_CapitalizeWords(tLogin.szText0x10);
        tLogin.nValue0x40 = tLogin.nValue0x40 & 0xFFFF8FFF | (gnDiffSelect_00798CD0 << 12);

        if (strlen(tLogin.szText0x00) < 1)
            return 0;

        if (!sub_00449B30_QueryAddress())
        {
            int bExpansion = (*(unsigned short*)gpCharInfo_0077BBD8->wFlags) & 4;
            int bLadder = (*(unsigned short*)gpCharInfo_0077BBD8->wFlags) & 0x20;
            if (bExpansion)
                gpCharInfo_0077BBD8->dwFlags |= 0x800;
            if (bLadder)
                gpCharInfo_0077BBD8->dwFlags |= 0x100000;

            szDesc[0] = (bExpansion ? 3 : 0) + gnDiffSelect_00798CD0 + '1';
            SStrCopy(&szDesc[1], tLogin.szText0x20, 0x7FFFFFFF);

            int nFlags = 0;
            if (gpCharInfo_0077BBD8->nByte210 == 1)
                nFlags = 1;
            if (gpCharInfo_0077BBD8->nByte210 == 2)
                nFlags |= 2;
            if ((*(unsigned short*)gpCharInfo_0077BBD8->wFlags) & 4)
                nFlags |= 4;
            if ((*(unsigned short*)gpCharInfo_0077BBD8->wFlags) & 0x20)
                nFlags |= 8;

            gpLaunchFuncs_0077B09C->pfn0x34(tLogin.szText0x00, tLogin.szText0x10, szDesc, nFlags);
            sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            sub_004FA590_RunLoop(sub_00443840_CallTable8C);
            sub_0043EA20_Wait();

            D2LaunchResultStrc tResult;
            gpLaunchFuncs_0077B09C->pfn0x8C((int*)&tResult);
            if (!tResult.nResult)
            {
                sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x1412), 0);
                return 1;
            }
        }
        else
        {
            char szValue[5];
            const Unicode* pValue = sub_004FDD90_GetEditText(gpMaxPlayerControl_00798C38);
            sub_005263E0(szValue, pValue, 5);
            SRegSaveValue(gszDiablo2_006CC8B8, gszMaxPlayer_006D57C0, 0, atoi(szValue));
            SRegSaveValue(gszDiablo2_006CC8B8, gszDiffLevel_006D57DC, 0, gnDiffSelect_00798CD0);
            if (!sub_00500960_IsPressed(gpButton_00798C40))
            {
                SRegSaveValue(gszDiablo2_006CC8B8, gszLvlRest_006D57CC, 0, 666);
            }
            else
            {
                pValue = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
                sub_005263E0(szValue, pValue, 5);
                SRegSaveValue(gszDiablo2_006CC8B8, gszLvlRest_006D57CC, 0, atoi(szValue));
            }
        }

        sub_0043FE40_SetupLogin(&tLogin, FOG_GetHostIPAddress());
        if (!sub_00449B30_QueryAddress())
        {
            sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            sub_00443220_DestroyControls();
            return 1;
        }

        gdwGlobal_00798CC4 = 0;
        sub_004401C0_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), sub_00443870_SetCancel);
        sub_004FA590_RunLoop(sub_00443880_PollMcp);
        sub_0043EA20_Wait();
        if (gdwGlobal_00798CC4)
            sub_0043F850();
        sub_00443220_DestroyControls();
        if (sub_00449E40())
            sub_004453B0_BuildPanel();
    }

    return 1;
}
