#include "D2Unicode.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

struct D2CompositeUnitStrc;

struct D2CompositeUnitStrc;
struct D2CelFileStrc;

struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
};

extern D2LaunchCharEntryStrc* gpCharList_00779DBC;                                                          // 0x00779DBC
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0
extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0
D2CompositeUnitStrc* __stdcall sub_005066C0_CreateComposite(int nSel, int nMode, unsigned char* pFlags, unsigned char* pColors);
void __stdcall D2Win_10149(D2CompositeUnitStrc* pCompositeUnit, unsigned char nValue);                     // 0x005051A0
void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame);                               // 0x00505260
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                // 0x005042F0
void __cdecl sub_00438560_Refresh();

// 0x0043A460
extern "C" int __stdcall sub_0043A460_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), ".\\Src\\CharSel.cpp", 0xBAF, 0);
    sub_005263E0(pEntry->szName, pTitle, 0x100);
    sub_005267E0((unsigned short*)pEntry->wszName, (const unsigned short*)pText);
    memset(pEntry->aFlags, 0, sizeof(pEntry->aFlags));
    memset(pEntry->aColors, 0, sizeof(pEntry->aColors));
    pEntry->nType = nSel;
    pEntry->nWord322 = 0;
    pEntry->nWord324 = 0;
    pEntry->nWord326 = 0;
    pEntry->nWord328 = 0;
    pEntry->nByte32E = 0;
    pEntry->nByte32F = 0;
    pEntry->nByte330 = 0;
    pEntry->pCompositeUnit = 0;
    pEntry->pNext = 0;
    for (int i = 0; i < 16; ++i)
    {
        pEntry->aFlags[i] = 0;
        pEntry->aColors[i] = 0xFF;
    }
    pEntry->aFlags[1] = 1;
    pEntry->pCompositeUnit = sub_005066C0_CreateComposite(pEntry->nType, 5, pEntry->aFlags, pEntry->aColors);
    pEntry->nState = nState;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);
    if (!gpCharList_00779DBC)
    {
        gpCharList_00779DBC = pEntry;
    }
    else
    {
        D2LaunchCharEntryStrc* pLast = gpCharList_00779DBC;
        D2LaunchCharEntryStrc** ppNext = &gpCharList_00779DBC->pNext;
        while (pLast->pNext)
        {
            pLast = *ppNext;
            ppNext = &pLast->pNext;
        }
        pLast->pNext = pEntry;
    }
    ++gdwGlobal_00779DC4;
    sub_00438560_Refresh();
    return 1;
}
