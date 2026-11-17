struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2TCExShortStrc;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[0x23A];
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
    D2SkillStrc* pUsedSkill;
    void* unk014;
};

struct D2MissileDataStrc
{
    unsigned int unk0x00;
    short nStreamMissile;
    short nStreamRange;
    short nActivateFrame;
    short nSkill;
    short nLevel;
    short nTotalFrames;
    short nCurrentFrame;
    unsigned short unk0x12;
    unsigned int fFlags;
    int nOwnerType;
    int dwOwnerGUID;
    int nHomeType;
    int dwHomeGUID;
    int nTargetX;
    int nTargetY;
    void* pStream;
};

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2FP32_16PartsStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
};

struct D2FP32_16PrecisionStrc
{
    unsigned int dwPrecisionX;
    unsigned int dwPrecisionY;
};

struct D2FP32_16
{
    union
    {
        D2FP32_16PartsStrc tParts;
        D2FP32_16PrecisionStrc tPrecision;
    };
};

struct D2DynamicPathStrc
{
    D2FP32_16 tGameCoords;
    int dwClientCoordX;
    int dwClientCoordY;
    D2PathPointStrc tTargetCoord;
    D2PathPointStrc tPrevTargetCoord;
    D2PathPointStrc tFinalTargetCoord;
    D2ActiveRoomStrc* pRoom;
    D2ActiveRoomStrc* pPreviousRoom;
    int dwCurrentPointIdx;
    int dwPathPoints;
    void* unk0x2C;
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
    char unk0x38[0x58 - 0x38];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x93 - 0x5C];
    unsigned char nStepNum;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MissileDataStrc* pMissileData;
    char unk0x18[0x2C - 0x18];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xA8 - 0x30];
    D2SkillListStrc* pSkills;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned char nMissileFlags[4];
    char unk0x08[0x19C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    int unk0xB68;
    int nMissilesTxtRecordCount;
};

struct D2Unk00667030InnerStrc
{
    int nValue0;
    int nValue1;
};

struct D2Unk00667030MidStrc
{
    char unk0x00[0x08];
    D2Unk00667030InnerStrc* pInner;
};

struct D2Unk00667030Strc
{
    char unk0x00[0x20];
    D2Unk00667030MidStrc* pMid;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgGridStrc
{
    char unk0x00[0x14];
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags;
    D2DrlgGridStrc pGrid[4];
    int nWidth;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x14];
    D2DrlgOutdoorInfoStrc* pOutdoors;
};

struct D2UnkOutdoorStrc
{
    D2DrlgLevelStrc* pLevel;
    int* field_4;
    D2DrlgGridStrc* pGrid1;
    D2DrlgGridStrc* pGrid2;
    int nLevelPrestId;
    int field_14;
    int nLvlSubId;
    unsigned int(__fastcall* field_1C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    int(__fastcall* field_20)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags);
    int(__fastcall* field_24)(D2DrlgLevelStrc* pLevel, int nX, int nY, int a4, int a5, unsigned int a6);
    int(__fastcall* field_28)(D2DrlgLevelStrc* pLevel, int nStyle, int a3);
    void(__fastcall* field_2C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_30)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_34)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nRand, int a6);
};

struct D2PathBoundsContextStrc
{
    char unk0x0000[0x6278];
    D2PathPointStrc tMin;
    D2PathPointStrc tMax;
};

struct D2PathFoWallNodeStrc
{
    D2PathPointStrc tPoint;
    short nFScore;
    short nHeuristicDistanceToTarget;
    short nBestDistanceFromStart;
    unsigned short wPad;
    D2PathFoWallNodeStrc* pBestParent;
    D2PathFoWallNodeStrc* pChildren[8];
    D2PathFoWallNodeStrc* pNextCachePoint;
    D2PathFoWallNodeStrc* pNextSortedByFScore;
};

