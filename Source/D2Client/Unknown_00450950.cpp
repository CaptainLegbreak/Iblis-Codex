#include "D2GameTypes.h"
#include "D2StormAutoLink.h"
#include "D2StormListArray.h"
struct D2SGameDataStrc;
struct D2StormLinkStrc;
struct D2StormHashKeyNoneStrc;
struct D2StormHashObjectStrc;
struct D2StormListAStrc;
struct D2StormChunkListStrc;
struct D2StormListArrayStrc;
struct D2StormHashTableStrc;
struct D2CriticalSectionStrc;
struct D2StormHashTableReuseStrc;
struct D2StormExportTableSimpleStrc;
struct D2StormExportTableSyncStrc;

struct D2StormHashKeyNoneStrc
{
};

struct D2StormHashObjectStrc
{
    unsigned int m_hashval;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc m_linktofull;
    D2StormHashKeyNoneStrc m_key;

    D2StormHashObjectStrc()
    {
    }
    D2StormHashObjectStrc(const D2StormHashObjectStrc&)
    {
    }
};

// build: symbol ??0D2SGameDataStrc@@QAE@ABU0@@Z 0x00450950
// 0x00450950
struct D2SGameDataStrc : D2StormHashObjectStrc
{
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
    unsigned short wUnk0x28;
    char szUnk0x2A[0x10];
    char szUnk0x3A[0x10];
    char szUnk0x4A[0x20];
    char nUnk0x6A;
    char nUnk0x6B;
    char nUnk0x6C;
    char nUnk0x6D;
    char nUnk0x6E;
    int nUnk0x70;
    int nUnk0x74;
    unsigned short wUnk0x78;
    int nUnk0x7C;
    int nUnk0x80;
    int nUnk0x84;
    int nUnk0x88;
    int nUnk0x8C;
    int nUnk0x90;
    int nUnk0x94;
    int nUnk0x98;
    int nUnk0x9C;
    int nUnk0xA0;
    int nUnk0xA4;
    int nUnk0xA8;
    int nUnk0xAC;
    int nUnk0xB0;
    int nUnk0xB4;
    int nUnk0xB8;
    int nUnk0xBC;
    int nUnk0xC0;
    int nUnk0xC4;
    int nUnk0xC8;
    int nUnk0xCC;
    int nUnk0xD0;
    int nUnk0xD4;
    int nUnk0xD8;
    int nUnk0xDC;
    int nUnk0xE0;
    int nUnk0xE4;
    int nUnk0xE8;
    int nUnk0xEC;
    char aUnk0xF0[0x1000];
    int nUnk0x10F0;
    int nUnk0x10F4;
    char aUnk0x10F8[0x28];
    int aUnk0x1120[0x80];
    int aUnk0x1320[0x80];
    int aUnk0x1520[0x80];
    int aUnk0x1720[0x80];
    int aUnk0x1920[0x80];
    int nUnk0x1B20;
    int aUnk0x1B24[0x80];
    int nUnk0x1D24;
    int nUnk0x1D28;
    int nUnk0x1D2C;
    int aUnk0x1D30[0x10];
    int aUnk0x1D70[0x12];
    int nUnk0x1DB8;
    int nUnk0x1DBC;
    int nUnk0x1DC0;
    int nUnk0x1DC4;
    int nUnk0x1DC8;
    int nUnk0x1DCC;
    int nUnk0x1DD0;
    int nUnk0x1DD4;
    int nUnk0x1DD8;
    int nUnk0x1DDC;
    int nUnk0x1DE0;
    int nUnk0x1DE4;
    int nUnk0x1DE8;
    int nUnk0x1DEC;
    int nUnk0x1DF0;
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00450580_DeleteAll();                                                                          // 0x00450580
};


struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableStrc();
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00450D20_Clear();
    void sub_0044FA00_InternalClear(int bWarn);                                                             // 0x0044FA00
};



extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

struct D2StormHashTableReuseStrc
{
    void* pVTable;
    char unk0x04[0x40];

    ~D2StormHashTableReuseStrc();                                                                           // 0x00450760
};

struct D2StormExportTableSimpleStrc : D2StormHashTableReuseStrc
{
    unsigned int unk0x44;
    unsigned int m_sequence;
    void* m_wrapper;

    ~D2StormExportTableSimpleStrc();
};

struct D2StormExportTableSyncStrc : D2StormExportTableSimpleStrc
{
    D2CriticalSectionStrc m_cs;

    ~D2StormExportTableSyncStrc();
};


inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void sub_Y01_EmitGameDataCopy(void* pWhere, const D2SGameDataStrc& tSource, void* pOther, const D2SGameDataStrc& tOther)
{
    new (pWhere) D2SGameDataStrc(tSource);
    new (pOther) D2SGameDataStrc(tOther);
}

// 0x00450D20
void D2StormHashTableStrc::sub_00450D20_Clear() {
 sub_0044FA00_InternalClear(0);
}

// 0x00451160
D2StormExportTableSimpleStrc::~D2StormExportTableSimpleStrc()
{
}

// 0x004511D0
D2StormExportTableSyncStrc::~D2StormExportTableSyncStrc()
{
    DeleteCriticalSection(&m_cs);
}
