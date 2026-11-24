#pragma once
// Client: the key configuration file (.key) the client saves and loads (tag, version, size, then the
// key table).

#include "D2Check.h"

struct D2KeyConfigFileStrc
{
    unsigned short wTag; // 0x00
    unsigned short wVersion; // 0x02
    unsigned short wSize; // 0x04
    unsigned char aBody[0x474]; // 0x06
};
