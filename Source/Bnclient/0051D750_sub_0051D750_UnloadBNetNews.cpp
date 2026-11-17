struct D2Storm408ElemStrc;

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650

extern "C" const char gszNewsItemTypeName_0072FF8C[];                                                       // 0x0072FF8C
int gbNewsActive_00881C24;                                                                                  // 0x00881C24
extern int (__fastcall* gpfnNewsMessage_00881C28)(unsigned int nStamp, const char* szText);                // 0x00881C28
int (__cdecl* gpfnNewsRefresh_00881C2C)();                                                                  // 0x00881C2C
extern D2StormArray408Strc gtNewsItems_00881C30;                                                            // 0x00881C30

// 0x0051D750
int __cdecl sub_0051D750_UnloadBNetNews()
{
    gpfnNewsMessage_00881C28 = 0;
    gpfnNewsRefresh_00881C2C = 0;
    if (gtNewsItems_00881C30.f_8)
        SMemFree(gtNewsItems_00881C30.f_8, gszNewsItemTypeName_0072FF8C, -2, 0);
    gtNewsItems_00881C30.f_0 = 0;
    gtNewsItems_00881C30.f_4 = 0;
    gtNewsItems_00881C30.f_8 = 0;
    gbNewsActive_00881C24 = 0;
    return 1;
}
