#include "D2Game.h"

#define ITEMQUAL_NORMAL 2
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPENED 2
#define UNITFLAG_TARGETABLE 0x00000002
#define OBJMODE_OPERATING 1
struct D2ObjectControlStrc;
struct D2SeedStrc;
struct D2ObjOperateFnStrc;

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
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0xA4];
    unsigned int dwDropItemCode;
    char unk0xBC[0x8];
    unsigned int dwFlags;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

static __forceinline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00584060
int __fastcall OBJECTS_OperateFunction26_BookShelf(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->pObject, &pCoord);

        int nRand = (unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) % 20;
        if (nRand > 12)
        {
            if ((unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) & 1)
            {
                pOp->pObject->dwDropItemCode = ' kbi';
            }
            else
            {
                pOp->pObject->dwDropItemCode = ' kbt';
            }
        }
        else
        {
            if ((unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) & 1)
            {
                pOp->pObject->dwDropItemCode = ' csi';
            }
            else
            {
                pOp->pObject->dwDropItemCode = ' cst';
            }
        }

        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
    }

    return 1;
}

// 0x005843D0
int __fastcall OBJECTS_OperateFunction11_Torch(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->pObject;
    if (pObject && pObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        switch (pObject->dwAnimMode)
        {
        case OBJMODE_OPERATING:
        case OBJMODE_OPENED:
            UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
            break;
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);
        pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}
