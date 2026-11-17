extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" int __cdecl memcmp(const void* p1, const void* p2, unsigned int nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData);                                  // 0x0052AE50

unsigned char gaLastSentPacket_007BB3B8[0x200];                                                             // 0x007BB3B8
unsigned int gdwLastSendTick_007BB5B8;                                                                      // 0x007BB5B8
extern int gnSentBytes_007A6AF8;                                                                            // 0x007A6AF8
extern int gnSentPackets_007A6B00;                                                                          // 0x007A6B00

#pragma pack(push, 1)
struct D2PacketSize1Strc
{
    unsigned char nHeader;
};

struct D2PacketSize3Strc
{
    unsigned char nHeader;
    unsigned short w1;
};

struct D2PacketShorts5Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
};

struct D2PacketShorts7Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
    unsigned short w5;
};

struct D2PacketShorts9Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
    unsigned short w5;
    unsigned short w7;
};

struct D2PacketDword5Strc
{
    unsigned char nHeader;
    unsigned int d1;
};

struct D2PacketDwords13Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
    unsigned int d9;
};

struct D2PacketDwords17Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
    unsigned int d9;
    unsigned int d13;
};

struct D2PacketPvp7Strc
{
    unsigned char nHeader;
    unsigned char b1;
    unsigned char bFlag;
    unsigned int d3;
};

struct D2PacketParty6Strc
{
    unsigned char nHeader;
    unsigned char b1;
    unsigned int d2;
};
#pragma pack(pop)

// 0x00478350
static void __stdcall sub_00478350_SendToServer(const unsigned char* pPacket, int nSize)
{
    D2_ASSERT(nSize < 0x200, 0x272);
    const unsigned int dwTick = GetTickCount();
    switch (pPacket[0])
    {
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x0A:
    case 0x0C:
    case 0x0D:
    case 0x0E:
    case 0x0F:
    case 0x10:
    case 0x11:
        if (dwTick - gdwLastSendTick_007BB5B8 < 50 && !memcmp(gaLastSentPacket_007BB3B8, pPacket, nSize))
            return;
        break;

    case 0x3A:
        break;

    default:
        if (dwTick - gdwLastSendTick_007BB5B8 < 200 && !memcmp(gaLastSentPacket_007BB3B8, pPacket, nSize))
            return;
        break;
    }

    memcpy(gaLastSentPacket_007BB3B8, pPacket, nSize);
    gdwLastSendTick_007BB5B8 = dwTick;
    unsigned char aBuffer[0x200];
    memcpy(aBuffer, pPacket, nSize);
    if (sub_0052AE50_SendPacket(nSize, 1, aBuffer))
    {
        gnSentBytes_007A6AF8 += nSize;
        ++gnSentPackets_007A6B00;
    }
}

// 0x00478590
void __fastcall sub_00478590(char nValue)
{
    D2PacketSize1Strc tPacket;
    tPacket.nHeader = nValue;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 1);
}

// 0x004785B0
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg)
{
    D2PacketSize3Strc tPacket;
    tPacket.nHeader = nCmd;
    tPacket.w1 = nArg;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 3);
}

// 0x004785D0
void __fastcall sub_004785D0_SendShortShort(char nHeader, short nArg1, short nArg2)
{
    D2PacketShorts5Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.w1 = nArg1;
    tPacket.w3 = nArg2;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 5);
}

// 0x00478600
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3)
{
    D2PacketShorts7Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.w1 = nArg1;
    tPacket.w3 = nArg2;
    tPacket.w5 = nArg3;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 7);
}

// 0x00478640
void __fastcall sub_00478640_SendShorts4(unsigned char nHeader, unsigned short w1, unsigned short w3, unsigned short w5, unsigned short w7)
{
    D2PacketShorts9Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.w1 = w1;
    tPacket.w3 = w3;
    tPacket.w5 = w5;
    tPacket.w7 = w7;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 9);
}

// 0x00478680
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg)
{
    D2PacketDword5Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = nArg;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 5);
}

// 0x004786D0
void __fastcall sub_004786D0_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9)
{
    D2PacketDwords13Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = d1;
    tPacket.d5 = d5;
    tPacket.d9 = d9;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 0xD);
}

// 0x00478700
void __fastcall sub_00478700_SendCommand(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3)
{
    D2PacketDwords17Strc tPacket;
    tPacket.nHeader = nCommand;
    tPacket.d1 = nUnitId;
    tPacket.d5 = nArg1;
    tPacket.d9 = nArg2;
    tPacket.d13 = nArg3;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 0x11);
}

// 0x00478740
void __fastcall sub_00478740_SendPvpCommand(int nCommand, int nUnitId, int bSet)
{
    D2PacketPvp7Strc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.nHeader = 0x5D;
    tPacket.b1 = nCommand;
    tPacket.d3 = nUnitId;
    if (bSet)
        tPacket.bFlag = 1;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 7);
}

// 0x00478780
void __fastcall sub_00478780_SendPartyCommand(unsigned char nCommand, int nUnitId)
{
    D2PacketParty6Strc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.nHeader = 0x5E;
    tPacket.b1 = nCommand;
    tPacket.d2 = nUnitId;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 6);
}

// build: context sub_004787B0_SendStrings
void __fastcall sub_004787B0_SendStrings(const unsigned char* pData)
{
    unsigned char aBuffer[0x200];
    aBuffer[0] = pData[0];
    aBuffer[1] = pData[1];
    aBuffer[2] = pData[2];
    unsigned char* pEnd = &aBuffer[3];
    pEnd += SStrCopy((char*)pEnd, (const char*)&pData[3], 0x100) + 1;
    const char* szSecond = (const char*)&pData[0x103];
    if (szSecond)
    {
        pEnd += SStrCopy((char*)pEnd, szSecond, 0x10) + 1;
    }
    else
    {
        *pEnd++ = 0;
    }
    *pEnd = 0;
    sub_00478350_SendToServer(aBuffer, pEnd - aBuffer + 1);
}

// 0x00478830
void __fastcall sub_00478830_SendPacket66(const void* pData, unsigned int nLength)
{
    if (nLength <= 0x1FD)
    {
        const unsigned int nSize = nLength + 3;
        D2_ASSERT(nSize <= 0x200, 0x453);
        unsigned char aBuffer[0x200];
        aBuffer[0] = 0x66;
        *(unsigned short*)&aBuffer[1] = (unsigned short)nLength;
        memcpy(&aBuffer[3], pData, nLength);
        sub_00478350_SendToServer(aBuffer, nSize);
        return;
    }
    D2_ASSERT(nLength <= 0x1FD, 0x452);
}
