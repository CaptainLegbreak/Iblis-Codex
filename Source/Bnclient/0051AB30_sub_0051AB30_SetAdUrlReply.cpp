extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0

char* gpAdUrlReply_008818DC;                                                                                // 0x008818DC

// 0x0051AB30
void __fastcall sub_0051AB30_SetAdUrlReply(const void* pData, unsigned int nSize)
{
    if (gpAdUrlReply_008818DC)
        SMemFree(gpAdUrlReply_008818DC, ".\\BnSend.cpp", 0x188, 0);
    gpAdUrlReply_008818DC = (char*)SMemAlloc(nSize, ".\\BnSend.cpp", 0x189, 0);
    memcpy(gpAdUrlReply_008818DC, pData, nSize);
}

// 0x0051AF20
int __cdecl sub_0051AF20_SendPacket10()
{
    return sub_0051C5C0_SendPacket(0x10, 0, 0) >= 0;
}
