#include "D2Launch.h"

struct Unicode
{
    unsigned short wChar;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x80];
    void (__fastcall* pfnSlot80)(int* pValue);
};

struct D2LaunchRecordStrc
{
    char unk0x000[0x19];
    char aState19[4];
    char aWord1D[2];
    char unk0x01F[0x18];
    char szName[0x10];
    char unk0x047[0x76];
    char szCharName[0x18];
    char nByteD5;
    char unk0x0D6[0x17];
    char aDataED[0x101];
    char nClass;
    char aFlags1EF[2];
    char unk0x1F1[0x18];
    char aState209[4];
    char unk0x20D[0x16];
    char bFlag223;
    char unk0x224[9];
    char nByte22D;
    char unk0x22E[0x130];
    char nByte35E;
    char unk0x35F[0x42];
    char aData3A1[0x10];
    char aData3B1[0x10];
    char nByte3C1;
    char nByte3C2;
    char unk0x3C3[8];
    char aWord3CB[2];
};
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
void __cdecl sub_0042FDD0();                                                                                // 0x0042FDD0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0042F6E0();                                                                                // 0x0042F6E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
void __cdecl sub_004317D0_FlushInput();                                                                     // 0x004317D0
void __cdecl sub_00430520();                                                                                // 0x00430520
void __stdcall sub_004313D0(int nLevel);                                                                    // 0x004313D0
void __cdecl sub_00431AF0();                                                                                // 0x00431AF0
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchCallback pfnDone, int nArg);         // 0x00433380
void __cdecl sub_004365B0_CreateCharacter();                                                                                // 0x004365B0
void __cdecl sub_0043B080_InitCharSelectScreen();                                                                                // 0x0043B080
void __cdecl sub_0043B9A0();                                                                                // 0x0043B9A0
void __fastcall sub_0043C6A0(int bSet);                                                                     // 0x0043C6A0
void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
int __fastcall sub_004F9190();                                                            // 0x004F9190
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
void __stdcall sub_00525260(void* pOut, int nField);                                                 // 0x00525260
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
extern D2WinControlStrc* gpOkButton_00779330;                                                               // 0x00779330
extern D2WinControlStrc* gpControl_007795AC;                                                                // 0x007795AC
extern int gbConnected_0077959C;                                                                            // 0x0077959C
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern int gbFeCharPalette_007795F0;                                                                        // 0x007795F0
extern char gszAddress_007795F8[];                                                                          // 0x007795F8
extern D2WinControlStrc* gpAddressEdit_00779958;                                                            // 0x00779958
extern int gbPaletteBusy_00779970;                                                                          // 0x00779970
extern int gbFlag_00779984;                                                                                 // 0x00779984
extern int gdwGlobal_00779974;                                                                              // 0x00779974
extern D2WinControlStrc* gpStatusText_007799A8;                                                             // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC;                                                            // 0x007799AC
extern int gnStatusStringId_007799B0;                                                                       // 0x007799B0
extern unsigned long gdwStatusStart_007799B8;                                                               // 0x007799B8
D2CellFileStrc* gpCellFile_007796F8;                                                                        // 0x007796F8
D2CellFileStrc* gpCellFile_007796FC;                                                                        // 0x007796FC
D2CellFileStrc* gpCellFile_00779704;                                                                        // 0x00779704
D2CellFileStrc* gpCellFile_00779708;                                                                        // 0x00779708
D2CellFileStrc* gpCellFile_0077970C;                                                                        // 0x0077970C
D2CellFileStrc* gpCellFile_00779710;                                                                        // 0x00779710
D2CellFileStrc* gpCellFile_00779714;                                                                        // 0x00779714
D2CellFileStrc* gpCellFile_00779718;                                                                        // 0x00779718
D2CellFileStrc* gpCellFile_0077971C;                                                                        // 0x0077971C
D2CellFileStrc* gpCellFile_00779720;                                                                        // 0x00779720
D2CellFileStrc* gpCellFile_0077972C;                                                                        // 0x0077972C
D2CellFileStrc* gpCellFile_00779730;                                                                        // 0x00779730
D2CellFileStrc* gpCellFile_00779734;                                                                        // 0x00779734
D2CellFileStrc* gpCellFile_00779738;                                                                        // 0x00779738
D2CellFileStrc* gpCellFile_0077973C;                                                                        // 0x0077973C
D2CellFileStrc* gpCellFile_00779740;                                                                        // 0x00779740
D2CellFileStrc* gpCellFile_00779748;                                                                        // 0x00779748
D2CellFileStrc* gpCellFile_0077974C;                                                                        // 0x0077974C
D2CellFileStrc* gpCellFile_00779750;                                                                        // 0x00779750
D2CellFileStrc* gpCellFile_00779754;                                                                        // 0x00779754
D2CellFileStrc* gpCellFile_00779758;                                                                        // 0x00779758
D2CellFileStrc* gpCellFile_0077975C;                                                                        // 0x0077975C
D2CellFileStrc* gpCellFile_00779764;                                                                        // 0x00779764
D2CellFileStrc* gpCellFile_00779768;                                                                        // 0x00779768
D2CellFileStrc* gpCellFile_0077976C;                                                                        // 0x0077976C
D2CellFileStrc* gpCellFile_00779770;                                                                        // 0x00779770
D2CellFileStrc* gpCellFile_00779774;                                                                        // 0x00779774
D2CellFileStrc* gpCellFile_00779778;                                                                        // 0x00779778
D2CellFileStrc* gpCellFile_0077977C;                                                                        // 0x0077977C
D2CellFileStrc* gpCellFile_00779780;                                                                        // 0x00779780
D2CellFileStrc* gpCellFile_00779784;                                                                        // 0x00779784
D2CellFileStrc* gpCellFile_00779788;                                                                        // 0x00779788
D2CellFileStrc* gpCellFile_0077978C;                                                                        // 0x0077978C
D2CellFileStrc* gpCellFile_00779790;                                                                        // 0x00779790
D2CellFileStrc* gpCellFile_00779794;                                                                        // 0x00779794
D2CellFileStrc* gpCellFile_00779798;                                                                        // 0x00779798
D2CellFileStrc* gpCellFile_0077979C;                                                                        // 0x0077979C
D2CellFileStrc* gpCellFile_007797A0;                                                                        // 0x007797A0
D2CellFileStrc* gpCellFile_007797A4;                                                                        // 0x007797A4
D2CellFileStrc* gpCellFile_007797A8;                                                                        // 0x007797A8
D2CellFileStrc* gpCellFile_007797AC;                                                                        // 0x007797AC
D2CellFileStrc* gpCellFile_007797B0;                                                                        // 0x007797B0
D2CellFileStrc* gpCellFile_007797B4;                                                                        // 0x007797B4
D2CellFileStrc* gpCellFile_007797B8;                                                                        // 0x007797B8
D2CellFileStrc* gpCellFile_007797C8;                                                                        // 0x007797C8
D2CellFileStrc* gpCellFile_007797CC;                                                                        // 0x007797CC
D2CellFileStrc* gpCellFile_007797D0;                                                                        // 0x007797D0
D2CellFileStrc* gpCellFile_007797D4;                                                                        // 0x007797D4
D2CellFileStrc* gpCellFile_007797D8;                                                                        // 0x007797D8
D2CellFileStrc* gpCellFile_007797DC;                                                                        // 0x007797DC

