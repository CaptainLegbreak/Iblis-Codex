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
extern char gData_00798D30[];                                                                               // 0x00798D30
D2MultiChannelUserStrc* gpChannelUsers_00798F34;                                                                 // 0x00798F34
int gnChannelLines_00798F40;                                                                                // 0x00798F40
int gbRandSeeded_00798F54;                                                                                  // 0x00798F54

static __forceinline int CHANNEL_IsMaleClass(int nClass)
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

static unsigned char sub_00446D90_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat);

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
                goto LABEL_UNKNOWN_CODE;
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

static void __stdcall sub_00447FD0_UpdateUser(D2MultiChannelUserStrc* pUser, const unsigned char* pStat, unsigned int nFlags, const char* szName)
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

int __fastcall sub_004480D0_OnUserUpdate(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat)
{
    for (D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34; pUser; pUser = pUser->pNext)
    {
        if (!strcmp(pUser->szName, szName))
        {
            sub_00447FD0_UpdateUser(pUser, pStat, nFlags, szName);
            return 1;
        }
    }

    return 0;
}

// 0x00449050
D2MultiChannelUserStrc* __stdcall sub_00449050_AddEntry(const char* szName, const unsigned char* pStat, unsigned int nFlags)
{
    D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
    if (gpChannelUsers_00798F34)
    {
        while (pUser)
        {
            const char* szUserName = strchr(pUser->szName, '*');
            szUserName = !szUserName ? pUser->szName : szUserName + 1;
            const char* szNewName = strchr(szName, '*');
            szNewName = !szNewName ? szName : szNewName + 1;
            if (!strcmp(szUserName, szNewName))
            {
                sub_00447FD0_UpdateUser(pUser, pStat, nFlags, szName);
                return pUser;
            }
            pUser = pUser->pNext;
        }
    }

    pUser = (D2MultiChannelUserStrc*)FOG_Alloc(sizeof(D2MultiChannelUserStrc), ".\\Src\\ComCallback.cpp", 0x6D4, 0);
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
                pUser->aComponents[i] = 1;
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
        D2MultiChannelUserStrc** ppNext = &gpChannelUsers_00798F34->pNext;
        while (pLast->pNext)
        {
            pLast = *ppNext;
            ppNext = &pLast->pNext;
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
