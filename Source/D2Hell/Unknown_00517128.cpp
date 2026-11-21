#include "D2Hell.h"

struct D2ArchiveHandleStrc;
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char* szDst, const char* szSrc);
extern "C" void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B380
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

static void* __stdcall sub_00517299_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething);

// 0x00517128
static int __stdcall sub_00517128_FindArchive(const char* filename,int priority,void** outHandle,char* path)
{
 char drives[260];
 GetModuleFileNameA(0,path,260);
 path[259]=0;
 char* end=path;
 while(*end && SStrChr(end+1,'\\')) end=SStrChr(end+1,'\\');
 *end=0;
 sub_00413800(path,"\\",0x7FFFFFFF);
 sub_00413800(path,filename,0x7FFFFFFF);
 if(SFileOpenArchive(path,priority,2,outHandle)) return 1;
 unsigned long length=GetLogicalDriveStringsA(260,drives);
 if(!length || length>260) return 0;
 while(*filename=='\\') ++filename;
 char* current=drives;
 while(*current) {
  char* root=current;
  while(*current++) {}
  if(GetDriveTypeA(root)==5 && GetVolumeInformationA(root,0,0,0,0,0,0,0)) {
   SStrCopy(path,root,0x7FFFFFFF);
   sub_00413800(path,filename,0x7FFFFFFF);
   if(SFileOpenArchive(path,priority,2,outHandle)) return 1;
  }
 }
 return 0;
}

int __cdecl EmitFindArchive(const char* filename,int priority,void** outHandle,char* path)
{
 return sub_00517128_FindArchive(filename,priority,outHandle,path);
}

// 0x00517299
static void* __stdcall sub_00517299_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething)
{
    unsigned int nFlags = 2;
    if (bSomething)
    {
        nFlags = 3;
    }
    void* hArchive;
    SStrCopy(szOutPath, szFileName, 0x7FFFFFFF);
    if (SFileOpenArchive(szOutPath, nPriority, nFlags, &hArchive))
    {
        return hArchive;
    }
    if (!GetModuleFileNameA(0, szOutPath, 260))
    {
        *szOutPath = 0;
    }
    char* pLastBackslash = strrchr(szOutPath, '\\');
    if (pLastBackslash)
    {
        pLastBackslash[1] = 0;
    }
    sub_00413800(szOutPath, szFileName, 0x7FFFFFFF);
    if (SFileOpenArchive(szOutPath, nPriority, nFlags, &hArchive))
    {
        return hArchive;
    }
    if (sub_00517128_FindArchive(szFileName, nPriority, &hArchive, szOutPath))
    {
        return hArchive;
    }
    return 0;
}

// 0x00517332
D2ArchiveHandleStrc* __fastcall ARCHIVE_LoadMPQFile(const char* szName, const char* szModule, ARCHIVE_ShowMessageFunctionPtr pfShowMessage, int nPriority)
{
    D2ArchiveHandleStrc* pMpqHandle = (D2ArchiveHandleStrc*)FOG_Alloc(sizeof(D2ArchiveHandleStrc), ".\\SRC\\Archive.cpp", 0x20A, 0);
    pMpqHandle->hArchive = 0;
    do
    {
        pMpqHandle->hArchive = sub_00517299_FindAndOpenArchive(pMpqHandle->szPath, szName, nPriority, (int)szModule);
        if (!pMpqHandle->hArchive)
        {
            if (!pfShowMessage || !pfShowMessage())
            {
                FOG_Free(pMpqHandle, ".\\SRC\\Archive.cpp", 0x21A, 0);
                return 0;
            }
            Sleep(100);
        }
    }
    while (!pMpqHandle->hArchive);
    return pMpqHandle;
}
