#define UNIT_PLAYER 0
#define PLRMODE_DEAD 17
#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_PERIODICSTATS 9

struct D2CoordStrc
{
    int nX;
    int nY;
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

struct D2ObjectsTxt
{
    char unk0x000[0xD8];
    unsigned int dwFrameCnt[8];
    char unk0x0F8[0x80];
    int dwParm[8];
};

struct D2ObjectDataStrc
{
    char unk0x00[4];
    unsigned char nInteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0xD0];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality);       // 0x00585B90
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static void __stdcall sub_00581680_DamagePlayersInRange(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->pRoomNext)
    {
        if (i->dwUnitType == UNIT_PLAYER && i->dwAnimMode != PLRMODE_DEAD && sub_006416D0_UnitEdgeDistance(pObject, i) <= pObjectsTxtRecord->dwParm[0] + 1)
        {
            OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, i, 1);
        }
    }
}

void __fastcall OBJMODE_UpdateTrapProximity(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwAnimMode == 1)
    {
        pObject->dwAnimMode = 2;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
    sub_00581680_DamagePlayersInRange(pGame, pObject);
    EVENT_SetEvent(pGame, pObject, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + SEED_RollRandomNumber_Inline(&pObjectControl->pSeed) % 35 + 15, 0, 0);
}

// 0x00585CE0
void __fastcall OBJMODE_UpdateTrappedSoul(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    switch (nMode)
    {
    case 1:
        EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 10, 0, 0);
        break;

    case 2:
    {
        D2ObjectDataStrc* pObjectData = pObject->pObjectData;
        const unsigned char nInteract = pObjectData->nInteractType + 1;
        pObjectData->nInteractType = nInteract;
        if (nInteract > 1)
        {
            D2ObjOperateFnStrc tOp;
            tOp.pGame = pGame;
            tOp.pObject = pObject;
            tOp.pPlayer = 0;
            tOp.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            tOp.nObjectIdx = pObject->dwClassId;
            if (OBJMODE_DropFromChestTCWithQuality(&tOp, 0))
            {
                UNITS_ChangeAnimMode(pObject, 3);
                EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, (pObjectsTxtRecord->dwFrameCnt[3] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            }
        }
        else
        {
            OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            sub_00581680_DamagePlayersInRange(pGame, pObject);
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 25, 0, 0);
        }
        break;
    }

    case 3:
        UNITS_ChangeAnimMode(pObject, 4);
        break;
    }
}
