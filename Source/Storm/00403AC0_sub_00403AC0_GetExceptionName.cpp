typedef unsigned int size_t;

struct D2ExceptionRecordStrc
{
    unsigned long ExceptionCode;
};

struct D2ExceptionPointersStrc
{
    D2ExceptionRecordStrc* ExceptionRecord;
    void* ContextRecord;
};

struct T00403AC0
{
    const char* szName;
    char* szText;
    int nUnk08;
    int nUnk0C;
    int nUnk10;
    unsigned long dwThreadId;
    D2ExceptionPointersStrc* pPointers;
    char szBuffer[0x200];
};

typedef int (__fastcall* D2CrashHandlerFn)(T00403AC0* pReport, void* pContext);

extern "C" int __cdecl strncpy_s(char* szDest, size_t nDestSize, const char* szSource, size_t nCount);      // 0x006859D2
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);                // 0x006CC198
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long dwFlags, const void* pSource, unsigned long dwMessageId, unsigned long dwLanguageId, char* pBuffer, unsigned long nSize, void* pArguments); // 0x006CC2B0
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
D2CrashHandlerFn gpfnCrashHandler_00992B10;                                                                 // 0x00992B10
extern void* gpCrashContext_00992B14;                                                                       // 0x00992B14

// 0x00403AC0
static void sub_00403AC0_GetExceptionName(char* szBuffer, unsigned long dwCode)
{
    const char* szName;
    switch (dwCode)
    {
    case 0xC0000005: szName = "ACCESS_VIOLATION"; break;
    case 0x80000002: szName = "DATATYPE_MISALIGNMENT"; break;
    case 0x80000003: szName = "BREAKPOINT"; break;
    case 0x80000004: szName = "SINGLE_STEP"; break;
    case 0xC000008C: szName = "ARRAY_BOUNDS_EXCEEDED"; break;
    case 0xC000008D: szName = "FLT_DENORMAL_OPERAND"; break;
    case 0xC000008E: szName = "FLT_DIVIDE_BY_ZERO"; break;
    case 0xC000008F: szName = "FLT_INEXACT_RESULT"; break;
    case 0xC0000090: szName = "FLT_INVALID_OPERATION"; break;
    case 0xC0000091: szName = "FLT_OVERFLOW"; break;
    case 0xC0000092: szName = "FLT_STACK_CHECK"; break;
    case 0xC0000093: szName = "FLT_UNDERFLOW"; break;
    case 0xC0000094: szName = "INT_DIVIDE_BY_ZERO"; break;
    case 0xC0000095: szName = "INT_OVERFLOW"; break;
    case 0xC0000096: szName = "PRIV_INSTRUCTION"; break;
    case 0xC0000006: szName = "IN_PAGE_ERROR"; break;
    case 0xC000001D: szName = "ILLEGAL_INSTRUCTION"; break;
    case 0xC0000025: szName = "NONCONTINUABLE_EXCEPTION"; break;
    case 0xC00000FD: szName = "STACK_OVERFLOW"; break;
    case 0xC0000026: szName = "INVALID_DISPOSITION"; break;
    case 0x80000001: szName = "GUARD_PAGE"; break;
    case 0xC0000008: szName = "INVALID_HANDLE"; break;
    default:
    {
        void* hNtdll = GetModuleHandleA("ntdll.dll");
        if (!hNtdll || FormatMessageA(0xA00, hNtdll, dwCode, 0x400, szBuffer, 0x100, 0) <= 0)
        {
            strncpy_s(szBuffer, 0x100, "unknown exception", -1);
        }
        return;
    }
    }
    strncpy_s(szBuffer, 0x100, szName, -1);
}

// 0x00403E90
long __stdcall sub_00403E90_UnhandledExceptionFilter(void* pExceptionPointers)
{
    if (!gpfnCrashHandler_00992B10)
        return 0;
    D2ExceptionPointersStrc* pPointers = (D2ExceptionPointersStrc*)pExceptionPointers;
    char szName[0x100];
    sub_00403AC0_GetExceptionName(szName, pPointers->ExceptionRecord->ExceptionCode);
    T00403AC0 tReport;
    tReport.szBuffer[0] = 0;
    tReport.szName = szName;
    tReport.szText = tReport.szBuffer;
    tReport.dwThreadId = GetCurrentThreadId();
    tReport.pPointers = pPointers;
    tReport.nUnk08 = 0;
    tReport.nUnk0C = 0;
    tReport.nUnk10 = 0;
    const int nResult = gpfnCrashHandler_00992B10(&tReport, gpCrashContext_00992B14);
    if (!nResult)
        return 0;
    return nResult == 1 ? -1 : 1;
}
