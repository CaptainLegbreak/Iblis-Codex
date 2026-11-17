struct FSafeSock;

struct D2BnPacketHeaderStrc
{
    unsigned char f_0;
    unsigned char nId;
    unsigned short nLength;
};

typedef int (__fastcall* D2BnPacketHandler)(const void* pData, int nSize);

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0
int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength);                     // 0x0040DCC0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0
void __cdecl sub_00520AD0_SetDisconnected();                                                                // 0x00520AD0

extern D2BnPacketHandler gpfPacketHandlers_0072FFB0[];                                                      // 0x0072FFB0
extern long volatile gnConnected_00881BF0;                                                                  // 0x00881BF0
extern long volatile gnDnsDone_00881BFC;                                                                    // 0x00881BFC
extern int gnSlotArrayA_00882128[94];                                                                       // 0x00882128

// 0x0051C5C0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize)
{
    D2BnPacketHeaderStrc tHeader;
    char aBuffer[0x2000];
    tHeader.f_0 = 0xFF;
    tHeader.nId = nId;
    tHeader.nLength = (unsigned short)(nSize + 4);
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected_00881BF0, 0, 0);
    if (!pSafeSock || InterlockedCompareExchange(&gnDnsDone_00881BFC, 0, 0))
    {
        sub_00520AD0_SetDisconnected();
        return 0;
    }
    if (!pData)
        nSize = 0;
    unsigned int nTotal = nSize + 4;
    SMemCopy(aBuffer, &tHeader, 4);
    if (pData && nTotal < 0x2000)
        SMemCopy(aBuffer + 4, pData, nSize);
    return FOG_SOCKET_Send(pSafeSock, aBuffer, nTotal);
}

// 0x00521B00
int __fastcall sub_00521B00(unsigned char nId, const void* pData, int nSize)
{
    int nResult = 0;
    if (nId < 0x5E)
    {
        if (gpfPacketHandlers_0072FFB0[nId])
            nResult = gpfPacketHandlers_0072FFB0[nId](pData, nSize);
        gnSlotArrayA_00882128[nId] = 1;
    }
    return nResult;
}

#include "gen/data/Source/Bnclient/0051C5C0_sub_0051C5C0_SendPacket.inc"
