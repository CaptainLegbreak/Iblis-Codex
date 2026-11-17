struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2UnkPlayerDataStrc
{
    char unk0x00[0x10];
    D2UnkPlayerDataStrc* pNext;
};

struct D2PlrIntroStrc;

struct D2PlayerDataStrc
{
    char unk0x00[0x60];
    D2PlrIntroStrc* pPlayerIntro[3];
    char unk0x6C[0x2C];
    D2UnkPlayerDataStrc* unk0x98;
};

struct D2UnitStrc;

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __fastcall PLRINTRO_Destroy(D2GameStrc* pGame, D2PlrIntroStrc* pPlayerIntro);                          // 0x00572620

// 0x00534840
static void sub_00534840_FreePlayerUnk98List(D2GameStrc* pGame, D2PlayerDataStrc* pPlayerData)
{
    D2UnkPlayerDataStrc* pNode = pPlayerData->unk0x98;
    while (pNode)
    {
        D2UnkPlayerDataStrc* pNext = pNode->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pNode, ".\\PLAYER\\Player.cpp", 43, 0);
        pNode = pNext;
    }
    pPlayerData->unk0x98 = 0;
}

// 0x00534880
void __fastcall sub_00534880_FreePlayerDataExtras(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        sub_00534840_FreePlayerUnk98List(pGame, pPlayerData);
        for (int i = 0; i < 3; ++i)
        {
            PLRINTRO_Destroy(pGame, pPlayerData->pPlayerIntro[i]);
            pPlayerData->pPlayerIntro[i] = 0;
        }
    }
}
