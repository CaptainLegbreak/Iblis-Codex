#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ClientGfx.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2HotkeySlotTableStrc;
struct D2TextPanelLineStrc;
struct D2TextPanelStrc;

extern int gnScreenWidth; // 0x0071146C
extern int gbControlPanelClicked; // 0x007BEFA4
extern int gbMiniPanelButtonDown; // 0x007BEFD0
extern int gbRunButtonDown; // 0x007BEFD8
extern int __cdecl GAME_IsExitPending(); // 0x0044DA30
extern int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS*); // 0x00420290

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
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern "C" const char gszBorderFramePath[]; // 0x006DA034
extern "C" const char gszParticleSourceFile[]; // 0x006DB95C
extern int gnTabSelection; // 0x00724CE0
extern int gnSkillPage; // 0x00724BEC
extern unsigned char gnCharClass; // 0x007A0522
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern void* gpBorderFrameCel; // 0x007BEF18
extern void* gpPanelQuadCel; // 0x007BF018
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8
extern int gbSkillSelectRight; // 0x007C07FC

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
extern void* gpCellFile_007BF028; // 0x007BF028

int gbLeftSkillButtonDown; // 0x007BEF84

int gbRightSkillButtonDown; // 0x007BEF88

int gdwShowHpText; // 0x007BEFDC

int gdwShowMpText; // 0x007BEFE0

static int __cdecl sub_00497440_Bounds(int nX,int nY)
{
    int nHalf=gnScreenWidth / 2;
    if (nX >= nHalf + -145 && nX <= nHalf + -128
        && nY >= gnScreenHeight + -28 && nY <= gnScreenHeight + -8)
        return 1;
    return 0;
}

static int __cdecl sub_00497780_Bounds(int nX,int nY)
{
    int nHalf=gnScreenWidth / 2;
    if (nX >= nHalf + -8 && nX <= nHalf + 5
        && nY >= gnScreenHeight + -39 && nY <= gnScreenHeight + -13)
        return 1;
    return 0;
}


#include "gen/data/Source/D2Client/Unknown_00499500.inc"

int gbSkillTabPressed; // 0x007C0C38

static int sub_004977C0_IsInButtonRect(int nX, int nY)
{
    return nX >= gnScreenWidth / 2 - 8 && nX <= gnScreenWidth / 2 + 5 && nY >= gnScreenHeight - 39 && nY <= gnScreenHeight - 13;
}

// 0x00499E50
void __cdecl sub_00499E50_DrawPanelQuad()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpPanelQuadCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 256, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnPanelOffsetX + 256, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
}


// 0x004AAAE0
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 320, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 64, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 320, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 64, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 320, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 1;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 64, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 2;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 320, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 3;
    sub_004F6480(&tContext, gnScreenWidth - gnPanelOffsetX - 64, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
}

// 0x004AB530
void __cdecl sub_004AB530_DrawTabCel()
{
// build: symbol ?gaSkillTabX@* 0x00724CE4
    int nX = gaSkillTabX[gnCharClass][gnSkillPage];
    if (nX == -149)
    {
        gnTabSelection = 1;
    }
    else if (nX == -220)
    {
        gnTabSelection = 2;
    }
    else if (nX == -305)
    {
        gnTabSelection = 3;
    }
    nX += gnScreenWidth - gnPanelOffsetX;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gbSkillTabPressed != 0) + 10;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nX, gnScreenHeight + gnPanelOffsetY - 63, -1, 5, 0);
}

int gaRosterIndex[8]; // 0x007BEFF4

// 0x00499F40
static void sub_00499F40_DrawRowSeparator(int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BF028;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + 0xC, nY - gnPanelOffsetY, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x10B, nY - gnPanelOffsetY, -1, 5, 0);
}

// 0x0049A9B0
void __cdecl sub_0049A9B0_RefreshRosterIndices()
{
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    for (int i = 0; i < 8; ++i)
        gaRosterIndex[i] = 0xFFFF;
    int nIndex = 0;
    while (pEntry)
    {
        gaRosterIndex[nIndex] = ROSTER_GetEntryIndex(pEntry);
        pEntry = ROSTER_GetNextStoredUnit(pEntry);
        ++nIndex;
    }
    int nY = 0x43;
    for (int i = 0; i < 7; ++i)
    {
        if (gaRosterIndex[i + 1] != gaRosterIndex[i] && gaRosterIndex[i] != 0xFFFF)
            sub_00499F40_DrawRowSeparator(nY);
        nY += 0x26;
    }
}
