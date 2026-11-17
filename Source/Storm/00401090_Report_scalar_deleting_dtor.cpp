typedef char* va_list;
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

struct _iobuf;

extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC
extern "C" int __cdecl vfprintf(_iobuf* pFile, const char* szFormat, va_list args);                         // 0x00685637
void __cdecl operator delete(void* pMemory);                                                                // 0x004053F0

namespace crashy
{
class Report
{
public:
    Report();
    virtual ~Report();
    int sub_00401380(const char* szFormat, ...);
    char* sub_004072A0_GetLine(int nIndex);

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[1][0x400];
};
}

crashy::Report::Report()
{
    m_pFile = 0;
    m_nLineCount = 0;
    m_szText408[0] = 0;
    m_szText08[0] = 0;
}

// build: symbol ??_7Report@crashy@@6B@ 0x006FF984
// build: symbol ??_GReport@crashy@@UAEPAXI@Z 0x00401090
inline crashy::Report::~Report()
{
    if (m_pFile)
    {
        fclose(m_pFile);
        m_pFile = 0;
    }
}

// 0x00401380
int crashy::Report::sub_00401380(const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    return vfprintf(m_pFile, szFormat, args);
}

// 0x004072A0
char* crashy::Report::sub_004072A0_GetLine(int nIndex)
{
    return m_aszLines[nIndex];
}
