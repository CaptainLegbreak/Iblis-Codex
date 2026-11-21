#include "D2CmpStormList.h"

struct D2StormNodeList006027A0Strc : D2StormNodeListStrc { ~D2StormNodeList006027A0Strc(); };
struct D2StormSlotList00602890Strc : D2StormSlotListStrc { ~D2StormSlotList00602890Strc(); };
struct D2StormListE006028D0Strc : D2StormListEStrc { ~D2StormListE006028D0Strc(); };
struct D2StormSlotList00602AA0Strc : D2StormSlotListStrc { ~D2StormSlotList00602AA0Strc(); };
struct D2StormListE00602AE0Strc : D2StormListEStrc { ~D2StormListE00602AE0Strc(); };
struct D2StormSlotList00602DF0Strc : D2StormSlotListStrc { ~D2StormSlotList00602DF0Strc(); };

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    int f_14;

    ~D2StormHashObjectStrc();                                                                               // 0x00602430
};

struct D2StormEntry00602B20Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeList006027A0Strc tList;

    ~D2StormEntry00602B20Strc();
};

struct D2StormEntry00602EC0Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeList006027A0Strc tList;

    ~D2StormEntry00602EC0Strc();
};

// 0x006027A0
D2StormNodeList006027A0Strc::~D2StormNodeList006027A0Strc()
{
}

// 0x00602890
D2StormSlotList00602890Strc::~D2StormSlotList00602890Strc()
{
}

// 0x006028D0
D2StormListE006028D0Strc::~D2StormListE006028D0Strc()
{
    UnlinkAll();
}

// 0x00602AA0
D2StormSlotList00602AA0Strc::~D2StormSlotList00602AA0Strc()
{
}

// 0x00602AE0
D2StormListE00602AE0Strc::~D2StormListE00602AE0Strc()
{
    UnlinkAll();
}

// 0x00602B20
D2StormEntry00602B20Strc::~D2StormEntry00602B20Strc()
{
}

// 0x00602DF0
D2StormSlotList00602DF0Strc::~D2StormSlotList00602DF0Strc()
{
}

// 0x00602EC0
D2StormEntry00602EC0Strc::~D2StormEntry00602EC0Strc()
{
}
