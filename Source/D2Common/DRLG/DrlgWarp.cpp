#include "D2Common.h"
#include "D2Structs.h"
#include "D2Txt.h"

struct D2DrlgStrc;
struct D2DrlgListEntryStrc;
struct D2DrlgListOwnerStrc;
struct D2DrlgWarpStrc;
struct D2LevelDefBin;
struct D2RoomTileStrc;
struct D2SeedStrc;
struct D2PresetUnitStrc;
struct D2ObjectsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    union
    {
        D2DrlgRoomStrc* pDrlgRoomNext;
        D2DrlgRoomStrc* pNext;
    };
    unsigned int dwFlags;
    char unk0x2C[0x04];
    D2ActiveRoomStrc* pRoom;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    unsigned char unk_44[0x8];
    D2RoomTileStrc* pRoomTiles;
    unsigned char unk_50[0xC];
    D2PresetUnitStrc* pPresetUnits;
};


struct D2DrlgLevelStrc
{
    char unk0x00[0x08];
    int nRooms;
    char unk0x0C[0x04];
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x14[0x08];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
    char unk0x2C[0x188];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
    D2DrlgRoomStrc* sub_0066AC40_GetTileRoom(int nTileIndex, int* pX, int* pY);    // 0x0066AC40
};

struct D2DrlgListEntryStrc
{
    char unk0x00[0x24];
    D2DrlgListEntryStrc* pNext;
    int dwFlags;
};

struct D2DrlgListOwnerStrc
{
    char unk0x00[0x10];
    D2DrlgListEntryStrc* pFirst;
};

unsigned int __fastcall sub_006C9A38(const char* szString); // 0x006C9A38
void __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730

struct D2DrlgStrc
{
    char unk0x00[0x90];
    D2DrlgWarpStrc* pWarp;
};

int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066AEC0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

struct D2LvlWarpTxt
{
    int dwLevelId;
};

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[8];
    int nWarp[8];
    D2DrlgWarpStrc* pNext;
};

struct D2LevelDefBin
{
    char unk0x00[0x68];
    int dwWarp[8];
    char unk0x88[0x08];
    int dwPosition;
};

struct D2RoomTileStrc
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2RoomTileStrc* pNext;
    int bEnabled;
    void* unk0x0C;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
};


D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470

struct D2PresetUnitStrc
{
    int unk0x00;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    int unk0x10;
    int nUnitType;
    int nYpos;
};


unsigned int __fastcall DRLGROOM_CheckWaypointFlags(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BAA0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00642630
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BFA0
void __fastcall sub_00678AD0_CreateLevelConnections(D2DrlgStrc* pDrlg); // 0x00678AD0

// 0x0066A290
void __cdecl sub_0066A290_AssertFail()
{
    D2_ASSERT(0, 0x65);
}

// 0x0066A870
static __forceinline int sub_0066A870_SumStringBytes(const char* szText)
{
    int nSum = 0;
    while (*szText)
    {
        nSum += (unsigned char)*szText;
        ++szText;
    }

    return nSum & 0xFF;
}

// 0x0066A890
static __forceinline int sub_0066A890_CompareCodes(const char* szA, const char* szB)
{
    D2_ASSERT(sub_006C9A38(szA) <= 8, 0xD9);
    D2_ASSERT(sub_006C9A38(szB) <= 8, 0xDA);
    if (*(const int*)szA != *(const int*)szB)
    {
        return 0;
    }

    return *(const int*)(szA + 4) == *(const int*)(szB + 4);
}

// 0x0066AC30
static __forceinline D2ActiveRoomStrc* sub_0066AC30_GetActiveRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
    return pDrlgRoom->pRoom;
}

// 0x0066AF10
int* __fastcall sub_0066AF10_GetWarpIdArray(D2DrlgLevelStrc* pLevel)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId);
}

// 0x0066AFB0
static __forceinline int sub_0066AFB0_FindVisIndex(D2DrlgStrc* pDrlg, int nLevelId, int nVisLevel, int nIndex)
{
    int* pVis = DRLGROOM_GetVisArrayFromLevelId(pDrlg, nLevelId);
    int nCount = 0;
    for (unsigned char i = 0; i < 8; ++i)
    {
        if (pVis[i] == nVisLevel)
        {
            if (nCount == nIndex)
            {
                return i;
            }

            ++nCount;
        }
    }

    return -1;
}

// 0x0066AFF0
static __forceinline D2DrlgListEntryStrc* sub_0066AFF0_FindFlaggedEntry(D2DrlgStrc* pDrlg, int nBit)
{
    const int nMask = 1 << (nBit + 4);
    for (D2DrlgListEntryStrc* pEntry = ((D2DrlgListOwnerStrc*)pDrlg)->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwFlags & nMask)
        {
            return pEntry;
        }
    }

    return 0;
}