extern D2CellFileStrc* gpCellFile_00779724;                                                                 // 0x00779724
extern D2CellFileStrc* gpCellFile_00779728;                                                                 // 0x00779728
extern D2CellFileStrc* gpCellFile_00779744;                                                                 // 0x00779744
extern D2CellFileStrc* gpCellFile_007797BC;                                                                 // 0x007797BC
extern D2CellFileStrc* gpCellFile_007797C0;                                                                 // 0x007797C0
extern D2CellFileStrc* gpCellFile_007797C4;                                                                 // 0x007797C4
D2CellFileStrc* gpCellFile_007797E0;                                                                        // 0x007797E0
extern D2CellFileStrc* gpCellFile_007797E4;                                                                 // 0x007797E4
extern D2CellFileStrc* gpCellFile_007797E8;                                                                 // 0x007797E8
extern D2CellFileStrc* gpCellFile_007797EC;                                                                 // 0x007797EC
extern D2CellFileStrc* gpCellFile_007797F0;                                                                 // 0x007797F0
D2CellFileStrc* gpCellFile_007797F4;                                                                        // 0x007797F4
extern D2CellFileStrc* gpCellFile_007797F8;                                                                 // 0x007797F8
extern D2CellFileStrc* gpCellFile_007797FC;                                                                 // 0x007797FC
extern D2CellFileStrc* gpCellFile_00779800;                                                                 // 0x00779800
extern D2CellFileStrc* gpCellFile_00779804;                                                                 // 0x00779804
D2CellFileStrc* gpCellFile_00779808;                                                                        // 0x00779808
extern D2CellFileStrc* gpCellFile_0077980C;                                                                 // 0x0077980C
extern D2CellFileStrc* gpCellFile_00779810;                                                                 // 0x00779810
extern D2CellFileStrc* gpCellFile_00779814;                                                                 // 0x00779814
extern D2CellFileStrc* gpCellFile_00779818;                                                                 // 0x00779818
D2CellFileStrc* gpCellFile_0077981C;                                                                        // 0x0077981C
extern D2CellFileStrc* gpCellFile_00779820;                                                                 // 0x00779820
extern D2CellFileStrc* gpCellFile_00779824;                                                                 // 0x00779824
extern D2CellFileStrc* gpCellFile_00779828;                                                                 // 0x00779828
extern D2CellFileStrc* gpCellFile_0077982C;                                                                 // 0x0077982C
D2CellFileStrc* gpCellFile_00779830;                                                                        // 0x00779830
extern D2CellFileStrc* gpCellFile_00779834;                                                                 // 0x00779834
extern D2CellFileStrc* gpCellFile_00779838;                                                                 // 0x00779838
extern D2CellFileStrc* gpCellFile_0077983C;                                                                 // 0x0077983C
extern D2CellFileStrc* gpCellFile_00779840;                                                                 // 0x00779840
D2CellFileStrc* gpCellFile_00779844;                                                                        // 0x00779844
extern D2CellFileStrc* gpCellFile_00779848;                                                                 // 0x00779848
extern D2CellFileStrc* gpCellFile_0077984C;                                                                 // 0x0077984C
extern D2CellFileStrc* gpCellFile_00779850;                                                                 // 0x00779850
extern D2CellFileStrc* gpCellFile_00779854;                                                                 // 0x00779854
D2CellFileStrc* gpCellFile_00779858;                                                                        // 0x00779858
extern D2CellFileStrc* gpCellFile_0077985C;                                                                 // 0x0077985C
extern D2CellFileStrc* gpCellFile_00779860;                                                                 // 0x00779860
extern D2CellFileStrc* gpCellFile_00779864;                                                                 // 0x00779864
extern D2CellFileStrc* gpCellFile_00779868;                                                                 // 0x00779868
D2CellFileStrc* gpCellFile_00779888;                                                                        // 0x00779888
extern D2CellFileStrc* gpCellFile_0077988C;                                                                 // 0x0077988C
extern D2CellFileStrc* gpCellFile_00779890;                                                                 // 0x00779890
D2CellFileStrc* gpCellFile_0077989C;                                                                        // 0x0077989C
extern D2CellFileStrc* gpCellFile_007798A0;                                                                 // 0x007798A0
extern D2CellFileStrc* gpCellFile_007798A4;                                                                 // 0x007798A4
extern D2CellFileStrc* gpCellFile_007798B0;                                                                 // 0x007798B0
extern D2CellFileStrc* gpCellFile_007798C4;                                                                 // 0x007798C4
// 0x0042E6D0
void __cdecl sub_0042E6D0_LoadFrontEndCells()
{
    char szPath[0x104];
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\blizno", szDataGlobal_006D4118);
    gpCellFile_007796F8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademarkscreenEXP", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademark", szDataGlobal_006D4118);
    gpCellFile_007796FC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\ohand", szDataGlobal_006D4118);
    gpCellFile_0077971C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\Diablo2", szDataGlobal_006D4118);
    gpCellFile_00779704 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackLeft", szDataGlobal_006D4118);
    gpCellFile_00779708 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireLeft", szDataGlobal_006D4118);
    gpCellFile_0077970C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackRight", szDataGlobal_006D4118);
    gpCellFile_00779710 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireRight", szDataGlobal_006D4118);
    gpCellFile_00779714 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\gameselectscreenEXP", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\TitleScreen", szDataGlobal_006D4118);
    gpCellFile_00779718 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckgexpand", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckg", szDataGlobal_006D4118);
    gpCellFile_00779720 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779738 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank02", szDataGlobal_006D4118);
    gpCellFile_00779754 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779758 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\GWListBox", szDataGlobal_006D4118);
    gpCellFile_0077975C = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselectbutton", szDataGlobal_006D4118);
        gpCellFile_0077972C = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\TallButtonBlank", szDataGlobal_006D4118);
        gpCellFile_00779730 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\characterselectscreenEXP", szDataGlobal_006D4118);
        gpCellFile_00779734 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelectionEXP", szDataGlobal_006D4118);
        gpCellFile_00779774 = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077973C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\ShortButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779740 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox2", szDataGlobal_006D4118);
    gpCellFile_00779748 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\3WideButtonBlank", szDataGlobal_006D4118);
    gpCellFile_0077974C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TermsofUseBckg", szDataGlobal_006D4118);
    gpCellFile_00779764 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbckg", szDataGlobal_006D4118);
    gpCellFile_00779768 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\DifficultyLevels", szDataGlobal_006D4118);
    gpCellFile_0077976C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelection", szDataGlobal_006D4118);
    gpCellFile_00779770 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbox", szDataGlobal_006D4118);
    gpCellFile_00779778 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectboxgrey", szDataGlobal_006D4118);
    gpCellFile_0077977C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\CreateNewCharImage", szDataGlobal_006D4118);
    gpCellFile_00779794 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK", szDataGlobal_006D4118);
    gpCellFile_00779798 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUp_340x224", szDataGlobal_006D4118);
    gpCellFile_0077979C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpWide", szDataGlobal_006D4118);
    gpCellFile_007797A0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpLargest", szDataGlobal_006D4118);
    gpCellFile_007797A4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TileableDialog", szDataGlobal_006D4118);
    gpCellFile_007797A8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK2", szDataGlobal_006D4118);
    gpCellFile_007797AC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel", szDataGlobal_006D4118);
    gpCellFile_00779780 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel2", szDataGlobal_006D4118);
    gpCellFile_00779784 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\OkCancelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_007797B0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CancelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_007797B4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\selectchararrows", szDataGlobal_006D4118);
    gpCellFile_00779788 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselect", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CurRealm", szDataGlobal_006D4118);
    gpCellFile_0077978C = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\RealmSelectbuttonthin", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank02", szDataGlobal_006D4118);
    gpCellFile_00779790 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\password", szDataGlobal_006D4118);
    gpCellFile_007797B8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\realmbckg", szDataGlobal_006D4118);
    gpCellFile_007797C8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", szDataGlobal_006D4118);
    gpCellFile_007797CC = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipscreen", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipbckg", szDataGlobal_006D4118);
    gpCellFile_007797D0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\IPAddressBox", szDataGlobal_006D4118);
    gpCellFile_007797D4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchbckg", szDataGlobal_006D4118);
    gpCellFile_007797D8 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchball2", szDataGlobal_006D4118);
    gpCellFile_007797DC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\EditTextBoxWide", szDataGlobal_006D4118);
    gpCellFile_00779750 = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x0042F2E0
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2)
{
    char szPathA[0x104];
    char szPathB[0x104];
    gbPaletteBusy_00779970 = 1;
    wsprintfA(szPathA, gszPathFormat_006D4124, szDataGlobal_006D4118, szFile1);
    wsprintfA(szPathB, gszPathFormat_006D4124, szDataGlobal_006D4118, szFile2);
    gbFeCharPalette_007795F0 = strcmp(szFile1, "palette\\fechar\\pal.dat") == 0;
    sub_004FB500(szPathA, szPathB);
    return 1;
}

