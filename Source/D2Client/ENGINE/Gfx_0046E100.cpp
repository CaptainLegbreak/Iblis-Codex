#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2CelContext.h"
#include "D2TxtTables.h"
#include "D2ClientGfx.h"
#define GFX_MODE_KEEP 0x11
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2HashedFileEntryStrc;
union D2SeedStrc;
struct D2MsgHandlerEntryStrc;
struct D2GfxLayerStrc;
struct D2GfxNodeTargetStrc;
struct D2GfxListNodeStrc;
struct D2UnitOverlayStrc;
struct D2GfxEntryStrc;
struct D2HashedFileStrc;
struct D2MonGfxCacheStrc;
struct D2OverlayTxt;
struct D2RosterPetStrc;
struct D2RosterUnitStrc;
struct D2Unk004760C0Strc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2GfxBoundsStrc;

struct D2GfxNodeTargetStrc
{
    char unk0x00[0x14];
    union
    {
        int nValue;
        D2GfxLayerStrc* pLayer;
    };
};


struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    int nUnk0x08;
    int unk0x0C[3];
    int nFrame;
    int nFrames;
    int nOffsetX;
    int nOffsetY;
    int unk0x28[3];
    int bFront;
    int unk0x38;
    int nUnk0x3C;
    char unk0x40[0x64];
    D2UnitOverlayStrc* pNext;
};

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[GFX_ENTRY_COUNT];
    D2GfxListNodeStrc* pList;
    D2UnitOverlayStrc* pOverlays;
    int nUnk0x30;
    int nUnk0x34;
    int nUnk0x38;
};




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x0046E040
int __cdecl sub_004FAC90_CheckCharArchive(); // 0x004FAC90
void __cdecl sub_004DA790_InitModeTokens(); // 0x004DA790
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern D2MonGfxCacheStrc* gpPoolBlock_007A80FC; // 0x007A80FC
extern D2HashedFileStrc gtHashedFile_007A8100; // 0x007A8100
extern D2HashedFileStrc gtHashedFile_007A78F0; // 0x007A78F0
extern char gData_007A7490[0x460]; // 0x007A7490
extern int gdwGlobal_007A8910; // 0x007A8910
extern int gdwGlobal_007A891C; // 0x007A891C



struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    char unk0x10[0x20];
    D2RosterPetStrc* pNext;
};

struct D2RosterUnitStrc
{
    char szName[16];
    unsigned int dwUnitId;
    char unk0x14[0x14];
    int nXPos;
    int nYPos;
    char unk0x30[0x50];
    D2RosterUnitStrc* pNext;
};

struct D2Unk004760C0Strc
{
    char unk0x00[0x24];
    int nUnk0x24;
    int nUnk0x28;
};

extern "C" int __cdecl strcmp(const char* szA, const char* szB);
extern "C" T0046E1B0* __stdcall ImmGetContext(int hWnd); // 0x006B00C6
extern "C" int __stdcall ImmReleaseContext(int hWnd, T0046E1B0* hImc); // 0x006B00B4
extern "C" int __stdcall ImmGetConversionStatus(T0046E1B0* hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE
void* __stdcall SMemAlloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400
void __fastcall sub_00473D00_SetPhase(int nPhase); // 0x00473D00
int __fastcall sub_00478830_SendPacket66(const void* pData, int nSize); // 0x00478830
int __fastcall sub_00478E70_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit); // 0x00478E70
int __cdecl sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
extern int gbPhaseActive_007A8A1C; // 0x007A8A1C
extern int gbPhaseBusy_007A8A20; // 0x007A8A20
extern int gnPhaseRange_007A8958[]; // 0x007A8958
extern int gnPhaseOffset_007A8970[]; // 0x007A8970
extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC
extern D2MsgHandlerEntryStrc gtChatHandlers_00712F4C[]; // 0x00712F4C
extern D2MsgHandlerEntryStrc gtChatInputHandlers_00712FA8[]; // 0x00712FA8
extern unsigned char gbChatInputOpen_007BB5E1; // 0x007BB5E1
extern int gnLanguageId_007BB5DC; // 0x007BB5DC
extern unsigned short gwChatText_007BB5F8; // 0x007BB5F8
extern unsigned short gwChatText_007BC850; // 0x007BC850
extern unsigned short gwChatCount_007BB5E4; // 0x007BB5E4
extern int gnSlotFrame_007BC918[]; // 0x007BC918
extern int gnSlotX_007BC898[]; // 0x007BC898
extern int gnSlotY_007BC8B8[]; // 0x007BC8B8
extern void* gpSlotCells_007BC964; // 0x007BC964
extern void* gpWardenBuffer_007BC988; // 0x007BC988
extern unsigned int gnWardenBufferSize_007BC98C; // 0x007BC98C

