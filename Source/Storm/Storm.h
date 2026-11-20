#include "D2Structs.h"
#pragma once

struct D2BitmapInfoStrc;
struct D2CelContextStrc;
struct D2CmpCelContextStrc;
struct D2Config006C8250Strc;
struct D2GfxBufferFuncsStrc;
struct D2ModuleEntry32Strc;
struct D2StormArchiveRecStrc;
struct D2SystemTimeStrc;
struct D2ThreadContextStrc;
struct D2TileDrawFunctionsStrc;
struct T004013C0;
struct _iobuf;
struct tagRECT;
struct z_stream;

T004013C0* __cdecl sub_00407360_GetSystemInfo(); // 0x00407360
__declspec(noreturn) void __cdecl sub_006B1A30_ThrowAtlException(long error); // 0x006B1A30
bool __fastcall sub_00404E60_EnumLoadedModules(void* pContext); // 0x00404E60
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile); // 0x006CC1C4
extern "C" __declspec(dllimport) int __stdcall FlushFileBuffers(void* hFile); // 0x006CC328
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall FreeResource(void* hResData); // 0x006CC2FC
extern "C" __declspec(dllimport) int __stdcall GetComputerNameA(char* szBuffer, unsigned long* pnSize); // 0x006CC1D8
extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234
extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238
extern "C" __declspec(dllimport) int __stdcall IsBadStringPtrA(const char* lpsz, unsigned int ucchMax); // 0x006CC2D0
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" __declspec(dllimport) int __stdcall UnmapViewOfFile(const void* pView); // 0x006CC2F8
extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194
extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz); // 0x006CC154
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long* pValue); // 0x006CC204
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long* pValue); // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread); // 0x006CC28C
extern "C" __declspec(dllimport) unsigned long __stdcall SizeofResource(void* hModule, void* hResInfo); // 0x006CC300
extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread); // 0x006CC288
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4
extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext); // 0x006CC290
extern "C" __declspec(dllimport) void* __stdcall CreateDIBSection(void* hDC, const D2BitmapInfoStrc* pbmi, unsigned int usage, void** ppvBits, void* hSection, unsigned int offset); // 0x006CC0CC
extern "C" __declspec(dllimport) void* __stdcall CreateFileMappingA(void* hFile, void* pAttributes, unsigned long nProtect, unsigned long nSizeHigh, unsigned long nSizeLow, const char* szName); // 0x006CC314
extern "C" __declspec(dllimport) void* __stdcall FindResourceA(void* hModule, const char* szName, const char* szType); // 0x006CC30C
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap(); // 0x006CC31C
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName); // 0x006CC294
extern "C" __declspec(dllimport) void* __stdcall LoadResource(void* hModule, void* hResInfo); // 0x006CC308
extern "C" __declspec(dllimport) void* __stdcall LockResource(void* hResData); // 0x006CC304
extern "C" __declspec(dllimport) void* __stdcall MapViewOfFile(void* hMapping, unsigned long nAccess, unsigned long nOffsetHigh, unsigned long nOffsetLow, unsigned long nBytes); // 0x006CC310
extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C
extern "C" char* __cdecl _fullpath(char* szAbsPath, const char* szRelPath, unsigned int nMaxLength); // 0x006867F7
extern "C" char* __cdecl strpbrk(const char* szString, const char* szCharSet); // 0x00686990
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" const char gszAdvapi32_006CCA1C[]; // 0x006CCA1C
extern "C" const char gszBackslash_006FF9B8[]; // 0x006FF9B8
extern "C" const char gszBlockTableKey_006CF1C8[]; // 0x006CF1C8
extern "C" const char gszCryptAcquireContextA_006CF174[]; // 0x006CF174
extern "C" const char gszCryptContainer_006CF0A8[]; // 0x006CF0A8
extern "C" const char gszCryptCreateHash_006CF164[]; // 0x006CF164
extern "C" const char gszCryptDestroyHash_006CF150[]; // 0x006CF150
extern "C" const char gszCryptDestroyKey_006CF140[]; // 0x006CF140
extern "C" const char gszCryptHashData_006CF130[]; // 0x006CF130
extern "C" const char gszCryptImportKey_006CF120[]; // 0x006CF120
extern "C" const char gszCryptProvider_006CF0B8[]; // 0x006CF0B8
extern "C" const char gszCryptReleaseContext_006CF10C[]; // 0x006CF10C
extern "C" const char gszCryptSignHashA_006CF0FC[]; // 0x006CF0FC
extern "C" const char gszCryptVerifySignatureA_006CF0E4[]; // 0x006CF0E4
extern "C" const char gszDelete_006CC824[]; // 0x006CC824
extern "C" const char gszDot_006CCAD8[]; // 0x006CCAD8
extern "C" const char gszDriveRoot_006CF09C[]; // 0x006CF09C
extern "C" const char gszHashTableKey_006CF1D8[]; // 0x006CF1D8
extern "C" const char gszKeyResourceType_006CF0A0[]; // 0x006CF0A0
extern "C" const char gszNew[]; // 0x006CC82C
extern "C" const char gszPathJoinFormat_006CE200[]; // 0x006CE200
extern "C" const char gszSEvtCpp[]; // 0x006D0224
extern "C" const char gszSLogNewline_006CFF08[]; // 0x006CFF08
extern "C" const char gszSignatureName_006CF18C[]; // 0x006CF18C
extern "C" const char gszSpace_006FFC44[]; // 0x006FFC44
extern "C" const char gszStormAudioStreamTypeName[]; // 0x00708408
extern "C" const char gszUncPrefix_006CF098[]; // 0x006CF098
extern "C" int __cdecl _snprintf_s(char* szBuffer, unsigned int nSizeOfBuffer, unsigned int nCount, const char* szFormat, ...); // 0x006824CB
extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl toupper(int nChar); // 0x00685385
extern "C" int __stdcall Module32FirstW(void* hSnapshot, D2ModuleEntry32Strc* pEntry); // 0x006B15AE
extern "C" int __stdcall Module32NextW(void* hSnapshot, D2ModuleEntry32Strc* pEntry); // 0x006B15B4
extern "C" int gnFlag_007788DC; // 0x007788DC
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
extern "C" void* __stdcall CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long dwProcessId); // 0x006B1446
extern D2Config006C8250Strc* gpConfig_007C9150; // 0x007C9150
extern D2GfxBufferFuncsStrc* gpBufferFuncs_007C914C; // 0x007C914C
extern D2StormArchiveRecStrc* gpArchiveHead_0070835C; // 0x0070835C
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C
extern bool gbSymInitialized_0098A6B0; // 0x0098A6B0
extern char gszTypeNameArchiveRec_00708398[]; // 0x00708398
extern char gszTypeNameChar_0070888C[]; // 0x0070888C
extern char gszTypeNameCmdDef_0074C47C[]; // 0x0074C47C
extern char gszTypeNameHandler_00708434[]; // 0x00708434
extern char gszTypeNameRequest_007083F0[]; // 0x007083F0
extern char gszTypeNameUChar_00708880[]; // 0x00708880
extern char gszTypeNameUInt_00708874[]; // 0x00708874
extern char gszTypeNameWndRec_00708850[]; // 0x00708850
extern char* gpEventHead_00708380; // 0x00708380
extern const char gszEmpty_006CC837[]; // 0x006CC837
extern const char gszSBmpSource[]; // 0x006FCC58
extern const char gszTypeBreakCmd_007088D8[]; // 0x007088D8
extern const char* const z_errmsg[10]; // 0x006D3848
extern const char* gaszCpuVendorNames_00708004[]; // 0x00708004
extern const int gaADPCMIndexTable_006CFCB8[]; // 0x006CFCB8
extern const int gaADPCMStepTable_006CFD38[]; // 0x006CFD38
extern const unsigned char gCharacterClass_0074C5C8[]; // 0x0074C5C8
extern const unsigned long crc_table[8][256]; // 0x006D17C8
extern const unsigned short gWideTable_006FCFC0[]; // 0x006FCFC0
extern const unsigned short gWideTable_006FD1C0[]; // 0x006FD1C0
extern const unsigned short gawTranslateTable_006FCFC0[]; // 0x006FCFC0
extern int gaSelectorValues_0074C5A0[]; // 0x0074C5A0
extern int gbAlignReads_007790A4; // 0x007790A4
extern int gbRenderPaused_007C9144; // 0x007C9144
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnBufferHeight_007C913C; // 0x007C913C
extern int gnBufferWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern int gnHeight_009702B8; // 0x009702B8
extern int gnModeWidth_0098A16C; // 0x0098A16C
extern int gnOriginX_0098A168; // 0x0098A168
extern int gnScreenWidth_0071146C; // 0x0071146C
extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnStride_007C9138; // 0x007C9138
extern int gnSurfaceHeight_007C913C; // 0x007C913C
extern int gnSurfaceWidth_007C9138; // 0x007C9138
extern int gnValueA_0070834C; // 0x0070834C
extern int gnValue_00708350; // 0x00708350
extern int gnValue_007C9140; // 0x007C9140
extern int gnValue_007C9154; // 0x007C9154
extern long gnErrorLockUsers_0070841C; // 0x0070841C
extern unsigned char gCriticalSection_0096D610[]; // 0x0096D610
extern unsigned char gnPlatform_0077905E; // 0x0077905E
extern unsigned char* gpBuffer_007C9154; // 0x007C9154
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern unsigned int gdwSStrScanWord_007788D8; // 0x007788D8
extern unsigned int gnReadRate_0077904C; // 0x0077904C
extern unsigned int gnReadUnit_00708348; // 0x00708348
extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
extern unsigned short gwLocale_0077905C; // 0x0077905C
extern void* ghDbgHelp_0098A680; // 0x0098A680
extern void* ghProcess_0074C6F0; // 0x0074C6F0
int __cdecl sub_0040E250_GetCpuVendor(); // 0x0040E250
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __fastcall deflate(z_stream* strm, int flush); // 0x00428C60
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath); // 0x00406A10
int __stdcall GetCmdIndex(const char* s); // 0x00405570
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
unsigned int __cdecl sub_0040E960_GetCpuSignature(); // 0x0040E960
unsigned int __cdecl sub_0040E980_GetCpuBrand(); // 0x0040E980
unsigned long __stdcall SFileSetFilePointer(void* hFile, long lDistanceToMove, long* plDistanceToMoveHigh, unsigned int dwMoveMethod); // 0x004165A0
void __cdecl sub_006C8930_Init(); // 0x006C8930
void __fastcall sub_006B20E0(const char*,long); // 0x006B20E0
void __fastcall sub_006C82D0_Apply(int nArg); // 0x006C82D0
void __stdcall SErrSetLastError(unsigned int); // 0x0041C340
void __stdcall sub_0041D300_ZeroMemory(void* pDest, unsigned int nSize); // 0x0041D300
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define DOLIT4 c ^= *buf4++; \
        c = crc_table[3][c & 0xff] ^ crc_table[2][(c >> 8) & 0xff] ^ \
            crc_table[1][(c >> 16) & 0xff] ^ crc_table[0][c >> 24]
