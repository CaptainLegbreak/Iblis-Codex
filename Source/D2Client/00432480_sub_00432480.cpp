extern "C" int __cdecl strcmp(const char* szA, const char* szB);
#pragma intrinsic(strcmp)

struct D2LaunchRecordStrc
{
    char unk0x000[0xD5];
    char szNameD5[0x158];
    char szName22D[0x100];
};

struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};

struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x44];
    D2LaunchPayloadStrc* (__fastcall* pfn0x44)(const char* szRealm, const char* szKey);
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4;                                                         // 0x007795D4
static int gnWaitDone_00779994;                                                                             // 0x00779994
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl sub_0042F3F0_DestroyControls();                                                                // 0x0042F3F0
void __cdecl sub_0042F6E0();                                                                                // 0x0042F6E0
int __cdecl sub_00432400_GetStatus();                                                                       // 0x00432400
int __stdcall sub_00432450_OnWait(int nArg);                                                                // 0x00432450
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
int __cdecl sub_00449B30_QueryAddress();                                                                    // 0x00449B30
void __stdcall sub_0044A130_StartThread(D2LaunchThreadRecordStrc* pRecord);                                 // 0x0044A130
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590

// 0x00432480
int __fastcall sub_00432480(const char* szName, int bFlag)
{
    if (*szName && gpLaunchRecord_007795D4->szName22D[0] && !strcmp(szName, gpLaunchRecord_007795D4->szName22D) && sub_00449B30_QueryAddress())
    {
        return 0;
    }

    if (!bFlag)
    {
        sub_0042F6E0();
    }

    D2MCPClientCloseMCP();
    gnWaitDone_00779994 = 0;

    if (!*szName)
    {
        gpLaunchRecord_007795D4->szName22D[0] = 0;
        gpLaunchRecord_007795D4->szNameD5[0] = 0;
        if (!bFlag)
        {
            sub_0042F3F0_DestroyControls();
        }

        return 0;
    }

    D2LaunchPayloadStrc* pPayload;
    if (!gpFuncTable_0077ABF0)
        goto fail;
    pPayload = gpFuncTable_0077ABF0->pfn0x44(szName, "password");
    if (!pPayload)
        goto fail;
    if (pPayload->nSize == 8)
    {
fail:
        if (!bFlag)
            sub_0042F3F0_DestroyControls();
        return 2;
    }
    SStrCopy(gpLaunchRecord_007795D4->szName22D, szName, 0x100);
    SStrCopy(gpLaunchRecord_007795D4->szNameD5, szName, 0x100);
    sub_0044A130_StartThread(&pPayload->tRecord);
    int nResult = 3;
    if (!bFlag)
    {
        sub_004FA590_RunLoop(sub_00432450_OnWait);
        nResult = sub_00432400_GetStatus();
        sub_0042F3F0_DestroyControls();
    }
    return nResult;
}
