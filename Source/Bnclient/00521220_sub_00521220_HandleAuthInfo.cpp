struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnAuthInfoStrc
{
    unsigned int dwLogonType;
    unsigned int f_4;
    unsigned int f_8;
    D2FileTimeStrc tFileTime;
    char szFileName[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __fastcall sub_0051A540_SetValue(int nValue);                                                          // 0x0051A540
void __fastcall sub_0051A560_SetValue(int nValue);                                                          // 0x0051A560
int __fastcall sub_0051E3B0_SetCheckRevisionValue(const char* szValue);                                    // 0x0051E3B0
int __fastcall sub_0051EA80_SetArchiveName(const char* szName);                                             // 0x0051EA80
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910

static int BNAUTH_IsValidAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 0x16)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 0x14; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 1)
        return 0;
    return 1;
}

// 0x00521220
int __fastcall sub_00521220_HandleAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (!BNAUTH_IsValidAuthInfo(pData, nSize))
        return 0;

    const D2BnAuthInfoStrc* pInfo = (const D2BnAuthInfoStrc*)pData;
    D2FileTimeStrc tFileTime = pInfo->tFileTime;
    unsigned int nLogonType = pInfo->dwLogonType;
    unsigned int nServerToken = pInfo->f_4;
    const char* szFileName = pInfo->szFileName;
    const char* szValue = szFileName + SStrLen(szFileName) + 1;
    sub_0051A540_SetValue(nServerToken);
    sub_0051A560_SetValue(nLogonType);
    sub_0051E3B0_SetCheckRevisionValue(szValue);
    sub_0051EA80_SetArchiveName(&gszEmptyAssertText);
    sub_0051F910_Report(0x80000001, 3, 0, 0, &tFileTime, szFileName, 0);
    return 1;
}
