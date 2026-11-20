#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"




struct D2MonCommandStrc
{
    int nX;
    int nY;
    int nZero;
    int nPathValue;
    int nArg;
    int nPathByte;
    int unk0x18;
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int* __fastcall sub_004AE170(D2UnitStrc* pUnit); // 0x004AE170
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pTarget); // 0x004AFF60
void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

static __forceinline unsigned int SEED_RollUnitHL_0046CE40(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline int AI_GetUnitMode_Inline(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

static void __stdcall sub_0046CA60_CommandToXY(int nCommand, D2UnitStrc* pUnit, int nX, int nArg, int nY); // 0x0046CA60

static void __stdcall sub_0046CA60_CommandToXY(int nCommand, D2UnitStrc* pUnit, int nX, int nArg, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2MonCommandStrc tCommand;
    tCommand.nX = nX;
    tCommand.nY = nY;
    tCommand.nZero = 0;
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    sub_004AFF60_MonsterCommand(nCommand, pUnit, &tCommand);
}

static __declspec(noinline) void sub_0046CE40_AiType3(D2UnitStrc* pUnit);

// 0x0046CE40
static void sub_0046CE40_AiType3(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        int* pState = sub_004AE170(pUnit);
        if (pState)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            const int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pPlayer);
            if (*pState && nDistance > 25)
            {
                sub_00465F00_RemoveServerSideUnit(UNITS_GetUnitIdInline(pUnit), 1);
                return;
            }

            *pState = 1;

            int nOffsetY;
            int nOffsetX;
            if (SEED_RollUnitHL_0046CE40(pUnit) & 1)
            {
                nOffsetX = 40;
                nOffsetY = SEED_RollUnitHL_0046CE40(pUnit) % 40;
            }
            else
            {
                nOffsetX = SEED_RollUnitHL_0046CE40(pUnit) % 40;
                nOffsetY = 40;
            }

            if (SEED_RollUnitHL_0046CE40(pUnit) & 1)
            {
                nOffsetX = -nOffsetX;
            }

            if (SEED_RollUnitHL_0046CE40(pUnit) & 1)
            {
                nOffsetY = -nOffsetY;
            }

            int nTargetX = CLIENTS_GetUnitXInline(pPlayer);
            int nTargetY = CLIENTS_GetUnitYInline(pPlayer);
            nTargetX += nOffsetX;
            nTargetY += nOffsetY;
            const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
            const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
            PATH_SetNewDistance(pUnit->pDynamicPath, 90);
            sub_0046CA60_CommandToXY(1, pUnit, 3 * nTargetX - 2 * nUnitX, 0, 3 * nTargetY - 2 * nUnitY);
        }
    }
}

void __fastcall sub_E19_Emit_0046CE40(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0x9D:
    case 0x9E:
    case 0x13F:
        sub_0046CE40_AiType3(pUnit);
        return;
    }
}
