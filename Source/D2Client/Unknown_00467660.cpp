#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

extern const unsigned int gdwMask_006CE278;                                                                 // 0x006CE278
extern const int gnAdjacentDirOffsets_006D6B34[];                                                           // 0x006D6B34
extern const int gnDirectionDX_006D6B14[];                                                                  // 0x006D6B14
extern const int gnDirectionDY_006D6AF4[];                                                                  // 0x006D6AF4

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall UNITS_GetNewDirection(D2UnitStrc* pUnit);                                                     // 0x006238C0
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0
int __fastcall sub_00467640_UnitFindTest(D2UnitStrc* pUnit, void* pArg);                                    // 0x00467640
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
static D2UnitStrc* __stdcall sub_00467660_FindAdjacentTarget(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x00467660

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

static inline int UNITS_IsSelectable(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 2) & 1;
    }
    return bResult;
}

static D2UnitStrc* __stdcall sub_00467660_FindAdjacentTarget(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit);

// 0x00467660
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
            if (UNITS_IsSelectable(pTarget))
            {
                if (!(pSkillsTxtRecord->nFlags[2] & gdwMask_006CE278)
                    || (pTarget->dwUnitType == UNIT_MONSTER && sub_004638A0_CheckMonStats2Flag(pTarget->dwClassId, 6))
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

D2UnitStrc* __fastcall sub_807B_Emit_00467660(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pPlayer, int bArg)
{
    if (bArg && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        return sub_00467660_FindAdjacentTarget(pSkillsTxtRecord, pPlayer);
    }
    UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);
    return pPlayer;
}

#include "gen/data/Source/D2Client/Unknown_00467660.inc"
