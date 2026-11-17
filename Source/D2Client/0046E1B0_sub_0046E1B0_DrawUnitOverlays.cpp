typedef unsigned int size_t;

struct D2SeedStrc;
struct D2DynamicPathStrc;
struct D2MsgHandlerEntryStrc;
struct T0046E1B0;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[4];
    int nUnk0x14;
    int unk0x18[7];
    void* pCellFile;
    int unk0x38[4];
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
    char unk0x00[0x2C];
    D2UnitOverlayStrc* pOverlays;
};

struct D2OverlayTxt
{
    char unk0x00[0x7C];
    unsigned char nTrans;
    char unk0x7D[7];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBBC];
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                     // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szA, const char* szB);
extern "C" T0046E1B0* __stdcall ImmGetContext(int hWnd);                                                       // 0x006B00C6
extern "C" int __stdcall ImmReleaseContext(int hWnd, T0046E1B0* hImc);                                         // 0x006B00B4
extern "C" int __stdcall ImmSetOpenStatus(T0046E1B0* hImc, int bOpen);                                         // 0x006B00F0
extern "C" int __stdcall ImmGetConversionStatus(T0046E1B0* hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE
extern "C" int __stdcall ImmSetConversionStatus(T0046E1B0* hImc, unsigned long nConversion, unsigned long nSentence); // 0x006B00EA

void* __stdcall SMemAlloc(int nSize, const char* szFile, int nLine, int nFlags);                            // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags);                           // 0x00412650
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x0041D2A0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
void __fastcall sub_00463E20_SetUnitFlagA(D2UnitStrc* pUnit, int bSet);                                     // 0x00463E20
void __fastcall sub_00463E80_SetUnitFlagB(D2UnitStrc* pUnit, int bSet);                                     // 0x00463E80
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
void __cdecl sub_00472400_ResetPhaseState();                                                                // 0x00472400
void __fastcall sub_00473D00_SetPhase(int nPhase);                                                          // 0x00473D00
int __fastcall sub_00478830_SendPacket66(const void* pData, int nSize);                                     // 0x00478830
int __fastcall sub_00478E70_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit);                          // 0x00478E70
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
int __fastcall sub_004DBB50_InitCelContext(D2CelContextStrc* pContext, D2UnitStrc* pUnit, int a3, int nDirection, int nFrame, int* pOut, int a7, int a8); // 0x004DBB50
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void* __fastcall sub_00517993_VirtualAlloc(unsigned int nSize);                                             // 0x00517993
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit);                                              // 0x00620100
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID);         // 0x00648BB0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gbPhaseActive_007A8A1C;                                                                          // 0x007A8A1C
extern int gbPhaseBusy_007A8A20;                                                                            // 0x007A8A20
int gnPhase_007A8A24;                                                                                       // 0x007A8A24
unsigned int gnPhaseTotal_007A8A38;                                                                         // 0x007A8A38
unsigned int gnPhaseLeft_007A8A3C;                                                                          // 0x007A8A3C
extern int gnPhaseRange_007A8958[];                                                                         // 0x007A8958
extern int gnPhaseOffset_007A8970[];                                                                        // 0x007A8970
unsigned int gnPhaseMax_007A89C0;                                                                           // 0x007A89C0
extern int gnPhaseLevel_007A89E0;                                                                           // 0x007A89E0
extern float gfPhaseLevel_007A89A0;                                                                         // 0x007A89A0
unsigned char gRowTable_007B5C10[49][0x100];                                                                // 0x007B5C10
extern D2RosterPetStrc* gpRosterPets_007BB5BC;                                                              // 0x007BB5BC
extern D2MsgHandlerEntryStrc gtChatHandlers_00712F4C[];                                                     // 0x00712F4C
extern D2MsgHandlerEntryStrc gtChatInputHandlers_00712FA8[];                                                // 0x00712FA8
extern unsigned char gbChatInputOpen_007BB5E1;                                                              // 0x007BB5E1
extern int gnLanguageId_007BB5DC;                                                                           // 0x007BB5DC
extern unsigned short gwChatText_007BB5F8;                                                                  // 0x007BB5F8
extern unsigned short gwChatText_007BC850;                                                                  // 0x007BC850
extern void* gpChatBuffer_007BB5F4;                                                                         // 0x007BB5F4
int gnChatIndex_007BB5D8;                                                                                   // 0x007BB5D8
extern unsigned short gwChatCount_007BB5E4;                                                                 // 0x007BB5E4
extern int gbSmallPanel_007BC978;                                                                           // 0x007BC978
extern int gnSlotState_007BC8F8[];                                                                          // 0x007BC8F8
extern int gnSlotFrame_007BC918[];                                                                          // 0x007BC918
extern int gnSlotX_007BC898[];                                                                              // 0x007BC898
extern int gnSlotY_007BC8B8[];                                                                              // 0x007BC8B8
extern void* gpSlotCells_007BC964;                                                                          // 0x007BC964
extern void* gpWardenBuffer_007BC988;                                                                       // 0x007BC988
extern unsigned int gnWardenBufferSize_007BC98C;                                                            // 0x007BC98C

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
                tContext.nUnk0x14 = nOverlay;
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
            D2_ASSERT(sub_00463DD0(), 0x137);
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
    D2UnitStrc* pPlayer = sub_00463DD0();
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

// 0x0047B2E0
void __cdecl sub_0047B2E0_CloseChatInput()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtChatHandlers_00712F4C, 4);
    if (gbChatInputOpen_007BB5E1)
    {
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtChatInputHandlers_00712FA8, 7);
        T0046E1B0* hImc = ImmGetContext(sub_004F59A0());
        if (hImc)
        {
            ImmSetOpenStatus(hImc, 0);
            if (gnLanguageId_007BB5DC == 7 || gnLanguageId_007BB5DC == 12)
            {
                unsigned long nConversion;
                unsigned long nSentence;
                ImmGetConversionStatus(hImc, &nConversion, &nSentence);
                ImmSetConversionStatus(hImc, 0, nSentence);
            }
            ImmReleaseContext(sub_004F59A0(), hImc);
        }
        gwChatText_007BB5F8 = 0;
        gwChatText_007BC850 = 0;
        if (gpChatBuffer_007BB5F4)
        {
            FOG_Free(gpChatBuffer_007BB5F4, ".\\UI\\chat.cpp", 0x29D, 0);
            gpChatBuffer_007BB5F4 = 0;
        }
    }
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
