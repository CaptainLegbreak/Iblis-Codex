extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xE4];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

void __fastcall sub_00534AB0_ClearTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);     // 0x00534AB0
void __fastcall sub_00573750_ClearTargetIfMatches(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);   // 0x00573750

static inline int UNITS_GetUnitTypeOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x0053AAA0
void __fastcall sub_0053AAA0_UpdateRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    D2_ASSERT(pRoom, 0x131);

    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 0:
            sub_00534AB0_ClearTargetIfMatch(pGame, pUnit, pTarget);
            break;

        case 1:
            sub_00573750_ClearTargetIfMatches(pGame, pUnit, pTarget);
            break;
        }
    }
}
