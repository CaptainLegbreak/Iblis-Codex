struct Unicode
{
    unsigned short wChar;
};

struct D2WinControlStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
int __fastcall D2Win_10188(D2WinControlStrc* pTextBox, int nLineNum, int a3);                               // 0x004FBDE0
int __cdecl sub_00430B40();                                                                                 // 0x00430B40
char* __fastcall sub_00430B50_GetSlotName(int nIndex);                                                      // 0x00430B50
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __cdecl sub_0043A270_UpdateStatus();                                                                   // 0x0043A270
int __cdecl sub_00449B70_Receive();                                                                         // 0x00449B70
int __cdecl sub_00449E60();                                                                                 // 0x00449E60
int __cdecl sub_00449C00();                                                                                 // 0x00449C00
void __stdcall sub_00449E70_SetMcpPacket(const char* pData, int nSize);                                     // 0x00449E70
int __cdecl sub_0044AAB0_SendPacket19();                                                                    // 0x0044AAB0
int __cdecl sub_00432400_GetStatus();                                                                       // 0x00432400
int __fastcall sub_00432480(const char* szName, int bFlag);                                                 // 0x00432480
int __stdcall sub_0043AAB0(const char* szName, int pPacket, int bFlag);                                     // 0x0043AAB0

int gbFlag_00779C6C;                                                                                        // 0x00779C6C
extern D2WinControlStrc* gpNameControl_007799E8;                                                            // 0x007799E8
extern D2WinControlStrc* gpControl_00779D90;                                                                // 0x00779D90
extern D2WinControlStrc* gpControl_00779DD0;                                                                // 0x00779DD0
int gnState_00779DAC;                                                                                       // 0x00779DAC
char* gpszName_00779DB0;                                                                                    // 0x00779DB0
extern unsigned long gdwStartTick_00779DB4;                                                                 // 0x00779DB4
extern int gdwGlobal_00779DB8;                                                                              // 0x00779DB8

static __declspec(noinline) void sub_00437CB0_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
next:
    if (i >= sub_00430B40())
        return;
    char* szSlot = sub_00430B50_GetSlotName(i);
    if (!szSlot)
        return;
    if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
        D2Win_10188(gpNameControl_007799E8, i, 1);
    ++i;
    goto next;
}

// 0x0043A1F0
static __declspec(noinline) void sub_0043A1F0_ShowConnectError(int nError)
{
    int nStringId;
    switch (nError)
    {
    case 0x7E:
        nStringId = 0x2B99;
        break;
    case 0x7F:
        nStringId = 0x2B9A;
        break;
    default:
        nStringId = 0x2B3A;
        break;
    }

    gdwGlobal_00779DB8 = 1;
    gnState_00779DAC = 0;
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(nStringId), 4, 0, 0);
    sub_004F96F0_ControlClearState(gpControl_00779D90, 0);
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl_007799E8, -1, 4);
}

// 0x0043AC00
int __stdcall sub_0043AC00_PollConnect(int nUnused)
{
    switch (gnState_00779DAC)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl_007799E8, -1, 4);
        sub_00437CB0_SelectNamedSlot(gpszName_00779DB0);
        sub_00432480(gpszName_00779DB0, 1);
        gnState_00779DAC = 2;
        gdwStartTick_00779DB4 = GetTickCount();
        break;

    case 2:
        sub_0043A270_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
            sub_00449E70_SetMcpPacket(0, 0);
            gnState_00779DAC = 3;
            if (!sub_0044AAB0_SendPacket19())
                sub_0043A1F0_ShowConnectError(sub_00449C00());
            break;
        case 2:
            sub_0043A1F0_ShowConnectError(sub_00449C00());
            break;
        }
        break;

    case 3:
    {
        sub_0043A270_UpdateStatus();
        sub_00449B70_Receive();
        int pPacket = sub_00449E60();
        if (pPacket)
        {
            gnState_00779DAC = 0;
            if (gbFlag_00779C6C)
                D2Win_10188(gpNameControl_007799E8, -1, 4);
            sub_0043AAB0(gpszName_00779DB0, pPacket, 1);
        }
        break;
    }
    }

    return 1;
}
