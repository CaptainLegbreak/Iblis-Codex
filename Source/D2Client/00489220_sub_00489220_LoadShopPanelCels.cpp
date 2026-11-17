typedef unsigned int size_t;

struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

struct D2UnitStrc;
struct D2CellFileStrc;

struct D2DataTablesStrc
{
    char unk0x00[0xBF0];
    int nPetTypeTxtRecordCount;
};

struct D2HirelingIconRecordStrc
{
    int unk0x00[5];
};

#pragma pack(push, 2)
struct D2PanelLabelStrc
{
    int nX;
    int nX2;
    int nY;
    unsigned short nString;
};
#pragma pack(pop)

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);       // 0x00413A40
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" size_t __cdecl strlen(const char* szString);
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2CellFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                             // 0x004788B0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __cdecl sub_00525150();                                                                         // 0x00525150
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode);                                                      // 0x0045AEA0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc);                                     // 0x00526700
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern);             // 0x00526940
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);                                     // 0x00464A60
int __fastcall sub_004A7660_SplitAtNewLine(Unicode* wszText, Unicode** ppSecond);                           // 0x004A7660
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB);                                          // 0x0046A530

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
int gnGlobal_007BCAF0;                                                                                      // 0x007BCAF0
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern int gnGlobal_007BCE30;                                                                               // 0x007BCE30
extern int gnGlobal_007BCE9C;                                                                               // 0x007BCE9C
int gnGlobal_007BCD34;                                                                                      // 0x007BCD34
int gnGlobal_007BCE14;                                                                                      // 0x007BCE14
extern int gnGlobal_007BCA48;                                                                               // 0x007BCA48
int gnGlobal_007BCE18;                                                                                      // 0x007BCE18
int gnGlobal_007BCE1C;                                                                                      // 0x007BCE1C
int gnGlobal_007BCE20;                                                                                      // 0x007BCE20
int gnGlobal_007BCE24;                                                                                      // 0x007BCE24
D2CellFileStrc* gpCellFile_007BCC24;                                                                        // 0x007BCC24
D2CellFileStrc* gpCellFile_007BCC28;                                                                        // 0x007BCC28
D2CellFileStrc* gpCellFile_007BCC38;                                                                        // 0x007BCC38
extern D2CellFileStrc* gpCellFile_007BCC2C;                                                                 // 0x007BCC2C
extern D2CellFileStrc* gpCellFile_007BCC3C;                                                                 // 0x007BCC3C
extern D2CellFileStrc* gpCellFile_007BCC30;                                                                 // 0x007BCC30
extern D2CellFileStrc* gpCellFile_007BCB04;                                                                 // 0x007BCB04
extern D2PanelLabelStrc gaPanelLabels_006D9AE8[12];                                                         // 0x006D9AE8
extern void* gpCellFile_007BEF7C;                                                                           // 0x007BEF7C
extern void* gpCellFile_007BEF64;                                                                           // 0x007BEF64
extern void* gpCellFile_007BEF78;                                                                           // 0x007BEF78
extern void* gpCellFile_007BEF24;                                                                           // 0x007BEF24
extern void* gpCellFile_007BEF60;                                                                           // 0x007BEF60
extern void* gpCellFile_007BEF14;                                                                           // 0x007BEF14
extern void* gpCellFile_007BEF10;                                                                           // 0x007BEF10
extern void* gpCellFile_007BEF68;                                                                           // 0x007BEF68
extern void* gpCellFile_007BEF80;                                                                           // 0x007BEF80
extern void* gpStateButtonCel_007BEF70;                                                                     // 0x007BEF70
extern void* gpCellFile_007BEF2C;                                                                           // 0x007BEF2C
extern void* gpCellFile_007BEF20;                                                                           // 0x007BEF20
extern void* gpGlobal_007BEF0C;                                                                             // 0x007BEF0C
extern void* gpCellFile_007BEF28;                                                                           // 0x007BEF28
extern unsigned char gabGlobal_007BEF30[0x30];                                                              // 0x007BEF30
extern unsigned long gdwShowHpText_007BEFDC;                                                                // 0x007BEFDC
extern unsigned long gdwShowMpText_007BEFE0;                                                                // 0x007BEFE0
void* gapHirelingIcons_007BEEB0[7];                                                                         // 0x007BEEB0
extern D2HirelingIconRecordStrc* gpHirelingRecords_007BEEAC;                                                // 0x007BEEAC

extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char szDataLocal_006D41A8[];                                                               // 0x006D41A8
extern "C" const char szIntFormat_006D57BC[];                                                               // 0x006D57BC

// 0x00489220
void __cdecl sub_00489220_LoadShopPanelCels()
{
    char szPath[0x104];
    if (!gpCellFile_007BCC24)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\buyselltabs", szDataGlobal_006D4118);
        gpCellFile_007BCC24 = sub_004788B0(szPath, 0);
    }
    if (!gpCellFile_007BCC28)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\miniconvert", szDataGlobal_006D4118);
        gpCellFile_007BCC28 = sub_004788B0(szPath, 0);
    }
    if (!gpCellFile_007BCC38 && sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\invchar6tab", szDataGlobal_006D4118);
        gpCellFile_007BCC38 = sub_004788B0(szPath, 0);
    }
}

// 0x00489360
void __fastcall sub_00489360_SetTradePanelOpen(int bOpen)
{
    char szPath[0x104];
    if (gnGlobal_007BCD34 || gnGlobal_007BCE14)
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    gnGlobal_007BCD34 = 0;
    gnGlobal_007BCE14 = 0;
    gnGlobal_007BCE30 = 0;
    if (bOpen)
    {
        gnGlobal_007BCA48 = 0;
        gdwGlobal_007BCBF0 = 0xB;
        sub_0045AEA0_SetPanelSlide(3);
        if (!gpCellFile_007BCB04)
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\trade", szDataGlobal_006D4118);
            gpCellFile_007BCB04 = sub_004788B0(szPath, 0);
        }
    }
    else
    {
        gdwGlobal_007BCBF0 = 0xA;
        sub_0045AEA0_SetPanelSlide(0);
    }
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE18 = 0;
    gnGlobal_007BCE1C = 0;
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE24 = 0;
}

// 0x00489E50
void __cdecl sub_00489E50_LoadStashPanelCels()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpCellFile_007BCC2C)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\bank", szDataGlobal_006D4118);
        gpCellFile_007BCC2C = sub_004788B0(szPath, 0);
        if (sub_00408F20_HasExpansionMpq())
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\TradeStash", szDataGlobal_006D4118);
            gpCellFile_007BCC3C = sub_004788B0(szPath, 0);
        }
    }
}

// 0x0048A4B0
void __cdecl sub_0048A4B0_LoadCubePanelCel()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpCellFile_007BCC30)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\supertransmogrifier", szDataGlobal_006D4118);
        gpCellFile_007BCC30 = sub_004788B0(szPath, 0);
    }
}

// 0x0048A7D0
void __stdcall sub_0048A7D0_DrawUnitName(D2UnitStrc* pUnit)
{
    Unicode wszName[32];
    for (int i = 0; i < 32; ++i)
    {
        wszName[i].wChar = 0;
    }
    const int nOldFont = sub_00502EF0(6);
    Unicode::strncpy(wszName, sub_00464A60_GetUnitName(pUnit), 32);
    wszName[31].wChar = 0;
    Unicode* pEnd = &wszName[31];
    while (sub_00501820(wszName) > 0xA0)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    sub_00502320(wszName, gnGlobal_007A2858 + 0xF, 0xD6 - gnGlobal_007A285C, 0, 0);
    sub_00502EF0(nOldFont);
}

