#include "D2StormLink.h"

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* process, unsigned int exitCode); // 0x006CC274


// 0x005173DF
void __cdecl sub_005173DF_TerminateCurrentProcess()
{
    TerminateProcess(GetCurrentProcess(), (unsigned int)-1);
}

// 0x005174AA
int D2StormLinkStrc::sub_005174AA_Next()
{
    int nNext = (int)m_next;
    if (nNext <= 0)
    {
        nNext = 0;
    }
    return nNext;
}

// 0x005174B4
int D2StormLinkStrc::sub_005174B4_RawNext()
{
    return (int)m_next;
}
