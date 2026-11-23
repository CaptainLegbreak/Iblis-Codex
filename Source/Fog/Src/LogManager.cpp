#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#include "D2StormLink.h"

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC

extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);  // 0x006CC1C8

unsigned long gdwLastLogSweep;                                                                     // 0x0075E874

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2ExceptionPointersStrc;

struct D2LogMessageStrc;

struct D2StormLinkStrc;

struct sub_0040F530;

struct sub_0040F810;

struct D2ChatStormLinkStrc;

struct D2ChatStormLinkAStrc;

struct D2ChatStormLinkBStrc;

struct D2ChatStormNodeStrc;

struct D2ChatStormBaseArrayAStrc;

struct D2ChatStormBaseArrayBStrc;

struct D2ChatStormListAStrc;

struct D2ChatStormListBStrc;

struct D2ChatStormHashTableStrc;

struct D2ChatStormCtorLinkStrc;

struct D2ChatStormListCStrc;

struct D2ChatStormListDStrc;

struct D2ChatStormListEStrc;

struct D2CommonStormSlotLinkStrc;

struct D2CommonStormSlotListAStrc;

struct D2CommonStormSlotListBStrc;

struct D2CommonMappingEntryNodeBaseStrc;

struct D2CommonMappingEntryNodeStrc;

struct D2CommonStringEntryNodeStrc;

struct D2CommonStormHashTableAStrc;

struct sub_0040F7D0;

struct sub_00417810;

struct sub_00417860;

struct sub_004178C0;

struct sub_00417900;

struct sub_00417950;

struct sub_004179B0;

struct sub_004183F0;

struct sub_00418430;

struct sub_00418780;

struct sub_004187C0;

struct sub_00418800;

struct sub_00418840;

struct sub_00418880;

struct sub_004188C0;

struct sub_00418BA0;

struct sub_00418BE0;

struct sub_00418C20;

struct sub_00418E10;

struct sub_0041C3D0;

struct sub_0041C500;

struct sub_0041C730;

struct sub_0041C800;

struct sub_00420430;

struct sub_004204B0;

struct sub_00420710;

struct sub_004207E0;

struct sub_00426960;

struct sub_00426A80;

struct sub_00426CB0;

struct sub_00426D80;

struct sub_0044DDD0;

struct sub_0044DE90;

struct sub_0044ECC0;

struct sub_0044ED50;

struct sub_00601BF0;

struct sub_00601C70;

struct sub_00601D60;

struct sub_00601F20;

struct sub_00601F60;

struct sub_006020D0;

struct sub_00602140;

struct sub_006024A0;

struct sub_00602760;

struct sub_00417780;

struct sub_00417850;

struct sub_004178B0;

struct sub_00417940;

struct sub_00417990;

struct sub_00418760;

struct sub_00418770;

struct sub_00418A40;

struct sub_00418DE0;

struct sub_00418DF0;

struct sub_00418E00;

struct sub_00418E50;

struct sub_00418FF0;

struct sub_00419060;

struct sub_0041C4F0;

struct sub_0041C720;

struct sub_0041C7F0;

struct sub_004204A0;

struct sub_00420700;

struct sub_004207D0;

struct sub_00426CA0;

struct sub_00426D70;

struct sub_0044BDE0;

struct sub_0044ED40;

struct sub_0044ED90;

struct sub_00601F10;

struct sub_00602130;

struct sub_00602180;

struct sub_00602420;

struct sub_00602750;

struct D2SystemTimeStrc;

struct D2FileTimeStrc;

struct D2LogMsgLinkStrc;

struct D2LogMsgNodeStrc;

struct D2ExceptionPointersStrc
{
    void* pExceptionRecord;
    D2ThreadContextStrc* pContextRecord;
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" size_t __cdecl fread(void* pBuffer, size_t nSize, size_t nCount, _iobuf* pFile); // 0x00684782

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

void __cdecl ERRORMANAGER_SetMiniDumpThreadName(); // 0x00401A70

void __cdecl sub_004026D0_WriteMiniDump(); // 0x004026D0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall sShowStack(void* hThread, D2ThreadContextStrc* pContext); // 0x0040CC10

_iobuf* __fastcall sub_0040EBD0_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize); // 0x0040EBD0

void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize); // 0x0040F000

void __fastcall EXCEPTIONS_CloseNamedLog(const char* szName); // 0x0040F470

void __cdecl LOGMANAGER_LogMemoryDump(const char* szPrefix, const char* szTitle, unsigned long dwAddress, unsigned int nSize, int nArg5, int nArg6, int nArg7); // 0x00410040

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern int gbImageHlpLoaded; // 0x0075D014

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2LogMessageStrc
{
    union
    {
        struct
        {
            void* pLinkPrev;
            char* pLinkNext;
        };
        D2StormLinkStrc f_0;
    };
    unsigned int nSize;
    int nType;
    int bTimeStamp;
    D2SystemTimeStrc f_14;
    char szName[1];
};

extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int __fastcall FOG_CreatePathHierarchy(const char* szPath); // 0x00406A10

int __fastcall ERRORMANAGER_AppendBackslash(char* szPath, unsigned int nSize); // 0x00406B20

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern int gbLogInitialized; // 0x0075D2EC

