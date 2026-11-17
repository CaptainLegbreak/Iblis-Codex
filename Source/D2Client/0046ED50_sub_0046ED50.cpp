struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
    char unk0x64[0x64];
    unsigned int dwFlagEx;
};

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    char unk0x10[0x198];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
};

struct D2ObjectsTxt
{
    char unk0x00[0x118];
    unsigned char nBlocksLight[8];
    char unk0x120[0x28];
    int dwXOffset;
    int dwYOffset;
    unsigned char nDraw;
};

struct D2CelStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

struct D2GfxLayerHeaderStrc
{
    unsigned char nLayers;
    unsigned char unk0x01;
    unsigned char nArg;
};

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_INVALID 6
#define STAT_HITPOINTS 6
#define MONSTATSFLAGINDEX_INTERACT 9

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks_006CE268[];                                                                 // 0x006CE268
int gbHealthBarColorsInit_007A8924;                                                                         // 0x007A8924
unsigned char gnHealthBarColors_007A890C[4];                                                                // 0x007A890C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);   // 0x004FB180
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2);           // 0x004709A0
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
int __fastcall sub_004DBB50_InitCelContext(D2CelContextStrc* pContext, D2UnitStrc* pUnit, int a3, int nDirection, int nFrame, int* pOut, int a7, int a8); // 0x004DBB50
void __stdcall sub_004F6570_DrawCelColored(D2CelContextStrc* pContext, int nX, int nY, unsigned char nColor); // 0x004F6570
int __stdcall sub_004DA0B0_GetUnitGfxOffsetX(D2UnitStrc* pUnit);                                            // 0x004DA0B0
int __stdcall sub_004DA0D0_GetUnitGfxOffsetY(D2UnitStrc* pUnit);                                            // 0x004DA0D0
int __stdcall sub_004DA0F0_GetUnitGfxOffsetZ(D2UnitStrc* pUnit);                                            // 0x004DA0F0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
void __stdcall sub_004F6760_PrecisionToScreen(int nPrecisionX, int nPrecisionY, int nArg, int* pX, int* pY); // 0x004F6760
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                // 0x0046FA80
void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode);                                   // 0x0046E570
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx);                                   // 0x004DB040
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
unsigned char* __fastcall sub_004DB110_GetLayerOrder(void* pGfx, int nA, int nFrame);                       // 0x004DB110
int __fastcall sub_004DBD30_CountVisibleLayers(D2UnitStrc* pUnit, D2GfxLayerHeaderStrc* pHeader, unsigned char* pLayers, int* pOut, int nDirection, int nFrame); // 0x004DBD30
int __fastcall sub_004DB670_IsLayerVisible(D2UnitStrc* pUnit, int nLayer);                                  // 0x004DB670

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0046ED50
static unsigned char sub_0046ED50(D2UnitStrc* pUnit)
{
    if (!gbHealthBarColorsInit_007A8924)
    {
        gnHealthBarColors_007A890C[0] = D2Win_10034_MixRGB(0, 0xC0, 0);
        gnHealthBarColors_007A890C[1] = D2Win_10034_MixRGB(0xE0, 0xE0, 0);
        gnHealthBarColors_007A890C[2] = D2Win_10034_MixRGB(0xE0, 0, 0);
        gnHealthBarColors_007A890C[3] = D2Win_10034_MixRGB(0, 0, 0xC0);
        gbHealthBarColorsInit_007A8924 = 1;
    }
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x991);
    if (nType != UNIT_MONSTER)
    {
        return gnHealthBarColors_007A890C[0];
    }
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClass);
    if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks_006CE268[MONSTATSFLAGINDEX_INTERACT & 7])
    {
        return gnHealthBarColors_007A890C[3];
    }
    int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (!nMaxLife)
    {
        return gnHealthBarColors_007A890C[0];
    }
    int nPercent = 100 * STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) / nMaxLife;
    if (nPercent < 33)
    {
        return gnHealthBarColors_007A890C[2];
    }
    if (nPercent < 66)
    {
        return gnHealthBarColors_007A890C[1];
    }
    return gnHealthBarColors_007A890C[0];
}

