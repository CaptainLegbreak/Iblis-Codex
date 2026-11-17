struct D2WinControlStrc;

struct Unicode
{
    unsigned short wChar;
};

class BNGatewayAccess
{
public:
    const char* __stdcall Name(int nGateway);

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x98];
    BNGatewayAccess* (__cdecl* pfnGetRecord)();
};

void __cdecl sub_0043C4F0();                                                                                // 0x0043C4F0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId);                                           // 0x0042F430
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText);                     // 0x004FD060
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl);                                    // 0x004FB950
int __fastcall D2Win_10055(D2WinControlStrc* pTextBox);                                                     // 0x004FBAB0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine);                                          // 0x004FBA30
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine);                                 // 0x004FB9D0
void __cdecl sub_00431AF0();                                                                                // 0x00431AF0

D2WinControlStrc* gpControl_00779590;                                                                       // 0x00779590
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

// build: symbol ?Name@BNGatewayAccess@@QAGPBDH@Z 0x005180A0
// 0x00434600
int __stdcall sub_00434600_CreateGatewayScreen(int nUnused)
{
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x47);
    sub_004FD060_SetText(sub_0042F430_CreateControl(0x48), D2LANG_GetStringFromTblIndex(0x2B2F));
    sub_004FD060_SetText(sub_0042F430_CreateControl(0x49), D2LANG_GetStringFromTblIndex(0x2B30));
    gpControl_00779590 = sub_0042F430_CreateControl(0x4A);
    sub_0042F430_CreateControl(0x4B);
    sub_0042F430_CreateControl(0x4C);
    BNGatewayAccess* pGateways = gpFuncTable_0077ABF0->pfnGetRecord();
    int nCur = pGateways->m_nCurGateway;
    for (int i = 1; i <= pGateways->m_nNumGateways; ++i)
    {
        sub_004FCF80_SetTextA(gpControl_00779590, pGateways->Name(i));
    }
    int nFirst = sub_004FB950_GetFirstVisible(gpControl_00779590);
    int nVisible = D2Win_10055(gpControl_00779590);
    int nLine = nCur - 1;
    if (nLine < nFirst || nLine - nFirst > nVisible)
    {
        D2Win_10053(gpControl_00779590, nLine);
        nLine = 0;
    }
    sub_004FB9D0_Select(gpControl_00779590, nLine);
    sub_00431AF0();
    return 1;
}
