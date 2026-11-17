struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
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
};

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc f_0;
    char szName[0x104];
    void* hFile;
    int nMode;
    int bNoDiskSearch;
    int nPriority;
    char pad0x11C[0x148 - 0x11C];
    int nRefCount;
    void* hNestedFile;
    D2StormArchiveRecStrc* pParent;
    char szPrefix[0x104];
    int nRefs;

    D2StormArchiveRecStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
};

struct D2StormArchiveListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormArchiveRecStrc* Head()
    {
        return (D2StormArchiveRecStrc*)m_terminator.Next();
    }
    void LinkBefore(D2StormArchiveRecStrc* pNode, D2StormArchiveRecStrc* pExisting)
    {
        pNode->f_0.Unlink();
        D2StormLinkStrc* pExistingLink = &pExisting->f_0;
        if (!pExisting)
            pExistingLink = &m_terminator;
        D2StormLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pNode->f_0.m_prevlink = pPrevLink;
        pNode->f_0.m_next = pPrevLink->m_next;
        pPrevLink->m_next = (char*)pNode;
        pExistingLink->m_prevlink = &pNode->f_0;
    }
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void __cdecl sub_00415B90_InitCryptTable();                                                                 // 0x00415B90

extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068
extern D2StormArchiveListStrc gArchiveList_00708354;                                                        // 0x00708354
extern char gszTypeNameArchiveRec_00708398[];                                                               // 0x00708398

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

// 0x00419180
int __stdcall sub_00419180_OpenPathAsArchive(void* hArchive, const char* szPrefix, int nPriority, unsigned int nFlags, void** phArchive)
{
    VALIDATEBEGIN;
    if (!phArchive)
        nValid = 0;
    else
        *phArchive = 0;
    VALIDATE(szPrefix);
    VALIDATE(*(const volatile char*)szPrefix);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();
    D2StormArchiveRecStrc* pParent = (D2StormArchiveRecStrc*)hArchive;
    if (!pParent)
    {
        sub_0041C340_SetLastError(0x57);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    void* pMemory = SMemAlloc(sizeof(D2StormArchiveRecStrc), gszTypeNameArchiveRec_00708398, -2, 8);
    D2StormArchiveRecStrc* pArchive = pMemory ? new (pMemory) D2StormArchiveRecStrc : 0;
    SStrCopy(pArchive->szName, pParent->szName, 0x104);
    pArchive->hFile = pParent->hFile;
    pArchive->pParent = pParent;
    pArchive->nPriority = nPriority;
    pArchive->nRefs = 0;
    SStrCopy(pArchive->szPrefix, szPrefix, 0x7FFFFFFF);
    pArchive->nRefCount = 1;
    ++pParent->nRefCount;
    D2StormArchiveRecStrc* pExisting;
    for (pExisting = gArchiveList_00708354.Head(); pExisting; pExisting = (D2StormArchiveRecStrc*)pExisting->f_0.Next())
    {
        if (pExisting->nPriority <= pArchive->nPriority)
            break;
    }
    gArchiveList_00708354.LinkBefore(pArchive, pExisting);
    *phArchive = pArchive;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}
