#include "D2StateIds.h"
#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Drlg.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2AutomapRecordStrc;
struct D2AutomapFileHeaderStrc;
struct D2AutomapCellStrc;
struct D2AutomapLayerStrc;
struct D2AutomapSaveStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct Unicode;
struct D2AutomapPointStrc;

struct D2AutomapFileHeaderStrc
{
    int nVersion;
    int nNext;
    unsigned int nSeeds[4];
};

typedef char D2AutomapFileHeaderSizeCheck[sizeof(D2AutomapFileHeaderStrc) == 0x18 ? 1 : -1];

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile);
int __fastcall sub_00406990_DeleteFile(const char* szFileName);
int __fastcall sub_004069A0_CloseFile(void* hFile);
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped);
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped);
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod);
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);
extern char gszCharName_007A05C4[]; // 0x007A05C4
extern D2AutomapRecordStrc* gpAutomapRecord_007A0638; // 0x007A0638

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __cdecl sub_00457F40_OpenAutomapFile(); // 0x00457F40
void __fastcall sub_00458470_StoreCells(D2AutomapCellStrc* pCells); // 0x00458470
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" const char szAutomapFile_006D66F0[]; // 0x006D66F0

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2AutomapCellStrc* __cdecl sub_00457C30(); // 0x00457C30
int __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot); // 0x00457B00
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gbRevealAutomap_007A51A0; // 0x007A51A0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
const char* __cdecl sub_0044B7C0_GetRecordText1F(); // 0x0044B7C0
const char* __cdecl sub_0044B820_GetRecordText37(); // 0x0044B820
const char* __cdecl sub_0044B7F0_GetRecordText245(); // 0x0044B7F0
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
extern int gnAutomapWidth_007A5220; // 0x007A5220

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, va_list args); // 0x006CC4AC
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern int gdwGlobal_007A5150; // 0x007A5150
extern "C" size_t __cdecl strlen(const char* szString);

extern const D2AutomapPointStrc gaAutomapCross_006D6638[13]; // 0x006D6638
extern int gdwGlobal_007113E8; // 0x007113E8
extern int gnAutomapScale_00711254; // 0x00711254
extern int gnAutomapOffsetX_007A5198; // 0x007A5198
extern int gnAutomapOffsetY_007A519C; // 0x007A519C
extern unsigned char gnAutomapColors_007A51B0[]; // 0x007A51B0
extern int gnGlobal_007A51C8; // 0x007A51C8
extern int gnGlobal_007A51CC; // 0x007A51CC
extern int gnGlobal_007A51D0; // 0x007A51D0
extern int gnGlobal_007A51D4; // 0x007A51D4
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit); // 0x00465400
int __fastcall sub_00478D90_GetPetRelation(int nUnitId); // 0x00478D90
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
const char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x006221A0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0
int __fastcall sub_0047A1E0(D2StoredUnitRecordStrc* pEntry); // 0x0047A1E0
void __fastcall sub_0047A1B0_GetEntryPosition(D2StoredUnitRecordStrc* pEntry, int* pX, int* pY); // 0x0047A1B0
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790

char gszAccountFolder_007A0500[32]; // 0x007A0500

