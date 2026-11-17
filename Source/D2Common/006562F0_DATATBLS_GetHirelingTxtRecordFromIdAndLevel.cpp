struct D2HirelingTxt
{
    unsigned short wVersion;
    unsigned short pad0x02;
    int nId;
    char unk0x08[0x14];
    int nHirelingLevel;
    char unk0x20[0xF8];
};

extern D2HirelingTxt* gpHirelingTxt_0096BDD0;                                                               // 0x0096BDD0
int gnHirelingTxtRecordCount_0096BDD4;                                                                      // 0x0096BDD4
extern int gaHirelingIndex_0096BDD8[2][256];                                                                // 0x0096BDD8

// 0x006562F0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel)
{
    D2HirelingTxt* pResult = 0;
    if (nId >= 256)
    {
        return 0;
    }

    const unsigned short nVersion = bExpansion ? 100 : 0;
    const int nIndex = gaHirelingIndex_0096BDD8[bExpansion != 0][nId];
    if (nIndex < 0)
    {
        return 0;
    }

    for (int i = nIndex; i < gnHirelingTxtRecordCount_0096BDD4; ++i)
    {
        D2HirelingTxt* pRecord = &gpHirelingTxt_0096BDD0[i];
        if (pRecord->nId == nId && pRecord->wVersion == nVersion)
        {
            if (!pResult)
            {
                pResult = pRecord;
            }
            else if (pRecord->nHirelingLevel <= nLevel)
            {
                pResult = pRecord;
            }
            else
            {
                return pResult;
            }
        }
        else if (pRecord->nId > nId)
        {
            return pResult;
        }
    }

    return pResult;
}
