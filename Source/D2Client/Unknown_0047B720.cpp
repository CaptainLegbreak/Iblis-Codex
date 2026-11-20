#include "D2Client.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct Unicode
{
    unsigned short wChar;
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6);  // 0x0046EFD0
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);       // 0x00502970
void __cdecl sub_0047B5C0_DrawImeCandidates();                                                              // 0x0047B5C0
void __stdcall sub_0047B4F0_DrawImeText(int nX, int nY);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern unsigned char gbGlobal_007BB5E0;                                                                     // 0x007BB5E0
extern unsigned char gbChatInputOpen_007BB5E1;                                                              // 0x007BB5E1
extern int gdwGlobal_007BB5EC;                                                                              // 0x007BB5EC
extern int gnImeLanguage_007BB5F0;                                                                          // 0x007BB5F0
extern Unicode gwszChatLine_007BB638[];                                                                     // 0x007BB638
extern unsigned long gdwBlinkTick_007BC890;                                                                 // 0x007BC890

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

// 0x0047B720
void __cdecl sub_0047B720_DrawChatPanel()
{
    const int nOldFont = sub_00502EF0(13);
    if (gbChatInputOpen_007BB5E1)
    {
        Unicode wszLanguage[20];
        memset(wszLanguage, 0, sizeof(wszLanguage));
        switch (gnImeLanguage_007BB5F0)
        {
        case 0:
            sub_00526F20_ToUnicode(wszLanguage, "Alphanumeric", 20);
            sub_00502320(wszLanguage, 0x14, gnGlobal_00711470 - 0x80, 0, 0);
            break;

        case 4:
        case 5:
            wszLanguage[1].wChar = 0x6F22;
            wszLanguage[2].wChar = 0;
            sub_00502320(wszLanguage, 0x14, gnGlobal_00711470 - 0x80, 0, 0);
            sub_0047B5C0_DrawImeCandidates();
            break;

        case 1:
            wszLanguage[0].wChar = 0xD55C;
            wszLanguage[1].wChar = 0xAE00;
            wszLanguage[2].wChar = 0;
            sub_00502320(wszLanguage, 0x14, gnGlobal_00711470 - 0x80, 0, 0);
            break;

        case 2:
        case 3:
            wszLanguage[0].wChar = 0x65E5;
            wszLanguage[1].wChar = 0x672C;
            wszLanguage[2].wChar = 0x8A9E;
            wszLanguage[3].wChar = 0;
            sub_00502320(wszLanguage, 0x14, gnGlobal_00711470 - 0x80, 0, 0);
            break;
        }
    }

    gdwGlobal_007BB5EC += 1;
    sub_0046EFD0_DrawFramedBox(0x7F, gnGlobal_00711470 - 0x67, gnGlobal_0071146C - 0xFF, 0x2F, 0, 1);

    int nWidth = 0;
    if (sub_0044DA30())
    {
        sub_00455F20(5, 1, 0);
    }

    int nRow = 0;
    if (sub_00526800(gwszChatLine_007BB638) > 0)
    {
        Unicode wszText[0x101];
        for (int i = 0; i < 0x101; ++i)
        {
            wszText[i].wChar = 0;
        }
        sub_00526790(wszText, gwszChatLine_007BB638, 0x100);

        int nLineCount;
        T0044CB60* pLines = sub_00502970_SplitText(wszText, &nLineCount, gnGlobal_0071146C - 0x109);
        T0044CB60* pLine = pLines;
        int nLine = 0;
        while (pLine)
        {
            nRow = nLine;
            if (nLine < 3)
            {
                sub_00502320(pLine->pText, 0x83, 15 * nLine + gnGlobal_00711470 - 0x58, 0, 0);
                nWidth = sub_00501820(pLine->pText);
            }

            T0044CB60* pNext = pLine->pNext;
            if (!pNext && gbChatInputOpen_007BB5E1 && gbGlobal_007BB5E0)
            {
                sub_0047B4F0_DrawImeText(sub_00501820(pLine->pText) + 0x83, 15 * nLine + gnGlobal_00711470 - 0x58);
            }

            nLine += 1;
            pLine = pNext;
        }
        sub_005028A0_FreeTextLines(pLines);

        if (nLine > 0)
        {
            nRow = (nLine - 1 > 2) ? 2 : nLine - 1;
        }
    }
    else if (gbChatInputOpen_007BB5E1 && gbGlobal_007BB5E0)
    {
        sub_0047B4F0_DrawImeText(0x83, gnGlobal_00711470 - 0x58);
    }

    if (!gbChatInputOpen_007BB5E1 || !gbGlobal_007BB5E0)
    {
        sub_0047B450_DrawBlinkingCaret(0, 15 * nRow + gnGlobal_00711470 - 0x58, nWidth);
    }

    sub_00502EF0(nOldFont);
}
