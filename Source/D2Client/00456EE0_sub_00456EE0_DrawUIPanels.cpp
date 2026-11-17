extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ViewStrc;
struct D2MsgHandlerEntryStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2UIVarRecordStrc
{
    char unk0x00[0x84];
    int nDrawCloseKind;
};

extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0
extern int gnUIVarCount_0070F9CC;                                                                           // 0x0070F9CC
extern D2UIVarRecordStrc* gpUIVarRecords_00711130[];                                                        // 0x00711130
extern D2MsgHandlerEntryStrc gtUIVar33Handlers_006D62C4[];                                                  // 0x006D62C4
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern unsigned short gwszText_007A2D30[];                                                                  // 0x007A2D30
extern unsigned short gwszText_007A2A78[];                                                                  // 0x007A2A78
extern void* gpGlobal_007A27A0;                                                                             // 0x007A27A0

int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10
void __fastcall sub_00454F30(D2UnitStrc* pUnit);                                                            // 0x00454F30
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_00456300(int nArg1, int nArg2);                                                         // 0x00456300
void __cdecl sub_00494FC0();                                                                                // 0x00494FC0
void __fastcall sub_004B8100(void* pObj);                                                                   // 0x004B8100
void __fastcall sub_004A0E70(D2ViewStrc* pView);                                                            // 0x004A0E70
void __fastcall sub_00453330(D2UnitStrc* pUnit);                                                            // 0x00453330
void __fastcall sub_00464950(void (__fastcall* pfnCallback)(D2UnitStrc*));                                  // 0x00464950
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
void __cdecl sub_0047E3D0();                                                                                // 0x0047E3D0
void __cdecl sub_004A5270();                                                                                // 0x004A5270
void __cdecl sub_00452D20();                                                                                // 0x00452D20
void __cdecl sub_00497FE0();                                                                                // 0x00497FE0
void __cdecl sub_00497E00();                                                                                // 0x00497E00
void __cdecl sub_0045AD60();                                                                                // 0x0045AD60
void __cdecl sub_00455510();                                                                                // 0x00455510
void __cdecl sub_00493340();                                                                                // 0x00493340
void __cdecl sub_00494020();                                                                                // 0x00494020
void __cdecl sub_004929F0();                                                                                // 0x004929F0
void __cdecl sub_0048BC10();                                                                                // 0x0048BC10
void __cdecl sub_004A34F0();                                                                                // 0x004A34F0
void __cdecl sub_0048EDF0();                                                                                // 0x0048EDF0
void __cdecl sub_004B8730();                                                                                // 0x004B8730
void __cdecl sub_00453470();                                                                                // 0x00453470
void __cdecl sub_004AC690();                                                                                // 0x004AC690
void __cdecl sub_004A7D00();                                                                                // 0x004A7D00
void __cdecl sub_0049C3D0();                                                                                // 0x0049C3D0
void __cdecl sub_0049FF10();                                                                                // 0x0049FF10
void __cdecl sub_0049C9C0_DrawPanel20();                                                                    // 0x0049C9C0
void __cdecl sub_00494320();                                                                                // 0x00494320
void __cdecl sub_00494EB0();                                                                                // 0x00494EB0
void __cdecl sub_00499450();                                                                                // 0x00499450
void __cdecl sub_004AA7E0();                                                                                // 0x004AA7E0
void __cdecl sub_00498E90();                                                                                // 0x00498E90
void __cdecl sub_004A64C0();                                                                                // 0x004A64C0
void __cdecl sub_00495180();                                                                                // 0x00495180
void __cdecl sub_004A6B30();                                                                                // 0x004A6B30
void __cdecl sub_004A6A70();                                                                                // 0x004A6A70
void __cdecl sub_004A6E60();                                                                                // 0x004A6E60
void __cdecl sub_004A6DA0();                                                                                // 0x004A6DA0
void __cdecl sub_004A2A80();                                                                                // 0x004A2A80
void __cdecl sub_00498120();                                                                                // 0x00498120
void __cdecl sub_0047F710();                                                                                // 0x0047F710
void __cdecl sub_0047B720();                                                                                // 0x0047B720
void __cdecl sub_004966C0();                                                                                // 0x004966C0
void __cdecl sub_004C0810_DrawUnitNames();                                                                  // 0x004C0810
void __cdecl sub_004B4380();                                                                                // 0x004B4380
void __cdecl sub_004C01E0();                                                                                // 0x004C01E0
void __cdecl sub_00496B10();                                                                                // 0x00496B10
void __cdecl sub_00503000();                                                                                // 0x00503000
void __cdecl sub_00454A70();                                                                                // 0x00454A70
void __cdecl sub_00453060();                                                                                // 0x00453060
void __cdecl sub_004554B0();                                                                                // 0x004554B0
void __cdecl sub_00453B30();                                                                                // 0x00453B30
void __cdecl sub_00453100();                                                                                // 0x00453100
void __cdecl sub_0046C130();                                                                                // 0x0046C130

