struct D2DynamicPathStrc
{
    char unk0x00[0x48];
    int dwCollisionPattern;
    int nCollisionMask;
};

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

struct D2ActiveRoomStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize);                        // 0x00648580
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit);                                        // 0x00649400
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce);                          // 0x00649560

#define UNIT_MONSTER 1
#define UNIT_INVALID 6

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
