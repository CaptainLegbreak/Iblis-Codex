enum D2C_J07DungeonConstants
{
    UNITFLAGINDEX_ISCLIENTUNIT = 22,
    UNITFLAG_J07_PATHUPDATE = 0x800000,
    UNITFLAGEX_J07_REMOVED = 0x20,
};

struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2DrlgActStrc
{
    char unk0x00[0x5C];
    void* pMemPool;
};

struct D2ActiveRoomStrc
{
    void* ppRoomList;
    char unk0x04[0x28];
    D2DrlgActStrc* pAct;
    char unk0x30[0x18];
    void* ppClients;
    char unk0x4C[0x28];
    D2UnitStrc* pUnitFirst;
};

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit);                                                      // 0x0064C450
void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom);                   // 0x0064CA10
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom);                                             // 0x0061A2C0
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

static __forceinline void DUNGEON_GetClientUnitFlag(D2UnitStrc* pUnit, unsigned int dwFlags, int* pResult)
{
    *pResult = pUnit ? (dwFlags >> UNITFLAGINDEX_ISCLIENTUNIT) & 1 : 0;
}

// 0x0061A840
void __fastcall DUNGEON_FreeRoom(void* pMemPool, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pRoom->pUnitFirst)
    {
        const unsigned int dwFlags = pUnit->dwFlags;
        int bClient;
        DUNGEON_GetClientUnitFlag(pUnit, dwFlags, &bClient);
        if (!bClient)
        {
            pUnit->dwFlagEx |= UNITFLAGEX_J07_REMOVED;
        }

        pUnit->dwFlags = dwFlags | UNITFLAG_J07_PATHUPDATE;
        UNITROOM_UpdatePath(pUnit);
    }

    COLLISION_FreeRoomCollisionGrid(pMemPool, pRoom);
    DUNGEON_FreeDrlgDelete(pRoom);

    if (pRoom->ppClients)
    {
        FOG_FreeServerMemory(pRoom->pAct->pMemPool, pRoom->ppClients, ".\\DUNGEON\\Dungeon.cpp", 0x4E2, 0);
    }

    FOG_FreeServerMemory(pMemPool, pRoom->ppRoomList, ".\\DUNGEON\\Dungeon.cpp", 0x4E4, 0);
    FOG_FreeServerMemory(pMemPool, pRoom, ".\\DUNGEON\\Dungeon.cpp", 0x4E5, 0);
}
