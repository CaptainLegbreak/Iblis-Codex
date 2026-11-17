struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2CelStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x2C - 0x08];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x44 - 0x30];
    int nFrameFixed;
    char unk0x48[0x60 - 0x48];
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

struct D2CelContextStrc
{
    int nArg0;
    unsigned char nFlags;
    unsigned char nComponent;
    short unk0x06;
    int nType;
    int nClass;
    int nMode;
    int nOverlay;
    int nArg18;
    int nArg1C;
    unsigned int dwToken;
    unsigned int dwModeToken;
    unsigned int dwCode;
    const char* szName;
    int nFrames;
    int nArg34;
    int unk0x38;
    D2CelStrc* pCel;
    int nArg40;
    int unk0x44;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                                // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                          // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClass, int a4, int a5);   // 0x0064F380
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nWeaponClass, int nIndex);   // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClass, int nIndex);                   // 0x0046FA80
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                      // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine);   // 0x00645270
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                         // 0x00463E10
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                          // 0x006487F0
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode);   // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);
int __stdcall sub_00601920(D2CelStrc* pCel);                                                                 // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                                 // 0x00601950

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x004706E0
void __fastcall sub_004706E0_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nUnitType = pUnit->dwUnitType;
    int nClassId = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD4D);

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
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassCode, nMode, 0);
    if (!sub_0046E5A0_FindGfxListNode(pUnit, nWeaponClass, -1) && !sub_0046FA80_LoadGfxNode(pUnit, nWeaponClass, -1))
    {
        return;
    }

    const int nGfxMode = nMode;
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }

    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode && pNode->nMode != nGfxMode)
    {
        pNode = pNode->pNext;
    }

    if (!pNode || !pNode->f_8->pData)
    {
        return;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    int nOut;
    if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, PATH_GetDirection(pPath), pUnit->nFrameFixed >> 8, &nOut, nComponent, -1) && sub_006001F0(&tContext, 0, 1))
    {
        D2_ASSERT(tContext.pCel, 0xD7A);
        *pOffsetX = sub_00601920(tContext.pCel);
        *pOffsetY = sub_00601950(tContext.pCel);
    }
}
