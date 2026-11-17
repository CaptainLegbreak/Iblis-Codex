struct Unicode;
struct D2WinControlStrc;
struct D2WinTextBoxStrc;
typedef void (__cdecl* D2LaunchDoneFn)();

struct D2CharSelCacheStrc
{
    unsigned int dwHash;
    void* pData;
    unsigned int dwExpireTick;
    D2CharSelCacheStrc* pNext;
};

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x68];
    int (__fastcall* pfnSlot68)();
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone);
void __cdecl sub_004336C0_ShowMainMenu();
void __cdecl sub_00438EA0_FreeCharList();
int __stdcall sub_0043AAB0(const char* szName, int pPacket, int bFlag);
int __fastcall D2Win_10047(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FB6A0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int a3);                        // 0x004FCFF0
void __cdecl sub_00439210_Redraw();
void __cdecl sub_00438560_Refresh();
int __cdecl sub_00408F20_HasExpansionMpq();
void __cdecl sub_0043A5D0_ShowMessage();
void __cdecl sub_00438F70();

extern D2CharSelCacheStrc* gpCharSelCache_00779DE8;                                                         // 0x00779DE8
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0
extern D2WinControlStrc* gpControl_00779D90;                                                                // 0x00779D90
D2WinControlStrc* gpControl_00779D8C;                                                                       // 0x00779D8C
extern int gdwGlobal_00779DB8;                                                                              // 0x00779DB8
extern int gnState_00779DAC;                                                                                // 0x00779DAC
extern char* gpszName_00779DB0;                                                                             // 0x00779DB0
extern int gnLaunchMode_007795EC;                                                                           // 0x007795EC
extern int gbFlag_00779DD8;                                                                                 // 0x00779DD8

static __forceinline void* CharSelCache_FindData(unsigned int dwHash, int nTick)
{
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache_00779DE8; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

// 0x0043AD10
static __declspec(noinline) void sub_0043AD10_RequestCharList(char* szName)
{
    sub_00438EA0_FreeCharList();
    gdwGlobal_00779DB8 = 0;
    sub_004F96F0_ControlClearState(gpControl_00779D90, 1);
    const unsigned int dwHash = SStrHash(szName, 0, 0);
    const int nTick = GetTickCount();
    void* pData = CharSelCache_FindData(dwHash, nTick);
    if (!pData)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0_ShowMainMenu);
            return;
        }
        gnState_00779DAC = 1;
        gpszName_00779DB0 = szName;
        return;
    }
    sub_0043AAB0(szName, (int)pData, 0);
}

// 0x0043ADB0
void __fastcall sub_0043ADB0_UseName(char* szName)
{
    gbFlag_00779DD8 = 0;
    if (gnLaunchMode_007795EC == 1)
    {
        D2Win_10047((D2WinTextBoxStrc*)gpControl_00779D8C);
        D2Win_10046(gpControl_00779D8C, szName, 0);
        sub_0043AD10_RequestCharList(szName);
    }
    else if (gnLaunchMode_007795EC == 0 || gnLaunchMode_007795EC == 3 || gnLaunchMode_007795EC == 2)
    {
        sub_00438EA0_FreeCharList();
        if (!sub_00408F20_HasExpansionMpq())
            sub_0043A5D0_ShowMessage();
        sub_00438F70();
    }
    sub_00439210_Redraw();
    sub_00438560_Refresh();
}
