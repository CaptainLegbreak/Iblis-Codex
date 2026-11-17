inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

struct D2CriticalSectionStrc
{
    void* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned int SpinCount;
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection);

struct D2StormEntryArray604080Strc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    D2StormEntryArray604080Strc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
};

struct D2StormEntryLink604080Strc
{
    D2StormEntryLink604080Strc* m_prevlink;
    char* m_next;

    D2StormEntryLink604080Strc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2StormEntryList604080Strc
{
    int m_linkoffset;
    D2StormEntryLink604080Strc m_terminator;

    D2StormEntryList604080Strc()
    {
        m_linkoffset = 0;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormEntryList604080Strc(const D2StormEntryList604080Strc& source)
    {
        m_linkoffset = source.m_linkoffset;
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2StormEntry604080Strc
{
    unsigned int unk0x00;
    D2StormEntryArray604080Strc tArray;
    unsigned int unk0x14;
    unsigned int nField18;
    unsigned int nField1C;
    unsigned int nField20;
    unsigned int nField24;
    unsigned int nField28;
    D2StormEntryList604080Strc tList;

    D2StormEntry604080Strc()
    {
    }
    D2StormEntry604080Strc(const D2StormEntry604080Strc& source) : nField18(source.nField18), nField1C(source.nField1C),
        nField20(source.nField20), nField24(source.nField24), nField28(source.nField28), tList(source.tList)
    {
    }
};

struct D2GameHashTableStrc
{
    void sub_00602800_InternalClear(int bWarn);
    void sub_00604070_Clear();
};

struct D2StormEntryGrowArray604460Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormEntry604080Strc* f_8;
    unsigned int f_C;

    D2StormEntry604080Strc* sub_006043B0_New();
};

struct D2Storm604460Strc
{
    D2StormEntryGrowArray604460Strc tArray;

    D2StormEntry604080Strc* sub_00604460_New();
};

struct D2Storm604470Strc
{
    unsigned int nField00;
    unsigned int nField04;
    unsigned int f_8;
    unsigned int nField0C;
    unsigned int nField10;
    unsigned int nField14;

    D2Storm604470Strc();
};

struct D2StormCritSectStrc
{
    D2CriticalSectionStrc f_0;

    ~D2StormCritSectStrc()
    {
        DeleteCriticalSection(&f_0);
    }
};

struct D2GameHashTableReuseViewStrc
{
    char unk0x00[0x44];

    ~D2GameHashTableReuseViewStrc();
};

struct D2GameExportTableSimpleViewStrc : D2GameHashTableReuseViewStrc
{
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;

    ~D2GameExportTableSimpleViewStrc();
};

struct D2GameDataTableViewStrc : D2GameHashTableReuseViewStrc
{
    int f_44;
    unsigned int m_sequence;
    int m_wrapped;
    D2StormCritSectStrc m_sync;

    ~D2GameDataTableViewStrc();
};

void D2GameHashTableStrc::sub_00604070_Clear()
{
    sub_00602800_InternalClear(0);
}

void __fastcall sub_00604080_ConstructEntry(D2StormEntry604080Strc* pEntry)
{
    new (pEntry) D2StormEntry604080Strc;
}

void __fastcall sub_00604100_CopyConstructEntry(D2StormEntry604080Strc* pEntry, const D2StormEntry604080Strc* pSource)
{
    new (pEntry) D2StormEntry604080Strc(*pSource);
}

D2StormEntry604080Strc* D2Storm604460Strc::sub_00604460_New()
{
    return tArray.sub_006043B0_New();
}

// 0x00450F80
D2Storm604470Strc::D2Storm604470Strc()
{
    nField00 = 0;
    nField04 = 0;
    f_8 = 0;
    nField0C = 0;
    nField10 = 0;
    nField14 = 0;
}

D2GameExportTableSimpleViewStrc::~D2GameExportTableSimpleViewStrc()
{
}

D2GameDataTableViewStrc::~D2GameDataTableViewStrc()
{
}
