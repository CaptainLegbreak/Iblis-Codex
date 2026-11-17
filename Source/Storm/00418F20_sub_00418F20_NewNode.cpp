inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

extern "C" const char gszStormFileRecTypeName[];                                                            // 0x007083C0
extern "C" const char gszStormEventRecTypeName[];                                                           // 0x007083D8
extern "C" const char gszStormAudioStreamTypeName[];                                                        // 0x00708408

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

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

struct D2StormFileRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x104];
    int nUnk0x10C;
    int nUnk0x110;
    int nUnk0x114;
    char unk0x118[0x14];
    int nUnk0x12C;
    char unk0x130[0x8];
    int nUnk0x138;
    char unk0x13C[0x1C];

    D2StormFileRecStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
        nUnk0x10C = 0;
        nUnk0x110 = -1;
        nUnk0x114 = 0;
        nUnk0x12C = 0;
        nUnk0x138 = 0;
    }
};

struct D2StormAudioStreamStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x48];

    D2StormAudioStreamStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
};

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void sub_00417B80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);                   // 0x00417B80
    void sub_00417D80_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);                   // 0x00417D80
    char* sub_00418F20_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_00419690_DeleteNode(char* pNode);
    char* sub_00419700_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
};

// 0x00418F20
char* D2StormFixedListStrc::sub_00418F20_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormFileRecStrc) + nExtraBytes, gszStormFileRecTypeName, -2, nFlags | 8);
    D2StormFileRecStrc* pRecord = pMemory ? new (pMemory) D2StormFileRecStrc : 0;
    if (nLinkType)
        sub_00417B80_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00419690
char* D2StormFixedListStrc::sub_00419690_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormLinkStrc*)pNode)->Unlink();
    SMemFree(pNode, gszStormEventRecTypeName, -2, 0);
    return pNext;
}

// 0x00419700
char* D2StormFixedListStrc::sub_00419700_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormAudioStreamStrc) + nExtraBytes, gszStormAudioStreamTypeName, -2, nFlags | 8);
    D2StormAudioStreamStrc* pRecord = pMemory ? new (pMemory) D2StormAudioStreamStrc : 0;
    if (nLinkType)
        sub_00417D80_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

#include "gen/data/Source/Storm/00418F20_sub_00418F20_NewNode.inc"
