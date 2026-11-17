extern "C" char* __cdecl strcpy(char* pDest, const char* pSource);
extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);              // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);              // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* lpCriticalSection);             // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* lpOutputString);             // 0x006CC200

struct D2McpPacket06Strc
{
    unsigned char f_0;
    unsigned char aRequestId[2];
    unsigned char aToken[4];
    unsigned char aValue[4];
    unsigned char nByte0B;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nCount;
    unsigned char aFirst[16];
    unsigned char aSecond[16];
    char szData[1];
};

struct D2McpInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int unk0x04;
    int nValue;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nByte0E;
    unsigned char unk0x0F;
    int nCount;
    int nToken;
    char unk0x18[0x10];
    char szName[0x20];
    unsigned short aFirst[16];
    unsigned short aSecond[16];
    char aNames[16][0x10];
};

struct D2ClientCharRecordStrc
{
    char unk0x00[0x1F];
    char szName[0x1D0];
    unsigned char aFlags[2];
    char unk0x1F1[0x1F];
    unsigned char nKind;
    char unk0x211[0x34];
    char szText245[0x18];
    char szText25D[0x10];
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x34];
    void (__fastcall* pfnCharUpdate)(char* szName, char* szText245, char* szText25D, int nFlags);
    char unk0x38[0x58];
    void (__cdecl* pfnNotify)();
};

void __stdcall sub_00449BF0_SetValue(int nValue);                                                           // 0x00449BF0
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify();                                                       // 0x0044B7B0
void __cdecl sub_0052CFE0();                                                                                // 0x0052CFE0
void __cdecl sub_0052E9C0();                                                                                // 0x0052E9C0
int __stdcall sub_0052EFF0(int nArg);                                                                       // 0x0052EFF0
void* __stdcall sub_0052FC20(int nArg);                                                                     // 0x0052FC20
void __stdcall sub_0052FD90(int nArg1, int nArg2);                                                          // 0x0052FD90

extern unsigned short gwMcpRequestId_00798F8C;                                                              // 0x00798F8C
D2McpInfoStrc gMcpInfo_0079910C;                                                                            // 0x0079910C
extern D2ClientCharRecordStrc* gpCharRecord_007A0438;                                                       // 0x007A0438
char gtQServerLock_007A0468[0x18];                                                                          // 0x007A0468
int gbQServerStop_007A0648;                                                                                 // 0x007A0648
int gbQServerRestart_007A064C;                                                                              // 0x007A064C
extern int gnQServerThreshold_0070F560;                                                                     // 0x0070F560

// 0x0044ACA0
int __fastcall sub_0044ACA0(D2McpPacket06Strc* pPacket, int nSize)
{
    const int nToken = *(int*)pPacket->aToken;
    const int nValue = *(int*)pPacket->aValue;
    if (*(unsigned short*)pPacket->aRequestId != gwMcpRequestId_00798F8C)
        return 1;
    gMcpInfo_0079910C.f_0 = gwMcpRequestId_00798F8C;
    gMcpInfo_0079910C.nToken = nToken;
    gMcpInfo_0079910C.nCount = pPacket->nCount;
    gMcpInfo_0079910C.nValue = nValue;
    gMcpInfo_0079910C.nByte0C = pPacket->nByte0B;
    gMcpInfo_0079910C.nByte0D = pPacket->nByte0C;
    gMcpInfo_0079910C.nByte0E = pPacket->nByte0D;
    if (nToken == -1)
    {
        sub_00449BF0_SetValue(0x32);
        return 1;
    }
    if (nToken == -2)
    {
        sub_00449BF0_SetValue(0x33);
        return 1;
    }
    const char* pString = pPacket->szData;
    const char* szName = pString;
    pString += strlen(pString) + 1;
    strcpy(gMcpInfo_0079910C.szName, szName);
    for (int i = 0; i < pPacket->nCount; i++)
    {
        gMcpInfo_0079910C.aFirst[i] = pPacket->aFirst[i];
        gMcpInfo_0079910C.aSecond[i] = pPacket->aSecond[i];
        const char* szEntry = pString;
        pString += strlen(pString) + 1;
        strcpy(gMcpInfo_0079910C.aNames[i], szEntry);
    }
    return 1;
}

// 0x0044CF20
unsigned long __stdcall sub_0044CF20(void* pArg)
{
    int nLast = 0;
    void* pSession = 0;
    EnterCriticalSection(gtQServerLock_007A0468);
    int bStop = gbQServerStop_007A0648;
    int bRestart = gbQServerRestart_007A064C;
    LeaveCriticalSection(gtQServerLock_007A0468);
    while (!bStop)
    {
        if (bRestart)
        {
            sub_0052CFE0();
            pSession = sub_0052FC20(1);
            if (pSession)
                sub_0052FD90(0, 0);
        }
        if (pSession)
        {
            Sleep(30);
            D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
            if (pNotify)
            {
                const int nLevel = sub_0052EFF0(1);
                if (nLevel != nLast)
                {
                    if (nLast < gnQServerThreshold_0070F560)
                    {
                        if (nLevel >= gnQServerThreshold_0070F560)
                            pNotify->pfnNotify();
                    }
                    else if (nLevel < gnQServerThreshold_0070F560)
                    {
                        int nFlags = 0;
                        if (gpCharRecord_007A0438->nKind == 1)
                            nFlags = 1;
                        if (gpCharRecord_007A0438->nKind == 2)
                            nFlags |= 2;
                        const unsigned short wFlags = *(unsigned short*)gpCharRecord_007A0438->aFlags;
                        if (wFlags & 4)
                            nFlags |= 4;
                        if (wFlags & 0x20)
                            nFlags |= 8;
                        pNotify->pfnCharUpdate(gpCharRecord_007A0438->szName, gpCharRecord_007A0438->szText245, gpCharRecord_007A0438->szText25D, nFlags);
                    }
                    nLast = nLevel;
                }
            }
        }
        else
        {
            Sleep(10);
        }
        EnterCriticalSection(gtQServerLock_007A0468);
        bStop = gbQServerStop_007A0648;
        bRestart = gbQServerRestart_007A064C;
        LeaveCriticalSection(gtQServerLock_007A0468);
    }
    sub_0052E9C0();
    sub_0052FD90(0, 1);
    DeleteCriticalSection(gtQServerLock_007A0468);
    OutputDebugStringA("Open server thread shut down\n");
    return 1;
}

#include "gen/data/Source/D2Client/0044ACA0_sub_0044ACA0.inc"
