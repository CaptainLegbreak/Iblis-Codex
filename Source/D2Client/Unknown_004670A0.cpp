#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2ItemsWorld.h"
#include "D2Structs.h"
#include "D2GameRecords.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2ObjModes.h"
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2UnitStrc;









typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
extern int gdwGlobal_007A6A98;                                                                              // 0x007A6A98
extern int gdwGlobal_007A6A94;                                                                              // 0x007A6A94
extern int gnSelectedUnitType_007A6A8C;                                                                     // 0x007A6A8C
extern unsigned int gnSelectedUnitId_007A6A78;                                                              // 0x007A6A78
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gbSelectionRectValid_007A6A9C;                                                                   // 0x007A6A9C
extern int gnSelectionLeft_007A6A7C;                                                                        // 0x007A6A7C
extern int gnSelectionRight_007A6A84;                                                                       // 0x007A6A84
extern int gnSelectionTop_007A6A80;                                                                         // 0x007A6A80
extern int gnSelectionBottom_007A6A88;                                                                      // 0x007A6A88
extern int gdwGlobal_007A6AA0;                                                                              // 0x007A6AA0

int __cdecl TEXT_IsTextBoxOpen();                                                                                 // 0x004A0000
D2UnitStrc* __cdecl TEXT_GetTextUnit();                                                             // 0x0049E8B0
void __fastcall TEXT_SetHoverUnit(D2UnitStrc* pUnit);                                                            // 0x0049DA30
void __cdecl TEXT_ClearHoverUnit();                                                                      // 0x0049DA50
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall VIEW_SetViewDirty(D2ViewStrc* pView);                                               // 0x00475FF0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
int __fastcall SCMD_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY);                           // 0x00463EE0
int __cdecl GAME_IsLeftButtonHeld();                                                                                 // 0x0044BF30
int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0
int __cdecl GAME_GetInteractDeadline(); // 0x0044DAC0
void __fastcall GAME_SetInteractDeadline(int nValue); // 0x0044DAD0
extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall ITEMS_IsMetalItem(int nItemId);                                                               // 0x00629CC0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, D2UnitFindCallback pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
int __fastcall sub_00467470_UnitFindTest(D2UnitStrc* pUnit, void* pArg);                                    // 0x00467470
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);                           // 0x00644140
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY);                     // 0x004C51E0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY);                                                   // 0x00643260

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

static inline int CLIENT_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENT_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static void sub_00466DE0_SetHoverUnit(D2UnitStrc* pUnit)
{
    char szBuffer[0x200];

    if (gdwGlobal_007A6A98)
    {
        return;
    }

    if (TEXT_IsTextBoxOpen() && TEXT_GetTextUnit() == pUnit)
    {
        TEXT_SetHoverUnit(pUnit);
        return;
    }

    TEXT_ClearHoverUnit();

    int bSame = 0;
    if (pUnit)
    {
        D2_ASSERT(sub_00466870(pUnit, 0, 0, 0), 0x4F);
        const int nUnitType = pUnit->dwUnitType;
        const unsigned int nUnitId = pUnit->dwUnitId;
        if (gdwGlobal_007A6A94 && nUnitType == gnSelectedUnitType_007A6A8C && nUnitId == gnSelectedUnitId_007A6A78)
        {
            bSame = 1;
        }
    }

    if (!bSame && gdwGlobal_007A6A94 && gnSelectedUnitType_007A6A8C == 5)
    {
        D2UnitStrc* pOld = CUNIT_FindClientUnit(gnSelectedUnitId_007A6A78, 5);
        if (pOld)
        {
            DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), pOld->dwClassId);
            VIEW_SetViewDirty(gpView_007A0640);
        }
    }

    if (!pUnit)
    {
        gdwGlobal_007A6A94 = 0;
        return;
    }

    gnSelectedUnitType_007A6A8C = pUnit->dwUnitType;
    gnSelectedUnitId_007A6A78 = pUnit->dwUnitId;
    gdwGlobal_007A6A94 = 1;

    switch (pUnit->dwUnitType)
    {
    case UNIT_TILE:
        if (!bSame)
        {
            DUNGEON_UpdateWarpRoomSelect(UNITS_GetRoom(pUnit), pUnit->dwClassId);
            VIEW_SetViewDirty(gpView_007A0640);
        }
        break;

    case UNIT_OBJECT:
        if (UnitIsDoor(pUnit) && pUnit->dwAnimMode != OBJMODE_SPECIAL2)
        {
            const unsigned int dwNow = GetTickCount();
            if (dwNow - pUnit->dwTickCount > 0x1F4)
            {
                sprintf(szBuffer, "msg at %d\n", dwNow);
                OutputDebugStringA(szBuffer);
                pUnit->dwTickCount = dwNow;
                sub_00478680_SendPacket5(0x3D, gnSelectedUnitId_007A6A78);
            }
        }
        break;

    case UNIT_MONSTER:
        if (!bSame)
        {
            const int nClassId = pUnit->dwClassId;
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pMonStatsTxtRecord)
            {
                D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
                if (pMonStats2TxtRecord
                    && !(pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
                    && pMonStatsTxtRecord->nAlign != 1
                    && (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[1]))
                {
                    if (!(pMonStats2TxtRecord->nFlags[2] & gdwBitMasks[1]))
                    {
                        gdwGlobal_00711F94 = nClassId;
                    }
                    gdwGlobal_00711F90 = nClassId;
                }
            }
        }
        break;
    }
}

