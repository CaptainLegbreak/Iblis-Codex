#pragma once
// Fog queue server (QServer*.cpp): the server and client records.

#include "D2SysTypes.h"
#include "D2NetTypes.h"
#include "Fog.h"

struct D2QueueServerStrc;
struct D2QClientStrc;
struct D2QLockStrc;
struct D2QServerIpNodeStrc;
struct D2QIpCountStrc;
struct D2QServerNodeStrc;
struct D2MessageStrc;
struct D2AddressRecordStrc;
struct D2ServerNode006BE980Strc;
struct D2QWriteNodeStrc;
struct D2QNodeStrc;

typedef void (__fastcall* D2AddressCallback)(unsigned int, const char*, int);
typedef int (__fastcall* D2MessageCallback)(unsigned char*, int, int*, int*, int*, int*, int, int, unsigned int);
typedef void (__fastcall* D2NewClientFn)(D2QueueServerStrc*, int, const char*, int);
typedef void (__fastcall* D2QRemoveCallback)(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine);

struct D2QClientStrc
{
    union
    {
        unsigned int nId;                                   // 0x000
        int iId;
        void* pKey;
    };
    union
    {
        D2QClientStrc* pNext;                               // 0x004
        int f_4;
    };
    long nRefCount;                                         // 0x008
    int bClosing;                                           // 0x00C
    union
    {
        void* hSocket;                                      // 0x010
        unsigned int nSocket;
        int iSocket;
    };
    int nSlot;                                              // 0x014
    unsigned int nAddress;                                  // 0x018
    D2QClientStrc* pNextByAddress;                          // 0x01C
    int nContext;                                           // 0x020
    union
    {
        unsigned long nTick24;                              // 0x024
        int nPending24;
    };
    union
    {
        unsigned int nPending;                              // 0x028
        int nQueued;
    };
    union
    {
        struct
        {
            D2CriticalSectionStrc tLock;                    // 0x02C
            union
            {
                D2QOverlappedStrc tRead;                    // 0x044
                struct
                {
                    int unk0x044[5];
                    int bEnabled;                           // 0x058
                };
            };
            union
            {
                D2QOverlappedStrc tWrite;                   // 0x05C
                struct
                {
                    int unk0x05C[5];
                    int nState;                             // 0x070
                };
            };
        };
        char cs[0x48];                                      // 0x02C
    };
    union
    {
        D2QWriteNodeStrc* pWriteQueue;                      // 0x074
        D2QNodeStrc* pNodes;
        int nValue74;
    };
    D2SockAddrInStrc tLocalAddr;                            // 0x078
    D2SockAddrInStrc tPeerAddr;                             // 0x088
    unsigned int nCreateTime;                               // 0x098
    unsigned int nLastTick;                                 // 0x09C
    unsigned int nTick3;                                    // 0x0A0
    unsigned int nTick4;                                    // 0x0A4
    union
    {
        unsigned int nReadBytes;                            // 0x0A8
        int iReadBytes;
    };
    unsigned long nBytesRead;                               // 0x0AC
    union
    {
        unsigned char pBuffer[0x5B4];                       // 0x0B0
        struct
        {
            unsigned char unk0x0B0[0x50C];
            D2QClientStrc* pNextQueued;                     // 0x5BC
        };
    };
};

struct D2QueueServerStrc
{
    int bAltSend;                                           // 0x000
    int unk0x004;                                           // 0x004
    unsigned int nBuckets;                                  // 0x008
    unsigned int nMask;                                     // 0x00C
    unsigned int nIpBuckets;                                // 0x010
    D2QClientStrc** ppClients;                              // 0x014
    int nBucketCount;                                       // 0x018
    union
    {
        D2CriticalSectionStrc* pLocks;                      // 0x01C
        D2QLockStrc* pClientLocks;
    };
    D2QClientStrc** ppAddressBuckets;                       // 0x020
    int unk0x024;                                           // 0x024
    D2CriticalSectionStrc tAddressLock;                     // 0x028
    union
    {
        D2QServerIpNodeStrc** ppIpBuckets;                  // 0x040
        D2QIpCountStrc** ppIpCounts;
    };
    int unk0x044[0x202];                                    // 0x044
    D2QServerNodeStrc* pHead;                               // 0x84C
    D2QServerNodeStrc* pTail;                               // 0x850
    D2CriticalSectionStrc tLock;                            // 0x854
    int unk0x86C;                                           // 0x86C
    D2MessageStrc** ppMsgHeads;                             // 0x870
    D2MessageStrc** ppMsgTails;                             // 0x874
    D2MessageStrc* pFreeMessages;                           // 0x878
    int nQueueCount;                                        // 0x87C
    int nClients;                                           // 0x880
    int nLimit;                                             // 0x884
    int unk0x888;                                           // 0x888
    D2AddressRecordStrc* pFreeRecords;                      // 0x88C
    int nRecordCount;                                       // 0x890
    D2CriticalSectionStrc tRecordLock;                      // 0x894
    union
    {
        D2AddressRecordStrc** ppRecords;                    // 0x8AC
        D2ServerNode006BE980Strc** ppRecordNodes;
    };
    unsigned int nRecordBuckets;                            // 0x8B0
    D2CriticalSectionStrc tClientLock;                      // 0x8B4
    union
    {
        unsigned char aRecords[0x2DC];                      // 0x8CC
        struct
        {
            int unk0x8CC[0xB1];
            int nListener;                                  // 0xB90
        };
    };
    int aValues[4];                                         // 0xBA8
    D2AddressCallback pfnAddressCallback;                   // 0xBB8
    int unk0xBBC;                                           // 0xBBC
    D2MessageCallback pfnProcess;                           // 0xBC0
    D2NewClientFn pfnOnNewClient;                           // 0xBC4
    D2QRemoveCallback pfnOnRemove;                          // 0xBC8
    int unk0xBCC;                                           // 0xBCC
    int bEnabled;                                           // 0xBD0
    void* hEvent;                                           // 0xBD4
    int unk0xBD8[8];                                        // 0xBD8
    int bStop;                                              // 0xBF8
    int unk0xBFC[7];                                        // 0xBFC
    int bInitialized;                                       // 0xC18
    int unk0xC1C[8];                                        // 0xC1C
    int nSlots[1];                                          // 0xC3C

    int __thiscall sub_006BE980_Refresh(unsigned int nKey);                                                 // 0x006BE980
    int __thiscall sub_006BF660_CheckClient(int nClientId);                                                 // 0x006BF660
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress);                                        // 0x006BF660
};
