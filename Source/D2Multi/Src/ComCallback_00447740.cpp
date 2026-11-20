#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2LaunchMsgStrc;
struct D2LaunchFuncsStrc;
struct Unicode;
struct D2MultiChannelUserStrc;

struct D2LaunchMsgStrc
{
    int nType;
    int nArg;
    char* szName;
    void* pExtra;
    void* pData;
    unsigned long nSize;
    char szText[0x108];
};

typedef int (__fastcall* D2LaunchMsgHandler)(int nArg, char* pArg, const char* szText, const char* szNext);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* szBuffer); // 0x006CC344
extern "C" __declspec(dllimport) unsigned int __stdcall GetTempFileNameA(const char* szPathName, const char* szPrefix, unsigned int nUnique, char* szTempFileName); // 0x006CC340
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern D2WinSmackStrc* gpSmack_0077B098; // 0x0077B098
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C
extern int gnVideoId_0077B0A4; // 0x0077B0A4
extern char gszText_00798CF8[]; // 0x00798CF8
extern char gszTempFile_00798E30[]; // 0x00798E30
extern D2LaunchMsgHandler gpfnMsgHandlers_0070EC20[]; // 0x0070EC20
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" int __cdecl rand(); // 0x00687461
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
int __fastcall sub_0043E630_ShowChannelText(Unicode* pText); // 0x0043E630
void __fastcall sub_00447400_SetNamedValue(const char* szName, const char* szValue); // 0x00447400
void __fastcall sub_00448BD0_UpdateScroll(int nDelta); // 0x00448BD0
void __stdcall sub_00504270_SetCompositeText(D2CompositeStrc* pComposite, Unicode* wszName, Unicode* wszAccount, Unicode* wszS97, Unicode* wszRealm, int nLevel, unsigned int dwCode); // 0x00504270
D2CompositeStrc* __stdcall sub_005066C0(int nA, int nMode, unsigned char* pComponents, unsigned char* pColors); // 0x005066C0
extern "C" const char szLaunchFile_006D5810[]; // 0x006D5810
extern "C" const char gszChannelCountFormat_006D5994[]; // 0x006D5994
extern char gData_00798D30[]; // 0x00798D30
extern D2MultiChannelUserStrc* gpChannelUsers_00798F34; // 0x00798F34
extern int gnChannelLines_00798F40; // 0x00798F40
extern int gbRandSeeded_00798F54; // 0x00798F54
static __declspec(noinline) unsigned char sub_00446D90_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat);
static __declspec(noinline) void sub_004471B0_UpdateUserText(D2MultiChannelUserStrc* pUser);
static __declspec(noinline) void __fastcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat);

static __declspec(noinline) int sub_00446B70_PlayVideoMessage(D2LaunchMsgStrc* pMsg)
{
    char szTempPath[0x104];
    char szTempFile[0x104];
    unsigned long nWritten;

    SMACK_DeleteFile(gpSmack_0077B098);
    if (!GetTempPathA(0x104, szTempPath))
        strcpy(szTempPath, ".");

    if (GetTempFileNameA(szTempPath, "BNetAd", 0, szTempFile) > 0)
    {
        DeleteFileA(gszTempFile_00798E30);
        void* hFile = sub_00406960_CreateFile(szTempFile, 0x40000000, 0, 0, 4, 0x8000000, 0);
        if (hFile != (void*)-1)
        {
            sub_004069D0_WriteFile(hFile, pMsg->pData, pMsg->nSize, &nWritten, 0);
            sub_004069A0_CloseFile(hFile);
        }
        const char* pExt = strrchr(pMsg->szName, '.') + 1;
        SMACK_Decode(gpSmack_0077B098, szTempFile, tolower(*pExt));
        strcpy(gszTempFile_00798E30, szTempFile);
    }

    gnVideoId_0077B0A4 = pMsg->nType;
    FOG_Free(pMsg->szName, ".\\Src\\ComCallback.cpp", 0x386, 0);
    FOG_Free(pMsg->pExtra, ".\\Src\\ComCallback.cpp", 0x387, 0);
    return 1;
}

// 0x00447740
static __declspec(noinline) int sub_00447740_DispatchMessage(D2LaunchMsgStrc* pMsg)
{
    int nArg = pMsg->nArg;
    char* pArg = pMsg->szName;
    unsigned int nIndex = pMsg->nType;
    const char* szText = pMsg->szText;
    int nLength = strlen(szText);
    if (nIndex < 0x18)
    {
        D2LaunchMsgHandler pfnHandler = gpfnMsgHandlers_0070EC20[nIndex];
        if (pfnHandler)
        {
            int nResult = pfnHandler(nArg, pArg, szText, szText + nLength + 1);
            if (nResult)
                return nResult;
        }
    }
    return 1;
}

