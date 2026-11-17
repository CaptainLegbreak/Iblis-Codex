struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2CellFileStrc;
struct D2ViewStrc;

struct D2OptionEntryStrc
{
    int nKind;
    int bExpansionOnly;
    int nY;
    char f_C[0x104];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);
    void (__fastcall* pfnLoad)(D2OptionEntryStrc* pEntry, int nArg);
    void (__fastcall* pfnInit)(D2OptionEntryStrc* pEntry, int nArg);
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[4];
    char szValueCels[4][0x104];
    D2CellFileStrc* pCel;
    D2CellFileStrc* pValueCels[4];
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __stdcall D2GFX_SetPerspective(int bPerspective);                                                      // 0x004F51E0
void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows);                                                  // 0x004F5200
int __cdecl sub_004F5170();                                                                                 // 0x004F5170
void __fastcall sub_00476000_SetViewRect(D2ViewStrc* pView, int nLeft, int nTop, int nRight, int nBottom);   // 0x00476000
void __fastcall sub_0044BA20(int nResolution);                                                              // 0x0044BA20
void __fastcall sub_0045A720(int nMode);                                                                    // 0x0045A720
void __fastcall sub_004576F0(int nFade);                                                                    // 0x004576F0
int __cdecl sub_00457740();                                                                                 // 0x00457740
int __fastcall sub_00457750_SetValue(int nValue);                                                           // 0x00457750
int __cdecl sub_004577B0();                                                                                 // 0x004577B0
int __fastcall sub_004577C0_SetValue(int nValue);                                                           // 0x004577C0
int __cdecl sub_004577E0();                                                                                 // 0x004577E0
int __fastcall sub_004577F0_SetValue(int nValue);                                                           // 0x004577F0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290

extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
static int gnOptionSelected_007BC938;                                                                       // 0x007BC938
static D2OptionEntryStrc* gpOptionEntries_007BC940;                                                         // 0x007BC940

static __forceinline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

// 0x0047D040
void __fastcall sub_0047D040_BlendShadowsChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Blended Shadows", 0, pEntry->nValue);
    D2GFX_SetBlendShadows(pEntry->nValue);
}

// 0x0047D070
void __fastcall sub_0047D070_BlendShadowsLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Blended Shadows", 0, (unsigned long*)&pEntry->nValue);
    D2GFX_SetBlendShadows(pEntry->nValue);
}

// 0x0047D0A0
void __fastcall sub_0047D0A0_ResolutionChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Resolution", 0, pEntry->nValue);
    int nResolution = 2;
    if (!pEntry->nValue)
    {
        nResolution = 0;
    }
    sub_0044BA20(nResolution);
}

// 0x0047D0E0
void __fastcall sub_0047D0E0_ResolutionLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    if (!SRegLoadValue("Diablo II", "Resolution", 0, (unsigned long*)&pEntry->nValue))
    {
        pEntry->nValue = 1;
    }
    int nResolution = 2;
    if (!pEntry->nValue)
    {
        nResolution = 0;
    }
    sub_0044BA20(nResolution);
}

// 0x0047D130
void __fastcall sub_0047D130_PerspectiveChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Perspective", 0, pEntry->nValue);
    D2GFX_SetPerspective(pEntry->nValue);
    sub_00476000_SetViewRect(gpView_007A0640, 0, 0, gnAutomapWidth_007A5220, gnAutomapHeight_007A521C);
}

// 0x0047D180
void __fastcall sub_0047D180_PerspectiveLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Perspective", 0, (unsigned long*)&pEntry->nValue);
    if (sub_004F5170())
    {
        sub_0047D130_PerspectiveChanged(pEntry, 0);
    }
    else
    {
        pEntry->nValue = 0;
    }
}

// 0x0047D370
void __fastcall sub_0047D370_AutoMapModeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 2)
    {
        pEntry->nValue = 0;
    }
    sub_0045A720(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapMode", 0, pEntry->nValue);
}

// 0x0047D3F0
void __fastcall sub_0047D3F0_AutoMapFadeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 4)
    {
        pEntry->nValue = 0;
    }
    sub_004576F0(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapFade", 0, pEntry->nValue);
}

// 0x0047D470
void __fastcall sub_0047D470_AutoMapCentersChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00457750_SetValue(pEntry->nValue);
}

// 0x0047D480
void __fastcall sub_0047D480_AutoMapCentersLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = sub_00457740();
}

// 0x0047D490
void __fastcall sub_0047D490_AutoMapPartyChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577C0_SetValue(pEntry->nValue);
}

// 0x0047D4A0
void __fastcall sub_0047D4A0_AutoMapPartyLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = sub_004577B0();
}

// 0x0047D4C0
void __fastcall sub_0047D4C0_AutoMapPartyNamesChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577F0_SetValue(pEntry->nValue);
}

// 0x0047D4D0
void __fastcall sub_0047D4D0_AutoMapPartyNamesLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = sub_004577B0() && sub_004577E0();
}

// 0x0047D9A0
void __stdcall sub_0047D9A0_OptionKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
    if (sub_0047D500(&gpOptionEntries_007BC940[gnOptionSelected_007BC938]))
    {
        switch (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind)
        {
        case 1:
            --gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1;
            }
            break;
        case 2:
            --gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = 0;
            }
            break;
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
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047DA90
void __stdcall sub_0047DA90_OptionKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
    if (sub_0047D500(&gpOptionEntries_007BC940[gnOptionSelected_007BC938]))
    {
        switch (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nKind)
        {
        case 1:
            ++gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = 0;
            }
            break;
        case 2:
            ++gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue;
            if (gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue > gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1)
            {
                gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValue = gpOptionEntries_007BC940[gnOptionSelected_007BC938].nValues - 1;
            }
            break;
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
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}
