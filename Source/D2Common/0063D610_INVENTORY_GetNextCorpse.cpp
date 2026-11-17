struct D2CorpseStrc
{
    unsigned int unk0x00;
    unsigned int dwUnitId;
    unsigned int unk0x08;
    D2CorpseStrc* pNextCorpse;
};

// 0x0063D610
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse)
{
    if (!pCorpse)
    {
        return pCorpse;
    }

    return pCorpse->pNextCorpse;
}