// 0x0042FA40
int __cdecl sub_0042FA40_InitAuxBattleNet()
{
    char szAddress[0x64];
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        return 1;
    sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    return 0;
}

// 0x0042FAB0
int __cdecl sub_0042FAB0_GetAuxFlag()
{
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        d = 0x22;
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
        unsigned char nLow = (unsigned char)d;
        if (nLow & 0x10)
            return (unsigned char)~nLow >> 7;
    }
    return 0;
}

// 0x00430620
void __cdecl sub_00430620_UpdateNameOk()
{
    char szText[0x20];
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    int bValid = 0;
    if (pText)
    {
        const int nLen = sub_00526800(pText);
        sub_005263E0(szText, pText, 0x20);
        if (nLen >= 2 && nLen <= 15)
        {
            const char cLast = szText[nLen - 1];
            const char cFirst = szText[0];
            if (cLast != '_' && cFirst != '_' && cLast != '-' && cFirst != '-')
            {
                int nCount = 0;
                for (int i = 0; i < nLen; i += 1)
                {
                    if (szText[i] == '-' || szText[i] == '_')
                        nCount += 1;
                }
                if (nCount < 2)
                    bValid = 1;
            }
        }
    }
    sub_004F96F0_ControlClearState(gpOkButton_00779330, bValid);
}

