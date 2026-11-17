struct D2UnitFindArgStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xE8 - 8];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

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

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms);// 0x00619790
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* pfn);                                     // 0x006CC34C
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

#define UF_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline int UnitGetType(D2UnitStrc* pUnit) { return pUnit ? pUnit->dwUnitType : 6; }
inline int UnitGetClassId(D2UnitStrc* pUnit) { return pUnit ? pUnit->dwClassId : -1; }

// 0x0065A590
int __stdcall UNITFINDS_AreUnitsInNeighboredRooms(D2UnitStrc* pDestUnit, D2UnitStrc* pSrcUnit)
{
    UF_ASSERT(pDestUnit, 24);
    UF_ASSERT(pSrcUnit, 25);

    D2ActiveRoomStrc* pSrcRoom = UNITS_GetRoom(pSrcUnit);
    if (pSrcRoom)
    {
        D2ActiveRoomStrc* pDestRoom = UNITS_GetRoom(pDestUnit);
        if (pDestRoom)
        {
            D2ActiveRoomStrc** ppRoomList;
            int nNumRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pSrcRoom, &ppRoomList, &nNumRooms);

            for (int i = 0; i < nNumRooms; ++i)
            {
                if (ppRoomList[i] == pDestRoom)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// build: context UNITFINDS_InitializeUnitFindData
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg)
{
    UF_ASSERT(pUnitFindData, 226);

    pUnitFindData->pUnitsArray = (D2UnitStrc**)sub_0040B430(pMemPool, sizeof(D2UnitStrc*) * 15, ".\\UNITS\\UnitFinds.cpp", 228, 0);
    UF_ASSERT(pUnitFindData->pUnitsArray, 229);
    memset(pUnitFindData->pUnitsArray, 0, sizeof(D2UnitStrc*) * 15);

    pUnitFindData->nIndex = 0;
    pUnitFindData->nFlags = 0;
    pUnitFindData->pRoom = pRoom;
    pUnitFindData->nX = nX;
    pUnitFindData->nY = nY;
    pUnitFindData->pMemPool = pMemPool;
    pUnitFindData->nMaxArrayEntries = 15;
    pUnitFindData->nSize = nSize;
    pUnitFindData->pfnUnitTest = pfnUnitTest;
    pUnitFindData->pUnitFindArg = pUnitFindArg;
}

// 0x0065AA00
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData)
{
    if (pUnitFindData && pUnitFindData->pUnitsArray)
    {
        sub_0040B480(pUnitFindData->pMemPool, pUnitFindData->pUnitsArray, ".\\UNITS\\UnitFinds.cpp", 255, 0);
        pUnitFindData->pUnitsArray = 0;
    }
}
