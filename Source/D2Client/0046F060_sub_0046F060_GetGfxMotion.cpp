struct D2PlayerDataStrc
{
    char unk0x000[0x150];
    int nUnk0x150;
    int nUnk0x154;
    int nUnk0x158;
    int nUnk0x15C;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2PlayerDataStrc* pPlayerData;
};

struct D2GfxMotionStrc;

struct D2GfxDataStrc
{
    char unk0x00[0x30];
    D2GfxMotionStrc* pMotion;
};

D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
void __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, void* pTarget, int nArg);          // 0x00461250
extern D2UnitStrc* gpAiTargets_007A7470[];                                                                  // 0x007A7470

// 0x0046F060
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
        return pGfxData->pMotion;
    return 0;
}

// 0x0046F950
void __fastcall sub_0046F950(D2UnitStrc* pUnit)
{
    if (!sub_00464820_IsDeadOrDying(pUnit) && pUnit && pUnit->dwUnitType == 0)
        sub_00461250_QueueMove(7, pUnit, 0, 1);
}

// 0x0046C6E0
void __fastcall sub_0046C6E0_AddToUnitSlots(D2UnitStrc* pUnit)
{
    D2UnitStrc** ppSlot = gpAiTargets_007A7470;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        if (!*ppSlot)
        {
            *ppSlot = pUnit;
            return;
        }
    }
}

// 0x0046C700
void __fastcall sub_0046C700(D2UnitStrc* pUnit)
{
    D2UnitStrc** ppSlot = gpAiTargets_007A7470;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        if (*ppSlot == pUnit)
        {
            *ppSlot = 0;
            return;
        }
    }
}

// 0x0045C470
void __fastcall sub_0045C470_ClearPendingAction(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nUnk0x150 = 0;
        pUnit->pPlayerData->nUnk0x154 = 0;
        pUnit->pPlayerData->nUnk0x158 = 0;
        pUnit->pPlayerData->nUnk0x15C = 0;
    }
}
