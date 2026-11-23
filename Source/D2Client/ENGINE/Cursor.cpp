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

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern D2MsgHandlerEntryStrc gaCursorMsgHandlers[]; // 0x00711FEC

extern D2PanelAnimEntryStrc gaPanelAnim[]; // 0x00712020

extern int gnScreenWidth; // 0x0071146C

extern int gnScreenHeight; // 0x00711470

int gbCursorVisible;                                                                                      // 0x007A6B08

static int gnCursorY;                                                                               // 0x007A6AAC

static int gnCursorX;                                                                               // 0x007A6AB0

static int gnCursorOffsetX;                                                                               // 0x007A6AB4

static int gnCursorAnim;                                                                               // 0x007A6ADC

static int gnCursorAnimFrame;                                                                               // 0x007A6AE0

extern int gdwLastMouseMoveTick; // 0x007A6AE8

static int gnCursorState;                                                                               // 0x007A6AF0

static void* gapCursorCels[NUM_CURSOR_CELLS];                                                      // 0x007A6AC0

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

D2CelFileStrc* gpCursorCel;        // 0x007A6AD8

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

static int gnCursorMaxY;                                                                               // 0x007A6AA8

static int gnCursorMaxX;                                                                               // 0x007A6AB8

static D2UnitStrc* gpCursorItem_007A6ABC;                                                                   // 0x007A6ABC

extern int gpCursorItem; // 0x007A6ABC

// 0x004680B0
int __fastcall CURSOR_InitCursor(int nArg)
{
    char szPath[0x50];
    gnCursorOffsetX = nArg;
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaCursorMsgHandlers, 3);
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
// build: symbol ?gszDataGlobal@* 0x006D4118
        wsprintfA(szPath, "%s\\UI\\CURSOR\\%s", gszDataGlobal, gaPanelAnim[i].f_8);
        gapCursorCels[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    gbCursorVisible = 1;
    gnCursorState = 1;
    gnCursorAnim = 5;
    gnCursorAnimFrame = 0;
    gwGlobal_007A6AE4 = 0;
    gdwLastMouseMoveTick = GetTickCount();
    gnCursorX = gnScreenWidth / 2;
    gnCursorY = gnScreenHeight / 2;
    return 1;
}

// 0x00468170
void __cdecl CURSOR_ShutdownCursor()
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaCursorMsgHandlers, NUM_CURSOR_MSG_HANDLERS);
    gbCursorVisible = 0;
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        if (gapCursorCels[i])
        {
            ARCHIVE_FreeClientCellFile(gapCursorCels[i]);
            gapCursorCels[i] = 0;
        }
    }
}

// 0x004683C0
void __cdecl CURSOR_DrawDefaultCursor()
{
    int nX = gnCursorX + gnCursorOffsetX;
    int nY = gnCursorY;
    if (nY < 0)
    {
        nY = 0;
    }
    else if (nY > gnScreenHeight - 1)
    {
        nY = gnScreenHeight - 1;
    }
    if (nX < gnCursorOffsetX)
    {
        nX = gnCursorOffsetX;
    }
    else if (nX > gnScreenWidth - gnCursorOffsetX - 1)
    {
        nX = gnScreenWidth - gnCursorOffsetX - 1;
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gapCursorCels[gnCursorAnim];
    tContext.nDirection = 0;
    tContext.nFrame = gnCursorAnimFrame >> 8;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
    sub_00468310_UpdateCursor();
}

// 0x00468460
void __cdecl CURSOR_DrawCursorCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCursorCel;
    tContext.nFrame = gnFrame_007A6AE0;
    const int nX = gnValue_007A6AB0 + gnValue_007A6AB4;
    const int nY = gnValue_007A6AAC + 0x21;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x004684C0
void __cdecl CURSOR_DrawCursor()
{
    if (!gbCursorVisible)
    {
        return;
    }
    D2UnitStrc* pItem = gpCursorItem_007A6ABC;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && gnCursorState < 6 && gnCursorState < 8)
    {
        D2CelContextStrc tContext;
        int nOut;
        memset(&tContext, 0, sizeof(tContext));
        if (GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2_ASSERT(tContext.pCel, 0x27D);
            GFX_DrawItemCel(gpCursorItem_007A6ABC, gnCursorX - CelGetWidth(tContext.pCel) / 2 + gnCursorOffsetX,
                gnCursorY - CelGetHeight(tContext.pCel) / 2);
        }
    }
    else
    {
        gaPanelAnim[gnCursorAnim].pfnDraw();
    }
}

// 0x004685C0
void __cdecl CURSOR_PaintCursorItem()
{
    if (!gbCursorVisible)
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
            GFX_DrawItemCel(gpCursorItem_007A6ABC, gnCursorX - CelGetWidth(tContext.pCel) / 2 + gnCursorOffsetX,
                gnCursorY - CelGetHeight(tContext.pCel) / 2);
        }
    }
    else
    {
        int nType = gnCursorAnim;
        if (nType < NUM_CURSOR_CELLS)
        {
            int nX = gnCursorOffsetX + gnCursorX;
            int nY = gnCursorY;
            if (nY < 0)
            {
                nY = 0;
            }
            else if (nY > gnCursorMaxY - 1)
            {
                nY = gnCursorMaxY - 1;
            }
            if (nX < gnCursorOffsetX)
            {
                nX = gnCursorOffsetX;
            }
            else if (nX > gnCursorMaxX - gnCursorOffsetX - 1)
            {
                nX = gnCursorMaxX - gnCursorOffsetX - 1;
            }
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gapCursorCels[nType];
            tContext.nDirection = 0;
            tContext.nFrame = gnCursorAnimFrame >> 8;
            sub_004F6480(&tContext, nX, nY, -1, 5, 0);
            sub_00468310_UpdateCursor();
        }
    }
}

// 0x004680A0
int __cdecl CURSOR_GetCursorItem()
{
    return gpCursorItem;
}
