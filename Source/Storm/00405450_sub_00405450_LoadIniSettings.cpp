struct _iobuf;

struct D2IniEntryStrc
{
    char szSection[0x1B];
    char szKey[0x36];
    unsigned char nType;
    char pad0x52[2];
    int nOffset;
    int nDefault;
};

extern D2IniEntryStrc gaIniEntries_00705040[58];                                                            // 0x00705040
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char* szAppName, const char* szKeyName, int nDefault, const char* szFileName); // 0x006CC150
extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(const char* szAppName, const char* szKeyName, const char* szDefault, char* szReturned, unsigned long nSize, const char* szFileName); // 0x006CC420
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" int __cdecl fputc(int nChar, _iobuf* pFile);                                                     // 0x00682058
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);                                        // 0x00406A10
int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, int nSize);                                    // 0x00406B60
int __fastcall sub_00406C40_GetBlizzardDataPath(char* szOutPath, int nSize);                                // 0x00406C40
bool __fastcall sub_00516DE1_CanRunSurvey(const char* szExePath);                                           // 0x00516DE1
bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath);                                              // 0x00516D8B
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800

// 0x00405450
void __stdcall sub_00405450_LoadIniSettings(char* pSettings)
{
    char szIni[0x104];
    sub_00406B60_GetModuleDirectory(szIni, 0x104);
    sub_00413800(szIni, "D2.ini", 0x104);
    for (int i = 0; i < sizeof(gaIniEntries_00705040) / sizeof(gaIniEntries_00705040[0]); i++)
    {
        char* pDest = pSettings + gaIniEntries_00705040[i].nOffset;
        switch (gaIniEntries_00705040[i].nType)
        {
        case 0:
            *pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni) != 0;
            break;
        case 1:
            *(int*)pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni);
            break;
        case 2:
            GetPrivateProfileStringA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, &gszEmptyAssertText, pDest, 0x1B, szIni);
            break;
        }
    }
}

// 0x00405A70
void __stdcall sub_00405A70_WriteSurveyLocale()
{
    unsigned int nLanguage;
    char szPath[0x104];
    char szExe[0x400];
    sub_00525260(&nLanguage, 3);
    if (sub_00406C40_GetBlizzardDataPath(szPath, 0x104))
    {
        sub_00413800(szPath, "System Survey\\ProductData\\", 0x104);
        char* pEnd = szPath + SStrLen(szPath);
        unsigned int nRemain = szPath + sizeof(szPath) - pEnd;
        SStrCopy(pEnd, "D2DV\\locale", nRemain);
        sub_00406A10_CreateDirectoryTree(szPath);
        _iobuf* pFile = fopen(szPath, "w");
        if (pFile)
        {
            fputc(nLanguage >> 24, pFile);
            fputc((nLanguage >> 16) & 0xFF, pFile);
            fputc((nLanguage >> 8) & 0xFF, pFile);
            fputc(nLanguage & 0xFF, pFile);
            fclose(pFile);
        }
        if (sub_00408F20_HasExpansionMpq())
        {
            SStrCopy(pEnd, "D2XP\\locale", nRemain);
            sub_00406A10_CreateDirectoryTree(szPath);
            pFile = fopen(szPath, "w");
            if (pFile)
            {
                fputc(nLanguage >> 24, pFile);
                fputc((nLanguage >> 16) & 0xFF, pFile);
                fputc((nLanguage >> 8) & 0xFF, pFile);
                fputc(nLanguage & 0xFF, pFile);
                fclose(pFile);
            }
        }
    }
    sub_00406B60_GetModuleDirectory(szExe, 0x400);
    sub_00413800(szExe, "SystemSurvey.exe", 0x400);
    if (sub_00516DE1_CanRunSurvey(szExe))
        sub_00516D8B_RunSurvey(szExe);
}

#include "gen/data/Source/Storm/00405450_sub_00405450_LoadIniSettings.inc"
