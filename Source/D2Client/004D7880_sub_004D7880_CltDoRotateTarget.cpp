struct D2DynamicPathStrc;
struct D2StaticPathStrc
{
    int unk_00[3];
    int nX;
    int nY;
};
struct D2UnitStrc
{
    int nType;
    int dwClassId[10];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};
int __stdcall sub_006488C0_GetX(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall sub_00648900_GetY(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall sub_0064A730_GetTargetX(D2UnitStrc* pUnit); // 0x0064A730
int __stdcall sub_0064A780_GetTargetY(D2UnitStrc* pUnit); // 0x0064A780
void __stdcall sub_00648AD0_SetTarget(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall sub_00649970_UpdatePath(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int nUnused); // 0x00649970
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pUnit); // 0x004D30C0

static __forceinline int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->nType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        if (pUnit->pDynamicPath)
            return sub_006488C0_GetX(pUnit->pDynamicPath);
        return 0;
    }
}
static __forceinline int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->nType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        if (pUnit->pDynamicPath)
            return sub_00648900_GetY(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x004D7880
void __fastcall sub_004D7880_CltDoRotateTarget(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDiffY = 0;
    const int nX = GetX(pUnit);
    const int nY = GetY(pUnit);
    const int nDiffX = nX - sub_0064A730_GetTargetX(pUnit);
    nDiffY = nY - sub_0064A780_GetTargetY(pUnit);
    sub_00648AD0_SetTarget(pPath, nX + nDiffY, nY - nDiffX);
    sub_00649970_UpdatePath(pPath, pUnit, 0);
    sub_004D30C0_CltDoCommon(pUnit);
}
