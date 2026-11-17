struct D2DynamicPathStrc;
struct D2BitBufferStrc;
struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectsTxt
{
    char unk0x000[0xD8];
    int dwFrameCnt[8];
    char unk0x0F8[0x129 - 0xF8];
    unsigned char nStart[8];
};

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
    char unk0x18[0x20 - 0x18];
    D2SeedStrc pSeed;
    char unk0x28[0x2C - 0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x44 - 0x30];
    int nFrame;
    char unk0x48[0xC8 - 0x48];
    unsigned int dwFlagEx;
    char unk0xCC[0xD4 - 0xCC];
    unsigned int dwTickCount;
};

struct D2ShrinesTxt
{
    unsigned char nCode;
};

struct D2ShrineHandlerStrc
{
    void (__fastcall* pfnInit)(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxt);
    void (__fastcall* pfnOperate)(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ShrinesTxt* pShrinesTxt);
    int f_8;
    int f_C;
    int nSoundId;
};

struct D2PlayerDataStrc
{
    char szName[16];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern "C" char* __cdecl _strrev(char* szString);                                                           // 0x00687860

extern D2ShrineHandlerStrc gShrineHandlers_006DA8C0[];                                                      // 0x006DA8C0
extern int gnShrineHandlerCount_0072779C;                                                                   // 0x0072779C
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00465F00_RemoveClientUnit(int nUnitId, int nUnitType);                                 // 0x00465F00
void __fastcall sub_00481030(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);                // 0x00481030
void __cdecl sub_004A30A0_TriggerOnceD3();                                                                  // 0x004A30A0
void __cdecl sub_004A30C0_TriggerOnce219();                                                                 // 0x004A30C0
D2BitBufferStrc* __cdecl sub_004B32D0();                                                           // 0x004B32D0
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500
int __fastcall sub_004BC5E0_UpdateEnvObject(D2UnitStrc* pUnit, int bNoRefresh);                             // 0x004BC5E0
void __fastcall sub_004CB460(D2UnitStrc* pUnit);                                                            // 0x004CB460
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);                                                    // 0x00624390
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

static __forceinline unsigned int SEED_RollRandomNumberLoFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

#define SEED_STEP_HIFIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

// 0x004BD090
void __fastcall sub_004BD090_OperateReverseNameShrine(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ShrinesTxt* pShrinesTxt)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        strncpy(pPlayerData->szName, _strrev(pPlayerData->szName), 16);
    }
}

// 0x004BD4A0
void __fastcall sub_004BD4A0_InitShrineOverlays(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxt)
{
    D2_ASSERT(pShrinesTxt->nCode < gnShrineHandlerCount_0072779C, 0x337);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->nCode];
    if (pHandler->f_8 != -1)
    {
        sub_0046F0C0(pUnit, 0, pHandler->f_8);
        if (!pUnit || !pUnit->dwAnimMode)
        {
            sub_00470390(pUnit, pHandler->f_8, 3, 0, 0, 0, 0, 0);
        }
    }

    if (pHandler->f_C != -1)
    {
        sub_0046F0C0(pUnit, 0, pHandler->f_C);
        if (!pUnit || !pUnit->dwAnimMode)
        {
            sub_00470390(pUnit, pHandler->f_C, 3, 0, 0, 0, 0, 0);
        }
    }
}

// 0x004BD730
char __fastcall sub_004BD730_AnimCycle(D2UnitStrc* pUnit)
{
    if (!pUnit->dwFlagEx)
    {
        pUnit->dwTickCount = SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwFlagEx = 1;
    }

    if (!(pUnit->dwTickCount & 0x3F) && pUnit->dwAnimMode != 1)
    {
        pUnit->dwAnimMode = 1;
        sub_00624390_AnimInit(pUnit);
    }

    ++pUnit->dwTickCount;

    if (pUnit->dwAnimMode == 2)
    {
        pUnit->dwTickCount += SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwAnimMode = 0;
        sub_00624390_AnimInit(pUnit);
    }

    return 1;
}

// 0x004BD7C0
char __fastcall sub_004BD7C0_AnimCycleUpdate(D2UnitStrc* pUnit)
{
    if (!pUnit->dwFlagEx)
    {
        pUnit->dwTickCount = SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwFlagEx = 1;
    }

    if (!(pUnit->dwTickCount & 0x3F) && pUnit->dwAnimMode != 1)
    {
        pUnit->dwAnimMode = 1;
        sub_00624390_AnimInit(pUnit);
    }

    ++pUnit->dwTickCount;

    if (pUnit->dwAnimMode == 2)
    {
        pUnit->dwTickCount += SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwAnimMode = 0;
        sub_00624390_AnimInit(pUnit);
    }

    sub_004CB460(pUnit);
    return 1;
}

