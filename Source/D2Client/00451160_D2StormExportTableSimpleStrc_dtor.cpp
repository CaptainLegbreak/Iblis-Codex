struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

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

// 0x00451160
D2StormExportTableSimpleStrc::~D2StormExportTableSimpleStrc()
{
}

// 0x004511D0
D2StormExportTableSyncStrc::~D2StormExportTableSyncStrc()
{
    DeleteCriticalSection(&m_cs);
}