typedef unsigned long DWORD;



struct D2MonStatsTxt
{
    char unk0x000[0x18];
    short wMonStatsEx;
    char unk0x01A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x000[0xF0];
    unsigned char aModeFlags[0x44];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, unsigned char nArg7, int nArg8); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
extern D2MonGfxCacheStrc gaPlayerGfxCache_007A7490[7]; // 0x007A7490
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern int gbPreloadForce_007A8920; // 0x007A8920
extern int gdwGlobal_007A8928; // 0x007A8928
__declspec(noinline) static void sub_00470040_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit);

D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nWeaponClass, int nIndex); // 0x0046E5A0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

struct D2GfxBoundsStrc
{
    char unk0x00[0x08];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

extern "C" void* __fastcall sub_004DB040_identity(void* pointer); // 0x004DB040

int gdwGlobal_007A8928; // 0x007A8928

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
    D2GfxDataStrc* ptGfxInfo = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(ptGfxInfo, 0xCCF);
    D2UnitOverlayStrc* pOverlay = ptGfxInfo->pOverlays;
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
    gdwGlobal_007A8928 = sub_004FAC90_CheckCharArchive();
    sub_004DA790_InitModeTokens();
}

int gnPhase_007A8A24; // 0x007A8A24

unsigned int gnPhaseTotal_007A8A38; // 0x007A8A38

unsigned int gnPhaseLeft_007A8A3C; // 0x007A8A3C

unsigned int gnPhaseMax_007A89C0; // 0x007A89C0

unsigned char gRowTable_007B5C10[49][0x100]; // 0x007B5C10

int gnChatIndex_007BB5D8; // 0x007BB5D8

// 0x0046E1B0
void __fastcall sub_0046E1B0_DrawUnitOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    if (!pOverlay)
    {
        return;
    }
    for (int nPass = 0; nPass < 2; ++nPass)
    {
        for (; pOverlay; pOverlay = pOverlay->pNext)
        {
            int bDraw = 1;
            if (pOverlay->bFront && !nPass)
            {
                bDraw = 0;
            }
            if (!pOverlay->bFront && nPass)
            {
                bDraw = 0;
            }
            if (pOverlay->nType == 6 && !pOverlay->nUnk0x08)
            {
                bDraw = 0;
            }
            if (pOverlay->nType == 8 && !pOverlay->nUnk0x3C)
            {
                bDraw = 0;
            }
            if (pOverlay->nOverlay == nOverlay && bDraw)
            {
                int nFrame = pOverlay->nFrame >> 8;
                int nId = pOverlay->nOverlay;
                if (nId < 0 || nId >= sgptDataTables->nOverlayTxtRecordCount)
                {
                    return;
                }
                D2OverlayTxt* pOverlayTxt = &sgptDataTables->pOverlayTxt[nId];
                if (!pOverlayTxt)
                {
                    return;
                }
                D2CelContextStrc tContext;
                memset(&tContext, 0, sizeof(tContext));
                tContext.nOverlay = nOverlay;
                int nOut;
                if (!sub_004DBB50_InitCelContext(&tContext, 0, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, 1, -1))
                {
                    return;
                }
                if (nFrame < pOverlay->nFrames >> 8)
                {
                    sub_004F6480(&tContext, pOverlay->nOffsetX + nX, pOverlay->nOffsetY + nY, -0x80, pOverlayTxt->nTrans, 0);
                }
            }
        }
    }
}

