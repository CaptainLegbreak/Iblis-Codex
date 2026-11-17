struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;
struct D2StatListStrc;
struct D2GfxLightStrc;
struct D2DrlgActStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
};

struct D2UnitSfxNodeStrc
{
    void* pUnitSfx;
    D2UnitSfxNodeStrc* pNext;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int unk0x10[7];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    int unk0x30[13];
    D2GfxLightStrc* pLight;
    int unk0x68[4];
    D2UnitSfxNodeStrc* pUnitSfxData;
    unsigned int dwSfxTicks;
    int unk0x80[17];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
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
    int unk0x38[5];
    int nTotalFrames;
    int nFrames;
    void* pfCallback;
    D2UnitStrc* pInitArgs;
};

struct D2MissilesTxt
{
    char unk0x00[0x12];
    short wTravelSound;
    char unk0x14[0x0A];
    short wCltSubMissile[3];
    char unk0x24[0x14];
    int dwParam[5];
    char unk0x4C[0x0C];
    int dwCltParam[5];
    char unk0x6C[0x138];
};

struct D2SkillsTxt
{
    char unk0x00[0x04];
    unsigned char nFlags[8];
    char unk0x0C[0x116];
    short wItemCastSound;
    short wItemCastOverlay;
    char unk0x126[0x116];
};

struct D2SetItemsTxt
{
    char unk0x00[0x2C];
    short nSetId;
    char unk0x2E[0x18A];
};

struct D2LevelSpeechStrc
{
    int nLevels[10];
    int nCondition;
    unsigned short f_2C;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
    char unk0xBC4[0x54];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
    char unk0xC20[0x3C];
    int nLevelsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnBitMasks_006CE268[8];                                                                          // 0x006CE268
extern int gaSetPropIds_006DBD70[];                                                                         // 0x006DBD70
extern const int gaRingOffsetY_006DAF08[16];                                                                // 0x006DAF08
extern const int gaRingOffsetX_006DAF48[16];                                                                // 0x006DAF48
extern D2LevelSpeechStrc* gpLevelSpeeches_0072A2C4[20];                                                     // 0x0072A2C4
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
int gaLevelVisited_007C78B8[1024];                                                                          // 0x007C78B8
int gnLastLevelId_007C88CC;                                                                                 // 0x007C88CC
extern unsigned int gdwFadeTick_007C89CC;                                                                   // 0x007C89CC
unsigned char gnRoomColorBlue_007C8A6C;                                                                     // 0x007C8A6C
unsigned char gnRoomColorGreen_007C8A6D;                                                                    // 0x007C8A6D
unsigned char gnRoomColorIntensity_007C8A6E;                                                                // 0x007C8A6E
unsigned char gnRoomColorRed_007C8A6F;                                                                      // 0x007C8A6F

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType);                              // 0x00465EE0
void __fastcall sub_00465F00_RemoveClientUnit(int nUnitId, int nUnitType);                                  // 0x00465F00
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00474470_ReleaseLight(D2GfxLightStrc* pLight);                                          // 0x00474470
int __fastcall sub_00481890_GetHintGroup(int nId);                                                          // 0x00481890
unsigned char __fastcall sub_004818C0_GetHintCount(int nId);                                                // 0x004818C0
int __fastcall sub_004A4180_TestCondition(int nCondition);                                                  // 0x004A4180
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __cdecl sub_004B9C20_IsSpeechPlaying();                                                                 // 0x004B9C20
int __fastcall sub_004B9CA0_GetHintIdByKey(void* pKey);                                                     // 0x004B9CA0
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce);                 // 0x004BA790
int __fastcall sub_004C6660_SkillStart(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode);               // 0x004C6660
int __fastcall sub_004C6680_SkillDo(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode);                  // 0x004C6680
D2UnitStrc* __fastcall sub_004C5470_CreateMissileToTarget(D2UnitStrc* pUnit, int nMissile, int nSkillId, int nSkillLevel); // 0x004C5470
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nId);                                // 0x004CB9C0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                     // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
int __cdecl sub_004DF880();                                                                                 // 0x004DF880
int __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pItem, int nArg1, int nArg2, int nArg3, int nProp, int nArg5, int nArg6, int nArg7); // 0x004E60A0
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340
void __stdcall sub_00619D70(D2ActiveRoomStrc* pRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x00619D70
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue);  // 0x0061C0B0
int __stdcall sub_0061C0E0(void* pAct);                                                                     // 0x0061C0E0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10
D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* pUnit);                                           // 0x00621150
void __stdcall sub_00621780_SetMissileArg(D2UnitStrc* pMissile, int nArg);                                  // 0x00621780
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall sub_006486C0(D2DynamicPathStrc* pDynamicPath);                                                // 0x006486C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall MISSILE_GetTotalFrames(D2UnitStrc* pMissile);                                                 // 0x0064A300
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                       // 0x0064A380
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(D2UnitStrc* pItem)
{
    int nFileIndex = ITEMS_GetFileIndex(pItem);
    if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nFileIndex];
    }

    return 0;
}

