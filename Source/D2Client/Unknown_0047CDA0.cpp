#include "D2Client.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2StormTypes.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;
struct D2MenuItemStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;

typedef void(__fastcall* MENUSELECT)(D2MenuItemStrc*, SMSGHANDLER_PARAMS*);

typedef void(__fastcall* MENUOPTION)(D2MenuItemStrc*, int);

typedef void(__fastcall* MENUUPDATE)(D2MenuItemStrc*, int);

struct D2MenuItemStrc
{
    unsigned int dwType;
    int bExpansion;
    int nHeight;
    char szImage[260];
    MENUENABLED pfEnabled;
    MENUSELECT pfSelect;
    MENUOPTION pfOption;
    MENUUPDATE pfUpdate;
    unsigned int dwCount;
    unsigned int dwMoveCount;
    unsigned int dwSliderType;
    char szChoices[4][260];
    D2CelFileStrc* pImage;
    D2CelFileStrc* pChoices[4];
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0
int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0
int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20
int __cdecl D2SOUND_GetNpcSpeechOption(); // 0x00514D50
int __fastcall D2SOUND_SetMasterVolumeOption(int nValue); // 0x00514CD0
int __fastcall D2SOUND_SetMusicVolumeOption(int nValue); // 0x00514D00
int __fastcall D2SOUND_SetPositionalBiasOption(int nValue); // 0x00514D30
int __fastcall sub_00514D60_SetNpcSpeech(int nValue); // 0x00514D60
int __cdecl sub_004DF880(); // 0x004DF880
int __cdecl sub_004DF980_IsSoundMode1Or2(); // 0x004DF980
int __cdecl sub_004DF9B0_IsSoundMode2(); // 0x004DF9B0
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue); // 0x004E0690
void __fastcall TEXT_SaveTextDisplaySetting(unsigned long nValue); // 0x0049D570
void __stdcall D2GFX_SetLowQuality(int bLowQuality); // 0x004F5220
void __fastcall sub_004CCF20_SetValue(int nValue); // 0x004CCF20
void __fastcall sub_004776C0(void* pArg); // 0x004776C0
int __cdecl sub_004F5140(); // 0x004F5140



extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
D2CelFileStrc* __cdecl UI_GetPentspinCel(); // 0x00453AA0
int __cdecl UI_TickElapsed(); // 0x00454850
void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nA, int nB, int nC); // 0x00502680
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __stdcall sub_0047E260_DrawOptionSlider(D2OptionEntryStrc* pEntry, int nY, int nColor, int bNoCel); // 0x0047E260
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C; // 0x007BC93C
extern int gnOptionArrowFrame_007BC944; // 0x007BC944
extern int gnOptionMaxWidth_007BC95C; // 0x007BC95C
extern int gnOptionLastX_007BC980; // 0x007BC980
extern int gnOptionLastY_007BC984; // 0x007BC984

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __cdecl sub_004979E0(); // 0x004979E0
int __cdecl HIREABLES_GetBeltRowCount(); // 0x004979F0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __cdecl GAME_GetConnectionType(); // 0x0044DB30
extern int gdwGlobal_007BC978; // 0x007BC978
extern int gdwGlobal_007BC970; // 0x007BC970
extern int gdwGlobal_007BC968; // 0x007BC968
extern int gdwGlobal_007BC96C; // 0x007BC96C
extern int gaSlotX_007BC898[]; // 0x007BC898
extern int gaSlotKind_007BC8D8[]; // 0x007BC8D8

static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg);

static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nValue - nMin + 1) * (float)(pItem->dwCount - 1) / (float)(nMax - nMin));
}

static unsigned int sub_0047CD00_SliderToValue(D2MenuItemStrc* pItem, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nMax - nMin) / (float)(pItem->dwCount - 1) * (float)pItem->dwMoveCount + (float)nMin);
}

// 0x0047CDA0
void __fastcall sub_0047CDA0_MasterVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetMasterVolumeOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CDC0
void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMasterVolumeOption(), 0, 100);
}

// 0x0047CDF0
void __fastcall sub_0047CDF0_MusicVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetMusicVolumeOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CE10
void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMusicVolumeOption(), 0, 100);
}

// 0x0047CE50
void __fastcall sub_0047CE50_SoundModeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF980_IsSoundMode1Or2();
}

// 0x0047CE70
void __fastcall sub_0047CE70_PositionalBiasSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetPositionalBiasOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CE90
void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetPositionalBiasOption(), 0, 100);
}

