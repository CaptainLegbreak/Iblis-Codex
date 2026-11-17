struct D2CelFileStrc;

struct D2CofNodeStrc
{
    int nRefCount;
    int unk0x04[4];
    void* pCofData;
    D2CofNodeStrc* pNext;
    D2CofNodeStrc* pPrev;
};

struct D2CofInfoStrc
{
    D2CofNodeStrc* pCofNode;
    D2CofInfoStrc* pNext;
};

struct D2GfxInfoStrc
{
    D2CofInfoStrc* pCofInfo;
};

struct D2CompositeUnitStrc
{
    char unk0x00[0xB8];
    D2GfxInfoStrc* pGfxInfo;
    D2CelFileStrc* pEmblemCellFile;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_004FAAE0_FreeCellFile(D2CelFileStrc* pCellFile);                                        // 0x004FAAE0
void __fastcall sub_00504100_UnlinkCompositeUnit(D2CompositeUnitStrc* pCompositeUnit);                      // 0x00504100
D2CofNodeStrc* gpCofNodeList_0087E83C;                                                                      // 0x0087E83C

// 0x00503410
static void __stdcall sub_00503410(int bFree, D2CofNodeStrc* pCofNode)
{
    D2_ASSERT(pCofNode, 0x455);

    if (!gpCofNodeList_0087E83C)
        return;

    --pCofNode->nRefCount;
    if (pCofNode->nRefCount > 0)
        return;

    D2CofNodeStrc* pPrev = pCofNode->pPrev;
    D2CofNodeStrc* pNext = pCofNode->pNext;
    if (bFree)
    {
        FOG_Free(pCofNode->pCofData, ".\\Src\\D2Comp.cpp", 0x461, 0);
        pCofNode->pCofData = 0;
    }

    if (!pPrev)
    {
        gpCofNodeList_0087E83C = pNext;
        if (pNext)
            pNext->pPrev = 0;
    }
    else if (!pNext)
    {
        pPrev->pNext = 0;
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }

    FOG_Free(pCofNode, ".\\Src\\D2Comp.cpp", 0x47A, 0);
}

void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink)
{
    D2_ASSERT(pCompositeUnit, 0x877);

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x87B);

    D2CofInfoStrc* pCofInfo = pGfxInfo->pCofInfo;
    while (pCofInfo)
    {
        D2CofNodeStrc* pCofNode = pCofInfo->pCofNode;
        D2CofInfoStrc* pNext = pCofInfo->pNext;
        sub_00503410(1, pCofNode);
        FOG_Free(pCofInfo, ".\\Src\\D2Comp.cpp", 0x883, 0);
        pCofInfo = pNext;
    }

    pGfxInfo->pCofInfo = 0;
    FOG_Free(pGfxInfo, ".\\Src\\D2Comp.cpp", 0x889, 0);

    if (pCompositeUnit->pEmblemCellFile)
    {
        sub_004FAAE0_FreeCellFile(pCompositeUnit->pEmblemCellFile);
        pCompositeUnit->pEmblemCellFile = 0;
    }

    if (bUnlink)
        sub_00504100_UnlinkCompositeUnit(pCompositeUnit);
}