static int __stdcall sub_00467000_CheckWarpTileHover(D2UnitStrc* pPlayer, int nY1, int nX2, int nY2, D2UnitStrc* pUnit, int nX1, int* pnFlag)
{
    if (pUnit && pUnit->dwUnitType == UNIT_TILE
        && SCMD_IsPointInTileRect(pUnit, nX1, nY1)
        && SCMD_IsPointInTileRect(pUnit, nX2, nY2)
        && UNITS_IsInMovingMode(pPlayer)
        && GAME_IsLeftButtonHeld())
    {
        if (GAME_GetCurrentTime() < GAME_GetInteractDeadline())
        {
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 0x1F4);
            return 1;
        }

        if (!*pnFlag)
        {
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 0x1F4);
            *pnFlag = 1;
        }
    }

    return 0;
}

// 0x004670A0
static void __stdcall sub_004670A0_AdjustCursorPerspective(int* pnX, int* pnY)
{
    if (sub_004F51D0_IsPerspective())
    {
        *pnY -= *pnY / 40;
        const int nHalfWidth = gnGlobal_0071146C / 2;
        *pnX += (40 - *pnY / 4) * (*pnX - nHalfWidth) / nHalfWidth;
    }

    *pnX += PLAYER_GetScreenOffsetX();
    *pnY += PLAYER_GetScreenOffsetY();
}

static int sub_00467130_GetHoverCursorPos(int* pnX, int* pnY)
{
    const int nMode = sub_0045AE90();
    if (nMode == 3)
    {
        if (gdwGlobal_007A6A98)
        {
            return 1;
        }

        if (TEXT_IsTextBoxOpen() && !TEXT_GetTextUnit())
        {
            TEXT_SetHoverUnit(0);
            return 1;
        }

        TEXT_ClearHoverUnit();
        if (gdwGlobal_007A6A94 && gnSelectedUnitType_007A6A8C == 5)
        {
            D2UnitStrc* pOld = CUNIT_FindClientUnit(gnSelectedUnitId_007A6A78, 5);
            if (pOld)
            {
                DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), pOld->dwClassId);
                VIEW_SetViewDirty(gpView_007A0640);
            }
        }
        gdwGlobal_007A6A94 = 0;
        return 1;
    }

    *pnX = sub_00468730();
    *pnY = sub_00468740();
    if (*pnY <= gnGlobal_00711470 - 0x31
        && (!gbSelectionRectValid_007A6A9C || *pnX <= gnSelectionLeft_007A6A7C || *pnX >= gnSelectionRight_007A6A84
            || *pnY <= gnSelectionTop_007A6A80 || *pnY >= gnSelectionBottom_007A6A88))
    {
        switch (nMode)
        {
        case 2:
            if (*pnX < gnGlobal_0071146C / 2)
            {
                break;
            }
            goto adjust;

        case 1:
            if (*pnX >= gnGlobal_0071146C / 2)
            {
                break;
            }
            goto adjust;

        default:
            goto adjust;
        }
    }

    sub_00466DE0_SetHoverUnit(0);
    return 1;

adjust:
    sub_004670A0_AdjustCursorPerspective(pnX, pnY);
    return 0;
}

int __stdcall sub_00467250_CheckDoorSideA(D2UnitStrc* pOther, D2UnitStrc* pUnit); // 0x00467250

