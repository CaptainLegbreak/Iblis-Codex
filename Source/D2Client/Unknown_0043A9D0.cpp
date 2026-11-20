#include "D2Client.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ListMsgStrc;
struct Unicode;
struct D2StatusStrc;
struct D2FuncTable_0077ABF0Strc;

struct D2ListMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall sub_00439840(D2ListMsgStrc* pMsg); // 0x00439840
int __cdecl sub_00439210_Redraw(); // 0x00439210
extern int gnSelected_0070CC00; // 0x0070CC00
extern void* gapRowControls_00779A20[]; // 0x00779A20
extern void* gapRowControlsX_00779B40[]; // 0x00779B40
extern int gbFlag_00779C6C; // 0x00779C6C
extern int gdwGlobal_00779DC4; // 0x00779DC4
extern int gnTopRow_00779DC8; // 0x00779DC8

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
    char unk0x2C[0x1C];
    int (__fastcall* pfnSlot48)(int* pValue);
    int (__fastcall* pfnSlot4C)();
    unsigned char unk_50[0x10];
    void (__fastcall* pfnSlot60)(char* szAccount, char* szPassword);
    void (__fastcall* pfnSlot64)(int* pValue);
    int (__fastcall* pfnSlot68)();
    char unk0x6C[0x2C];
    int (__fastcall* pfnSlot98)();
    void (__fastcall* pfnSlot9C)(char* szAccount, char* szOldPassword, char* szPassword);
    void (__fastcall* pfnSlotA0)(int* pValue);
    char unk0xA4[0x10];
    int (__fastcall* pfnSlotB4)();
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_0042F6D0(); // 0x0042F6D0
void __cdecl sub_0042F880_DestroyControls(); // 0x0042F880
void __fastcall sub_0042FF10_SetValue(int nArg); // 0x0042FF10
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __cdecl sub_00436D50_CreateScreen(); // 0x00436D50
int __stdcall sub_00436E90_AlwaysOne(int nArg); // 0x00436E90
int __cdecl sub_00436EA0(); // 0x00436EA0
int __stdcall sub_0043B890(int nArg); // 0x0043B890
int __stdcall sub_0043B8E0(int nArg); // 0x0043B8E0
int __stdcall sub_0043B940(int nArg); // 0x0043B940
int __fastcall sub_0043B9F0_HandleStatus(D2StatusStrc* pStatus); // 0x0043B9F0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode); // 0x006CC274
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __cdecl sub_0042F890_ShowProgressScreen(); // 0x0042F890
void __cdecl sub_0042FA20(); // 0x0042FA20
int __cdecl sub_0042FA30(); // 0x0042FA30
int __stdcall sub_004374F0_UpdateStatusWait(int nArg); // 0x004374F0
void __cdecl sub_00437550_CreateStatusScreen(); // 0x00437550
int __stdcall sub_0043B850_LogonCallback(int nArg); // 0x0043B850
int __stdcall D2Win_CloseSpriteCache(); // 0x004F9030
void __stdcall sub_00517ED0(int nValue); // 0x00517ED0
extern int gnLaunchMode_007795EC; // 0x007795EC
extern int gdwGlobal_007795F4; // 0x007795F4
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern int gdwGlobal_0077AC04; // 0x0077AC04
extern int s_bConnected_0077AC08; // 0x0077AC08

unsigned long gdwLastClick_00779DEC; // 0x00779DEC

// 0x0043A9D0
int __stdcall sub_0043A9D0_ListClick(D2ListMsgStrc* pMsg)
{
    if (!gbFlag_00779C6C)
    {
        const int nPrevious = gnSelected_0070CC00;
        void* hWnd = pMsg->hWnd;
        int nRow;
        for (nRow = 0; nRow < gnVisibleRows_0070CC0C; nRow += 1)
        {
            if (sub_00408F20_HasExpansionMpq() && hWnd == gapRowControlsX_00779B40[nRow])
                break;
            if (hWnd == gapRowControls_00779A20[nRow])
                break;
        }
        const int nIndex = gnTopRow_00779DC8 + nRow;
        if (gdwGlobal_00779DC4 < nIndex)
            return 0;
        gnSelected_0070CC00 = nIndex;
        if (gdwGlobal_00779DC4 <= 0)
            gnSelected_0070CC00 = -1;
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
            if (gnSelected_0070CC00 != -1 && gnSelected_0070CC00 == nPrevious && dwTick - gdwLastClick_00779DEC < 500)
                return sub_00439840(pMsg);
            gdwLastClick_00779DEC = dwTick;
        }
        return sub_00439210_Redraw();
    }
    return 1;
}

