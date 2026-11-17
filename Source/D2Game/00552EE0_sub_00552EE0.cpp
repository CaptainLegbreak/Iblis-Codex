struct D2ClientStrc;
struct D2EventTimerStrc;
struct D2PlayerDataStrc
{
    char unk0x00[64];
    int nNecropetFlag;
    char unk0x44[88];
    D2ClientStrc* pClient;
};
struct D2GameStrc
{
    char unk0x00[144];
    int dwLastUsedUnitGUID[6];
};
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2PlayerDataStrc* pPlayerData;
    char unk0x18[0x56];
    short nUpdateType;
    D2UnitStrc* pUpdateUnit;
    char f_74[4];
    unsigned char bSparkChest;
    char unk0x79[7];
    D2GameStrc* pGame;
    char unk0x84[0x18];
    int dwKillerType;
    int dwKillerGUID;
    char unk0xA4[0x20];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define NUM_UNIT_TYPES 6
#define UNITFLAGEX_STORELASTATTACKER 0x20000
#define UNITFLAG_HASEVENTSOUND 0x400
#define UNIT_LIST_MASK 0x7F

// 0x00552EE0
int __fastcall sub_00552EE0(D2GameStrc* pGame, int nUnitType)
{
    D2_ASSERT(nUnitType < NUM_UNIT_TYPES, 452);

    int nUnitGUID = pGame->dwLastUsedUnitGUID[nUnitType] + 1;
    if (nUnitGUID == -1)
    {
        nUnitGUID = 1;
    }

    pGame->dwLastUsedUnitGUID[nUnitType] = nUnitGUID;
    return nUnitGUID;
}

// 0x00552F20
int __fastcall sub_00552F20(int nUnitGUID)
{
    return nUnitGUID & UNIT_LIST_MASK;
}

// 0x00553010
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 800);

    if (pUnit->dwFlagEx & UNITFLAGEX_STORELASTATTACKER)
    {
        return SUNIT_GetServerUnit(pGame, pUnit->dwKillerType, pUnit->dwKillerGUID);
    }

    return 0;
}

// 0x00553180
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit, 1210);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 1211);

    UNITS_GetPlayerData(pUnit)->pClient = pClient;
}

// 0x005531C0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    return UNITS_GetPlayerData(pPlayer)->pClient;
}

// 0x00553380
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit)
{
    D2_ASSERT(pUnit, 1367);

    pUnit->nUpdateType = nUpdateType;
    pUnit->pUpdateUnit = pUpdateUnit;
    UNITROOM_RefreshUnit(pUnit);
    pUnit->dwFlags |= UNITFLAG_HASEVENTSOUND;
}

// 0x00554010
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2601);

    return pUnit->pGame;
}

// 0x00554040
void __fastcall sub_00554040(D2UnitStrc* pUnit, int nFlag)
{
    D2_ASSERT(pUnit, 2610);

    pUnit->pPlayerData->nNecropetFlag = nFlag;
}

// 0x00554070
unsigned int __fastcall sub_00554070(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2620);

    return pUnit->pPlayerData->nNecropetFlag;
}

// 0x005540A0
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest)
{
    D2_ASSERT(pUnit, 2631);

    pUnit->bSparkChest = nSparkChest;
}

// 0x005540D0
unsigned char __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2640);

    return pUnit->bSparkChest;
}
