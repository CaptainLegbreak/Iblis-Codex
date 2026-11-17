struct D2CellFileStrc;
struct D2UnitStrc;

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
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

#include "gen/data/Source/D2Client/0049FBA0_sub_0049FBA0_OpenTextPanel.inc"
