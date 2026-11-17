struct D2SkillStrc;
struct D2SkillListStrc;
struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2CoordStrc
{
    int nX;
    int nY;
};
struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
    int dwUnk0x14;
    int dwUnk0x18;
    unsigned char nDirection;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[4];
    void* pMonsterData;
    char unk0x18[20];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[120];
    D2SkillListStrc* pSkills;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" const char gszUnitsSourceFile;                                                                   // 0x006E8E10
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910
void __stdcall STATLIST_FreeStatListEx(D2UnitStrc* pUnit);                                                  // 0x00626D10
void __stdcall SKILLS_FreeSkillList(D2UnitStrc* pUnit);                                                     // 0x00643A60
int __stdcall PATH_GetPrecisionX(D2DynamicPathStrc* pPath);                                                 // 0x00648940
int __stdcall PATH_GetPrecisionY(D2DynamicPathStrc* pPath);                                                 // 0x00648970
int __stdcall PATH_GetClientCoordX(D2DynamicPathStrc* pPath);                                               // 0x006489C0
int __stdcall PATH_GetClientCoordY(D2DynamicPathStrc* pPath);                                               // 0x006489D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX);                                     // 0x006489E0
void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY);                                     // 0x006489F0
void __stdcall PATH_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pRoom);                             // 0x00648A90
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID);         // 0x00648BB0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define FP16_SHIFT 16

// 0x00620100
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 955);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        return pUnit->pStaticPath->nDirection;

    default:
        return PATH_GetDirection(pUnit->pDynamicPath);
    }
}

// 0x00620150
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1592);
    return SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills);
}

// 0x00620360
void __fastcall sub_00620360(D2UnitStrc* pUnit, int nX, int nY, int nUnk0x14, int nUnk0x18)
{
    D2_ASSERT(pUnit, 1711);
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 1713);

    D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
    pStaticPath->tGameCoords.nX = nX;
    pStaticPath->tGameCoords.nY = nY;
    pStaticPath->dwUnk0x14 = nUnk0x14;
    pStaticPath->dwUnk0x18 = nUnk0x18;
}

// 0x006203B0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1732);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX << FP16_SHIFT;

    default:
        return PATH_GetPrecisionX(pUnit->pDynamicPath);
    }
}

// 0x00620410
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1754);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY << FP16_SHIFT;

    default:
        return PATH_GetPrecisionY(pUnit->pDynamicPath);
    }
}

// 0x00620470
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX)
{
    D2_ASSERT(pUnit, 1775);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        pUnit->pStaticPath->tGameCoords.nX = nX;
        break;

    default:
        D2_ASSERT(0, 1786);
    }
}

// 0x006204C0
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY)
{
    D2_ASSERT(pUnit, 1798);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        pUnit->pStaticPath->tGameCoords.nY = nY;
        break;

    default:
        D2_ASSERT(0, 1809);
    }
}

// 0x00620650
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1909);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->dwClientCoordX;

    default:
        return PATH_GetClientCoordX(pUnit->pDynamicPath);
    }
}

// 0x006206B0
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1930);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->dwClientCoordY;

    default:
        return PATH_GetClientCoordY(pUnit->pDynamicPath);
    }
}

// 0x00620710
int __stdcall UNITS_GetAbsoluteXDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nX1;
    int nX2;

    switch (pUnit1->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX1 = pUnit1->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit1->pDynamicPath)
        {
            nX1 = PATH_GetXPosition(pUnit1->pDynamicPath);
        }
        else
        {
            nX1 = 0;
        }
        break;
    }

    switch (pUnit2->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX2 = pUnit2->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit2->pDynamicPath)
        {
            nX2 = PATH_GetXPosition(pUnit2->pDynamicPath);
        }
        else
        {
            nX2 = 0;
        }
        break;
    }

    int nDistance = nX1 - nX2;
    if (nDistance < 0)
    {
        nDistance = -nDistance;
    }

    return nDistance;
}

