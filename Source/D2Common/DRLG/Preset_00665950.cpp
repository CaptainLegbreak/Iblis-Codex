#include "D2DataTbls.h"
struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    D2MapAIStrc* pMapAI;
    int nUnitType;
    int nYpos;
    int dwFlags;
};

struct D2DrlgSubstGroupStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int unk0x10;
    int nSubstGroup;
};

struct D2DrlgFileStrc
{
    int nSubstMethod;
    void* pDS1File;
    int unk0x08;
    int nWidth;
    int nHeight;
    int nWallLayers;
    int nFloorLayers;
    int* pTileTypeLayer[4];
    int* pWallLayer[4];
    int* pFloorLayer[2];
    int* pShadowLayer;
    int* pSubstGroupTags;
    int nSubstGroups;
    D2DrlgSubstGroupStrc* pSubstGroups;
    D2PresetUnitStrc* pPresetUnit;
    D2DrlgFileStrc* pNext;
};

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nPlace;
    unsigned short wPlace;
};


struct D2PresetCodeStrc
{
    char c0;
    char c1;
    char c2;
    char c3;
};

struct D2ItemsTxt;

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
unsigned int __fastcall sub_006C9A38(const char* szString);                                                    // 0x006C9A38
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
D2MonPresetTxt* __stdcall DATATBLS_GetMonPresetTxtActSection(int nAct, int* pnRecords);                     // 0x00659B40
int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount(); // 0x00655710
int __fastcall sub_004E6C50_ValidateMonsterId(int nMonsterId);                                              // 0x004E6C50
D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(void* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30
int __fastcall DRLGPRESET_MapTileType(int nId);                                                             // 0x0066D7F0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const char* gpszPresetItemCodes_00748AD4[];                                                          // 0x00748AD4
extern int gnPresetObjectIndices[5][150];                                                                   // 0x00748AD8

static void sub_00665810_CopyCodePadded(D2PresetCodeStrc* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        const char c = 0x20;
        pDst->c0 = c;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c0 = pSrc[0];
    if (!pSrc[1])
    {
        const char c = 0x20;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c1 = pSrc[1];
    if (!pSrc[2])
    {
        const char c = 0x20;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c2 = pSrc[2];
    pDst->c3 = 0x20;
}

__declspec(noinline) int __fastcall sub_004E6C50_ValidateMonsterId(int nMonsterId);

static __forceinline int sub_IsSubstMethod(int nSubstMethod)
{
    switch (nSubstMethod)
    {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}

// 0x00665950
void __fastcall DRLGPRESET_ParseDS1File(D2DrlgFileStrc* pDrlgFile, void* hArchive, const char* szFileName)
{
    int* pData = (int*)ARCHIVE_AllocateBufferAndReadFile(hArchive, szFileName, 0, ".\\DRLG\\Preset.cpp", 0x300);
    pDrlgFile->pDS1File = pData;

    int nAct = 0;
    int nVersion = *pData++;
    pDrlgFile->nWidth = *pData++;
    pDrlgFile->nHeight = *pData++;

    if (nVersion >= 8)
    {
        nAct = *pData++;
        if (nAct > 4)
        {
            nAct = 4;
        }
    }

    pDrlgFile->nSubstMethod = 0;
    if (nVersion >= 10)
    {
        pDrlgFile->nSubstMethod = *pData++;
    }

    if (nVersion >= 3)
    {
        int nFiles = *pData++;
        for (int i = 0; i < nFiles; ++i)
        {
            pData = (int*)((char*)pData + sub_006C9A38((const char*)pData) + 1);
        }
    }

    int nCells = (pDrlgFile->nWidth + 1) * (pDrlgFile->nHeight + 1);

    if (nVersion >= 9 && nVersion <= 13)
    {
        pData += 2;
    }

    if (nVersion >= 4)
    {
        pDrlgFile->nWallLayers = *pData++;
        if (nVersion >= 16)
        {
            pDrlgFile->nFloorLayers = *pData++;
        }
        else
        {
            pDrlgFile->nFloorLayers = 1;
        }

        for (int i = 0; i < pDrlgFile->nWallLayers; ++i)
        {
            pDrlgFile->pWallLayer[i] = pData;
            pData += nCells;
            pDrlgFile->pTileTypeLayer[i] = pData;
            pData += nCells;
        }

        for (int i = 0; i < pDrlgFile->nFloorLayers; ++i)
        {
            pDrlgFile->pFloorLayer[i] = pData;
            pData += nCells;
        }
    }
    else
    {
        pDrlgFile->pWallLayer[0] = pData;
        pData += nCells;
        pDrlgFile->pFloorLayer[0] = pData;
        pData += nCells;
        pDrlgFile->pTileTypeLayer[0] = pData;
        pData += nCells;
        pDrlgFile->pSubstGroupTags = pData;
        pDrlgFile->nWallLayers = 1;
        pData += nCells;
    }

    if (nVersion < 7)
    {
        for (int i = 0; i < pDrlgFile->nWallLayers; ++i)
        {
            int* pTileType = pDrlgFile->pTileTypeLayer[i];
            for (int j = 0; j < nCells; ++j)
            {
                *pTileType = DRLGPRESET_MapTileType(*pTileType);
                ++pTileType;
            }
        }
    }

    pDrlgFile->pShadowLayer = pData;
    pData += nCells;

    switch (pDrlgFile->nSubstMethod)
    {
    case 1:
    case 2:
        pDrlgFile->pSubstGroupTags = pData;
        pData += nCells;
        break;
    }

    if (nVersion > 1)
    {
        int nObjects = *pData++;
        for (int i = 0; i < nObjects; ++i)
        {
            int nType = *pData++;
            int nIndex = *pData++;
            int nMode = 0;

            switch (nType)
            {
            case 1:
                nMode = 1;
                if (nVersion > 4)
                {
                    int nRecords = 0;
                    D2MonPresetTxt* pMonPreset = DATATBLS_GetMonPresetTxtActSection(nAct, &nRecords);
                    if (pMonPreset && nIndex < nRecords)
                    {
                        unsigned char nPlace = pMonPreset[nIndex].nPlace;
                        nIndex = pMonPreset[nIndex].wPlace;
                        switch (nPlace)
                        {
                        case 0:
                            nIndex += DATATBLS_GetSuperUniquesTxtRecordCount();
                            nIndex += sgptDataTables->nMonStatsTxtRecordCount;
                            break;
                        case 1:
                            break;
                        case 2:
                            nIndex += sgptDataTables->nMonStatsTxtRecordCount;
                            break;
                        default:
                            nIndex = -1;
                            break;
                        }
                    }

                    if (nAct == 2)
                    {
                        if (nIndex < sgptDataTables->nMonStatsTxtRecordCount)
                        {
                            if (nIndex == sub_004E6C50_ValidateMonsterId(297))
                            {
                                nIndex = 382;
                                nType = 2;
                                nMode = 0;
                            }
                            else if (nIndex == sub_004E6C50_ValidateMonsterId(366))
                            {
                                nIndex = 404;
                                nType = 2;
                                nMode = 0;
                            }
                        }
                    }
                    else if (nAct == 4)
                    {
                        if (nIndex < sgptDataTables->nMonStatsTxtRecordCount && nIndex >= 0)
                        {
                            switch (nIndex)
                            {
                            case 514:
                                nIndex = 461;
                                nType = 2;
                                nMode = 0;
                                break;
                            case 537:
                            case 538:
                            case 539:
                                nIndex = 1013 - nIndex;
                                nType = 2;
                                nMode = 0;
                                break;
                            }
                        }
                    }
                }
                break;

            case 2:
                if (nVersion > 5)
                {
                    if (nIndex < 150)
                    {
                        nIndex = gnPresetObjectIndices[nAct][nIndex];
                    }
                    else
                    {
                        nIndex -= 150;
                    }
                }
                else if (nIndex == 573)
                {
                    nIndex = -1;
                }
                break;

            case 4:
                if (nVersion > 4)
                {
                    char szCode[4];
                    strncpy(szCode, gpszPresetItemCodes_00748AD4[nIndex], 4);
                    szCode[3] = 0;
                    for (int j = 0; j < 3; ++j)
                    {
                        szCode[j] = tolower(szCode[j]);
                    }
                    unsigned int dwCode = 0;
                    sub_00665810_CopyCodePadded((D2PresetCodeStrc*)&dwCode, szCode);
                    DATATBLS_GetItemRecordFromItemCode(dwCode, &nIndex);
                }
                nMode = 3;
                break;
            }

            int nX = *pData++;
            int nY = *pData++;
            int nFlags = 0;
            if (nVersion > 5)
            {
                nFlags = *pData++;
            }

            if (nIndex >= 0 && (nType != 1 || nVersion > 4))
            {
                D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, 0, nType, nIndex, nMode, nX, nY);
                pPresetUnit->pNext = pDrlgFile->pPresetUnit;
                pDrlgFile->pPresetUnit = pPresetUnit;
                pPresetUnit->dwFlags |= nFlags;
            }
        }
    }

    if (nVersion >= 12 && sub_IsSubstMethod(pDrlgFile->nSubstMethod))
    {
        if (nVersion >= 18)
        {
            ++pData;
        }

        pDrlgFile->nSubstGroups = *pData++;
        pDrlgFile->pSubstGroups = (D2DrlgSubstGroupStrc*)FOG_AllocPool(0, sizeof(D2DrlgSubstGroupStrc) * pDrlgFile->nSubstGroups, ".\\DRLG\\Preset.cpp", 1142, 0);
        for (int i = 0; i < pDrlgFile->nSubstGroups; ++i)
        {
            pDrlgFile->pSubstGroups[i].nX = *pData++;
            pDrlgFile->pSubstGroups[i].nY = *pData++;
            pDrlgFile->pSubstGroups[i].nWidth = *pData++;
            pDrlgFile->pSubstGroups[i].nHeight = *pData++;
            if (nVersion >= 13)
            {
                pDrlgFile->pSubstGroups[i].nSubstGroup = *pData++;
            }
        }
    }

    if (nVersion >= 14)
    {
        int nNodes = *pData++;
        for (int i = 0; i < nNodes; ++i)
        {
            int nPoints = *pData++;
            int nX = *pData++;
            int nY = *pData++;
            if (nPoints)
            {
                D2PresetUnitStrc* pPresetUnit = pDrlgFile->pPresetUnit;
                while (pPresetUnit)
                {
                    if (pPresetUnit->nXpos == nX && pPresetUnit->nYpos == nY)
                    {
                        break;
                    }
                    pPresetUnit = pPresetUnit->pNext;
                }

                if (pPresetUnit)
                {
                    pPresetUnit->pMapAI = (D2MapAIStrc*)FOG_AllocPool(0, sizeof(D2MapAIStrc), ".\\DRLG\\Preset.cpp", 1192, 0);
                    pPresetUnit->pMapAI->pPosition = (D2MapAIPathPositionStrc*)FOG_AllocPool(0, sizeof(D2MapAIPathPositionStrc) * nPoints, ".\\DRLG\\Preset.cpp", 1193, 0);
                    pPresetUnit->pMapAI->nPathNodes = nPoints;
                    for (int j = 0; j < nPoints; ++j)
                    {
                        pPresetUnit->pMapAI->pPosition[j].nX = *pData++;
                        pPresetUnit->pMapAI->pPosition[j].nY = *pData++;
                        if (nVersion >= 15)
                        {
                            pPresetUnit->pMapAI->pPosition[j].nMapAIAction = *pData++;
                        }
                        else
                        {
                            pPresetUnit->pMapAI->pPosition[j].nMapAIAction = 1;
                        }
                    }
                }
                else
                {
                    pData += 2 * nPoints;
                    if (nVersion >= 15)
                    {
                        pData += nPoints;
                    }
                }
            }
        }
    }
}

// build: context sub_004E6C50_ValidateMonsterId
// calling-convention shim (not game code)
int __fastcall sub_004E6C50_ValidateMonsterId(int nMonsterId)
{

    return nMonsterId / sgptDataTables->nMonStatsTxtRecordCount;
}

#include "gen/data/Source/D2Common/DRLG/Preset_00665950.inc"