// 0x00467310
static int __stdcall sub_00467310_CheckDoorSideB(D2UnitStrc* pOther, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        return 0;
    }

    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pUnit);
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    D2CoordStrc tOther;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        UNITS_GetCoords(pPlayer, &tPlayer);
    }
    else
    {
        tPlayer.nX = 0;
        tPlayer.nY = 0;
    }
    UNITS_GetCoords(pUnit, &tUnit);
    UNITS_GetCoords(pOther, &tOther);

    if (pObjectsTxtRecord->nSide == 1)
    {
        if ((tOther.nY > (unsigned int)tUnit.nY && (unsigned int)tUnit.nY > tPlayer.nY) || (tOther.nY < (unsigned int)tUnit.nY && (unsigned int)tUnit.nY < tPlayer.nY))
        {
            return 1;
        }
    }
    else
    {
        if ((tOther.nX < (unsigned int)tUnit.nX && (unsigned int)tUnit.nX < tPlayer.nX) || (tOther.nX > (unsigned int)tUnit.nX && (unsigned int)tUnit.nX > tPlayer.nX))
        {
            return 1;
        }
    }
    return 0;
}

// 0x004673C0
static int sub_004673C0_GetDistanceSquared(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    const int nDX = UNITS_GetClientCoordX(pUnit) - UNITS_GetClientCoordX(pOther);
    const int nDY = UNITS_GetClientCoordY(pUnit) - UNITS_GetClientCoordY(pOther);
    return nDY * nDY + nDX * nDX;
}

static D2UnitStrc* __stdcall sub_00467490_FindSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pUnit, int* pnX, int* pnY, D2SkillsTxt* pSkillsTxtRecord)
{
    if (pUnit)
    {
        if ((pSkillsTxtRecord->nFlags[3] & gdwBitMasks[0]) && CUNIT_IsDeadOrDying(pUnit))
        {
            return pUnit;
        }

        *pnX = CLIENT_GetUnitXInline(pUnit);
        *pnY = CLIENT_GetUnitYInline(pUnit);
    }

    int nFlags = (pSkillsTxtRecord->nFlags[3] & gdwBitMasks[0]) ? 0x3002 : 0x2003;
    D2UnitFindCallback pfnTest = 0;
    if (SKILLS_GetSkillIdFromSkill(pSkill, ".\\GAME\\Select.cpp", 0x301) == SKILL_IRONGOLEM)
    {
        if (pUnit && pUnit->dwUnitType == UNIT_ITEM && ITEMS_IsMetalItem(pUnit->dwClassId))
        {
            return pUnit;
        }
        nFlags = 0x20;
        pfnTest = sub_00467470_UnitFindTest;
    }

    D2UnitFindArgStrc tArg;
    memset(&tArg, 0, sizeof(tArg));
    tArg.nFlags = nFlags;
    tArg.pUnit = sub_00463DE0_GetPlayerUnit();
    tArg.nX = *pnX;
    tArg.nY = *pnY;
    tArg.nSize = 9;

    D2UnitFindDataStrc tFindData;
    UNITFINDS_InitializeUnitFindData(0, &tFindData, sub_004646A0_GetPlayerRoom(), *pnX, *pnY, 9, pfnTest, &tArg);
    tFindData.nFlags = nFlags;
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&tFindData);

    int nBestDistance = 10;
    for (int i = 0; i < tFindData.nIndex; ++i)
    {
        D2UnitStrc* pCandidate = tFindData.pUnitsArray[i];
        const int nDistance = UNITS_GetDistanceToCoordinates(pCandidate, *pnX, *pnY);
        if (sub_00466870(pCandidate, 0, 0, 0) && nDistance < nBestDistance)
        {
            pUnit = pCandidate;
            nBestDistance = nDistance;
        }
    }

    UNITFINDS_FreeUnitFindData(&tFindData);
    return pUnit;
}

static D2UnitStrc* __stdcall sub_00467660_FindAdjacentTarget(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    const int nDirection = (unsigned char)UNITS_GetNewDirection(pUnit) >> 3;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    for (int i = 0; i < 5; ++i)
    {
        const int nIndex = (gnAdjacentDirOffsets_006D6B34[i] + nDirection) & 7;
        const int nX = gnDirectionDX_006D6B14[nIndex] + CLIENT_GetUnitXInline(pUnit);
        const int nY = gnDirectionDY_006D6AF4[nIndex] + CLIENT_GetUnitYInline(pUnit);
        if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, 1, 0x180))
        {
            D2UnitStrc* pTarget = D2Common_10407(pRoom, nX, nY, sub_00467640_UnitFindTest, 0, 1);
            if (UNIT_HasFlag(pTarget, 4))
            {
                if (!(pSkillsTxtRecord->nFlags[2] & gdwBitMasks[4])
                    || (pTarget->dwUnitType == UNIT_MONSTER && MONSTERREGION_CheckMonStats2Flag(pTarget->dwClassId, 6))
                    || sub_00465C60_CheckUnitPair(pUnit, pTarget))
                {
                    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
                    return pTarget;
                }
            }
        }
    }

    return 0;
}

