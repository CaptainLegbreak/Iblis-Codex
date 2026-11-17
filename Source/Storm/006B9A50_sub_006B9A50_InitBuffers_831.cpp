extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern void* gpArray_009897D4[2]; // 0x009897D4
extern void* gpArray_009897DC[2]; // 0x009897DC
extern void* gpArray_009897E4[2]; // 0x009897E4
extern void* gpArray_009897EC[2]; // 0x009897EC
void __fastcall sub_006B3730_Allocate(void** ppFirst, void** ppSecond, int nCount, int nSize); // 0x006B3730
int __fastcall sub_006B58A0_Allocate(void** ppFirst, void** ppSecond, int nCount, int nSize); // 0x006B58A0

// 0x006B9A50
char* __fastcall sub_006B9A50_InitBuffers(char* pBuffer)
{
    for (int i = 0; i < 2; ++i)
    {
        void** ppFirst = &gpArray_009897D4[i];
        void** ppSecond = &gpArray_009897DC[i];
        sub_006B3730_Allocate(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4A);
        D2_ASSERT(*ppSecond, 0x4B);
        ppFirst = &gpArray_009897E4[i];
        ppSecond = &gpArray_009897EC[i];
        int nResult = sub_006B58A0_Allocate(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4E);
        D2_ASSERT(*ppSecond, 0x4F);
        D2_ASSERT(nResult, 0x50);
    }
    return pBuffer + 0x10000;
}
