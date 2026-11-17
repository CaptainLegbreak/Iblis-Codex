struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};
struct D2UnitStrc
{
    int dwUnitType;
    unsigned char pad04[0x10];
    D2MonsterDataStrc* pMonsterData;
};
struct D2ItemsTxt
{
    unsigned char pad00[0x12F];
    unsigned char nLightRadius;
};
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860

// 0x0063EBD0
unsigned char __stdcall sub_0063EBD0_GetLightRadius(D2UnitStrc* pMonster)
{
    if (pMonster && (!pMonster ? 6 : pMonster->dwUnitType) == 1)
    {
        unsigned char nMaxLightRadius = 0;
        unsigned char* pComponents = pMonster && pMonster->dwUnitType == 1 && pMonster->pMonsterData ? pMonster->pMonsterData->nComponent : 0;
        if (!pComponents)
            return 0;
        for (int i = 0; i < 16; ++i)
        {
            unsigned int nCode = D2Common_11069(pMonster, i, pComponents[i]);
            if (nCode && nCode != ' til' && nCode != ' dem' && nCode != ' yvh')
            {
                int nItemId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(nCode, &nItemId);
                if (pItemsTxtRecord && pItemsTxtRecord->nLightRadius > nMaxLightRadius)
                    nMaxLightRadius = pItemsTxtRecord->nLightRadius;
            }
        }
        return nMaxLightRadius;
    }
    return 0;
}
