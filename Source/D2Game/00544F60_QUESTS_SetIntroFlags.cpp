struct D2PlrIntroStrc;
struct D2UnitStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId);                         // 0x00572420

// 0x00544F60
static void __stdcall QUESTS_SetIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, const int* pNPCs, int nNPCs)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
    for (int i = 0; i < nNPCs; ++i)
    {
        PLRINTRO_SetNpcIntroFlag(pPlayerIntro, pNPCs[i]);
    }
}

void __fastcall sub_K10_EmitSetIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    static const int aNpcs[2] = { 1, 2 };
    QUESTS_SetIntroFlags(pGame, pPlayer, aNpcs, 2);
}
