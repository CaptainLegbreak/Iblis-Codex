extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);                // 0x006CC198
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall ReadProcessMemory(void* hProcess, const void* pBaseAddress, void* pBuffer, unsigned long nSize, unsigned long* pBytesRead); // 0x006CC350
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

unsigned int __cdecl sub_0044CE70();                                                                        // 0x0044CE70
int __stdcall sub_0052AE50_SendPacket(int nSize, int nFlags, void* pData);                                  // 0x0052AE50

unsigned int gdwEncodedName0_007A04E8;                                                                      // 0x007A04E8
unsigned int gdwEncodedName1_007A04EC;                                                                      // 0x007A04EC
unsigned int gdwEncodedOffset_007A04F0;                                                                     // 0x007A04F0
extern int gnSentBytes_007A6AF8;                                                                            // 0x007A6AF8
extern int gnSentPackets_007A6B00;                                                                          // 0x007A6B00
unsigned long gdwLastCheckTick_007BB3B0;                                                                    // 0x007BB3B0

#define LOBYTE(w) ((unsigned char)(((unsigned long)(w)) & 0xFF))
#define HIBYTE(w) ((unsigned char)((((unsigned long)(w)) >> 8) & 0xFF))

// 0x00477DD0
void __cdecl sub_00477DD0()
{
    int aPacket[4];
    unsigned int aName[3];
    unsigned short wLow;
    unsigned short wHigh;

    aName[0] = gdwEncodedName0_007A04E8 * 0x470E31C1;
    aName[1] = gdwEncodedName1_007A04EC * 0x470E31C1;
    const unsigned int nOffset = gdwEncodedOffset_007A04F0 * 0x470E31C1;
    ((char*)aName)[8] = 0;

    unsigned int nValue;
    if ((char)aName[0])
    {
        nValue = 0xCCCCCCCC;
        char* hModule = (char*)GetModuleHandleA((const char*)aName);
        if (hModule)
        {
            char* pAddress = hModule + nOffset;
            if (ReadProcessMemory(GetCurrentProcess(), pAddress, &wLow, 2, 0))
            {
                if (ReadProcessMemory(GetCurrentProcess(), pAddress + 0x20, &wHigh, 2, 0))
                {
                    nValue = !hModule ? 0 : HIBYTE(wHigh);
                    __assume(nValue != 0x80000000);
                    nValue <<= 8;
                    __assume(nValue != 0x80000000);
                    nValue |= LOBYTE(wHigh);
                    __assume(nValue != 0x80000000);
                    nValue <<= 8;
                    __assume(nValue != 0x80000000);
                    nValue |= HIBYTE(wLow);
                    __assume(nValue != 0x80000000);
                    nValue <<= 8;
                    __assume(nValue != 0xFFFFFFFF);
                    nValue |= LOBYTE(wLow);
                }
            }
        }
    }
    else
    {
        nValue = 0;
    }

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastCheckTick_007BB3B0 >= 5000)
    {
        gdwLastCheckTick_007BB3B0 = dwTick;
        char* pPacket = (char*)aPacket;
        pPacket[0] = 0x6D;
        *(unsigned long*)(pPacket + 1) = GetTickCount();
        *(unsigned int*)(pPacket + 5) = sub_0044CE70() >> 1;
        *(unsigned int*)(pPacket + 9) = nValue * 0xB640DE41;
        sub_0052AE50_SendPacket(13, 0, aPacket);
        gnSentBytes_007A6AF8 += 13;
        gnSentPackets_007A6B00 += 1;
    }
}
