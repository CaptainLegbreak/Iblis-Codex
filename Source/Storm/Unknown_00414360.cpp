#include "Storm.h"

struct D2StormQuadStrc;
extern "C" int gnBufferBase_007D5448;
extern "C" int gnSoundFlag_007C545C;
// build: symbol _gnSoundSerial 0x007C5460
extern "C" int gnSoundSerial;
// build: symbol _gnSubsystemActive 0x007A0458
extern "C" int gnSubsystemActive;
void __cdecl sub_004142A0_InitPowTable(); // 0x004142A0
extern "C" void __cdecl CMNSUBTILE_BuildGouraudCache(); // 0x004F7CC0
extern "C" void __cdecl sub_004E4280(); // 0x004E4280
int __stdcall GAME_Shutdown(); // 0x0052C030
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010
extern "C" __declspec(dllimport) long __stdcall RegDeleteValueA(void* hKey, const char* szValueName); // 0x006CC018
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode); // 0x006CC2E4
int __stdcall SRegGetBaseKey(unsigned int nFlags, char* szDest, unsigned int nMaxLength); // 0x00414930
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
extern "C" const char gszFmtUnsigned_006CEF68[]; // 0x006CEF68
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004
extern "C" __declspec(dllimport) long __stdcall RegFlushKey(void* hKey); // 0x006CC008
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
extern "C" const char gszEmptyString_006CC837; // 0x006CC837
int __fastcall InternalDeleteEntry(unsigned int nFlags, const char* szKeyName, const char* szValueName);

struct D2StormQuadStrc {
 int n00,n04,n08,n0C;
 D2StormQuadStrc& __thiscall sub_00415160_Copy(const D2StormQuadStrc& source);
};

// 0x00414360
extern "C" void __cdecl sub_00414360_CallThenSetFlag()
{
    sub_004142A0_InitPowTable();
    gnFlag_007788DC = 1;
}

extern "C" void __cdecl sub_004F8DC0_InitLookupTable(); // 0x004F8DC0

extern "C" void __cdecl sub_004B9D00_ResetSoundState(); // 0x004B9D00

extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80



#include "gen/data/Source/Storm/Unknown_00414360.inc"






// 0x00415160
D2StormQuadStrc& __thiscall D2StormQuadStrc::sub_00415160_Copy(const D2StormQuadStrc& source) {
 n00=source.n00;
 n04=source.n04;
 n08=source.n08;
 n0C=source.n0C;
 return *this;
}
