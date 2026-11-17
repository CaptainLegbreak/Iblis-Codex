struct D2WinSmackStrc;

struct D2LaunchMsgStrc
{
    int nType;
    int nArg;
    char* szName;
    void* pExtra;
    void* pData;
    unsigned long nSize;
    char szText[0x108];
};

typedef int (__fastcall* D2LaunchMsgHandler)(int nArg, char* pArg, const char* szText, const char* szNext);

struct D2LaunchFuncsStrc
{
    char unk0x00[0x24];
    int (__fastcall* pfnGetMessage)(int* pnType, D2LaunchMsgStrc* pMsg);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* szBuffer);      // 0x006CC344
extern "C" __declspec(dllimport) unsigned int __stdcall GetTempFileNameA(const char* szPathName, const char* szPrefix, unsigned int nUnique, char* szTempFileName); // 0x006CC340
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName);                         // 0x006CC1A0
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack);                                                     // 0x00506990
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion);                   // 0x00506910
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

extern D2WinSmackStrc* gpSmack_0077B098;                                                                    // 0x0077B098
extern D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                           // 0x0077B09C
extern int gnVideoId_0077B0A4;                                                                              // 0x0077B0A4
extern char gszText_00798CF8[];                                                                             // 0x00798CF8
extern char gszTempFile_00798E30[];                                                                         // 0x00798E30
extern D2LaunchMsgHandler gpfnMsgHandlers_0070EC20[];                                                       // 0x0070EC20

static __declspec(noinline) int sub_00446B70_PlayVideoMessage(D2LaunchMsgStrc* pMsg)
{
    char szTempPath[0x104];
    char szTempFile[0x104];
    unsigned long nWritten;

    SMACK_DeleteFile(gpSmack_0077B098);
    if (!GetTempPathA(0x104, szTempPath))
        strcpy(szTempPath, ".");

    if (GetTempFileNameA(szTempPath, "BNetAd", 0, szTempFile) > 0)
    {
        DeleteFileA(gszTempFile_00798E30);
        void* hFile = sub_00406960_CreateFile(szTempFile, 0x40000000, 0, 0, 4, 0x8000000, 0);
        if (hFile != (void*)-1)
        {
            sub_004069D0_WriteFile(hFile, pMsg->pData, pMsg->nSize, &nWritten, 0);
            sub_004069A0_CloseFile(hFile);
        }
        const char* pExt = strrchr(pMsg->szName, '.') + 1;
        SMACK_Decode(gpSmack_0077B098, szTempFile, tolower(*pExt));
        strcpy(gszTempFile_00798E30, szTempFile);
    }

    gnVideoId_0077B0A4 = pMsg->nType;
    FOG_Free(pMsg->szName, ".\\Src\\ComCallback.cpp", 0x386, 0);
    FOG_Free(pMsg->pExtra, ".\\Src\\ComCallback.cpp", 0x387, 0);
    return 1;
}

// 0x00447740
static __declspec(noinline) int sub_00447740_DispatchMessage(D2LaunchMsgStrc* pMsg)
{
    int nArg = pMsg->nArg;
    char* pArg = pMsg->szName;
    unsigned int nIndex = pMsg->nType;
    const char* szText = pMsg->szText;
    int nLength = strlen(szText);
    if (nIndex < 0x18)
    {
        D2LaunchMsgHandler pfnHandler = gpfnMsgHandlers_0070EC20[nIndex];
        if (pfnHandler)
        {
            int nResult = pfnHandler(nArg, pArg, szText, szText + nLength + 1);
            if (nResult)
                return nResult;
        }
    }
    return 1;
}

// 0x00447A10
int __cdecl sub_00447A10_Pump()
{
    int nType;
    D2LaunchMsgStrc tMsg;
    if (!gpLaunchFuncs_0077B09C->pfnGetMessage(&nType, &tMsg))
        return 0;

    switch (nType)
    {
    case 0:
        sub_00447740_DispatchMessage(&tMsg);
        break;
    case 2:
        SStrCopy(gszText_00798CF8, (char*)&tMsg, 0x32);
        break;
    case 3:
        sub_00446B70_PlayVideoMessage(&tMsg);
        break;
    }
    return 1;
}

#include "gen/data/Source/D2Client/00447740_sub_00447740_DispatchMessage.inc"
