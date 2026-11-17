#include "D2BNClient.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" size_t __cdecl strlen(const char* szString);
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0

extern void* gpReply_008818CC;                                                                              // 0x008818CC

// 0x0051ABF0
void* __cdecl sub_0051ABF0_QueryRealms()
{
    sub_00520C00_ClearReply(0x40);
    if (sub_0051C5C0_SendPacket(0x40, 0, 0) < 0)
    {
        return 0;
    }
    sub_00520B70_WaitForReply(0x40);
    return gpReply_008818CC;
}

// 0x0051AE10
int __fastcall sub_0051AE10_Send(const char* szArg1, const char* szArg2, int nArg3)
{
    int nProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    sub_0051C5C0_SendPacket(0x0B, &nProduct, 4);

    char szBuffer[0x200] = { 0 };
    SStrCopy(szBuffer, szArg1, 0x100);
    SStrCopy(&szBuffer[strlen(szBuffer) + 1], szArg2, 0x100);
    return sub_0051C5C0_SendPacket(0x0A, szBuffer, strlen(szBuffer) + strlen(&szBuffer[strlen(szBuffer) + 1]) + 2) >= 0;
}
