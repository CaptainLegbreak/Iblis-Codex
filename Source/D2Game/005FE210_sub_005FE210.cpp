typedef char* va_list;
extern "C" int __cdecl vsprintf(char*,const char*,va_list);
extern "C" char* __cdecl strcat(char*,const char*);
struct Config { int enabled; const char* compressed; const char* standard; };
extern Config extensions;  // 0x00741EFC
enum { DISABLED = 0 };
// 0x005FE210
void __stdcall sub_005FE210(char* output,int allowCompressed,const char* format,va_list args)
{
    vsprintf(output,format,args);
    const char* suffix=(allowCompressed!=DISABLED && extensions.enabled!=DISABLED)?extensions.compressed:extensions.standard;
    strcat(output,suffix);
}
