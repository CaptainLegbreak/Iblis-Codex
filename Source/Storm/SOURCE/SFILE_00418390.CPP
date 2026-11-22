#include "Storm.h"
#include "D2GameTypes.h"

struct D2StormBlockStrc;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);
void __cdecl sub_00415B90_InitCryptTable();
int __fastcall sub_00417F10_FindFile(void* hArchive, D2StormBlockStrc** ppBlock, const char* szName, unsigned int nFlags, ARCHIVEREC** ppArchive, char* szFoundPath);
extern D2CriticalSectionStrc gBasePathLock_00779068;                                                        // 0x00779068

// 0x00418390
int __stdcall SFileFileExistsEx(void* hArchive, const char* szFileName, int nFlags)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATEEND;
    EnterCriticalSection(&gBasePathLock_00779068);
    sub_00415B90_InitCryptTable();
    int nResult = sub_00417F10_FindFile(hArchive, 0, szFileName, nFlags, 0, 0);
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}
