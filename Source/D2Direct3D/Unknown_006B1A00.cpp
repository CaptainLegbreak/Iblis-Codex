extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz); // 0x006CC154
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey);
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* lpSubKey, unsigned long Reserved, char* lpClass, unsigned long dwOptions, unsigned long samDesired, void* lpSecurityAttributes, void** phkResult, unsigned long* lpdwDisposition);

namespace Define_the_symbol__ATL_MIXED
{
struct Thank_you
{
    Thank_you();
    virtual void sub_006B1A10_Nop();
};
}

namespace ATL
{

class CAtlException
{
public:
    long m_hr;
    CAtlException(long hr) : m_hr(hr)
    {
    }
};

void __cdecl sub_006B1A30_ThrowAtlException(long error);

class CRegKey
{
public:
    void* m_hKey;

    CRegKey() throw();
    long Close() throw();
    long Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass, unsigned long dwOptions, unsigned long samDesired, void* lpSecAttr, unsigned long* lpdwDisposition) throw();
    long SetDWORDValue(const char* pszValueName, unsigned long dwValue) throw();
    long SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType) throw();
    void* GetHKEY() const throw();
};

}

struct GUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

// atliface.h
extern "C" const GUID LIBID_ATLLib;
extern "C" const GUID CLSID_Registrar;
extern "C" const GUID IID_IRegistrar;
extern "C" const GUID IID_IAxWinHostWindow;
extern "C" const GUID IID_IAxWinAmbientDispatch;
extern "C" const GUID IID_IInternalConnection;
extern "C" const GUID IID_IDocHostUIHandlerDispatch;
extern "C" const GUID IID_IAxWinHostWindowLic;
extern "C" const GUID IID_IAxWinAmbientDispatchEx;

namespace ATL
{

// statreg.h
class CRegParser
{
public:
    static const char* const szStringVal;
    static const char* const multiszStringVal;
    static const char* const szDwordVal;
    static const char* const szBinaryVal;
    static const char* const szValToken;
    static const char* const szForceRemove;
    static const char* const szNoRemove;
    static const char* const szDelete;
    static const int MAX_VALUE;
    static const int MAX_TYPE;
    static const char* const rgszNeverDelete[12];
    static const int cbNeverDelete;
};

}

// The .rdata in front of these, 0x6FADC4-0x6FAF0B, is atlbase.h's AtlLimits<T>::_Min/_Max for int, unsigned int,
// long, unsigned long, __int64 and unsigned __int64, then atlcomcli.h's CVarTypeInfo<T>::VT and ::pmField for each
// variant type ATL maps (each VARTYPE is stored in a 4-byte slot). They are template statics, so they are defined in the
// data include under their addresses.

struct D2PixelFormat006B1B60Strc
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};

extern D2PixelFormat006B1B60Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned long gnFormatCap_006CE28C; // 0x006CE28C

// build: symbol ??_7Thank_you@Define_the_symbol__ATL_MIXED@@6B@ 0x006FAFFC
// 0x006B1A00
Define_the_symbol__ATL_MIXED::Thank_you::Thank_you()
{
}

// 0x006B1A10
void Define_the_symbol__ATL_MIXED::Thank_you::sub_006B1A10_Nop()
{
}

// build: symbol ??0CAtlException@ATL@@QAE@J@Z 0x006B1A20
// build: symbol __TI1?AVCAtlException@ATL@@ 0x007020B4
// 0x006B1A30
void __cdecl ATL::sub_006B1A30_ThrowAtlException(long error)
{
    throw CAtlException(error);
}

// 0x006B1A50
ATL::CRegKey::CRegKey() throw() : m_hKey(0)
{
}

// 0x006B1A60
void* ATL::CRegKey::GetHKEY() const throw()
{
    return m_hKey;
}

// 0x006B1A70
inline long ATL::CRegKey::Close() throw()
{
    long lRes = 0;
    if (m_hKey != 0)
    {
        lRes = RegCloseKey(m_hKey);
        m_hKey = 0;
    }
    return lRes;
}

// 0x006B1A90
long ATL::CRegKey::Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass, unsigned long dwOptions, unsigned long samDesired, void* lpSecAttr, unsigned long* lpdwDisposition) throw()
{
    unsigned long dw;
    void* hKey = 0;
    long lRes = RegCreateKeyExA(hKeyParent, lpszKeyName, 0, lpszClass, dwOptions, samDesired, lpSecAttr, &hKey, &dw);
    if (lpdwDisposition != 0)
        *lpdwDisposition = dw;
    if (lRes == 0)
    {
        lRes = Close();
        m_hKey = hKey;
    }
    return lRes;
}

// 0x006B1B00
long ATL::CRegKey::SetDWORDValue(const char* pszValueName, unsigned long dwValue) throw()
{
    return RegSetValueExA(m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
}

// 0x006B1B20
long ATL::CRegKey::SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType) throw()
{
    if (!pszValue)
        sub_006B1A30_ThrowAtlException(0x80004005);
    return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
}

// 0x006B1B60
int __stdcall sub_006B1B60_EnumTextureFormat(D2PixelFormat006B1B60Strc* pFormat, unsigned long* pFlags)
{
    if (!pFlags)
    {
        return 1;
    }
    if (pFormat->dwFlags != gtWantedFormat_0074C024.dwFlags)
    {
        return 1;
    }
    if (pFormat->dwRGBBitCount != gtWantedFormat_0074C024.dwRGBBitCount)
    {
        return 1;
    }
    if (pFormat->dwRBitMask != gtWantedFormat_0074C024.dwRBitMask)
    {
        return 1;
    }
    if (pFormat->dwGBitMask != gtWantedFormat_0074C024.dwGBitMask)
    {
        return 1;
    }
    if (pFormat->dwBBitMask != gtWantedFormat_0074C024.dwBBitMask)
    {
        return 1;
    }
    if (pFormat->dwRGBAlphaBitMask != gtWantedFormat_0074C024.dwRGBAlphaBitMask)
    {
        return 1;
    }
    *pFlags |= gnFormatCap_006CE28C;
    return 1;
}

#include "gen/data/Source/D2Direct3D/Unknown_006B1A00.inc"
