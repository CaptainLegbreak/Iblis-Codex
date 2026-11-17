struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
    int dwAnimMode;
};

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);
extern D2UnitStrc* gpAiTargets_007A7470[];                                                                  // 0x007A7470

// 0x0046C720
static __declspec(noinline) D2UnitStrc* __stdcall sub_0046C720_FindNearestTarget(D2UnitStrc* pUnit, int* pDistance)
{
    D2UnitStrc* pNearest = 0;
    D2UnitStrc** ppSlot = gpAiTargets_007A7470;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        D2UnitStrc* pTarget = *ppSlot;
        if (pTarget && pTarget->dwAnimMode && pTarget->dwAnimMode != 12)
        {
            const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pTarget);
            if (nDistance < *pDistance)
            {
                pNearest = *ppSlot;
                *pDistance = nDistance;
            }
        }
    }

    return pNearest;
}

D2UnitStrc* __fastcall sub_M305_Emit_0046C720(D2UnitStrc* pUnit)
{
    int nDistance = 0x7FFFFFFF;
    return sub_0046C720_FindNearestTarget(pUnit, &nDistance);
}
