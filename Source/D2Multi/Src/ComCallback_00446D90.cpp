#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

extern "C" int __cdecl rand();                                                                              // 0x00687461

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl strcmp(const char* szA, const char* szB);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260

const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0

int __fastcall sub_0043E630_ShowChannelText(Unicode* pText);                                                // 0x0043E630

void __fastcall sub_00447400_SetNamedValue(const char* szName, const char* szValue);                        // 0x00447400

void __fastcall sub_00448BD0_UpdateScroll(int nDelta);                                                      // 0x00448BD0

void __stdcall sub_00504270_SetCompositeText(D2CompositeStrc* pComposite, Unicode* wszName, Unicode* wszAccount, Unicode* wszS97, Unicode* wszRealm, int nLevel, unsigned int dwCode); // 0x00504270

D2CompositeStrc* __stdcall sub_005066C0(int nA, int nMode, unsigned char* pComponents, unsigned char* pColors); // 0x005066C0

char gData_00798D30[256]; // 0x00798D30

extern D2MultiChannelUserStrc* gpChannelUsers_00798F34;                                                          // 0x00798F34

extern int gnChannelLines_00798F40;                                                                         // 0x00798F40

extern int gbRandSeeded_00798F54;                                                                           // 0x00798F54

static __declspec(noinline) unsigned char sub_00446D90_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat);

static unsigned char sub_00446D90_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat);

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

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0

extern D2WinSmackStrc* gpSmack_0077B098; // 0x0077B098

extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C; // 0x0077B09C

extern int gnVideoId_0077B0A4; // 0x0077B0A4

extern char gszText_00798CF8[]; // 0x00798CF8

extern char gszTempFile_00798E30[]; // 0x00798E30

extern D2LaunchMsgHandler gpfnMsgHandlers_0070EC20[]; // 0x0070EC20

extern "C" const char szLaunchFile_006D5810[]; // 0x006D5810

extern "C" const char gszChannelCountFormat_006D5994[]; // 0x006D5994

static __declspec(noinline) void sub_004471B0_UpdateUserText(D2MultiChannelUserStrc* pUser);

static __declspec(noinline) void __fastcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat);

struct D2ChannelEntryStrc;

struct D2LaunchCharInfoStrc;

int __fastcall sub_0043E610_PrintText(Unicode* pText, int nColor); // 0x0043E610

void __stdcall sub_00446A90_RemoveTableString(Unicode* pText); // 0x00446A90

void __cdecl sub_00448050_ClearSelectedUser(); // 0x00448050

D2MultiChannelUserStrc* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA); // 0x00449050

int __stdcall sub_005041B0_Destroy(D2CompositeStrc* pComposite, int nFlag); // 0x005041B0

Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

extern D2MultiChannelUserStrc* gpSelectedChannelUser_00798F48; // 0x00798F48

extern D2WinControlStrc* gapChatButtons_0077AD78[]; // 0x0077AD78

extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8

extern D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

extern int gnChannelScroll_00798F44; // 0x00798F44

int gbShowJoinLeave_0077BD54; // 0x0077BD54

extern "C" void _ReadWriteBarrier();

#pragma intrinsic(_ReadWriteBarrier)

struct D2CompositeUnitStrc;

union D2ChannelFlagsStrc
{
    unsigned int dwFlags;
    unsigned char nFlags;
    struct
    {
        unsigned int bFlag01 : 1;
        unsigned int bFlag02 : 1;
        unsigned int bFlag04 : 1;
        unsigned int bFlag08 : 1;
        unsigned int bFlag10 : 1;
        unsigned int bFlag20 : 1;
    };
};

struct D2ChatChannelMemberStrc
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x3];
    union
    {
        unsigned short wFlags8A;
        struct
        {
            unsigned short nLow8A : 5;
            unsigned short bExp8A : 1;
            unsigned short nMid8A : 2;
            unsigned short nLevel8A : 5;
        };
    };
    char unk0x8C[0x4];
    D2ChannelFlagsStrc tFlags90;
    char nValue94;
    char unk0x95[0x7];
    D2CompositeUnitStrc* pComposite;
    int nValue0xA0;
    int unk0xA4;
    int nValue0xA8;
    int unk0xAC;
    D2ChatChannelMemberStrc* pNext;
};

