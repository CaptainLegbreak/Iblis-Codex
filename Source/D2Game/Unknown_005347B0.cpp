#include "D2Game.h"

struct D2PlayerDataStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
    unsigned int dwBoughtItemId;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2PlrIntroStrc* __fastcall PLRINTRO_Create(D2GameStrc* pGame); // 0x00572560

// 0x005347B0
void __fastcall sub_005347B0_Stub5(int a1, int a2, int a3, int a4, int a5)
{
}

// 0x005347C0
void __fastcall sub_005347C0_Stub6(int a1, int a2, int a3, int a4, int a5, int a6)
{
}

// 0x005347D0
void __fastcall sub_005347D0_Stub9(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
}

// 0x005347E0
void __fastcall sub_005347E0_Stub5(int a1, int a2, int a3, int a4, int a5)
{
}

// 0x00534800
void __fastcall sub_00534800_CreatePlayerIntros(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        for (int i = 0; i < 3; ++i)
        {
            pPlayerData->pPlayerIntro[i] = PLRINTRO_Create(pGame);
        }
        pPlayerData->dwBoughtItemId = 0;
    }
}
