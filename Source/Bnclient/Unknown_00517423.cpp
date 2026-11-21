#include "Bnclient.h"
#include "D2StormLink.h"

#define D2_IMPORT __declspec(dllimport)

extern "C" D2_IMPORT int __stdcall MessageBoxA(void* window, const char* text, const char* caption, unsigned int flags);
extern "C" D2_IMPORT int __cdecl wsprintfA(char* buffer, const char* format, ...);

typedef void (__stdcall* FaultAssertHandler)(const char*, unsigned int, const char*);

extern FaultAssertHandler sgpfnAssertHandler; // 0x00881834
extern const char* const gpszModuleName; // 0x006CC848
extern const char sgszAssertFormatString[]; // 0x006DEBE8
void __cdecl sub_005173DF_TerminateCurrentProcess(); // 0x005173DF
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

// 0x00517423
int __fastcall FaultDoAssert(const char* a1, unsigned int a2, const char* a3)
{
    char Text[512];

    if (sgpfnAssertHandler)
        sgpfnAssertHandler(a1, a2, a3);
    wsprintfA(Text, sgszAssertFormatString, a1, a2, a3);
    const int buttonID = MessageBoxA(0, Text, gpszModuleName, 0x52212);
    if (buttonID == 3) {
        sub_005173DF_TerminateCurrentProcess();
        return 1;
    }
    return buttonID == 4;
}

#include "gen/data/Source/Bnclient/Unknown_00517423.inc"

// 0x005174B8
void D2StormLinkStrc::sub_005174B8_Clear()
{
    m_prevlink = 0;
    m_next = 0;
}
