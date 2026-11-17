#include "D2Client.h"

#define UNIT_MONSTER 1
#define FIELD_OFFSET(T,F) ((unsigned long)&(((T*)0)->F))
struct D2SeedStrc;
struct D2MonsterDataStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct D2MissilesTxt;
struct RecordView;
struct PayloadView;
struct UnitView;
struct TablesView;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    char pad0x00[0x16];
    unsigned short nTypeFlag;
    int nSpawnCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    unsigned char unk_30[0x1E];
    unsigned char nActionFrame;
    unsigned char unk_4F[0x1];
};
void __fastcall sub_0046F170_RemoveOverlays(D2UnitStrc* pUnit); // 0x0046F170
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount); // 0x0046C320

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    int nXPos;
    int nYPos;
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
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void(__fastcall* pInitFunc)(D2UnitStrc* pMissile);
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile); // 0x004E2ED0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

struct D2MissilesTxt
{
    char unk0[0x4];
    unsigned char nMissileFlags[4];
    char wCltDoFunc[0x19C];
};

struct D2DataTablesStrc
{
    char unk0[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char f_B68[0x4];
    int nMissilesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
extern "C" int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wMask); // 0x004AC7E0
D2UnitStrc* __fastcall sub_004CDBA0_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210
extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

struct RecordView
{
    char opaque[0x1a8];
};

struct PayloadView
{
    RecordView* record;
    char unused4[0x24];
    unsigned short flags28;
    char unusedAfterFlags[0x12];
    int value3c;
};

struct UnitView
{
    int type;
    int classId;
    char unusedAfterClass[0x0c];
    PayloadView* payload;
};

struct TablesView
{
    char unused0[0xa78];
    RecordView* records;
    int unusedAfterRecords;
    int count;
};

extern "C" TablesView* gTables_00744304;

typedef char RecordView_size[(sizeof(RecordView)==0x1a8)?1:-1];

typedef char PayloadView_size[(sizeof(PayloadView)==0x40)?1:-1];

typedef char PayloadView_record_offset[(FIELD_OFFSET(PayloadView,record)==0)?1:-1];

typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags28)==0x28)?1:-1];

typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value3c)==0x3c)?1:-1];

typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];

typedef char UnitView_class_offset[(FIELD_OFFSET(UnitView,classId)==0x4)?1:-1];

typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];

typedef char TablesView_size[(sizeof(TablesView)==0xa84)?1:-1];

typedef char TablesView_records_offset[(FIELD_OFFSET(TablesView,records)==0xa78)?1:-1];

typedef char TablesView_count_offset[(FIELD_OFFSET(TablesView,count)==0xa80)?1:-1];

static __forceinline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004AD5F0
void __fastcall sub_004AD5F0_StateOverlayOrSpawn(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
        return;

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
        return;

    if (pUnit->dwAnimMode == MONMODE_DEATH)
    {
        int nFrame;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
        if (nFrame == 13)
        {
            sub_0046F170_RemoveOverlays(pUnit);
            sub_00470390(pUnit, 0x34, 5, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, 0x9C, 5, 0, 0, 0, 0, 0);
            pUnit->nActionFrame = 0;
        }
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD)
    {
        if ((unsigned int)SEED_RollRandomNumberForceInline(&pUnit->pSeed) % 100 == 0 && pMonsterData->nSpawnCount < 100)
        {
            CLIENTS_GetUnitX(pUnit);
            CLIENTS_GetUnitY(pUnit);
            sub_0046C320_SpawnAroundUnit(pUnit, 0xE3, 4);
            pMonsterData->nSpawnCount += 4;
        }
    }
}

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x004AD6E0
static void __stdcall sub_004AD6E0_StateMissileBurst(int nSkillLevel, D2UnitStrc* pUnit, int nMissile)
{
    if (!nSkillLevel)
        nSkillLevel = 1;
    if (nMissile == 0xC3)
    {
        if (!pUnit || pUnit->dwUnitType != 1 || !pUnit->pMonsterData || !(pUnit->pMonsterData->nTypeFlag & 0x100))
            return;
    }
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = GetUnitPathX(pUnit);
    tMissile.nY = GetUnitPathY(pUnit);
    tMissile.nSkill = 0;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    if (nMissile != 0x141)
        tMissile.pInitFunc = sub_004E2ED0_VolleyCallback;
    int anDX[4] = { 0, 1, 0, -1 };
    int anDY[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = GetUnitPathX(pUnit);
        const int nUnitY = GetUnitPathY(pUnit);
        const int nX = anDX[i] + nUnitX;
        const int nY = anDY[i] + nUnitY;
        for (int j = 0; j < 2; ++j)
        {
            tMissile.pInitArgs = j;
            tMissile.nTargetX = nX;
            tMissile.nTargetY = nY;
            sub_004CD540_CreateMissile(&tMissile);
        }
    }
}

