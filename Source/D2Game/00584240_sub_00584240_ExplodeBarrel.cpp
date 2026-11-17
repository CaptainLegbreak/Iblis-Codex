struct D2ObjectControlStrc;

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
    char unk0xC8[0x20];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_TILE 5
#define PLRMODE_DEAD 17
#define MONMODE_DEAD 12
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJECT_EXPLODINGBARREL 11
#define UNITFLAG_TARGETABLE 0x00000002
#define EVENTTYPE_ENDANIM 1

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall UNITS_IsInRange(D2UnitStrc* pUnit, D2CoordStrc* pCoord, int nDistance);                       // 0x00641890

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp);                         // 0x00584330

// build: context OBJECTS_IsNeutralExplodingBarrel
static __forceinline int OBJECTS_IsNeutralExplodingBarrel(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwClassId == OBJECT_EXPLODINGBARREL && pUnit->dwAnimMode == OBJMODE_NEUTRAL;
}

// 0x00584240
static int sub_00584240_ExplodeBarrel(D2ObjOperateFnStrc* pOp)
{
    D2ObjOperateFnStrc tNewOp = *pOp;
    D2CoordStrc tCoord;
    UNITS_GetCoords(pOp->pObject, &tCoord);
    for (D2UnitStrc* pUnit = UNITS_GetRoom(pOp->pObject)->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (pUnit != pOp->pObject && nUnitType != UNIT_TILE)
        {
            if (nUnitType == UNIT_PLAYER)
            {
                if (nAnimMode != PLRMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_MONSTER)
            {
                if (nAnimMode != MONMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->pObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_OBJECT)
            {
                if (OBJECTS_IsNeutralExplodingBarrel(pUnit) && sub_006416D0_UnitEdgeDistance(pOp->pObject, pUnit) <= 2)
                {
                    tNewOp.pObject = pUnit;
                    OBJECTS_OperateFunction07_ExplodingBarrel(&tNewOp);
                }
            }
        }
    }
    return 0;
}

// 0x00584330
int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp)
{
    if ((!pOp->pObject ? 0 : pOp->pObject->dwAnimMode) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->pObject, UNITFLAG_TARGETABLE);
        sub_00584240_ExplodeBarrel(pOp);
        UNITS_FreeCollisionPath(pOp->pObject);
        D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}