#define DOLIT32 DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4
#define Z_NEED_DICT     2
#define ERR_MSG(err) z_errmsg[Z_NEED_DICT - (err)]
#define INVALID_FILE_HANDLE ((void*)-1)
#define MAX_WBITS       15
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEBEGIN int nValid = -1
#define VALIDATEENDVOID if (!nValid) { sub_0041C340_SetLastError(0x57); return; }
#define ZSWAP32(q) ((((q) >> 24) & 0xff) + (((q) >> 8) & 0xff00) + \
                    (((q) & 0xff00) << 8) + (((q) & 0xff) << 24))
#define Z_BLOCK         5
#define Z_BUF_ERROR     (-5)
#define Z_DATA_ERROR    (-3)
#define Z_DEFAULT_COMPRESSION (-1)
#define Z_DEFLATED      8
#define Z_FINISH        4
#define Z_FIXED         4
#define Z_MEM_ERROR     (-4)
#define Z_NULL          0
#define Z_OK            0
#define Z_STREAM_END    1
#define Z_STREAM_ERROR  (-2)
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define gwProcessorLevel_0074D8C0 (gtSystemInfo_0074D8A0.wProcessorLevel)
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

typedef char* va_list;

typedef unsigned char BOOLEAN;

struct D2AdpcmHeaderStrc
{
    unsigned char nZero;
    unsigned char f_1;
};

