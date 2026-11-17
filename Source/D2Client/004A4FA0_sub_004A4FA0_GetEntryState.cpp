#pragma pack(push, 2)
struct D2ClientListEntryStrc
{
    int nKey;
    unsigned char unk0x04[6];
};
#pragma pack(pop)

extern int gnGlobal_007C02B0;                                                                               // 0x007C02B0
extern int gnGlobal_007C02B8;                                                                               // 0x007C02B8
extern int gnGlobal_007246D4;                                                                               // 0x007246D4
extern D2ClientListEntryStrc* gpListEntries_00724264;                                                       // 0x00724264

int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90

// 0x004A4FA0
static int sub_004A4FA0_GetEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnGlobal_007C02B0 && (gnGlobal_007C02B8 || nFlag == gnGlobal_007246D4))
    {
        return 3;
    }

    if (!sub_00469D90(gpListEntries_00724264[nIndex].nKey, 1) && !sub_00469D90(gpListEntries_00724264[nIndex].nKey, 0))
    {
        return 1;
    }

    return sub_00469D90(gpListEntries_00724264[nIndex].nKey, nFlag) ? 4 : 5;
}

int __stdcall sub_B05_Sink(int nA, int nB);

int sub_B05_Emit_004A4FA0(int* pIndex)
{
    int nA = sub_004A4FA0_GetEntryState(*pIndex, 1);
    int nB = sub_004A4FA0_GetEntryState(*pIndex, 0);
    return sub_B05_Sink(nA, nB);
}