extern int gnLogQueueCount; // 0x0075E870

extern D2CriticalSectionStrc gtLogQueueLock; // 0x0075E838

_iobuf* __fastcall sub_0040EDE0_GetLogFile(const char* szName, int* pnSlot); // 0x0040EDE0

struct sub_0040F530
{
    D2StormLinkStrc f_0;
    ~sub_0040F530();
};

struct sub_0040F810
{
    D2StormLinkStrc f_0;
    sub_0040F810();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2ChatStormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2ChatStormLinkStrc*)(m_next + nLinkOffset);
    }
    char* MaskNext()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
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
    bool IGNORELIST_IsLinkLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
};

struct D2ChatStormLinkAStrc
{
    D2ChatStormLinkAStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkAStrc();
};

struct D2ChatStormLinkBStrc
{
    D2ChatStormLinkBStrc* m_prevlink;
    char* m_next;

    D2ChatStormLinkBStrc();
};

struct D2ChatStormNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    char* IGNORELIST_GetStringEntryKey();
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayAStrc();
    unsigned int IGNORELIST_GetStringSlotArrayCount();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayBStrc();
    unsigned int IGNORELIST_GetMappingSlotArrayCount();
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitStringListTerminator();
    char* IGNORELIST_GetStringListHead();
    void IGNORELIST_ResetStringList();
};

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_InitMappingListTerminator();
    char* IGNORELIST_GetMappingListHead();
    void IGNORELIST_ResetMappingList();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* IGNORELIST_GetStringTableHead();
};

struct D2ChatStormCtorLinkStrc
{
    D2ChatStormCtorLinkStrc* m_prevlink;
    char* m_next;

    D2ChatStormCtorLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
};

struct D2ChatStormListCStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListCStrc();
};

struct D2ChatStormListDStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListDStrc();
};

struct D2ChatStormListEStrc
{
    int m_linkoffset;
    D2ChatStormCtorLinkStrc m_terminator;

    D2ChatStormListEStrc();
};

struct D2CommonStormSlotLinkStrc
{
    D2CommonStormSlotLinkStrc* m_prevlink;
    char* m_next;

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

    ~D2CommonStormSlotListAStrc();
    void UnlinkAll();
};

struct D2CommonStormSlotListBStrc
{
    int m_linkoffset;
    D2CommonStormSlotLinkStrc m_terminator;

    ~D2CommonStormSlotListBStrc();
    void UnlinkAll();
};

struct D2CommonMappingEntryNodeBaseStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonMappingEntryNodeBaseStrc();
};

struct D2CommonMappingEntryNodeStrc : D2CommonMappingEntryNodeBaseStrc
{
    void* pMapped;

    ~D2CommonMappingEntryNodeStrc();
};

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonStringEntryNodeStrc();
    void IGNORELIST_DestroyStringEntryNode();
};

struct D2CommonStormHashTableAStrc
{
    void IGNORELIST_InternalClearStringTable(int bWarn);
    void IGNORELIST_ClearStringTable();
};

struct sub_0040F7D0
{
    D2StormLinkStrc f_0;
    ~sub_0040F7D0();
};

struct sub_00417810
{
    D2StormLinkStrc f_0;
    ~sub_00417810();
};

struct sub_00417860
{
    D2StormLinkStrc f_0;
    ~sub_00417860();
};

struct sub_004178C0
{
    D2StormLinkStrc f_0;
    ~sub_004178C0();
};

struct sub_00417900
{
    D2StormLinkStrc f_0;
    ~sub_00417900();
};

struct sub_00417950
{
    D2StormLinkStrc f_0;
    ~sub_00417950();
};

struct sub_004179B0
{
    D2StormLinkStrc f_0;
    ~sub_004179B0();
};

struct sub_004183F0
{
    D2StormLinkStrc f_0;
    ~sub_004183F0();
};

struct sub_00418430
{
    D2StormLinkStrc f_0;
    ~sub_00418430();
};

struct sub_00418780
{
    D2StormLinkStrc f_0;
    ~sub_00418780();
};

struct sub_004187C0
{
    D2StormLinkStrc f_0;
    ~sub_004187C0();
};

struct sub_00418800
{
    D2StormLinkStrc f_0;
    ~sub_00418800();
};

struct sub_00418840
{
    D2StormLinkStrc f_0;
    ~sub_00418840();
};

struct sub_00418880
{
    D2StormLinkStrc f_0;
    ~sub_00418880();
};

struct sub_004188C0
{
    D2StormLinkStrc f_0;
    ~sub_004188C0();
};

struct sub_00418BA0
{
    D2StormLinkStrc f_0;
    ~sub_00418BA0();
};

struct sub_00418BE0
{
    D2StormLinkStrc f_0;
    ~sub_00418BE0();
};

struct sub_00418C20
{
    D2StormLinkStrc f_0;
    ~sub_00418C20();
};

struct sub_00418E10
{
    D2StormLinkStrc f_0;
    ~sub_00418E10();
};

struct sub_0041C3D0
{
    D2StormLinkStrc f_0;
    ~sub_0041C3D0();
};

struct sub_0041C500
{
    D2StormLinkStrc f_0;
    ~sub_0041C500();
};

