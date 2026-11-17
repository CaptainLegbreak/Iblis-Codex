extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct FSafeSock
{
    int bConnected;
    int bConnecting;
    unsigned int nSocket;
    D2CriticalSectionStrc tCriticalSection;
    void* hThread;
    unsigned long nThreadId;
    int bStopping;
    unsigned long nFogErrorCode;
    unsigned long nWSALastError;
    char szName[64];
};

struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2TimeZoneInformationStrc
{
    long f_0;
    unsigned short wszStandardName[32];
    D2SystemTimeStrc tStandardDate;
    long nStandardBias;
    unsigned short wszDaylightName[32];
    D2SystemTimeStrc tDaylightDate;
    long nDaylightBias;
};

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425D90_Init();                                                                               // 0x00425D90
    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);                                // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                                                        // 0x00425F00
};

struct D2BnRegistrationPacketStrc
{
    unsigned long nLead;
    unsigned long nRegistrationVersion;
    unsigned long nRegistrationAuthority;
    unsigned long nClientId;
    unsigned long f_10;
    char szText[0x400];
};

struct D2BnLogonRequestStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    unsigned int dwUnk0x0C;
};

struct D2BnCheckAdPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    long nTime;
};

struct D2BnVersionPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    char szText[0x500];
};

struct D2BnLocalePacketStrc
{
    D2FileTimeStrc tSystemTime;
    D2FileTimeStrc tLocalTime;
    long f_10;
    unsigned long nSystemLcid;
    unsigned long nUserLcid;
    unsigned long nUserLangId;
    char szText[0x100];
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime);                // 0x006CC1D4
extern "C" __declspec(dllimport) unsigned short __stdcall GetUserDefaultLangID(void);                      // 0x006CC384
extern "C" __declspec(dllimport) unsigned long __stdcall GetTimeZoneInformation(D2TimeZoneInformationStrc* pTimeZoneInformation); // 0x006CC388
extern "C" __declspec(dllimport) void __stdcall GetSystemTime(D2SystemTimeStrc* pSystemTime);               // 0x006CC38C
extern "C" __declspec(dllimport) int __stdcall GetLocaleInfoA(unsigned long nLocale, unsigned long nLCType, char* pData, int nData); // 0x006CC394
extern "C" __declspec(dllimport) unsigned long __stdcall GetUserDefaultLCID(void);                         // 0x006CC398
extern "C" __declspec(dllimport) unsigned long __stdcall GetSystemDefaultLCID(void);                       // 0x006CC39C
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
int __fastcall sub_0040D290_GetData(char* pBuffer, unsigned int* pnSize);                                  // 0x0040D290
int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength);                  // 0x0040DC60
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock);                                                     // 0x0040DDF0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __fastcall sub_0051A8F0_HandleLogon(int nArg1, int nArg2, const char* szText);                        // 0x0051A8F0
int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
int __fastcall sub_0051C760_SplitPackets(unsigned char* pBuffer, int nLength);                                       // 0x0051C760
int __fastcall sub_0051E370_SetText(const char* szText, int nLength);                                       // 0x0051E370
void __fastcall sub_0051EA40_SetStatus(int nStatus);                                                        // 0x0051EA40
int __fastcall sub_0051EA80_SetName(const char* szName);                                                    // 0x0051EA80
int __cdecl sub_0051EAA0_HasName();                                                                         // 0x0051EAA0
int __fastcall sub_0051E6D0_ParseLogon(int* pArg1, int* pArg2, char* szText);                               // 0x0051E6D0
int __fastcall sub_005204A0_SetError(int nError);                                                           // 0x005204A0
void __cdecl sub_00520AD0_SetDisconnected();                                                                // 0x00520AD0
int __cdecl sub_00520AE0();                                                                                 // 0x00520AE0
int __fastcall sub_00520B70_WaitForReply(unsigned char nReply);                                             // 0x00520B70
int __fastcall sub_00520BF0_IsReplyReceived(unsigned char nReply);                                          // 0x00520BF0
void __fastcall sub_00520C00_ClearReply(unsigned char nReply);                                              // 0x00520C00

extern "C" const char szConfiguration_006DEC7C[];                                                           // 0x006DEC7C
extern "C" const char szEmpty_006DEF80[];                                                                   // 0x006DEF80
extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0
extern long volatile gnReceiveThreads_00881BF4;                                                             // 0x00881BF4
extern int gbReady_00881BF8;                                                                                // 0x00881BF8
extern long volatile gnDnsDone_00881BFC;                                                                    // 0x00881BFC
unsigned int gnVersion_0088252C;                                                                            // 0x0088252C

// 0x0051A490
int __cdecl sub_0051A490_SendRegistration()
{
    D2BnRegistrationPacketStrc tPacket;
    SRegLoadValue(szConfiguration_006DEC7C, "Registration Version", 2, &tPacket.nRegistrationVersion);
    SRegLoadValue(szConfiguration_006DEC7C, "Registration Authority", 2, &tPacket.nRegistrationAuthority);
    SRegLoadValue(szConfiguration_006DEC7C, "Client ID", 2, &tPacket.nClientId);
    SRegLoadValue(szConfiguration_006DEC7C, "Client Token", 2, &tPacket.f_10);
    tPacket.nLead = 1;
    tPacket.szText[1] = tPacket.szText[0] = 0;
    sub_0051C5C0_SendPacket(0x1E, &tPacket, 0x16);
    return 1;
}

