extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2UnitStrc;

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct T004013C0
{
    char unk0x00[0x0C];
    unsigned int nTotalMemory;
};

T004013C0* __cdecl sub_00407360_GetSystemInfo();                                                     // 0x00407360
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
void __fastcall sub_00481840_SetCacheSize(unsigned int nSize);                                              // 0x00481840
void __stdcall sub_005FE120_InitCelPool(void* pMemPool, int nArg);                                          // 0x005FE120
void __stdcall D2CMP_InitSpriteCache(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40
void __fastcall sub_00470200_InitTables(int nSize);                                                         // 0x00470200
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004C52E0(D2UnitStrc* pUnit, int* pTargetX, int* pTargetY);                       // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

// 0x00457300
void __fastcall sub_00457300_InitGfxCaches(void* pMemPool, int bCelPool)
{
    T004013C0* pInfo = sub_00407360_GetSystemInfo();
    D2_ASSERT(pInfo, 0x30);
    if (pInfo->nTotalMemory < 0x167D000)
    {
        sub_00410610_WriteLogLine("This machine doesn't have enough physical memory (> %.2f MB) for minimal performance!", (float)pInfo->nTotalMemory / 1048576.0);
        exit(-1);
    }
    unsigned int nSize = pInfo->nTotalMemory - 0xB00000;
    unsigned int nCacheSize = nSize * 10 / 100;
    nCacheSize = D2_MIN(D2_MAX(nCacheSize, 0x300000u), 0x500000u);
    sub_00481840_SetCacheSize(nCacheSize);
    unsigned int nRest = nSize - nCacheSize;
    if (bCelPool)
    {
        nRest -= 0x600000;
        sub_005FE120_InitCelPool(pMemPool, 0x600000);
    }
    nRest -= 0x200000;
    unsigned int nMaxSize = D2_MIN(D2_MAX(nRest / 3, 0x1800000u), 0x4000000u);
    D2CMP_InitSpriteCache(pMemPool, nMaxSize, 0x7D000, nSize);
    sub_00470200_InitTables(0x200000);
}

// 0x004C7400
D2UnitStrc* __fastcall sub_004C7400_CreateTargetedMissile(D2UnitStrc* pUnit, int nMissile, int nSkill, int nSkillLevel,
    int nTargetX, int nTargetY)
{
    D2UnitStrc* pResult;
    if ((nTargetX && nTargetY) || (pResult = sub_004C52E0(pUnit, &nTargetX, &nTargetY)) != 0)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 1;
        tMissileParams.pOwner = pUnit;
        tMissileParams.nX = nTargetX;
        tMissileParams.nY = nTargetY;
        tMissileParams.nSkill = nSkill;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        pResult = sub_004CD540_CreateMissile(&tMissileParams);
    }
    return pResult;
}
