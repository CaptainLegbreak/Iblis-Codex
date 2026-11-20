#include "D2Client.h"
#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


struct D2UIVarRecordStrc
{
    int anCloseKind[0x26];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __cdecl sub_0044B850_IsHardcore();                                                                      // 0x0044B850
void __cdecl sub_0044B860();                                                                                // 0x0044B860
void __fastcall sub_0044B880_SetValue(int nValue);                                                          // 0x0044B880
void __cdecl sub_0044D520();                                                                                // 0x0044D520
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void __fastcall sub_00455720_OpenUIVar(int nUIVar);                                                         // 0x00455720
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode);                                                      // 0x0045AEA0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_00468770(int nA, int nB);                                                               // 0x00468770
void __fastcall sub_00478590(char nValue);                                                                  // 0x00478590
void __cdecl sub_0047BDC0();                                                                                // 0x0047BDC0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
int __cdecl sub_004A0000();                                                                                 // 0x004A0000
void __cdecl sub_004A5DE0();                                                                                // 0x004A5DE0
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
int __cdecl sub_004B85E0();                                                                                 // 0x004B85E0

extern const int gaUIVarDefaults_006D6378[];                                                                // 0x006D6378
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gdwGlobal_007A0618;                                                                              // 0x007A0618
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
unsigned long gdwUIVarTick_007A2790;                                                                        // 0x007A2790
extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                    // 0x00455F20

// 0x00453910
static int sub_00453910_CanSetUIVar(int nUIVar, int nState)
{
    D2_ASSERT(gnUIVarCount_0070F9CC == 0x26, 0x1397);
    if (nState == 0 || (nState == 2 && !gaUIVarStates_007A27C0[nUIVar]))
    {
        if (nUIVar == 0x05 || nUIVar == 0x09)
        {
            if (sub_004B85E0() && nUIVar == 0x05 && !gaUIVarStates_007A27C0[0x18])
            {
                return 0;
            }
            if (gdwUIVarTick_007A2790 > GetTickCount())
            {
                return 0;
            }
            if (nUIVar == 0x09)
            {
                D2UnitStrc* pPlayer = sub_00463DD0();
                if (!pPlayer)
                {
                    return 0;
                }
                if (pPlayer->dwUnitType == 0 && pPlayer->dwAnimMode == 0x11)
                {
                    sub_004647D0(pPlayer);
                    sub_00478590(0x41);
                    if (sub_0044B850_IsHardcore())
                    {
                        sub_00477EE0();
                        gdwGlobal_007A061C = 0;
                        gdwGlobal_007A0618 = 0;
                        sub_0044B860();
                        sub_0044B880_SetValue(0);
                        sub_0044D520();
                    }
                    return 0;
                }
            }
        }
        if (sub_004A0000() && nUIVar != 0x0A && nUIVar != 0x13 && nUIVar != 0x11 && nUIVar != 0x06 && nUIVar != 0x07)
        {
            return 0;
        }
        for (int i = 0; i < gnUIVarCount_0070F9CC; i++)
        {
            if (gaUIVarStates_007A27C0[i] == 1)
            {
                switch (gpUIVarRecords_00711130[i]->anCloseKind[nUIVar])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (sub_004B3230_GetTickPair(&nLow))
                    {
                        sub_004B3C20(nLow);
                    }
                    break;
                }
                case 1:
                    sub_00455F20(i, 1, 0);
                    break;
                case 2:
                    return 0;
                default:
                    D2_ASSERT(nUIVar, 0x13E6);
                    return 0;
                }
            }
        }
    }
    return 1;
}

