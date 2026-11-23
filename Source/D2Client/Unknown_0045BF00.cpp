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

extern "C" const char gszHeapsTitle[];        // 0x006D69C0
extern "C" const char gszSeparator[];         // 0x006D698C
extern "C" const char gszHeapsHeader[];       // 0x006D6938
extern "C" const char gszHeapLine[];          // 0x006D6910
extern "C" const char gszHeapCount[];         // 0x006D68F8
extern "C" const char gszTotal124[];          // 0x006D68E0
extern "C" const char gszTotal120[];          // 0x006D68C8
extern "C" const char gszTotal118[];          // 0x006D68B0
extern "C" const char gszTotal114[];          // 0x006D6898
extern "C" const char gszTotal11C[];          // 0x006D6880
extern "C" const char gszTotal110[];          // 0x006D6864
extern "C" const char gszArchiveCpp[];        // 0x006D6844
extern "C" const char gszAllocTotal[];        // 0x006D6830
extern "C" const char gszBlockTotal[];        // 0x006D681C
extern "C" const char gszAllocCount[];        // 0x006D6804
extern "C" const char gszAllocLine[];         // 0x006D67F0

// 0x0045BF00
void __cdecl sub_0045BF00_DumpMemory()
{
    void* hFile = CreateFileA("D2Mem.txt", 0x40000000, 0, 0, 2, 0x80, 0);
    sub_0045B960_FilePrintf(hFile, gszHeapsTitle);
    sub_0045B960_FilePrintf(hFile, gszSeparator);

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
    sub_0045B960_FilePrintf(hFile, gszHeapsHeader);
    for (D2ClientAllocRecStrc* pRec = tList.First(); (int)pRec > 0; pRec = (D2ClientAllocRecStrc*)pRec->f_0.m_next)
    {
        sub_0045B960_FilePrintf(hFile, gszHeapLine, pRec->tInfo.dw124, pRec->tInfo.dw120, pRec->tInfo.dw118,
            pRec->tInfo.dw114, pRec->tInfo.dw11C, pRec->tInfo.dw110, (char*)pRec->tInfo.adwName, pRec->tInfo.nLine);
        nTotal124 += pRec->tInfo.dw124;
        nTotal120 += pRec->tInfo.dw120;
        nTotal118 += pRec->tInfo.dw118;
        nTotal114 += pRec->tInfo.dw114;
        nTotal11C += pRec->tInfo.dw11C;
        nTotal110 += pRec->tInfo.dw110;
        ++nHeaps;
    }

    sub_0045B960_FilePrintf(hFile, gszSeparator);
    sub_0045B960_FilePrintf(hFile, gszHeapCount, nHeaps);
    sub_0045B960_FilePrintf(hFile, gszTotal124, nTotal124);
    sub_0045B960_FilePrintf(hFile, gszTotal120, nTotal120);
    sub_0045B960_FilePrintf(hFile, gszTotal118, nTotal118);
    sub_0045B960_FilePrintf(hFile, gszTotal114, nTotal114);
    sub_0045B960_FilePrintf(hFile, gszTotal11C, nTotal11C);
    sub_0045B960_FilePrintf(hFile, gszTotal110, nTotal110);
    sub_0045B960_FilePrintf(hFile, gszSeparator);

    hHeap = SMemGetHeapByCaller(gszArchiveCpp, 0xF5);
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
                    sub_0045B960_FilePrintf(hFile, gszAllocLine, pHeader->nSize, (char*)pHeader->adwName, (char*)pHeader->adwFile, pHeader->nLine);
                    nAllocTotal += pHeader->nSize;
                    nBlockTotal += tBlock.nBytes;
                    ++nAllocCount;
                    break;
                }
            }
        }
    }

    sub_0045B960_FilePrintf(hFile, gszAllocTotal, nAllocTotal);
    sub_0045B960_FilePrintf(hFile, gszBlockTotal, nBlockTotal);
    sub_0045B960_FilePrintf(hFile, gszAllocCount, nAllocCount);
    CloseHandle(hFile);
}
