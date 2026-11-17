struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    char unk0x10[0xB4];
    unsigned int dwFlagEx;
};

static inline int UNITS_IsServerSide(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx >> 21) & 1;
    }
    return 0;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

struct D2LightStrc
{
    int nUnitType;
    unsigned int nUnitId;
    unsigned char bServerSide;
    char unk0x09[3];
    int nMode;
    int nX;
    int nY;
    int nRadius;
    int nTargetRadius;
    int bFixed;
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    D2LightStrc* pNext;
    int bMaskReady;
    unsigned int* pMask;
};

static D2LightStrc* gpLights_007B5668;                                                                      // 0x007B5668
int gnLightsAllocated_007B566C;                                                                             // 0x007B566C
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                              // 0x006203B0
unsigned int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                              // 0x00620410

// 0x00474160
D2LightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nMode, int nRadius, unsigned char nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (nRadius > 0)
    {
        if (nRadius >= 18)
        {
            nRadius = 18;
        }

        ++gnLightsAllocated_007B566C;

        D2LightStrc* pLight = (D2LightStrc*)FOG_Alloc(sizeof(D2LightStrc), ".\\DRAW\\dLightMap.cpp", 255, 0);
        pLight->nUnitType = sub_0044BE50(pUnit);
        pLight->nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
        if (UNITS_IsServerSide(pUnit))
        {
            pLight->bServerSide = 1;
        }
        else
        {
            pLight->bServerSide = 0;
        }
        pLight->nX = (UNITS_GetPrecisionX(pUnit) >> 13) + 4;
        unsigned int nPrecisionY = UNITS_GetPrecisionY(pUnit);
        unsigned char nNativeIntensity = *(volatile unsigned char*)&nIntensity;
        int nNativeMode = *(volatile int*)&nMode;
        pLight->nY = (nPrecisionY >> 13) + 4;
        pLight->nRadius = nRadius << 3;
        pLight->nTargetRadius = nRadius << 3;
        pLight->nIntensity = nNativeIntensity;
        pLight->nRed = nRed;
        pLight->nGreen = nGreen;
        pLight->nMode = nNativeMode;
        pLight->bFixed = 0;
        pLight->nBlue = nBlue;
        pLight->pNext = gpLights_007B5668;
        pLight->bMaskReady = 0;
        if (nNativeMode == 2)
        {
            pLight->pMask = (unsigned int*)FOG_Alloc(((2 * nRadius + 1) * (2 * nRadius + 1)) << 2, ".\\DRAW\\dLightMap.cpp", 278, 0);
        }
        else
        {
            pLight->pMask = 0;
        }
        gpLights_007B5668 = pLight;
        return pLight;
    }
    return 0;
}