// 0x00473E50
void __stdcall sub_00473E50_StepPhase(D2SeedStrc* pSeed)
{
    int nPhase = gnPhase_007A8A24;
    if (gbPhaseActive_007A8A1C && nPhase != 2)
    {
        if (!gbPhaseBusy_007A8A20)
        {
            gnPhase_007A8A24 = 2;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0x137);
            sub_00472400_ResetPhaseState();
        }
        return;
    }
    if (!gnPhaseLeft_007A8A3C)
    {
        ++nPhase;
        if (nPhase == 4)
        {
            nPhase = 0;
        }
        gnPhaseTotal_007A8A38 = sub_00472280(pSeed, gnPhaseOffset_007A8970[nPhase], gnPhaseRange_007A8958[nPhase]);
        gnPhaseLeft_007A8A3C = gnPhaseTotal_007A8A38;
        sub_00473D00_SetPhase(nPhase);
    }
    --gnPhaseLeft_007A8A3C;
    if (nPhase == 1)
    {
        gnPhaseLevel_007A89E0 = (gnPhaseTotal_007A8A38 - gnPhaseLeft_007A8A3C) * gnPhaseMax_007A89C0 / gnPhaseTotal_007A8A38;
    }
    else if (nPhase == 3)
    {
        gnPhaseLevel_007A89E0 = gnPhaseMax_007A89C0 * gnPhaseLeft_007A8A3C / gnPhaseTotal_007A8A38;
    }
    gfPhaseLevel_007A89A0 = gnPhaseLevel_007A89E0 * (1.0 / 256.0);
}

// 0x00475B80
unsigned char* __stdcall sub_00475B80_BuildLerpTable(unsigned int nCount, int nSteps)
{
    unsigned char* pTable = (unsigned char*)sub_00517993_VirtualAlloc(nCount * nCount * nSteps + 3);
    unsigned char* pOut = pTable;
    for (int i = 0; i < nCount; ++i)
    {
        for (int j = 0; j < nCount; ++j)
        {
            int nStep = ((j - i) << 16) / nSteps;
            int nValue = i << 16;
            for (unsigned int k = 0; k < nSteps; ++k)
            {
                *pOut++ = nValue / 65536;
                nValue += nStep;
            }
        }
    }
    return pTable;
}

// 0x00475C40
unsigned char** __stdcall sub_00475C40_BuildLerpRowTable(unsigned int nCount, int nSteps)
{
    unsigned char** pTable = (unsigned char**)sub_00517993_VirtualAlloc((nSteps + 1) * nCount * nCount * sizeof(unsigned char*));
    unsigned char** pOut = pTable;
    unsigned char nIndex;
    for (int i = 0; i < nCount; ++i)
    {
        for (int j = 0; j < nCount; ++j)
        {
            int nStep = ((j - i) << 16) / nSteps;
            int nValue = i << 16;
            for (unsigned int k = 0; k < nSteps; ++k)
            {
                nIndex = nValue / 65536;
                *pOut++ = gRowTable_007B5C10[nIndex];
                nValue += nStep;
            }
            *pOut++ = gRowTable_007B5C10[nIndex];
        }
    }
    return pTable;
}

// 0x00478FA0
void __cdecl sub_00478FA0_UpdatePetFlags()
{
    D2RosterPetStrc* pPet = gpRosterPets_007BB5BC;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    for (; pPet; pPet = pPet->pNext)
    {
        if (pPet->nType == 4)
        {
            D2UnitStrc* pUnit = sub_00463990(pPet->dwUnitId, 1);
            if (pUnit)
            {
                int bSet = !sub_00478E70_IsPetFriendly(pPlayer, pUnit);
                sub_00463E20_SetUnitFlagA(pUnit, bSet);
                sub_00463E80_SetUnitFlagB(pUnit, bSet);
            }
        }
    }
}

// 0x004795F0
D2RosterUnitStrc* __stdcall sub_004795F0_SortRosterByName(D2RosterUnitStrc* pList)
{
    D2RosterUnitStrc* pSorted = 0;
    D2RosterUnitStrc* pCurrent = pList;
    while (pCurrent)
    {
        pList = pCurrent->pNext;
        D2RosterUnitStrc* pPrevious = 0;
        for (D2RosterUnitStrc* pRoster = pSorted; pRoster; pRoster = pRoster->pNext)
        {
            if (strcmp(pCurrent->szName, pRoster->szName) < 0)
            {
                break;
            }
            pPrevious = pRoster;
        }
        if (pPrevious)
        {
            pCurrent->pNext = pPrevious->pNext;
            pPrevious->pNext = pCurrent;
        }
        else
        {
            pCurrent->pNext = pSorted;
            pSorted = pCurrent;
        }
        pCurrent = pList;
    }
    return pSorted;
}

// 0x0047BA80
void __stdcall sub_0047BA80_StepChatIndex(int nDelta)
{
    int nOld = gnChatIndex_007BB5D8;
    gnChatIndex_007BB5D8 += nDelta;
    if (gnChatIndex_007BB5D8 >= 8)
    {
        gnChatIndex_007BB5D8 = 0;
    }
    else if (gnChatIndex_007BB5D8 < 0)
    {
        gnChatIndex_007BB5D8 = 7;
    }
    if (gwChatCount_007BB5E4 < 7 && 8 - gnChatIndex_007BB5D8 > gwChatCount_007BB5E4)
    {
        gnChatIndex_007BB5D8 = nOld;
    }
}

