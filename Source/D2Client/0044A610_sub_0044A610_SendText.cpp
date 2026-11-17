#pragma pack(push, 1)
struct D2McpPacket06Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

void __stdcall sub_00449BF0_SetValue(int nValue);                                                           // 0x00449BF0
void __stdcall sub_00449C20_SetValue(int nValue);                                                           // 0x00449C20
int __stdcall sub_006BC8A0_SendBuffer(void* pConnection, const unsigned char* pBuffer, int nSize);          // 0x006BC8A0

extern void* gpConnection_00798FB4;                                                                         // 0x00798FB4
extern unsigned short gwMcpRequestId_00798F8C;                                                              // 0x00798F8C

static char* __stdcall sub_0044A170_AppendText(unsigned int nMax, char* pDest, const char* szText, unsigned int* pnSize)
{
    const unsigned int nLength = strlen(szText);
    *pnSize += nLength + 1;
    D2_ASSERT(*pnSize < nMax, 0x26);
    strcpy(pDest, szText);
    return pDest + nLength + 1;
}

// 0x0044A610
int __fastcall sub_0044A610_SendText(char* szText, unsigned short wRequestId)
{
    D2McpPacket06Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 6;
    tPacket.f_1 = wRequestId;
    gwMcpRequestId_00798F8C = wRequestId;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    nSize += 3;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nSize);
}
