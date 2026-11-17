struct D2GameStrc;
struct D2TimerArg2Strc;
struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
    int dwUnitId;
};
struct D2UnitStrc;
struct D2ObjInitFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
};

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit);                                            // 0x006234F0

#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define OBJECTS_CONSTANT_00552AB0 2

// 0x005500C0
void __fastcall OBJECTS_InitFunction08_Torch(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
}

// 0x005500D0
void __fastcall OBJECTS_InitFunction14_Brazier(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
}

// 0x005500E0
void __fastcall sub_005500E0(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
}

// 0x00552AB0
unsigned char __fastcall sub_00552AB0()
{
    return OBJECTS_CONSTANT_00552AB0;
}

// 0x00552AF0
void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pPortal, int nUnitId)
{
    D2TimerArgStrc* pTimerArg = UNITS_GetTimerArg(pPortal);
    if (pTimerArg)
    {
        pTimerArg->dwUnitId = nUnitId;
    }
}

// 0x00552B10
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit)
{
    D2TimerArgStrc* pTimerArg = UNITS_GetTimerArg(pUnit);
    if (pTimerArg)
    {
        return pTimerArg->dwUnitId;
    }

    return -1;
}
