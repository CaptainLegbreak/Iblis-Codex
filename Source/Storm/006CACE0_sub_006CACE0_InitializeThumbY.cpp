extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnThumbY_007C02CC; // 0x007C02CC
// 0x006CACE0
void __cdecl sub_006CACE0_InitializeThumbY()
{
    gnThumbY_007C02CC = (gnAutomapHeight_007A521C - 420) / 2 + 47;
}
