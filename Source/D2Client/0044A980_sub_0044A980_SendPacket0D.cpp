struct D2UnitStrc;

struct D2ClientPacket11Strc
{
    unsigned char nHeader;
    unsigned char nArg1;
    unsigned short nArg2;
};

struct D2ClientPacket19Strc
{
    unsigned char nHeader;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_3;
    unsigned char nValue3;
};

struct D2ClientListNodeStrc;

struct D2ClientListLinkStrc
{
    D2ClientListLinkStrc* pPrevLink;
    D2ClientListNodeStrc* pNext;
};

struct D2ClientListNodeStrc : D2ClientListLinkStrc
{
    int nData;
};

struct D2ClientOffsetListAStrc
{
    int nLinkOffset;
    D2ClientListLinkStrc tTerminator;

    D2ClientListLinkStrc* Link(D2ClientListNodeStrc* pNode) { return pNode ? (D2ClientListLinkStrc*)((char*)pNode + nLinkOffset) : &tTerminator; }
    void sub_004502A0_LinkNode(D2ClientListNodeStrc* pNode, unsigned int nLinkType, D2ClientListNodeStrc* pExisting);
};

struct D2ClientOffsetListBStrc
{
    int nLinkOffset;
    D2ClientListLinkStrc tTerminator;

    D2ClientListLinkStrc* Link(D2ClientListNodeStrc* pNode) { return pNode ? (D2ClientListLinkStrc*)((char*)pNode + nLinkOffset) : &tTerminator; }
    void sub_004508A0_LinkNode(D2ClientListNodeStrc* pNode, unsigned int nLinkType, D2ClientListNodeStrc* pExisting);
};

struct D2ClientNodeListStrc
{
    int nLinkOffset;
    D2ClientListLinkStrc tTerminator;

    D2ClientListLinkStrc* sub_0045BB30_Link(D2ClientListNodeStrc* pNode);
    D2ClientListNodeStrc* sub_0045BB50_Next(D2ClientListNodeStrc* pNode);
    void sub_0045BBE0_LinkNode(D2ClientListNodeStrc* pNode, unsigned int nLinkType, D2ClientListNodeStrc* pExisting);
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x150];
    int nState;
    int nMode;
    int nArg1;
    int nArg2;
};

struct D2ClientUnitViewStrc
{
    int dwUnitType;
    int unk0x04[4];
    D2PlayerDataStrc* pPlayerData;
};

struct D2ClientRecordStrc
{
    int unk0x00[3];
    int nKey;
};

struct D2ClientEntryStrc
{
    int unk0x00[2];
    int nValue;
};

struct D2ClientTimedBoxStrc
{
    int bActive;
    int nValue;
    unsigned char nColor[4];
    int nFadeIn;
    int nFadeOut;
    int nHold;
    int nTotal;
    int nTick;
    int nAngle;
    int nLevelId;
    int bLocked;
};

struct D2ClientViewStrc
{
    unsigned int dwFlags;
    int nValue04;
    int nValue08;
    int nValue0C;
    int nValue10;
    int unk0x14[4];
    int nPosX;
    int nPosY;
};

struct D2ClientArrayStrc
{
    unsigned int nAllocated;
    unsigned int nCount;

    void sub_00450110_SetCount(unsigned int nCount);                                                        // 0x00450110
    void sub_00450680_SetCount(unsigned int nCount);
};