struct D2BitmapInfoStrc
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
    unsigned int bmiColors[256];
};

struct D2ChatStormBaseArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayAStrc();
    unsigned int sub_0060E230_Count();
};

struct D2ChatStormBaseArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;

    D2ChatStormBaseArrayBStrc();
    unsigned int sub_0060E250_Count();
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
    bool sub_0060E0C0_IsLinked();
    char* sub_0060E1A0_Next();
    char* sub_0060E240_Next();
    void sub_0060E3B0_Unlink();
    void sub_0060E400_Unlink();
    void sub_0060E690_Unlink();
    void sub_0060E760_Unlink();
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
    void sub_0060E260_InitializeTerminator();
    char* sub_0060E440_Head();
    void sub_0060E5F0_Reset();
};

struct D2ChatStormHashTableStrc
{
    void* m_pVTable;
    D2ChatStormListAStrc m_fulllist;

    char* sub_0060E6D0_Head();
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

struct D2ChatStormListBStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void sub_0060E270_InitializeTerminator();
    char* sub_0060E5D0_Head();
    void sub_0060E610_Reset();
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

struct D2ChatStormNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    char* sub_0060E0B0_GetKey();
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

struct D2CommonStormHashTableAStrc
{
    void sub_0060EB70_InternalClear(int bWarn);
    void sub_0060ED60_Clear();
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

struct D2CommonStringEntryNodeStrc
{
    unsigned int f_0;
    D2ChatStormLinkStrc m_linktoslot;
    D2ChatStormLinkStrc f_C;
    char* f_14;

