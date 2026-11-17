struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};
struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
struct D2BnExtraWorkPacketStrc
{
    unsigned short wType;
    unsigned short wSize;
    unsigned int dwLocale;
    unsigned char pData[0xFFC];
};
struct D2BnAdInfoStrc
{
    unsigned int nArg1;
    unsigned int nArg2;
    char* szText1;
    char* szText2;
    void* pData;
    unsigned int nDataSize;
};
class BNGatewayAccess
{
public:
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850
    void __stdcall SaveAndUnload();                                                                         // 0x00517ED0

private:
    int unk0x00[9];
};
typedef int (__stdcall* D2CheckRevisionFn)(const char* szFile1, const char* szFile2, const char* szFile3, const char* szValue, int* pVersion, int* pChecksum, char* szExeInfo);
typedef int (__fastcall* D2ExtraWorkFn)(D2BnExtraWorkPacketStrc* pPacket);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* szBuffer); // 0x006CC344
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);                  // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);    // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule);                                  // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);               // 0x006CC198
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                        // 0x006CC1A0
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile);         // 0x004192F0
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);                        // 0x00416370
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped);       // 0x0041B050
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq);    // 0x0041BA60
int __stdcall SFileCloseArchive(void* hMpq);                                                                // 0x00419A80
int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult);                             // 0x004172F0
int __stdcall sub_00419980(const char* szFileName, void** phFile);                                       // 0x00419980
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
bool __fastcall sub_00516DE1_CanRunSurvey(const char* szExePath);                                           // 0x00516DE1
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __fastcall sub_0051EA40_SetStatus(int nStatus);                                                        // 0x0051EA40
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
void __fastcall sub_0051B060_SetAdText(const char* szText1, const char* szText2);                           // 0x0051B060
void __fastcall sub_005202F0_PostText(int nType, const char* szText);                                       // 0x005202F0
void __fastcall sub_00520210_PostData(int nType, const void* pData, unsigned int nSize);                    // 0x00520210

extern "C" const char gszBnDownloadFile_006DF338[];                                                         // 0x006DF338
char gszDownloadArchive_00881C58[260];                                                                      // 0x00881C58
char gszCheckRevisionValue_00881E60[260];                                                                   // 0x00881E60
extern char gszAdList_00881D60[];                                                                           // 0x00881D60
extern D2CriticalSectionStrc gDownloadLock_00881F64;                                                        // 0x00881F64
extern BNGatewayAccess gBnGatewayAccess_00881838;                                                           // 0x00881838

// 0x0051E490
static int __stdcall sub_0051E490_ExtractArchiveDll(void* hArchive, char* szPath, const char* szFile)
{
    int bResult = 0;
    void* hFile = 0;
    unsigned int nLength = GetTempPathA(0x104 - strlen(szFile), szPath);
    if (!nLength)
    {
        sub_00410610_WriteLogLine("Failed to create temp file!");
    }
    else
    {
        sub_00413800(szPath, szFile, 0x104);
        char* pExtension = strrchr(szPath, '.');
        if (pExtension)
            *pExtension = 0;
        sub_00413800(szPath, ".dll", 0x104);
        if (SFileOpenFileEx(hArchive, szPath + nLength, 0, &hFile))
        {
            unsigned int nSize = sub_00416370_StormGetFileSize(hFile, 0);
            void* pBuffer = SMemAlloc(nSize, gszBnDownloadFile_006DF338, 0xF7, 0);
            if (pBuffer)
            {
                SFileReadFile(hFile, pBuffer, nSize, 0, 0);
                void* hOut = sub_00406960_CreateFile(szPath, 0x40000000, 0, 0, 2, 0x80, 0);
                if (hOut != (void*)-1)
                {
                    unsigned long nWritten;
                    sub_004069D0_WriteFile(hOut, pBuffer, nSize, &nWritten, 0);
                    sub_004069A0_CloseFile(hOut);
                    bResult = 1;
                }
                SMemFree(pBuffer, gszBnDownloadFile_006DF338, 0x111, 0);
            }
        }
    }
    if (hFile)
        sub_004198D0(hFile);
    return bResult;
}

