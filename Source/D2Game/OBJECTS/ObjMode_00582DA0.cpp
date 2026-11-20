#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
struct D2UnitStrc;

struct D2SfxStrc { D2GameStrc* pGame; D2UnitStrc* pObject; D2UnitStrc* pOwner; };
struct D2SfxArgStrc { int unk, nDamagePct, nRadius; };
struct D2UnitFindArgStrc
{
    int nFlags; int unk0x04; D2UnitStrc* pUnit; int nX; int nY; int nSize; int nMaxArrayEntries; int nIndex;
    void* pField; void* pfnUnitTest; int unk0x28; int unk0x2C; int unk0x30; int unk0x34;
};
struct D2UnitFindDataStrc
{
    void* pMemPool; D2UnitStrc** pUnitsArray; D2ActiveRoomStrc* pRoom; void* pfnUnitTest; D2UnitFindArgStrc* pUnitFindArg;
    int nFlags; int nIndex; int nMaxArrayEntries; int nX; int nY; int nSize;
};
struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625480
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x006272B0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pFind, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnTest, D2UnitFindArgStrc* pArg); // 0x0065A950
int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pFind); // 0x0065AA00
int __fastcall sub_00582710_IsLivingUnit(D2UnitStrc* unit, void* unused); // 0x00582710
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissile); // 0x0059FA30
__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}
__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}
// 0x00582DA0
void __fastcall sub_00582DA0_ExplosionEffect(D2SfxStrc* pSfx, D2SfxArgStrc* pArgs)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pSfx->pObject);
    int nX = CLIENTS_GetUnitX(pSfx->pObject);
    int nY = CLIENTS_GetUnitY(pSfx->pObject);
    D2UnitFindArgStrc arg;
    memset(&arg, 0, sizeof(arg));
    arg.nFlags = 0x583;
    arg.nX = nX;
    arg.nY = nY;
    arg.nSize = pArgs->nRadius;
    D2UnitFindDataStrc data;
    UNITFINDS_InitializeUnitFindData(pSfx->pGame->pMemoryPool, &data, pRoom, nX, nY, pArgs->nRadius, (void*)sub_00582710_IsLivingUnit, &arg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&data);
    for (int i = 0; i < data.nIndex; ++i)
    {
        D2UnitStrc* pUnit = data.pUnitsArray[i];
        if (pUnit && (pUnit->dwUnitType == 1 || pUnit->dwUnitType == 0) && !SUNIT_IsDead(pUnit))
        {
            int nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
            STATLIST_AddUnitStat(pUnit, 6, (pArgs->nDamagePct * nLife / -100) << 8, 0);
        }
    }
    UNITFINDS_FreeUnitFindData(&data);
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            D2MissileStrc missile;
            memset(&missile, 0, sizeof(missile));
            missile.dwFlags = 3;
            missile.nX = CLIENTS_GetUnitX(pSfx->pObject);
            missile.nY = CLIENTS_GetUnitY(pSfx->pObject);
            missile.nTargetX = (i & 1) ? 5 * i : -5 * i;
            missile.nTargetY = (j & 1) ? 5 * j : -5 * j;
            missile.pOwner = pSfx->pOwner;
            missile.nMissile = 62;
            int nSkillLevel = STATLIST_UnitGetStatValue(pSfx->pOwner, 12, 0) / 5;
            if (nSkillLevel < 1) nSkillLevel = 1;
            else if (nSkillLevel > 8) nSkillLevel = 8;
            missile.nSkillLevel = nSkillLevel;
            MISSILES_CreateMissileFromParams(pSfx->pGame, &missile);
        }
    }
}
