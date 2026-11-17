extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470

// 0x004A6630
int __fastcall sub_004A6630_IsInRightPanelButton(int nMode, int nX, int nY)
{
    switch (nMode)
    {
    case 1:
        if (nX > (gnGlobal_0071146C - gnGlobal_0071146C / 2) - 73 && nX < (gnGlobal_0071146C - gnGlobal_0071146C / 2) - 40 && nY > gnGlobal_00711470 - 138 && nY < gnGlobal_00711470 - 102)
            return 1;
        return 0;
    default:
        if (nX > gnGlobal_0071146C - 73 && nX < gnGlobal_0071146C - 40 && nY > gnGlobal_00711470 - 138 && nY < gnGlobal_00711470 - 102)
            return 1;
        return 0;
    }
}