// 0x0047CED0
void __fastcall sub_0047CED0_SoundMode2Option(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF9B0_IsSoundMode2();
}

// 0x0047CEF0
void __fastcall sub_0047CEF0_NpcSpeechSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D60_SetNpcSpeech(pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        sub_004E0690_SetSoundTableFlag(1);
        TEXT_SaveTextDisplaySetting(0);
        break;
    case 1:
        sub_004E0690_SetSoundTableFlag(0);
        TEXT_SaveTextDisplaySetting(1);
        break;
    case 2:
        sub_004E0690_SetSoundTableFlag(1);
        TEXT_SaveTextDisplaySetting(1);
        break;
    }
}

// 0x0047CF50
void __fastcall sub_0047CF50_NpcSpeechOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = D2SOUND_GetNpcSpeechOption();
    if (sub_004DF880())
    {
        sub_0047CEF0_NpcSpeechSelect(pItem, (SMSGHANDLER_PARAMS*)nArg);
    }
}

// 0x0047CF80
void __fastcall sub_0047CF80_LightQualitySelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Light Quality", 0, pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        D2GFX_SetLowQuality(1);
        sub_004CCF20_SetValue(0);
        break;
    case 1:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetValue(0);
        break;
    case 2:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetValue(1);
        break;
    }
}

// 0x0047CFE0
void __fastcall sub_0047CFE0_LightQualityOption(D2MenuItemStrc* pItem, int nArg)
{
    SRegLoadValue("Diablo II", "Light Quality", 0, (unsigned long*)&pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        D2GFX_SetLowQuality(1);
        sub_004CCF20_SetValue(0);
        break;
    case 1:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetValue(0);
        break;
    case 2:
        D2GFX_SetLowQuality(0);
        sub_004CCF20_SetValue(1);
        break;
    }
}

void __fastcall sub_0047D200_GammaSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nGamma = sub_0047CD00_SliderToValue(pItem, 0x37, 0xFF);
    SRegSaveValue("Diablo II", "Gamma", 0, nGamma);
    sub_004776C0((void*)nGamma);
}

void __fastcall sub_0047D230_GammaOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nGamma = 0x9B;
    SRegLoadValue("Diablo II", "Gamma", 0, &nGamma);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nGamma, 0x37, 0xFF);
    if (D2GFX_GammaCanBeControlled())
    {
        sub_0047D200_GammaSelect(pItem, 0);
    }
}

void __fastcall sub_0047D2B0_ContrastSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Contrast", 0, sub_0047CD00_SliderToValue(pItem, 0, 100));
    D2GFX_SetOption(0x0B, pItem->dwMoveCount);
    D2GFX_SetGamma(0);
}

void __fastcall sub_0047D2F0_ContrastOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nContrast = (sub_004F5140() != 4) ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nContrast, 0, 100);
    sub_0047D2B0_ContrastSelect(pItem, 0);
}

// 0x0047CDE0
int __fastcall sub_0047CD80_IsSoundEnabled()
{
    return sub_004DF880();
}

int __fastcall sub_0047CD90_IsSoundEnabled()
{
    return sub_004DF880();
}

static int gnOptionSelected_007BC938; // 0x007BC938

static D2OptionEntryStrc* gpOptionEntries_007BC940; // 0x007BC940

static int gbOptionPressed_007BC948; // 0x007BC948

static int gbOptionDragging_007BC94C; // 0x007BC94C

static inline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

// 0x0047D520
static int sub_0047D520_FindOptionAtY(int nY)
{
    const int nCount = gpOptionHeader_007BC93C->nCount;
    const int nHalf = gpOptionHeader_007BC93C->nHeight * nCount / 2;
    const int nCenter = (gnGlobal_00711470 - 0x50) / 2;
    int nResult = -1;

    if (nY > nCenter - nHalf && nY < nCenter + nHalf)
    {
        for (int i = 0; i < nCount; ++i)
        {
            if (gpOptionEntries_007BC940[i].nY && nY >= gpOptionEntries_007BC940[i].nY + nCount)
            {
                nResult = i;
            }
        }

        if (nResult >= 0)
        {
            if (gpOptionEntries_007BC940[nResult].nKind != -1 && sub_0047D500(&gpOptionEntries_007BC940[nResult]))
            {
                return nResult;
            }

            nResult = -1;
        }
    }

    return nResult;
}

static void sub_0047D5B0_SelectOptionAtY(int nY)
{
    const int nIndex = sub_0047D520_FindOptionAtY(nY);
    if (nIndex != -1)
    {
        gnOptionSelected_007BC938 = nIndex;
    }
}