// 0x00457F40
void* __cdecl sub_00457F40_OpenAutomapFile()
{
    char szSavePath[0x104] = { 0 };
    char szFileName[0x104] = { 0 };
    char szAccountPath[0x104] = { 0 };

    sub_00407050_GetSavePath(szSavePath, sizeof(szSavePath));

    void* hFile = (void*)-1;
    if (gszAccountFolder_007A0500[0])
    {
        SStrPrintf(szAccountPath, sizeof(szAccountPath), "%s%s\\", szSavePath, gszAccountFolder_007A0500);
        sub_00406A10_CreateDirectoryTree(szAccountPath);
        SStrPrintf(szFileName, sizeof(szFileName), "%s%s.map", szAccountPath, gszCharName_007A05C4);
        hFile = sub_00406960_CreateFile(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (hFile != (void*)-1)
        {
            SStrCopy(szSavePath, szAccountPath, sizeof(szSavePath));
        }
    }

    if (hFile == (void*)-1)
    {
        sprintf(szFileName, "%s%s.map", szSavePath, gszCharName_007A05C4);
        hFile = sub_00406960_CreateFile(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (hFile == (void*)-1)
        {
            return hFile;
        }
    }

    D2AutomapFileHeaderStrc tHeader = { 0 };
    unsigned long nBytes = 0;
    sub_004069B0_ReadFile(hFile, &tHeader, sizeof(tHeader), &nBytes, 0);

    int bInvalid = 1;
    if (nBytes == sizeof(tHeader))
    {
        bInvalid = tHeader.nVersion != 12;
    }

    int nIndex;
    if (bInvalid)
    {
        tHeader.nVersion = 12;
        tHeader.nNext = 1;
        tHeader.nSeeds[0] = gpAutomapRecord_007A0638->nUnk0x00;
        for (int i = 0; i < 4; ++i)
        {
            sprintf(szFileName, "%s%s.ma%d", szSavePath, gszCharName_007A05C4, i);
            sub_00406990_DeleteFile(szFileName);
        }
        nIndex = 0;
    }
    else
    {
        for (nIndex = 0; nIndex < 4; ++nIndex)
        {
            if (tHeader.nSeeds[nIndex] == gpAutomapRecord_007A0638->nUnk0x00)
            {
                break;
            }
        }

        if (nIndex != 4)
        {
            goto reopen;
        }

        nIndex = tHeader.nNext;
        tHeader.nNext = (nIndex + 1) % 4;
        tHeader.nSeeds[nIndex] = gpAutomapRecord_007A0638->nUnk0x00;
        sprintf(szFileName, "%s%s.ma%d", szSavePath, gszCharName_007A05C4, nIndex);
        sub_00406990_DeleteFile(szFileName);
    }

    sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
    sub_004069D0_WriteFile(hFile, &tHeader, sizeof(tHeader), &nBytes, 0);

reopen:
    sub_004069A0_CloseFile(hFile);
    sprintf(szFileName, "%s%s.ma%d", szSavePath, gszCharName_007A05C4, nIndex);
    return sub_00406960_CreateFile(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
}

static D2AutomapLayerStrc* gpAutomapContext_007A5164; // 0x007A5164

static void* gpAutomapSaveBuffer_007A5154; // 0x007A5154

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
    sub_004069D0_WriteFile(hFile, &pSave->dwFloorSize, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->dwWallsSize, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nObjects, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->dwExtraSize, 4, &nCount, 0);
    if (pSave->dwFloorSize)
        sub_004069D0_WriteFile(hFile, pSave->pFloors, pSave->dwFloorSize, &nCount, 0);
    if (pSave->dwWallsSize)
        sub_004069D0_WriteFile(hFile, pSave->pWalls, pSave->dwWallsSize, &nCount, 0);
    if (pSave->nObjects)
        sub_004069D0_WriteFile(hFile, pSave->pObjects, pSave->nObjects, &nCount, 0);
    if (pSave->dwExtraSize)
        sub_004069D0_WriteFile(hFile, pSave->pExtras, pSave->dwExtraSize, &nCount, 0);
    sub_004069A0_CloseFile(hFile);
}

// 0x00458440
void __fastcall sub_00458440_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount)
{
    if (!pCells)
    {
        return;
    }
    sub_00458440_CountCells(pCells->pPrev, pCount);
    if (!pCells->fSaved)
    {
        *pCount += 6;
    }
    sub_00458440_CountCells(pCells->pNext, pCount);
}

// 0x004584C0
void __cdecl sub_004584C0()
{
    D2AutomapLayerStrc* pLayer = gpAutomapContext_007A5164;
    if (!pLayer)
    {
        return;
    }
    D2AutomapSaveStrc tSave;
    memset(&tSave.fSaved, 0, sizeof(tSave) - sizeof(tSave.nLayerNo));
    tSave.nLayerNo = pLayer->nLayerNo;
    tSave.fSaved = pLayer->fSaved;
    tSave.nUnk0x08 = gpAutomapRecord_007A0638->nValue;
    sub_00458440_CountCells(pLayer->pFloors, &tSave.dwFloorSize);
    sub_00458440_CountCells(pLayer->pWalls, &tSave.dwWallsSize);
    sub_00458440_CountCells(pLayer->pObjects, &tSave.nObjects);
    sub_00458440_CountCells(pLayer->pExtras, &tSave.dwExtraSize);
    if (!tSave.dwFloorSize && !tSave.dwWallsSize && !tSave.nObjects && !tSave.dwExtraSize)
    {
        return;
    }
    if (tSave.dwFloorSize)
    {
        tSave.pFloors = FOG_Alloc(tSave.dwFloorSize, szAutomapFile_006D66F0, 0x4EA, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pFloors;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pFloors);
    }
    if (tSave.dwWallsSize)
    {
        tSave.pWalls = FOG_Alloc(tSave.dwWallsSize, szAutomapFile_006D66F0, 0x4F1, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pWalls;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pWalls);
    }
    if (tSave.nObjects)
    {
        tSave.pObjects = FOG_Alloc(tSave.nObjects, szAutomapFile_006D66F0, 0x4F8, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pObjects;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pObjects);
    }
    if (tSave.dwExtraSize)
    {
        tSave.pExtras = FOG_Alloc(tSave.dwExtraSize, szAutomapFile_006D66F0, 0x4FF, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pExtras;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pExtras);
    }
    sub_00458200_WriteAutomapLayer(&tSave);
    if (tSave.pFloors)
        FOG_Free(tSave.pFloors, szAutomapFile_006D66F0, 0x509, 0);
    if (tSave.pWalls)
        FOG_Free(tSave.pWalls, szAutomapFile_006D66F0, 0x50A, 0);
    if (tSave.pObjects)
        FOG_Free(tSave.pObjects, szAutomapFile_006D66F0, 0x50B, 0);
    if (tSave.pExtras)
        FOG_Free(tSave.pExtras, szAutomapFile_006D66F0, 0x50C, 0);
}

// 0x00457E80
static void __stdcall sub_00457E80_AddUnitAutomapCell(int nCellNo, D2AutomapCellStrc** ppRoot, D2UnitStrc* pUnit)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    const int nX = UNITS_GetClientCoordX(pUnit) / 10 + 1;
    const int nY = UNITS_GetClientCoordY(pUnit) / 10 - 3;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 0x3C5);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 0x3C6);
    D2_ASSERT(nCellNo >= -0x8000 && nCellNo <= 0x7FFF, 0x3C7);
    pCell->nCellNo = nCellNo;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    sub_00457B00(pCell, ppRoot);
}

