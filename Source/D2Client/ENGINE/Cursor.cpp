// Built /GS-: the buffer in 0x004680B0 has no security cookie.
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2CelContext.h"
#include "D2Constants.h"

struct D2MsgHandlerEntryStrc;

struct D2PanelAnimEntryStrc;

enum D2C_W04CursorConstants
{
    NUM_CURSOR_CELLS = 7,
};

struct D2PanelAnimEntryStrc
{
    void* pData;
    void (__cdecl* pfnDraw)();
    const char* f_8;
    char unk0x0C[0x10];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __cdecl sub_004F59A0(); // 0x004F59A0

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern D2MsgHandlerEntryStrc gaCursorMsgHandlers_00711FEC[]; // 0x00711FEC

extern D2PanelAnimEntryStrc gaPanelAnim_00712020[]; // 0x00712020

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

int gnGlobal_007A6B08;                                                                                      // 0x007A6B08

static int gnGlobal_007A6AAC;                                                                               // 0x007A6AAC

static int gnGlobal_007A6AB0;                                                                               // 0x007A6AB0

static int gnGlobal_007A6AB4;                                                                               // 0x007A6AB4

static int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC

static int gnGlobal_007A6AE0;                                                                               // 0x007A6AE0

extern int gnGlobal_007A6AE8; // 0x007A6AE8

static int gnGlobal_007A6AF0;                                                                               // 0x007A6AF0

static void* gpCursorCells_007A6AC0[NUM_CURSOR_CELLS];                                                      // 0x007A6AC0

extern unsigned short gwGlobal_007A6AE4; // 0x007A6AE4

#define NUM_CURSOR_MSG_HANDLERS 3

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

struct D2CelFileStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int gnValue_007A6AAC;        // 0x007A6AAC

int gnValue_007A6AB0;        // 0x007A6AB0

int gnValue_007A6AB4;        // 0x007A6AB4

D2CelFileStrc* gpCellFile_007A6AD8;        // 0x007A6AD8

int gnFrame_007A6AE0;        // 0x007A6AE0

struct D2UnitStrc;


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __cdecl sub_00468310_UpdateCursor();                                                                // 0x00468310

int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0

unsigned int __stdcall CelGetWidth(D2CelStrc* pCel);                                                        // 0x006018C0

unsigned int __stdcall CelGetHeight(D2CelStrc* pCel);                                                       // 0x006018F0

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

static int gnGlobal_007A6AA8;                                                                               // 0x007A6AA8

static int gnGlobal_007A6AB8;                                                                               // 0x007A6AB8

static D2UnitStrc* gpCursorItem_007A6ABC;                                                                   // 0x007A6ABC

// 0x004680B0
int __fastcall CURSOR_InitCursor(int nArg)
{
    char szPath[0x50];
    gnGlobal_007A6AB4 = nArg;
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaCursorMsgHandlers_00711FEC, 3);
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        wsprintfA(szPath, "%s\\UI\\CURSOR\\%s", szDataGlobal_006D4118, gaPanelAnim_00712020[i].f_8);
        gpCursorCells_007A6AC0[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    gnGlobal_007A6B08 = 1;
    gnGlobal_007A6AF0 = 1;
    gnGlobal_007A6ADC = 5;
    gnGlobal_007A6AE0 = 0;
    gwGlobal_007A6AE4 = 0;
    gnGlobal_007A6AE8 = GetTickCount();
    gnGlobal_007A6AB0 = gnGlobal_0071146C / 2;
    gnGlobal_007A6AAC = gnGlobal_00711470 / 2;
    return 1;
}

// 0x00468170
void __cdecl CURSOR_ShutdownCursor()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaCursorMsgHandlers_00711FEC, NUM_CURSOR_MSG_HANDLERS);
    gnGlobal_007A6B08 = 0;
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        if (gpCursorCells_007A6AC0[i])
        {
            ARCHIVE_FreeClientCellFile(gpCursorCells_007A6AC0[i]);
            gpCursorCells_007A6AC0[i] = 0;
        }
    }
}

