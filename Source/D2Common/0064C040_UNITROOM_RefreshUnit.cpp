struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xBC];
    unsigned int dwFlags;
    char unk0xC8[0x18];
    D2UnitStrc* pChangeNextUnit;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate);           // 0x00619F90
int __stdcall D2Common_10084(D2ActiveRoomStrc* pRoom);                                                      // 0x0061AB60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

// 0x0064C040
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 123);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && !D2Common_10084(pRoom) && !(pUnit->dwFlags & 0x2000))
    {
        pUnit->dwFlags |= 0x2000;

        D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 1);
        D2_ASSERT(ppUnitFirst, 142);

        pUnit->pChangeNextUnit = *ppUnitFirst;
        *ppUnitFirst = pUnit;
    }
}
