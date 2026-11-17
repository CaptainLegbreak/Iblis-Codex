struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpDifficultylevelsTxt;                                                                         // 0x0096C8AC
int gnDifficultylevelsTxtRecordCount;                                                                       // 0x0096C8B0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00617D90
void __stdcall DATATBLS_LoadDifficultyLevelsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "ResistPenalty", 2, 0, 0, 0 },
        { "DeathExpPenalty", 2, 0, 4, 0 },
        { "UberCodeOddsNormal", 2, 0, 8, 0 },
        { "UberCodeOddsGood", 2, 0, 12, 0 },
        { "UltraCodeOddsNormal", 2, 0, 32, 0 },
        { "UltraCodeOddsGood", 2, 0, 36, 0 },
        { "LifeStealDivisor", 2, 0, 40, 0 },
        { "ManaStealDivisor", 2, 0, 44, 0 },
        { "MonsterSkillBonus", 2, 0, 16, 0 },
        { "MonsterFreezeDivisor", 2, 0, 20, 0 },
        { "MonsterColdDivisor", 2, 0, 24, 0 },
        { "AiCurseDivisor", 2, 0, 28, 0 },
        { "UniqueDamageBonus", 2, 0, 48, 0 },
        { "ChampionDamageBonus", 2, 0, 52, 0 },
        { "HireableBossDamagePercent", 2, 0, 56, 0 },
        { "MonsterCEDamagePercent", 2, 0, 60, 0 },
        { "StaticFieldMin", 2, 0, 64, 0 },
        { "GambleRare", 2, 0, 68, 0 },
        { "GambleSet", 2, 0, 72, 0 },
        { "GambleUnique", 2, 0, 76, 0 },
        { "GambleUber", 2, 0, 80, 0 },
        { "GambleUltra", 2, 0, 84, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpDifficultylevelsTxt = DATATBLS_CompileTxt(hArchive, "difficultylevels", pTbl, &gnDifficultylevelsTxtRecordCount, 88);
    TBL_ASSERT(gnDifficultylevelsTxtRecordCount == 3, 1567);
}
