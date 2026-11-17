struct D2GameStrc;
struct D2ObjectControlStrc;

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define UNITFLAG_TARGETABLE 0x00000002

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                          // 0x00624690

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
