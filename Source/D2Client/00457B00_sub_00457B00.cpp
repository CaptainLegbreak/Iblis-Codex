struct D2AutomapCellStrc
{
    unsigned int fSaved;
    short nCellNo;
    short xPixel;
    short yPixel;
    short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

struct D2AutomapCellBlockStrc
{
    D2AutomapCellStrc aCells[512];
    D2AutomapCellBlockStrc* pNext;
};

struct D2AutomapContextStrc
{
    int unk0x00;
    int nLayerKind;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __stdcall sub_00457900_RotateLeftHeavy(D2AutomapCellStrc** ppRoot);                                    // 0x00457900
void __stdcall sub_004579E0_RotateRightHeavy(D2AutomapCellStrc** ppRoot);                                   // 0x004579E0

extern int gaAutomapCellTable_007A3150[0x800];                                                              // 0x007A3150

static D2AutomapCellBlockStrc* gpAutomapCellBlocks_007A5158;                                                // 0x007A5158
static int gnAutomapCellCount_007A515C;                                                                     // 0x007A515C
static D2AutomapContextStrc* gpAutomapContext_007A5164;                                                     // 0x007A5164

// 0x00457B00
int __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pRoot = *ppRoot;
    D2AutomapCellStrc* pRotate = pRoot;
    int nResult;
    if (pRoot)
    {
        int nDiff = pCell->yPixel - pRoot->yPixel;
        if (!nDiff)
        {
            nDiff = pCell->xPixel - pRoot->xPixel;
            if (!nDiff)
            {
                const int nValue = gaAutomapCellTable_007A3150[pCell->nCellNo];
                if (nValue != -1 && nValue != gaAutomapCellTable_007A3150[pRoot->nCellNo])
                    nDiff = pCell->nCellNo - pRoot->nCellNo;
            }
        }
        if (nDiff < 0)
        {
            nResult = sub_00457B00(pCell, &pRoot->pPrev);
            if (nResult)
            {
                switch (pRoot->wWeight)
                {
                case -1:
                    sub_00457900_RotateLeftHeavy(&pRotate);
                    pRoot = pRotate;
                    nResult = 0;
                    break;
                case 0:
                    pRoot->wWeight = -1;
                    break;
                case 1:
                    pRoot->wWeight = 0;
                    nResult = 0;
                    break;
                }
            }
        }
        else if (nDiff > 0)
        {
            nResult = sub_00457B00(pCell, &pRoot->pNext);
            if (nResult)
            {
                switch (pRoot->wWeight)
                {
                case -1:
                    pRoot->wWeight = 0;
                    nResult = 0;
                    break;
                case 0:
                    pRoot->wWeight = 1;
                    break;
                case 1:
                    sub_004579E0_RotateRightHeavy(&pRotate);
                    pRoot = pRotate;
                    nResult = 0;
                    break;
                }
            }
        }
        else
        {
            nResult = 0;
        }
    }
    else
    {
        pCell->pPrev = 0;
        pCell->pNext = 0;
        pRoot = pCell;
        pCell->wWeight = 0;
        nResult = 1;
    }
    *ppRoot = pRoot;
    return nResult;
}

// 0x00458680
void __cdecl sub_00458680_ResetAutomapCells()
{
    if (gpAutomapContext_007A5164)
    {
        D2AutomapCellBlockStrc* pBlock = gpAutomapCellBlocks_007A5158;
        while (pBlock)
        {
            D2AutomapCellBlockStrc* pFree = pBlock;
            pBlock = pBlock->pNext;
            FOG_Free(pFree, ".\\UI\\automap.cpp", 0x51E, 0);
        }
        gpAutomapCellBlocks_007A5158 = 0;
        gnAutomapCellCount_007A515C = 0;
        gpAutomapContext_007A5164->pFloors = 0;
        gpAutomapContext_007A5164->pWalls = 0;
        gpAutomapContext_007A5164->pObjects = 0;
        gpAutomapContext_007A5164->pExtras = 0;
    }
}

void __fastcall sub_J02_EmitSetAutomapContext(D2AutomapContextStrc* pContext, D2AutomapCellBlockStrc* pBlock)
{
    gpAutomapContext_007A5164 = pContext;
    gpAutomapCellBlocks_007A5158 = pBlock;
    gnAutomapCellCount_007A515C = 7;
}
