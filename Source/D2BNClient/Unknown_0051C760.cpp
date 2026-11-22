extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __fastcall BNSEND_DispatchPacket(unsigned char nId, const void* pData, int nSize);       // 0x00521B00

// 0x0051C760
int __fastcall sub_0051C760_SplitPackets(unsigned char* pBuffer, int nLength)
{
    unsigned char* p = pBuffer;
    for (;;)
    {
        while (*p != 0xFF && p - pBuffer < nLength)
            ++p;
        const unsigned short nSize = *(unsigned short*)(p + 2);
        const int nLeft = pBuffer + nLength - p;
        if ((unsigned int)nLeft < 4 || nLeft < nSize)
            break;
        BNSEND_DispatchPacket(p[1], p + 4, nSize - 4);
        p += nSize;
    }
    const int nRemain = pBuffer + nLength - p;
    memcpy(pBuffer, p, nRemain);
    return nRemain;
}
