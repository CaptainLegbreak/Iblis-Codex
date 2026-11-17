struct D2GameStrc;
struct D2UnitStrc;
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall sub_005FDA80_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int a7); // 0x005FDA80
void __fastcall sub_6FCC6150(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, short nX, short nY, unsigned char a6); // 0x00571840

// 0x005FDD60
int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6)
{
    if (!pUnit)
        return 0;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return 0;
    }
    if (STATES_CheckState(pUnit, 54))
    {
        return 0;
    }
    int nUnitType;
    int nUnitGUID;
    int nNewX = 0;
    int nNewY = 0;
    if (!sub_005FDA80_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, 0, nX, nY, &nUnitType, &nUnitGUID, &nNewX, &nNewY, a6))
        return 0;
    int nFinalX = nNewX;
    int nFinalY;
    if (!nFinalX)
    {
        nFinalX = nX;
        nFinalY = nY;
    }
    else
    {
        nFinalY = nNewY;
    }
    sub_6FCC6150(pUnit, nSkillId, nSkillLevel, nFinalX, nFinalY, a6);
    return 1;
}
