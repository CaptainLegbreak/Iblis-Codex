struct D2UnitStrc;
struct D2PlrIntroStrc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId);                         // 0x00572420
extern int gpAct1_NPCIds_007318B0[6];                                                                       // 0x007318B0
extern int gpAct2_NPCIds_007318C8[11];                                                                      // 0x007318C8
extern int gpAct3_NPCIds_007318F4[7];                                                                       // 0x007318F4
extern int gpAct5_NPCIds_00731910[7];                                                                       // 0x00731910

// 0x00544FA0
static void sub_00544FA0_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 6; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct1_NPCIds_007318B0[i]);
        break;
    }
    case 1:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 11; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct2_NPCIds_007318C8[i]);
        break;
    }
    case 2:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct3_NPCIds_007318F4[i]);
        break;
    }
    case 4:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
            PLRINTRO_SetNpcIntroFlag(pIntro, gpAct5_NPCIds_00731910[i]);
        break;
    }
    }
}

void sub_A04_Emit_005467E0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    sub_00544FA0_SetActNpcIntroFlags(pGame, pPlayer, 1);
    sub_00544FA0_SetActNpcIntroFlags(pGame, pPlayer, 2);
}

#include "gen/data/Source/D2Game/00544FA0_sub_00544FA0_SetActNpcIntroFlags.inc"
