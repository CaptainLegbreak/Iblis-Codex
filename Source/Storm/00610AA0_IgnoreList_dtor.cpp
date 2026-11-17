struct D2CommonStormNodeStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;

struct StringEntryNode;
struct MappingEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>;
typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;
template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>;
typedef TSHashTable<MappingEntryNode, HASHKEY_STRI> D2CommonStormHashTableBStrc;
class ChatIgnoreList;
typedef ChatIgnoreList D2CommonIgnoreListBaseStrc;
class IgnoreList;
typedef IgnoreList D2CommonIgnoreListStrc;
// build: symbol ??1?$TSHashTable@UStringEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x0060FD90
// build: symbol ??1?$TSHashTable@UMappingEntryNode@@VHASHKEY_STRI@@@@UAE@XZ 0x00610550

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x0060FFA0
    virtual D2CommonStormNodeStrc* sub_0060FEF0_InternalNew(D2CommonStormSlotListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x0060FEF0
    virtual ~TSHashTable();                                                                 // 0x0060FD90
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020

    char unk0x04[0x24];

    void sub_0060EB70_InternalClear(int bWarn);                                                             // 0x0060EB70
};

template <> class TSHashTable<MappingEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_00610690_InternalDelete(D2CommonStormNodeStrc* pNode);                                 // 0x00610690
    virtual D2CommonStormNodeStrc* sub_006106D0_InternalNew(D2CommonStormSlotListBStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x006106D0
    virtual ~TSHashTable();                                                                 // 0x00610550
    virtual void sub_006107D0_VirtSlot3();                                                                  // 0x006107D0

    char unk0x04[0x24];

    void sub_0060EE60_InternalClear(int bWarn);                                                             // 0x0060EE60
};

class ChatIgnoreList
{
public:
    virtual int sub_00610EB0_Add(const char* szName) = 0;
    virtual void sub_0060FB20_VirtSlot1() = 0;
    virtual int sub_00610380_IsListed(const char* szName) = 0;
    virtual void sub_00610F90_VirtSlot3() = 0;
    virtual void sub_0060FBE0_VirtSlot4() = 0;
    virtual void sub_0060FC40_VirtSlot5() = 0;
    virtual void sub_00611320_VirtSlot6() = 0;
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;
    virtual int sub_0060DDF0_IsEnabled() = 0;
    virtual void sub_0060DE00_VirtSlot9() = 0;
    virtual void sub_0060F500_VirtSlot10() = 0;
    // 0x0060DD50
    virtual ~ChatIgnoreList()
    {
    }
};

class IgnoreList : public D2CommonIgnoreListBaseStrc
{
public:
    virtual int sub_00610EB0_Add(const char* szName);                                                       // 0x00610EB0
    virtual void sub_0060FB20_VirtSlot1();                                                                  // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName);                                                  // 0x00610380
    virtual void sub_00610F90_VirtSlot3();                                                                  // 0x00610F90
    virtual void sub_0060FBE0_VirtSlot4();                                                                  // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5();                                                                  // 0x0060FC40
    virtual void sub_00611320_VirtSlot6();                                                                  // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize);                        // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled();                                                                   // 0x0060DDF0
    virtual void sub_0060DE00_VirtSlot9();                                                                  // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10();                                                                 // 0x0060F500
    virtual ~IgnoreList();

    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2C;
    D2CommonStormHashTableBStrc m_table54;
    char unk0x7C[0x10C];
};

// build: symbol ??_7ChatIgnoreList@@6B@ 0x006E6248
// build: symbol ??_7IgnoreList@@6B@ 0x006E62DC
// 0x00610AA0
D2CommonIgnoreListStrc::~IgnoreList()
{
    m_table.sub_0060EB70_InternalClear(0);
    m_table54.sub_0060EE60_InternalClear(0);
}
