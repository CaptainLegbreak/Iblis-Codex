extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int); // 0x006CC464
extern const char* gpCaption_006CC848; // 0x006CC848
void __cdecl sub_005173DF_Terminate();

// 0x005173EF
int __fastcall sub_005173EF_FatalBox(const char* text) {
 MessageBoxA(0,text,gpCaption_006CC848,0x2010);
 sub_005173DF_Terminate();
 return 0;
}

// 0x0051740B
int __fastcall sub_0051740B_ErrorBox(const char* text) {
 MessageBoxA(0,text,gpCaption_006CC848,0x2010);
 return 1;
}
