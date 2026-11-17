extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2UIVarRecordStrc
{
    int anCloseKind[0x26];
};

struct D2MsgHandlerEntryStrc;
struct D2CellFileStrc;
struct D2UiControlAStrc;
struct D2UiControlBStrc;
struct D2UiControlCStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);    // 0x00451E10
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_004567F0_ToggleMiniPanel();                                                                // 0x004567F0
void __cdecl sub_0045A4C0();                                                                                // 0x0045A4C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __cdecl sub_0046AC70();                                                                                // 0x0046AC70
D2CellFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                             // 0x004788B0
void __cdecl sub_0047DD70_LoadOptionMenus();                                                                // 0x0047DD70
void __cdecl sub_0047F0C0();                                                                                // 0x0047F0C0
void __cdecl sub_004868B0();                                                                                // 0x004868B0
void __cdecl sub_00489220_LoadShopPanelCels();                                                              // 0x00489220
void __cdecl sub_00492C20_LoadHirelingIcons();                                                              // 0x00492C20
void __cdecl sub_004967F0_LoadPanelCels();                                                                  // 0x004967F0
void __cdecl sub_0049C6A0();                                                                                // 0x0049C6A0
void __cdecl sub_0049D440_LoadTextSettings();                                                               // 0x0049D440
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
void __cdecl sub_004A3410();                                                                                // 0x004A3410
void __cdecl sub_004A5190_InitTextSlider();                                                                 // 0x004A5190
void __cdecl sub_004A6460();                                                                                // 0x004A6460
void __cdecl sub_004B23E0_InitPartyPanel();                                                                 // 0x004B23E0
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __cdecl sub_004B7B40();                                                                                // 0x004B7B40
void __cdecl sub_004B8720();                                                                                // 0x004B8720
void __cdecl sub_004BE020_LoadTextSliderCel();                                                              // 0x004BE020
void __cdecl sub_004BF9D0();                                                                                // 0x004BF9D0
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D5F28[];                                                    // 0x006D5F28
extern D2MsgHandlerEntryStrc gtPanelHandlers_006D6300[];                                                    // 0x006D6300
extern int gnUIVarCount_0070F9CC;                                                                           // 0x0070F9CC
extern D2UIVarRecordStrc* gpUIVarRecords_00711130[];                                                        // 0x00711130
extern D2CellFileStrc* gpBoxPiecesCel_007A2798;                                                             // 0x007A2798
extern void* gpGlobal_007A27A0;                                                                             // 0x007A27A0
extern D2UiControlAStrc* gpGoldControlA_007A27A4;                                                           // 0x007A27A4
extern D2UiControlBStrc* gpGoldControlB_007A27A8;                                                           // 0x007A27A8
extern D2UiControlCStrc* gpGoldControlC_007A27AC;                                                           // 0x007A27AC
extern D2UiControlCStrc* gpGoldControlD_007A27B0;                                                           // 0x007A27B0
extern int gbGoldPanelFlag_007A27B4;                                                                        // 0x007A27B4
int gaUIVarStates_007A27C0[1];                                                                              // 0x007A27C0
extern D2CellFileStrc* gpPentspinCel_007A2878;                                                              // 0x007A2878
extern D2CellFileStrc* gpFocus16Cel_007A2880;                                                               // 0x007A2880

// 0x00456970
void __cdecl sub_00456970_InitUI()
{
    char szPath[0x104];
    sub_004967F0_LoadPanelCels();
    sub_0047F0C0();
    sub_0049D440_LoadTextSettings();
    sub_004A6460();
    sub_00492C20_LoadHirelingIcons();
    sub_004B23E0_InitPartyPanel();
    sub_0045A4C0();
    sub_0049C6A0();
    sub_004B8720();
    gpGlobal_007A27A0 = 0;
    gpGoldControlA_007A27A4 = 0;
    gpGoldControlB_007A27A8 = 0;
    gpGoldControlD_007A27B0 = 0;
    gpGoldControlC_007A27AC = 0;
    gbGoldPanelFlag_007A27B4 = 0;
    sub_004868B0();
    for (int i = 0; i < 0x26; i++)
        gaUIVarStates_007A27C0[i] = 0;

    {
        const int bWasOn = gaUIVarStates_007A27C0[0];
        if (sub_00408F20_HasExpansionMpq())
            sub_0044DCC0();
        D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
        if (sub_004A0000())
            goto mini_panel;
        for (int i = 0; i < gnUIVarCount_0070F9CC; ++i)
        {
            if (gaUIVarStates_007A27C0[i] == 1)
            {
                switch (gpUIVarRecords_00711130[i]->anCloseKind[0])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (sub_004B3230_GetTickPair(&nLow))
                        sub_004B3C20(nLow);
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                    goto mini_panel;
                default:
                    D2_ASSERT(false, 0x13E6);
                }
            }
        }
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
            gaUIVarStates_007A27C0[0] = 1;
        if (!bWasOn)
        {
            if (gaUIVarStates_007A27C0[0])
                sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D5F28, 4);
        }
        else
        {
            if (!gaUIVarStates_007A27C0[0])
                sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D5F28, 4);
        }
        sub_00468730();
        sub_00468740();
    }

mini_panel:
    sub_004567F0_ToggleMiniPanel();
    {
        const int bWasOn = gaUIVarStates_007A27C0[0x22];
        if (sub_00408F20_HasExpansionMpq())
            sub_0044DCC0();
        D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
        if (sub_004A0000())
            goto load_cels;
        for (int i = 0; i < gnUIVarCount_0070F9CC; ++i)
        {
            if (gaUIVarStates_007A27C0[i] == 1)
            {
                bool bClose = true;
                switch (gpUIVarRecords_00711130[i]->anCloseKind[0x22])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (sub_004B3230_GetTickPair(&nLow))
                        sub_004B3C20(nLow);
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                case 3:
                    bClose = false;
                    break;
                default:
                    goto load_cels;
                }
                if (!bClose)
                    goto load_cels;
            }
        }
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
            gaUIVarStates_007A27C0[0x22] = 1;
        if (!bWasOn)
        {
            if (gaUIVarStates_007A27C0[0x22])
                sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtPanelHandlers_006D6300, 2);
        }
        else
        {
            if (!gaUIVarStates_007A27C0[0x22])
                sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtPanelHandlers_006D6300, 2);
        }
        sub_00468730();
        sub_00468740();
    }

load_cels:
    wsprintfA(szPath, "%s\\UI\\CURSOR\\Pentspin", szDataGlobal_006D4118);
    gpPentspinCel_007A2878 = sub_004788B0(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\focus16", szDataGlobal_006D4118);
    gpFocus16Cel_007A2880 = sub_004788B0(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\menu\\boxpieces", szDataGlobal_006D4118);
    gpBoxPiecesCel_007A2798 = sub_004788B0(szPath, 0);
    sub_004BF9D0();
    sub_004B7B40();
    sub_00489220_LoadShopPanelCels();
    sub_004BE020_LoadTextSliderCel();
    sub_004A3410();
    sub_0046AC70();
    sub_0047DD70_LoadOptionMenus();
    sub_004A5190_InitTextSlider();
}

#include "gen/data/Source/D2Client/00456970_sub_00456970_InitUI.inc"
