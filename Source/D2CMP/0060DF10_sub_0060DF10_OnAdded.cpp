extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
struct _iobuf;
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                              // 0x0068239A
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
extern "C" char* __cdecl fgets(char* szBuffer, int nCount, _iobuf* pFile);                                  // 0x00688271

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
char* __stdcall sub_00414310(const char* szString);                                                             // 0x00414310

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2CommonStormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2CommonStormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2CommonStormSlotListStrc* f_8;
    unsigned int f_C;
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    char* f_14;
};

struct D2CommonMappingEntryNodeStrc
{
    unsigned int f_0;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
    char* f_14;
    char* pMapped;
};

struct D2CommonStormHashTableAStrc
{
    virtual void sub_0060FFA0_InternalDelete(D2CommonStringEntryNodeStrc* pNode);                           // 0x0060FFA0
    D2CommonStormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    D2CommonStringEntryNodeStrc* sub_0060F8B0_Ptr(const char* szKey);                                       // 0x0060F8B0
    D2CommonStringEntryNodeStrc* sub_00610D60_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags); // 0x00610D60
};

struct D2CommonStormHashTableBStrc
{
    virtual void sub_00610690_InternalDelete(D2CommonMappingEntryNodeStrc* pNode);                          // 0x00610690
    D2CommonStormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2CommonStormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    D2CommonMappingEntryNodeStrc* sub_0060F510_Ptr(const char* szKey);                                      // 0x0060F510
    D2CommonMappingEntryNodeStrc* sub_00611170_New(const char* szKey, unsigned int nExtraBytes, unsigned int nFlags); // 0x00611170
};

struct D2CommonChatIgnoreListStrc
{
    D2CommonChatIgnoreListStrc(int nEmitTag);
    virtual int sub_00610EB0_Add(const char* szName) = 0;                                                   // 0x00610EB0
    virtual int sub_0060FB20_Remove(const char* szName) = 0;                                                // 0x0060FB20
    virtual int sub_00610380_IsListed(const char* szName) = 0;                                              // 0x00610380
    virtual int sub_00610F90_AddAlias(const char* szName) = 0;                                              // 0x00610F90
    virtual int sub_0060FBE0_RemoveAlias(const char* szName) = 0;                                           // 0x0060FBE0
    virtual void sub_0060FC40_VirtSlot5() = 0;                                                              // 0x0060FC40
    virtual int sub_00611320_StoreAccountAlias(char* szRaw, int nRawLen) = 0;                               // 0x00611320
    virtual int sub_0060F870_Translate(const char* szName, char* szOut, int nSize) = 0;                     // 0x0060F870
    virtual int sub_0060DDF0_IsEnabled() = 0;                                                               // 0x0060DDF0
    virtual void sub_0060DE00_SetEnabled(int bEnabled) = 0;                                                 // 0x0060DE00
    virtual void sub_0060F500_VirtSlot10() = 0;                                                             // 0x0060F500
    virtual ~D2CommonChatIgnoreListStrc()
    {
    }
    static void operator delete(void* pMemory);
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
    D2CommonStormHashTableAStrc m_table;
    D2CommonStormHashTableAStrc m_table2;
    D2CommonStormHashTableBStrc m_table3;
    _iobuf* m_pFile;
    char szFileName[0x104];
    int m_bEnabled;

    int sub_00610F90_AddAlias(const char* szName);
    int sub_00611320_StoreAccountAlias(char* szRaw, int nRawLen);
    int sub_0060F870_Translate(const char* szName, char* szOut, int nSize);
    void sub_0060DE30_Normalize(const char* szName, char* szOut, int nSize);                                // 0x0060DE30
    void sub_0060DEA0_NormalizeAlias(const char* szName, char* szOut, int nSize);                           // 0x0060DEA0
    int sub_0060DF10_OnAdded(const char* szLine);
    int sub_0060DFF0_NormalizeKey(const char* szName, char* szOut, int nSize);
    void sub_00611050_Load();
};