// 0x004AD890
void __fastcall sub_004AD890_StateBurstOnFrame(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bSet, &nFrameCount);
    if (!pUnit || pUnit->dwAnimMode != 3 || bSet != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, 0xC3);
}

// 0x004AD8E0
void __fastcall sub_004AD8E0_StateBurst(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    if (pUnit && pUnit->dwAnimMode == 3)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, 0xC3);
}

// 0x004AD920
void __fastcall sub_004AD920_StateBurstNeutral(D2UnitStrc* pUnit, int nState, int bSet)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode != 3 && pUnit->dwAnimMode)
        return;
    if (nFrameNo != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, 0xE1);
}

__forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004AD970
void __fastcall sub_004AD970_StateMissileSplit(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag || !pUnit || pUnit->dwUnitType != 3)
    {
        return;
    }

    const int nMissileId = pUnit->dwClassId;
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_004AC7E0(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pOwner);
    int nX;

    if (!pTarget)
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pPath);
        bFlag = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nX = CLIENTS_GetUnitX(pTarget);
        bFlag = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 'SEIS');
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDX = CLIENTS_GetUnitX(pOwner) - nX;
    int nDY = CLIENTS_GetUnitY(pOwner) - bFlag;

    if (nDX < 0)
    {
        nDX = -1;
    }
    else if (nDX > 0)
    {
        nDX = 1;
    }

    if (nDY < 0)
    {
        nDY = -1;
    }
    else if (nDY > 0)
    {
        nDY = 1;
    }

    switch (nMissileId)
    {
    case 63:
    case 63 + 1:
    case 63 + 2:
    case 66:
        nDY = 0;
        nDX = 0;
        break;
    }

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 0x80;
        }
    }

    sub_004CDBA0_SubmitOwnerRequest(pOwner, nMissileId, nX - nDY, bFlag + nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));
    sub_004CDBA0_SubmitOwnerRequest(pOwner, nMissileId, nX + nDY, bFlag - nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));

    if (pOwner->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~0x80;
        }
    }
}

// 0x004ADCE0
void __fastcall sub_004ADCE0_StateRequests(D2UnitStrc* pUnit)
{
    int nX = GetUnitPathX(pUnit);
    int nY = GetUnitPathY(pUnit);
    sub_004CDB40_SubmitRequest(pUnit, 0x75, nX, nY, 0, 1);
    sub_004CDB40_SubmitRequest(pUnit, 0x221, nX, nY, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004ADD80
void __fastcall sub_004ADD80_StateRequestsCallback(D2UnitStrc* pUnit, int nState, int bFlag)
{
    sub_004ADCE0_StateRequests(pUnit);
}

// 0x004AE080
extern "C" int __fastcall sub_004AE080_MaskedPayloadWord(UnitView* unit, unsigned short mask)
{
    if (unit && unit->type == 1)
    {
        PayloadView* data = unit->payload;
        if (data)
            return data->flags28 & mask;
    }
    return 0;
}

extern "C" int __fastcall sub_004AE130_GetPayloadValue(UnitView* unit)
{
    PayloadView* data = (unit && unit->type == 1) ? unit->payload : 0;
    if (!data)
        return -1;
    return data->value3c;
}