void __stdcall D2Win_10152(D2CompositeUnitStrc* pCompositeUnit, int nY);                                    // 0x005052B0

void __stdcall D2Win_10156(D2CompositeUnitStrc* hCompositeUnit, int nFlags); // 0x00505360


extern unsigned int gdwInvBitMasks[];                                                                       // 0x006CE2E8




#define CHAN_SETBIT(x, n, cond) if (cond) x |= gdwBitMasks[n]; else x &= gdwInvBitMasks[n]

#pragma intrinsic(strcmp)

#define D2_STACKARG(x) (x)


class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};


void __fastcall sub_00447940_PrependNumberText(Unicode* pText, int nValue);                                 // 0x00447940

void __fastcall sub_00447870_AppendNumberText(Unicode* pText, int nValue);                                  // 0x00447870

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

void __fastcall sub_00447560_SplitName(const char* szName, char* szTitle, char* szOut);                     // 0x00447560

static void sub_004471B0_UpdateUserText(D2MultiChannelUserStrc* pUser);

static void __fastcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const char* szName, const unsigned char* pStat);

int __fastcall sub_004480D0_OnUserUpdate(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat);

D2ChannelEntryStrc* gpChannelEntries_00798F38; // 0x00798F38

int gnChannelEntries_00798F3C; // 0x00798F3C

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

// 0x00446D90
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
            for (; i < 16; ++i)
            {
                pUser->aComponents[i] = 0xFF;
            }

            if (!pUser->aComponents[0])
            {
                goto LABEL_UNKNOWN_CODE;
            }

            pUser->nClass = *pStat++ - 1;

            for (i = 0; i < 11; ++i)
            {
                pUser->aColors[i] = *pStat++;
            }
            for (; i < 16; ++i)
            {
                pUser->aColors[i] = 0xFF;
            }

            pUser->wLevel = *pStat++;

            pUser->wFlags = sub_006BBF20_ReadPackedWord(pStat);
            unsigned int wFlags = pUser->wFlags;
            pUser->bFlagA0 = (wFlags >> 2) & 1;
            pUser->bFlagA4 = (wFlags >> 3) & 1;
            pUser->bFlagA8 = (wFlags >> 5) & 1;
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
LABEL_UNKNOWN_CODE:
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
            pUser->aComponents[i] = 1;
        }
        else
        {
            pUser->aComponents[i] = 0;
        }
        pUser->aColors[i] = 0xFF;
    }

    return nResult;
}

