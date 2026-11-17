struct Unicode
{
    unsigned short wChar;
};

struct D2WinEditBoxStrc;
struct D2CompositeStrc;

typedef int (__stdcall* D2LaunchCallback)(int nArg);

struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x15];
    D2CompositeStrc* f_9C;
    char unk0xA0[0x10];
    T0043E860* pNext;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    int (__fastcall* pfn0x14)(void* pBuffer);
    char unk0x18[0x50];
    int (__fastcall* pfn0x68)();
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x8D];
    char szText0x8D[0x10];
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

char* __stdcall SStrChr(const char* szString, char nChar);                                                  // 0x00413490
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                       // 0x00413590
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinEditBoxStrc* pEditBox);                          // 0x004FDD90
int __fastcall sub_004FF5A0(D2WinEditBoxStrc* pEditBox, const Unicode* pText);                               // 0x004FF5A0
int __fastcall sub_004428D0_SendChatText(const char* szText, int bFlag);                                   // 0x004428D0
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
int __stdcall sub_0043E6C0_OnError(int nArg);                                                               // 0x0043E6C0
void __cdecl sub_00448050_ClearSelectedUser();                                                              // 0x00448050
D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList();                                                   // 0x00611560

extern D2WinEditBoxStrc* gpChatEditBox_0077BD94;                                                            // 0x0077BD94
extern T0043E860* gpSelectedChannelUser_00798F48;                                                   // 0x00798F48
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8

static unsigned long s_dwLastCommandTick_00798F50;                                                          // 0x00798F50

// 0x004468F0
int __stdcall sub_004468F0_SendChatLine(int nUnused)
{
    char szText[0x100];
    const Unicode* wszText = D2Win_10077_EDITBOX_GetText(gpChatEditBox_0077BD94);
    if (!wszText || !sub_00526800(wszText))
    {
        return 1;
    }

    sub_00526F70(szText, wszText, sizeof(szText));
    return sub_004428D0_SendChatText(szText, 1);
}

// 0x00446970
int __stdcall sub_00446970_SendEmoteLine(int nUnused)
{
    char szText[0x12C];
    char szLine[0x12C];
    const Unicode* wszText = D2Win_10077_EDITBOX_GetText(gpChatEditBox_0077BD94);
    if (wszText && sub_00526800(wszText))
    {
        sub_00526F70(szText, wszText, sizeof(szText));
        if (szText[0] != '/')
        {
            const unsigned long dwTick = GetTickCount();
            if (dwTick >= s_dwLastCommandTick_00798F50 + 1000)
            {
                s_dwLastCommandTick_00798F50 = dwTick;
                sprintf(szLine, "/me %s", szText);
                sub_004428D0_SendChatText(szLine, 0);
            }
        }
    }
    return 1;
}

// 0x00448E30
int __stdcall sub_00448E30_SquelchSelectedUser(int nUnused)
{
    char szName[0x100];
    char szText[0x100];
    if (!gpSelectedChannelUser_00798F48)
    {
        return 1;
    }

    strcpy(szName, gpSelectedChannelUser_00798F48->szName);
    const unsigned long dwTick = GetTickCount();
    if (dwTick < s_dwLastCommandTick_00798F50 + 1000)
    {
        return 1;
    }

    s_dwLastCommandTick_00798F50 = dwTick;
    char* pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    sprintf(szText, "/squelch *%s", pName);
    sub_00448050_ClearSelectedUser();
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 0;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
    sub_004FF5A0(gpChatEditBox_0077BD94, 0);
    pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    if (SStrCmpI(pName, gpCharInfo_0077BBD8->szText0x8D, 0x7FFFFFFF))
    {
        sub_00611560_GetSquelchList()->Squelch(szName);
    }
    return 1;
}

// 0x00448F60
int __stdcall sub_00448F60_UnsquelchSelectedUser(int nUnused)
{
    char szName[0x100];
    char szText[0x100];
    if (!gpSelectedChannelUser_00798F48)
    {
        return 1;
    }

    strcpy(szName, gpSelectedChannelUser_00798F48->szName);
    const unsigned long dwTick = GetTickCount();
    if (dwTick < s_dwLastCommandTick_00798F50 + 1000)
    {
        return 1;
    }

    s_dwLastCommandTick_00798F50 = dwTick;
    char* pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    sprintf(szText, "/unsquelch *%s", pName);
    sub_00448050_ClearSelectedUser();
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 0;
    }

    gpLaunchFuncs_0077B09C->pfn0x14(szText);
    sub_004FF5A0(gpChatEditBox_0077BD94, 0);
    sub_00611560_GetSquelchList()->Unsquelch(szName);
    return 1;
}
