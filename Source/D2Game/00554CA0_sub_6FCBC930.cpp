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
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pMissile);                                      // 0x00553490
void __fastcall sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x00554670
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50
int __stdcall D2Common_10226(D2UnitStrc* pUnit, int nFlag);                                                 // 0x00650840

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00554CA0
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2_ASSERT(pGame, 1838);

    sub_6FCBC7E0(pGame, pMissile);
    const int v4 = D2Common_10226(pMissile, 1024) ? 1 : 2;
    if (UNITS_IsCurrentRoomInvalid(pMissile))
    {
        sub_6FCBB190(pGame, pMissile, 0);
    }

    return v4;
}
