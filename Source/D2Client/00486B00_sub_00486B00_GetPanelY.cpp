int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A285C;                                                                               // 0x007A285C

// 0x00486B00
int __cdecl sub_00486B00_GetPanelY()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x41;
    }
    return gnGlobal_00711470 + gnGlobal_007A285C - 0x40;
}
