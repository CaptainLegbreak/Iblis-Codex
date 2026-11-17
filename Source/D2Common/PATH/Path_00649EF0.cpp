#include "D2Common.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
union D2FP32_16;

union D2FP32_16
{
    struct
    {
        unsigned short wOffsetX;
        unsigned short wPosX;
        unsigned short wOffsetY;
        unsigned short wPosY;
    };

    struct
    {
        unsigned int dwPrecisionX;
        unsigned int dwPrecisionY;
    };
};

struct D2DynamicPathStrc
{
    D2FP32_16 tGameCoords;
    unsigned char unk_08[0x40];
    int dwCollisionPattern;
    int nCollisionMask;
    unsigned char unk_50[0x14];
    unsigned char nNewDirection;
    unsigned char nDirection;
    unsigned char unk_66[0x2];
};

int __stdcall PATH_ComputeDirectionFromPreciseCoords_6FDAC760(D2FP32_16 tStart, D2FP32_16 tTarget); // 0x0064FE10
void __fastcall sub_6FDA9720(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006485F0

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize); // 0x00648580
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560

// 0x00649EF0
void __stdcall D2Common_10216(D2DynamicPathStrc* pDynamicPath, int nX, int nY, int a4)
{
    if (pDynamicPath)
    {
        D2FP32_16 tTarget;
        tTarget.dwPrecisionX = (nX << 16) + 0x8000;
        tTarget.dwPrecisionY = (nY << 16) + 0x8000;
        const int nDirection = PATH_ComputeDirectionFromPreciseCoords_6FDAC760(pDynamicPath->tGameCoords, tTarget);
        if (a4)
        {
            pDynamicPath->nNewDirection = nDirection & 0x3F;
            pDynamicPath->nDirection = nDirection & 0x3F;
        }
        else
        {
            sub_6FDA9720(pDynamicPath, nDirection);
        }
    }
}

// 0x00648C10
int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0xFFFF;
    }

    return pDynamicPath->nCollisionMask;
}

static __forceinline int sub_00649FF0_GetCollisionPattern(D2UnitStrc* pUnit)
{
    int nPattern = D2Common_11281_CollisionPatternFromSize(pUnit, UNITS_GetUnitSizeX(pUnit));
    const int nBaseId = sub_00463860(pUnit);
    if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        switch (nBaseId)
        {
        case 38:
        case 157:
        case 158:
        case 319:
            nPattern = 5;
            break;
        }
    }
    return nPattern;
}

// 0x00649FF0
void __stdcall sub_00649FF0_ResetMonsterCollision(D2UnitStrc* pUnit, int bSkip)
{
    if (bSkip)
    {
        return;
    }

    int nValue = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nValue == UNIT_MONSTER, 1346);

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (PATH_GetFootprintCollisionMask(pDynamicPath) == 0x8000)
    {
        nValue = sub_00649FF0_GetCollisionPattern(pUnit);
        if (UNITS_GetRoom(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            pUnit->pDynamicPath->dwCollisionPattern = nValue;
            PATH_SetFootprintCollisionMask(pDynamicPath, 0x100);
            PATH_AddCollisionFootprintForUnit(pUnit);
        }
        else
        {
            pUnit->pDynamicPath->dwCollisionPattern = nValue;
            PATH_SetFootprintCollisionMask(pDynamicPath, 0x100);
        }
    }
}
