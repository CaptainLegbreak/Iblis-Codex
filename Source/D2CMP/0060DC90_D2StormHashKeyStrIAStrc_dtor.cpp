struct _iobuf;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC

struct D2StormHashKeyStrIAStrc
{
    char* m_str;

    ~D2StormHashKeyStrIAStrc();
    char* sub_0060DCF0_GetString();
};

struct D2StormHashKeyStrIBStrc
{
    char* m_str;

    ~D2StormHashKeyStrIBStrc();
};

// build: symbol ??_7ChatIgnoreList@@6B@ 0x006E6248
// 0x0060DC90
D2StormHashKeyStrIAStrc::~D2StormHashKeyStrIAStrc()
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
}

// 0x0060DCF0
char* D2StormHashKeyStrIAStrc::sub_0060DCF0_GetString()
{
    return m_str;
}

// 0x0060DD90
D2StormHashKeyStrIBStrc::~D2StormHashKeyStrIBStrc()
{
    if (m_str)
        SMemFree(m_str, "d:\\diablo2\\Diablo2\\3rdparty\\storm\\h\\stpl.h", 0x5E4, 0);
}

class ChatIgnoreList;
typedef ChatIgnoreList D2CommonChatIgnoreListStrc;
class IgnoreList;
typedef IgnoreList D2CommonIgnoreListStrc;

class ChatIgnoreList
{
public:
    ChatIgnoreList();
    virtual int sub_00610EB0_Add(const char* szName) = 0;
    virtual int sub_0060FB20_Remove(const char* szName) = 0;
    virtual int sub_00610380_IsListed(const char* szName) = 0;
    virtual void sub_00610F90_VirtSlot3() = 0;
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;
    virtual void sub_0060FC40_VirtSlot5() = 0;
    virtual void sub_00611320_VirtSlot6() = 0;
    virtual void sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;
    virtual int sub_0060DDF0_IsEnabled() = 0;
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;
    virtual void sub_0060F500_VirtSlot10() = 0;
    virtual ~ChatIgnoreList();
    static void operator delete(void* pMemory);
};

// 0x0060DDD0
D2CommonChatIgnoreListStrc::ChatIgnoreList()
{
}

// 0x0060DD50
D2CommonChatIgnoreListStrc::~ChatIgnoreList()
{
}

class IgnoreList : public D2CommonChatIgnoreListStrc
{
public:
    char unk0x04[0x78];
    _iobuf* pFile;
    char szFileName[0x104];
    int m_bEnabled;

    int sub_0060DDF0_IsEnabled();
    void sub_0060DDE0_CloseFile();
};

// 0x0060DDE0
void D2CommonIgnoreListStrc::sub_0060DDE0_CloseFile()
{
    fclose(pFile);
}

// 0x0060DDF0
int D2CommonIgnoreListStrc::sub_0060DDF0_IsEnabled()
{
    return m_bEnabled;
}
