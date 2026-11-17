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
    char unk0x00[0x54];
    int nCloseKind;
};

struct D2MsgHandlerEntryStrc;

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740

int gbMiniPanel_007A2814;                                                                                   // 0x007A2814
extern int gnUIVarCount_0070F9CC;                                                                           // 0x0070F9CC
extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0
extern D2UIVarRecordStrc* gpUIVarRecords_00711130[];                                                        // 0x00711130
extern D2MsgHandlerEntryStrc gtMiniPanelHandlers_006D6204[];                                                // 0x006D6204

// 0x004567F0
void __cdecl sub_004567F0_ToggleMiniPanel()
{
    unsigned long dwValue;
    if (SRegLoadValue("Diablo II", "Mini Panel", 1, &dwValue) && dwValue)
        return;
    const int bWasOn = gbMiniPanel_007A2814;
    if (sub_00408F20_HasExpansionMpq())
        sub_0044DCC0();
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    if (!gbMiniPanel_007A2814)
    {
        if (sub_004A0000())
            return;
        for (int i = 0; i < gnUIVarCount_0070F9CC; ++i)
        {
            if (gaUIVarStates_007A27C0[i] == 1)
            {
                bool bClose = true;
                switch (gpUIVarRecords_00711130[i]->nCloseKind)
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
                    return;
                }
                if (!bClose)
                    return;
            }
        }
    }
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
        gbMiniPanel_007A2814 = gbMiniPanel_007A2814 == 0;
    if (!bWasOn)
    {
        if (gbMiniPanel_007A2814)
            sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtMiniPanelHandlers_006D6204, 2);
    }
    else
    {
        if (!gbMiniPanel_007A2814)
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtMiniPanelHandlers_006D6204, 2);
    }
    sub_00468730();
    sub_00468740();
}

#include "gen/data/Source/D2Client/004567F0_sub_004567F0_ToggleMiniPanel.inc"
