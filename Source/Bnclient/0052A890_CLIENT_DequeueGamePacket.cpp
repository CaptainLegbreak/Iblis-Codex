struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
struct D2NetPacketRecStrc;

extern D2CriticalSectionStrc gCriticalSection;                                                              // 0x00882CE8
extern D2NetPacketRecStrc* gpGamePacketList;                                                                      // 0x00882CE4
extern D2NetPacketRecStrc* gpSystemPacketList;                                                                    // 0x00882CDC

int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052B820

// 0x0052A890
int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpGamePacketList, pBuffer, nBufferSize);
}

// 0x0052A8B0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize)
{
    return NET_DequeueFirstPacketFromList(&gCriticalSection, &gpSystemPacketList, pBuffer, nBufferSize);
}
