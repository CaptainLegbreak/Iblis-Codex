struct D2HirelingTxt
{
    unsigned short wVersion;
    unsigned short pad0x02;
    int nId;
    int dwClass;
    char unk0x0C[0x118 - 0x0C];
};

extern D2HirelingTxt* gpHirelingTxt;                                                                        // 0x0096BDD0
extern int gnHirelingTxtRecordCount;                                                                        // 0x0096BDD4

// 0x00656440
D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromClassId(int bExpansion, int nClass, D2HirelingTxt* pOldRecord)
{
    D2HirelingTxt* pHirelingTxtRecord = 0;
    const unsigned short nVersion = bExpansion != 0 ? 100 : 0;
    int nRecordId = 0;

    if (pOldRecord)
    {
        nRecordId = pOldRecord - gpHirelingTxt + 1;
    }

    for (int i = nRecordId; i < gnHirelingTxtRecordCount; ++i)
    {
        if (gpHirelingTxt[i].dwClass == nClass && gpHirelingTxt[i].wVersion == nVersion)
        {
            pHirelingTxtRecord = &gpHirelingTxt[i];
            break;
        }
    }

    return pHirelingTxtRecord;
}
