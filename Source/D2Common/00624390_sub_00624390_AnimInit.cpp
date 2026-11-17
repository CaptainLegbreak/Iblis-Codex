struct D2StatListStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2AnimDataRecordStrc
{
    char unk0x00[0x08];
    int dwFramesPerDirection;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
    char unk0x28[0x08];
    void* pAnimSeq;
    char unk0x34[0x10];
    int dwGFXcurrentFrame;
    int dwFrameCountPrecise;
    unsigned short wAnimSpeed;
    unsigned char nActionFrame;
    unsigned char unk0x4F;
    D2AnimDataRecordStrc* pAnimData;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    int dwFrameCnt[8];
    short nFrameDelta[8];
    char unk0x108[0x21];
    unsigned char nStart[8];
    char unk0x131[0x44];
    unsigned char nSync;
};

struct D2MissilesTxt
{
    char unk0x00[0xA0];
    short nAnimLen_2;
    char unk0xA2[0xD6];
    unsigned char nAnimLen;
};

struct D2CharStatsTxt
{
    char unk0x00[0x40];
    unsigned char nWalkSpeed;
    unsigned char nRunSpeed;
    char unk0x42[0x82];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall sub_006270B0(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);           // 0x006270B0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
int __stdcall sub_00623B10_GetStartFrame(D2UnitStrc* pUnit);                                                // 0x00623B10
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit);                                                 // 0x00621260
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit);                                                 // 0x0063A400
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C3E0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0

static __declspec(noinline) void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId);

// 0x00620E80
static void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    D2CharStatsTxt* pCharStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
    const int nWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    if (nWalkSpeed)
    {
        sub_006270B0(pStatList, 0x43, 100 * pCharStatsTxtRecord->nRunSpeed / nWalkSpeed - 100, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

static __forceinline int UNITS_ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x00624390
int __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x951);

    pUnit->nActionFrame = 0;
    pUnit->dwGFXcurrentFrame = sub_00623B10_GetStartFrame(pUnit) << 8;

    int nUnitType = pUnit->dwUnitType;
    int nMode = pUnit->dwAnimMode;
    int nClassId = pUnit->dwClassId;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\UNITS\\Units.cpp", 0x958);

    switch (nUnitType)
    {
    case 0:
        if (nMode == 3 || nMode == 0x13)
        {
            UNITS_CharacterStartRunningOrKnockback(pUnit, nClassId);
        }

        if (nMode == 0x12)
        {
            UNITS_InitializeSequence(pUnit);
            UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNITS\\Units.cpp", 0x967);
            return 1;
        }

        pUnit->pAnimSeq = 0;
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNITS\\Units.cpp", 0x96A);
        pUnit->dwFrameCountPrecise = pUnit->pAnimData->dwFramesPerDirection << 8;
        return 1;

    case 1:
        if (pUnit->dwUnitType == 0 && STATES_IsUnitShapeShifted(pUnit))
        {
            switch (nMode)
            {
            case 0xD:
            case 0xF:
                UNITS_CharacterStartRunningOrKnockback(pUnit, pUnit->dwClassId);
                break;
            }
        }

        if (nMode == 0xE)
        {
            UNITS_InitializeSequence(pUnit);
            UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNITS\\Units.cpp", 0x97E);
            return 1;
        }

        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNITS\\Units.cpp", 0x980);
        pUnit->pAnimSeq = 0;
        pUnit->dwFrameCountPrecise = pUnit->pAnimData->dwFramesPerDirection << 8;
        return 1;

    case 2:
    {
        const int nObjectMode = nMode;
        D2_ASSERT(nObjectMode < 8, 0x98A);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        pUnit->dwFrameCountPrecise = pObjectsTxtRecord->dwFrameCnt[nObjectMode];
        const int nStartFrame = pObjectsTxtRecord->nStart[nObjectMode] << 8;
        short nAnimSpeed = pObjectsTxtRecord->nFrameDelta[nObjectMode];
        pUnit->dwGFXcurrentFrame = nStartFrame;
        if (pObjectsTxtRecord->nSync)
        {
            pUnit->wAnimSpeed = nAnimSpeed;
            return 1;
        }

        int nSpeed = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nAnimSpeed >> 3) + nAnimSpeed - (short)(nAnimSpeed >> 4);
        nSpeed = nSpeed <= 0 ? 0 : nSpeed;
        if (nSpeed >= 0x7FFF)
        {
            nSpeed = 0x7FFF;
        }
        pUnit->wAnimSpeed = nSpeed;
        return 1;
    }

    case 4:
        switch (nMode)
        {
        case 5:
            pUnit->wAnimSpeed = 0x100;
            pUnit->dwFrameCountPrecise = 0x1100;
            return 1;

        case 3:
            pUnit->wAnimSpeed = 0;
            pUnit->dwFrameCountPrecise = 0x1100;
            pUnit->dwGFXcurrentFrame = 0x1000;
            return 1;
        }
        break;

    case 3:
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pUnit->dwClassId);
        if (!pMissilesTxtRecord)
        {
            return 0;
        }

        pUnit->wAnimSpeed = UNITS_ApplyRatio_Inline(256, pMissilesTxtRecord->nAnimLen_2, 1024);
        pUnit->dwFrameCountPrecise = pMissilesTxtRecord->nAnimLen << 8;
        break;
    }
    }

    return 1;
}
