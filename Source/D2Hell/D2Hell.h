#pragma once


char* __stdcall SStrChr(const char*,char); // 0x00413490
extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(const char*,char*,unsigned long,unsigned long*,unsigned long*,unsigned long*,char*,unsigned long); // 0x006CC2E8
extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(const char*); // 0x006CC2EC
extern "C" __declspec(dllimport) unsigned long __stdcall GetLogicalDriveStringsA(unsigned long,char*); // 0x006CC378
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void*,char*,unsigned long); // 0x006CC1BC
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0
int __stdcall SFileOpenArchive(const char*,int,unsigned int,void**); // 0x0041BA60
unsigned int __stdcall SStrCopy(char*,const char*,unsigned int); // 0x004135D0
unsigned int __stdcall sub_00413800(char*,const char*,unsigned int); // 0x00413800

typedef int (__stdcall* ARCHIVE_ShowMessageFunctionPtr)();

struct D2ArchiveHandleStrc
{
    void* hArchive;
    char szPath[260];
};
