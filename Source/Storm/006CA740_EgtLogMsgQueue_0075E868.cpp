struct D2LogMsgLinkStrc
{
    D2LogMsgLinkStrc* m_prevlink;
    char* m_next;

    D2LogMsgLinkStrc()
    {
    }
    // 0x0040F820
    ~D2LogMsgLinkStrc()
    {
        Unlink();
    }
    D2LogMsgLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2LogMsgLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2LogMsgLinkStrc*)(m_next + nLinkOffset);
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

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2LogMsgLinkStrc m_terminator;

    D2LogMsgListStrc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    ~D2LogMsgListStrc(); // 0x0040FD90
};

extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
void __cdecl FgtLogMsgQueue_0075E868(); // 0x006CB090

// 0x006CA740
void __cdecl EgtLogMsgQueue_0075E868();
D2LogMsgListStrc gtLogMsgQueue_0075E868; // 0x0075E868
