#include "Storm.h"

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

struct D2SCompLinkStrc
{
    D2SCompLinkStrc* m_prevlink;
    char* m_next;

    D2SCompLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2SCompLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2SCompLinkStrc*)(m_next + nLinkOffset);
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

// build: context ??_GD2StormCmdDefStrc@@QAEPAXI@Z
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormCmdDefStrc
{
    D2StormLinkStrc tLink;
    char unk0x08[0x10];

    ~D2StormCmdDefStrc()
    {
        tLink.Unlink();
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
int __stdcall SMemFree(void*,const char*,int,unsigned int); // 0x00412650

struct D2CmdListStrc {
 int offset; D2StormLinkStrc terminator;
 D2StormLinkStrc* Link(char* node) { return node ? (D2StormLinkStrc*)node : &terminator; }
 char* sub_006C47B0_DeleteNode(char* node);
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

#include "gen/data/Source/Storm/SOURCE/SCMD.inc"

// 0x006C47B0
char* D2CmdListStrc::sub_006C47B0_DeleteNode(char* node) {
 char* next=Link(node)->Next();
 ((D2StormLinkStrc*)node)->Unlink();
 SMemFree(node,gszCmdDef_0074C47C,-2,0);
 return next;
}