// 0x0051E6D0
int __fastcall sub_0051E6D0_RunCheckRevision(int* pVersion, int* pChecksum, char* szExeInfo)
{
    if (pVersion)
        *pVersion = 0;
    if (pChecksum)
        *pChecksum = 0;
    if (szExeInfo)
        *szExeInfo = 0;

    void* hArchive = 0;
    char szDll[0x104] = { 0 };
    int nResult = 0;
    unsigned long dwStart = GetTickCount();
    do
    {
        if (gszDownloadArchive_00881C58[0])
        {
    if (!SFileOpenArchive(gszDownloadArchive_00881C58, 0, 0, &hArchive))
        return 0;

    unsigned int nAuth;
    SFileAuthenticateArchive(hArchive, &nAuth);
    if (!nAuth || nAuth >= 5)
    {
        if (sub_0051E490_ExtractArchiveDll(hArchive, szDll, gszDownloadArchive_00881C58) && sub_00516DE1_CanRunSurvey(szDll))
        {
            void* hDll = LoadLibraryA(szDll);
            if (hDll)
            {
                D2CheckRevisionFn pfnCheckRevision = (D2CheckRevisionFn)GetProcAddress(hDll, "CheckRevision");
                if (pfnCheckRevision)
                {
                    char szFile1[0x104] = { 0 };
                    char szFile2[0x104] = { 0 };
                    char szFile3[0x104] = { 0 };
                    GetModuleFileNameA(GetModuleHandleA(0), szFile1, 0x104);
                    nResult = pfnCheckRevision(szFile1, szFile2, szFile3, gszCheckRevisionValue_00881E60, pVersion, pChecksum, szExeInfo);
                }
                FreeLibrary(hDll);
            }
        }
    }

    if (hArchive)
        SFileCloseArchive(hArchive);
    Sleep(50);
    DeleteFileA(gszDownloadArchive_00881C58);
    if (szDll[0])
        DeleteFileA(szDll);
    return nResult;
        }
        Sleep(10);
    }
    while (GetTickCount() - dwStart <= 20000);
    return 1;
}

