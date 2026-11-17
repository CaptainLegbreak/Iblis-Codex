#pragma pack(push, 1)
struct D2SaveChunkPacketStrc
{
    unsigned char f_0;
    unsigned char nLength;
    unsigned char bFirst;
    unsigned int nTotal;
    unsigned char aData[1];
};

struct D2ErrorPacketStrc
{
    unsigned char f_0;
    int nCode;
};
#pragma pack(pop)

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __cdecl sub_0045C520_SaveCharFile();                                                                   // 0x0045C520
void __fastcall sub_0044E380_SetConnectionError(int nError);                                                // 0x0044E380
static unsigned char* gpSaveBuffer_007A5224;                                                                // 0x007A5224
static unsigned int gnSaveBufferSize_007A5228;                                                              // 0x007A5228
extern int gdwGlobal_007A0618;                                                                              // 0x007A0618

// 0x0045C620
static void sub_0045C620_ReceiveSaveChunk(D2SaveChunkPacketStrc* pPacket)
{
    if (gpSaveBuffer_007A5224 && pPacket->bFirst)
    {
        FOG_Free(gpSaveBuffer_007A5224, ".\\GAME\\SCmd.cpp", 0x5B, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }

    if (!gpSaveBuffer_007A5224)
        gpSaveBuffer_007A5224 = (unsigned char*)FOG_Alloc(pPacket->nTotal, ".\\GAME\\SCmd.cpp", 0x62, 0);

    unsigned int nSize = gnSaveBufferSize_007A5228;
    unsigned char* pDest = gpSaveBuffer_007A5224 + nSize;
    const unsigned char* pSource = pPacket->aData;
    for (int i = 0; i < pPacket->nLength; i++)
        pDest[i] = pSource[i];

    gnSaveBufferSize_007A5228 += pPacket->nLength;
    if (pPacket->nTotal == gnSaveBufferSize_007A5228)
    {
        sub_0045C520_SaveCharFile();
        FOG_Free(gpSaveBuffer_007A5224, ".\\GAME\\SCmd.cpp", 0x71, 0);
        gpSaveBuffer_007A5224 = 0;
        gnSaveBufferSize_007A5228 = 0;
    }
}

static void sub_0045C6D0_HandleErrorPacket(D2ErrorPacketStrc* pPacket)
{
    switch (pPacket->nCode)
    {
    case 1: sub_0044E380_SetConnectionError(0); return;
    case 2: sub_0044E380_SetConnectionError(1); return;
    case 3: sub_0044E380_SetConnectionError(2); return;
    case 4: sub_0044E380_SetConnectionError(3); return;
    case 5: sub_0044E380_SetConnectionError(4); return;
    case 6: sub_0044E380_SetConnectionError(5); return;
    case 7: sub_0044E380_SetConnectionError(0x0A); return;
    case 8: sub_0044E380_SetConnectionError(0x0B); return;
    case 9: sub_0044E380_SetConnectionError(0x0C); return;
    case 10: sub_0044E380_SetConnectionError(0x0D); return;
    case 11: sub_0044E380_SetConnectionError(0x0E); return;
    case 12: sub_0044E380_SetConnectionError(0x0F); return;
    case 13: sub_0044E380_SetConnectionError(0x10); return;
    case 14: sub_0044E380_SetConnectionError(0x11); return;
    case 15: sub_0044E380_SetConnectionError(0x12); return;
    case 16: sub_0044E380_SetConnectionError(0x13); return;
    case 17: sub_0044E380_SetConnectionError(0x14); return;
    case 18: sub_0044E380_SetConnectionError(0x15); return;
    case 19: sub_0044E380_SetConnectionError(0x16); return;
    case 20: sub_0044E380_SetConnectionError(0x17); return;
    case 21: sub_0044E380_SetConnectionError(0x18); return;
    case 24: sub_0044E380_SetConnectionError(0x1A); return;
    case 23: sub_0044E380_SetConnectionError(0x19); return;
    case 26: sub_0044E380_SetConnectionError(0x1C); return;
    case 25: sub_0044E380_SetConnectionError(0x1B); return;
    }
    sub_0044E380_SetConnectionError(9);
}

void __fastcall sub_0045C850_HandleSystemPacket(unsigned char* pPacket, int nSize)
{
    if (nSize == -1)
        return;

    switch (pPacket[0])
    {
    case 0xAF:
        gdwGlobal_007A0618 = 1;
        return;
    case 0xB0:
        gdwGlobal_007A0618 = 0;
        return;
    case 0xB3:
        sub_0045C620_ReceiveSaveChunk((D2SaveChunkPacketStrc*)pPacket);
        return;
    case 0xB4:
        sub_0045C6D0_HandleErrorPacket((D2ErrorPacketStrc*)pPacket);
        return;
    }
}
