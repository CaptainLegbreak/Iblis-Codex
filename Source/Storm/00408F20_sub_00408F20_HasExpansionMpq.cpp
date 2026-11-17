extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
void __fastcall FOG_GetInstallPath(char* szPath, int nBufferSize);                                          // 0x00406BA0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
extern "C" const char gszExpansionMpq_006CD3A0[];                                                           // 0x006CD3A0

static int s_bExpansionChecked_0074F0DC;                                                                    // 0x0074F0DC
static int s_bExpansionMpq_0074F0D8;                                                                        // 0x0074F0D8

static int FOG_FileExists(const char* szFile)
{
    return GetFileAttributesA(szFile) != (unsigned long)-1;
}

// 0x00408F20
int __cdecl sub_00408F20_HasExpansionMpq()
{
    if (!s_bExpansionChecked_0074F0DC)
    {
        char szPath[0x104];
        s_bExpansionChecked_0074F0DC = 1;
        FOG_GetInstallPath(szPath, 0x104);
        sub_00413800(szPath, gszExpansionMpq_006CD3A0, 0x104);
        int bExists = FOG_FileExists(szPath);
        if (!bExists)
        {
            SStrCopy(szPath, gszExpansionMpq_006CD3A0, 0x104);
            bExists = FOG_FileExists(szPath);
        }
        if (bExists)
            s_bExpansionMpq_0074F0D8 = 1;
    }
    return s_bExpansionMpq_0074F0D8;
}
