struct D2GameStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
    char unk0xC8[0x20];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char nDirection;
    unsigned char unk0x15;
    unsigned char unk0x16;
    unsigned char unk0x17;
    int unk0x18;
    int unk0x1C;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_INVALID 6
#define PLRMODE_DEATH 0
#define PLRMODE_DEAD 17
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12
#define OBJMODE_OPENED 2
#define MONSTATSFLAGINDEX_KILLABLE 15
#define MONSTATS2FLAGINDEX_OBJCOL 18
#define MONSTER_BARRICADEDOOR1 432
#define MONSTER_BARRICADEDOOR2 433

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                  // 0x00457490
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
void __fastcall sub_6FC7D470(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet);                     // 0x005751A0
void __fastcall sub_6FC62780(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame);              // 0x005A4EF0
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender);    // 0x0053F720
void __stdcall sub_0066A220_Stub(D2UnitStrc* pPlayer, int nMonsterId);                                      // 0x0066A220
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20
void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker);          // 0x00543A30

static void __stdcall sub_0057CC30_OpenBarricadeObject(D2UnitStrc* pDefender, int nObjectId)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pDefender);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
    {
        pNext = pUnit->pRoomNext;
        if (pUnit->dwUnitType == UNIT_OBJECT && pUnit->dwClassId == nObjectId)
        {
            D2CoordStrc tCoords;
            UNITS_GetCoords(pUnit, &tCoords);
            D2CoordStrc tDefenderCoords;
            UNITS_GetCoords(pDefender, &tDefenderCoords);

            if (tCoords.nX == tDefenderCoords.nX && tCoords.nY == tDefenderCoords.nY)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
                UNITS_FreeCollisionPath(pUnit);
                return;
            }
        }
    }
}

static __forceinline unsigned int sub_I18_UnitIsRevived(D2UnitStrc* pUnit)
{
    if (pUnit)
        return pUnit->dwFlags >> 31;
    return 0;
}

// 0x0057CCB0
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bPetKill)
{
    unsigned int nUnitType = UNIT_INVALID;
    if (pDefender)
    {
        nUnitType = pDefender->dwUnitType;
    }

    switch (nUnitType)
    {
    case UNIT_PLAYER:
    {
        if (!pDefender || pDefender->dwAnimMode == PLRMODE_DEATH || pDefender->dwAnimMode == PLRMODE_DEAD)
        {
            return;
        }
        break;
    }
    case UNIT_MONSTER:
    {
        if (!pDefender || pDefender->dwAnimMode == MONMODE_DEATH || pDefender->dwAnimMode == MONMODE_DEAD)
        {
            return;
        }

        if (!sub_00457490_CheckMonStatsFlag(pDefender->dwClassId, MONSTATSFLAGINDEX_KILLABLE))
        {
            return;
        }

        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pDefender);
        if (bPetKill && pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            sub_6FC7D470(pGame, pOwner, pDefender);
        }
        break;
    }
    default:
        return;
    }

    if (pAttacker)
    {
        sub_6FC62780(pAttacker, pDefender, pGame);
        ARENA_ProcessKillEvent(pGame, pAttacker, pDefender);

        const unsigned int nMonsterId = pDefender->dwClassId;
        if (nMonsterId < sgptDataTables->nMonStatsTxtRecordCount && pAttacker->dwUnitType == UNIT_PLAYER)
        {
            sub_0066A220_Stub(pAttacker, nMonsterId);
        }
    }

    if (pDefender->dwUnitType == UNIT_MONSTER)
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pDefender, MONMODE_DEATH, &modeChange);

        if (pAttacker)
        {
            modeChange.nDirection = UNITS_GetDirectionToCoords(pDefender, CLIENTS_GetUnitX(pAttacker), CLIENTS_GetUnitY(pAttacker));
        }
        else
        {
            modeChange.nDirection = PATH_GetDirection(pDefender->pDynamicPath);
        }

        modeChange.pTargetUnit = pAttacker;
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

        if (!sub_I18_UnitIsRevived(pDefender))
        {
            QUESTS_ParseKill(pGame, pDefender, pAttacker);
        }

        const int nClassId = pDefender->dwClassId;
        if (sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_OBJCOL))
        {
            if (nClassId == MONSTER_BARRICADEDOOR1)
            {
                sub_0057CC30_OpenBarricadeObject(pDefender, 571);
                return;
            }

            if (nClassId == MONSTER_BARRICADEDOOR2)
            {
                sub_0057CC30_OpenBarricadeObject(pDefender, 572);
            }
        }
    }
}
