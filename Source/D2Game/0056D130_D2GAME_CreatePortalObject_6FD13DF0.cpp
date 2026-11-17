struct D2GameStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel); // 0x0056CF40
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                         // 0x0061A1B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                               // 0x0061AB00
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet);                             // 0x0061AED0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit);                                      // 0x006222C0
struct D2PortalFlagsStrc
{
    unsigned char nFlags;
};

void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, D2PortalFlagsStrc portalFlags);                // 0x00622300
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighboringRooms); // 0x0064E810

// 0x0056D130
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm)
{
    D2_ASSERT(pRoom, 0xE42);

    if (ppSourceUnit)
    {
        *ppSourceUnit = 0;
    }

    if (pUnit && DUNGEON_IsRoomInTown(pRoom))
    {
        if ((nDestLevel != 0x27 && nDestLevel != 0x88 && nDestLevel != 0x85 && nDestLevel != 0x86 && nDestLevel != 0x87) || nObjectId != 0x3C)
        {
            SUNIT_AttachSound(pUnit, 0x18, pUnit);
            return 0;
        }
    }

    const unsigned char nAct = DRLG_GetActNoFromLevelId(nDestLevel);
    const int nSourceLevel = DUNGEON_GetLevelIdFromRoom(pRoom);

    D2_ASSERT(nAct == DRLG_GetActNoFromLevelId(nSourceLevel), 0xE5C);

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (!bPerm)
    {
        if (!COLLISION_GetFreeCoordinatesWithField(pRoom, &coords, &coords, 3, 0x3E01, 0xC01, 0))
        {
            return 0;
        }
    }

    const int nTargetX = coords.nX;
    const int nTargetY = coords.nY;

    D2ActiveRoomStrc* pTargetRoom = D2GAME_GetRoom_6FC52070(pRoom, nTargetX, nTargetY);
    if (!pTargetRoom)
    {
        return 0;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(2, nObjectId, nTargetX, nTargetY, pGame, pTargetRoom, 1, 1, 0);
    if (ppSourceUnit)
    {
        *ppSourceUnit = pPortal;
    }

    UNITS_ChangeAnimMode(pPortal, 1);

    D2UnitStrc* pLinkPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, pUnit, pPortal, nDestLevel, nSourceLevel);
    if (!pLinkPortal)
    {
        return 0;
    }

    D2PortalFlagsStrc portalFlags;
    portalFlags.nFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, portalFlags);
    DUNGEON_ToggleHasPortalFlag(pTargetRoom, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pLinkPortal), 0);
    return 1;
}
