#include "Storm.h"
#include "D2StormAutoLink.h"

struct D2GameStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2StormTSListStrc;
struct BREAKCMD;
struct D2GameLinkStrc;
struct D2StormGameArrayStrc;
struct D2StormHashObjectChunkStrc;
struct D2StormBreakCmdListStrc;
struct D2GameListStrc;
struct D2StormChunkListStrc;

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2StormTSListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }

    void sub_00426CF0_UnlinkAll();
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
extern char gszTypeNameBreakCmd_007088D8[]; // 0x007088D8
extern "C" const char gszSGameDataTypeName[]; // 0x0070F56C
extern char gszTypeNameHashObjectChunk_0070F5F4[]; // 0x0070F5F4

struct BREAKCMD
{
    D2StormLinkStrc f_0;
    int nData;
};

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;

    D2GameLinkStrc()
    {
        pPrevLink = 0;
        pNext = 0;
    }
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;
    char unk0x14[0x1DE0];
};

struct D2StormGameArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2GameStrc* f_8;
    unsigned int f_C;

    D2StormGameArrayStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameArrayStrc m_array;
    D2StormLinkStrc f_10;
};

struct D2StormBreakCmdListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00426B00_LinkNode(BREAKCMD* pNode, unsigned int nLinkType, BREAKCMD* pExisting); // 0x00426B00
    BREAKCMD* sub_00426DC0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2GameListStrc
{
    int m_linkoffset;
    D2GameLinkStrc m_terminator;

    void sub_004502A0_LinkNode(D2GameStrc* pNode, unsigned int nLinkType, D2GameStrc* pExisting);          // 0x004502A0
    D2GameStrc* sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_004508A0_LinkNode(D2StormHashObjectChunkStrc* pNode, unsigned int nLinkType, D2StormHashObjectChunkStrc* pExisting); // 0x004508A0
    D2StormHashObjectChunkStrc* sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

inline void* operator new(unsigned int nSize, void* pWhere) throw();

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

// 0x00426910
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

// 0x004269A0
void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00426BD0
void D2StormLinkStrc::sub_00426BD0()
{
    Unlink();
}

// 0x00426CF0
void D2StormTSListStrc::sub_00426CF0_UnlinkAll()
{
    while (char* pNode = Head())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00426DC0
BREAKCMD* D2StormBreakCmdListStrc::sub_00426DC0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(BREAKCMD) + nExtraBytes, gszTypeNameBreakCmd_007088D8, -2, nFlags | 8);
    BREAKCMD* pNode = pMemory ? new (pMemory) BREAKCMD : 0;
    if (nLocation)
        sub_00426B00_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// 0x00450390
D2GameStrc* D2GameListStrc::sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2GameStrc) + nExtraBytes, gszSGameDataTypeName, -2, nFlags | 8);
    D2GameStrc* pNode = pMemory ? new (pMemory) D2GameStrc : 0;
    if (nLocation)
        sub_004502A0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// 0x00450FA0
D2StormHashObjectChunkStrc* D2StormChunkListStrc::sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHashObjectChunkStrc) + nExtraBytes, gszTypeNameHashObjectChunk_0070F5F4, -2, nFlags | 8);
    D2StormHashObjectChunkStrc* pNode = pMemory ? new (pMemory) D2StormHashObjectChunkStrc : 0;
    if (nLocation)
        sub_004508A0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

#include "gen/data/Source/Storm/Unknown_00426910.inc"
