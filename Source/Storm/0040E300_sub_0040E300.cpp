typedef unsigned int size_t;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
int __cdecl sub_0040E250_GetCpuVendor();                                                                    // 0x0040E250
unsigned int __cdecl sub_0040E960_GetCpuSignature();                                                        // 0x0040E960
unsigned int __cdecl sub_0040E980_GetCpuBrand();                                                            // 0x0040E980
int __cdecl sub_0040E870_MeasureCpuMHz();                                                                   // 0x0040E870
struct T004013C0
{
    unsigned long dwOemId;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};
extern T004013C0 gtSystemInfo_0074D8A0;                                                                     // 0x0074D8A0
#define gwProcessorLevel_0074D8C0 (gtSystemInfo_0074D8A0.wProcessorLevel)
extern const char* gaszCpuVendorNames_00708004[];                                                           // 0x00708004
extern "C" const char gszIntel386_006CE074[];                                                               // 0x006CE074
extern "C" const char gszIntel486_006CE080[];                                                               // 0x006CE080
extern "C" const char gszCpuSpeedFormat_006CE08C[];                                                         // 0x006CE08C
extern "C" const char gszCpuVersionFormat_006CE0A8[];                                                       // 0x006CE0A8
extern "C" const char gszCpuVendorFormat_006CE0EC[];                                                        // 0x006CE0EC

// 0x0040E300
static void __stdcall sub_0040E300(char* szBuf, int nVendor, int nFamily, unsigned int nModel, int nBrand, int nType)
{
    strcpy(szBuf, "{Unknown}");
    switch (nVendor)
    {
    case 1:
        if (nBrand == 1)
        {
            strcpy(szBuf, "Celeron");
        }
        else if (nBrand == 2)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nBrand == 3)
        {
            strcpy(szBuf, "Pentium III Xeon");
        }
        else if (nBrand == 4)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nBrand == 8)
        {
            strcpy(szBuf, "Pentium 4");
        }
        else if (nBrand == 14)
        {
            strcpy(szBuf, "Xeon");
        }
        else if (nType == 0 && nFamily == 5 && nModel < 4)
        {
            strcpy(szBuf, "Pentium");
        }
        else if (nType == 0 && nFamily == 5)
        {
            strcpy(szBuf, "Pentium MMX");
        }
        else if (nType == 1 && nFamily == 5 && nModel < 3)
        {
            strcpy(szBuf, "Pentium OD586");
        }
        else if (nType == 1 && nFamily == 5 && nModel == 3)
        {
            strcpy(szBuf, "Pentium OD486");
        }
        else if (nType == 1 && nFamily == 5 && nModel >= 4)
        {
            strcpy(szBuf, "Pentium MMX OD586");
        }
        else if (nType == 0 && nFamily == 6 && nModel < 3)
        {
            strcpy(szBuf, "Pentium Pro");
        }
        else if (nType == 1 && nFamily == 6)
        {
            strcpy(szBuf, "Pentium II OD");
        }
        else if (nType == 0 && nFamily == 6 && nModel < 5)
        {
            strcpy(szBuf, "Pentium II");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 5)
        {
            strcpy(szBuf, "Pentium II or Celeron");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 6)
        {
            strcpy(szBuf, "Celeron");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 7)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nType == 0 && nFamily == 6 && nModel >= 8)
        {
            strcpy(szBuf, "Pentium III (no brand)");
        }
        else if (nType == 0 && nFamily == 15)
        {
            strcpy(szBuf, "Pentium 4 (no brand)");
        }
        break;
    case 2:
        if (nFamily == 4)
        {
            strcpy(szBuf, "Am486DX4 or Am5x86");
        }
        else if (nFamily == 5)
        {
            if (nModel < 6)
            {
                strcpy(szBuf, "K5");
            }
            else if (nModel < 8)
            {
                strcpy(szBuf, "K6");
            }
            else if (nModel == 8)
            {
                strcpy(szBuf, "K6-II");
            }
            else if (nModel >= 9)
            {
                strcpy(szBuf, "K6-III");
            }
        }
        else if (nFamily == 6)
        {
            if (nModel < 3)
            {
                strcpy(szBuf, "Athlon");
            }
            else if (nModel == 3)
            {
                strcpy(szBuf, "Duron");
            }
            else if (nModel < 6)
            {
                strcpy(szBuf, "Athlon");
            }
            else if (nModel == 6)
            {
                strcpy(szBuf, "Athlon MP, XP, or Mobile");
            }
            else if (nModel == 7)
            {
                strcpy(szBuf, "Duron Mobile");
            }
        }
        break;
    case 3:
        if (nType == 0)
        {
            if (nFamily == 4)
            {
                strcpy(szBuf, "MediaGX");
            }
            else if (nFamily == 5)
            {
                if (nModel < 4)
                {
                    strcpy(szBuf, "6x86");
                }
                else
                {
                    strcpy(szBuf, "GXm");
                }
            }
            else if (nFamily == 6)
            {
                strcpy(szBuf, "6x86MX");
            }
        }
        break;
    }
}

void __cdecl sub_0040EA00_WriteProcessorReport()
{
    char szName[0x100];
    switch (gwProcessorLevel_0074D8C0)
    {
    case 3:
        sub_00410610_WriteLogLine(gszIntel386_006CE074);
        break;
    case 4:
        sub_00410610_WriteLogLine(gszIntel486_006CE080);
        break;
    default:
    {
        const int nVendor = sub_0040E250_GetCpuVendor();
        const unsigned int nSignature = sub_0040E960_GetCpuSignature();
        const unsigned int nModel = (nSignature >> 4) & 0xF;
        const int nType = (nSignature >> 12) & 3;
        const int nFamily = (nSignature >> 8) & 0xF;
        const int nBrand = sub_0040E980_GetCpuBrand() & 0xFF;
        sub_0040E300(szName, nVendor, nFamily, nModel, nBrand, nType);
        sub_00410610_WriteLogLine(gszCpuVendorFormat_006CE0EC, gaszCpuVendorNames_00708004[nVendor]);
        sub_00410610_WriteLogLine(gszCpuVersionFormat_006CE0A8, szName, nType, nFamily, nModel, nSignature & 0xF, nBrand);
        sub_00410610_WriteLogLine(gszCpuSpeedFormat_006CE08C, sub_0040E870_MeasureCpuMHz());
        break;
    }
    }
}
