struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x60 - 0x08];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC8 - 0x64];
    unsigned int dwFlagEx;
};

struct D2HashedFileEntryStrc
{
    char unk0x00[0x14];
    void* pData;
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    D2HashedFileEntryStrc* f_8;
    char unk0x0C[0x04];
    D2GfxListNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x28];
    D2GfxListNodeStrc* pList;
};

struct D2GfxBoundsStrc
{
    char unk0x00[0x08];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                                // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                          // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClass, int a4, int a5);   // 0x0064F380
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nWeaponClass, int nIndex);   // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClass, int nIndex);                   // 0x0046FA80
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                      // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine);   // 0x00645270
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                         // 0x00463E10
extern "C" void* __fastcall sub_004DB040_identity(void* pointer);                                             // 0x004DB040

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x00470860
int __fastcall sub_00470860_HitTestUnitGfx(D2UnitStrc* pUnit, int nOriginX, int nOriginY, int nX, int nY)
{
    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    int nWeaponClassCode;
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassCode, -1, 1);
    if (!sub_0046E5A0_FindGfxListNode(pUnit, nWeaponClass, -1))
    {
        sub_0046FA80_LoadGfxNode(pUnit, nWeaponClass, -1);
    }

    int nUnitType = pUnit->dwUnitType;
    int nClassId = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD90);

    const int nGfxMode = nMode;
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return 0;
    }

    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode && pNode->nMode != nGfxMode)
    {
        pNode = pNode->pNext;
    }

    if (!pNode || !pNode->f_8->pData)
    {
        return 0;
    }

    D2GfxBoundsStrc* pBounds = (D2GfxBoundsStrc*)sub_004DB040_identity(pNode->f_8->pData);
    D2_ASSERT(pBounds, 0xDA4);

    if (nX < pBounds->nLeft + nOriginX - 16 || nX >= pBounds->nRight + nOriginX + 16)
    {
        return 0;
    }

    if (nY < pBounds->nTop + nOriginY - 16 || nY >= pBounds->nBottom + nOriginY + 16)
    {
        return 0;
    }

    return 1;
}
