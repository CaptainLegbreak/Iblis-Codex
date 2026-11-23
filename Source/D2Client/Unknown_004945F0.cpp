#include "D2Client.h"
#include "D2StormTypes.h"

void __cdecl sub_00499E30();
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
void __fastcall UI_SetUIVar(int nUIVar, int nState, int nArg); // 0x00455F20
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern int gbHelpUiOpened;

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
extern int gnGlobal_00722310; // 0x00722310
extern int gbHelpButtonVisible; // 0x007BEF08

unsigned char gnHelpShadeColor; // 0x007BEEF8

// 0x004945F0
void __cdecl sub_00494EB0()
{
    sub_00499E30();
    AUTOMAP_DrawFramedBox(0, 0, gnScreenWidth, gnScreenHeight - 0x31, gnHelpShadeColor, 1);
}

void __cdecl sub_00494FC0()
{
    if (gbHelpUiOpened)
    {
        UI_SetUIVar(0x15, 1, 0);
        gbHelpUiOpened = 0;
    }
}

static int gbHelpButtonPressed; // 0x007BEF04

// 0x004952B0
void __stdcall sub_004952B0_ButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbHelpButtonVisible)
    {
        return;
    }
    const int nBottom = gnScreenHeight - 0xA0;
    const int nLeft = gnScreenWidth - 0x4B;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x23 && nY >= nBottom - 0x24 && nY <= nBottom)
    {
        gbHelpButtonPressed = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00495320
void __stdcall sub_00495320_ButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbHelpButtonVisible)
    {
        return;
    }
    const int nBottom = gnScreenHeight - 0xA0;
    const int nLeft = gnScreenWidth - 0x4B;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x23 && nY >= nBottom - 0x24 && nY <= nBottom)
    {
        UI_SetUIVar(0x22, 1, 0);
        UI_SetUIVar(0x21, 2, 0);
        gnGlobal_00722310 = 1;
        SRegSaveValue("Diablo II", "Help Menu", 1, 1);
        gbHelpButtonPressed = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

int gbHelpUiOpened; // 0x007BEF00

// 0x004967A0
void __stdcall sub_004967A0_KeyCloseHelp(SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(0x21, 1, 0);
    if (gbHelpUiOpened)
    {
        UI_SetUIVar(0x15, 1, 0);
        gbHelpUiOpened = 0;
    }
}
