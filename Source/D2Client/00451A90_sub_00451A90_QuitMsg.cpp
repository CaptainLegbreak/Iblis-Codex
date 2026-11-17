extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;

struct Unicode
{
    unsigned short wChar;
};

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

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

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

struct D2UnitFlagsStrc
{
    char unk0x00[0xC8];
    unsigned int dwFlagEx;
};

struct D2GSPacketSrv0C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char unk0x06;
    unsigned char nHitClass;
    unsigned char nLife;
};

struct D2GSPacketSrv0E
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08[4];
};

struct D2GSPacketSrv0F
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nFlags;
    unsigned char nDestPosX[2];
    unsigned char nDestPosY[2];
    unsigned char unk0x0B;
    unsigned char nCurrentPosX[2];
    unsigned char nCurrentPosY[2];
};

struct D2GSPacketSrv17
{
    unsigned char nHeader;
    unsigned char unk0x01[5];
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08[2];
    unsigned char unk0x0A[2];
};

struct D2GSPacketSrv4C
{
    unsigned char nHeader;
    unsigned char unk0x01[5];
    unsigned char unk0x06[2];
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A[4];
};

struct D2GSPacketSrv4D
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02[4];
    unsigned char unk0x06[4];
    unsigned char unk0x0A;
    unsigned char unk0x0B[2];
    unsigned char unk0x0D[2];
};

struct D2GSPacketSrv67
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char nPathType;
    unsigned char nVelocity[2];
    unsigned char unk0x0F;
};

struct D2GSPacketSrv68
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B[4];
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char nPathType;
    unsigned char nVelocity[2];
    unsigned char unk0x14;
};

struct D2GSPacketSrv69
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06[2];
    unsigned char unk0x08[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
};

struct D2GSPacketSrv6A
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nTargetUnitType;
    unsigned char nTargetUnitGuid[4];
    unsigned char nDirection;
};

struct D2GSPacketSrv6B
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06[2];
    unsigned char unk0x08[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C[2];
    unsigned char unk0x0E[2];
};

struct D2GSPacketSrv6C
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07[4];
    unsigned char unk0x0B;
    unsigned char unk0x0C[2];
    unsigned char unk0x0E[2];
};

struct D2ClientPacket7Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
    unsigned char nValue0;
    unsigned char nValue1;
};

struct D2ClientPacket6Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
};

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);                                // 0x006CC460
extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode);                             // 0x006CC4A4
extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC488
extern "C" __declspec(dllimport) int __stdcall SendMessageA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC49C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
extern "C" __declspec(dllimport) int __stdcall TranslateAcceleratorA(void* hWnd, void* hAccTable, D2WinMsgStrc* pMsg); // 0x006CC4A8
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned int nMilliseconds);                          // 0x006CC258
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840

void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
void __fastcall sub_004FB130_SetActiveState(int bActive);                                                   // 0x004FB130
int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
void __cdecl sub_0044C060_Refresh();                                                                        // 0x0044C060
void __cdecl sub_00466FF0();                                                                                // 0x00466FF0
void __cdecl sub_004A01E0_ClearListFlags();                                                                 // 0x004A01E0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __stdcall SMsgRegisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler);                             // 0x00420BF0
int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler);                             // 0x00420C10
int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler);                               // 0x00420C30
int __stdcall SMsgRegisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler);                             // 0x00420C50
int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler);                           // 0x00420C70
int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler);                           // 0x00420C90
int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler);                             // 0x00420CB0
int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler);                           // 0x00420CD0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern);             // 0x00526940
void __stdcall sub_005022F0_ShowPopUpText(const Unicode* wszText, int nX, int nY, int nArg);                 // 0x005022F0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall sub_004B1240_UsePacket7(D2ClientPacket7Strc* pPacket);                                      // 0x004B1240
void __fastcall sub_0049F8C0_UsePacket6(D2ClientPacket6Strc* pPacket);                                      // 0x0049F8C0

