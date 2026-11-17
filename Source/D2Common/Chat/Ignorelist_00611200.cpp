inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

extern "C" void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);
extern "C" void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);
extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszTypeNameStringEntryList_0074366C[];                                                          // 0x0074366C
extern "C" const char gszTypeNameMappingEntryList_007436AC[];                                                         // 0x007436AC

int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, unsigned int nSize);                                    // 0x00406B60
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                             // 0x0041D300
const char* __stdcall SStrChrR(const char* szString, char nChar);                                                     // 0x004134D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                          // 0x00413800
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                          // 0x004135D0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
struct _iobuf;

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

    D2CommonStormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2CommonStormSlotLinkStrc()
    {
        Unlink();
    }
    D2CommonStormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2CommonStormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2CommonStormSlotLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2CommonStormSlotListAStrc(const D2CommonStormSlotListAStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListAStrc()
    {
        UnlinkAll();
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void UnlinkAll(); // 0x0060E820
    static void operator delete(void* pMemory);
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    D2CommonStormSlotListBStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2CommonStormSlotListBStrc(const D2CommonStormSlotListBStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2CommonStormSlotListBStrc()
    {
        UnlinkAll();
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    D2CommonStormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2CommonStormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void UnlinkAll(); // 0x0060ECB0
    static void operator delete(void* pMemory);
};

// build: symbol ??_7IgnoreList@@6B@ 0x006E62DC

// build: context D2CommonStormSlotListAStrc::UnlinkAll
inline __declspec(noinline) void D2CommonStormSlotListAStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

// build: context D2CommonStormSlotListBStrc::UnlinkAll
inline __declspec(noinline) void D2CommonStormSlotListBStrc::UnlinkAll()
{
    char* pNode;
    while ((pNode = Head()) != 0)
        Link(pNode)->Unlink();
}

inline void D2CommonStormSlotListAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

inline void D2CommonStormSlotListBStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

static unsigned int __stdcall STORM_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;

    D2CommonStormSlotArrayAStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    unsigned int sub_0060E2A0_CalcChunkSize(unsigned int nCount);
    void sub_0060F390_ReallocData(unsigned int nAlloc);
    void sub_0060F9D0_SetCount(unsigned int nCount);
};

struct D2CommonStormSlotArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListBStrc* f_8;
    unsigned int f_C;

    D2CommonStormSlotArrayBStrc()
    {
        f_0 = 0;
        f_4 = 0;
        f_8 = 0;
        f_C = 0;
    }
    unsigned int sub_0060E300_CalcChunkSize(unsigned int nCount);
    void sub_0060F720_ReallocData(unsigned int nAlloc);
    void sub_006100B0_SetCount(unsigned int nCount);
};

// 0x0060E2A0
inline __declspec(noinline) unsigned int D2CommonStormSlotArrayAStrc::sub_0060E2A0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// 0x0060E300
inline __declspec(noinline) unsigned int D2CommonStormSlotArrayBStrc::sub_0060E300_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x15)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x15;
    return 0x15;
}

// build: context D2CommonStormSlotArrayAStrc::sub_0060F390_ReallocData
inline __declspec(noinline) void D2CommonStormSlotArrayAStrc::sub_0060F390_ReallocData(unsigned int nAlloc)
{
    D2CommonStormSlotListAStrc* pOldData = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOldData[i].~D2CommonStormSlotListAStrc();
    f_0 = nAlloc;
    f_8 = (D2CommonStormSlotListAStrc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2CommonStormSlotListAStrc), gszTypeNameStringEntryList_0074366C, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2CommonStormSlotListAStrc*)SMemAlloc(nAlloc * sizeof(D2CommonStormSlotListAStrc), gszTypeNameStringEntryList_0074366C, -2, 0);
        if (pOldData)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
            {
                new (&f_8[i]) D2CommonStormSlotListAStrc(pOldData[i]);
                pOldData[i].~D2CommonStormSlotListAStrc();
            }
            SMemFree(pOldData, gszTypeNameStringEntryList_0074366C, -2, 0);
        }
    }
}

// build: context D2CommonStormSlotArrayBStrc::sub_0060F720_ReallocData
inline __declspec(noinline) void D2CommonStormSlotArrayBStrc::sub_0060F720_ReallocData(unsigned int nAlloc)
{
    D2CommonStormSlotListBStrc* pOldData = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOldData[i].~D2CommonStormSlotListBStrc();
    f_0 = nAlloc;
    f_8 = (D2CommonStormSlotListBStrc*)SMemReAlloc(pOldData, nAlloc * sizeof(D2CommonStormSlotListBStrc), gszTypeNameMappingEntryList_007436AC, -2, 0x10);
    if (!f_8)
    {
        f_8 = (D2CommonStormSlotListBStrc*)SMemAlloc(nAlloc * sizeof(D2CommonStormSlotListBStrc), gszTypeNameMappingEntryList_007436AC, -2, 0);
        if (pOldData)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
            {
                new (&f_8[i]) D2CommonStormSlotListBStrc(pOldData[i]);
                pOldData[i].~D2CommonStormSlotListBStrc();
            }
            SMemFree(pOldData, gszTypeNameMappingEntryList_007436AC, -2, 0);
        }
    }
}

// build: context D2CommonStormSlotArrayAStrc::sub_0060F9D0_SetCount
inline __declspec(noinline) void D2CommonStormSlotArrayAStrc::sub_0060F9D0_SetCount(unsigned int nCount)
{
    if (nCount > f_4)
    {
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_0060E2A0_CalcChunkSize(nCount);
            sub_0060F390_ReallocData(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = f_4; i < nCount; i++)
            new (&f_8[i]) D2CommonStormSlotListAStrc;
    }
    else if (nCount < f_4)
    {
        for (unsigned int i = nCount; i < f_4; i++)
            f_8[i].~D2CommonStormSlotListAStrc();
    }
    f_4 = nCount;
}

