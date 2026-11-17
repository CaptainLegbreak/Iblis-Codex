struct D2DynamicPathStrc;
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

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nXPos;
    int nYPos;
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
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x44 - 0x30];
    int nFrame;
    char unk0x48[0xC8 - 0x48];
    unsigned int dwFlagEx;
    char unk0xCC[0xD4 - 0xCC];
    unsigned int dwTickCount;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
char __cdecl sub_004A3110_GetFlag025F();                                                                    // 0x004A3110
char __cdecl sub_004A3120();                                                                                // 0x004A3120
void __fastcall sub_004A3150(int nX, int nY);                                                               // 0x004A3150
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);                                                    // 0x00624390
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

#define SEED_STEP_HIFIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x004BDCF0
char __fastcall sub_004BDCF0_TimedOverlay(D2UnitStrc* pUnit)
{
    if (GetTickCount() > pUnit->dwTickCount)
    {
        if (!pUnit->dwAnimMode)
        {
            sub_00470390(pUnit, 0x48, 3, 0, 0, 0, 0, 0);
            pUnit->dwTickCount = GetTickCount() + 500;
        }
        else
        {
            sub_0046F0C0(pUnit, 0, 0x48);
            pUnit->dwTickCount = GetTickCount() + 500;
        }
    }
    return 1;
}

// 0x004BDD50
char __fastcall sub_004BDD50_RandomSound(D2UnitStrc* pUnit)
{
    if (GetTickCount() > pUnit->dwTickCount)
    {
        unsigned int nRoll;
        SEED_STEP_HIFIRST(&pUnit->pSeed, nRoll);
        if (nRoll % 100 < 10)
        {
            sub_004B9A00(0x9C9, pUnit, 0, 0, 0);
        }
        SEED_STEP_HIFIRST(&pUnit->pSeed, nRoll);
        pUnit->dwTickCount = GetTickCount() + nRoll % 60 * 1000;
    }
    return 1;
}

// 0x004BDE00
char __fastcall sub_004BDE00_FinishOperate(D2UnitStrc* pUnit)
{
    if (pUnit->dwAnimMode == 1 && pUnit->nFrame == pUnit->pObjectData->pObjectTxt->nStart[1] << 8)
    {
        pUnit->dwAnimMode = 2;
        pUnit->nFrame = 0;
        sub_00470610_Refresh(pUnit, 0);
        sub_00624390_AnimInit(pUnit);
    }
    return 1;
}

// 0x004BDE40
char __fastcall sub_004BDE40_ReportPosition(D2UnitStrc* pUnit)
{
    if (sub_004A3110_GetFlag025F() && !sub_004A3120())
    {
        sub_004A3150(CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit));
    }
    return 1;
}
