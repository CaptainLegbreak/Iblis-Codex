#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RectStrc;
struct D2MsgHandlerEntryStrc;
struct D2DialogWidgetNodeStrc;

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

struct D2DialogWidgetNodeStrc
{
    void* f_0;
    D2DialogWidgetNodeStrc* pNext;
};

struct D2ClientDialogStrc
{
    unsigned long dwTick;
    int unk0x04;
    void* pCelFile;
    int unk0x0C;
    char unk0x10[0xAF8];
    D2DialogWidgetNodeStrc* pWidgets;
    D2ClientDialogStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_004F59A0(); // 0x004F59A0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
void __fastcall sub_004898D0(int nState); // 0x004898D0
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273E4[]; // 0x007273E4
extern D2MsgHandlerEntryStrc gaMsgHandlers_007273F0[]; // 0x007273F0
int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0
extern int gnGlobal_007273F4; // 0x007273F4
extern int gnGlobal_00727400; // 0x00727400

static int gnGlobal_007C0E4C; // 0x007C0E4C

static D2ClientDialogStrc* gpGlobal_007C0E54; // 0x007C0E54

static int gnGlobal_007C0E58; // 0x007C0E58

static int gnGlobal_007C0E5C; // 0x007C0E5C

// 0x004B7B40
void __cdecl sub_004B7B40()
{
    gnGlobal_007C0E58 = 0;
}

// 0x004B7B50
void __cdecl sub_004B7B50()
{
    if (gnGlobal_007C0E58)
    {
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_007273F0, 0xE);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_007273E4, 1);
        gnGlobal_007C0E4C -= 1;
    }

    D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
    while (pDialog)
    {
        D2ClientDialogStrc* pNext = pDialog->pNext;
        FOG_Free(pDialog, ".\\UI\\dialog.cpp", 0x333, 0);
        pDialog = pNext;
    }

    gpGlobal_007C0E54 = 0;
}

// 0x004B7C00
void __fastcall sub_004B7C00_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC)
{
    D2_ASSERT(pDialog, 0x355);
    D2DialogWidgetNodeStrc* pOld = pDialog->pWidgets;
    pDialog->pWidgets = (D2DialogWidgetNodeStrc*)FOG_Alloc(sizeof(D2DialogWidgetNodeStrc), ".\\UI\\dialog.cpp", 0x359, 0);
    pDialog->pWidgets->pNext = pOld;
    pDialog->pWidgets->f_0 = pWidget;
}

// 0x004B8020
void __fastcall sub_004B8020(void* pRes)
{
    gnGlobal_007C0E5C -= 1;
    if (gnGlobal_007C0E5C == 0)
    {
        sub_004545C0(1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_007273F0, 0xE);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_007273E4, 1);
        sub_004898D0(1);
        sub_00467430(0);
        gnGlobal_007C0E58 = 0;
        D2ClientDialogStrc* pDialog = gpGlobal_007C0E54;
        D2DialogWidgetNodeStrc* pNode = pDialog->pWidgets;
        while (pNode)
        {
            D2DialogWidgetNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, ".\\UI\\dialog.cpp", 0x425, 0);
            pNode = pNext;
        }

        if (pDialog->unk0x0C && pDialog->pCelFile)
        {
            sub_00478A00(pDialog->pCelFile);
        }

        D2ClientDialogStrc* pNext = pDialog->pNext;
        FOG_Free(pDialog, ".\\UI\\dialog.cpp", 0x430, 0);
        gpGlobal_007C0E54 = pNext;
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x436);
        exit(-1);
    }
}

#include "gen/data/Source/D2Client/UI/dialog_004B7B40.inc"

// 0x004B7C60
void __cdecl sub_004B7C60()
{
    if (sub_00469D90(0x26, 1))
    {
        unsigned short nValue = sub_00469AA0(0x26, 1);
        if (nValue != 0xFFFF && nValue <= 0xDF)
        {
            gnGlobal_007273F4 = nValue;
        }
    }
    if (sub_00469D90(0x26, 0))
    {
        unsigned short nValue = sub_00469AA0(0x26, 0);
        if (nValue != 0xFFFF && nValue <= 0xDF)
        {
            gnGlobal_00727400 = nValue;
        }
    }
}