struct T0044A980
{
    int nId;
    int nValue;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall sub_00449BF0_SetGlobal(int nValue);                                                          // 0x00449BF0
int __stdcall sub_006BC8A0_SendBuffer(void* pConnection, const unsigned char* pBuffer, int nSize);           // 0x006BC8A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey);                                             // 0x00478E40
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
void __fastcall sub_004785D0_SendShortShort(char nHeader, short nArg1, short nArg2);                       // 0x004785D0
void* __cdecl sub_00454600();                                                                               // 0x00454600
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __cdecl sub_0044BE90();                                                                                 // 0x0044BE90
void __cdecl sub_00497300();                                                                                // 0x00497300
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
int __cdecl sub_004942D0();                                                                                 // 0x004942D0
void __cdecl sub_00495030();                                                                                // 0x00495030

extern void* gpGlobal_00798FB4;                                                                             // 0x00798FB4
extern void* gpGlobal_007A5240;                                                                             // 0x007A5240
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern D2ClientTimedBoxStrc gtTimedBox_007A742C;                                                            // 0x007A742C
extern void* gpGlobal_007BC964;                                                                             // 0x007BC964
extern void* gpGlobal_007BEEEC;                                                                             // 0x007BEEEC
extern int gnGlobal_007BEEFC;                                                                               // 0x007BEEFC
int gnGlobal_007BEF04;                                                                                      // 0x007BEF04
int gnGlobal_007BEF08;                                                                                      // 0x007BEF08
extern void* gpGlobal_007BEF0C;                                                                             // 0x007BEF0C
extern int gnGlobal_007BEFD8;                                                                               // 0x007BEFD8
extern void* gpGlobal_007C02DC;                                                                             // 0x007C02DC
extern void* gpGlobal_007C02E0;                                                                             // 0x007C02E0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern T0044A980* gpPalShiftEntries_007B9578;                                                     // 0x007B9578
extern int gnGlobal_007B957C;                                                                               // 0x007B957C
char gData_007B9580[7680];                                                                                  // 0x007B9580
int gnGlobal_007BB380;                                                                                      // 0x007BB380
extern void* gpGlobal_007BB384;                                                                             // 0x007BB384
extern void* gpGlobal_007BEEF0;                                                                             // 0x007BEEF0
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470

static inline D2ClientListLinkStrc* ListNextLink(D2ClientListLinkStrc* pLink, int nLinkOffset)
{
    int nOffset = (int)pLink->pNext;
    if (nOffset < 0)
        return (D2ClientListLinkStrc*)~nOffset;
    if (nLinkOffset < 0)
        nLinkOffset = (int)pLink - (int)pLink->pPrevLink->pNext;
    return (D2ClientListLinkStrc*)(nOffset + nLinkOffset);
}

// 0x0044A980
void __cdecl sub_0044A980_SendPacket0D()
{
    unsigned char nHeader;
    sub_00449BF0_SetGlobal(0);
    nHeader = 0x0D;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, &nHeader, 1);
}

// 0x0044A9B0
void __cdecl sub_0044A9B0_SendPacket0F()
{
    unsigned char nHeader;
    sub_00449BF0_SetGlobal(0);
    nHeader = 0x0F;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, &nHeader, 1);
}

// 0x0044A9E0
void __cdecl sub_0044A9E0_SendPacket10()
{
    unsigned char nHeader;
    sub_00449BF0_SetGlobal(0);
    nHeader = 0x10;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, &nHeader, 1);
}

// 0x0044AA10
void __fastcall sub_0044AA10_SendPacket11(unsigned char nArg1, unsigned short nArg2)
{
    D2ClientPacket11Strc tPacket;
    sub_00449BF0_SetGlobal(0);
    tPacket.nHeader = 0x11;
    tPacket.nArg1 = nArg1;
    tPacket.nArg2 = nArg2;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, (unsigned char*)&tPacket, 4);
}

// 0x0044AA50
void __cdecl sub_0044AA50_SendPacket12()
{
    unsigned char nHeader;
    sub_00449BF0_SetGlobal(0);
    nHeader = 0x12;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, &nHeader, 1);
}

// 0x0044AA80
void __cdecl sub_0044AA80_SendPacket13()
{
    unsigned char nHeader;
    sub_00449BF0_SetGlobal(0);
    nHeader = 0x13;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, &nHeader, 1);
}

// 0x0044AAB0
void __cdecl sub_0044AAB0_SendPacket19()
{
    D2ClientPacket19Strc tPacket;
    sub_00449BF0_SetGlobal(0);
    tPacket.nHeader = 0x19;
    *(int*)&tPacket.nValue0 = 8;
    sub_006BC8A0_SendBuffer(gpGlobal_00798FB4, &tPacket.nHeader, 5);
}

// 0x004502A0
void D2ClientOffsetListAStrc::sub_004502A0_LinkNode(D2ClientListNodeStrc* pNode, unsigned int nLinkType, D2ClientListNodeStrc* pExisting)
{
    D2ClientListLinkStrc* pLink = Link(pNode);
    D2ClientListLinkStrc* pExistingLink;
    if (pLink->pPrevLink)
    {
        ListNextLink(pLink, -1)->pPrevLink = pLink->pPrevLink;
        pLink->pPrevLink->pNext = pLink->pNext;
        pLink->pPrevLink = 0;
        pLink->pNext = 0;
    }
    pExistingLink = Link(pExisting);
    switch (nLinkType)
    {
    case 1:
        pLink->pPrevLink = pExistingLink;
        pLink->pNext = pExistingLink->pNext;
        ListNextLink(pExistingLink, nLinkOffset)->pPrevLink = pLink;
        pExistingLink->pNext = pNode;
        break;
    default:
        {
            D2ClientListLinkStrc* pPrev = pExistingLink->pPrevLink;
            pLink->pPrevLink = pPrev;
            pLink->pNext = pPrev->pNext;
            pPrev->pNext = pNode;
            pExistingLink->pPrevLink = pLink;
        }
        break;
    }
}

