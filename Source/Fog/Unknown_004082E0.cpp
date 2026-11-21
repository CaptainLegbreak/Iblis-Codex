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

extern long volatile gnReportBusy_007076B8;                                                                 // 0x007076B8
extern int gdwGlobal_0074F0C8;                                                                              // 0x0074F0C8
extern D2InspectorInfoStrc gtInspectorInfo_0074D868;                                                       // 0x0074D868

extern "C" const char gszCrashFile_006CD1C0[];                                                              // 0x006CD1C0
extern "C" const char gszFmtSummary_006CD1E8[];                                                             // 0x006CD1E8
extern "C" const char gszFmtLineNumber_006CD1CC[];                                                          // 0x006CD1CC
extern "C" const char gszAssertionBegin_006CD170[];                                                         // 0x006CD170
extern "C" const char gszAssertionEnd_006CD158[];                                                           // 0x006CD158
extern "C" const char gszRegisters_006CD14C[];                                                              // 0x006CD14C
extern "C" const char gszThreads_006CD140[];                                                                // 0x006CD140

struct D2StackFrameStrc;
struct D2ExceptionPointersStrc { void* pRecord; D2ThreadContextStrc* pContext; };
struct D2CrashInputStrc
{
    const char* szSummary;
    const char* szDetail;
    D2StackFrameStrc* pFrames;
    int nFrames;
    int nSkip;
    unsigned long dwThreadId;
    D2ExceptionPointersStrc* pException;
};
void __fastcall sub_00403100_PrintFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, unsigned int nFrames, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader); // 0x00403100
void __fastcall sub_00402EE0_DumpModules(D2CrashPrintFn pfnPrint,void* pContext); // 0x00402EE0
unsigned long __cdecl sub_00401690_GetCurrentThreadId(); // 0x00401690
void __fastcall sub_004013C0_TerminateCurrentProcess(unsigned int nCode); // 0x004013C0
bool __fastcall sub_00402820_WriteMiniDump(const char* szPath,const char* szComment,void* pExceptionPointers,unsigned long dwThreadId); // 0x00402820
unsigned int __stdcall SStrCopy(char* szDest,const char* szSource,unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest,const char* szSource,unsigned int nDestSize); // 0x00413800
extern char gszProcessPath_0074E8C8[0x800]; // 0x0074E8C8
extern const char gszEmptyAssertText; // 0x006CC837
extern const char gszCrashSummary_006CD1A8[]; // 0x006CD1A8
extern const char gszCrashDetail_006CD1A0[]; // 0x006CD1A0
extern const char gszCrashNewline_006CD188[]; // 0x006CD188
extern const char gszModules_006CD124[]; // 0x006CD124
extern const char gszMore1_006CD108[]; // 0x006CD108
extern const char gszMore2_006CD0F0[]; // 0x006CD0F0
extern const char gszMore3_006CD0D4[]; // 0x006CD0D4
extern const char gszMore4_006CD0C4[]; // 0x006CD0C4
extern const char gszMinidump_006CD0B4[]; // 0x006CD0B4
extern const char gszMore5_006CD09C[]; // 0x006CD09C

// 0x004082E0
int __fastcall sub_004082E0_CrashHandler(D2CrashInputStrc* pInput)
{
    D2ThreadContextStrc* pThread = pInput->pException->pContext;
    const long nBusy = InterlockedIncrement(&gnReportBusy_007076B8);
    if (nBusy == 0)
    {
        gdwGlobal_0074F0C8 = 1;
        crashy::Report report;
        if (!report.sub_00401100_Open(gszCrashFile_006CD1C0))
        {
            gdwGlobal_0074F0C8 = 0;
        }
        else
        {
            report.sub_00407A80_WriteInspectorHeader();
            report.sub_00401380(gszCrashSummary_006CD1A8,pInput->szSummary);
            if (pInput->szDetail[0]) report.sub_00401380(gszCrashDetail_006CD1A0,pInput->szDetail);
            report.sub_00401380(gszCrashNewline_006CD188);
            report.sub_00401380(gszAssertionBegin_006CD170);
            int nSkip = 0;
            if (!pThread && !pInput->pFrames)
            {
                nSkip = pInput->nSkip;
                if (pInput->dwThreadId == sub_00401690_GetCurrentThreadId()) nSkip += 2;
            }
            if (pInput->pFrames)
                sub_00403100_PrintFrames(pInput->dwThreadId,pInput->pFrames,pInput->nFrames,sub_00407980_ReportPrint,&report,0,1);
            else
                sub_00403070_DumpThread(pInput->dwThreadId,pThread,sub_00407980_ReportPrint,&report,0,1,nSkip);
            report.sub_00401380(gszAssertionEnd_006CD158);
            report.sub_00401380(gszRegisters_006CD14C);
            sub_004032F0_DumpRegisters(pInput->dwThreadId,sub_00407980_ReportPrint,&report);
            report.sub_00401380(gszThreads_006CD140);
            sub_00403A20_DumpOtherThreads(sub_00407980_ReportPrint,&report,pInput->dwThreadId);
            report.sub_00401380(gszModules_006CD124);
            sub_00402EE0_DumpModules(sub_00407980_ReportPrint,&report);
            report.sub_00401380(gszMore1_006CD108);
            report.sub_00401380(gszMore2_006CD0F0);
            report.sub_00401380(gszMore3_006CD0D4);
            if (pInput->pFrames)
                sub_00403100_PrintFrames(pInput->dwThreadId,pInput->pFrames,pInput->nFrames,sub_00407980_ReportPrint,&report,0,0);
            else
                sub_00403070_DumpThread(pInput->dwThreadId,pThread,sub_00407980_ReportPrint,&report,0,0,nSkip);
            report.sub_00401380(gszMore4_006CD0C4);
            SStrCopy(gszProcessPath_0074E8C8,report.m_szText408,0x800);
            sub_00413800(gszProcessPath_0074E8C8,gszMinidump_006CD0B4,0x800);
            if (sub_00402820_WriteMiniDump(gszProcessPath_0074E8C8,&gszEmptyAssertText,pInput->pException,0))
                report.sub_00401220_AddFile(gszProcessPath_0074E8C8,false);
            report.sub_00401380(gszMore5_006CD09C);
            report.sub_004011F0_Close();
            D2CrashSubmitInfoStrc info;
            memset(&info,0,sizeof(info));
            info.szName=gtInspectorInfo_0074D868.szUnused04;
            for (int i=0;i<report.m_nLineCount;++i)
            {
                if (i < sizeof(info.apszLines)/sizeof(info.apszLines[0]))
                {
                    info.apszLines[i]=report.m_aszLines[i];
                    ++info.nLines;
                }
            }
            sub_00401790_SubmitReport(report.m_szText08,&info);
            gdwGlobal_0074F0C8=0;
        }
        InterlockedDecrement(&gnReportBusy_007076B8);
        sub_004013C0_TerminateCurrentProcess(-1);
    }
    return 2;
}

#include "gen/data/Source/Fog/Unknown_004082E0.inc"
