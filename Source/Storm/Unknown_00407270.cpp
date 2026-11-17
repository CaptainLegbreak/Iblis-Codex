struct _iobuf;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize);                                   // 0x0040C220
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800
int __fastcall sub_00406A10_CreateDirectoryTree(const char* szPath);                                        // 0x00406A10
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
static __forceinline void sub_00407540_MakeAppSubdir(char* szPath, unsigned int nSize)
{
    *szPath = 0;
    if (sub_0040C220_GetAppPath(szPath, nSize))
    {
        sub_00413800(szPath, "\\", nSize);
        sub_00406A10_CreateDirectoryTree(szPath);
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
