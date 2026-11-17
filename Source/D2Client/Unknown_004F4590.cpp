#include "D2Client.h"

struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned char unk_04[0x4A];
    unsigned char nState4E;
};

struct D2SkillsTxt
{
    unsigned char unk_000[0x102];
    short wDoSoundA;
    short wDoSoundB;
    unsigned char unk_106[0x136];
};

struct D2DataTablesStrc
{
    unsigned char unk_000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    unsigned char unk_B9C[0x04];
    int nSkillsTxtRecordCount;
};
void __fastcall sub_004B9A00(int nSound, D2UnitStrc* pUnit, int a3, int a4, int a5); // 0x004B9A00

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTable->nSkillsTxtRecordCount)
    {
        return &sgptDataTable->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004F4590
int __fastcall sub_004F4590_DoSkillSound(D2UnitStrc* pUnit, int nSkillId, int nUnused)
{
    if (pUnit->nState4E == 3)
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 0;
        }

        if ((!pUnit ? 6 : pUnit->dwUnitType) == 0 && pSkillsTxtRecord->wDoSoundA > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSoundA, pUnit, 0, 0, 0);
        }

        if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pSkillsTxtRecord->wDoSoundB > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSoundB, pUnit, 0, 0, 0);
        }
    }
    return 1;
}
