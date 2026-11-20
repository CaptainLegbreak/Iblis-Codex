#include "D2DataTbls.h"
struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc tSeed;
    int unk0x28[7];
    int nSeqCurrentFramePrecise;
};

struct D2MissilesTxt
{
    char unk0x000[0x181];
    unsigned char nSubStart;
    unsigned char nSubStop;
    char unk0x183[0x1A4 - 0x183];
};


typedef char cc_M439_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];
typedef char cc_M439_D2UnitStrc_frame[sizeof(D2UnitStrc) == 0x48 ? 1 : -1];

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
extern "C" int __stdcall sub_0064A380(D2UnitStrc* pMissile);                                             // 0x0064A380

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D3540
void __fastcall sub_004D3540_CltDoSubLoop(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nFrame = pMissile->nSeqCurrentFramePrecise >> 8;
    if (nFrame == pMissilesTxtRecord->nSubStart - 1)
    {
        pMissile->nSeqCurrentFramePrecise = (ITEMS_RollLimitedRandomNumber(&pMissile->tSeed, pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart) + nFrame) << 8;
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    if (sub_0064A380(pMissile) == pMissilesTxtRecord->nSubStart)
    {
        const int nNewFrame = pMissilesTxtRecord->nSubStart - 3;
        pMissile->nSeqCurrentFramePrecise = (nNewFrame < 0 ? 0 : nNewFrame) << 8;
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    if (sub_0064A380(pMissile) < pMissilesTxtRecord->nSubStart)
    {
        nFrame -= 2;
        pMissile->nSeqCurrentFramePrecise = (nFrame < 0 ? 0 : nFrame) << 8;
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
