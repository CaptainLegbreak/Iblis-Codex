struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2LaunchRecord3Strc
{
    int nValue0;
    int nValue1;
    int f_8;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x14];
    int (__fastcall* pfn0x14)(void* pBuffer);
    char unk0x18[0x04];
    int (__fastcall* pfn0x1C)(int nA, int nB, int nC);
    char unk0x20[0x48];
    int (__fastcall* pfn0x68)();
    char unk0x6C[0x08];
    int (__fastcall* pfn0x74)(int nA, int nB, void* pKey, D2LaunchRecord3Strc* pRecord);
    char unk0x78[0x04];
    int (__fastcall* pfn0x7C)(int nA, int nB, void* pKey, D2LaunchRecord3Strc* pRecord);
    char unk0x80[0x0C];
    int (__fastcall* pfn0x8C)(int* pOut);
};

struct D2LaunchCharInfoStrc
{
    char unk0x00[0x19];
    char nState[4];
    char wValue[2];
    char szText0x1F[0x18];
    char szText0x37[0x1B8];
    char wFlags[2];
    char unk0x1F1[0x3C];
    char bOnline;
    char unk0x22E[0x17];
    char szText0x245[0x10];
};

struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                        // 0x00683840

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern);            // 0x00526940
void __cdecl sub_004F9190();                                                              // 0x004F9190
void __fastcall sub_004F9740_ControlSetState(D2WinControlStrc* pControl, int nFlags);                       // 0x004F9740
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __stdcall sub_004F9160_SetLoopValue(int nValue);                                                       // 0x004F9160
void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
void __cdecl sub_0043FBD0_Refresh();                                                                        // 0x0043FBD0
int __fastcall sub_0044AAE0_SendSelect(const char* szName, int nB, int nC);                                 // 0x0044AAE0
int __fastcall sub_0044A4E0_SendConnect(const char* szName, const char* szRealm, unsigned short wRequestId); // 0x0044A4E0
int __fastcall sub_0044A2E0_Forward3(int nA, int nB, int nC);                                               // 0x0044A2E0
int __fastcall sub_0044A380_Forward1(int nA);                                                               // 0x0044A380
void __fastcall sub_0043FB50_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50
void __fastcall sub_00440140_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
void* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA);                             // 0x00449050
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
int __stdcall sub_0043DAF0_OnConnect(int nArg);                                                             // 0x0043DAF0
int __stdcall sub_0043E6C0_OnError(int nArg);                                                               // 0x0043E6C0
unsigned long __stdcall sub_0044A070_ThreadProc(void* pParameter);                                          // 0x0044A070

extern unsigned short gwRequestId_0070CD60;                                                                 // 0x0070CD60
extern char gnSelectModeA_0070CD62;                                                                         // 0x0070CD62
extern char gnSelectModeB_0070CD63;                                                                         // 0x0070CD63
extern int gnSelectIdA_0070CD7C;                                                                            // 0x0070CD7C
extern int gnSelectIdB_0070CD80;                                                                            // 0x0070CD80
extern char gKey_0070CD54;                                                                                  // 0x0070CD54
extern char gszSelectName_0077B040[];                                                                       // 0x0077B040
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern char gKey_0077B0A8;                                                                                  // 0x0077B0A8
extern int gbFlag_0077ADA4;                                                                                 // 0x0077ADA4
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern unsigned short gwSavedRequestId_0077BBDC;                                                            // 0x0077BBDC
extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4
D2WinControlStrc* gpControlMain_0077BC4C;                                                                   // 0x0077BC4C
extern int gbCheck_0077BD58;                                                                                // 0x0077BD58
extern int gbSelectActive_0077BD00;                                                                         // 0x0077BD00
extern unsigned long gdwSelectTime_0077BD5C;                                                                // 0x0077BD5C
int gbPending_0077BD9C;                                                                                     // 0x0077BD9C
extern int gbDone_0077BDA0;                                                                                 // 0x0077BDA0
D2LaunchCallback gpfnLaunchCallback_0077BDA4;                                                               // 0x0077BDA4
int gnResult_00798F58;                                                                                      // 0x00798F58
extern int gnValue_00798F5C;                                                                                // 0x00798F5C
char gszText_00798F60[28];                                                                                  // 0x00798F60
extern int gnValue_00798F7C;                                                                                // 0x00798F7C
extern int gnValue_00798F84;                                                                                // 0x00798F84
extern D2LaunchThreadRecordStrc gtThreadRecord_00798FB8;                                                    // 0x00798FB8
extern int gnValue_00799100;                                                                                // 0x00799100
extern int gnValue_00799104;                                                                                // 0x00799104
char gszText_00799294[4];                                                                                   // 0x00799294
extern int gnValue_00799298;                                                                                // 0x00799298
extern int gnValue_0079929C;                                                                                // 0x0079929C
extern int gnValue_007992A0;                                                                                // 0x007992A0
extern void* ghThread_007992A4;                                                                             // 0x007992A4
extern int gnValue_007992A8;                                                                                // 0x007992A8
extern int gnValue_007992E0;                                                                                // 0x007992E0
extern int gnValue_007992E8;                                                                                // 0x007992E8
extern int gnValue_007992F0;                                                                                // 0x007992F0

