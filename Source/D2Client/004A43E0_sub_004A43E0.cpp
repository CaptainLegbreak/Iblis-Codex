#pragma pack(push, 2)
struct D2ClientListEntryStrc
{
    int nKey;
    unsigned short nString;
    unsigned char unk0x06[4];
};
#pragma pack(pop)

int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0

extern D2ClientListEntryStrc* gpListEntries_00724264;                                                       // 0x00724264
extern D2ClientListEntryStrc gaEntries_00724268[];                                                          // 0x00724268
extern D2ClientListEntryStrc gaEntries_00724468[];                                                          // 0x00724468
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
int gnEntryCount_007C0274;                                                                                  // 0x007C0274
int gnThumbScale_007C0278;                                                                                  // 0x007C0278
int gnThumbRange_007C027C;                                                                                  // 0x007C027C

static __forceinline int sub_KEYCFG_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_KEYCFG_Rows()
{
    return ((sub_KEYCFG_ListTop() + 0x16C) - (sub_KEYCFG_ListTop() + 0x28)) / 0x12;
}

static __forceinline int sub_KEYCFG_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static __forceinline int sub_KEYCFG_TrackCels()
{
    return (sub_KEYCFG_Rows() * 0x12 - 0x4E) / 0x0C + 1;
}

// 0x004A43E0
void __cdecl sub_004A43E0()
{
    if (sub_0044DCC0())
    {
        gpListEntries_00724264 = gaEntries_00724468;
        gnEntryCount_007C0274 = 62;
        gnThumbScale_007C0278 = sub_KEYCFG_TrackCels() * sub_KEYCFG_VisibleLines() / gnEntryCount_007C0274;
        gnThumbRange_007C027C = gnEntryCount_007C0274 - sub_KEYCFG_VisibleLines();
    }
    else
    {
        gpListEntries_00724264 = gaEntries_00724268;
        gnEntryCount_007C0274 = 51;
        gnThumbScale_007C0278 = sub_KEYCFG_TrackCels() * sub_KEYCFG_VisibleLines() / gnEntryCount_007C0274;
        gnThumbRange_007C027C = gnEntryCount_007C0274 - sub_KEYCFG_VisibleLines();
    }
}

#include "gen/data/Source/D2Client/004A43E0_sub_004A43E0.inc"
