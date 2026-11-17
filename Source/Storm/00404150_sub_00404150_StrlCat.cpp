typedef unsigned int size_t;

struct D2CrashSubmitInfoStrc
{
    const char* szName;
    const char* szLocale;
    const char* f_8;
    unsigned int dwFlags;
    const char* apszLines[16];
    unsigned int nLines;
};

extern "C" size_t __cdecl strlen(const char* szString);
extern char gszTextBuffer_0098A280[0x400];                                                                  // 0x0098A280
bool __stdcall sub_00404330_FileExistsUtf8(const char* szPath);                                             // 0x00404330
bool __fastcall sub_00404210_CreateProcessUtf8(const char* szApplicationName, const char* szCommandLine);   // 0x00404210

static size_t __stdcall sub_00404150_StrlCat(const char* szSource, char* szDest, size_t nSize);

// 0x00401790
bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo)
{
    char szPath[0x400];
    char* pDest = szPath;
    const char* pSource = gszTextBuffer_0098A280;
    size_t nLeft = 0x400;
    if (nLeft != 0 && --nLeft != 0)
    {
        do
        {
            if ((*pDest++ = *pSource++) == 0)
            {
                break;
            }
        }
        while (--nLeft != 0);
    }
    if (nLeft == 0)
    {
        *pDest = 0;
        while (*pSource++)
        {
        }
    }
    const size_t nLength = pSource - gszTextBuffer_0098A280 - 1;
    if (nLength >= 0x400)
        return false;
    if (szPath[nLength - 1] != '/' && szPath[nLength - 1] != '\\')
        sub_00404150_StrlCat("\\", szPath, 0x400);
    sub_00404150_StrlCat("BlizzardError.exe", szPath, 0x400);
    if (!sub_00404330_FileExistsUtf8(szPath))
        return false;
    char szCommand[0x1000] = "";
    if (pInfo->dwFlags & 1)
        sub_00404150_StrlCat(" -auto", szCommand, 0x1000);
    if (pInfo->dwFlags & 2)
        sub_00404150_StrlCat(" -nocancel", szCommand, 0x1000);
    if (pInfo->dwFlags & 4)
        sub_00404150_StrlCat(" -simple", szCommand, 0x1000);
    if (pInfo->f_8)
    {
        sub_00404150_StrlCat(" -from ", szCommand, 0x1000);
        sub_00404150_StrlCat(pInfo->f_8, szCommand, 0x1000);
    }
    if (pInfo->szLocale)
    {
        sub_00404150_StrlCat(" -locale ", szCommand, 0x1000);
        sub_00404150_StrlCat(pInfo->szLocale, szCommand, 0x1000);
    }
    if (pInfo->szName)
    {
        sub_00404150_StrlCat(" -product \"", szCommand, 0x1000);
        sub_00404150_StrlCat(pInfo->szName, szCommand, 0x1000);
        sub_00404150_StrlCat("\"", szCommand, 0x1000);
    }
    for (unsigned int i = 0; i < pInfo->nLines; i++)
    {
        if (pInfo->apszLines[i] && *pInfo->apszLines[i])
        {
            sub_00404150_StrlCat(" -attachment \"", szCommand, 0x1000);
            sub_00404150_StrlCat(pInfo->apszLines[i], szCommand, 0x1000);
            sub_00404150_StrlCat("\"", szCommand, 0x1000);
        }
    }
    sub_00404150_StrlCat(" \"", szCommand, 0x1000);
    sub_00404150_StrlCat(szText, szCommand, 0x1000);
    sub_00404150_StrlCat("\"", szCommand, 0x1000);
    return sub_00404210_CreateProcessUtf8(szPath, szCommand);
}

// 0x00404150
static size_t __stdcall sub_00404150_StrlCat(const char* szSource, char* szDest, size_t nSize)
{
    char* pDest = szDest;
    const char* pSource = szSource;
    size_t nLeft = nSize;
    while (*pDest != 0 && nLeft-- != 0)
        pDest++;
    const size_t nDestLength = pDest - szDest;
    nLeft = nSize - nDestLength;
    if (nLeft == 0)
    {
        return nDestLength + strlen(pSource);
    }
    while (*pSource != 0)
    {
        if (nLeft != 1)
        {
            *pDest++ = *pSource;
            nLeft--;
        }
        pSource++;
    }
    *pDest = 0;
    return nDestLength + (pSource - szSource);
}
