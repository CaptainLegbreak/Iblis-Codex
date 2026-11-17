struct D2DrlgActStrc;
struct D2ActiveRoomStrc;
struct D2ObjectDataStrc { int unk_00; unsigned char nLevelId; char unk_05[0x13]; int nX; int nY; };
struct D2UnitStrc { char unk_00[0x14]; D2ObjectDataStrc* pObjectData; char unk_18[0x7C]; int dwOwnerType; int dwOwnerGUID; };
struct D2GameStrc { char unk_00[0xBC]; D2DrlgActStrc* pAct[5]; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ActiveRoomStrc* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0
D2ActiveRoomStrc* __stdcall sub_0061A140_FindRoom(D2DrlgActStrc* pAct, int nX, int nY); // 0x0061A140
void __fastcall GAME_ActivateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0052D0F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

// 0x00553720
D2UnitStrc* __fastcall sub_00553720_ResolveObjectOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1930); exit(-1); }
    const unsigned char nLevelId = pUnit->pObjectData->nLevelId;
    const int nAct = DRLG_GetActNoFromLevelId(nLevelId);
    const int nX = pUnit->pObjectData->nX;
    const int nY = pUnit->pObjectData->nY;

    if (!sub_00619DA0_ActLookup(pGame->pAct[nAct], nX, nY))
    {
        D2ActiveRoomStrc* pRoom = sub_0061A140_FindRoom(pGame->pAct[nAct], nX, nY);
        if (pRoom)
            GAME_ActivateRoom(pGame, pRoom);
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}
