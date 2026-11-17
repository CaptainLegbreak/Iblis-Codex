#include "D2Common.h"
#define UNIT_PLAYER 0
#define STAT_TOHIT 19
#define STAT_DEXTERITY 2
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
struct D2AnimSeqTxt;
struct D2StaticPathStrc;
struct D2CoordStrc;
struct D2AnimDataRecordStrc;
struct D2CharStatsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090

struct D2CoordStrc { int nX; int nY; };

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nConvX;
    int nConvY;
    union
    {
        struct
        {
            D2CoordStrc tGameCoords;
        };
        struct
        {
            int nX;
            int nY;
        };
    };
    unsigned char unk_14[8];
    unsigned char bFlag1C;
    unsigned char unk_1D[0x3];
};

struct D2UnitStrc
{
    int nUnitType;
    int dwClassId;
    int unk0x08[2];
    int nAnimMode;
    unsigned char unk_14[0x18];
    union
    {
        D2StaticPathStrc* pPath;
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    D2AnimSeqTxt* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    unsigned char nActionFrame;
    char unk0x4F[0x01];
    D2AnimDataRecordStrc* pAnimData;
    char unk0x54[0x70];
    unsigned int dwFlags;
};

void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260

struct D2AnimDataRecordStrc
{
    char unk_00[0x10];
    unsigned char nFrameFlags[144];
};
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc*); // 0x006633B0
void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt*, int, int, int*, int*, int*, int*); // 0x00663410

struct D2CharStatsTxt
{
    char unk0x00[0x3C];
    int dwToHitFactor;
    char unk0x40[0x84];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit); // 0x006209D0
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560
int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260
static __declspec(noinline) int __fastcall sub_00622920_RayTraceBetweenBoxes(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask);
static __declspec(noinline) int __stdcall sub_00622920_TestCollision(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask);
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem); // 0x00629FE0
extern int gaFrameBonus_006E8E60[][7]; // 0x006E8E60
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit); // 0x006633D0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit); // 0x00623B10

// 0x00620AE0
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, D2CoordStrc tCoord)
{
    D2_ASSERT(pUnit, 0x866);
    D2StaticPathStrc* pPath = pUnit->pPath;
    pPath->nX = tCoord.nX;
    pPath->nY = tCoord.nY;
    pPath->bFlag1C = 0;
    pPath->pRoom = pRoom;
    int nConvX = tCoord.nX;
    int nConvY = tCoord.nY;
    sub_00643260(&nConvX, &nConvY);
    pPath->nConvX = nConvX;
    pPath->nConvY = nConvY;
}

// 0x00621330
void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate)
{
    nFailRate <<= 8;
    pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

    if (pUnit->nSeqCurrentFramePrecise >= nFailRate)
    {
        pUnit->nSeqCurrentFramePrecise -= nFailRate - (nRate << 8);
    }
}

// 0x00621920
int __stdcall sub_00621920_GetEventFrameInfo(D2UnitStrc* pUnit, int nFrame)
{
    if (!pUnit)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDCC);
        exit(-1);
    }
    if (nFrame >= 144)
        return 0;

    int bSequence = 0;
    switch (pUnit->nUnitType)
    {
    case 0:
        if (pUnit->nAnimMode == 18)
            bSequence = 1;
    case 1:
        if (pUnit->nAnimMode == 14)
            break;
        if (bSequence)
            break;
    default:
        return pUnit->pAnimData->nFrameFlags[nFrame];
    }
    int nMode;
    int nSequenceFrame;
    int nDirection;
    int nEvent;
    D2AnimSeqTxt* pSequence = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    DATATBLS_ComputeSequenceAnimation(pSequence, nFrame << 8, nFrame << 8, &nMode, &nSequenceFrame, &nDirection, &nEvent);
    return nEvent;
}

// build: context UNITS_GetCharStatsTxtRecord
static __forceinline D2CharStatsTxt* UNITS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        return &sgptDataTables->pCharStatsTxt[nClassId];
    return 0;
}

