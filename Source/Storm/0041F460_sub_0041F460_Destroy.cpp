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

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0041EE40_UnlinkAll();
    void sub_0041F460_Destroy();
};

class THuffmannTree
{
public:
    THuffmannTree();
    ~THuffmannTree();

    unsigned int adwData[0x3474 / 4];
};

class D2StormHuffEncTreeStrc : public THuffmannTree
{
public:
    D2StormHuffEncTreeStrc();
    ~D2StormHuffEncTreeStrc();
};

class D2StormHuffDecTreeStrc : public THuffmannTree
{
public:
    ~D2StormHuffDecTreeStrc();
};

// build: symbol ??0THuffmannTree@@QAE@XZ 0x0041F4A0
// build: symbol ??1THuffmannTree@@QAE@XZ 0x0041F6A0
// 0x0041F460
void D2StormNodeListStrc::sub_0041F460_Destroy()
{
    sub_0041EE40_UnlinkAll();
    m_terminator.Unlink();
}

// 0x0041F920
D2StormHuffEncTreeStrc::D2StormHuffEncTreeStrc()
{
}

// 0x0041F930
D2StormHuffEncTreeStrc::~D2StormHuffEncTreeStrc()
{
}

// 0x0041F940
D2StormHuffDecTreeStrc::~D2StormHuffDecTreeStrc()
{
}