struct sub_0041C730
{
    D2StormLinkStrc f_0;
    ~sub_0041C730();
};

struct sub_0041C800
{
    D2StormLinkStrc f_0;
    ~sub_0041C800();
};

struct sub_00420430
{
    D2StormLinkStrc f_0;
    ~sub_00420430();
};

struct sub_004204B0
{
    D2StormLinkStrc f_0;
    ~sub_004204B0();
};

struct sub_00420710
{
    D2StormLinkStrc f_0;
    ~sub_00420710();
};

struct sub_004207E0
{
    D2StormLinkStrc f_0;
    ~sub_004207E0();
};

struct sub_00426960
{
    D2StormLinkStrc f_0;
    ~sub_00426960();
};

struct sub_00426A80
{
    D2StormLinkStrc f_0;
    ~sub_00426A80();
};

struct sub_00426CB0
{
    D2StormLinkStrc f_0;
    ~sub_00426CB0();
};

struct sub_00426D80
{
    D2StormLinkStrc f_0;
    ~sub_00426D80();
};

struct sub_0044DDD0
{
    D2StormLinkStrc f_0;
    ~sub_0044DDD0();
};

struct sub_0044DE90
{
    D2StormLinkStrc f_0;
    ~sub_0044DE90();
};

struct sub_0044ECC0
{
    D2StormLinkStrc f_0;
    ~sub_0044ECC0();
};

struct sub_0044ED50
{
    D2StormLinkStrc f_0;
    ~sub_0044ED50();
};

struct sub_00601BF0
{
    D2StormLinkStrc f_0;
    ~sub_00601BF0();
};

struct sub_00601C70
{
    D2StormLinkStrc f_0;
    ~sub_00601C70();
};

struct sub_00601D60
{
    D2StormLinkStrc f_0;
    ~sub_00601D60();
};

struct sub_00601F20
{
    D2StormLinkStrc f_0;
    ~sub_00601F20();
};

struct sub_00601F60
{
    D2StormLinkStrc f_0;
    ~sub_00601F60();
};

struct sub_006020D0
{
    D2StormLinkStrc f_0;
    ~sub_006020D0();
};

struct sub_00602140
{
    D2StormLinkStrc f_0;
    ~sub_00602140();
};

struct sub_006024A0
{
    D2StormLinkStrc f_0;
    ~sub_006024A0();
};

struct sub_00602760
{
    D2StormLinkStrc f_0;
    ~sub_00602760();
};

struct sub_00417780
{
    D2StormLinkStrc f_0;
    sub_00417780();
};

struct sub_00417850
{
    D2StormLinkStrc f_0;
    sub_00417850();
};

struct sub_004178B0
{
    D2StormLinkStrc f_0;
    sub_004178B0();
};

struct sub_00417940
{
    D2StormLinkStrc f_0;
    sub_00417940();
};

struct sub_00417990
{
    D2StormLinkStrc f_0;
    sub_00417990();
};

struct sub_00418760
{
    D2StormLinkStrc f_0;
    sub_00418760();
};

struct sub_00418770
{
    D2StormLinkStrc f_0;
    sub_00418770();
};

struct sub_00418A40
{
    D2StormLinkStrc f_0;
    sub_00418A40();
};

struct sub_00418DE0
{
    D2StormLinkStrc f_0;
    sub_00418DE0();
};

struct sub_00418DF0
{
    D2StormLinkStrc f_0;
    sub_00418DF0();
};

struct sub_00418E00
{
    D2StormLinkStrc f_0;
    sub_00418E00();
};

struct sub_00418E50
{
    D2StormLinkStrc f_0;
    sub_00418E50();
};

struct sub_00418FF0
{
    D2StormLinkStrc f_0;
    sub_00418FF0();
};

struct sub_00419060
{
    D2StormLinkStrc f_0;
    sub_00419060();
};

struct sub_0041C4F0
{
    D2StormLinkStrc f_0;
    sub_0041C4F0();
};

struct sub_0041C720
{
    D2StormLinkStrc f_0;
    sub_0041C720();
};

struct sub_0041C7F0
{
    D2StormLinkStrc f_0;
    sub_0041C7F0();
};

struct sub_004204A0
{
    D2StormLinkStrc f_0;
    sub_004204A0();
};

struct sub_00420700
{
    D2StormLinkStrc f_0;
    sub_00420700();
};

struct sub_004207D0
{
    D2StormLinkStrc f_0;
    sub_004207D0();
};

struct sub_00426CA0
{
    D2StormLinkStrc f_0;
    sub_00426CA0();
};

struct sub_00426D70
{
    D2StormLinkStrc f_0;
    sub_00426D70();
};

struct sub_0044BDE0
{
    D2StormLinkStrc f_0;
    sub_0044BDE0();
};

struct sub_0044ED40
{
    D2StormLinkStrc f_0;
    sub_0044ED40();
};

struct sub_0044ED90
{
    D2StormLinkStrc f_0;
    sub_0044ED90();
};

struct sub_00601F10
{
    D2StormLinkStrc f_0;
    sub_00601F10();
};

struct sub_00602130
{
    D2StormLinkStrc f_0;
    sub_00602130();
};

struct sub_00602180
{
    D2StormLinkStrc f_0;
    sub_00602180();
};

