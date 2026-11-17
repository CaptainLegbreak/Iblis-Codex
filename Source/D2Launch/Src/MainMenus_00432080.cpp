#include "D2Launch.h"

struct Unicode
{
    unsigned short wChar;
};

typedef void (__cdecl* D2LaunchDoneFn)();

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
    char szPassword[0x100];
    char unk0x1A5[0x21E];
    unsigned int dwPasswordHash;
    int nPasswordLength;
};
#pragma pack(pop)
unsigned int __stdcall sub_00414150_HashPath(const char* szPath);                                           // 0x00414150
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00526590_Compare(const Unicode* pString1, const Unicode* pString2);                      // 0x00526590
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode);                    // 0x0043C180
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0043B080();                                                                                // 0x0043B080
int __cdecl sub_00430BC0_HasSaveFiles();                                                                    // 0x00430BC0
void __cdecl sub_0042FDD0();                                                                                // 0x0042FDD0
void __cdecl sub_00435330_ShowLoginScreen();                                                                // 0x00435330
void __cdecl sub_004325B0_CreateScreen();                                                                   // 0x004325B0
void __cdecl sub_004301A0();                                                                                // 0x004301A0
void __cdecl sub_00432100();                                                                                // 0x00432100
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern D2WinControlStrc* gpEdit_00779340;                                                                   // 0x00779340
char gszOldPassword_00779550[24];                                                                           // 0x00779550
extern D2WinControlStrc* gpEdit_007795A8;                                                                   // 0x007795A8
extern int gdwGlobal_007795F4;                                                                              // 0x007795F4

// 0x00432080
static void sub_00432080_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit)
{
    if (pAccountEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pAccountEdit);
        sub_00526F70(gpLaunchRecord_007795D4->szAccount, pText, 0x100);
    }
    if (pPasswordEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pPasswordEdit);
        sub_00526F70(gpLaunchRecord_007795D4->szPassword, pText, 0x100);
        gpLaunchRecord_007795D4->dwPasswordHash = sub_00414150_HashPath(gpLaunchRecord_007795D4->szPassword);
        gpLaunchRecord_007795D4->nPasswordLength = SStrLen(gpLaunchRecord_007795D4->szPassword);
    }
}

// 0x00435030
int __stdcall sub_00435030_ChangePasswordOk(int nArg)
{
    if (!nArg)
    {
        sub_004370C0();
        return 1;
    }
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779340);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pOldPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779340);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpEdit_007795A8);
    sub_00526F70(gszOldPassword_00779550, pOldPassword, 0x100);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        sub_00433380_ShowMessage(pMessage, sub_00432100, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        sub_00433380_ShowMessage(pMessage, sub_00432100, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        sub_00433380_ShowMessage(pMessage, sub_00432100, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        sub_00433380_ShowMessage(pMessage, sub_00432100, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        sub_00433380_ShowMessage(pMessage, sub_00432100, 1);
        return 1;
    }
    gdwGlobal_007795F4 = 0;
    if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 1))
    {
        if (gdwGlobal_007795F4)
        {
            sub_00432100();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        sub_0042F3F0_DestroyControls();
        sub_0042FDD0();
    }
    return 1;
}

// 0x004361B0
int __stdcall sub_004361B0_LoginOk(int nArg)
{
    if (!nArg)
    {
        sub_004336C0();
        return 1;
    }
    if (!sub_004F9710_TestFlag(gpControl_00779594))
        return 0;
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    if (sub_0043C180_Connect(gpLaunchRecord_007795D4, 0, 0))
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        if (gnLaunchMode_007795EC == 1)
        {
            sub_00515020();
            sub_0042F480_Reset();
            sub_0043B080();
            return 1;
        }
        if (sub_00430BC0_HasSaveFiles())
        {
            sub_0042FDD0();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

// 0x00436910
int __stdcall sub_00436910_CreateAccountOk(int nArg)
{
    if (!nArg)
    {
        sub_00435330_ShowLoginScreen();
        return 1;
    }
    sub_00432080_StoreAccountTexts(gpEdit_0077958C, gpEdit_00779334);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpEdit_0077958C);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpEdit_00779334);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpEdit_007795A8);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        sub_00433380_ShowMessage(pMessage, sub_004301A0, 1);
        return 1;
    }
    sub_004325B0_CreateScreen();
    return 1;
}
