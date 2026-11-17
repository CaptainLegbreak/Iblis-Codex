struct D2UnitStrc;
struct D2GameStrc;

struct D2ClientStrc
{
    char unk0x000[0x16C];
    int dwUnitType;
    int dwUnitGUID;
    D2UnitStrc* pPlayer;
    char unk0x178[0x30];
    D2GameStrc* pGame;
    char unk0x1AC[0x228];
    unsigned int dwFlags;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60

#define CLIENTFLAGEX_PLAYER_UNIT_ALIVE 0x01

// 0x00537860
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath)
{
    D2_ASSERT(pClient, 251);

    if (pClient->dwFlags & CLIENTFLAGEX_PLAYER_UNIT_ALIVE)
    {
        return pClient->pPlayer;
    }

    if (bIgnoreDeath)
    {
        return pClient->pPlayer;
    }

    if (!pClient->pPlayer)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pClient->pGame, pClient->dwUnitType, pClient->dwUnitGUID);
    if (!pPlayer)
    {
        pClient->pPlayer = 0;
    }

    return pPlayer;
}
