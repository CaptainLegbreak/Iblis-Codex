struct D2BnReplyStrc
{
    unsigned int nResult;
    char szText[0x100];
};
int gnReplyReady_008823B0;        // 0x008823B0
unsigned int gnReplyResult_00882420;        // 0x00882420
extern char gszReplyText_00882428[0x100]; // 0x00882428
int __fastcall sub_00520520_SetState(int nState); // 0x00520520
int __fastcall sub_00520550_SetStateArg(void* pArg); // 0x00520550
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

// 0x00520FE0
int __fastcall sub_00520FE0_HandleReply(D2BnReplyStrc* pReply)
{
    const unsigned int nResult = pReply->nResult;
    gnReplyResult_00882420 = nResult;
    gszReplyText_00882428[0] = 0;
    gnReplyReady_008823B0 = 0;
    switch (nResult)
    {
    case 0:
        gnReplyReady_008823B0 = 1;
        break;
    case 3:
        sub_00520520_SetState(3);
        break;
    case 6:
        sub_00520520_SetState(5);
        break;
    case 5:
        sub_00520520_SetState(4);
        break;
    case 4:
        sub_00520520_SetState(6);
        SStrCopy(gszReplyText_00882428, pReply->szText, 0x100);
        sub_00520550_SetStateArg(gszReplyText_00882428);
        break;
    }
    return 1;
}
