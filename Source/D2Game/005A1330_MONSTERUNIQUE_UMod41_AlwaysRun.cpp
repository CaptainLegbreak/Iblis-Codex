struct D2GameStrc
{
    char pad0x00[0x6A];
    unsigned char nGameType;
    char pad0x6B[0x02];
    unsigned char nDifficulty;
    char pad0x6E[0x06];
    int dwGameType;
    char pad0x78[0x30];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005A1330
void __fastcall MONSTERUNIQUE_UMod41_AlwaysRun(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
        if (pGame)
        {
            EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 75, 0, 0);
        }
    }
}
