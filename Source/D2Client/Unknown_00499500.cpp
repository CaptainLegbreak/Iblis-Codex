#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2MotionVectorStrc;
struct D2HotkeySlotTableStrc;
struct D2TextPanelLineStrc;
struct D2TextPanelStrc;

struct SMSGHANDLER_PARAMS
{
    char pad_00[12];
    unsigned short nX;
    unsigned short nY;
    char pad_10[8];
    int bReturn;
    int lResult;
};

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007BEFA4; // 0x007BEFA4
extern int gnGlobal_007BEFD0; // 0x007BEFD0
extern int gnGlobal_007BEFD8; // 0x007BEFD8
extern int __cdecl sub_0044DA30_InputBlocked(); // 0x0044DA30
extern int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS*); // 0x00420290

struct Unicode
{
    unsigned short wChar;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2MotionVectorStrc
{
    int nX;
    int nY;
    int nZ;
};

struct D2GfxMotionStrc
{
    unsigned int dwFlags;
    D2MotionVectorStrc tA;
    D2MotionVectorStrc tB;
    D2MotionVectorStrc tD;
    D2MotionVectorStrc tC;
    char unk0x34[0xC];
    int nParam0;
    int nParam1;
    int unk0x48;
};

struct D2HotkeySlotTableStrc
{
    int nX[60];
    int nY[60];
    int nSkill[60];
    int f_2D0[60];
};

struct D2TextPanelLineStrc
{
    unsigned short unk0x00[4];
    Unicode wszText[6][0x400];
    unsigned short unk0x3008[3];
};

struct D2TextPanelStrc
{
    D2TextPanelLineStrc pLines[128];
    int unk0x180700[5];
    int nHeight;
    int unk0x180718[6];
    int nFirstLine;
    int unk0x180734[5];
    unsigned short f_180748;
    unsigned short unk0x18074A[14];
    unsigned char nLineStep[4];
    unsigned char nLineGap[4];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern "C" const char gszBorderFramePath_006DA034[]; // 0x006DA034
extern "C" const char gszParticleSourceFile_006DB95C[]; // 0x006DB95C
extern int gnTabSelection_00724CE0; // 0x00724CE0
extern int gnGlobal_00724BEC; // 0x00724BEC
extern unsigned char gbGlobal_007A0522; // 0x007A0522
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern void* gpBorderFrameCel_007BEF18; // 0x007BEF18
extern void* gpPanelQuadCel_007BF018; // 0x007BF018
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300
extern int gnHotkeySkill_007C06C8[16]; // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16]; // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16]; // 0x007C07B8
extern int gbGlobal_007C07FC; // 0x007C07FC

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
extern void* gpCellFile_007BF028; // 0x007BF028

int gnGlobal_007BEF84; // 0x007BEF84

int gnGlobal_007BEF88; // 0x007BEF88

int gnGlobal_007BEFDC; // 0x007BEFDC

int gnGlobal_007BEFE0; // 0x007BEFE0

static __declspec(noinline) int __cdecl sub_00497440_Bounds(int nX,int nY)
{
    int nHalf=gnGlobal_0071146C / 2;
    if (nX >= nHalf + -145 && nX <= nHalf + -128
        && nY >= gnGlobal_00711470 + -28 && nY <= gnGlobal_00711470 + -8)
        return 1;
    return 0;
}

static __declspec(noinline) int __cdecl sub_00497780_Bounds(int nX,int nY)
{
    int nHalf=gnGlobal_0071146C / 2;
    if (nX >= nHalf + -8 && nX <= nHalf + 5
        && nY >= gnGlobal_00711470 + -39 && nY <= gnGlobal_00711470 + -13)
        return 1;
    return 0;
}

// 0x00499500
void __stdcall sub_00499500_Click(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30_InputBlocked() || sub_00463DF0_StateBlocked())
    {
        pMsg->bReturn=0;
        return;
    }
    int nY=pMsg->nY;
    int nX=pMsg->nX;
    if (sub_00498DC0_OverlayHit(pMsg))
    {
        gnGlobal_007BEFA4=1;
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    int nHeight=gnGlobal_00711470;
    if (nY>nHeight + -48)
    {
        int nWidth;
        if ((unsigned int)(nX + -117)<=48 && nY<=nHeight)
        {
            gnGlobal_007BEFA4=1;
            gnGlobal_007BEF84=1;
        }
        else if (nX>=(nWidth=gnGlobal_0071146C) + -165 && nX<=nWidth + -117 && nY<=nHeight)
        {
            gnGlobal_007BEFA4=1;
            gnGlobal_007BEF88=1;
        }
        else if ((unsigned int)(nX + -30)<=80 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gnGlobal_007BEFDC=!gnGlobal_007BEFDC;
            sub_004150E0_SaveValue("Diablo II","Show HP Text",0,gnGlobal_007BEFDC);
        }
        else if (nX>=nWidth + -111 && nX<=nWidth + -31 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gnGlobal_007BEFE0=!gnGlobal_007BEFE0;
            sub_004150E0_SaveValue("Diablo II","Show MP Text",0,gnGlobal_007BEFE0);
        }
        else if (sub_00497780_Bounds(nX,nY))
        {
            gnGlobal_007BEFD0=1;
            gnGlobal_007BEFA4=1;
            sub_004B9A00_Sound(4,0,0,0,0);
        }
        else if (sub_00497440_Bounds(nX,nY))
        {
            gnGlobal_007BEFD8=1;
            gnGlobal_007BEFA4=1;
            sub_004B9A00_Sound(4,0,0,0,0);
        }
        gnGlobal_00722358=1;
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn=0;
}

#include "gen/data/Source/D2Client/Unknown_00499500.inc"

int gbGlobal_007C0C38; // 0x007C0C38

static int sub_004977C0_IsInButtonRect(int nX, int nY)
{
    return nX >= gnGlobal_0071146C / 2 - 8 && nX <= gnGlobal_0071146C / 2 + 5 && nY >= gnGlobal_00711470 - 39 && nY <= gnGlobal_00711470 - 13;
}

// 0x00499E50
void __cdecl sub_00499E50_DrawPanelQuad()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpPanelQuadCel_007BF018;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 256, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 256, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, 5, 0);
}

// 0x004A9E60
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey)
{
    for (int i = 0; i < 60; ++i)
    {
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            if (gnHotkeySkill_007C06C8[nHotkey] != -1)
            {
                sub_004786A0_SendIntInt(0x51, (nHotkey << 16) + 0xFFFF, -1);
            }

            gnHotkeySkill_007C06C8[nHotkey] = gtHotkeySlots_007C0300.nSkill[i];
            if (!gbGlobal_007C07FC)
            {
                gbHotkeyLeft_007C07B8[nHotkey] = 0;
            }
            else
            {
                gbHotkeyLeft_007C07B8[nHotkey] = 1;
            }
            gnHotkeyOwner_007C0768[nHotkey] = gtHotkeySlots_007C0300.f_2D0[i];
            sub_004786A0_SendIntInt(0x51, (nHotkey << 16) + (gbHotkeyLeft_007C07B8[nHotkey] ? 0x8000 : 0) + gnHotkeySkill_007C06C8[nHotkey], gnHotkeyOwner_007C0768[nHotkey]);

            for (int j = 0; j < 16; ++j)
            {
                if (gnHotkeySkill_007C06C8[nHotkey] == gnHotkeySkill_007C06C8[j] && gnHotkeyOwner_007C0768[nHotkey] == gnHotkeyOwner_007C0768[j] && nHotkey != j)
                {
                    gnHotkeySkill_007C06C8[j] = -1;
                    gbHotkeyLeft_007C07B8[j] = -1;
                    gnHotkeyOwner_007C0768[j] = -1;
                    sub_004786A0_SendIntInt(0x51, (j << 16) + 0xFFFF, -1);
                }
            }
        }
    }
}

