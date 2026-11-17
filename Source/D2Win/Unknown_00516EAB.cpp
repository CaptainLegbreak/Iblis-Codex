extern "C" const char gszEmptyAssertText;  // 0x006CC837
extern "C" const char* __cdecl sub_00408090();  // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
int __fastcall sub_00406930(void*,unsigned int*);  // 0x00406930
int __stdcall sub_00416230_GetFileName(void*,char*,unsigned int);
#ifdef MOVED_TEST
#define NAME_SIZE 0x108
#define NULL_LINE 0x5D
#define FAIL_LINE 0x63
#else
#define NAME_SIZE 0x104
#define NULL_LINE 0x59
#define FAIL_LINE 0x5F
#endif
#define D2_ASSERT(expr,line) if(!(expr)) {sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
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