// build: context UNITS_GetToHitFactor
static __forceinline int UNITS_GetToHitFactor(D2UnitStrc* pUnit)
{
    if (pUnit->nUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = UNITS_GetCharStatsTxtRecord(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    return pCharStatsTxtRecord->dwToHitFactor;
}

// 0x00622560
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker)
{
    const int bValid = pAttacker && pAttacker->nUnitType == UNIT_PLAYER;
    D2_ASSERT(bValid, 0x107F);

    int nAttackRate = STATLIST_UnitGetStatValue(pAttacker, STAT_TOHIT, 0);
    int nDexterity = STATLIST_UnitGetStatValue(pAttacker, STAT_DEXTERITY, 0);
    nDexterity -= 7;
    nAttackRate += 5 * nDexterity;

    return nAttackRate + UNITS_GetToHitFactor(pAttacker);
}

static __forceinline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->nUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->nUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00622920
static int __fastcall sub_00622920_RayTraceBetweenBoxes(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask)
{
    D2CoordStrc tBegin;
    D2CoordStrc tEnd;
    int nBeginX = nX1;
    int nBeginY = nY1;
    int nEndX = nX2;
    int nEndY = nY2;
    int nXDiff;
    int nYDiff;

    const int nBeginSize = (nSize1 < 3) ? nSize1 : 2;
    const int nEndSize = (nSize2 < 3) ? nSize2 : 2;

    int nDX = nX2 - nX1;
    if (nDX < 0)
    {
        nXDiff = -nDX;
    }
    else
    {
        nXDiff = nDX;
    }

    int nDY = nY2 - nY1;
    if (nDY < 0)
    {
        nYDiff = -nDY;
    }
    else
    {
        nYDiff = nDY;
    }

    if (nXDiff + nYDiff < nBeginSize + nEndSize)
    {
        return 0;
    }

    if (nBeginSize || nEndSize)
    {
        if (nXDiff >= nYDiff)
        {
            if (nX2 > nX1)
            {
                nBeginX += nBeginSize;
                nEndX -= nEndSize;
            }
            else
            {
                nBeginX -= nBeginSize;
                nEndX += nEndSize;
            }
        }

        if (nYDiff >= nXDiff)
        {
            if (nY2 > nY1)
            {
                nBeginY += nBeginSize;
                nEndY -= nEndSize;
            }
            else
            {
                nBeginY -= nBeginSize;
                nEndY += nEndSize;
            }
        }
    }

    tBegin.nX = nBeginX;
    tBegin.nY = nBeginY;
    tEnd.nX = nEndX;
    tEnd.nY = nEndY;
    return COLLISION_RayTrace(pRoom, &tBegin, &tEnd, nCollisionMask);
}

// 0x006229F0
int __stdcall sub_006229F0_IsRayFreeFromUnit(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask)
{
    if (!pUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nUnitX = UNITS_GetXPositionForceInl(pUnit);
    const int nUnitY = UNITS_GetYPositionForceInl(pUnit);
    const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
    return sub_00622920_RayTraceBetweenBoxes(nUnitX, nUnitY, nUnitSize, nX, nY, 2, pRoom, nCollisionMask);
}

// 0x00622B50
int __stdcall sub_00622B50_IsRayFreeBetweenUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask)
{
    if (!pUnit1 || !pUnit2)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    if (!pRoom)
    {
        return 0;
    }

    const int nX1 = CLIENTS_GetUnitX(pUnit1);
    const int nY1 = CLIENTS_GetUnitY(pUnit1);
    const int nX2 = CLIENTS_GetUnitX(pUnit2);
    const int nY2 = CLIENTS_GetUnitY(pUnit2);
    int bRemoved1 = 0;
    int bRemoved2 = 0;
    if (UNITS_GetCollisionMask(pUnit1) & nCollisionMask)
    {
        bRemoved1 = PATH_RemoveCollisionFootprintForUnit(pUnit1, 0);
    }

    if (UNITS_GetCollisionMask(pUnit2) & nCollisionMask)
    {
        bRemoved2 = PATH_RemoveCollisionFootprintForUnit(pUnit2, 0);
    }

    const int nResult = sub_00622920_RayTraceBetweenBoxes(nX1, nY1, UNITS_GetUnitSizeX(pUnit1), nX2, nY2, UNITS_GetUnitSizeX(pUnit2), pRoom, nCollisionMask);
    if (bRemoved1)
    {
        PATH_AddCollisionFootprintForUnit(pUnit1);
    }

    if (bRemoved2)
    {
        PATH_AddCollisionFootprintForUnit(pUnit2);
    }

    return nResult;
}

static int __stdcall sub_00622920_TestCollision(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask)
{
    COLLISION_RayTrace((D2ActiveRoomStrc*)nSize2, (D2CoordStrc*)nX1, (D2CoordStrc*)nX2, 0);
    return COLLISION_RayTrace(pRoom, (D2CoordStrc*)nY1, (D2CoordStrc*)nSize1, nY2 + nCollisionMask);
}

// 0x00622AA0
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask)
{
    if (!pUnit1) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1290); exit(-1); }
    if (!pUnit2) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1291); exit(-1); }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    if (!pRoom)
    {
        return 0;
    }

    const int nX1 = CLIENTS_GetUnitX(pUnit1);
    const int nY1 = CLIENTS_GetUnitY(pUnit1);
    const int nSize1 = UNITS_GetUnitSizeX(pUnit1);
    const int nX2 = CLIENTS_GetUnitX(pUnit2);
    const int nY2 = CLIENTS_GetUnitY(pUnit2);
    const int nSize2 = UNITS_GetUnitSizeX(pUnit2);
    return sub_00622920_TestCollision(nX1, nY1, nSize1, nX2, nY2, nSize2, pRoom, nCollisionMask);
}

