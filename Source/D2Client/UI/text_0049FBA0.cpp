#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CellFileStrc;
struct D2ScrollPosStrc;
struct Unicode;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    D2CellFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2ScrollPosStrc
{
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2CellFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
void __cdecl sub_0049FA10_DrawPanelFrame(); // 0x0049FA10
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2ScrollPosStrc gaScrollPiecePos_00722EB8[5]; // 0x00722EB8
extern D2ScrollPosStrc gaScrollFadePos_00722EE0[5]; // 0x00722EE0
extern unsigned int gaScrollThresholds_00722F08[5]; // 0x00722F08
extern unsigned short gawScrollSlots_007BF098[5]; // 0x007BF098
extern unsigned int gdwScrollTick_007BF243; // 0x007BF243
extern unsigned int gnScrollCounter_007BF247; // 0x007BF247
extern D2CellFileStrc* gpScroin3_007BF26C; // 0x007BF26C
extern D2CellFileStrc* gpScroin2_007BF270; // 0x007BF270

struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short ch) : wChar(ch) {}
};

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0
void __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

// 0x0049FBA0
void __stdcall sub_0049FBA0_OpenTextPanel(int bDraw)
{
    if (!sub_00463DD0())
    {
        return;
    }

    D2CelContextStrc tPiece;
    memset(&tPiece, 0, sizeof(tPiece));
    sub_0049FA10_DrawPanelFrame();

    if (!gpScroin2_007BF270)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin2");
        gpScroin2_007BF270 = sub_004788B0(szPath, 0);
    }

    if (!gpScroin3_007BF26C)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin3");
        gpScroin3_007BF26C = sub_004788B0(szPath, 0);
    }

    if (!bDraw)
    {
        return;
    }

    const int nOldMode = sub_00502EF0(5);
    tPiece.pCellFile = gpScroin2_007BF270;
    if (!gdwScrollTick_007BF243)
    {
        gdwScrollTick_007BF243 = GetTickCount();
        gnScrollCounter_007BF247 = 0;
    }
    else if (gdwScrollTick_007BF243 + 50 < GetTickCount())
    {
        gdwScrollTick_007BF243 = GetTickCount();
        ++gnScrollCounter_007BF247;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (gnScrollCounter_007BF247 > gaScrollThresholds_00722F08[i])
        {
            const int nTicks = gnScrollCounter_007BF247 - gaScrollThresholds_00722F08[i];
            tPiece.nFrame = i;
            int nDrawMode = 5;
            if (nTicks == 1)
            {
                sub_004B9A00(0xA6F, 0, 0, 0, 0);
            }
            if (nTicks < 5)
            {
                nDrawMode = 0;
            }
            else if (nTicks < 10)
            {
                nDrawMode = 1;
            }
            else if (nTicks < 15)
            {
                nDrawMode = 2;
            }

            const unsigned short nSlot = gawScrollSlots_007BF098[i];
            if (nSlot < 6)
            {
                D2_ASSERT(nSlot < 5, 0x1673);
                TEXTURE_CelDraw(&tPiece, gaScrollPiecePos_00722EB8[nSlot].nX + gnGlobal_007A2858, gaScrollPiecePos_00722EB8[nSlot].nY - gnGlobal_007A285C, -1, nDrawMode, 0);

                D2CelContextStrc tFade;
                memset(&tFade, 0, sizeof(tFade));
                tFade.pCellFile = gpScroin3_007BF26C;
                tFade.nFrame = nTicks >= 21 ? 0 : nTicks;
                TEXTURE_CelDraw(&tFade, gaScrollFadePos_00722EE0[nSlot].nX + gnGlobal_007A2858, gaScrollFadePos_00722EE0[nSlot].nY - gnGlobal_007A285C, -1, 3, 0);
            }
        }
    }

    sub_00502EF0(nOldMode);
}

#include "gen/data/Source/D2Client/UI/text_0049FBA0.inc"

// build: context TEXT_ReadLine
static __forceinline const unsigned short* TEXT_ReadLine(Unicode* pLine, const unsigned short* pText)
{
    int i = 0;
    memset(pLine, 0, 100 * sizeof(Unicode));
    for (; i < 100 && *pText != '\n'; ++i)
    {
        pLine[i] = *pText++;
    }
    if (i < 100 && *pText == '\n')
    {
        ++pText;
    }
    return pText;
}

// 0x004A0320
T0044CB60* __stdcall sub_004A0320_BuildTextLines(const unsigned short* wszText, int* pLineCount, unsigned short* pMaxLines)
{
    Unicode szLine[100];
    const unsigned short* pText = wszText;

    *pLineCount = 0;
    T0044CB60* pLast = 0;
    T0044CB60* pFirst = 0;
    int bFirstLine = 1;
    while (*pText)
    {
        pText = TEXT_ReadLine(szLine, pText);

        T0044CB60* pLine = (T0044CB60*)FOG_Alloc(sizeof(T0044CB60), ".\\UI\\text.cpp", 0x5B8, 0);
        if (bFirstLine == 1)
        {
            const int nLength = sub_00526800(szLine);
            int bAscii = 1;
            for (int j = 0; j < nLength; ++j)
            {
                if (szLine[j].wChar >= 0x80)
                {
                    bAscii = 0;
                }
            }

            if (bAscii)
            {
                char szNumber[100];
                sub_005263E0(szNumber, szLine, 100);
                *pMaxLines = atoi(szNumber);
            }
            else
            {
                char szMessage[80];
                wsprintfA(szMessage, "line 0 of string does not contain scroll rate");
                *pMaxLines = 8;
            }

            bFirstLine = 0;
            pText = TEXT_ReadLine(szLine, pText);
        }

        const int nLength = sub_00526800(szLine);
        if (sub_00501820(szLine) >= 0x134)
        {
            char szMessage[80];
            wsprintfA(szMessage, "line %d of string is too long", *pLineCount);
        }

        pLine->pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nLength + 1), ".\\UI\\text.cpp", 0x5EB, 0);
        sub_005267E0(pLine->pText, szLine);
        pLine->pNext = 0;
        if (pLast)
        {
            pLast->pNext = pLine;
        }
        else
        {
            pFirst = pLine;
        }
        ++*pLineCount;
        pLast = pLine;
    }
    return pFirst;
}
