#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ClientListNodeStrc;
struct D2StaticPathStrc;
struct D2ClientUnitPointStrc;
struct D2MapAIStrc;
struct D2ClientPacket11Strc;
struct D2ClientPacket19Strc;
struct D2ClientListLinkStrc;
struct D2ClientOffsetListAStrc;
struct D2ClientOffsetListBStrc;
struct D2ClientNodeListStrc;
struct D2PlayerDataStrc;
struct D2ClientUnitViewStrc;
struct D2ClientRecordStrc;
struct D2ClientEntryStrc;
struct D2ClientTimedBoxStrc;
struct D2ClientViewStrc;
struct D2ClientArrayStrc;
struct T0044A980;
struct D2DrlgCoordsStrc;
struct D2MissileStrc;
struct D2RosterPetStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;
struct D2HintCursorStrc;
struct D2PalShiftNodeStrc;
struct D2SeedStrc;

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

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2ClientViewStrc
{
    unsigned int dwFlags;
    union
    {
        struct
        {
            tagRECT tViewRect;
        };
        struct
        {
            int nValue04;
            int nValue08;
            int nValue0C;
            int nValue10;
        };
    };
    tagRECT tClipRect;
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

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __stdcall sub_00449BF0_SetGlobal(int nValue); // 0x00449BF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
D2ClientEntryStrc* __fastcall sub_00478E40_FindEntry(int nKey); // 0x00478E40
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
void __fastcall sub_004785D0_SendShortShort(char nHeader, short nArg1, short nArg2); // 0x004785D0
int __cdecl D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __cdecl sub_0044BE90(); // 0x0044BE90
void __cdecl sub_00497300(); // 0x00497300
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __cdecl sub_004942D0(); // 0x004942D0
void __cdecl sub_00495030(); // 0x00495030
extern void* gpGlobal_00798FB4; // 0x00798FB4
extern void* gpGlobal_007A5240; // 0x007A5240
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2ClientTimedBoxStrc gtTimedBox_007A742C; // 0x007A742C
extern void* gpGlobal_007BC964; // 0x007BC964
extern void* gpGlobal_007BEEEC; // 0x007BEEEC
extern int gnGlobal_007BEEFC; // 0x007BEEFC
extern int gnGlobal_007BEFD8; // 0x007BEFD8
extern void* gpGlobal_007C02DC; // 0x007C02DC
extern void* gpGlobal_007C02E0; // 0x007C02E0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern T0044A980* gpPalShiftEntries_007B9578; // 0x007B9578
extern int gnGlobal_007B957C; // 0x007B957C
extern void* gpGlobal_007BB384; // 0x007BB384
extern void* gpGlobal_007BEEF0; // 0x007BEEF0
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470

enum D2C_W10Constants
{
    UNIT_MONSTER = 1,
    UNIT_TILE = 5,
    STAT_HITPOINTS = 6,
    PET_TYPE_LIFE = 7,
    WEAPON_CLASS_7 = 7,
    DRAW_MODE_5 = 5,
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned char unk_04[0x1C];
    D2SeedStrc tSeed;
    unsigned char unk_28[0x4];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x14];
    int nSeqCurrentFramePrecise;
    char unk0x48[0x0C];
    D2ClientUnitPointStrc* pPoints;
    char unk0x58[0x08];
    D2InventoryStrc* pInventory;
    char unk0x64[0x28];
    unsigned short nLastClickX;
    unsigned short nLastClickY;
    char unk0x90[0x58];
    D2UnitStrc* pRoomNext;
};

struct D2ClientUnitPointStrc
{
    int nX;
    int nY;
    char unk0x08[0x18];
    D2ClientUnitPointStrc* pNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
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
    unsigned int bSpawned;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38[9];
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    int nArg10;
    int unk0x14[2];
    int nLifePercent;
    int unk0x20[4];
    D2RosterPetStrc* pNext;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x24];
    int nState;
};

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

