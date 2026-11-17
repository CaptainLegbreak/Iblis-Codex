struct D2UnitStrc
{
    char unk0x00[48];
    void* pAnimSeq;
    char unk0x34[16];
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006217C0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3457);

    if (pUnit->pAnimSeq)
    {
        return pUnit->dwFrameCountPrecise <= 0;
    }
    else
    {
        return pUnit->nSeqCurrentFramePrecise + pUnit->wAnimSpeed >= pUnit->dwFrameCountPrecise;
    }
}
