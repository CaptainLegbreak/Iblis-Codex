struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct Unicode
{
    unsigned short wChar;
};

struct D2CmdLineArgStrc
{
    char unk0x00[0x18];
    const char* szValue;
};

struct D2TickValueStrc
{
    unsigned int dwTickCount;
    int nValue;

    void sub_0044BDF0_Set(int nValue);
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" int __cdecl abs(int nValue);
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(short nIndex);                                       // 0x00524A30
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern);             // 0x00526940
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned char nFlags, const char* szString); // 0x00415070
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00420290
void __cdecl sub_00466FF0();                                                                                // 0x00466FF0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00462D00(int nMode, int nX, int nY, int nFlags);                                    // 0x00462D00
void __fastcall sub_004693B0(int nSteps);                                                                   // 0x004693B0
void __cdecl sub_00469270();                                                                                // 0x00469270
void __cdecl sub_00469230();                                                                                // 0x00469230
void __cdecl sub_004692B0();                                                                                // 0x004692B0
void __cdecl sub_00469330();                                                                                // 0x00469330
void __cdecl sub_004692F0();                                                                                // 0x004692F0
void __cdecl sub_00469370();                                                                                // 0x00469370
int __cdecl sub_004F5A30();                                                                                 // 0x004F5A30
void __cdecl sub_00453DE0();                                                                                // 0x00453DE0
void __cdecl sub_00467A00();                                                                                // 0x00467A00
void __cdecl sub_00477EE0();                                                                                // 0x00477EE0

extern int gdwGlobal_0070F234;                                                                              // 0x0070F234
extern int gdwGlobal_0070F2BC;                                                                              // 0x0070F2BC
extern int gdwGlobal_007A05FC;                                                                              // 0x007A05FC
extern unsigned char gnGlobal_007A060D;                                                                     // 0x007A060D
int gdwGlobal_007A061C;                                                                                     // 0x007A061C
extern int gdwGlobal_007A0620;                                                                              // 0x007A0620
int gdwGlobal_007A0650;                                                                                     // 0x007A0650
int gdwGlobal_007A0654;                                                                                     // 0x007A0654
int gdwGlobal_007A0658;                                                                                     // 0x007A0658
extern int gdwGlobal_007A065C;                                                                              // 0x007A065C
extern int gdwGlobal_007A0660;                                                                              // 0x007A0660
extern int gdwGlobal_007A0664;                                                                              // 0x007A0664
extern int gdwGlobal_007A0670;                                                                              // 0x007A0670
extern int gdwGlobal_007A0674;                                                                              // 0x007A0674
int gdwGlobal_007A06F8;                                                                                     // 0x007A06F8

// 0x0044B230
void __stdcall sub_0044B230_StripStringAndNextChar(Unicode* pString)
{
    D2_ASSERT(sub_00526800(pString) < 500, 0x342);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    int nLength = sub_00526800(pPattern);
    for (Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pPattern); pFound && pFound[nLength].wChar; pFound = sub_00526940_UnicodeStrStr(pString, pPattern))
    {
        memmove(pFound, &pFound[nLength + 1], (sub_00526800(pFound) - nLength) * sizeof(Unicode));
    }
}

// 0x0044B5E0
int __stdcall sub_0044B5E0_SaveDefaultCmdLine(D2CmdLineArgStrc* pArg, int nUnused)
{
    return SRegSaveString("Diablo II", "Default Command Line", 0, pArg->szValue);
}

// 0x0044BDF0
void D2TickValueStrc::sub_0044BDF0_Set(int nValue)
{
    dwTickCount = GetTickCount();
    this->nValue = nValue;
}

// 0x0044BF40
void __stdcall sub_0044BF40_ClickMapMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F234 = 4;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (gdwGlobal_007A061C)
    {
        gdwGlobal_007A0650 = 1;
        D2UnitStrc* pPlayer = sub_00463DD0();
        int nFlags = 0;
        if (gdwGlobal_007A065C)
            nFlags = 8;
        if (gdwGlobal_007A0660)
            nFlags |= 8;
        if (gdwGlobal_007A0664)
            nFlags |= 4;
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            gdwGlobal_007A0650 = sub_00462D00(0, pMsg->nXpos, pMsg->nYpos, nFlags);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C370
void __stdcall sub_0044C370_ClickMapMsgMode5(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_0070F2BC = 0x10;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A0670 = 1;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (gdwGlobal_007A061C)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && pPlayer->dwUnitType == 0)
        {
            gdwGlobal_007A0654 = sub_00462D00(5, pMsg->nXpos, pMsg->nYpos, pMsg->nWParamLo);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C400
void __stdcall sub_0044C400_WheelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        gdwGlobal_007A06F8 += pMsg->nWParamHi;
        if (abs(gdwGlobal_007A06F8) >= 120)
        {
            sub_004693B0(gdwGlobal_007A06F8 / 120);
            gdwGlobal_007A06F8 = 0;
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C470
void __stdcall sub_0044C470_Call469270Msg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        sub_00469270();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C4A0
void __stdcall sub_0044C4A0_Call469230Msg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        sub_00469230();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C4D0
void __stdcall sub_0044C4D0_HiWordDispatchMsgA(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        unsigned short nCode = pMsg->nWParamHi;
        if (nCode == 1)
            sub_004692B0();
        else if (nCode == 2)
            sub_00469330();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C520
void __stdcall sub_0044C520_HiWordDispatchMsgB(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007A061C)
    {
        unsigned short nCode = pMsg->nWParamHi;
        if (nCode == 1)
            sub_004692F0();
        else if (nCode == 2)
            sub_00469370();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C570
void __stdcall sub_0044C570_SysCommandMsg(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned short nCommand = pMsg->nWParamLo & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && sub_004F5A30()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0044C5C0
void __stdcall sub_0044C5C0_DefaultMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0044D0A0
void __stdcall sub_0044D0A0_IncCounterMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A060D += 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0044D0D0
void __stdcall sub_0044D0D0_IncCounterNoRepeatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        gnGlobal_007A060D += 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0044DBE0
void __cdecl sub_0044DBE0_ReadColorFlag()
{
    if (gdwGlobal_007A05FC == 0)
    {
        void* hFile;
        if (ARCHIVE_OpenFile(0, "Data\\Local\\Color.txt", &hFile, 1))
        {
            char nFlag;
            ARCHIVE_ReadFileToBuffer(0, hFile, &nFlag, 1);
            ARCHIVE_CloseFile(0, hFile);
            if (nFlag == '1')
                gdwGlobal_007A05FC = 1;
        }
    }
}

// 0x0044E0B0
void __stdcall sub_0044E0B0_ToggleMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007A065C = 0;
    if (gdwGlobal_007A0620)
    {
        sub_00453DE0();
        sub_00467A00();
        pMsg->bReturn = 0;
        return;
    }
    sub_00477EE0();
    gdwGlobal_007A0674 = 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}