extern int gdwGlobal_0070F7E0;                                                                              // 0x0070F7E0
extern int gdwGlobal_007A0664;                                                                              // 0x007A0664
extern int gdwGlobal_007A065C;                                                                              // 0x007A065C
extern int gdwGlobal_0070F234;                                                                              // 0x0070F234
extern int gdwGlobal_0070F2BC;                                                                              // 0x0070F2BC
extern int gdwGlobal_007A0654;                                                                              // 0x007A0654
extern int gdwGlobal_007A0670;                                                                              // 0x007A0670
extern int gdwGlobal_007A0658;                                                                              // 0x007A0658
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern void* gxGlobal_007A0708;                                                                             // 0x007A0708
extern Unicode gxGlobal_007A2C80[80];                                                                       // 0x007A2C80
int gdwGlobal_007A2D20;                                                                                     // 0x007A2D20
int gdwGlobal_007A2D24;                                                                                     // 0x007A2D24
int gdwGlobal_007A2D28;                                                                                     // 0x007A2D28

// build: context sub_0044C5E0_ActivateMsg
void __stdcall sub_0044C5E0_ActivateMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F7E0 = pMsg->wParam;
    if (pMsg->wParam)
    {
        sub_00455F20(0xD, 1, 0);
        gdwGlobal_007A0664 = 0;
        sub_00466FE0();
        sub_004FB130_SetActiveState(0);
        pMsg->bUseResult = 0;
        return;
    }

    if (sub_00469D90(0x22, 1) && !(GetAsyncKeyState(sub_00469AA0(0x22, 1)) & 0x8000))
    {
        gdwGlobal_007A065C = 0;
    }

    if (gdwGlobal_0070F234 != 0x10)
    {
        sub_0044C060_Refresh();
    }

    if (gdwGlobal_0070F2BC != 0x10)
    {
        gdwGlobal_0070F2BC = 0x10;
        gdwGlobal_007A0654 = 0;
        gdwGlobal_007A0670 = 1;
        gdwGlobal_007A0658 = 0;
        sub_00466FF0();
    }

    pMsg->bUseResult = 0;
}

// 0x00451A90
void __stdcall sub_00451A90_QuitMsg(SMSGHANDLER_PARAMS* pMsg)
{
    PostQuitMessage(0);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
}

// 0x00451AD0
void __stdcall sub_00451AD0_DefWindowProcMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bUseResult = 1;
    pMsg->lResult = DefWindowProcA(pMsg->hWnd, pMsg->uMessage, pMsg->wParam, pMsg->lParam);
}

// 0x00451B00
void __stdcall sub_00451B00_CloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
}

// 0x00451BB0
int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int))
{
    int nCount = 0;
    int bContinue = 1;
    int nResult;
    D2WinMsgStrc msg;

    while (bContinue)
    {
        if (PeekMessageA(&msg, 0, 0, 0, 0))
        {
            bContinue = GetMessageA(&msg, 0, 0, 0);
            if (bContinue && gxGlobal_007A0708)
            {
                TranslateAcceleratorA((void*)sub_004F59A0(), gxGlobal_007A0708, &msg);
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
        else
        {
            if (pfnIdle)
            {
                nResult = pfnIdle(nCount++);
                if (nResult)
                {
                    break;
                }
            }

            if (!gdwGlobal_0070F7E0 && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 8)
            {
                Sleep(10);
            }
        }
    }

    return bContinue ? nResult : 1;
}

// 0x00451C70
void __fastcall sub_00451C70_RegisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler)
{
    D2_ASSERT(hWnd, 0x110);

    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x114);
        SMsgRegisterMessage(hWnd, nId, pfnHandler);
        return;
    case 1:
        SMsgRegisterCommand(hWnd, nId, pfnHandler);
        return;
    case 2:
        SMsgRegisterKeyUp(hWnd, nId, pfnHandler);
        return;
    case 3:
        SMsgRegisterKeyDown(hWnd, nId, pfnHandler);
        return;
    }
}

// 0x00451D10
void __fastcall sub_00451D10_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler)
{
    D2_ASSERT(hWnd, 0x131);

    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x135);
        SMsgUnregisterMessage(hWnd, nId, pfnHandler);
        return;
    case 1:
        SMsgUnregisterCommand(hWnd, nId, pfnHandler);
        return;
    case 2:
        SMsgUnregisterKeyUp(hWnd, nId, pfnHandler);
        return;
    case 3:
        SMsgUnregisterKeyDown(hWnd, nId, pfnHandler);
        return;
    }
}

