#include "Storm.h"
#include "D2StormTypes.h"

struct T0051755C;

struct PairStrc_006C4030;

struct D2SCompLinkStrc;

struct D2FogUnlinkStrc;

struct D2StormLinkStrc;

struct D2StormFixedListStrc;

struct sub_006C4250;

struct D2StormListAStrc;

struct D2FogUnlinkBStrc;

struct D2StormListStrc;

struct CMDDEF;

struct CMDDEFList;

struct D2StormCmdDefStrc;

struct D2StormCmdDefListStrc;

struct D2CmdListStrc;

struct T0051755C { T0051755C* pPrevLink; int pNext; };

struct PairStrc_006C4030
{
    int nFirst;
    int nSecond;
};

extern int gdwGlobal_0098A164; // 0x0098A164

extern int gdwGlobal_007C914C; // 0x007C914C

struct D2FogUnlinkStrc
{
    D2SCompLinkStrc tLink;
    void sub_006C4100_Unlink();
    void sub_006C4480_Unlink();
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc* sub_00416770_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_004168C0_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00416930_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00416970_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_004169B0_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0041C3A0_NextLink(int nLinkOffset);
    ~D2StormLinkStrc()
    {
        Unlink();
    }
};

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    D2StormLinkStrc* Link(char* pNode) { return pNode ? (D2StormLinkStrc*)pNode : &m_terminator; }
    void sub_006C4180_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);
    char* sub_006C44C0_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
};

struct sub_006C4250
{
    D2StormLinkStrc f_0;
    ~sub_006C4250();
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_006C4380_RawNext(D2StormLinkStrc* pNode);
};

struct D2FogUnlinkBStrc { D2SCompLinkStrc tLink; void sub_006C43B0_Unlink(); };

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Head()
    {
        return (int)m_terminator.m_next <= 0 ? 0 : (D2StormLinkStrc*)m_terminator.m_next;
    }
    void UnlinkAll();
};

int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" const char gszDelete[]; // 0x006CC824

struct CMDDEF
{
    D2StormLinkStrc m_link;
    int nData;

    static void operator delete(void* pMemory);
};

struct CMDDEFList
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    CMDDEF* Head()
    {
        return (int)m_terminator.m_next <= 0 ? 0 : (CMDDEF*)m_terminator.m_next;
    }
};

struct D2StormCmdDefListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_006C4760_DeleteAll();
};

extern const char gszCmdDef_0074C47C[]; // 0x0074C47C

struct D2CmdListStrc {
 int offset; D2StormLinkStrc terminator;
 D2StormLinkStrc* Link(char* node) { return node ? (D2StormLinkStrc*)node : &terminator; }
 char* sub_006C47B0_DeleteNode(char* node);
};

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

extern const char* gszErrorDefaults_006FCC24[]; // 0x006FCC24

extern const char gszPercentS_006FFC58[]; // 0x006FFC58

extern const char gszNewline_006FFCB0[]; // 0x006FFCB0

void* __cdecl sub_0041BEF0_GetExeModule(); // 0x0041BEF0

unsigned int __stdcall sub_00413800(char*, const char*, unsigned int); // 0x00413800

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340

extern "C" char* __cdecl strstr(const char*, const char*);

extern "C" __declspec(dllimport) int __stdcall LoadStringA(void*, unsigned int, char*, int);

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...);

static __declspec(noinline)
// 0x006C3E10
void __stdcall sub_006C3E10_ReportCommandError(D2ErrorCallback callback, unsigned int error, const char* context)
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
    LoadStringA(sub_0041BEF0_GetExeModule(), resource, format, 256);
    if (!format[0])
        SStrCopy(format, gszErrorDefaults_006FCC24[index], 256);
    if (strstr(format, gszPercentS_006FFC58))
        wsprintfA(message, format, context);
    else
        SStrCopy(message, format, 256);
    if (message[0])
        sub_00413800(message, gszNewline_006FFCB0, 256);
    sub_0041C340_SetLastError(error);
    report.error = error;
    report.context = context;
    report.message = message;
    report.callback(&report);
}

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

#define OPTION_MAX(a, b) ((a) < (b) ? (b) : (a))

__declspec(noinline) static int __stdcall sub_006C4A00_ParseOptionString(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError);

typedef int (__stdcall* OptionCallbackToken)(const char* szToken);

static __declspec(noinline) int __stdcall sub_006C4BC0_HandleToken(const char* szToken, OptionContextStrc* pContext, OptionStrc** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError);

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*);

