#include "D2Multi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ModuleInterfaceStrc;
struct D2CelFileStrc;
struct D2WinMsgStrc;
struct SMSGHANDLER_PARAMS;

extern D2ModuleInterfaceStrc gtInterface_0070CD14; // 0x0070CD14
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00
void* __cdecl sub_0044DA90(); // 0x0044DA90
void* __cdecl sub_004F59A0(); // 0x004F59A0

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMsg;
    unsigned int wParam;
    int lParam;
};

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

void __fastcall sub_00448BD0_UpdateScroll(int nDelta); // 0x00448BD0
void __cdecl sub_004477A0_Refresh(); // 0x004477A0
int __cdecl sub_00449AC0(); // 0x00449AC0
int __fastcall sub_004F9190(); // 0x004F9190
int __cdecl sub_00449C30(); // 0x00449C30
void __stdcall sub_00449C40_SetValue(int nValue); // 0x00449C40
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
extern D2WinControlStrc* gpControl_0077BCFC; // 0x0077BCFC

void* gpInstance_0077AD68; // 0x0077AD68

// 0x0043CBE0
D2ModuleInterfaceStrc* __fastcall sub_0043CBE0_Init(void* hInstance)
{
    gpInstance_0077AD68 = hInstance;
    return &gtInterface_0070CD14;
}

#include "gen/data/Source/D2Multi/Unknown_0043CBE0.inc"
#include "D2StormTypes.h"

// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x0042B9D0
void __cdecl sub_0042B9D0_Nop()
{
}

// 0x00650EA0
void __cdecl sub_00650EA0_Nop()
{
}

// 0x0043CC00
const char* __fastcall sub_0043CC00_StrChr(const char* szString, char nChar, int bReverse)
{
    if (bReverse)
        return SStrChrR(szString, nChar);
    return SStrChr(szString, nChar);
}

// 0x00451880
int __fastcall sub_00451880_DispatchMsg(D2WinMsgStrc* pMsg)
{
    int bUseResult = 0;
    int lResult = 0;
    D2_ASSERT(pMsg->hWnd == sub_0044DA90(), 0x12A);
    return SMsgDispatchMessage(sub_004F59A0(), pMsg->uMsg, pMsg->wParam, pMsg->lParam, &bUseResult, &lResult);
}

// 0x0043CC20
int __fastcall sub_0043CC20_TestBit2(int nValue)
{
    return nValue & 4;
}

D2CelFileStrc* gpCellFile_0077BC04; // 0x0077BC04

D2CelFileStrc* gpCellFile_0077BC08; // 0x0077BC08

D2CelFileStrc* gpCellFile_0077BC0C; // 0x0077BC0C

D2CelFileStrc* gpCellFile_0077BC10; // 0x0077BC10

D2CelFileStrc* gpCellFile_0077BC14; // 0x0077BC14

D2CelFileStrc* gpCellFile_0077BC18; // 0x0077BC18

D2CelFileStrc* gpCellFile_0077BC1C; // 0x0077BC1C

D2CelFileStrc* gpCellFile_0077BC20; // 0x0077BC20

D2CelFileStrc* gpCellFile_0077BC24; // 0x0077BC24

D2CelFileStrc* gpCellFile_0077BC28; // 0x0077BC28

D2CelFileStrc* gpCellFile_0077BC2C; // 0x0077BC2C

D2CelFileStrc* gpCellFile_0077BC30; // 0x0077BC30

D2CelFileStrc* gpCellFile_0077BC34; // 0x0077BC34

D2CelFileStrc* gpCellFile_0077BC38; // 0x0077BC38

D2CelFileStrc* gpCellFile_0077BC3C; // 0x0077BC3C

D2CelFileStrc* gpCellFile_0077BC50; // 0x0077BC50

D2CelFileStrc* gpCellFile_0077BC54; // 0x0077BC54

D2CelFileStrc* gpCellFile_0077BC58; // 0x0077BC58

D2CelFileStrc* gpCellFile_0077BC5C; // 0x0077BC5C

D2CelFileStrc* gpCellFile_0077BC60; // 0x0077BC60

D2CelFileStrc* gpCellFile_0077BC64; // 0x0077BC64

D2CelFileStrc* gpCellFile_0077BC68; // 0x0077BC68

D2CelFileStrc* gpCellFile_0077BC6C; // 0x0077BC6C

D2CelFileStrc* gpCellFile_0077BC70; // 0x0077BC70

D2CelFileStrc* gpCellFile_0077BC74; // 0x0077BC74

D2CelFileStrc* gpCellFile_0077BC78; // 0x0077BC78

D2CelFileStrc* gpCellFile_0077BC7C; // 0x0077BC7C

