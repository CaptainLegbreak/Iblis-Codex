// build: context GetSkillsRecord
// build: context UnitHasFlag

struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc { char unk_00[0xC4]; unsigned int dwFlags; };
struct D2CoordStrc { int nX; int nY; };
struct D2SkillsTxt { char unk_00[8]; unsigned char nFlags[4]; char unk_0C[0x22]; unsigned short wSrvDoFunc; char unk_30[0x20C]; };
struct D2DataTablesStrc { char unk_00[0xB98]; D2SkillsTxt* pSkillsTxt; int unk_B9C; int nSkillsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall sub_6FC6A810(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTarget, int a6, short a7); // 0x005B34C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40
int __stdcall sub_00645910_TestLine(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180
int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, unsigned short nMask); // 0x0064D910
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
static __forceinline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static __forceinline int UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (!(pUnit))
    {
        return 0;
    }
    return (pUnit->dwFlags & nFlag) != 0;
}
// 0x005FD470
int __fastcall sub_005FD470(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt) return 0;
    if (nSkillId == 167) return 0;
    if (pSkillsTxt->nFlags[0] & gdwBitMasks[0])
    {
        if (!UnitHasFlag(pTarget, 2)) return 0;
        const int nPattern = PATH_GetUnitCollisionPattern(pTarget);
        return !COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nPattern, 0x3C01);
    }
    if (nSkillId == 164) return pTarget != 0;
    if (pSkillsTxt->wSrvDoFunc != 77 && pSkillsTxt->wSrvDoFunc != 78)
    {
    if (nSkillId == 199)
            return sub_6FC6A810(pGame, UNITS_GetRoom(pTarget), 0, 0, pTarget, 340, 1);
        if (nSkillId == 184)
        {
            if (!pUnit) return 0;
            D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom) || COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x3C01)) return 0;
            const int nUnitX = CLIENTS_GetUnitX(pUnit);
            const int nUnitY = CLIENTS_GetUnitY(pUnit);
            return sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0xC01) != 0;
        }
        if (pSkillsTxt->wSrvDoFunc == 67)
        {
            if (!pUnit) return 0;
            D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
            const int nUnitX = CLIENTS_GetUnitX(pUnit);
            const int nUnitY = CLIENTS_GetUnitY(pUnit);
            return sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0xC01) != 0;
        }
        if (nSkillId == 203)
        {
            if (!pUnit) return 0;
            D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(UNITS_GetRoom(pUnit), nX, nY);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
            const int nUnitX = CLIENTS_GetUnitX(pUnit);
            const int nUnitY = CLIENTS_GetUnitY(pUnit);
            return sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0x805) != 0;
        }
        return 1;
    }

        if (!pTarget)
        {
            return 0;
        }

        if (MONSTERS_IsDead(pUnit))
        {
            return 0;
        }
        const int nUnitX = CLIENTS_GetUnitX(pUnit);
        const int nUnitY = CLIENTS_GetUnitY(pUnit);
        const int nOldTargetX = CLIENTS_GetUnitX(pTarget);
        const int nDiffX = nOldTargetX - nUnitX;
        const int nTargetX = nOldTargetX + nDiffX;
        const int nTargetY = 2 * CLIENTS_GetUnitY(pTarget) - nUnitY;
        D2CoordStrc tCoords;
        tCoords.nX = nTargetX;
        tCoords.nY = nTargetY;
        D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoords, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0);
        if (!pRoom)
            goto reflectionFailed;
        if (DUNGEON_IsRoomInTown(pRoom))
            goto reflectionFailed;
        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, nTargetX, nTargetY, PATH_GetUnitCollisionPattern(pUnit), 0x3C01))
        {
reflectionFailed:
            return 0;
        }
        return sub_00645910_TestLine(nUnitX, nUnitY, nTargetX, nTargetY, pRoom, 0xC01) != 0;
    }
