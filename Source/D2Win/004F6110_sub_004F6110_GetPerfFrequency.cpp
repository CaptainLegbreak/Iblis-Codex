union D2LargeIntegerStrc
{
    struct
    {
        unsigned long nLowPart;
        long nHighPart;
    };
    __int64 nQuadPart;
};

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(D2LargeIntegerStrc* pFrequency);   // 0x006CC254
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount);         // 0x006CC25C

struct D2PerfStartStrc
{
    D2LargeIntegerStrc tStart;

    D2PerfStartStrc()
    {
        QueryPerformanceCounter(&tStart);
    }
};

// build: symbol ?$S1@?1??sub_004F6130_GetElapsedMs@@YANXZ@4IA 0x007C9358
// 0x004F6110
double __cdecl sub_004F6110_GetPerfFrequency()
{
    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (double)tFrequency.nQuadPart;
}

// 0x004F6130
double __cdecl sub_004F6130_GetElapsedMs()
{
    static D2PerfStartStrc stStart; // 0x007C9350

    D2LargeIntegerStrc tNow;
    QueryPerformanceCounter(&tNow);
    tNow.nQuadPart -= stStart.tStart.nQuadPart;
    const double dTicks = (double)tNow.nQuadPart;

    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return dTicks / ((double)tFrequency.nQuadPart / 1000.0);
}