// 0x004AAAE0
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_00711470 + gnGlobal_007A285C - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 2;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 3;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_00711470 + gnGlobal_007A285C - 48, -1, 5, 0);
}

// 0x004AB530
void __cdecl sub_004AB530_DrawTabCel()
{
    int nX = gnTabTable_00724CE4[gbGlobal_007A0522][gnGlobal_00724BEC];
    if (nX == -149)
    {
        gnTabSelection_00724CE0 = 1;
    }
    else if (nX == -220)
    {
        gnTabSelection_00724CE0 = 2;
    }
    else if (nX == -305)
    {
        gnTabSelection_00724CE0 = 3;
    }
    nX += gnGlobal_0071146C - gnGlobal_007A2858;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gbGlobal_007C0C38 != 0) + 10;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, nX, gnGlobal_00711470 + gnGlobal_007A285C - 63, -1, 5, 0);
}

int gaRosterIndex_007BEFF4[8]; // 0x007BEFF4

// 0x00499F40
static void sub_00499F40_DrawRowSeparator(int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BF028;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0xC, nY - gnGlobal_007A285C, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x10B, nY - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0049A9B0
void __cdecl sub_0049A9B0_RefreshRosterIndices()
{
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    for (int i = 0; i < 8; ++i)
        gaRosterIndex_007BEFF4[i] = 0xFFFF;
    int nIndex = 0;
    while (pEntry)
    {
        gaRosterIndex_007BEFF4[nIndex] = sub_00479BC0_GetEntryIndex(pEntry);
        pEntry = sub_004795A0_GetNextEntry(pEntry);
        ++nIndex;
    }
    int nY = 0x43;
    for (int i = 0; i < 7; ++i)
    {
        if (gaRosterIndex_007BEFF4[i + 1] != gaRosterIndex_007BEFF4[i] && gaRosterIndex_007BEFF4[i] != 0xFFFF)
            sub_00499F40_DrawRowSeparator(nY);
        nY += 0x26;
    }
}
