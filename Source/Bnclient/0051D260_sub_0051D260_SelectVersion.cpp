extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2Storm408ElemStrc
{
    int unk0x00;
    unsigned int nStamp;
    char szText[0x400];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;
};

extern const char* gpszNewsName_0072FF80;                                                                   // 0x0072FF80
extern int gbNewsActive_00881C24;                                                                           // 0x00881C24
int (__fastcall* gpfnNewsMessage_00881C28)(unsigned int nStamp, const char* szText);                       // 0x00881C28
extern int (__cdecl* gpfnNewsRefresh_00881C2C)();                                                           // 0x00881C2C
extern D2StormArray408Strc gtNewsItems_00881C30;                                                            // 0x00881C30
extern unsigned int gnNewsFirstIndex_00881C40;                                                              // 0x00881C40

// 0x0051D260
void __fastcall sub_0051D260_SelectVersion(int bAlternate)
{
    D2_ASSERT(!gbNewsActive_00881C24, 0x2F);
    gpszNewsName_0072FF80 = "BNNews-D2DV";
    if (!bAlternate)
        gpszNewsName_0072FF80 = "BNNews-D2XP";
}

// 0x0051D510
void __cdecl sub_0051D510_ReportNews()
{
    if (gpfnNewsRefresh_00881C2C)
        gpfnNewsRefresh_00881C2C();
    if (!gpfnNewsMessage_00881C28)
        return;
    unsigned int nIndex = gtNewsItems_00881C30.f_4;
    const int nCount = nIndex - gnNewsFirstIndex_00881C40;
    for (int i = 0; i < nCount; ++i)
    {
        gpfnNewsMessage_00881C28(gtNewsItems_00881C30.f_8[nIndex - 1].nStamp, gtNewsItems_00881C30.f_8[nIndex - 1].szText);
        --nIndex;
    }
}

#include "gen/data/Source/Bnclient/0051D260_sub_0051D260_SelectVersion.inc"
