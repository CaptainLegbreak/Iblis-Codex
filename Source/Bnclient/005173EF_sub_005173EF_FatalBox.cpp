extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int);  // 0x006CC464
extern const char* gpCaption_006CC848;  // 0x006CC848
void __cdecl sub_005173DF_Terminate();
// 0x005173EF
int __fastcall sub_005173EF_FatalBox(const char* text) {
#ifdef MOVED_TEST
 MessageBoxA(0,text,gpCaption_006CC848,0x2014);
#else
 MessageBoxA(0,text,gpCaption_006CC848,0x2010);
#endif
 sub_005173DF_Terminate();
 return 0;
}
