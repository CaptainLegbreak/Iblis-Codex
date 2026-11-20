#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2LightStrc;
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissilesTxt;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemPool;
    int dwUnitId;
    unsigned char unk_10[0x10];
    D2SeedStrc tSeed;
    int unk0x28;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    int unk0x30[5];
    unsigned int dwFlags0x44;
    char unk0x48[0x04];
    short wAnimSpeed;
    unsigned char unk_4E[0x16];
    D2LightStrc* pLight;
};



typedef void (__fastcall* D2CltDoFunc)(D2UnitStrc* pMissile);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern D2CltDoFunc gpfnCltDoFuncs_0072A398[]; // 0x0072A398
int __fastcall sub_00474350_GetLightSize(D2LightStrc* pLight); // 0x00474350
void __fastcall sub_00474290_SetLightSize(D2LightStrc* pLight, int nSize); // 0x00474290
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall sub_00479150_FindRosterIndex(int nUnitId); // 0x00479150

enum
{
    CLTDO_SLOW_FRAME = 8,
    CLTDO_FAST_FRAME = 0x23,
    CLTDO_SLOW_FLAG = 0x100,
};

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CD1C0
static void sub_004CD1C0_FlickerLight(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissile->dwFlags0x44 & 0x300)
        return;
    D2LightStrc* pLight = pMissile->pLight;
    if (!pLight)
        return;
    if (sub_00474350_GetLightSize(pLight) < pMissilesTxtRecord->nLight)
        return;
    const int nRadius = pMissilesTxtRecord->nLight + ITEMS_RollLimitedRandomNumber(&pMissile->tSeed, pMissilesTxtRecord->nFlicker);
    sub_00474290_SetLightSize(pLight, nRadius);
}

void __fastcall sub_004D2C70_CltDoMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    if (pMissilesTxtRecord->nFlicker)
        sub_004CD1C0_FlickerLight(pMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        pRoom = D2GAME_GetRoom_6FC52070(0, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[10 >> 3] & gdwBitMasks[10 & 7]) && DUNGEON_IsRoomInTown(pRoom))
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    const short nCltDoFunc = pMissilesTxtRecord->wCltDoFunc;
    if (nCltDoFunc > 0 && nCltDoFunc < gnCltDoFuncs_0072A34C)
        gpfnCltDoFuncs_0072A398[nCltDoFunc](pMissile);
}

// 0x004CD240
int __fastcall sub_004CD240_IsOwnersPet(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pOwner->dwUnitType != 0)
    {
        return 0;
    }

    if (pUnit->dwUnitType != 1)
    {
        return 0;
    }

    const int nRosterId = sub_00479150_FindRosterIndex(pUnit->dwUnitId);
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    return nRosterId == nOwnerId;
}

// 0x004CD290
static __forceinline void sub_004CD290_CltAnimSpeedSteps(D2UnitStrc* pMissile, int nFrame)
{
    switch (nFrame)
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }
}

void __fastcall sub_M130_Emit_004CD290(D2UnitStrc* pMissile)
{
    sub_004CD290_CltAnimSpeedSteps(pMissile, sub_0064A3B0_GetElapsedFrames(pMissile));
}