// 0x00450680
void D2ClientArrayStrc::sub_00450680_SetCount(unsigned int nCount)
{
    sub_00450110_SetCount(nCount);
}

// 0x004508A0
void D2ClientOffsetListBStrc::sub_004508A0_LinkNode(D2ClientListNodeStrc* pNode, unsigned int nLinkType, D2ClientListNodeStrc* pExisting)
{
    D2ClientListLinkStrc* pLink = Link(pNode);
    D2ClientListLinkStrc* pExistingLink;
    if (pLink->pPrevLink)
    {
        ListNextLink(pLink, -1)->pPrevLink = pLink->pPrevLink;
        pLink->pPrevLink->pNext = pLink->pNext;
        pLink->pPrevLink = 0;
        pLink->pNext = 0;
    }
    pExistingLink = Link(pExisting);
    switch (nLinkType)
    {
    case 1:
        pLink->pPrevLink = pExistingLink;
        pLink->pNext = pExistingLink->pNext;
        ListNextLink(pExistingLink, nLinkOffset)->pPrevLink = pLink;
        pExistingLink->pNext = pNode;
        break;
    default:
        {
            D2ClientListLinkStrc* pPrev = pExistingLink->pPrevLink;
            pLink->pPrevLink = pPrev;
            pLink->pNext = pPrev->pNext;
            pPrev->pNext = pNode;
            pExistingLink->pPrevLink = pLink;
        }
        break;
    }
}

// 0x0045BB30
D2ClientListLinkStrc* D2ClientNodeListStrc::sub_0045BB30_Link(D2ClientListNodeStrc* pNode)
{
    return pNode ? pNode : &tTerminator;
}

// 0x0045BB50
D2ClientListNodeStrc* D2ClientNodeListStrc::sub_0045BB50_Next(D2ClientListNodeStrc* pNode)
{
    D2ClientListLinkStrc* pLink = pNode ? pNode : &tTerminator;
    return (int)pLink->pNext <= 0 ? 0 : pLink->pNext;
}

// 0x0045BBE0
void D2ClientNodeListStrc::sub_0045BBE0_LinkNode(D2ClientListNodeStrc* pNode, unsigned int nLinkType, D2ClientListNodeStrc* pExisting)
{
    D2ClientListLinkStrc* pLink = pNode ? pNode : &tTerminator;
    D2ClientListLinkStrc* pExistingLink;
    if (pLink->pPrevLink)
    {
        ListNextLink(pLink, -1)->pPrevLink = pLink->pPrevLink;
        pLink->pPrevLink->pNext = pLink->pNext;
        pLink->pPrevLink = 0;
        pLink->pNext = 0;
    }
    pExistingLink = pExisting ? pExisting : &tTerminator;
    switch (nLinkType)
    {
    case 1:
        pLink->pPrevLink = pExistingLink;
        pLink->pNext = pExistingLink->pNext;
        ListNextLink(pExistingLink, nLinkOffset)->pPrevLink = pLink;
        pExistingLink->pNext = pNode;
        break;
    default:
        {
            D2ClientListLinkStrc* pPrev = pExistingLink->pPrevLink;
            pLink->pPrevLink = pPrev;
            pLink->pNext = pPrev->pNext;
            pPrev->pNext = pNode;
            pExistingLink->pPrevLink = pLink;
        }
        break;
    }
}

// 0x0045FD20
void __stdcall sub_0045FD20_DrawPanelCel(int nFrame)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007A5240;
    tContext.nFrame = nFrame;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x110, 0x13E - gnGlobal_007A285C, -1, 5, 0);
}

// 0x00460060
void __stdcall sub_00460060_DrawPanelCels(int nFrame1, int nFrame2)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007A5240;
    tContext.nFrame = nFrame1;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0xCE, 0x13E - gnGlobal_007A285C, -1, 5, 0);
    tContext.nFrame = nFrame2;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x152, 0x13E - gnGlobal_007A285C, -1, 5, 0);
}

