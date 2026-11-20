#include "D2Game.h"

struct D2MonStatsTxt
{
    char unk0x00[30];
    short wAI;
};
struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[12];
    D2MonsterDataStrc* pMonsterData;
    unsigned char nAct;
};
struct D2AiTableStrc
{
    int unk0x00;
    void* unk0x04;
    void* pAiParamFn;
    void* unk0x0C;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY);               // 0x005DC530
extern const D2AiTableStrc gpAiTable_6FD3F990[148];                                                         // 0x0073CA18
extern const D2AiTableStrc gpSpecialAiStateTable_6FD40290[18];                                              // 0x0073D358

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define AISPECIALSTATE_DIMVISION 10
#define AISPECIALSTATE_TERROR 11
#define AISPECIALSTATE_TAUNT 12
#define AI_TABLE_COUNT 0x94

// 0x005E8EB0
int __fastcall AITHINK_CullPotentialTargetsForDiablo(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2_ASSERT(pUnit, 876);
    D2_ASSERT(pTarget, 877);

    if (pUnit->nAct != pTarget->nAct)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTarget, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) < 1020;
}

#include "gen/data/Source/D2Game/Unknown_005E8EB0.inc"
#include "D2Constants.h"
