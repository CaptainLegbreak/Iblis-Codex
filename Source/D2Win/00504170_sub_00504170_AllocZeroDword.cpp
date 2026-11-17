struct D2TxtLinkStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0

extern D2TxtLinkStrc* gpHitClassLinker_0087D820;                                                            // 0x0087D820
extern D2TxtLinkStrc* gpCompItemsLinker_0087D824;                                                           // 0x0087D824
extern D2TxtLinkStrc* gpItemTypesLinker_0087D828;                                                           // 0x0087D828

// 0x00504170
int* __cdecl sub_00504170_AllocZeroDword()
{
    int* pValue = (int*)FOG_Alloc(4, ".\\Src\\D2Comp.cpp", 0x866, 0);
    D2_ASSERT(pValue, 0x867);
    *pValue = 0;
    return pValue;
}

// 0x005043D0
void __stdcall sub_005043D0_Stub4(int a1, int a2, int a3, int a4)
{
}

// 0x005049D0
void __stdcall sub_005049D0_FreeCompLinkers()
{
    if (gpCompItemsLinker_0087D824)
    {
        FOG_FreeLinker(gpCompItemsLinker_0087D824);
        gpCompItemsLinker_0087D824 = 0;
    }
    if (gpItemTypesLinker_0087D828)
    {
        FOG_FreeLinker(gpItemTypesLinker_0087D828);
        gpItemTypesLinker_0087D828 = 0;
    }
    if (gpHitClassLinker_0087D820)
    {
        FOG_FreeLinker(gpHitClassLinker_0087D820);
        gpHitClassLinker_0087D820 = 0;
    }
}
