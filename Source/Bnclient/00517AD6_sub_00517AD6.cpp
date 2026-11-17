typedef unsigned long DWORD;
typedef long LONG;
typedef void* HANDLE;
typedef void* HWND;
struct GUID { unsigned long Data1; unsigned short Data2; unsigned short Data3; unsigned char Data4[8]; };
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, wchar_t* lpWideCharStr, int cchWideChar); // 0x006CC29C
extern "C" __declspec(dllimport) DWORD __stdcall GetLastError(void); // 0x006CC1B4

void* __cdecl operator new(unsigned int nSize);   // 0x00405410
void __cdecl operator delete(void* pMemory);      // 0x004053F0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie);    // 0x00681A48
extern "C" unsigned int __security_cookie;        // 0x00749DE0

struct TRUSTFILEINFO
{
    DWORD cbStruct;
    const wchar_t* pcwszFilePath;
    HANDLE hFile;
    GUID* pgKnownSubject;
};

struct TRUSTDATA
{
    DWORD cbStruct;
    void* pPolicyCallbackData;
    void* pSIPClientData;
    DWORD dwUIChoice;
    DWORD fdwRevocationChecks;
    DWORD dwUnionChoice;
    TRUSTFILEINFO* pFile;
    DWORD dwStateAction;
    HANDLE hWVTStateData;
    wchar_t* pwszURLReference;
    DWORD dwProvFlags;
    DWORD dwUIContext;
};

extern "C" LONG __stdcall BNCLIENT_WinVerifyTrust(HWND hWnd, GUID* pgActionID, void* pWVTData); // 0x006B00F6

// 0x00517AD6
int __fastcall sub_00517AD6(const char* szPath)
{
    if (!szPath || !*szPath)
        return 4;

    int nLen = MultiByteToWideChar(0, 0, szPath, -1, 0, 0);
    if (nLen <= 0)
        return 4;

    wchar_t* wszPath = new wchar_t[nLen];
    MultiByteToWideChar(0, 0, szPath, -1, wszPath, nLen);

    TRUSTFILEINFO tFile;
    memset(&tFile, 0, sizeof(tFile));
    tFile.cbStruct = sizeof(tFile);
    tFile.pcwszFilePath = wszPath;
    tFile.hFile = 0;
    tFile.pgKnownSubject = 0;

    GUID tAction = { 0x00AAC56B, 0xCD44, 0x11D0, { 0x8C, 0xC2, 0x00, 0xC0, 0x4F, 0xC2, 0x95, 0xEE } };

    TRUSTDATA tData;
    memset(&tData, 0, sizeof(tData));
    tData.cbStruct = sizeof(tData);
    tData.pPolicyCallbackData = 0;
    tData.pSIPClientData = 0;
    tData.dwUIChoice = 2;
    tData.fdwRevocationChecks = 0;
    tData.dwUnionChoice = 1;
    tData.pFile = &tFile;
    tData.dwStateAction = 0;
    tData.hWVTStateData = 0;
    tData.pwszURLReference = 0;
    tData.dwUIContext = 0;

    LONG nResult = BNCLIENT_WinVerifyTrust(0, &tAction, &tData);
    int nRet;
    switch (nResult)
    {
    case 0x80092026:
    case 0x800B0004:
    case 0x800B0111:
        nRet = 3;
        break;
    case 0x800B0100:
        nRet = (GetLastError() != 0x800B0100) + 1;
        break;
    default:
        nRet = nResult ? 4 : 0;
        break;
    }

    delete wszPath;
    return nRet;
}
