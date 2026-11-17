struct D2SeedStrc;

struct D2AutomapRecordStrc
{
    int nLevelNo;
    int nTileType;
    unsigned char nStyle;
    unsigned char nStartSequence;
    unsigned char nEndSequence;
    unsigned char pad0x0B;
    int nCel[4];
    int nCels;
};

struct D2AutomapIndexStrc
{
    int nStart;
    int nEnd;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

extern D2SeedStrc* gpAutomapSeed_00744504;                                                                  // 0x00744504
extern D2AutomapIndexStrc gAutomapIndex_0096C8D0[];                                                         // 0x0096C8D0
D2AutomapRecordStrc* gpAutomapRecords_0096CA28;                                                             // 0x0096CA28

// 0x0061FFF0
int __fastcall sub_0061FFF0_GetAutomapCel(int nLevelNo, int nTileType, int nStyle, int nSequence)
{
    if (!nLevelNo)
        return -1;

    int nStart = gAutomapIndex_0096C8D0[nLevelNo].nStart;
    int nEnd = gAutomapIndex_0096C8D0[nLevelNo].nEnd;
    if (nStart == -1)
        return -1;

    D2_ASSERT(gAutomapIndex_0096C8D0[nLevelNo].nEnd != -1, 0x53B);

    for (int i = nStart; i < nEnd; ++i)
    {
        if (gpAutomapRecords_0096CA28[i].nLevelNo == nLevelNo && gpAutomapRecords_0096CA28[i].nTileType == nTileType
            && (gpAutomapRecords_0096CA28[i].nStyle == 0xFF || gpAutomapRecords_0096CA28[i].nStyle == nStyle)
            && (gpAutomapRecords_0096CA28[i].nStartSequence == 0xFF
                || (gpAutomapRecords_0096CA28[i].nStartSequence <= nSequence && gpAutomapRecords_0096CA28[i].nEndSequence >= nSequence)))
        {
            D2AutomapRecordStrc* pRecords = gpAutomapRecords_0096CA28;
            return pRecords[i].nCel[ITEMS_RollLimitedRandomNumber(gpAutomapSeed_00744504, gpAutomapRecords_0096CA28[i].nCels)];
        }
    }
    return -1;
}
