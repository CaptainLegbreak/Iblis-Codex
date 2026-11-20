#include "Storm.h"
#include "D2GameTypes.h"

struct D2BigPairStrc;
struct D2CriticalSectionStrc;
struct D2StormLinkStrc;
struct D2StormList00708354Strc;
struct D2StormList00708360Strc;
struct D2StormList0070836CStrc;
struct D2StormList00708378Strc;
struct D2StormList00708384Strc;
struct D2StormList00708420Strc;
struct D2StormList00708860Strc;
struct D2StormList007088E8Strc;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00881860[]; // 0x00881860
void __cdecl sub_006CB420_DestroyLock(); // 0x006CB420
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824
extern unsigned char gCriticalSection_00881894[]; // 0x00881894
void __cdecl sub_006CB440_DestroyLock(); // 0x006CB440
void __cdecl sub_006CB450_StaticFiniNewsCache(); // 0x006CB450
extern unsigned char gCriticalSection_00881F64[24]; // 0x00881F64
void __cdecl sub_006CB470_DestroyLock(); // 0x006CB470

struct D2BigPairStrc {
    void* pState;
    D2BigPairStrc(); // 0x00528500
};

extern D2BigPairStrc gtBigPair_0088273C; // 0x0088273C
void __cdecl sub_006CB480_DestroyBigPair(); // 0x006CB480
extern int gnDivisor_00731014; // 0x00731014
extern int gnQuotient_00883D60; // 0x00883D60
extern int gnSource_00731DCC; // 0x00731DCC
extern int gnSource_00731DF8; // 0x00731DF8
extern int gnSource_00731E24; // 0x00731E24
extern int gnSource_00731E60; // 0x00731E60
extern int gnCopy_00731EB8; // 0x00731EB8
extern int gnCopy_00731EC0; // 0x00731EC0
extern int gnCopy_00731EC8; // 0x00731EC8
extern int gnCopy_00731ED0; // 0x00731ED0
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260
extern unsigned int gdwStartTick_008846E8; // 0x008846E8
extern unsigned char gCriticalSection_0088CAA8[]; // 0x0088CAA8
void __cdecl sub_006CB490_DestroyLock(); // 0x006CB490
void __cdecl sub_006CB4E0_DestroyLock(); // 0x006CB4E0
extern unsigned int gnListTerminator_0074C490; // 0x0074C490
extern void* gpListHead_0074C494; // 0x0074C494
void __cdecl sub_006CB4F0_DestroyList(); // 0x006CB4F0
extern unsigned int gnListTerminator_0074C49C; // 0x0074C49C
extern void* gpListHead_0074C4A0; // 0x0074C4A0
void __cdecl sub_006CB550_DestroyList(); // 0x006CB550


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC
extern D2CriticalSectionStrc gCriticalSection_0075E838; // 0x0075E838
extern D2CriticalSectionStrc gCriticalSection_0075E850; // 0x0075E850
extern D2CriticalSectionStrc gCriticalSection_00779068; // 0x00779068
extern D2CriticalSectionStrc gCriticalSection_00779080; // 0x00779080

// build: context ??_GD2StormList00708354Strc@@QAEPAXI@Z
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

struct D2StormList00708354Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708354Strc()
    {
        sub_00418900_UnlinkAll();
    }
    void sub_00418900_UnlinkAll(); // 0x00418900
};

extern D2StormList00708354Strc gArchiveList_00708354; // 0x00708354

struct D2StormList00708360Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708360Strc()
    {
        sub_00418940_UnlinkAll();
    }
    void sub_00418940_UnlinkAll(); // 0x00418940
};

extern D2StormList00708360Strc gRequestList_00708360; // 0x00708360

struct D2StormList0070836CStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList0070836CStrc()
    {
        sub_00418980_UnlinkAll();
    }
    void sub_00418980_UnlinkAll(); // 0x00418980
};

extern D2StormList0070836CStrc gList_0070836C; // 0x0070836C

struct D2StormList00708378Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708378Strc()
    {
        sub_004189C0_UnlinkAll();
    }
    void sub_004189C0_UnlinkAll(); // 0x004189C0
};

extern D2StormList00708378Strc gList_00708378; // 0x00708378

struct D2StormList00708384Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708384Strc()
    {
        sub_00418A00_UnlinkAll();
    }
    void sub_00418A00_UnlinkAll(); // 0x00418A00
};

extern D2StormList00708384Strc gList_00708384; // 0x00708384

struct D2StormList00708420Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708420Strc()
    {
        sub_0041C770_UnlinkAll();
    }
    void sub_0041C770_UnlinkAll(); // 0x0041C770
};

extern D2StormList00708420Strc gList_00708420; // 0x00708420
extern D2CriticalSectionStrc gCriticalSection_00779214; // 0x00779214

struct D2StormList00708860Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList00708860Strc()
    {
        sub_00420750_UnlinkAll();
    }
    void sub_00420750_UnlinkAll(); // 0x00420750
};

