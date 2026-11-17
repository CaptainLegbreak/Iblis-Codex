struct D2WinControlStrc;
struct D2WinSmackStrc;

struct ComAdStrc
{
    void* pContext;
    int n04;
    char* szName;
    void* pData;
    void* pBuffer;
    unsigned long nSize;
};

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion); // 0x00506910
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack); // 0x00506990
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" int __cdecl tolower(int nChar); // 0x0068523E
D2WinSmackStrc* gpControl_0077B098;        // 0x0077B098
extern void* gpLaunchContext_0077B0A4; // 0x0077B0A4
extern char gszTempFile_00798E30[]; // 0x00798E30
extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* lpBuffer); // 0x006CC344
extern "C" __declspec(dllimport) unsigned int __stdcall GetTempFileNameA(const char* lpPathName, const char* lpPrefixString, unsigned int uUnique, char* lpTempFileName); // 0x006CC340
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0

// 0x00446B70
static int sub_00446B70_Func(ComAdStrc* pAd)
{
    char szTempFile[260];
    char szTempPath[260];
    unsigned long nWritten;

    SMACK_DeleteFile(gpControl_0077B098);
    if (!GetTempPathA(260, szTempPath))
    {
        *(unsigned short*)szTempPath = '.';
    }
    if (GetTempFileNameA(szTempPath, "BNetAd", 0, szTempFile) > 0)
    {
        DeleteFileA(gszTempFile_00798E30);
        void* hFile = sub_00406960_CreateFile(szTempFile, 0x40000000, 0, 0, 4, 0x8000000, 0);
        if (hFile != (void*)-1)
        {
            sub_004069D0_WriteFile(hFile, pAd->pBuffer, pAd->nSize, &nWritten, 0);
            sub_004069A0_CloseFile(hFile);
        }
        char* pExt = strrchr(pAd->szName, '.');
        pExt++;
        int ch = *pExt;
        int n = tolower(ch);
        SMACK_Decode(gpControl_0077B098, szTempFile, n);
        int i = 0;
        char c;
        do
        {
            c = szTempFile[i];
            gszTempFile_00798E30[i] = c;
            i++;
        } while (c);
    }
    gpLaunchContext_0077B0A4 = pAd->pContext;
    FOG_Free(pAd->szName, ".\\Src\\ComCallback.cpp", 0x386, 0);
    FOG_Free(pAd->pData, ".\\Src\\ComCallback.cpp", 0x387, 0);
    return 1;
}

int __cdecl sub_00447A10_Pump(int n)
{
    ComAdStrc ad;
    return sub_00446B70_Func(&ad);
}
