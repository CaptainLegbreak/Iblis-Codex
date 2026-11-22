#include "D2Hell.h"

struct D2ArchiveHandleStrc;

int __fastcall sub_00516E46_OpenFile(void* pUnused, const char* szFileName, void** phFile, int bAllowMissing); // 0x00516E46
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* pFile); // 0x00516E84
unsigned int __fastcall sub_00516EAB_FileSize(void* unused, void* file, unsigned int* high); // 0x00516EAB
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char* szDst, const char* szSrc);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);

static void* __stdcall sub_00517299_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething);
int __stdcall SFileCloseArchive(void* hArchive); // 0x00419A80

int __fastcall sub_004068F0(void* pArg); // 0x004068F0
#define D2_ASSERT(expr,line) if(!(expr)) {sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
int __fastcall sub_00406930(void*,unsigned int*);  // 0x00406930
int __stdcall sub_00416230_GetFileName(void*,char*,unsigned int);
#define FAIL_LINE 0x5F
#define NAME_SIZE 0x104
#define NULL_LINE 0x59
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __fastcall sub_00406940_mpqSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940
// 0x00516E84
void __fastcall sub_00516E84_CloseFile(void* pUnused, void* hFile)
{
    if (!hFile)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 73);
        exit(-1);
    }

    sub_004068F0(hFile);
}

// 0x00516EAB
unsigned int __fastcall sub_00516EAB_FileSize(void* unused,void* file,unsigned int* high) {
 char name[NAME_SIZE];
 D2_ASSERT(file,NULL_LINE);
 unsigned int size=sub_00406930(file,high);
 if(!size) {
  sub_00416230_GetFileName(file,name,NAME_SIZE);
  D2_ASSERT(0,FAIL_LINE);
 }
 return size;
}

// 0x00516F14
int __fastcall sub_00516F14_SetFilePointer(void* unused, void* file, long nOffset, long* pnOffsetHigh, int nMethod)
{
    char name[0x104];
    D2_ASSERT(file, 0x70);
    int nResult = sub_00406940_mpqSetFilePointer(file, nOffset, pnOffsetHigh, nMethod);
    if (nResult != -1)
    {
        return nResult;
    }

    sub_00416230_GetFileName(file, name, 0x104);
    D2_ASSERT(0, 0x79);
}

// 0x00516F85
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead)
{
    D2_ASSERT(hFile, 0x87);

    int dwBytes;
    if (!sub_00406900(hFile, pBuffer, dwBytesToRead, &dwBytes, 0, 0, 0))
    {
        char szArchivePath[0x104];
        sub_00416230_GetFileName(hFile, szArchivePath, sizeof(szArchivePath));
        D2_ASSERT(0, 0x8F);
    }

    D2_ASSERT(dwBytesToRead == dwBytes, 0x92);
}

// 0x00517015
unsigned int __fastcall sub_00517015_ReadFileToSizedBuffer(void* hArchive, const char* szFilePath, void* pBuffer, unsigned int dwBufferSize)
{
    void* hFile;
    sub_00516E46_OpenFile(hArchive, szFilePath, &hFile, 0);
    D2_ASSERT(dwBufferSize >= sub_00516EAB_FileSize(hArchive, hFile, 0), 0xA5);
    ARCHIVE_ReadFileToBuffer(hArchive, hFile, pBuffer, dwBufferSize);
    sub_00516E84_CloseFile(hArchive, hFile);
    return dwBufferSize;
}

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
 SStrPack(path,"\\",0x7FFFFFFF);
 SStrPack(path,filename,0x7FFFFFFF);
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
   SStrPack(path,filename,0x7FFFFFFF);
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
    SStrPack(szOutPath, szFileName, 0x7FFFFFFF);
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
