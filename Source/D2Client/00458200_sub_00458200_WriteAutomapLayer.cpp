struct D2AutomapCellStrc;

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
};

struct D2AutomapSaveStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    unsigned int nUnk0x08;
    unsigned int nFloors;
    unsigned int nWalls;
    unsigned int nObjects;
    unsigned int nExtras;
    void* pFloors;
    void* pWalls;
    void* pObjects;
    void* pExtras;
};

struct D2AutomapRecordStrc
{
    unsigned int nUnk0x00;
    unsigned int nValue;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __cdecl sub_00457F40_OpenAutomapFile();                                                               // 0x00457F40
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh); // 0x006CC2F0
void __fastcall sub_00458440_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount);                  // 0x00458440
void __fastcall sub_00458470_StoreCells(D2AutomapCellStrc* pCells);                                         // 0x00458470
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern D2AutomapLayerStrc* gpAutomapContext_007A5164;                                                       // 0x007A5164
extern D2AutomapRecordStrc* gpAutomapRecord_007A0638;                                                       // 0x007A0638
extern void* gpAutomapSaveBuffer_007A5154;                                                                  // 0x007A5154

// 0x00458200
static void sub_00458200_WriteAutomapLayer(D2AutomapSaveStrc* pSave)
{
    void* hFile = sub_00457F40_OpenAutomapFile();
    if (hFile == (void*)-1)
    {
        return;
    }
    unsigned int anOffsets[100] = { 0 };
    unsigned long nCount = 0;
    sub_004069B0_ReadFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    if (nCount != sizeof(anOffsets))
    {
        memset(anOffsets, 0, sizeof(anOffsets));
        sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
        sub_004069D0_WriteFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    }
    unsigned int nOffset = anOffsets[pSave->nLayerNo];
    unsigned int nEnd = GetFileSize(hFile, 0);
    if (nOffset)
    {
        unsigned int nPrev;
        do
        {
            sub_004069F0_SetFilePointer(hFile, nOffset, 0, 0);
            nPrev = nOffset;
            sub_004069B0_ReadFile(hFile, &nOffset, 4, &nCount, 0);
        }
        while (nOffset);
        sub_004069F0_SetFilePointer(hFile, nPrev, 0, 0);
        sub_004069D0_WriteFile(hFile, &nEnd, 4, &nCount, 0);
    }
    else
    {
        anOffsets[pSave->nLayerNo] = nEnd;
    }
    sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
    sub_004069D0_WriteFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    sub_004069F0_SetFilePointer(hFile, nEnd, 0, 0);
    nEnd = 0;
    sub_004069D0_WriteFile(hFile, &nEnd, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nLayerNo, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->fSaved, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nUnk0x08, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nFloors, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nWalls, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nObjects, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nExtras, 4, &nCount, 0);
    if (pSave->nFloors)
        sub_004069D0_WriteFile(hFile, pSave->pFloors, pSave->nFloors, &nCount, 0);
    if (pSave->nWalls)
        sub_004069D0_WriteFile(hFile, pSave->pWalls, pSave->nWalls, &nCount, 0);
    if (pSave->nObjects)
        sub_004069D0_WriteFile(hFile, pSave->pObjects, pSave->nObjects, &nCount, 0);
    if (pSave->nExtras)
        sub_004069D0_WriteFile(hFile, pSave->pExtras, pSave->nExtras, &nCount, 0);
    sub_004069A0_CloseFile(hFile);
}

void __cdecl sub_004584C0()
{
    D2AutomapLayerStrc* pLayer = gpAutomapContext_007A5164;
    if (!pLayer)
    {
        return;
    }
    D2AutomapSaveStrc tSave = { pLayer->nLayerNo };
    tSave.fSaved = pLayer->fSaved;
    tSave.nUnk0x08 = gpAutomapRecord_007A0638->nValue;
    sub_00458440_CountCells(pLayer->pFloors, &tSave.nFloors);
    sub_00458440_CountCells(pLayer->pWalls, &tSave.nWalls);
    sub_00458440_CountCells(pLayer->pObjects, &tSave.nObjects);
    sub_00458440_CountCells(pLayer->pExtras, &tSave.nExtras);
    if (!tSave.nFloors && !tSave.nWalls && !tSave.nObjects && !tSave.nExtras)
    {
        return;
    }
    if (tSave.nFloors)
    {
        tSave.pFloors = FOG_Alloc(tSave.nFloors, ".\\UI\\automap.cpp", 0x4EA, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pFloors;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pFloors);
    }
    if (tSave.nWalls)
    {
        tSave.pWalls = FOG_Alloc(tSave.nWalls, ".\\UI\\automap.cpp", 0x4F1, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pWalls;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pWalls);
    }
    if (tSave.nObjects)
    {
        tSave.pObjects = FOG_Alloc(tSave.nObjects, ".\\UI\\automap.cpp", 0x4F8, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pObjects;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pObjects);
    }
    if (tSave.nExtras)
    {
        tSave.pExtras = FOG_Alloc(tSave.nExtras, ".\\UI\\automap.cpp", 0x4FF, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pExtras;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pExtras);
    }
    sub_00458200_WriteAutomapLayer(&tSave);
    if (tSave.pFloors)
        FOG_Free(tSave.pFloors, ".\\UI\\automap.cpp", 0x509, 0);
    if (tSave.pWalls)
        FOG_Free(tSave.pWalls, ".\\UI\\automap.cpp", 0x50A, 0);
    if (tSave.pObjects)
        FOG_Free(tSave.pObjects, ".\\UI\\automap.cpp", 0x50B, 0);
    if (tSave.pExtras)
        FOG_Free(tSave.pExtras, ".\\UI\\automap.cpp", 0x50C, 0);
}
