extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName);        // 0x006CC1B0
void __fastcall FOG_GetInstallPath(char* szPath, int nBufferSize);                                          // 0x00406BA0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __cdecl sub_00406D20();                                                                              // 0x00406D20
extern "C" const char szD2CharMpq_006DC77C[];                                                               // 0x006DC77C

// 0x004FAC90
int __cdecl sub_004FAC90_CheckCharArchive()
{
    char szPath[0x104];
    FOG_GetInstallPath(szPath, sizeof(szPath));
    sub_00413800(szPath, szD2CharMpq_006DC77C, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    SStrCopy(szPath, szD2CharMpq_006DC77C, sizeof(szPath));
    if (GetFileAttributesA(szPath) != -1)
    {
        return 0;
    }

    return !sub_00406D20();
}
