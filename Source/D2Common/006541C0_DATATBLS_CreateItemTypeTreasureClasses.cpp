struct D2TxtLinkStrc;

struct TableRow
{
    char unk0x00[0x1D];
    unsigned char nTreasureClass;
    unsigned char nRarity;
    char unk0x1F[0xE4 - 0x1F];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBF8];
    TableRow* pItemTypesTxt;
    int nItemTypesTxtRecordCount;
};

struct D2ItemsTxt
{
    char unk0x00[0xF6];
    unsigned short wVersion;
    char unk0xF8[0xFD - 0xF8];
    unsigned char nLevel;
    char unk0xFE[0x11E - 0xFE];
    short wType[2];
    char unk0x122[0x12A - 0x122];
    unsigned char nQuest;
    char unk0x12B[0x133 - 0x12B];
    unsigned char nSpawnable;
    char unk0x134[0x1A8 - 0x134];
};

struct D2ItemDataTbl { int nItemsTxtRecordCount; D2ItemsTxt* pItemsTxt; };

struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    short nItemId;
    char unk0x0A[2];
    unsigned char nFlags;
    char unk0x0D[0x1C - 0x0D];
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    char unk0x14[0x28 - 0x14];
    D2TCExInfoStrc* pInfo;
};

typedef char check_TableRow_size[sizeof(TableRow) == 0xE4 ? 1 : -1];
typedef char check_D2ItemsTxt_size[sizeof(D2ItemsTxt) == 0x1A8 ? 1 : -1];
typedef char check_D2TCExInfoStrc_size[sizeof(D2TCExInfoStrc) == 0x1C ? 1 : -1];
typedef char check_D2TCExShortStrc_size[sizeof(D2TCExShortStrc) == 0x2C ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2TxtLinkStrc* gpItemTypesLinker;                                                                    // 0x0096C824
extern unsigned short gwTreasureClassItemTypes;                                                             // 0x0096D4B0

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
int __stdcall FOG_GetStringFromLinkIndex(D2TxtLinkStrc* pLinker, int nIndex, char* szString);               // 0x006BD180
extern "C" TableRow* __fastcall sub_00555C90_GetTableRow(int index);                                        // 0x00555C90
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType);                                    // 0x00629A90
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables();                                                      // 0x00633590
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2TCExShortStrc* __fastcall DATATBLS_NewTreasureClassEx(const char* szTreasureClass);                       // 0x00653F90
D2TCExInfoStrc* __fastcall sub_00654080(D2TCExShortStrc* pTCExShort);                               // 0x00654080
void __fastcall DATATBLS_UpdateTreasureClassProbabilities(D2TCExShortStrc* pTCExShort, D2TCExInfoStrc* pTCExInfo, int nProbability, int bExpansion); // 0x006540C0

#define ITEMTYPES_RECORD(i) (((i) >= 0 && (i) < sgptDataTables->nItemTypesTxtRecordCount) ? &sgptDataTables->pItemTypesTxt[(i)] : 0)

// 0x006541C0
void __cdecl DATATBLS_CreateItemTypeTreasureClasses()
{
    char szName[32];
    char szCode[8];

    DATATBLS_NewTreasureClassEx(&gszEmptyAssertText);
    D2ItemDataTbl* pItemDataTables = DATATBLS_GetItemDataTables();

    for (int i = 0; i < sgptDataTables->nItemTypesTxtRecordCount; ++i)
    {
        TableRow* pItemTypesTxtRecord = ITEMTYPES_RECORD(i);
        if (!pItemTypesTxtRecord)
        {
            break;
        }

        if (pItemTypesTxtRecord->nTreasureClass)
        {
            ++gwTreasureClassItemTypes;

            int nLevel = 3;
            do
            {
                if (FOG_GetStringFromLinkIndex(gpItemTypesLinker, i, szCode))
                {
                    SStrPrintf(szName, sizeof(szName), "%s%d", szCode, nLevel);
                    D2TCExShortStrc* pTCExTxtRecord = DATATBLS_NewTreasureClassEx(szName);
                    if (pTCExTxtRecord)
                    {
                        pTCExTxtRecord->nPicks = 1;
                        pTCExTxtRecord->nGroup = 0;
                        pTCExTxtRecord->nLevel = nLevel - 3;

                        for (int j = 0; j < pItemDataTables->nItemsTxtRecordCount; ++j)
                        {
                            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(j);
                            if (pItemsTxtRecord && !pItemsTxtRecord->nQuest && pItemsTxtRecord->nSpawnable && ITEMS_CheckItemTypeIdByItemId(j, i)
                                && (i == 38 || !ITEMS_CheckItemTypeIdByItemId(j, 38))
                                && pItemsTxtRecord->nLevel > nLevel - 3 && pItemsTxtRecord->nLevel <= nLevel)
                            {
                                TableRow* pTypeRecord = sub_00555C90_GetTableRow(pItemsTxtRecord->wType[0]);
                                if (pTypeRecord)
                                {
                                    const int nProbability = pTypeRecord->nRarity > 1 ? pTypeRecord->nRarity : 1;
                                    D2TCExInfoStrc* pTCExInfo = sub_00654080(pTCExTxtRecord);
                                    pTCExInfo->nItemId = j;
                                    if (pItemsTxtRecord->wVersion >= 100)
                                    {
                                        pTCExInfo->nFlags |= 0x10;
                                    }
                                    DATATBLS_UpdateTreasureClassProbabilities(pTCExTxtRecord, pTCExInfo, nProbability, pItemsTxtRecord->wVersion >= 100);
                                }
                            }
                        }
                    }
                }
                nLevel += 3;
            }
            while (nLevel <= 96);
        }
    }
}
