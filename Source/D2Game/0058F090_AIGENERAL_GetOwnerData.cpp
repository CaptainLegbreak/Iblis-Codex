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

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058F090
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pUnitGUID, int* pUnitType)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        *pUnitGUID = -1;
        return;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl->pGame)
    {
        *pUnitGUID = -1;
        return;
    }

    *pUnitGUID = pAiControl->dwOwnerGUIDEx;
    *pUnitType = pAiControl->dwOwnerTypeEx;
}
