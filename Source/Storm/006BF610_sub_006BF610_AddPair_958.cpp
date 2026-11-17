struct D2PairEntry006BF610Strc
{
    int nKey;
    int nValue;
};
struct D2PairTable006BF610Strc
{
    unsigned char unk_000[0x48];
    D2PairEntry006BF610Strc pEntries[256];
    int nCount;
};

// 0x006BF610
void __fastcall sub_006BF610_AddPair(D2PairTable006BF610Strc* pTable, int nValue, int nKey)
{
    if (pTable->nCount < 256)
    {
        for (int i = 0; i < pTable->nCount; ++i)
        {
            if (pTable->pEntries[i].nKey == nKey)
            {
                return;
            }
        }
        pTable->pEntries[pTable->nCount].nKey = nKey;
        pTable->pEntries[pTable->nCount].nValue = nValue;
        ++pTable->nCount;
    }
}
