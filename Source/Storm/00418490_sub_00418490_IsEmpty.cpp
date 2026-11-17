int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormListBaseStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

static D2StormLinkStrc* STORM_LinkNextLink(D2StormLinkStrc* pLink, int nLinkOffset)
{
    if ((int)pLink->m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)pLink->m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)pLink - pLink->m_prevlink->m_next;
    return (D2StormLinkStrc*)(pLink->m_next + nLinkOffset);
}

static char* STORM_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

static void STORM_LinkUnlink(D2StormLinkStrc* pLink)
{
    if (pLink->m_prevlink)
    {
        STORM_LinkNextLink(pLink, -1)->m_prevlink = pLink->m_prevlink;
        pLink->m_prevlink->m_next = pLink->m_next;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
    }
}

struct D2StormList00418490Strc : D2StormListBaseStrc { int sub_00418490_IsEmpty(); };
struct D2StormList004185B0Strc : D2StormListBaseStrc { int sub_004185B0_IsEmpty(); };

struct D2StormList00708354Strc : D2StormListBaseStrc { void sub_00418900_UnlinkAll(); ~D2StormList00708354Strc(); };
struct D2StormList00708360Strc : D2StormListBaseStrc { void sub_00418940_UnlinkAll(); ~D2StormList00708360Strc(); };
struct D2StormList0070836CStrc : D2StormListBaseStrc { void sub_00418980_UnlinkAll(); ~D2StormList0070836CStrc(); };
struct D2StormList00708378Strc : D2StormListBaseStrc { void sub_004189C0_UnlinkAll(); ~D2StormList00708378Strc(); };
struct D2StormList00708384Strc : D2StormListBaseStrc { void sub_00418A00_UnlinkAll(); ~D2StormList00708384Strc(); };

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x140];
    int nRefCount;
    char unk0x14C[0x110];

    ~D2StormArchiveRecStrc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormFileRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x104];
    void* pBuffer0x10C;
    void* hFile;
    D2StormArchiveRecStrc* f_114;
    char unk0x118[0x14];
    void* pBuffer0x12C;
    char unk0x130[0x8];
    void* pBuffer0x138;
    char unk0x13C[0x1C];

    D2StormFileRecStrc();
};

// build: symbol ??1D2StormArchiveRecStrc@@QAE@XZ 0x00418A50
// 0x00418490
int D2StormList00418490Strc::sub_00418490_IsEmpty()
{
    return STORM_LinkNext(&m_terminator) == 0;
}

// 0x004185B0
int D2StormList004185B0Strc::sub_004185B0_IsEmpty()
{
    return STORM_LinkNext(&m_terminator) == 0;
}

// 0x00418C60
D2StormList00708354Strc::~D2StormList00708354Strc()
{
    sub_00418900_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418CC0
D2StormList00708360Strc::~D2StormList00708360Strc()
{
    sub_00418940_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418D00
D2StormList0070836CStrc::~D2StormList0070836CStrc()
{
    sub_00418980_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418D40
D2StormList00708378Strc::~D2StormList00708378Strc()
{
    sub_004189C0_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418DA0
D2StormList00708384Strc::~D2StormList00708384Strc()
{
    sub_00418A00_UnlinkAll();
    STORM_LinkUnlink(&m_terminator);
}

// 0x00418E60
D2StormFileRecStrc::D2StormFileRecStrc()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
    pBuffer0x10C = 0;
    hFile = (void*)-1;
    f_114 = 0;
    pBuffer0x12C = 0;
    pBuffer0x138 = 0;
}

// 0x00418E90
void __fastcall sub_00418E90_ReleaseArchive(D2StormArchiveRecStrc* pArch)
{
    if (pArch && !--pArch->nRefCount)
        delete pArch;
}