void __fastcall sub_0051FAB0_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag)
{
    switch (nType)
    {
    case 0x80000003:
    {
        D2BnAdInfoStrc info;
        info.nArg1 = nArg1;
        info.nArg2 = nArg2;
        char* szCopy1;
        if (szText1 && strlen(szText1))
        {
            szCopy1 = (char*)FOG_Alloc(strlen(szText1) + 1, gszBnDownloadFile_006DF338, 0x179, 0);
            strcpy(szCopy1, szText1);
        }
        else
        {
            szCopy1 = 0;
        }
        info.szText1 = szCopy1;
        char* szCopy2;
        if (szText2 && strlen(szText2))
        {
            szCopy2 = (char*)FOG_Alloc(strlen(szText2) + 1, gszBnDownloadFile_006DF338, 0x182, 0);
            strcpy(szCopy2, szText2);
        }
        else
        {
            szCopy2 = 0;
        }
        info.szText2 = szCopy2;
        void* pCopy;
        if (nDataSize && pData)
        {
            pCopy = FOG_Alloc(nDataSize, gszBnDownloadFile_006DF338, 0x18B, 0);
            memcpy(pCopy, pData, nDataSize);
        }
        else
        {
            pCopy = 0;
        }
        info.pData = pCopy;
        info.nDataSize = nDataSize;
        sub_0051B060_SetAdText(szText1, szText2);
        char szMessage[0x200];
        sprintf(szMessage, "<Received Ad: %s, %s>\n", info.szText1, info.szText2);
        sub_005202F0_PostText(1, szMessage);
        sub_00520210_PostData(3, &info, sizeof(info));
        break;
    }
    case 0x80000002:
    {
        EnterCriticalSection(&gDownloadLock_00881F64);
        const char* pEntry = gszAdList_00881D60;
        while (*pEntry)
        {
            if (!_stricmp(pEntry, szText1))
                break;
            pEntry += strlen(pEntry) + 1;
        }
        if (!*pEntry || !pEntry[strlen(pEntry) + 1])
        {
            sub_0051EA40_SetStatus(0x65);
        }
        else
        {
            const char* szValue = pEntry + strlen(pEntry) + 1;
            D2FileTimeStrc fileTime = { 0, 0 };
            sub_0051F910_Report(0x80000002, 2, 0, 0, &fileTime, szValue, 0);
        }
        LeaveCriticalSection(&gDownloadLock_00881F64);
        break;
    }
    case 0x80000001:
        sub_0051A480_DebugLog("Processing Version file");
        strcpy(gszDownloadArchive_00881C58, szText1);
        break;
    case 0x80000005:
        if (bFlag)
        {
            DeleteFileA(szText1);
            break;
        }
    case 0x80000006:
    {
        void* hArchive = 0;
        void* hFile = 0;
        void* hDll = 0;
        char szDll[0x104] = { 0 };
        sub_0051A480_DebugLog("Processing ExtraWork file");
        if (!SFileOpenArchive(szText1, 0, 0, &hArchive))
            break;

        unsigned int nAuth;
        SFileAuthenticateArchive(hArchive, &nAuth);
        if (nAuth && nAuth < 5)
        {
            sub_0051A480_DebugLog("<ERROR: Failed ExtraWork archive authentication!>");
        }
        else if (!sub_0051E490_ExtractArchiveDll(hArchive, szDll, szText1))
        {
            sub_0051A480_DebugLog("<ERROR: Failed to extract ExtraWork DLL!>");
        }
        else
        {
            hDll = LoadLibraryA(szDll);
            D2ExtraWorkFn pfnExtraWork;
            unsigned char nLocale;
            int nRead;
            if (!hDll)
                sub_0051A480_DebugLog("<ERROR: Failed to load ExtraWork DLL!>");
            else if (!(pfnExtraWork = (D2ExtraWorkFn)GetProcAddress(hDll, "ExtraWork")))
                sub_0051A480_DebugLog("<ERROR: Failed to get address of ExtraWork function!>");
            else if (!sub_00419980("data\\local\\use", &hFile))
                sub_0051A480_DebugLog("<ERROR: Failed to open game locale file!>");
            else if (!SFileReadFile(hFile, &nLocale, 1, &nRead, 0))
                sub_0051A480_DebugLog("<ERROR: Failed to read game locale file!>");
            else if (nRead != 1)
                sub_0051A480_DebugLog("<ERROR: Failed to read game locale file!>");
            else
            {
                sub_004198D0(hFile);
                D2BnExtraWorkPacketStrc packet;
                memset(&packet, 0, sizeof(packet));
                packet.wType = 1;
                packet.wSize = 4;
                packet.dwLocale = nLocale;
                if (pfnExtraWork(&packet))
                    sub_0051C5C0_SendPacket(0x4B, &packet, packet.wSize + 4);
                else
                    sub_0051A480_DebugLog("<ERROR: ExtraWork DLL indicated failure!>");
            }
        }
        if (hDll)
            FreeLibrary(hDll);

        if (hArchive)
            SFileCloseArchive(hArchive);
        Sleep(50);
        DeleteFileA(szText1);
        if (szDll[0])
            DeleteFileA(szDll);
        break;
    }
    case 0x80000004:
    {
        sub_0051A480_DebugLog("Processing Bnserver.ini file");
        unsigned int nSize = SStrLen((const char*)pData) + 1;
        char* szText = (char*)SMemAlloc(nSize, gszBnDownloadFile_006DF338, 0x23F, 0);
        SStrCopy(szText, (const char*)pData, nSize);
        gBnGatewayAccess_00881838.UpdateGatewaysFromIni(szText);
        SMemFree(szText, gszBnDownloadFile_006DF338, 0x245, 0);
        gBnGatewayAccess_00881838.SaveAndUnload();
        break;
    }
    }
}