inline int UNITS_IsAsyncInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 21) & 1;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CA060
int __fastcall sub_004CA060(D2UnitStrc* pUnit, int nSkillId, int nArg, D2UnitStrc* pTarget, int nX, int nY, unsigned short nMode)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pOldTarget = sub_004648F0_GetTargetUnit(pUnit);
    int nOldX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    int nOldY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    int bFlag = (pUnit->dwFlags >> 6) & 1;
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    }

    int nResult = 0;
    if (pSkillsTxtRecord->nFlags[4] & gnBitMasks_006CE268[2])
    {
        int bToggled = 0;
        if (pTarget && sub_00464820_IsDeadOrDying(pTarget) && STATES_CheckState(pTarget, 0x76))
        {
            bToggled = 1;
            STATES_ToggleState(pTarget, 0x76, 0);
        }

        if (!sub_004C6660_SkillStart(pUnit, nSkillId, nArg, -1))
        {
            goto restore;
        }

        if (bToggled)
        {
            STATES_ToggleState(pTarget, 0x76, 1);
        }
    }

    if (pSkillsTxtRecord->wItemCastSound >= 0)
    {
        sub_004B9A00(pSkillsTxtRecord->wItemCastSound, pUnit, 0, 0, 0);
    }

    if (pSkillsTxtRecord->wItemCastOverlay >= 0 && pSkillsTxtRecord->wItemCastOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        sub_00470390(pUnit, pSkillsTxtRecord->wItemCastOverlay, 2, 0, 0, 0, 0, 0);
    }

    nResult = sub_004C6680_SkillDo(pUnit, nSkillId, nArg, nMode);

restore:
    if (pOldTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nOldX, nOldY);
    }

    if (bFlag)
    {
        pUnit->dwFlags |= 0x40;
    }
    else
    {
        pUnit->dwFlags &= ~0x40;
    }

    return nResult;
}

// 0x004CA900
void* __fastcall sub_004CA900_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId)
{
    D2_ASSERT(pUnit, 0xC47);
    if (!sub_004DF880())
    {
        return 0;
    }

    int nGroup = sub_00481890_GetHintGroup(nId);
    int nCount = sub_004818C0_GetHintCount(nGroup);
    for (D2UnitSfxNodeStrc* pNode = pUnit->pUnitSfxData; pNode; pNode = pNode->pNext)
    {
        void* pUnitSfx = pNode->pUnitSfx;
        int nHintId = sub_004B9CA0_GetHintIdByKey(pUnitSfx);
        if (nHintId >= nGroup && nHintId < nGroup + nCount)
        {
            return pUnitSfx;
        }
    }

    return 0;
}

// 0x004CC270
void __cdecl sub_004CC270_CheckLevelSpeech()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount || nLevelId == gnLastLevelId_007C88CC)
    {
        return;
    }

    gnLastLevelId_007C88CC = nLevelId;
    if (gaLevelVisited_007C78B8[nLevelId])
    {
        return;
    }

    D2LevelSpeechStrc* pEntry;
    for (int i = 0; i < 20; ++i)
    {
        pEntry = gpLevelSpeeches_0072A2C4[i];
        if (!pEntry)
        {
            return;
        }

        for (int j = 0; j < 10; ++j)
        {
            int nLevel = pEntry->nLevels[j];
            if (!nLevel)
            {
                break;
            }

            if (nLevel == nLevelId)
            {
                goto found;
            }
        }
    }

    return;

found:
    for (int j = 0; j < 10; ++j)
    {
        int nLevel = pEntry->nLevels[j];
        if (!nLevel)
        {
            break;
        }

        gaLevelVisited_007C78B8[nLevel] = 1;
    }

    if (pEntry->nCondition && !sub_004A4180_TestCondition(pEntry->nCondition))
    {
        return;
    }

    D2_ASSERT(pPlayer, 0xCBB);
    unsigned int dwSfxTicks = pPlayer->dwSfxTicks;
    if (sub_0044DB00() - dwSfxTicks <= 0x3E)
    {
        return;
    }

    if (sub_004B9C20_IsSpeechPlaying())
    {
        return;
    }

    sub_004CB9C0_Request(pPlayer, pEntry->f_2C);
}

