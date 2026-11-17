extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall sub_0052B690_SendToServer(const unsigned char* pBuffer, unsigned short nSize);               // 0x0052B690

// 0x0052ADC0
int __fastcall sub_0052ADC0_SendToServerChecked(void* pUnused, unsigned short nSize, const unsigned char* pBuffer)
{
    D2_ASSERT(nSize <= 0x204, 0x1C6);
    return sub_0052B690_SendToServer(pBuffer, nSize);
}
