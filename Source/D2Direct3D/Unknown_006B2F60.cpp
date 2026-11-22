#include "D2Direct3D.h"

struct D2Object006BB3E0Strc;
struct D2Object006BADC0Strc;
struct D2DDrawDeviceStrc;
class CRegKeyInline;
struct D2Cache006BA830Strc;
struct D2DDCaps006B3420Strc;
struct D2DDSurfaceDesc006B3420Strc;
struct D2ComObject006B3420Strc;

struct D2DDrawDeviceStrc
{
    unsigned int dwFlags;
    unsigned char guid[0x10];
    char unk0x014[0x08];
    char szName[0x104];
};

extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030
extern D2DDrawDeviceStrc gaDDrawDevices_0096F4E0[]; // 0x0096F4E0

class CRegKeyInline
{
public:
    void* m_hKey;

    CRegKeyInline() : m_hKey(0) {}
    ~CRegKeyInline() { Close(); }

    long Close()
    {
        long lRes = 0;
        if (m_hKey != 0)
        {
            lRes = RegCloseKey(m_hKey);
            m_hKey = 0;
        }
        return lRes;
    }

    long Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass = 0, unsigned long dwOptions = 0,
        unsigned long samDesired = 0x20006, void* lpSecAttr = 0, unsigned long* lpdwDisposition = 0)
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

    long SetDWORDValue(const char* pszValueName, unsigned long dwValue)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
    }

    long SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType = 1)
    {
        if (!pszValue)
            sub_006B1A30_ThrowAtlException(0x80004005);
        return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
    }

    long SetBinaryValue(const char* pszValueName, const void* pValue, unsigned long nBytes)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 3, (const unsigned char*)pValue, nBytes);
    }
};

struct D2Cache006BA830Strc
{
    int unk0x00[7];
};

void __cdecl D3D_ReleaseSprites(); // 0x006B5B10
void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250
void __cdecl D3D_ReleaseSmackSurfaces(); // 0x006B9B30
void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830
void __fastcall sub_006BADC0_Free(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0
void __fastcall sub_006BB3E0_Free(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0
extern int gdwGlobal_00970E8C; // 0x00970E8C
extern D2Object006BADC0Strc gObject_0096FC80; // 0x0096FC80
extern D2Object006BB3E0Strc gObject_0096FC9C; // 0x0096FC9C
extern D2Cache006BA830Strc gCache_00970EC8; // 0x00970EC8
extern D2Cache006BA830Strc gCache_00970EE4; // 0x00970EE4
extern D2Cache006BA830Strc gCache_00970F00; // 0x00970F00
void __cdecl D3D_ReleaseResources(); // 0x006B3320
extern void* ghDDrawWindow_007C9140; // 0x007C9140

struct D2DDCaps006B3420Strc
{
    unsigned int dwCaps;
    unsigned int dwCaps2;
    unsigned int dwCaps3;
    unsigned int dwCaps4;
};

struct D2DDSurfaceDesc006B3420Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int aUnk0x08[24];
    D2DDCaps006B3420Strc tCaps;
    unsigned int dwTextureStage;
};

struct D2ComObject006B3420Strc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2DDSurfaceDesc006B3420Strc* pDesc, D2ComObject006B3420Strc** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0
extern int gbVideoUp_00970E40; // 0x00970E40
extern int gnVideoState_00970E44; // 0x00970E44
extern D2ComObject006B3420Strc* gpDirectDraw_00970E60; // 0x00970E60
extern D2ComObject006B3420Strc* gpPrimary_00970E68; // 0x00970E68
extern const unsigned int gdwBitMask7_006CE284; // 0x006CE284
extern const unsigned int gdwBitMask8_006CE288; // 0x006CE288
extern int gnScreenHeight_007C913C; // 0x007C913C

// 0x006B2F60
void __fastcall sub_006B2F60_SaveVideoConfig(int nRender, int nDevice)
{
    int aDeviceName[0x104 / 4];
    int aFlags[0x104 / 4];
    int aGuid[0x104 / 4];
    sprintf((char*)aDeviceName, "DeviceName");
    sprintf((char*)aFlags, "dwFlags");
    sprintf((char*)aGuid, "GUID");

    CRegKeyInline tKey;
    if (tKey.Create((void*)0x80000001, "SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig") == 0)
    {
        tKey.SetDWORDValue("Render", nRender);
        tKey.SetStringValue((const char*)aDeviceName, gaDDrawDevices_0096F4E0[nDevice].szName);
        tKey.SetDWORDValue((const char*)aFlags, gaDDrawDevices_0096F4E0[nDevice].dwFlags);
        tKey.SetBinaryValue((const char*)aGuid, gaDDrawDevices_0096F4E0[nDevice].guid, 0x10);
    }
}

// 0x006B32B0
void __cdecl sub_006B32B0_ReleaseRenderer()
{
    if (gdwGlobal_00970E8C)
    {
        sub_006B7250_ReleaseAll();
        sub_006BB3E0_Free(&gObject_0096FC9C, 1);
        sub_006BADC0_Free(&gObject_0096FC80, 1);
    }
    else
    {
        D3D_ReleaseSmackSurfaces();
    }

    sub_006BA830_FreeCache(&gCache_00970EC8, 1);
    sub_006BA830_FreeCache(&gCache_00970EE4, 1);
    sub_006BA830_FreeCache(&gCache_00970F00, 1);
    D3D_ReleaseSprites();
}

// 0x006B3400
int __cdecl sub_006B3400_ReleaseWindow()
{
    D3D_ReleaseResources();
    ghDDrawWindow_007C9140 = 0;
    return 1;
}


#include "gen/data/Source/D2Direct3D/Unknown_006B2F60.inc"
