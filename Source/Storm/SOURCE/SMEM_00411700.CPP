#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"

struct T004013C0
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};

extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo); // 0x006CC1F0
extern int gnFlag3_007788CC; // 0x007788CC

extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030

enum { NO_NODE = 0 };

unsigned int gnPageSize_00776CB8; // 0x00776CB8
int gnFlag0_007784C4; // 0x007784C4
int gnFlag2_00776CBC; // 0x00776CBC
int gnFlag1_007784C0; // 0x007784C0

// 0x00411700
int __stdcall sub_00411700_ToByte(unsigned char nValue)
{
    return nValue;
}

// 0x00411A20
void __cdecl sub_00411A20_InitPageSize()
{
    T004013C0 systemInfo;
    GetSystemInfo(&systemInfo);
    gnPageSize_00776CB8 = 1;
    while (gnPageSize_00776CB8 < systemInfo.dwPageSize)
        gnPageSize_00776CB8 *= 2;
}

// 0x00411D40
void __stdcall sub_00411D40_SetFlags(unsigned int dwValues, unsigned int dwMask)
{
    if (dwMask & 1)
        gnFlag0_007784C4 = dwValues & 1;
    if (dwMask & 8)
        gnFlag3_007788CC = (dwValues >> 3) & 1;
    if (dwMask & 4)
        gnFlag2_00776CBC = (dwValues >> 2) & 1;
    if (dwMask & 2)
        gnFlag1_007784C0 = (dwValues >> 1) & 1;
}
