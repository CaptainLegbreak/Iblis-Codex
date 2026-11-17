typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
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

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
const Unicode* __fastcall sub_00469DE0_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __stdcall sub_0047E9A0_DrawSlots(int bDraw);                                                           // 0x0047E9A0
int __cdecl sub_0047EA60_IsAnyPanelOpen();                                                                  // 0x0047EA60
int __cdecl sub_0047EB50_IsAnyLeftPanelOpen();                                                              // 0x0047EB50
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
int gnSlotX_007BC898[8];                                                                                    // 0x007BC898
int gnSlotY_007BC8B8[8];                                                                                    // 0x007BC8B8
int gaSlotKind_007BC8D8[8];                                                                                 // 0x007BC8D8
int gnSlotFrame_007BC918[8];                                                                                // 0x007BC918
extern void* gpCellFile_007BC960;                                                                           // 0x007BC960
extern int gdwGlobal_007BC970;                                                                              // 0x007BC970
extern int gbSmallPanel_007BC978;                                                                           // 0x007BC978

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0047E8B0
static void sub_0047E8B0_LayoutSlots(int nMode)
{
    int nSlots = 8;
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    int nFrameAdd = 0;
    int nKindAdd = 0;
    if (!nMode)
    {
        return;
    }
    int nX = gnGlobal_0071146C / 2 - 0x54;
    if (gbSmallPanel_007BC978)
    {
        nX = gnGlobal_0071146C / 2 - 0x4A;
    }
    const int nY = gnGlobal_00711470 - 0x32;
    if (nMode == 1)
    {
        nX = gnGlobal_0071146C / 2 - 0xCA;
    }
    else if (nMode == 3)
    {
        nX = gnGlobal_0071146C / 2 + 0x39;
        if (!gbSmallPanel_007BC978)
        {
            nX = gnGlobal_0071146C / 2 + 0x23;
        }
    }
    gaSlotKind_007BC8D8[0] = 0;
    gnSlotFrame_007BC918[0] = 0;
    gnSlotX_007BC898[0] = nX;
    gnSlotY_007BC8B8[0] = nY;
    nX += 0x15;
    for (int i = 1; i < nSlots; ++i)
    {
        gnSlotX_007BC898[i] = nX;
        gnSlotY_007BC8B8[i] = nY;
        if (gbSmallPanel_007BC978)
        {
            if (i == 3)
            {
                nFrameAdd += 2;
                nKindAdd += 1;
            }
            gaSlotKind_007BC8D8[i] = nKindAdd + i;
            gnSlotFrame_007BC918[i] = nFrameAdd + i * 2;
        }
        else
        {
            gaSlotKind_007BC8D8[i] = i;
            gnSlotFrame_007BC918[i] = i * 2;
        }
        nX += 0x15;
    }
}

// 0x0047F490
static void __stdcall sub_0047F490_ShowSlotTooltip(int nX, int nY, int nKind)
{
    int bHasKey = 0;
    int nHotKey = 0x39;
    int nString;
    switch (nKind)
    {
    case 0:
        nString = 0x1049;
        bHasKey = 1;
        nHotKey = 0;
        break;
    case 1:
        bHasKey = 1;
        nString = 0x104A;
        nHotKey = 1;
        break;
    case 2:
        bHasKey = 1;
        nString = 0x104B;
        nHotKey = 0xC;
        break;
    case 3:
        bHasKey = 1;
        nString = 0x104C;
        nHotKey = 2;
        break;
    case 4:
        bHasKey = 1;
        nString = 0x104D;
        nHotKey = 7;
        break;
    case 5:
        bHasKey = 1;
        nString = 0x104E;
        nHotKey = 3;
        break;
    case 6:
        bHasKey = 1;
        nString = 0x104F;
        nHotKey = 4;
        break;
    case 7:
        nString = 0x1050;
        break;
    default:
        return;
    }
    Unicode wszText[200];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    if (bHasKey && nHotKey != 0x39)
    {
        Unicode wszKey[30];
        if (sub_00469AA0(nHotKey, 1) != 0xFFFF)
        {
            memset(wszKey, 0, sizeof(wszKey));
            sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_00469DE0_GetKeyText(nHotKey, 1));
            sub_00526700(wszText, wszKey);
        }
        if (sub_00469AA0(nHotKey, 0) != 0xFFFF)
        {
            memset(wszKey, 0, sizeof(wszKey));
            sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_00469DE0_GetKeyText(nHotKey, 0));
            sub_00526700(wszText, wszKey);
        }
    }
    sub_00502280_SetPopUpText(wszText, nX - 3, nY - 0x1A, 0, 1);
}

// 0x0047F650
static void sub_0047F650_UpdateSlotHover(int nMode)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    int nOffset = 0;
    int nSlots = 8;
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    if (!nMode)
    {
        return;
    }
    if (nMode == 1)
    {
        nOffset = -0x76;
    }
    else if (nMode == 3)
    {
        nOffset = 0x77;
    }
    const int nCenter = gnGlobal_0071146C / 2 + nOffset;
    if (nMouseX <= nCenter - 0x54 || nMouseX >= nCenter + 0x59)
    {
        return;
    }
    if (nMouseY <= gnGlobal_00711470 - 0x45 || nMouseY >= gnGlobal_00711470 - 0x2F)
    {
        return;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (nMouseX > gnSlotX_007BC898[i] && nMouseX < gnSlotX_007BC898[i] + 0x14)
        {
            sub_0047F490_ShowSlotTooltip(gnSlotX_007BC898[i], gnSlotY_007BC8B8[i], gaSlotKind_007BC8D8[i]);
        }
    }
}

// build: context sub_0047F710_UpdateSlotBar
void __cdecl sub_0047F710_UpdateSlotBar()
{
    const int bAnyPanel = sub_0047EA60_IsAnyPanelOpen();
    const int bLeftPanel = sub_0047EB50_IsAnyLeftPanelOpen();
    D2CelContextStrc tContext;
    if (bAnyPanel)
    {
        if (!bLeftPanel)
        {
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpCellFile_007BC960;
            int nX = gnGlobal_0071146C / 2;
            if (gbSmallPanel_007BC978)
            {
                nX += 0x38;
            }
            else
            {
                nX += 0x23;
            }
            sub_004F6480(&tContext, nX - 2, gnGlobal_00711470 - 0x2F, -1, 5, 0);
            sub_0047E8B0_LayoutSlots(3);
            sub_0047E9A0_DrawSlots(1);
            sub_0047F650_UpdateSlotHover(3);
            gdwGlobal_007BC970 = 0;
            return;
        }
    }
    else
    {
        if (!bLeftPanel)
        {
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpCellFile_007BC960;
            int nX = gnGlobal_0071146C / 2;
            if (gbSmallPanel_007BC978)
            {
                nX -= 0x4A;
            }
            else
            {
                nX -= 0x54;
            }
            sub_004F6480(&tContext, nX - 3, gnGlobal_00711470 - 0x2F, -1, 5, 0);
            sub_0047E8B0_LayoutSlots(2);
            sub_0047E9A0_DrawSlots(1);
            sub_0047F650_UpdateSlotHover(2);
            gdwGlobal_007BC970 = 0;
            return;
        }
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpCellFile_007BC960;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xCD, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(1);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(1);
        gdwGlobal_007BC970 = 0;
        return;
    }
    sub_00468730();
    sub_00468740();
    gdwGlobal_007BC970 = 1;
}