// 0x00471A30
int __fastcall sub_00471A30(D2UnitStrc* pUnit)
{
    int nOffsetX = 0;
    int nOffsetY = 0;
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x9B6);
    int bPerspective = sub_004F51D0_IsPerspective();
    if (nType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClass);
        D2_ASSERT(pObjectsTxtRecord, 0x9BE);
        if (!pObjectsTxtRecord->nDraw || !pObjectsTxtRecord->nBlocksLight[nMode])
        {
            return 0;
        }
        nOffsetY = pObjectsTxtRecord->dwYOffset;
        nOffsetX = pObjectsTxtRecord->dwXOffset;
    }
    int nX = nOffsetX - sub_0045AFC0() + UNITS_GetClientCoordX(pUnit);
    int nY = nOffsetY - sub_0045AFD0_GetMouseYOffset() + UNITS_GetClientCoordY(pUnit);
    if (bPerspective)
    {
        switch (sub_0045AE90())
        {
        case 1:
            nX += -(gnGlobal_0071146C / 4);
            break;
        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
    }
    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
    {
        return 0;
    }
    unsigned char nColor = sub_0046ED50(pUnit);
    unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    sub_004F6570_DrawCelColored(&tContext, nX, nY, nColor);
    return 1;
}

// 0x00471BD0
int __fastcall sub_00471BD0(D2UnitStrc* pUnit)
{
    int nX;
    int nY;
    int bPerspective = sub_004F51D0_IsPerspective();
    if (pUnit && pUnit->dwUnitType >= UNIT_PLAYER && pUnit->dwUnitType <= UNIT_OBJECT)
    {
        if (bPerspective)
        {
            int nZ = sub_004DA0F0_GetUnitGfxOffsetZ(pUnit);
            sub_004F6760_PrecisionToScreen(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), nZ, &nX, &nY);
            switch (sub_0045AE90())
            {
            case 1:
                nX += -(gnGlobal_0071146C / 4);
                break;
            case 2:
                nX += gnGlobal_0071146C / 4;
                break;
            }
            nY += 0x10;
            nX += sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
            nY += sub_004DA0D0_GetUnitGfxOffsetY(pUnit);
        }
        else
        {
            nX = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0() + sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
            nY = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset() + sub_004DA0D0_GetUnitGfxOffsetY(pUnit);
            nY += sub_004DA0F0_GetUnitGfxOffsetZ(pUnit);
        }
        if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
        {
            return 0;
        }
        unsigned char nColor = sub_0046ED50(pUnit);
        int nType = pUnit->dwUnitType;
        int nClass = pUnit->dwClassId;
        int nMode = UNITS_GetAnimOrSeqMode(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0xA2F);
        int nDirection = UNITS_GetDirection(pUnit);
        int nFrameNo;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
        D2InventoryStrc* pInventory;
        D2UnitStrc* pOwner;
        if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
        {
            pInventory = pOwner->pInventory;
        }
        else
        {
            pInventory = pUnit->pInventory;
        }
        int nWeaponClassId;
        int nComponent = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, nMode, 0);
        if (!sub_0046E5A0_FindGfxNode(pUnit, nComponent, -1) && !sub_0046FA80_LoadGfxNode(pUnit, nComponent, -1))
        {
            return 0;
        }
        void* pGfx = sub_0046E570_GetGfxEntry(pUnit, nMode);
        if (!pGfx)
        {
            return 0;
        }
        D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pGfx);
        int nA;
        int nB;
        sub_004DB2E0_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nA, &nB, pHeader->nArg, 1);
        unsigned char* pLayers = sub_004DB110_GetLayerOrder(pGfx, nA, nFrameNo);
        D2_ASSERT(pLayers, 0xA56);
        int nVisible = 0;
        if (sub_004DBD30_CountVisibleLayers(pUnit, pHeader, pLayers, &nVisible, nDirection, nFrameNo) > 0)
        {
            for (unsigned int i = 0; i < pHeader->nLayers; ++i)
            {
                int nLayer = pLayers[i];
                if (sub_004DB670_IsLayerVisible(pUnit, nLayer))
                {
                    D2CelContextStrc tContext;
                    memset(&tContext, 0, sizeof(tContext));
                    int nOut;
                    if (sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, nLayer, -1))
                    {
                        sub_004F6570_DrawCelColored(&tContext, nX, nY, nColor);
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    sub_00471A30(pUnit);
    return 1;
}