// 0x00447A10
int __cdecl sub_00447A10_Pump()
{
    int nType;
    D2LaunchMsgStrc tMsg;
    if (!gpLaunchFuncs_0077B09C->pfnGetMessage(&nType, &tMsg))
        return 0;

    switch (nType)
    {
    case 0:
        sub_00447740_DispatchMessage(&tMsg);
        break;
    case 2:
        SStrCopy(gszText_00798CF8, (char*)&tMsg, 0x32);
        break;
    case 3:
        sub_00446B70_PlayVideoMessage(&tMsg);
        break;
    }
    return 1;
}

#include "gen/data/Source/D2Multi/Src/ComCallback_00447740.inc"

static int CHANNEL_IsMaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
        return 1;
    }

    return 1;
}

static unsigned char sub_00446D90_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat)
{
    unsigned char nResult = 7;
    int bValid = 0;
    int nLength = strlen((const char*)pStat);
    pUser->wFlags = 0;

    if (nFlags & 2)
    {
        nResult = 0x13;
    }
    else if (nFlags & 8)
    {
        nResult = 0x14;
        goto LABEL_DEFAULT_LOOK;
    }
    else if (nFlags & 1)
    {
        nResult = 0x12;
        goto LABEL_DEFAULT_LOOK;
    }
    else if (nFlags & 4)
    {
        nResult = 0x17;
        goto LABEL_DEFAULT_LOOK;
    }
    else if (nFlags & 0x101000)
    {
        nResult = 0x15;
        goto LABEL_DEFAULT_LOOK;
    }
    else if (nLength < 4)
    {
        nResult = 7;
        goto LABEL_DEFAULT_LOOK;
    }
    else
    {
        bValid = 1;
    }

    if (nLength >= 4)
    {
        pUser->dwCode = *(const unsigned int*)pStat;
        nLength -= 4;
        pStat += 4;

        switch (pUser->dwCode)
        {
        case 0x44324456:
        case 0x44325354:
        case 0x44325850:
        {
            if (!*pStat)
            {
                if (nResult == 7)
                {
                    nResult = 0x18;
                }

                pUser->dwCode = 0x554E4B4E;
                strcpy(pUser->szText, pUser->szName);
                break;
            }

            D2_ASSERT(nLength > 0, 0x579);

            char* pDst = pUser->szRealm;
            while (*pStat != ',')
            {
                *pDst++ = *pStat++;
            }
            ++pStat;
            *pDst = 0;

            pDst = pUser->szText;
            while (*pStat != ',')
            {
                *pDst++ = *pStat++;
            }
            ++pStat;
            *pDst = 0;

            sub_006BBF20_ReadPackedWord(pStat);
            pStat += 2;

            int i;
            for (i = 0; i < 11; ++i)
            {
                pUser->aComponents[i] = *pStat++;
            }
            if (i < 16)
            {
                memset(&pUser->aComponents[i], 0xFF, 16 - i);
            }

            if (!pUser->aComponents[0])
            {
                if (bValid)
                {
                    pUser->dwCode = 0x554E4B4E;
                    nResult = 7;
                    strcpy(pUser->szText, pUser->szName);
                }
                break;
            }

            pUser->nClass = *pStat++ - 1;

            for (i = 0; i < 11; ++i)
            {
                pUser->aColors[i] = *pStat++;
            }
            if (i < 16)
            {
                memset(&pUser->aColors[i], 0xFF, 16 - i);
            }

            pUser->wLevel = *pStat++;

            const unsigned short wFlags = sub_006BBF20_ReadPackedWord(pStat);
            pUser->wFlags = wFlags;
            pUser->bFlagA8 = (wFlags >> 5) & 1;
            pUser->bFlagA0 = (wFlags >> 2) & 1;
            pUser->bFlagA4 = (wFlags >> 3) & 1;
            pUser->bFlagAC = (wFlags >> 6) & 1;
            pStat += 2;

            if (bValid)
            {
                if (pUser->bFlagA0 && pUser->bFlagA4)
                {
                    nResult = CHANNEL_IsMaleClass(pUser->nClass) ? 8 : 9;
                }
                else
                {
                    nResult = pUser->nClass;
                }
            }

            pUser->wW8C = sub_006BBF20_ReadPackedWord(pStat);
            pStat += 2;

            pUser->nB94 = *pStat++;
            pUser->nB94 = pUser->nB94 == 0xFF ? 0 : pUser->nB94;
            pUser->nB95 = *pStat++;
            pUser->nB95 = pUser->nB95 == 0xFF ? 0 : pUser->nB95;
            pUser->nB96 = *pStat;
            pUser->nB96 = pUser->nB96 == 0xFF ? 0 : pUser->nB96;

            if (bValid)
            {
                return nResult;
            }
            break;
        }

        case 0x43484154:
            if (bValid)
            {
                nResult = 0x16;
            }
            break;

        case 0x4452544C:
        case 0x44534852:
        case 0x44545354:
            if (bValid)
            {
                nResult = 0xA;
            }
            break;

        case 0x53544152:
        case 0x4A535452:
        case 0x53534852:
            if (bValid)
            {
                nResult = 0xD;
            }
            break;

        case 0x53455850:
            if (bValid)
            {
                nResult = 0xE;
            }
            break;

        case 0x5732424E:
            if (bValid)
            {
                nResult = 0xF;
            }
            break;

        case 0x57415233:
        case 0x57335850:
            if (bValid)
            {
                nResult = 0x10;
            }
            break;

        default:
            if (bValid)
            {
                pUser->dwCode = 0x554E4B4E;
                nResult = 7;
                strcpy(pUser->szText, pUser->szName);
            }
            break;
        }
    }

LABEL_DEFAULT_LOOK:
    for (int i = 0; i < 16; ++i)
    {
        if (i == 1)
        {
            pUser->aComponents[1] = 1;
        }
        else
        {
            pUser->aComponents[i] = 0;
        }
        pUser->aColors[i] = 0xFF;
    }

    return nResult;
}

