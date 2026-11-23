#include "D2Client.h"
#include "D2StormAutoLink.h"

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2SMemHeapInfoStrc
{
    unsigned int dwSize;
    unsigned int hHeap;
    unsigned int adwName[0x41];
    int nLine;
    unsigned int dw110;
    unsigned int dw114;
    unsigned int dw118;
    unsigned int dw11C;
    unsigned int dw120;
    unsigned int dw124;
};

struct D2SMemBlockInfoStrc
{
    unsigned int dwSize;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int dw0C;
    unsigned int nBytes;
    unsigned int dw14;
    unsigned int dw18;
};

struct D2HellAllocHeaderStrc
{
    unsigned int dwSignature[4];
    int nLine;
    int nSize;
    unsigned int adwFile[0x41];
    unsigned int adwName[0x41];
};

struct D2ClientAllocRecStrc
{
    D2StormLinkStrc f_0;
    D2SMemHeapInfoStrc tInfo;
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

struct D2ClientAllocRecListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2ClientAllocRecListStrc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    ~D2ClientAllocRecListStrc()
    {
        UnlinkAll();
        m_terminator.Unlink();
    }
    D2ClientAllocRecStrc* Head()
    {
        return (int)m_terminator.m_next <= 0 ? 0 : (D2ClientAllocRecStrc*)m_terminator.m_next;
    }
    D2ClientAllocRecStrc* First()
    {
        return (D2ClientAllocRecStrc*)((((int)m_terminator.m_next <= 0) - 1) & (int)m_terminator.m_next);
    }
    D2ClientAllocRecStrc* Next(D2ClientAllocRecStrc* pNode)
    {
        return (int)pNode->f_0.m_next <= 0 ? 0 : (D2ClientAllocRecStrc*)pNode->f_0.m_next;
    }
    D2ClientAllocRecStrc* NewNode()
    {
// build: symbol ?gszTypeNameAllocRec@* 0x00711480
        void* pMemory = SMemAlloc(sizeof(D2ClientAllocRecStrc), gszTypeNameAllocRec, -2, 8);
        return pMemory ? new (pMemory) D2ClientAllocRecStrc : 0;
    }
    __forceinline void LinkToHead(D2ClientAllocRecStrc* pNode)
    {
        D2StormLinkStrc* pLink = &pNode->f_0;
        pLink->Unlink();
        pLink->m_prevlink = &m_terminator;
        pLink->m_next = m_terminator.m_next;
        m_terminator.NextLink(m_linkoffset)->m_prevlink = pLink;
        m_terminator.m_next = (char*)pNode;
    }
    void sub_0045BBE0_LinkNode(D2ClientAllocRecStrc* pNode, unsigned int nLinkType, D2ClientAllocRecStrc* pExisting); // 0x0045BBE0
    void UnlinkAll();                                                                                       // 0x0045BD00
};

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwAccess, unsigned long dwShareMode, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x006CC19C
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                 // 0x006CC134
void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...);                              // 0x0045B960
int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, D2SMemHeapInfoStrc* pInfo);      // 0x004124B0
int __stdcall SMemFindNextBlock(unsigned int hHeap, void* pMemory, void** ppBlock, D2SMemBlockInfoStrc* pInfo); // 0x004122F0
unsigned int __stdcall SMemGetHeapByCaller(const char* szFile, int nLine);                                 // 0x00412710


