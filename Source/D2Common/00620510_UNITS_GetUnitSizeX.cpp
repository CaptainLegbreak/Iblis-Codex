struct D2DynamicPathStrc;
struct T00620190;
struct D2MonStats2Txt
{
    char unk0x00[8];
    signed char nSizeX;
    signed char nSizeY;
};
struct D2MissilesTxt
{
    char unk0x00[394];
    unsigned char nSize;
};
struct D2ObjectsTxt
{
    char unk0x00[208];
    int dwSizeX;
    int dwSizeY;
};
struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[8];
    unsigned int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0
unsigned int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                           // 0x00621190
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId);                                             // 0x00463900

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define PLRMODE_WALK 2
#define PLRMODE_RUN 3
#define PLRMODE_TOWNWALK 6
#define MONMODE_WALK 2
#define MONMODE_SKILL1 8
#define MONMODE_SKILL2 9
#define MONMODE_RUN 15
#define MONSTER_VULTURE1 110
#define SIZE_PLAYER 2
#define SIZE_ITEM 1
#define TRUE 1
#define FALSE 0

// 0x00620510
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            return SIZE_PLAYER;

        case UNIT_MONSTER:
            if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
            {
                return pMonStats2TxtRecord->nSizeX;
            }
            return 0;

        case UNIT_OBJECT:
            return pUnit->pObjectData->pObjectTxt->dwSizeX;

        case UNIT_ITEM:
            return SIZE_ITEM;

        case UNIT_MISSILE:
            if (D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pUnit->dwClassId))
            {
                return pMissilesTxtRecord->nSize;
            }
            return 0;

        case UNIT_TILE:
            return 0;

        default:
            return 0;
        }
    }

    return 0;
}

// 0x006205A0
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1867);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SIZE_PLAYER;

    case UNIT_MONSTER:
        if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
        {
            return pMonStats2TxtRecord->nSizeY;
        }
        return 0;

    case UNIT_OBJECT:
        return pUnit->pObjectData->pObjectTxt->dwSizeY;

    case UNIT_ITEM:
        return SIZE_ITEM;

    case UNIT_MISSILE:
        if (D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pUnit->dwClassId))
        {
            return pMissilesTxtRecord->nSize;
        }
        return 0;

    case UNIT_TILE:
        return 0;

    default:
        return 0;
    }
}
