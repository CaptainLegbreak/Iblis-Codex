#include "D2StormTypes.h"
#include "D2StormAutoLink.h"
// build: base-profile

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

static inline OptionStrc* OPTION_Next(OptionStrc* pLink)
{
    return (int)pLink > 0 ? pLink : 0;
}

// 0x006C3CB0
static void __stdcall ConvertBool(int* pLength, OptionStrc* pOption, const char* szString)
{
    int bValue;
    if (*szString == '-')
    {
        bValue = 0;
        *pLength = 1;
    }
    else if (*szString == '+')
    {
        bValue = 1;
        *pLength = 1;
    }
    else
    {
        bValue = (unsigned char)((pOption->dwFlags & 1) - 1) != 0;
    }

    int nMask = ~pOption->nParam28;
    pOption->nValue &= nMask;
    if (bValue)
        pOption->nValue |= pOption->nParam24;

    if (pOption->pTarget)
    {
        *(int*)pOption->pTarget &= nMask;
        if (bValue)
            *(int*)pOption->pTarget |= pOption->nParam24;
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

// 0x006C3DA0
static void __stdcall sub_006C3DA0_ParseString(OptionStrc* pOption, const char* szString, int* pLength)
{
    *pLength = SStrLen(szString);
    if (pOption->szValue)
        SMemFree(pOption->szValue, gszSCmdFile_006FCC30, 0x8B, 0);
    pOption->szValue = (char*)SMemAlloc(SStrLen(szString) + 1, gszSCmdFile_006FCC30, 0x8C, 0);
    SStrCopy(pOption->szValue, szString, 0x7FFFFFFF);
    if (pOption->pTarget)
        SStrCopy((char*)pOption->pTarget, szString, pOption->nTargetSize);
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
        ConvertBool(pLength, pOption, szString);
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
        int nLength;
        if (!sub_006C4820_ParseOption(szString, &nLength, pOption))
            return 0;

        *pLength = *pLength > nLength ? *pLength : nLength;

        pOption = sub_006C42E0_FindLongestPrefix(pContext->szBuffer, pContext->nMinLength, OPTION_Next(pOption->pNext));
    }
    return 1;
}

extern const char* gszErrorDefaults_006FCC24[]; // 0x006FCC24
extern const char gszPercentS_006FFC58[]; // 0x006FFC58
extern const char gszNewline_006FFCB0[]; // 0x006FFCB0
void* __cdecl StormGetInstance(); // 0x0041BEF0
unsigned int __stdcall SStrPack(char*, const char*, unsigned int); // 0x00413800
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" __declspec(dllimport) int __stdcall LoadStringA(void*, unsigned int, char*, int);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...);

static

// build: context GenerateError
void __stdcall GenerateError(D2ErrorCallback callback, unsigned int error, const char* context)
{
    D2ErrorReportStrc report;
    report.callback = callback;
    char format[256];
    char message[256];
    int index;
    unsigned int resource;
    switch (error)
    {
    case 0x85100065:
        index = 0;
        resource = 0x5201;
        break;
    case 0x8510006D:
        index = 1;
        resource = 0x5202;
        break;
    case 110:
        index = 2;
        resource = 0x5203;
        break;
    default:
        return;
    }
    format[0] = 0;
    LoadStringA(StormGetInstance(), resource, format, 256);
    if (!format[0])
        SStrCopy(format, gszErrorDefaults_006FCC24[index], 256);
    if (strstr(format, gszPercentS_006FFC58))
        wsprintfA(message, format, context);
    else
        SStrCopy(message, format, 256);
    if (message[0])
        SStrPack(message, gszNewline_006FFCB0, 256);
    sub_0041C340_SetLastError(error);
    report.error = error;
    report.context = context;
    report.message = message;
    report.callback(&report);
}

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

#define OPTION_MAX(a, b) ((a) < (b) ? (b) : (a))

static int __stdcall ProcessFlags(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError);

// build: context ProcessFlags
static int __stdcall ProcessFlags(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError)
{
    char szBuffer[0x100];
    szBuffer[0] = 0;
    while (*szString)
    {
        const int nStringLength = SStrLen(szString);
        unsigned int nPos = OPTION_MAX(SStrLen(szBuffer), 1);
        OptionStrc* pFound = 0;
        while (nPos--)
        {
            if ((int)(nPos + nStringLength) < 0x100)
            {
                SStrCopy(&szBuffer[nPos], szString, 0x100);
                pFound = sub_006C42E0_FindLongestPrefix(szBuffer, 0, OPTION_Next(gOptionList_0074C498.pHead));
                if (pFound)
                {
                    nPos = pFound->nNameLength;
                    szBuffer[nPos] = 0;
                    break;
                }
            }
        }

        if (!pFound)
        {
            if (pfnError)
            {
                GenerateError(pfnError, 0x85100065, szString);
            }

            return 0;
        }

        szString += nPos;
        while (SStrChr("=:", *szString))
        {
            ++szString;
        }

        pContext->pCurrent = pFound;
        pContext->nMinLength = nPos;
        SStrCopy(pContext->szBuffer, szBuffer, 0x7FFFFFFF);
        if (!*szString && (pFound->dwFlags & 0x30000))
        {
            return 1;
        }

        int nLength;
        if (!sub_006C4980_ApplyOptions(pContext, szString, &nLength))
        {
            return 0;
        }

        szString += nLength;
    }

    return 1;
}

typedef int (__stdcall* OptionCallbackToken)(const char* szToken);

static int __stdcall ProcessToken(const char* szToken, OptionContextStrc* pContext, OptionStrc** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError);
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetFileSize(void*, unsigned int*);
extern "C" __declspec(dllimport) int __stdcall ReadFile(void*, void*, unsigned int, unsigned int*, void*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
int __fastcall sub_006C4EC0_ParseCommandLine(const char** ppszCmdLine, OptionContextStrc* pContext, OptionStrc** ppOption, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError); // 0x006C4EC0

static

// build: context sub_006C3F50_ReadCommandFile
int __stdcall sub_006C3F50_ReadCommandFile(const char* file, OptionContextStrc* arg1, OptionStrc** arg2, OptionCallbackToken arg3, D2ErrorCallback callback)
{
    void* handle = CreateFileA(file, 0x80000000, 1, 0, 3, 0x08000000, 0);
    if (handle == (void*)-1)
    {
        if (callback)
            GenerateError(callback, 110, file);
        return 0;
    }
    unsigned int size = GetFileSize(handle, 0);
    char* buffer = (char*)SMemAlloc(size + 1, gszSCmdFile_006FCC30, 339, 0);
    unsigned int read;
    ReadFile(handle, buffer, size, &read, 0);
    CloseHandle(handle);
    buffer[read] = 0;
    const char* cursor = buffer;
    int result = sub_006C4EC0_ParseCommandLine(&cursor, arg1, arg2, arg3, callback);
    SMemFree(buffer, gszSCmdFile_006FCC30, 356, 0);
    return result;
}

void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted); // 0x00413B80
extern "C" const char gszCmdWhitespace_006FCC4C[];                                                         // 0x006FCC4C
extern "C" unsigned int __security_cookie;                                                                  // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie);                                   // 0x00681A48

// build: context ProcessToken
static int __stdcall ProcessToken(const char* szToken, OptionContextStrc* pContext, OptionStrc** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError)
{
    if (*szToken == '@' && !nQuoted)
    {
        return sub_006C3F50_ReadCommandFile(szToken + 1, pContext, ppOption, pfnCallback, pfnError);
    }

    if (SStrChr("-/", *szToken) && !nQuoted)
    {
        pContext->pCurrent = 0;
        return ProcessFlags(szToken + 1, pContext, pfnError);
    }

    int nLength;
    if (pContext->pCurrent)
    {
        return sub_006C4980_ApplyOptions(pContext, szToken, &nLength);
    }

    OptionStrc* pOption = *ppOption;
    if (pOption)
    {
        if (!sub_006C4820_ParseOption(szToken, &nLength, pOption))
        {
            return 0;
        }

        *ppOption = (int)(*ppOption)->pNext <= 0 ? 0 : (*ppOption)->pNext;
        return 1;
    }

    if (pfnCallback)
    {
        return pfnCallback(szToken);
    }

    if (pfnError)
    {
        GenerateError(pfnError, 0x85100065, szToken);
    }

    return 0;
}

// build: context sub_006C4EC0_ParseCommandLine
int __fastcall sub_006C4EC0_ParseCommandLine(const char** ppszCmdLine, OptionContextStrc* pnState, OptionStrc** pnContext, OptionCallbackToken pfnCallback, D2ErrorCallback pUserData)
{
    while (**ppszCmdLine)
    {
        const char* pszNext = *ppszCmdLine;
        int nQuoted = 0;
        char szToken[0x100];
        SStrTokenize(&pszNext, szToken, 0x100, gszCmdWhitespace_006FCC4C, &nQuoted);
        if (szToken[0] && !ProcessToken(szToken, pnState, pnContext, nQuoted, pfnCallback, pUserData))
        {
            break;
        }
        *ppszCmdLine = pszNext;
    }
    return **ppszCmdLine == 0;
}

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

extern const char gszEmpty_006CC837[]; // 0x006CC837
extern const char gszCmdDefType_0074C47C[]; // 0x0074C47C

struct D2CmdDefStrc
{
    D2StormLinkStrc link;
    unsigned int dwFlags;
    unsigned int dwId;
    char szName[16];
    int nNameLength;
    int bSet;
    void* pfnCallback;
    void* pVariable;
    unsigned int nBytes;
    void* pParam;
    int unk38;
    int nValue;
};

extern D2StormLinkStrc gtCommands_0074C490; // 0x0074C490
extern D2StormLinkStrc gtArguments_0074C49C; // 0x0074C49C

int gnGlobal_00989C38; // 0x00989C38

inline void* operator new(unsigned int, void* pPlace) throw() { return pPlace; }

// build: context NewCommand
static __forceinline D2CmdDefStrc* NewCommand(D2StormLinkStrc& terminator)
{
    D2CmdDefStrc* pNode = new (SMemAlloc(sizeof(D2CmdDefStrc), gszCmdDefType_0074C47C, -2, 8)) D2CmdDefStrc;
    D2StormLinkStrc* pLink = pNode ? &pNode->link : &terminator;
    pLink->Unlink();
    D2StormLinkStrc* pPrevLink = terminator.m_prevlink;
    pLink->m_prevlink = pPrevLink;
    pLink->m_next = pPrevLink->m_next;
    pPrevLink->m_next = (char*)pNode;
    terminator.m_prevlink = pLink;
    return pNode;
}

// 0x006C4580
int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam)
{
    if (!szName)
        szName = gszEmpty_006CC837;
    int nNameLength = SStrLen(szName);

    VALIDATEBEGIN;
    VALIDATE(nNameLength < 16);
    VALIDATE(!nBytes || pVariable);
    VALIDATE((dwFlags & 0x03000000) != 0x02000000 || !gnGlobal_00989C38);
    VALIDATE((dwFlags & 0x03000000) || nNameLength > 0);
    VALIDATE((dwFlags & 0x00030000) || !pVariable || nBytes == 4);
    VALIDATEEND;

    D2CmdDefStrc* pCommand;
    if (!(dwFlags & 0x03000000))
        pCommand = NewCommand(gtArguments_0074C49C);
    else
        pCommand = NewCommand(gtCommands_0074C490);
    SStrCopy(pCommand->szName, szName, sizeof(pCommand->szName));
    pCommand->dwId = dwId;
    pCommand->dwFlags = dwFlags;
    pCommand->nNameLength = nNameLength;
    pCommand->pVariable = pVariable;
    pCommand->nBytes = nBytes;
    pCommand->pfnCallback = pfnCallback;
    pCommand->bSet = bSet;
    pCommand->pParam = pParam;
    if (!(dwFlags & 0x00030000) && (dwFlags & 1))
        pCommand->nValue = bSet;
    else
        pCommand->nValue = 0;
    if ((dwFlags & 0x03000000) == 0x01000000)
        gnGlobal_00989C38 = 1;
    return nValid ? 1 : 0;
}
