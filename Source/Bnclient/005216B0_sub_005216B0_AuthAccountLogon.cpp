void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480
int __fastcall sub_005204A0_SetError(int nError); // 0x005204A0
int __fastcall sub_005220B0_SendLogonProof(const unsigned char* pSalt, const unsigned char* pServerKey); // 0x005220B0
int __fastcall sub_005223A0(int bFlag); // 0x005223A0

extern int gdwGlobal_0072FFA8; // 0x0072FFA8

// 0x005216B0
int __fastcall sub_005216B0_AuthAccountLogon(const void* pData, unsigned int nSize)
{
    if (nSize < 0x44)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountLogon");
        return 0;
    }

    switch (*(const int*)pData)
    {
    case 0:
        sub_0051A480_DebugLog("Logon requires proof");
        return sub_005220B0_SendLogonProof((const unsigned char*)pData + 4, (const unsigned char*)pData + 0x24);
    case 1:
        sub_0051A480_DebugLog("Logon failed: Account unknown");
        sub_005204A0_SetError(0x0D);
        gdwGlobal_0072FFA8 = 1;
        return 1;
    case 5:
        sub_0051A480_DebugLog("Logon requires upgrade");
        if (!sub_005223A0(1))
        {
            sub_005204A0_SetError(0x12);
            return 0;
        }
        return 1;
    default:
        sub_0051A480_DebugLog("Logon failed: Unknown result");
        sub_005204A0_SetError(0x12);
        return 0;
    }
}
