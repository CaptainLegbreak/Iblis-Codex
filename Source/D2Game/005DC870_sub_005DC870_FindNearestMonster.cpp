struct D2GameStrc;
struct D2UnitStrc
{
    unsigned int dwUnitType;
};
struct D2NearestRecord005DC870Strc
{
    D2UnitStrc* pNearest;
    int nBestDistance;
    int nCount;
    int nMaxDistance;
};
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
int __fastcall sub_00554200_CheckTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

// 0x005DC870
int __fastcall sub_005DC870_FindNearestMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2NearestRecord005DC870Strc* pRecord)
{
    if (pUnit == pTarget)
    {
        return 0;
    }
    if (!pTarget)
    {
        return 0;
    }
    const int nUnitType = pTarget ? pTarget->dwUnitType : 6;
    if (nUnitType != 1)
    {
        return 0;
    }
    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance >= pRecord->nMaxDistance)
    {
        return 0;
    }
    if (sub_00554200_CheckTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }
    ++pRecord->nCount;
    if (nDistance < pRecord->nBestDistance)
    {
        pRecord->nBestDistance = nDistance;
        pRecord->pNearest = pTarget;
    }
    return 0;
}
