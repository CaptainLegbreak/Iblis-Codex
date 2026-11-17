#include "Storm.h"

struct D2StormLinkStrc;
struct D2StormList0074C48CStrc;
struct D2StormList0074C498Strc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC

// build: context ??_GD2StormList0074C48CStrc@@QAEPAXI@Z
struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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
};

struct D2StormList0074C48CStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList0074C48CStrc()
    {
        sub_006C43F0_UnlinkAll();
    }
    void sub_006C43F0_UnlinkAll(); // 0x006C43F0
};

extern D2StormList0074C48CStrc gList_0074C48C; // 0x0074C48C

struct D2StormList0074C498Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList0074C498Strc()
    {
        sub_006C43F0_UnlinkAll();
    }
    void sub_006C43F0_UnlinkAll(); // 0x006C43F0
};

extern D2StormList0074C498Strc gList_0074C498; // 0x0074C498

// 0x006CB4E0
void __cdecl sub_006CB4E0_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_0096D610);
}

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
