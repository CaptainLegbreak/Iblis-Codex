struct D2LogMsgLinkStrc
{
    D2LogMsgLinkStrc* m_prevlink;
    char* m_next;

    D2LogMsgLinkStrc() { m_prevlink = 0; m_next = 0; }
    // 0x0040F820
    ~D2LogMsgLinkStrc() { Unlink(); }
    D2LogMsgLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2LogMsgLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2LogMsgLinkStrc*)(m_next + nLinkOffset);
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

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern "C" const char gszLogMessageTypeName_00708124[];                                                     // 0x00708124

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

struct D2LogMsgNodeStrc
{
    D2LogMsgLinkStrc f_0;

    D2LogMsgNodeStrc() {}
    ~D2LogMsgNodeStrc();                                                    // 0x0040FAA0
};

struct D2LogMessageStrc : D2LogMsgNodeStrc
{
    char unk0x08[0x1C];

    D2LogMessageStrc() {}
    ~D2LogMessageStrc() {}
    static void operator delete(void* pMemory);
    static void operator delete(void*, void*) {}
};

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2LogMsgLinkStrc m_terminator;

    D2LogMsgListStrc();
    ~D2LogMsgListStrc();
    void sub_0040FD00_UnlinkAll();                                          // 0x0040FD00
    void sub_0040FBB0_LinkNode(char* pNode, int nLinkType, char* pExistingNode); // 0x0040FBB0
    void sub_0040FED0_DeleteAll();
    char* sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
};

// build: symbol ??3D2LogMessageStrc@@SAXPAX0@Z 0x0040EB30
// 0x0040FB50
D2LogMsgListStrc::D2LogMsgListStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0040FD90
D2LogMsgListStrc::~D2LogMsgListStrc()
{
    sub_0040FD00_UnlinkAll();
}

// build: symbol ??_GD2LogMessageStrc@@QAEPAXI@Z 0x0040FE60
inline void D2LogMessageStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0040FED0
void D2LogMsgListStrc::sub_0040FED0_DeleteAll()
{
    while (D2LogMessageStrc* pNode = (D2LogMessageStrc*)m_terminator.Next())
    {
        pNode->~D2LogMessageStrc();
        SMemFree(pNode, gszLogMessageTypeName_00708124, -2, 0);
    }
}

// 0x0040FF40
char* D2LogMsgListStrc::sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2LogMessageStrc) + nExtraBytes, gszLogMessageTypeName_00708124, -2, nFlags | 8);
    D2LogMessageStrc* pNode = new (pMemory) D2LogMessageStrc;
    if (nLinkType)
        sub_0040FBB0_LinkNode((char*)pNode, nLinkType, 0);
    return (char*)pNode;
}

#include "gen/data/Source/Fog/Unknown_0040EB30.inc"
