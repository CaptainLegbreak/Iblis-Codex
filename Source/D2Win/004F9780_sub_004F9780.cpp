extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct D2WinControlStrc
{
    int nType;
    D2CelFileStrc* pCellFile;
    unsigned int dwFlags;
    int nImageX;
    int nImageY;
    int nWidth;
    int nHeight;
    void* pfDraw;
    void* pfInitialize;
    void* pfHandleMouseDown;
    void* pfHandleMouseUp;
    void* pfHandleCharInput;
    void* pfHandleVirtualKeyInput;
    void* field_34;
    void* pfShouldMouseInputBeHandled;
    D2WinControlStrc* pNext;
};

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2WinControlStrc* dword_6F8FE264;                                                                    // 0x007D55D4

// 0x004F9780
int __fastcall sub_004F9780(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x35A);

    return pControl->dwFlags & gdwBitMasks[2];
}

// 0x004F9B30
int __fastcall sub_004F9B30_CONTROL_IsInActiveList(D2WinControlStrc* pControl)
{
    if (dword_6F8FE264)
    {
        for (D2WinControlStrc* p = dword_6F8FE264; p; p = p->pNext)
        {
            if (p == pControl)
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}