// build: context sub_0047E9A0_DrawSlots
void __stdcall sub_0047E9A0_DrawSlots(int bDraw)
{
    int nSlots = 8;
    if (!bDraw)
    {
        return;
    }
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (gnSlotState_007BC8F8[i] == 1)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpSlotCells_007BC964;
            tContext.nFrame = gnSlotFrame_007BC918[i] + 1;
            sub_004F6480(&tContext, gnSlotX_007BC898[i], gnSlotY_007BC8B8[i], -1, 5, 0);
        }
        else
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpSlotCells_007BC964;
            tContext.nFrame = gnSlotFrame_007BC918[i];
            sub_004F6480(&tContext, gnSlotX_007BC898[i], gnSlotY_007BC8B8[i], -1, 5, 0);
        }
    }
}

// 0x00480000
int __stdcall sub_00480000_SendWardenPacket(const void* pData, int nSize)
{
    return sub_00478830_SendPacket66(pData, nSize);
}

// 0x004800C0
void* __stdcall sub_004800C0_WardenAlloc(int nSize)
{
    return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x274, 0);
}

// 0x004800E0
void __stdcall sub_004800E0_WardenFree(void* pMemory)
{
    SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x27B, 0);
}

// 0x00480100
void __stdcall sub_00480100_SetWardenBuffer(const void* pData, unsigned int nSize)
{
    if (gpWardenBuffer_007BC988)
    {
        SMemFree(gpWardenBuffer_007BC988, ".\\WARDEN\\WardenClient.cpp", 0x283, 0);
    }
    gpWardenBuffer_007BC988 = SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x284, 0);
    gnWardenBufferSize_007BC98C = nSize;
    sub_0041D2A0_MemCopy(gpWardenBuffer_007BC988, pData, nSize);
}

// 0x00480420
void __fastcall sub_00480420_RefreshPathTarget(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x26);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 0x2A);
    if (PATH_GetTargetUnit(pPath))
    {
        int nUnitType;
        int nUnitGUID;
        PATH_GetTargetTypeAndGUID(pPath, &nUnitType, &nUnitGUID);
        D2UnitStrc* pTarget = sub_00463990(nUnitGUID, nUnitType);
        if (pTarget != PATH_GetTargetUnit(pPath))
        {
            PATH_SetTargetUnit(pPath, 0);
        }
    }
}

inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

static __forceinline D2GfxLayerStrc* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->pLayer;
            }
        }
    }
    return 0;
}

static int __stdcall sub_0046FB60_LoadUnitLayers(int bAsync, int nMode, D2UnitStrc* pUnit)
{
    int nResult = 1;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }
    int nWeaponClass;
    const int nToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    if (!sub_0046E5A0_FindGfxListNode(pUnit, nToken, nMode) && !sub_0046FA80_LoadGfxNode(pUnit, nToken, nMode))
    {
        char szBuffer[256];
        const int nClassArg = pUnit ? pUnit->dwClassId : -1;
        const int nTypeArg = pUnit ? pUnit->dwUnitType : 6;
        sprintf(szBuffer, gszAsyncLoadFailed_006D6CC8, bAsync, nTypeArg, nClassArg, nMode, nWeaponClass, nToken);
        return 0;
    }

    D2GfxLayerStrc* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer)
    {
        return 0;
    }

    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    D2_ASSERT(pHeader, 0x6C3);
    struct
    {
        int nA;
        int nIndex;
    } tArg;
    tArg.nIndex = pHeader->nArg;
    tArg.nA = 0;
    int nDirection = UNITS_GetDirection(pUnit);
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x6CD);
    int nB;
    sub_004DB2E0_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &tArg.nA, &nB, tArg.nIndex, 0);
    unsigned char* pOrder = sub_004DB110_GetLayerOrder(pLayer, tArg.nA, 0);
    D2_ASSERT(pOrder, 0x6D6);
    tArg.nIndex = 0;
    while (tArg.nIndex < pHeader->nLayers)
    {
        const int nLayer = pOrder[tArg.nIndex];
        D2_ASSERT(nLayer < 0x10, 0x6DD);
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        int nItemId;
        if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), 0, &nItemId, nLayer, nMode))
        {
            if (!sub_006001F0(&tContext, bAsync, bAsync))
            {
                tContext.nArg34 = 0;
                if (!sub_006004E0_LoadSprite(&tContext))
                {
                    return -1;
                }
                if (!(tContext.nFlags44 & 4))
                {
                    nResult = 0;
                }
            }
        }
        ++tArg.nIndex;
    }
    return nResult;
}

