typedef unsigned int size_t;

struct _iobuf;

struct D2SidAuthorityStrc
{
    unsigned char Value[6];
};

struct D2InspectorInfoStrc
{
    int f_0;
    const char* szUnused04;
    const char* szApplication;
    const char* szModule;
    const char* szMilestone;
    const char* szBuildNumber;
    const char* f_18;
    const char* szPrimaryAssignment;
    const char* szAssignments;
};

namespace crashy
{
class Report
{
public:
    Report();
    virtual ~Report();
    bool sub_00401210_IsOpen();                                             // 0x00401210
    bool sub_00401220_AddFile(const char* szPath, bool bFlag);              // 0x00401220
    int sub_00401380(const char* szFormat, ...);                                  // 0x00401380
    bool sub_00407A80_WriteInspectorHeader();

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[1][0x400];
};
}

extern "C" __declspec(dllimport) int __stdcall AllocateAndInitializeSid(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid); // 0x006CC014
extern "C" __declspec(dllimport) int __stdcall CheckTokenMembership(void* hToken, void* pSid, int* pbIsMember); // 0x006CC050
extern "C" __declspec(dllimport) void* __stdcall FreeSid(void* pSid);                                       // 0x006CC044
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();                             // 0x006CC1EC
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                         // 0x00682990
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

bool __fastcall sub_00407A20_GetProcessImageName(unsigned long dwProcessId, char* szName, unsigned long nSize); // 0x00407A20
unsigned long __fastcall sub_00407990_FindOwnerProcess(unsigned long dwProcessId);                         // 0x00407990
unsigned int __fastcall sub_0040EB90_GetLogFiles(char** apszFiles, unsigned int nCount);                     // 0x0040EB90
int __stdcall sub_00525150();                                                                       // 0x00525150
int __stdcall sub_005251C0_GetLanguage();                                                                   // 0x005251C0

extern D2InspectorInfoStrc gtInspectorInfo_0074D868;                                                       // 0x0074D868
char gszProcessPath_0074E8C8[2048];                                                                         // 0x0074E8C8
extern const char* const gaszLanguageNames_00706618[];                                                      // 0x00706618

extern "C" const char gszUnknownUpper_006CCED8[];                                                           // 0x006CCED8

// 0x00407A80
bool crashy::Report::sub_00407A80_WriteInspectorHeader()
{
    if (!sub_00401210_IsOpen())
    {
        return false;
    }

    sub_00401380("<Application>%s\n", gtInspectorInfo_0074D868.szApplication);
    sub_00401380("<Inspector.ProjectId>%d\n", gtInspectorInfo_0074D868.f_0);
    sub_00401380("<Inspector.Module>%s\n", gtInspectorInfo_0074D868.szModule);
    sub_00401380("<Inspector.Milestone>%s\n", gtInspectorInfo_0074D868.szMilestone);
    sub_00401380("<Inspector.BuildNumber>%s\n", gtInspectorInfo_0074D868.szBuildNumber);
    sub_00401380("<Inspector.Platform>%s\n", gtInspectorInfo_0074D868.f_18);
    sub_00401380("<Inspector.IssueType>%s\n", "Exception");
    sub_00401380("<Inspector.Priority>%s\n", "1 - Critical");
    sub_00401380("<Inspector.PrimaryAssignment>%s\n", gtInspectorInfo_0074D868.szPrimaryAssignment);
    sub_00401380("<Inspector.Assignments>%s\n", gtInspectorInfo_0074D868.szAssignments);

    int bIsAdmin = 0;
    D2SidAuthorityStrc tNtAuthority = { { 0, 0, 0, 0, 0, 5 } };
    void* pSid;
    if (AllocateAndInitializeSid(&tNtAuthority, 2, 0x20, 0x220, 0, 0, 0, 0, 0, 0, &pSid))
    {
        bIsAdmin = CheckTokenMembership(0, pSid, &bIsAdmin);
        sub_00401380("<Process.UserIsAdmin> %s\n", bIsAdmin ? "TRUE" : "FALSE");
        FreeSid(pSid);
    }
    sub_00401380("<Process.Elevated> %s\n", gszUnknownUpper_006CCED8);

    unsigned long dwProcessId = GetCurrentProcessId();
    bool bFound = sub_00407A20_GetProcessImageName(dwProcessId, gszProcessPath_0074E8C8, 0x800);
    sub_00401380("<Process.Path> %s\n", bFound ? gszProcessPath_0074E8C8 : "Unknown");
    const char* szSlash = strrchr(gszProcessPath_0074E8C8, '\\');
    const char* szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.Name> %s\n", (szName && bFound) ? szName : "Unknown");

    unsigned long dwParentId = sub_00407990_FindOwnerProcess(dwProcessId);
    bFound = sub_00407A20_GetProcessImageName(dwParentId, gszProcessPath_0074E8C8, 0x800);
    sub_00401380("<Process.ParentProcessPath> %s\n", bFound ? gszProcessPath_0074E8C8 : "Unknown");
    szSlash = strrchr(gszProcessPath_0074E8C8, '\\');
    szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.ParentProcessName> %s\n", (szName && bFound) ? szName : "Unknown");

    unsigned long dwGrandParentId = sub_00407990_FindOwnerProcess(dwParentId);
    bFound = sub_00407A20_GetProcessImageName(dwGrandParentId, gszProcessPath_0074E8C8, 0x800);
    sub_00401380("<Process.GrandParentProcessPath> %s\n", bFound ? gszProcessPath_0074E8C8 : "Unknown");
    szSlash = strrchr(gszProcessPath_0074E8C8, '\\');
    szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.GrandParentProcessName> %s\n", (szName && bFound) ? szName : "Unknown");

    sub_00401380("<Locale.Game> %s\n", gaszLanguageNames_00706618[sub_00525150()]);
    sub_00401380("<Locale.System> %s\n", gaszLanguageNames_00706618[sub_005251C0_GetLanguage()]);
    sub_00401380("<Game.Type> %s\n", "Client");
    sub_00401380("<Game.Build> %s\n", "79b7ae8fe1e97d05d57ebdc4b65bf012d38c797e");

    char* apszFiles[0x15];
    memset(apszFiles, 0, sizeof(apszFiles));
    sub_0040EB90_GetLogFiles(apszFiles, 0x15);
    for (unsigned int i = 0; i < 0x15; ++i)
    {
        if (apszFiles[i] && *apszFiles[i])
        {
            sub_00401220_AddFile(apszFiles[i], true);
        }
    }
    return true;
}

#include "gen/data/Source/Fog/Unknown_00407A80.inc"
