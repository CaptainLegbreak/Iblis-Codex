#pragma once
// Client: a list box line (six text columns, its flags, data and font).

#include "D2Check.h"

#pragma pack(push, 2)
struct D2ListBoxLineStrc
{
    inline D2ListBoxLineStrc()
    {
    }

    Unicode wszText0[0x400];
    Unicode f_800[0x400];
    Unicode f_1000[0x400];
    Unicode f_1800[0x400];
    Unicode f_2000[0x400];
    Unicode wszText5[0x400];
    short nFlags;
    int unk0x3002;
    int nData;
    int nFont;
};
#pragma pack(pop)