// 0x004CD390
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wTravelSound >= 0)
    {
        void* pUnitSfx = sub_004CA900_FindUnitSfxInRange(pMissile, pMissilesTxtRecord->wTravelSound);
        if (pUnitSfx)
        {
            sub_004BA790_ReleaseUnitSfx(pUnitSfx, pMissile, 0);
        }
    }

    D2GfxLightStrc* pLight = UNITS_ResetLightMap(pMissile);
    if (pLight)
    {
        sub_00474470_ReleaseLight(pLight);
    }

    if (UNITS_IsAsyncInline(pMissile))
    {
        sub_00465F00_RemoveClientUnit(pMissile->dwUnitId, pMissile->dwUnitType);
    }
    else
    {
        sub_00465EE0_RemoveClientSideUnit(pMissile->dwUnitId, pMissile->dwUnitType);
    }
}

// 0x004CEFE0
void __fastcall sub_004CEFE0_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nOuterStep, int nInnerStep, int nLoops)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    if (!nMissile)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x17;
    if (nLoops > 0)
    {
        missileParams.dwFlags = 0x1F;
        missileParams.nLoops = nLoops;
    }

    missileParams.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nMissile = nMissile;
    missileParams.nX = UNITS_GetUnitXPosition(pMissile);
    missileParams.nY = UNITS_GetUnitYPosition(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    int nStep = nInnerStep < 1 ? 1 : nInnerStep;
    for (int i = 0; i < 16; i += nStep)
    {
        missileParams.nTargetX = gaRingOffsetX_006DAF48[i];
        missileParams.nTargetY = gaRingOffsetY_006DAF08[i];
        sub_004CD540_CreateMissile(&missileParams);
    }

    if (nOuterStep > 0)
    {
        missileParams.nVelocity = pMissilesTxtRecord->dwParam[1] << 7;
        for (int i = 1; i < 16; i += nOuterStep)
        {
            missileParams.nTargetX = gaRingOffsetX_006DAF48[i];
            missileParams.nTargetY = gaRingOffsetY_006DAF08[i];
            sub_004CD540_CreateMissile(&missileParams);
        }
    }
}

