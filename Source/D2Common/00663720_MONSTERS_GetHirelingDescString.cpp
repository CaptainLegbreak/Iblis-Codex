typedef unsigned short Unicode;
struct D2UnitStrc;

struct D2HirelingTxt
{
    char unk0x00[0xC];
    int dwAct;
};

extern "C" const unsigned short gnHirelingDescStringIds[9];                                                       // 0x006EE410
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                                              // 0x00524A30
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromClassId(int bExpansion, int nClassId, D2HirelingTxt* pOldRecord);          // 0x00656440
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromNameId(int bExpansion, int nNameId, D2HirelingTxt* pOldRecord);            // 0x00656390
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                           // 0x00625480

// 0x00663720
const Unicode* __fastcall MONSTERS_GetHirelingDescString(int nId)
{
    if (nId >= 0 && nId < sizeof(gnHirelingDescStringIds) / sizeof(gnHirelingDescStringIds[0]) && gnHirelingDescStringIds[nId])
    {
        return D2LANG_GetStringFromTblIndex(gnHirelingDescStringIds[nId]);
    }

    return 0;
}

// 0x00663750
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, int nNameId)
{
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromClassId(bExpansion, nClassId, 0);
    if (pHirelingTxtRecord)
    {
        return pHirelingTxtRecord->dwAct - 1;
    }

    pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromNameId(bExpansion, nNameId, 0);
    if (pHirelingTxtRecord)
    {
        return pHirelingTxtRecord->dwAct - 1;
    }

    return 0;
}

// 0x00663790
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel)
{
    return nExpPerLevel * nLevel * nLevel * (nLevel + 1);
}

// 0x006637B0
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling)
{
    const int nLevel = STATLIST_UnitGetStatValue(pHireling, 12, 0);
    unsigned int nCost = 15 * (nLevel * nLevel / 2);
    if (nCost > 50000)
    {
        nCost = 50000;
    }

    return nCost;
}

#include "gen/data/Source/D2Common/00663720_MONSTERS_GetHirelingDescString.inc"
