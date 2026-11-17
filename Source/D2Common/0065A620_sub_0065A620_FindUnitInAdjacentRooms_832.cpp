extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    unsigned char pMemoryPool[0xE0];
    D2UnitStrc* pRoomNext;
};
struct D2ActiveRoomStrc
{
    unsigned char unk_00[0x74];
    D2UnitStrc* pUnitFirst;
};
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790

static inline int UNITS_GetUnitTypeOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int UNITS_GetClassIdOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x0065A620
D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId)
{
    D2_ASSERT(pRoom, 0x31);
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (int i = 0; i < nNumRooms; ++i)
    {
        D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst;
        while (pUnit)
        {
            if (UNITS_GetUnitTypeOrInvalid_Inline(pUnit) == nUnitType && UNITS_GetClassIdOrInvalid_Inline(pUnit) == nClassId)
            {
                return pUnit;
            }
            pUnit = pUnit->pRoomNext;
        }
    }
    return 0;
}
