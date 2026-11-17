struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}

    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                     // 0x00526790
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);                    // 0x00526F20
};

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

struct D2StatusStrc
{
    int nCode;
    int nArg;
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
    char szPassword[0x100];
};
#pragma pack(pop)

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x08];
    void (__fastcall* pfnSlot08)(char* szAccount, char* szPassword);
    char unk0x0C[0x04];
    int (__fastcall* pfnSlot10)();
    char unk0x14[0x14];
    int (__fastcall* pfnSlot28)(D2StatusStrc* pStatus);
    char unk0x2C[0x34];
    void (__fastcall* pfnSlot60)(char* szAccount, char* szPassword);
    void (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x30];
    void (__fastcall* pfnSlot9C)(char* szAccount, char* szOldPassword, char* szPassword);
    void (__fastcall* pfnSlotA0)(int* pValue);
    char unk0xA4[0x10];
    int (__fastcall* pfnSlotB4)();
};

typedef void (__cdecl* D2LaunchDoneFn)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);                        // 0x00433450
void __fastcall sub_00433130_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone); // 0x00433130
void __fastcall sub_004331C0_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone); // 0x004331C0
void __fastcall sub_004332B0_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone); // 0x004332B0
void __cdecl sub_004336C0_ShowMainMenu();                                                                   // 0x004336C0
void __cdecl sub_004301A0();                                                                                // 0x004301A0
void __cdecl sub_00435330_ShowLoginScreen();                                                                // 0x00435330
void __fastcall sub_0042FF10_SetValue(int nValue);                                                          // 0x0042FF10
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars);                         // 0x00413550
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern int gnLogonRetries_0070CC4C;                                                                         // 0x0070CC4C
char gszLastAccount_0077ABF4[16];                                                                           // 0x0077ABF4

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0043B9F0
int __fastcall sub_0043B9F0_HandleStatus(D2StatusStrc* pStatus)
{
    Unicode wszText[0x200];
    Unicode wszText3[0x200];
    Unicode wszTitle[0x200];

    int nTitle;
    int nText;
    int nMode;
    D2LaunchDoneFn pfnDone;
    int bClose;
    int nText3;
    bClose = 1;
    pfnDone = sub_004336C0_ShowMainMenu;
    nText3 = -1;
    wszTitle[0].wChar = 0;
    wszText3[0].wChar = 0;

    switch (pStatus->nCode)
    {
    case 1:
        nTitle = 0x147D;
        nText = 0x1443;
        nText3 = 0x1444;
        nMode = 2;
        break;

    case 2:
        nTitle = 0x147E;
        nText = 0x143F;
        nMode = 1;
        break;

    case 3:
    case 7:
        nTitle = 0x147F;
        nText = (pStatus->nCode == 3) ? 0x1442 : 0x2AA0;
        nText3 = 0x144A;
        nMode = 2;
        break;

    case 4:
    case 8:
        nTitle = 0x147F;
        nText = (pStatus->nCode == 4) ? 0x144F : 0x2AA1;
        nMode = 1;
        break;

    case 5:
    case 9:
        nTitle = 0x147F;
        nText = 0x1452;
        nMode = 1;
        break;

    case 6:
    case 10:
    {
        UnicodeChar wszArg[0x200];
        D2_ASSERT(pStatus->nArg, 685);
        Unicode::win2Unicode(wszArg, (const char*)pStatus->nArg, 0x200);
        Unicode::strncpy(wszTitle, D2LANG_GetStringFromTblIndex(0x147F), 0x200);
        Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex((pStatus->nCode == 6) ? 0x1450 : 0x2AA2), 0x200);
        Unicode::strncpy(wszText3, D2LANG_GetStringFromTblIndex(0x1451), 0x200);
        sub_004332B0_ShowFourTexts(wszTitle, wszText, wszArg, wszText3, sub_004336C0_ShowMainMenu);
        return 0;
    }

    case 11:
        nTitle = 0x147F;
        nText = 0x14EC;
        nMode = 1;
        break;

    case 12:
        nTitle = 0x147F;
        nText = 0x1445;
        nText3 = 0x1446;
        nMode = 2;
        break;

    case 19:
        nTitle = 0x1481;
        nText = 0x146F;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 20:
        nTitle = 0x1481;
        nText = 0x1470;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 21:
        nTitle = 0x1481;
        nText = 0x1471;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 22:
        nTitle = 0x1481;
        nText = 0x1477;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 23:
        nTitle = 0x1481;
        nText = 0x1472;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 24:
        nTitle = 0x1481;
        nText = 0x1473;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 25:
        nTitle = 0x1481;
        nText = 0x1474;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 26:
        nTitle = 0x1481;
        nText = 0x1475;
        nMode = 1;
        pfnDone = sub_004301A0;
        bClose = 0;
        break;

    case 13:
        nTitle = 0x147C;
        nText = 0x1458;
        nMode = 1;
        bClose = 0;
        pfnDone = sub_00435330_ShowLoginScreen;
        break;

    case 14:
        if (!SStrCmp(gszLastAccount_0077ABF4, gpLaunchRecord_007795D4->szAccount, 0x7FFFFFFF))
        {
            ++gnLogonRetries_0070CC4C;
        }
        else
        {
            gnLogonRetries_0070CC4C = 1;
            SStrCopy(gszLastAccount_0077ABF4, gpLaunchRecord_007795D4->szAccount, 0x10);
        }
        nTitle = 0x147C;
        nMode = 1;
        bClose = 0;
        pfnDone = sub_00435330_ShowLoginScreen;
        if (gnLogonRetries_0070CC4C >= 2)
        {
            nText = 0x2B63;
            sub_0042FF10_SetValue(1);
        }
        else
        {
            nText = 0x1457;
        }
        break;

    case 15:
        nTitle = 0x147C;
        nText = 0x1459;
        nMode = 1;
        bClose = 0;
        pfnDone = sub_00435330_ShowLoginScreen;
        break;

    case 16:
        nTitle = 0x1480;
        nText = 0x14E5;
        nMode = 1;
        break;

    case 17:
        nTitle = 0x1480;
        nText = 0x14EA;
        nMode = 1;
        break;

    case 18:
        nTitle = 0x1480;
        nText = 0x14E3;
        nMode = 1;
        break;

    case 27:
        sub_00526E40_Utf8ToUnicode(wszText, (const char*)pStatus->nArg, 0x200);
        Unicode::strncpy(wszTitle, D2LANG_GetStringFromTblIndex(0x147C), 0x200);
        sub_00433130_ShowTwoTexts(wszTitle, wszText, sub_00435330_ShowLoginScreen);
        return 0;

    default:
        nTitle = 0x1480;
        nText = 0x1445;
        nText3 = 0x1446;
        nMode = 2;
        break;
    }

    Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(nText), 0x200);
    if (nText3 != -1)
        Unicode::strncpy(wszText3, D2LANG_GetStringFromTblIndex(nText3), 0x200);
    if (nTitle != -1)
        Unicode::strncpy(wszTitle, D2LANG_GetStringFromTblIndex(nTitle), 0x200);

    if (nMode == 0)
        sub_00433450_ShowText(wszText, pfnDone);
    else if (nMode == 1)
        sub_00433130_ShowTwoTexts(wszTitle, wszText, pfnDone);
    else
        sub_004331C0_ShowThreeTexts(wszTitle, wszText, wszText3, pfnDone);

    if (bClose)
    {
        D2MCPClientCloseMCP();
        gpFuncTable_0077ABF0->pfnSlot10();
    }
    return 0;
}

#include "gen/data/Source/D2Client/0043B9F0_sub_0043B9F0_HandleStatus.inc"