// 0x00460780
void __fastcall sub_00460780_SetPlayerMode(int nMode, D2ClientUnitViewStrc* pUnit, int nArg1, int nArg2)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 1;
        pUnit->pPlayerData->nMode = nMode;
        pUnit->pPlayerData->nArg1 = nArg1;
        pUnit->pPlayerData->nArg2 = nArg2;
    }
}

// 0x00467410
void __fastcall sub_00467410_SetEntryValue(void* pOwner, D2ClientRecordStrc* pRecord, int nValue)
{
    if (pOwner && pRecord)
    {
        sub_00478E40_FindEntry(pRecord->nKey)->nValue = nValue;
    }
}

// 0x0046AE50
void __fastcall sub_0046AE50_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce)
{
    if (gtTimedBox_007A742C.bLocked && !bForce)
    {
        return;
    }
    memset(&gtTimedBox_007A742C, 0, sizeof(gtTimedBox_007A742C));
    gtTimedBox_007A742C.bActive = 1;
    D2_ASSERT(nFadeIn, 0x67);
    gtTimedBox_007A742C.nFadeIn = nFadeIn;
    gtTimedBox_007A742C.nHold = nHold;
    if (!nFadeOut)
    {
        nFadeOut = 0x19;
    }
    gtTimedBox_007A742C.nFadeOut = nFadeOut;
    gtTimedBox_007A742C.nTotal = nFadeIn + nHold + nFadeOut;
    gtTimedBox_007A742C.nLevelId = nLevelId;
}

// 0x00476070
void __fastcall sub_00476070_GetViewValues(D2ClientViewStrc* pView, int* pValue04, int* pValue08, int* pValue0C, int* pValue10)
{
    *pValue04 = pView->nValue04;
    *pValue08 = pView->nValue08;
    *pValue0C = pView->nValue0C;
    *pValue10 = pView->nValue10;
}

// 0x004760A0
void __fastcall sub_004760A0_SetViewPos(D2ClientViewStrc* pView, int nX, int nY)
{
    if (pView->nPosX != nX || pView->nPosY != nY)
    {
        pView->dwFlags |= 1;
        pView->nPosX = nX;
        pView->nPosY = nY;
    }
}

// 0x00476EA0
void __cdecl sub_00476EA0_LoadPalShift()
{
    int nSize = sgptDataTables->nMonStatsTxtRecordCount * sizeof(T0044A980);
    T0044A980* pEntries = (T0044A980*)FOG_Alloc(nSize, ".\\GAME\\PalShift.cpp", 0x63, 0);
    gpPalShiftEntries_007B9578 = pEntries;
    memset(pEntries, 0, nSize);
    int nCount = sgptDataTables->nMonStatsTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pEntries[i].nId = i;
    }
    gnGlobal_007B957C = 0;
    void* hFile;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\RandTransforms.dat", &hFile, 1))
    {
        ARCHIVE_ReadFileToBuffer(0, hFile, gData_007B9580, 0x1E00);
        ARCHIVE_CloseFile(0, hFile);
        gnGlobal_007BB380 = 1;
    }
    void* hFile2;
    if (ARCHIVE_OpenFile(0, "Data\\Global\\Monsters\\GreenBlood.dat", &hFile2, 1))
    {
        void* pBuffer = FOG_Alloc(0x100, ".\\GAME\\PalShift.cpp", 0x52, 0);
        gpGlobal_007BB384 = pBuffer;
        memset(pBuffer, 0, 0x100);
        ARCHIVE_ReadFileToBuffer(0, hFile2, pBuffer, 0x100);
        ARCHIVE_CloseFile(0, hFile2);
    }
}

// 0x0047E860
void __stdcall sub_0047E860_DrawCel(int nFrame, int nX, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BC964;
    tContext.nFrame = nFrame;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x00480B40
void __fastcall sub_00480B40_SendPacket(int nHeader, int nUnused, int nArg1, int nArg2, int nUnused2)
{
    if (nHeader == 0x13)
    {
        return;
    }
    switch (nHeader)
    {
    case 1: case 3:
        sub_004785D0_SendShortShort(nHeader, nArg1, nArg2);
        return;
    case 2: case 4: case 6: case 7: case 9: case 10: case 13: case 14: case 16: case 17:
        sub_004786A0_SendIntInt(nHeader, nArg1, nArg2);
        return;
    default:
        sub_004785D0_SendShortShort(nHeader, nArg1, nArg2);
        return;
    }
}

// 0x004943B0
void __cdecl sub_004943B0_DrawFrameCels()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BEEEC;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 0x100, 0x100, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0, gnGlobal_00711470 - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0x100, gnGlobal_00711470 - 0x30, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 0x140, 0x100, -1, 5, 0);
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 0x240, 0x100, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 0x140, gnGlobal_00711470 - 0x30, -1, 5, 0);
    tContext.nFrame = 7;
    sub_004F6480(&tContext, 0x240, gnGlobal_00711470 - 0x30, -1, 5, 0);
}

