struct D2StatusStrc
{
    int nCode;
    int nArg;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x10];
    int (__fastcall* pfnSlot10)();
    char unk0x14[0x14];
    int (__fastcall* pfnSlot28)(D2StatusStrc* pStatus);
    char unk0x2C[0x1C];
    int (__fastcall* pfnSlot48)(int* pValue);
    int (__fastcall* pfnSlot4C)();
    char unk0x50[0x18];
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x2C];
    int (__fastcall* pfnSlot98)();
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode);    // 0x006CC274

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __cdecl sub_0042F880();                                                                                // 0x0042F880
void __cdecl sub_0042F890();                                                                                // 0x0042F890
void __cdecl sub_0042FA20();                                                                                // 0x0042FA20
int __cdecl sub_0042FA30();                                                                                 // 0x0042FA30
void __cdecl sub_004336C0();                                                                                // 0x004336C0
int __stdcall sub_004374F0_ConnectCallback(int nArg);                                                       // 0x004374F0
void __cdecl sub_00437550();                                                                                // 0x00437550
int __stdcall sub_0043B850_LogonCallback(int nArg);                                                         // 0x0043B850
int __fastcall sub_0043B9F0_HandleStatus(D2StatusStrc* pStatus);                                            // 0x0043B9F0
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
void __cdecl D2Win_CloseSpriteCache();                                                                      // 0x004F9030
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
void __stdcall sub_00517ED0(int nValue);                                                                    // 0x00517ED0

extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gdwGlobal_007795F4;                                                                              // 0x007795F4
extern int gdwGlobal_00779DA4;                                                                              // 0x00779DA4
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern int gdwGlobal_0077AC04;                                                                              // 0x0077AC04
extern int gdwGlobal_0077AC08;                                                                              // 0x0077AC08
static int s_bConnecting_0077AC0C;                                                                          // 0x0077AC0C

// 0x0043BF60
int __cdecl sub_0043BF60()
{
    if (!gpFuncTable_0077ABF0)
    {
        return 0;
    }

    D2_ASSERT(!s_bConnecting_0077AC0C, 296);
    s_bConnecting_0077AC0C = 1;
    gdwGlobal_00779DA4 = 1;
    sub_0042FA20();
    OutputDebugStringA("------------------\nConnect to Battle.net\n------------------\n");
    D2MCPClientCloseMCP();

    if (!gpFuncTable_0077ABF0->pfnSlot10())
    {
        D2StatusStrc tStatus;
        s_bConnecting_0077AC0C = 0;
        tStatus.nCode = 0;
        tStatus.nArg = 0;
        return sub_0043B9F0_HandleStatus(&tStatus);
    }

    gdwGlobal_0077AC08 = 0;
    sub_00437550();
    sub_004FA590_RunLoop(sub_004374F0_ConnectCallback);

    if (gdwGlobal_0077AC04)
    {
        gdwGlobal_007795F4 = 1;
        sub_0042F880();
        gpFuncTable_0077ABF0->pfnSlot10();
        s_bConnecting_0077AC0C = 0;
        return 0;
    }

    if (gpFuncTable_0077ABF0->pfnSlot4C() != 0x66)
    {
        sub_0042F890();
        sub_004FA590_RunLoop(sub_0043B850_LogonCallback);

        if (!sub_0042FA30() && gpFuncTable_0077ABF0->pfnSlot4C() == 0x65)
        {
            int nValue = 0;
            const int nResult = gpFuncTable_0077ABF0->pfnSlot48(&nValue);
            if (nValue)
            {
                int bSkipToOpen = 0;
                if (gnLaunchMode_007795EC == 3)
                {
                    bSkipToOpen = 1;
                }
                SRegSaveValue("Diablo II", "UseCmdLine", 0, 1);
                SRegSaveValue("Diablo II", "Skip To Open", 0, bSkipToOpen);
                D2Win_CloseSpriteCache();
                gpFuncTable_0077ABF0->pfnSlot10();
                s_bConnecting_0077AC0C = 0;
                sub_00517ED0(gpFuncTable_0077ABF0->pfnSlot98());
                TerminateProcess(GetCurrentProcess(), 0);
                return 0;
            }

            if (!nResult)
            {
                D2StatusStrc tStatus;
                s_bConnecting_0077AC0C = 0;
                tStatus.nCode = 0x12;
                tStatus.nArg = 0;
                return sub_0043B9F0_HandleStatus(&tStatus);
            }
        }
        else
        {
            gpFuncTable_0077ABF0->pfnSlot10();
            s_bConnecting_0077AC0C = 0;
            sub_004336C0();
            return 0;
        }
    }

    sub_0042F880();
    D2StatusStrc tResult;
    gpFuncTable_0077ABF0->pfnSlot28(&tResult);
    s_bConnecting_0077AC0C = 0;
    if (tResult.nCode)
    {
        return sub_0043B9F0_HandleStatus(&tResult);
    }

    return gpFuncTable_0077ABF0->pfnSlot68() != 0;
}
