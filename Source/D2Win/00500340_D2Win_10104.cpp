extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

struct D2WinControlStrc
{
    int nType;
    char unk0x04[0x40 - 0x04];
};

struct D2WinAnimImageStrc
{
    D2WinControlStrc controlHeader;
    void* pAnimatedImageDescriptor;
    unsigned int nAnimSpeed;
    unsigned long dwStartTickCount;
    unsigned int nFrame;
    int nAnimType;
};

// 0x00500340
int __fastcall D2Win_10104(D2WinAnimImageStrc* pAnimImage)
{
    D2_ASSERT(pAnimImage->controlHeader.nType == 2, 92);

    if (pAnimImage->nAnimType == 3)
    {
        pAnimImage->nAnimType = 4;
        pAnimImage->nFrame = 0;
        pAnimImage->dwStartTickCount = GetTickCount();
    }
    else if (pAnimImage->nAnimType == 2 || pAnimImage->nAnimType == 4)
    {
        return 0;
    }

    return 1;
}
