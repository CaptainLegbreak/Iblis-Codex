struct D2GameStrc;
struct D2InventoryStrc;
struct D2CorpseStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc
{
    char unk00[12];
    int nX;
    int nY;
};
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk08;
    int dwUnitId;
    int dwAnimMode;
    char unk14[24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk30[48];
    D2InventoryStrc* pInventory;
};

struct D2CorpseSaveStrc
{
    unsigned int unk0x00;
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory);                             // 0x0063D570
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse);                                       // 0x0063D630
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __fastcall sub_005317B0_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pData, int nBufferSize, int a4, int a5, int a6); // 0x005317B0

static __forceinline int sub_00531C10_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int sub_00531C10_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00531C10
int __fastcall sub_00531C10_WriteCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nSize, int a5)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pCorpse = 0;
    unsigned short nCorpses = 0;
    D2CorpseStrc* pCorpseNode = INVENTORY_GetFirstCorpse(pInventory);
    if (pCorpseNode)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetUnitGUIDFromCorpse(pCorpseNode));
        if (pCorpse)
        {
            nCorpses = 1;
        }
    }

    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    nSize -= 4;
    *(unsigned short*)pData = nCorpses;
    pData += 2;

    if (!pCorpse)
    {
        return 4;
    }

    D2CorpseSaveStrc tCorpse;
    const int nX = sub_00531C10_GetUnitX(pCorpse);
    const int nY = sub_00531C10_GetUnitY(pCorpse);

    D2_ASSERT(nSize >= sizeof(tCorpse), 0x97A);
    tCorpse.nX = nX;
    tCorpse.nY = nY;
    memcpy(pData, &tCorpse, sizeof(tCorpse));
    pData += sizeof(tCorpse);
    nSize -= sizeof(tCorpse);

    D2InventoryStrc* const tArg3 = pCorpse->pInventory;
    const int nWritten = sub_005317B0_WriteItems(pGame, pCorpse, tArg3, pData, nSize, 0, a5, 0);
    D2_ASSERT(nWritten > 0, 0x984);
    return nWritten + 16;
}
