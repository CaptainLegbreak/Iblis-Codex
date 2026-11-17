struct D2HirelingTxt
{
    unsigned short wVersion;
    unsigned short pad0x02;
    char unk0x04[0x0C - 0x04];
    int dwAct;
    int dwDifficulty;
    char unk0x14[0x1C - 0x14];
    int nHirelingLevel;
    char unk0x20[0x118 - 0x20];
};

extern D2HirelingTxt* gpHirelingTxt;                                                                        // 0x0096BDD0
extern int gnHirelingTxtRecordCount;                                                                        // 0x0096BDD4

// 0x00656580
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord)
{
    ++nAct;
    ++nDifficulty;

    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;
    int nLevel = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
        nLevel = pOldRecord->nHirelingLevel;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        pHirelingTxtRecord = &gpHirelingTxt[i];
        if (pHirelingTxtRecord->dwAct == nAct && pHirelingTxtRecord->dwDifficulty == nDifficulty && pHirelingTxtRecord->wVersion == nVersion && (!nLevel || pHirelingTxtRecord->nHirelingLevel == nLevel))
        {
            return pHirelingTxtRecord;
        }
    }

    return 0;
}
