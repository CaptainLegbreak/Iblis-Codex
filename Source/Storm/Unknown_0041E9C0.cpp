#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#define DECODE_LENGTH sub_00420F80_DecodeLength
#define FROM_BINARY sub_00423380_FromBinary
#define FROM_LENGTH_PREFIXED sub_004234F0_FromLengthPrefixed

struct D2StormHuffItemStrc;
struct UiContext;
struct D2StormLinkStrc;
struct D2IdentityView;
struct D2StormNodeListStrc;
class THuffmannTree;
class D2StormHuffEncTreeStrc;
class D2StormHuffDecTreeStrc;
struct D2StormHuffInputStrc;
struct D2StormHuffTreeStrc;
struct D2StormHuffOutputStrc;
struct D2CriticalSectionStrc;
struct T0041FA40;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
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
struct D2TSLinkStrc;
struct D2TSListStrc;
struct D2StormNodeListBStrc;
struct D2StormWndRecStrc;
struct SMSGHANDLER_PARAMS;
struct Entry;
struct SlotArray;
struct D2Field14Strc;
struct D2UnitStrc;
struct D2StormArrayAStrc;
struct D2StormQueueStrc;
struct D2StormBigStackStrc;
struct D2StormBigBufferStrc;
struct LimbCell;
struct SequenceView;
struct StoredRecordView;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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
    D2StormLinkStrc();
    void sub_00420610();
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2IdentityView {
 D2StormLinkStrc link;
};

int __stdcall sub_0041E720_Worker(void* p1, unsigned int* p2, const void* p3, unsigned int n4, int n5); // 0x0041E720

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0041EE40_UnlinkAll();
    void sub_0041F460_Destroy();
};

class THuffmannTree
{
public:
    THuffmannTree();
    ~THuffmannTree();

    unsigned int adwData[0x3474 / 4];
};

class D2StormHuffEncTreeStrc : public THuffmannTree
{
public:
    D2StormHuffEncTreeStrc();
    ~D2StormHuffEncTreeStrc();
};

class D2StormHuffDecTreeStrc : public THuffmannTree
{
public:
    ~D2StormHuffDecTreeStrc();
};

struct D2StormHuffInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    unsigned int Get8Bits()
    {
        if (nBitCount <= 8)
        {
            nBitBuffer |= *(unsigned short*)pInput << nBitCount;
            nBitCount += 16;
            pInput += 2;
        }
        unsigned int nValue = nBitBuffer & 0xFF;
        nBitBuffer >>= 8;
        nBitCount -= 8;
        return nValue;
    }
};

struct D2StormHuffTreeStrc
{
    int bIsCmp0;
    int unk0x04;
    unsigned int unk0x08[0xC19];
    D2StormHuffItemStrc* pItemsByValue[0x102];
    void BuildTree(unsigned char nCmpType);                                                    // 0x0041EF20
    unsigned int sub_0041EBC0_DecodeOne(D2StormHuffInputStrc* pInput);                                      // 0x0041EBC0
    void AddSymbol(unsigned int nValue);                                                    // 0x0041F510
    void sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem);                                               // 0x0041F350
    unsigned int Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput); // 0x0041F740
    void sub_0041D9E0_EncodeOne(D2StormHuffOutputStrc* pOutput, unsigned int nValue);                       // 0x0041D9E0
    unsigned int Compress(D2StormHuffOutputStrc* pOutput, void* pvIn, int cbIn, unsigned char nCmpType); // 0x0041F850
};

struct D2StormHuffOutputStrc
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    unsigned int sub_0041D940_GetSize();                                                                    // 0x0041D940
    void sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits);                                     // 0x0041D950
    void sub_0041D9A0_Flush();                                                                              // 0x0041D9A0
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
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern D2CriticalSectionStrc gaSLogLocks_00779238[4]; // 0x00779238

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

