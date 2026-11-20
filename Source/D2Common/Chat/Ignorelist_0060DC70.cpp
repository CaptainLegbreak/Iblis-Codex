#include "D2StormLink.h"
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
char* __stdcall sub_00414310(const char* szString);                                                             // 0x00414310
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

struct D2StormHashKeyStrIAStrc
{
    char* m_str;

    D2StormHashKeyStrIAStrc(const char* szString);
    D2StormHashKeyStrIAStrc& operator=(const D2StormHashKeyStrIAStrc& source);
};

struct D2StormHashKeyStrIBStrc
{
    char* m_str;

    D2StormHashKeyStrIBStrc(const char* szString);
    D2StormHashKeyStrIBStrc& operator=(const D2StormHashKeyStrIBStrc& source);
};

// build: symbol ??4D2StormHashKeyStrIAStrc@@QAEAAU0@ABU0@@Z 0x0060DCB0
// build: symbol ??4D2StormHashKeyStrIBStrc@@QAEAAU0@ABU0@@Z 0x0060E130
// build: symbol ??_7ChatIgnoreList@@6B@ 0x006E6248
// 0x0060DC70
D2StormHashKeyStrIAStrc::D2StormHashKeyStrIAStrc(const char* szString)
{
    m_str = sub_00414310(szString);
}

// 0x0060DCB0
D2StormHashKeyStrIAStrc& D2StormHashKeyStrIAStrc::operator=(const D2StormHashKeyStrIAStrc& source)
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
    m_str = sub_00414310(source.m_str);
    return *this;
}

// 0x0060DD00
D2StormHashKeyStrIBStrc::D2StormHashKeyStrIBStrc(const char* szString)
{
    m_str = sub_00414310(szString);
}

// 0x0060E130
D2StormHashKeyStrIBStrc& D2StormHashKeyStrIBStrc::operator=(const D2StormHashKeyStrIBStrc& source)
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E9, 0);
    m_str = sub_00414310(source.m_str);
    return *this;
}


struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;
};

struct D2CommonStormHashNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2CommonStormSlotListAStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;
};

struct D2CommonStormSlotArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListAStrc* f_8;
    unsigned int f_C;
};

struct StringEntryNode;
class HASHKEY_STRI;
template <class T, class KEY> class TSHashTable;
template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>;
typedef TSHashTable<StringEntryNode, HASHKEY_STRI> D2CommonStormHashTableAStrc;
class ChatIgnoreList;
typedef ChatIgnoreList D2CommonChatIgnoreListStrc;
class IgnoreList;
typedef IgnoreList D2CommonIgnoreListStrc;

template <> class TSHashTable<StringEntryNode, HASHKEY_STRI>
{
public:
    virtual void sub_0060FFA0_InternalDelete(D2CommonStormHashNodeStrc* pNode);                             // 0x0060FFA0
    virtual void sub_0060FEF0_VirtSlot1();                                                                  // 0x0060FEF0
    virtual void sub_00610050_VirtSlot2();                                                                  // 0x00610050
    virtual void sub_00610020_VirtSlot3();                                                                  // 0x00610020
    D2CommonStormSlotListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayAStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0060E6E0_UnlinkNode(D2CommonStormHashNodeStrc* pNode);                                         // 0x0060E6E0
    D2CommonStormHashNodeStrc* sub_0060F8B0_Ptr(const char* szKey);                                         // 0x0060F8B0
};

class ChatIgnoreList
{
public:
    ChatIgnoreList(int nEmitTag);
    virtual int sub_00610EB0_Add(const char* szName) = 0;                                                   // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName) = 0;                                                // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName) = 0;                                              // 0x00610380
    virtual void sub_00610F90_VirtSlot3() = 0;                                                              // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;                                           // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5() = 0;                                                              // 0x0060FC40
    virtual void sub_00611320_VirtSlot6() = 0;                                                              // 0x00611320
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;                    // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled() = 0;                                                               // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;                                                 // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10() = 0;                                                             // 0x0060F500
    virtual ~ChatIgnoreList()
    {
    }
    static void operator delete(void* pMemory);
};

class IgnoreList : public D2CommonChatIgnoreListStrc
{
public:
    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2;
    char unk0x54[0x2C];
    char szFileName[0x104];
    int m_bEnabled;

    int sub_0060FB20_Remove(const char* szName);
    void sub_0060DE00_SetEnabled(int bEnabled);
    void sub_0060DFF0_NormalizeKey(const char* szName, char* szOut, int nSize);                             // 0x0060DFF0
    int sub_0060F0A0_Save();                                                                                // 0x0060F0A0
    int sub_0060FD50_Contains(const char* szKey);
};

D2CommonChatIgnoreListStrc::ChatIgnoreList(int nEmitTag)
{
}

// build: symbol ??_GChatIgnoreList@@UAEPAXI@Z 0x0060DD60
inline void D2CommonChatIgnoreListStrc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

// 0x0060DE00
void D2CommonIgnoreListStrc::sub_0060DE00_SetEnabled(int bEnabled)
{
    m_bEnabled = bEnabled;
    SRegSaveValue("Diablo II", "Persistent Ignore", 0, bEnabled);
}

// 0x0060FB20
int D2CommonIgnoreListStrc::sub_0060FB20_Remove(const char* szName)
{
    if (!szName || !*szName)
        return 0;
    if (!sub_0060DDF0_IsEnabled())
        return 0;
    char szKey[0x100] = "";
    sub_0060DFF0_NormalizeKey(szName, szKey, sizeof(szKey));
    if (!szKey[0])
        return 0;
    D2CommonStormHashNodeStrc* pNode = m_table.sub_0060F8B0_Ptr(szKey);
    if (!pNode)
        return 0;
    m_table.sub_0060E6E0_UnlinkNode(pNode);
    sub_0060F0A0_Save();
    return 1;
}

// 0x0060FD50
int D2CommonIgnoreListStrc::sub_0060FD50_Contains(const char* szKey)
{
    if (!szKey || !*szKey)
        return 0;
    if (!sub_0060DDF0_IsEnabled())
        return 0;
    return m_table.sub_0060F8B0_Ptr(szKey) != 0;
}
