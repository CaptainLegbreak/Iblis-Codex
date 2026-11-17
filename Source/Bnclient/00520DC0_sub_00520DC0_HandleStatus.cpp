extern int gnLastStatus_0072FFA8; // 0x0072FFA8
void __fastcall sub_005204A0_SetError(int nError); // 0x005204A0
void __fastcall sub_005204D0_SetErrorText(int nError, const char* szText); // 0x005204D0
struct D2BnReply00520DC0Strc
{
    int nStatus;
    char szText[1];
};

// 0x00520DC0
int __fastcall sub_00520DC0_HandleStatus(D2BnReply00520DC0Strc* pReply)
{
    const int nStatus = pReply->nStatus;
    gnLastStatus_0072FFA8 = nStatus;
    switch (nStatus)
    {
    case 0:
        break;
    case 1:
        sub_005204A0_SetError(0xD);
        break;
    case 2:
        sub_005204A0_SetError(0xE);
        break;
    case 3:
        sub_005204A0_SetError(0xF);
        break;
    case 6:
        sub_005204D0_SetErrorText(0x1B, pReply->szText);
        break;
    default:
        sub_005204A0_SetError(0x12);
        break;
    }
    return 1;
}
