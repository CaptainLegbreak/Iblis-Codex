#include "D2Client.h"
#include "D2ClientUi.h"
#include "D2ClientSound.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;
struct D2HintKeyListStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
void __cdecl INV_ClearTradeFlag(); // 0x0048A6F0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue); // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8); // 0x004B85F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_004B8A30_OnCancel(); // 0x004B8A30
int __cdecl sub_004B8A80_OnClose(); // 0x004B8A80
extern D2ClientDialogStrc* gpTradeWaitDialog; // 0x007C0E6C
extern unsigned long gdwTradeTimeoutTick; // 0x007C0E70
extern unsigned long gdwSecondaryTradeGold; // 0x007C0E78
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __cdecl sub_004B8BA0_OnClose2(); // 0x004B8BA0

struct D2HintKeyListStrc
{
    int unk0x00;
    int nCount;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x10];
    int nValue;
    char unk0x20[8];
    D2HintKeyListStrc* pKeyList;
    int unk0x2C;
    int nState;
    char unk0x34[9];
    char f_3D[4];
    char unk0x41[4];
    char bArmed[4];
    char nSavedValue[4];
    char nGroup[4];
    char nStart[4];
    char nEnd[4];
};

int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue); // 0x004B9B50
extern D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458

D2ClientDialogStrc* gpTradeRequestDialog; // 0x007C0E64

unsigned long gdwPrimaryTradeGold; // 0x007C0E68

char gbGlobal_007C0E74; // 0x007C0E74

int gnTradeState; // 0x007C0E7C

char gbTradeActive; // 0x007C0E80

// 0x004B8720
void __cdecl sub_004B8720()
{
    gnTradeState = 0;
    gbGlobal_007C0E74 = 0;
}

// 0x004B8920
void __cdecl sub_004B8920()
{
    gdwSecondaryTradeGold = 0;
    gdwPrimaryTradeGold = 0;
    gbTradeActive = 1;
}

// 0x004B8940
void __fastcall sub_004B8940_CloseWait(int bReopen)
{
    gbTradeActive = 0;
    if (gpTradeWaitDialog)
    {
        DIALOG_DestroyDialog(gpTradeWaitDialog);
        gpTradeWaitDialog = 0;
    }

    if (gpTradeRequestDialog)
    {
        DIALOG_DestroyDialog(gpTradeRequestDialog);
        gpTradeRequestDialog = 0;
    }

    if (gnTradeState == 7)
    {
        return;
    }

    if (GAME_GetUIVarState(0x17))
    {
        UI_SetUIVar(0x17, 1, 0);
        INV_ClearTradeFlag();
        sub_00487B30();
        if (!CUNIT_IsPlayerDeadOrMissing() && bReopen)
        {
            UI_SetUIVar(1, 2, 0);
        }

        if (GAME_GetUIVarState(5))
        {
            UI_SetUIVar(5, 1, 0);
        }
    }

    if (gnTradeState)
    {
        sub_00478600_SendShorts(0x4F, 2, 0, 0);
        gnTradeState = 0;
    }
}

// 0x004B8AD0
int __cdecl sub_004B8AD0_OpenWait()
{
    if (gpTradeRequestDialog)
    {
        return 0;
    }

    gpTradeRequestDialog = DIALOG_CreateDialog(0x140, 0x64, sub_004B8A80_OnClose, sub_004B8A80_OnClose, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpTradeRequestDialog, 1);
    sub_004B85F0_AddTextLine(gpTradeRequestDialog, D2LANG_GetStringFromTblIndex(0xFCA), 0xF, 0, 0, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpTradeRequestDialog, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B8A30_OnCancel, 1);
    sub_004B85F0_AddTextLine(gpTradeRequestDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B8A80_OnClose, 1);
    sub_004B82F0_Select(gpTradeRequestDialog, -1);
    return 1;
}

// 0x004B8CB0
void __cdecl sub_004B8CB0()
{
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    if (gnTradeState != 7)
    {
        gbGlobal_007C0E74 = 1;
        gdwTradeTimeoutTick = GetTickCount();
        gnTradeState = 7;
    }
}

// 0x004B9070
void __cdecl sub_004B9070_SendPosition()
{
    gnTradeState = 7;
    sub_00478600_SendShorts(0x4F, 4, (unsigned short)(gdwPrimaryTradeGold >> 16), (unsigned short)gdwPrimaryTradeGold);
    gdwTradeTimeoutTick = 0xFFFFFFFF;
}

D2ClientDialogStrc* gpTradeWaitDialog; // 0x007C0E6C

// 0x004B8BF0
void __cdecl sub_004B8BF0_OpenWait2()
{
    D2_ASSERT(!gpTradeWaitDialog, 0x13D);
    gpTradeWaitDialog = DIALOG_CreateDialog(0x140, 0x64, sub_004B8BA0_OnClose2, sub_004B8BA0_OnClose2, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpTradeWaitDialog, 1);
    sub_004B85F0_AddTextLine(gpTradeWaitDialog, D2LANG_GetStringFromTblIndex(0xFCB), 0xF, 0, 0, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpTradeWaitDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B8BA0_OnClose2, 1);
    sub_004B82F0_Select(gpTradeWaitDialog, -1);
}

#include "gen/data/Source/D2Client/Unknown_004B8720.inc"
