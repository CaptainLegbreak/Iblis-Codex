#pragma once

struct D2CmpPoolStrc;
struct D2TileLibraryHashStrc;
struct T00481720;

D2TileLibraryHashStrc* __cdecl sub_0060CDB0_AllocTileHash(); // 0x0060CDB0
T00481720* __fastcall sub_0040A620(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* lpCriticalSection); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszNewline_006FFCB0[]; // 0x006FFCB0
extern "C" const char gszSpriteCacheSourceFile[]; // 0x006E364C
extern "C" const char gszTypeNameCelList[]; // 0x00741F2C
extern "C" const char gszTypeNameCelSlotList[]; // 0x00741F44
extern "C" const char szFastCmpFile[]; // 0x006E5F08
extern "C" const char szSubTileFile[]; // 0x006E61F8
extern "C" const char szTileCodecFile[]; // 0x006E61F8
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" double __cdecl sqrt(double x); // 0x006879C0
extern const char gszSubTileFile_006E61F8[]; // 0x006E61F8
extern int gaDirectionIndex64_006E45A0[][64]; // 0x006E45A0
extern int gbCmpCompressedDataMode; // 0x00741EFC
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall sub_0040A7F0_AsyncDataCheck(T00481720* pAsyncData); // 0x0040A7F0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile); // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall sub_00609020_PoolInit(D2CmpPoolStrc* pPool, void* pMemPool, int nArg, void (__fastcall* pfnFree)(void*), int nBlocks); // 0x00609020
void __fastcall sub_006092D0_PoolFree(D2CmpPoolStrc* pPool, void* pMemory); // 0x006092D0
void __fastcall sub_006093E0_PoolFreeAll(D2CmpPoolStrc* pPool); // 0x006093E0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall sub_0060D430_Compress(const void* pSrc, int* pLength); // 0x0060D430