static inline int AUTOMAP_CheckFlagEx(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> nBit) & 1;
}

static inline D2MonStats2Txt* AUTOMAP_GetMonStats2TxtRecord(int nMonStatsEx)
{
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }
    return 0;
}

// 0x00458DC0
void __stdcall sub_00458DC0_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        const int nFlag = AUTOMAP_CheckFlagEx(pUnit, 28);
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (!gbRevealAutomap_007A51A0)
        {
            if (!nFlag)
                continue;

            if (AUTOMAP_CheckFlagEx(pUnit, 29))
                continue;
        }

        if (pUnit)
            pUnit->dwFlags |= 0x20000000;

        switch (nUnitType)
        {
        case UNIT_MONSTER:
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
                {
                    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nClassId].wMonStatsEx;
                    D2MonStats2Txt* pMonStats2Txt = AUTOMAP_GetMonStats2TxtRecord(nMonStatsEx);
                    if (pMonStats2Txt && pMonStats2Txt->dwAutomapCel)
                        sub_00457E80_AddUnitAutomapCell(pMonStats2Txt->dwAutomapCel, ppRoot, pUnit);
                }
            }
            break;

        case UNIT_OBJECT:
        {
            const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nClassId);
            const unsigned int nAutomap = pObjectsTxt->dwAutomap;
            if (!nAutomap)
                break;

            switch (nClassId)
            {
            default:
                sub_00457E80_AddUnitAutomapCell(nAutomap, ppRoot, pUnit);
                break;

            case 0x192:
                if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_ARCANESANCTUARY)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;

            case 0x16E:
                if ((!pUnit ? 0 : pUnit->dwAnimMode) == 2)
                    sub_00457E80_AddUnitAutomapCell(nAutomap, ppRoot, pUnit);
                break;

            case 0x10B:
            {
                const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (nAct == 2 || nAct == 3)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;
            }
            }
            break;
        }
        }
    }
}