extern unsigned short gwValue_0077905C;

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    D2TSLinkStrc* pNext;

    D2TSLinkStrc* NextLink(int nLinkOffset)
    {
        const int nNext = (int)pNext;
        if (nNext < 0)
        {
            return (D2TSLinkStrc*)~nNext;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        }
        return (D2TSLinkStrc*)(nNext + nLinkOffset);
    }

    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    D2TSLinkStrc* Head()
    {
        return (int)tTerminator.pNext > 0 ? tTerminator.pNext : 0;
    }

    void sub_00420750_UnlinkAll();
};

struct D2StormNodeListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    char* sub_00420970_DeleteNode(char* pNode);                                                            // 0x00420970
};

struct D2StormWndRecStrc
{
    D2StormLinkStrc f_0;
    void* hWnd;
};

char* __fastcall sub_004209E0_FindWndRec(void* hWnd); // 0x004209E0
int __stdcall SEvtUnregisterType(unsigned int nType, void* hWnd); // 0x00426810
int __stdcall SEvtDispatch(unsigned int nType, void* hWnd, unsigned int nId, SMSGHANDLER_PARAMS* pParams); // 0x00426F90
extern D2StormNodeListBStrc gWndRecList_00708860; // 0x00708860

struct Entry { unsigned char data[20]; };

enum { KEEP_EXISTING = 0 };

struct SlotArray {
    Entry slots[16];
    int count;
    Entry* sub_00420E10(Entry* existing,int mode);
};

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                            // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                   // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                      // 0x004216E0
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0

    unsigned int GetInline(unsigned int nIndex)
    {
        const unsigned int nPosition = m_start + nIndex;
        return nPosition < m_array.f_4 ? m_array.f_8[nPosition] : 0;
    }
    // build: context D2StormQueueStrc::SetCountInline
    void SetCountInline(unsigned int nCount)
    {
        if (nCount > m_array.f_4 && nCount > m_array.f_0)
        {
            unsigned int nChunk = m_array.f_C;
            if (!nChunk)
                nChunk = m_array.sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            m_array.sub_004216E0_ReallocData(nAlloc);
        }
        m_array.f_4 = nCount;
    }
    unsigned int ChunkSizeInline(unsigned int nCount)
    {
        if (nCount < 0x40)
        {
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_array.f_C = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nIndex)
    {
        const unsigned int nPosition = m_start + nIndex;
        if (nPosition >= m_array.f_4)
        {
            const unsigned int nNewCount = nPosition + 1;
            if (nNewCount > m_array.f_0)
            {
                const unsigned int nChunk = m_array.f_C ? m_array.f_C : ChunkSizeInline(nNewCount);
                unsigned int nAlloc = nNewCount;
                const unsigned int nRemainder = nNewCount % nChunk;
                if (nRemainder)
                    nAlloc = nNewCount + nChunk - nRemainder;
                m_array.sub_004216E0_ReallocData(nAlloc);
            }
            SMemZero(&m_array.f_8[m_array.f_4], (nPosition - m_array.f_4 + 1) * sizeof(unsigned int));
            m_array.f_4 = nNewCount;
        }
    }
    unsigned int& AtInline(unsigned int nIndex)
    {
        GrowToFitInline(nIndex);
        return m_array.f_8[m_start + nIndex];
    }
};

struct D2StormBigStackStrc
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;
};

