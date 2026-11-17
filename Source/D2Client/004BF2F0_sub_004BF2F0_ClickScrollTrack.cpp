struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nLParamLo;
    unsigned short nLParamHi;
};

#pragma pack(push, 2)
struct ListBoxView
{
    void* pVtable;
    int unk0x04;
    char aLines[0x180700];
    int nRectX;
    int nRectY;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int bMouseDown;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int nTopIndex;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int nVisibleRows;
    int nThumbStart;
    int nThumbEnd;
    int nX;
    int nY;

    void sub_004BE8D0_Refresh();                                                                            // 0x004BE8D0
    int sub_004BF2F0_ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg);
};
#pragma pack(pop)

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

// 0x004BF2F0
int ListBoxView::sub_004BF2F0_ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseY = pMsg->nLParamHi;
    const unsigned short nCount = nEntryCount;
    const int nTop = nY;

    if (nCount && nVisibleRows <= nCount && nMouseY - nTop > 0)
    {
        if (nThumbStart != nThumbEnd)
        {
            if (nMouseY < nTop + 12 * nThumbStart + 13)
            {
                if (nSelectedIndex - nVisibleRows > 0)
                    nSelectedIndex = nSelectedIndex - nVisibleRows;
                else
                    nSelectedIndex = 0;
            }
            else
            {
                if (nMouseY <= nY + 12 * nThumbEnd + 13)
                {
                    return 0;
                }

                if (nSelectedIndex + nVisibleRows >= nCount)
                    nSelectedIndex = nCount - 1;
                else
                    nSelectedIndex = nSelectedIndex + nVisibleRows;
                if (nCount - nSelectedIndex < nVisibleRows)
                {
                    if (nCount >= nVisibleRows)
                    {
                        nSelectedIndex = nCount - nVisibleRows;
                    }
                    else
                    {
                        nSelectedIndex = 0;
                    }
                }
            }

            if (nSelectedIndex >= 0x80)
            {
                nSelectedIndex = D2_MAX(0, nCount - 1);
            }

            nTopIndex = nSelectedIndex;
            sub_004B9A00(1, 0, 0, 0, 0);
            sub_004BE8D0_Refresh();
            return 1;
        }

        return 0;
    }

    return 0;
}
