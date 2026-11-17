#define UNIT_PLAYER 0
#define EVENTTYPE_REMOVESKILLCOOLDOWN 14

struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2PlayerDataStrc
{
    char unk0x000[0x148];
    int nSkillCooldown148;
    int nSkillCooldown14C;
};

typedef int (__fastcall* EventTimerCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5);

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __fastcall sub_6FC349B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback); // 0x00540EA0

// 0x00554570
int __fastcall sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventType, int a4, int a5)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }

    pPlayerData->nSkillCooldown148 = 0;
    pPlayerData->nSkillCooldown14C = 0;
    sub_6FC349B0(pGame, pPlayer, EVENTTYPE_REMOVESKILLCOOLDOWN, sub_6FCBDF90);
    return 1;
}