struct D2StormBigBufferStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    void sub_00421FE0_GrowToFit(int nIndex);                                                                // 0x00421FE0
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    // build: context D2StormBigBufferStrc::InlineSetCount
    void InlineSetCount(unsigned int nCount)
    {
        if (nCount > f_4 && nCount > f_0)
        {
            unsigned int nChunk = f_C;
            if (!nChunk)
                nChunk = sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            sub_004216E0_ReallocData(nAlloc);
        }
        f_4 = nCount;
    }
    void InlineGrowToFit(int nIndex)
    {
        unsigned int nPosition = m_offset + nIndex;
        if (nPosition >= f_4)
        {
            unsigned int nNewCount = nPosition + 1;
            if (nNewCount > f_0)
            {
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nNewCount);
                sub_004216E0_ReallocData(RoundUp(nNewCount, nChunk));
            }
            SMemZero(&f_8[f_4], (nPosition - f_4 + 1) * sizeof(unsigned int));
            f_4 = nNewCount;
        }
    }
    unsigned int& Get(unsigned int nIndex)
    {
        sub_00421FE0_GrowToFit(nIndex);
        return f_8[m_offset + nIndex];
    }
    unsigned int& At(unsigned int nIndex)
    {
        InlineGrowToFit(nIndex);
        return f_8[m_offset + nIndex];
    }
};

typedef unsigned int U32;

struct LimbCell
{
    U32 value;
};

struct SequenceView
{
    char prefix[0x4];
    U32 count;
    LimbCell* values;
    char gap[0x4];
    U32 cursor;
};

struct StoredRecordView
{
    char prefix[0x10];
    int f_10;
};

typedef char check_pointer[sizeof(void*)==4?1:-1];

typedef char check_word[sizeof(U32)==4?1:-1];

typedef char check_cell[sizeof(LimbCell)==0x4?1:-1];

typedef char check_count[OFFSET(SequenceView,count)==0x4?1:-1];

typedef char check_values[OFFSET(SequenceView,values)==0x8?1:-1];

typedef char check_cursor[OFFSET(SequenceView,cursor)==0x10?1:-1];

typedef char check_mode[OFFSET(StoredRecordView,f_10)==0x10?1:-1];

extern "C" U32 gSlotFirst;
extern "C" U32 gSlotSecond;
extern "C" U32 gRangeMode;
extern "C" int gRangeValue;
extern "C" UiContext* gUiContext;
extern "C" int gRequest;
extern "C" int gState;

static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength);
static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, D2StormBigBufferStrc* pBuf);
static void __stdcall sub_004234F0_FromLengthPrefixed(D2StormBigBufferStrc* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData);

// 0x0041E9C0
D2StormLinkStrc* __fastcall sub_0041E9C0_Identity(D2IdentityView* value) {return &value->link;}

// 0x0041EA20
int __stdcall sub_0041EA20_Forward(void* p1, unsigned int* p2, const void* p3, unsigned int n4)
{
    return sub_0041E720_Worker(p1, p2, p3, n4, 0);
}

// build: symbol ??0THuffmannTree@@QAE@XZ 0x0041F4A0
// build: symbol ??1THuffmannTree@@QAE@XZ 0x0041F6A0
// 0x0041F460
void D2StormNodeListStrc::sub_0041F460_Destroy()
{
    sub_0041EE40_UnlinkAll();
    m_terminator.Unlink();
}

// 0x0041F920
D2StormHuffEncTreeStrc::D2StormHuffEncTreeStrc()
{
}

// 0x0041F930
D2StormHuffEncTreeStrc::~D2StormHuffEncTreeStrc()
{
}

// 0x0041F940
D2StormHuffDecTreeStrc::~D2StormHuffDecTreeStrc()
{
}

// 0x0041F740
unsigned int D2StormHuffTreeStrc::Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput)
{
    if (!nOutputSize)
    {
        return 0;
    }
    unsigned char nType = pInput->Get8Bits();
    BuildTree(nType);
    bIsCmp0 = nType == 0;
    unsigned char* pbOut = (unsigned char*)pOutput;
    for (;;)
    {
        unsigned int nValue = sub_0041EBC0_DecodeOne(pInput);
        if (nValue == 0x101)
        {
            nValue = pInput->Get8Bits();
            AddSymbol(nValue);
            if (!bIsCmp0)
            {
                sub_0041F350_IncWeights(pItemsByValue[nValue]);
            }
        }
        if (nValue == 0x100)
        {
            return (unsigned int)(pbOut - (unsigned char*)pOutput);
        }
        *pbOut++ = (unsigned char)nValue;
        if (--nOutputSize == 0)
        {
            return (unsigned int)(pbOut - (unsigned char*)pOutput);
        }
        if (bIsCmp0)
        {
            sub_0041F350_IncWeights(pItemsByValue[nValue]);
        }
    }
}