struct D2PathFoWallContextStrc
{
    D2PathFoWallNodeStrc* aPendingCache[128];
    D2PathFoWallNodeStrc* aVisitedCache[128];
};

#define UNIT_MISSILE 3
#define D2UnitInvalidGUID -1
#define PLRMODE_THROW 11
#define LVLSUB_UNUSED_INVALID -1
#define PATH_CURRENT_ROOM_INVALID 2
#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern int gdwPathResetPrecisionX_006EB7C8;                                                                 // 0x006EB7C8
extern int gdwPathResetPrecisionY_006EB7CC;                                                                 // 0x006EB7CC
D2TCExShortStrc* gpChestTreasureClasses[45];                                                                // 0x0096C5F4
extern int gaLookupRow_006F0FD0[];                                                                          // 0x006F0FD0
extern int gaLookupSmall_006F0630[][4];                                                                     // 0x006F0630
extern int gaLookupLarge_006F06F0[][2];                                                                     // 0x006F06F0
extern const int gaPathHeuristicTable_006F1698[];                                                           // 0x006F1698
extern const int gaIdaStar_PointCacheHashMaskX[];                                                           // 0x006F1998
extern const int gaIdaStar_PointCacheHashMaskY[];                                                           // 0x006F1B98
extern const int gaPathDeltaTable_006F1E28[];                                                               // 0x006F1E28
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                      // 0x00641530
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused);           // 0x0064C2C0
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60
void __fastcall sub_0064FD70_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70
void __fastcall DRLGTILESUB_AddSecondaryBorder(D2UnkOutdoorStrc* pOutdoor);                                // 0x00670750
void __fastcall DRLGOUTDOORS_AlterAdjacentPresetGridCells(D2DrlgLevelStrc* pLevel, int nX, int nY);         // 0x00674160
void __fastcall DRLGOUTDOORS_SetBlankGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY);                     // 0x006741A0
unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY);       // 0x006741E0
int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags); // 0x00674230
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0

__forceinline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x00643340
void __stdcall DUNGEON_ClientTileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 2 * nY + nX;
    *pY = 2 * nY - nX;

    if (*pX < 0)
    {
        *pX = *pX / 160 - 1;
    }
    else
    {
        *pX /= 160;
    }

    if (*pY < 0)
    {
        *pY = *pY / 160 - 1;
    }
    else
    {
        *pY /= 160;
    }
}

// 0x00643400
void __stdcall DUNGEON_ClientSubileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 2 * nY + nX;
    *pY = 2 * nY - nX;

    if (*pX < 0)
    {
        *pX = (*pX / 32) - 1;
    }
    else
    {
        *pX /= 32;
    }

    if (*pY < 0)
    {
        *pY = (*pY / 32) - 1;
    }
    else
    {
        *pY /= 32;
    }
}

// 0x00643510
void __stdcall DUNGEON_ClientToGameSubtileCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;

    *pX = (2 * nY + nX) >> 5;
    *pY = (2 * nY - nX) >> 5;
}

// 0x00643540
void __stdcall DUNGEON_ClientToGameCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;

    *pX = 2 * nY + nX;
    *pY = 2 * nY - nX;
}

// 0x00643A00
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* a2)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return 0;
    }

    void* pResult = pSkillList->unk014;
    pSkillList->unk014 = a2;
    return pResult;
}

// 0x00643CE0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine)
{
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->pSkillsTxt->nSkillId;
}

// build: context MISSILE_CheckUnitIfOwner
int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pMissile && pUnit && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->nMissileFlags[0 >> 3] & gdwBitMasks[0 & 7])
        {
            D2MissileDataStrc* pMissileData = pMissile->pMissileData;
            if (pMissileData)
            {
                return pUnit->dwUnitType == pMissileData->nOwnerType && pUnit->dwUnitId == pMissileData->dwOwnerGUID;
            }
        }
    }

    return 0;
}

