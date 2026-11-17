struct D2UnitEventStrc;
struct D2AiParamStrc;

struct D2ClientKeySkillStrc
{
    short nSkill;
    unsigned char nHand;
    char unk0x03;
    int nItemGUID;
};

struct D2ClientStrc
{
    char unk0x00[0x3DC];
    D2ClientKeySkillStrc HotkeySkills[16];
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
    int nShrines;
    int nWells;
    int nTrapMonsterId;
    D2CoordStrc wellCoordinates[4];
    D2CoordStrc shrineCoordinates[10];
};

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x10D0];
    D2ObjectControlStrc* pObjectControl;
};

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x68];
    D2GameStrc* pGame;
    char unk0x84[0x0C];
    D2UnitEventStrc* pSrvUnitEventsList;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int unk0x08[26];
};

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2);

struct D2UnitEventStrc
{
    unsigned char nUnitEvent;
    unsigned char unk0x01;
    unsigned short nFlags;
    unsigned int nEventGroup;
    int unk0x08;
    int nGUID1;
    int nGUID2;
    D2UnitEventCallbackFunction pCallback;
    D2UnitEventStrc* pPrevious;
    D2UnitEventStrc* pNext;
};

struct D2AiParamStrc
{
    char unk0x00[0x18];
    int unk0x18;
    int nVelocity;
    unsigned char unk0x20;
};

typedef int (__stdcall* FARPROC)();
typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);
typedef void (__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);
typedef void (__fastcall* MonEventFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
extern EventCallbackFunction scpfnItemEventFunctions_6FD27DDC[15];                                          // 0x006E117C
extern EventCallbackFunction gpEventFunctions_6FD28CD8[15];                                                 // 0x006E19B0
extern MonEventFunc gpMonsterEventFunctions[15];                                                            // 0x006E2490
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480
void __fastcall sub_005404C0_AddLivingMemberLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);       // 0x005404C0
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits);           // 0x005404F0
void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00553010
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define STAT_LEVEL 12
#define STATE_FREEZE 1
#define STATE_UNINTERRUPTABLE 54
#define STATE_DEATH_DELAY 92
#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_STATREGEN 3
#define EVENTTYPE_TRAP 4
#define EVENTTYPE_RESET 5
#define EVENTTYPE_PERIODICSKILLS 8
#define EVENTTYPE_REMOVESTATE 12
#define EVENTTYPE_COUNT 15
#define DAMAGERESULTFLAG_WILLDIE 0x02
#define UNITEVENTFLAG_IN_CALLBACK 0x01
#define UNITEVENTFLAG_SHOULD_BE_FREED 0x02
#define MONSTER_COMPONENT_COUNT 16
#define OBJRGN_MAX_WELLS 4
#define OBJRGN_MAX_SHRINES 10
#define AIPARAM_MAX_STEPS 77

// 0x005390A0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID)
{
    if (pClient)
    {
        pClient->HotkeySkills[nHotkeyId].nSkill = nSkillId;
        pClient->HotkeySkills[nHotkeyId].nHand = nHand;
        pClient->HotkeySkills[nHotkeyId].nItemGUID = nItemGUID;
    }
}

// 0x00540890
int __fastcall sub_00540890_SumLivingPartyLevelsInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLevelSum = 0;
    if (SUNIT_GetPartyId(pUnit) == -1)
    {
        return STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    }

    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, sub_005404C0_AddLivingMemberLevel, &nLevelSum);
    return nLevelSum;
}

// 0x005408E0
int __fastcall PARTY_GetLivingPartyMemberCountInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLivingPartyMembers = 0;
    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, PARTY_CountLivingUnits, &nLivingPartyMembers);
    return nLivingPartyMembers;
}

// 0x00541830
void __fastcall sub_00541830_SetMonsterComponent(D2UnitStrc* pUnit, unsigned char nComponent, unsigned char nValue)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nComponent < MONSTER_COMPONENT_COUNT && pUnit->pMonsterData)
    {
        pUnit->pMonsterData->nComponent[nComponent] = nValue;
    }
}

// 0x00547400
void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells >= OBJRGN_MAX_WELLS)
    {
        return;
    }

    pObjectRegion->wellCoordinates[pObjectRegion->nWells].nX = nX;
    pObjectRegion->wellCoordinates[pObjectRegion->nWells].nY = nY;
    ++pObjectRegion->nWells;
}

