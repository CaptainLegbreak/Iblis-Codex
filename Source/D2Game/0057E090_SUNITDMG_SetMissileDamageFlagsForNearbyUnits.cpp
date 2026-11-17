struct D2ActiveRoomStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int unk0x10[9];
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int unk0x40[3];
    int dwDmgTotal;
    int unk0x50[4];
    unsigned int dwHitClass;
    unsigned char nHitClassActiveSet;
    signed char nConvType;
    unsigned short unk0x66;
    int dwConvPct;
    int nOverlay;
};

struct D2UnitFindArgStrc
{
    int nFlags;
    int unk0x04;
    D2UnitStrc* pUnit;
    int nX;
    int nY;
    int nSize;
    int nMaxArrayEntries;
    int nIndex;
    void* pField;
    void* pfnUnitTest;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    void* pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nFlags;
    int nIndex;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
};

typedef int (__fastcall* DAMAGECALLBACK)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(DAMAGECALLBACK lpfn);                           // 0x006CC34C
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD730
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall sub_00645950_CheckTargetPos(int nX, int nY, D2UnitStrc* pUnit, int nCollisionMask);           // 0x00645950
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                              // 0x0065AA00
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData);         // 0x0065AC70

// 0x0057E090
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, DAMAGECALLBACK pfCallback, int a10)
{
    D2DamageStrc damage;
    D2UnitFindArgStrc unitFindArg;
    D2UnitFindDataStrc unitFindData;
    D2ActiveRoomStrc* pRoom;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOwnerOwner;
    int nFlags;
    int i;
    int bResult;

    bResult = 0;
    pRoom = UNITS_GetRoom(pUnit);
    pRoom = D2GAME_GetRoom_6FC52070(pRoom, nX, nY);

    nFlags = a10;
    if (!a10)
    {
        nFlags = 0x583;
    }

    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nFlags = nFlags;
    unitFindArg.nSize = nSize;
    unitFindArg.nY = nY;
    unitFindArg.nX = nX;

    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    pOwner = SUNIT_GetOwner(pGame, pUnit);
    pOwnerOwner = pOwner ? SUNIT_GetOwner(pGame, pOwner) : 0;
    if (!pOwner)
    {
        UNITFINDS_FreeUnitFindData(&unitFindData);
        return 0;
    }

    for (i = 0; i < unitFindData.nIndex; ++i)
    {
        if ((pOwnerOwner != unitFindData.pUnitsArray[i] || a8) && (pOwner != unitFindData.pUnitsArray[i] || a7)
            && sub_00554200(pGame, pOwner, unitFindData.pUnitsArray[i])
            && sub_00645950_CheckTargetPos(nX, nY, unitFindData.pUnitsArray[i], 0x805))
        {
            damage = *pDamage;
            if (pfCallback)
            {
                D2_ASSERT(!IsBadCodePtr(pfCallback), 0xDA6);

                if (pfCallback(pGame, pUnit, unitFindData.pUnitsArray[i]))
                {
                    MISSMODE_SetDamageFlags(pGame, pUnit, unitFindData.pUnitsArray[i], &damage);
                    bResult = 1;
                }
            }
            else
            {
                MISSMODE_SetDamageFlags(pGame, pUnit, unitFindData.pUnitsArray[i], &damage);
                bResult = 1;
            }
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
    return bResult;
}
