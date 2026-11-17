extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x2C - 0x04];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0xC4 - 0x30];
    unsigned int dwFlags;
    char unk0xC8[0xE0 - 0xC8];
    D2UnitStrc* pChangeNextUnit;
    char unk0xE4[0xE8 - 0xE4];
    D2UnitStrc* pRoomNext;
};

D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom);                               // 0x00619F60
D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate);            // 0x00619F90
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __stdcall sub_0064FC20_ResetDynamicPathRoom(D2DynamicPathStrc* pDynamicPath);                          // 0x0064FC20

// 0x0064C160
void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc** ppChangeUnit = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 0);
    D2UnitStrc* pChangeUnit = *ppChangeUnit;
    while (pChangeUnit)
    {
        D2UnitStrc* pNextChangeUnit = pChangeUnit->pChangeNextUnit;
        pChangeUnit->dwFlags &= ~0x2000;
        pChangeUnit->pChangeNextUnit = 0;
        pChangeUnit = pNextChangeUnit;
    }

    *ppChangeUnit = 0;
}

// 0x0064C260
int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 340);

    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* pRoomUnit = *DUNGEON_GetUnitListFromRoom(pRoom);
    while (pRoomUnit != pUnit)
    {
        pRoomUnit = pRoomUnit->pRoomNext;
        if (!pRoomUnit)
        {
            return 0;
        }
    }

    return 1;
}

// 0x0064C450
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 210);

    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
    {
        D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
        if (pStaticPath->pRoom)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        pStaticPath->pRoom = 0;
        break;
    }

    default:
        sub_0064FC20_ResetDynamicPathRoom(pUnit->pDynamicPath);
        break;
    }
}