    ~D2CommonStringEntryNodeStrc();
    void sub_0060EE30_Destroy();
};

struct D2Config006C8250Strc
{
    int n000;
    int n004;
    int n008;
    unsigned char unk_00C[0xF8];
    int n104;
    int n108;
    int n10C;
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

typedef int (__stdcall* D2CryptAcquireContextFn)(unsigned int*, const char*, const char*, unsigned int, unsigned int);

typedef int (__stdcall* D2CryptCreateHashFn)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int*);

typedef int (__stdcall* D2CryptDestroyFn)(unsigned int);

typedef int (__stdcall* D2CryptHashDataFn)(unsigned int, const unsigned char*, unsigned int, unsigned int);

typedef int (__stdcall* D2CryptImportKeyFn)(unsigned int, const void*, unsigned int, unsigned int, unsigned int, unsigned int*);

typedef int (__stdcall* D2CryptReleaseContextFn)(unsigned int, unsigned int);

typedef int (__stdcall* D2CryptSignHashFn)(unsigned int, unsigned int, const char*, unsigned int, unsigned char*, unsigned int*);

typedef int (__stdcall* D2CryptVerifySignatureFn)(unsigned int, const unsigned char*, unsigned int, unsigned int, const char*, unsigned int);

struct D2CvNb10Strc
{
    unsigned long dwCvSignature;
    unsigned long dwOffset;
    unsigned long dwSignature;
    unsigned long dwAge;
    char szPdbName[4];
};

struct D2DDSurfaceDescStrc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    int lPitch;
    unsigned int dwBackBufferCount;
    unsigned int dwRefreshRate;
    unsigned int dwAlphaBitDepth;
    unsigned int dwReserved;
    void* lpSurface;
    unsigned int unk0x28[21];
};

struct D2Field14Strc
{
    char unk0x00[0x14];
    int nField14;
};

struct D2FloatSaveStrc
{
    unsigned long ControlWord;
    unsigned long StatusWord;
    unsigned long TagWord;
    unsigned long ErrorOffset;
    unsigned long ErrorSelector;
    unsigned long DataOffset;
    unsigned long DataSelector;
    unsigned char RegisterArea[80];
    unsigned long Cr0NpxState;
};

struct D2GfxBufferFuncsStrc
{
    void (__fastcall* pfnSetBuffer)(void* pBits, int nWidth, int nHeight, int a4);
};

struct D2GfxPaletteViewStrc { unsigned int fields[72]; };

struct D2ImageDataDirStrc
{
    unsigned long VirtualAddress;
    unsigned long Size;
};

struct D2ImageDebugDirStrc
{
    unsigned long Characteristics;
    unsigned long TimeDateStamp;
    unsigned short MajorVersion;
    unsigned short MinorVersion;
    unsigned long Type;
    unsigned long SizeOfData;
    unsigned long AddressOfRawData;
    unsigned long PointerToRawData;
};

struct D2ImageDosHeaderStrc
{
    unsigned short e_magic;
    unsigned short e_unk02[25];
    unsigned short e_res2[4];
    long e_lfanew;
};

struct D2ImageFileHeaderStrc
{
    unsigned short Machine;
    unsigned short NumberOfSections;
    unsigned long TimeDateStamp;
    unsigned long PointerToSymbolTable;
    unsigned long NumberOfSymbols;
    unsigned short SizeOfOptionalHeader;
    unsigned short Characteristics;
};

struct D2ImageOptionalHeaderStrc
{
    unsigned short Magic;
    unsigned char unk0x02[0x36];
    unsigned long SizeOfImage;
    unsigned char unk0x3C[0x20];
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

struct D2ImageNtHeadersStrc
{
    unsigned long Signature;
    D2ImageFileHeaderStrc FileHeader;
    D2ImageOptionalHeaderStrc OptionalHeader;
};

struct D2ImageOptionalHeader64Strc
{
    unsigned short Magic;
    unsigned char unk0x02[0x6A];
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

struct D2PaletteEntry006C7C10Strc
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct D2LogPalette006C7C10Strc
{
    unsigned short palVersion;
    unsigned short palNumEntries;
    D2PaletteEntry006C7C10Strc palPalEntry[256];
};

struct D2ModuleStrc
{
    bool sub_00404AB0_VisitModule(void* pContext, const wchar_t* wszName, int nNameLength);                 // 0x00404AB0
};

struct D2ModuleEntry32Strc
{
    unsigned long dwSize;
    unsigned long th32ModuleID;
    unsigned long th32ProcessID;
    unsigned long GlblcntUsage;
    unsigned long ProccntUsage;
    D2ModuleStrc* modBaseAddr;
    unsigned long modBaseSize;
    void* hModule;
    wchar_t szModule[256];
    wchar_t szExePath[260];
};

struct D2PsapiModuleInfoStrc
{
    D2ModuleStrc* lpBaseOfDll;
    unsigned long SizeOfImage;
    void* EntryPoint;
};

struct D2SCompLinkStrc
{
    D2SCompLinkStrc* m_prevlink;
    char* m_next;