int gnAutomapTextY_007A51BC; // 0x007A51BC

// 0x00459E90
void __cdecl sub_00459E90_DrawGameInfoLines()
{
    Unicode wszName[25];
    char szText[28];
    Unicode wszLine[50];
    for (int i = 0; i < 25; ++i)
        wszName[i].wChar = 0;
    for (int i = 0; i < 50; ++i)
        wszLine[i].wChar = 0;
    const char* szFirst = sub_0044B7C0_GetRecordText1F();
    const char* szSecond = sub_0044B820_GetRecordText37();
    if (!szFirst)
    {
        if (!szSecond)
            return;
    }
    else
    {
        sprintf(szText, gszStringFormat_006FFC58, szFirst);
        sub_00526320_ToUnicode(wszName, szText, 25);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0x1055));
        sub_00526700(wszLine, wszName);
        sub_00502320(wszLine, gnAutomapWidth_007A5220 - sub_00501820(wszLine) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
        gnAutomapTextY_007A51BC += 0x10;
    }
    const char* szThird = sub_0044B7F0_GetRecordText245();
    if (!szThird)
        return;
    sprintf(szText, gszStringFormat_006FFC58, szThird);
    sub_00526320_ToUnicode(wszName, szText, 25);
    sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0x1056));
    sub_00526700(wszLine, wszName);
    sub_00502320(wszLine, gnAutomapWidth_007A5220 - sub_00501820(wszLine) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x00459FF0
void __cdecl sub_00459FF0_DrawStringLine()
{
    Unicode wszText[50];
    for (int i = 0; i < 50; ++i)
        wszText[i].wChar = 0;
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x58CA));
    sub_00502320(wszText, gnAutomapWidth_007A5220 - sub_00501820(wszText) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x0045A0A0
void __cdecl sub_0045A0A0_DrawVersionLine()
{
    Unicode wszText[100];
    char szText[100];
    for (int i = 0; i < 100; ++i)
        wszText[i].wChar = 0;
    SStrPrintf(szText, 100, "v %d.%d%c", 1, 14, 100);
    sub_00526320_ToUnicode(wszText, szText, 100);
    const int nWidth = sub_00501820(wszText);
    sub_00502320(wszText, gnAutomapWidth_007A5220 - nWidth - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x0045A120
void __cdecl sub_0045A120_DrawLocalIpLine()
{
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, FOG_GetHostIPAddress(), 300);
    sub_00502320(wszText, gnAutomapWidth_007A5220 - sub_00501820(wszText) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

// 0x0045A190
void __cdecl sub_0045A190_DrawDifficultyLine()
{
    unsigned short nString;
    switch (sub_0044DCD0_GetDifficulty())
    {
    case 1:
        nString = 0x1423;
        break;
    case 2:
        nString = 0x1422;
        break;
    default:
        return;
    }
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
        wszText[i].wChar = 0;
    D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(nString)) + sub_00526800(D2LANG_GetStringFromTblIndex(0x1057)) + 3 < 300, 0xB2A);
    sub_005269D0(300, wszText, D2LANG_GetStringFromTblIndex(0x1057), D2LANG_GetStringFromTblIndex(nString));
    sub_00502320(wszText, gnAutomapWidth_007A5220 - sub_00501820(wszText) - 0x10, gnAutomapTextY_007A51BC, 4, 0);
    gnAutomapTextY_007A51BC += 0x10;
}

int gnAutomapCelFrames_007A5178[4]; // 0x007A5178

// 0x0045A2B0
void __cdecl sub_0045A2B0_ReloadAutomapCels()
{
    char szPath[260] = {0};
    for (int i = 0; i < 4; ++i)
    {
        if (gpAutomapCels_007A5168[i])
            sub_00478A00(gpAutomapCels_007A5168[i]);
        gpAutomapCels_007A5168[i] = 0;
    }
    switch (gdwGlobal_007A5150)
    {
    case 1:
        sprintf(szPath, "%s\\UI\\AutoMap\\MaxiMapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[0] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[0] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[0]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act2MapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[1] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[1] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[1]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act4MapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[2] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[2] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[2]);
        sprintf(szPath, "%s\\UI\\AutoMap\\ExTnMapS", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[3] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[3] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[3]);
        break;
    default:
        sprintf(szPath, "%s\\UI\\AutoMap\\MaxiMap", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[0] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[0] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[0]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act2Map", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[1] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[1] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[1]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act4Map", szDataGlobal_006D4118);
        gpAutomapCels_007A5168[2] = sub_004788B0(szPath, 0);
        gnAutomapCelFrames_007A5178[2] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[2]);
        if (sub_00408F20_HasExpansionMpq())
        {
            sprintf(szPath, "%s\\UI\\AutoMap\\ExTnMap", szDataGlobal_006D4118);
            gpAutomapCels_007A5168[3] = sub_004788B0(szPath, 0);
            gnAutomapCelFrames_007A5178[3] = CelFileGetCelsPerDirection(gpAutomapCels_007A5168[3]);
        }
        else
        {
            gpAutomapCels_007A5168[3] = 0;
            gnAutomapCelFrames_007A5178[3] = 0;
        }
        break;
    }
}

void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...); // 0x0045B960

static inline int AUTOMAP_GetUnitType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static inline int AUTOMAP_GetUnitClassId(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwClassId : -1;
}

static inline int AUTOMAP_GetUnitAnimMode(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

static inline int AUTOMAP_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

static int sub_00459BC0_GetAutomapUnitColor(unsigned char* pColor, D2UnitStrc* pUnit)
{
    switch (AUTOMAP_GetUnitType(pUnit))
    {
    case 0:
        if (pUnit && pUnit->dwAnimMode == 0x11)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory || INVENTORY_GetOwnerId(pInventory) != pUnit->dwUnitId)
            {
                return 0;
            }

            *pColor = gnAutomapColors_007A51B0[2];
            return 1;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            *pColor = gnAutomapColors_007A51B0[0];
            return 1;
        }

        {
            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                *pColor = gnAutomapColors_007A51B0[3];
                return 1;
            }
        }

        *pColor = gnAutomapColors_007A51B0[1];
        return 1;

    case 1:
    {
        if (pUnit)
        {
            if (pUnit->dwAnimMode == 0xC || AUTOMAP_UnitHasFlag(pUnit, 0x200000))
            {
                return 0;
            }
        }

        if (sub_00457490_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B)
                {
                    return 0;
                }
            }

            *pColor = gnAutomapColors_007A51B0[6];
            return 1;
        }

        int nType = AUTOMAP_GetUnitType(pUnit);
        int nClass = AUTOMAP_GetUnitClassId(pUnit);
        int nMode = AUTOMAP_GetUnitAnimMode(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UI\\automap.cpp", 0x92D);
        if (!nType && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && sub_004639D0_GetOwnerUnit(pUnit))
        {
            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                *pColor = gnAutomapColors_007A51B0[4];
                return 1;
            }

            *pColor = gnAutomapColors_007A51B0[1];
            return 1;
        }

        switch (sub_00478D90_GetPetRelation(pUnit ? pUnit->dwUnitId : -1))
        {
        case 0:
        case 3:
            return 0;

        case 1:
            if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                *pColor = gnAutomapColors_007A51B0[4];
                return 1;
            }
            *pColor = gnAutomapColors_007A51B0[4];
            return 1;

        case 2:
            if (!gdwGlobal_007113E4)
            {
                return 0;
            }
            *pColor = gnAutomapColors_007A51B0[5];
            return 1;
        }

        return 1;
    }

    case 2:
        switch (AUTOMAP_GetUnitClassId(pUnit))
        {
        case 0x3B:
            *pColor = gnAutomapColors_007A51B0[8];
            return 1;

        case 0x3C:
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            if (nLevelId == LEVEL_HELL1 || nLevelId == LEVEL_HELL2 || nLevelId == LEVEL_HELL3 || nLevelId == LEVEL_ID_ACT5_BARRICADE_1
                || nLevelId == LEVEL_ARREATPLATEAU || nLevelId == LEVEL_TUNDRAWASTELANDS)
            {
                return 0;
            }
        }
            *pColor = gnAutomapColors_007A51B0[8];
            return 1;

        case 0x10B:
            *pColor = 0;
            return 1;
        }
        break;
    }

    return 0;
}