D2CelFileStrc* gpCellFile_0077BC80; // 0x0077BC80

D2CelFileStrc* gpCellFile_0077BC84; // 0x0077BC84

D2CelFileStrc* gpCellFile_0077BC88; // 0x0077BC88

D2CelFileStrc* gpCellFile_0077BC8C; // 0x0077BC8C

D2CelFileStrc* gpCellFile_0077BC90; // 0x0077BC90

D2CelFileStrc* gpCellFile_0077BC94; // 0x0077BC94

D2CelFileStrc* gpCellFile_0077BCB8; // 0x0077BCB8

D2CelFileStrc* gpCellFile_0077BCBC; // 0x0077BCBC

D2CelFileStrc* gpCellFile_0077BCC0; // 0x0077BCC0

D2CelFileStrc* gpCellFile_0077BCC4; // 0x0077BCC4

D2CelFileStrc* gpCellFile_0077BCC8; // 0x0077BCC8

D2CelFileStrc* gpCellFile_0077BCCC; // 0x0077BCCC

D2CelFileStrc* gpCellFile_0077BCD0; // 0x0077BCD0

D2CelFileStrc* gpCellFile_0077BCD4; // 0x0077BCD4

D2CelFileStrc* gpCellFile_0077BCD8; // 0x0077BCD8

D2CelFileStrc* gpCellFile_0077BD0C; // 0x0077BD0C

D2CelFileStrc* gpCellFile_0077BD10; // 0x0077BD10

D2CelFileStrc* gpCellFile_0077BD18; // 0x0077BD18

D2CelFileStrc* gpCellFile_0077BD2C; // 0x0077BD2C

D2CelFileStrc* gpCellFile_0077BD30; // 0x0077BD30

D2CelFileStrc* gpCellFile_0077BD34; // 0x0077BD34

D2CelFileStrc* gpCellFile_0077BD38; // 0x0077BD38

D2CelFileStrc* gpCellFile_0077BD3C; // 0x0077BD3C

D2CelFileStrc* gpCellFile_0077BD40; // 0x0077BD40

D2CelFileStrc* gpCellFile_0077BD44; // 0x0077BD44

D2CelFileStrc* gpCellFile_0077BD48; // 0x0077BD48

D2CelFileStrc* gpCellFile_0077BD4C; // 0x0077BD4C