// 0x00620780
int __stdcall UNITS_GetAbsoluteYDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nY1;
    int nY2;

    switch (pUnit1->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY1 = pUnit1->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit1->pDynamicPath)
        {
            nY1 = PATH_GetYPosition(pUnit1->pDynamicPath);
        }
        else
        {
            nY1 = 0;
        }
        break;
    }

    switch (pUnit2->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY2 = pUnit2->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit2->pDynamicPath)
        {
            nY2 = PATH_GetYPosition(pUnit2->pDynamicPath);
        }
        else
        {
            nY2 = 0;
        }
        break;
    }

    int nDistance = nY1 - nY2;
    if (nDistance < 0)
    {
        nDistance = -nDistance;
    }

    return nDistance;
}

// 0x006207F0
void __stdcall UNITS_SetTargetX(D2UnitStrc* pUnit, int nTargetX)
{
    D2_ASSERT(pUnit, 1970);

    PATH_SetClientCoordX(pUnit->pDynamicPath, nTargetX);
}

// 0x00620830
void __stdcall UNITS_SetTargetY(D2UnitStrc* pUnit, int nTargetY)
{
    D2_ASSERT(pUnit, 1982);

    PATH_SetClientCoordY(pUnit->pDynamicPath, nTargetY);
}

// 0x00620870
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2_ASSERT(pUnit, 1994);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        {
            D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
            pCoord->nX = pStaticPath->tGameCoords.nX;
            pCoord->nY = pStaticPath->tGameCoords.nY;
        }
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            pCoord->nX = PATH_GetXPosition(pUnit->pDynamicPath);
            pCoord->nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            pCoord->nX = 0;
            pCoord->nY = 0;
        }
        break;
    }
}

// 0x00620900
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords)
{
    D2_ASSERT(pUnit, 2023);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        {
            D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
            pClientCoords->nX = pStaticPath->dwClientCoordX;
            pClientCoords->nY = pStaticPath->dwClientCoordY;
        }
        break;

    default:
        pClientCoords->nX = PATH_GetClientCoordX(pUnit->pDynamicPath);
        pClientCoords->nY = PATH_GetClientCoordY(pUnit->pDynamicPath);
        break;
    }
}

// 0x00620980
void __fastcall sub_00620980(D2UnitStrc* pUnit, int nClientX, int nClientY)
{
    D2_ASSERT(pUnit, 2047);
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 2049);

    D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
    pStaticPath->dwClientCoordX = nClientX;
    pStaticPath->dwClientCoordY = nClientY;
}

// 0x00620B50
void __stdcall UNITS_ResetRoom(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2173);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        pUnit->pStaticPath->pRoom = 0;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            PATH_SetRoom(pUnit->pDynamicPath, 0);
        }
        break;
    }
}

// 0x00620C70
int __stdcall UNITS_GetTargetTypeFromDynamicUnit(D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2_ASSERT(pUnit, 2233);
    D2_ASSERT((pUnit->dwUnitType == UNIT_PLAYER) || (pUnit->dwUnitType == UNIT_MONSTER) || (pUnit->dwUnitType == UNIT_MISSILE), 2235);

    PATH_GetTargetTypeAndGUID(pUnit->pDynamicPath, &nUnitType, &nUnitGUID);
    return nUnitType;
}

// 0x00620CD0
int __stdcall UNITS_GetTargetGUIDFromDynamicUnit(D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2_ASSERT(pUnit, 2250);
    D2_ASSERT((pUnit->dwUnitType == UNIT_PLAYER) || (pUnit->dwUnitType == UNIT_MONSTER) || (pUnit->dwUnitType == UNIT_MISSILE), 2252);

    PATH_GetTargetTypeAndGUID(pUnit->pDynamicPath, &nUnitType, &nUnitGUID);
    return nUnitGUID;
}

// 0x00620D30
void __stdcall UNITS_SetTargetUnitForPlayerOrMonster(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(pUnit, 2268);
    D2_ASSERT((pUnit->dwUnitType == UNIT_PLAYER) || (pUnit->dwUnitType == UNIT_MONSTER), 2270);

    PATH_SetTargetUnit(pUnit->pDynamicPath, pTargetUnit);
}
