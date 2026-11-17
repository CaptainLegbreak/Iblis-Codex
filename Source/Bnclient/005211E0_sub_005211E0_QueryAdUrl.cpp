struct D2BnTokenReplyStrc
{
    int nResult;
    unsigned int nToken;
};

void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
int __fastcall sub_005224C0_CheckServerProof(const unsigned char* pServerProof);                           // 0x005224C0
void __cdecl sub_005224F0_ClearPassword();                                                                  // 0x005224F0
int __fastcall sub_005223F0_SendUpgradeProof(unsigned int nServerToken);                                    // 0x005223F0
int __cdecl sub_005224E0();                                                                                 // 0x005224E0
int __fastcall sub_005223A0(int bFlag);                                                                     // 0x005223A0
int __fastcall sub_00522310(const unsigned char* pSalt, const unsigned char* pServerKey);                   // 0x00522310
int __cdecl sub_00522050();                                                                                 // 0x00522050
void __fastcall sub_0051AB30_SetAdUrlReply(const void* pData, unsigned int nSize);                          // 0x0051AB30
void __fastcall sub_0051B3E0_SetSizedReply(const void* pData, unsigned int nSize);                          // 0x0051B3E0
void __fastcall sub_0051B820_SetReply(const void* pData, unsigned int nSize);                               // 0x0051B820
void __fastcall sub_0051CA80_SetFlag(int nValue);                                                           // 0x0051CA80
int __fastcall sub_0051E3D0_PostMessage(const char* szText, int nCode);                                     // 0x0051E3D0

extern int gdwGlobal_0072FFA8;                                                                              // 0x0072FFA8
int gdwGlobal_008822A0;                                                                                     // 0x008822A0
int gdwGlobal_008822A4;                                                                                     // 0x008822A4
int gdwGlobal_008823F0;                                                                                     // 0x008823F0
int gdwGlobal_008823FC;                                                                                     // 0x008823FC

// 0x005211E0
int __fastcall sub_005211E0_QueryAdUrl(const void* pData, unsigned int nSize)
{
    sub_0051AB30_SetAdUrlReply(pData, nSize);
    return 1;
}

// 0x005211F0
int __fastcall sub_005211F0_LogonRealmEx(const void* pData, unsigned int nSize)
{
    sub_0051B3E0_SetSizedReply(pData, nSize);
    return 1;
}

// 0x00521200
int __fastcall sub_00521200_ReadUserData(const void* pData, unsigned int nSize)
{
    sub_0051B820_SetReply(pData, nSize);
    return 1;
}

// 0x005215B0
int __fastcall sub_005215B0_AuthAccountCreate(const void* pData, unsigned int nSize)
{
    if (nSize < 4)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountCreate");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        gdwGlobal_008822A4 = 0;
        sub_0051A480_DebugLog("Account created");
        break;
    case 4:
        gdwGlobal_008822A4 = 4;
        sub_0051A480_DebugLog("Create failed: Name is in use");
        break;
    case 7:
        gdwGlobal_008822A4 = 1;
        sub_0051A480_DebugLog("Create failed: Name blank");
        break;
    case 8:
        gdwGlobal_008822A4 = 2;
        sub_0051A480_DebugLog("Create failed: Name contains bad characters");
        break;
    case 9:
        gdwGlobal_008822A4 = 3;
        sub_0051A480_DebugLog("Create failed: Name contains bad words");
        break;
    case 10:
        gdwGlobal_008822A4 = 6;
        sub_0051A480_DebugLog("Create failed: Name doesn't have alpha characters");
        break;
    case 11:
        gdwGlobal_008822A4 = 7;
        sub_0051A480_DebugLog("Create failed: Name contains adjacent punctuation");
        break;
    case 12:
        gdwGlobal_008822A4 = 8;
        sub_0051A480_DebugLog("Create failed: Name contains too much punctuation");
        break;
    default:
        gdwGlobal_008822A4 = 4;
        sub_0051A480_DebugLog("Create failed: unknown result");
        break;
    }
    gdwGlobal_008823F0 = 1;
    return 1;
}

