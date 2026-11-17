struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
char gData_00882428[256];                                                                                   // 0x00882428
extern int gnGlobal_008823B0;                                                                               // 0x008823B0
int gnGlobal_008823EC;                                                                                      // 0x008823EC

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned int nSize); // 0x00415000
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
int __cdecl sub_0051BCF0_SendBuffer();                                                                      // 0x0051BCF0
int __fastcall sub_0051E370_SetText(const char* szText, int nLength);                                       // 0x0051E370
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
int __fastcall sub_00520520_SetState(int nState);                                                           // 0x00520520
int __fastcall sub_00520550_SetStateArg(void* pArg);                                                        // 0x00520550

static int BNAUTH_IsValidAuthCheck(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 5)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 4; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 0)
        return 0;
    return 1;
}

// 0x005212D0
int __fastcall sub_005212D0_HandleAuthCheck(const unsigned char* pData, unsigned int nSize)
{
    if (!BNAUTH_IsValidAuthCheck(pData, nSize))
    {
        sub_0051A480_DebugLog("INVALID: AuthCheck");
        return 0;
    }

    unsigned int nResult = *(const unsigned int*)pData;
    unsigned int nCode = nResult & 0xFF0F;
    const char* szInfo = (const char*)pData + 4;

    switch (nCode)
    {
    case 0:
    case 0x100:
    case 0x102:
        sub_0051BCF0_SendBuffer();
        break;
    }

    gData_00882428[0] = 0;
    gnGlobal_008823B0 = 0;
    SRegSaveData("Patch", "Patches", 0x82, &gszEmptyAssertText, 1);

    switch (nCode)
    {
    case 0x100:
    {
        char szPatches[0x100];
        unsigned int nLength = SStrCopy(szPatches, szInfo, 0xFE) + 1;
        szPatches[nLength] = 0;
        ++nLength;
        sub_0051E370_SetText(szPatches, nLength);
        SRegSaveData("Patch", "Patches", 0x82, szPatches, nLength);
        D2FileTimeStrc tFileTime;
        tFileTime.dwLowDateTime = 0;
        tFileTime.dwHighDateTime = 0;
        sub_0051F910_Report(0x80000002, 2, 0, 0, &tFileTime, szPatches, 0);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("Downloading Upgrade");
        break;
    }
    case 0:
        gnGlobal_008823B0 = 1;
        gnGlobal_008823EC = 1;
        sub_0051A480_DebugLog("User has latest version and a valid cdkey");
        break;
    case 0x101:
        sub_005204A0_SetError(1);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("User has unknown version");
        break;
    case 0x102:
        sub_005204A0_SetError(1);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("User must revert to an older version");
        break;
    case 0x200:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 7 : 3);
        sub_0051A480_DebugLog("User has an invalid cdkey (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x203:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 9 : 5);
        sub_0051A480_DebugLog("CD Key is for another product (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x202:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 8 : 4);
        sub_0051A480_DebugLog("CD Key is disabled (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x201:
    {
        sub_00520520_SetState(((nResult >> 4) & 0xF) ? 10 : 6);
        SStrCopy(gData_00882428, szInfo, 0x100);
        sub_00520550_SetStateArg(gData_00882428);
        sub_0051A480_DebugLog("CD Key is in use by %s (%ld)", gData_00882428, (nResult >> 4) & 0xF);
        break;
    }
    }
    return 1;
}
