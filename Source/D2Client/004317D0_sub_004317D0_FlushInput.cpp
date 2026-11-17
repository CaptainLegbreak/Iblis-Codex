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

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwTime;
    int f_14;
    int nPointY;
};

struct D2CoordPairStrc
{
    int nX;
    int nY;
};

extern "C" int __cdecl abs(int nValue);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetCursorPos(D2CoordPairStrc* pPoint);                           // 0x006CC48C

extern int gnLastClickX_00779998;                                                                           // 0x00779998
extern int gnLastClickY_0077999C;                                                                           // 0x0077999C
extern int gnLastClickTick_007799A0;                                                                        // 0x007799A0

// 0x004317D0
void __cdecl sub_004317D0_FlushInput()
{
    D2WinMsgStrc tMsg;
    while (PeekMessageA(&tMsg, 0, 0, 0, 1))
    {
        switch (tMsg.uMessage)
        {
        case 0x12:
        case 0x102:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
        case 0x207:
        case 0x208:
            break;
        default:
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
            break;
        }
    }
}

// build: context sub_00431A60_IsDoubleClick
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
    if (abs(tPoint.nX - gnLastClickX_00779998) + abs(tPoint.nY - gnLastClickY_0077999C) > 4)
        bResult = 0;
    gnLastClickX_00779998 = tPoint.nX;
    gnLastClickTick_007799A0 = nTick;
    gnLastClickY_0077999C = tPoint.nY;
    return bResult;
}
