extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void*,char*,unsigned long); // 0x006CC1BC
extern "C" __declspec(dllimport) unsigned long __stdcall GetLogicalDriveStringsA(unsigned long,char*); // 0x006CC378
extern "C" __declspec(dllimport) unsigned int __stdcall GetDriveTypeA(const char*); // 0x006CC2EC
extern "C" __declspec(dllimport) int __stdcall GetVolumeInformationA(const char*,char*,unsigned long,unsigned long*,unsigned long*,unsigned long*,char*,unsigned long); // 0x006CC2E8
char* __stdcall SStrChr(const char*,char); // 0x00413490
unsigned int __stdcall SStrCopy(char*,const char*,unsigned int); // 0x004135D0
unsigned int __stdcall sub_00413800(char*,const char*,unsigned int); // 0x00413800
int __stdcall SFileOpenArchive(const char*,int,unsigned int,void**); // 0x0041BA60
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
