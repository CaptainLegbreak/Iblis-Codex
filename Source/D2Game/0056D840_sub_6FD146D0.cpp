struct D2ActiveRoomStrc;
struct D2AiControlStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
    int unk0x10;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};

#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STATE_UNINTERRUPTABLE 54
#define EVENTTYPE_AITHINK 2
#define UNITFLAG_NOTC 0x00020000
#define UNITFLAG_ISREVIVE 0x80000000

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_00554070(D2UnitStrc* pUnit);                                          // 0x00554070
void __fastcall sub_00554040(D2UnitStrc* pUnit, int nUnitGUID);                         // 0x00554040
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
void __fastcall sub_6FC7D7A0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nPetType, int nPetMax); // 0x00575D90
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00573780
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

static __forceinline int UNITS_HasBeenDeletedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx >> 8) & 1;
}

static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

// 0x0056D840
static void sub_6FD146D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4008);

    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, sub_00554070(pUnit));
    if (pPet)
    {
        if (UNITS_HasBeenDeletedInline(pPet))
        {
            SUNIT_RemoveUnit(pGame, pPet);
            sub_00554040(pUnit, -1);
            return;
        }

        pPet->dwFlags |= 0x4000000u;

        SUNITDMG_KillMonster(pGame, pPet, pUnit, 1);
    }

    sub_00554040(pUnit, -1);
}

// 0x0056D8D0
static void __stdcall sub_0056D8D0_SetPetFlagsAndCount(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg, D2UnitStrc* pPet)
{
    if (!(pSummonArg->dwFlags & 8) && pPet)
    {
        pPet->dwFlags |= UNITFLAG_ISREVIVE;
    }

    if (pSummonArg->dwFlags & 2)
    {
        sub_6FD146D0(pGame, pSummonArg->pOwner);
        sub_00554040(pSummonArg->pOwner, !pPet ? -1 : pPet->dwUnitId);
    }

    int nPetMax = pSummonArg->nPetMax;
    if (nPetMax < 1)
    {
        nPetMax = 1;
    }
    sub_6FC7D7A0(pGame, pSummonArg->pOwner, pPet, pSummonArg->nPetType, nPetMax);
}

D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg)
{
    D2CoordStrc tCoords;
    if (pSummonArg->dwFlags & 1)
    {
        tCoords = pSummonArg->pPosition;
    }
    else
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pSummonArg->pOwner, &tCoords.nX, &tCoords.nY);
    }

    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pSummonArg->pOwner), tCoords.nX, tCoords.nY);
    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, tCoords.nX, tCoords.nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, -1, 66);
    if (!pPet)
    {
        if (pSummonArg->dwFlags & 4)
        {
            return 0;
        }

        pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, tCoords.nX, tCoords.nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, 4, 66);
        if (!pPet)
        {
            return 0;
        }
    }

    sub_0056D8D0_SetPetFlagsAndCount(pGame, pSummonArg, pPet);

    if (pPet)
    {
        pPet->dwFlags |= UNITFLAG_NOTC;
    }

    if (pSummonArg->pOwner)
    {
        AIGENERAL_SetOwnerData(pGame, pPet, pSummonArg->pOwner->dwUnitId, pSummonArg->pOwner->dwUnitType, 0, 0);
    }
    else
    {
        AIGENERAL_SetOwnerData(pGame, pPet, -1, UNIT_INVALID, 0, 0);
    }

    D2_ASSERT(!STATES_CheckState(pPet, STATE_UNINTERRUPTABLE), 4108);

    AITHINK_ExecuteAiFn(pGame, pPet, AIGENERAL_GetAiControlFromUnit(pPet), pSummonArg->nAiSpecialState);
    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pPet, EVENTTYPE_AITHINK, pGame->dwGameFrame + 25, 0, 0);

    return pPet;
}
