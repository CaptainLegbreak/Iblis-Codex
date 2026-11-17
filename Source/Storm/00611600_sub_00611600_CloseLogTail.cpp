struct D2ProfileCounterStrc
{
    char szName[0x68];
    __int64 nTotal;
    int nCount;
    int f_74;
};

typedef int (__cdecl* PROFHOOK0096BC24FN)();

extern D2ProfileCounterStrc gaProfEntries[23];                                                                   // 0x00743800
PROFHOOK0096BC24FN gpfnHook_0096BC24;                                                                       // 0x0096BC24
void __cdecl sub_006116B0_WriteProfileCounters();                                                                    // 0x006116B0
void __cdecl sub_00624B20_CloseLog();                                                                       // 0x00624B20

// 0x00611600
void __cdecl sub_00611600_CloseLogTail()
{
    sub_00624B20_CloseLog();
}

// 0x00611650
int __cdecl sub_00611650_CallHook0096BC24()
{
    if (gpfnHook_0096BC24)
    {
        return gpfnHook_0096BC24();
    }
    return 0;
}

// 0x00611730
void __cdecl sub_00611730_DumpAndResetProfile()
{
    sub_006116B0_WriteProfileCounters();
    for (int i = 0; i < 23; i++)
    {
        gaProfEntries[i].nTotal = 0;
        gaProfEntries[i].nCount = 0;
    }
}

#include "gen/data/Source/Storm/00611600_sub_00611600_CloseLogTail.inc"
