#include "D2Common.h"

#define UNIT_PLAYER 0
#define STATEMASK_BOSSSTAYDEATH 15

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DataTablesStrc
{
    char unk0x00[0xC4];
    int nStatesTxtRecordCount;
    char unk0xC8[0x04];
    unsigned int* fStateMasks[40];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall D2Common_STATES_ToggleState_6FDB8900(D2UnitStrc* pUnit, int nState, int bSet); // 0x00625A70
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit); // 0x00625BB0
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit); // 0x00625BE0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

// 0x00639DB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        D2Common_STATES_ToggleState_6FDB8900(pUnit, nState, bSet);
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x00639FB0
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);

    if (pGfxFlags && pStatFlags)
    {
        const int nCount = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
        if (bIsBoss)
        {
            for (int i = 0; i < nCount; ++i)
            {
                pGfxFlags[i] |= pStatFlags[i] & ~sgptDataTables->fStateMasks[STATEMASK_BOSSSTAYDEATH][i];
                pStatFlags[i] &= sgptDataTables->fStateMasks[STATEMASK_BOSSSTAYDEATH][i];
            }
        }
        else if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            for (int i = 0; i < nCount; ++i)
            {
                pGfxFlags[i] |= pStatFlags[i] & ~sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][i];
                pStatFlags[i] &= sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][i];
            }
        }
        else
        {
            for (int i = 0; i < nCount; ++i)
            {
                pGfxFlags[i] |= pStatFlags[i] & ~sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][i];
                pStatFlags[i] &= sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][i];
            }
        }

        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x0063A180
void __stdcall sub_0063A180_UpdateGfxFlagsWithMask(D2UnitStrc* pUnit, unsigned int* pMask)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);

    if (pGfxFlags && pStatFlags)
    {
        for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
        {
            pGfxFlags[i] |= pMask[i] & pStatFlags[i];
            pStatFlags[i] &= ~pMask[i];
        }

        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x00639E30
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    if (pGfxFlags && nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (bSet)
        {
            pGfxFlags[nState >> 5] |= gdwBitMasks[nState & 31];
        }
        else
        {
            pGfxFlags[nState >> 5] &= gdwInvBitMasks[nState & 31];
        }
        UNITROOM_RefreshUnit(pUnit);
    }
}
