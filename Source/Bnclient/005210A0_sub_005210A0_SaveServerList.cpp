struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2BnReportStrc
{
    int nResult;
    int unk0x04;
    D2FileTimeStrc tFileTime;
    char szText[1];
};

extern "C" const char szConfiguration_006DEC7C[];                                                           // 0x006DEC7C
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
void __fastcall sub_0051BDC0_SetReply(const void* pData, unsigned int nSize);                               // 0x0051BDC0
void __fastcall sub_0051BE20_SetReply(const void* pData, unsigned int nSize);                               // 0x0051BE20
void __fastcall sub_0051BD60_SetReply(const void* pData, unsigned int nSize);                               // 0x0051BD60
void __fastcall sub_005202F0_PostText(int nType, const char* szText);                                       // 0x005202F0
int __fastcall sub_00520630_SetText(const char* szText);                                                    // 0x00520630
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910

// 0x005210A0
int __fastcall sub_005210A0_SaveServerList(const void* pData, unsigned int nSize)
{
    SRegSaveString(szConfiguration_006DEC7C, "Server List", 2, (const char*)pData + 4);
    return 1;
}

// 0x005210C0
int __fastcall sub_005210C0_SetReply(const void* pData, unsigned int nSize)
{
    sub_0051BDC0_SetReply(pData, nSize);
    return 1;
}

// 0x005210D0
int __fastcall sub_005210D0_SetReply(const void* pData, unsigned int nSize)
{
    sub_0051BE20_SetReply(pData, nSize);
    return 1;
}

// 0x005211D0
int __fastcall sub_005211D0_SetReply(const void* pData, unsigned int nSize)
{
    sub_0051BD60_SetReply(pData, nSize);
    return 1;
}

// 0x005210F0
int __fastcall sub_005210F0_ShowText(const void* pData, unsigned int nSize)
{
    sub_005202F0_PostText(2, (const char*)pData);
    sub_00520630_SetText((const char*)pData);
    return 1;
}

// 0x00521110
int __fastcall sub_00521110_Report(const void* pData, unsigned int nSize)
{
    const D2BnReportStrc* pReport = (const D2BnReportStrc*)pData;
    const int nResult = pReport->nResult;
    const D2FileTimeStrc* pFileTime = &pReport->tFileTime;
    const char* szText = (const char*)(pFileTime + 1);
    const int nSubType = (nResult == 0x80000005 || nResult == 0x80000006) ? 2 : 4;
    sub_0051F910_Report(nResult, nSubType | 1, 0, 0, pFileTime, szText, 0);
    return 1;
}
