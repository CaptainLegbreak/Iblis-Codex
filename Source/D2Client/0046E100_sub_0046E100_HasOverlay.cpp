struct D2UnitStrc;

struct D2GfxNodeTargetStrc
{
    char unk0x00[0x14];
    int nValue;
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    D2GfxNodeTargetStrc* pTarget;
    char unk0x0C[0x4];
    D2GfxListNodeStrc* pNext;
};

struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    char unk0x08[0x9C];
    D2UnitOverlayStrc* pNext;
};

struct D2GfxEntryStrc
{
    unsigned char nValue;
    unsigned char unk0x01;
};

#define GFX_ENTRY_COUNT 20

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[GFX_ENTRY_COUNT];
    D2GfxListNodeStrc* pList;
    D2UnitOverlayStrc* pOverlays;
    int nUnk0x30;
    int nUnk0x34;
    int nUnk0x38;
};

struct D2HashedFileEntryStrc;

struct D2HashedFileStrc
{
    int f_0;
    unsigned char* pData;
    unsigned int nSize;
    D2HashedFileEntryStrc* f_C[0x200];
};

struct D2MonGfxCacheStrc
{
    char unk0x00[0xA0];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

#define GFX_INDEX_COUNT 16
#define GFX_MODE_KEEP 0x11

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);  // 0x0040B430
void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay);                  // 0x0046E040
int __fastcall sub_0046D9F0_TestUnit(D2UnitStrc* pUnit);                                                    // 0x0046D9F0
void __fastcall sub_004DB1C0_SetGfxByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue);              // 0x004DB1C0
int __cdecl sub_004FAC90();                                                                                 // 0x004FAC90
void __cdecl sub_004DA790();                                                                                // 0x004DA790

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2MonGfxCacheStrc* gpPoolBlock_007A80FC;                                                             // 0x007A80FC
extern D2HashedFileStrc gtHashedFile_007A8100;                                                              // 0x007A8100
extern D2HashedFileStrc gtHashedFile_007A78F0;                                                              // 0x007A78F0
extern char gData_007A7490[0x460];                                                                          // 0x007A7490
extern int gdwGlobal_007A8910;                                                                              // 0x007A8910
extern int gdwGlobal_007A891C;                                                                              // 0x007A891C
int gdwGlobal_007A8928;                                                                                     // 0x007A8928

// 0x0046E100
int __fastcall sub_0046E100_HasOverlay(D2UnitStrc* pUnit, int nOverlay)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x1EA);
    for (D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays; pOverlay; pOverlay = pOverlay->pNext)
    {
        if (pOverlay->nOverlay == nOverlay)
        {
            return 1;
        }
    }
    return 0;
}

// 0x0046E570
int __fastcall sub_0046E570_GetNodeValue(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->nValue;
            }
        }
    }
    return 0;
}

// 0x0046EBB0
D2GfxDataStrc* __cdecl sub_0046EBB0_AllocGfxData()
{
    D2GfxDataStrc* pGfxData = (D2GfxDataStrc*)FOG_Alloc(sizeof(D2GfxDataStrc), ".\\ENGINE\\Gfx.cpp", 0x804, 0);
    D2_ASSERT(pGfxData, 0x805);
    memset(pGfxData, 0, sizeof(D2GfxDataStrc));
    pGfxData->nUnk0x34 = 2;
    pGfxData->nUnk0x38 = 2;
    return pGfxData;
}

// 0x0046EC80
void __fastcall sub_0046EC80_FreeGfxNodes(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x82A);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x830, 0);
        pNode = pNext;
    }
    pGfxData->pList = 0;
}

// 0x0046ECE0
void __fastcall sub_0046ECE0_PruneGfxNodes(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x83D);
    D2GfxListNodeStrc* pPrev = 0;
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        if (pNode->nMode && pNode->nMode != GFX_MODE_KEEP)
        {
            FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x847, 0);
            if (!pPrev)
            {
                pGfxData->pList = pNext;
            }
            else
            {
                pPrev->pNext = pNext;
            }
        }
        else
        {
            pPrev = pNode;
        }
        pNode = pNext;
    }
}

// 0x0046F020
void __fastcall sub_0046F020_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0xBBA);
    for (int i = 0; i < GFX_ENTRY_COUNT; ++i)
    {
        pGfxData->tEntries[i].nValue = nValue;
    }
}

// 0x0046F070
void __fastcall sub_0046F070_SetGfxValue(D2UnitStrc* pUnit, int nValue)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        pGfxData->nUnk0x30 = nValue;
    }
}

// 0x0046F170
void __fastcall sub_0046F170_RemoveOverlays(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0xCCF);
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2UnitOverlayStrc* pNext = pOverlay->pNext;
        sub_0046E040_RemoveOverlay(pUnit, pOverlay);
        pOverlay = pNext;
    }
}

// 0x0046F1C0
void __fastcall sub_0046F1C0_SetGfx34(D2GfxDataStrc* pGfxData, int nValue)
{
    D2_ASSERT(pGfxData, 0xCE4);
    pGfxData->nUnk0x34 = nValue;
}

// 0x0046F220
void __fastcall sub_0046F220_SetGfx38(D2GfxDataStrc* pGfxData, int nValue)
{
    D2_ASSERT(pGfxData, 0xCFD);
    pGfxData->nUnk0x38 = nValue;
}

// 0x0046F280
void __fastcall sub_0046F280_ClearGfxBytes(D2UnitStrc* pUnit, int nIndex)
{
    if (nIndex >= GFX_INDEX_COUNT)
    {
        return;
    }
    switch (sub_0046D9F0_TestUnit(pUnit))
    {
    case 0:
        for (unsigned int i = 0; i < GFX_ENTRY_COUNT; ++i)
        {
            sub_004DB1C0_SetGfxByte(pUnit, i, 0);
        }
        break;
    case 1:
        for (int i = 0; i < GFX_INDEX_COUNT; ++i)
        {
            sub_004DB1C0_SetGfxByte(pUnit, i, 0);
        }
        break;
    case 2:
        for (int i = 0; i < 8; ++i)
        {
            sub_004DB1C0_SetGfxByte(pUnit, i, 0);
        }
        break;
    default:
        D2_ASSERT(0, 0xD3E);
        break;
    }
}

// 0x0046F9D0
D2MonGfxCacheStrc* __fastcall sub_0046F9D0_GetMonGfxCache(int nMonsterId)
{
    return &gpPoolBlock_007A80FC[nMonsterId];
}

// 0x00470200
void __fastcall sub_00470200_InitGfxTables(int nValue)
{
    gdwGlobal_007A8910 = 0;
    gdwGlobal_007A891C = nValue;
    memset(&gtHashedFile_007A8100, 0, sizeof(gtHashedFile_007A8100));
    memset(&gtHashedFile_007A78F0, 0, sizeof(gtHashedFile_007A78F0));
    memset(gData_007A7490, 0, sizeof(gData_007A7490));
    const int nSize = sgptDataTables->nMonStatsTxtRecordCount * sizeof(D2MonGfxCacheStrc);
    gpPoolBlock_007A80FC = (D2MonGfxCacheStrc*)sub_0040B430(0, nSize, ".\\ENGINE\\Gfx.cpp", 0x7E1, 0);
    memset(gpPoolBlock_007A80FC, 0, nSize);
    gdwGlobal_007A8928 = sub_004FAC90();
    sub_004DA790();
}
