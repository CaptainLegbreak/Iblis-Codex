extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(int (__stdcall* lpfn)());                     // 0x006CC34C

struct D2UnitFindArgStrc;

struct D2UnitStrc
{
    char unk0x00[0xE8];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

typedef int (__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit, D2UnitFindArgStrc* pUnitFindArg);

// 0x0065A790
int __stdcall UNITFINDS_GetTestedUnitsFromRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc** ppUnits, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg)
{
    int nUnitIndex = 0;
    D2UnitStrc* pUnit = pRoom->pUnitFirst;

    D2_ASSERT(!IsBadCodePtr((int (__stdcall*)())pfnUnitTest), 114);

    for (; pUnit; pUnit = pUnit->pRoomNext)
    {
        if (pfnUnitTest(pUnit, pUnitFindArg))
        {
            ppUnits[nUnitIndex] = pUnit;
            ++nUnitIndex;

            D2_ASSERT(nUnitIndex < 15, 120);
        }
    }

    return nUnitIndex;
}
