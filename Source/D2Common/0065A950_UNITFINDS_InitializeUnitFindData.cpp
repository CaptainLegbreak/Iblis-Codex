struct D2UnitFindArgStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

typedef int(__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit, D2UnitFindArgStrc* pUnitFindArg);

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    UNITFINDTEST pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nIndex;
    int nFlags;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);             // 0x0040B480
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0065A950
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg)
{
    D2_ASSERT(pUnitFindData, 226);

    pUnitFindData->pUnitsArray = (D2UnitStrc**)FOG_AllocPool(pMemPool, sizeof(D2UnitStrc*) * 15, ".\\UNITS\\UnitFinds.cpp", 228, 0);
    D2_ASSERT(pUnitFindData->pUnitsArray, 229);
    memset(pUnitFindData->pUnitsArray, 0, sizeof(D2UnitStrc*) * 15);

    pUnitFindData->pRoom = pRoom;
    pUnitFindData->nX = nX;
    pUnitFindData->nY = nY;
    pUnitFindData->pMemPool = pMemPool;
    pUnitFindData->nMaxArrayEntries = 15;
    pUnitFindData->nFlags = 0;
    pUnitFindData->nIndex = 0;
    pUnitFindData->nSize = nSize;
    pUnitFindData->pfnUnitTest = pfnUnitTest;
    pUnitFindData->pUnitFindArg = pUnitFindArg;
}

// 0x0065AA00
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData)
{
    if (pUnitFindData && pUnitFindData->pUnitsArray)
    {
        FOG_FreePool(pUnitFindData->pMemPool, pUnitFindData->pUnitsArray, ".\\UNITS\\UnitFinds.cpp", 255, 0);
        pUnitFindData->pUnitsArray = 0;
    }
}
