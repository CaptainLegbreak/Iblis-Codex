#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"

struct SGAMEDATA;
struct D2MsgHandlerEntryStrc;
struct D2PanelAnimEntryStrc;

extern int gdwGlobal_007A6A94; // 0x007A6A94
extern int gdwGlobal_007A6A98; // 0x007A6A98
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

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
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
extern D2MsgHandlerEntryStrc gaCursorMsgHandlers_00711FEC[]; // 0x00711FEC
extern D2PanelAnimEntryStrc gaPanelAnim_00712020[]; // 0x00712020
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A6B08; // 0x007A6B08

extern int gnGlobal_007A6AAC; // 0x007A6AAC
extern int gnGlobal_007A6AB0; // 0x007A6AB0
extern int gnGlobal_007A6AB4; // 0x007A6AB4
extern int gnGlobal_007A6ADC; // 0x007A6ADC
extern int gnGlobal_007A6AE0; // 0x007A6AE0
extern int gnGlobal_007A6AE8; // 0x007A6AE8
extern int gnGlobal_007A6AF0; // 0x007A6AF0
extern void* gpCursorCells_007A6AC0[NUM_CURSOR_CELLS]; // 0x007A6AC0
extern unsigned short gwGlobal_007A6AE4; // 0x007A6AE4

#define NUM_CURSOR_MSG_HANDLERS 3
void __fastcall sub_00478A00(void* pCel); // 0x00478A00

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

// 0x004680B0
int __fastcall sub_004680B0_InitCursor(int nArg)
{
    char szPath[0x50];
    gnGlobal_007A6AB4 = nArg;
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaCursorMsgHandlers_00711FEC, 3);
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        wsprintfA(szPath, "%s\\UI\\CURSOR\\%s", szDataGlobal_006D4118, gaPanelAnim_00712020[i].f_8);
        gpCursorCells_007A6AC0[i] = sub_004788B0(szPath, 0);
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
void __cdecl sub_00468170_ShutdownCursor()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaCursorMsgHandlers_00711FEC, NUM_CURSOR_MSG_HANDLERS);
    gnGlobal_007A6B08 = 0;
    for (int i = 0; i < NUM_CURSOR_CELLS; ++i)
    {
        if (gpCursorCells_007A6AC0[i])
        {
            sub_00478A00(gpCursorCells_007A6AC0[i]);
            gpCursorCells_007A6AC0[i] = 0;
        }
    }
}

