#pragma once

struct D2CriticalSectionStrc;
struct D2FileTimeStrc;
struct D2LangByteRangeStrc;
struct D2SrpSha1ContextStrc;
struct Unicode;

Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" int __cdecl rand(); // 0x00687461
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454
extern "C" void* __cdecl bsearch(const void* pKey, const void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x006881B1
extern D2LangByteRangeStrc* gpLeadByteRanges_00882B28; // 0x00882B28
extern unsigned short* gpCharMapIndex_00882B2C; // 0x00882B2C
int __cdecl sub_0051BCF0_SendBuffer(); // 0x0051BCF0
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight); // 0x00527AE0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
int __fastcall sub_0051E370_SetText(const char* szText, int nLength); // 0x0051E370
int __fastcall sub_0051F910_Report(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2); // 0x0051F910
int __fastcall sub_00520520_SetState(int nState); // 0x00520520
int __fastcall sub_00520550_SetStateArg(void* pArg); // 0x00520550
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __fastcall sub_0052A600(void* pArg); // 0x0052A600
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned int nSize); // 0x00415000
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
void __fastcall sub_00529F50_Sha1Init(D2SrpSha1ContextStrc* pContext); // 0x00529F50
void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext); // 0x0052A040
