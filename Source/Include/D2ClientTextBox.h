#pragma once
// Client: a text box (gpTextBox, gpMainTextBox): its split lines and line count, the text's top and bottom, size
// and scroll position.

#include "D2Check.h"

struct D2SplittedTextStrc;

#pragma pack(push, 2)
struct D2TextBoxStrc
{
    D2SplittedTextStrc* pFirst; // 0x00
    int nLines; // 0x04
    int nTextTop; // 0x08
    int nTextBottom; // 0x0C
    unsigned short nWidth; // 0x10
    unsigned short nHeight; // 0x12
    unsigned short f_14; // 0x14
    int nScroll; // 0x16
    int nField1A; // 0x1A
    int nField1E; // 0x1E
    int nField22; // 0x22
    int nField26; // 0x26
    unsigned short nField2A; // 0x2A
};
#pragma pack(pop)
