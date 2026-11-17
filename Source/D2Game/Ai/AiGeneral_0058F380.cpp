#include "D2Game.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C
struct D2AiCmdStrc;

enum D2C_F33Ai2Constants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
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

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

__forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0058F380
void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*))
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)pfnParty), 590);

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pUnit);
    if (!pAiControl || !pAiControl->pGame)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pAiControl->pGame, pAiControl->dwOwnerTypeEx, pAiControl->dwOwnerGUIDEx);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerType != UNIT_MONSTER)
    {
        return;
    }

    D2AiControlStrc* pOwnerAiControl = AIGENERAL_GetAiControlFromUnit(pOwner);
    D2GameStrc* pGame = pOwnerAiControl->pGame;
    D2MinionListStrc* pMinionList = pOwnerAiControl->pMinionList;
    while (pMinionList)
    {
        D2MinionListStrc* pNext = pMinionList->pNext;
        D2UnitStrc* pMinion = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pMinionList->dwMinionGUID);
        if (pMinion)
        {
            pfnParty(pMinion, a2, a3);
        }
        pMinionList = pNext;
    }
}
