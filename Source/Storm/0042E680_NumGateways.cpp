class BNGatewayAccess
{
public:
    int __stdcall NumGateways();
    int __stdcall CurGateway();

private:
    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
};

extern int gnGatewayValue_007795BC;                                                                         // 0x007795BC
extern int gbGatewayFlag_00779954;                                                                          // 0x00779954

// 0x0042E680
int __stdcall BNGatewayAccess::NumGateways()
{
    return m_nNumGateways;
}

// 0x0042E690
int __stdcall BNGatewayAccess::CurGateway()
{
    return m_nCurGateway;
}

// 0x0042E6A0
void __fastcall sub_0042E6A0_SetGatewayValue(int nValue)
{
    gnGatewayValue_007795BC = nValue;
}

// 0x0042E6B0
void __cdecl sub_0042E6B0_SetGatewayFlag()
{
    gbGatewayFlag_00779954 = 1;
}

// 0x0042E6C0
int __cdecl sub_0042E6C0_GetGatewayFlag()
{
    return gbGatewayFlag_00779954;
}
