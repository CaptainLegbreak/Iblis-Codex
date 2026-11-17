typedef unsigned int size_t;

struct D2UnitStrc;

struct Unicode
{
    unsigned short wChar;
};

extern "C" size_t __cdecl strlen(const char* szString);

unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);  // 0x004FB180
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
const char* __fastcall sub_0047A210(D2UnitStrc* pUnit);                                       // 0x0047A210
unsigned int __fastcall sub_005262A0_CountChars(const char* szText, int nLength);                          // 0x005262A0
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);  // 0x004A7080
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __cdecl sub_00499E50_DrawPanelQuad();                                                                  // 0x00499E50
void __cdecl sub_0049C270_DrawPartyRows();                                                                  // 0x0049C270
void __cdecl sub_0049A510_DrawPartyButtons();                                                               // 0x0049A510
void __cdecl sub_0049A950_DrawPanelCel();                                                                   // 0x0049A950
void __cdecl sub_0049ABD0_DrawPartyBoxes();                                                                 // 0x0049ABD0
void __cdecl sub_0049B330_DrawPartyBar();                                                                   // 0x0049B330
void __cdecl sub_0049A9B0_RefreshRosterIndices();                                                           // 0x0049A9B0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gbUiRecordMode_007BEF98;                                                                         // 0x007BEF98
extern int gdwGlobal_007BEFA8;                                                                              // 0x007BEFA8
extern int gdwGlobal_007BEFAC;                                                                              // 0x007BEFAC
void* gpPanelQuadCel_007BF018;                                                                              // 0x007BF018
void* gpCelFile_007BF01C;                                                                                   // 0x007BF01C
extern void* gpCelFile_007BF020;                                                                            // 0x007BF020
void* gpCelFile_007BF024;                                                                                   // 0x007BF024
void* gpCelFile_007BF028;                                                                                   // 0x007BF028
extern unsigned char gbGlobal_007BF034;                                                                     // 0x007BF034

// 0x00498E80
void __cdecl sub_00498E80_ClearPair()
{
    gdwGlobal_007BEFA8 = 0;
    gdwGlobal_007BEFAC = 0;
}

// 0x00498E90
void __cdecl sub_00498E90_SetRecordMode()
{
    gbUiRecordMode_007BEF98 = 1;
}

// 0x00499E10
void __cdecl sub_00499E10_SetRedColour()
{
    gbGlobal_007BF034 = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00499E30
void __cdecl sub_00499E30_SetBlackColour()
{
    gbGlobal_007BF034 = D2Win_10034_MixRGB(0, 0, 0);
}

// 0x0049A580
void __cdecl sub_0049A580_DrawPlayerName()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;
    const char* szName = sub_0047A210(pPlayer);
    if (!szName)
        return;
    unsigned int nLen = sub_005262A0_CountChars(szName, strlen(szName)) + 1;
    if (nLen > 11)
    {
        if (nLen >= 14)
            sub_00502EF0(6);
        else
            sub_00502EF0(0);
    }
    Unicode* wszName = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLen, ".\\UI\\Party.cpp", 0x211, 0);
    sub_00526320_ToUnicode(wszName, szName, nLen);
    sub_004A7080(gnGlobal_007A2858 + 0x14, 0x1F - gnGlobal_007A285C, gnGlobal_007A2858 + 0xBE, wszName, 0);
    sub_00502EF0(0);
    FOG_Free(wszName, ".\\UI\\Party.cpp", 0x21A, 0);
}

// 0x0049C0A0
void __cdecl sub_0049C0A0_LoadPartyCels()
{
    gpPanelQuadCel_007BF018 = sub_004520C0_LoadUiCelFile("Menu\\party");
    gpCelFile_007BF01C = sub_004520C0_LoadUiCelFile("Menu\\partybuttons");
    gpCelFile_007BF020 = sub_004520C0_LoadUiCelFile("Menu\\partyboxes");
    gpCelFile_007BF024 = sub_004520C0_LoadUiCelFile("Panel\\inv_goldbtn");
    gpCelFile_007BF028 = sub_004520C0_LoadUiCelFile("Menu\\partybar");
}

// 0x0049C0F0
void __cdecl sub_0049C0F0_FreePartyCels()
{
    if (gpPanelQuadCel_007BF018)
    {
        sub_00478A00(gpPanelQuadCel_007BF018);
        gpPanelQuadCel_007BF018 = 0;
    }
    if (gpCelFile_007BF01C)
    {
        sub_00478A00(gpCelFile_007BF01C);
        gpCelFile_007BF01C = 0;
    }
    if (gpCelFile_007BF020)
    {
        sub_00478A00(gpCelFile_007BF020);
        gpCelFile_007BF020 = 0;
    }
    if (gpCelFile_007BF024)
    {
        sub_00478A00(gpCelFile_007BF024);
        gpCelFile_007BF024 = 0;
    }
    if (gpCelFile_007BF028)
    {
        sub_00478A00(gpCelFile_007BF028);
        gpCelFile_007BF028 = 0;
    }
}

// 0x0049C3D0
void __cdecl sub_0049C3D0_DrawPartyPanel()
{
    sub_00499E50_DrawPanelQuad();
    sub_0049A580_DrawPlayerName();
    sub_0049C270_DrawPartyRows();
    sub_0049A510_DrawPartyButtons();
    sub_0049A950_DrawPanelCel();
    sub_0049ABD0_DrawPartyBoxes();
    sub_0049B330_DrawPartyBar();
    sub_0049A9B0_RefreshRosterIndices();
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= gnGlobal_007A2858 + 0x116 && nX <= gnGlobal_007A2858 + 0x136 && nY >= 0x185 - gnGlobal_007A285C && nY <= 0x1A5 - gnGlobal_007A285C)
        sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x102F), gnGlobal_007A2858 + 0x125, 0x182 - gnGlobal_007A285C, 0, 1);
}
