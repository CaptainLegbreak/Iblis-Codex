struct Unicode
{
    unsigned short wChar;
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0xB8];
    void (__fastcall* pfnSlotB8)(char* szText);
};

struct D2LaunchRecordStrc
{
    char unk0x000[0x19];
    char aState19[4];
    char unk0x01D[0x70];
    char szAccount[0x18];
    char unk0x0A5[0x18];
    char szCharName[0x18];
    char nByteD5;
    char unk0x0D6[0x17];
    char aDataED[0x101];
    char nClass;
    char aFlags1EF[2];
    char unk0x1F1[0x18];
    char aState209[4];
    char unk0x20D[0x20];
    char nByte22D;
    char unk0x22E[0x130];
    char nByte35E;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
int __stdcall sub_004334D0_CloseBox(int nArg);                                                              // 0x004334D0
int __fastcall sub_004F9190();                                                            // 0x004F9190
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode);                    // 0x0043C180
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
void __cdecl sub_00515020();                                                                                // 0x00515020
void __cdecl sub_0042F480_Reset();                                                                          // 0x0042F480
void __cdecl sub_0043B080();                                                                                // 0x0043B080
int __cdecl sub_00430BC0_HasSaveFiles();                                                                    // 0x00430BC0
void __cdecl sub_00435580();                                                                                // 0x00435580
void __cdecl sub_00435330_ShowLoginScreen();                                                                // 0x00435330
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_00436CF0();                                                                                // 0x00436CF0
void __cdecl sub_00436EB0_UpdateOkButton();                                                                 // 0x00436EB0
void __fastcall sub_0043C540(char* szName, char nClass, char* pData, int nFlags);                           // 0x0043C540
void __fastcall sub_0043C6A0(int bSet);                                                                     // 0x0043C6A0
void __fastcall sub_0043C6B0(char* szName);                                                                 // 0x0043C6B0
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
void __cdecl sub_00435E10();                                                                                // 0x00435E10

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
int gnLaunchState_007795E8;                                                                                 // 0x007795E8
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
int gdwGlobal_007795F4;                                                                                     // 0x007795F4
int gdwGlobal_007799D8;                                                                                     // 0x007799D8
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

// 0x00436270
int __stdcall sub_00436270_OnShowLogin(int nArg)
{
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436280
int __stdcall sub_00436280_ConnectOk(int nArg)
{
    gdwGlobal_007795F4 = 0;
    if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 1, 0))
    {
        if (gdwGlobal_007795F4)
        {
            sub_00435330_ShowLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        if (sub_00430BC0_HasSaveFiles())
        {
            sub_00515020();
            sub_0042F480_Reset();
            sub_0043B080();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

// 0x00436300
int __stdcall sub_00436300_BackToLogin(int nArg)
{
    sub_0042F3F0_DestroyControls();
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436360
int __stdcall sub_00436360_SubmitCharacter(int nArg)
{
    if (gpLaunchRecord_007795D4->nClass == 6 || gpLaunchRecord_007795D4->nClass == 5)
        *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF |= 0x20;
    if (gnLaunchMode_007795EC == 3)
    {
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 4;
        gnLaunchState_007795E8 = 3;
        *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        gpLaunchRecord_007795D4->nByte22D = 0;
        gpLaunchRecord_007795D4->nByteD5 = 0;
        sub_004F9190();
        return 1;
    }
    if (gnLaunchMode_007795EC == 0)
    {
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 1;
        *(int*)gpLaunchRecord_007795D4->aState19 = 0;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        gnLaunchState_007795E8 = 1;
        sub_004F9190();
        return 1;
    }
    if (gnLaunchMode_007795EC == 2)
    {
        sub_0043C6A0(0);
        sub_0043C540(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
        return 1;
    }
    if (gnLaunchMode_007795EC == 1)
        sub_00435E10();
    return 1;
}

// 0x00436590
int __stdcall sub_00436590_Back(int nArg)
{
    sub_0042F3F0_DestroyControls();
    sub_00435580();
    return 1;
}

// 0x00436C70
int __stdcall sub_00436C70_SendEmptyText(int nArg)
{
    gpFuncTable_0077ABF0->pfnSlotB8((char*)&gszEmptyAssertText);
    sub_004F9190();
    return 1;
}

// 0x00436C90
int __stdcall sub_00436C90_AskConfirm(int nArg)
{
    sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5E), 0x2B61, 0x13EF, sub_00436C70_SendEmptyText, sub_004334D0_CloseBox, 0, 1);
    return 1;
}

// 0x00436CD0
int __stdcall sub_00436CD0_SetFlagAndExit(int nArg)
{
    gdwGlobal_007799D8 = 1;
    sub_004F9190();
    return 1;
}

// 0x00436D40
int __stdcall sub_00436D40_Callback(int nArg)
{
    sub_00436CF0();
    return 1;
}

// 0x00436F20
int __stdcall sub_00436F20_OnEditChange(int nArg)
{
    sub_00436EB0_UpdateOkButton();
    return 1;
}