// 0x00521760
int __fastcall sub_00521760_AuthAccountLogonProof(const void* pData, unsigned int nSize)
{
    if (nSize < 0x18)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountLogonProof");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        if (sub_005224C0_CheckServerProof((const unsigned char*)pData + 4))
        {
            sub_0051A480_DebugLog("Logon Proof success");
            gdwGlobal_0072FFA8 = 0;
            return 1;
        }
        sub_0051A480_DebugLog("Logon Proof failed: Server didn't know our password but told us it did!");
        sub_005204A0_SetError(0x12);
        return 0;
    case 2:
        sub_0051A480_DebugLog("Logon Proof failed: Invalid password");
        sub_005204A0_SetError(0x0E);
        gdwGlobal_0072FFA8 = 2;
        return 1;
    default:
        sub_0051A480_DebugLog("Logon Proof failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521800
int __fastcall sub_00521800_AuthAccountChange(const void* pData, unsigned int nSize)
{
    if (nSize < 0x44)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountChange");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        sub_0051A480_DebugLog("Change requires proof");
        return sub_00522310((const unsigned char*)pData + 4, (const unsigned char*)pData + 0x24);
    case 1:
        sub_0051A480_DebugLog("Change failed: Account unknown");
        sub_005204A0_SetError(0x0D);
        return 1;
    case 5:
        sub_0051A480_DebugLog("Change requires upgrade");
        return sub_005223A0(0);
    default:
        sub_0051A480_DebugLog("Change failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x005218A0
int __fastcall sub_005218A0_AuthAccountChangeProof(const void* pData, unsigned int nSize)
{
    if (nSize < 0x18)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountChangeProof");
        return 0;
    }
    const int nResult = *(const int*)pData;
    sub_005224F0_ClearPassword();
    switch (nResult)
    {
    case 0:
        if (sub_005224C0_CheckServerProof((const unsigned char*)pData + 4))
        {
            sub_0051A480_DebugLog("Change Proof success");
            gdwGlobal_008823FC = 1;
            return 1;
        }
        sub_0051A480_DebugLog("Change Proof failed: Server didn't know our password but told us it did!");
        sub_005204A0_SetError(0x12);
        return 0;
    case 2:
        sub_0051A480_DebugLog("Change Proof failed: Invalid password");
        gdwGlobal_008823FC = 1;
        sub_005204A0_SetError(0x0E);
        return 1;
    default:
        sub_0051A480_DebugLog("Change Proof failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521950
int __fastcall sub_00521950_AuthAccountUpgrade(const void* pData, unsigned int nSize)
{
    if (nSize < 8)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountUpgrade");
        return 0;
    }
    const D2BnTokenReplyStrc* pReply = (const D2BnTokenReplyStrc*)pData;
    const unsigned int nToken = pReply->nToken;
    if (pReply->nResult)
    {
        sub_0051A480_DebugLog("Upgrade Failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
    sub_0051A480_DebugLog("Upgrade requires proof");
    sub_005223F0_SendUpgradeProof(nToken);
    return 1;
}

// 0x005219B0
int __fastcall sub_005219B0_AuthAccountUpgradeProof(const void* pData, unsigned int nSize)
{
    if (nSize < 4)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountUpgradeProof");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        if (sub_005224E0())
        {
            sub_0051A480_DebugLog("Upgrade Proof success, logging in");
            return sub_00522050();
        }
        sub_0051A480_DebugLog("Upgrade Proof success, password changed");
        sub_005224F0_ClearPassword();
        gdwGlobal_008822A0 = 0;
        gdwGlobal_008823FC = 1;
        return 1;
    case 2:
        if (sub_005224E0())
        {
            sub_0051A480_DebugLog("Upgrade Proof Failed: Invalid password during logon");
            sub_005224F0_ClearPassword();
            gdwGlobal_0072FFA8 = 2;
            sub_005204A0_SetError(0x0E);
            return 1;
        }
        sub_0051A480_DebugLog("Upgrade Proof Failed: Invalid password during change");
        sub_005224F0_ClearPassword();
        gdwGlobal_008822A0 = 2;
        gdwGlobal_008823FC = 1;
        sub_005204A0_SetError(0x0E);
        return 1;
    default:
        sub_0051A480_DebugLog("Upgrade Proof failed: Unknown Result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}

// 0x00521AB0
int __fastcall sub_00521AB0_SetEmail(const void* pData, unsigned int nSize)
{
    sub_0051CA80_SetFlag(1);
    return 1;
}

// 0x00521AC0
int __fastcall sub_00521AC0_OptionalWork(const void* pData, unsigned int nSize)
{
    if (pData && *(const char*)pData && nSize)
        sub_0051E3D0_PostMessage((const char*)pData, 0x80000005);
    return 1;
}

// 0x00521AE0
int __fastcall sub_00521AE0_RequiredWork(const void* pData, unsigned int nSize)
{
    if (pData && *(const char*)pData && nSize)
        sub_0051E3D0_PostMessage((const char*)pData, 0x80000006);
    return 1;
}

#include "gen/data/Source/Bnclient/005211E0_sub_005211E0_QueryAdUrl.inc"