D2MultiChannelUserStrc* __stdcall sub_00449050_AddEntry(const char* szName, const unsigned char* pStat, unsigned int nFlags)
{
    for (D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34; pUser; pUser = pUser->pNext)
    {
        const char* szUserName = strchr(pUser->szName, '*');
        szUserName = !szUserName ? pUser->szName : szUserName + 1;
        const char* szNewName = strchr(szName, '*');
        szNewName = !szNewName ? szName : szNewName + 1;
        if (!strcmp(szUserName, szNewName))
        {
            sub_00447FD0_UpdateUser(pUser, nFlags, szName, pStat);
            return pUser;
        }
    }

    D2MultiChannelUserStrc* pUser = (D2MultiChannelUserStrc*)FOG_Alloc(sizeof(D2MultiChannelUserStrc), ".\\Src\\ComCallback.cpp", 0x6D4, 0);
    memset(pUser, 0, sizeof(D2MultiChannelUserStrc));
    strcpy(pUser->szName, szName);
    pUser->dwFlags = nFlags;

    const unsigned char nResult = sub_00446D90_ParseStatString(pUser, nFlags, pStat);
    int nMode = 5;
    if ((pUser->wFlags & 4) && !(pUser->wFlags & 8) && !(pUser->dwFlags & 2) && (sub_00408F20_HasExpansionMpq() || nResult < 5))
    {
        nMode = 1;
    }

    pUser->pComposite = sub_005066C0(nResult, nMode, pUser->aComponents, pUser->aColors);
    if (!pUser->pComposite)
    {
        pUser->nClass = 7;
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

        pUser->pComposite = sub_005066C0(pUser->nClass, 5, pUser->aComponents, pUser->aColors);
    }

    D2_ASSERT(pUser->pComposite, 0x708);
    sub_005052F0(pUser->pComposite, 0x23B);
    sub_005051A0(pUser->pComposite, 0);

    if (!gbRandSeeded_00798F54)
    {
        srand(GetTickCount());
        gbRandSeeded_00798F54 = 1;
    }

    const int nFrames = D2Win_10169(pUser->pComposite) << 8;
    sub_00505260(pUser->pComposite, rand() % nFrames);
    sub_004471B0_UpdateUserText(pUser);

    if (gpChannelUsers_00798F34)
    {
        D2MultiChannelUserStrc* pLast = gpChannelUsers_00798F34;
        while (pLast->pNext)
        {
            pLast = pLast->pNext;
        }
        pLast->pNext = pUser;
    }
    else
    {
        gpChannelUsers_00798F34 = pUser;
    }

    sub_00447400_SetNamedValue(pUser->szName, pUser->szText);

    char szText[0x100];
    ++gnChannelLines_00798F40;
    sprintf(szText, "%s (%d)", gData_00798D30, gnChannelLines_00798F40);

    Unicode wszText[0x240];
    Unicode::win2Unicode(wszText, szText, 0x240);
    sub_0043E630_ShowChannelText(wszText);
    sub_00448BD0_UpdateScroll(0);
    sub_00447BB0_Refresh();
    return pUser;
}


// 0x004471B0
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

// 0x00447AB0
static __declspec(noinline) int __stdcall sub_00447AB0_AddChatLine(const char* szText, int nColor)
{
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, nColor);
    return 1;
}

static inline int CHAN_GetRank(const D2ChannelFlagsStrc* pFlags)
{
    const D2ChannelFlagsStrc tFlags = *pFlags;
    if (tFlags.dwFlags & 2)
        return 4;
    if (tFlags.dwFlags & 8)
        return 3;
    if (tFlags.dwFlags & 1)
        return 2;
    if (tFlags.nFlags & 4)
        return 1;
    return 0;
}

static inline int CHAN_GetLevelClass(D2ChatChannelMemberStrc* pUser)
{
    const int nLevel = pUser->nLevel8A;
    if (pUser->bExp8A)
    {
        if (nLevel >= 15)
            return 3;
        if (nLevel >= 10)
            return 2;
        return nLevel >= 5;
    }
    if (nLevel >= 12)
        return 3;
    if (nLevel >= 8)
        return 2;
    return nLevel >= 4;
}