// 0x0048A890
void __cdecl sub_0048A890_DrawPanelLabels()
{
    const int nOldFont = sub_00502EF0(6);
    for (int i = 0; i < sizeof(gaPanelLabels_006D9AE8) / sizeof(gaPanelLabels_006D9AE8[0]); ++i)
    {
        Unicode wszText[100];
        for (int j = 0; j < 100; ++j)
        {
            wszText[j].wChar = 0;
        }
        Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(gaPanelLabels_006D9AE8[i].nString), 99);
        wszText[99].wChar = 0;
        const int nLeft = gaPanelLabels_006D9AE8[i].nX + gnGlobal_007A2858;
        const int nRight = gaPanelLabels_006D9AE8[i].nX2 + gnGlobal_007A2858;
        const int nY = gaPanelLabels_006D9AE8[i].nY - gnGlobal_007A285C;
        Unicode* pSecond;
        if (sub_004A7660_SplitAtNewLine(wszText, &pSecond))
        {
            sub_004A7080(nLeft, nY - 4, nRight, wszText, 0);
            sub_004A7080(nLeft, nY + 4, nRight, pSecond, 0);
        }
        else if (nRight)
        {
            sub_004A7080(nLeft, nY, nRight, wszText, 0);
        }
        else
        {
            sub_00502320(wszText, nLeft, nY, 0, 0);
        }
    }
    sub_00502EF0(nOldFont);
}

// 0x0048BE00
void __fastcall sub_0048BE00_CutBracketToken(Unicode* pString, const Unicode* pToken)
{
    Unicode wszOpen[2] = { '[', 0 };
    Unicode wszText[100];
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pToken);
    if (pFound)
    {
        pFound += 4;
        const int nLength = sub_00526800(pFound);
        Unicode::strncpy(wszText, pFound, nLength - sub_00526800(sub_00526940_UnicodeStrStr(pFound, wszOpen)));
        sub_005267E0(pString, wszText);
    }
}

// 0x004953C0
int __fastcall sub_004953C0_GetCenteredX(unsigned short nString, int nX)
{
    Unicode wszText[100];
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    return nX - sub_00501820(wszText) / 2;
}

// 0x00493100
void __stdcall sub_00493100_DrawNumber(int nValue, int nX)
{
    Unicode wszConverted[32];
    for (int i = 0; i < 32; ++i)
    {
        wszConverted[i].wChar = 0;
    }
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
    {
        wszText[i].wChar = 0;
    }
    char szNumber[0x20];
    sprintf(szNumber, szIntFormat_006D57BC, nValue);
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszConverted, szNumber, 32);
    Unicode::strncpy(wszText, wszConverted, 32);
    wszText[31].wChar = 0;
    Unicode* pEnd = &wszText[sub_00526800(wszText)];
    while (sub_00501820(wszText) > 0x2E)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    const int nOldFont = sub_00502EF0(6);
    sub_00502320(wszText, nX + 8, 0x37, 0, 0);
    sub_00502EF0(nOldFont);
}

