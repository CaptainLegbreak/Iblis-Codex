int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, unsigned int nCount); // 0x00682591
extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040
extern "C" long __cdecl strtol(const char* szString, char** ppEnd, int nRadix); // 0x0068676E
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

struct OptionInfoStrc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pTarget;
    int nParam24;
    int nParam28;
    int nValue;
};

typedef int (__stdcall* OptionCallback)(OptionInfoStrc* pInfo, const char* szString);

struct OptionStrc
{
    OptionStrc* pPrev;
    OptionStrc* pNext;
    unsigned int dwFlags;
    unsigned int dwId;
    char szName[0x10];
    int nNameLength;
    int nParam24;
    int nParam28;
    void* pTarget;
    unsigned int nTargetSize;
    OptionCallback pfnCallback;
    int bSet;
    union
    {
        int nValue;
        char* szValue;
    };
};

struct OptionListStrc
{
    int nLinkOffset;
    OptionStrc* pTail;
    OptionStrc* pHead;
};

struct OptionContextStrc
{
    OptionStrc* pCurrent;
    char szBuffer[0x10];
    int nMinLength;
};

extern OptionListStrc gOptionList_0074C48C; // 0x0074C48C
extern const char gszSCmdFile_006FCC30[]; // 0x006FCC30
extern OptionListStrc gOptionList_0074C498; // 0x0074C498

static __forceinline OptionStrc* OPTION_Next(OptionStrc* pLink)
{
    return (int)pLink > 0 ? pLink : 0;
}

// 0x006C3CB0

static void __stdcall sub_006C3CB0_ParseBool(int* pLength, OptionStrc* pOption, const char* szString)
{
    int bOn;
    if (*szString == '-')
    {
        bOn = 0;
        *pLength = 1;
    }
    else if (*szString == '+')
    {
        bOn = 1;
        *pLength = 1;
    }
    else
    {
        bOn = ((unsigned char)pOption->dwFlags & 1) != 1;
    }

    pOption->nValue &= ~pOption->nParam28;
    if (bOn)
    {
        pOption->nValue |= pOption->nParam24;
    }

    if (pOption->pTarget)
    {
        *(int*)pOption->pTarget &= ~pOption->nParam28;
        if (bOn)
        {
            *(int*)pOption->pTarget |= pOption->nParam24;
        }
    }
}

// 0x006C3DA0

static void __stdcall sub_006C3DA0_ParseString(OptionStrc* pOption, const char* szString, int* pLength)
{
    *pLength = SStrLen(szString);
    if (pOption->szValue)
    {
        SMemFree(pOption->szValue, gszSCmdFile_006FCC30, 0x8B, 0);
    }
    pOption->szValue = (char*)SMemAlloc(SStrLen(szString) + 1, gszSCmdFile_006FCC30, 0x8C, 0);
    SStrCopy(pOption->szValue, szString, 0x7FFFFFFF);
    if (pOption->pTarget)
    {
        SStrCopy((char*)pOption->pTarget, szString, pOption->nTargetSize);
    }
}

// 0x006C3D20
static void __stdcall sub_006C3D20_ParseInteger(OptionStrc* pOption, const char* szString, int* pLength)
{
    char* pEnd = 0;
    if (pOption->dwFlags & 1)
        pOption->nValue = strtol(szString, &pEnd, 0);
    else
        pOption->nValue = strtoul(szString, &pEnd, 0);

    if (pEnd)
        *pLength = pEnd - szString;
    else
        *pLength = SStrLen(szString);

    if (pOption->pTarget)
    {
        unsigned int nSize = pOption->nTargetSize;
        if (nSize > 4)
            nSize = 4;
        SMemCopy(pOption->pTarget, &pOption->nValue, nSize);
    }
}

