extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct D2GameStrc;
struct D2UnitStrc { unsigned int dwUnitType; volatile int dwClassId; };
struct D2TimerArg2Strc { int dwUnitId; };
struct D2TimerArgStrc { D2TimerArg2Strc* pArg; };
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit); // 0x006234F0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

inline int __fastcall GetObjectClass(D2UnitStrc* pObject)
{
    if (!pObject) return -1;
    int nClass = pObject->dwClassId;
    _ReadWriteBarrier();
    return nClass;
}

// 0x00585550
void __fastcall sub_00585550_ResetObject(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (GetObjectClass(pObject) == 337)
    {
        D2TimerArg2Strc* pArg = UNITS_GetTimerArg(pObject)->pArg;
        if (pArg) pArg->dwUnitId = -1;
    }
    else
    {
        UNITS_ChangeAnimMode(pObject, 0);
    }
}
