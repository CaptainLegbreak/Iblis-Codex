extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;
struct D2ClientStrc;

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

void __fastcall sub_005531E0_FixRoomIfInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient);                    // 0x005531E0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00573780
void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pMonster);                              // 0x005738D0
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

// 0x0053A6A0
static void sub_0053A6A0_FixRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x62);
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        sub_005531E0_FixRoomIfInvalid(pUnit, pClient);
}

// 0x0053A880
static void sub_0053A880_UpdateMonsterAiCallbacks(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 1:
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
            break;
        }
    }
}

// 0x0053A8B0
static void sub_0053A8B0_DeleteMonsterEvents(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 1:
            MONSTER_DeleteEvents(pGame, pUnit);
            break;
        }
    }
}

// 0x0053AA70
static void sub_0053AA70_UpdateUnitTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
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

void __fastcall sub_M126_Emit_0053A6A0(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient, int nUnused)
{
    sub_0053A6A0_FixRoomUnits(pRoom, pClient);
}
void __fastcall sub_M126_Emit_0053A880(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused)
{
    sub_0053A880_UpdateMonsterAiCallbacks(pGame, pRoom);
}
void __fastcall sub_M126_Emit_0053A8B0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused)
{
    sub_0053A8B0_DeleteMonsterEvents(pGame, pRoom);
}
void __fastcall sub_M126_Emit_0053AA70(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        sub_0053AA70_UpdateUnitTarget(pGame, pUnit, pTarget);
}
