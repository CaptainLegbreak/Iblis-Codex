#include "D2Hell.h"

struct D2ArchiveHandleStrc;

int __fastcall sub_00516E46_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* pFile); // 0x00516E84
unsigned int __fastcall sub_00516EAB_FileSize(void* unused, void* file, unsigned int* high); // 0x00516EAB
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char* szDst, const char* szSrc);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

static __declspec(noinline) void* __stdcall sub_00517299_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething);
int __stdcall SFileCloseArchive(void* hArchive); // 0x00419A80

// 0x00517079
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine)
{
    void* hFile;
    if (!sub_00516E46_OpenFile(hArchive, szFilePath, &hFile, 0))
    {
        return 0;
    }

    unsigned int dwFileSizeHigh;
    unsigned int dwFileSize = sub_00516EAB_FileSize(hArchive, hFile, &dwFileSizeHigh);
    void* pBuffer = FOG_Alloc(dwFileSize + 800, ".\\SRC\\Archive.cpp", 207, 0);
    if (!pBuffer)
    {
        return 0;
    }

    ARCHIVE_ReadFileToBuffer(hArchive, hFile, pBuffer, dwFileSize);
    sub_00516E84_CloseFile(hArchive, hFile);

    if (pdwBytesWritten)
    {
        *pdwBytesWritten = dwFileSize;
    }

    return pBuffer;
}

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

// 0x005173AC
void __fastcall sub_005173AC_Unload(D2ArchiveHandleStrc* pArchive)
{
    if (pArchive->hArchive)
    {
        SFileCloseArchive(pArchive->hArchive);
    }
    pArchive->hArchive = 0;
    FOG_Free(pArchive, ".\\SRC\\Archive.cpp", 0x25C, 0);
}
