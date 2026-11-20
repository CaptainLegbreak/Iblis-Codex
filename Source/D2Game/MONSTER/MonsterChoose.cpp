#include "D2Structs.h"
struct D2MonStats2Txt { char pad00[0x15]; unsigned char nComponentCount[16]; unsigned char nTotalPieces; };
struct D2MonPresetStrc { short nMonsterId; unsigned char nUnk02; unsigned char nCount; unsigned char nComponents[3][16]; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
static __forceinline unsigned int RollRandom(D2SeedStrc* pSeed)
{
 unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
 pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
 pSeed->nLowSeed = (unsigned int)nSeed;
 return (unsigned int)nSeed;
}
static __forceinline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
 if (nMax <= 0) return 0;
 if ((nMax - 1) & nMax) return RollRandom(pSeed) % nMax;
 return RollRandom(pSeed) & (nMax - 1);
}
// 0x005BDB20
void __stdcall sub_005BDB20_RollComponentVariants(D2SeedStrc* pSeed, D2MonPresetStrc* pPreset, int nCount)
{
 D2_ASSERT(pSeed, 0xa0);
 D2_ASSERT(pPreset, 0xa1);
 D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pPreset->nMonsterId);
 if (!pMonStats2Txt) return;
 const int nRemaining = (1 << pMonStats2Txt->nTotalPieces) - pPreset->nCount;
 if (nCount > nRemaining) nCount = nRemaining;
 if (nCount <= 0) return;
 if (pPreset->nCount + nCount > 3) nCount = 3 - pPreset->nCount;
 if (nCount <= 0) return;
 unsigned char* pComponentCount = pMonStats2Txt->nComponentCount;
 unsigned char* pNewComponents = pPreset->nComponents[pPreset->nCount];
 unsigned char* pBaseComponents = pPreset->nComponents[0];
 if (!pPreset->nCount)
 {
  for (int i=0; i<16; ++i)
  {
   if (pComponentCount[i] <= 1) pBaseComponents[i] = 0;
   else pBaseComponents[i] = (unsigned char)SEED_RollLimitedRandomNumber(pSeed, pComponentCount[i]);
  }
  ++pPreset->nCount;
  --nCount;
  pNewComponents += 16;
 }
 if (!nCount) return;
 unsigned char nIndices[16];
 int nParts = 0;
 for (unsigned char i = 0; i<16; ++i)
 {
  if (pComponentCount[i] > 1) nIndices[nParts++] = i;
 }
 unsigned char nFirst, nSecond;
 if (nParts == 1) nFirst = nSecond = nIndices[0];
 else if (nParts > 1)
 {
  int nIndex = SEED_RollLimitedRandomNumber(pSeed, nParts);
  nFirst = nIndices[nIndex];
  nIndices[nIndex] = nIndices[--nParts];
  nSecond = nIndices[SEED_RollLimitedRandomNumber(pSeed, nParts)];
 }
 else return;
 if (nCount > 0)
 {
 const int nFirstIndex = nFirst;
 int nLeft = nCount;
 do
 {
  memcpy(pNewComponents, pBaseComponents, 16);
  int nTries=3;
  int bDuplicate;
  do
  {
   pNewComponents[nFirstIndex] = (unsigned char)RollLimited(pSeed, pComponentCount[nFirstIndex]);
   if (nFirst != nSecond) pNewComponents[nSecond] = (unsigned char)RollLimited(pSeed, pComponentCount[nSecond]);
   bDuplicate=0;
   for (int j=0; j<pPreset->nCount; ++j)
   {
    if (!memcmp(pNewComponents, pPreset->nComponents[j], 16))
    {
     --nTries;
     bDuplicate=1;
    }
   }
  } while (bDuplicate && nTries);
  ++pPreset->nCount;
  pNewComponents += 16;
 } while (--nLeft);
 }
}