extern "C" __declspec(dllimport) unsigned int __stdcall GetFileSize(void*, unsigned int*);

extern "C" __declspec(dllimport) int __stdcall ReadFile(void*, void*, unsigned int, unsigned int*, void*);

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

int __fastcall sub_006C4EC0_ParseCommandLine(const char** ppszCmdLine, OptionContextStrc* pContext, OptionStrc** ppOption, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError); // 0x006C4EC0

void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted); // 0x00413B80

extern "C" const char gszCmdWhitespace_006FCC4C[];                                                         // 0x006FCC4C

extern "C" unsigned int __security_cookie;                                                                  // 0x00749DE0

extern "C" void __fastcall __security_check_cookie(unsigned int nCookie);                                   // 0x00681A48

static int __stdcall sub_006C4A00_ParseOptionString(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError);

static int __stdcall sub_006C4BC0_HandleToken(const char* szToken, OptionContextStrc* pContext, OptionStrc** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError);

// build: context ??_GD2StormCmdDefStrc@@QAEPAXI@Z

struct D2StormCmdDefStrc
{
    D2StormLinkStrc tLink;
    char unk0x08[0x38];

    D2StormCmdDefStrc()
    {
        tLink.m_prevlink = 0;
        tLink.m_next = 0;
    }

    ~D2StormCmdDefStrc()
    {
        tLink.Unlink();
    }
};

// 0x006C4020
int __fastcall sub_006C4020_GetRawNext(T0051755C* pLink)
{
    return pLink->pNext;
}

// 0x006C4030
void __fastcall sub_006C4030(PairStrc_006C4030* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x006C4100
void D2FogUnlinkStrc::sub_006C4100_Unlink() { tLink.Unlink(); }

// 0x006C4180
void D2StormFixedListStrc::sub_006C4180_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExistingNode);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
        break;
    }
}

// 0x006C4250
sub_006C4250::~sub_006C4250()
{
    f_0.Unlink();
}

// 0x006C4380
char* D2StormListAStrc::sub_006C4380_RawNext(D2StormLinkStrc* pNode)
{
    return pNode ? pNode->m_next : m_terminator.m_next;
}

// 0x006C43B0
void D2FogUnlinkBStrc::sub_006C43B0_Unlink() { tLink.Unlink(); }

// 0x006C43F0
void D2StormListStrc::UnlinkAll()
{
    D2StormLinkStrc* pLink;
    while ((pLink = Head()) != 0)
        pLink->Unlink();
}

// 0x006C4480
void D2FogUnlinkStrc::sub_006C4480_Unlink() { tLink.Unlink(); }

inline void* operator new(unsigned int, void* pMemory) throw() { return pMemory; }

// 0x006C44C0
char* D2StormFixedListStrc::sub_006C44C0_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormCmdDefStrc) + nExtraBytes, gszTypeNameCmdDef_0074C47C, -2, nFlags | 8);
    D2StormCmdDefStrc* pRecord = pMemory ? new (pMemory) D2StormCmdDefStrc : 0;
    if (nLinkType)
        sub_006C4180_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// build: symbol ??_GCMDDEF@@* 0x006C4520
inline void CMDDEF::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, gszDelete, -1, 0);
}

// build: context sub_Emit_CMDDEF
void sub_Emit_CMDDEF(CMDDEFList* pList)
{
    CMDDEF* p;
    while ((p = pList->Head()) != 0)
        delete p;
}

// 0x006C4760
void D2StormCmdDefListStrc::sub_006C4760_DeleteAll()
{
    while (D2StormCmdDefStrc* pRecord = (D2StormCmdDefStrc*)Head())
    {
        pRecord->~D2StormCmdDefStrc();
        SMemFree(pRecord, gszTypeNameCmdDef_0074C47C, -2, 0);
    }
}

// 0x006C47B0
char* D2CmdListStrc::sub_006C47B0_DeleteNode(char* node) {
 char* next=Link(node)->Next();
 ((D2StormLinkStrc*)node)->Unlink();
 SMemFree(node,gszCmdDef_0074C47C,-2,0);
 return next;
}

static __forceinline OptionStrc* OPTION_Next(OptionStrc* pLink)
{
    return (int)pLink > 0 ? pLink : 0;
}

static void __stdcall sub_006C3CB0_ParseBool(int* pLength, OptionStrc* pOption, const char* szString)
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

