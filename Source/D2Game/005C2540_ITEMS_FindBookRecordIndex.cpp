struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    int dwCode;
};

struct D2BooksTxt
{
    unsigned short wStr;
    unsigned char nSpellIcon;
    unsigned char pad0x03;
    unsigned int dwPSpell;
    int dwScrollSkillId;
    int dwBookSkillId;
    unsigned int dwBaseCost;
    unsigned int dwCostPerCharge;
    int dwScrollSpellCode;
    int dwBookSpellCode;
};

struct D2BookDataTbl
{
    int nBooksTxtRecordCount;
    D2BooksTxt* pBooksTxt;
};

D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables(); // 0x006374A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

// 0x005C2540
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll)
{
    D2BookDataTbl* pBookDataTbl = DATATBLS_GetBookDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pBookDataTbl)
    {
        return -1;
    }

    if (!pItemsTxtRecord)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    if (!pBookDataTbl->pBooksTxt)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    int nIndex = -1;
    for (int i = 0; i < pBookDataTbl->nBooksTxtRecordCount; ++i)
    {
        if (bScroll)
        {
            if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwScrollSpellCode)
            {
                nIndex = i;
                break;
            }
        }
        else if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwBookSpellCode)
        {
            nIndex = i;
            break;
        }
    }

    if (nIndex < 0)
    {
        nIndex = pBookDataTbl->nBooksTxtRecordCount;
    }
    return nIndex;
}