// 0x00452090
void __stdcall sub_00452090_ResetMsg(SMSGHANDLER_PARAMS* pMsg)
{
    sub_004A01E0_ClearListFlags();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00452300
Unicode* __fastcall sub_00452300_StripStringAndNextChar(Unicode* pString)
{
    D2_ASSERT(sub_00526800(pString) < 500, 0x37F);

    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pPattern);
    while (pFound && pFound[nLength].wChar)
    {
        memmove(pFound, &pFound[nLength + 1], sizeof(Unicode) * (sub_00526800(pFound) - nLength));
        pFound = sub_00526940_UnicodeStrStr(pString, pPattern);
    }

    return pString;
}

// 0x004524D0
void __fastcall sub_004524D0_SetPopUpText(const Unicode* wszText, int nA, int nB, int nC)
{
    gxGlobal_007A2C80[0].wChar = 0;
    if (wszText)
    {
        sub_005267E0(gxGlobal_007A2C80, wszText);
        gdwGlobal_007A2D20 = nA;
        gdwGlobal_007A2D24 = nB;
        gdwGlobal_007A2D28 = nC;
    }
}

// 0x00452510
void __stdcall sub_00452510_ShowPopUpText(const Unicode* wszText, int nX, int nY, int nArg)
{
    sub_005022F0_ShowPopUpText(wszText, nX, nY, nArg);
}

// 0x0045C430
void __fastcall sub_0045C430_SetUnitFlagEx(D2UnitFlagsStrc* pUnit, unsigned int dwFlag, int bSet)
{
    if (pUnit)
    {
        if (bSet)
            pUnit->dwFlagEx |= dwFlag;
        else
            pUnit->dwFlagEx &= ~dwFlag;
    }
}

// 0x0045CC70
void __fastcall sub_0045CC70_UnitPacket0C(D2UnitStrc* pUnit, const D2GSPacketSrv0C* pPacket)
{
    int args[7] = {};
    args[0] = pPacket->nHitClass;
    args[1] = pPacket->nLife;
    sub_00480C10_UnitEvent(pPacket->unk0x06, pUnit, args, 1);
}

// 0x0045CD10
void __fastcall sub_0045CD10_UnitPacket0E(D2UnitStrc* pUnit, const D2GSPacketSrv0E* pPacket)
{
    int args[7];
    args[0] = pPacket->unk0x07;
    args[1] = *(const int*)pPacket->unk0x08;
    sub_00480C10_UnitEvent(pPacket->unk0x06, pUnit, args, 1);
}

// 0x0045CD40
void __fastcall sub_0045CD40(D2UnitStrc* pUnit, const D2GSPacketSrv0F* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nDestPosX;
    args[1] = *(const unsigned short*)pPacket->nDestPosY;
    args[2] = pPacket->unk0x0B;
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->nCurrentPosX, *(const unsigned short*)pPacket->nCurrentPosY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->nFlags, pUnit, args, 1);
}

