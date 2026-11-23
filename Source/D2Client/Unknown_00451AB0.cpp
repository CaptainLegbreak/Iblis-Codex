#include "D2Client.h"
#include "D2StormTypes.h"

enum { USE_RESULT = 0 };
// 0x00451AB0
void __stdcall sub_00451AB0(SMSGHANDLER_PARAMS* msg)
{
// build: symbol ?gbClientAppActive@* 0x0070F7E0
    gbClientAppActive = msg->wParam != 0;
    msg->bReturn = USE_RESULT;
}