// 0x00455F20
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg)
{
    D2_ASSERT(nUIVar < 0x26, 0x13FB);
    D2_ASSERT(nState <= 2, 0x13FC);
    const int nOldState = gaUIVarStates_007A27C0[nUIVar];
    if (!sub_00408F20_HasExpansionMpq() || !sub_0044DCC0())
    {
        if (nUIVar == 0x23 || nUIVar == 0x24 || nUIVar == 0x25)
        {
            return 0;
        }
    }
    if (!sub_00453910_CanSetUIVar(nUIVar, nState))
    {
        return 0;
    }
    D2UnitStrc* pPlayer = sub_00463DD0();
    switch (nState)
    {
    case 0:
        if (!pPlayer || (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer)))
        {
            gaUIVarStates_007A27C0[nUIVar] = 1;
        }
        break;
    case 1:
        gaUIVarStates_007A27C0[nUIVar] = 0;
        break;
    case 2:
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == 0 && !sub_00464820_IsDeadOrDying(pPlayer))
            {
                gaUIVarStates_007A27C0[nUIVar] = !gaUIVarStates_007A27C0[nUIVar];
            }
            else if (nUIVar == 0x05)
            {
                gaUIVarStates_007A27C0[0x05] = !gaUIVarStates_007A27C0[0x05];
            }
        }
        else
        {
            gaUIVarStates_007A27C0[nUIVar] = !gaUIVarStates_007A27C0[nUIVar];
        }
        break;
    }

    const int nNewState = gaUIVarStates_007A27C0[nUIVar];
    if (!nOldState)
    {
        if (nNewState)
        {
            sub_00455720_OpenUIVar(nUIVar);
            if (nUIVar == 0x05)
            {
                sub_0047BDC0();
            }
        }
    }
    else if (!nNewState)
    {
        sub_00455AE0_CloseUIVar(nUIVar);
    }

    const int nA = sub_00468730();
    const int nB = sub_00468740();
    switch (nUIVar)
    {
    case 14:
        if (nNewState)
        {
            sub_0045AEA0_SetPanelSlide(1);
        }
        else
        {
            sub_0045AEA0_SetPanelSlide(0);
        }
        break;
    case 12:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 32:
        if (nNewState)
        {
            sub_0045AEA0_SetPanelSlide(3);
        }
        else
        {
            sub_0045AEA0_SetPanelSlide(0);
        }
        break;
    case 11:
        if (!nNewState)
        {
            sub_004A5DE0();
        }
        break;
    case 1:
        sub_00487990_ResetHover();

    case 4:
        if (!gaUIVarStates_007A27C0[2] && !gaUIVarStates_007A27C0[0x14] && !gaUIVarStates_007A27C0[0xF] && !gaUIVarStates_007A27C0[0x10]
            && !gaUIVarStates_007A27C0[0x24] && !gaUIVarStates_007A27C0[0x25] && !gaUIVarStates_007A27C0[0x16])
        {
            if (nNewState)
            {
                sub_0045AEA0_SetPanelSlide(1);
                if (nArg && nA > gnGlobal_0071146C / 4)
                {
                    sub_00468770(nA - gnGlobal_0071146C / 4, nB);
                }
            }
            else
            {
                sub_0045AEA0_SetPanelSlide(0);
                if (nArg && nA < gnGlobal_0071146C / 2)
                {
                    sub_00468770(gnGlobal_0071146C / 4 + nA, nB);
                }
            }
        }
        else if (nNewState)
        {
            sub_0045AEA0_SetPanelSlide(3);
        }
        else
        {
            sub_0045AEA0_SetPanelSlide(2);
        }
        break;
    case 2:
    case 15:
    case 16:
    case 20:
    case 22:
    case 36:
    case 37:
        if (!gaUIVarStates_007A27C0[1] && !gaUIVarStates_007A27C0[4])
        {
            if (nNewState)
            {
                sub_0045AEA0_SetPanelSlide(2);
                if (nArg && nA < gnGlobal_0071146C - gnGlobal_0071146C / 4)
                {
                    sub_00468770(gnGlobal_0071146C / 4 + nA, nB);
                }
            }
            else
            {
                sub_0045AEA0_SetPanelSlide(0);
                if (nArg && nA > gnGlobal_0071146C / 2)
                {
                    sub_00468770(nA - gnGlobal_0071146C / 4, nB);
                }
            }
        }
        else if (nNewState)
        {
            sub_0045AEA0_SetPanelSlide(3);
        }
        else
        {
            sub_0045AEA0_SetPanelSlide(1);
        }
        break;
    }
    return 1;
}

// 0x00456300
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2)
{
    int bResult = 0;
    for (int i = 0; i < 0x26; i++)
    {
        if (gaUIVarStates_007A27C0[i] == 1 && (gaUIVarDefaults_006D6378[i] == 1 || (bArg1 && i == 0x0A)))
        {
            sub_00455F20(i, 1, nArg2);
            bResult = 1;
            if (i == 0x19 || i == 1)
            {
                sub_00487990_ResetHover();
            }
        }
    }
    return bResult;
}

#include "gen/data/Source/D2Client/UI/ui_00453910.inc"
