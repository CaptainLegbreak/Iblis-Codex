void __fastcall sub_00517804_GetText(unsigned int, char*, unsigned int); // 0x00517804
void __cdecl sub_005173DF_TerminateCurrentProcess(); // 0x005173DF
extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char*, const char*, char*); // 0x006CC4AC
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int); // 0x006CC464
extern const char* gszCaption_006CC848; // 0x006CC848
extern "C" unsigned int __security_cookie; // 0x00749DE0
void __fastcall __security_check_cookie(unsigned int); // 0x00681A48
// 0x00517874
int __cdecl sub_00517874_ShowError(unsigned int message, ...)
{
 char format[512];
 char text[512];
 sub_00517804_GetText(message, format, sizeof(format));
 wvsprintfA(text, format, (char*)(&message+1));
 int result;
 if(MessageBoxA(0,text,gszCaption_006CC848,0x2215)==4) result=1;
 else {sub_005173DF_TerminateCurrentProcess();result=0;}
 return result;
}