// 0x0043D9B0
int __stdcall sub_0043D9B0_NextRequestCallback(int nArg)
{
    while (++gwRequestId_0070CD60 == 0)
    {
    }
    gpfnLaunchCallback_0077BDA4(nArg);
    return 1;
}

// 0x0043EB10
int __stdcall sub_0043EB10_RunCallback(int nArg)
{
    if (gpfnLaunchCallback_0077BDA4)
        gpfnLaunchCallback_0077BDA4(nArg);
    return 1;
}

// 0x0043EC60
void __fastcall sub_0043EC60_SelectEntry(const char* szName, int nB, int nC)
{
    if (!gbSelectActive_0077BD00)
        return;
    SStrCopy(gszSelectName_0077B040, szName, 0x7FFFFFFF);
    char nMode;
    if (nC)
        nMode = nB ? 0x13 : 0x1B;
    else
        nMode = nB ? 0 : 9;
    gnSelectModeA_0070CD62 = nMode;
    gnSelectModeB_0070CD63 = nMode;
    gnSelectIdA_0070CD7C = -1;
    gnSelectIdB_0070CD80 = -1;
    sub_0044AAE0_SendSelect(szName, nB, nC);
    gdwSelectTime_0077BD5C = GetTickCount() + 1000;
}

// 0x0043F590
int __stdcall sub_0043F590_CallTable7C(int nUnused)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = 8;
    tRecord.nValue1 = 0x28;
    tRecord.f_8 = 0xC8;
    if (gpLaunchFuncs_0077B09C->pfn0x7C(3, 1, &gKey_0077B0A8, &tRecord) || gbFlag_0077ADA4)
        sub_004F9190();
    return 1;
}

// 0x0043F5F0
int __fastcall sub_0043F5F0_CallTable74(int nA, int nB, int nC, int nD)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = nB;
    tRecord.nValue1 = nC;
    tRecord.f_8 = nD;
    return gpLaunchFuncs_0077B09C->pfn0x74(nA, 3, &gKey_0070CD54, &tRecord);
}

// 0x0043F930
int __stdcall sub_0043F930_SetCallback(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
    sub_0043F8C0_ResetLaunchState();
    gpfnLaunchCallback_0077BDA4 = pfnCallback;
    return 1;
}

// 0x0043FFA0
int __fastcall sub_0043FFA0_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37)
{
    gnLaunchMode_0077BBE4 = 2;
    sub_0043F930_SetCallback(0, sub_0043DAF0_OnConnect);
    *(unsigned short*)gpCharInfo_0077BBD8->wValue = wValue;
    strcpy(gpCharInfo_0077BBD8->szText0x1F, szText0x1F);
    strcpy(gpCharInfo_0077BBD8->szText0x245, szText0x245);
    if (gpCharInfo_0077BBD8->bOnline)
    {
        if (sub_00449B30_QueryAddress())
        {
            *(int*)gpCharInfo_0077BBD8->nState = 3;
            while (++gwRequestId_0070CD60 == 0)
            {
            }
            sub_0044A4E0_SendConnect(szText0x1F, szText0x245, gwRequestId_0070CD60);
            gwSavedRequestId_0077BBDC = gwRequestId_0070CD60;
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
            return 1;
        }
        gnLaunchMode_0077BBE4 = 0;
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
        return 0;
    }
    *(int*)gpCharInfo_0077BBD8->nState = 7;
    strcpy(gpCharInfo_0077BBD8->szText0x37, szText0x37);
    gbDone_0077BDA0 = 1;
    sub_004F9160_SetLoopValue(0);
    sub_004F9190();
    return 1;
}

// 0x004413E0
void __stdcall sub_004413E0_Enable(int bEnable)
{
    if (bEnable)
    {
        if (!sub_00449B30_QueryAddress())
        {
            sub_00440140_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return;
        }
        gnLaunchMode_0077BBE4 = 0;
        sub_0043FB50_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        if (gpControlMain_0077BC4C)
            sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 0);
        return;
    }
    if (!gnLaunchMode_0077BBE4 && gbPending_0077BD9C)
        sub_0043F8C0_ResetLaunchState();
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
        sub_004F96F0_ControlClearState(gpControlA_0077B070, 1);
        sub_004F96F0_ControlClearState(gpControlB_0077B078, 1);
    }
    sub_004F96F0_ControlClearState(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    if (gpControlMain_0077BC4C)
        sub_004F9740_ControlSetState(gpControlMain_0077BC4C, 1);
}

// 0x00442B20
int __fastcall sub_00442B20_IsCharOverLimit(const unsigned char* pChar)
{
    unsigned char nChar = *pChar;
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    const int nLimit = ((wFlags >> 8) & 0x1F) / 5 + 1;
    if (wFlags & 4)
    {
        if (nChar - '3' > nLimit || nChar < '3')
            return 1;
        return 0;
    }
    return nChar - '0' > nLimit;
}

