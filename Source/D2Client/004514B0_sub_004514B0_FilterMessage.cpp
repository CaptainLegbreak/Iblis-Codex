void __stdcall sub_00451450_RecordMessage(unsigned int uMessage, unsigned int wParam, int lParam);          // 0x00451450
extern int gdwGlobal_007A2780;                                                                              // 0x007A2780

// 0x004514B0
void __fastcall sub_004514B0_FilterMessage(unsigned int uMessage, unsigned int wParam, int lParam)
{
    if (gdwGlobal_007A2780)
    {
        switch (uMessage)
        {
        case 0x100:
        case 0x200:
            sub_00451450_RecordMessage(uMessage, wParam, lParam);
            return;
        case 0x10:
        case 0x101:
        case 0x102:
        case 0x111:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
            sub_00451450_RecordMessage(uMessage, wParam, lParam);
            break;
        }
    }
}