// 0x0043D510
void __cdecl sub_0043D510_FreeCellFiles()
{
    if (gpCellFile_0077BC0C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC0C);
        gpCellFile_0077BC0C = 0;
    }

    if (gpCellFile_0077BC10)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC10);
        gpCellFile_0077BC10 = 0;
    }

    if (gpCellFile_0077BC04)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC04);
        gpCellFile_0077BC04 = 0;
    }

    if (gpCellFile_0077BC08)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC08);
        gpCellFile_0077BC08 = 0;
    }

    if (gpCellFile_0077BC14)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC14);
        gpCellFile_0077BC14 = 0;
    }

    if (gpCellFile_0077BC18)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC18);
        gpCellFile_0077BC18 = 0;
    }

    if (gpCellFile_0077BC1C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC1C);
        gpCellFile_0077BC1C = 0;
    }

    if (gpCellFile_0077BC20)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC20);
        gpCellFile_0077BC20 = 0;
    }

    if (gpCellFile_0077BC28)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC28);
        gpCellFile_0077BC28 = 0;
    }

    if (gpCellFile_0077BC2C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC2C);
        gpCellFile_0077BC2C = 0;
    }

    if (gpCellFile_0077BC30)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC30);
        gpCellFile_0077BC30 = 0;
    }

    if (gpCellFile_0077BC34)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC34);
        gpCellFile_0077BC34 = 0;
    }

    if (gpCellFile_0077BC38)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC38);
        gpCellFile_0077BC38 = 0;
    }

    if (gpCellFile_0077BC3C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC3C);
        gpCellFile_0077BC3C = 0;
    }

    if (gpCellFile_0077BC50)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC50);
        gpCellFile_0077BC50 = 0;
    }

    if (gpCellFile_0077BC5C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC5C);
        gpCellFile_0077BC5C = 0;
    }

    if (gpCellFile_0077BC60)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC60);
        gpCellFile_0077BC60 = 0;
    }

    if (gpCellFile_0077BCC0)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCC0);
        gpCellFile_0077BCC0 = 0;
    }

    if (gpCellFile_0077BCC4)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCC4);
        gpCellFile_0077BCC4 = 0;
    }

    if (gpCellFile_0077BCC8)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCC8);
        gpCellFile_0077BCC8 = 0;
    }

    if (gpCellFile_0077BCCC)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCCC);
        gpCellFile_0077BCCC = 0;
    }

    if (gpCellFile_0077BCD0)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCD0);
        gpCellFile_0077BCD0 = 0;
    }

    if (gpCellFile_0077BC64)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC64);
        gpCellFile_0077BC64 = 0;
    }

    if (gpCellFile_0077BCD4)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCD4);
        gpCellFile_0077BCD4 = 0;
    }

    if (gpCellFile_0077BCD8)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCD8);
        gpCellFile_0077BCD8 = 0;
    }

    if (gpCellFile_0077BD0C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD0C);
        gpCellFile_0077BD0C = 0;
    }

    if (gpCellFile_0077BD10)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD10);
        gpCellFile_0077BD10 = 0;
    }

    if (gpCellFile_0077BC24)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC24);
        gpCellFile_0077BC24 = 0;
    }

    if (gpCellFile_0077BD18)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD18);
        gpCellFile_0077BD18 = 0;
    }

    if (gpCellFile_0077BD2C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD2C);
        gpCellFile_0077BD2C = 0;
    }

    if (gpCellFile_0077BD30)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD30);
        gpCellFile_0077BD30 = 0;
    }

    if (gpCellFile_0077BD48)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD48);
        gpCellFile_0077BD48 = 0;
    }

    if (gpCellFile_0077BD4C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD4C);
        gpCellFile_0077BD4C = 0;
    }

    if (gpCellFile_0077BC54)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC54);
        gpCellFile_0077BC54 = 0;
    }

    if (gpCellFile_0077BC58)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC58);
        gpCellFile_0077BC58 = 0;
    }

    if (gpCellFile_0077BD34)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD34);
        gpCellFile_0077BD34 = 0;
    }

    if (gpCellFile_0077BD38)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD38);
        gpCellFile_0077BD38 = 0;
    }

    if (gpCellFile_0077BD3C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD3C);
        gpCellFile_0077BD3C = 0;
    }

    if (gpCellFile_0077BD44)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD44);
        gpCellFile_0077BD44 = 0;
    }

    if (gpCellFile_0077BD40)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BD40);
        gpCellFile_0077BD40 = 0;
    }

    if (gpCellFile_0077BC68)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC68);
        gpCellFile_0077BC68 = 0;
    }

    if (gpCellFile_0077BC6C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC6C);
        gpCellFile_0077BC68 = 0;
    }

    if (gpCellFile_0077BC70)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC70);
        gpCellFile_0077BC70 = 0;
    }

    if (gpCellFile_0077BC74)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC74);
        gpCellFile_0077BC74 = 0;
    }

    if (gpCellFile_0077BC78)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC78);
        gpCellFile_0077BC78 = 0;
    }

    if (gpCellFile_0077BC7C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC7C);
        gpCellFile_0077BC7C = 0;
    }

    if (gpCellFile_0077BC80)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC80);
        gpCellFile_0077BC80 = 0;
    }

    if (gpCellFile_0077BC84)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC84);
        gpCellFile_0077BC84 = 0;
    }

    if (gpCellFile_0077BC88)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC88);
        gpCellFile_0077BC88 = 0;
    }

    if (gpCellFile_0077BC8C)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC8C);
        gpCellFile_0077BC8C = 0;
    }

    if (gpCellFile_0077BC90)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC90);
        gpCellFile_0077BC90 = 0;
    }

    if (gpCellFile_0077BC94)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC94);
        gpCellFile_0077BC94 = 0;
    }

    if (gpCellFile_0077BCB8)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCB8);
        gpCellFile_0077BCB8 = 0;
    }

    if (gpCellFile_0077BCBC)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BCBC);
        gpCellFile_0077BCBC = 0;
    }
}

int gnFlag_0077BD60; // 0x0077BD60

// 0x0043DA00
int __stdcall sub_0043DA00_ScrollPageDown(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(10);
    return 1;
}

// 0x0043DA20
int __stdcall sub_0043DA20_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(-1);
    return 1;
}

// 0x0043DBA0
int __stdcall sub_0043DBA0_ClearSelection(int nArg1, int nArg2, int nArg3)
{
    sub_004FB9D0_Select(gpControl_0077BCFC, -1);
    return 1;
}

// 0x0043DBC0
int __stdcall sub_0043DBC0_OnWaitTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (!WaitForSingleObject((void*)sub_00449AC0(), 0) || gnFlag_0077BD60)
        sub_004F9190();
    return 1;
}

// 0x0043DBF0
int __stdcall sub_0043DBF0_OnReceiveTick(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00449B70_Receive();
    if (sub_00449C30() || !sub_00449B30_QueryAddress() || gnFlag_0077BD60)
    {
        sub_00449C40_SetValue(0);
        sub_004F9190();
    }
    return 1;
}