void D2StormHuffOutputStrc::sub_0041D9A0_Flush()
{
    while (nBitCount)
    {
        if (f_4)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            f_4--;
        }
        nBitBuffer >>= 8;
        nBitCount -= nBitCount > 8 ? 8 : nBitCount;
    }
}

// 0x0041F850
unsigned int D2StormHuffTreeStrc::Compress(D2StormHuffOutputStrc* pOutput, void* pvIn, int cbIn, unsigned char nCmpType)
{
    BuildTree(nCmpType);
    bIsCmp0 = nCmpType == 0;
    pOutput->sub_0041D950_PutBits(nCmpType, 8);
    unsigned char* pbIn = (unsigned char*)pvIn;
    while (cbIn != 0)
    {
        unsigned int nValue = *pbIn++;
        cbIn--;
        if (pItemsByValue[nValue] == 0)
        {
            sub_0041D9E0_EncodeOne(pOutput, 0x101);
            pOutput->sub_0041D950_PutBits(nValue, 8);
            AddSymbol(nValue);
            if (!bIsCmp0)
            {
                sub_0041F350_IncWeights(pItemsByValue[nValue]);
            }
        }
        else
        {
            sub_0041D9E0_EncodeOne(pOutput, nValue);
        }
        if (bIsCmp0)
        {
            sub_0041F350_IncWeights(pItemsByValue[nValue]);
        }
    }
    sub_0041D9E0_EncodeOne(pOutput, 0x100);
    pOutput->sub_0041D9A0_Flush();
    return pOutput->sub_0041D940_GetSize();
}

// 0x00426A70
D2StormLinkStrc::D2StormLinkStrc() : m_prevlink(0), m_next(0)
{
}

void __cdecl sub_00601B50_Empty()
{
}

// 0x004203C0
char* __fastcall sub_00601B60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00601C60_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00601CE0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

void __fastcall sub_00601E10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x004203D0
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

// 0x00420420
D2StormLinkStrc* __fastcall sub_00420420_Identity(D2IdentityView* value) {return &value->link;}

// 0x00420470
void __fastcall sub_00601DF0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x00420480
D2StormLinkStrc* __fastcall sub_00420480_Identity(D2IdentityView* value) {return &value->link;}

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
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

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

// 0x00420490
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
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

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
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

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x00420500
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00420610
void D2StormLinkStrc::sub_00420610()
{
    Unlink();
}

// 0x004206A0
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00420750
void D2TSListStrc::sub_00420750_UnlinkAll()
{
    D2TSLinkStrc* pNode;
    while ((pNode = Head()) != 0)
    {
        pNode->Unlink();
    }
}

void* gdwGlobal_007792F4; // 0x007792F4

// 0x00420A10
static __declspec(noinline) void DeleteWindow(void* hWnd)
{
    if (hWnd == gdwGlobal_007792F4)
    {
        gdwGlobal_007792F4 = 0;
    }
    char* pRec = sub_004209E0_FindWndRec(hWnd);
    if (pRec)
    {
        SEvtUnregisterType(0x534D5347, hWnd);
        SEvtUnregisterType(0x534D5348, hWnd);
        SEvtUnregisterType(0x534D534A, hWnd);
        SEvtUnregisterType(0x534D5349, hWnd);
        gWndRecList_00708860.sub_00420970_DeleteNode(pRec);
    }
}

