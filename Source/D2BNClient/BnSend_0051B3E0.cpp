#include "D2BNClient.h"

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" unsigned short __stdcall ntohs(unsigned short nValue);                                           // 0x006B019E

struct D2BnSizedReplyStrc
{
    unsigned int nSize;
    unsigned char abData[0x14];
    unsigned int nValue;
};

void* gnChannelList_008818C8;                                                                               // 0x008818C8
void* gpReply_008818CC;                                                                                     // 0x008818CC
void* gpReply_008818D0;                                                                                     // 0x008818D0
D2BnSizedReplyStrc* gpSizedReply_008818D4;                                                                  // 0x008818D4
void* gpReply_008818D8;                                                                                     // 0x008818D8

// 0x0051B3E0
void __fastcall sub_0051B3E0_SetSizedReply(const void* pData, unsigned int nSize)
{
    if (gpSizedReply_008818D4)
        FOG_Free(gpSizedReply_008818D4, ".\\BnSend.cpp", 0x3B2, 0);
    gpSizedReply_008818D4 = 0;
    gpSizedReply_008818D4 = (D2BnSizedReplyStrc*)FOG_Alloc(nSize + 4, ".\\BnSend.cpp", 0x3BB, 0);
    gpSizedReply_008818D4->nSize = nSize;
    memcpy(gpSizedReply_008818D4->abData, pData, nSize);
    if (nSize != 8 && nSize >= 0x48)
    {
        unsigned int* pValue = &gpSizedReply_008818D4->nValue;
        *pValue = ntohs(*pValue);
    }
}

// 0x0051B820
void __fastcall sub_0051B820_SetReply(const void* pData, unsigned int nSize)
{
    if (gpReply_008818D8)
        FOG_Free(gpReply_008818D8, ".\\BnSend.cpp", 0x4EC, 0);
    gpReply_008818D8 = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x4ED, 0);
    memcpy(gpReply_008818D8, pData, nSize);
}

// 0x0051BD60
void __fastcall sub_0051BD60_SetReply(const void* pData, unsigned int nSize)
{
    if (gpReply_008818CC)
        FOG_Free(gpReply_008818CC, ".\\BnSend.cpp", 0x19A, 0);
    gpReply_008818CC = 0;
    gpReply_008818CC = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x16B, 0);
    memcpy(gpReply_008818CC, pData, nSize);
}

// 0x0051BDC0
void __fastcall sub_0051BDC0_SetReply(const void* pData, unsigned int nSize)
{
    if (gnChannelList_008818C8)
        FOG_Free(gnChannelList_008818C8, ".\\BnSend.cpp", 0x1EF, 0);
    gnChannelList_008818C8 = 0;
    gnChannelList_008818C8 = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x1E6, 0);
    memcpy(gnChannelList_008818C8, pData, nSize);
}

// 0x0051BE20
void __fastcall sub_0051BE20_SetReply(const void* pData, unsigned int nSize)
{
    if (gpReply_008818D0)
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    gpReply_008818D0 = 0;
    gpReply_008818D0 = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x326, 0);
    memcpy(gpReply_008818D0, pData, nSize);
}
