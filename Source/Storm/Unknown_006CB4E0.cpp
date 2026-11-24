#include "Storm.h"
#include "D2StormAutoLink.h"

struct D2StormList0074C48CStrc;
struct D2StormList0074C498Strc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC

struct D2StormList0074C48CStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList0074C48CStrc()
    {
        UnlinkAll();
    }
    void UnlinkAll(); // 0x006C43F0
};

extern D2StormList0074C48CStrc gList_0074C48C; // 0x0074C48C

struct D2StormList0074C498Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList0074C498Strc()
    {
        UnlinkAll();
    }
    void UnlinkAll(); // 0x006C43F0
};

extern D2StormList0074C498Strc gList_0074C498; // 0x0074C498

// 0x006CB4F0
void __cdecl sub_006CB4F0_DestroyList()
{
    gList_0074C48C.~D2StormList0074C48CStrc();
}

// 0x006CB550
void __cdecl sub_006CB550_DestroyList()
{
    gList_0074C498.~D2StormList0074C498Strc();
}
