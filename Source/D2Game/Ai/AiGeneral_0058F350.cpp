#include "D2Constants.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
struct D2MinionListStrc
{
    int dwMinionGUID;
    D2MinionListStrc* pNext;
};


struct D2AiControlStrc
{
    char unk0x00[0x3C];
    int nMinionSpawnClassId;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};


void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058F350
void __fastcall AIGENERAL_FreeAllMinionLists(D2GameStrc* pGame, D2MinionListStrc* pMinionList)
{
    while (pMinionList)
    {
        D2MinionListStrc* pNext = pMinionList->pNext;
        FOG_FreePool(pGame->pMemoryPool, pMinionList, ".\\Ai\\AiGeneral.cpp", 582, 0);
        pMinionList = pNext;
    }
}

// 0x0058F710
int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit)
{
    return AIGENERAL_GetAiControlFromUnit(pUnit)->nMinionSpawnClassId;
}
