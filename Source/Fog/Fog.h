#pragma once

struct D2Connection006C03A0Strc;
struct D2FileTimeStrc;
struct D2MemoryBasicInfoStrc;
struct D2ModuleInfoStrc;
struct D2PoolSystemStrc;
struct D2QClientStrc;
struct D2Server006C03A0Strc;
struct D2SockAddrInStrc;
struct D2SystemTimeStrc;
struct D2ThreadContextStrc;
struct T006BE350;
struct T006BFAD0;
struct _iobuf;

D2ModuleInfoStrc* __stdcall sub_0040B920_GetModuleListPsapi(void* hProcess); // 0x0040B920
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" __declspec(dllimport) int __stdcall DuplicateHandle(void* hSourceProcess, void* hSource, void* hTargetProcess, void** phTarget, unsigned long dwAccess, int bInherit, unsigned long dwOptions); // 0x006CC248
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentDirectoryA(unsigned long nSize, char* szBuffer); // 0x006CC240
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId(); // 0x006CC1EC
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C
extern "C" __declspec(dllimport) unsigned long __stdcall GetEnvironmentVariableA(const char* szName, char* szBuffer, unsigned long nSize); // 0x006CC23C
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread(); // 0x006CC24C
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" const char gszExceptionsCppFile_006CD628[]; // 0x006CD628
extern "C" const char gszMiniDumpWriteDump_006FFB94[]; // 0x006FFB94
extern "C" const char gszNewline_006FFCB0[]; // 0x006FFCB0
extern "C" const char gszQServerFile_006FC460[]; // 0x006FC460
extern "C" const char gszQServerNTFile_006FC8A0[]; // 0x006FC8A0
extern "C" const char gszSpace_006FFC44[]; // 0x006FFC44
extern "C" const char gszStringFormat_006FFC58[]; // 0x006FFC58
extern "C" const char gszUnknown_006CD5FC[]; // 0x006CD5FC
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" const unsigned char gaASTOperatorPrecedence_006FC874[]; // 0x006FC874
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" int __cdecl fprintf(_iobuf* pFile, const char* szFormat, ...); // 0x00684C94
extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin); // 0x00684A2A
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __stdcall connect(unsigned int nSocket, const D2SockAddrInStrc* pName, int nNameLength); // 0x006B014A
extern "C" int __stdcall getsockname(unsigned int nSocket, D2SockAddrInStrc* pName, int* pnNameLength); // 0x006B0144
extern "C" long __cdecl ftell(_iobuf* pFile); // 0x00684935
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" unsigned int __stdcall accept(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen); // 0x006C9B6A
extern "C" unsigned long __stdcall inet_addr(const char* szAddress); // 0x006B0150
extern "C" void __cdecl free(void* pMemory); // 0x00683FC0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
extern "C" void* __stdcall CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long dwProcessId); // 0x006B1446
extern _iobuf* gapLogFiles_0075E790[20]; // 0x0075E790
extern char gaszLogNames_0075D148[20][0x10]; // 0x0075D148
extern char gszLogPrefix_00708018[]; // 0x00708018
extern const char gszQServerNT_006FC8A0[]; // 0x006FC8A0
extern const char gszServerFile_006FC460[]; // 0x006FC460
extern const char* gaszErrorTypeNames_00706654[]; // 0x00706654
extern int gbLogThreadStop_0075E830; // 0x0075E830
extern int gdwGlobal_0074F0C8; // 0x0074F0C8
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern unsigned long gadwLogWriteTick_0075D2F0[20]; // 0x0075D2F0
extern void* ghDbgHelpDoneEvent_0098A6BC; // 0x0098A6BC
extern void* ghDbgHelpWorkEvent_0098A6C0; // 0x0098A6C0
int __fastcall FOG_SOCKET_WSACleanup(); // 0x0040D8D0
int __fastcall sub_006BFFA0_CheckReconnects(T006BE350* pServer, unsigned int* pAddress); // 0x006BFFA0
int __fastcall sub_006C2C70_Queue(D2Server006C03A0Strc* pServer, D2Connection006C03A0Strc* pConnection, int a, int b); // 0x006C2C70
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590
int __stdcall sub_006B0144_GetSockAddr(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen); // 0x006B0144
int __stdcall sub_006B018C_GetSockAddr(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen); // 0x006B018C
unsigned int __cdecl sub_00410A80_GetTime(); // 0x00410A80
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
unsigned short __stdcall sub_006B019E(unsigned short nValue); // 0x006B019E
void __cdecl sub_00409020_LogPoolError(const char* szFormat, ...); // 0x00409020
void __cdecl sub_00409DD0_InitPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize); // 0x00409DD0
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...); // 0x00410740
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall sub_00408660_ShowErrorReport(const char* szText, const char* szMessage, int nArg3, int nArg4, int nLine, int nArg6); // 0x00408660
void __fastcall sub_00409810_FreeLarge(D2PoolSystemStrc* pSystem, void* pMemory, const char* szFile, int nLine); // 0x00409810
void __fastcall sub_006C0360_Release(T006BE350* pServer, D2QClientStrc* pClient); // 0x006C0360
void __fastcall sub_006C0360_RemoveClient(T006BE350*, T006BFAD0*); // 0x006C0360
void __fastcall sub_006C0420_CloseRemote(T006BE350*, int token, const char* file, int line); // 0x006C0420
void __fastcall sub_006C0420_Disconnect(T006BE350* pServer, unsigned int nId, const char* szFile, int nLine); // 0x006C0420
void __fastcall sub_006C08A0_Dispatch(T006BE350* pServer, D2QClientStrc* pClient); // 0x006C08A0
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void* __fastcall sub_004098B0_ReallocLarge(D2PoolSystemStrc* pSystem, void* pMemory, int nSize, const char* szFile, int nLine); // 0x004098B0
