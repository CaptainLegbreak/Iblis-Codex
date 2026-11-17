struct D2DynamicPathStrc;
struct D2ActiveRoomStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[9];
    D2DynamicPathStrc* pDynamicPath;
    int unk0x30[5];
    int nSeqCurrentFramePrecise;
    int unk0x48[31];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

struct D2MissilesTxt
{
    char unk0x000[0x12C];
    unsigned char nCltSrcTown;
    char unk0x12D[0x08];
    unsigned char nInitSteps;
    unsigned char nActivate;
    unsigned char nLoopAnim;
    char unk0x138[0x40];
    unsigned char nAnimLen;
    char unk0x179[0x07];
    unsigned char nSubLoop;
    unsigned char nSubStart;
    unsigned char nSubStop;
    char unk0x183[0x02];
    unsigned char nClientCol;
    char unk0x186[0x1E];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

struct D2CltMissileFindArgStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

struct D2CltMissileModeStrc
{
    D2UnitFindCallback pfUnitFindCallback;
    int nCollisionMask;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern D2CltMissileModeStrc gaCltMissileModes_0072A350[];                                                   // 0x0072A350

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380
int __stdcall sub_0064A640(D2UnitStrc* pMissile);                                          // 0x0064A640
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0
int __stdcall sub_004DA6B0_TestMotionFlags(D2UnitStrc* pUnit);                                              // 0x004DA6B0
void __fastcall sub_004D2D70_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg);          // 0x004D2D70
int __stdcall sub_006217C0(D2UnitStrc* pUnit);                                                              // 0x006217C0
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit);                                                        // 0x00621310
void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate);           // 0x00621330
int __stdcall sub_006486C0(D2DynamicPathStrc* pDynamicPath);                                                // 0x006486C0
int __cdecl sub_0044DB10();                                                                                 // 0x0044DB10
void __stdcall sub_00650840(D2UnitStrc* pUnit, int nValue);                                                 // 0x00650840
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __fastcall sub_00451F70_GetUnitMode(D2UnitStrc* pUnit);                                                 // 0x00451F70
unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648EB0
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints); // 0x00648F40
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit);                                                        // 0x00620510
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D30C0
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile)
{
    if (!pMissile)
        return;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
        return;
    int bRepeat = 0;
    switch (gdwGlobal_007A0610)
    {
    case 0:
    case 1:
    case 6:
    case 8:
        if (sub_004639D0_GetOwnerUnit(pMissile) == sub_00463DD0())
            bRepeat = 1;
        break;
    }
    D2CltMissileFindArgStrc tFindArg;
    for (;;)
    {
        const int bActive = sub_0064A380_GetRemainingFrames(pMissile) <= sub_0064A640(pMissile);
        if (bActive && sub_0064A3B0_GetElapsedFrames(pMissile) > pMissilesTxtRecord->nInitSteps)
            pMissile->dwFlagEx &= ~0x40000;
        if (!sub_004DA6B0_TestMotionFlags(pMissile))
        {
            sub_004D2D70_CltMissileHit(pMissile, 0, 1);
            return;
        }
        if (bActive)
        {
            if (!pMissilesTxtRecord->nLoopAnim)
            {
                if (!sub_006217C0(pMissile))
                    UNITS_UpdateFrame(pMissile);
            }
            else
            {
                if (pMissilesTxtRecord->nSubLoop)
                {
                    const int nSubStop = pMissilesTxtRecord->nSubStop;
                    if (sub_0064A380_GetRemainingFrames(pMissile) <= pMissilesTxtRecord->nAnimLen - nSubStop + 1)
                        UNITS_UpdateFrame(pMissile);
                    else
                        D2COMMON_10375_UNITS_SetFrameNonRate(pMissile, pMissilesTxtRecord->nSubStart, nSubStop);
                }
                else
                {
                    UNITS_UpdateFrame(pMissile);
                }
            }
        }
        D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
        if (sub_006486C0(pDynamicPath))
            sub_00650840(pMissile, sub_0044DB10());
        MISSILE_SetCurrentFrame(pMissile, sub_0064A380_GetRemainingFrames(pMissile) - 1);
        if (sub_0064A380_GetRemainingFrames(pMissile) <= 0)
        {
            sub_004D2D70_CltMissileHit(pMissile, 0, 0);
            return;
        }
        if (!bActive)
            return;
        if (pMissilesTxtRecord->nCltSrcTown > 0)
        {
            D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
            D2ActiveRoomStrc* pOwnerRoom;
            if (!pOwner || ((pOwnerRoom = UNITS_GetRoom(pOwner)) != 0 && DUNGEON_IsRoomInTown(pOwnerRoom)))
            {
                const int nFrame = pMissilesTxtRecord->nCltSrcTown;
                if (sub_0064A380_GetRemainingFrames(pMissile) >= nFrame)
                {
                    MISSILE_SetCurrentFrame(pMissile, nFrame);
                    if (!pMissilesTxtRecord->nLoopAnim)
                    {
                        const int nDelta = pMissilesTxtRecord->nAnimLen - pMissilesTxtRecord->nCltSrcTown;
                        if (nDelta > 0)
                            pMissile->nSeqCurrentFramePrecise = nDelta << 8;
                    }
                }
            }
        }
        const int nMissileMode = sub_00451F70_GetUnitMode(pMissile);
        if (!nMissileMode)
            return;
        const unsigned short nCollisionFlags = D2Common_10201(pDynamicPath);
        if (nCollisionFlags & 5)
        {
            sub_004D2D70_CltMissileHit(pMissile, 0, 1);
            return;
        }
        if (nMissileMode == 6)
            return;
        tFindArg.pMissile = pMissile;
        tFindArg.pOwner = sub_004639D0_GetOwnerUnit(pMissile);
        tFindArg.pMissilesTxtRecord = pMissilesTxtRecord;
        if (pMissilesTxtRecord->nClientCol && nCollisionFlags)
        {
            D2PathPointStrc* pPathPoints;
            const int nPathPoints = D2COMMON_10198_PathGetSaveStep(pDynamicPath, &pPathPoints);
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
            for (int i = 0; i < nPathPoints; ++i)
            {
                D2UnitStrc* pTarget = D2Common_10407(pRoom, pPathPoints[i].X, pPathPoints[i].Y, gaCltMissileModes_0072A350[nMissileMode].pfUnitFindCallback, &tFindArg, UNITS_GetUnitSizeX(pMissile));
                if (pTarget && !sub_00464820_IsDeadOrDying(pTarget))
                {
                    sub_004D2D70_CltMissileHit(pMissile, pTarget, 0);
                    return;
                }
            }
        }
        if (!bRepeat)
            return;
        if (sub_0064A3B0_GetElapsedFrames(pMissile) != 1)
            return;
        if (!sub_006486C0(pDynamicPath))
            return;
        bRepeat = 0;
    }
}
