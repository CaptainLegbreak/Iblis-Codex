#include "D2Client.h"
#include "D2StormAutoLink.h"
#include "D2StormListArray.h"

struct D2SGameDataStrc;
struct D2StormLinkStrc;
struct D2StormBreakCmdListStrc;
struct D2StormListAStrc;
struct D2StormListFixedArrayStrc;
struct D2StormGameDataArrayStrc;
struct D2StormChunkListStrc;
struct D2StormListArrayStrc;
struct D2StormHashTableStrc;
struct D2StormHashTableReuseStrc;

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00412650
extern const char gszTypeBreakCmd_007088D8[]; // 0x007088D8

struct D2StormBreakCmdListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* sub_00426F20_DeleteNode(char* pNode);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
};

struct D2StormListFixedArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;

    ~D2StormListFixedArrayStrc();
};

struct D2SGameDataStrc
{
    char unk0x00[0x1DF4];

    D2SGameDataStrc(const D2SGameDataStrc& tSource);                                                        // 0x00450950
    ~D2SGameDataStrc();                                                                                     // 0x0044F820
};

struct D2StormGameDataArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2SGameDataStrc* m_data;
    unsigned int m_chunk;

    void sub_00450D90_ReallocData(unsigned int nAlloc);
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00450580_DeleteAll();                                                                          // 0x00450580
};


struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableStrc();
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0044FA00_InternalClear(int bWarn);                                                             // 0x0044FA00
};

struct D2StormHashTableReuseStrc : D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableReuseStrc();
    virtual void Destroy();
    D2StormListAStrc m_reuseList;
    unsigned int m_chunkSize;
    D2StormChunkListStrc m_chunkList;
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00426F20
char* D2StormBreakCmdListStrc::sub_00426F20_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormLinkStrc*)pNode)->Unlink();
    SMemFree(pNode, gszTypeBreakCmd_007088D8, -2, 0);
    return pNext;
}

// 0x0044FF60
D2StormListFixedArrayStrc::~D2StormListFixedArrayStrc()
{
    for (unsigned int i = 0; i < m_count; i++)
        m_data[i].~D2StormListAStrc();
    if (m_data)
// build: symbol ?gszTypeExplicitList@* 0x0070F584
        SMemFree(m_data, gszTypeExplicitList, -2, 0);
}

// 0x00450D90
void D2StormGameDataArrayStrc::sub_00450D90_ReallocData(unsigned int nAlloc)
{
    D2SGameDataStrc* pOld = m_data;
    for (unsigned int i = nAlloc; i < m_count; i++)
        pOld[i].~D2SGameDataStrc();
    m_alloc = nAlloc;
// build: symbol ?gszTypeSGameData@* 0x0070F56C
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2SGameDataStrc), gszTypeSGameData, -2, 0x10);
    m_data = (D2SGameDataStrc*)pNew;
    if (!pNew)
    {
        m_data = (D2SGameDataStrc*)SMemAlloc(nAlloc * sizeof(D2SGameDataStrc), gszTypeSGameData, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= m_count ? m_count : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&m_data[i]) D2SGameDataStrc(pOld[i]);
                pOld[i].~D2SGameDataStrc();
            }
            SMemFree(pOld, gszTypeSGameData, -2, 0);
        }
    }
}

// 0x004510B0
void D2StormHashTableReuseStrc::Destroy()
{
    sub_0044FA00_InternalClear(0);
    m_chunkList.sub_00450580_DeleteAll();
    m_reuseList.sub_0044FC60_DeleteAll();
}
