#include "D2Client.h"

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};
enum { USE_RESULT = 0 };
// 0x00451AB0
void __stdcall sub_00451AB0(SMSGHANDLER_PARAMS* msg)
{
    gdwGlobal_0070F7E0 = msg->wParam != 0;
    msg->bUseResult = USE_RESULT;
}
