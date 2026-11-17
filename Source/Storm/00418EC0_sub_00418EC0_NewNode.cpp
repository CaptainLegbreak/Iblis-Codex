inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern char gszTypeNameArchiveRec_00708398[];                                                               // 0x00708398
extern char gszTypeNameRequest_007083F0[];                                                                  // 0x007083F0
extern "C" const char gszStormAudioStreamTypeName[];                                                        // 0x00708408
extern char gszTypeNameHandler_00708434[];                                                                  // 0x00708434
extern char gszTypeNameWndRec_00708850[];                                                                   // 0x00708850

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
    char unk0x08[0x254];

    D2StormArchiveRecStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
};

struct D2StormRequestStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x3C];

    D2StormRequestStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
    ~D2StormRequestStrc();                                                                                  // 0x0041A020
    static void operator delete(void* pMemory);
};

struct D2StormAudioStreamStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x48];

    ~D2StormAudioStreamStrc();                                                                              // 0x004199A0
    static void operator delete(void* pMemory);
};

struct D2StormHandlerStrc
{
    D2StormLinkStrc f_0;
    int unk0x08;

    D2StormHandlerStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
    ~D2StormHandlerStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormWndRecStrc
{
    D2StormLinkStrc f_0;
    int unk0x08;

    D2StormWndRecStrc()
    {
        f_0.m_prevlink = 0;
        f_0.m_next = 0;
    }
    ~D2StormWndRecStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
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
    void sub_00417A70_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);                   // 0x00417A70
    void sub_004184B0_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);                   // 0x004184B0
    void sub_0041C580_LinkNode(char* pNode, unsigned int nLinkType, char* pExistingNode);                   // 0x0041C580
    char* sub_00418EC0_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_00419630_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_00419B90_DeleteNode(char* pNode);
    char* sub_0041A2C0_DeleteNode(char* pNode);
    char* sub_0041C840_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_0041CA10_DeleteNode(char* pNode);
};

struct D2StormNodeListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void sub_00420540_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);                       // 0x00420540
    char* sub_00420820_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* sub_00420970_DeleteNode(char* pNode);
};

// build: symbol ??_GD2StormAudioStreamStrc@@QAEPAXI@Z 0x00419A50
// build: symbol ??_GD2StormRequestStrc@@QAEPAXI@Z 0x0041A0E0
// 0x00419A50
inline void D2StormAudioStreamStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0041A0E0
inline void D2StormRequestStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??_GD2StormHandlerStrc@@QAEPAXI@Z 0x0041C8A0
inline D2StormHandlerStrc::~D2StormHandlerStrc()
{
    f_0.Unlink();
}

// build: symbol ??_GD2StormWndRecStrc@@QAEPAXI@Z 0x00420880
inline D2StormWndRecStrc::~D2StormWndRecStrc()
{
    f_0.Unlink();
}

// 0x00418EC0
char* D2StormFixedListStrc::sub_00418EC0_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormArchiveRecStrc) + nExtraBytes, gszTypeNameArchiveRec_00708398, -2, nFlags | 8);
    D2StormArchiveRecStrc* pRecord = pMemory ? new (pMemory) D2StormArchiveRecStrc : 0;
    if (nLinkType)
        sub_004184B0_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00419630
char* D2StormFixedListStrc::sub_00419630_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormRequestStrc) + nExtraBytes, gszTypeNameRequest_007083F0, -2, nFlags | 8);
    D2StormRequestStrc* pRecord = pMemory ? new (pMemory) D2StormRequestStrc : 0;
    if (nLinkType)
        sub_00417A70_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00419B90
char* D2StormFixedListStrc::sub_00419B90_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormAudioStreamStrc*)pNode)->~D2StormAudioStreamStrc();
    SMemFree(pNode, gszStormAudioStreamTypeName, -2, 0);
    return pNext;
}

// 0x0041A2C0
char* D2StormFixedListStrc::sub_0041A2C0_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormRequestStrc*)pNode)->~D2StormRequestStrc();
    SMemFree(pNode, gszTypeNameRequest_007083F0, -2, 0);
    return pNext;
}

// 0x0041C840
char* D2StormFixedListStrc::sub_0041C840_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormHandlerStrc) + nExtraBytes, gszTypeNameHandler_00708434, -2, nFlags | 8);
    D2StormHandlerStrc* pRecord = pMemory ? new (pMemory) D2StormHandlerStrc : 0;
    if (nLinkType)
        sub_0041C580_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x0041CA10
char* D2StormFixedListStrc::sub_0041CA10_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormHandlerStrc*)pNode)->~D2StormHandlerStrc();
    SMemFree(pNode, gszTypeNameHandler_00708434, -2, 0);
    return pNext;
}

// 0x00420820
char* D2StormNodeListBStrc::sub_00420820_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2StormWndRecStrc) + nExtraBytes, gszTypeNameWndRec_00708850, -2, nFlags | 8);
    D2StormWndRecStrc* pRecord = pMemory ? new (pMemory) D2StormWndRecStrc : 0;
    if (nLinkType)
        sub_00420540_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}

// 0x00420970
char* D2StormNodeListBStrc::sub_00420970_DeleteNode(char* pNode)
{
    char* pNext = Link(pNode)->Next();
    ((D2StormWndRecStrc*)pNode)->~D2StormWndRecStrc();
    SMemFree(pNode, gszTypeNameWndRec_00708850, -2, 0);
    return pNext;
}

#include "gen/data/Source/Storm/00418EC0_sub_00418EC0_NewNode.inc"
