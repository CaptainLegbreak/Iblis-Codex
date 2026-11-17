struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x10];
    int dwAnimMode;
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2ActiveRoomStrc* pRoom;
};

#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_PERIODICSTATS 9

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

static __forceinline unsigned int ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005500F0
void __fastcall OBJECTS_InitFunction34_HellBrazierFire(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pOp->pGame, pOp->pRoom);
    if (ITEMS_RollRandomNumberForceInline(&pObjectControl->pSeed) & 1)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    }
}

// 0x005501F0
void __fastcall OBJECTS_InitFunction51_TrappedSoul(D2ObjInitFnStrc* pOp)
{
    if ((pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPENED) || (pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPERATING))
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_PERIODICSTATS, pOp->pGame->dwGameFrame + 35, 0, 0);
    }
}
