struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

#define MONSTER_TRAP_FIREBOLT 0x146
#define MONSTER_TRAP_POISONCLOUD 0x149
#define MONSTER_TRAP_LIGHTNING 0x14A
#define MONSTER_TRAP_NOVA 0x171
#define COLLIDE_MASK_PLACEMENT 0x3F11

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2UnitStrc* __fastcall sub_6FC6A090(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags); // 0x005B3090
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall D2Common_10136(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int a3, unsigned short nMask, D2ActiveRoomStrc** ppRoom); // 0x0064E840

// 0x00582420
static void sub_00582420_SpawnTrapMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);

    if (!sub_6FC6A090(pGame, UNITS_GetRoom(pUnit), tCoord.nX, tCoord.nY, nMonsterId, 1, 136))
    {
        D2ActiveRoomStrc* pRoom;
        D2Common_10136(UNITS_GetRoom(pUnit), &tCoord, 0, COLLIDE_MASK_PLACEMENT, &pRoom);
        if (pRoom)
        {
            D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, tCoord.nX, tCoord.nY, nMonsterId, 1, 3, 8);
        }
    }
}

// 0x00582490
void __fastcall D2GAME_OBJECTS_TrapHandler1_6FC75C70(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_LIGHTNING);
}

// 0x005824B0
void __fastcall D2GAME_OBJECTS_TrapHandler2_6_6FC75D00(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_FIREBOLT);
}

// 0x005824D0
void __fastcall D2GAME_OBJECTS_TrapHandler3_6FC75D90(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_POISONCLOUD);
}

// 0x005824F0
void __fastcall D2GAME_OBJECTS_TrapHandler4_6FC75E20(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_00582420_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_NOVA);
}
