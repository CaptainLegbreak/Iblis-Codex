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

// build: symbol ??0D2LogMsgNodeStrc@@QAE@XZ 0x0040FCB0
struct D2LogMsgNodeStrc
{
    D2LogMsgLinkStrc f_0;

    D2LogMsgNodeStrc() {}
    ~D2LogMsgNodeStrc();                                                    // 0x0040FAA0
};

struct D2LogMessageStrc : D2LogMsgNodeStrc
{
    char unk0x08[0x1C];

    D2LogMessageStrc();
    ~D2LogMessageStrc();
};

// 0x0040FE10
D2LogMessageStrc::D2LogMessageStrc()
{
}

// 0x0040FD40
D2LogMessageStrc::~D2LogMessageStrc()
{
}