int __fastcall sub_M117_Emit_0066A870(const char* szText, D2DrlgRoomStrc* pDrlgRoom, D2DrlgStrc* pDrlg, int nLevelId)
{
    int n = sub_0066A870_SumStringBytes(szText);
    n += sub_0066A890_CompareCodes(szText, (const char*)pDrlgRoom);
    n += (int)sub_0066AC30_GetActiveRoom(pDrlgRoom);
    n += sub_0066AFB0_FindVisIndex(pDrlg, nLevelId, n, nLevelId);
    n += (int)sub_0066AFF0_FindFlaggedEntry(pDrlg, n);
    return n;
}

// 0x0066AB00
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord)
{
    for (D2RoomTileStrc* pSourceRoomTile = pDrlgRoom->pRoomTiles; pSourceRoomTile; pSourceRoomTile = pSourceRoomTile->pNext)
    {
        if (pSourceRoomTile->pLvlWarpTxtRecord->dwLevelId == nSourceLevel)
        {
            D2DrlgRoomStrc* pDestinationRoom = pSourceRoomTile->pDrlgRoom;
            for (D2RoomTileStrc* pDestinationRoomTile = pDestinationRoom->pRoomTiles; pDestinationRoomTile; pDestinationRoomTile = pDestinationRoomTile->pNext)
            {
                if (pDestinationRoomTile->pDrlgRoom == pDrlgRoom)
                {
                    *pDestinationLevel = pDestinationRoomTile->pLvlWarpTxtRecord->dwLevelId;
                    *ppLvlWarpTxtRecord = pDestinationRoomTile->pLvlWarpTxtRecord;

                    if (!pDestinationRoom->pRoom)
                    {
                        DRLGACTIVATE_InitializeRoomEx(pDestinationRoom);
                    }

                    return pDestinationRoom->pRoom;
                }
            }

            return 0;
        }
    }

    return 0;
}

// 0x0066AEC0
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* ptVisInfo = pDrlg->pWarp; ptVisInfo; ptVisInfo = ptVisInfo->pNext)
    {
        if (!ptVisInfo->nLevel)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 418);
            exit(-1);
        }

        if (nLevelId == ptVisInfo->nLevel)
        {
            return ptVisInfo->nWarp;
        }
    }

    return DATATBLS_GetLevelDefRecord(nLevelId)->dwWarp;
}

inline int DRLGWARP_GetWarpDestinationFromArrayInline(D2DrlgLevelStrc* pLevel, unsigned char nWarpId)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId)[nWarpId];
}

// 0x0066AF50
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char szDirection)
{
    return DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(DRLGWARP_GetWarpDestinationFromArrayInline(pLevel, nWarpId), szDirection);
}

// 0x0066AF80
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromUnit(D2DrlgRoomStrc* pDrlgRoom, D2UnitStrc* pUnit)
{
    D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles;
    int nClassId;

    if (!pUnit)
    {
        nClassId = -1;
    }
    else
    {
        nClassId = pUnit->dwClassId;
    }

    while (pRoomTile)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == (unsigned char)nClassId)
        {
            if (pRoomTile->bEnabled)
            {
                return pRoomTile->pLvlWarpTxtRecord;
            }

            return 0;
        }

        pRoomTile = pRoomTile->pNext;
    }

    return 0;
}

static __forceinline int* sub_0066AEC0(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        D2_ASSERT(pDrlgWarp->nLevel, 418);
        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nWarp;
        }
    }
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwWarp;
}

// 0x0066AD80
static D2DrlgRoomStrc* __stdcall DRLGWARP_GetWaypointRoomExFromLevel(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGROOM_CheckWaypointFlags(pDrlgRoom))
        {
            DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
            for (D2PresetUnitStrc* pPresetUnit = pDrlgRoom->pPresetUnits; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
            {
                if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 573 && (DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40))
                {
                    *pX = pDrlgRoom->nTileXPos + pPresetUnit->nXpos / 5;
                    *pY = pDrlgRoom->nTileYPos + pPresetUnit->nYpos / 5;
                    return pDrlgRoom;
                }
            }
            return pDrlgRoom;
        }
    }
    return 0;
}

static D2DrlgRoomStrc* sub_0066AE70_GetRandomRoom(D2DrlgLevelStrc* pLevel)
{
    D2_ASSERT(pLevel, 318);
    D2_ASSERT(pLevel->pFirstRoomEx, 319);
    int nRand = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx;
    for (int i = nRand; i; --i)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }
    return pDrlgRoom;
}

// 0x0066B1F0
static D2DrlgRoomStrc* sub_0066B1F0_GetFirstWarpRoom(D2DrlgLevelStrc* pLevel)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->pFirstRoomEx; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (pDrlgRoom->dwFlags & 0xFF0)
        {
            int nFlags = 0x10;
            unsigned char nCounter = 0;
            do
            {
                if ((nFlags & pDrlgRoom->dwFlags) && sub_0066AEC0(pLevel->pDrlg, pLevel->nLevelId)[nCounter] != -1)
                {
                    return pDrlgRoom;
                }
                nFlags *= 2;
                ++nCounter;
            }
            while (nFlags & 0xFF0);
        }
    }
    return 0;
}