// 0x004677B0
static D2UnitStrc* __stdcall sub_004677B0_FindFreeTargetCoords(int* pnX, int* pnY, D2UnitStrc* pUnit)
{
    D2CoordStrc tCoord;
    if (pUnit)
    {
        tCoord.nX = CLIENT_GetUnitXInline(pUnit);
        tCoord.nY = CLIENT_GetUnitYInline(pUnit);
    }
    else
    {
        tCoord.nX = *pnX;
        tCoord.nY = *pnY;
    }

    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom && COLLISION_CheckMask(pRoom, tCoord.nX, tCoord.nY, 1)
        && COLLISION_GetFreeCoordinatesWithMaxDistance(pRoom, &tCoord, 1, 1, 0, 7))
    {
        *pnX = tCoord.nX;
        *pnY = tCoord.nY;
        return 0;
    }

    return pUnit;
}

// 0x00467880
D2UnitStrc* __fastcall sub_00467880_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pUnit, int* pnX, int* pnY, unsigned char nFlags, int bArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER && CUNIT_IsDeadOrDying(pUnit))
        {
            return pUnit;
        }

        if ((pSkillsTxtRecord->nFlags[3] & gdwBitMasks[0]) || !CUNIT_IsDeadOrDying(pUnit))
        {
            goto skip;
        }

        sub_00466DE0_SetHoverUnit(0);
        *pnX = CLIENTS_GetUnitX(pUnit);
        *pnY = CLIENTS_GetUnitY(pUnit);
        pUnit = 0;
    }

    if (*pnX == CLIENT_GetUnitXInline(pPlayer) && *pnY == CLIENT_GetUnitYInline(pPlayer))
    {
        ITEM_GetAdjacentPosition(pPlayer, pnX, pnY);
    }

skip:
    if ((nFlags & 8) && (nFlags & 1) && !(nFlags & 0x20) && UNITS_IsInMovingMode(pPlayer))
    {
        return pUnit;
    }

    if (sub_004D9FC0(pPlayer, pSkill))
    {
        return pUnit;
    }

    const int nFlags6 = pSkillsTxtRecord->nFlags[2];
    if (nFlags6 & gdwBitMasks[6])
    {
        return sub_00467490_FindSkillTarget(pSkill, pUnit, pnX, pnY, pSkillsTxtRecord);
    }

    if (!pUnit && (nFlags6 & gdwBitMasks[5]) && bArg)
    {
        return sub_00467660_FindAdjacentTarget(pSkillsTxtRecord, pPlayer);
    }

    if (nFlags6 & gdwBitMasks[7])
    {
        return sub_004677B0_FindFreeTargetCoords(pnX, pnY, pUnit);
    }

    return pUnit;
}

void __cdecl sub_E01_Emit_00467AC0(D2UnitStrc* pFirst)
{
    int nX = 0;
    int nY = 0;
    if (sub_00467130_GetHoverCursorPos(&nX, &nY))
    {
        return;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPX = CLIENTS_GetUnitX(pPlayer);
    int nPY = CLIENTS_GetUnitY(pPlayer);
    DUNGEON_GameSubtileToClientCoords(&nPX, &nPY);
    D2UnitStrc* pBest = 0;
    for (D2UnitStrc* pUnit = pFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        if (sub_00467000_CheckWarpTileHover(pPlayer, nPY, nX, nY, pUnit, nPX, &gdwGlobal_007A6AA0))
        {
            continue;
        }
        if (!pBest)
        {
            pBest = pUnit;
            continue;
        }
        if (sub_00467250_CheckDoorSideA(pUnit, pBest))
        {
            pBest = pUnit;
        }
        else if (sub_00467310_CheckDoorSideB(pBest, pUnit))
        {
            pBest = pUnit;
        }
        else if (sub_004673C0_GetDistanceSquared(pPlayer, pUnit) < sub_004673C0_GetDistanceSquared(pPlayer, pBest))
        {
            pBest = pUnit;
        }
    }
    sub_00466DE0_SetHoverUnit(pBest);
}