    D2SCompLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2SCompLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2SCompLinkStrc*)(m_next + nLinkOffset);
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

struct D2SMemHeapInfoStrc
{
    unsigned int dwSize;
    unsigned int hHeap;
    char szName[0x104];
    int nLine;
    unsigned int dwUnk110;
    unsigned int dwSizeA;
    unsigned int dwSizeB;
    unsigned int dwUnk11C;
    unsigned int nBlocks;
    unsigned int dwSizeC;
};

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

struct D2StormCryptFuncsStrc
{
    int (__stdcall* pfnAcquireContext)(unsigned int* phProv, const char* szContainer, const char* szProvider, unsigned int nProvType, unsigned int nFlags);
    int (__stdcall* pfnCreateHash)(unsigned int hProv, unsigned int nAlgId, unsigned int hKey, unsigned int nFlags, unsigned int* phHash);
    int (__stdcall* pfnDestroyHash)(unsigned int hHash);
    int (__stdcall* pfnDestroyKey)(unsigned int hKey);
    int (__stdcall* pfnHashData)(unsigned int hHash, const unsigned char* pData, unsigned int nSize, unsigned int nFlags);
    int (__stdcall* pfnImportKey)(unsigned int hProv, const void* pKey, unsigned int nSize, unsigned int hPubKey, unsigned int nFlags, unsigned int* phKey);
    int (__stdcall* pfnReleaseContext)(unsigned int hProv, unsigned int nFlags);
    int (__stdcall* pfnSignHash)(unsigned int hHash, unsigned int nKeySpec, const char* szDesc, unsigned int nFlags, unsigned char* pSig, unsigned int* pnSigLen);
    int (__stdcall* pfnVerifySignature)(unsigned int hHash, const unsigned char* pSig, unsigned int nSigLen, unsigned int hKey, const char* szDesc, unsigned int nFlags);

};

struct D2StormHuffLinkSlotStrc
{
    int nData[3];
};

struct D2StormMsgSourceStrc
{
    unsigned short wFacility;
    char unk0x02[2];
    void* hModule;
    D2StormMsgSourceStrc* pNext;
};

struct D2StormRequestCallbackStrc
{
    void (__stdcall* pfnDone)(unsigned int nSize, unsigned char* pEnd, D2StormRequestCallbackStrc* pCallback);
};

struct D2StormRequestLinkStrc
{
    D2StormRequestLinkStrc* m_prevlink;
    char* m_next;

    D2StormRequestLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormRequestLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormRequestLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormSignatureKeyStrc
{
    const char* szResourceName;
    unsigned int nResult;
};

struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};


typedef int (__stdcall* EnumProcessModulesFn)(void* hProcess, void** phModules, unsigned long nSize, unsigned long* pnNeeded);

typedef unsigned long (__stdcall* GetModuleBaseNameWFn)(void* hProcess, void* hModule, wchar_t* wszName, unsigned long nSize);

typedef int (__stdcall* GetModuleInformationFn)(void* hProcess, void* hModule, D2PsapiModuleInfoStrc* pInfo, unsigned long nSize);

typedef void (__stdcall* SEVTHANDLER)(void* pData);

typedef int (__stdcall* SymCleanupFn)(void* hProcess);

struct T0041FA40
{
    void* hLog;
    T0041FA40* pNext;
    void* hFile;
    unsigned long nUsed;
    unsigned long nPended;
    int nIndent;
    int f_18;
    char szBuffer[0x10000];
};

typedef void* (__fastcall* alloc_func)(void* opaque, unsigned int items, unsigned int size);

struct code
{
    unsigned char op;
    unsigned char bits;
    unsigned short val;
};

typedef void (__fastcall* free_func)(void* opaque, void* address);

typedef unsigned int size_t;

struct tagPOINT
{
    long x;
    long y;
};

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};
