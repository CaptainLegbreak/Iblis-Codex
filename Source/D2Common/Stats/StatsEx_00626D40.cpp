struct D2StatListEx00626D40Strc
{
    void* pMemPool;
    int unk0x04;
    unsigned int dwOwnerType;
    unsigned int dwOwnerGUID;
    unsigned int dwFlags;
    char unk0x14[0x44 - 0x14];
    void* pOwner;
    char unk0x48[0x58 - 0x48];
    unsigned int* pStatFlags;
    void* pfOnStatChanged;
    void* pGame;
};

struct D2Unit00626D40Strc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    char unk0x10[0x5C - 0x10];
    D2StatListEx00626D40Strc* pStatListEx;
};

struct D2DataTables00626D40Strc
{
    char unk0x00[0xC4];
    int nItemStatCostTxtRecordCount;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListEx00626D40Strc* pStatListEx); // 0x00626C00
extern D2DataTables00626D40Strc* sgptDataTables; // 0x00744304

// 0x00626D40
void __stdcall STATLIST_AllocStatListEx(D2Unit00626D40Strc* pUnit, int nFlags, void* pCallbackFunc, void* pGame)
{
    if (pUnit->pStatListEx)
    {
        if (pUnit->pStatListEx->dwFlags & 0x80000000)
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pUnit->pStatListEx);
        }
        pUnit->pStatListEx = 0;
    }

    D2StatListEx00626D40Strc* pStatListEx = (D2StatListEx00626D40Strc*)sub_0040B430(pUnit->pMemoryPool, sizeof(D2StatListEx00626D40Strc), ".\\Stats\\StatsEx.cpp", 0x586, 0);
    memset(pStatListEx, 0, sizeof(D2StatListEx00626D40Strc));
    pStatListEx->pMemPool = pUnit->pMemoryPool;
    pStatListEx->dwOwnerType = !pUnit ? 6 : pUnit->dwUnitType;
    pStatListEx->dwOwnerGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pStatListEx->dwFlags = nFlags & 1 | 0x80000000;
    pStatListEx->pfOnStatChanged = pCallbackFunc;
    pStatListEx->pGame = pGame;
    pStatListEx->pOwner = pUnit;
    const int nSize = sizeof(unsigned int) * 2 * ((sgptDataTables->nItemStatCostTxtRecordCount + 31) / 32);
    pStatListEx->pStatFlags = (unsigned int*)sub_0040B430(pUnit->pMemoryPool, nSize, ".\\Stats\\StatsEx.cpp", 0x593, 0);
    memset(pStatListEx->pStatFlags, 0, nSize);
    pUnit->pStatListEx = pStatListEx;
}