struct sub_00602420
{
    D2StormLinkStrc f_0;
    sub_00602420();
};

struct sub_00602750
{
    D2StormLinkStrc f_0;
    sub_00602750();
};

struct D2LogMsgLinkStrc
{
    D2LogMsgLinkStrc* m_prevlink;
    char* m_next;

    D2LogMsgLinkStrc() { m_prevlink = 0; m_next = 0; }
    // 0x0040F820
    ~D2LogMsgLinkStrc() { Unlink(); }
    D2LogMsgLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2LogMsgLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2LogMsgLinkStrc*)(m_next + nLinkOffset);
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

struct D2LogMsgNodeStrc
{
    D2LogMsgLinkStrc f_0;

    D2LogMsgNodeStrc();
    ~D2LogMsgNodeStrc();
};

D2CriticalSectionStrc gtLogLock; // 0x0075E850

void* gpMiniDumpRequest; // 0x0098A6E4

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags); // 0x0040FF40
};

struct D2LogMemoryInfoStrc
{
    const void* pAddress;
    unsigned int nSize;
    int nArg5;
    int bBadPointer;
    int bArg7;
};

extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* pAddress, unsigned int nSize); // 0x006CC238

extern int gnLogQueuedBytes; // 0x0075D144

extern int gnLogQueued; // 0x0075D140

extern D2LogMsgListStrc gtLogMsgQueue_0075E868; // 0x0075E868

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0

void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

struct D2LogDumpStrc;

struct D2StormListStrc;


struct D2LogDumpStrc
{
    const unsigned char* pAddress;
    unsigned int nSize;
    int bShortAddress;
    int bIndirect;
    int bShowAscii;
    char szLabel[1];
};

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl strcmp(const char* szA, const char* szB);

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);


void __fastcall sub_0040ECC0_LogWriteHeader(_iobuf* pFile, const D2SystemTimeStrc* pTime); // 0x0040ECC0

void __fastcall sub_0040ED40_LogWriteStartup(_iobuf* pFile); // 0x0040ED40

extern int ganLogNewFile[20]; // 0x0075D298

extern char gaszLogFilePaths[20][0x104]; // 0x0075D340

extern unsigned long gadwLogOpenTick[20]; // 0x0075E7E0

extern "C" const char gszLogTimeStampFormat[]; // 0x006CE1DC

extern "C" const char gszLogBlankStamp[]; // 0x006CE1CC

extern "C" const char gszLogDumpAddress16[]; // 0x006CE1C0

extern "C" const char gszLogDumpAddress32[]; // 0x006CE1B4

extern "C" const char gszLogUnreadable[]; // 0x006CD880

extern "C" const char gszLogDumpByte[]; // 0x006CE1AC

extern "C" const char gszLogDumpByteSpaced[]; // 0x006CE1A4

extern "C" const char gszLogLineFormat_006CD90C[]; // 0x006CD90C

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

// 0x004027C0
unsigned long __stdcall LOGMANAGER_DbgHelpThreadProc(void* pParam)
{
    // stands for a stack local the original stores 0 to and reads back unused (no plain-C form found)
    volatile int nDummy = 0;
    nDummy;
    ERRORMANAGER_SetMiniDumpThreadName();
// build: symbol ?ghDbgHelpWorkEvent@* 0x0098A6C0
    WaitForSingleObject(ghDbgHelpWorkEvent, 0xFFFFFFFF);
    while (gpMiniDumpRequest)
    {
        sub_004026D0_WriteMiniDump();
// build: symbol ?ghDbgHelpDoneEvent@* 0x0098A6BC
        SetEvent(ghDbgHelpDoneEvent);
        WaitForSingleObject(ghDbgHelpWorkEvent, 0xFFFFFFFF);
    }
    return 0;
}

// 0x0040F000
void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize)
{
    char szPath[0x104];
    *szDirectory = 0;
    if (SHGetFolderPathA(0, 5, 0, 0, szPath) >= 0)
    {
        SStrCopy(szDirectory, szPath, nSize);
        ERRORMANAGER_AppendBackslash(szDirectory, nSize);
        SStrPack(szDirectory, "Diablo II\\GameLogs\\", nSize);
        FOG_CreatePathHierarchy(szDirectory);
    }
}

// 0x0040F3D0
void __fastcall LOGMANAGER_SweepLogFile(const D2FileTimeStrc* pNow, const char* szFile)
{
    int nOffset = SStrLen(szFile) - 10;
    if (nOffset > 0)
    {
        int nYear, nMonth, nDay;
        sscanf(szFile + nOffset, "%2d%2d%2d", &nYear, &nMonth, &nDay);
        D2SystemTimeStrc tTime;
        memset(&tTime, 0, sizeof(tTime));
        tTime.wYear = nYear > 90 ? nYear + 1900 : nYear + 2000;
        tTime.wMonth = nMonth;
        tTime.wDay = nDay;
        D2FileTimeStrc tFileTime;
        SystemTimeToFileTime(&tTime, &tFileTime);
        if (pNow->dwHighDateTime >= tFileTime.dwHighDateTime && pNow->dwHighDateTime - tFileTime.dwHighDateTime >= 0x4B7)
            DeleteFileA(szFile);
    }
}

