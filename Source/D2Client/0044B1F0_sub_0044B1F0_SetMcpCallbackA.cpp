extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef void (__fastcall* D2McpCallbackFn)(unsigned short wRequestId, unsigned char* pData);

struct D2RangeStrc
{
    int nStart;
    int nLength;
};

extern "C" __declspec(dllimport) int __stdcall SendMessageA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC49C
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __stdcall WINDOW_ShowAll();                                                                            // 0x004F5F60
int __stdcall GAME_Initialize();                                                                            // 0x00530690
void __stdcall CLIENT_Initialize(int nArg, const char* szAddress);                                          // 0x0052A750
int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0
int __stdcall sub_0044BBB0_WaitConnect(int nUnused);                                                        // 0x0044BBB0

extern D2McpCallbackFn gpfnMcpCallback_007992F8;                                                            // 0x007992F8
extern D2McpCallbackFn gpfnMcpCallback_007992FC;                                                            // 0x007992FC
int gaValues_007A0424[1];                                                                                   // 0x007A0424
int gnValueCount_007A044C;                                                                                  // 0x007A044C
extern int gnLaunchState_0070EE4C;                                                                          // 0x0070EE4C
extern "C" int gnSubsystemActive_007A0458;                                                                  // 0x007A0458

// 0x0044B1F0
void __fastcall sub_0044B1F0_SetMcpCallbackA(D2McpCallbackFn pfnCallback)
{
    gpfnMcpCallback_007992F8 = pfnCallback;
}

// 0x0044B200
void __fastcall sub_0044B200_SetMcpCallbackB(D2McpCallbackFn pfnCallback)
{
    gpfnMcpCallback_007992FC = pfnCallback;
}

// 0x0044B480
int __cdecl sub_0044B480_PopValue()
{
    D2_ASSERT(gnValueCount_007A044C, 0xB4);
    int nValue = gaValues_007A0424[0];
    --gnValueCount_007A044C;
    for (int i = 0; i < 3; ++i)
        gaValues_007A0424[i] = gaValues_007A0424[i + 1];
    return nValue;
}

// 0x0044B780
void __cdecl sub_0044B780_RaiseGameWindow()
{
    void* hWnd = (void*)sub_004F59A0();
    if (hWnd)
        SendMessageA(hWnd, 0x1C, 0, 0);
    WINDOW_ShowAll();
}

// 0x0044B870
void __cdecl sub_0044B870_SetLaunchState1()
{
    gnLaunchState_0070EE4C = 1;
}

// 0x0044BB70
int __stdcall sub_0044BB70_StartGame()
{
    gnSubsystemActive_007A0458 = 1;
    return GAME_Initialize();
}

// 0x0044BC10
int __fastcall sub_0044BC10_RunClient(int nArg, const char* szAddress)
{
    CLIENT_Initialize(nArg, szAddress);
    sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
    return 1;
}

// 0x0044BE10
int __fastcall sub_0044BE10_GetRangeEnd(D2RangeStrc* pRange)
{
    return pRange->nLength + pRange->nStart;
}