// 0x0064A7F0
void __stdcall MISSILE_GetHomeType(D2UnitStrc* pMissile, int* nHomeType, int* nHomeGUID)
{
    if (pMissile && pMissile->dwUnitType == UNIT_MISSILE)
    {
        D2MissileDataStrc* pMissileData = pMissile->pMissileData;
        if (!pMissileData)
        {
            *nHomeType = 0;
            *nHomeGUID = D2UnitInvalidGUID;
        }
        else
        {
            *nHomeType = pMissileData->nHomeType;
            *nHomeGUID = pMissileData->dwHomeGUID;
        }
    }
    else
    {
        *nHomeType = 0;
        *nHomeGUID = D2UnitInvalidGUID;
    }
}

// 0x0064C350
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    return UNITROOM_AddUnitToRoomEx(pUnit, pRoom, 1);
}

// 0x0064EFE0
void __fastcall sub_0064EFE0_FixThrowWeaponClassCode(unsigned int* pWeaponClassCode, int nUnused, int nMode)
{
    if (nMode == PLRMODE_THROW)
    {
        if (*pWeaponClassCode != ' sh1' && *pWeaponClassCode != ' th1' && *pWeaponClassCode != ' sj1' && *pWeaponClassCode != ' tj1' && *pWeaponClassCode != ' ss1' && *pWeaponClassCode != ' ts1')
        {
            *pWeaponClassCode = ' hth';
        }
    }
}

// 0x0064FC20
void __stdcall sub_0064FC20_ResetDynamicPathRoom(D2DynamicPathStrc* pDynamicPath)
{
    const int nPrecisionX = gdwPathResetPrecisionX_006EB7C8;
    const int nPrecisionY = gdwPathResetPrecisionY_006EB7CC;

    pDynamicPath->tGameCoords.tPrecision.dwPrecisionX = nPrecisionX;
    pDynamicPath->dwClientCoordX = nPrecisionX;
    pDynamicPath->tGameCoords.tPrecision.dwPrecisionY = nPrecisionY;
    pDynamicPath->dwClientCoordY = nPrecisionY;
    pDynamicPath->dwPathPoints = 0;

    if (pDynamicPath->pRoom)
    {
        pDynamicPath->pPreviousRoom = pDynamicPath->pRoom;
        UNITROOM_RemoveUnitFromRoom(pDynamicPath->pUnit);
        pDynamicPath->dwFlags |= PATH_CURRENT_ROOM_INVALID;
    }
}

// build: context PATH_ComputeDirectionFromPreciseCoords_6FDAC760
int __stdcall PATH_ComputeDirectionFromPreciseCoords_6FDAC760(unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY)
{
    D2CoordStrc pCoords;
    int nDirection;

    PATH_GetDirectionVector(&pCoords, &nDirection, dwStartPrecisionX, dwStartPrecisionY, dwTargetPrecisionX, dwTargetPrecisionY);

    return nDirection;
}

// 0x00650540
int __stdcall D2Common_10227(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 1;
    }

    if (pDynamicPath->pTargetUnit && D2Common_10399(pDynamicPath->pTargetUnit, pUnit) <= pDynamicPath->nStepNum)
    {
        return 1;
    }

    return pDynamicPath->tGameCoords.tParts.wPosX == pDynamicPath->tTargetCoord.X && pDynamicPath->tGameCoords.tParts.wPosY == pDynamicPath->tTargetCoord.Y;
}

// 0x00654E80
D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(int nDifficulty, int nAct, int nIndex)
{
    const int nDifficultyFloor = nDifficulty > 0 ? nDifficulty : 0;
    const int nDifficultyIndex = nDifficultyFloor < 2 ? nDifficultyFloor : 2;
    const int nActFloor = nAct > 0 ? nAct : 0;
    const int nActIndex = nActFloor < 4 ? nActFloor : 4;
    const int nIndexFloor = nIndex > 0 ? nIndex : 0;
    const int nChestIndex = nIndexFloor < 2 ? nIndexFloor : 2;

    return gpChestTreasureClasses[nChestIndex + 3 * (nActIndex + 5 * nDifficultyIndex)];
}

