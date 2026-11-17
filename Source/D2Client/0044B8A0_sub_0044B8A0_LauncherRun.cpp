extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

struct D2PoolSystemStrc;

struct D2ClientCharRecordStrc
{
    char unk0x00[0x19];
    char aState[4];
    char unk0x1D[2];
    char szName[0x1D0];
};

void __cdecl sub_00409B80(int nArg);                                                                        // 0x00409B80
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc);                     // 0x00409FF0
int __stdcall sub_0044B6B0(D2ClientCharRecordStrc* pRecord);                                                // 0x0044B6B0
int __cdecl sub_00451330();                                                                                 // 0x00451330
void __cdecl sub_004F8FE0();                                                                                // 0x004F8FE0
int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc);                                                      // 0x004F8FC0
int __stdcall sub_00451B30_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam);   // 0x00451B30
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void* __stdcall sub_004FAC80(int nArg);                                                                     // 0x004FAC80
int __fastcall sub_005259C0(void* pArg, int nArg);                                                          // 0x005259C0
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
void __stdcall sub_00619300(void* pArg, int bArg);                                                          // 0x00619300
void __cdecl sub_004FA550();                                                                                // 0x004FA550
void __cdecl sub_00619140();                                                                                // 0x00619140
void __cdecl sub_00524E40();                                                                                // 0x00524E40
void __cdecl sub_00451290();                                                                                // 0x00451290
void __cdecl sub_006116B0_WriteProfileCounters();                                                                    // 0x006116B0
void __cdecl sub_0044BB80();                                                                                // 0x0044BB80

extern D2ClientCharRecordStrc* gpCharRecord_007A0438;                                                       // 0x007A0438
void* ghInstance_007A043C;                                                                                  // 0x007A043C
char gszModulePath_007A0320[260];                                                                           // 0x007A0320
extern int gnLaunchState_0070EE4C;                                                                          // 0x0070EE4C
extern int gdwGlobal_0070EE8C;                                                                              // 0x0070EE8C
extern int (__cdecl* gpfnLaunchStates_0070EE54[])();                                                        // 0x0070EE54
int gnLaunchResult_007A0440;                                                                                // 0x007A0440

// 0x0044B8A0
int __stdcall sub_0044B8A0_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord)
{
    gpCharRecord_007A0438 = pRecord;
    sub_00409B80(0);
    FOG_SetMemoryPoolSystemMode(0, 1);
    ghInstance_007A043C = hInstance;
    GetModuleFileNameA(hInstance, gszModulePath_007A0320, 0x104);
    if (!sub_0044B6B0(pRecord))
        return 0;
    if (!sub_00451330())
        return 0;
    sub_004F8FE0();
    D2Win_10014_SetWndProc((WNDPROC)sub_00451B30_WindowProc);
    if (!sub_005259C0(sub_004FAC80(sub_00408F20_HasExpansionMpq()), 0))
        return 0;
    int nLanguage;
    sub_00525260(&nLanguage, 0);
    sub_00619300(sub_004FAC80(0), *(int*)pRecord->aState == 6);
    gnLaunchState_0070EE4C = 3;
    gdwGlobal_0070EE8C = 1;
    while (gnLaunchState_0070EE4C != 1)
    {
        gnLaunchState_0070EE4C = gpfnLaunchStates_0070EE54[gnLaunchState_0070EE4C]();
        D2_ASSERT(gnLaunchState_0070EE4C < 7, 0x28E);
        D2_ASSERT(gnLaunchState_0070EE4C > 0, 0x28F);
    }
    sub_004FA550();
    sub_00619140();
    sub_00524E40();
    sub_00451290();
    sub_006116B0_WriteProfileCounters();
    sub_0044BB80();
    int nResult;
    if (gdwGlobal_0070EE8C)
    {
        nResult = 0;
    }
    else
    {
        switch (*(int*)pRecord->aState)
        {
        case 0:
        case 8:
        case 9:
            nResult = 4;
            break;
        case 2:
        case 3:
        case 6:
        case 7:
            nResult = 3;
            break;
        default:
            gnLaunchResult_007A0440 = 4;
            return 4;
        }
    }
    gnLaunchResult_007A0440 = nResult;
    return nResult;
}

#include "gen/data/Source/D2Client/0044B8A0_sub_0044B8A0_LauncherRun.inc"
