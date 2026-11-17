#include "D2Client.h"

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x01F];
    char nByte1F;
    char unk0x020[0x17];
    char nByte37;
    char unk0x038[0x6D];
    unsigned int adwSecret[6];
    char unk0x0BD[0x168];
    D2FuncTable_0077ABF0Strc* pFuncTable;
    char unk0x229[0x1C];
    char nByte245;
    char unk0x246[0x117];
    char bRegistryMode;
    char nStartMode;
    char bIntroPlayed;
    char unk0x360[1];
    char nByte361;
    char unk0x362[0x1F];
    char nByte381;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
void __cdecl sub_0042E6D0_LoadFrontEndCells();                                                              // 0x0042E6D0
void __cdecl sub_0042EF50_FreeFrontEndCells();                                                              // 0x0042EF50
void __cdecl sub_0042FFE0_CreateScreen();                                                                   // 0x0042FFE0
int __cdecl sub_004309B0_ClearState();                                                                      // 0x004309B0
void __stdcall sub_00430BB0_LoopCallback(unsigned long nArg);                                               // 0x00430BB0
void __cdecl sub_00435230_PlayIntroVideos();                                                                // 0x00435230
void __cdecl sub_00435330_ShowLoginScreen();                                                                // 0x00435330
int __fastcall sub_0043B7A0_InitFuncTable(D2LaunchRecordStrc* pRecord);                                     // 0x0043B7A0
int __stdcall sub_004F5BC0_CenterWindow(int nResolution);                                                   // 0x004F5BC0
int __fastcall D2Win_10015();                                                                               // 0x004F8FE0
int __stdcall CURSOR_SetCellFile(D2CelFileStrc* pCellFile);                                                 // 0x004F9160
void __stdcall sub_004F9180(int (__cdecl* a1)());                                                            // 0x004F9180
int __stdcall sub_004FA590(void (__stdcall* pCallback)(unsigned long));                                      // 0x004FA590
void* __stdcall sub_004FAC80(int nArg);                                                                     // 0x004FAC80
void __cdecl sub_00514DB0();                                                                                // 0x00514DB0
void __fastcall sub_00514E10(const char* szFile);                                                           // 0x00514E10
int __cdecl sub_00514FB0_IsAnyWavePlaying();                                                                // 0x00514FB0
void __cdecl sub_00515070();                                                                                // 0x00515070

extern D2CelFileStrc* gpCellFile_0077971C;                                                                  // 0x0077971C
extern int gnLaunchState_007795E8;                                                                          // 0x007795E8
int gnLaunchMode_007795EC;                                                                                  // 0x007795EC
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

// 0x004359D0
int __fastcall sub_004359D0_RunFrontEnd(D2LaunchRecordStrc* pRecord)
{
    gpLaunchRecord_007795D4 = pRecord;
    D2Win_10015();
    D2_ASSERT(sub_005259C0(sub_004FAC80(sub_00408F20_HasExpansionMpq()), 0), 0x125A);
    sub_0042E6D0_LoadFrontEndCells();
    CURSOR_SetCellFile(gpCellFile_0077971C);
    gpLaunchRecord_007795D4->nByte361 = 0;
    gpLaunchRecord_007795D4->nByte381 = 0;
    gpLaunchRecord_007795D4->nByte1F = 0;
    gpLaunchRecord_007795D4->nByte245 = 0;
    if (gnLaunchMode_007795EC != 2)
        gpLaunchRecord_007795D4->nByte37 = 0;
    sub_00514DB0();
    sub_00514E10("data\\global\\sfx\\cursor\\button.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\amazon select.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\amazon deselect.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\barbarian select.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\barbarian deselect.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\paladin select.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\paladin deselect.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\necromancer select.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\necromancer deselect.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\sorceress select.wav");
    sub_00514E10("data\\global\\sfx\\cursor\\intro\\sorceress deselect.wav");
    if (sub_00408F20_HasExpansionMpq())
    {
        sub_00514E10("data\\global\\sfx\\cursor\\intro\\druid select.wav");
        sub_00514E10("data\\global\\sfx\\cursor\\intro\\druid deselect.wav");
        sub_00514E10("data\\global\\sfx\\cursor\\intro\\assassin select.wav");
        sub_00514E10("data\\global\\sfx\\cursor\\intro\\assassin deselect.wav");
    }
    gpFuncTable_0077ABF0 = pRecord->pFuncTable;
    const char nStartMode = gpLaunchRecord_007795D4->nStartMode;
    if (nStartMode == 2)
    {
        if (gpFuncTable_0077ABF0->pfnSlot68())
        {
            gnLaunchMode_007795EC = 1;
            sub_004F90A0(1);
            sub_0043B080();
        }
        else
        {
            gnLaunchMode_007795EC = 1;
            sub_004F90A0(1);
            sub_00435330_ShowLoginScreen();
        }
    }
    else if (nStartMode == 4)
    {
        if (gpFuncTable_0077ABF0->pfnSlot68())
        {
            gnLaunchMode_007795EC = 3;
            sub_004F90A0(1);
            sub_0043B080();
        }
        else
        {
            gnLaunchMode_007795EC = 3;
            sub_004F90A0(1);
            sub_00435330_ShowLoginScreen();
        }
    }
    else if (nStartMode == 3)
    {
        sub_0043B7A0_InitFuncTable(gpLaunchRecord_007795D4);
        gnLaunchMode_007795EC = 2;
        sub_004F90A0(1);
        sub_0042FFE0_CreateScreen();
    }
    else
    {
        sub_0043B7A0_InitFuncTable(gpLaunchRecord_007795D4);
        if (gpLaunchRecord_007795D4->bRegistryMode)
        {
            unsigned long nValue = 0;
            SRegLoadValue("Diablo II", "Skip To Open", 0, &nValue);
            gpLaunchRecord_007795D4->bRegistryMode = 0;
            gpLaunchRecord_007795D4->bIntroPlayed = 1;
            sub_004F90A0(1);
            sub_004F5BC0_CenterWindow(1);
            gnLaunchMode_007795EC = nValue ? 3 : 1;
            sub_00435330_ShowLoginScreen();
        }
        else
        {
            if (!gpLaunchRecord_007795D4->bIntroPlayed)
            {
                gnLaunchMode_007795EC = 0;
                sub_004F90A0(1);
                sub_004F5BC0_CenterWindow(1);
                sub_00435230_PlayIntroVideos();
                gpLaunchRecord_007795D4->bIntroPlayed = 1;
            }
            else
            {
                gnLaunchMode_007795EC = 0;
                sub_004F90A0(1);
                sub_004336C0();
            }
        }
    }
    sub_004F9180(sub_004309B0_ClearState);
    sub_004FA590(sub_00430BB0_LoopCallback);
    sub_00515020();
    while (sub_00514FB0_IsAnyWavePlaying())
        Sleep(0);
    sub_00515070();
    sub_0042F480_Reset();
    sub_0042EF50_FreeFrontEndCells();
    sub_00524E40();
    memset(gpLaunchRecord_007795D4->adwSecret, 0, sizeof(gpLaunchRecord_007795D4->adwSecret));
    sub_004FA550();
    return gnLaunchState_007795E8;
}