// 0x00667030
void __fastcall sub_00667030_GetInnerPair(D2Unk00667030Strc* pRecord, int* pValue0, int* pValue1)
{
    D2Unk00667030MidStrc* pMid = pRecord->pMid;
    if (pValue0)
    {
        *pValue0 = pMid->pInner->nValue0;
    }
    if (pValue1)
    {
        *pValue1 = pMid->pInner->nValue1;
    }
}

// 0x0066B800
int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY)
{
    if (pDrlgCoord1->nPosX < pDrlgCoord2->nPosX)
    {
        *pDistanceX = pDrlgCoord2->nPosX - pDrlgCoord1->nWidth - pDrlgCoord1->nPosX;
    }
    else
    {
        *pDistanceX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth - pDrlgCoord2->nPosX;
    }

    if (pDrlgCoord1->nPosY < pDrlgCoord2->nPosY)
    {
        *pDistanceY = pDrlgCoord2->nPosY - pDrlgCoord1->nHeight - pDrlgCoord1->nPosY;
    }
    else
    {
        *pDistanceY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight - pDrlgCoord2->nPosY;
    }

    return *pDistanceX >= nMaxDistance || *pDistanceY >= nMaxDistance;
}

// 0x0066B880
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nOrthogonalDistanceMax)
{
    int nSignedDistanceX = 0;
    int nSignedDistanceY = 0;

    if (pDrlgCoord1->nPosX <= pDrlgCoord2->nPosX)
    {
        nSignedDistanceX = pDrlgCoord2->nPosX - pDrlgCoord1->nWidth - pDrlgCoord1->nPosX;
    }
    if (pDrlgCoord1->nPosX > pDrlgCoord2->nPosX)
    {
        nSignedDistanceX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth - pDrlgCoord2->nPosX;
    }

    if (pDrlgCoord1->nPosY <= pDrlgCoord2->nPosY)
    {
        nSignedDistanceY = pDrlgCoord2->nPosY - pDrlgCoord1->nHeight - pDrlgCoord1->nPosY;
    }
    if (pDrlgCoord1->nPosY > pDrlgCoord2->nPosY)
    {
        nSignedDistanceY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight - pDrlgCoord2->nPosY;
    }

    if (!nOrthogonalDistanceMax)
    {
        return nSignedDistanceX <= 0 && nSignedDistanceY <= 0;
    }

    if (nSignedDistanceX == 0 && nSignedDistanceY <= nOrthogonalDistanceMax)
    {
        return 1;
    }

    return nSignedDistanceY == 0 && nSignedDistanceX <= nOrthogonalDistanceMax;
}

// 0x0066E140
char __stdcall sub_0066E140_GetModeChar(int nMode)
{
    return nMode == 11 ? 'r' : 'l';
}

// 0x006752A0
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2UnkOutdoorStrc a1 = {};

    a1.pLevel = pLevel;
    a1.field_4 = &pOutdoors->nWidth;
    a1.pGrid1 = &pOutdoors->pGrid[0];
    a1.pGrid2 = &pOutdoors->pGrid[2];
    a1.nLevelPrestId = nLevelPrestId;
    a1.field_14 = -1;
    a1.nLvlSubId = nLvlSubId;
    a1.field_1C = DRLGOUTDOORS_TestGridCellNonLvlLink;
    a1.field_20 = DRLGOUTDOORS_TestOutdoorLevelPreset;
    a1.field_2C = DRLGOUTDOORS_AlterAdjacentPresetGridCells;
    a1.field_30 = DRLGOUTDOORS_SetBlankGridCell;
    a1.field_34 = DRLGOUTDOORS_SpawnOutdoorLevelPresetEx;

    DRLGTILESUB_AddSecondaryBorder(&a1);
}

