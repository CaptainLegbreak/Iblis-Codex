struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x30];
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
    unsigned int unk0x38;
    unsigned int dwPathType;
    unsigned int dwPrevPathType;
    char unk0x44[0x38];
    int dwVelocity;
    unsigned int nPreviousVelocity;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0

#define UNIT_PLAYER 0
#define PATHTYPE_STRAIGHT 7
#define PATH_UNKNOWN_FLAG_0x02000 0x00002000
#define PATH_WITH_PREVIOUS_VELOCITY 0x00008000

// 0x00648DC0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath->pUnit, 2174);

    if (pDynamicPath->dwFlags & PATH_WITH_PREVIOUS_VELOCITY)
    {
        pDynamicPath->dwVelocity = pDynamicPath->nPreviousVelocity;
    }

    if (pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER)
    {
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
    }
    else if (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x02000)
    {
        PATH_SetType(pDynamicPath, pDynamicPath->dwPrevPathType);
    }
}
