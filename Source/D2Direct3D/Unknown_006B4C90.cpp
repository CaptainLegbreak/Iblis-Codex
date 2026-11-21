#include "D2Direct3D.h"
#include "D2Win32Types.h"

typedef void* HINSTANCE;
typedef void* HWND;
typedef void* HMENU;
typedef void* HICON;
typedef void* HCURSOR;
typedef void* HBRUSH;
typedef void* HGDIOBJ;
typedef long LRESULT;
typedef long HRESULT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef unsigned short ATOM;
typedef LRESULT (__stdcall* WNDPROC)(HWND, unsigned int, WPARAM, LPARAM);

typedef int (__stdcall* LPDDENUMCALLBACKA)(void* pGuid, char* szDescription, char* szName, void* pContext);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) HGDIOBJ __stdcall GetStockObject(int nObject);                             // 0x006CC0E8
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwError);                        // 0x006CC2E4
extern "C" __declspec(dllimport) LRESULT __stdcall DefWindowProcA(HWND hWnd, unsigned int nMsg, WPARAM wParam, LPARAM lParam); // 0x006CC488
extern "C" __declspec(dllimport) int __stdcall UnregisterClassA(const char* szClassName, HINSTANCE hInstance); // 0x006CC4C8
extern "C" __declspec(dllimport) ATOM __stdcall RegisterClassA(const WNDCLASSA* pWndClass);                 // 0x006CC4CC
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(HWND hWnd);                                    // 0x006CC4E0
extern "C" __declspec(dllimport) HWND __stdcall CreateWindowExA(unsigned long dwExStyle, const char* szClassName, const char* szWindowName, unsigned long dwStyle, int nX, int nY, int nWidth, int nHeight, HWND hParent, HMENU hMenu, HINSTANCE hInstance, void* pParam); // 0x006CC4F0
extern "C" HRESULT __stdcall DirectDrawEnumerateA(LPDDENUMCALLBACKA pCallback, void* pContext);             // 0x006C9B82

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...) throw();                                                  // 0x00410610
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...); // 0x0051793E
void __fastcall sub_006B20E0_ReportError(const char* szMessage, long hResult) throw();                      // 0x006B20E0
void __fastcall sub_006B2F60_SaveVideoConfig(int nRender, int nDevice);                                     // 0x006B2F60
int __stdcall sub_006B42F0_DDrawEnumCallback(void* pGuid, char* szDescription, char* szName, void* pContext); // 0x006B42F0

extern char gszEnumerationClass_0074C044[];                                                                 // 0x0074C044
extern char gszEnumerationWindow_0074C058[];                                                                // 0x0074C058
extern HWND ghEnumWindow_00970E84;                                                                          // 0x00970E84
extern int gnD3DDeviceCount_00970E88;                                                                       // 0x00970E88
extern int gnDeviceStatus2_0096F83C;                                                                        // 0x0096F83C
extern int gnDeviceStatus3_0096F95C;                                                                        // 0x0096F95C

struct T004013C0 { int unk00; int mode; };
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __stdcall SRegLoadValue(const char*,const char*,unsigned int,unsigned long*); // 0x00414F10
int __stdcall SRegLoadData(const char*,const char*,unsigned int,void*,unsigned int,unsigned int*); // 0x00414DE0
#pragma pack(push,1)
struct D2VideoKeyStrc { unsigned int words[5]; unsigned short tail; };
#pragma pack(pop)
extern const D2VideoKeyStrc gVideoKey_006DD634; // 0x006DD634
extern int gbConfigured_00970EB8;        // 0x00970EB8
extern int gbSeen_00970EBC;        // 0x00970EBC
extern char gszDevice_0096F3BC[264];     // 0x0096F3BC
extern unsigned long gnFlags_0096F3A8;        // 0x0096F3A8
extern unsigned int gGuid_0096F3AC[4];        // 0x0096F3AC

static int __stdcall sub_006B4C90_DetectDirect3D(HINSTANCE hInstance);