D2ActiveRoomStrc* __fastcall sub_0066B2B0_GetLevelEntryRoom(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY)
{
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgLevelStrc* pLevel = 0;
    D2DrlgRoomStrc* pDrlgRoom = 0;

    pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(nLevelId);
    *pX = -1;
    *pY = -1;

    pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (!pLevel->pFirstRoomEx)
    {
        DRLG_InitLevel(pLevel);
    }

    if (pLevelDefBinRecord->dwPosition)
    {
        if (nTileIndex == 13)
        {
            pDrlgRoom = DRLGWARP_GetWaypointRoomExFromLevel(pLevel, pX, pY);
            DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
            return pDrlgRoom->pRoom;
        }

        pDrlgRoom = pLevel->sub_0066AC40_GetTileRoom(nTileIndex, pX, pY);
        DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
        return pDrlgRoom->pRoom;
    }

    pDrlgRoom = DRLGWARP_GetWaypointRoomExFromLevel(pLevel, pX, pY);
    if (!pDrlgRoom)
    {
        pDrlgRoom = sub_0066B1F0_GetFirstWarpRoom(pLevel);
        if (!pDrlgRoom)
        {
            pDrlgRoom = DRLG_GetRoomExFromLevelAndCoordinates(pLevel, pLevel->nWidth / 2 + pLevel->nPosX - 2, pLevel->nHeight / 2 + pLevel->nPosY - 2);
            if (!pDrlgRoom)
            {
                pDrlgRoom = sub_0066AE70_GetRandomRoom(pLevel);
            }
        }
    }

    if (pDrlgRoom)
    {
        if (*pX == -1 || *pY == -1)
        {
            *pX = pDrlgRoom->nTileXPos + pDrlgRoom->nTileWidth / 2;
            *pY = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight / 2;
        }

        DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
        return pDrlgRoom->pRoom;
    }

    return 0;
}

// 0x0066AF30
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->nLevelId)[nWarpId];
}

// 0x0066B010
D2PresetUnitStrc* __fastcall sub_0066B010_FindPresetTile(D2DrlgRoomStrc* pDrlgRoom)
{
    D2PresetUnitStrc* pPreset = DRLGROOM_GetPresetUnits(pDrlgRoom);
    for (; pPreset; pPreset = pPreset->pNext)
    {
        if (pPreset->nUnitType == 5)
        {
            break;
        }
    }

    return pPreset;
}

// 0x0066B7F0
void __cdecl sub_0066B7F0_Nop()
{
}

static __forceinline int FindVis(D2DrlgStrc* pDrlg,int nLevel,int nOther,int nIndex)
{
 int* pVis=DRLGROOM_GetVisArrayFromLevelId(pDrlg,nLevel);
 int nCount=0;
 for(unsigned char i=0;i<8;++i) if(pVis[i]==nOther) { if(nCount==nIndex)return i; ++nCount; }
 return -1;
}

static __forceinline D2DrlgRoomStrc* FindRoom(D2DrlgLevelStrc* pLevel,int nIndex)
{
 int nMask=1<<(nIndex+4);
 for(D2DrlgRoomStrc* pRoom=pLevel->pFirstRoomEx;pRoom;pRoom=pRoom->pNext) if(pRoom->dwFlags&nMask)return pRoom;
 return 0;
}

// 0x0066B030
void __fastcall sub_0066B030_InitializeConnectedLevels(D2DrlgStrc* pDrlg,int unused,int nLevel1,int nLevel2)
{
 sub_00678AD0_CreateLevelConnections(pDrlg);
 D2DrlgLevelStrc* pLevel1=DRLG_GetLevel(pDrlg,nLevel1);
 if(!pLevel1->pFirstRoomEx)DRLG_InitLevel(pLevel1);
 D2DrlgLevelStrc* pLevel2=DRLG_GetLevel(pDrlg,nLevel2);
 if(!pLevel2->pFirstRoomEx)DRLG_InitLevel(pLevel2);
 for(int n=0;n<8;++n) {
  int i=FindVis(pDrlg,nLevel1,nLevel2,n);
  int j=FindVis(pDrlg,nLevel2,nLevel1,n);
  if(i==-1 || j==-1)return;
  DRLGWARP_GetWarpIdArrayFromLevelId(pLevel1->pDrlg,pLevel1->nLevelId);
  DRLGWARP_GetWarpIdArrayFromLevelId(pLevel2->pDrlg,pLevel2->nLevelId);
  D2DrlgRoomStrc* pRoom1=FindRoom(pLevel1,i);
  D2DrlgRoomStrc* pRoom2=FindRoom(pLevel2,j);
  DRLGACTIVATE_InitializeRoomEx(pRoom1);
  DRLGACTIVATE_InitializeRoomEx(pRoom2);
  D2PresetUnitStrc* pPreset=DRLGROOM_GetPresetUnits(pRoom1);
  while(pPreset && pPreset->nUnitType!=5)pPreset=pPreset->pNext;
  pPreset=DRLGROOM_GetPresetUnits(pRoom2);
  while(pPreset && pPreset->nUnitType!=5)pPreset=pPreset->pNext;
 }
}
