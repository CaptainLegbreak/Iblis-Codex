#include "D2Client.h"

#define LOBYTE(w) ((unsigned char)(((unsigned long)(w)) & 0xFF))
#define HIBYTE(w) ((unsigned char)((((unsigned long)(w)) >> 8) & 0xFF))
struct D2ClientPacket67Strc;
struct D2ClientCharRecordStrc;

struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSprite1Size;
    unsigned int nSprite2Size;
    unsigned int nSprite3Size;
    int unk0x24[3];
    int nSprite1Misses;
    int nSprite2Misses;
    int nSprite3Misses;
    int unk0x3C[3];
    int nSprite1Accesses;
    int nSprite2Accesses;
    int nSprite3Accesses;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void __stdcall sub_005FE010_GetTileCacheStats(unsigned int* pSize, int* pMisses, int* pTotal, int* pUtilized); // 0x005FE010

struct D2ClientPacket67Strc
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nGameType;
    unsigned char nClass;
    unsigned char nByte13;
    unsigned char nByte14;
    char szCharName[16];
    unsigned char aWord[2];
    unsigned char aFlags[4];
    unsigned char nByte2B;
    unsigned char nByte2C;
    unsigned char f_2D;
};

struct D2ClientCharRecordStrc
{
    char unk0x000[0x207];
    unsigned char aWord207[2];
    unsigned char aFlags209[4];
    unsigned char nByte20D;
    unsigned char nByte20E;
    unsigned char nByte20F;
    unsigned char nKind;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
int __cdecl CHAT_HasClassOverride(); // 0x0047AA30
extern unsigned char gnCharClass; // 0x007A0522
extern D2ClientCharRecordStrc* gpCharRecord; // 0x007A0438
extern char gszClientCharName[]; // 0x007A05C4
extern int gnSentBytes; // 0x007A6AF8
extern int gnSentPackets; // 0x007A6B00
extern "C" __declspec(dllimport) int __stdcall ReadProcessMemory(void* hProcess, const void* pBaseAddress, void* pBuffer, unsigned long nSize, unsigned long* pBytesRead); // 0x006CC350
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
unsigned int __cdecl sub_0044CE70(); // 0x0044CE70

// 0x00477760
void __cdecl sub_00477760_DrawCacheStats()
{
    char szText[0x400];
    int nTotal;
    int nMisses;
    int nUtilized;
    unsigned int nSize;
    sub_005FE010_GetTileCacheStats(&nSize, &nMisses, &nTotal, &nUtilized);
    if (nTotal > 0)
    {
        const float fPercent = (float)(nMisses * 100.0 / nTotal);
        sprintf(szText, "Tile Cache: (%.2fK) %3.2f%%, Misses: %d, %d percent utilized\n", (float)nSize * 0.0009765625, fPercent, nMisses, nUtilized);
        D2GFX_OutputString(10, 0x30, szText);
    }
// build: symbol ?D2GFX_GetCacheResults@* 0x004F5290
    D2CacheStatsStrc* pStats = D2GFX_GetCacheResults();
    if (!pStats)
        return;
    if (pStats->nFloorSize)
    {
        sprintf(szText, "Floor Cache: (%.2fK) Misses: %d\n", (float)pStats->nFloorSize * 0.0009765625, pStats->nFloorMisses);
        D2GFX_OutputString(10, 0x3C, szText);
    }
    if (pStats->nSubtileSize)
    {
        sprintf(szText, "Subtile Cache: (%.2fK) Misses: %d\n", (float)pStats->nSubtileSize * 0.0009765625, pStats->nSubtileMisses);
        D2GFX_OutputString(10, 0x48, szText);
    }
    if (pStats->nSprite1Size)
    {
        sprintf(szText, "Sprite Cache 1: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSprite1Size * 0.0009765625, pStats->nSprite1Misses, pStats->nSprite1Accesses);
        D2GFX_OutputString(10, 0x54, szText);
    }
    if (pStats->nSprite2Size)
    {
        sprintf(szText, "Sprite Cache 2: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSprite2Size * 0.0009765625, pStats->nSprite2Misses, pStats->nSprite2Accesses);
        D2GFX_OutputString(10, 0x60, szText);
    }
    if (pStats->nSprite3Size)
    {
        sprintf(szText, "Sprite Cache 3: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSprite3Size * 0.0009765625, pStats->nSprite3Misses, pStats->nSprite3Accesses);
        D2GFX_OutputString(10, 0x6C, szText);
    }
}

// 0x00477CA0
void __fastcall sub_00477CA0_SendPacket67(const char* szName)
{
    D2ClientPacket67Strc tPacket;
    tPacket.nHeader = 0x67;
    SStrCopy(tPacket.szName, szName, 0x7FFFFFFF);
    switch (gdwGlobal_007A0610)
    {
    case 0:
        tPacket.nGameType = 3;
        break;
    case 6:
        tPacket.nGameType = 1;
        break;
    case 8:
        tPacket.nGameType = 2;
        break;
    default:
        tPacket.nGameType = 0;
        break;
    }
    if (CHAT_HasClassOverride())
        tPacket.nClass = sub_0047AA20_GetClassOverride();
    else
        tPacket.nClass = gnCharClass;
    tPacket.f_2D = STRTABLE_GetLanguage();
    if (!*(int*)gpCharRecord->aFlags209)
    {
        *(int*)gpCharRecord->aFlags209 = 4;
        *(int*)gpCharRecord->aFlags209 |= 0x100000;
    }
    memcpy(tPacket.aWord, gpCharRecord->aWord207, sizeof(tPacket.aWord));
    memcpy(tPacket.aFlags, gpCharRecord->aFlags209, sizeof(tPacket.aFlags));
    tPacket.nByte13 = gpCharRecord->nByte20D;
    tPacket.nByte2B = gpCharRecord->nByte20E;
    tPacket.nByte2C = gpCharRecord->nByte20F;
    tPacket.nByte14 = gpCharRecord->nKind;
    SStrCopy(tPacket.szCharName, gszClientCharName, 0x7FFFFFFF);
// build: symbol ?CLIENT_Send@* 0x0052AE50
    CLIENT_Send(sizeof(tPacket), 0, &tPacket);
    gnSentBytes += sizeof(tPacket);
    gnSentPackets += 1;
}

unsigned int gdwEncodedName0; // 0x007A04E8

unsigned int gdwEncodedName1; // 0x007A04EC

unsigned int gdwEncodedOffset; // 0x007A04F0

unsigned long gdwLastCheckTick; // 0x007BB3B0

struct D2SendPacket6BStrc
{
    unsigned char nHeader;
};

// 0x00477DA0
void __cdecl sub_00477DA0()
{
    D2SendPacket6BStrc tPacket;
    tPacket.nHeader = 0x6B;
    CLIENT_Send(sizeof(D2SendPacket6BStrc), 0, &tPacket);
    gnSentBytes += sizeof(D2SendPacket6BStrc);
    gnSentPackets += 1;
}

// 0x00477DD0
void __cdecl sub_00477DD0()
{
    int aPacket[4];
    unsigned int aName[3];
    unsigned short wLow;
    unsigned short wHigh;

    aName[0] = gdwEncodedName0 * 0x470E31C1;
    aName[1] = gdwEncodedName1 * 0x470E31C1;
    const unsigned int nOffset = gdwEncodedOffset * 0x470E31C1;
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
                    // __assume: keeps the bytes collecting in nValue's own register, as the original does; no plain form found
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
    if (dwTick - gdwLastCheckTick >= 5000)
    {
        gdwLastCheckTick = dwTick;
        char* pPacket = (char*)aPacket;
        pPacket[0] = 0x6D;
        *(unsigned long*)(pPacket + 1) = GetTickCount();
        *(unsigned int*)(pPacket + 5) = sub_0044CE70() >> 1;
        *(unsigned int*)(pPacket + 9) = nValue * 0xB640DE41;
        CLIENT_Send(13, 0, aPacket);
        gnSentBytes += 13;
        gnSentPackets += 1;
    }
}