extern D2StormList00708860Strc gList_00708860; // 0x00708860
extern D2CriticalSectionStrc gCriticalSection_0077930C; // 0x0077930C

struct D2StormList007088E8Strc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormList007088E8Strc()
    {
        sub_00426CF0_UnlinkAll();
    }
    void sub_00426CF0_UnlinkAll(); // 0x00426CF0
};

extern D2StormList007088E8Strc gList_007088E8; // 0x007088E8

inline void* __cdecl operator new(unsigned int, void* location);

// 0x006CAE80
void __cdecl sub_006CAE80_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00881860);
    sub_00683824_RegisterExit(sub_006CB420_DestroyLock);
}

// 0x006CAEA0
void __cdecl sub_006CAEA0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00881894);
    sub_00683824_RegisterExit(sub_006CB440_DestroyLock);
}

// 0x006CAEC0
void __cdecl sub_006CAEC0_RegisterCleanup()
{
    sub_00683824_RegisterExit(sub_006CB450_StaticFiniNewsCache);
}

// 0x006CAED0
void __cdecl sub_006CAED0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00881F64);
    sub_00683824_RegisterExit(sub_006CB470_DestroyLock);
}

inline void* __cdecl operator new(unsigned int, void* location) { return location; }

// 0x006CAEF0
void __cdecl sub_006CAEF0_InitializeBigPair()
{
    new (&gtBigPair_0088273C) D2BigPairStrc;
    atexit(sub_006CB480_DestroyBigPair);
}

// 0x006CAF10
void __cdecl sub_006CAF10_SetPerSecond()
{
    gnQuotient_00883D60 = 1000 / gnDivisor_00731014;
}

// 0x006CAF30
void __cdecl sub_006CAF30_SnapshotCounters()
{
    gnCopy_00731EB8 = gnSource_00731DCC;
    gnCopy_00731EC0 = gnSource_00731DF8;
    gnCopy_00731EC8 = gnSource_00731E24;
    gnCopy_00731ED0 = gnSource_00731E60;
}

#include "gen/data/Source/Storm/Unknown_006CAE80.inc"

// 0x006CAF60
void __cdecl sub_006CAF60_InitStartTick()
{
    gdwStartTick_008846E8 = GetTickCount();
}

// 0x006CAF70
void __cdecl sub_006CAF70_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0088CAA8);
    sub_00683824_RegisterExit(sub_006CB490_DestroyLock);
}

// 0x006CB010
void __cdecl sub_006CB010_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0096D610);
    sub_00683824_RegisterExit(sub_006CB4E0_DestroyLock);
}

// 0x006CB030
void __cdecl sub_006CB030_InitializeList()
{
    gpListHead_0074C494 = (void*)~(unsigned int)&gnListTerminator_0074C490;
    atexit(sub_006CB4F0_DestroyList);
}

// 0x006CB050
void __cdecl sub_006CB050_InitializeList()
{
    gpListHead_0074C4A0 = (void*)~(unsigned int)&gnListTerminator_0074C49C;
    atexit(sub_006CB550_DestroyList);
}

// 0x006CB070
void __cdecl sub_006CB070_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_0075E838);
}

// 0x006CB080
void __cdecl sub_006CB080_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_0075E850);
}

// 0x006CB0A0
void __cdecl sub_006CB0A0_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_00779068);
}

// 0x006CB0B0
void __cdecl sub_006CB0B0_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_00779080);
}

// 0x006CB0C0
void __cdecl sub_006CB0C0_DestroyList()
{
    gArchiveList_00708354.~D2StormList00708354Strc();
}

// 0x006CB120
void __cdecl sub_006CB120_DestroyList()
{
    gRequestList_00708360.~D2StormList00708360Strc();
}

// 0x006CB180
void __cdecl sub_006CB180_DestroyList()
{
    gList_0070836C.~D2StormList0070836CStrc();
}

// 0x006CB1E0
void __cdecl sub_006CB1E0_DestroyList()
{
    gList_00708378.~D2StormList00708378Strc();
}

// 0x006CB240
void __cdecl sub_006CB240_DestroyList()
{
    gList_00708384.~D2StormList00708384Strc();
}

// 0x006CB2A0
void __cdecl sub_006CB2A0_DestroyList()
{
    gList_00708420.~D2StormList00708420Strc();
}

// 0x006CB300
void __cdecl sub_006CB300_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_00779214);
}

// 0x006CB310
void __cdecl sub_006CB310_DestroyList()
{
    gList_00708860.~D2StormList00708860Strc();
}

// 0x006CB370
void __cdecl sub_006CB370_DeleteCriticalSection()
{
    DeleteCriticalSection(&gCriticalSection_0077930C);
}

// 0x006CB380
void __cdecl sub_006CB380_DestroyList()
{
    gList_007088E8.~D2StormList007088E8Strc();
}