// 0x0040F530
sub_0040F530::~sub_0040F530()
{
    f_0.Unlink();
}

// 0x0040F5A0
void __fastcall LOGMANAGER_SetLogPrefix(const char* szName)
{
    char szDirectory[0x104];
    LOGMANAGER_GetLogDirectory(szDirectory, 0x104);
// build: symbol ?gszLogPrefix@* 0x00708018
    SStrPrintf(gszLogPrefix, 0x104, "%s%s", szDirectory, szName);
}

// 0x0040F600
long __fastcall LOGMANAGER_MeasureLogFile(const char* szName)
{
    D2SystemTimeStrc tTime;
    EnterCriticalSection(&gtLogLock);
    EXCEPTIONS_CloseNamedLog(szName);
    long nSize = 0;
    _iobuf* pFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "r", 0, 0, 0);
    if (pFile)
    {
        fseek(pFile, 0, 2);
        nSize = ftell(pFile);
        fclose(pFile);
    }
    LeaveCriticalSection(&gtLogLock);
    return nSize;
}

// 0x0040F670
char* __fastcall LOGMANAGER_ReadLogRange(const char* szName, long nStart, long nEnd)
{
    D2SystemTimeStrc tTime;
    long nLength = nEnd - nStart;
    char* pBuffer = (char*)FOG_Alloc(nLength + 1, ".\\Src\\LogManager.cpp", 0x10A, 0);
    memset(pBuffer, 0, nLength + 1);
    EnterCriticalSection(&gtLogLock);
    EXCEPTIONS_CloseNamedLog(szName);
    _iobuf* pFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "r", 0, 0, 0);
    if (pFile)
    {
        if (!fseek(pFile, nStart, 0))
            fread(pBuffer, 1, nLength, pFile);
        fclose(pFile);
    }
    LeaveCriticalSection(&gtLogLock);
    return pBuffer;
}

// 0x0040F8A0
void __cdecl LOGMANAGER_CloseLogFilesNow()
{
    D2_ASSERT(gbLogInitialized, 456);
    const unsigned long dwStart = GetTickCount();
    while (GetTickCount() - dwStart < 1000)
    {
        EnterCriticalSection(&gtLogQueueLock);
        const int nQueued = gnLogQueueCount > 0 ? gnLogQueueCount : 0;
        LeaveCriticalSection(&gtLogQueueLock);
        if (!nQueued)
        {
            break;
        }
        Sleep(10);
    }
    for (int i = 0; i < 20; i++)
    {
        EnterCriticalSection(&gtLogLock);
// build: symbol ?gapLogFiles@* 0x0075E790
        if (gapLogFiles[i])
        {
            fclose(gapLogFiles[i]);
            gapLogFiles[i] = 0;
        }
        LeaveCriticalSection(&gtLogLock);
    }
}

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return f_4;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

// 0x0040F960
void __cdecl LOGMANAGER_CloseLogFiles()
{
    LOGMANAGER_CloseLogFilesNow();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

// 0x0040FAA0
D2LogMsgNodeStrc::~D2LogMsgNodeStrc()
{
    f_0.Unlink();
}

// 0x0040FCB0
D2LogMsgNodeStrc::D2LogMsgNodeStrc()
{
}

// 0x00410C40
void __stdcall LOGMANAGER_OrBits(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    const int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] | *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] | pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] | pB[i + 1];
    case 1:
        pOut[i] = pA[i] | pB[i];
    }
}

// 0x00417780
sub_00417780::sub_00417780()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417810
sub_00417810::~sub_00417810()
{
    f_0.Unlink();
}

// 0x00417850
sub_00417850::sub_00417850()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417860
sub_00417860::~sub_00417860()
{
    f_0.Unlink();
}

// 0x004178B0
sub_004178B0::sub_004178B0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004178C0
sub_004178C0::~sub_004178C0()
{
    f_0.Unlink();
}

// 0x00417900
sub_00417900::~sub_00417900()
{
    f_0.Unlink();
}

// 0x00417940
sub_00417940::sub_00417940()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00417950
sub_00417950::~sub_00417950()
{
    f_0.Unlink();
}

// 0x00417990
sub_00417990::sub_00417990()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004179B0
sub_004179B0::~sub_004179B0()
{
    f_0.Unlink();
}

// 0x004183F0
sub_004183F0::~sub_004183F0()
{
    f_0.Unlink();
}

// 0x00418430
sub_00418430::~sub_00418430()
{
    f_0.Unlink();
}

// 0x00418760
sub_00418760::sub_00418760()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418770
sub_00418770::sub_00418770()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418780
sub_00418780::~sub_00418780()
{
    f_0.Unlink();
}

// 0x004187C0
sub_004187C0::~sub_004187C0()
{
    f_0.Unlink();
}

// 0x00418800
sub_00418800::~sub_00418800()
{
    f_0.Unlink();
}

// 0x00418840
sub_00418840::~sub_00418840()
{
    f_0.Unlink();
}

// 0x00418880
sub_00418880::~sub_00418880()
{
    f_0.Unlink();
}

// 0x004188C0
sub_004188C0::~sub_004188C0()
{
    f_0.Unlink();
}