// 0x00430BC0
int __cdecl sub_00430BC0_HasSaveFiles()
{
    char szDir[0x400];
    char szPattern[0x400];
    D2FindDataStrc tFind;
    sub_00407050_GetSavePath(szDir, 0x400);
    sprintf(szPattern, gszSaveMask_006D41D4, szDir);
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        FindClose(hFind);
        return 1;
    }
    return 0;
}

// 0x00431600
int __stdcall sub_00431600_ShowLevelScreen(int nUnused)
{
    char szAddress[0x64];
    unsigned char nLevel;
    sub_00515F50(0xB4);
    sub_00514930();
    sub_00515CE0_SetMasterVolume(0xFF);
    sub_0043C4F0();
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        int a;
        int b;
        int c;
        int d = 0x22;
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
        const unsigned char nLow = (unsigned char)d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 1;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_004313D0(nLevel);
        return 1;
    }
    sub_0042F430_CreateControl(0x32);
    D2WinControlStrc* pTitle = sub_0042F430_CreateControl(0x33);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    sub_0042F430_CreateControl(0x34);
    D2WinControlStrc* pField1 = sub_0042F430_CreateControl(0x35);
    D2WinControlStrc* pField2 = sub_0042F430_CreateControl(0x36);
    D2WinControlStrc* pField3 = sub_0042F430_CreateControl(0x37);
    D2WinControlStrc* pField4 = sub_0042F430_CreateControl(0x38);
    switch (nLevel)
    {
    default:
        sub_004F96F0_ControlClearState(pField1, 0);
    case 2:
        sub_004F96F0_ControlClearState(pField2, 0);
    case 3:
        sub_004F96F0_ControlClearState(pField3, 0);
    case 4:
        sub_004F96F0_ControlClearState(pField4, 0);
    case 5:
    case 6:
    case 7:
        break;
    }
    sub_0042F430_CreateControl(0x39);
    return 1;
}

