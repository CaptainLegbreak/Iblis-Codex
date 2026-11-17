extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2AiCmdStrc;

enum D2C_F33AiConstants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2MinionListStrc
{
    int dwMinionGUID;
    D2MinionListStrc* pNext;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
    D2AiCmdStrc* pCurrentCmd;
    D2AiCmdStrc* pLastCmd;
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
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall AIUTIL_CheckAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag);                // 0x005DD220
void __fastcall AIUTIL_ToggleAiControlFlag(D2AiControlStrc* pAiControl, unsigned short nFlag, int bSet);    // 0x005DD230

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058F030
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (bSetFlag2)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 2, 1);
    }

    if (bSetFlag1)
    {
        AIUTIL_ToggleAiControlFlag(pAiControl, 1, 1);
    }

    pAiControl->dwOwnerGUIDEx = nOwnerGUID;
    pAiControl->dwOwnerTypeEx = nOwnerType;
    pAiControl->pGame = pGame;
}

// 0x0058F100
void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    D2MinionListStrc* pMinionList = (D2MinionListStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2MinionListStrc), ".\\Ai\\AiGeneral.cpp", 499, 0);
    memset(pMinionList, 0, sizeof(D2MinionListStrc));
    pMinionList->dwMinionGUID = !pMinion ? -1 : pMinion->dwUnitId;
    if (pAiControl->pMinionList)
    {
        pMinionList->pNext = pAiControl->pMinionList;
    }
    pAiControl->pMinionList = pMinionList;
}

// 0x0058F440
void __fastcall AIGENERAL_GetAiControlInfo(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType, int* pAiControlFlag1, int* pAiControlFlag2, D2MinionListStrc** ppMinionList)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        *pOwnerGUID = -1;
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (pAiControl->dwOwnerTypeEx != UNIT_MONSTER)
    {
        *pOwnerGUID = -1;
        return;
    }

    *pOwnerGUID = pAiControl->dwOwnerGUIDEx;
    *pOwnerType = pAiControl->dwOwnerTypeEx;
    *pAiControlFlag1 = AIUTIL_CheckAiControlFlag(pAiControl, 1);
    *pAiControlFlag2 = AIUTIL_CheckAiControlFlag(pAiControl, 2);
    *ppMinionList = pAiControl->pMinionList;
    pAiControl->dwOwnerGUIDEx = -1;
    pAiControl->pMinionList = 0;
}