// 0x00418A40
sub_00418A40::sub_00418A40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418BA0
sub_00418BA0::~sub_00418BA0()
{
    f_0.Unlink();
}

// 0x00418BE0
sub_00418BE0::~sub_00418BE0()
{
    f_0.Unlink();
}

// 0x00418C20
sub_00418C20::~sub_00418C20()
{
    f_0.Unlink();
}

// 0x00418DE0
sub_00418DE0::sub_00418DE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418DF0
sub_00418DF0::sub_00418DF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418E00
sub_00418E00::sub_00418E00()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418E10
sub_00418E10::~sub_00418E10()
{
    f_0.Unlink();
}

// 0x00418E50
sub_00418E50::sub_00418E50()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00418FF0
sub_00418FF0::sub_00418FF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00419060
sub_00419060::sub_00419060()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C3D0
sub_0041C3D0::~sub_0041C3D0()
{
    f_0.Unlink();
}

// 0x0041C4F0
sub_0041C4F0::sub_0041C4F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C500
sub_0041C500::~sub_0041C500()
{
    f_0.Unlink();
}

// 0x0041C720
sub_0041C720::sub_0041C720()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C730
sub_0041C730::~sub_0041C730()
{
    f_0.Unlink();
}

// 0x0041C7F0
sub_0041C7F0::sub_0041C7F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0041C800
sub_0041C800::~sub_0041C800()
{
    f_0.Unlink();
}

// 0x00420430
sub_00420430::~sub_00420430()
{
    f_0.Unlink();
}

// 0x004204A0
sub_004204A0::sub_004204A0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004204B0
sub_004204B0::~sub_004204B0()
{
    f_0.Unlink();
}

// 0x00420700
sub_00420700::sub_00420700()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00420710
sub_00420710::~sub_00420710()
{
    f_0.Unlink();
}

// 0x004207D0
sub_004207D0::sub_004207D0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x004207E0
sub_004207E0::~sub_004207E0()
{
    f_0.Unlink();
}

// 0x00426960
sub_00426960::~sub_00426960()
{
    f_0.Unlink();
}

// 0x00426A80
sub_00426A80::~sub_00426A80()
{
    f_0.Unlink();
}

// 0x00426CA0
sub_00426CA0::sub_00426CA0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00426CB0
sub_00426CB0::~sub_00426CB0()
{
    f_0.Unlink();
}

// 0x00426D70
sub_00426D70::sub_00426D70()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x00426D80
sub_00426D80::~sub_00426D80()
{
    f_0.Unlink();
}

sub_0044BDE0::sub_0044BDE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0044DDD0::~sub_0044DDD0()
{
    f_0.Unlink();
}

sub_0044DE90::~sub_0044DE90()
{
    f_0.Unlink();
}

sub_0044ECC0::~sub_0044ECC0()
{
    f_0.Unlink();
}

sub_0044ED40::sub_0044ED40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0044ED50::~sub_0044ED50()
{
    f_0.Unlink();
}

sub_0044ED90::sub_0044ED90()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00601BF0::~sub_00601BF0()
{
    f_0.Unlink();
}

sub_00601C70::~sub_00601C70()
{
    f_0.Unlink();
}

sub_00601D60::~sub_00601D60()
{
    f_0.Unlink();
}

sub_00601F10::sub_00601F10()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00601F20::~sub_00601F20()
{
    f_0.Unlink();
}

sub_00601F60::~sub_00601F60()
{
    f_0.Unlink();
}

sub_006020D0::~sub_006020D0()
{
    f_0.Unlink();
}

sub_00602130::sub_00602130()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00602140::~sub_00602140()
{
    f_0.Unlink();
}

sub_00602180::sub_00602180()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00602420::sub_00602420()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_006024A0::~sub_006024A0()
{
    f_0.Unlink();
}

sub_00602750::sub_00602750()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00602760::~sub_00602760()
{
    f_0.Unlink();
}

// 0x00410040
void __cdecl LOGMANAGER_LogMemoryDump(const char* szPrefix, const char* szTitle, unsigned long dwAddress, unsigned int nSize, int nArg5, int bBadPointer, int nArg7)
{
// build: symbol ?gbLogThreadStop@* 0x0075E830
    if (gbLogThreadStop || !gbLogInitialized)
        return;
    if (!bBadPointer && IsBadReadPtr((const void*)dwAddress, nSize))
        bBadPointer = 1;
    unsigned int nExtraBytes = SStrLen(szPrefix) + 1 + sizeof(D2LogMemoryInfoStrc);
    nExtraBytes += SStrLen(szTitle) + 1;
    if (!bBadPointer)
        nExtraBytes += nSize;
    EnterCriticalSection(&gtLogQueueLock);
    D2LogMessageStrc* pMessage = (D2LogMessageStrc*)gtLogMsgQueue_0075E868.sub_0040FF40_NewNode(0, nExtraBytes, 0);
    LeaveCriticalSection(&gtLogQueueLock);
    pMessage->nSize = nExtraBytes + 0x24;
    pMessage->nType = 2;
    pMessage->bTimeStamp = 1;
    GetLocalTime(&pMessage->f_14);
    char* pText = pMessage->szName;
    pText += SStrCopy(pText, szPrefix, 0x7FFFFFFF) + 1;
    D2LogMemoryInfoStrc* pInfo = (D2LogMemoryInfoStrc*)pText;
    pInfo->pAddress = (const void*)dwAddress;
    pInfo->nSize = nSize;
    pInfo->nArg5 = nArg5;
    pInfo->bBadPointer = bBadPointer;
    pInfo->bArg7 = !nArg7;
    pText = (char*)(pInfo + 1);
    pText += SStrCopy(pText, szTitle, 0x7FFFFFFF) + 1;
    if (!bBadPointer)
        memcpy(pText, (const void*)dwAddress, nSize);
    EnterCriticalSection(&gtLogQueueLock);
    D2StormLinkStrc* pLink = &pMessage->f_0;
    if (pLink->m_prevlink)
    {
        pLink->NextLink(-1)->m_prevlink = pLink->m_prevlink;
        pLink->m_prevlink->m_next = pLink->m_next;
        pLink->m_prevlink = 0;
        pLink->m_next = 0;
    }
    D2StormLinkStrc* pPrev = gtLogMsgQueue_0075E868.m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = (char*)pMessage;
    gtLogMsgQueue_0075E868.m_terminator.m_prevlink = pLink;
    ++gnLogQueued;
    gnLogQueuedBytes += pMessage->nSize;
    LeaveCriticalSection(&gtLogQueueLock);
}