// 0x00443600
int __stdcall sub_00443600_IsPrintableChar(int nA, int nB, const char* pChar)
{
    const char nChar = *pChar;
    if (nChar >= 0x20 && nChar < 0x80)
        return 1;
    return 0;
}

// 0x00443840
int __stdcall sub_00443840_CallTable8C(int nUnused)
{
    int nOut;
    if (gpLaunchFuncs_0077B09C->pfn0x8C(&nOut))
        sub_004F9190();
    return 1;
}

// 0x00446810
char* __cdecl sub_00446810_StrChr(const char* szString, int nChar)
{
    return strchr(szString, nChar);
}

// 0x00446A90
void __stdcall sub_00446A90_RemoveTableString(Unicode* pText)
{
    D2_ASSERT(sub_00526800(pText) < 500, 0x300);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nPatternLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_UnicodeStrStr(pText, pPattern);
    while (pFound && pFound[nPatternLength].wChar)
    {
        memmove(pFound, &pFound[nPatternLength + 1], (sub_00526800(pFound) - nPatternLength) * sizeof(Unicode));
        pFound = sub_00526940_UnicodeStrStr(pText, pPattern);
    }
}

// 0x00447700
int __fastcall sub_00447700_OnMessage(int nA, int nB, const char* szText, int nLength)
{
    gpLaunchFuncs_0077B09C->pfn0x1C(nLength, 1, 0);
    sub_0043FBD0_Refresh();
    return 1;
}

// 0x00449330
int __fastcall sub_00449330_OnMessage(int nA, int nB, const char* szText, int nLength)
{
    sub_00449050_AddEntry(szText, nLength, nA);
    return 1;
}

// 0x004497F0
void __fastcall sub_004497F0_MixChar(char* pChar, int nBits, unsigned int* pPool)
{
    *pChar = (char)toupper(*pChar);
    if (*pChar <= '7')
    {
        *pChar ^= *pPool & 7;
        *pPool >>= 3;
    }
    else if (*pChar < 'A')
    {
        *pChar ^= nBits & 1;
    }
}

// 0x00449BF0
void __stdcall sub_00449BF0_SetValue(int nValue)
{
    gnValue_0079929C = nValue;
}

// 0x00449C20
void __stdcall sub_00449C20_SetValue(int nValue)
{
    gnValue_007992E8 = nValue;
}

// 0x00449C40
void __stdcall sub_00449C40_SetValue(int nValue)
{
    gnValue_007992E0 = nValue;
}

// 0x00449C60
void __stdcall sub_00449C60_SetValue(int nValue)
{
    gnValue_00799298 = nValue;
}

// 0x00449C80
void __stdcall sub_00449C80_SetValue(int nValue)
{
    gnValue_007992F0 = nValue;
}

// 0x00449C90
void __stdcall sub_00449C90_SetValue(int nValue)
{
    gnValue_00799100 = nValue;
}

// 0x00449CC0
void __stdcall sub_00449CC0_SetValue(int nValue)
{
    gnValue_007992A0 = nValue;
}

// 0x00449CD0
int __stdcall sub_00449CD0_GetTexts(char* szText1, char* szText2)
{
    strcpy(szText1, gszText_00799294);
    strcpy(szText2, gszText_00798F60);
    return gnResult_00798F58;
}

// 0x00449D10
void __stdcall sub_00449D10_SetTexts(int nResult, const char* szText1, const char* szText2)
{
    strcpy(gszText_00799294, szText1);
    strcpy(gszText_00798F60, szText2);
    gnResult_00798F58 = nResult;
}

// 0x00449D90
void __stdcall sub_00449D90_SetValue(int nValue)
{
    gnValue_007992A8 = nValue;
}

// 0x00449DB0
void __stdcall sub_00449DB0_SetValue(int nValue)
{
    gnValue_00798F5C = nValue;
}

// 0x00449DD0
void __stdcall sub_00449DD0_SetValue(int nValue)
{
    gnValue_00798F84 = nValue;
}

// 0x00449DF0
int __stdcall sub_00449DF0_Forward3(int nA, int nB, int nC)
{
    return sub_0044A2E0_Forward3(nA, nB, nC);
}

// 0x00449E10
int __stdcall sub_00449E10_Forward1(int nA)
{
    return sub_0044A380_Forward1(nA);
}

// 0x00449E30
void __stdcall sub_00449E30_SetValue(int nValue)
{
    gnValue_00799104 = nValue;
}

// 0x00449E50
void __stdcall sub_00449E50_SetValue(int nValue)
{
    gnValue_00798F7C = nValue;
}

// 0x0044A130
void __stdcall sub_0044A130_StartThread(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghThread_007992A4)
    {
        gtThreadRecord_00798FB8 = *pRecord;
        unsigned long nThreadId;
        ghThread_007992A4 = CreateThread(0, 0, sub_0044A070_ThreadProc, 0, 0, &nThreadId);
    }
}

#include "gen/data/Source/D2Client/0043D9B0_sub_0043D9B0_NextRequestCallback.inc"
