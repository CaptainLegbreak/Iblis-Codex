extern "C" __declspec(dllimport) unsigned int __stdcall GetWindowsDirectoryA(char* lpBuffer, unsigned int uSize); // 0x006CC374
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" int __stdcall DirectSoundEnumerateA(void* pfCallback, void* pContext);                           // 0x006B134A

void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
int __stdcall sub_00513A20_EnumCallback(void* pGuid, const char* szDescription, const char* szModule, void* pContext); // 0x00513A20
void __fastcall sub_005140D0_TrySetup();                                                                    // 0x005140D0
int __fastcall sub_00516CA0_GetFileVersion(const char* szPath, unsigned int* pMajor, unsigned int* pMinor, unsigned int* pBuild); // 0x00516CA0

extern int gnSoundArg_008816DC;                                                                             // 0x008816DC
int gbSoundReady_00881764;                                                                                  // 0x00881764
extern int gdwGlobal_0088176C;                                                                              // 0x0088176C
int gbEaxEnabled_00881770;                                                                                  // 0x00881770
extern int gbSoundEnumDone_00881780;                                                                        // 0x00881780
int gbOldSoundDriver_00881784;                                                                              // 0x00881784
int gbCheckEmu10k1_00881788;                                                                                // 0x00881788
extern int gbCheckCrlds3d_0088178C;                                                                         // 0x0088178C
extern int gdwGlobal_00881790;                                                                              // 0x00881790

// 0x00514530
void __fastcall sub_00514530_InitSound(int nArg1, int nArg2)
{
    gdwGlobal_00881790 = nArg1;
    gnSoundArg_008816DC = nArg2;
    gbSoundEnumDone_00881780 = 0;
    DirectSoundEnumerateA(sub_00513A20_EnumCallback, 0);

    char szPath[260];
    unsigned int nMajor;
    unsigned int nMinor;
    unsigned int nBuild;
    if (gbCheckEmu10k1_00881788)
    {
        GetWindowsDirectoryA(szPath, sizeof(szPath));
        strcat(szPath, "\\SYSTEM\\EMU10K1.VXD");
        if (sub_00516CA0_GetFileVersion(szPath, &nMajor, &nMinor, &nBuild) && nMajor == 4)
        {
            if (nMinor == 6)
            {
                if (nBuild - 622 <= 88)
                {
                    gbOldSoundDriver_00881784 = 1;
                }
            }
            else if (nMinor == 11)
            {
                if (nBuild - 628 <= 1)
                {
                    gbOldSoundDriver_00881784 = 1;
                }
            }
        }
    }

    if (gbCheckCrlds3d_0088178C)
    {
        GetWindowsDirectoryA(szPath, sizeof(szPath));
        strcat(szPath, "\\SYSTEM\\CRLDS3D.VXD");
        if (sub_00516CA0_GetFileVersion(szPath, &nMajor, &nMinor, &nBuild)
            && (nMajor < 4 || nMajor == 4 && (nMinor < 12 || nMinor == 12 && nBuild < 0x40B)))
        {
            gbOldSoundDriver_00881784 = 1;
        }
    }

    if (!gbSoundReady_00881764)
    {
        gdwGlobal_0088176C = 1;
        gbEaxEnabled_00881770 = 1;
        sub_005140D0_TrySetup();
        if (!gbSoundReady_00881764)
        {
            gdwGlobal_0088176C = 1;
            gbEaxEnabled_00881770 = 0;
            sub_005140D0_TrySetup();
            if (!gbSoundReady_00881764)
            {
                gdwGlobal_0088176C = 0;
                gbEaxEnabled_00881770 = 0;
                sub_005140D0_TrySetup();
                if (!gbSoundReady_00881764)
                {
                    sub_00410610_WriteLogLine("\tCouldn't initialize DirectSound");
                }
            }
        }
    }
}
