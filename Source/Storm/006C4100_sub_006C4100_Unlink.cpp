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

struct D2FogUnlinkStrc { D2SCompLinkStrc tLink; void sub_006C4100_Unlink(); };

// 0x006C4100
void D2FogUnlinkStrc::sub_006C4100_Unlink() { tLink.Unlink(); }
