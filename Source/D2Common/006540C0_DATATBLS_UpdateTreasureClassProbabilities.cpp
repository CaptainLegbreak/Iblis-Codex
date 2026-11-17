struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    short nItemId;
    short nTxtRow;
    unsigned char nFlags;
    char unk0x0D;
    short nMagic;
    short nRare;
    short nSet;
    short nUnique;
    short nSuperior;
    short nNormal;
    char unk0x1A[2];
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    int nNoDrop;
    char unk0x18[2];
    short nQuality[6];
    char unk0x26[2];
    D2TCExInfoStrc* pInfo;
};

// 0x006540C0
void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion)
{
    int nIndex = pTCExInfo - pTCExShort->pInfo;
    int nCurrent;

    if (nIndex == pTCExShort->nTypes - 1)
    {
        nCurrent = pTCExShort->nProb - pTCExInfo->nProb;
    }
    else
    {
        nCurrent = pTCExShort->pInfo[nIndex + 1].nProb - pTCExInfo->nProb;
    }

    if (nCurrent != nProbability)
    {
        int nDiff = nProbability - nCurrent;
        pTCExShort->nProb += nDiff;
        for (int i = nIndex + 1; i < pTCExShort->nTypes; ++i)
        {
            pTCExShort->pInfo[i].nProb += nDiff;
        }
    }

    if (!bExpansion)
    {
        if (nIndex == pTCExShort->nTypes - 1)
        {
            nCurrent = pTCExShort->nClassic - pTCExInfo->nClassic;
        }
        else
        {
            nCurrent = pTCExShort->pInfo[nIndex + 1].nClassic - pTCExInfo->nClassic;
        }

        if (nCurrent != nProbability)
        {
            int nDiff = nProbability - nCurrent;
            pTCExShort->nClassic += nDiff;
            for (int i = nIndex + 1; i < pTCExShort->nTypes; ++i)
            {
                pTCExShort->pInfo[i].nClassic += nDiff;
            }
        }
    }
}
