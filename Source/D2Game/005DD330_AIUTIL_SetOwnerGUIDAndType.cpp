struct D2AiControlStrc
{
    char unk_00[0x0C];
    int nOwnerId;
    int nOwnerType;
};
struct D2MonsterDataStrc
{
    char unk_00[0x28];
    D2AiControlStrc* pAiControl;
};
struct D2UnitStrc
{
    int dwUnitType;
    char dwClassId[8];
    int dwUnitId;
    int unk_10;
    D2MonsterDataStrc* pMonsterData;
};
static __forceinline D2AiControlStrc* GetAiControl(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType == 1 && pUnit->pMonsterData)
        return pUnit->pMonsterData->pAiControl;
    return 0;
}
static __forceinline int GetUnitType(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    return nUnitType;
}
// 0x005DD330
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
        return;
    D2AiControlStrc* pAi = GetAiControl(pUnit);
    if (pOwner)
    {
        pAi->nOwnerId = pOwner->dwUnitId;
        pAi->nOwnerType = GetUnitType(pOwner);
    }
    else
    {
        pAi->nOwnerId = -1;
        pAi->nOwnerType = 1;
    }
}
