#include "D2BNClient.h"

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

class BNGatewayAccess
{
public:
    void __stdcall UpdateGatewaysFromIni(char* szText); // 0x00518850
    void __stdcall SaveAndUnload(); // 0x00517ED0

private:
    int unk0x00[9];
};
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
unsigned int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370
int __stdcall sub_004198D0(void* hFile); // 0x004198D0
int __stdcall SFileReadFile(void* hFile, void* pBuffer, unsigned int nToRead, unsigned int* pnRead, void* pOverlapped); // 0x0041B050
void __fastcall sub_0051E920_ExtractFile(const char* szMember, void* hArchive, const char* szDestination); // 0x0051E920

extern BNGatewayAccess gBnGatewayAccess_00881838; // 0x00881838

static int sub_0051E9D0_RunProgramList(const char* szList, const char* szDirectory); // 0x0051E9D0

// 0x0051E9D0
static int sub_0051E9D0_RunProgramList(const char* szList, const char* szDirectory)
{
    while (*szList)
    {
        if (!sub_00516DE1_CanRunSurvey(szList))
            return 0;

        if ((int)ShellExecuteA(0, 0, szList, 0, szDirectory, 1) <= 0x20)
            return 0;

        szList += SStrLen(szList) + 1;
    }

    return 1;
}

// 0x0051ED00
int __fastcall sub_0051ED00_ApplyPatches(int* pResult)
{
    D2_ASSERT(pResult, 1205);

    char szModuleDir[260] = { 0 };
    GetModuleFileNameA(0, szModuleDir, sizeof(szModuleDir));
    szModuleDir[259] = 0;

    char* pSlash = szModuleDir;
    while (*pSlash && SStrChr(pSlash + 1, '\\'))
    {
        pSlash = SStrChr(pSlash + 1, '\\');
    }
    *pSlash = 0;

    char szPatches[1024] = { 0 };
    if (!SRegLoadData("Patch", "Patches", 2, szPatches, 1022, 0) || !szPatches[0])
    {
        *pResult = 0;
        return 0;
    }

    char szRunList[1024] = { 0 };
    char* pRun = szRunList;
    char* szPatch = szPatches;
    while (*szPatch)
    {
        void* hArchive;
        if (!SFileOpenArchive(szPatch, 0, 0, &hArchive))
        {
            DeleteFileA(szPatch);
            *pResult = -1;
            return 0;
        }

        unsigned int nAuth;
        SFileAuthenticateArchive(hArchive, &nAuth);
        if (nAuth && nAuth < 5)
        {
            SFileCloseArchive(hArchive);
            DeleteFileA(szPatch);
            *pResult = -1;
            return 0;
        }

        void* hFile;
        if (SFileOpenFileEx(hArchive, "Prepatch.lst", 0, &hFile))
        {
            unsigned int nSize = sub_00416370_StormGetFileSize(hFile, 0);
            char* pBuffer = (char*)SMemAlloc(nSize, ".\\BnDownload.cpp", 1267, 0);
            if (SFileReadFile(hFile, pBuffer, nSize, 0, 0))
            {
                char* pCur = pBuffer;
                while ((unsigned int)(pCur - pBuffer) < nSize)
                {
                    char szLine[256] = { 0 };
                    char* pOut = szLine;
                    while ((unsigned int)(pCur - pBuffer) < nSize && pOut - szLine < 255 && *pCur && *pCur != '\r' && *pCur != '\n')
                    {
                        *pOut++ = *pCur++;
                        *pOut = 0;
                    }

                    while ((unsigned int)(pCur - pBuffer) < nSize && (*pCur == '\r' || *pCur == '\n'))
                    {
                        ++pCur;
                    }

                    char szMember[260] = { 0 };
                    char szDest[260] = { 0 };
                    if (SStrChr(szLine, ' '))
                    {
                        pSlash = SStrChr(szLine, ' ') + 1;
                        while (*pSlash == ' ')
                        {
                            ++pSlash;
                        }
                        SStrCopy(szMember, pSlash, sizeof(szMember));
                        wsprintfA(szDest, "%s\\%s", szModuleDir, pSlash);
                    }

                    if (!_strnicmp(szLine, "delete ", 7))
                    {
                        DeleteFileA(szDest);
                    }
                    else if (!_strnicmp(szLine, "extract ", 8))
                    {
                        sub_0051E920_ExtractFile(szMember, hArchive, szDest);
                    }
                    else if (!_strnicmp(szLine, "execute ", 8))
                    {
                        pRun += SStrCopy(pRun, szDest, 0x7FFFFFFF) + 1;
                    }
                }
            }
            SMemFree(pBuffer, ".\\BnDownload.cpp", 1320, 0);
            sub_004198D0(hFile);
        }
        SFileCloseArchive(hArchive);

        szPatch += SStrLen(szPatch) + 1;
    }

    char szValue[900];
    pSlash = szValue;
    sprintf(pSlash, "%s\\Game.exe", szModuleDir);
    SRegSaveString("Patch", "Launcher", 2, pSlash);
    if (sub_00408F20_HasExpansionMpq())
    {
        pSlash += sprintf(pSlash, "%s\\%s;", szModuleDir, "d2exp.mpq");
    }
    sprintf(pSlash, "%s\\%s;%s\\%s", szModuleDir, "d2data.mpq", szModuleDir, "d2sfx.mpq");
    SRegSaveString("Patch", "SrcData", 2, szValue);
    sprintf(szValue, "%s\\%s", szModuleDir, "patch_d2.mpq");
    SRegSaveString("Patch", "DstData", 2, szValue);

    if (pRun == szRunList)
    {
        wsprintfA(pRun, "%s\\bnupdate.exe", szModuleDir);
        pRun += SStrLen(pRun) + 1;
    }
    *pRun = 0;

    gBnGatewayAccess_00881838.SaveAndUnload();

    if (!sub_0051E9D0_RunProgramList(szRunList, szModuleDir))
    {
        *pResult = -1;
        return 0;
    }

    *pResult = 2;
    return 1;
}
