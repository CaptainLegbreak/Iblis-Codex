extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2ObjectRegionStrc
{
    unsigned char nAct;
    char unk0x01[7];
    int nMinDistance;
    char unk0x0C[0x10];
    int nWanderCount;
    char unk0x20[0x70];
};
struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
    int nShrineCounts[8];
    int* pShrineIds[8];
    D2ObjectRegionStrc* pObjectRegion[1024];
    char unk0x1048[0xC8];
    void* unk0x1110;
};
struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0xB0];
    D2SeedStrc pGameSeed;
    char unk0xD8[0x1018];
    D2ObjectControlStrc* pObjectControl;
};
struct D2DataTablesStrc { char unk0x00[0xC5C]; int nLevelsTxtRecordCount; };
struct D2LevelsTxt { char unk0x00[3]; unsigned char nAct; };
struct D2ShrinesTxt { char unk0x00[0xB2]; unsigned char nClass; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId); // 0x006414B0
int __cdecl sub_00641500(); // 0x00641500
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
inline unsigned __int64 OBJECTS_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return seed;
}
// 0x00546C60
unsigned int __fastcall sub_00546C60_AllocObjectControl(D2GameStrc* pGame)
{
    if (!pGame)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 41);
        exit(-1);
    }
    D2ObjectControlStrc* pControl = (D2ObjectControlStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ObjectControlStrc), ".\\OBJECTS\\objrgn.cpp", 42, 0);
    pGame->pObjectControl = pControl;
    SEED_InitSeed(&pControl->pSeed);
    const unsigned int nSeed = (unsigned int)OBJECTS_RollGameSeed(&pGame->pGameSeed);
    SEED_InitLowSeed(&pControl->pSeed, nSeed);
    pControl->pObjectRegion[0] = 0;
    pControl->unk0x1110 = 0;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; i += 1)
    {
        D2ObjectRegionStrc* pRegion = (D2ObjectRegionStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ObjectRegionStrc), ".\\OBJECTS\\objrgn.cpp", 54, 0);
        D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(i);
        memset(pRegion, 0, sizeof(D2ObjectRegionStrc));
        pRegion->nWanderCount = -1;
        pRegion->nAct = pLevelsTxt->nAct;
        pRegion->nMinDistance = 0x7FFFFFFF;
        pControl->pObjectRegion[i] = pRegion;
    }
    const int nShrines = sub_00641500();
    int nClassCounts[8] = {};
    for (int i = 0; i < nShrines; i += 1)
    {
        const unsigned char nClass = DATATBLS_GetShrinesTxtRecord(i)->nClass;
        if (nClass < 8)
            ++nClassCounts[nClass];
    }
    memset(pControl->unk0x1048, 0, sizeof(pControl->unk0x1048));
    memset(pControl->pShrineIds, 0, sizeof(pControl->pShrineIds));
    for (int i = 0; i < 8; i += 1)
    {
        if (nClassCounts[i] > 0)
        {
            pControl->pShrineIds[i] = (int*)FOG_AllocPool(pGame->pMemoryPool, 4 * nClassCounts[i], ".\\OBJECTS\\objrgn.cpp", 84, 0);
            memset(pControl->pShrineIds[i], 0, 4 * nClassCounts[i]);
        }
        pControl->nShrineCounts[i] = 0;
    }
    for (int i = 0; i < nShrines; i += 1)
    {
        const unsigned char nClass = DATATBLS_GetShrinesTxtRecord(i)->nClass;
        if (nClass < 8)
        {
            pControl->pShrineIds[nClass][pControl->nShrineCounts[nClass]] = i;
            pControl->nShrineCounts[nClass] += 1;
        }
    }
    return nSeed;
}