static void sub_0047D670_UpdateOptionSlider(int nX, int nY)
{
    if (!gbOptionDragging_007BC94C && sub_0047D520_FindOptionAtY(nY) != gnOptionSelected_007BC938)
    {
        return;
    }

    const unsigned int nOldValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
    if (sub_0047D500(&gpOptionEntries_007BC940[gnOptionSelected_007BC938]))
    {
        switch (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind)
        {
        case 2:
        {
            const int nHalfWidth = gnGlobal_0071146C / 2;
            int nLeft = nHalfWidth - 0x3B;
            int nBar = nHalfWidth - 0x3C;
            if (!gpOptionEntries_007BC940[gnOptionSelected_007BC938].pCel)
            {
                nLeft = nHalfWidth - 0x90;
                nBar = nHalfWidth - 0x91;
            }

            if (gbOptionDragging_007BC94C || nX > nLeft && nX < nLeft + 0x121)
            {
                const int nStart = nBar + 0xC;
                if (nX < nStart)
                {
                    gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = 0;
                }
                else if (nX > nStart + 0x109)
                {
                    gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1;
                }
                else
                {
                    gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = (int)((nX - nStart) / (float)(265.0 / (float)(gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1) * 0.5) + 1.0) / 2;
                }
                gbOptionDragging_007BC94C = 1;
            }
            break;
        }
        }
    }

    if (nOldValue != gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue)
    {
        if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged)
        {
            gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged(&gpOptionEntries_007BC940[gnOptionSelected_007BC938], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}

void __stdcall sub_0047D7F0_OptionMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_0047D5B0_SelectOptionAtY(nY);
    sub_0047D670_UpdateOptionSlider(nX, nY);
    gbOptionPressed_007BC948 = 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __stdcall sub_0047D840_OptionMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    if (gbOptionPressed_007BC948 && sub_0047D520_FindOptionAtY(nY) == gnOptionSelected_007BC938)
    {
        sub_0047D5C0_ActivateOption(pMsg);
    }
    GAME_ResetMouseState();
    gbOptionPressed_007BC948 = 0;
    gbOptionDragging_007BC94C = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __stdcall sub_0047DB80_OptionActivate(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0047D5C0_ActivateOption(pMsg);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __cdecl sub_0047E3D0_DrawOptions()
{
    D2_ASSERT(gpOptionHeader_007BC93C, 0x64B);
    D2_ASSERT(gpOptionEntries_007BC940, 0x64C);

    const int nX = sub_00468730();
    const int nY = sub_00468740();
    const int nTop = (gnGlobal_00711470 - 0x50) / 2 - gpOptionHeader_007BC93C->nHeight * gpOptionHeader_007BC93C->nCount / 2;

    if (gnOptionLastY_007BC984 != nY || gnOptionLastX_007BC980 != nX)
    {
        gnOptionLastY_007BC984 = nY;
        gnOptionLastX_007BC980 = nX;
        if (gbOptionPressed_007BC948)
        {
            sub_0047D670_UpdateOptionSlider(nX, nY);
        }
        else
        {
            sub_0047D5B0_SelectOptionAtY(nY);
        }
    }

    int bEnabled;
    int nRow = 0;
    for (int i = 0; i < gpOptionHeader_007BC93C->nCount; ++i)
    {
        bEnabled = 0;
        gpOptionEntries_007BC940[i].nY = 0;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (gpOptionEntries_007BC940[i].bExpansionOnly && !FOG_IsExpansion())
        {
            continue;
        }

        if (!gpOptionEntries_007BC940[i].pfnEnabled || gpOptionEntries_007BC940[i].pfnEnabled())
        {
            bEnabled = 1;
        }

        const int nColor = bEnabled ? 5 : 1;
        if (gpOptionEntries_007BC940[i].pfnInit)
        {
            gpOptionEntries_007BC940[i].pfnInit(&gpOptionEntries_007BC940[i], 0);
        }

        const int nEntryY = gpOptionHeader_007BC93C->nHeight * nRow + nTop;
        const int nDrawY = gpOptionHeader_007BC93C->nTextOffset + nEntryY;
        gpOptionEntries_007BC940[i].nY = nEntryY;
        switch (gpOptionEntries_007BC940[i].nKind)
        {
        case -1:
        case 0:
            D2Win_10134_DrawCellFile(gpOptionEntries_007BC940[i].pCel, gnGlobal_0071146C / 2, nDrawY, 1, nColor, -1);
            break;

        case 1:
            D2Win_10134_DrawCellFile(gpOptionEntries_007BC940[i].pCel, gnGlobal_0071146C / 2 - 0xE6, nDrawY, 0, nColor, -1);
            D2Win_10134_DrawCellFile(gpOptionEntries_007BC940[i].pValueCels[gpOptionEntries_007BC940[i].nValue], gnGlobal_0071146C / 2 + 0xE6, nDrawY, 2, nColor, -1);
            break;

        case 2:
            if (gpOptionEntries_007BC940[i].pCel)
            {
                D2Win_10134_DrawCellFile(gpOptionEntries_007BC940[i].pCel, gnGlobal_0071146C / 2 - 0xE6, nDrawY, 0, nColor, -1);
            }
            sub_0047E260_DrawOptionSlider(&gpOptionEntries_007BC940[i], nEntryY, nColor, gpOptionEntries_007BC940[i].pCel == 0);
            break;
        }
        ++nRow;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = UI_GetPentspinCel();
    if (gnOptionArrowFrame_007BC944)
    {
        tContext.nFrame = 8 - gnOptionArrowFrame_007BC944;
    }
    else
    {
        tContext.nFrame = 0;
    }

    const int nArrowY = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nY + gpOptionHeader_007BC93C->nArrowOffset;
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - gnOptionMaxWidth_007BC95C - 0xF9, nArrowY, -1, 5, 0);
    tContext.nFrame = gnOptionArrowFrame_007BC944;
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0xF9, nArrowY, -1, 5, 0);
    if (UI_TickElapsed())
    {
        gnOptionArrowFrame_007BC944 = (gnOptionArrowFrame_007BC944 + 1) % 8;
    }
}

// 0x0047D5C0
static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0047D500(&gpOptionEntries_007BC940[gnOptionSelected_007BC938]))
    {
        return;
    }

    switch (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind)
    {
    case 1:
        gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue++;
        if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
        {
            gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = 0;
        }
        if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged)
        {
            gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged(&gpOptionEntries_007BC940[gnOptionSelected_007BC938], pMsg);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
        break;

    case 0:
        if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged)
        {
            gpOptionEntries_007BC940[gnOptionSelected_007BC938].pfnChanged(&gpOptionEntries_007BC940[gnOptionSelected_007BC938], pMsg);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
        break;
    }
}