// 0x004BD860
char __fastcall sub_004BD860_TimedSpecial(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 7000, 12000) + dwTick;
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[5];
        UNITS_ChangeAnimMode(pUnit, 3);
        sub_00470610_Refresh(pUnit, 0);
    }

    if (pUnit->dwAnimMode == 3 && pUnit->nFrame >= pUnit->pObjectData->pObjectTxt->dwFrameCnt[3] - 0x100)
    {
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_004CB460(pUnit);
    return 0;
}

// 0x004BD900
char __fastcall sub_004BD900_TimedSpecialRandom(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount < dwTick)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(pSeed, 23000, 33000) + dwTick;
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[5];
        unsigned int nRoll;
        SEED_STEP_HIFIRST(pSeed, nRoll);
        if (nRoll & 1)
        {
            UNITS_ChangeAnimMode(pUnit, 3);
        }
        else
        {
            UNITS_ChangeAnimMode(pUnit, 4);
        }
        sub_00470610_Refresh(pUnit, 0);
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if ((nMode == 3 || nMode == 4) && pUnit->nFrame >= pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode] - 0x100)
    {
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_004CB460(pUnit);
    return 0;
}

// 0x004BD9C0
char __fastcall sub_004BD9C0_TimedSpecialExact(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 20000, 30000) + dwTick;
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[5];
        UNITS_ChangeAnimMode(pUnit, 3);
        sub_00470610_Refresh(pUnit, 0);
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode >= 3 && pUnit->nFrame == pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode] - 0x100)
    {
        pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_004CB460(pUnit);
    return 0;
}

// 0x004BDA60
char __fastcall sub_004BDA60_TimedOperate(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode == 0)
    {
        if (pUnit->dwTickCount < dwTick)
        {
            pUnit->dwTickCount = dwTick + 10000;
            pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[1];
            UNITS_ChangeAnimMode(pUnit, 1);
            sub_00470610_Refresh(pUnit, 0);
        }
    }
    else if (nMode >= 1 && pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 4500, 7500) + dwTick;
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    return 1;
}

// 0x004BDB00
char __fastcall sub_004BDB00_TimedOperateShort(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode == 0)
    {
        if (pUnit->dwTickCount < dwTick)
        {
            pUnit->dwTickCount = dwTick + 3000;
            pUnit->nFrame = pUnit->pObjectData->pObjectTxt->nStart[1];
            UNITS_ChangeAnimMode(pUnit, 1);
            sub_00470610_Refresh(pUnit, 0);
        }
    }
    else if (nMode >= 1 && pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 2500, 7500) + dwTick;
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    return 1;
}

// 0x004BDBA0
char __fastcall sub_004BDBA0_RemoveWhenFar(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount)
    {
        if (dwTick - pUnit->dwTickCount <= 1000)
        {
            return 1;
        }

        if (sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0()) > 25)
        {
            sub_00465F00_RemoveClientUnit(pUnit->dwUnitId, 2);
            return 0;
        }
    }

    pUnit->dwTickCount = dwTick;
    return 1;
}

// 0x004BDBF0
char __fastcall sub_004BDBF0_TriggerOnce219(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_004A30C0_TriggerOnce219();
    }

    return 1;
}

// 0x004BDC10
char __fastcall sub_004BDC10_QuestObject(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->dwAnimMode)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && QUESTRECORD_GetQuestState(sub_004B32D0(), 0x27, 0) && !QUESTRECORD_GetQuestState(sub_004B32D0(), 0x27, 4)
            && sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0()) < 25)
        {
            if (pPlayer->pDynamicPath)
            {
                D2Common_10153(pPlayer->pDynamicPath);
            }

            sub_00481030(0x13, pPlayer, 2, pUnit->dwUnitId, 0);
            UNITS_ChangeAnimMode(pUnit, 2);
            sub_00470610_Refresh(pUnit, 0);
        }
    }

    return 1;
}

// 0x004BDCA0
char __fastcall sub_004BDCA0_TriggerOnceD3(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_004A30A0_TriggerOnceD3();
    }

    return 1;
}

// 0x004BDCC0
char __fastcall sub_004BDCC0_UpdateEnvObject(D2UnitStrc* pUnit)
{
    if (GetTickCount() > pUnit->dwTickCount)
    {
        sub_004BC5E0_UpdateEnvObject(pUnit, 0);
        pUnit->dwTickCount = GetTickCount() + 500;
    }

    return 1;
}