struct D2HintCursorStrc
{
    char unk0x00[0x60];
    int nOwnerId;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern int gdwGlobal_007A520C; // 0x007A520C
extern int gdwGlobal_007A5208; // 0x007A5208
extern D2TimedHintNodeStrc* gpTimedHintList_007C5458; // 0x007C5458
extern "C" int __cdecl sub_0045AFC0(); // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset(); // 0x0045AFD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_00464810(D2UnitStrc* pUnit); // 0x00464810
void __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730
D2HintCursorStrc* __fastcall sub_00481860(int nId); // 0x00481860
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
void __stdcall DUNGEON_ClientSubileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY); // 0x00643400
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

struct D2ViewStrc
{
    unsigned int dwFlags;
    tagRECT tRect;
    unsigned char unk_14[0x10];
    int nPosX;
    int nPosY;
    void* pLerpData;
    void* pLerpTable;
    void* pLerpRows;
};

struct D2PalShiftNodeStrc
{
    int nId;
    char unk0x04[0x1000];
    D2PalShiftNodeStrc* pNext;
};

struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSpriteSize[3];
    int unk0x24[3];
    int nSpriteMisses[3];
    int unk0x3C[3];
    int nSpriteAccesses[3];
    int unk0x54[3];
    int unk0x60[3];
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __cdecl sub_00475EB0(); // 0x00475EB0
void __fastcall sub_004DCF30(D2ViewStrc* pView); // 0x004DCF30
int __cdecl sub_0045AE90(); // 0x0045AE90
void __fastcall sub_004DDB70_PrepareWallCells(D2ViewStrc* pView, int nValue); // 0x004DDB70
extern "C" void __cdecl sub_005FE060_ClearPair88CB10(); // 0x005FE060
extern "C" int gnModeValue_00712CCC; // 0x00712CCC
extern int gnGlobal_007B8D2C; // 0x007B8D2C
extern int gnGlobal_007B9534; // 0x007B9534
extern unsigned char** gppLerpRows_007B953C; // 0x007B953C
extern int gnGlobal_007BB3AC; // 0x007BB3AC
void __fastcall sub_004FAAE0_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0
extern D2CelFileStrc* ghPentagramCellFile; // 0x0087E96C
extern unsigned char gabBeltHotkey_007BEFB0[]; // 0x007BEFB0
extern int gnBeltHover_007BEF94; // 0x007BEF94
extern D2UnitStrc* gpBeltItemA_007BEFA8; // 0x007BEFA8
extern int gnGlobal_007BEECC; // 0x007BEECC
extern unsigned char gnTextColorRed_007BEFBA; // 0x007BEFBA
extern unsigned char gabBeltColors_007BEF6C[4]; // 0x007BEF6C
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern int gdwGlobal_007BCBE4; // 0x007BCBE4
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4
extern int gdwGlobal_007BCBF8; // 0x007BCBF8
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004B9B20(int nHandle); // 0x004B9B20
void __fastcall sub_004B9B50_SetHintValue(int nKey, int nValue); // 0x004B9B50
void __fastcall sub_004BA840(int nHandle); // 0x004BA840
extern int gnGlobal_007B8D10; // 0x007B8D10
extern int gnGlobal_007B8D14; // 0x007B8D14
extern int gnGlobal_007B8D18; // 0x007B8D18
extern int gnGlobal_007B8D1C; // 0x007B8D1C
extern int gnGlobal_007B8D20; // 0x007B8D20
extern int gnGlobal_007B9538; // 0x007B9538

int gnGlobal_007BEF04; // 0x007BEF04

int gnGlobal_007BEF08; // 0x007BEF08

char gData_007B9580[7680]; // 0x007B9580

int gnGlobal_007BB380; // 0x007BB380

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

static D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

// 0x0045B0B0
void __fastcall sub_0045B0B0_DrawRoomUnitBoxes(D2ActiveRoomStrc* pRoom)
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
        {
            const int nX = UNITS_GetClientCoordX(pUnit) - gdwGlobal_007A520C;
            const int nY = UNITS_GetClientCoordY(pUnit) - gdwGlobal_007A5208;
            D2GFX_DrawBox(nX, nY, nX + 4, nY + 4, 0xFF, DRAW_MODE_5);
            if (pUnit && pUnit->dwUnitType == UNIT_TILE)
            {
                for (D2ClientUnitPointStrc* pPoint = pUnit->pPoints; pPoint; pPoint = pPoint->pNext)
                {
                    D2GFX_DrawLine(UNITS_GetClientCoordX(pUnit) - gdwGlobal_007A520C, UNITS_GetClientCoordY(pUnit) - gdwGlobal_007A5208, pPoint->nX - gdwGlobal_007A520C, pPoint->nY - gdwGlobal_007A5208, 0xFF, 0xFF);
                }
            }
        }
    }
}