// 0x004106B0
void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 335);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 1, 0, szFormat, args);
}

// 0x0040F720
void __fastcall LOGMANAGER_WriteMessage(D2LogMessageStrc* pMessage)
{
    D2_ASSERT(pMessage->nType == 1, 0x2A1);
    char* szName = pMessage->szName;
    char* szText = szName + SStrLen(szName) + 1;
    int nSlot;
    _iobuf* pFile = sub_0040EDE0_GetLogFile(szName, &nSlot);
    if (pFile)
    {
        if (pMessage->bTimeStamp)
            fprintf(pFile, "%02d:%02d:%02d.%03d  ", pMessage->f_14.wHour, pMessage->f_14.wMinute, pMessage->f_14.wSecond, pMessage->f_14.wMilliseconds);
        fwrite(szText, SStrLen(szText), 1, pFile);
// build: symbol ?gadwLogWriteTick@* 0x0075D2F0
        gadwLogWriteTick[nSlot] = GetTickCount();
    }
}

// 0x0040F7C0
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

// 0x0040F7D0
sub_0040F7D0::~sub_0040F7D0()
{
    f_0.Unlink();
}

// 0x0040F810
sub_0040F810::sub_0040F810()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0040F860
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0040F970
void __cdecl LOGMANAGER_SweepOldLogFiles()
{
    if (gdwLastLogSweep && GetTickCount() - gdwLastLogSweep < 86400000)
    {
        return;
    }
    gdwLastLogSweep = GetTickCount();
    LeaveCriticalSection(&gtLogLock);
    LOGMANAGER_CloseLogFilesNow();
    EnterCriticalSection(&gtLogLock);
    D2SystemTimeStrc tNow;
    GetLocalTime(&tNow);
    D2FileTimeStrc ftNow;
    SystemTimeToFileTime(&tNow, &ftNow);
    char szDirectory[0x104];
    LOGMANAGER_GetLogDirectory(szDirectory, sizeof(szDirectory));
    char szPattern[0x104];
    SStrPrintf(szPattern, sizeof(szPattern), "%sd2*.txt", szDirectory);
    D2FindDataStrc tFind;
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        do
        {
            char szFile[0x104];
            SStrPrintf(szFile, sizeof(szFile), "%s%s", szDirectory, tFind.cFileName);
            LOGMANAGER_SweepLogFile(&ftNow, szFile);
        }
        while (FindNextFileA(hFind, &tFind));
        FindClose(hFind);
    }
}

// 0x0040F590
extern "C" void* __fastcall sub_0040F590(void* value) { return value; }

