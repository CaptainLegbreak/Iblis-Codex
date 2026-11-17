struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2VersionReplyStrc
{
    unsigned int nResult;
    char szText[1];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned int nSize); // 0x00415000
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
int __cdecl sub_0051BCF0_SendBuffer();                                                                      // 0x0051BCF0
int __fastcall sub_0051E370_SetText(const char* szText, int nLength);                                       // 0x0051E370
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0

extern int gnUpdateState_008822C4;                                                                          // 0x008822C4

// 0x00520E50
int __fastcall sub_00520E50_HandleVersionReply(D2VersionReplyStrc* pReply, int nSize)
{
    const unsigned int nResult = pReply->nResult;
    switch (nResult)
    {
    case 1:
    case 2:
    case 3:
        sub_0051BCF0_SendBuffer();
        break;
    }

    SRegSaveData("Patch", "Patches", 0x82, &gszEmptyAssertText, 1);

    if (nResult == 1)
    {
        const char* szText = pReply->szText;
        const int nLength = nSize - 4;
        sub_0051E370_SetText(szText, nLength);
        SRegSaveData("Patch", "Patches", 0x82, szText, nLength);
        D2FileTimeStrc tFileTime = { 0 };
        sub_0051F910_Report(0x80000002, 2, 0, 0, &tFileTime, szText, 0);
        gnUpdateState_008822C4 = 0;
        sub_00518D40_Log("downloading upgrade");
        return 1;
    }

    if (nResult == 2)
    {
        gnUpdateState_008822C4 = 1;
        sub_00518D40_Log("user has latest version");
        return 1;
    }

    sub_005204A0_SetError(1);
    if (nResult == 3)
    {
        gnUpdateState_008822C4 = 0;
        sub_00518D40_Log("User must reinstall and patch");
        return 1;
    }

    gnUpdateState_008822C4 = 0;
    sub_00518D40_Log("user has unknown version");
    return 1;
}