// 0x006755C0
int __fastcall sub_006755C0_LookupTable(int nA, int nB, int nC)
{
    const int nRow = gaLookupRow_006F0FD0[nA + 3 * nB];
    if (nC >= 4)
    {
        return gaLookupLarge_006F06F0[nRow][nC - 4];
    }
    return gaLookupSmall_006F0630[nRow][nC];
}

// 0x00678B40
int __stdcall sub_00678B40_PathHeuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint2.X - tPoint1.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint2.Y - tPoint1.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    const int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    const int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x00679380
int __stdcall sub_00679380_PathTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nDiffX = pPoint1.X - pPoint2.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = pPoint1.Y - pPoint2.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    if (nDiffX < 8 && nDiffY < 8)
    {
        const int nResult = gaPathHeuristicTable_006F1698[nDiffX + 8 * nDiffY];
        if (nResult < 0)
        {
            return 0;
        }
        return nResult + 1;
    }

    if (nDiffX > nDiffY)
    {
        return nDiffY + 2 * nDiffX;
    }
    return nDiffX + 2 * nDiffY;
}

// 0x0067A390
void __fastcall sub_0067A390_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDirection;
    sub_0064FD70_GetDirectionVectorFromPoints(pDirectionVector, &nDirection, tPoint1, tPoint2);
    pDirectionVector->nX = (pDirectionVector->nX * nVelocity) >> 8;
    pDirectionVector->nY = (pDirectionVector->nY * nVelocity) >> 8;
    D2_ASSERT(D2_MAX(D2_ABS(pDirectionVector->nX), D2_ABS(pDirectionVector->nY)) < 0x200000, 817);
}

// 0x0067A550
int __stdcall sub_0067A550_PathHeuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint2.X - tPoint1.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint2.Y - tPoint1.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    const int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    const int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x0067A5F0
int __fastcall sub_0067A5F0_IsPointInBounds(D2PathBoundsContextStrc* pContext, int nUnused, D2PathPointStrc tPoint)
{
    return tPoint.X >= pContext->tMin.X && tPoint.X <= pContext->tMax.X && tPoint.Y >= pContext->tMin.Y && tPoint.Y <= pContext->tMax.Y;
}

// 0x0067ADC0
int __stdcall PATH_AStar_Heuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint1.X - tPoint2.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint1.Y - tPoint2.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    if (nDiffX >= nDiffY)
    {
        return nDiffY + 2 * nDiffX;
    }
    return nDiffX + 2 * nDiffY;
}

// 0x0067AE00
D2PathFoWallNodeStrc* __stdcall PATH_AStar_GetNodeFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[tPathPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[tPathPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pNode = pContext->aPendingCache[nHash]; pNode != 0; pNode = pNode->pNextCachePoint)
    {
        if (tPathPoint.X == pNode->tPoint.X && tPathPoint.Y == pNode->tPoint.Y)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x0067AE50
D2PathFoWallNodeStrc* __stdcall PATH_AStar_FindPointInVisitedCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[tPathPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[tPathPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pNode = pContext->aVisitedCache[nHash]; pNode != 0; pNode = pNode->pNextCachePoint)
    {
        if (tPathPoint.X == pNode->tPoint.X && tPathPoint.Y == pNode->tPoint.Y)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x0067B9C0
int __stdcall sub_0067B9C0_SquaredDistance(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    const int nDiffX = tPoint1.X - tPoint2.X;
    const int nDiffY = tPoint1.Y - tPoint2.Y;
    return nDiffY * nDiffY + nDiffX * nDiffX;
}

// 0x0067BBC0
int __stdcall sub_0067BBC0_DeltaTableLookup(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    return gaPathDeltaTable_006F1E28[3 * (tPoint2.Y - tPoint1.Y) + (tPoint2.X - tPoint1.X)];
}

#include "gen/data/Source/D2Common/00643340_DUNGEON_ClientTileDrawPositionToGameCoords.inc"