// 0x0045A760
static void __stdcall sub_0045A760_DrawAutomapText(unsigned char nColor, const char* szText, int nX, int nY)
{
    if (!strlen(szText))
    {
        return;
    }

    if (nColor >= 0xD)
    {
        nColor = 0;
    }

    const int nOldFont = sub_00502EF0(6);
    Unicode wszText[0x17];
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszText, szText, 0x17);
    sub_00502320(wszText, nX - sub_00501820(wszText) / 2, nY - 10, nColor, 0);
    sub_00502EF0(nOldFont);
}

// 0x0045A7F0
static void __stdcall sub_0045A7F0_DrawAutomapCross(unsigned char nColor, int nX, int nY)
{
    if (gdwGlobal_007A5150 == 1)
    {
        nX -= 1;
        nY += 5;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross_006D6638[i].nX * 2, nY + gaAutomapCross_006D6638[i].nY * 2,
            nX + gaAutomapCross_006D6638[i + 1].nX * 2, nY + gaAutomapCross_006D6638[i + 1].nY * 2, nColor, 0xFF);
    }
}

static void sub_0045A860_DrawAutomapUnit(D2UnitStrc* pUnit)
{
    const int nUnitType = AUTOMAP_GetUnitType(pUnit);
    unsigned char nColor = 0;
    if (nUnitType == 0 && sub_00464820_IsDeadOrDying(pUnit) && !STATES_CheckState(pUnit, STATE_PLAYERBODY))
    {
        return;
    }

    if (!sub_00459BC0_GetAutomapUnitColor(&nColor, pUnit))
    {
        return;
    }

    const int nClientX = UNITS_GetClientCoordX(pUnit);
    const int nClientY = UNITS_GetClientCoordY(pUnit);
    const int nX = nClientX / gnAutomapScale_00711254 - gnAutomapOffsetX_007A5198 + 8;
    const int nY = nClientY / gnAutomapScale_00711254 - gnAutomapOffsetY_007A519C - 8;
    if (nX < gnGlobal_007A51C8 || nX > gnGlobal_007A51D0 || nY < gnGlobal_007A51CC || nY > gnGlobal_007A51D4)
    {
        return;
    }

    switch (nUnitType)
    {
    case 0:
        if (gdwGlobal_007113E4 || nColor != gnAutomapColors_007A51B0[3])
        {
            sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        }

        if (gdwGlobal_007113E8 && gdwGlobal_007113E4 && pUnit != sub_00463DD0_GetPlayerUnit())
        {
            if (nColor == gnAutomapColors_007A51B0[3])
            {
                if (gdwGlobal_007113E4)
                {
                    sub_0045A760_DrawAutomapText(2, UNITS_GetPlayerName(pUnit), nX, nY);
                }
            }
            else
            {
                sub_0045A760_DrawAutomapText(1, UNITS_GetPlayerName(pUnit), nX, nY);
            }
        }
        break;

    case 1:
    {
        sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        if (!gdwGlobal_007113E8)
        {
            break;
        }

        if (sub_00457490_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            const int nOldFont = sub_00502EF0(6);
            const Unicode* wszName = sub_00464A60_GetUnitName(pUnit);
            sub_00502320(wszName, nX - sub_00501820(wszName) / 2, nY - 10, 4, 0);
            sub_00502EF0(nOldFont);
        }

        if (!gdwGlobal_007113E8 || !gdwGlobal_007113E4)
        {
            break;
        }

        int nType = AUTOMAP_GetUnitType(pUnit);
        int nClass = AUTOMAP_GetUnitClassId(pUnit);
        int nMode = AUTOMAP_GetUnitAnimMode(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UI\\automap.cpp", 0xA15);
        if (nType || !STATES_CheckStateMaskOnUnit(pUnit, 0x25))
        {
            break;
        }

        D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
        if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
        {
            break;
        }

        const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
        if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
        {
            break;
        }

        sub_0045A760_DrawAutomapText(1, UNITS_GetPlayerName(pOwner), nX, nY);
        break;
    }

    case 2:
        if (gdwGlobal_007113E8 && pUnit && pUnit->dwClassId == 0x10B)
        {
            const int nOldFont = sub_00502EF0(6);
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xCF3);
            sub_00502320(wszText, nX - sub_00501820(wszText) / 2, nY - 10, nColor, 0);
            sub_00502EF0(nOldFont);
        }
        else
        {
            sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        }
        break;
    }
}

