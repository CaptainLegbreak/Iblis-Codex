#include "D2Client.h"
#include "D2Unicode.h"

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern int gnScreenWidth;                                                                               // 0x0071146C
extern Unicode gwszImeResult[32];                                                                     // 0x007BB5F8
extern unsigned long gdwBlinkTick;                                                                 // 0x007BC890
extern Unicode gwszImeComposition[32];                                                                     // 0x007BC850

// 0x0047B450
static void sub_0047B450_DrawBlinkingCaret(int nY, int nColor, int nX)
{
// build: symbol ?gnBlinkOn@* 0x00713004
    if (gnBlinkOn == 1)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xD4C), nX + 0x83, nY, nColor, 0);
    }

    const unsigned long dwTick = GetTickCount();
// build: symbol ?gwBlinkDelay@* 0x00713000
    if (dwTick - gdwBlinkTick > gwBlinkDelay)
    {
        gdwBlinkTick = dwTick;
        if (gnBlinkOn)
        {
            gwBlinkDelay = 100;
            gnBlinkOn = 0;
        }
        else
        {
            gwBlinkDelay = 500;
            gnBlinkOn = 1;
        }
    }
}

// 0x0047B4F0
void __stdcall sub_0047B4F0_DrawImeText(int nX, int nY)
{
    int nWidth = 0;
    int nTextX = nX;
    int nTextY = nY;
    if (sub_00526800(gwszImeResult))
    {
        nWidth = D2Win_10121_GetTextWidth(gwszImeResult);
        if (nWidth + nTextX - 0x83 > gnScreenWidth - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        D2Win_10117_DrawText(gwszImeResult, nTextX, nTextY, 4, 0);
    }

    const int nWidth2 = D2Win_10121_GetTextWidth(gwszImeComposition);
    if (sub_00526800(gwszImeComposition))
    {
        if (nWidth2 + nTextX + nWidth - 0x83 > gnScreenWidth - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        D2Win_10117_DrawText(gwszImeComposition, nTextX + nWidth, nTextY, 4, 0);
    }

    sub_0047B450_DrawBlinkingCaret(nTextY, 4, nWidth2 + nTextX + nWidth - 0x83);
}

void __cdecl sub_Z01_Emit_0047B450(int nX, int nY)
{
    sub_0047B450_DrawBlinkingCaret(nY, 0, nX);
}
