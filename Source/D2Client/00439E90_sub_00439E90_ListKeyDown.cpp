struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
};

void __stdcall sub_00439E60_AddToValue(int nDelta);                                                         // 0x00439E60
void __cdecl sub_00438560_Refresh();                                                                        // 0x00438560
void __cdecl sub_00439210_Redraw();                                                                         // 0x00439210

extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern int gnVisibleRows_0070CC0C;                                                                          // 0x0070CC0C
int gdwGlobal_00779DC4;                                                                                     // 0x00779DC4
int gnTopRow_00779DC8;                                                                                      // 0x00779DC8

// 0x00439E90
int __stdcall sub_00439E90_ListKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->uMessage != 0x102)
    {
    switch (pMsg->wParam)
    {
    case 0x28:
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1)
        {
            gnSelected_0070CC00 += 2;
            if (gnSelected_0070CC00 > gdwGlobal_00779DC4 - 1)
            {
                gnSelected_0070CC00 -= 2;
            }
            else if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00;
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                if (gnSelected_0070CC00 % 2 == 0)
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 2;
                }
                else
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
                }
                sub_00439E60_AddToValue(1);
            }
        }
        break;

    case 0x26:
        if (gnSelected_0070CC00 > 0)
        {
            gnSelected_0070CC00 -= 2;
            if (gnSelected_0070CC00 < 0)
            {
                gnSelected_0070CC00 += 2;
            }
            else if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                if (gnSelected_0070CC00 % 2 != 0)
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00 - 1;
                }
                else
                {
                    gnTopRow_00779DC8 = gnSelected_0070CC00;
                }
                sub_00439E60_AddToValue(-1);
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 2;
            }
        }
        break;

    case 0x27:
        if (gnSelected_0070CC00 < gdwGlobal_00779DC4 - 1 && gnSelected_0070CC00 % 2 == 0)
        {
            gnSelected_0070CC00 += 1;
            if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00;
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
        }
        break;

    case 0x25:
        if (gnSelected_0070CC00 > 0 && gnSelected_0070CC00 % 2 != 0)
        {
            gnSelected_0070CC00 -= 1;
            if (gnSelected_0070CC00 < gnTopRow_00779DC8)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00;
            }
            else if (gnSelected_0070CC00 > gnTopRow_00779DC8 + gnVisibleRows_0070CC0C - 1)
            {
                gnTopRow_00779DC8 = gnSelected_0070CC00 - gnVisibleRows_0070CC0C + 1;
            }
        }
        break;

    case 0x24:
        gnTopRow_00779DC8 = 0;
        gnSelected_0070CC00 = 0;
        break;

    case 0x23:
        if (gdwGlobal_00779DC4 > gnVisibleRows_0070CC0C)
        {
            gnTopRow_00779DC8 = gdwGlobal_00779DC4 - gnVisibleRows_0070CC0C;
        }
        gnSelected_0070CC00 = gdwGlobal_00779DC4 - 1;
        break;
    }

    sub_00438560_Refresh();
    sub_00439210_Redraw();
    return 1;
    }

    return 0;
}

#include "gen/data/Source/D2Client/00439E90_sub_00439E90_ListKeyDown.inc"
