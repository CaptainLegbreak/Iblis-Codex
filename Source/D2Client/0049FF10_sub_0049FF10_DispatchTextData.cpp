struct D2ClientTextDataStrc
{
    char unk0x00[0x80];
    int dwTag;
};

void __cdecl sub_0049FA10_DrawPanelFrame();                                                                 // 0x0049FA10
void __stdcall sub_0049FBA0_OpenTextPanel(int bFlag);                                                       // 0x0049FBA0

extern D2ClientTextDataStrc* gpTextData_007BF228;                                                           // 0x007BF228
extern int gnGlobal_007BF254;                                                                               // 0x007BF254

// 0x0049FF10
void __cdecl sub_0049FF10_DispatchTextData()
{
    if (!gpTextData_007BF228)
        return;

    const int nTag = gpTextData_007BF228->dwTag;
    if (nTag == 0x20736B62)
    {
        sub_0049FBA0_OpenTextPanel(0);
        return;
    }
    if (nTag == 0x20646B62)
    {
        if (!gnGlobal_007BF254)
        {
            sub_0049FBA0_OpenTextPanel(1);
            return;
        }
    }
    else if (nTag != 0x20317274)
    {
        return;
    }
    sub_0049FA10_DrawPanelFrame();
}