// 0x00547490
void __fastcall OBJRGN_SetShrineCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines >= OBJRGN_MAX_SHRINES)
    {
        return;
    }

    pObjectRegion->shrineCoordinates[pObjectRegion->nShrines].nX = nX;
    pObjectRegion->shrineCoordinates[pObjectRegion->nShrines].nY = nY;
    ++pObjectRegion->nShrines;
}

// 0x005544B0
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int bSetUninterruptable)
{
    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, bSetUninterruptable);

    D2_ASSERT(pUnit, 2601);
    D2GameStrc* pGame = pUnit->pGame;
    if (!pGame)
    {
        return;
    }

    if (!bSetUninterruptable && STATES_CheckState(pUnit, STATE_DEATH_DELAY))
    {
        STATES_ToggleState(pUnit, STATE_DEATH_DELAY, 0);

        D2UnitStrc* pAttacker = SUNIT_GetLastAttacker(pGame, pUnit);
        if (pAttacker)
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
            SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);
        }
        else
        {
            SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        }
    }

    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    }
}

// 0x00562DA0
void __fastcall D2GAME_Items_EventsHandler_6FC4A460(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType)
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)scpfnItemEventFunctions_6FD27DDC[nEventType]), 5610);
    scpfnItemEventFunctions_6FD27DDC[nEventType](pGame, pUnit);
}

// 0x00586AD0
void __fastcall D2GAME_OBJMODE_InvokeEventFunction_6FC75250(D2GameStrc* pGame, D2UnitStrc* pObject, int nEventType)
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)gpEventFunctions_6FD28CD8[nEventType]), 576);
    gpEventFunctions_6FD28CD8[nEventType](pGame, pObject);
}

// 0x005A6260
void __fastcall sub_005A6260_SetAiParamFields(D2AiParamStrc* pAiParam, int nParam18, int nParam1C, unsigned char nParam20)
{
    if (nParam18)
    {
        pAiParam->unk0x18 = nParam18;
    }

    if (nParam1C)
    {
        pAiParam->nVelocity = nParam1C;
    }

    if (nParam20)
    {
        if (nParam20 >= AIPARAM_MAX_STEPS + 1)
        {
            nParam20 = AIPARAM_MAX_STEPS;
        }

        pAiParam->unk0x20 = nParam20;
    }
}

// 0x005A7F80
void __fastcall MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nSkillId, int nSkillLevel)
{
    if (nEvent < 0 || nEvent >= EVENTTYPE_COUNT)
    {
        return;
    }

    switch (nEvent)
    {
    case EVENTTYPE_STATREGEN:
    case EVENTTYPE_TRAP:
    case EVENTTYPE_RESET:
    case EVENTTYPE_PERIODICSKILLS:
    case EVENTTYPE_REMOVESTATE:
        break;
    default:
        if (STATES_CheckState(pUnit, STATE_FREEZE) && !SUNIT_IsDead(pUnit))
        {
            return;
        }
        break;
    }

    const MonEventFunc pfMonEvent = gpMonsterEventFunctions[nEvent];
    if (pfMonEvent)
    {
        pfMonEvent(pGame, pUnit, nSkillId, nSkillLevel);
    }
}

// 0x005C0C30
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage)
{
    if (!pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        if (pUnitEvent->nUnitEvent == nUnitEvent)
        {
            pUnitEvent->nFlags |= UNITEVENTFLAG_IN_CALLBACK;
            nResult = pUnitEvent->pCallback(pGame, nUnitEvent, pUnit, pEventSourceUnit, pDamage, pUnitEvent->nGUID1, pUnitEvent->nGUID2);
            pUnitEvent->nFlags &= ~UNITEVENTFLAG_IN_CALLBACK;

            pNext = pUnitEvent->pNext;
            if ((pUnitEvent->nFlags & UNITEVENTFLAG_SHOULD_BE_FREED) || !pUnitEvent->nEventGroup)
            {
                if (pUnitEvent->pPrevious)
                {
                    pUnitEvent->pPrevious->pNext = pNext;
                }
                else
                {
                    pUnit->pSrvUnitEventsList = pNext;
                }

                if (pUnitEvent->pNext)
                {
                    pUnitEvent->pNext->pPrevious = pUnitEvent->pPrevious;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pUnitEvent, ".\\UNIT\\SUnitEvent.cpp", 235, 0);
            }
        }

        pUnitEvent = pNext;
    }

    return nResult;
}

#include "gen/data/Source/D2Game/005390A0_CLIENTS_SetSkillHotKey.inc"
