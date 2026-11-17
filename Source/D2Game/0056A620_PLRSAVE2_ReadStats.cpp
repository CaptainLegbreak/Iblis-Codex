struct D2GameStrc;
struct D2UnitStrc;

#define PLRSAVE2ERROR_BAD_STATS 0x12

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
int __stdcall sub_00411170_SumByteTable(unsigned char* pData, int nSize);                                   // 0x00411170
int __fastcall PLRSAVE2_ReadStatsEx(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A4F0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

// 0x0056A620
int __fastcall PLRSAVE2_ReadStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nStats)
{
    if (nVersion > 0x5E)
    {
        return PLRSAVE2_ReadStatsEx(pGame, pUnit, ppSection, pEnd, nVersion);
    }

    const int nHeaderSectionLength = (nStats + 7) / 8;
    unsigned char* pData = *ppSection;
    if (&pData[nHeaderSectionLength + 2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6667)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    unsigned char* pHeaderData = pData;
    pData += nHeaderSectionLength;
    if (&pData[4 * sub_00411170_SumByteTable(pHeaderData, nHeaderSectionLength)] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    int nCounter = 0;
    for (int i = 0; i < nStats; ++i)
    {
        if (pHeaderData[i >> 3] & gdwBitMasks[i & 7])
        {
            const int nValue = *(int*)&pData[4 * nCounter];
            ++nCounter;
            STATLIST_SetUnitStat(pUnit, i, nValue, 0);
        }
        else
        {
            STATLIST_SetUnitStat(pUnit, i, 0, 0);
        }
    }

    *ppSection = &pData[4 * nCounter];
    return 0;
}
