enum D2C_W04CursorConstants
{
    NUM_CURSOR_CELLS = 7,
};

struct D2CelFileStrc;

struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

struct D2PanelAnimEntryStrc
{
    void* pData;
    void (__cdecl* pfnDraw)();
    const char* f_8;
    char unk0x0C[0x10];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...);          // 0x006CC468
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType);                              // 0x004788B0

extern D2MsgHandlerEntryStrc gaCursorMsgHandlers_00711FEC[];                                                // 0x00711FEC
extern D2PanelAnimEntryStrc gaPanelAnim_00712020[];                                                         // 0x00712020
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A6B08;                                                                               // 0x007A6B08
static int gnGlobal_007A6AAC;                                                                               // 0x007A6AAC
static int gnGlobal_007A6AB0;                                                                               // 0x007A6AB0
static int gnGlobal_007A6AB4;                                                                               // 0x007A6AB4
static void* gpCursorCells_007A6AC0[NUM_CURSOR_CELLS];                                                      // 0x007A6AC0
static int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
static int gnGlobal_007A6AE0;                                                                               // 0x007A6AE0
static unsigned short gwGlobal_007A6AE4;                                                                    // 0x007A6AE4
static int gnGlobal_007A6AE8;                                                                               // 0x007A6AE8
static int gnGlobal_007A6AF0;                                                                               // 0x007A6AF0

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

int __cdecl sub_W04_EmitReadStatics()
{
    return gnGlobal_007A6AAC + gnGlobal_007A6AB0 + gnGlobal_007A6AB4 + gnGlobal_007A6ADC + gnGlobal_007A6AE0 + gwGlobal_007A6AE4 + gnGlobal_007A6AE8 + gnGlobal_007A6AF0 + (gpCursorCells_007A6AC0[0] ? 1 : 0);
}

#include "gen/data/Source/D2Client/004680B0_sub_004680B0_InitCursor.inc"
