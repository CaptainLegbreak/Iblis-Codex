struct D2GameStrc;
struct D2StatListExStrc;

struct D2UnitStrc
{
    char unk0x00[0x5C];
    D2StatListExStrc* pStatListEx;
};

struct D2StatStrc
{
    union
    {
        struct
        {
            unsigned short nLayer;
            unsigned short nStat;
        };
        int nPackedValue;
    };
    int nValue;
};

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x02];
    unsigned char nCsvBits;
    unsigned char nCsvParam;
    char unk0x0C[0x144 - 0x0C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

#define ITEMSTATCOSTFLAGINDEX_CSVSIGNED 13
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                   // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0
int __stdcall STATLIST_GetBaseStatsData(D2StatListExStrc* pStatListEx, D2StatStrc* pStatBuffer, int nBufferSize); // 0x00625C90

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x00569540
int __fastcall PLRSAVE2_WritePlayerStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd)
{
    D2StatStrc aStatBuffer[512];
    D2BitBufferStrc bitBuffer;

    unsigned char* pSection = *ppSection;
    unsigned char* pData = pSection + 2;
    if (pData > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pSection = 0x6667;
    BITMANIP_Initialize(&bitBuffer, pData, pEnd - pData);

    if (pPlayer->pStatListEx)
    {
        const int nStats = STATLIST_GetBaseStatsData(pPlayer->pStatListEx, aStatBuffer, 512);
        if (nStats > 0)
        {
            for (int i = 0; i < nStats; ++i)
            {
                const int nStatId = (unsigned int)aStatBuffer[i].nPackedValue >> 16;
                const unsigned short nLayer = aStatBuffer[i].nLayer;
                int nValue = aStatBuffer[i].nValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
                if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nCsvBits > 0)
                {
                    if (pItemStatCostTxtRecord->nCsvBits < 32)
                    {
                        if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_CSVSIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_CSVSIGNED & 7])
                        {
                            const int nMin = -1 << (pItemStatCostTxtRecord->nCsvBits - 1);
                            nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pItemStatCostTxtRecord->nCsvBits - 1)) - 1);
                        }
                        else
                        {
                            nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pItemStatCostTxtRecord->nCsvBits) - 1);
                        }
                    }

                    BITMANIP_Write(&bitBuffer, nStatId, 9);
                    if (pItemStatCostTxtRecord->nCsvParam)
                    {
                        BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nCsvParam);
                    }
                    BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nCsvBits);
                }
            }
        }
    }

    BITMANIP_Write(&bitBuffer, 0x1FF, 9);
    *ppSection = &pData[BITMANIP_GetSize(&bitBuffer)];
    return 0;
}