D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0

int gdwGlobal_0077AC04; // 0x0077AC04

static int s_bConnected_0077AC08; // 0x0077AC08

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
            sub_0042F880_DestroyControls();
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
            sub_0042F880_DestroyControls();
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
            sub_0042F880_DestroyControls();
            return 0;
        }
    }

    gpFuncTable_0077ABF0->pfnSlot28(&tStatus);
    sub_0042F880_DestroyControls();
    if (tStatus.nCode)
    {
        return sub_0043B9F0_HandleStatus(&tStatus);
    }

    s_bConnected_0077AC08 = 1;
    int bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    if (bConnected && gpFuncTable_0077ABF0->pfnSlotB4())
    {
        sub_00436D50_CreateScreen();
        sub_004FA590_RunLoop(sub_00436E90_AlwaysOne);
        sub_0042F880_DestroyControls();
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
        sub_0042FF10_SetValue(0);
        return 1;
    }

    D2StatusStrc tError;
    tError.nCode = 0x12;
    tError.nArg = 0;
    sub_0043B9F0_HandleStatus(&tError);
    return 0;
}

static int s_bConnecting_0077AC0C; // 0x0077AC0C

// 0x0043BF60
int __cdecl sub_0043BF60()
{
    if (!gpFuncTable_0077ABF0)
    {
        return 0;
    }

    D2_ASSERT(!s_bConnecting_0077AC0C, 296);
    s_bConnecting_0077AC0C = 1;
    gdwGlobal_00779DA4 = 1;
    sub_0042FA20();
    OutputDebugStringA("------------------\nConnect to Battle.net\n------------------\n");
    D2MCPClientCloseMCP();

    if (!gpFuncTable_0077ABF0->pfnSlot10())
    {
        D2StatusStrc tStatus;
        s_bConnecting_0077AC0C = 0;
        tStatus.nCode = 0;
        tStatus.nArg = 0;
        return sub_0043B9F0_HandleStatus(&tStatus);
    }

    s_bConnected_0077AC08 = 0;
    sub_00437550_CreateStatusScreen();
    sub_004FA590_RunLoop(sub_004374F0_UpdateStatusWait);

    if (gdwGlobal_0077AC04)
    {
        gdwGlobal_007795F4 = 1;
        sub_0042F880_DestroyControls();
        gpFuncTable_0077ABF0->pfnSlot10();
        s_bConnecting_0077AC0C = 0;
        return 0;
    }

    if (gpFuncTable_0077ABF0->pfnSlot4C() != 0x66)
    {
        sub_0042F890_ShowProgressScreen();
        sub_004FA590_RunLoop(sub_0043B850_LogonCallback);

        if (!sub_0042FA30() && gpFuncTable_0077ABF0->pfnSlot4C() == 0x65)
        {
            int nValue = 0;
            const int nResult = gpFuncTable_0077ABF0->pfnSlot48(&nValue);
            if (nValue)
            {
                int bSkipToOpen = 0;
                if (gnLaunchMode_007795EC == 3)
                {
                    bSkipToOpen = 1;
                }
                SRegSaveValue("Diablo II", "UseCmdLine", 0, 1);
                SRegSaveValue("Diablo II", "Skip To Open", 0, bSkipToOpen);
                D2Win_CloseSpriteCache();
                gpFuncTable_0077ABF0->pfnSlot10();
                s_bConnecting_0077AC0C = 0;
                sub_00517ED0(gpFuncTable_0077ABF0->pfnSlot98());
                TerminateProcess(GetCurrentProcess(), 0);
                return 0;
            }

            if (!nResult)
            {
                D2StatusStrc tStatus;
                s_bConnecting_0077AC0C = 0;
                tStatus.nCode = 0x12;
                tStatus.nArg = 0;
                return sub_0043B9F0_HandleStatus(&tStatus);
            }
        }
        else
        {
            gpFuncTable_0077ABF0->pfnSlot10();
            s_bConnecting_0077AC0C = 0;
            sub_004336C0();
            return 0;
        }
    }

    sub_0042F880_DestroyControls();
    D2StatusStrc tResult;
    gpFuncTable_0077ABF0->pfnSlot28(&tResult);
    s_bConnecting_0077AC0C = 0;
    if (tResult.nCode)
    {
        return sub_0043B9F0_HandleStatus(&tResult);
    }

    return gpFuncTable_0077ABF0->pfnSlot68() != 0;
}
