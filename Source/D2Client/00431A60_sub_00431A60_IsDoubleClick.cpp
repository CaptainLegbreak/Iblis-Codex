struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2CoordPairStrc
{
    int nX;
    int nY;
};

extern "C" int __cdecl abs(int nValue);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall GetCursorPos(D2CoordPairStrc* pPoint);                           // 0x006CC48C
int gnLastClickX_00779998;                                                                                  // 0x00779998
int gnLastClickY_0077999C;                                                                                  // 0x0077999C
int gnLastClickTick_007799A0;                                                                               // 0x007799A0

// 0x00431A60
int __fastcall sub_00431A60_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg)
{
    int bResult = 1;
    if (pMsg->uMessage != 0x201)
        bResult = 0;
    int nTick = GetTickCount();
    if (nTick - gnLastClickTick_007799A0 > 300)
        bResult = 0;
    D2CoordPairStrc tPoint;
    GetCursorPos(&tPoint);
    if (abs(tPoint.nY - gnLastClickY_0077999C) + abs(tPoint.nX - gnLastClickX_00779998) > 4)
        bResult = 0;
    gnLastClickY_0077999C = tPoint.nY;
    gnLastClickTick_007799A0 = nTick;
    gnLastClickX_00779998 = tPoint.nX;
    return bResult;
}
