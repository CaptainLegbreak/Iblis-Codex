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
    unsigned int BitBuffer;
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

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

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

// build: symbol ?BigIsEven@* 0x00421440
static int BigIsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

