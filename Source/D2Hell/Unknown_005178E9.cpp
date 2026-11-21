extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char*,const char*,char*);  // 0x006CC4AC
void __fastcall sub_00517804_GetMessage(unsigned int,char*,unsigned int);
void __fastcall sub_005173EF_Display(const char*);
#define BUFFER_SIZE 512
// 0x005178E9
void __cdecl sub_005178E9_Format(unsigned int id,...) {
 char formatted[BUFFER_SIZE];
 char format[BUFFER_SIZE];
 sub_00517804_GetMessage(id,format,BUFFER_SIZE);
 wvsprintfA(formatted,format,(char*)(&id+1));
 sub_005173EF_Display(formatted);
}