// 0x004683C0
void __cdecl CURSOR_DrawDefaultCursor()
{
    int nX = gnGlobal_007A6AB0 + gnGlobal_007A6AB4;
    int nY = gnGlobal_007A6AAC;
    if (nY < 0)
    {
        nY = 0;
    }
    else if (nY > gnGlobal_00711470 - 1)
    {
        nY = gnGlobal_00711470 - 1;
    }
    if (nX < gnGlobal_007A6AB4)
    {
        nX = gnGlobal_007A6AB4;
    }
    else if (nX > gnGlobal_0071146C - gnGlobal_007A6AB4 - 1)
    {
        nX = gnGlobal_0071146C - gnGlobal_007A6AB4 - 1;
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCursorCells_007A6AC0[gnGlobal_007A6ADC];
    tContext.nDirection = 0;
    tContext.nFrame = gnGlobal_007A6AE0 >> 8;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
    sub_00468310_UpdateCursor();
}

// 0x00468460
void __cdecl CURSOR_DrawCursorCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007A6AD8;
    tContext.nFrame = gnFrame_007A6AE0;
    const int nX = gnValue_007A6AB0 + gnValue_007A6AB4;
    const int nY = gnValue_007A6AAC + 0x21;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x004684C0
void __cdecl CURSOR_DrawCursor()
{
    if (!gnGlobal_007A6B08)
    {
        return;
    }
    D2UnitStrc* pItem = gpCursorItem_007A6ABC;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && gnGlobal_007A6AF0 < 6 && gnGlobal_007A6AF0 < 8)
    {
        D2CelContextStrc tContext;
        int nOut;
        memset(&tContext, 0, sizeof(tContext));
        if (GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2_ASSERT(tContext.pCel, 0x27D);
            GFX_DrawItemCel(gpCursorItem_007A6ABC, gnGlobal_007A6AB0 - CelGetWidth(tContext.pCel) / 2 + gnGlobal_007A6AB4,
                gnGlobal_007A6AAC - CelGetHeight(tContext.pCel) / 2);
        }
    }
    else
    {
        gaPanelAnim_00712020[gnGlobal_007A6ADC].pfnDraw();
    }
}

// 0x004685C0
void __cdecl CURSOR_PaintCursorItem()
{
    if (!gnGlobal_007A6B08)
    {
        return;
    }
    D2UnitStrc* pItem = gpCursorItem_007A6ABC;
    D2CelContextStrc tContext;
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        int nOut;
        memset(&tContext, 0, sizeof(tContext));
        if (GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2_ASSERT(tContext.pCel, 0x2BB);
            GFX_DrawItemCel(gpCursorItem_007A6ABC, gnGlobal_007A6AB0 - CelGetWidth(tContext.pCel) / 2 + gnGlobal_007A6AB4,
                gnGlobal_007A6AAC - CelGetHeight(tContext.pCel) / 2);
        }
    }
    else
    {
        int nType = gnGlobal_007A6ADC;
        if (nType < NUM_CURSOR_CELLS)
        {
            int nX = gnGlobal_007A6AB4 + gnGlobal_007A6AB0;
            int nY = gnGlobal_007A6AAC;
            if (nY < 0)
            {
                nY = 0;
            }
            else if (nY > gnGlobal_007A6AA8 - 1)
            {
                nY = gnGlobal_007A6AA8 - 1;
            }
            if (nX < gnGlobal_007A6AB4)
            {
                nX = gnGlobal_007A6AB4;
            }
            else if (nX > gnGlobal_007A6AB8 - gnGlobal_007A6AB4 - 1)
            {
                nX = gnGlobal_007A6AB8 - gnGlobal_007A6AB4 - 1;
            }
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpCursorCells_007A6AC0[nType];
            tContext.nDirection = 0;
            tContext.nFrame = gnGlobal_007A6AE0 >> 8;
            sub_004F6480(&tContext, nX, nY, -1, 5, 0);
            sub_00468310_UpdateCursor();
        }
    }
}