// 0x00447BB0
void __cdecl sub_00447BB0_Refresh()
{
    int n;
    if (gpChannelUsers_00798F34)
    {
        D2ChatChannelMemberStrc* pSorted = (D2ChatChannelMemberStrc*)gpChannelUsers_00798F34;
        D2ChatChannelMemberStrc** ppNext = (D2ChatChannelMemberStrc**)&gpChannelUsers_00798F34->pNext;
        D2ChatChannelMemberStrc* pList = *ppNext;
        _ReadWriteBarrier();
        *ppNext = 0;
        while (pList)
        {
            n = CHAN_GetRank(&pList->tFlags90);
            D2ChatChannelMemberStrc* pPrev = 0;
            int bInserted = 0;
            D2ChatChannelMemberStrc* pCur = pSorted;
            while (pCur && !bInserted)
            {
                if (n > CHAN_GetRank(&pCur->tFlags90))
                {
                    D2ChatChannelMemberStrc* pInsert = pList;
                    pList = pInsert->pNext;
                    pInsert->pNext = pCur;
                    if (pPrev)
                    {
                        pPrev->pNext = pInsert;
                        bInserted = 1;
                    }
                    else
                    {
                        pSorted = pInsert;
                        bInserted = 1;
                    }
                }
                else
                {
                    pPrev = pCur;
                    pCur = pCur->pNext;
                }
            }

            if (!bInserted)
            {
                pPrev->pNext = pList;
                D2ChatChannelMemberStrc* pLast = pList;
                pList = pLast->pNext;
                pLast->pNext = 0;
            }
        }
        gpChannelUsers_00798F34 = (D2MultiChannelUserStrc*)pSorted;
    }

    D2ChatChannelMemberStrc* pUser = (D2ChatChannelMemberStrc*)gpChannelUsers_00798F34;
    int nY = 0x46;
    n = 0;
    if (gpChannelUsers_00798F34)
    do
    {
        unsigned int nState;
        D2ChannelFlagsStrc tFlags;
        if (n >= gnChannelScroll_00798F44 && n < gnChannelScroll_00798F44 + 11)
        {
            D2Win_10152(pUser->pComposite, nY);
            nState = 0xF;
            CHAN_SETBIT(nState, 11, pUser->tFlags90.dwFlags & 9);
            const unsigned short wFlags = pUser->wFlags8A;
            CHAN_SETBIT(nState, 4, wFlags & 8);
            CHAN_SETBIT(nState, 5, wFlags & 4);
            CHAN_SETBIT(nState, 12, wFlags & 0x20);
            const int nLevelClass = CHAN_GetLevelClass(pUser);
            CHAN_SETBIT(nState, 6, nLevelClass & 1);
            CHAN_SETBIT(nState, 7, nLevelClass & 2);
            if (n & 1)
                nState |= gdwBitMasks[8];
            CHAN_SETBIT(nState, 9, pUser->tFlags90.nFlags & 0x20);
            CHAN_SETBIT(nState, 10, pUser == (D2ChatChannelMemberStrc*)gpSelectedChannelUser_00798F48);
            nY += 0x3C;
        }
        else
        {
            tFlags = pUser->tFlags90;
            nState = 0;
            CHAN_SETBIT(nState, 11, tFlags.dwFlags & 9);
            const unsigned short wFlags = pUser->wFlags8A;
            CHAN_SETBIT(nState, 4, wFlags & 8);
            CHAN_SETBIT(nState, 5, wFlags & 4);
            CHAN_SETBIT(nState, 12, wFlags & 0x20);
            const D2LaunchCharInfoStrc* pCharInfo = *(D2LaunchCharInfoStrc* volatile*)&gpCharInfo_0077BBD8;
            int bDiffers = pCharInfo->nValue3C2 != pUser->nValue94;
            const unsigned short wCharFlags = *(const unsigned short*)pCharInfo->wFlags;
            bDiffers |= (wCharFlags & 4) && !pUser->nValue0xA0;
            bDiffers |= !(wCharFlags & 4) && pUser->nValue0xA0;
            bDiffers |= (wCharFlags & 0x20) && !pUser->nValue0xA8;
            bDiffers |= !(wCharFlags & 0x20) && pUser->nValue0xA8;
            CHAN_SETBIT(nState, 13, bDiffers);
            const int nLevelClass = CHAN_GetLevelClass(pUser);
            CHAN_SETBIT(nState, 6, nLevelClass & 1);
            CHAN_SETBIT(nState, 7, nLevelClass & 2);
            CHAN_SETBIT(nState, 9, tFlags.dwFlags & 0x20);
            CHAN_SETBIT(nState, 10, pUser == (D2ChatChannelMemberStrc*)gpSelectedChannelUser_00798F48);
        }
        D2Win_10156(pUser->pComposite, nState);
        n++;
        pUser = pUser->pNext;
    } while (pUser);
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

// 0x004480D0
int __fastcall sub_004480D0_OnUserUpdate(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat)
{
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
        do
        {
            if (!strcmp(pUser->szName, szName))
            {
                sub_00447FD0_UpdateUser(pUser, nFlags, szName, pStat);
                return 1;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }

    return 0;
}

static const char* SkipStarPrefix_Inl(const char* szName)
{
    const char* p = SStrChr(szName, '*');
    if (p)
    {
        p++;
        if (*p)
        {
            return p;
        }
    }
    return szName;
}

static void __stdcall sub_00447B00_PrintChannelLine(const char* szText, int nPrefix, const char* szName, int nColor)
{
    Unicode wszName[0x240];
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszName[i].wChar = 0;
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    Unicode::win2Unicode(wszName, szName, 0x240);
    Unicode::win2Unicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszName);
    sub_00446A90_RemoveTableString(wszText);
    sub_00447940_PrependNumberText(wszName, nPrefix);
    sub_00447870_AppendNumberText(wszName, nColor);
    sub_00526700(wszName, wszText);
    sub_0043E610_PrintText(wszName, nColor);
}

static __declspec(noinline) void __stdcall sub_004481B0_PrintNamedLine(const char* szText, int nPrefix, const char* szName, int nColor)
{
    char szBuffer[0x100];
    sprintf(szBuffer, "<%s> ", szName);
    sub_00447B00_PrintChannelLine(szText, nPrefix, szBuffer, nColor);
}

// 0x004481F0
void __fastcall sub_004481F0_PrintOwnLine(const char* szText)
{
    char szName[0x100];
    char szOut[0x100];
    char szPlain[0x100];
    char szTitle[0x100];
    SStrCopy(szName, gpLaunchFuncs_0077B09C->pfnGetUserName(), 0x7FFFFFFF);
    int nPrefix = 4;
    int nColor = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
        do
        {
            if (!strcmp(SkipStarPrefix_Inl(pUser->szName), szName))
            {
                SStrCopy(szName, pUser->szName, 0x7FFFFFFF);
                if (pUser->dwFlags & 2)
                    nPrefix = 0;
                else if (pUser->dwFlags & 1)
                    nPrefix = nColor = 3;
                else if (pUser->dwFlags & 8)
                    nPrefix = nColor = 3;
                break;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }
    sub_00447560_SplitName(szName, szTitle, szPlain);
    if (strlen(szPlain))
    {
        if (strlen(szTitle))
            sprintf(szOut, "<%s%s> ", szTitle, szPlain);
        else
            sprintf(szOut, "<%s> ", szPlain);
    }
    else
    {
        sprintf(szOut, "<%s> ", szName);
    }
    sub_00447B00_PrintChannelLine(szText, nPrefix, szOut, nColor);
}

// 0x00449350
static __declspec(noinline) void sub_00449350_ShowUserJoined(const char* szName, int nLength, int nA)
{
    D2MultiChannelUserStrc* pUser = sub_00449050_AddEntry(szName, nLength, nA);
    if (!gbShowJoinLeave_0077BD54)
    {
        return;
    }

    char szText[500];
    if (strlen(pUser->szText))
    {
        sprintf(szText, "%s has joined the channel.", pUser->szText);
    }
    else
    {
        sprintf(szText, "%s has joined the channel.", szName);
    }
    sub_00447AB0_AddChatLine(szText, 5);
}

// 0x004493C0
int __fastcall sub_004493C0_OnUserJoin(int nA, int nB, const char* szText, int nLength)
{
    sub_00449350_ShowUserJoined(szText, nLength, nA);
    return 1;
}

// 0x004493E0
void __stdcall sub_004493E0_RemoveChannelUser(const char* szName)
{
    D2MultiChannelUserStrc* pPrev = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
    while (pUser)
    {
        const char* szA = strchr(pUser->szName, '*');
        if (!szA)
        {
            szA = pUser->szName;
        }
        else
        {
            szA += 1;
        }
        const char* szB = strchr(szName, '*');
        if (!szB)
        {
            szB = szName;
        }
        else
        {
            szB += 1;
        }
        if (!strcmp(szA, szB))
        {
            break;
        }
        pPrev = pUser;
        pUser = pUser->pNext;
    }

    if (pUser)
    {
        if (gbShowJoinLeave_0077BD54)
        {
            char szText[500];
            if (pUser->szText && strlen(pUser->szText))
            {
                sprintf(szText, "%s has left the channel.", pUser->szText);
            }
            else
            {
                sprintf(szText, "%s has left the channel.", pUser->szName);
            }
            sub_00447AB0_AddChatLine(szText, 5);
        }

        if (pPrev)
        {
            pPrev->pNext = pUser->pNext;
        }
        else
        {
            gpChannelUsers_00798F34 = pUser->pNext;
        }

        if (gpSelectedChannelUser_00798F48 == pUser)
        {
            sub_00448050_ClearSelectedUser();
        }

        sub_005041B0_Destroy(pUser->pComposite, 1);
        pUser->pComposite = 0;
        FOG_Free(pUser, ".\\Src\\ComCallback.cpp", 0x7FE, 0);
    }
    }

    gnChannelLines_00798F40 -= 1;
    char szCount[0x100];
    sprintf(szCount, "%s (%d)", gData_00798D30, gnChannelLines_00798F40);
    Unicode wszCount[0x240];
    sub_00526F20_ToUnicode(wszCount, szCount, 0x240);
    sub_0043E630_ShowChannelText(wszCount);
    sub_00448BD0_UpdateScroll(0);
    sub_00447BB0_Refresh();
}

// 0x004495A0
void __cdecl sub_004495A0_ClearChannel()
{
    char szText[0x100];
    sub_00448050_ClearSelectedUser();
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    while (pUser)
    {
        D2MultiChannelUserStrc* pNext = pUser->pNext;
        sub_005041B0_Destroy(pUser->pComposite, 1);
        pUser->pComposite = 0;
        FOG_Free(pUser, ".\\Src\\ComCallback.cpp", 0x822, 0);
        pUser = pNext;
    }
    gpChannelUsers_00798F34 = 0;
    D2ChannelEntryStrc* pEntry = gpChannelEntries_00798F38;
    while (pEntry)
    {
        D2ChannelEntryStrc* pNext = pEntry->pNext;
        FOG_Free(pEntry, ".\\Src\\ComCallback.cpp", 0x82A, 0);
        pEntry = pNext;
    }
    gpChannelEntries_00798F38 = 0;
    gnChannelEntries_00798F3C = 0;
    gnChannelLines_00798F40 = 0;
    sprintf(szText, "%s (%d)", gData_00798D30, 0);
    Unicode wszText[0x240];
    sub_00526F20_ToUnicode(wszText, szText, 0x240);
    sub_0043E630_ShowChannelText(wszText);
    gnChannelScroll_00798F44 = 0;
    sub_00448BD0_UpdateScroll(0);
}

// 0x004496B0
int __fastcall sub_004496B0_OnJoinChannel(int nA, int nB, int nC, const char* szChannel)
{
    char szText[500];
    sprintf(szText, "You have joined channel: %s", szChannel);
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    sub_00446A90_RemoveTableString(wszText);
    sub_0043E610_PrintText(wszText, 5);
    strcpy(gData_00798D30, szChannel);
    strcpy(gpCharInfo_0077BBD8->szRealm0x361, gData_00798D30);
    if (!gpCharInfo_0077BBD8->szRealm0x381[0])
    {
        strcpy(gpCharInfo_0077BBD8->szRealm0x381, gData_00798D30);
    }
    for (int i = 0; i < 11; i++)
    {
        sub_004F96F0_ControlClearState(gapChatButtons_0077AD78[i], 1);
    }
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    sub_004495A0_ClearChannel();
    return 1;
}

// build: context sub_00448370_OnChannelTalk
int __stdcall sub_00448370_OnChannelTalk(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szOut[0x100];
    sub_00447560_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
        return 1;

    int nPrefix = 4;
    int nColor = 0;
    for (D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34; pUser; pUser = pUser->pNext)
    {
        if (!strcmp(pUser->szName, szSender))
        {
            if (pUser->dwFlags & 2)
                nPrefix = 0;
            else if (pUser->dwFlags & 1)
                nPrefix = nColor = 3;
            else if (pUser->dwFlags & 8)
                nPrefix = nColor = 3;
            break;
        }
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
            sprintf(szOut, "%s%s", szTitle, szName);
        else
            strcpy(szOut, szName);
        sub_004481B0_PrintNamedLine(szMessage, nPrefix, szOut, nColor);
    }
    else
    {
        sub_004481B0_PrintNamedLine(szMessage, nPrefix, szSender, nColor);
    }
    return 1;
}

#include "gen/data/Source/D2Multi/Src/ComCallback_00446D90.inc"
