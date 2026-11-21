#include "D2StormLink.h"

// 0x005174C0
D2StormLinkStrc* __thiscall D2StormLinkStrc::sub_005174C0(int nLinkOffset)
{
    int nNextLink = (int)m_next;
    if (nNextLink < 0)
    {
        return (D2StormLinkStrc*)~nNextLink;
    }

    if (nLinkOffset < 0)
    {
        nLinkOffset = (int)this - (int)m_prevlink->m_next;
    }

    return (D2StormLinkStrc*)(nNextLink + nLinkOffset);
}
