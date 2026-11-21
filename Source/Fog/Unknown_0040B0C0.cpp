unsigned __int64 gaqHuffmanByteCounts_0075B7A0[256];                                                        // 0x0075B7A0
unsigned __int64 gqHuffmanBytesIn_0075BFA0;                                                                 // 0x0075BFA0
unsigned __int64 gqHuffmanBytesOut_0075BFA8;                                                                // 0x0075BFA8
unsigned __int64 gqHuffmanHeaders_0075BFB0;                                                                 // 0x0075BFB0
extern unsigned char gabHuffmanCodeLength_007076C0[256];                                                    // 0x007076C0
void __fastcall FOG_10219(unsigned char* pData);                                                            // 0x0040ADB0

static inline void AddTotal(unsigned __int64* pTotal, unsigned __int64 nValue)
{
    *pTotal += nValue;
}

// 0x0040B0C0
void __cdecl FOG_10218()
{
    for (int i = 0; i < 256; i++)
        gaqHuffmanByteCounts_0075B7A0[i] = 0;
    gqHuffmanBytesIn_0075BFA0 = 0;
    gqHuffmanBytesOut_0075BFA8 = 0;
    gqHuffmanHeaders_0075BFB0 = 0;
    FOG_10219(gabHuffmanCodeLength_007076C0);
}

// 0x0040B130
void __fastcall FOG_10222(const unsigned char* pData, unsigned int nSize)
{
    unsigned int i = 0;
    unsigned int nBits = 0;
    for (; i < nSize; i++)
    {
        const unsigned char nByte = pData[i];
        ++gaqHuffmanByteCounts_0075B7A0[nByte];
        nBits += gabHuffmanCodeLength_007076C0[nByte];
    }
    unsigned int nHeader = 1;
    unsigned int nBytes = ((nBits + 7) >> 3) + nHeader;
    if (nBytes >= 0xF0)
    {
        nBytes += nHeader;
        nHeader = 2;
    }
    AddTotal(&gqHuffmanBytesIn_0075BFA0, nSize);
    AddTotal(&gqHuffmanBytesOut_0075BFA8, nBytes);
    AddTotal(&gqHuffmanHeaders_0075BFB0, nHeader);
}

#include "gen/data/Source/Fog/Unknown_0040B0C0.inc"
