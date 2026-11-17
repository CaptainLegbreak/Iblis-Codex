struct D2GameStrc;
struct D2UnitStrc;
struct D2PlrIntroStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
    unsigned int dwBoughtItemId;
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                        // 0x006221A0
D2PlrIntroStrc* __fastcall PLRINTRO_Create(D2GameStrc* pGame);                                             // 0x00572560

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
