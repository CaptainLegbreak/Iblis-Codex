#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"

struct HWND__;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct HUFFNODE;
struct CHuffman;
class TOutputStream;
class THuffmannTree;
struct D2CriticalSectionStrc;
struct D2SLogStrc;
struct D2Field14Strc;
struct D2UnitStrc;
struct D2StormByteArrayStrc;
struct D2StormFixedArrayAStrc;
struct D2StormFixedArrayBStrc;
struct D2StormFixedUIntArrayStrc;
struct D2StormFixedUCharArrayStrc;
struct D2StormGrowUIntArrayStrc;
struct D2StormGrowUCharArrayStrc;
struct D2StormArrayBStrc;
struct D2StormNodeListStrc
{
    int nLinkOffset;
    D2StormLinkStrc terminator;
    void __thiscall sub_0041EE40_UnlinkAll(); // 0x0041EE40
    inline void Clear()
    {
        sub_0041EE40_UnlinkAll();
        terminator.Unlink();
    }
};

struct HUFFNODE
{
    D2StormLinkStrc link;
    unsigned int nValue, nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;
};

struct CHuffman
{
    int unk_00[2];
    HUFFNODE items[515];
    D2StormNodeListStrc listA;
    D2StormNodeListStrc listB;
};

void __fastcall sub_0041EE90_DestroyItem(void* pItem); // 0x0041EE90
void __stdcall sub_00686AD1_DestroyArray(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pDestroy)(void*)); // 0x00686AD1

class TOutputStream
{
public:
    TOutputStream(void* pvOutBuffer, unsigned int cbOutLength);                                             // 0x0041D920

    unsigned char* pbOutBuffer;
    unsigned int cbOutSize;
    unsigned char* pbOutPos;
    unsigned int T00410B70;
    unsigned int BitCount;
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0
    ~THuffmannTree();                                                                                       // 0x0041F6A0
    unsigned int Compress(TOutputStream* os, void* pvInBuffer, int cbInBuffer, unsigned char nCmpType);    // 0x0041F850

    unsigned int adwData[0x3474 / 4];
};


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
extern D2CriticalSectionStrc gaSLogLocks_00779238[4]; // 0x00779238
extern D2SLogStrc* gapSLogBuckets_00779298[4]; // 0x00779298
extern int gbSLogDebugOutput_007790AC; // 0x007790AC

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void __stdcall AddWindow(int nValue); // 0x004208E0
int __stdcall DispatcherWindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x00420CF0
int __fastcall FindWindow(HWND__* hWnd); // 0x004209E0
int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormByteArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    char* m_data;
    unsigned int m_chunk;

    char* sub_00421010_Ptr();
};

struct D2StormFixedArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;

    unsigned int* sub_00421150_Ptr();
};

struct D2StormFixedArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;

    unsigned char* sub_004215B0_Ptr();
};

struct D2StormFixedUIntArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;

    ~D2StormFixedUIntArrayStrc();
};

struct D2StormFixedUCharArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;

    ~D2StormFixedUCharArrayStrc();
};

struct D2StormGrowUIntArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;

    ~D2StormGrowUIntArrayStrc();
};

struct D2StormGrowUCharArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    ~D2StormGrowUCharArrayStrc();
};

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned char* sub_00421930_New();
};

#include "D2StormBigBuffer.h"

// 0x0041F6A0
void __fastcall sub_0041F6A0_DestroyTree(CHuffman* pTree)
{
    pTree->listB.Clear();
    pTree->listA.Clear();
    sub_00686AD1_DestroyArray(pTree->items, sizeof(HUFFNODE), 515, sub_0041EE90_DestroyItem);
}

// 0x0041F980
void __fastcall HuffmanCompress(void* pvOutBuffer, int* pcbOutBuffer, void* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    TOutputStream os(pvOutBuffer, *pcbOutBuffer);
    THuffmannTree ht;
    *pcbOutBuffer = ht.Compress(&os, pvInBuffer, cbInBuffer, *pCmpType);
}

// 0x00420E70
int* __fastcall MONSTERMODE_GetTargetTimerPtr(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

static inline int MONSTERMODE_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = MONSTERMODE_IsActionFrame(pUnit) + 1;
}

// 0x00421010
char* D2StormByteArrayStrc::sub_00421010_Ptr()
{
    return m_data;
}

// 0x00421040
void __cdecl sub_00421040_Empty()
{
}

// 0x00421050
void __fastcall sub_00421050_Construct(unsigned char* pDest, const unsigned char* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x00421060
void __cdecl sub_00421060_Empty()
{
}

// 0x00421070
void __cdecl sub_00421070_Empty()
{
}

// 0x00421080
void __cdecl sub_00421080_Empty()
{
}

// 0x00421090
void __fastcall sub_00421090_Construct(char* pDest, const char* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x00421150
unsigned int* D2StormFixedArrayAStrc::sub_00421150_Ptr()
{
    return m_data;
}

// 0x004212A0
void __fastcall sub_004212A0_Construct(unsigned int* pDest, const unsigned int* pValue)
{
    if (pDest)
        *pDest = *pValue;
}

// 0x004212B0
void __cdecl sub_004212B0_Empty()
{
}

// build: symbol ?BigIsEven@* 0x00421440
static int BigIsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

// 0x00421570
D2StormFixedUIntArrayStrc::~D2StormFixedUIntArrayStrc()
{
    if (m_data)
        SMemFree(m_data, gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421590
D2StormFixedUCharArrayStrc::~D2StormFixedUCharArrayStrc()
{
    if (m_data)
        SMemFree(m_data, gszTypeNameUChar_00708880, -2, 0);
}

// 0x004215B0
unsigned char* D2StormFixedArrayBStrc::sub_004215B0_Ptr()
{
    return m_data;
}

// 0x004217F0
D2StormGrowUIntArrayStrc::~D2StormGrowUIntArrayStrc()
{
    if (m_data)
        SMemFree(m_data, gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421840
D2StormGrowUCharArrayStrc::~D2StormGrowUCharArrayStrc()
{
    if (m_data)
        SMemFree(m_data, gszTypeNameUChar_00708880, -2, 0);
}

// 0x00421930
unsigned char* D2StormArrayBStrc::sub_00421930_New()
{
    unsigned int nCount = m_count + 1;
    if (nCount > m_alloc)
    {
        unsigned int nChunk = m_chunk ? m_chunk : sub_00421160_CalcChunkSize(nCount);
        sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
    }
    return &m_data[m_count++];
}
