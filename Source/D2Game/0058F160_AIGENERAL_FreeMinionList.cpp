struct D2MinionListStrc { int dwMinionGUID; D2MinionListStrc* pNext; };
struct D2GameStrc { char unk00[0x1C]; void* pMemoryPool; };
struct D2AiControlStrc { char unk00[0x28]; D2GameStrc* pGame; int dwOwnerGUIDEx; int dwOwnerTypeEx; D2MinionListStrc* pMinionList; };
struct D2MonsterDataStrc { char unk00[0x28]; D2AiControlStrc* pAiControl; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode; D2MonsterDataStrc* pMonsterData; };
enum { UNIT_MONSTER = 1, UNIT_INVALID = 6 };
extern const char gszAiGeneralSourceFile[]; // 0x006E1B24
void __fastcall FOG_FreePool(void* pPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nGUID); // 0x00552F60

// build: context sub_GetUnitTypeOrInvalid
static __forceinline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return UNIT_INVALID;
    return pUnit->dwUnitType;
}

// build: context AIGENERAL_GetAiControlFromUnit
static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit || sub_GetUnitTypeOrInvalid(pUnit) != UNIT_MONSTER)
        return 0;
    if (!pUnit->pMonsterData)
        return 0;
    return pUnit->pMonsterData->pAiControl;
}

// 0x0058F0D0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
        return 0;

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
        return 0;

    if (!pAiControl->pGame)
        return 0;

    return SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
}

// 0x0058F160
void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || sub_GetUnitTypeOrInvalid(pOwner) != UNIT_MONSTER)
        return;

    D2AiControlStrc* pOwnerControl = AIGENERAL_GetAiControlFromUnit(pOwner);
    D2MinionListStrc* pList = pOwnerControl->pMinionList;
    D2MinionListStrc* pPrevious = 0;
    const int nUnitGUID = pUnit->dwUnitId;
    D2GameStrc* pGame = pOwnerControl->pGame;
    for (; pList; pList = pList->pNext)
    {
        if (pList->dwMinionGUID == nUnitGUID)
        {
            D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pList->dwMinionGUID);
            if (sub_GetUnitTypeOrInvalid(pMinion) == UNIT_MONSTER)
            {
                D2AiControlStrc* pMinionControl = AIGENERAL_GetAiControlFromUnit(pMinion);
                pMinionControl->dwOwnerGUIDEx = -1;
                pMinionControl->dwOwnerTypeEx = UNIT_MONSTER;
                pMinionControl->pGame = pGame;
            }

            if (pPrevious)
                pPrevious->pNext = pList->pNext;
            else
                pOwnerControl->pMinionList = pList->pNext;

            FOG_FreePool(pGame->pMemoryPool, pList, gszAiGeneralSourceFile, 0x217, 0);
            return;
        }

        pPrevious = pList;
    }
}
