extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void*,char*,unsigned long); // 0x006CC1BC
extern "C" __declspec(dllimport) unsigned long __stdcall GetLogicalDriveStringsA(unsigned long,char*); // 0x006CC378
extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(const char*); // 0x006CC2EC
extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(const char*,char*,unsigned long,unsigned long*,unsigned long*,unsigned long*,char*,unsigned long); // 0x006CC2E8
char* __stdcall SStrChr(const char*,char); // 0x00413490
unsigned int __stdcall SStrCopy(char*,const char*,unsigned int); // 0x004135D0
unsigned int __stdcall sub_00413800(char*,const char*,unsigned int); // 0x00413800
int __stdcall SFileOpenArchive(const char*,int,unsigned int,void**); // 0x0041BA60
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char* szDst, const char* szSrc);
extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990
extern "C" void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x0040B380
extern "C" void __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x0040B3C0
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char* szDst, const char* szSrc);

struct D2ArchiveHandleStrc
{
    void* hArchive;
    char szPath[260];
};

typedef int (__stdcall* ARCHIVE_ShowMessageFunctionPtr)();

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

static __declspec(noinline) void* __stdcall sub_00517299_FindAndOpenArchive(char* szOutPath, const char* szFileName, int nPriority, int bSomething);

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
