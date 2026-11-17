struct _iobuf;
struct D2ThreadContextStrc;

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

struct D2CrashSubmitInfoStrc
{
    const char* szName;
    int nUnk04;
    int nUnk08;
    unsigned int dwFlags;
    const char* apszLines[16];
    int nLines;
};

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool sub_00401100_Open(const char* szFileName);                         // 0x00401100
    bool sub_004011F0_Close();                                              // 0x004011F0
    bool sub_00401220_AddFile(const char* szPath, bool bFlag);              // 0x00401220
    int sub_00401380(const char* szFormat, ...);                                  // 0x00401380
    bool sub_00407A80_WriteInspectorHeader();                               // 0x00407A80

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[16][0x400];
};
}

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __fastcall sub_00403070_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, int nArg5, int nArg6, int nArg7); // 0x00403070
void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext); // 0x004032F0
void __fastcall sub_00403A20_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId); // 0x00403A20
void __fastcall sub_00407980_ReportPrint(void* pContext, const char* szText);                               // 0x00407980
bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo);                // 0x00401790

extern long volatile gnReportBusy_007076BC;                                                                 // 0x007076BC
int gdwGlobal_0074F0C8;                                                                                     // 0x0074F0C8
extern D2InspectorInfoStrc gtInspectorInfo_0074D868;                                                       // 0x0074D868

// 0x00408660
bool __fastcall sub_00408660_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag)
{
    crashy::Report tReport;
    const long nBusy = InterlockedIncrement(&gnReportBusy_007076BC);
    if (nBusy != 0)
    {
        gdwGlobal_0074F0C8 = 0;
        InterlockedDecrement(&gnReportBusy_007076BC);
        return false;
    }

    gdwGlobal_0074F0C8 = 1;
    if (!tReport.sub_00401100_Open("Crash.txt"))
    {
        gdwGlobal_0074F0C8 = 0;
        InterlockedDecrement(&gnReportBusy_007076BC);
        return false;
    }

    tReport.sub_00407A80_WriteInspectorHeader();
    tReport.sub_00401380("<Inspector.Summary:>\n%s\n<:Inspector.Summary>\n", szSummary);
    if (nLine > 0)
    {
        tReport.sub_00401380("<Inspector.LineNumber>%u\n", nLine);
    }
    tReport.sub_00401380("<Inspector.Assertion:>\n");
    const unsigned long dwThreadId = GetCurrentThreadId();
    sub_00403070_DumpThread(dwThreadId, 0, sub_00407980_ReportPrint, &tReport, nBusy, 1, 4);
    tReport.sub_00401380("<:Inspector.Assertion>\n");
    tReport.sub_00401380("Registers:\n");
    sub_004032F0_DumpRegisters(dwThreadId, sub_00407980_ReportPrint, &tReport);
    tReport.sub_00401380("Threads:\n");
    sub_00403A20_DumpOtherThreads(sub_00407980_ReportPrint, &tReport, dwThreadId);

    const char** ppszEnd = ppszFiles + nFiles;
    for (const char** ppszFile = ppszFiles; ppszFile != ppszEnd; ++ppszFile)
    {
        tReport.sub_00401220_AddFile(*ppszFile, true);
    }
    tReport.sub_004011F0_Close();

    D2CrashSubmitInfoStrc tInfo;
    memset(&tInfo, 0, sizeof(tInfo));
    tInfo.szName = gtInspectorInfo_0074D868.szUnused04;
    if (bFlag)
    {
        tInfo.dwFlags |= 1;
    }
    for (int i = 0; i < tReport.m_nLineCount; i++)
    {
        if (i < sizeof(tInfo.apszLines) / sizeof(tInfo.apszLines[0]))
        {
            tInfo.apszLines[i] = tReport.m_aszLines[i];
            tInfo.nLines++;
        }
    }

    const bool bResult = sub_00401790_SubmitReport(tReport.m_szText08, &tInfo);
    gdwGlobal_0074F0C8 = 0;
    InterlockedDecrement(&gnReportBusy_007076BC);
    return bResult;
}

#include "gen/data/Source/Storm/00408660_sub_00408660_ShowErrorReport.inc"
