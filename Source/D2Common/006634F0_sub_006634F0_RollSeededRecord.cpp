struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

struct D2Rolled6634F0Strc
{
    int nType;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    unsigned short wFlags;
};

struct D2Roll8Strc { int a; int b; };
struct D2Roll16Strc { int a; int b; int c; int d; };
struct D2Roll24Strc { int a; int b; int c; int d; int e; int f; };
struct D2Roll20Strc { int a; int b; int c; int d; int e; };
struct D2Roll28Strc { int a; int b; int c; int d; int e; int f; int g; };

extern const int gnRollBase1_007484CC[];                                                                    // 0x007484CC
extern const int gnRollCount1_007484DC[];                                                                   // 0x007484DC
extern const int gnRollBase2_007484F0[];                                                                    // 0x007484F0
extern const int gnRollCount2_00748500[];                                                                   // 0x00748500
extern const int gnRollBase3_00748514[];                                                                    // 0x00748514
extern const int gnRollCount3_00748524[];                                                                   // 0x00748524
extern const int gnRollBase4_00748538[];                                                                    // 0x00748538
extern const int gnRollCount4_00748548[];                                                                   // 0x00748548
extern const D2Roll8Strc gtRollStart_00748558[];                                                            // 0x00748558
extern const D2Roll16Strc gtRoll1_00748578[];                                                               // 0x00748578
extern const D2Roll16Strc gtRoll2_007485D8[];                                                               // 0x007485D8
extern const D2Roll24Strc gtRoll3_00748638[];                                                               // 0x00748638
extern const D2Roll20Strc gtRoll4_007486C8[];                                                               // 0x007486C8
extern const D2Roll28Strc gtRollLevel_007487B8[];                                                           // 0x007487B8

// 0x006634F0
int __fastcall sub_006634F0_RollSeededRecord(int nSeed, D2Rolled6634F0Strc* pOut, unsigned char nLevel)
{
    if (!nSeed)
        return 0;
    if (!pOut || nLevel > 2)
        return 0;

    const int nType = pOut->nType;
    if (nType < 0 || nType > 3)
        return 0;

    D2SeedStrc tSeed;
    pOut->wFlags = 0;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, nSeed);

    pOut->n34 = gtRollStart_00748558[nType].a;
    pOut->n20 = gtRollStart_00748558[nType].b;

    const int nRoll1 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount1_007484DC[nType]) + gnRollBase1_007484CC[nType];
    pOut->n04 = gtRoll1_00748578[nRoll1].a;
    pOut->n18 = gtRoll1_00748578[nRoll1].b;
    pOut->n20 += gtRoll1_00748578[nRoll1].d;
    pOut->n34 += gtRoll1_00748578[nRoll1].c;

    const int nRoll2 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount2_00748500[nType]) + gnRollBase2_007484F0[nType];
    pOut->n08 = gtRoll2_007485D8[nRoll2].a;
    pOut->n1C = gtRoll2_007485D8[nRoll2].b;
    pOut->n20 += gtRoll2_007485D8[nRoll2].d;
    pOut->n34 += gtRoll2_007485D8[nRoll2].c;

    const int nRoll3 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount3_00748524[nType]) + gnRollBase3_00748514[nType];
    if (nType < 3)
    {
        pOut->n0C = gtRoll3_00748638[nRoll3].a;
        pOut->n14 = 0;
    }
    else
    {
        pOut->n0C = 0;
        pOut->n14 = gtRoll3_00748638[nRoll3].a;
    }
    pOut->n24 = gtRoll3_00748638[nRoll3].c;
    pOut->n28 = gtRoll3_00748638[nRoll3].d;
    if (!gtRoll3_00748638[nRoll3].b)
        pOut->wFlags |= 1;
    pOut->n20 += gtRoll3_00748638[nRoll3].f;
    pOut->n34 += gtRoll3_00748638[nRoll3].e;

    const int nRoll4 = ITEMS_RollLimitedRandomNumber(&tSeed, gnRollCount4_00748548[nType]) + gnRollBase4_00748538[nType];
    pOut->n2C = gtRoll4_007486C8[nRoll4].a;
    pOut->n30 = gtRoll4_007486C8[nRoll4].d;
    if (pOut->n2C >= 9 && pOut->n2C <= 0xB)
        pOut->n10 = 1;
    else
        pOut->n10 = 0;
    pOut->n20 += gtRoll4_007486C8[nRoll4].c;
    pOut->n34 += gtRoll4_007486C8[nRoll4].b;

    if (nLevel)
    {
        pOut->n18 += gtRollLevel_007487B8[nLevel].a;
        pOut->n1C += gtRollLevel_007487B8[nLevel].b;
        pOut->n20 += gtRollLevel_007487B8[nLevel].c;
        pOut->n24 *= gtRollLevel_007487B8[nLevel].d;
        pOut->n28 *= gtRollLevel_007487B8[nLevel].e;
        pOut->n30 += gtRollLevel_007487B8[nLevel].f;
        pOut->n34 *= gtRollLevel_007487B8[nLevel].g;
    }
    return 1;
}

#include "gen/data/Source/D2Common/006634F0_sub_006634F0_RollSeededRecord.inc"