// 0x00420B00
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult)
{
    if (pbUseResult)
    {
        *pbUseResult = 0;
    }
    if (plResult)
    {
        *plResult = 0;
    }
    SMSGHANDLER_PARAMS tParams;
    tParams.hWnd = hWnd;
    tParams.uMessage = uMsg;
    tParams.wParam = wParam;
    tParams.lParam = lParam;
    if (uMsg == 0x111)
    {
        tParams.dwCommandSource = wParam >> 0x10;
    }
    else
    {
        tParams.dwCommandSource = 0;
    }
    tParams.bReturn = 0;
    tParams.lResult = 0;
    void* hTarget = hWnd;
    for (;;)
    {
        SEvtDispatch(0x534D5347, hTarget, uMsg, &tParams);
        if (uMsg == 0x111)
        {
            SEvtDispatch(0x534D5348, hTarget, (unsigned short)wParam, &tParams);
        }
        else if (uMsg == 0x100)
        {
            SEvtDispatch(0x534D5349, hTarget, wParam, &tParams);
        }
        else if (uMsg == 0x101)
        {
            SEvtDispatch(0x534D534A, hTarget, wParam, &tParams);
        }
        if (!hTarget || hTarget != gdwGlobal_007792F4)
        {
            break;
        }
        hTarget = 0;
    }
    if (uMsg == 0x82)
    {
        DeleteWindow(hWnd);
    }
    if (pbUseResult)
    {
        *pbUseResult = tParams.bReturn;
    }
    if (plResult)
    {
        *plResult = tParams.lResult;
    }
    return 1;
}

// 0x00420AE0
static int sub_00420AE0_UnregisterAllWindows()
{
    while (D2StormWndRecStrc* pRec = (D2StormWndRecStrc*)gWndRecList_00708860.Head())
    {
        DeleteWindow(pRec->hWnd);
    }
    return 1;
}

int __stdcall sub_K01_Emit_00420AE0()
{
    return sub_00420AE0_UnregisterAllWindows();
}

// 0x00420E10
Entry* SlotArray::sub_00420E10(Entry* existing,int mode)
{
    if(mode != KEEP_EXISTING) return &slots[count++];
    return existing;
}

// 0x00420E40
D2StormLinkStrc* __fastcall sub_00420E40_Identity(D2IdentityView* value) {return &value->link;}

// 0x00420E50
extern "C" void* __fastcall sub_00420E50(void* value) { return value; }

// 0x00420E60
int* __fastcall sub_005A6250_GetField14(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

static inline int sub_005A64F0_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = sub_005A64F0_IsActionFrame(pUnit) + 1;
}

// 0x00420EB0
static unsigned int __stdcall sub_00420EB0_Accumulate64(unsigned __int64 nValue, unsigned __int64* pAccumulator)
{
    *pAccumulator += nValue;
    const unsigned __int64 nCarry = *pAccumulator < nValue ? 1ui64 : 0ui64;
    const unsigned int nLow = (unsigned int)*pAccumulator;
    *pAccumulator >>= 32;
    *pAccumulator += nCarry * 0x100000000ui64;
    return nLow;
}

void __stdcall sub_00424B00_BigSquare(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, D2StormBigStackStrc* pStack)
{
    D2StormQueueStrc* pWork;
    if (pResult == pA)
        pWork = &pStack->f_0[pStack->nUsed++];
    else
        pWork = pResult;

    pWork->SetCountInline(pWork->m_start);

    for (unsigned int i = 0; pA->m_start + i < pA->m_array.f_4; i++)
    {
        unsigned __int64 nCarry = 0;
        unsigned int j;
        for (j = 0; j <= i; j++)
        {
            const unsigned int nDigit = pA->GetInline(j);
            const unsigned __int64 nProduct = (unsigned __int64)pA->sub_004212D0_Get(i) * nDigit;
            const unsigned int k = j + i;
            const unsigned __int64 nSum = pWork->AtInline(k) + nProduct;
            if (j < i)
                nCarry += nProduct;
            unsigned int& rDigit = pWork->AtInline(k);
            rDigit = sub_00420EB0_Accumulate64(nSum, &nCarry);
        }
        pWork->AtInline(j + i) = (unsigned int)nCarry;
    }

    if (pResult != pWork)
    {
        pResult->m_array.sub_004215C0_Set(pWork->m_array.f_4, pWork->m_array.f_8);
        pResult->m_array.f_C = pWork->m_array.f_C;
        pResult->m_start = pWork->m_start;
        pStack->nUsed--;
    }
}

