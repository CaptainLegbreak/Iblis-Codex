struct D2UnitStrc;

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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void* __cdecl sub_00454600();                                                                               // 0x00454600
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
void __fastcall sub_0046F070_SetGfxMotion(D2UnitStrc* pUnit, D2GfxMotionStrc* pMotion);                     // 0x0046F070
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnTabSelection_00724CE0;                                                                         // 0x00724CE0
extern int gnTabTable_00724CE4[][3];                                                                        // 0x00724CE4
extern int gnGlobal_00724BEC;                                                                               // 0x00724BEC
extern unsigned char gbGlobal_007A0522;                                                                     // 0x007A0522
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
void* gpBorderFrameCel_007BEF18;                                                                            // 0x007BEF18
extern void* gpStateButtonCel_007BEF70;                                                                     // 0x007BEF70
extern int gbGlobal_007BEFD0;                                                                               // 0x007BEFD0
extern void* gpPanelQuadCel_007BF018;                                                                       // 0x007BF018
extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300;                                                        // 0x007C0300
extern int gnHotkeySkill_007C06C8[16];                                                                      // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16];                                                                      // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16];                                                                       // 0x007C07B8
extern int gbGlobal_007C07FC;                                                                               // 0x007C07FC
extern int gbGlobal_007C0C38;                                                                               // 0x007C0C38

static int sub_004977C0_IsInButtonRect(int nX, int nY)
{
    return nX >= gnGlobal_0071146C / 2 - 8 && nX <= gnGlobal_0071146C / 2 + 5 && nY >= gnGlobal_00711470 - 39 && nY <= gnGlobal_00711470 - 13;
}

// 0x004977C0
void __cdecl sub_004977C0_DrawStateButton()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpStateButtonCel_007BEF70;
    tContext.unk0x40 = 0;
    if (sub_004538D0(21))
    {
        if (gbGlobal_007BEFD0 && sub_004977C0_IsInButtonRect(sub_00468730(), sub_00468740()))
        {
            tContext.nFrame = 3;
        }
        else
        {
            tContext.nFrame = 2;
        }
    }
    else
    {
        if (gbGlobal_007BEFD0 && sub_004977C0_IsInButtonRect(sub_00468730(), sub_00468740()))
        {
            tContext.nFrame = 1;
        }
        else
        {
            tContext.nFrame = 0;
        }
    }
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 8, gnGlobal_00711470 - 16, -1, 5, 0);
}

// 0x00498630
void __cdecl sub_00498630_DrawBorderFrameLeft()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (!gpBorderFrameCel_007BEF18)
    {
        gpBorderFrameCel_007BEF18 = sub_004520C0_LoadUiCelFile("Panel\\800BorderFrame");
    }
    tContext.pCellFile = gpBorderFrameCel_007BEF18;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 253, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 256, 63, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0, 484, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0, 553, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 256, 553, -1, 5, 0);
}

// 0x00498700
void __cdecl sub_00498700_DrawBorderFrameRight()
{
    if (!gpBorderFrameCel_007BEF18)
    {
        gpBorderFrameCel_007BEF18 = sub_004520C0_LoadUiCelFile("Panel\\800BorderFrame");
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpBorderFrameCel_007BEF18;
    tContext.unk0x40 = 0;
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 400, 63, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 544, 253, -1, 5, 0);
    tContext.nFrame = 7;
    sub_004F6480(&tContext, 713, 484, -1, 5, 0);
    tContext.nFrame = 8;
    sub_004F6480(&tContext, 544, 553, -1, 5, 0);
    tContext.nFrame = 9;
    sub_004F6480(&tContext, 400, 553, -1, 5, 0);
}

// build: context sub_00499E50_DrawPanelQuad
void __cdecl sub_00499E50_DrawPanelQuad()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpPanelQuadCel_007BF018;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 256, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 256, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
}

// build: context sub_004A9E60_AssignHotkey
void __fastcall sub_004A9E60_AssignHotkey(int nHotkey)
{
    for (int i = 0; i < 60; ++i)
    {
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nY = gtHotkeySlots_007C0300.nY[i];
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

// build: context sub_004AAAE0_DrawPagedPanel
void __stdcall sub_004AAAE0_DrawPagedPanel(void* pCellFile, int nPage)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 1;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 224, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 2;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 320, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
    tContext.nFrame = 4 * nPage + 3;
    sub_004F6480(&tContext, gnGlobal_0071146C - gnGlobal_007A2858 - 64, gnGlobal_007A285C + gnGlobal_00711470 - 48, -1, 5, 0);
}

// build: context sub_004AB530_DrawTabCel
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
    sub_004F6480(&tContext, nX, gnGlobal_007A285C + gnGlobal_00711470 - 63, -1, 5, 0);
}

// 0x004BE340
int __fastcall sub_004BE340_CountLinesInView(D2TextPanelStrc* pPanel)
{
    const int nLineCount = pPanel->f_180748;
    int nTotal = 0;
    for (int i = 0; i < nLineCount; ++i)
    {
        if (i >= pPanel->nFirstLine && i < nLineCount)
        {
            for (int k = 0; k < 6; ++k)
            {
                if (pPanel->pLines[i].wszText[k][0].wChar)
                {
                    nTotal += *(int*)pPanel->nLineStep;
                }
            }
            nTotal += *(int*)pPanel->nLineGap;
        }

        if (nTotal > pPanel->nHeight - 20)
        {
            i -= pPanel->nFirstLine;
            if (i < 1)
            {
                i = 1;
            }
            return i;
        }
    }

    return nLineCount;
}

// 0x004DA000
void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (!pMotion)
    {
        pMotion = (D2GfxMotionStrc*)FOG_Alloc(sizeof(D2GfxMotionStrc), ".\\ENGINE\\Particle.cpp", 72, 0);
        D2_ASSERT(pMotion, 74);
    }
    memset(pMotion, 0, sizeof(D2GfxMotionStrc));
    sub_0046F070_SetGfxMotion(pUnit, pMotion);
}
