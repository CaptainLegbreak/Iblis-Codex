struct D2GameStrc;
struct D2UnitStrc { unsigned int dwUnitType; int dwClassId; char unk_08[8]; unsigned int dwAnimMode; };
struct D2ObjOperateFnStrc { D2GameStrc* pGame; D2UnitStrc* pObject; };
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

// 0x005843A0
int __fastcall sub_005843A0_ToggleObjectMode(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->pObject;
    switch (!pObject ? 0 : pObject->dwAnimMode)
    {
    case 0:
        UNITS_ChangeAnimMode(pObject, 1);
        break;
    case 1:
        UNITS_ChangeAnimMode(pObject, 0);
        break;
    }
    return 0;
}