// 0x006B4C90
static int __stdcall sub_006B4C90_DetectDirect3D(HINSTANCE hInstance)
{
    WNDCLASSA wc;

    try
    {
        sub_00410610_WriteLogLine("Detecting boards which support Direct3D...");

        memset(&wc, 0, sizeof(wc));
        gnD3DDeviceCount_00970E88 = 0;
        wc.style = 0;
        wc.lpfnWndProc = DefWindowProcA;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = 0;
        wc.hbrBackground = (HBRUSH)GetStockObject(5);
        wc.lpszMenuName = 0;
        wc.lpszClassName = gszEnumerationClass_0074C044;
        if (!RegisterClassA(&wc))
        {
            sub_0051793E_FormatAndRaise(GetLastError());
            return 0;
        }

        SetLastError(0);
        ghEnumWindow_00970E84 = CreateWindowExA(0x40000, gszEnumerationClass_0074C044, gszEnumerationWindow_0074C058, 0xA0000000, 0, 0, 640, 480, 0, 0, hInstance, 0);
        if (!ghEnumWindow_00970E84)
        {
            sub_00410610_WriteLogLine("***** Failed to create window for D3D enumeration= %d", GetLastError());
            return 0;
        }

        const HRESULT hResult = DirectDrawEnumerateA(sub_006B42F0_DDrawEnumCallback, 0);
        if (hResult)
        {
            sub_006B20E0_ReportError("DirectDrawEnumerate", hResult);
        }
    }
    catch (...)
    {
        sub_00410610_WriteLogLine(" ** Caught a failure in Direct3DDetect ** ");
    }

    try
    {
        if (ghEnumWindow_00970E84)
        {
            DestroyWindow(ghEnumWindow_00970E84);
            sub_00410610_WriteLogLine("Destroyed D3D window.");
        }

        if (!gnD3DDeviceCount_00970E88)
        {
            sub_00410610_WriteLogLine("Found no valid Direct3D devices to use!");
            return 0;
        }
    }
    catch (...)
    {
    }

    UnregisterClassA(gszEnumerationClass_0074C044, hInstance);

    if (gnDeviceStatus2_0096F83C == 2)
    {
        sub_006B2F60_SaveVideoConfig(1, 2);
        return 2;
    }

    if (gnDeviceStatus3_0096F95C == 2)
    {
        sub_006B2F60_SaveVideoConfig(1, 3);
        return 2;
    }

    return 0;
}

// build: context sub_006B4E80_LoadVideoConfiguration
int __fastcall sub_006B4E80_LoadVideoConfiguration(void* window) {
    T004013C0* info=sub_00407360_GetSystemInfo();
    if (!info) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),1032); exit(-1); }
    if (info->mode==1) return 0;
    D2VideoKeyStrc key=gVideoKey_006DD634;
    if (gbSeen_00970EBC && !gbConfigured_00970EB8) {
        sub_006B4C90_DetectDirect3D(window);
        gbConfigured_00970EB8=1;
    }
    gbSeen_00970EBC=1;
    for (;;) {
        if (!SRegLoadString((const char*)&key,"DeviceName",0,gszDevice_0096F3BC,256)) {
            if (gbConfigured_00970EB8) return 0;
            int result=sub_006B4C90_DetectDirect3D(window);
            gbConfigured_00970EB8=1;
            if (result!=2) return 0;
        } else if (!SRegLoadValue((const char*)&key,"dwFlags",0,&gnFlags_0096F3A8)) {
            if (gbConfigured_00970EB8) return 0;
            int result=sub_006B4C90_DetectDirect3D(window);
            gbConfigured_00970EB8=1;
            if (result!=2) return 0;
        } else break;
    }
    if (!(gnFlags_0096F3A8 & gdwBitMasks_006CE268[0])) {
        unsigned int length=16;
        if (!SRegLoadData((const char*)&key,"GUID",0,gGuid_0096F3AC,16,&length) || length!=16) return 0;
    }
    return 1;
}

#include "gen/data/Source/D2Direct3D/Unknown_006B4C90.inc"