__forceinline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->nUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->nUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00623660
int __stdcall sub_00623660_IsInObjectInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    int nX1 = 0;
    int nY1 = 0;
    int nX2 = 0;
    int nY2 = 0;
    int nX = 0;
    int nY = 0;
    int nSizeX2 = 0;
    int nSizeY2 = 0;

    const int nObjectType = pObject ? pObject->nUnitType : 6;
    if (nObjectType != 2)
    {
        return 0;
    }

    if ((unsigned int)D2Common_10399(pUnit, pObject) <= 0)
    {
        return 1;
    }

    nX1 = UNITS_GetXPositionInline(pUnit);
    nY1 = UNITS_GetYPositionInline(pUnit);

    nX2 = UNITS_GetXPositionInline(pObject);
    nY2 = UNITS_GetYPositionInline(pObject);

    nSizeX2 = UNITS_GetUnitSizeX(pObject);
    nSizeY2 = UNITS_GetUnitSizeY(pObject);

    nX = nX2 - nSizeX2 / 2;
    nY = nY2 - nSizeY2 / 2;

    if (nSizeX2 >= 1 && nSizeY2 >= 1)
    {
        if (nX1 >= nX - 2 && nX1 <= nSizeX2 + nX + 2 && nY1 >= nY - 2 && nY1 <= nSizeY2 + nY + 2)
        {
            if ((unsigned int)UNITS_GetUnitSizeX(pUnit) > 2)
            {
                return 1;
            }

            if (nY1 < nY - 1)
            {
                return nX1 >= nX - 1 && nX1 <= nSizeX2 + nX + 1;
            }

            return nY1 <= nSizeY2 + nY + 1 || (nX1 >= nX - 1 && nX1 <= nSizeX2 + nX + 1);
        }

        return 0;
    }

    return nX1 >= nX - 1 && nX1 <= nX + 1 && nY1 >= nY - 1 && nY1 <= nY + 1;
}

static inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 6;
    return pUnit->nUnitType;
}

static inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

static inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->nAnimMode;
}

// 0x00623B10
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit)
{
    int nUnitType = UNITS_GetUnitTypeInline(pUnit);
    int nClassId = UNITS_GetClassIdInline(pUnit);
    int nAnimMode = UNITS_GetAnimModeInline(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nAnimMode, ".\\UNITS\\Units.cpp", 0x118A);

    if (nUnitType != 0)
        return 0;

    switch (nAnimMode)
    {
    case 7:
    case 8:
    {
        D2UnitStrc* pWeapon = D2Common_10434(pUnit, 1);
        unsigned short nWeaponClass = 0;
        if (pWeapon)
            nWeaponClass = ITEMS_GetWeaponClassId(pWeapon);
        return gaFrameBonus_006E8E60[nWeaponClass][nClassId];
    }
    case 15:
    case 16:
        if (UNITS_CanDualWield(pUnit))
        {
            D2UnitStrc* pWeapon = D2Common_10434(pUnit, 1);
            unsigned short nWeaponClass = 0;
            if (pWeapon)
                nWeaponClass = ITEMS_GetWeaponClassId(pWeapon);
            return gaFrameBonus_006E8E60[nWeaponClass][nClassId];
        }
        break;
    }

    return 0;
}

#include "gen/data/Source/D2Common/UNITS/Units_00620AE0.inc"

