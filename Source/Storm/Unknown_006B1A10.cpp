#include "Storm.h"

class CRegKey;
struct CRegKeyView;
struct CRegKey006B1B00Strc;
struct CRegKey006B1B20Strc;
struct D2PixelFormat006B1B60Strc;

class CRegKey
{
public:
    void* m_hKey;
    CRegKey();
};

struct CRegKeyView
{
    void* m_hKey;
};

struct CRegKey006B1B00Strc
{
    void* m_hKey;
};

struct CRegKey006B1B20Strc
{
    void* m_hKey;
};

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

// 0x006B1A10
void __cdecl sub_006B1A10_Nop()
{
}

// 0x006B1A50
CRegKey::CRegKey() : m_hKey(0)
{
}

// 0x006B1A60
void* __fastcall sub_006B1A60_CRegKey_GetHKEY(const CRegKeyView* pKey)
{
    return pKey->m_hKey;
}

// 0x006B1B00
long __fastcall sub_006B1B00_RegKeySetDWORDValue(CRegKey006B1B00Strc* pKey, int nUnused, const char* pszValueName, unsigned long dwValue)
{
    return RegSetValueExA(pKey->m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
}

// 0x006B1B20
long __fastcall sub_006B1B20_RegKeySetStringValue(CRegKey006B1B20Strc* pKey, int nUnused, const char* pszValueName, const char* pszValue, unsigned long dwType)
{
    if (!pszValue)
        sub_006B1A30_ThrowAtlException(0x80004005);
    return RegSetValueExA(pKey->m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
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

#include "gen/data/Source/Storm/Unknown_006B1A10.inc"
