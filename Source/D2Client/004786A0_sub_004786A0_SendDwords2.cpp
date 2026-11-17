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

extern unsigned char gaLastSentPacket_007BB3B8[0x200];                                                      // 0x007BB3B8
extern unsigned int gdwLastSendTick_007BB5B8;                                                               // 0x007BB5B8
extern int gnSentBytes_007A6AF8;                                                                            // 0x007A6AF8
extern int gnSentPackets_007A6B00;                                                                          // 0x007A6B00

#pragma pack(push, 1)
struct D2PacketDwords9Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
};
#pragma pack(pop)

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

// 0x004786A0
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5)
{
    D2PacketDwords9Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = d1;
    tPacket.d5 = d5;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 9);
}
