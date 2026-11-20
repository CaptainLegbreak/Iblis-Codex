extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
#pragma intrinsic(strcpy)

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x70];
    int (__fastcall* pfnSlot70)();
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x19];
    int nValue019;
    char unk0x01D[0x1A];
    char szLocalIp037[0x1D2];
    int nValue209;
};
#pragma pack(pop)

extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gdwGlobal_0077932C;                                                                              // 0x0077932C

const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
int __cdecl sub_00430BC0_HasSaveFiles();                                                                    // 0x00430BC0
void __cdecl sub_004336C0_ShowMainMenu();                                                                                // 0x004336C0
void __cdecl sub_00435330_ShowLoginScreen();                                                                // 0x00435330
void __cdecl sub_00435580_CreateCharCreateScreen();                                                                                // 0x00435580
void __cdecl sub_0043B080_InitCharSelectScreen();                                                                                // 0x0043B080
void __cdecl sub_00515020_FadeOutWaves();                                                                                // 0x00515020

// 0x00435200
int __stdcall sub_00435200_RunSlot70(int nArg)
{
    gpFuncTable_0077ABF0->pfnSlot70();
    gdwGlobal_0077932C = 1;
    sub_004336C0_ShowMainMenu();
    return 1;
}

// 0x00435CD0
int __stdcall sub_00435CD0_SelectMode0(int nArg)
{
    gnLaunchMode_007795EC = 0;
    if (sub_00430BC0_HasSaveFiles() == 1)
    {
        sub_00515020_FadeOutWaves();
        sub_0042F480_Reset();
        sub_0043B080_InitCharSelectScreen();
        return 1;
    }

    sub_00435580_CreateCharCreateScreen();
    return 1;
}

// 0x00435D10
int __stdcall sub_00435D10_SelectMode3(int nArg)
{
    gnLaunchMode_007795EC = 3;
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00435D30
int __stdcall sub_00435D30_SelectMode1(int nArg)
{
    gnLaunchMode_007795EC = 1;
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00435D80
int __stdcall sub_00435D80_SelectMode2(int nArg)
{
    gpLaunchRecord_007795D4->nValue019 = 8;
    strcpy(gpLaunchRecord_007795D4->szLocalIp037, FOG_GetHostIPAddress());
    gnLaunchMode_007795EC = 2;
    gpLaunchRecord_007795D4->nValue209 = 4;
    if (!sub_00430BC0_HasSaveFiles())
    {
        sub_00435580_CreateCharCreateScreen();
        return 1;
    }

    sub_00515020_FadeOutWaves();
    sub_0042F480_Reset();
    sub_0043B080_InitCharSelectScreen();
    return 1;
}
