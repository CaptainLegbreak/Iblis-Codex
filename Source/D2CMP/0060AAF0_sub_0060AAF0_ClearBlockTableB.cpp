extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);               // 0x006CC208
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);               // 0x006CC204
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* lpCriticalSection);         // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);             // 0x006CC1FC

struct D2CmpBlockTableAStrc
{
    unsigned char data[0x1000];
};

struct D2CmpBlockTableBStrc
{
    unsigned char data[0x10000];
};

struct T00604AE0
{
    unsigned int nKey;
    char szName[0x20];
    int nValue;
    T00604AE0* pPrev;
    T00604AE0* pNext;
};

struct D2CelDataHashStrc
{
    int nCheck[0x200];
    T00604AE0* pBuckets[0x200];
};

struct D2FindTileEntryStrc;

long gnTileLockRefCount_008F03E4;                                                                           // 0x008F03E4
char gTileLock_008F03CC[0x18];                                                                              // 0x008F03CC

// 0x0060AAF0
void __fastcall sub_0060AAF0_ClearBlockTableB(D2CmpBlockTableBStrc* pTable)
{
    memset(pTable, 0, sizeof(D2CmpBlockTableBStrc));
}

// 0x0060AEE0
void __fastcall sub_0060AEE0_ClearBlockTableA(D2CmpBlockTableAStrc* pTable)
{
    memset(pTable, 0, sizeof(D2CmpBlockTableAStrc));
}

// 0x0060AF90
T00604AE0* __fastcall sub_0060AF90_CelDataHashFind(D2CelDataHashStrc* pHash, const char* szName)
{
    if (!*szName)
        return 0;

    unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nKey = ((((((nHash >> 8) ^ nHash) >> 8) ^ nHash) >> 8) ^ nHash) & 0x1FF;
    for (T00604AE0* pEntry = pHash->pBuckets[nKey]; pEntry; pEntry = pEntry->pNext)
    {
        if (!strcmp(szName, pEntry->szName))
            return pEntry;
    }
    return 0;
}

// 0x0060CD30
void __cdecl sub_0060CD30_InitTileLock()
{
    if (InterlockedIncrement(&gnTileLockRefCount_008F03E4) == 1)
        InitializeCriticalSection(gTileLock_008F03CC);
}

// 0x0060CD50
void __cdecl sub_0060CD50_ReleaseTileLock()
{
    if (InterlockedDecrement(&gnTileLockRefCount_008F03E4) == 0)
        DeleteCriticalSection(gTileLock_008F03CC);
}

// 0x0060CDB0
D2FindTileEntryStrc** __cdecl sub_0060CDB0_AllocFindTilesTable()
{
    D2FindTileEntryStrc** ppBuckets = (D2FindTileEntryStrc**)FOG_Alloc(0x200, ".\\SRC\\FindTiles.cpp", 0x2A, 0);
    D2_ASSERT(ppBuckets, 0x2B);
    memset(ppBuckets, 0, 0x200);
    return ppBuckets;
}