// 0x00456EE0
void __fastcall sub_00456EE0_DrawUIPanels(D2ViewStrc* pView)
{
    if (gaUIVarStates_007A27C0[18])
        return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        gnGlobal_007A2858 = 0x50;
        gnGlobal_007A285C = -0x3C;
    }
    else
    {
        gnGlobal_007A2858 = 0;
        gnGlobal_007A285C = 0;
    }
    sub_00502280_SetPopUpText(0, 0, 0, 0, 0);
    gwszText_007A2D30[0] = 0;
    gwszText_007A2A78[0] = 0;
    if (gaUIVarStates_007A27C0[9])
        sub_0047E3D0();
    if (gaUIVarStates_007A27C0[11])
        sub_004A5270();
    sub_00454F30(sub_00467A10());
    if (gaUIVarStates_007A27C0[35])
        sub_00452D20();
    if (!gaUIVarStates_007A27C0[1] && !gaUIVarStates_007A27C0[12] && !gaUIVarStates_007A27C0[14])
    {
        sub_00497FE0();
        sub_00497E00();
    }
    if (gaUIVarStates_007A27C0[10] && sub_0045AE90() != 3)
        sub_0045AD60();
    sub_00455510();
    sub_00493340();
    if (gaUIVarStates_007A27C0[19])
        sub_00494020();
    if (gaUIVarStates_007A27C0[36])
        sub_004929F0();
    if (gaUIVarStates_007A27C0[37])
        sub_0048BC10();
    if (gaUIVarStates_007A27C0[15])
        sub_004A34F0();
    if (gaUIVarStates_007A27C0[1] || gaUIVarStates_007A27C0[12] || gaUIVarStates_007A27C0[14] || gaUIVarStates_007A27C0[25]
        || gaUIVarStates_007A27C0[26] || gaUIVarStates_007A27C0[28] || gaUIVarStates_007A27C0[29])
        sub_0048EDF0();
    if (gaUIVarStates_007A27C0[23])
    {
        sub_004B8730();
        sub_0048EDF0();
    }
    sub_00453470();
    if (gaUIVarStates_007A27C0[4])
        sub_004AC690();
    if (gaUIVarStates_007A27C0[2])
        sub_004A7D00();
    if (gaUIVarStates_007A27C0[22])
        sub_0049C3D0();
    if (gpGlobal_007A27A0)
        sub_004B8100(gpGlobal_007A27A0);
    if (gaUIVarStates_007A27C0[16])
        sub_0049FF10();
    if (gaUIVarStates_007A27C0[20])
        sub_0049C9C0_DrawPanel20();
    if (gaUIVarStates_007A27C0[33])
    {
        sub_00494320();
        sub_00494EB0();
    }
    sub_00499450();
    if (gaUIVarStates_007A27C0[3])
        sub_004AA7E0();
    if (gaUIVarStates_007A27C0[31])
        sub_00498E90();
    sub_004A64C0();
    if (gaUIVarStates_007A27C0[34])
        sub_00495180();
    if (gaUIVarStates_007A27C0[6])
        sub_004A6B30();
    else
        sub_004A6A70();
    if (gaUIVarStates_007A27C0[7])
        sub_004A6E60();
    else
        sub_004A6DA0();
    if (gaUIVarStates_007A27C0[17])
        sub_004A2A80();
    sub_00498120();
    if (gaUIVarStates_007A27C0[21])
        sub_0047F710();
    if (gaUIVarStates_007A27C0[5])
        sub_0047B720();
    if (gaUIVarStates_007A27C0[33])
    {
        sub_00456300(0, 0);
        const int bWasOn = gaUIVarStates_007A27C0[33];
        if (sub_00408F20_HasExpansionMpq())
            sub_0044DCC0();
        D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
        if (!gaUIVarStates_007A27C0[33])
        {
            if (sub_004A0000())
                goto done;
            for (int i = 0; i < gnUIVarCount_0070F9CC; ++i)
            {
                if (gaUIVarStates_007A27C0[i] == 1)
                {
                    bool bClose = true;
                    switch (gpUIVarRecords_00711130[i]->nDrawCloseKind)
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
                        goto done;
                    }
                    if (!bClose)
                        goto done;
                }
            }
        }
        {
            D2UnitStrc* pPlayer = sub_00463DD0();
            if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
                gaUIVarStates_007A27C0[33] = gaUIVarStates_007A27C0[33] == 0;
            if (!bWasOn)
            {
                if (gaUIVarStates_007A27C0[33])
                    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtUIVar33Handlers_006D62C4, 5);
            }
            else
            {
                if (!gaUIVarStates_007A27C0[33])
                {
                    sub_00494FC0();
                    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtUIVar33Handlers_006D62C4, 5);
                }
            }
            sub_00468730();
            sub_00468740();
        }
done:
        sub_004966C0();
    }
    if (gaUIVarStates_007A27C0[13] && sub_0045AE90() != 3)
    {
        sub_004C0810_DrawUnitNames();
        if (sub_0044DB30())
            sub_00464950(sub_00453330);
    }
    if (gaUIVarStates_007A27C0[8])
        sub_004B4380();
    if (gaUIVarStates_007A27C0[14])
        sub_004C01E0();
    sub_00496B10();
    sub_004A0E70(pView);
    sub_00503000();
    sub_00454A70();
    sub_00453060();
    sub_004554B0();
    sub_00453B30();
    sub_00453100();
    sub_0046C130();
}

#include "gen/data/Source/D2Client/00456EE0_sub_00456EE0_DrawUIPanels.inc"
