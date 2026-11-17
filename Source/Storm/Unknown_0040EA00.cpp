#include "Storm.h"

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
int __stdcall sub_0040E870_MeasureCpuMHz();                                                                   // 0x0040E870
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
T004013C0 gtSystemInfo_0074D8A0;                                                                            // 0x0074D8A0

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

// 0x0040EA00
void __cdecl sub_0040EA00_WriteProcessorReport()
{
    char szName[0x100];

    switch (gwProcessorLevel_0074D8C0)
    {
    case 3:
        sub_00410610_WriteLogLine("Intel 386");
        break;

    case 4:
        sub_00410610_WriteLogLine("Intel 486");
        break;

    default:
    {
        int nVendor = sub_0040E250_GetCpuVendor();
        unsigned int dwSignature = sub_0040E960_GetCpuSignature();
        int nType = (dwSignature >> 12) & 3;
        int nFamily = (dwSignature >> 8) & 0xF;
        int nModel = (dwSignature >> 4) & 0xF;
        int nBrand = sub_0040E980_GetCpuBrand() & 0xFF;
        sub_0040E300(szName, nVendor, nFamily, nModel, nBrand, nType);
        sub_00410610_WriteLogLine("Vendor:  %s", gaszCpuVendorNames_00708004[nVendor]);
        sub_00410610_WriteLogLine("Version: %s (Type %X, Family %X, Model %X, Stepping %X, Brand %X)", szName, nType, nFamily, nModel, dwSignature & 0xF, nBrand);
        sub_00410610_WriteLogLine("Speed: Approx. %d MHz", sub_0040E870_MeasureCpuMHz());
        break;
    }
    }
}

#include "gen/data/Source/Storm/Unknown_0040EA00.inc"