// 0x0060DF10
int D2CommonIgnoreListStrc::sub_0060DF10_OnAdded(const char* szLine)
{
    if (!szLine || !*szLine || !sub_0060DDF0_IsEnabled())
    {
        return 0;
    }

    int bResult = 0;
    char szBuffer[0x100];
    SStrCopy(szBuffer, szLine, sizeof(szBuffer));
    sub_00413800(szBuffer, gszNewline_006FFCB0, sizeof(szBuffer));
    m_pFile = fopen(szFileName, "at+");
    if (m_pFile)
    {
        fwrite(szBuffer, SStrLen(szBuffer), 1, m_pFile);
        bResult = fclose(m_pFile) == 0;
    }
    return bResult;
}

// 0x0060DFF0
int D2CommonIgnoreListStrc::sub_0060DFF0_NormalizeKey(const char* szName, char* szOut, int nSize)
{
    D2_ASSERT(szOut, 416);

    *szOut = '\0';
    char szKey[0x100] = "";
    sub_0060DEA0_NormalizeAlias(szName, szKey, sizeof(szKey));
    if (!szKey[0])
    {
        sub_0060DE30_Normalize(szName, szKey, sizeof(szKey));
    }
    SStrCopy(szOut, szKey, nSize);
    return 0;
}

// 0x0060F870
int D2CommonIgnoreListStrc::sub_0060F870_Translate(const char* szName, char* szOut, int nSize)
{
    D2CommonMappingEntryNodeStrc* pNode = m_table3.sub_0060F510_Ptr(szName);
    if (pNode)
    {
        SStrCopy(szOut, pNode->pMapped, nSize);
        return 1;
    }
    return 0;
}

// 0x00610F90
int D2CommonIgnoreListStrc::sub_00610F90_AddAlias(const char* szName)
{
    if (!szName || !*szName || !sub_0060DDF0_IsEnabled() || !*szName)
    {
        return 0;
    }

    if (!m_table2.sub_0060F8B0_Ptr(szName))
    {
        m_table2.sub_00610D60_New(szName, 0, 0);
        char szLine[0x100] = "";
        szLine[0] = '!';
        sub_00413800(szLine, szName, sizeof(szLine));
        sub_0060DF10_OnAdded(szLine);
    }

    return 1;
}

// 0x00611050
void D2CommonIgnoreListStrc::sub_00611050_Load()
{
    _iobuf* pFile = fopen(szFileName, "rt");
    if (!pFile)
    {
        return;
    }

    char szLine[0x100] = "";
    while (fgets(szLine, sizeof(szLine), pFile))
    {
        for (unsigned int i = 0; i < SStrLen(szLine); ++i)
        {
            if (szLine[i] == '\r' || szLine[i] == '\n')
            {
                szLine[i] = '\0';
            }
        }

        if (szLine[0] == '!' && szLine[1])
        {
            m_table2.sub_00610D60_New(&szLine[1], 0, 0);
        }
        else
        {
            m_table.sub_00610D60_New(szLine, 0, 0);
        }
    }

    fclose(pFile);
}

// 0x00611320
int D2CommonIgnoreListStrc::sub_00611320_StoreAccountAlias(char* szRaw, int nRawLen)
{
    if (!szRaw || !*szRaw || !sub_0060DDF0_IsEnabled())
    {
        return 0;
    }

    char szAccount[0x100];
    char szName[0x100];
    SMemZero(szAccount, sizeof(szAccount));
    SMemZero(szName, sizeof(szName));

    unsigned int nStart = 0;
    for (unsigned int i = 0; szRaw[i] && i < nRawLen - 1; ++i)
    {
        if (szRaw[i + 1] == '(')
        {
            nStart = i + 1;
            SMemCopy(szName, szRaw, nStart);
        }

        if (szRaw[i + 1] == ')')
        {
            SMemCopy(szAccount, &szRaw[nStart + 1], i - nStart);
        }

        if (szName[0] && szAccount[0])
        {
            break;
        }
    }

    if (!szName[0] || !szAccount[0])
    {
        return 0;
    }

    D2CommonMappingEntryNodeStrc* pNode = m_table3.sub_0060F510_Ptr(szName);
    if (!pNode)
    {
        pNode = m_table3.sub_00611170_New(szName, 0, 0);
    }

    if (pNode->pMapped)
    {
        SMemFree(pNode->pMapped, ".\\Chat\\Ignorelist.cpp", 322, 0);
    }

    char szMapped[0x100] = "";
    szMapped[0] = '*';
    sub_00413800(szMapped, szAccount, sizeof(szMapped));
    pNode->pMapped = sub_00414310(szMapped);
    return 1;
}
