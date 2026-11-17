extern int gnDivisor_00731014; // 0x00731014
extern int gnQuotient_00883D60; // 0x00883D60

// 0x006CAF10
void __cdecl sub_006CAF10_SetPerSecond()
{
    gnQuotient_00883D60 = 1000 / gnDivisor_00731014;
}
