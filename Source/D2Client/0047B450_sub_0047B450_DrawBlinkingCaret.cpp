struct Unicode
{
    unsigned short wChar;
};

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern unsigned short gwBlinkDelay_00713000;                                                                // 0x00713000
extern int gnBlinkOn_00713004;                                                                              // 0x00713004
extern Unicode gwChatText_007BB5F8[32];                                                                     // 0x007BB5F8
unsigned long gdwBlinkTick_007BC890;                                                                        // 0x007BC890
extern Unicode gwChatText_007BC850[32];                                                                     // 0x007BC850

// 0x0047B450
static void sub_0047B450_DrawBlinkingCaret(int nColor, int nY, int nX)
{
    if (gnBlinkOn_00713004 == 1)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xD4C), nX + 0x83, nY, nColor, 0);
    }

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwBlinkTick_007BC890 > gwBlinkDelay_00713000)
    {
        gdwBlinkTick_007BC890 = dwTick;
        if (gnBlinkOn_00713004)
        {
            gwBlinkDelay_00713000 = 100;
            gnBlinkOn_00713004 = 0;
        }
        else
        {
            gwBlinkDelay_00713000 = 500;
            gnBlinkOn_00713004 = 1;
        }
    }
}

void __stdcall sub_0047B4F0_DrawImeText(int nX, int nY)
{
    int nWidth = 0;
    int nTextX = nX;
    int nTextY = nY;
    if (sub_00526800(gwChatText_007BB5F8))
    {
        nWidth = sub_00501820(gwChatText_007BB5F8);
        if (nWidth + nTextX - 0x83 > gnGlobal_0071146C - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        sub_00502320(gwChatText_007BB5F8, nTextX, nTextY, 4, 0);
    }

    const int nWidth2 = sub_00501820(gwChatText_007BC850);
    if (sub_00526800(gwChatText_007BC850))
    {
        if (nWidth2 + nTextX + nWidth - 0x83 > gnGlobal_0071146C - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        sub_00502320(gwChatText_007BC850, nTextX + nWidth, nTextY, 4, 0);
    }

    sub_0047B450_DrawBlinkingCaret(4, nTextY, nWidth2 + nTextX + nWidth - 0x83);
}

void __cdecl sub_E04_Emit_0047B450(int nX, int nY)
{
    sub_0047B450_DrawBlinkingCaret(0, nY, nX);
}

#include "gen/data/Source/D2Client/0047B450_sub_0047B450_DrawBlinkingCaret.inc"
