struct Unicode
{
    unsigned short wChar;
};

struct D2StatusStrc
{
    int nCode;
    int nArg;
};

#pragma pack(push, 1)
struct D2LaunchRecordStrc
{
    char unk0x000[0x8D];
    char szAccount[0x18];
    char szPassword[0x100];
};
#pragma pack(pop)

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x08];
    void (__fastcall* pfnSlot08)(char* szAccount, char* szPassword);
    char unk0x0C[0x04];
    int (__fastcall* pfnSlot10)();
    char unk0x14[0x14];
    int (__fastcall* pfnSlot28)(D2StatusStrc* pStatus);
    char unk0x2C[0x34];
    void (__fastcall* pfnSlot60)(char* szAccount, char* szPassword);
    void (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x30];
    void (__fastcall* pfnSlot9C)(char* szAccount, char* szOldPassword, char* szPassword);
    void (__fastcall* pfnSlotA0)(int* pValue);
    char unk0xA4[0x10];
    int (__fastcall* pfnSlotB4)();
};

typedef void (__cdecl* D2LaunchDoneFn)();
typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl sub_0042F6D0();                                                                                 // 0x0042F6D0
void __cdecl sub_0042F6E0();                                                                                // 0x0042F6E0
void __cdecl sub_0042F880();                                                                                // 0x0042F880
void __fastcall sub_0042FF10(int nArg);                                                                     // 0x0042FF10
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);                        // 0x00433450
void __cdecl sub_004336C0();                                                                                // 0x004336C0
void __cdecl sub_00436D50_CreateScreen();                                                                   // 0x00436D50
int __stdcall sub_00436E90(int nArg);                                                                       // 0x00436E90
int __cdecl sub_00436EA0();                                                                                 // 0x00436EA0
int __stdcall sub_0043B890(int nArg);                                                                       // 0x0043B890
int __stdcall sub_0043B8E0(int nArg);                                                                       // 0x0043B8E0
int __stdcall sub_0043B940(int nArg);                                                                       // 0x0043B940
int __fastcall sub_0043B9F0_HandleStatus(D2StatusStrc* pStatus);                                            // 0x0043B9F0
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590

extern char gszOldPassword_00779550[];                                                                      // 0x00779550
D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                             // 0x0077ABF0
int gdwGlobal_0077AC04;                                                                                     // 0x0077AC04
static int s_bConnected_0077AC08;                                                                           // 0x0077AC08

// 0x0043BF40
static __declspec(noinline) void sub_0043BF40_ReportStatus(int nCode, int nArg)
{
    D2StatusStrc tStatus;
    tStatus.nCode = nCode;
    tStatus.nArg = nArg;
    sub_0043B9F0_HandleStatus(&tStatus);
}

// 0x0043C180
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode)
{
    D2StatusStrc tStatus;

    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return 0;
    }

    if (s_bConnected_0077AC08)
    {
        return 1;
    }

    sub_0042F6E0();
    gpFuncTable_0077ABF0->pfnSlot28(&tStatus);
    if (bFlag && !tStatus.nCode)
    {
        gpFuncTable_0077ABF0->pfnSlot60(pRecord->szAccount, pRecord->szPassword);
        sub_004FA590_RunLoop(sub_0043B8E0);
        if (gdwGlobal_0077AC04)
        {
            sub_0042F880();
            return 0;
        }

        gpFuncTable_0077ABF0->pfnSlot64(&nMode);
        if (nMode && gpFuncTable_0077ABF0->pfnSlot68())
        {
            int nCode;
            switch (nMode)
            {
            case 2:
                nCode = 0x14;
                break;
            case 3:
                nCode = 0x15;
                break;
            case 4:
                nCode = 0x16;
                break;
            case 5:
                nCode = 0x17;
                break;
            case 6:
                nCode = 0x18;
                break;
            case 7:
                nCode = 0x19;
                break;
            case 8:
                nCode = 0x1A;
                break;
            default:
                nCode = 0x13;
                break;
            }

            sub_0043BF40_ReportStatus(nCode, 0);
            return 0;
        }
    }
    else if (nMode && !tStatus.nCode)
    {
        gpFuncTable_0077ABF0->pfnSlot9C(pRecord->szAccount, gszOldPassword_00779550, pRecord->szPassword);
        sub_004FA590_RunLoop(sub_0043B940);
        if (gdwGlobal_0077AC04)
        {
            sub_0042F880();
            return 0;
        }

        gpFuncTable_0077ABF0->pfnSlotA0(&nMode);
        if (nMode != 1 && gpFuncTable_0077ABF0->pfnSlot68())
        {
            sub_0043BF40_ReportStatus(0xE, 0);
            return 0;
        }
    }

    if (gpFuncTable_0077ABF0->pfnSlot68() && !tStatus.nCode)
    {
        gpFuncTable_0077ABF0->pfnSlot08(pRecord->szAccount, pRecord->szPassword);
        memset(pRecord->szPassword, 0, 0x18);
        sub_004FA590_RunLoop(sub_0043B890);
        if (gdwGlobal_0077AC04 || sub_0042F6D0())
        {
            sub_0042F880();
            return 0;
        }
    }

    gpFuncTable_0077ABF0->pfnSlot28(&tStatus);
    sub_0042F880();
    if (tStatus.nCode)
    {
        return sub_0043B9F0_HandleStatus(&tStatus);
    }

    s_bConnected_0077AC08 = 1;
    int bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    if (bConnected && gpFuncTable_0077ABF0->pfnSlotB4())
    {
        sub_00436D50_CreateScreen();
        sub_004FA590_RunLoop(sub_00436E90);
        sub_0042F880();
        if (sub_00436EA0())
        {
            D2MCPClientCloseMCP();
            gpFuncTable_0077ABF0->pfnSlot10();
            sub_004336C0();
            return 0;
        }

        bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    }

    if (bConnected)
    {
        sub_0042FF10(0);
        return 1;
    }

    D2StatusStrc tError;
    tError.nCode = 0x12;
    tError.nArg = 0;
    sub_0043B9F0_HandleStatus(&tError);
    return 0;
}
