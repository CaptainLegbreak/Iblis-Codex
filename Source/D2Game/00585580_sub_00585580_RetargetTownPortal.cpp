struct D2GameStrc;
struct D2ActiveRoomStrc;

struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char nInteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
};

struct D2PortalFlags00585580Strc
{
    unsigned char nFlags;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall sub_00553720_GetPortalPair(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x00553720
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, unsigned char nDestLevel, int nSourceLevel); // 0x0056CF40
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit);                                      // 0x006222C0
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, D2PortalFlags00585580Strc tFlags);             // 0x00622300
int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag);                          // 0x00622350
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

// 0x00585580
void __fastcall sub_00585580_RetargetTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPortalGUID, int nDestLevel)
{
    D2_ASSERT(pGame, 0x11DD);

    D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, nPortalGUID);
    if ((pPortal ? pPortal->dwClassId : -1) != 0x3B || UNITS_CheckObjectPortalFlag(pPortal, 1))
    {
        return;
    }

    D2UnitStrc* pPair = sub_00553720_GetPortalPair(pGame, pPortal);
    if (!pPair)
    {
        return;
    }

    D2_ASSERT(pPair->dwClassId == 0x3B, 0x11EA);
    D2_ASSERT((unsigned char)nDestLevel <= 0xFF, 0x11EC);

    pPortal->pObjectData->nInteractType = (unsigned char)nDestLevel;
    D2PortalFlags00585580Strc tFlags;
    tFlags.nFlags = UNITS_GetObjectPortalFlags(pPortal) | 1;
    UNITS_SetObjectPortalFlags(pPortal, tFlags);
    UNITS_ChangeAnimMode(pPortal, 3);

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPair), 2, !pPair ? -1 : pPair->dwUnitId);
    SUNIT_RemoveUnit(pGame, pPair);

    D2UnitStrc* pLinkPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, pPlayer, pPortal, nDestLevel, DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal)));
    D2_ASSERT(pLinkPortal, 0x11FB);

    tFlags.nFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, tFlags);
}
