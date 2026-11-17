struct D2WaypointDataStrc
{
    unsigned short nFlags[8];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00660F80
int __fastcall sub_00660F80_ValidateWaypointData(D2WaypointDataStrc* pData)
{
    if (pData->nFlags[0] != 0x102)
    {
        D2_ASSERT(pData->nFlags[0] == 0 || pData->nFlags[0] == 0x101, 0x113);
        pData->nFlags[0] = 0x102;
        return 0;
    }
    return 1;
}
