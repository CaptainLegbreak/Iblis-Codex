#pragma once

struct D2LangCharMapEntryStrc;
struct D2StringTableStrc;
struct Unicode;

const Unicode* __fastcall sub_00524930(D2StringTableStrc* pTable, void* pIndex, unsigned short nIndex); // 0x00524930
extern "C" char* __cdecl _ultoa(unsigned long nValue, char* szOut, int nRadix); // 0x00687652
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char szStar_006D5830[]; // 0x006D5830
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern D2LangCharMapEntryStrc* gpCharMap_00882B24; // 0x00882B24
extern unsigned short gwToUpperTable_00730578[0x100]; // 0x00730578
int __cdecl sub_00525150(); // 0x00525150
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __fastcall sub_00517079(void* hArchive, const char* szPath, int* pSize, const char* szFile, int nLine); // 0x00517079
