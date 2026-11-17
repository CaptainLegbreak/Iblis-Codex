struct Unicode
{
    unsigned short wChar;
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 1)
struct D2ClientCharRecordStrc
{
    char unk0x00[0x1EF];
    unsigned char aFlags[2];
};
#pragma pack(pop)

int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);    // 0x004F60F0
void __stdcall D2GFX_ClearScreen(int bPartial);                                                             // 0x004F63B0
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190
void __stdcall sub_004F98E0();                                                                               // 0x004F98E0
int __stdcall D2Win_10125();                                                                                // 0x00501A40
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);       // 0x00502970
void __fastcall sub_005028A0_FreeTextLines(T0044CB60* pLines);                                         // 0x005028A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern unsigned short gawLoadingStrings_0070F384[];                                                         // 0x0070F384
extern int gnLoadingIndex_007A05D4;                                                                         // 0x007A05D4
extern D2ClientCharRecordStrc* gpCharRecord_007A0438;                                                       // 0x007A0438
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220

// 0x0044CB60
void __cdecl sub_0044CB60_DrawLoadingText()
{
    if (WINDOW_GetState())
    {
        return;
    }
    if (!D2GFX_StartDraw(1, 0, 0, 0))
    {
        return;
    }
    D2GFX_ClearScreen(0);
    sub_00502EF0(3);
    const Unicode* pText = D2LANG_GetStringFromTblIndex(gawLoadingStrings_0070F384[gnLoadingIndex_007A05D4]);
    if (gpCharRecord_007A0438->aFlags[0] & 0x20)
    {
        if (gnLoadingIndex_007A05D4 == 0x14)
        {
            pText = D2LANG_GetStringFromTblIndex(0x5522);
        }
        else if (gnLoadingIndex_007A05D4 == 0x15)
        {
            pText = D2LANG_GetStringFromTblIndex(0x5521);
        }
    }
    const int nWidth = sub_00501820(pText);
    if (nWidth < gnAutomapWidth_007A5220 - 0x28)
    {
        sub_00502320(pText, (gnAutomapWidth_007A5220 - nWidth) >> 1, 0xC8, 0, 0);
    }
    else
    {
        sub_00502EF0(2);
        int nLines;
        T0044CB60* pLines = sub_00502970_SplitText(pText, &nLines, 0x258);
        T0044CB60* pLine = pLines;
        for (unsigned int i = 0; i < nLines; ++i)
        {
            const int nX = (gnAutomapWidth_007A5220 - sub_00501820(pLine->pText)) >> 1;
            sub_00502320(pLine->pText, nX, 2 * (D2Win_10125() * i) + 0xC8, 0, 0);
            pLine = pLine->pNext;
        }
        sub_005028A0_FreeTextLines(pLines);
    }
    sub_004F98E0();
    D2GFX_EndScene();
}

#include "gen/data/Source/D2Client/0044CB60_sub_0044CB60_DrawLoadingText.inc"
