struct _iobuf;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize);                                   // 0x0040C220
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
int __fastcall FOG_CreatePathHierarchy(const char* szPath);                                        // 0x00406A10
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...);                // 0x00410660

namespace crashy
{
class Report
{
public:
    Report();
    virtual ~Report();
    int Printf(const char* szFormat, ...);
    char* sub_004072A0_GetLine(int nIndex);
    char* sub_00407270_GetText08();
    char* sub_00407280_GetText408();
    int sub_00407290_GetLineCount();

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[1][0x400];
};
}

struct D2OsVersionInfoStrc
{
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};

struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

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

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2OsVersionInfoStrc* pInfo); // 0x006CC1F8
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus); // 0x006CC1F4
extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(T004013C0* pInfo); // 0x006CC1F0
extern unsigned long gdwTotalPhys_0074D898; // 0x0074D898
extern T004013C0 gtSystemInfo_0074D8A0; // 0x0074D8A0
int gnOsKind_0074D890; // 0x0074D890
float gfOsVersion_0074D894; // 0x0074D894
int gbSystemInfoDone_0074D88C; // 0x0074D88C

// 0x00407270
char* crashy::Report::sub_00407270_GetText08()
{
    return m_szText08;
}

// 0x00407280
char* crashy::Report::sub_00407280_GetText408()
{
    return m_szText408;
}

// 0x00407290
int crashy::Report::sub_00407290_GetLineCount()
{
    return m_nLineCount;
}

// 0x004072C0
void __cdecl sub_004072C0_Empty()
{
}

// 0x004072D0
void __cdecl sub_004072D0_Empty()
{
}

// 0x004072E0
void __cdecl sub_004072E0_Empty()
{
}

// 0x004072F0
void __cdecl sub_004072F0_Empty()
{
}

// 0x00407300
void __cdecl sub_00407300_Empty()
{
}

// 0x00407540
static inline void sub_00407540_MakeAppSubdir(char* szPath, unsigned int nSize)
{
    *szPath = 0;
    if (EXCEPTIONS_GetAppPath(szPath, nSize))
    {
        SStrPack(szPath, "\\", nSize);
        FOG_CreatePathHierarchy(szPath);
    }
}

void __fastcall sub_M111_Emit_00407540(char* szPath, unsigned int nSize, int* pDone)
{
    sub_00407540_MakeAppSubdir(szPath, nSize);
    *pDone = 1;
}

// 0x00407DD0
bool __cdecl sub_00407DD0_AlwaysFalse()
{
    return false;
}

// 0x00407F70
void __fastcall sub_00407F70_LogText(void* pUnused, const char* szText)
{
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, szText);
}

// 0x00407FA0
void __cdecl sub_00407FA0_Empty()
{
}

// 0x00407FB0
void __cdecl sub_00407FB0_Empty()
{
}

// 0x00407DE0
void __cdecl AUTOMAP_CaptureSystemInfo()
{
    D2OsVersionInfoStrc tVersion;
    D2MemoryStatusStrc tMemory;
    tVersion.dwOSVersionInfoSize = sizeof(tVersion);
    if (GetVersionExA(&tVersion))
    {
        float fMinor = (float)tVersion.dwMinorVersion;
        while (fMinor > 1.0)
        {
            fMinor = fMinor / 10.0;
        }
        gfOsVersion_0074D894 = (float)((float)tVersion.dwMajorVersion + fMinor / 100.0);
        switch (tVersion.dwPlatformId)
        {
        case 2:
            gnOsKind_0074D890 = 1;
            if (tVersion.dwMajorVersion >= 5)
            {
                if (tVersion.dwMinorVersion >= 2)
                {
                    gnOsKind_0074D890 = 4;
                }
                else
                {
                    gnOsKind_0074D890 = tVersion.dwMinorVersion < 1 ? 2 : 3;
                }
            }
            break;
        case 3:
            gnOsKind_0074D890 = 0;
            break;
        default:
            gnOsKind_0074D890 = 0;
            break;
        }
    }
    GlobalMemoryStatus(&tMemory);
    gdwTotalPhys_0074D898 = tMemory.dwTotalPhys;
    GetSystemInfo(&gtSystemInfo_0074D8A0);
    gbSystemInfoDone_0074D88C = 1;
}
