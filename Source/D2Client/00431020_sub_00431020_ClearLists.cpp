struct D2WinControlStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80
extern D2WinControlStrc* gpList_0077995C;                                                                   // 0x0077995C
extern D2WinControlStrc* gpList_00779960;                                                                   // 0x00779960
extern int gdwGlobal_00779990;                                                                              // 0x00779990

// 0x00431020
void __cdecl sub_00431020_ClearLists()
{
    sub_004FCF80_SetTextA(gpList_0077995C, &gszEmptyAssertText);
    sub_004FCF80_SetTextA(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431C60
void __fastcall sub_00431C60_HandleModeMessage(unsigned char* pMsg, int nSize)
{
    if (nSize != -1)
    {
        switch (*pMsg)
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            break;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }
}
