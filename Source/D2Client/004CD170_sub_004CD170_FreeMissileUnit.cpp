extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

struct D2DynamicPathStrc;
struct D2DrlgActStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2GfxMotionStrc
{
    unsigned int dwFlags;
};

struct D2GfxEntryStrc
{
    unsigned char nValue;
    unsigned char unk0x01;
};

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[20];
};

extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634
extern unsigned int gdwFadeTick_007C89CC;                                                                   // 0x007C89CC

void __stdcall MISSTREAM_FreeMissileStream(D2UnitStrc* pMissile);                                           // 0x00663D90
void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile);                                               // 0x0064A150
void __stdcall sub_004DA080_FreeGfxMotion(D2UnitStrc* pUnit);                                               // 0x004DA080
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10
void __stdcall D2Common_10228(D2UnitStrc* pUnit);                                                           // 0x00649F50
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370
void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath);                       // 0x00648460
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __fastcall sub_004CED60(D2UnitStrc* pMissile, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CED60
void __fastcall sub_004D85C0_SkillSeqDo0(D2UnitStrc* pUnit, int nArg);                                      // 0x004D85C0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10

static __forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetXPosition(pUnit->pDynamicPath);
        return 0;
    }
}

static __forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetYPosition(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x004CD170
void __fastcall sub_004CD170_FreeMissileUnit(D2UnitStrc* pMissile)
{
    MISSTREAM_FreeMissileStream(pMissile);
    MISSILE_FreeMissileData(pMissile);
    sub_004DA080_FreeGfxMotion(pMissile);
    sub_0046EC10_FreeGfxData(pMissile);
    if (gpAct_007A0634)
    {
        D2Common_10228(pMissile);
        UNITROOM_RemoveUnitFromRoom(pMissile);
    }
    PATH_FreeDynamicPath(0, pMissile->pDynamicPath);
    pMissile->pDynamicPath = 0;
}

// 0x004CEF50
void __fastcall sub_004CEF50_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult)
{
    sub_004CED60(pMissile, CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), nCount, nMissile, nSkill, nLevel, nPerStep, nMult);
}

// 0x004D8650
void __fastcall sub_004D8650(D2UnitStrc* pUnit, int nArg)
{
    sub_004D85C0_SkillSeqDo0(pUnit, nArg);
}

// 0x004DA340
void __fastcall sub_004DA340(D2UnitStrc* pMissile)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pMissile);
    if (pMotion)
        pMotion->dwFlags &= ~2;
}

// 0x004DA6E0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bSet)
            pMotion->dwFlags |= 0x20;
        else
            pMotion->dwFlags &= ~0x20;
    }
}

// 0x004DB1A0
unsigned char __fastcall sub_004DB1A0(D2UnitStrc* pUnit, int nIndex)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
        return 0;
    return pGfxData->tEntries[nIndex].nValue;
}

// 0x004DBFE0
void __cdecl sub_004DBFE0_StopSkill()
{
    gdwFadeTick_007C89CC = GetTickCount() + 500;
}