// build: context sub_00431F70_SaveExists
int __cdecl sub_00431F70_SaveExists()
{
    char szDir[0x400];
    char szUtf8[0x100];
    char szPath[0x100];
    char szName[0x100];
    sub_00407050_GetSavePath(szDir, 0x400);
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szUtf8, pText, 0x100);
    sprintf(szName, gszStringFormat_006FFC58, szUtf8);
    sprintf(szPath, gszSavePathFormat_006D4230, szDir, szName);
    void* hFile = sub_00406960_CreateFile(szPath, 0x80000000, 0, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        sub_004069A0_CloseFile(hFile);
        return 1;
    }
    return 0;
}

// 0x004326F0
void __cdecl sub_004326F0_LoadFrontEndCells2()
{
    char szPath[0x104];
    if (gpCellFile_00779724)
        return;
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumSelButtonBlank", szDataGlobal_006D4118);
    gpCellFile_00779744 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\charactercreationscreenEXP", szDataGlobal_006D4118);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CharacterCreate", szDataGlobal_006D4118);
    gpCellFile_00779724 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\fire", szDataGlobal_006D4118);
    gpCellFile_00779728 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox", szDataGlobal_006D4118);
    gpCellFile_007797BC = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\clickbox", szDataGlobal_006D4118);
    gpCellFile_007797C0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (sub_00408F20_HasExpansionMpq())
    {
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\joingameclickboxgrey", szDataGlobal_006D4118);
        gpCellFile_007797C4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu1", szDataGlobal_006D4118);
        gpCellFile_007797E0 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu2", szDataGlobal_006D4118);
        gpCellFile_007797E4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asfw", szDataGlobal_006D4118);
        gpCellFile_007797E8 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu3", szDataGlobal_006D4118);
        gpCellFile_007797EC = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asbw", szDataGlobal_006D4118);
        gpCellFile_007797F0 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu1", szDataGlobal_006D4118);
        gpCellFile_007797F4 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu2", szDataGlobal_006D4118);
        gpCellFile_007797F8 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzfw", szDataGlobal_006D4118);
        gpCellFile_007797FC = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu3", szDataGlobal_006D4118);
        gpCellFile_00779800 = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzbw", szDataGlobal_006D4118);
        gpCellFile_00779804 = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu1", szDataGlobal_006D4118);
    gpCellFile_00779808 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu2", szDataGlobal_006D4118);
    gpCellFile_0077980C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amfw", szDataGlobal_006D4118);
    gpCellFile_00779810 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu3", szDataGlobal_006D4118);
    gpCellFile_00779814 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\ambw", szDataGlobal_006D4118);
    gpCellFile_00779818 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu1", szDataGlobal_006D4118);
    gpCellFile_0077981C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu2", szDataGlobal_006D4118);
    gpCellFile_00779820 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefw", szDataGlobal_006D4118);
    gpCellFile_00779824 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3", szDataGlobal_006D4118);
    gpCellFile_00779828 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebw", szDataGlobal_006D4118);
    gpCellFile_0077982C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu1", szDataGlobal_006D4118);
    gpCellFile_00779830 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu2", szDataGlobal_006D4118);
    gpCellFile_00779834 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafw", szDataGlobal_006D4118);
    gpCellFile_00779838 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu3", szDataGlobal_006D4118);
    gpCellFile_0077983C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\babw", szDataGlobal_006D4118);
    gpCellFile_00779840 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu1", szDataGlobal_006D4118);
    gpCellFile_00779844 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu2", szDataGlobal_006D4118);
    gpCellFile_00779848 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofw", szDataGlobal_006D4118);
    gpCellFile_0077984C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3", szDataGlobal_006D4118);
    gpCellFile_00779850 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobw", szDataGlobal_006D4118);
    gpCellFile_00779854 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu1", szDataGlobal_006D4118);
    gpCellFile_00779858 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu2", szDataGlobal_006D4118);
    gpCellFile_0077985C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafw", szDataGlobal_006D4118);
    gpCellFile_00779860 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu3", szDataGlobal_006D4118);
    gpCellFile_00779864 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pabw", szDataGlobal_006D4118);
    gpCellFile_00779868 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofws", szDataGlobal_006D4118);
    gpCellFile_0077989C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3s", szDataGlobal_006D4118);
    gpCellFile_007798A0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobws", szDataGlobal_006D4118);
    gpCellFile_007798A4 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefws", szDataGlobal_006D4118);
    gpCellFile_00779888 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3s", szDataGlobal_006D4118);
    gpCellFile_0077988C = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebws", szDataGlobal_006D4118);
    gpCellFile_00779890 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafws", szDataGlobal_006D4118);
    gpCellFile_007798B0 = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafws", szDataGlobal_006D4118);
    gpCellFile_007798C4 = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x004334E0
void __cdecl sub_004334E0_PlayIntro()
{
    char szPath[0x104];
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d;
    void* hFile;
    char szLanguage[4];
    char szSize[8];
    sub_004317D0_FlushInput();
    int nMode = 0;
    if (!sub_0040EB10())
    {
        strcpy(szSize, "640x292");
    }
    else
    {
        nMode = 2;
        strcpy(szSize, "640x146");
    }
    sub_00525260(szLanguage, 0);
    sprintf(szPath, "%s\\video\\%s\\D2x_Intro_%s.bik", gszDataLocal_006D41A8, szLanguage, szSize);
    if (SFileOpenFileEx(0, szPath, 0, &hFile))
        sub_004198D0(hFile);
    else
        sprintf(szPath, "%s\\video\\%s\\D2x_Intro%s.bik", gszDataLocal_006D41A8, "ENG", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
    d |= 0x80;
    sprintf(szAddress, "%d.%d.%d.%ld", 0xD8, 0x94, 0xF6, d);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
}

// 0x004336C0
void __cdecl sub_004336C0_ShowMainMenu()
{
    char szVersion[0x40];
    D2WinControlStrc* pFirst;
    D2WinControlStrc* pSecond;
    sub_0043B9A0();
    gpLaunchRecord_007795D4->szName[0] = 0;
    sub_0043C4F0();
    if (sub_00408F20_HasExpansionMpq())
    {
        gpControl_007795AC = sub_0042F430_CreateControl(0x12);
        sub_00431AF0();
        pFirst = sub_0042F430_CreateControl(0x11);
        pSecond = sub_0042F430_CreateControl(0x13);
        sub_0042F430_CreateControl(0x10);
    }
    else
    {
        pFirst = sub_0042F430_CreateControl(0x0A);
        gpControl_007795AC = sub_0042F430_CreateControl(0x0B);
        sub_00431AF0();
        sub_0042F430_CreateControl(0x09);
        pSecond = sub_0042F430_CreateControl(0x0C);
    }
    if (sub_004FAC90())
    {
        sub_004F96F0_ControlClearState(pFirst, 0);
        sub_004F96F0_ControlClearState(pSecond, 0);
        sub_004F96F0_ControlClearState(gpControl_007795AC, 0);
    }
    sub_0042F430_CreateControl(0x0D);
    sub_0042F430_CreateControl(0x0E);
    sub_0042F430_CreateControl(0x0F);
    D2WinControlStrc* pText = sub_0042F430_CreateControl(0x115);
    const int nLen = SStrPrintf(szVersion, 0x40, "v %d.%d%c", 1, 0x0E, 0x64);
    if (gpLaunchRecord_007795D4->bFlag223)
        SStrPrintf(&szVersion[nLen], 0x40 - nLen, " %d", 0x47);
    sub_004FCFF0_SetTextA(pText, szVersion, 0);
    if (sub_00514D80())
        D2SOUND_10034(1);
}

// 0x00434790
int __stdcall sub_00434790_JoinTcpIp(int nUnused)
{
    char szText[0x400];
    int a;
    int b;
    int c;
    int d;
    const Unicode* pText = sub_004FDD90_GetEditText(gpAddressEdit_00779958);
    sub_005263E0(szText, pText, 0x100);
    if (!szText[0])
        return 1;
    strncpy(gszAddress_007795F8, szText, 0xFF);
    gszAddress_007795F8[0xFF] = 0;
    SRegSaveString("Diablo II", "LastTcpIp", 0, gszAddress_007795F8);
    if (sscanf(szText, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
    {
        const char* szResolved = FOG_ResolveHostIPAddress(szText);
        if (szResolved)
        {
            strcpy(szText, szResolved);
        }
        else
        {
            sub_004FFE10_SetTextA(gpAddressEdit_00779958, &gszEmptyAssertText);
            return 1;
        }
    }
    strcpy(gpLaunchRecord_007795D4->szName, szText);
    sub_0042F6E0();
    sub_004FA590_RunLoop(sub_00431D10);
    gbConnected_0077959C = 0;
    sub_0052A750(0, szText);
    sub_004FA590_RunLoop(sub_00431E30);
    if (!gbConnected_0077959C)
    {
        sub_0052A7E0();
        sub_0042F3F0_DestroyControls();
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x145B);
        sub_00433380_ShowMessage(pMessage, sub_0042FFE0, 1);
        return 1;
    }
    sub_0042F3F0_DestroyControls();
    sub_0042F6E0();
    sub_004FA590_RunLoop(sub_00431C90);
    sub_0052A7E0();
    sub_0042F3F0_DestroyControls();
    if (!gdwGlobal_00779974)
    {
        gnLaunchMode_007795EC = 2;
        *(int*)gpLaunchRecord_007795D4->aState19 = 9;
        *(unsigned short*)gpLaunchRecord_007795D4->aWord1D = 1;
        sub_00515020();
        sub_0042F480_Reset();
        sub_0043B080_InitCharSelectScreen();
    }
    return 1;
}

// 0x004365B0
void __cdecl sub_004365B0_CreateCharacter()
{
    char szName[0x100];
    if (sub_00431F70_SaveExists() == 1 && gnLaunchMode_007795EC != 1)
    {
        sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x142D), sub_0042F3F0_DestroyControls);
        return;
    }
    if (gpLaunchRecord_007795D4->nClass == 6 || gpLaunchRecord_007795D4->nClass == 5)
        *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF |= 0x20;
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szName, pText, 0x100);
    sprintf(gpLaunchRecord_007795D4->szCharName, gszStringFormat_006FFC58, szName);
    gpLaunchRecord_007795D4->nByteD5 = 0;
    if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
        gbFlag_00779984 = 1;
    if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
    {
        sub_00430520();
        return;
    }
    if (gnLaunchMode_007795EC == 0)
    {
        sub_0042F480_Reset();
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 1;
        *(int*)gpLaunchRecord_007795D4->aState19 = 0;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
    }
    else if (gnLaunchMode_007795EC == 2)
    {
        sub_0042F480_Reset();
        sub_0043C6A0(0);
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
    }
    else if (gnLaunchMode_007795EC == 3)
    {
        sub_0042F480_Reset();
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte3C1 = 1;
        SMemCopy(gpLaunchRecord_007795D4->aData3A1, gabDefault_006D4D88, 0x10);
        SMemZero(gpLaunchRecord_007795D4->aData3B1, 0x10);
        gpLaunchRecord_007795D4->nByte3C2 = (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF >> 6) & 1;
        *(unsigned short*)gpLaunchRecord_007795D4->aWord3CB = *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF;
        gpLaunchRecord_007795D4->nByte35E = 4;
        gpLaunchRecord_007795D4->nByte22D = 0;
        gpLaunchRecord_007795D4->nByteD5 = 0;
        gnLaunchState_007795E8 = 3;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
    }
    else if (gnLaunchMode_007795EC == 1)
    {
        sub_00435E10();
    }
}