_iobuf* __fastcall sub_0040EDE0_GetLogFile(const char* szName, int* pnSlot)
{
    const unsigned long dwTick = GetTickCount();
    int nEmpty = -1;
    int nFree = -1;
    int nOldest;
    int nSlot = -1;
    _iobuf* pFile;

    int i = szName[0] != 0;
    nOldest = 1;
    for (; i < 20; ++i)
    {
// build: symbol ?gaszLogNames@* 0x0075D148
        if (!strcmp(gaszLogNames[i], szName))
        {
            nSlot = i;
// build: symbol ?gapLogFiles@* 0x0075E790
            pFile = gapLogFiles[i];
            if (pFile)
            {
                goto done;
            }
            break;
        }

        if (!gaszLogNames[i][0])
        {
            if (nEmpty < 0)
            {
                nEmpty = i;
            }
        }
        else if (!gapLogFiles[i])
        {
            if (nFree < 0)
            {
                nFree = i;
            }
// build: symbol ?gadwLogWriteTick@* 0x0075D2F0
            else if (dwTick - gadwLogWriteTick[i] > gadwLogWriteTick[nFree])
            {
                nFree = i;
            }
        }
        else if (dwTick - gadwLogWriteTick[i] > dwTick - gadwLogWriteTick[nOldest])
        {
            nOldest = i;
        }
    }

    if (nSlot < 0)
    {
        if (nEmpty >= 0)
        {
            nSlot = nEmpty;
        }
        else
        {
            if (nFree >= 0)
            {
                nOldest = nFree;
            }

            if (gapLogFiles[nOldest])
            {
                fclose(gapLogFiles[nOldest]);
                gapLogFiles[nOldest] = 0;
            }

            nSlot = nOldest;
        }
    }

    {
        D2_ASSERT(SStrLen(szName) < 16, 0x34C);
        strcpy(gaszLogNames[nSlot], szName);

        D2SystemTimeStrc tTime;
        int bNew;
        _iobuf* pNewFile = sub_0040EBD0_OpenDatedLogFile(szName, &tTime, "a", &bNew, gaszLogFilePaths[nSlot], 0x104);
        gapLogFiles[nSlot] = pNewFile;
        gadwLogOpenTick[nSlot] = dwTick;
        gadwLogWriteTick[nSlot] = dwTick;
        if (ganLogNewFile[nSlot] && pNewFile)
        {
            sub_0040ED40_LogWriteStartup(pNewFile);
            ganLogNewFile[nSlot] = 0;
        }
        else if (bNew)
        {
            sub_0040ECC0_LogWriteHeader(pNewFile, &tTime);
        }
    }

    pFile = gapLogFiles[nSlot];

done:
    if (pFile && pnSlot)
    {
        *pnSlot = nSlot;
    }

    return pFile;
}

// 0x0040F070
void __fastcall sub_0040F070_WriteDumpMessage(D2LogMessageStrc* pMessage)
{
    D2SystemTimeStrc* const pStamp = &pMessage->f_14;
    D2_ASSERT(pMessage->nType == 2, 0x389);
    char* szName = pMessage->szName;
    D2LogDumpStrc* pDump = (D2LogDumpStrc*)(szName + SStrLen(szName) + 1);
    const unsigned char* pData;
    char* const szLabel = pDump->szLabel;
    if (pDump->bIndirect)
    {
        pData = pDump->pAddress;
    }
    else
    {
        pData = (const unsigned char*)(szLabel + SStrLen(szLabel) + 1);
    }

    int nSlot;
    _iobuf* pFile = sub_0040EDE0_GetLogFile(szName, &nSlot);
    if (!pFile)
    {
        return;
    }

    char szTime[32];
    SStrPrintf(szTime, sizeof(szTime), gszLogTimeStampFormat, pStamp->wHour, pStamp->wMinute, pStamp->wSecond, pStamp->wMilliseconds);
    char szWhite[32];
    SStrCopy(szWhite, gszLogBlankStamp, sizeof(szWhite));

    const unsigned char* pCur = pData;
    unsigned int nRemain = pDump->nSize;
    int bFirst = 1;
    while (nRemain > 0)
    {
        const unsigned int nOffset = pCur - pData;
        fprintf(pFile, pDump->bShortAddress ? gszLogDumpAddress16 : gszLogDumpAddress32, bFirst ? szTime : szWhite, szLabel, pDump->bShortAddress ? nOffset : (unsigned int)pDump->pAddress + nOffset);
        bFirst = 0;
        unsigned int nLine = nRemain < 16 ? nRemain : 16;

        char szLine[0x100];
        szLine[0] = 0;
        if (IsBadReadPtr(pCur, nLine))
        {
            SStrCopy(szLine, gszLogUnreadable, 0x7FFFFFFF);
        }
        else
        {
            unsigned int i;
            for (i = 0; i < nLine; ++i)
            {
                const unsigned int nLen = strlen(szLine);
                SStrPrintf(&szLine[nLen], sizeof(szLine) - nLen, (i & 3) ? gszLogDumpByte : gszLogDumpByteSpaced, pCur[i]);
            }

            if (pDump->bShowAscii)
            {
                for (i = (16 - nLine) * 9 / 4 + 2; i; --i)
                {
// build: symbol ?gszSpace@* 0x006FFC44
                    SStrPack(szLine, gszSpace, sizeof(szLine));
                }

                const int nLen = strlen(szLine);
                int j = nLen;
                for (i = 0; i < nLine; ++i)
                {
                    unsigned char c = pCur[i];
                    szLine[j++] = (c & 0x7F) < 0x20 ? '.' : c;
                }
                szLine[nLen + i] = 0;
            }
        }

        fprintf(pFile, gszLogLineFormat_006CD90C, szLine);
        pCur += nLine;
        nRemain -= nLine;
    }
}

// 0x0040F520
char* __fastcall sub_0040F520_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0040F580
void __fastcall sub_0040F580_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0040F350
void __cdecl AUTOMAP_CloseStaleLogs()
{
    char szPath[0x104];
    int bLog = 0;
    szPath[0] = 0;
    unsigned long nNow = GetTickCount();
    for (int i = 0; i < 20; ++i)
    {
        if (gapLogFiles[i])
        {
            if (nNow - gadwLogOpenTick[i] > 15000 || nNow - gadwLogWriteTick[i] > 5000)
            {
                if (bLog)
                {
                    OutputDebugStringA(szPath);
                }
                fclose(gapLogFiles[i]);
                gapLogFiles[i] = 0;
            }
        }
    }
}

#include "gen/data/Source/Fog/Src/LogManager.inc"
