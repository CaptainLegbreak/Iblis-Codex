struct D2ItemRatioTxt
{
    int dwUnique;
    int dwUniqueDivisor;
    int dwUniqueMin;
    int dwRare;
    int dwRareDivisor;
    int dwRareMin;
    int dwSet;
    int dwSetDivisor;
    int dwSetMin;
    int dwMagic;
    int dwMagicDivisor;
    int dwMagicMin;
    int dwHiQuality;
    int dwHiQualityDivisor;
    int dwNormal;
    int dwNormalDivisor;
    unsigned short wVersion;
    unsigned char nUber;
    unsigned char nClassSpecific;
};
struct D2ItemRatioDataTbl { int nItemRatioTxtRecordCount; D2ItemRatioTxt* pItemRatioTxt; };

extern D2ItemRatioDataTbl gItemRatioDataTables;                                                             // 0x0096CC48
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __stdcall ITEMS_IsClassValidByItemId(int nItemId);                                                      // 0x00629F70
int __stdcall ITEMS_GetQuestFromItemId(int nItemId);                                                        // 0x0062B4D0

// 0x00637910
D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int nItemId, unsigned char nDifficulty, unsigned short wVersion)
{
    int nId = -1;
    int nLastVersion = -1;

    const int nClass = ITEMS_IsClassValidByItemId(nItemId);
    const int nQuest = ITEMS_GetQuestFromItemId(nItemId);

    D2_ASSERT(wVersion == 0 || wVersion == 100, 1565);

    for (int i = 0; i < gItemRatioDataTables.nItemRatioTxtRecordCount; ++i)
    {
        if (nClass == gItemRatioDataTables.pItemRatioTxt[i].nClassSpecific
            && nQuest == gItemRatioDataTables.pItemRatioTxt[i].nUber
            && gItemRatioDataTables.pItemRatioTxt[i].wVersion <= wVersion
            && gItemRatioDataTables.pItemRatioTxt[i].wVersion >= nLastVersion)
        {
            nLastVersion = gItemRatioDataTables.pItemRatioTxt[i].wVersion;
            nId = i;
        }
    }

    if (nId < 0)
    {
        return 0;
    }

    return &gItemRatioDataTables.pItemRatioTxt[nId];
}
