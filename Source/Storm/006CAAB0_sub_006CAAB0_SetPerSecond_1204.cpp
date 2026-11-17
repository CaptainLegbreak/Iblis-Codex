extern int gnDivisor_007121DC; // 0x007121DC
extern int gnQuotient_007A6B0C; // 0x007A6B0C

// 0x006CAAB0
void __cdecl sub_006CAAB0_SetPerSecond()
{
    gnQuotient_007A6B0C = 1000 / gnDivisor_007121DC;
}