// 0x004944F0
void __cdecl sub_004944F0_DrawFrameCels()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BEEEC;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 0, 0x200, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0x42, 0x14, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0x142, 0x14, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 0x217, 0x100, -1, 5, 0);
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 0x30C, 0x100, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 0x30C, 0x200, -1, 5, 0);
}

// 0x00494680
void __cdecl sub_00494680_DrawCelsAndLines()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BEEF0;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x33, 0x19E, -1, 5, 0);
    D2GFX_DrawLine(0x36, 0x16D, 0x36, 0x19B, 0xFF, 0xFF);
    D2GFX_DrawLine(0x37, 0x16D, 0x37, 0x19B, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x7F, 0x1BC, -1, 5, 0);
    D2GFX_DrawLine(0x82, 0x145, 0x82, 0x1B9, 0xFF, 0xFF);
    D2GFX_DrawLine(0x83, 0x145, 0x83, 0x1B9, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0xB2, 0x1D0, -1, 5, 0);
    D2GFX_DrawLine(0xB5, 0x195, 0xB5, 0x1CD, 0xFF, 0xFF);
    D2GFX_DrawLine(0xB6, 0x195, 0xB6, 0x1CD, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0xE3, 0x1D0, -1, 5, 0);
    D2GFX_DrawLine(0xE6, 0x16D, 0xE6, 0x1CD, 0xFF, 0xFF);
    D2GFX_DrawLine(0xE7, 0x16D, 0xE7, 0x1CD, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x11C, 0x1BD, -1, 5, 0);
    D2GFX_DrawLine(0x11F, 0x195, 0x11F, 0x1BA, 0xFF, 0xFF);
    D2GFX_DrawLine(0x120, 0x195, 0x120, 0x1BA, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x15E, 0x19F, -1, 5, 0);
    D2GFX_DrawLine(0x161, 0x145, 0x161, 0x19B, 0xFF, 0xFF);
    D2GFX_DrawLine(0x162, 0x145, 0x162, 0x19B, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x1BD, 0x1C2, -1, 5, 0);
    D2GFX_DrawLine(0x1C0, 0x195, 0x1C0, 0x1BE, 0xFF, 0xFF);
    D2GFX_DrawLine(0x1C1, 0x195, 0x1C1, 0x1BE, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x1F7, 0x1BD, -1, 5, 0);
    D2GFX_DrawLine(0x1FA, 0x145, 0x1FA, 0x1B9, 0xFF, 0xFF);
    D2GFX_DrawLine(0x1FB, 0x145, 0x1FB, 0x1B9, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x246, 0x19F, -1, 5, 0);
    D2GFX_DrawLine(0x249, 0x16D, 0x249, 0x19B, 0xFF, 0xFF);
    D2GFX_DrawLine(0x24A, 0x16D, 0x24A, 0x19B, 0xFF, 0xFF);
}

