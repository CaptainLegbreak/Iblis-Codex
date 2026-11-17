struct T004013C0 { int unk00; int mode; };
T004013C0* __cdecl sub_00407360_GetSystemInfo(); // 0x00407360
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern const char gszEmpty_006CC837[]; // 0x006CC837
int __stdcall sub_006B4C90_ShowVideoConfiguration(void*); // 0x006B4C90
int __stdcall SRegLoadString(const char*,const char*,unsigned int,char*,unsigned int); // 0x00414E50
int __stdcall SRegLoadValue(const char*,const char*,unsigned int,unsigned long*); // 0x00414F10
int __stdcall SRegLoadData(const char*,const char*,unsigned int,void*,unsigned int,unsigned int*); // 0x00414DE0
#pragma pack(push,1)
struct D2VideoKeyStrc { unsigned int words[5]; unsigned short tail; };
#pragma pack(pop)
extern const D2VideoKeyStrc gVideoKey_006DD634; // 0x006DD634
int gbConfigured_00970EB8;        // 0x00970EB8
int gbSeen_00970EBC;        // 0x00970EBC
char gszDevice_0096F3BC[264];     // 0x0096F3BC
unsigned long gnFlags_0096F3A8;        // 0x0096F3A8
unsigned int gGuid_0096F3AC[4];        // 0x0096F3AC
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
// 0x006B4E80
int __fastcall sub_006B4E80_LoadVideoConfiguration(void* window) {
    T004013C0* info=sub_00407360_GetSystemInfo();
    if (!info) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),1032); exit(-1); }
    if (info->mode==1) return 0;
    D2VideoKeyStrc key=gVideoKey_006DD634;
    if (gbSeen_00970EBC && !gbConfigured_00970EB8) {
        sub_006B4C90_ShowVideoConfiguration(window);
        gbConfigured_00970EB8=1;
    }
    gbSeen_00970EBC=1;
    for (;;) {
        if (!SRegLoadString((const char*)&key,"DeviceName",0,gszDevice_0096F3BC,256)) {
            if (gbConfigured_00970EB8) return 0;
            int result=sub_006B4C90_ShowVideoConfiguration(window);
            gbConfigured_00970EB8=1;
            if (result!=2) return 0;
        } else if (!SRegLoadValue((const char*)&key,"dwFlags",0,&gnFlags_0096F3A8)) {
            if (gbConfigured_00970EB8) return 0;
            int result=sub_006B4C90_ShowVideoConfiguration(window);
            gbConfigured_00970EB8=1;
            if (result!=2) return 0;
        } else break;
    }
    if (!(gnFlags_0096F3A8 & gdwBitMasks_006CE268[0])) {
        unsigned int length=16;
        if (!SRegLoadData((const char*)&key,"GUID",0,gGuid_0096F3AC,16,&length) || length!=16) return 0;
    }
    return 1;
}