// 0x00466820
void __fastcall sub_00466820_SpawnRoomPresets(D2ActiveRoomStrc* pRoom)
{
    for (D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom); pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->bSpawned & 1)
        {
            D2DrlgCoordsStrc tCoords;
            DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
            sub_00466730_SpawnPresetUnit(pPresetUnit->nIndex, pPresetUnit->nXpos + tCoords.nSubtileX, pPresetUnit->nYpos + tCoords.nSubtileY, pPresetUnit->nUnitType, pPresetUnit->nMode);
        }
    }
}

// 0x0046B680
void __fastcall sub_0046B680_SpawnMissileTrio(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x11C;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
        MISSILE_SetTargetX(pMissile, 0x32);

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x128;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
    tMissileParams.nMissile = 0x125;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x0046B9A0
void __fastcall sub_0046B9A0_SpawnMissileTrio2(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x12B;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x4B);
        MISSILE_SetTargetY(pMissile, 0x4B);
    }

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkillLevel = 1;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nMissile = 0x166;
    sub_004CD540_CreateMissile(&tMissileParams);

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x132;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x0046BA50
void __fastcall sub_0046BA50_SpawnMissile(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x133;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x0046BC10
void __fastcall sub_0046BC10_HintAndMissile(D2UnitStrc* pUnit)
{
    sub_004DCD40_ShowTimedHint((void*)0x1253, 0, 0xFA, 0, 0, 0, 0);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = 0x17B;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissileParams);
}

// 0x00476000
void __fastcall sub_00476000_SetViewRects(D2ClientViewStrc* pView, int nLeft, int nTop, int nRight, int nBottom)
{
    if (!pView)
        return;

    SetRect(&pView->tViewRect, nLeft, nTop, nRight, nBottom);
    nBottom = sub_004F51D0_IsPerspective();
    SetRect(&pView->tClipRect, -0x50, -0x50, gnGlobal_0071146C + 0x50, gnGlobal_00711470 - 0x2F);
    if (nBottom)
    {
        pView->tClipRect.top -= 30;
        pView->tClipRect.left -= 45;
        pView->tClipRect.right += 30;
    }
    pView->dwFlags |= 1;
}

// 0x004760E0
void __fastcall sub_004760E0_ViewToGameCoords(D2ClientViewStrc* pView, int nX, int nY, int* pX, int* pY)
{
    D2_ASSERT(pView, 0x1CD);
    D2_ASSERT(pX, 0x1CE);
    D2_ASSERT(pY, 0x1CF);
    DUNGEON_ClientSubileDrawPositionToGameCoords(pView->nPosX + nX, pView->nPosY + nY, pX, pY);
}

// 0x00479010
void __fastcall sub_00479010_UpdatePetLife(int nUnitId, int nLifePercent, unsigned short nArg)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwUnitId == nUnitId)
        {
            pPet->nLifePercent = nLifePercent;
            pPet->nArg10 = nArg;
            if (pPet->nType == PET_TYPE_LIFE)
            {
                D2UnitStrc* pUnit = sub_00463990(nUnitId, UNIT_MONSTER);
                if (pUnit)
                    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pUnit) * nLifePercent / 100, 0);
            }
            return;
        }
    }
}

// 0x004B9640
int __fastcall sub_004B9640_CountHintsForOwner(int nOwnerId)
{
    int nCount = 0;
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        if (sub_00481860(pEntry->nHintId)->nOwnerId == nOwnerId && pEntry->nState == 1)
            nCount += 1;
    }
    return nCount;
}

// 0x004C76A0
int __fastcall sub_004C76A0_GetWeaponClassMask(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == WEAPON_CLASS_7 ? 0x1F : 0;
}