// 0x00494A00
void __cdecl sub_00494A00_DrawCelsAndLines()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BEEF0;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x37, 0x217, -1, 5, 0);
    D2GFX_DrawLine(0x3A, 0x1E6, 0x3A, 0x214, 0xFF, 0xFF);
    D2GFX_DrawLine(0x3B, 0x1E6, 0x3B, 0x214, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x82, 0x234, -1, 5, 0);
    D2GFX_DrawLine(0x85, 0x1BD, 0x85, 0x231, 0xFF, 0xFF);
    D2GFX_DrawLine(0x86, 0x1BD, 0x86, 0x231, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0xD9, 0x23F, -1, 5, 0);
    D2GFX_DrawLine(0xDC, 0x177, 0xDC, 0x23C, 0xFF, 0xFF);
    D2GFX_DrawLine(0xDD, 0x177, 0xDD, 0x23C, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x104, 0x249, -1, 5, 0);
    D2GFX_DrawLine(0x107, 0x20E, 0x107, 0x246, 0xFF, 0xFF);
    D2GFX_DrawLine(0x108, 0x20E, 0x108, 0x246, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x136, 0x249, -1, 5, 0);
    D2GFX_DrawLine(0x139, 0x1E6, 0x139, 0x246, 0xFF, 0xFF);
    D2GFX_DrawLine(0x13A, 0x1E6, 0x13A, 0x246, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x16D, 0x235, -1, 5, 0);
    D2GFX_DrawLine(0x170, 0x20D, 0x170, 0x232, 0xFF, 0xFF);
    D2GFX_DrawLine(0x171, 0x20D, 0x171, 0x232, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x1BD, 0x21C, -1, 5, 0);
    D2GFX_DrawLine(0x1C0, 0x1C3, 0x1C0, 0x219, 0xFF, 0xFF);
    D2GFX_DrawLine(0x1C1, 0x1C3, 0x1C1, 0x219, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x212, 0x239, -1, 5, 0);
    D2GFX_DrawLine(0x215, 0x20D, 0x215, 0x236, 0xFF, 0xFF);
    D2GFX_DrawLine(0x216, 0x20D, 0x216, 0x236, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x23C, 0x23F, -1, 5, 0);
    D2GFX_DrawLine(0x23F, 0x177, 0x23F, 0x23C, 0xFF, 0xFF);
    D2GFX_DrawLine(0x240, 0x177, 0x240, 0x23C, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x29E, 0x234, -1, 5, 0);
    D2GFX_DrawLine(0x2A1, 0x1BD, 0x2A1, 0x231, 0xFF, 0xFF);
    D2GFX_DrawLine(0x2A2, 0x1BD, 0x2A2, 0x231, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x2E4, 0x217, -1, 5, 0);
    D2GFX_DrawLine(0x2E7, 0x1E6, 0x2E7, 0x214, 0xFF, 0xFF);
    D2GFX_DrawLine(0x2E8, 0x1E6, 0x2E8, 0x214, 0xFF, 0xFF);
}

// 0x00494E40
void __cdecl sub_00494E40_DrawPanelCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gnGlobal_007BEEFC != 0) + 10;
    tContext.unk0x40 = 0;
    if (D2GFX_GetResolutionMode() == 2)
    {
        sub_004F6480(&tContext, 0x2AD, 0x38, -1, 5, 0);
    }
    else
    {
        sub_004F6480(&tContext, 0x20D, 0x38, -1, 5, 0);
    }
}

// 0x00495180
void __cdecl sub_00495180_DrawButtons()
{
    if (sub_004538D0(4) || sub_004538D0(3) || sub_004538D0(1) || sub_004538D0(0xC)
        || sub_004538D0(0x17) || sub_004538D0(0x19))
    {
        gnGlobal_007BEF08 = 1;
        return;
    }
    gnGlobal_007BEF08 = 0;
    if (!sub_004942D0())
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        sub_00495030();
        tContext.pCellFile = gpGlobal_007C02E0;
        tContext.unk0x40 = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x4B, gnGlobal_00711470 - 0xA0, -1, 5, 0);
        tContext.pCellFile = gpGlobal_007C02DC;
        tContext.nFrame = gnGlobal_007BEF04 != 0;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x48, gnGlobal_00711470 - 0xA4, -1, 5, 0);
    }
    else
    {
        sub_00455F20(0x22, 1, 0);
    }
}

static int ButtonHitTest_00497480(int nX, int nY)
{
    int nHeight = gnGlobal_00711470;
    int nWidth = gnGlobal_0071146C;
    return nX >= nWidth / 2 - 0x91 && nX <= nWidth / 2 - 0x80 && nY >= nHeight - 0x1C && nY <= nHeight - 8;
}

// 0x00497480
void __cdecl sub_00497480_DrawButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BEF0C;
    tContext.unk0x40 = 0;
    if (sub_0044BE90())
    {
        if (gnGlobal_007BEFD8 && ButtonHitTest_00497480(nX, nY))
        {
            tContext.nFrame = 3;
        }
        else
        {
            tContext.nFrame = 2;
        }
    }
    else
    {
        if (gnGlobal_007BEFD8 && ButtonHitTest_00497480(nX, nY))
        {
            tContext.nFrame = 1;
        }
        else
        {
            tContext.nFrame = 0;
        }
    }
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x91, gnGlobal_00711470 - 0xA, -1, 5, 0);
    if (nX >= gnGlobal_0071146C / 2 - 0x91 && nX <= gnGlobal_0071146C / 2 - 0x80
        && nY >= gnGlobal_00711470 - 0x1C && nY <= gnGlobal_00711470 - 8)
    {
        sub_00497300();
    }
}
