#pragma pack(push, 2)
struct D2SliderButtonStrc
{
    unsigned short nStringId;
    void (__cdecl* pfnClick)();
    int unk0x06;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};
#pragma pack(pop)

unsigned char __cdecl sub_00483350();                                                                       // 0x00483350
void __cdecl sub_004A23D0_LoadPanelCels();                                                                  // 0x004A23D0
void __stdcall sub_004A3220(int nPage, int nArg);                                                           // 0x004A3220
extern unsigned char gbFlag_007BF2B0;                                                                       // 0x007BF2B0
extern int gnState_007BF298;                                                                                // 0x007BF298
extern D2Record42Strc gtRecord_007BF355;                                                                    // 0x007BF355
extern int gnPage_007C0255;                                                                                 // 0x007C0255
extern D2SliderButtonStrc gaSliderButtons_007246D8[3];                                                      // 0x007246D8
extern int gaPressed_007C0288[7];                                                                           // 0x007C0288
extern int gnPressedButton_007C02B4;                                                                        // 0x007C02B4

// 0x004A40D0
void __fastcall sub_004A40D0_SetRecord(const D2Record42Strc* pRecord)
{
    gtRecord_007BF355 = *pRecord;
    gbFlag_007BF2B0 = 0;
    if (!sub_00483350())
    {
        if (gnState_007BF298 == 2)
        {
            sub_004A23D0_LoadPanelCels();
        }
        sub_004A3220(gnPage_007C0255, 1);
    }
}

static __declspec(noinline) int sub_004A47C0_GetButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaSliderButtons_007246D8[i].nLeft && nX <= gaSliderButtons_007246D8[i].nRight
            && nY >= gaSliderButtons_007246D8[i].nTop && nY <= gaSliderButtons_007246D8[i].nBottom)
            break;
    }
    return i;
}

// 0x004A4A00
static __forceinline int sub_004A4A00_IsOnButton(int nX, int nY)
{
    return sub_004A47C0_GetButtonAt(nX, nY) != 3;
}

// 0x004A4A80
static __forceinline int sub_004A4A80_IsOnPressedButton(int nX, int nY)
{
    const int nButton = gnPressedButton_007C02B4;
    if (nButton != 3 && sub_004A47C0_GetButtonAt(nX, nY) == nButton)
    {
        return 1;
    }
    return 0;
}

// 0x004A4AA0
int __fastcall sub_004A4AA0_IsOnlyPressed(int nIndex)
{
    for (int i = 0; i < 7; i++)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
        {
            return 0;
        }
    }
    return 1;
}

int __stdcall sub_M119_Emit_004A4A00(int nX, int nY)
{
    if (sub_004A4A00_IsOnButton(nX, nY))
    {
        return sub_004A4A80_IsOnPressedButton(nX + 1, nY);
    }
    return 2;
}