// build: context D2CommonStormSlotArrayBStrc::sub_006100B0_SetCount
inline __declspec(noinline) void D2CommonStormSlotArrayBStrc::sub_006100B0_SetCount(unsigned int nCount)
{
    if (nCount > f_4)
    {
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_0060E300_CalcChunkSize(nCount);
            sub_0060F720_ReallocData(STORM_RoundUp(nCount, nChunk));
        }
        for (unsigned int i = f_4; i < nCount; i++)
            new (&f_8[i]) D2CommonStormSlotListBStrc;
    }
    else if (nCount < f_4)
    {
        for (unsigned int i = nCount; i < f_4; i++)
            f_8[i].~D2CommonStormSlotListBStrc();
    }
    f_4 = nCount;
}

struct D2CommonStringEntryNodeStrc;
struct D2CommonMappingEntryNodeStrc;

struct StringEntryNode;
struct MappingEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>;
typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;
template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>;
typedef TSHashTable<MappingEntryNode, HASHKEY_STRI> D2CommonStormHashTableBStrc;
class ChatIgnoreList;
typedef ChatIgnoreList D2CommonChatIgnoreListStrc;
class IgnoreList;
typedef IgnoreList D2CommonIgnoreListStrc;
// build: symbol ??0?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@QAE@XZ 0x006104A0
// build: symbol ??0?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@QAE@XZ 0x00610B30
// build: symbol ??1?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x0060FD90
// build: symbol ??1?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x00610550

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_0060FFA0_InternalDelete(D2CommonStringEntryNodeStrc* pNode);                                    // 0x0060FFA0
    virtual D2CommonStringEntryNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~TSHashTable();                                                                         // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();                                                                          // 0x00610020
    static void operator delete(void* pMemory);

    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable(); // 0x006104A0
};

template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_00610690_InternalDelete(D2CommonMappingEntryNodeStrc* pNode);                                   // 0x00610690
    virtual D2CommonMappingEntryNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~TSHashTable();                                                                         // 0x00610550
    virtual void sub_006107D0_VirtSlot3();                                                                          // 0x006107D0
    static void operator delete(void* pMemory);

    D2CommonStormSlotListBStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayBStrc m_slotlistarray;
    unsigned int m_slotmask;

    TSHashTable(); // 0x00610B30
};

// build: context ??0?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@*
inline __declspec(noinline) D2CommonStormHashTableAStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.sub_0060F9D0_SetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
}

// build: context ??0?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@*
inline __declspec(noinline) D2CommonStormHashTableBStrc::TSHashTable()
{
    m_fullnessIndicator = 0;
    m_fulllist.ChangeLinkOffset(0xC);
    m_slotmask = 3;
    m_slotlistarray.sub_006100B0_SetCount(4);
    for (unsigned int i = 0; i <= m_slotmask; i++)
        m_slotlistarray.f_8[i].ChangeLinkOffset(4);
}

class ChatIgnoreList
{
public:
    virtual int sub_00610EB0_Add(const char* szName) = 0;
    virtual int sub_0060FB20_Remove(const char* szName) = 0;
    virtual int sub_00610380_IsListed(const char* szName) = 0;
    virtual int sub_00610F90_AddAlias(const char* szName) = 0;
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;
    virtual int sub_0060FC40_VirtSlot5(const char* szName) = 0;
    virtual int sub_00611320_StoreAccountAlias(char* szRaw, int nRawLen) = 0;
    virtual int sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;
    virtual int sub_0060DDF0_IsEnabled() = 0;
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;
    virtual void sub_0060F500_VirtSlot10() = 0;
    virtual ~ChatIgnoreList();                                                                          // 0x0060DD50
    static void operator delete(void* pMemory);
};

class IgnoreList : public D2CommonChatIgnoreListStrc
{
public:
    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2;
    D2CommonStormHashTableBStrc m_table3;
    _iobuf* m_pFile;
    char szFileName[0x104];
    int m_bEnabled;

    IgnoreList();
    virtual int sub_00610EB0_Add(const char* szName);                                                               // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName);                                                            // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName);                                                          // 0x00610380
    virtual int sub_00610F90_AddAlias(const char* szName);                                                          // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName);                                                       // 0x0060FBE0
    virtual int sub_0060FC40_VirtSlot5(const char* szName);                                                         // 0x0060FC40
    virtual int sub_00611320_StoreAccountAlias(char* szRaw, int nRawLen);                                           // 0x00611320
    virtual int sub_0060F870_Translate(const char* szName, char* szOut, int nSize);                                 // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled();                                                                           // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled);                                                             // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10();                                                                         // 0x0060F500
    virtual ~IgnoreList();                                                                              // 0x00610AA0
    void sub_00611050_Load();                                                                                       // 0x00611050
};

// 0x00611200
D2CommonIgnoreListStrc::IgnoreList()
{
    m_pFile = 0;
    m_bEnabled = 1;

    char szPath[0x104];
    sub_00406B60_GetModuleDirectory(szPath, 0x104);
    SMemZero(szFileName, 0x104);
    char* pSep = (char*)SStrChrR(szPath, 0x5C);
    if (pSep)
        pSep[1] = 0;
    sub_00413800(szPath, "ignorelist", 0x104);
    SStrCopy(szFileName, szPath, 0x104);

    unsigned long dwEnabled = 1;
    SRegLoadValue("Diablo II", "Persistent Ignore", 0, &dwEnabled);
    m_bEnabled = dwEnabled;
    sub_00611050_Load();
}