// 0x0045BF00
void __cdecl sub_0045BF00_DumpMemory()
{
    void* hFile = CreateFileA("D2Mem.txt", 0x40000000, 0, 0, 2, 0x80, 0);
    sub_0045B960_FilePrintf(hFile, "D2 MEMORY CHECK\n");
    sub_0045B960_FilePrintf(hFile, "================================================\n\n");

    D2ClientAllocRecListStrc tList;
    D2SMemHeapInfoStrc tInfo;
    unsigned int hHeap = 0;
    tInfo.dwSize = sizeof(tInfo);
    while (SMemFindNextHeap(hHeap, &hHeap, &tInfo))
    {
        D2ClientAllocRecStrc* pNode = tList.NewNode();
        pNode->tInfo = tInfo;
        D2ClientAllocRecStrc* pCurrent = tList.Head();
        if (pCurrent)
        {
            if (pCurrent->tInfo.dw124 < tInfo.dw124)
            {
                tList.LinkToHead(pNode);
            }
            else
            {
                D2ClientAllocRecStrc* pNext;
                while ((pNext = tList.Next(pCurrent)) != 0 && pNext->tInfo.dw124 > tInfo.dw124)
                {
                    pCurrent = pNext;
                }
                tList.sub_0045BBE0_LinkNode(pNode, 1, pCurrent);
            }
        }
        else
        {
            tList.LinkToHead(pNode);
        }
    }

    unsigned int nTotal124 = 0;
    unsigned int nTotal120 = 0;
    unsigned int nTotal118 = 0;
    unsigned int nTotal114 = 0;
    unsigned int nTotal11C = 0;
    unsigned int nTotal110 = 0;
    int nHeaps = 0;
    sub_0045B960_FilePrintf(hFile, "      SIZE|    BLOCKS|  RESERVED| COMMITTED|       MAX|   REGIONS|FILENAME:LINE\n");
    for (D2ClientAllocRecStrc* pRec = tList.First(); (int)pRec > 0; pRec = (D2ClientAllocRecStrc*)pRec->f_0.m_next)
    {
        sub_0045B960_FilePrintf(hFile, "%10d|%10d|%10d|%10d|%10d|%10d|%s:%d\n", pRec->tInfo.dw124, pRec->tInfo.dw120, pRec->tInfo.dw118,
            pRec->tInfo.dw114, pRec->tInfo.dw11C, pRec->tInfo.dw110, (char*)pRec->tInfo.adwName, pRec->tInfo.nLine);
        nTotal124 += pRec->tInfo.dw124;
        nTotal120 += pRec->tInfo.dw120;
        nTotal118 += pRec->tInfo.dw118;
        nTotal114 += pRec->tInfo.dw114;
        nTotal11C += pRec->tInfo.dw11C;
        nTotal110 += pRec->tInfo.dw110;
        ++nHeaps;
    }

    sub_0045B960_FilePrintf(hFile, "================================================\n\n");
    sub_0045B960_FilePrintf(hFile, "NUM HEAPS:       %10d\n", nHeaps);
    sub_0045B960_FilePrintf(hFile, "TOTAL MEMORY:    %10d\n", nTotal124);
    sub_0045B960_FilePrintf(hFile, "TOTAL BLOCKS:    %10d\n", nTotal120);
    sub_0045B960_FilePrintf(hFile, "TOTAL RESERVED:  %10d\n", nTotal118);
    sub_0045B960_FilePrintf(hFile, "TOTAL COMMITTED: %10d\n", nTotal114);
    sub_0045B960_FilePrintf(hFile, "TOTAL MAX:       %10d\n", nTotal11C);
    sub_0045B960_FilePrintf(hFile, "TOTAL REGIONS:   %10d\n\n\n\n\n", nTotal110);
    sub_0045B960_FilePrintf(hFile, "================================================\n\n");

    hHeap = SMemGetHeapByCaller("SOURCE\\D2HELL\\Src\\Archive.cpp", 0xF5);
    D2SMemBlockInfoStrc tBlock;
    tBlock.dwSize = sizeof(tBlock);
    void* pBlock = 0;
    unsigned int nAllocTotal = 0;
    unsigned int nAllocCount = 0;
    unsigned int nBlockTotal = 0;
    while (SMemFindNextBlock(hHeap, pBlock, &pBlock, &tBlock))
    {
        if (tBlock.nBytes > 0x220 && tBlock.dw0C && tBlock.dw08)
        {
            for (unsigned int* p = (unsigned int*)pBlock; p < (unsigned int*)((char*)pBlock + tBlock.nBytes); ++p)
            {
                if (p[0] == 'LOAD' && p[1] == 'FUCK' && p[2] == 'THIS' && p[3] == 'NOW ')
                {
                    D2HellAllocHeaderStrc* pHeader = (D2HellAllocHeaderStrc*)p;
                    sub_0045B960_FilePrintf(hFile, "%8d\t%50s\t(%s:%d)\n", pHeader->nSize, (char*)pHeader->adwName, (char*)pHeader->adwFile, pHeader->nLine);
                    nAllocTotal += pHeader->nSize;
                    nBlockTotal += tBlock.nBytes;
                    ++nAllocCount;
                    break;
                }
            }
        }
    }

    sub_0045B960_FilePrintf(hFile, "TOTAL MEMORY: %8d\n", nAllocTotal);
    sub_0045B960_FilePrintf(hFile, "TOTAL ALLOC:  %8d\n", nBlockTotal);
    sub_0045B960_FilePrintf(hFile, "TOTAL BLOCKS: %8d\n\n\n\n", nAllocCount);
    CloseHandle(hFile);
}