// 0x004D4180
void __fastcall sub_004D4180_CltDoHomingSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nTargetX = MISSILE_GetTargetX(pMissile);
    if (nTargetX <= -pMissilesTxtRecord->dwCltParam[1])
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    if (nTargetX <= 0)
    {
        MISSILE_SetTargetX(pMissile, nTargetX - 1);
    }

    if (!sub_006486C0(pMissile->pDynamicPath))
    {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pMissile->pDynamicPath);
    if (!pTarget)
    {
        pTarget = sub_004648F0_GetTargetUnit(pOwner);
    }

    int nRate = pMissilesTxtRecord->dwCltParam[2];
    if (nRate <= 0)
    {
        nRate = 5;
    }

    if (pTarget && !(sub_0064A380_GetRemainingFrames(pMissile) % nRate) && nTargetX > 0
        && sub_006416D0_UnitEdgeDistance(pMissile, pTarget) < pMissilesTxtRecord->dwCltParam[3])
    {
        int nX = UNITS_GetXPosition(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        int nTargetUnitX = UNITS_GetXPosition(pTarget);
        int nTargetUnitY = CLIENTS_GetUnitY(pTarget);
        int nStep = pMissilesTxtRecord->dwCltParam[4] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[4];

        int nDeltaX = 0;
        int nDeltaY = 0;
        if (nTargetUnitX > nX)
        {
            nDeltaX = nStep;
        }
        else if (nTargetUnitX < nX)
        {
            nDeltaX = -nStep;
        }

        if (nTargetUnitY > nY)
        {
            nDeltaY = nStep;
        }
        else if (nTargetUnitY < nY)
        {
            nDeltaY = -nStep;
        }

        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, UNITS_GetXPosition(pMissile) + nDeltaX, CLIENTS_GetUnitY(pMissile) + nDeltaY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        int nPeriod = pMissilesTxtRecord->dwCltParam[0] > 1 ? pMissilesTxtRecord->dwCltParam[0] : 1;
        if (!(sub_0064A380_GetRemainingFrames(pMissile) % nPeriod) && nTargetX > 0)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 5;
            missileParams.nX = UNITS_GetXPosition(pMissile);
            missileParams.nY = CLIENTS_GetUnitY(pMissile);
            missileParams.nTotalFrames = MISSILE_GetTotalFrames(pMissile) - 1;
            missileParams.nVelocity = 0;
            missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            missileParams.pOwner = pOwner;
            missileParams.nSkill = MISSILE_GetSkill(pMissile);
            missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            D2UnitStrc* pSubMissile = sub_004CD540_CreateMissile(&missileParams);
            if (pSubMissile)
            {
                MISSILE_SetTargetX(pSubMissile, 0);
            }
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}

// build: context sub_004DC000_DrawFadeBox
void __cdecl sub_004DC000_DrawFadeBox()
{
    if (!gdwFadeTick_007C89CC)
    {
        return;
    }

    unsigned int dwNow = GetTickCount();
    if (dwNow > gdwFadeTick_007C89CC)
    {
        gdwFadeTick_007C89CC = 0;
        return;
    }

    int nRemaining = gdwFadeTick_007C89CC - dwNow;
    int nYEnd = gnGlobal_00711470 - 47;
    int nXEnd = gnGlobal_0071146C;
    int nXStart = 0;
    switch (sub_0045AE90())
    {
    case 1:
        nXEnd -= gnGlobal_0071146C / 2;
        break;

    case 2:
        nXStart = gnGlobal_0071146C / 2;
        break;
    }

    D2GFX_DrawBoxAlpha(nXStart, 0, nXEnd, nYEnd, 0, nRemaining * 255 / 1000);
}

// 0x004DED20
void __cdecl sub_004DED20_UpdateRoomColor()
{
    sub_0061C0B0(gpGlobal_007A0634, &gnRoomColorRed_007C8A6F, &gnRoomColorGreen_007C8A6D, &gnRoomColorBlue_007C8A6C);
    gnRoomColorIntensity_007C8A6E = sub_0061C0E0(gpGlobal_007A0634);

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    sub_00619D70(pRoom, &nIntensity, &nRed, &nGreen, &nBlue);
    if (nRed || nGreen || nBlue)
    {
        gnRoomColorIntensity_007C8A6E = nIntensity;
        gnRoomColorRed_007C8A6F = nRed;
        gnRoomColorGreen_007C8A6D = nGreen;
        gnRoomColorBlue_007C8A6C = nBlue;
    }
}

// 0x004E27C0
int __fastcall sub_004E27C0_SkillStartSpawnRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pMissileA = sub_004C5470_CreateMissileToTarget(pUnit, 0x150, nSkillId, nSkillLevel);
    D2UnitStrc* pMissileB = sub_004C5470_CreateMissileToTarget(pUnit, 0x151, nSkillId, nSkillLevel);
    D2UnitStrc* pRequestA = sub_004CDB40_SubmitRequest(pUnit, 0x14F, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestB = sub_004CDB40_SubmitRequest(pUnit, 0x151, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestC = sub_004CDB40_SubmitRequest(pUnit, 0x14E, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestD = sub_004CDB40_SubmitRequest(pUnit, 0x14D, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);

    if (pRequestA)
    {
        sub_004DA200_SetMotionVectorB(pRequestA, 0, 0, 15, 1);
    }

    if (pRequestB)
    {
        sub_004DA200_SetMotionVectorB(pRequestB, 0, 0, 15, 1);
    }

    if (pMissileA)
    {
        sub_004DA1D0_SetMotionVectorA(pMissileA, 0, 0, 0x15F9);
        sub_004DA200_SetMotionVectorB(pMissileA, 0, 0, -25, 1);
    }

    if (pMissileB)
    {
        sub_004DA1D0_SetMotionVectorA(pMissileB, 0, 0, 0x15F9);
        sub_004DA200_SetMotionVectorB(pMissileB, 0, 0, -25, 1);
    }

    if (pRequestC)
    {
        sub_00621780_SetMissileArg(pRequestD, 0x80);
        sub_00621780_SetMissileArg(pRequestC, 0x80);
    }

    return 1;
}

// 0x004E6680
void __fastcall sub_004E6680_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nArg1, int nArg2)
{
    if (ITEMS_GetItemQuality(pItem) != 5)
    {
        return;
    }

    D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordInline(pItem);
    if (!pSetItemsTxt)
    {
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, gaSetPropIds_006DBD70[i]);
        if (pStatList && pSetItemsTxt->nSetId == STATLIST_GetStatValue(pStatList, 0x47, 0))
        {
            sub_004E60A0_AddSetPropText(pUnit, nArg1, nArg2, 0, gaSetPropIds_006DBD70[i], 0, 0, 1);
            return;
        }
    }
}

#include "gen/data/Source/D2Client/004CA060_sub_004CA060.inc"
