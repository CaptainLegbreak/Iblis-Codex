struct D2AutomapCellStrc
{
    unsigned int fSaved;
    unsigned short nCellNo;
    unsigned short xPixel;
    unsigned short yPixel;
    unsigned short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __cdecl sub_00457F40_OpenAutomapFile();                                                               // 0x00457F40
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30
void __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot);              // 0x00457B00
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2AutomapLayerStrc* gpAutomapContext_007A5164;                                                              // 0x007A5164
extern D2AutomapRecordStrc* gpAutomapRecord_007A0638;                                                       // 0x007A0638
extern int gnAutomapCelFrames_007A5178[4];                                                                  // 0x007A5178

void __stdcall sub_00457E40_AddAutomapCell(unsigned short nCellNo, unsigned short xPixel, unsigned short yPixel, D2AutomapCellStrc** ppRoot, unsigned int fSaved)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    pCell->fSaved = fSaved;
    pCell->nCellNo = nCellNo;
    pCell->xPixel = xPixel;
    pCell->yPixel = yPixel;
    sub_00457B00(pCell, ppRoot);
}

// 0x004586E0
static void __stdcall sub_004586E0_UnlinkAutomapLayer(void* hFile, unsigned int* pOffsets, unsigned int nPrev)
{
    unsigned long nCount = 0;
    if (nPrev)
    {
        sub_004069F0_SetFilePointer(hFile, nPrev, 0, 0);
        nPrev = 0;
        sub_004069D0_WriteFile(hFile, &nPrev, 4, &nCount, 0);
    }
    else
    {
        pOffsets[gpAutomapContext_007A5164->nLayerNo] = 0;
        sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
        sub_004069D0_WriteFile(hFile, pOffsets, 0x190, &nCount, 0);
    }
}

// 0x00458750
void __cdecl sub_00458750()
{
    if (!gpAutomapContext_007A5164)
    {
        return;
    }
    void* hFile = sub_00457F40_OpenAutomapFile();
    if (hFile == (void*)-1)
    {
        return;
    }
    unsigned int anOffsets[100] = { 0 };
    unsigned long nCount = 0;
    sub_004069B0_ReadFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    if (nCount == sizeof(anOffsets))
    {
        unsigned int nRecord = 0;
        unsigned int nLink = anOffsets[gpAutomapContext_007A5164->nLayerNo];
        unsigned short* pData;
        unsigned int nWords;
        unsigned int i;
        while (nLink)
        {
            D2AutomapSaveStrc tSave = { 0 };
            sub_004069F0_SetFilePointer(hFile, nLink, 0, 0);
            sub_004069B0_ReadFile(hFile, &nLink, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nLayerNo, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.fSaved, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nUnk0x08, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nFloors, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nWalls, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nObjects, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nExtras, 4, &nCount, 0);
            if (tSave.nLayerNo != gpAutomapContext_007A5164->nLayerNo)
            {
                sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                break;
            }
            if (tSave.nFloors)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.nFloors, ".\\UI\\automap.cpp", 0x575, 0);
                nWords = tSave.nFloors / 2;
                sub_004069B0_ReadFile(hFile, pData, tSave.nFloors, &nCount, 0);
                D2_ASSERT(nCount == tSave.nFloors, 0x57A);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gnAutomapCelFrames_007A5178[0])
                    {
                        sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pFloors, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x586, 0);
            }
            if (tSave.nWalls)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.nWalls, ".\\UI\\automap.cpp", 0x58A, 0);
                nWords = tSave.nWalls / 2;
                sub_004069B0_ReadFile(hFile, pData, tSave.nWalls, &nCount, 0);
                D2_ASSERT(nCount == tSave.nWalls, 0x58F);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gnAutomapCelFrames_007A5178[0])
                    {
                        sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pWalls, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x59B, 0);
            }
            if (tSave.nObjects)
            {
                if (tSave.nUnk0x08 == gpAutomapRecord_007A0638->nValue)
                {
                    pData = (unsigned short*)FOG_Alloc(tSave.nObjects, ".\\UI\\automap.cpp", 0x5A2, 0);
                    nWords = tSave.nObjects / 2;
                    sub_004069B0_ReadFile(hFile, pData, tSave.nObjects, &nCount, 0);
                    D2_ASSERT(nCount == tSave.nObjects, 0x5A7);
                    for (i = 0; i < nWords; i += 3)
                    {
                        if ((short)pData[i] >= gnAutomapCelFrames_007A5178[0])
                        {
                            sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                            break;
                        }
                        sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pObjects, 1);
                    }
                    FOG_Free(pData, ".\\UI\\automap.cpp", 0x5B3, 0);
                }
                else
                {
                    sub_004069F0_SetFilePointer(hFile, tSave.nObjects, 0, 1);
                }
            }
            if (tSave.nExtras)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.nExtras, ".\\UI\\automap.cpp", 0x5BD, 0);
                nWords = tSave.nExtras / 2;
                sub_004069B0_ReadFile(hFile, pData, tSave.nExtras, &nCount, 0);
                D2_ASSERT(nCount == tSave.nExtras, 0x5C2);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gnAutomapCelFrames_007A5178[tSave.fSaved])
                    {
                        sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pExtras, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x5CE, 0);
            }
            nRecord = nLink;
        }
    }
    sub_004069A0_CloseFile(hFile);
}