// 0x006C42E0
static OptionStrc* __stdcall sub_006C42E0_FindLongestPrefix(const char* szString, int nMinLength, OptionStrc* pHead)
{
    int nStringLength = SStrLen(szString);
    int nBestLength = nMinLength - 1;
    OptionStrc* pBest = 0;
    for (OptionStrc* pNode = pHead; pNode; pNode = (int)pNode->pNext > 0 ? pNode->pNext : 0)
    {
        if (pNode->nNameLength > nBestLength && pNode->nNameLength <= nStringLength)
        {
            int bMatch;
            if (pNode->dwFlags & 0x100)
                bMatch = !strncmp(pNode->szName, szString, pNode->nNameLength);
            else
                bMatch = !_strnicmp(pNode->szName, szString, pNode->nNameLength);

            if (bMatch)
            {
                nBestLength = pNode->nNameLength;
                pBest = pNode;
            }
        }
    }
    return pBest;
}

// 0x006C4820
static int __stdcall sub_006C4820_ParseOption(const char* szString, int* pLength, OptionStrc* pOption)
{
    *pLength = 0;
    switch (pOption->dwFlags & 0x30000)
    {
    case 0:
        sub_006C3CB0_ParseBool(pLength, pOption, szString);
        break;
    case 0x10000:
        sub_006C3D20_ParseInteger(pOption, szString, pLength);
        break;
    case 0x20000:
        sub_006C3DA0_ParseString(pOption, szString, pLength);
        break;
    default:
        return 0;
    }

    pOption->bSet = 1;
    if (pOption->pfnCallback)
    {
        OptionInfoStrc info;
        info.dwFlags = pOption->dwFlags;
        info.dwId = pOption->dwId;
        info.szName = pOption->szName;
        info.pTarget = pOption->pTarget;
        info.nParam24 = pOption->nParam24;
        info.nParam28 = pOption->nParam28;
        info.nValue = pOption->nValue;
        if (!pOption->pfnCallback(&info, szString))
            return 0;
    }

    int nPass = 0;
    do
    {
        OptionListStrc* pList = nPass ? &gOptionList_0074C498 : &gOptionList_0074C48C;
        for (OptionStrc* pOther = pList->pHead; (int)pOther > 0; pOther = pOther->pNext)
        {
            if (pOther->dwId == pOption->dwId
                && (pOther->dwFlags & 0x30000) == (pOption->dwFlags & 0x30000)
                && pOther != pOption)
            {
                pOther->bSet = 1;
                if ((pOther->dwFlags & 0x30000) == 0x20000)
                {
                    if (pOther->szValue)
                        SMemFree(pOther->szValue, gszSCmdFile_006FCC30, 0x120, 0);
                    pOther->szValue = (char*)SMemAlloc(SStrLen(pOption->szValue) + 1, gszSCmdFile_006FCC30, 0x121, 0);
                    SStrCopy(pOther->szValue, pOption->szValue, 0x7FFFFFFF);
                }
                else
                {
                    pOther->nValue = pOption->nValue;
                }
            }
        }
        ++nPass;
    } while (nPass <= 1);
    return 1;
}

// 0x006C4980
static int __stdcall sub_006C4980_ApplyOptions(OptionContextStrc* pContext, const char* szString, int* pLength)
{
    *pLength = 0;
    OptionStrc* pOption = pContext->pCurrent;
    pContext->pCurrent = 0;
    while (pOption)
    {
        int nOptionLength;
        if (!sub_006C4820_ParseOption(szString, &nOptionLength, pOption))
        {
            return 0;
        }

        *pLength = *pLength > nOptionLength ? *pLength : nOptionLength;

        pOption = sub_006C42E0_FindLongestPrefix(pContext->szBuffer, pContext->nMinLength, OPTION_Next(pOption->pNext));
    }

    return 1;
}

// build: context sub_006C4980_Shim
// calling-convention shim (not game code)
int __stdcall sub_006C4980_Shim(OptionContextStrc* pContext, const char* szString, int* pLength)
{
    return sub_006C4980_ApplyOptions(pContext, szString, pLength);
}
