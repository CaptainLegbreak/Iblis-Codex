extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x18];
    D2SeedStrc tSeed;
    char unk0x28[0xA0];
    unsigned int dwFlagEx;
};

struct D2GfxLightStrc;

struct D2OverlayStrc
{
    int nType;
    int nOverlay;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int unk0x2C;
    int unk0x30;
    int n34;
    int nState;
    int nActive;
    D2GfxLightStrc* pLight;
    char unk0x44[0x60];
    D2OverlayStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x2C];
    D2OverlayStrc* pOverlays;
};

struct D2OverlayTxt
{
    char unk0x00[0x42];
    short wPreDraw;
    char unk0x44[4];
    unsigned char nByte48;
    char unk0x49[0x0B];
    int n54;
    int n58;
    int n5C;
    int n60;
    int n64;
    int n68;
    int n6C;
    int n70;
    int n74;
    int n78;
    unsigned char unk0x7C;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    char unk0x80[4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBBC];
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
int __fastcall sub_0046E100(D2UnitStrc* pUnit, int nOverlay);                                               // 0x0046E100
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0
D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160
void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290
int __fastcall sub_004DBE20(D2UnitStrc* pUnit, D2OverlayStrc* pOverlay);                                    // 0x004DBE20
int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit);                                                    // 0x006223A0

static __forceinline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x0046DEF0
static void sub_0046DEF0_SyncStateOverlay(D2OverlayStrc* pOverlay, D2GfxDataStrc* pGfx)
{
    for (D2OverlayStrc* pOther = pGfx->pOverlays; pOther; pOther = pOther->pNext)
    {
        if (pOther->nType == 8 && pOther != pOverlay)
        {
            if (pOther->nState == pOverlay->nState)
            {
                pOverlay->nActive = pOther->nActive;
                pOverlay->n08 = pOther->n08;
                return;
            }
            if (pOther->nActive)
            {
                pOverlay->nActive = 0;
                return;
            }
        }
    }
    pOverlay->nActive = 1;
    pOverlay->n08 = 0;
}

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8)
{
    if (nOverlay < 0 || nOverlay >= sgptDataTables->nOverlayTxtRecordCount)
        return;

    D2OverlayTxt* pTxt = &sgptDataTables->pOverlayTxt[nOverlay];
    if (!pTxt)
        return;

    if (!sub_00408F20_HasExpansionMpq() && pTxt->wPreDraw >= 0x64)
        return;

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pUnit)
    {
        if (UNIT_HasFlagEx(pUnit, 0x40000))
            return;

        if (pUnit->dwUnitType == 1 && sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 2))
            return;
    }

    if (nType == 8 && sub_0046E100(pUnit, nOverlay))
        return;

    if (nOverlay < 0x8C || nOverlay > 0x8E && nOverlay != 0x9E)
        sub_0046F0C0(pUnit, pTxt->nByte48, nOverlay);

    D2OverlayStrc* pNew = (D2OverlayStrc*)FOG_Alloc(sizeof(D2OverlayStrc), ".\\ENGINE\\Gfx.cpp", 0xC48, 0);
    D2_ASSERT(pNew, 0xC49);
    memset(pNew, 0, sizeof(D2OverlayStrc));
    pNew->nType = nType;
    pNew->nOverlay = nOverlay;
    pNew->n1C = sub_004DBE20(pUnit, pNew);
    switch (nType)
    {
    case 2:
        pNew->n08 = 1;
        break;
    case 6:
        pNew->n18 = ITEMS_RollLimitedRandomNumber(&pPlayer->tSeed, pNew->n1C);
        break;
    default:
        pNew->n08 = nArg5;
        pNew->n0C = nArg6;
        pNew->n10 = nArg7;
        break;
    }

    pNew->n20 = pTxt->n54;
    pNew->n24 = pTxt->n58;
    switch (UNITS_GetOverlayHeight(pUnit))
    {
    case -1:
        pNew->n24 += 0x4B;
        break;
    case 0:
        pNew->n24 += pTxt->n5C;
        break;
    case 1:
        pNew->n24 += pTxt->n60;
        break;
    case 2:
        pNew->n24 += pTxt->n64;
        break;
    case 3:
        pNew->n24 += pTxt->n68;
        break;
    }

    if (pTxt->n74)
    {
        pNew->pLight = sub_00474160_MakeLightEntry(pUnit, 1, pTxt->n70, 0xFF, pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
        if (pTxt->n74 != pTxt->n70)
            sub_00474290(pNew->pLight, pTxt->n74);
    }

    D2GfxDataStrc* pGfx = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfx, 0xC7A);
    pNew->n34 = pTxt->nByte48;
    pNew->pNext = pGfx->pOverlays;
    pGfx->pOverlays = pNew;
    if (pNew->nType == 8)
    {
        pNew->nState = nArg5;
        sub_0046DEF0_SyncStateOverlay(pNew, pGfx);
    }

    if (nArg4)
        pNew->n18 = ITEMS_RollLimitedRandomNumber(&pPlayer->tSeed, nArg4 << 8);

    pNew->n14 = pTxt->n6C << 4;
    if (nArg8)
        pNew->n14 += ITEMS_RollLimitedRandomNumber(&pPlayer->tSeed, nArg8 << 4);

    pNew->n28 = pTxt->n78;
}
