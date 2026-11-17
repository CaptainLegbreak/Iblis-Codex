extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4 - 0x04];
    unsigned int dwFlags;
    char unk0xC8[0xE0 - 0xC8];
    D2UnitStrc* pChangeNextUnit;
    char unk0xE4[0xE8 - 0xE4];
    D2UnitStrc* pRoomNext;
};

D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom);                               // 0x00619F60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom);                                  // 0x00619F20
void __stdcall UNITS_ResetRoom(D2UnitStrc* pUnit);                                                          // 0x00620B50
void __stdcall UNITROOM_RemoveUnitFromUpdateQueue(D2UnitStrc* pUnit);                                       // 0x0064C1B0

// 0x0064C370
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit)
{
    int bReset = 0;

    D2_ASSERT(pUnit, 245);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        D2_ASSERT(!pUnit->pRoomNext, 253);
        return;
    }

    D2UnitStrc** ppRoomUnit = DUNGEON_GetUnitListFromRoom(pRoom);
    D2UnitStrc* pRoomUnit = *ppRoomUnit;
    D2UnitStrc* pPreviousUnit = 0;
    for (; pRoomUnit; pRoomUnit = pRoomUnit->pRoomNext)
    {
        if (pRoomUnit == pUnit)
        {
            break;
        }

        pPreviousUnit = pRoomUnit;
    }

    if (pRoomUnit)
    {
        bReset = 1;
        if (!pPreviousUnit)
        {
            *ppRoomUnit = pRoomUnit->pRoomNext;
        }
        else
        {
            pPreviousUnit->pRoomNext = pRoomUnit->pRoomNext;
        }

        pRoomUnit->pRoomNext = 0;

        switch (pUnit->dwUnitType)
        {
        case 0:
            DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            break;

        case 1:
            if (STATLIST_GetUnitAlignment(pUnit) == 2)
            {
                DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            }
            break;
        }
    }

    UNITROOM_RemoveUnitFromUpdateQueue(pUnit);
    pUnit->dwFlags &= ~0x2000;
    if (bReset)
    {
        UNITS_ResetRoom(pUnit);
    }
}
