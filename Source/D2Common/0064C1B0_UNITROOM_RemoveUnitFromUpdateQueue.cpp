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

D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate);            // 0x00619F90
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

// 0x0064C1B0
void __stdcall UNITROOM_RemoveUnitFromUpdateQueue(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 301);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        D2_ASSERT(!pUnit->pChangeNextUnit, 312);
        return;
    }

    D2UnitStrc** ppChangeUnit = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 0);
    D2UnitStrc* pChangeUnit = *ppChangeUnit;
    D2UnitStrc* pPreviousChangeUnit = 0;
    for (; pChangeUnit; pChangeUnit = pChangeUnit->pChangeNextUnit)
    {
        if (pChangeUnit == pUnit)
        {
            break;
        }

        pPreviousChangeUnit = pChangeUnit;
    }

    if (pChangeUnit)
    {
        if (!pPreviousChangeUnit)
        {
            *ppChangeUnit = pChangeUnit->pChangeNextUnit;
            pChangeUnit->pChangeNextUnit = 0;
        }
        else
        {
            pPreviousChangeUnit->pChangeNextUnit = pChangeUnit->pChangeNextUnit;
            pChangeUnit->pChangeNextUnit = 0;
        }
    }
}
