extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

char* gpMcpPacket; // 0x007992F4

// 0x00449E70
void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize)
{
    if (gpMcpPacket)
    {
        FOG_Free(gpMcpPacket, ".\\Src\\McpConnect.cpp", 0x21E, 0);
        gpMcpPacket = 0;
    }
    if (!nSize)
        return;
    gpMcpPacket = (char*)FOG_Alloc(nSize, ".\\Src\\McpConnect.cpp", 0x227, 0);
    memcpy(gpMcpPacket, pData, nSize);
    if (*pData == 0x17)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 1) < 0x100, 0x233);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 3) < 0x100, 0x234);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 5) < 0x100, 0x235);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 7) < 0x100, 0x236);
    }
    else if (*pData == 0x19)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 1) < 0x100, 0x242);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 3) < 0x100, 0x243);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 5) < 0x100, 0x244);
        const unsigned short nCount = *(unsigned short*)(gpMcpPacket + 7);
        D2_ASSERT(nCount < 0x100, 0x245);
        const char* p = gpMcpPacket + 9;
        for (int i = 0; i < nCount; i++)
        {
            p += 4;
            while (*p++);
            while (*p++);
        }
    }
    else
    {
        D2_ASSERT(0, 0x254);
    }
}
