struct D2GameStrc;
struct D2UnitStrc;

struct D2PetTypeTxt
{
    char unk0x00[0x0A];
    short wBaseMax;
    char unk0x0C[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBE8];
    D2PetTypeTxt* pPetTypeTxt;
    char unk0xBEC[0x04];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall sub_6FC7D150(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax);          // 0x00575850

// 0x00575A80
void __fastcall sub_00575A80_InitPetTypeMax(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    for (int nPetType = 0; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetTypeTxt* pPetTypeTxtRecord = 0;
        if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
        {
            pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
        }

        if (pPetTypeTxtRecord)
        {
            sub_6FC7D150(pGame, pPlayer, nPetType, pPetTypeTxtRecord->wBaseMax);
        }
    }
}
