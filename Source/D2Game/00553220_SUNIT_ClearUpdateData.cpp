struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

#define UNITFLAG_DOUPDATE           0x00000001
#define UNITFLAG_INITSEEDSET        0x00000010
#define UNITFLAG_HASTXTMSG          0x00000100
#define UNITFLAG_HASEVENTSOUND      0x00000400
#define UNITFLAG_SUMMONER           0x00000800
#define UNITFLAG_SENDREFRESHMSG     0x00001000
#define UNITFLAG_UPGRLIFENHITCLASS  0x00008000
#define UNITFLAGEX_TELEPORTED       0x00010000

extern "C" const char gszEmptyAssertText;                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                               // 0x00681E09
void __stdcall STATLIST_FreeModStats(D2UnitStrc* pUnit);                                     // 0x00625960
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit);               // 0x00571F40
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int bInvalid);                 // 0x00620FA0
void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit);                                 // 0x00639EE0
void __fastcall D2GAME_INVMODE_Last_6FC416D0(D2GameStrc* pGame, D2UnitStrc* pUnit);          // 0x00597B00
int __stdcall D2COMMON_10530_D2CheckStatlistFlagDMGRed(D2UnitStrc* pUnit);                  // 0x00625A20
void __stdcall STATLIST_RemoveAllStatsFromOverlay(D2UnitStrc* pUnit);                        // 0x00627410
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __fastcall sub_0053FA90_ClearArenaUnitUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit);     // 0x0053FA90
void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int bSet, int bUpdate);        // 0x00573570
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);          // 0x006280D0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// build: context UNIT_HasFlag
__forceinline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x00553220
void __fastcall SUNIT_ClearUpdateData(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1304);

    STATLIST_FreeModStats(pUnit);
    D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(pUnit);
    pUnit->dwFlags &= ~(UNITFLAG_DOUPDATE | UNITFLAG_INITSEEDSET);
    UNITS_SetCurrentRoomInvalid(pUnit, 0);
    pUnit->dwFlags &= ~(UNITFLAG_HASEVENTSOUND | UNITFLAG_UPGRLIFENHITCLASS);
    pUnit->dwFlagEx &= 0xFFDEE7FF;
    STATES_ClearGfxStateFlags(pUnit);
    D2GAME_INVMODE_Last_6FC416D0(pGame, pUnit);

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pUnit))
    {
        STATLIST_RemoveAllStatsFromOverlay(pUnit);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pUnit))
    {
        STATLIST_RemoveAllStatsFromOverlay(pUnit);
    }

    switch (pUnit->dwUnitType)
    {
    case 0:
        STATLIST_SetUnitStat(pUnit, 29, -1, 0);
        pUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        sub_0053FA90_ClearArenaUnitUpdate(pGame, pUnit);
        return;

    case 2:
        pUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        return;

    case 1:
        pUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        if (UNIT_HasFlag(pUnit, UNITFLAG_SUMMONER))
        {
            pUnit->dwFlags &= ~UNITFLAG_SUMMONER;
            MONSTER_ToggleSummonerFlag(pUnit, 1, 0);
        }
        pUnit->dwFlagEx &= ~UNITFLAGEX_TELEPORTED;
        return;

    case 3:
        return;

    case 4:
        pUnit->dwFlags &= ~UNITFLAG_SENDREFRESHMSG;
        break;
    }

    if (pUnit->dwUnitType == 4)
    {
        ITEMS_SetItemFlag(pUnit, 0x20, 0);
        ITEMS_SetItemFlag(pUnit, 0x2000, 0);
    }
}
