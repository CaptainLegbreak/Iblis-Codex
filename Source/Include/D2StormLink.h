#pragma once
// Storm: the link node of Storm's intrusive lists.

#include "D2Check.h"
#include "D2Structs.h"

struct D2StormLinkStrc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink; // 0x00
    char* m_next; // 0x04
};

D2_CHECK_SIZE(D2StormLinkStrc, 0x8);