// 0x0045AB60
static void sub_0045AB60_DrawAutomapPartyMember(D2StoredUnitRecordStrc* pEntry)
{
    int nX = 0;
    int nY = 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));
    const unsigned char nEntryAct = DRLG_GetActNoFromLevelId(sub_0047A1E0(pEntry));
    if (DRLG_GetActNoFromLevelId(nLevelId) != nEntryAct)
    {
        return;
    }

    sub_0047A1B0_GetEntryPosition(pEntry, &nX, &nY);
    sub_00643260(&nX, &nY);
    nX = nX / gnAutomapScale_00711254 - gnAutomapOffsetX_007A5198 + 8;
    nY = nY / gnAutomapScale_00711254 - gnAutomapOffsetY_007A519C - 8;
    if (nX < gnGlobal_007A51C8 || nX > gnGlobal_007A51D0 || nY < gnGlobal_007A51CC || nY > gnGlobal_007A51D4)
    {
        return;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross_006D6638[i].nX * 2, nY + gaAutomapCross_006D6638[i].nY * 2,
            nX + gaAutomapCross_006D6638[i + 1].nX * 2, nY + gaAutomapCross_006D6638[i + 1].nY * 2, gnAutomapColors_007A51B0[3], 0xFF);
    }

    if (gdwGlobal_007113E8)
    {
        sub_0045A760_DrawAutomapText(2, sub_004795C0_GetEntryName(pEntry), nX, nY);
    }
}

void __cdecl sub_0045AC90_DrawAutomapUnits()
{
    D2StoredUnitRecordStrc* pFirst = sub_004795A0_GetNextEntry(0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc** ppRooms = 0;
    int nRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pPlayer), &ppRooms, &nRooms);
    const int nCount = nRooms;
    for (int i = 0; i < nCount; ++i)
    {
        for (D2UnitStrc* pUnit = ppRooms[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            sub_0045A860_DrawAutomapUnit(pUnit);
        }
    }

    const unsigned short nIndex = sub_00479BC0_GetEntryIndex(pFirst);
    if (nIndex == 0xFFFF || !gdwGlobal_007113E4)
    {
        return;
    }

    for (D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(pFirst); pEntry; pEntry = sub_004795A0_GetNextEntry(pEntry))
    {
        if (!sub_00463990(sub_0047A0C0_GetRecordUnitId(pEntry), 0) && sub_00479BC0_GetEntryIndex(pEntry) == nIndex)
        {
            sub_0045AB60_DrawAutomapPartyMember(pEntry);
        }
    }
}

#include "gen/data/Source/D2Client/UI/automap_00457F40.inc"
struct D2StoredUnitRecordStrc;