int gaSlotState_007BC8F8[8]; // 0x007BC8F8

static int gbSlotClicked_007BC97C; // 0x007BC97C

// 0x0047EF30
void __stdcall sub_0047EF30_SlotsClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nSlots = 8;
    if (gdwGlobal_007BC978)
    {
        nSlots = 7;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || !pPlayer->pInventory || INVENTORY_GetCursorItem(pPlayer->pInventory) || gdwGlobal_007BC970)
    {
        return;
    }
    D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
    if (!pUnit)
    {
        return;
    }
    int nY = pMsg->nYpos;
    int nX = pMsg->nXpos;
    int nOffset = 0;
    if (sub_004979E0() && HIREABLES_GetBeltRowCount() > 1)
    {
        nOffset = -0x76;
    }
    if (gdwGlobal_007BC968)
    {
        nOffset -= 0x76;
    }
    if (gdwGlobal_007BC96C)
    {
        nOffset += 0x77;
    }
    int nCenter = gnGlobal_0071146C / 2 + nOffset;
    if (nX <= nCenter - 0x54 || nX >= nCenter + 0x59 || nY <= gnGlobal_00711470 - 0x45 || nY >= gnGlobal_00711470 - 0x2F)
    {
        return;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (nX > gaSlotX_007BC898[i] && nX < gaSlotX_007BC898[i] + 0x14)
        {
            if (gaSlotKind_007BC8D8[i] == 7)
            {
                gaSlotState_007BC8F8[i] = 1;
            }
            else if (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11)
            {
                if (!GAME_GetUIVarState(9))
                {
                    gaSlotState_007BC8F8[i] = 1;
                }
                else if (!GAME_GetConnectionType())
                {
                    if (i >= 4)
                    {
                        gaSlotState_007BC8F8[i] = 1;
                    }
                }
                else
                {
                    if (i >= 5)
                    {
                        gaSlotState_007BC8F8[i] = 1;
                    }
                }
            }
            sub_004B9A00(4, 0, 0, 0, 0);
            gbSlotClicked_007BC97C = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}
