#define UNIT_MONSTER 1
#define UNIT_INVALID 6

struct D2GameStrc;

struct D2MinionListStrc
{
    int dwMinionGUID;
    D2MinionListStrc* pNext;
};

struct D2AiControlStrc
{
    char unk0x00[0x28];
    D2GameStrc* pGame;
    int dwOwnerGUIDEx;
    int dwOwnerTypeEx;
    D2MinionListStrc* pMinionList;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

int __fastcall AIUTIL_CheckAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag);               // 0x005DD220
void __fastcall AIUTIL_ToggleAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag, int bSet);    // 0x005DD230
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion);       // 0x0058F100

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

inline void AIGENERAL_SetOwnerData_Inl(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (bSetFlag2)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 2, UNIT_MONSTER);
    }

    if (bSetFlag1)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, UNIT_MONSTER, UNIT_MONSTER);
    }

    pAiControl->dwOwnerGUIDEx = nOwnerGUID;
    pAiControl->dwOwnerTypeEx = nOwnerType;
    pAiControl->pGame = pGame;
}

// 0x0058F530
static __declspec(noinline) void __stdcall sub_0058F530_LinkMinions(D2UnitStrc* pUnit, D2AiControlStrc* pAiControl)
{
    D2MinionListStrc* pList = pAiControl->pMinionList;
    if (!pList)
    {
        return;
    }

    D2GameStrc* pGame = pAiControl->pGame;
    for (D2MinionListStrc* pMinionList = pList; pMinionList; pMinionList = pMinionList->pNext)
    {
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            AIGENERAL_SetOwnerData_Inl(pGame, pMinion, pMinionList->dwMinionGUID, UNIT_MONSTER, UNIT_MONSTER, UNIT_MONSTER);
            AIGENERAL_SetOwnerData_Inl(pGame, pUnit, pMinionList->dwMinionGUID, UNIT_MONSTER, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pMinion, pUnit);

            do
            {
                D2UnitStrc* pTemp = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pList->dwMinionGUID);
                if (pTemp && pTemp != pMinion)
                {
                    AIGENERAL_SetOwnerData_Inl(pGame, pTemp, pMinionList->dwMinionGUID, UNIT_MONSTER, 0, 0);
                    AIGENERAL_AllocMinionList(pGame, pMinion, pTemp);
                }
                pList = pList->pNext;
            }
            while (pList);
            return;
        }
    }
}

// 0x0058F660
static __declspec(noinline) void sub_0058F660_ReleaseMinions(D2AiControlStrc* pAiControl)
{
    D2MinionListStrc* pMinionList = pAiControl->pMinionList;
    D2GameStrc* pGame = pAiControl->pGame;
    while (pMinionList)
    {
        AIGENERAL_SetOwnerData_Inl(pGame, SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID), -1, UNIT_MONSTER, 0, 0);
        pMinionList = pMinionList->pNext;
    }
}

// 0x0058F6C0
void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!AIUTIL_CheckAiControlFlag(pAiControl, UNIT_MONSTER))
    {
        return;
    }

    if (AIUTIL_CheckAiControlFlag(pAiControl, 2))
    {
        sub_0058F530_LinkMinions(pUnit, pAiControl);
    }
    else
    {
        sub_0058F660_ReleaseMinions(pAiControl);
    }
}