// 0x004369F0
int __stdcall sub_004369F0_OkClick(int nUnused)
{
    char szPath[0x400];
    if (sub_004F9710_TestFlags(gpOkButton_00779330))
    {
        sub_00407050_GetSavePath(szPath, 0x400);
        for (unsigned int i = 0; i < 0x400; i += 1)
        {
            if (szPath[i] == '\\')
            {
                szPath[i + 1] = 0;
                break;
            }
        }
        unsigned long nSectorsPerCluster = 0;
        unsigned long nBytesPerSector = 0;
        unsigned long nFreeClusters = 0;
        unsigned long nTotalClusters = 0;
        GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
        if (nFreeClusters * nBytesPerSector * nSectorsPerCluster < 5000)
        {
            sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), sub_0042FDD0);
            return 1;
        }
        sub_004F96F0_ControlClearState(gpOkButton_00779330, 0);
        sub_004365B0_CreateCharacter();
    }
    return 1;
}

// 0x00436AD0
void __cdecl sub_00436AD0_UpdateStatus()
{
    char szText[0x100];
    int nState;
    if (!gpStatusText_007799A8)
        return;
    gpFuncTable_0077ABF0->pfnSlot80(&nState);
    switch (nState)
    {
    case 0:
        gnStatusStringId_007799B0 = 0x1433;
        break;
    case 1:
        gnStatusStringId_007799B0 = 0x1434;
        break;
    case 2:
        gnStatusStringId_007799B0 = 0x1435;
        break;
    case 3:
        gnStatusStringId_007799B0 = 0x1436;
        break;
    case 4:
        gnStatusStringId_007799B0 = 0x1437;
        break;
    case 5:
        gnStatusStringId_007799B0 = 0x1438;
        break;
    case 6:
        gnStatusStringId_007799B0 = 0x1439;
        break;
    default:
        gnStatusStringId_007799B0 = -1;
        break;
    }
    sub_004FB6A0_ClearText(gpStatusText_007799A8);
    if (gnStatusStringId_007799B0 >= 0)
        sub_004FC9B0_SetText(gpStatusText_007799A8, D2LANG_GetStringFromTblIndex(gnStatusStringId_007799B0), 0, 0, 0);
    const unsigned long nCounter = (GetTickCount() - gdwStatusStart_007799B8) / 250 % 20 + 1;
    sprintf(szText, "%.*s", nCounter, "....................");
    sub_004FB6A0_ClearText(gpCounterText_007799AC);
    D2Win_10045(gpCounterText_007799AC, szText);
}