// 0x00420F30
static void __stdcall sub_00420F30_BigMulAddDigit(unsigned __int64* pAcc, unsigned int nDigit)
{
    *pAcc = *pAcc * 0x100000000ui64 + nDigit;
}

void __stdcall sub_K01_Emit_00420F30(unsigned __int64* pAcc, unsigned int nDigit)
{
    sub_00420F30_BigMulAddDigit(pAcc, nDigit);
}

// 0x00420F60
static unsigned __int64 __stdcall sub_00420F60_BigJoinDigits(unsigned int nHigh, unsigned int nLow)
{
    return (unsigned __int64)nHigh * 0x100000000ui64 + nLow;
}

unsigned __int64 __stdcall sub_K01_Emit_00420F60(unsigned int nHigh, unsigned int nLow)
{
    return sub_00420F60_BigJoinDigits(nHigh, nLow);
}

// 0x00420F80
static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength)
{
    *pnLength = 0;
    *pnOffset = 0;
    while (*pnOffset < nSize)
    {
        unsigned int nByte = pData[(*pnOffset)++];
        if (nByte == 0xFF)
            break;
        *pnLength = *pnLength * 0xFF + nByte;
    }
    *pnLength = *pnLength < nSize - *pnOffset ? *pnLength : nSize - *pnOffset;
}

static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, D2StormBigBufferStrc* pBuf)
{
    pBuf->InlineSetCount(pBuf->m_offset);
    for (unsigned int i = 0; i < nCount; i++)
    {
        unsigned int nByte = pData[i];
        unsigned int nWord = i >> 2;
        unsigned int nShift = i & 3;
        pBuf->At(nWord) = (nByte << (nShift * 8)) + (nShift ? pBuf->Get(nWord) : 0);
    }
}

// 0x004234F0
static void __stdcall sub_004234F0_FromLengthPrefixed(D2StormBigBufferStrc* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData)
{
    unsigned int nOffset;
    unsigned int nLength;
    DECODE_LENGTH(pData, nSize, &nOffset, &nLength);
    FROM_BINARY(pData + nOffset, nLength, pBuf);
    if (pnUsed)
        *pnUsed = nOffset + nLength;
}

// 0x00423850
void __stdcall sub_00423850(void* hBig, const void* pData, unsigned int nSize)
{
    FROM_BINARY((const unsigned char*)pData, nSize, (D2StormBigBufferStrc*)hBig);
}

// build: context SBigFromStream
void __stdcall SBigFromStream(void* hBig, const void* pData, unsigned int nSize, unsigned int* pnUsed)
{
    FROM_LENGTH_PREFIXED((D2StormBigBufferStrc*)hBig, pnUsed, nSize, (const unsigned char*)pData);
}

// 0x00420FE0
extern "C" LimbCell* __fastcall sub_00420FE0_LastCell(SequenceView* sequence)
{
    U32 count = sequence->count;
    if (count)
        return sequence->values + count - 1;
    return 0;
}

extern "C" void __fastcall sub_0044B210_StoreSlots(U32 first, U32 second); // 0x0044B210

extern "C" int __cdecl sub_004549C0_IsEnabled()
{
    return gUiContext != 0;
}

extern "C" int __fastcall sub_0047A0C0_GetRecordUnitId(StoredRecordView* object)
{
    if (object)
        return object->f_10;
    return -1;
}

extern "C" int __cdecl sub_00487CA0_SetStateIfDifferent()
{
    int value = 6;
    if (gState == value)
        return 0;
    gState = value;
    return 1;
}
