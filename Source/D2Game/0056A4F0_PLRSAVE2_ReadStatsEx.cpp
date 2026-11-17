struct D2GameStrc;
struct D2UnitStrc;
struct D2ClientStrc;

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

#define PLRSAVE2ERROR_BAD_STATS 0x12
#define PLRSAVE2ERROR_BAD_SKILLS 0x13
#define ITEMSTATCOSTFLAGINDEX_CSVSIGNED 13

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits);                                     // 0x00411030
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer);                                                   // 0x00410E90
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient);                                                   // 0x005385F0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0
void __fastcall sub_6FD14C30(D2UnitStrc* pUnit);                                                            // 0x0056DE40
void __fastcall sub_0053C5D0(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053C5D0

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0056A4F0
int __fastcall PLRSAVE2_ReadStatsEx(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pData = *ppSection;
    if (&pData[2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6667)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    D2BitBufferStrc bitBuffer;
    BITMANIP_Initialize(&bitBuffer, pData, pEnd - pData);

    for (int nStatId = sub_00411020_ReadBits(&bitBuffer, 9); nStatId < 511; nStatId = sub_00411020_ReadBits(&bitBuffer, 9))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (!pItemStatCostTxtRecord || pItemStatCostTxtRecord->nCsvBits <= 0)
        {
            return PLRSAVE2ERROR_BAD_STATS;
        }

        int nLayer = 0;
        if (pItemStatCostTxtRecord->nCsvParam > 0)
        {
            nLayer = (unsigned short)BITMANIP_ReadSigned(&bitBuffer, pItemStatCostTxtRecord->nCsvParam);
        }

        int nValue = 0;
        if (pItemStatCostTxtRecord->nCsvBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_CSVSIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_CSVSIGNED & 7])
        {
            nValue = BITMANIP_ReadSigned(&bitBuffer, pItemStatCostTxtRecord->nCsvBits);
        }
        else
        {
            nValue = sub_00411020_ReadBits(&bitBuffer, pItemStatCostTxtRecord->nCsvBits);
        }

        STATLIST_SetUnitStat(pUnit, nStatId, nValue, nLayer);
    }

    *ppSection = &pData[BITMANIP_GetSize(&bitBuffer)];
    return 0;
}

// 0x0056A710
int __fastcall PLRSAVE2_ReadSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nSkills)
{
    unsigned char* pData = *ppSection;
    if (&pData[2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6669)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 1773);
    if (!pClient)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    const int nClassId = CLIENTS_GetClassId(pClient);
    for (int i = 0; i < nSkills; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        if (i > SKILLS_GetPlayerSkillCount(nClassId))
        {
            break;
        }

        if (pData[i])
        {
            D2GAME_SetSkills_6FD14C60(pPlayer, nSkillId, pData[i], 1);
        }
    }

    sub_0053C5D0(pClient, pPlayer);
    sub_6FD14C30(pPlayer);

    *ppSection = &pData[nSkills];
    return 0;
}
