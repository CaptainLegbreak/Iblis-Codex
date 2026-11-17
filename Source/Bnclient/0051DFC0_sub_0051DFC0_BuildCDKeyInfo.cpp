struct D2CDKeyInfoStrc
{
    unsigned int f_0;
    int f_4;
    int nValue1;
    int f_C;
    unsigned char abDigest[20];
};

struct D2CDKeyHash16Strc
{
    unsigned int f_0;
    unsigned int f_4;
    int f_8;
    int nValue1;
    int f_10;
    int nValue3;
};

struct D2CDKeyHash26Strc
{
    unsigned int f_0;
    unsigned int f_4;
    int f_8;
    int nValue1;
    unsigned char abPrivate[12];
};

struct D2AuthCheck2Strc
{
    unsigned int f_0;
    unsigned int nKeys;
    unsigned int f_8;
    D2CDKeyInfoStrc aKeys[2];
    char f_54[0x100];
};

struct D2AuthCheck1Strc
{
    unsigned int f_0;
    unsigned int nKeys;
    unsigned int f_8;
    D2CDKeyInfoStrc aKeys[1];
    char f_30[0x100];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
unsigned int __cdecl sub_0051A550_GetServerToken();                                                         // 0x0051A550
int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
void __fastcall sub_0051DC80(unsigned char* pDigest, const unsigned char* pData, unsigned int nLength); // 0x0051DC80
int __fastcall sub_0051DDD0_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2);   // 0x0051DDD0
void __fastcall sub_005209D0_HashData(unsigned char* pDigest, const void* pData, unsigned int nLength);     // 0x005209D0
int __fastcall sub_00522AE0_DecodeCDKey(const char* szKey, void* pArg2, void* pArg3, void* pArg4);         // 0x00522AE0
unsigned int __cdecl sub_00523A00_GetExeHash();                                                             // 0x00523A00
const char* __cdecl sub_00523AA0_GetExeInfo();                                                              // 0x00523AA0
const char* __fastcall sub_00523AB0_GetCDKey(int nSlot);                                                    // 0x00523AB0
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern unsigned int gdwClientToken_00881C48;                                                                // 0x00881C48

// 0x0051DFC0
static int __stdcall sub_0051DFC0_BuildCDKeyInfo(D2CDKeyInfoStrc* pInfo, const char* szKey, unsigned int dwClientToken, unsigned int dwServerToken)
{
    D2CDKeyHash26Strc tHash26;
    int nValue1;
    D2CDKeyHash16Strc tHash16;
    switch (SStrLen(szKey))
    {
    case 0x10:
        tHash16.f_0 = dwClientToken;
        tHash16.f_4 = dwServerToken;
        if (!sub_0051DDD0_DecodeCDKey16(&tHash16.f_8, &nValue1, szKey, &tHash16.nValue3))
            return 0;

        tHash16.nValue1 = nValue1;
        tHash16.f_10 = 0;
        pInfo->f_0 = SStrLen(szKey);
        pInfo->f_4 = tHash16.f_8;
        pInfo->nValue1 = tHash16.nValue1;
        pInfo->f_C = tHash16.f_10;
        sub_005209D0_HashData(pInfo->abDigest, &tHash16, 0x18);
        return 1;

    case 0x1A:
        tHash26.f_0 = dwClientToken;
        tHash26.f_4 = dwServerToken;
        if (!szKey)
            return 0;

        sub_00522AE0_DecodeCDKey(szKey, &tHash26.f_8, &nValue1, tHash26.abPrivate);
        tHash26.nValue1 = nValue1;
        pInfo->f_0 = SStrLen(szKey);
        pInfo->f_4 = tHash26.f_8;
        pInfo->nValue1 = tHash26.nValue1;
        pInfo->f_C = 0;
        sub_0051DC80(pInfo->abDigest, (const unsigned char*)&tHash26, 0x1A);
        return 1;
    }

    return 0;
}

int __stdcall sub_0051E0B0_SendAuthCheck()
{
    const char* szExeInfo = sub_00523AA0_GetExeInfo();
    const char* szKey0 = sub_00523AB0_GetCDKey(0);
    const char* szKey1 = sub_00523AB0_GetCDKey(1);
    const unsigned int dwExeHash = sub_00523A00_GetExeHash();
    gdwClientToken_00881C48 += _time32(0);
    gdwClientToken_00881C48 += GetTickCount();
    if (sub_0051BEC0_IsExpansion())
    {
        D2AuthCheck2Strc tPacket;
        if (!sub_0051DFC0_BuildCDKeyInfo(&tPacket.aKeys[0], szKey0, gdwClientToken_00881C48, sub_0051A550_GetServerToken()))
            return 0;
        if (!sub_0051DFC0_BuildCDKeyInfo(&tPacket.aKeys[1], szKey1, gdwClientToken_00881C48, sub_0051A550_GetServerToken()))
            return 0;

        tPacket.f_0 = gdwClientToken_00881C48;
        tPacket.nKeys = 2;
        tPacket.f_8 = dwExeHash;
        if (sub_0051C5C0_SendPacket(0x42, &tPacket, SStrCopy(tPacket.f_54, szExeInfo, 0x100) + 0x55) < 0)
            return 0;
    }
    else
    {
        D2AuthCheck1Strc tPacket;
        tPacket.f_0 = gdwClientToken_00881C48;
        tPacket.nKeys = 1;
        tPacket.f_8 = dwExeHash;
        if (!sub_0051DFC0_BuildCDKeyInfo(&tPacket.aKeys[0], szKey0, gdwClientToken_00881C48, sub_0051A550_GetServerToken()))
            return 0;

        if (sub_0051C5C0_SendPacket(0x42, &tPacket, SStrCopy(tPacket.f_30, szExeInfo, 0x100) + 0x31) < 0)
            return 0;
    }

    return 1;
}

int __fastcall sub_0051E340_BuildCDKeyInfoForSlot(D2CDKeyInfoStrc* pInfo, unsigned int dwClientToken, int nSlot)
{
    return sub_0051DFC0_BuildCDKeyInfo(pInfo, sub_00523AB0_GetCDKey(nSlot), dwClientToken, sub_0051A550_GetServerToken());
}
