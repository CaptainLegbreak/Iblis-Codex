extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int);  // 0x006CC464
extern const char* gpCaption_006CC848;  // 0x006CC848
// 0x0051740B
int __fastcall sub_0051740B_ErrorBox(const char* text) {
#ifdef MOVED_TEST
 MessageBoxA(0,text,gpCaption_006CC848,0x2014);
#else
 MessageBoxA(0,text,gpCaption_006CC848,0x2010);
#endif
 return 1;
}
