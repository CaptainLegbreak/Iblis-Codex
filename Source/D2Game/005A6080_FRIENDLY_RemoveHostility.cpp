struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nFlag, int bSet); // 0x0055B260

#define UNIT_PLAYER 0
#define UNIT_INVALID 6
#define PLAYERLIST_FLAG_HOSTILE 8

// 0x005A6080
int __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2_ASSERT((pPlayer1 ? pPlayer1->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 21);

    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, PLAYERLIST_FLAG_HOSTILE, 0);
    return 1;
}
