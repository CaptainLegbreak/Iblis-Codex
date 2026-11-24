#include "D2Hell.h"
#include "D2Win32System.h"
#include "D2Win32StartupInfo.h"



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall CreateProcessA(const char* szApplicationName, char* szCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const char* szCurrentDirectory, D2StartupInfoAStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC33C
// 0x00516D8B
bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath) {
 D2ProcessInformationStrc process;
 D2StartupInfoAStrc startup;
 startup.cb=sizeof(startup);
 memset((char*)&startup+4,0,sizeof(startup)-4);
 if(!CreateProcessA(szExePath,0,0,0,0,0,0,0,&startup,&process)) return false;
 CloseHandle(process.hProcess);
 CloseHandle(process.hThread);
 return true;
}
