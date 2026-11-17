struct D2DataTablesStrc
{
    char unk0x00[0xAC];
    int nPropertiesTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define IM_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0065C5D0
int __cdecl sub_0065C5D0()
{
    return sgptDataTables->nPropertiesTxtRecordCount;
}

// 0x0065C7A0
void __stdcall D2Common_10844_ITEMMODS_First(int nDataBits, int* pLayer, int* pValue)
{
    *pLayer = nDataBits & 511;
    *pValue = (nDataBits >> 9) & 31;
}

// 0x0065C7D0
void __stdcall D2Common_10846(int nDataBits, int* a2, int* a3, int* a4, int* a5)
{
    *a2 = nDataBits & 511;
    *a3 = (nDataBits >> 9) & 31;
    *a4 = (nDataBits >> 14) & 255;
    *a5 = (nDataBits >> 22) & 255;
}

// 0x0065CA30
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax)
{
    int nTempItemModPeriodOfDay = nAmount & 3;
    int nTempItemModMin = ((nAmount >> 2) & 0x3FF) - 0x100;
    int nTempItemModMax = ((nAmount >> 12) & 0x3FF) - 0x100;

    if (pItemModPeriodOfDay)
    {
        *pItemModPeriodOfDay = nTempItemModPeriodOfDay;
    }

    if (pItemModMin)
    {
        *pItemModMin = nTempItemModMin;
    }

    if (pItemModMax)
    {
        *pItemModMax = nTempItemModMax;
    }

    int nTimeDiff = nBaseTime - (nTempItemModPeriodOfDay * 90);
    if (nTimeDiff < 0)
    {
        nTimeDiff = -nTimeDiff;
    }

    int nRoundedTimeDiff = ((nTimeDiff + 7) / 15) * 15;

    int nClampedTimeDiff = nRoundedTimeDiff > 0 ? nRoundedTimeDiff : 0;
    if (nClampedTimeDiff >= (360 - 1))
    {
        nClampedTimeDiff = (360 - 1);
    }

    if (nClampedTimeDiff > 180)
    {
        nClampedTimeDiff = 360 - nClampedTimeDiff;
    }

    return nTempItemModMax - (((nTempItemModMax - nTempItemModMin) * nClampedTimeDiff) / 180);
}

// 0x0065CB00
int __stdcall D2Common_10849(int a1, int a2)
{
    return a1 + (a2 << 9);
}

// 0x0065CB10
void __stdcall D2Common_10845(int nDataBits, int* a2, int* a3, int* a4)
{
    *a2 = nDataBits & 511;
    *a3 = (nDataBits >> 9) & 31;
    *a4 = (nDataBits >> 14) & 127;
}

// 0x0065CB40
int __stdcall D2Common_10850(int a1, int a2, int a3)
{
    return a1 + ((a2 + 32 * a3) << 9);
}

// 0x0065CB60
void __stdcall D2Common_10848(int nDataBits, int* pClass, int* pTab, int* pLevel)
{
    IM_ASSERT(pClass && pTab && pLevel, 426);

    int nClassTab = nDataBits & 31;
    *pClass = nClassTab / 3;
    *pTab = nClassTab % 3;
    *pLevel = (nDataBits >> 5) & 31;
}

// 0x0065CBD0
int __stdcall D2Common_10851(int a1, int a2, int a3)
{
    return a2 + 3 * a1 + 32 * a3;
}