// 0x004D1640
D2UnitStrc* __fastcall sub_004D1640_SpawnDirectionalMissile(D2UnitStrc* pUnit, int nFrame)
{
    D2UnitStrc* pMissile = 0;
    if (pUnit->pDynamicPath)
    {
        unsigned char nDirection = PATH_GetDirection(pUnit->pDynamicPath);
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.pOwner = pUnit;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nMissile = 0x54;
        tMissileParams.nSkillLevel = 1;
        pMissile = sub_004CD540_CreateMissile(&tMissileParams);
        if (pMissile)
        {
            pMissile->nSeqCurrentFramePrecise = nFrame << 8;
            if (pMissile->pDynamicPath)
                D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, nDirection);
            sub_00464810(pMissile);
        }
    }
    return pMissile;
}

// 0x004DC580
void __fastcall sub_004DC580_DrawUnitClickCross(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x61);
    int nX = pUnit->nLastClickX;
    int nY = pUnit->nLastClickY;
    sub_00643260(&nX, &nY);
    D2GFX_DrawLine(nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset(), nX - sub_0045AFC0() + 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset(), nX - sub_0045AFC0() - 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - sub_0045AFC0() - 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset() + 0x10, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - sub_0045AFC0() + 0x10, nY - sub_0045AFD0_GetMouseYOffset() + 8, nX - sub_0045AFC0(), nY - sub_0045AFD0_GetMouseYOffset() + 0x10, 0xFF, 0xFF);
    const int nBoxX = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0();
    const int nBoxY = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset();
    D2GFX_DrawBox(nBoxX, nBoxY, nBoxX + 4, nBoxY + 4, 0xFF, DRAW_MODE_5);
}

int gnGlobal_007B8D20; // 0x007B8D20

int gnGlobal_007B9538; // 0x007B9538

void* gpLerpTable_007B9540; // 0x007B9540

void* gpLerpTable_007B9544; // 0x007B9544

void* gpLerpTable_007B954C; // 0x007B954C

void* gpLerpTable_007B9550; // 0x007B9550

D2PalShiftNodeStrc* gpPalShiftList_007B957C; // 0x007B957C

void* gpGlobal_007BB384; // 0x007BB384

int gbCacheStats_007BB3A4; // 0x007BB3A4

// 0x00475EF0
void __cdecl sub_00475EF0_FreeLerpTables()
{
    if (!gppLerpRows_007B953C)
        return;

    D2_ASSERT(gpLerpTable_007B9540, 0xFB);
    D2_ASSERT(gpLerpTable_007B9544, 0xFC);
    D2_ASSERT(gpLerpTable_007B954C, 0xFD);
    D2_ASSERT(gpLerpTable_007B9550, 0xFE);
    sub_005179A4_VirtualFree(gppLerpRows_007B953C);
    if (gpLerpTable_007B9540)
        sub_005179A4_VirtualFree(gpLerpTable_007B9540);
    if (gpLerpTable_007B9544)
        sub_005179A4_VirtualFree(gpLerpTable_007B9544);
    if (gpLerpTable_007B954C)
        sub_005179A4_VirtualFree(gpLerpTable_007B954C);
    if (gpLerpTable_007B9550)
        sub_005179A4_VirtualFree(gpLerpTable_007B9550);
    gppLerpRows_007B953C = 0;
    gpLerpTable_007B9540 = 0;
    gpLerpTable_007B9544 = 0;
    gpLerpTable_007B954C = 0;
    gpLerpTable_007B9550 = 0;
    gnGlobal_007B8D2C = 0;
    sub_00475EB0();
}

// 0x00475FD0
void __fastcall sub_00475FD0(D2ViewStrc* pView)
{
    sub_004DCF30(pView);
    FOG_Free(pView, ".\\GAME\\View.cpp", 0x141, 0);
}

// 0x00475FF0
void __fastcall sub_00475FF0_SetViewDirty(D2ViewStrc* pView)
{
    pView->dwFlags |= 1;
}

// 0x00476140
void __fastcall sub_00476140(D2ViewStrc* pView, int nArg)
{
    D2_ASSERT(pView, 0x1DD);
    if (pView->tRect.right || pView->tRect.bottom)
    {
        if (sub_0045AE90() != 3)
            sub_004DDB70_PrepareWallCells(pView, nArg);
        pView->dwFlags &= ~1;
    }
}

