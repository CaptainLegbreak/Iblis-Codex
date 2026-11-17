struct D2GameStrc;
struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned char dwClassId[8];
    unsigned int dwUnitId;
};
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00620C10

// 0x005FDA10
int __fastcall sub_005FDA10_TargetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2, int* pTargetType, int* pTargetGUID)
{
    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        D2UnitStrc* pTarget = SUNIT_GetLastAttacker(pGame, pUnit);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        if (pTargetType)
        {
            int nTargetType = 6;
            if (pTarget)
            {
                nTargetType = pTarget->dwUnitType;
            }
            *pTargetType = nTargetType;
            unsigned int nTargetGUID;
            if (!pTarget)
            {
                nTargetGUID = 0xFFFFFFFFu;
            }
            else
            {
                nTargetGUID = pTarget->dwUnitId;
            }
            *pTargetGUID = nTargetGUID;
        }
    }
    return 1;
}