static void sub_004471B0_UpdateUserText(D2MultiChannelUserStrc* pUser)
{
    Unicode wszName[51];
    Unicode wszAccount[17];
    Unicode wszS97[51];
    Unicode wszRealm[32];

    if (pUser->szName[0] == '*')
    {
        Unicode::win2Unicode(wszName, pUser->szName, 50);
        wszAccount[0] = 0;
    }
    else
    {
        char szAccount[50] = { 0 };
        Unicode wszCharName[50];

        const char* szName = pUser->szName;
        if (*szName == '*')
        {
            SStrCopy(szAccount, szName, 0x7FFFFFFF);
        }
        else
        {
            const char* pStar = SStrChr(szName, '*');
            if (pStar)
            {
                memcpy(szAccount, szName, pStar - szName);
                szAccount[pStar - szName] = 0;
            }
            else
            {
                SStrCopy(szAccount, szName, 0x7FFFFFFF);
            }
        }

        const char* szCharName = SStrChr(szName, '*');
        if (!szCharName || !*++szCharName)
        {
            szCharName = szName;
        }

        Unicode::win2Unicode(wszCharName, szCharName, 50);
        Unicode::win2Unicode(wszName, szStar_006D5830, 50);
        Unicode::strncat(wszName, wszCharName, 50);
        Unicode::win2Unicode(wszAccount, szAccount, 16);
    }

    Unicode::win2Unicode(wszS97, pUser->szS97, 50);
    Unicode::win2Unicode(wszRealm, pUser->szRealm, 32);

    const unsigned int dwCode = pUser->dwCode;
    unsigned short nLevel = 0;
    if (dwCode == 0x44324456 || dwCode == 0x44325354 || dwCode == 0x44325850)
    {
        nLevel = pUser->wLevel;
    }

    sub_00504270_SetCompositeText(pUser->pComposite, wszName, wszAccount, wszS97, wszRealm, nLevel, dwCode);
}

// 0x00447FD0
static void __fastcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat)
{
    pUser->dwFlags = nFlags;
    const unsigned char nResult = sub_00446D90_ParseStatString(pUser, nFlags, pStat);
    SStrCopy(pUser->szName, szName, 0x7FFFFFFF);

    int nMode = 5;
    if ((pUser->wFlags & 4) && !(pUser->wFlags & 8) && (sub_00408F20_HasExpansionMpq() || nResult < 5))
    {
        nMode = 1;
    }

    sub_00504F80_UpdateComposite(pUser->pComposite, nResult, nMode, pUser->aComponents, pUser->aColors);
    sub_004471B0_UpdateUserText(pUser);
    sub_00447BB0_Refresh();
}

// calling-convention shim (not game code)
void __fastcall Caller_00447FD0(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat)
{
    sub_00447FD0_UpdateUser(pUser, nFlags, szName, pStat);
}
