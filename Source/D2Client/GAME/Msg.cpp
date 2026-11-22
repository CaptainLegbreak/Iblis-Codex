#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SaveFilePacketStrc;

struct D2RosterPetNodeStrc;

#pragma pack(push, 1)

struct D2SaveFilePacketStrc
{
    unsigned char nHeader;
    unsigned char f_1;
    int nTotalSize;
    unsigned char pData[0x100];
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin); // 0x00684A2A

extern "C" long __cdecl ftell(_iobuf* pFile); // 0x00684935

extern "C" size_t __cdecl fread(void* pBuffer, size_t nSize, size_t nCount, _iobuf* pFile); // 0x00684782

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

void __fastcall CHARSEL_ShowProgressSteps(int nDone, int nTotal); // 0x00478160

extern char gszCharName_007A05C4[]; // 0x007A05C4

extern "C" const char gszSavePathFormat_006D4230[]; // 0x006D4230

extern "C" const char gszFileModeRb[]; // 0x006CDC90

extern int gnSentBytes_007A6AF8; // 0x007A6AF8

extern int gnSentPackets_007A6B00; // 0x007A6B00

int gnProgress_007BB3B4; // 0x007BB3B4

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50

extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

struct D2PacketDwords9Strc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" int __cdecl memcmp(const void* p1, const void* p2, unsigned int nSize);

extern unsigned char gaLastSentPacket_007BB3B8[0x200]; // 0x007BB3B8

extern unsigned int gdwLastSendTick_007BB5B8; // 0x007BB5B8

#pragma pack(push, 1)

struct D2PacketDwords9Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
};

#pragma pack(pop)

struct D2PacketSize1Strc
{
    unsigned char nHeader;
};

// 0x00478040
static unsigned char* MSG_ReadSaveFile(int* pnFileSize)
{
    char szSavePath[0x400];
    char szFileName[0x1F4];
    D2_ASSERT(gszCharName_007A05C4[0], 0x1EB);
    FOG_GetSavePath(szSavePath, 0x400);
    sprintf(szFileName, gszSavePathFormat_006D4230, szSavePath, gszCharName_007A05C4);
    _iobuf* pFile = fopen(szFileName, gszFileModeRb);
    if (!pFile)
        return 0;
    if (fseek(pFile, 0, 2))
    {
        fclose(pFile);
        return 0;
    }
    *pnFileSize = ftell(pFile);
    fseek(pFile, 0, 0);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(*pnFileSize, ".\\GAME\\Msg.cpp", 0x1FF, 0);
    fread(pBuffer, *pnFileSize, 1, pFile);
    fclose(pFile);
    return pBuffer;
}

// 0x00478130
void __fastcall MSG_SetProgress(int nValue, int nDivisor)
{
    if (!nDivisor)
    {
        gnProgress_007BB3B4 = 0;
        return;
    }
    gnProgress_007BB3B4 = (nValue << 8) / nDivisor;
}

// 0x004781D0
void __fastcall MSG_UploadSaveFile(int bAnimate)
{
    D2SaveFilePacketStrc tPacket;
    int nFileSize = 0;
    unsigned char* pBuffer = MSG_ReadSaveFile(&nFileSize);
    D2_ASSERT(pBuffer, 0x232);
    if (bAnimate)
        CHARSEL_ShowProgressSteps(0, 0);
    unsigned char* pRead = pBuffer;
    const int nChunks = nFileSize / 0xFF;
    for (int i = 0; i < nChunks; ++i)
    {
        tPacket.nHeader = 0x6C;
        tPacket.nTotalSize = nFileSize;
        tPacket.f_1 = 0xFF;
        for (int k = 0; k < 0xFF; ++k)
            tPacket.pData[k] = *pRead++;
// build: symbol ?CLIENT_Send@* 0x0052AE50
        CLIENT_Send(0xFF + 7, 0, &tPacket);
        gnSentBytes_007A6AF8 += 0xFF + 7;
        gnSentPackets_007A6B00 += 1;
        if (bAnimate)
            CHARSEL_ShowProgressSteps(i, nChunks);
    }
    const int nRemain = nFileSize - nChunks * 0xFF;
    tPacket.nHeader = 0x6C;
    tPacket.nTotalSize = nFileSize;
    tPacket.f_1 = (unsigned char)nRemain;
    for (int k = 0; k < nRemain; ++k)
        tPacket.pData[k] = *pRead++;
    const int nSize = nRemain + 7;
    CLIENT_Send(nSize, 0, &tPacket);
    gnSentBytes_007A6AF8 += nSize;
    gnSentPackets_007A6B00 += 1;
    FOG_Free(pBuffer, ".\\GAME\\Msg.cpp", 0x262, 0);
    if (nChunks == 0)
        gnProgress_007BB3B4 = nChunks;
    else
        gnProgress_007BB3B4 = (nChunks << 8) / nChunks;
}

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
// build: symbol ?CLIENT_Send@* 0x0052AE50
    if (CLIENT_Send(nSize, 1, aBuffer))
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

// 0x004786A0
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5)
{
    D2PacketDwords9Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = d1;
    tPacket.d5 = d5;
    sub_00478350_SendToServer((unsigned char*)&tPacket, 9);
}
