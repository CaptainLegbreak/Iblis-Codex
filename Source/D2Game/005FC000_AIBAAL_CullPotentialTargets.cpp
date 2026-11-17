struct D2GameStrc;
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

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x005FC000
int __fastcall AIBAAL_CullPotentialTargets(D2UnitStrc* pBaal, D2UnitStrc* pTarget)
{
    D2_ASSERT(pBaal, 285);
    D2_ASSERT(pTarget, 286);

    if (pBaal->nAct != pTarget->nAct)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTarget, CLIENTS_GetUnitX(pBaal), CLIENTS_GetUnitY(pBaal)) < 1020;
}