// 0x006C4A00
static int __stdcall sub_006C4A00_ParseOptionString(const char* szString, OptionContextStrc* pContext, D2ErrorCallback pfnError)
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
                sub_006C3E10_ReportCommandError(pfnError, 0x85100065, szString);
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

int __stdcall sub_006C3F50_ReadCommandFile(const char* file, OptionContextStrc* arg1, OptionStrc** arg2, OptionCallbackToken arg3, D2ErrorCallback callback); // 0x006C3F50

// 0x006C4BC0
static int __stdcall sub_006C4BC0_HandleToken(const char* szToken, OptionContextStrc* pContext, OptionStrc** ppOption, int nQuoted, OptionCallbackToken pfnCallback, D2ErrorCallback pfnError)
{
    if (*szToken == '@' && !nQuoted)
    {
        return sub_006C3F50_ReadCommandFile(szToken + 1, pContext, ppOption, pfnCallback, pfnError);
    }

    if (SStrChr("-/", *szToken) && !nQuoted)
    {
        pContext->pCurrent = 0;
        return sub_006C4A00_ParseOptionString(szToken + 1, pContext, pfnError);
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
        sub_006C3E10_ReportCommandError(pfnError, 0x85100065, szToken);
    }

    return 0;
}

// 0x006C7A60
int __cdecl sub_006C7A60()
{
    return 1;
}

// 0x006C7CC0
int __cdecl sub_006C7CC0()
{
    return 0;
}

// 0x006C7CD0
void __stdcall sub_006C7CD0(int nUnused1)
{
}

// 0x006C7CE0
int __cdecl sub_006C7CE0()
{
    return 0;
}

// 0x006C8020
int __cdecl sub_006C8020()
{
    return gdwGlobal_0098A164;
}

// 0x006C8050
int __cdecl sub_006C8050()
{
    return 0;
}

// 0x006C8060
void __stdcall sub_006C8060(int nUnused1)
{
}

// 0x006C80F0
int __cdecl sub_006C80F0()
{
    return 0;
}

// 0x006C8100
int __cdecl sub_006C8100()
{
    return 0;
}

// 0x006C8190
int __cdecl sub_006C8190()
{
    return 0;
}

// 0x006C8240
int __cdecl sub_006C8240()
{
    return gdwGlobal_007C914C;
}

// 0x006C88A0
void __stdcall sub_006C88A0(int nUnused1, int nUnused2)
{
}

// 0x006C8A40
void __stdcall sub_006C8A40(int nUnused1, int nUnused2)
{
}

static __declspec(noinline)
// 0x006C3F50
int __stdcall sub_006C3F50_ReadCommandFile(const char* file, OptionContextStrc* arg1, OptionStrc** arg2, OptionCallbackToken arg3, D2ErrorCallback callback)
{
    void* handle = CreateFileA(file, 0x80000000, 1, 0, 3, 0x08000000, 0);
    if (handle == (void*)-1)
    {
        if (callback)
            sub_006C3E10_ReportCommandError(callback, 110, file);
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

// 0x006C4EC0
int __fastcall sub_006C4EC0_ParseCommandLine(const char** ppszCmdLine, OptionContextStrc* pnState, OptionStrc** pnContext, OptionCallbackToken pfnCallback, D2ErrorCallback pUserData)
{
    while (**ppszCmdLine)
    {
        const char* pszNext = *ppszCmdLine;
        int nQuoted = 0;
        char szToken[0x100];
        SStrTokenize(&pszNext, szToken, 0x100, gszCmdWhitespace_006FCC4C, &nQuoted);
        if (szToken[0] && !sub_006C4BC0_HandleToken(szToken, pnState, pnContext, nQuoted, pfnCallback, pUserData))
        {
            break;
        }
        *ppszCmdLine = pszNext;
    }
    return **ppszCmdLine == 0;
}

typedef int (__stdcall* D2CmdCallback)(const char*);
extern "C" __declspec(dllimport) char* __stdcall GetCommandLineA(); // 0x006CC3AC
int __stdcall SCmdProcess(const char*, int, D2CmdCallback, D2CmdCallback); // 0x006C4FB0

// 0x006C50B0
int __stdcall SCmdProcessCommandLine(D2CmdCallback extra, D2CmdCallback error)
{
    return SCmdProcess(GetCommandLineA(), 1, extra, error);
}

#include "gen/data/Source/Storm/SOURCE/SCMD.inc"
