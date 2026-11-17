#include "Storm.h"

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2ScmdStrc;
struct D2StormLinkStrc;
struct D2CmdDefStrc;

struct D2ScmdStrc
{
    char unk0x00[0x2C];
    char* szBuffer;
    unsigned int nBufferSize;
    char unk0x34[0x3C - 0x34];
    char* szName;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
static __declspec(noinline) void __stdcall sub_006C3DA0_SetName(D2ScmdStrc* pScmd, const char* szName, unsigned int* pnLength);
void* __stdcall SMemAlloc(unsigned int, const char*, int, unsigned int); // 0x00413020
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0
unsigned int __stdcall SStrLen(const char*); // 0x00413750
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
extern const char gszCmdDefType_0074C47C[]; // 0x0074C47C

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc() : m_prevlink(0), m_next(0) {}
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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
};

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

inline void* operator new(unsigned int, void* pPlace) throw();

// 0x006C3DA0
static void __stdcall sub_006C3DA0_SetName(D2ScmdStrc* pScmd, const char* szName, unsigned int* pnLength)
{
    *pnLength = SStrLen(szName);
    if (pScmd->szName)
    {
        SMemFree(pScmd->szName, ".\\SOURCE\\SCMD.CPP", 0x8B, 0);
    }
    pScmd->szName = (char*)SMemAlloc(SStrLen(szName) + 1, ".\\SOURCE\\SCMD.CPP", 0x8C, 0);
    SStrCopy(pScmd->szName, szName, 0x7FFFFFFF);
    if (pScmd->szBuffer)
    {
        SStrCopy(pScmd->szBuffer, szName, pScmd->nBufferSize);
    }
}

// build: context sub_006C3DA0_Shim
// calling-convention shim (not game code)
void __stdcall sub_006C3DA0_Shim(D2ScmdStrc* pScmd, const char* szName, unsigned int* pnLength)
{
    sub_006C3DA0_SetName(pScmd, szName, pnLength);
}

int gnGlobal_00989C38; // 0x00989C38

inline void* operator new(unsigned int, void* pPlace) throw() { return pPlace; }

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