// 0x00476AC0
int __fastcall sub_00476AC0_GetViewShift(int* pX, int* pY)
{
    if (!gnGlobal_007B9534)
        return 0;

    *pX = gnGlobal_007B9538;
    *pY = gnGlobal_007B8D20;
    return 1;
}

// 0x00476FB0
void __cdecl sub_00476FB0()
{
    while (gpPalShiftList_007B957C)
    {
        D2PalShiftNodeStrc* pNext = gpPalShiftList_007B957C->pNext;
        FOG_Free(gpPalShiftList_007B957C, ".\\GAME\\PalShift.cpp", 0x84, 0);
        gpPalShiftList_007B957C = pNext;
    }
    if (gpPalShiftEntries_007B9578)
    {
        FOG_Free(gpPalShiftEntries_007B9578, ".\\GAME\\PalShift.cpp", 0x8A, 0);
        gpPalShiftEntries_007B9578 = 0;
    }
    if (gpGlobal_007BB384)
    {
        FOG_Free(gpGlobal_007BB384, ".\\GAME\\PalShift.cpp", 0x90, 0);
        gpGlobal_007BB384 = 0;
    }
}

// 0x00477030
D2PalShiftNodeStrc* __fastcall sub_00477030_FindPalShiftNode(int nId)
{
    for (D2PalShiftNodeStrc* pNode = gpPalShiftList_007B957C; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
            return pNode;
    }
    return 0;
}

// 0x00477750
int __cdecl sub_00477750_IsModeAtLeast4()
{
    return gnModeValue_00712CCC >= 4;
}

// 0x00477C00
void __cdecl sub_00477C00_ToggleCacheStats()
{
    gnGlobal_007BB3AC = 0;
    gbCacheStats_007BB3A4 = !gbCacheStats_007BB3A4;
    if (!gbCacheStats_007BB3A4)
        return;

    D2CacheStatsStrc* pStats = sub_004F5290_GetCacheStats();
    if (pStats)
    {
        pStats->unk0x04 = 0;
        pStats->nFloorMisses = 0;
        pStats->unk0x10 = 0;
        pStats->nSubtileMisses = 0;
        memset(pStats->unk0x24, 0, sizeof(pStats->unk0x24));
        memset(pStats->nSpriteMisses, 0, sizeof(pStats->nSpriteMisses));
        memset(pStats->nSpriteAccesses, 0, sizeof(pStats->nSpriteAccesses));
        memset(pStats->unk0x60, 0, sizeof(pStats->unk0x60));
    }
    sub_005FE060_ClearPair88CB10();
}

int gdwGlobal_007BEFAC; // 0x007BEFAC

unsigned char gnLifeColorHigh_007BEED0; // 0x007BEED0

unsigned char gnLifeColorMid_007BEED1; // 0x007BEED1

unsigned char gnLifeColorLow_007BEED2; // 0x007BEED2

unsigned char gbLifeColorsInit_007BEED3; // 0x007BEED3

// 0x004760C0
void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY)
{
    *pX = pView->nPosX;
    *pY = pView->nPosY;
}

// 0x00507140
void __stdcall LIST_UnloadPentspinCellfile()
{
    sub_004FAAE0_FreeCellFile(ghPentagramCellFile);
    ghPentagramCellFile = 0;
}

// 0x00498D50
void __fastcall sub_00498D50(int nX, int nArg)
{
    if ((unsigned int)nX < 4)
        gabBeltHotkey_007BEFB0[nX] = (unsigned char)nArg;
}

// 0x00498D60
void __cdecl sub_00498D60()
{
    gnBeltBox_0072235C = -1;
    gnBeltRectX_00722360 = -1;
    gnBeltRectY_00722364 = -1;
    gnBeltHover_007BEF94 = 0;
    gpBeltItemA_007BEFA8 = 0;
    gdwGlobal_007BEFAC = 0;
}

// 0x00492C10
int __cdecl sub_00492C10()
{
    return gnGlobal_007BEECC != 2;
}

