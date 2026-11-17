struct D2MonsterInteractStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    int unk0x10;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x4C];
    int dwInteractGUID;
    int dwInteractType;
    unsigned char nInteract;
    char unk0x6D[0x77];
    D2UnitStrc* pListNext;
};

struct D2GameStrc
{
    char unk0x00[0x1120];
    D2UnitStrc* pUnitList[5][128];
    D2UnitStrc* pTileList;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define UNIT_LIST_MASK 0x7F

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const int s_anUnitListOffset_006E10E0[6]; // 0x006E10E0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract); // 0x00572E00
void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc);       // 0x00536B50
void __fastcall sub_6FC79C00(D2GameStrc* pGame, D2UnitStrc* pObject);                                       // 0x00585550
void __stdcall D2Common_10228(D2UnitStrc* pUnit);                                                           // 0x00649F50
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

inline D2UnitStrc** SUNIT_GetUnitList(int nUnitType, D2GameStrc* pGame, int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
    {
        return (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }

    return 0;
}

// 0x005530F0
static void sub_005530F0_RemoveFromUnitList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc** ppUnitList;
    if (pUnit->dwUnitType == UNIT_TILE)
    {
        ppUnitList = &pGame->pTileList;
    }
    else
    {
        ppUnitList = SUNIT_GetUnitList(pUnit->dwUnitType, pGame, pUnit->dwUnitId);
    }

    D2UnitStrc* pPrevious = 0;
    D2UnitStrc* i;
    for (i = *ppUnitList; i; i = i->pListNext)
    {
        if (i == pUnit)
        {
            break;
        }
        pPrevious = i;
    }

    if (i)
    {
        if (!pPrevious)
        {
            *ppUnitList = i->pListNext;
        }
        else
        {
            pPrevious->pListNext = i->pListNext;
        }
    }
}

// 0x00555500
static void sub_00555500_ClearPlayerInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nInteractGUID = pUnit->dwInteractGUID;
    const int nInteractType = pUnit->dwInteractType;
    if (pUnit->nInteract)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nInteractType, nInteractGUID);
        if (pInteractUnit)
        {
            switch (pInteractUnit->dwUnitType)
            {
            case UNIT_MONSTER:
                MONSTERAI_RemoveInteractInfoFor(pGame, pUnit, !pInteractUnit->pMonsterData ? 0 : pInteractUnit->pMonsterData->pMonInteract);
                SUNITPROXY_FreeVendorChain(pGame, pUnit, pInteractUnit);
                break;
            case UNIT_OBJECT:
                sub_6FC79C00(pGame, pInteractUnit);
                break;
            }

            pUnit->dwInteractGUID = -1;
            pUnit->dwInteractType = UNIT_INVALID;
            pUnit->nInteract = 0;
        }
    }
}

// 0x00555580
void __fastcall sub_00555580_DetachUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int bKeepInRoom)
{
    D2_ASSERT(pUnit, 940);
    D2_ASSERT(pUnit->dwUnitType < 6, 941);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        sub_00555500_ClearPlayerInteraction(pGame, pUnit);
        D2Common_10228(pUnit);
        break;
    case UNIT_MONSTER:
        D2Common_10228(pUnit);
        break;
    case UNIT_OBJECT:
        D2Common_10228(pUnit);
        break;
    case UNIT_MISSILE:
        D2Common_10228(pUnit);
        break;
    }

    if (!bKeepInRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    sub_005530F0_RemoveFromUnitList(pGame, pUnit);
}