static void __stdcall sub_0046FDA0_PreloadMonsterMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x70A);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount || gpPoolBlock_007A80FC[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gpPoolBlock_007A80FC[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 0;
            gpPoolBlock_007A80FC[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gpPoolBlock_007A80FC[nClass].nModeFlags[nMode] = 1;
    }
}

// 0x0046FEB0
static void __stdcall sub_0046FEB0_PreloadMonsterModes(int bAsync, D2UnitStrc* pUnit)
{
    const int nId = sub_0046DAC0_GetItemClassId(pUnit);
    if (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }
    const int nIndex = sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonStats2TxtRecordCount)
    {
        return;
    }
    D2MonStats2Txt* pMonStats2 = &sgptDataTables->pMonStats2Txt[nIndex];
    if (!pMonStats2)
    {
        return;
    }
    for (unsigned int i = 0; i < gnCofModeCount_00712B00; ++i)
    {
        const unsigned int nMode = gaCofModes_00712AC4[i];
        if (pMonStats2->aModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            sub_0046FDA0_PreloadMonsterMode(bAsync, pUnit, nMode);
        }
    }
}

// build: context sub_0046FF50_PreloadPlayerMode
static void __stdcall sub_0046FF50_PreloadPlayerMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x751);
    if (gaPlayerGfxCache_007A7490[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gaPlayerGfxCache_007A7490[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 0;
            gaPlayerGfxCache_007A7490[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gaPlayerGfxCache_007A7490[nClass].nModeFlags[nMode] = 1;
    }
}

int __stdcall sub_M389_Emit_0046FEB0(int bAsync, D2UnitStrc* pUnit)
{
    sub_0046FEB0_PreloadMonsterModes(bAsync, pUnit);
    return 0x3B;
}

// 0x00470040
static void sub_00470040_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < gnPlayerModeCount_00712AC0; ++i)
    {
        sub_0046FF50_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes_00712AA0[i]);
    }
}

void __stdcall sub_Emit_00470040(int bAsync, D2UnitStrc* pUnit)
{
    sub_00470040_PreloadPlayerModes(bAsync, pUnit);
}

#include "gen/data/Source/D2Client/ENGINE/Gfx_0046E100.inc"
struct D2UnitStrc;

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

    if (!pNode || !pNode->pFileEntry->pData)
    {
        return;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    int nOut;
    if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, PATH_GetDirection(pPath), pUnit->nSeqCurrentFramePrecise >> 8, &nOut, nComponent, -1) && sub_006001F0(&tContext, 0, 1))
    {
        D2_ASSERT(tContext.pCel, 0xD7A);
        *pOffsetX = sub_00601920(tContext.pCel);
        *pOffsetY = sub_00601950(tContext.pCel);
    }
}

// 0x00470860
int __fastcall sub_00470860_HitTestUnitGfx(D2UnitStrc* pUnit, int nOriginX, int nOriginY, int nX, int nY)
{
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
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassCode, -1, 1);
    if (!sub_0046E5A0_FindGfxListNode(pUnit, nWeaponClass, -1))
    {
        sub_0046FA80_LoadGfxNode(pUnit, nWeaponClass, -1);
    }

    int nUnitType = pUnit->dwUnitType;
    int nClassId = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD90);

    const int nGfxMode = nMode;
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return 0;
    }

    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode && pNode->nMode != nGfxMode)
    {
        pNode = pNode->pNext;
    }

    if (!pNode || !pNode->pFileEntry->pData)
    {
        return 0;
    }

    D2GfxBoundsStrc* ptGfxInfo = (D2GfxBoundsStrc*)sub_004DB040_identity(pNode->pFileEntry->pData);
    D2_ASSERT(ptGfxInfo, 0xDA4);

    if (nX < ptGfxInfo->nLeft + nOriginX - 16 || nX >= ptGfxInfo->nRight + nOriginX + 16)
    {
        return 0;
    }

    if (nY < ptGfxInfo->nTop + nOriginY - 16 || nY >= ptGfxInfo->nBottom + nOriginY + 16)
    {
        return 0;
    }

    return 1;
}
