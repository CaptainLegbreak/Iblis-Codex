struct D2ListMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                     // 0x006CC260
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __stdcall sub_00439840(D2ListMsgStrc* pMsg);                                                            // 0x00439840
int __cdecl sub_00439210_Redraw();                                                                          // 0x00439210

extern int gnSelected_0070CC00;                                                                             // 0x0070CC00
extern int gnVisibleRows_0070CC0C;                                                                          // 0x0070CC0C
extern void* gapRowControls_00779A20[];                                                                     // 0x00779A20
extern void* gapRowControlsX_00779B40[];                                                                    // 0x00779B40
extern int gbFlag_00779C6C;                                                                                 // 0x00779C6C
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4
extern int gnTopRow_00779DC8;                                                                               // 0x00779DC8
unsigned long gdwLastClick_00779DEC;                                                                        // 0x00779DEC

// 0x0043A9D0
int __stdcall sub_0043A9D0_ListClick(D2ListMsgStrc* pMsg)
{
    if (!gbFlag_00779C6C)
    {
        const int nPrevious = gnSelected_0070CC00;
        void* hWnd = pMsg->hWnd;
        int nRow;
        for (nRow = 0; nRow < gnVisibleRows_0070CC0C; nRow += 1)
        {
            if (sub_00408F20_HasExpansionMpq() && hWnd == gapRowControlsX_00779B40[nRow])
                break;
            if (hWnd == gapRowControls_00779A20[nRow])
                break;
        }
        const int nIndex = gnTopRow_00779DC8 + nRow;
        if (gdwGlobal_00779DC4 < nIndex)
            return 0;
        gnSelected_0070CC00 = nIndex;
        if (gdwGlobal_00779DC4 <= 0)
            gnSelected_0070CC00 = -1;
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
            if (gnSelected_0070CC00 != -1 && gnSelected_0070CC00 == nPrevious && dwTick - gdwLastClick_00779DEC < 500)
                return sub_00439840(pMsg);
            gdwLastClick_00779DEC = dwTick;
        }
        return sub_00439210_Redraw();
    }
    return 1;
}
