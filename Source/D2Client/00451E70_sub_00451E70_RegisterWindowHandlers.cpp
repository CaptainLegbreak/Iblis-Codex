struct SMSGHANDLER_PARAMS;
typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    SMSGHANDLER pfnHandler;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2MsgHandlerEntryStrc gMsgHandlers_0070F7E4[4];                                                      // 0x0070F7E4

int __stdcall sub_00420320_RegisterHandlers(void* pContext);                                                // 0x00420320
int __stdcall SMsgPushRegisterState(int nType);                                                             // 0x00420360
void __fastcall sub_00451D10_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler);  // 0x00451D10
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

// 0x00451E70
int __fastcall sub_00451E70_RegisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x178);
    sub_00451DB0_RegisterMsgHandlers((int)hWnd, gMsgHandlers_0070F7E4, 4);
    SMsgPushRegisterState((int)hWnd);
    return 1;
}

// 0x00451EB0
void __fastcall sub_00451EB0_UnregisterWindowHandlers(void* hWnd)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < 4; ++i)
    {
        sub_00451D10_UnregisterMsgHandler(hWnd, gMsgHandlers_0070F7E4[i].nType, gMsgHandlers_0070F7E4[i].nId, gMsgHandlers_0070F7E4[i].pfnHandler);
    }
    sub_00420320_RegisterHandlers(hWnd);
}

#include "gen/data/Source/D2Client/00451E70_sub_00451E70_RegisterWindowHandlers.inc"
