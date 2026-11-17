struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
};

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __stdcall sub_00439E90_ListKeyDown(SMSGHANDLER_PARAMS* pMsg);                                           // 0x00439E90
void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560
void __cdecl sub_00439210_Redraw();                                                                         // 0x00439210

extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern int gnVisibleRows_0070CC0C;                                                                          // 0x0070CC0C
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4
extern int gnTopRow_00779DC8;                                                                               // 0x00779DC8

// 0x0043A0D0
int __stdcall sub_0043A0D0_ListKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00408F20_HasExpansionMpq())
        return sub_00439E90_ListKeyDown(pMsg);

    if (pMsg->uMessage != 0x102)
    {
        switch (pMsg->wParam)
        {
        case 0x28:
            if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
            {
                gnSelected_0070CC00 += 1;
                if (gnSelected_0070CC00 < gnTopRow_00779DC8)
                    gnTopRow_00779DC8 = gnSelected_0070CC00;
                else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
            break;

        case 0x26:
            if (gnSelected_0070CC00 > 0)
            {
                gnSelected_0070CC00 -= 1;
                if (gnSelected_0070CC00 < gnTopRow_00779DC8)
                    gnTopRow_00779DC8 = gnSelected_0070CC00;
                else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
            break;

        case 0x24:
            gnTopRow_00779DC8 = 0;
            gnSelected_0070CC00 = 0;
            break;

        case 0x23:
            if (gdwGlobal_00779DC4 > gnVisibleRows_0070CC0C)
                gnTopRow_00779DC8 = gdwGlobal_00779DC4 - gnVisibleRows_0070CC0C;
            gnSelected_0070CC00 = gdwGlobal_00779DC4 - 1;
            break;
        }

        sub_00438560_Refresh();
        sub_00439210_Redraw();
        return 1;
    }

    return 0;
}
