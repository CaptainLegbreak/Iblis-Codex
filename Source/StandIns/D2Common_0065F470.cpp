// Functional replacement for the function at 0x0065F470, not the original code: only the ordinary build (tools/link.py) uses it.

struct D2UnitStrc;

struct D2PropertyStrc
{
    int nProperty;
    int nLayer;
    int nMin;
    int nMax;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
};

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
int __stdcall SKILLS_GetRequiredLevel(int nSkillId); // 0x00644710
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50

// 0x0065F470
int __fastcall ITEMMODS_PropertyFunc11(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        int nChance = pProperty->nMin;
        if (nChance <= 0)
        {
            nChance = 5;
        }

        nValue = pProperty->nMax;
        if (nValue == 0)
        {
            const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
            nValue = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / 4 + 1;
            nValue = D2_MIN(D2_MAX(nValue, 1), sub_004AA8B0_GetSkillMaxLevel(nSkillId));
        }
        else if (nValue < 0)
        {
            const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
            int nDivisor = 99 - nRequiredLevel;
            if (nDivisor < 1)
            {
                nDivisor = 1;
            }

            nDivisor = -(nDivisor / nValue);
            if (nDivisor < 1)
            {
                nDivisor = 1;
            }

            nValue = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / nDivisor;
            if (nValue <= 0)
            {
                nValue = 1;
            }
        }

        return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, (nSkillId << 6) + (nValue & 0x3F), nChance, nState);
    }

    return 0;
}
