extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

class BNGatewayAccess
{
public:
    void __stdcall Load();                                                                                   // 0x005186D0
    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
};

extern BNGatewayAccess gBnGatewayAccess_00881838;                                                           // 0x00881838
extern int gbDnsPending_008818E0;                                                                           // 0x008818E0

int __cdecl sub_0051A570_GetMode();                                                                         // 0x0051A570
int __fastcall sub_0051A660_SendLogonResponse2(const char* szName, const char* szPassword);                  // 0x0051A660
int __fastcall sub_0051A740_SendCreateAccount2(const char* szName, const char* szPassword);                  // 0x0051A740
int __cdecl sub_0051AF20_SendPacket10();                                                                    // 0x0051AF20
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
int __cdecl sub_00520AE0();                                                                                 // 0x00520AE0
int __cdecl sub_00520B10();                                                                                 // 0x00520B10
int __cdecl sub_00520B20();                                                                                 // 0x00520B20
int __fastcall sub_00520BF0_IsReplyReceived(unsigned char nReply);                                          // 0x00520BF0
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00
int __fastcall sub_00521F60_SendLogon(const char* szName, const char* szPassword);                          // 0x00521F60
int __fastcall sub_00522130_SendCreateAccount(const char* szName, const char* szPassword);                  // 0x00522130

// 0x0051C180
BNGatewayAccess* __cdecl sub_0051C180_GetBnGatewayAccess()
{
    gBnGatewayAccess_00881838.Load();
    return &gBnGatewayAccess_00881838;
}

// 0x0051C210
void __fastcall sub_0051C210_GetConnectionState(int* pState)
{
    D2_ASSERT(pState, 0x280);
    *pState = gbDnsPending_008818E0;
}

// 0x0051C240
int __fastcall sub_0051C240_Logon(const char* szName, const char* szPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x3A);
        sub_0051A660_SendLogonResponse2(szName, szPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x54);
        return sub_00521F60_SendLogon(szName, szPassword);
    }
    return 0;
}

// 0x0051C290
int __cdecl sub_0051C290_GetLogonInfo()
{
    if (sub_00520AE0())
    {
        sub_005204A0_SetError(0x12);
        return 0;
    }
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return sub_00520BF0_IsReplyReceived(0x3A);
    case 1:
        return sub_00520BF0_IsReplyReceived(0x54);
    }
    return 0;
}

// 0x0051C2D0
int __fastcall sub_0051C2D0_CreateAccount(const char* szName, const char* szPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x3D);
        sub_0051A740_SendCreateAccount2(szName, szPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x52);
        return sub_00522130_SendCreateAccount(szName, szPassword);
    }
    return 0;
}

// 0x0051C320
int __fastcall sub_0051C320_GetCreateAccountResult(int* pResult)
{
    *pResult = sub_00520B10();
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return sub_00520BF0_IsReplyReceived(0x3D);
    case 1:
        return sub_00520BF0_IsReplyReceived(0x52);
    }
    return 0;
}

// 0x0051C3B0
int __fastcall sub_0051C3B0_GetChangePasswordResult(int* pResult)
{
    *pResult = sub_00520B20();
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return sub_00520BF0_IsReplyReceived(0x31);
    case 1:
        return sub_00520BF0_IsReplyReceived(0x56);
    }
    return 0;
}

// 0x0051C460
int __cdecl sub_0051C460_LeaveChat()
{
    sub_0051AF20_SendPacket10();
    return 1;
}
