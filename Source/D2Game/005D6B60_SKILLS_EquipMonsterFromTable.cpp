struct D2GameStrc;
struct D2InventoryStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x38];
    D2InventoryStrc* pInventory;
};

struct D2MonEquipTxt
{
    short nMonster;
    short wLevel;
    unsigned char nOnInit;
    char unk0x05[3];
    unsigned int dwItem[3];
    char nLoc[3];
    char nMod[3];
    char unk0x1A[2];
};

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
    unsigned char unk0x05;
};

typedef char D2MonEquipTxt_size_check[sizeof(D2MonEquipTxt) == 0x1C ? 1 : -1];
typedef char D2UnitStrc_inventory_check[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

#define UNIT_MONSTER 1

D2MonEquipTxt* __fastcall sub_005D30A0_GetMonEquipTxtRecord(int nMonsterId);
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
void __fastcall sub_6FC61190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterItemCodeStrc* pItemCode, int nItemLevel, int nMod); // 0x00573B20
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

// 0x005D6B60
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel, int bCheckOnInit)
{
    const int nType = pPet ? pPet->dwUnitType : 6;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    const int nClassId = pPet->dwClassId;
    D2MonEquipTxt* pRecord = sub_005D30A0_GetMonEquipTxtRecord(nClassId);
    if (!pRecord)
    {
        return;
    }

    if (bCheckOnInit && !pRecord->nOnInit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pPet->pInventory;
    if (!pInventory)
    {
        return;
    }

    while (pRecord->nMonster == nClassId && pRecord->wLevel > nSkillLevel)
    {
        ++pRecord;
    }

    for (; pRecord->nMonster == nClassId; ++pRecord)
    {
        int nMax = 0;
        while (nMax < 3 && pRecord->nLoc[nMax] > 0 && pRecord->nLoc[nMax] < 11)
        {
            ++nMax;
        }

        if (nMax <= 0)
        {
            continue;
        }

        unsigned int nIndex;
        if ((nMax - 1) & nMax)
        {
            const unsigned __int64 lSeed = pPet->pSeed.nHighSeed + 0x6AC690C5i64 * pPet->pSeed.nLowSeed;
            pPet->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pPet->pSeed.nLowSeed = (unsigned int)lSeed;
            nIndex = (unsigned int)lSeed % nMax;
        }
        else
        {
            const unsigned __int64 lSeed = pPet->pSeed.nHighSeed + 0x6AC690C5i64 * pPet->pSeed.nLowSeed;
            pPet->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pPet->pSeed.nLowSeed = (unsigned int)lSeed;
            nIndex = (unsigned int)lSeed & (nMax - 1);
        }

        const int nBodyLoc = pRecord->nLoc[nIndex];
        if (INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc))
        {
            continue;
        }

        int nMod = pRecord->nMod[nIndex];
        if (nMod < 0 || nMod >= 8)
        {
            nMod = 0;
        }

        unsigned int nItemCode = pRecord->dwItem[nIndex];
        if (nItemCode == 0x20202020 && pUnit)
        {
            if (!pUnit->pInventory)
            {
                continue;
            }

            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
            if (!pItem)
            {
                continue;
            }

            nItemCode = ITEMS_GetBaseCode(pItem);
        }

        D2MonsterItemCodeStrc tItemCode;
        tItemCode.nItemCode = nItemCode;
        tItemCode.nBodyLoc = nBodyLoc;
        tItemCode.unk0x05 = 1;
        sub_6FC61190(pGame, pPet, &tItemCode, nItemLevel, nMod);
    }
}
