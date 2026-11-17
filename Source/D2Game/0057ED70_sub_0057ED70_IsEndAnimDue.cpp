struct D2UnitStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

typedef void(__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCustomId, int nCustomParam);

#define EVENTTYPE_ENDANIM 1
#define STAT_HITPOINTS 6

extern const EventCallbackFunction gpPlayerEventCallbacks_006E1810[15];                                     // 0x006E1810
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent);                       // 0x005415A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

// 0x0057ED70
int __fastcall sub_0057ED70_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return pGame->dwGameFrame <= EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM) + 5;
}

// 0x005805D0
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0x80;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nMaxHp > 0 && nHitpoints < nMaxHp)
    {
        return (nHitpoints << 7) / nMaxHp;
    }

    return 0x80;
}

// 0x00581220
void __fastcall D2GAME_EVENTS_Callback_6FC81BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam)
{
    if ((unsigned int)nEvent <= 14 && gpPlayerEventCallbacks_006E1810[nEvent])
    {
        gpPlayerEventCallbacks_006E1810[nEvent](pGame, pUnit, nCustomId, nCustomParam);
    }
}

#include "gen/data/Source/D2Game/0057ED70_sub_0057ED70_IsEndAnimDue.inc"
