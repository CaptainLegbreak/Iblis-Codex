struct D2ErrorReportStrc;
typedef void (__stdcall* D2ErrorCallback)(D2ErrorReportStrc*);
struct D2ErrorReportStrc
{
    unsigned int error;
    const char* context;
    const char* message;
    D2ErrorCallback callback;
};
extern const char* gszErrorDefaults_006FCC24[]; // 0x006FCC24
extern const char gszPercentS_006FFC58[]; // 0x006FFC58
extern const char gszNewline_006FFCB0[]; // 0x006FFCB0
void* __stdcall sub_0041BEF0_GetModule(); // 0x0041BEF0
unsigned int __stdcall SStrCopy(char*, const char*, unsigned int); // 0x004135D0
unsigned int __stdcall sub_00413800(char*, const char*, unsigned int); // 0x00413800
void __stdcall SErrSetLastError(unsigned int); // 0x0041C340
extern "C" char* __cdecl strstr(const char*, const char*);
extern "C" __declspec(dllimport) int __stdcall LoadStringA(void*, unsigned int, char*, int);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...);

static __declspec(noinline) void __stdcall sub_006C3E10_ReportCommandError(D2ErrorCallback callback, unsigned int error, const char* context);

// 0x006C3E10
static void __stdcall sub_006C3E10_ReportCommandError(D2ErrorCallback callback, unsigned int error, const char* context)
{
    D2ErrorReportStrc report;
    report.callback = callback;
    char format[256];
    char message[256];
    int index;
    unsigned int resource;
    switch (error)
    {
    case 0x85100065:
        index = 0;
        resource = 0x5201;
        break;
    case 0x8510006D:
        index = 1;
        resource = 0x5202;
        break;
    case 110:
        index = 2;
        resource = 0x5203;
        break;
    default:
        return;
    }
    format[0] = 0;
    LoadStringA(sub_0041BEF0_GetModule(), resource, format, 256);
    if (!format[0])
        SStrCopy(format, gszErrorDefaults_006FCC24[index], 256);
    if (strstr(format, gszPercentS_006FFC58))
        wsprintfA(message, format, context);
    else
        SStrCopy(message, format, 256);
    if (message[0])
        sub_00413800(message, gszNewline_006FFCB0, 256);
    SErrSetLastError(error);
    report.error = error;
    report.context = context;
    report.message = message;
    report.callback(&report);
}

struct D2CmdNodeStrc
{
    int unk0x00;
    D2CmdNodeStrc* pNext;
    unsigned int dwFlags;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern const char gszCmdSeparators_006FCC4C[];                                                              // 0x006FCC4C
extern D2CmdNodeStrc* gpCmdList_0074C494;                                                                   // 0x0074C494
void __stdcall SStrTokenize(char** ppString, char* pBuffer, unsigned int nBufferSize, const char* szSeparators, int* pbQuoted); // 0x00413B80
void __stdcall SMemZero(void* pDst, unsigned int nSize);                                                    // 0x0041D300
int __fastcall sub_006C4EC0_ParseCommandText(char** ppCursor, unsigned char* pState, D2CmdNodeStrc** ppCmd, void* pfnExtra, D2ErrorCallback pfnError); // 0x006C4EC0

static __forceinline D2CmdNodeStrc* CMD_LinkOrNull(D2CmdNodeStrc* pNode)
{
    return (int)pNode > 0 ? pNode : 0;
}

// 0x006C4FB0
int __stdcall SCmdProcess(char* szCommandLine, int bSkipFirst, void* pfnExtra, D2ErrorCallback pfnError)
{
    int nValid = -1;
    nValid &= szCommandLine ? -1 : 0;
    if (!nValid)
    {
        SErrSetLastError(0x57);
        return 0;
    }

    if (bSkipFirst)
    {
        SStrTokenize(&szCommandLine, 0, 0, gszCmdSeparators_006FCC4C, 0);
    }

    unsigned char aState[0x18];
    SMemZero(aState, sizeof(aState));
    D2CmdNodeStrc* pCmd = CMD_LinkOrNull(gpCmdList_0074C494);
    if (!sub_006C4EC0_ParseCommandText(&szCommandLine, aState, &pCmd, pfnExtra, pfnError))
    {
        return 0;
    }

    int bResult = 1;
    while (pCmd && bResult)
    {
        if ((pCmd->dwFlags & 0x3000000) == 0x2000000)
        {
            bResult = 0;
        }
        else if ((int)pCmd->pNext > 0)
        {
            pCmd = pCmd->pNext;
        }
        else
        {
            pCmd = 0;
        }
    }

    if (pfnError && !bResult)
    {
        sub_006C3E10_ReportCommandError(pfnError, 0x8510006D, &gszEmptyAssertText);
    }

    return nValid ? bResult : 0;
}

void __fastcall EmitCommandError(D2ErrorCallback callback, unsigned int error, const char* context)
{
    sub_006C3E10_ReportCommandError(callback, error + 1, context + 1);
}
