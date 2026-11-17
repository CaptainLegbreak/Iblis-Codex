struct D2MonStatsTxt
{
    char unk0x000[0x00C];
    unsigned char nMonStatsFlags[4];
    char unk0x010[0x0A0];
    short nMinHP[3];
    short nMaxHP[3];
    short nAC[3];
    short nA1TH[3];
    short nA2TH[3];
    short nS1TH[3];
    short nExp[3];
    short nA1MinD[3];
    short nA1MaxD[3];
    short nA2MinD[3];
    short nA2MaxD[3];
    short nS1MinD[3];
    short nS1MaxD[3];
    char unk0x0FE[0x010];
    short nElMinD[3][3];
    short nElMaxD[3][3];
    short nElDur[3][3];
    char unk0x144[0x064];
};

struct D2MonLvlTxt
{
    unsigned int dwAC[2][3];
    unsigned int dwTH[2][3];
    unsigned int dwHP[2][3];
    unsigned int dwDM[2][3];
    unsigned int dwXP[2][3];
};

struct D2MonStatsInitStrc
{
    int nMinHP;
    int nMaxHP;
    int nAC;
    int nTH;
    int nExp;
    int nA1MinD;
    int nA1MaxD;
    int nA2MinD;
    int nA2MaxD;
    int nS1MinD;
    int nS1MaxD;
    int nElMinD;
    int nElMaxD;
    int nElDur;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0EC];
    D2MonLvlTxt* pMonLvlTxt;
    int nMonLvlTxtRecordCount;
};

#define MONSTATSFLAGINDEX_NORATIO 2

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

__forceinline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

__forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x006538A0
int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord(nLevel < sgptDataTables->nMonLvlTxtRecordCount - 1 ? nLevel : sgptDataTables->nMonLvlTxtRecordCount - 1);
    if (!pMonLvlTxtRecord)
    {
        return 0;
    }

    nDifficulty = nDifficulty > 0 ? nDifficulty : 0;
    if (nDifficulty >= 2)
    {
        nDifficulty = 2;
    }

    const int bExpansion = nGameType != 0;

    if (nFlags & 1)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nMinHP = pMonStatsTxtRecord->nMinHP[nDifficulty];
            pMonStatsInit->nMaxHP = pMonStatsTxtRecord->nMaxHP[nDifficulty];
        }
        else
        {
            pMonStatsInit->nMinHP = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwHP[bExpansion][nDifficulty], pMonStatsTxtRecord->nMinHP[nDifficulty], 0x64);
            pMonStatsInit->nMaxHP = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwHP[bExpansion][nDifficulty], pMonStatsTxtRecord->nMaxHP[nDifficulty], 0x64);
        }
    }

    if (nFlags & 2)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nAC = pMonStatsTxtRecord->nAC[nDifficulty];
        }
        else
        {
            pMonStatsInit->nAC = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwAC[bExpansion][nDifficulty], pMonStatsTxtRecord->nAC[nDifficulty], 0x64);
        }
    }

    if (nFlags & 4)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nExp = pMonStatsTxtRecord->nExp[nDifficulty];
        }
        else
        {
            pMonStatsInit->nExp = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwXP[bExpansion][nDifficulty], pMonStatsTxtRecord->nExp[nDifficulty], 0x64);
        }
    }

    if (nFlags & 8)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nA1TH[nDifficulty];
            pMonStatsInit->nA1MinD = pMonStatsTxtRecord->nA1MinD[nDifficulty];
            pMonStatsInit->nA1MaxD = pMonStatsTxtRecord->nA1MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1TH[nDifficulty], 0x64);
            pMonStatsInit->nA1MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1MinD[nDifficulty], 0x64);
            pMonStatsInit->nA1MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA1MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x10)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nA2TH[nDifficulty];
            pMonStatsInit->nA2MinD = pMonStatsTxtRecord->nA2MinD[nDifficulty];
            pMonStatsInit->nA2MaxD = pMonStatsTxtRecord->nA2MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2TH[nDifficulty], 0x64);
            pMonStatsInit->nA2MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2MinD[nDifficulty], 0x64);
            pMonStatsInit->nA2MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nA2MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x20)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nTH = pMonStatsTxtRecord->nS1TH[nDifficulty];
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nS1MinD[nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nS1MaxD[nDifficulty];
        }
        else
        {
            pMonStatsInit->nTH = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwTH[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1TH[nDifficulty], 0x64);
            pMonStatsInit->nS1MinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1MinD[nDifficulty], 0x64);
            pMonStatsInit->nS1MaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nS1MaxD[nDifficulty], 0x64);
        }
    }

    if (nFlags & 0x40)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[0][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[0][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[0][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[0][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[0][nDifficulty];
    }

    if (nFlags & 0x80)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[1][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[1][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[1][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[1][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[1][nDifficulty];
    }

    if (nFlags & 0x100)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7])
        {
            pMonStatsInit->nS1MinD = pMonStatsTxtRecord->nElMinD[2][nDifficulty];
            pMonStatsInit->nS1MaxD = pMonStatsTxtRecord->nElMaxD[2][nDifficulty];
        }
        else
        {
            pMonStatsInit->nElMinD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMinD[2][nDifficulty], 0x64);
            pMonStatsInit->nElMaxD = DATATBLS_ApplyRatio(pMonLvlTxtRecord->dwDM[bExpansion][nDifficulty], pMonStatsTxtRecord->nElMaxD[2][nDifficulty], 0x64);
        }

        pMonStatsInit->nElDur = pMonStatsTxtRecord->nElDur[2][nDifficulty];
    }

    return 1;
}

#include "gen/data/Source/D2Common/006538A0_DATATBLS_CalculateMonsterStatsByLevel.inc"
