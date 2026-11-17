struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; };
struct D2AiControlStrc
{
    char unk_00[0x0C];
    int nOwnerGUID;
    int nOwnerType;
};
struct D2AiTickParamStrc { D2AiControlStrc* pAiControl; };
int __fastcall sub_0046C140_CheckMonStats2ModeFlag(int, int); // 0x0046C140
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380
int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0
void __fastcall AITACTICS_SetVelocity(D2UnitStrc*, int, int, unsigned char); // 0x005DE190
int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x005DF530

static __forceinline int CanWalk(D2UnitStrc* pMonster)
{
    return sub_0046C140_CheckMonStats2ModeFlag(!pMonster ? -1 : pMonster->dwClassId, 2);
}

// 0x005B0FF0
int __fastcall D2GAME_AICORE_MinionLeash_6FCF0D10(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam)
{
    int nOwnerGUID = 0;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    nOwnerGUID = *(volatile int*)&pAiControl->nOwnerGUID;
    if (nOwnerGUID == -1)
        return 0;
    if (!CanWalk(pMonster))
    {
        pAiControl->nOwnerGUID = -1;
        return 0;
    }
    nOwnerGUID = pAiControl->nOwnerGUID;
    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, !pAiControl ? 6 : pAiControl->nOwnerType, nOwnerGUID);
    if (!pOwner)
    {
        (*(D2AiControlStrc* volatile*)&pAiControl)->nOwnerGUID = -1;
        return 0;
    }
    if (SUNIT_IsDead(pOwner))
    {
        (*(D2AiControlStrc* volatile*)&pAiControl)->nOwnerGUID = -1;
        return 0;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pMonster, pOwner);
    if (nDistance <= 1 && (*(D2AiControlStrc* volatile*)&pAiControl)->nOwnerType == 0)
    {
        if (D2GAME_AICORE_Escape_6FCD0560(pGame, pMonster, pOwner, 19, 1))
            return 1;
    }
    else
    {
        if (nDistance <= 20)
            return 0;
        AITACTICS_SetVelocity(pMonster, 7, 0, 40);
    }
    D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pMonster, pOwner, 19);
    return 1;
}