// 0x004967F0
void __cdecl sub_004967F0_LoadPanelCels()
{
    char szPath[0x104];
    gpCellFile_007BEF7C = sub_004520C0_LoadUiCelFile("Panel\\btn");
    const int nLanguage = sub_00525150();
    int bExpansion = 0;
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        bExpansion = 1;
    }
    if (nLanguage >= 6 && nLanguage <= 9)
    {
        if (bExpansion)
        {
            sprintf(szPath, "%s\\UI\\InvChar6", szDataLocal_006D41A8);
        }
        else
        {
            sprintf(szPath, "%s\\UI\\InvChar", szDataLocal_006D41A8);
        }
        gpCellFile_007BEF64 = sub_004788B0(szPath, 0);
    }
    else
    {
        gpCellFile_007BEF64 = sub_004520C0_LoadUiCelFile(bExpansion ? "Panel\\InvChar6" : "Panel\\InvChar");
    }
    gpCellFile_007BEF78 = sub_004520C0_LoadUiCelFile("Panel\\Arrow");
    gpCellFile_007BEF24 = sub_004520C0_LoadUiCelFile("Panel\\Invwarn");
    gpCellFile_007BEF60 = sub_004520C0_LoadUiCelFile("Panel\\DuroIcon");
    gpCellFile_007BEF14 = sub_004520C0_LoadUiCelFile("Panel\\GemSocket");
    gpCellFile_007BEF10 = sub_004520C0_LoadUiCelFile("Panel\\ctrlpnl_popbelt");
    gpCellFile_007BEF68 = sub_004520C0_LoadUiCelFile("Panel\\Hlthmana");
    gpCellFile_007BEF80 = sub_004520C0_LoadUiCelFile("Panel\\overlap");
    gpStateButtonCel_007BEF70 = sub_004520C0_LoadUiCelFile("Panel\\menubutton");
    gpCellFile_007BEF2C = sub_004520C0_LoadUiCelFile("Panel\\menupanel");
    gpCellFile_007BEF20 = sub_004520C0_LoadUiCelFile("Panel\\skillpoints");
    gpGlobal_007BEF0C = sub_004520C0_LoadUiCelFile("Panel\\runbutton");
    gpCellFile_007BEF28 = sub_004520C0_LoadUiCelFile("Panel\\hostilepic");
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
    SRegLoadValue("Diablo II", "Show HP Text", 0, &gdwShowHpText_007BEFDC);
    SRegLoadValue("Diablo II", "Show MP Text", 0, &gdwShowMpText_007BEFE0);
}

// 0x00497300
void __cdecl sub_00497300_DrawKeyBindingPopup()
{
    Unicode wszText[200];
    for (int i = 0; i < 200; ++i)
    {
        wszText[i].wChar = 0;
    }
    Unicode wszKey[30];
    for (int i = 0; i < 30; ++i)
    {
        wszKey[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1053));
    if (sub_00469AA0(0x23, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_0046A530_GetKeyName(0x23, 1));
        sub_00526700(wszText, wszKey);
    }
    if (sub_00469AA0(0x23, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_0046A530_GetKeyName(0x23, 0));
        sub_00526700(wszText, wszKey);
    }
    sub_00502280_SetPopUpText(wszText, gnGlobal_0071146C / 2 - 0x91, gnGlobal_00711470 - 0x17, 0, 1);
}

// 0x00492C20
void __cdecl sub_00492C20_LoadHirelingIcons()
{
    char aszClassIcons[5][32] = {
        "Hireables\\AmazonIcon",
        "Hireables\\SorceressIcon",
        "Hireables\\BarbarianIcon",
        "Hireables\\PaladinIcon",
        "Hireables\\NecromancerIcon",
    };
    char aszExpansionIcons[7][32] = {
        "Hireables\\AssassinIcon",
        "Hireables\\DruidIcon",
    };
    memset(gapHirelingIcons_007BEEB0, 0, sizeof(gapHirelingIcons_007BEEB0));
    int nIcon = 0;
    for (int i = 0; i < 5; ++i, ++nIcon)
    {
        gapHirelingIcons_007BEEB0[nIcon] = sub_004520C0_LoadUiCelFile(aszClassIcons[i]);
    }
    if (sub_00408F20_HasExpansionMpq())
    {
        for (int i = 0; i < 7; ++i, ++nIcon)
        {
            if (!strlen(aszExpansionIcons[i]))
            {
                break;
            }
            gapHirelingIcons_007BEEB0[nIcon] = sub_004520C0_LoadUiCelFile(aszExpansionIcons[i]);
        }
    }
    const int nSize = sgptDataTables->nPetTypeTxtRecordCount * sizeof(D2HirelingIconRecordStrc);
    gpHirelingRecords_007BEEAC = (D2HirelingIconRecordStrc*)sub_0040B430(0, nSize, ".\\UI\\Hireables.cpp", 0x96, 0);
    memset(gpHirelingRecords_007BEEAC, 0, nSize);
}

#include "gen/data/Source/D2Client/00489220_sub_00489220_LoadShopPanelCels.inc"
