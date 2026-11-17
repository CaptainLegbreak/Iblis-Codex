extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x14];
    unsigned char nAct;
    char unk0x19[3];
    void* pDrlgAct;
    char unk0x20[0xC];
    D2DynamicPathStrc* pDynamicPath;
};

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_004654C0_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags);                // 0x004654C0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __stdcall D2Common_10214(D2UnitStrc* pUnit);                                                           // 0x00649CA0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit);                                                           // 0x0063EA40
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                  // 0x00648C30
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall sub_0061AB30(D2ActiveRoomStrc* pRoom);                                                        // 0x0061AB30
void __fastcall sub_0044DB40(int nDelay);                                                                   // 0x0044DB40

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634

// 0x0045D160
void __fastcall sub_0045D160(const unsigned char* pPacket)
{
    const unsigned short nX = *(const unsigned short*)(pPacket + 6);
    const unsigned short nY = *(const unsigned short*)(pPacket + 8);
    D2UnitStrc* pUnit = sub_00463990(*(const int*)(pPacket + 2), pPacket[1]);
    if (!pUnit)
        return;
    sub_004654C0_SetUnitPosition(pUnit, nX, nY, pPacket[0xA]);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpGlobal_007A0634;
        if (pUnit->pDynamicPath)
        {
            if (pUnit->dwUnitType == 0)
            {
                D2Common_10214(pUnit);
                PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x1C09);
            }
            else if (pUnit->dwUnitType == 1 && !MONSTERS_IsDead(pUnit))
            {
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x100);
            }
        }
        if (pUnit == sub_00463DD0())
        {
            D2_ASSERT(!sub_0061AB30(UNITS_GetRoom(pUnit)), 0x81E);
            sub_0044DB40(3000);
        }
    }
    else
    {
        D2_ASSERT(pRoom, 0x538);
    }
}