// 0x0051A9C0
int __cdecl sub_0051A9C0_RequestLogon()
{
    sub_00520C00_ClearReply(7);
    sub_0051EA80_SetName(&gszEmptyAssertText);
    D2BnLogonRequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.dwPlatform = 0x49583836;
    tRequest.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tRequest.dwVersion = 0x0E;
    sub_00520C00_ClearReply(6);
    if (sub_0051C5C0_SendPacket(6, &tRequest, sizeof(tRequest)) < 0)
        return 0;
    while (!sub_0051EAA0_HasName())
    {
        if (sub_00520BF0_IsReplyReceived(7))
            break;
        if (sub_00520AE0())
            return 0;
        Sleep(10);
    }
    sub_0051EA40_SetStatus(0x66);
    if (sub_00520BF0_IsReplyReceived(7))
        return 0;
    char szText[0x100] = { 0 };
    int nArg2;
    int nArg1;
    if (!sub_0051E6D0_ParseLogon(&nArg1, &nArg2, szText))
    {
        sub_005204A0_SetError(1);
        return 0;
    }
    sub_0051E370_SetText(szEmpty_006DEF80, 2);
    sub_0051A8F0_HandleLogon(nArg1, nArg2, szText);
    sub_00520B70_WaitForReply(7);
    return 0;
}

// 0x0051B010
int __cdecl sub_0051B010_CheckAd()
{
    D2BnCheckAdPacketStrc tPacket;
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = gnVersion_0088252C;
    tPacket.nTime = _time32(0);
    sub_0051C5C0_SendPacket(0x15, &tPacket, sizeof(tPacket));
    return 1;
}

// 0x0051B060
int __cdecl sub_0051B060_SendVersion()
{
    D2BnVersionPacketStrc tPacket;
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = gnVersion_0088252C;
    tPacket.szText[1] = tPacket.szText[0] = 0;
    sub_0051C5C0_SendPacket(0x21, &tPacket, 0x0E);
    return 1;
}

// 0x0051B540
void __cdecl sub_0051B540_SendLocale()
{
    D2TimeZoneInformationStrc tTimeZone;
    memset(&tTimeZone, 0, sizeof(tTimeZone));
    GetTimeZoneInformation(&tTimeZone);
    D2SystemTimeStrc tSystemTime;
    GetSystemTime(&tSystemTime);
    D2SystemTimeStrc tLocalTime;
    GetLocalTime(&tLocalTime);
    D2BnLocalePacketStrc tPacket;
    SystemTimeToFileTime(&tSystemTime, &tPacket.tSystemTime);
    SystemTimeToFileTime(&tLocalTime, &tPacket.tLocalTime);
    tPacket.f_10 = tTimeZone.f_0;
    tPacket.nSystemLcid = GetSystemDefaultLCID();
    tPacket.nUserLcid = GetUserDefaultLCID();
    tPacket.nUserLangId = GetUserDefaultLangID();
    tPacket.szText[0] = 0;
    GetLocaleInfoA(0x400, 3, tPacket.szText, 0x40);
    char* p = tPacket.szText + strlen(tPacket.szText) + 1;
    GetLocaleInfoA(0x400, 5, p, 0x40);
    p += strlen(p) + 1;
    GetLocaleInfoA(0x400, 7, p, 0x40);
    p += strlen(p) + 1;
    GetLocaleInfoA(0x400, 0x1002, p, 0x40);
    p += strlen(p) + 1;
    sub_0051C5C0_SendPacket(0x12, &tPacket, p - tPacket.szText + 0x20);
}

// 0x0051BCF0
int __cdecl sub_0051BCF0_SendBuffer()
{
    unsigned int nSize = 0x5DC;
    char aBuffer[0x5DC];
    if (!sub_0040D290_GetData(aBuffer, &nSize))
        return 0;
    return sub_0051C5C0_SendPacket(0x5D, aBuffer, nSize) >= 0;
}

// build: context sub_0051C7E0_ReceiveThread
unsigned long __stdcall sub_0051C7E0_ReceiveThread(void* pParameter)
{
    char aBuffer[0x2000];
    int nResult = 1;
    if (InterlockedIncrement(&gnReceiveThreads_00881BF4) > 1)
    {
        InterlockedDecrement(&gnReceiveThreads_00881BF4);
        return 1;
    }
    while (!InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0) && !gbReady_00881BF8)
        Sleep(10);
    unsigned long dwLastTick = GetTickCount();
    int nUsed = 0;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    while (pSafeSock && !pSafeSock->bStopping && !InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        const int bReady = FOG_SOCKET_Select(pSafeSock);
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
        if (!pSafeSock || pSafeSock->bStopping || InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
            break;
        if (bReady)
        {
            const int nReceived = FOG_SOCKET_Receive(pSafeSock, &aBuffer[nUsed], sizeof(aBuffer) - nUsed);
            if (nReceived <= 0)
            {
                sub_00520AD0_SetDisconnected();
                nResult = 0;
                break;
            }
            nUsed = sub_0051C760_SplitPackets((unsigned char*)aBuffer, nReceived + nUsed);
        }
        const unsigned long dwTick = GetTickCount();
        if (dwTick - dwLastTick >= 180000)
        {
            sub_0051C5C0_SendPacket(0, 0, 0);
            dwLastTick = dwTick;
        }
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    }
    InterlockedDecrement(&gnReceiveThreads_00881BF4);
    return nResult;
}

// 0x0051DC80
void __fastcall sub_0051DC80(unsigned char* pDigest, const unsigned char* pData, unsigned int nLength)
{
    T0041D340 tContext;
    tContext.sub_00425D90_Init();
    tContext.sub_00425DD0_Update(pData, nLength);
    tContext.sub_00425F00_Final(pDigest);
}