// 0x0045CDE0
void __fastcall sub_0045CDE0_UnitPacket67(D2UnitStrc* pUnit, const D2GSPacketSrv67* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nX;
    args[1] = *(const unsigned short*)pPacket->nY;
    args[2] = pPacket->unk0x0A;
    args[3] = pPacket->nPathType;
    args[4] = *(const short*)pPacket->nVelocity;
    args[5] = pPacket->unk0x0F;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CE30
void __fastcall sub_0045CE30_UnitPacket68(D2UnitStrc* pUnit, const D2GSPacketSrv68* pPacket)
{
    int args[7];
    args[0] = pPacket->unk0x0A;
    args[1] = *(const int*)pPacket->unk0x0B;
    args[2] = pPacket->unk0x0F;
    args[3] = pPacket->nPathType;
    args[4] = *(const short*)pPacket->nVelocity;
    args[5] = pPacket->unk0x14;
    args[6] = pPacket->unk0x10;
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->nX, *(const unsigned short*)pPacket->nY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CEA0
void __fastcall sub_0045CEA0_UnitPacket69(D2UnitStrc* pUnit, const D2GSPacketSrv69* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->unk0x06;
    args[1] = *(const unsigned short*)pPacket->unk0x08;
    args[2] = pPacket->unk0x0A;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CEF0
void __fastcall sub_0045CEF0_UnitPacket6A(D2UnitStrc* pUnit, const D2GSPacketSrv6A* pPacket)
{
    int args[7];
    args[0] = pPacket->nTargetUnitType;
    args[1] = *(const int*)pPacket->nTargetUnitGuid;
    args[2] = pPacket->nDirection;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CF40
void __fastcall sub_0045CF40_UnitPacket6B(D2UnitStrc* pUnit, const D2GSPacketSrv6B* pPacket)
{
    int args[7];
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->unk0x0C, *(const unsigned short*)pPacket->unk0x0E, 0, 0, 0);
    args[0] = *(const unsigned short*)pPacket->unk0x06;
    args[1] = *(const unsigned short*)pPacket->unk0x08;
    args[2] = pPacket->unk0x0A;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CFB0
void __fastcall sub_0045CFB0_UnitPacket6C(D2UnitStrc* pUnit, const D2GSPacketSrv6C* pPacket)
{
    int args[7];
    sub_004804E0_SetPosition(pUnit, *(const unsigned short*)pPacket->unk0x0C, *(const unsigned short*)pPacket->unk0x0E, 0, 0, 0);
    args[0] = pPacket->unk0x06;
    args[1] = *(const int*)pPacket->unk0x07;
    args[2] = pPacket->unk0x0B;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045D260
void __fastcall sub_0045D260_UnitPacket17(D2UnitStrc* pUnit, const D2GSPacketSrv17* pPacket)
{
    if (pUnit != sub_00463DD0())
    {
        D2_ASSERT(pUnit, 0x841);

        int args[7];
        unsigned short pos[2];
        pos[0] = *(const unsigned short*)*(const unsigned short*)pPacket->unk0x08;
        pos[1] = *(const unsigned short*)*(const unsigned short*)pPacket->unk0x0A;
        args[0] = pPacket->unk0x06 >> 1;
        args[1] = (int)pos;
        sub_00480C10_UnitEvent(pPacket->unk0x07, pUnit, args, 1);
    }
}

// 0x0045DE50
void __fastcall sub_0045DE50_CopyPacket7(const D2ClientPacket7Strc* pPacket)
{
    D2ClientPacket7Strc tPacket = *pPacket;
    sub_004B1240_UsePacket7(&tPacket);
}

// 0x0045DF00
void __fastcall sub_0045DF00_UnitPacket4C(D2UnitStrc* pUnit, const D2GSPacketSrv4C* pPacket)
{
    if (pUnit)
    {
        int args[7] = {};
        args[0] = *(const unsigned short*)pPacket->unk0x06;
        args[2] = pPacket->unk0x09;
        args[3] = *(const int*)pPacket->unk0x0A;
        args[4] = pPacket->unk0x08;
        args[1] = -1;
        sub_00480C10_UnitEvent(0x16, pUnit, args, 1);
    }
}

// 0x0045DF60
void __fastcall sub_0045DF60_UnitPacket4D(D2UnitStrc* pUnit, const D2GSPacketSrv4D* pPacket)
{
    if (pUnit)
    {
        int args[7] = {};
        args[0] = *(const int*)pPacket->unk0x06;
        args[2] = *(const unsigned short*)pPacket->unk0x0B;
        args[3] = *(const unsigned short*)pPacket->unk0x0D;
        args[4] = pPacket->unk0x0A;
        args[1] = -1;
        sub_00480C10_UnitEvent(0x15, pUnit, args, 1);
    }
}

// 0x0045E050
void __fastcall sub_0045E050_CopyPacket6(const D2ClientPacket6Strc* pPacket)
{
    D2ClientPacket6Strc tPacket = *pPacket;
    sub_0049F8C0_UsePacket6(&tPacket);
}