// 0x00621210
static int __stdcall sub_00621210(D2UnitStrc* pUnit, int nPrevFrame)
{
    const int nOldMode = pUnit->dwSeqMode;
    int nFrame;
    int nDirection;
    int nEvent;
    DATATBLS_ComputeSequenceAnimation(pUnit->pAnimSeq, pUnit->dwSeqFrame, nPrevFrame, &nPrevFrame, &nFrame, &nDirection, &nEvent);
    pUnit->nSeqCurrentFramePrecise = nFrame << 8;
    pUnit->dwSeqMode = nPrevFrame;
    pUnit->nActionFrame = nEvent;
    return nPrevFrame != nOldMode;
}

// 0x00621260
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->pAnimSeq = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
        if (pUnit->pAnimSeq)
        {
            pUnit->dwSeqFrameCount = DATATBLS_GetSeqFramePointsCount(pUnit);
            pUnit->dwSeqFrame = 0;
            pUnit->dwSeqSpeed = 0x100;
            pUnit->dwFrameCountPrecise = DATATBLS_GetSeqFrameCount(pUnit) << 8;
            sub_00621210(pUnit, 0);
            pUnit->dwFlags |= 0x4000;
        }
    }
}

// 0x006218D0
void __stdcall UNITS_SetAnimActionFrame(D2UnitStrc* pUnit, int nFrame)
{
    if (pUnit && pUnit->pAnimData && nFrame < 144)
    {
        if (pUnit->pAnimData->nFrameFlags[nFrame] == 1)
        {
            pUnit->nActionFrame = 1;
        }
        if (pUnit->pAnimData->nFrameFlags[nFrame] == 2)
        {
            pUnit->nActionFrame = 2;
        }
        if (pUnit->pAnimData->nFrameFlags[nFrame] == 3)
        {
            pUnit->nActionFrame = 3;
        }
        if (pUnit->pAnimData->nFrameFlags[nFrame] == 4)
        {
            pUnit->nActionFrame = 4;
        }
    }
}

// build: context StopSequence_SetActionFrame
static __forceinline void StopSequence_SetActionFrame(D2UnitStrc* pUnit, int nFrame)
{
    D2AnimDataRecordStrc* pAnimData = pUnit->pAnimData;
    if (pAnimData && nFrame < 144)
    {
        if (pAnimData->nFrameFlags[nFrame] == 1)
        {
            pUnit->nActionFrame = 1;
        }
        if (pAnimData->nFrameFlags[nFrame] == 2)
        {
            pUnit->nActionFrame = 2;
        }
        if (pAnimData->nFrameFlags[nFrame] == 3)
        {
            pUnit->nActionFrame = 3;
        }
        if (pAnimData->nFrameFlags[nFrame] == 4)
        {
            pUnit->nActionFrame = 4;
        }
    }
}

// 0x00623E00
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit)
{
    pUnit->nActionFrame = 0;

    if (pUnit->pAnimSeq)
    {
        const int nOldFrame = pUnit->dwSeqFrame;
        pUnit->dwFlags &= ~0x4000;
        pUnit->dwSeqFrame += pUnit->dwSeqSpeed;
        if (pUnit->dwSeqFrame >= pUnit->dwSeqFrameCount)
            pUnit->dwSeqFrame -= pUnit->dwSeqFrameCount;
        pUnit->dwFrameCountPrecise -= pUnit->dwSeqSpeed;
        if (sub_00621210(pUnit, nOldFrame))
            pUnit->dwFlags |= 0x4000;
    }
    else
    {
        int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
        if (pUnit->wAnimSpeed >= 0x100)
            nFrame++;

        pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

        while (pUnit->nSeqCurrentFramePrecise >= pUnit->dwFrameCountPrecise)
        {
            for (int i = nFrame; i < pUnit->dwFrameCountPrecise >> 8; i++)
            {
                StopSequence_SetActionFrame(pUnit, i);
            }
            nFrame = 0;
            pUnit->nSeqCurrentFramePrecise -= pUnit->dwFrameCountPrecise;
            pUnit->nSeqCurrentFramePrecise += UNITS_GetFrameBonus(pUnit) << 8;
        }

        const int nLastFrameReached = pUnit->nSeqCurrentFramePrecise >> 8;
        for (int i = nFrame; i <= nLastFrameReached; i++)
        {
            StopSequence_SetActionFrame(pUnit, i);
        }
    }
}
