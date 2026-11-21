#pragma once
// Storm: the link node of Storm's intrusive lists.

#include "D2Check.h"
#include "D2Structs.h"

struct D2StormLinkStrc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink; // 0x00
    char* m_next; // 0x04

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
    char* Prev()
    {
        return m_prevlink->m_prevlink->Next();
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
    void sub_0041C650(); // 0x0041C650
    D2StormLinkStrc* sub_00426930_NextLink(int nLinkOffset); // 0x00426930
};

D2_CHECK_SIZE(D2StormLinkStrc, 0x8);
