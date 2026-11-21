#include "Storm.h"
#include "D2StormLink.h"

struct D2StormListStrc;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void UnlinkAll();                   // 0x006C43F0
    ~D2StormListStrc();
};

// 0x006C4430
D2StormListStrc::~D2StormListStrc()
{
    UnlinkAll();
    m_terminator.Unlink();
}
