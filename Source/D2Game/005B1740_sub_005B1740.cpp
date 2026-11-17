extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(int (__stdcall* lpfn)());                       // 0x006CC34C

#define UNIT_MONSTER 1

struct D2GameStrc;
struct D2UnitStrc;
struct D2AiTickParamStrc;

typedef void (__fastcall* AIPARAMFN)(D2GameStrc*, D2UnitStrc*, D2AiTickParamStrc*);

struct D2AiControlStrc
{
    int nAiSpecialState;
    AIPARAMFN pAiParamFn;
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
    char unk0x08[0x0C];
    D2MonsterDataStrc* pMonsterData;
};

struct D2MonStatsTxt
{
    char unk0x000[0x18];
    short wMonStatsEx;
    char unk0x01A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x000[0x134];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
    D2MonStats2Txt* pMonstats2Txt;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    char unk0xA94[0x04];
    int nMonStats2TxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall sub_005B10E0_AiTickPreChecks(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B10E0
int __fastcall sub_005B1650_AiTickTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);    // 0x005B1650
int __fastcall sub_005B13E0_AiMeleeWalkTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B13E0

static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}
static __forceinline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMonsterId = pUnit->dwClassId;
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nMonsterId];
        }
    }
    return 0;
}
static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecordFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMonsterId = pUnit->dwClassId;
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
            if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
            {
                return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
            }
        }
    }
    return 0;
}
// 0x005B1740
void __fastcall sub_005B1740(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    D2AiTickParamStrc aiTickParam = {};
    aiTickParam.pAiControl = AIGENERAL_GetAiControlFromUnit_Inline(pUnit);
    aiTickParam.pMonstatsTxt = MONSTERMODE_GetMonStatsTxtRecordFromUnit_Inline(pUnit);
    aiTickParam.pMonstats2Txt = MONSTERREGION_GetMonStats2TxtRecordFromUnit_Inline(pUnit);
    if (!aiTickParam.pMonstatsTxt || !aiTickParam.pMonstats2Txt)
    {
        return;
    }
    if (sub_005B10E0_AiTickPreChecks(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    if (sub_005B1650_AiTickTarget(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    if (sub_005B13E0_AiMeleeWalkTarget(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    D2_ASSERT(!IsBadCodePtr((int (__stdcall*)())aiTickParam.pAiControl->pAiParamFn), 0x39E);
    aiTickParam.pAiControl->pAiParamFn(pGame, pUnit, &aiTickParam);
}
