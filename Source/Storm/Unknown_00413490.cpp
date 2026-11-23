#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"

struct D2CriticalSectionStrc;
struct SMEMHEAPDETAILS;

enum D2SMemBlockFlags
{
    SMEM_BLOCK_SENTINEL = 0x01,
    SMEM_BLOCK_FREE = 0x02,
    SMEM_BLOCK_LARGE = 0x04,
    SMEM_BLOCK_INDIRECT = 0x08,
    SMEM_BLOCK_PREVFREE = 0x10,
    SMEM_BLOCK_NOREPORT = 0x40,
    SMEM_BLOCK_KEEP = 0x80,
};

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void __cdecl SMemInitialize(); // 0x00411CD0
void __cdecl sub_00411A20_InitPageSize(); // 0x00411A20
void __fastcall sub_00411A80_ReleaseBlock(D2SMemHeapStrc** ppLink); // 0x00411A80
void __cdecl AUTOMAP_ReleaseFreeBlocks(); // 0x00412000
extern "C" const char szSMemAlloc_006CEDCC[]; // 0x006CEDCC
extern int gbCallerFirst_00708340; // 0x00708340
extern unsigned int gnHeapId_00708344; // 0x00708344
extern unsigned int gdwCallerId_007768A8; // 0x007768A8
extern unsigned int gdwCallerWord_007768AC; // 0x007768AC
extern int gnCallerLine_007768B0; // 0x007768B0
extern const char* gszCallerFile_007768B4; // 0x007768B4
extern unsigned int gnPageSize_00776CB8; // 0x00776CB8
extern int gnFlag2_00776CBC; // 0x00776CBC
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0
extern int gnFlag1_007784C0; // 0x007784C0
extern int gnFlag0_007784C4; // 0x007784C4
extern int gabFreeBlockDirty[0x100]; // 0x007784C8
extern D2SMemHeapStrc* gpFreeBlockSweep_007788C8; // 0x007788C8
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8
extern int gnFlag3_007788CC; // 0x007788CC
extern int gbHeapInitialized_007788D0; // 0x007788D0
extern int gnFlag_00779098; // 0x00779098
static void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock);
static int sub_00411910_CheckPtr(void* pMemory, int bReport, const char* szFile, int nLine);

typedef void (__stdcall* SMEMDUMPCALLBACK)(void* pParam, const char* szText);

int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, SMEMHEAPDETAILS* pInfo); // 0x004124B0
extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, unsigned int nCount);

extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args); // 0x00682F22
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
extern "C" const unsigned int gdwSStrHashTable_006CEE30[16]; // 0x006CEE30
extern "C" const unsigned __int64 gqwSStrHash64Table_006CEE70[16]; // 0x006CEE70

void* __stdcall SMemHeapAlloc(unsigned int hHeap, unsigned int dwFlags, unsigned int nSize);



static __declspec(noreturn) void sub_00411620_FatalError(unsigned int nError, const char* szFile, int nLine)
{
    SErrDisplayError(nError, szFile, nLine, 0, 0, 1);
    ExitProcess(1);
}


// 0x004134D0
const char* __stdcall SStrChrR(const char* szString, char nChar)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const char* pLast = 0;
    for (const char* pString = szString; *pString; ++pString)
    {
        if (*pString == nChar)
            pLast = pString;
    }
    return nValid ? pLast : 0;
}





// 0x00413A00
static int sub_00413A00_VPrintf(char* szDest, size_t nSize, const char* szFormat, va_list args)
{
    if (nSize)
    {
        if (nSize != 0x7FFFFFFF)
        {
            size_t nResult = _vsnprintf(szDest, nSize, szFormat, args);
            if (nResult >= nSize)
            {
                nResult = nSize - 1;
                szDest[nResult] = 0;
            }
            return nResult;
        }
        return vsprintf(szDest, szFormat, args);
    }
    return 0;
}

// calling-convention shim (not game code)
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...)
{
    if (!szDest || !szFormat)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    return sub_00413A00_VPrintf(szDest, nMaxCount, szFormat, (va_list)(&szFormat + 1));
}

// calling-convention shim (not game code)
extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list args)
{
    if (!szDest || !szFormat)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }
    return sub_00413A00_VPrintf(szDest, nMaxCount, szFormat, args);
}


// 0x00413B30
int __stdcall sub_00413B30_ParseUnsignedDecimal(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    int nResult = *szString - '0';
    if ((unsigned int)nResult < 10)
    {
        unsigned int nDigit = *++szString - '0';
        while (nDigit < 10)
        {
            ++szString;
            nResult = nResult * 10 + nDigit;
            nDigit = *szString - '0';
        }
    }
    else
    {
        nResult = 0;
    }
    return nValid ? nResult : 0;
}


// 0x00413CE0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned int nResult = nSeed ? nSeed : 0x7FED7FED;
    unsigned int nAdjust = 0xEEEEEEEE;
    unsigned int nChar;
    if (nFlags & 1)
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            nResult = (gdwSStrHashTable_006CEE30[nChar >> 4] - gdwSStrHashTable_006CEE30[nChar & 0xF]) ^ (nResult + nAdjust);
            nAdjust = (nAdjust << 5) + nChar + nAdjust + nResult + 3;
        }
    }
    else
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            if (nChar >= 'a' && nChar <= 'z')
            {
                nChar -= 0x20;
            }
            if (nChar == '/')
            {
                nChar = '\\';
            }
            nResult = (gdwSStrHashTable_006CEE30[nChar >> 4] - gdwSStrHashTable_006CEE30[nChar & 0xF]) ^ (nResult + nAdjust);
            nAdjust = (nAdjust << 5) + nChar + nAdjust + nResult + 3;
        }
    }
    if (!nResult)
    {
        nResult = 1;
    }
    return nValid ? nResult : 0;
}



