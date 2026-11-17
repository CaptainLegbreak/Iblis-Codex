extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

struct D2CelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
};

int __stdcall D2CMP_CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50

// 0x00601EA0
void __stdcall sub_00601EA0_CelFileRelease(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile, 0x41B);
    if (pCelFile->dwFlags & 3)
    {
        if (pCelFile->dwFlags & 2)
        {
            D2CMP_CelFileFreeHardware(pCelFile);
        }
        FOG_Free(pCelFile, ".\\SRC\\CelCmp.cpp", 0x422, 0);
    }
}
