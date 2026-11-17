struct D2WinControlStrc;
struct D2WinSmackStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion);                   // 0x00506910
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
extern D2WinControlStrc* gpControl_0077B098;                                                                // 0x0077B098
char gszTempFile_00798E30[260];                                                                             // 0x00798E30
char gszText_00798CF8[56];                                                                                  // 0x00798CF8

// 0x00446CA0
int __cdecl sub_00446CA0_PlayTempSmack()
{
    if (gszTempFile_00798E30[0] && GetFileAttributesA(gszTempFile_00798E30) != (unsigned long)-1)
    {
        const char* pExt = strrchr(gszTempFile_00798E30, '.') + 1;
        SMACK_Decode((D2WinSmackStrc*)gpControl_0077B098, gszTempFile_00798E30, tolower(*pExt));
        return 1;
    }
    return 0;
}

// 0x00446D00
static __forceinline int sub_00446D00_SetText(const char* szText)
{
    SStrCopy(gszText_00798CF8, szText, 0x32);
    return 1;
}

int __stdcall sub_M121_Emit_00446D00(const char* szText) { return sub_00446D00_SetText(szText); }
