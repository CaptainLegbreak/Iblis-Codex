struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    int dwOwnerType;
    int dwAiParam[3];
    void* pCurrentCmd;
    void* pLastCmd;
    D2GameStrc* pGame;
    int dwOwnerGUIDEx;
    int dwOwnerTypeEx;
    void* pMinionList;
    char unk0x38[0x08];
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

#define UNIT_MONSTER 1
#define UNIT_INVALID 6

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058EBC0
D2AiControlStrc* __fastcall AIGENERAL_AllocAiControl(D2GameStrc* pGame)
{
    D2AiControlStrc* pAiControl = (D2AiControlStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2AiControlStrc), ".\\Ai\\AiGeneral.cpp", 0x1B, 0);
    memset(pAiControl, 0, sizeof(D2AiControlStrc));
    pAiControl->dwOwnerGUIDEx = -1;
    pAiControl->dwOwnerTypeEx = UNIT_MONSTER;
    pAiControl->dwOwnerGUID = -1;
    pAiControl->dwOwnerType = UNIT_MONSTER;

    return pAiControl;
}

// 0x0058F0D0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl)
    {
        return 0;
    }

    if (!pAiControl->pGame)
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
}
