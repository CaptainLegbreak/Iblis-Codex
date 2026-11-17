extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

struct D2FuncRecordStrc
{
    char unk0x00[0x0C];
    int nIndex;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x98];
    D2FuncRecordStrc* (__cdecl* pfnGetRecord)();
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);  // 0x006CC1C8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
const char* __stdcall sub_005180A0_GetNthString(D2FuncRecordStrc* pRecord, int nIndex);                     // 0x005180A0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __fastcall sub_005009D0_SetValue(D2WinControlStrc* pControl, int nMode, Unicode* pText, int nArg);     // 0x005009D0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize);                 // 0x0052A8B0
int __fastcall sub_004F9190();                                                            // 0x004F9190
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                          // 0x00407050
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);                                        // 0x00406A10
int __fastcall sub_00449920_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue);  // 0x00449920

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578
extern D2WinControlStrc* gpControl_007795AC;                                                                // 0x007795AC
int gdwGlobal_00779990;                                                                                     // 0x00779990
extern int gdwGlobal_00779974;                                                                              // 0x00779974

// 0x00431AF0
void __cdecl sub_00431AF0()
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    char szText[0x100];
    const int nIndex = pRecord->nIndex;
    SStrCopy(szText, sub_005180A0_GetNthString(pRecord, nIndex), 0x100);

    Unicode wszText[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, szText, 0x100);

    Unicode wszFormat[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszFormat[i].wChar = 0;
    sub_005267E0(wszFormat, D2LANG_GetStringFromTblIndex(0x2B29));

    Unicode wszOut[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszOut[i].wChar = 0;
    memset(wszOut, 0, 0x100);
    sub_005269D0(0x100, wszOut, wszFormat, wszText);

    for (int i = 0; i < sub_00526800(wszOut); ++i)
    {
        const unsigned short wChar = wszOut[i].wChar;
        wszOut[i].wChar = wChar < 0x100 ? gwToUpperTable_00730578[wChar] : wChar;
    }

    sub_005009D0_SetValue(gpControl_007795AC, 10, wszOut, 0);
}

// 0x00431C90
int __stdcall sub_00431C90_PollSystemPacket(int nUnused)
{
    unsigned char pBuffer[0x200];
    if (CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer)) != -1)
    {
        switch (pBuffer[0])
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            sub_004F9190();
            return 1;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }

    if (gdwGlobal_00779990 || gdwGlobal_00779974)
        sub_004F9190();

    return 1;
}

// 0x0043C750
void __fastcall sub_0043C750(const char* szCharName, const char* szSubdirectory)
{
    char szDir[0x104];
    D2FindDataStrc tFind;
    char szTemp[0x104];
    char szPath[500];
    char szMask[500];

    D2_ASSERT(szCharName[0], 0xAF);

    sub_00407050_GetSavePath(szDir, 0x104);
    if (szSubdirectory && szSubdirectory[0])
    {
        SStrPrintf(szTemp, 0x104, "%s%s\\", szDir, szSubdirectory);
        sub_00406A10_CreateDirectoryTree(szTemp);
        SStrCopy(szDir, szTemp, 0x104);
    }

    sprintf(szMask, "%s%s.*", szDir, szCharName);
    void* hFind = FindFirstFileA(szMask, &tFind);
    while (hFind != (void*)-1)
    {
        sprintf(szPath, "%s%s", szDir, tFind.cFileName);
        if (GetFileAttributesA(szPath) & 0x10)
        {
            if (!FindNextFileA(hFind, &tFind))
                return;
        }
        else
        {
            if (!DeleteFileA(szPath))
                return;
            hFind = FindFirstFileA(szMask, &tFind);
        }
    }
}

// 0x0043E900
int __stdcall sub_0043E900_FindCdKeyInText(const char* szText)
{
    char szKey[0x400];
    int nCount = 0;
    const int nLength = SStrLen(szText);
    for (int i = 0; i < nLength; ++i)
    {
        if (nLength - i < 16 - nCount)
            return 0;

        const char c = szText[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            szKey[nCount++] = c;
        }
        else if (c != '-' && c != ' ')
        {
            nCount = 0;
            continue;
        }

        if (nCount == 16)
        {
            unsigned int nProduct;
            unsigned int nValue;
            szKey[16] = 0;
            if (sub_00449920_DecodeCdKey(szKey, &nProduct, &nValue)
                && (nProduct == 6 || nProduct == 7 || nProduct == 10 || nProduct == 12))
                return 1;
            nCount = 0;
        }
    }
    return 0;
}
