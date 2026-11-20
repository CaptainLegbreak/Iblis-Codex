#include "D2Unicode.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma intrinsic(memset)

struct D2CompositeUnitStrc;

struct D2LaunchCharEntryStrc
{
    char szTitle[0x100];
    Unicode f_100[0x100];
    unsigned char aFlags[16];
    unsigned char aColors[16];
    unsigned char nSel;
    char unk0x321;
    short nWord322;
    short nWord324;
    short nWord326;
    short nWord328;
    char unk0x32A[4];
    char nByte32E;
    char nByte32F;
    char nByte330;
    char unk0x331[3];
    int bShared;
    D2CompositeUnitStrc* pCompositeUnit;
    char unk0x33C[0x10];
    D2LaunchCharEntryStrc* pNext;
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
    sub_005263E0(pEntry->szTitle, pTitle, 0x100);
    sub_005267E0((unsigned short*)pEntry->f_100, (const unsigned short*)pText);
    memset(pEntry->aFlags, 0, sizeof(pEntry->aFlags));
    memset(pEntry->aColors, 0, sizeof(pEntry->aColors));
    pEntry->nSel = nSel;
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
    pEntry->pCompositeUnit = sub_005066C0_CreateComposite(pEntry->nSel, 5, pEntry->aFlags, pEntry->aColors);
    pEntry->bShared = nState;
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
