#include "D2CMP.h"
#include "D2CmpCelFile.h"
#include "D2CmpTypes.h"
#include "D2CmpStormList.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelStrc;
struct D2StormEntry38Strc;
struct D2CmpCelContextStrc;
struct D2CelEntryStrc;
struct D2StormHashObjectStrc;
struct D2GameHashTableStrc;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormHashObjectStrc
{
    unsigned int f_0;
    D2StormSlotLinkStrc m_linktoslot;
    D2StormSlotLinkStrc f_C;
    int f_14;
};

struct D2StormEntry38Strc : D2StormHashObjectStrc
{
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;

    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2GameHashTableStrc
{
    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_00602800_InternalClear(int bWarn);                                                             // 0x00602800
};

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

// 0x00601810
int __stdcall sub_00601810_IsGfxFrameValid(D2CmpCelContextStrc* pContext)
{
    D2CelFileStrc* pCelFile = (D2CelFileStrc*)pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->dwVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    if (pContext->nFrame > pCelFile->nFrames)
    {
        return 0;
    }

    return 1;
}

// 0x00601840
D2CelStrc* __stdcall CelGetHandle(D2CmpCelContextStrc* pCelContext)
{
    D2_ASSERT(pCelContext, 0x566);
    D2_ASSERT(sub_00601810_IsGfxFrameValid(pCelContext), 0x567);

    D2CelFileStrc* pCelFile = (D2CelFileStrc*)pCelContext->pCelFile;
    const unsigned int nDirection = pCelContext->nDirection;
    const unsigned int nDirections = pCelFile->nDirectionCount;
    const int nIndex = gaDirectionIndex64_006E45A0[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    return pCelFile->pCels[nIndex * pCelFile->nFrames + pCelContext->nFrame];
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// build: symbol ??1D2StormHashObjectStrc@@QAE@XZ 0x00602430
// 0x00603060
D2StormSlotArrayStrc::~D2StormSlotArrayStrc() throw()
{
    for (unsigned int i = 0; i < f_4; ++i)
        f_8[i].~D2StormSlotListStrc();
    if (f_8)
        SMemFree(f_8, gszTypeNameCelSlotList, -2, 0);
}

// 0x00603140
D2StormEntryArrayStrc::~D2StormEntryArrayStrc()
{
    for (unsigned int i = 0; i < f_4; ++i)
        f_8[i].~D2StormEntry38Strc();
    if (f_8)
        SMemFree(f_8, gszTypeNameCelList, -2, 0);
}

// 0x00603780
void D2GameHashTableStrc::Destroy()
{
    sub_00602800_InternalClear(1);
    m_fullnessIndicator = 0;
    m_slotmask = 0;
    m_slotlistarray.Clear();
}