// 0x00492F40
void __fastcall sub_00492F40_SetFade(int nMode)
{
    if (!nMode)
    {
        if (gbLifeColorsInit_007BEED3)
            return;
        gbLifeColorsInit_007BEED3 = 1;
    }

    gnLifeColorHigh_007BEED0 = D2Win_10034_MixRGB(0, 0x80, 0);
    gnLifeColorMid_007BEED1 = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
    gnLifeColorLow_007BEED2 = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00492F90
void __cdecl sub_00492F90()
{
    gbLifeColorsInit_007BEED3 = 0;
}

// 0x00497250
void __cdecl sub_00497250_InitTextColorRed()
{
    gnTextColorRed_007BEFBA = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x004972B0
void __cdecl sub_004972B0_InitBeltColors()
{
    gabBeltColors_007BEF6C[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors_007BEF6C[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors_007BEF6C[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors_007BEF6C[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

// 0x004879D0
void __fastcall sub_004879D0(D2UnitStrc* pUnit)
{
    if (gdwGlobal_007BCBF4 == pUnit)
    {
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
    }
}

// 0x00487CA0
int __cdecl sub_00487CA0_SetNpcState6()
{
    if (gdwGlobal_007BCBF0 == 6)
        return 0;
    gdwGlobal_007BCBF0 = 6;
    return 1;
}

int gnGlobal_007B8D2C; // 0x007B8D2C

// 0x004769D0
static void sub_004769D0_UpdateShakeSound(int nIntensity)
{
    int nVolume = nIntensity * 0xFF / 20;
    nVolume = nVolume > 0 ? nVolume : 0;
    if (nVolume >= 0xFF)
    {
        nVolume = 0xFF;
    }

    if (nVolume && !gnGlobal_007B8D2C)
    {
        gnGlobal_007B8D2C = sub_004B9A00(0x1C4, 0, 0, 0, 0);
        if (!gnGlobal_007B8D2C)
        {
            return;
        }
        sub_004B9B50_SetHintValue(gnGlobal_007B8D2C, 0);
    }

    if (!gnGlobal_007B8D2C)
    {
        return;
    }

    const int nCurrent = sub_004B9B20(gnGlobal_007B8D2C);
    if (nVolume == nCurrent)
    {
        return;
    }

    int nNew;
    if (nVolume > nCurrent)
    {
        nNew = nCurrent + 6;
        if (nVolume < nNew)
        {
            nNew = nVolume;
        }
    }
    else
    {
        nNew = nCurrent - 6;
        if (nVolume > nNew)
        {
            nNew = nVolume;
        }
    }

    if (nNew)
    {
        sub_004B9B50_SetHintValue(gnGlobal_007B8D2C, nNew);
        return;
    }

    sub_004BA840(gnGlobal_007B8D2C);
    gnGlobal_007B8D2C = 0;
}

void __fastcall sub_00476D40_AdjustViewPos(int* pX, int* pY)
{
    const unsigned int nElapsed = GetTickCount() - gnGlobal_007B8D10;
    const unsigned int nFadeIn = gnGlobal_007B8D14;
    const unsigned int nHold = gnGlobal_007B8D18;
    const unsigned int nFadeOut = gnGlobal_007B8D1C;
    if (nElapsed > nFadeOut + nHold + nFadeIn)
    {
        sub_004769D0_UpdateShakeSound(0);
        gnGlobal_007B9534 = 0;
        gnGlobal_007B9538 = 0;
        gnGlobal_007B8D20 = 0;
        return;
    }

    int nMagnitude = 0;
    if (nElapsed < nFadeIn)
    {
        if (!nFadeIn)
        {
            return;
        }
        nMagnitude = gnGlobal_007B9534 * nElapsed / nFadeIn;
    }
    else if (nElapsed < nHold + nFadeIn)
    {
        nMagnitude = gnGlobal_007B9534;
    }
    else
    {
        if (!nFadeOut)
        {
            return;
        }
        nMagnitude = (nFadeOut - nElapsed + nHold + nFadeIn) * gnGlobal_007B9534 / nFadeOut;
    }

    if (nMagnitude)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        gnGlobal_007B9538 = sub_00472280(&pPlayer->tSeed, -nMagnitude, 2 * nMagnitude);
        const int nOffsetY = sub_00472280(&pPlayer->tSeed, -nMagnitude, 2 * nMagnitude);
        *pX += gnGlobal_007B9538;
        *pY += nOffsetY;
        gnGlobal_007B8D20 = nOffsetY;
    }
    sub_004769D0_UpdateShakeSound(nMagnitude);
}
