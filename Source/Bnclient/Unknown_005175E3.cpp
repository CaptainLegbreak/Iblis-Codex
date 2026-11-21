#include "D2StormLink.h"

struct D2HellStormListStrc;
struct S;

struct D2HellStormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_005175E3_Initialize();
};

struct S { int a; int b; S(); };


// 0x005175E3
void D2HellStormListStrc::sub_005175E3_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00517619
S::S() { a = 0; b = 0; }
